// File Line: 128
// RVA: 0x4CC7C0
UFG::TSActor *__fastcall UFG::TSSimObject::AsInstanceSimOrActor(UFG::SimObject *obj, SSInstance *pAssociated)
{
  SSInstance *v2; // rdi
  UFG::SimObject *v3; // rbx
  unsigned __int16 v5; // cx
  UFG::TSActorComponent *v6; // rax

  v2 = pAssociated;
  v3 = obj;
  if ( pAssociated
    && (pAssociated->vfptr->is_actor((SSObjectBase *)pAssociated) || v2->i_class_p == UFG::TSSimObject::mspSimObjectClass) )
  {
    return (UFG::TSActor *)v2;
  }
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = (UFG::TSActorComponent *)v3->m_Components.p[4].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
        v6 = (UFG::TSActorComponent *)v3->m_Components.p[3].m_pComponent;
      else
        v6 = (UFG::TSActorComponent *)((v5 >> 12) & 1 ? v3->m_Components.p[2].m_pComponent : UFG::SimObject::GetComponentOfType(
                                                                                               v3,
                                                                                               UFG::TSActorComponent::_TypeUID));
    }
    else
    {
      v6 = (UFG::TSActorComponent *)v3->m_Components.p[4].m_pComponent;
    }
    if ( v6 )
      return UFG::TSActorComponent::GetActor(v6);
  }
  return (UFG::TSActor *)SSInstance::pool_new(UFG::TSSimObject::mspSimObjectClass, (unsigned __int64)v3);
}

// File Line: 153
// RVA: 0x4E0FB0
UFG::qBaseNodeRB *__fastcall UFG::TSSimObject::GetArgByNameOrInstance(SSInvokedContextBase *pScope, unsigned int argPos)
{
  SSInstance *v2; // rbx
  SSActorClass *v3; // rcx
  UFG::qBaseNodeRB *result; // rax
  SSClass *v5; // rcx

  v2 = pScope->i_data.i_array_p[argPos]->i_data_p;
  if ( !v2 )
    goto LABEL_13;
  v3 = (SSActorClass *)v2->i_class_p;
  if ( v3 == (SSActorClass *)UFG::TSSimObject::mspSimObjectClass )
    return (UFG::qBaseNodeRB *)v2->i_user_data;
  if ( v3 == (SSActorClass *)SSBrain::c_symbol_class_p )
    return UFG::Simulation::GetSimObject(&UFG::gSim, (UFG::qSymbol *)&v2->i_user_data);
  if ( SSBrain::c_physical_actor_class_p == v3
    || (v5 = v3->i_superclass_p) != 0i64 && SSClass::is_class(v5, (SSClass *)&SSBrain::c_physical_actor_class_p->vfptr) )
  {
    result = *(UFG::qBaseNodeRB **)&v2[4].i_ref_count;
  }
  else
  {
LABEL_13:
    result = 0i64;
  }
  return result;
}

// File Line: 187
// RVA: 0x4CC5B0
void __fastcall UFG::TSSimObject::AddSimObjectsToList(SSList *ssList, UFG::qArray<UFG::SceneObjectProperties *,0> *sceneObjsPtr)
{
  UFG::qArray<UFG::SceneObjectProperties *,0> *v2; // rsi
  SSList *v3; // rbp
  __int64 v4; // rdi
  __int64 v5; // rbx
  unsigned __int64 v6; // rdx
  SSInstance *v7; // rax

  if ( sceneObjsPtr )
  {
    v2 = sceneObjsPtr;
    v3 = ssList;
    if ( sceneObjsPtr->size )
    {
      v4 = sceneObjsPtr->size;
      v5 = 0i64;
      do
      {
        v6 = (unsigned __int64)v2->p[v5]->m_pSimObject;
        if ( v6 )
        {
          v7 = SSInstance::pool_new(UFG::TSSimObject::mspSimObjectClass, v6);
          SSList::append(v3, v7, 1);
        }
        ++v5;
        --v4;
      }
      while ( v4 );
    }
  }
}

