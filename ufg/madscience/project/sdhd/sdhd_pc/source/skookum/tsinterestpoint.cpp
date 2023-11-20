// File Line: 65
// RVA: 0x4CC630
SSInstance *__fastcall UFG::TSInterestPoint::AsInstance(UFG::InterestPoint *poi)
{
  UFG::InterestPoint *v1; // rbx
  UFG::CollectibleComponent *v2; // rax
  SSClass *v3; // rcx

  v1 = poi;
  v2 = UFG::CollectibleComponent::GetCollectibleComponent(poi->m_pSimObject);
  v3 = UFG::TSCollectible::mspCollectibleClass;
  if ( !v2 )
    v3 = UFG::TSInterestPoint::mspInterestPointClass;
  return SSInstance::pool_new(v3, (unsigned __int64)v1);
}

// File Line: 122
// RVA: 0x4D4020
void UFG::TSInterestPoint::BindAtomics(void)
{
  UFG::TSInterestPoint::mspInterestPointClass = SSBrain::get_class("InterestPoint");
  SSClass::register_method_func(
    UFG::TSInterestPoint::mspInterestPointClass,
    "enable_interest_point",
    UFG::TSInterestPoint::Mthd_enable_interest_point,
    0);
  SSClass::register_method_func(
    UFG::TSInterestPoint::mspInterestPointClass,
    "get_child_poi",
    UFG::TSInterestPoint::Mthd_get_child_poi,
    0);
  SSClass::register_method_func(
    UFG::TSInterestPoint::mspInterestPointClass,
    "get_parent_poi",
    UFG::TSInterestPoint::Mthd_get_parent_poi,
    0);
  SSClass::register_method_func(
    UFG::TSInterestPoint::mspInterestPointClass,
    "enable_child_pois",
    UFG::TSInterestPoint::Mthd_enable_child_pois,
    0);
  SSClass::register_method_func(
    UFG::TSInterestPoint::mspInterestPointClass,
    "finish",
    UFG::TSInterestPoint::Mthd_finish,
    0);
  SSClass::register_method_func(
    UFG::TSInterestPoint::mspInterestPointClass,
    "is_active",
    UFG::TSInterestPoint::Mthd_is_active,
    0);
  SSClass::register_method_func(
    UFG::TSInterestPoint::mspInterestPointClass,
    "is_in_use",
    UFG::TSInterestPoint::Mthd_is_in_use,
    0);
  SSClass::register_method_func(
    UFG::TSInterestPoint::mspInterestPointClass,
    "get_user",
    UFG::TSInterestPoint::Mthd_get_user,
    0);
  SSClass::register_method_func(
    UFG::TSInterestPoint::mspInterestPointClass,
    "find_named",
    UFG::TSInterestPoint::MthdC_find_named,
    1,
    0);
  SSClass::register_method_func(
    UFG::TSInterestPoint::mspInterestPointClass,
    "find_nearest_min",
    UFG::TSInterestPoint::MthdC_find_nearest_min,
    1,
    0);
  SSClass::register_method_func(
    UFG::TSInterestPoint::mspInterestPointClass,
    "find_nearest_max",
    UFG::TSInterestPoint::MthdC_find_nearest_max,
    1,
    0);
  SSClass::register_method_func(
    UFG::TSInterestPoint::mspInterestPointClass,
    "find_nearest_min_max",
    UFG::TSInterestPoint::MthdC_find_nearest_min_max,
    1,
    0);
  SSClass::register_method_func(
    UFG::TSInterestPoint::mspInterestPointClass,
    "get_named",
    UFG::TSInterestPoint::MthdC_get_named,
    1,
    0);
  SSClass::register_method_func(
    UFG::TSInterestPoint::mspInterestPointClass,
    "list_parents",
    UFG::TSInterestPoint::MthdC_list_parents,
    1,
    0);
  SSClass::register_method_func(
    UFG::TSInterestPoint::mspInterestPointClass,
    "force_update_can_path_to",
    UFG::TSInterestPoint::MthdC_force_update_can_path_to,
    1,
    0);
}