// File Line: 208
// RVA: 0x4F4F00
void __fastcall UFG::TSSimObject::Mthd_as_actor(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // r8
  SSObjectBase *v3; // rcx

  if ( ppResult )
  {
    v2 = pScope;
    v3 = pScope->i_scope_p.i_obj_p;
    if ( !v3 || v2->i_scope_p.i_ptr_id != v3->i_ptr_id )
      v3 = 0i64;
    *ppResult = (SSInstance *)UFG::TSActor::SkookumObjFromSimObj((UFG::SimObject *)v3[2].vfptr);
  }
}

// File Line: 244
// RVA: 0x4E4AB0
void __fastcall UFG::TSSimObject::MthdC_delete(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::qBaseNodeRB *v2; // rax

  v2 = UFG::TSSimObject::GetArgByNameOrInstance((SSInvokedContextBase *)&pScope->vfptr, 0);
  if ( v2 )
    UFG::Simulation::QueueSimObjectToBeDestroyed(&UFG::gSim, (UFG::SimObject *)v2);
}

// File Line: 259
// RVA: 0x4F9020
void __fastcall UFG::TSSimObject::Mthd_enable_physics(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  SSObjectBase *v3; // rcx
  UFG::SimObjectGame *v4; // rcx
  unsigned __int16 v5; // dx
  UFG::RigidBody *v6; // rax
  unsigned int v7; // edx

  v2 = pScope;
  v3 = pScope->i_scope_p.i_obj_p;
  if ( !v3 || v2->i_scope_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  v4 = (UFG::SimObjectGame *)v3[2].vfptr;
  if ( v4 )
  {
    v5 = v4->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::RigidBodyComponent::_TypeUID);
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
        v6 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::RigidBodyComponent::_TypeUID);
      else
        v6 = (UFG::RigidBody *)((v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   v4,
                                                   UFG::RigidBodyComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                          (UFG::SimObject *)&v4->vfptr,
                                                                                          UFG::RigidBodyComponent::_TypeUID));
    }
    else
    {
      v6 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::RigidBodyComponent::_TypeUID);
    }
    if ( v6 )
    {
      v7 = 0x100;
      if ( (*v2->i_data.i_array_p)->i_data_p->i_user_data )
        v7 = 0x80;
      UFG::RigidBody::SetMotionType(v6, v7);
    }
  }
}

// File Line: 273
// RVA: 0x4E7090
void __fastcall UFG::TSSimObject::MthdC_getInstances(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // r14
  SSList *v3; // rax
  SSList *v4; // rsi
  UFG::qBaseTreeRB *i; // rax
  unsigned __int64 v6; // rbx
  SSInstance *v7; // rax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = (SSList *)AMemory::c_malloc_func(0x18ui64, "SSList");
    v4 = v3;
    if ( v3 )
    {
      v3->i_items.i_count = 0;
      v3->i_items.i_array_p = 0i64;
      v3->i_items.i_size = 0;
      v3->i_items.i_array_p = (SSInstance **)AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
    }
    else
    {
      v4 = 0i64;
    }
    for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::gSim);
          ;
          i = UFG::qBaseTreeRB::GetNext(&UFG::gSim.mSimObjects.mTree, (UFG::qBaseNodeRB *)(v6 + 40)) )
    {
      v6 = (unsigned __int64)(i ? &i[-1].mNULL : 0i64);
      if ( !v6 )
        break;
      v7 = SSInstance::pool_new(UFG::TSSimObject::mspSimObjectClass, v6);
      SSList::append(v4, v7, 1);
    }
    *v2 = SSList::as_instance(v4);
  }
}

// File Line: 291
// RVA: 0x4E85D0
void __fastcall UFG::TSSimObject::MthdC_get_prefab_objects(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rsi
  UFG::SimObjectGame *v3; // rax
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  UFG::SimComponent *v6; // rdi
  SSList *v7; // rbx
  UFG::qSymbol name; // [rsp+48h] [rbp+10h]
  SSList *v9; // [rsp+50h] [rbp+18h]

  if ( ppResult )
  {
    v2 = ppResult;
    name.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    v3 = (UFG::SimObjectGame *)UFG::Simulation::GetSimObject(&UFG::gSim, &name);
    if ( v3 )
    {
      v4 = v3->m_Flags;
      if ( (v4 >> 14) & 1 )
      {
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::PrefabComponent::_TypeUID);
      }
      else if ( (v4 & 0x8000u) == 0 )
      {
        if ( (v4 >> 13) & 1 )
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::PrefabComponent::_TypeUID);
        else
          v5 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::PrefabComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::PrefabComponent::_TypeUID);
      }
      else
      {
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::PrefabComponent::_TypeUID);
      }
      v6 = v5;
      if ( v5 )
      {
        v7 = (SSList *)AMemory::c_malloc_func(0x18ui64, "SSList");
        v9 = v7;
        if ( v7 )
        {
          v7->i_items.i_count = 0;
          v7->i_items.i_array_p = 0i64;
          v7->i_items.i_size = 0;
          v7->i_items.i_array_p = (SSInstance **)AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
        }
        else
        {
          v7 = 0i64;
        }
        UFG::TSSimObject::AddSimObjectsToList(v7, (UFG::qArray<UFG::SceneObjectProperties *,0> *)&v6[1].m_TypeUID);
        *v2 = SSList::as_instance(v7);
      }
    }
  }
}

// File Line: 317
// RVA: 0x4E6630
void __fastcall UFG::TSSimObject::MthdC_find_named(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rdi
  SSInstance *v3; // rdx
  UFG::qSymbol *v4; // rax
  UFG::qBaseNodeRB *v5; // rax
  UFG::qSymbol name; // [rsp+48h] [rbp+10h]
  ASymbol result; // [rsp+50h] [rbp+18h]

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = (*pScope->i_data.i_array_p)->i_data_p;
    if ( v3->i_class_p == SSBrain::c_symbol_class_p )
    {
      name.mUID = v3->i_user_data;
      v4 = &name;
    }
    else
    {
      v4 = (UFG::qSymbol *)ASymbol::create(&result, (AString *)&v3->i_user_data, 0);
    }
    name.mUID = v4->mUID;
    v5 = UFG::Simulation::GetSimObject(&UFG::gSim, &name);
    if ( v5 )
      *v2 = SSInstance::pool_new(UFG::TSSimObject::mspSimObjectClass, (unsigned __int64)v5);
    else
      *v2 = SSBrain::c_nil_p;
  }
}

// File Line: 340
// RVA: 0x4E84A0
void __fastcall UFG::TSSimObject::MthdC_get_named_rigidbody(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *v3; // rax
  unsigned __int64 v4; // rdx

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = (UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *)&UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mNext[-18].mNext;
    if ( &UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mNext[-18].mNext == (UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> **)((char *)&UFG::RigidBodyComponent::s_RigidBodyComponentList - 280) )
    {
LABEL_5:
      *v2 = SSBrain::c_nil_p;
    }
    else
    {
      while ( 1 )
      {
        v4 = (unsigned __int64)v3[2].mNode.mNext;
        if ( *(_DWORD *)(v4 + 64) == LODWORD((*pScope->i_data.i_array_p)->i_data_p->i_user_data) )
          break;
        v3 = (UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *)&v3[18].mNode.mPrev[-18].mNext;
        if ( v3 == (UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *)((char *)&UFG::RigidBodyComponent::s_RigidBodyComponentList
                                                                                     - 280) )
          goto LABEL_5;
      }
      *v2 = SSInstance::pool_new(UFG::TSSimObject::mspSimObjectClass, v4);
    }
  }
}