// File Line: 156
// RVA: 0x4E6490
void __fastcall UFG::TSInterestPoint::MthdC_find_named(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rdi
  UFG::InterestPoint *v3; // rax
  unsigned __int64 v4; // rbx

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = UFG::InterestPoint::GetNamed((UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    v4 = (unsigned __int64)v3;
    if ( v3 )
    {
      if ( UFG::CollectibleComponent::GetCollectibleComponent(v3->m_pSimObject) )
        *v2 = SSInstance::pool_new(UFG::TSCollectible::mspCollectibleClass, v4);
      else
        *v2 = SSInstance::pool_new(UFG::TSInterestPoint::mspInterestPointClass, v4);
    }
    else
    {
      *v2 = SSBrain::c_nil_p;
    }
  }
}

// File Line: 174
// RVA: 0x4E6870
void __fastcall UFG::TSInterestPoint::MthdC_find_nearest_min(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // r8
  SSInstance **v3; // rdi
  float v4; // xmm2_4
  UFG::InterestPoint *v5; // rax
  unsigned __int64 v6; // rbx

  if ( ppResult )
  {
    v2 = pScope->i_data.i_array_p;
    v3 = ppResult;
    v4 = *(float *)&v2[2]->i_data_p->i_user_data;
    v5 = UFG::InterestPoint::FindNearestMinOfType(
           (UFG::qVector3 *)(*v2)->i_data_p->i_user_data,
           (UFG::qSymbol *)&v2[1]->i_data_p->i_user_data,
           v4 * v4,
           3.4028235e38,
           0i64);
    v6 = (unsigned __int64)v5;
    if ( v5 )
    {
      if ( UFG::CollectibleComponent::GetCollectibleComponent(v5->m_pSimObject) )
        *v3 = SSInstance::pool_new(UFG::TSCollectible::mspCollectibleClass, v6);
      else
        *v3 = SSInstance::pool_new(UFG::TSInterestPoint::mspInterestPointClass, v6);
    }
    else
    {
      *v3 = SSBrain::c_nil_p;
    }
  }
}

// File Line: 198
// RVA: 0x4E67B0
void __fastcall UFG::TSInterestPoint::MthdC_find_nearest_max(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // r8
  SSInstance **v3; // rdi
  float v4; // xmm3_4
  UFG::InterestPoint *v5; // rax
  unsigned __int64 v6; // rbx

  if ( ppResult )
  {
    v2 = pScope->i_data.i_array_p;
    v3 = ppResult;
    v4 = *(float *)&v2[2]->i_data_p->i_user_data;
    v5 = UFG::InterestPoint::FindNearestMaxOfType(
           (UFG::qVector3 *)(*v2)->i_data_p->i_user_data,
           (UFG::qSymbol *)&v2[1]->i_data_p->i_user_data,
           0.0,
           v4 * v4,
           0i64);
    v6 = (unsigned __int64)v5;
    if ( v5 )
    {
      if ( UFG::CollectibleComponent::GetCollectibleComponent(v5->m_pSimObject) )
        *v3 = SSInstance::pool_new(UFG::TSCollectible::mspCollectibleClass, v6);
      else
        *v3 = SSInstance::pool_new(UFG::TSInterestPoint::mspInterestPointClass, v6);
    }
    else
    {
      *v3 = SSBrain::c_nil_p;
    }
  }
}

// File Line: 223
// RVA: 0x4E6930
void __fastcall UFG::TSInterestPoint::MthdC_find_nearest_min_max(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // r10
  SSInstance **v3; // rdi
  float v4; // xmm1_4
  float v5; // xmm0_4
  UFG::InterestPoint *v6; // rax
  unsigned __int64 v7; // rbx

  if ( ppResult )
  {
    v2 = pScope->i_data.i_array_p;
    v3 = ppResult;
    v4 = *(float *)&v2[2]->i_data_p->i_user_data;
    v5 = *(float *)&v2[3]->i_data_p->i_user_data;
    v6 = UFG::InterestPoint::FindNearestMinMaxOfType(
           (UFG::qVector3 *)(*v2)->i_data_p->i_user_data,
           v2[4]->i_data_p->i_user_data != 0,
           v2[5]->i_data_p->i_user_data != 0,
           (UFG::qSymbol *)&v2[1]->i_data_p->i_user_data,
           v4 * v4,
           v5 * v5,
           0i64);
    v7 = (unsigned __int64)v6;
    if ( v6 )
    {
      if ( UFG::CollectibleComponent::GetCollectibleComponent(v6->m_pSimObject) )
        *v3 = SSInstance::pool_new(UFG::TSCollectible::mspCollectibleClass, v7);
      else
        *v3 = SSInstance::pool_new(UFG::TSInterestPoint::mspInterestPointClass, v7);
    }
    else
    {
      *v3 = SSBrain::c_nil_p;
    }
  }
}

// File Line: 251
// RVA: 0x4E8220
void __fastcall UFG::TSInterestPoint::MthdC_get_named(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  UFG::InterestPoint *v3; // rax
  unsigned __int64 v4; // rdi
  UFG::CollectibleComponent *v5; // rax
  SSClass *v6; // rcx

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = UFG::InterestPoint::GetNamed((UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    v4 = (unsigned __int64)v3;
    v5 = UFG::CollectibleComponent::GetCollectibleComponent(v3->m_pSimObject);
    v6 = UFG::TSCollectible::mspCollectibleClass;
    if ( !v5 )
      v6 = UFG::TSInterestPoint::mspInterestPointClass;
    *v2 = SSInstance::pool_new(v6, v4);
  }
}

// File Line: 277
// RVA: 0x4F8BD0
void __fastcall UFG::TSInterestPoint::Mthd_enable_interest_point(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // r8
  SSInvokedMethod *v3; // r9
  SSObjectBase *v4; // rcx
  bool v5; // r10
  bool v6; // r8

  v2 = pScope->i_data.i_array_p;
  v3 = pScope;
  v4 = pScope->i_scope_p.i_obj_p;
  v5 = (*v2)->i_data_p->i_user_data != 0;
  v6 = v2[1]->i_data_p->i_user_data != 0;
  if ( !v4 || v3->i_scope_p.i_ptr_id != v4->i_ptr_id )
    v4 = 0i64;
  UFG::InterestPoint::SetActive((UFG::InterestPoint *)v4[2].vfptr, v5, v6);
}

// File Line: 290
// RVA: 0x4F9D70
void __fastcall UFG::TSInterestPoint::Mthd_finish(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rbx
  UFG::InterestPoint *v3; // rbx

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = (UFG::InterestPoint *)v2[2].vfptr;
  UFG::InterestPoint::FinishUsing(v3);
  UFG::InterestPoint::EndReservation(v3);
}

// File Line: 299
// RVA: 0x5008D0
void __fastcall UFG::TSInterestPoint::Mthd_is_active(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  *ppResult = (SSInstance *)SSBoolean::pool_new(BYTE6(v2[2].vfptr[6].set_data_by_name) != 0);
}

// File Line: 310
// RVA: 0x501CB0
void __fastcall UFG::TSInterestPoint::Mthd_is_in_use(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // r8
  SSObjectBase *v3; // rcx
  SSInstance **v4; // rbx
  bool v5; // al

  v2 = pScope;
  v3 = pScope->i_scope_p.i_obj_p;
  v4 = ppResult;
  if ( !v3 || v2->i_scope_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  v5 = UFG::InterestPoint::IsReservationMatch((UFG::InterestPoint *)v3[2].vfptr, 2u, ReserveReason_normal);
  *v4 = (SSInstance *)SSBoolean::pool_new(v5);
}

// File Line: 321
// RVA: 0x4FC110
void __fastcall UFG::TSInterestPoint::Mthd_get_child_poi(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rdi
  SSObjectBase *v3; // r8
  unsigned int v4; // edx
  void (__fastcall *v5)(SSObjectBase *, ASymbol *, SSInstance *); // rcx
  UFG::SimObject *v6; // rax
  UFG::SimComponent *v7; // rax
  unsigned __int64 v8; // rbx
  UFG::CollectibleComponent *v9; // rax
  SSClass *v10; // rcx

  if ( ppResult )
  {
    v2 = ppResult;
    *ppResult = SSBrain::c_nil_p;
    v3 = pScope->i_scope_p.i_obj_p;
    if ( !v3 || pScope->i_scope_p.i_ptr_id != v3->i_ptr_id )
      v3 = 0i64;
    v4 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    v5 = v3[2].vfptr->set_data_by_name;
    if ( v5 )
    {
      v6 = UFG::SceneObjectProperties::GetChildAsSimObject(*((UFG::SceneObjectProperties **)v5 + 10), v4);
      if ( v6 )
      {
        v7 = UFG::SimObject::GetComponentOfType(v6, UFG::InterestPoint::_TypeUID);
        v8 = (unsigned __int64)v7;
        if ( v7 )
        {
          v9 = UFG::CollectibleComponent::GetCollectibleComponent(v7->m_pSimObject);
          v10 = UFG::TSCollectible::mspCollectibleClass;
          if ( !v9 )
            v10 = UFG::TSInterestPoint::mspInterestPointClass;
          *v2 = SSInstance::pool_new(v10, v8);
        }
      }
    }
  }
}

// File Line: 347
// RVA: 0x4FDCF0
void __fastcall UFG::TSInterestPoint::Mthd_get_parent_poi(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  SSObjectBase *v3; // r8
  UFG::InterestPoint *v4; // rdi
  UFG::SimObject *v5; // rax
  UFG::SimComponent *v6; // rax
  unsigned __int64 v7; // rdi
  UFG::CollectibleComponent *v8; // rax
  SSClass *v9; // rcx

  if ( ppResult )
  {
    v2 = ppResult;
    *ppResult = SSBrain::c_nil_p;
    v3 = pScope->i_scope_p.i_obj_p;
    if ( !v3 || pScope->i_scope_p.i_ptr_id != v3->i_ptr_id )
      v3 = 0i64;
    v4 = (UFG::InterestPoint *)v3[2].vfptr;
    if ( UFG::InterestPoint::GetParent((UFG::InterestPoint *)v3[2].vfptr) )
    {
      v5 = UFG::InterestPoint::GetParent(v4);
      v6 = UFG::SimObject::GetComponentOfType(v5, UFG::InterestPoint::_TypeUID);
      v7 = (unsigned __int64)v6;
      if ( v6 )
      {
        v8 = UFG::CollectibleComponent::GetCollectibleComponent(v6->m_pSimObject);
        v9 = UFG::TSCollectible::mspCollectibleClass;
        if ( !v8 )
          v9 = UFG::TSInterestPoint::mspInterestPointClass;
        *v2 = SSInstance::pool_new(v9, v7);
      }
    }
  }
}

// File Line: 366
// RVA: 0x4F8970
void __fastcall UFG::TSInterestPoint::Mthd_enable_child_pois(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx
  unsigned int v3; // ebx
  void (__fastcall *v4)(SSObjectBase *, ASymbol *, SSInstance *); // rdi
  bool v5; // si
  UFG::SceneObjectProperties *v6; // rax
  UFG::SimObject *v7; // rax
  UFG::InterestPoint *v8; // rax

  v2 = pScope->i_scope_p.i_obj_p;
  v3 = 0;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v4 = v2[2].vfptr->set_data_by_name;
  v5 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  if ( v4 )
  {
    v6 = (UFG::SceneObjectProperties *)*((_QWORD *)v4 + 10);
    if ( v6->mChildren.mCount > 0 )
    {
      do
      {
        v7 = UFG::SceneObjectProperties::GetChildAsSimObject(v6, v3);
        if ( v7 )
        {
          v8 = (UFG::InterestPoint *)UFG::SimObject::GetComponentOfType(v7, UFG::InterestPoint::_TypeUID);
          if ( v8 )
            UFG::InterestPoint::SetActive(v8, v5, 1);
        }
        v6 = (UFG::SceneObjectProperties *)*((_QWORD *)v4 + 10);
        ++v3;
      }
      while ( v3 < v6->mChildren.mCount );
    }
  }
}

// File Line: 391
// RVA: 0x4FF2D0
void __fastcall UFG::TSInterestPoint::Mthd_get_user(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  SSInstance **v3; // rdi
  SSObjectBaseVtbl *v4; // rcx
  SSInstance *(__fastcall *v5)(SSObjectBase *); // rcx
  UFG::TSActorComponent *v6; // rax
  UFG::TSActorComponent *v7; // rbx
  SSActorClass *v8; // rcx
  SSClass *v9; // rcx
  UFG::TSActor *v10; // rax

  v2 = pScope->i_scope_p.i_obj_p;
  v3 = ppResult;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v4 = v2[2].vfptr;
  if ( ppResult )
  {
    *ppResult = SSBrain::c_nil_p;
    v5 = v4[5].get_topmost_scope;
    if ( v5 )
    {
      if ( !((*((_BYTE *)v5 + 76) >> 1) & 1) )
      {
        v6 = (UFG::TSActorComponent *)UFG::SimObject::GetComponentOfType(
                                        (UFG::SimObject *)v5,
                                        UFG::TSActorComponent::_TypeUID);
        v7 = v6;
        if ( v6 )
        {
          if ( UFG::TSActorComponent::GetActor(v6) )
          {
            if ( UFG::TSActorComponent::GetActor(v7)->i_class_p )
            {
              v8 = (SSActorClass *)UFG::TSActorComponent::GetActor(v7)->i_class_p;
              if ( UFG::SkookumMgr::mspCharacterClass == v8
                || (v9 = v8->i_superclass_p) != 0i64
                && SSClass::is_class(v9, (SSClass *)&UFG::SkookumMgr::mspCharacterClass->vfptr) )
              {
                v10 = UFG::TSActorComponent::GetActor(v7);
                ++v10->i_ref_count;
                *v3 = (SSInstance *)&v10->vfptr;
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
void __fastcall UFG::TSInterestPoint::MthdC_force_update_can_path_to(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::InterestPoint::ForceUpdateCanPathTo();
}