// File Line: 376
// RVA: 0x4FD220
void __fastcall UFG::TSSimObject::Mthd_get_health_ratio(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rbx
  float v3; // xmm6_4
  SSInstance **v4; // rdi
  UFG::SimObjectGame *v5; // rbx
  unsigned __int16 v6; // cx
  UFG::SimComponent *v7; // rax
  unsigned __int16 v8; // cx
  UFG::SimComponent *v9; // rax
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v10; // rcx

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    v3 = *(float *)&FLOAT_1_0;
    v4 = ppResult;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v5 = (UFG::SimObjectGame *)v2[2].vfptr;
    if ( v5 )
    {
      v6 = v5->m_Flags;
      if ( (v6 >> 14) & 1 )
      {
        v7 = v5->m_Components.p[6].m_pComponent;
      }
      else if ( (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
        {
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::HealthComponent::_TypeUID);
        }
        else if ( (v6 >> 12) & 1 )
        {
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::HealthComponent::_TypeUID);
        }
        else
        {
          v7 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::HealthComponent::_TypeUID);
        }
      }
      else
      {
        v7 = v5->m_Components.p[6].m_pComponent;
      }
      if ( v7 )
      {
        v3 = *((float *)&v7[1].m_SafePointerList.mNode.mNext + 1) / *(float *)&v7[1].m_NameUID;
      }
      else
      {
        v8 = v5->m_Flags;
        if ( (v8 >> 14) & 1 )
        {
          v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::RigidBodyComponent::_TypeUID);
        }
        else if ( (v8 & 0x8000u) == 0 )
        {
          if ( (v8 >> 13) & 1 )
          {
            v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::RigidBodyComponent::_TypeUID);
          }
          else if ( (v8 >> 12) & 1 )
          {
            v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::RigidBodyComponent::_TypeUID);
          }
          else
          {
            v9 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::RigidBodyComponent::_TypeUID);
          }
        }
        else
        {
          v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::RigidBodyComponent::_TypeUID);
        }
        if ( v9 )
        {
          v10 = v9[6].vfptr;
          if ( v10 )
            v3 = *((float *)&v10[33].__vecDelDtor + 1);
          if ( v3 <= 0.0 )
            v3 = 0.0;
        }
      }
    }
    *v4 = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(v3));
  }
}

// File Line: 410
// RVA: 0x4FD710
void __fastcall UFG::TSSimObject::Mthd_get_name(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // r8
  SSObjectBase *v3; // rcx

  if ( ppResult )
  {
    v2 = pScope;
    v3 = pScope->i_scope_p.i_obj_p;
    if ( !v3 || v2->i_scope_p.i_ptr_id != v3->i_ptr_id )
      v3 = 0i64;
    *ppResult = SSSymbol::as_instance((ASymbol *)&v3[2].vfptr[1].get_obj_type);
  }
}

// File Line: 425
// RVA: 0x4E83B0
void __fastcall UFG::TSSimObject::MthdC_get_named(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  UFG::qBaseNodeRB *v3; // rax
  UFG::qSymbol name; // [rsp+38h] [rbp+10h]

  if ( ppResult )
  {
    v2 = ppResult;
    name.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    v3 = UFG::Simulation::GetSimObject(&UFG::gSim, &name);
    if ( v3 )
      *v2 = SSInstance::pool_new(UFG::TSSimObject::mspSimObjectClass, (unsigned __int64)v3);
    else
      *v2 = SSBrain::c_nil_p;
  }
}

// File Line: 490
// RVA: 0x4FDF20
void __fastcall UFG::TSSimObject::Mthd_get_properties(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  SSInstance **v3; // rdi
  UFG::SceneObjectProperties *v4; // rcx
  UFG::qPropertySet *v5; // rbx

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    v3 = ppResult;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v4 = (UFG::SceneObjectProperties *)v2[2].vfptr[1].is_actor;
    if ( v4 )
    {
      v5 = UFG::SceneObjectProperties::GetWritableProperties(v4);
      UFG::qPropertySet::AddRef(v5);
      *v3 = SSInstance::pool_new(UFG::SkookumMgr::mspPropertySetClass, (unsigned __int64)v5);
    }
  }
}

// File Line: 508
// RVA: 0x4FF700
void __fastcall UFG::TSSimObject::Mthd_get_xform(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  UFG::TransformNodeComponent *v3; // r9
  SSObjectBaseVtbl *v4; // rax
  UFG::TransformNodeComponent *v5; // rcx

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    v3 = 0i64;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v4 = v2[2].vfptr;
    if ( v4 )
      v3 = (UFG::TransformNodeComponent *)v4[1].as_instance;
    v5 = &UFG::TransformNodeComponent::sIdentityNode;
    if ( v3 )
      v5 = v3;
    *ppResult = UFG::TSTransform::AsInstance(v5);
  }
}

// File Line: 524
// RVA: 0x5017D0
void __fastcall UFG::TSSimObject::Mthd_is_highlighted(SSInvokedMethod *pScope, SSInstance **ppResult)
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
    v5 = UFG::IsHighlightSimObject((UFG::SimObject *)v3[2].vfptr);
    *v4 = (SSInstance *)SSBoolean::pool_new(v5);
  }
}

// File Line: 538
// RVA: 0x508B00
void __fastcall UFG::TSSimObject::Mthd_set_is_highlighted(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx
  UFG::SimObject *v3; // rbx
  UFG::RadarSystem *v4; // rax
  UFG::RadarSystem *v5; // rax

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = (UFG::SimObject *)v2[2].vfptr;
  if ( v3 )
  {
    if ( (*pScope->i_data.i_array_p)->i_data_p->i_user_data )
    {
      v4 = UFG::RadarSystem::Instance();
      UFG::RadarSystem::AddRimLight(v4, v3);
    }
    else
    {
      v5 = UFG::RadarSystem::Instance();
      UFG::RadarSystem::RemoveRimLight(v5, v3);
    }
  }
}

// File Line: 559
// RVA: 0x4D62A0
void UFG::TSSimObject::BindAtomics(void)
{
  UFG::TSSimObject::mspSimObjectClass = SSBrain::get_class("SimObject");
  SSClass::register_method_func(UFG::TSSimObject::mspSimObjectClass, &ASymbol_Actor, UFG::TSSimObject::Mthd_as_actor, 0);
  SSClass::register_method_func(UFG::TSSimObject::mspSimObjectClass, "as_actor", UFG::TSSimObject::Mthd_as_actor, 0);
  SSClass::register_method_func(
    UFG::TSSimObject::mspSimObjectClass,
    "enable_physics",
    UFG::TSSimObject::Mthd_enable_physics,
    0);
  SSClass::register_method_func(
    UFG::TSSimObject::mspSimObjectClass,
    "get_health_ratio",
    UFG::TSSimObject::Mthd_get_health_ratio,
    0);
  SSClass::register_method_func(UFG::TSSimObject::mspSimObjectClass, "get_name", UFG::TSSimObject::Mthd_get_name, 0);
  SSClass::register_method_func(
    UFG::TSSimObject::mspSimObjectClass,
    "get_properties",
    UFG::TSSimObject::Mthd_get_properties,
    0);
  SSClass::register_method_func(UFG::TSSimObject::mspSimObjectClass, "get_xform", UFG::TSSimObject::Mthd_get_xform, 0);
  SSClass::register_method_func(
    UFG::TSSimObject::mspSimObjectClass,
    "is_highlighted",
    UFG::TSSimObject::Mthd_is_highlighted,
    0);
  SSClass::register_method_func(
    UFG::TSSimObject::mspSimObjectClass,
    "enable_highlight",
    UFG::TSSimObject::Mthd_set_is_highlighted,
    0);
  SSClass::register_method_func(
    UFG::TSSimObject::mspSimObjectClass,
    "getInstances",
    UFG::TSSimObject::MthdC_getInstances,
    1,
    0);
  SSClass::register_method_func(
    UFG::TSSimObject::mspSimObjectClass,
    "get_prefab_objects",
    UFG::TSSimObject::MthdC_get_prefab_objects,
    1,
    0);
  SSClass::register_method_func(UFG::TSSimObject::mspSimObjectClass, "delete", UFG::TSSimObject::MthdC_delete, 1, 0);
  SSClass::register_method_func(
    UFG::TSSimObject::mspSimObjectClass,
    "find_named",
    UFG::TSSimObject::MthdC_find_named,
    1,
    0);
  SSClass::register_method_func(
    UFG::TSSimObject::mspSimObjectClass,
    "find_named_rigidbody",
    UFG::TSSimObject::MthdC_get_named_rigidbody,
    1,
    0);
  SSClass::register_method_func(
    UFG::TSSimObject::mspSimObjectClass,
    "get_named",
    UFG::TSSimObject::MthdC_get_named,
    1,
    0);
  SSClass::register_method_func(
    UFG::TSSimObject::mspSimObjectClass,
    "get_named_rigidbody",
    UFG::TSSimObject::MthdC_get_named_rigidbody,
    1,
    0);
}

