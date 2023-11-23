// File Line: 128
// RVA: 0x4CC7C0
UFG::TSActor *__fastcall UFG::TSSimObject::AsInstanceSimOrActor(UFG::SimObject *obj, SSInstance *pAssociated)
{
  signed __int16 m_Flags; // cx
  UFG::TSActorComponent *m_pComponent; // rax

  if ( pAssociated
    && (pAssociated->vfptr->is_actor(pAssociated) || pAssociated->i_class_p == UFG::TSSimObject::mspSimObjectClass) )
  {
    return (UFG::TSActor *)pAssociated;
  }
  if ( obj )
  {
    m_Flags = obj->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::TSActorComponent *)obj->m_Components.p[4].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
        m_pComponent = (UFG::TSActorComponent *)obj->m_Components.p[3].m_pComponent;
      else
        m_pComponent = (UFG::TSActorComponent *)((m_Flags & 0x1000) != 0
                                               ? obj->m_Components.p[2].m_pComponent
                                               : UFG::SimObject::GetComponentOfType(
                                                   obj,
                                                   UFG::TSActorComponent::_TypeUID));
    }
    else
    {
      m_pComponent = (UFG::TSActorComponent *)obj->m_Components.p[4].m_pComponent;
    }
    if ( m_pComponent )
      return UFG::TSActorComponent::GetActor(m_pComponent);
  }
  return (UFG::TSActor *)SSInstance::pool_new(UFG::TSSimObject::mspSimObjectClass, (unsigned __int64)obj);
}

// File Line: 153
// RVA: 0x4E0FB0
UFG::qBaseNodeRB *__fastcall UFG::TSSimObject::GetArgByNameOrInstance(
        SSInvokedContextBase *pScope,
        unsigned int argPos)
{
  SSInstance *i_data_p; // rbx
  SSActorClass *i_class_p; // rcx
  SSClass *i_superclass_p; // rcx

  i_data_p = pScope->i_data.i_array_p[argPos]->i_data_p;
  if ( !i_data_p )
    return 0i64;
  i_class_p = (SSActorClass *)i_data_p->i_class_p;
  if ( i_class_p == UFG::TSSimObject::mspSimObjectClass )
    return (UFG::qBaseNodeRB *)i_data_p->i_user_data;
  if ( i_class_p == SSBrain::c_symbol_class_p )
    return UFG::Simulation::GetSimObject(&UFG::gSim, (UFG::qSymbol *)&i_data_p->i_user_data);
  if ( SSBrain::c_physical_actor_class_p == i_class_p )
    return *(UFG::qBaseNodeRB **)&i_data_p[4].i_ref_count;
  i_superclass_p = i_class_p->i_superclass_p;
  if ( i_superclass_p && SSClass::is_class(i_superclass_p, SSBrain::c_physical_actor_class_p) )
    return *(UFG::qBaseNodeRB **)&i_data_p[4].i_ref_count;
  else
    return 0i64;
}

// File Line: 187
// RVA: 0x4CC5B0
void __fastcall UFG::TSSimObject::AddSimObjectsToList(
        SSList *ssList,
        UFG::qArray<UFG::SceneObjectProperties *,0> *sceneObjsPtr)
{
  __int64 size; // rdi
  __int64 v5; // rbx
  UFG::SimObject *m_pSimObject; // rdx
  SSInstance *v7; // rax

  if ( sceneObjsPtr && sceneObjsPtr->size )
  {
    size = sceneObjsPtr->size;
    v5 = 0i64;
    do
    {
      m_pSimObject = sceneObjsPtr->p[v5]->m_pSimObject;
      if ( m_pSimObject )
      {
        v7 = SSInstance::pool_new(UFG::TSSimObject::mspSimObjectClass, (unsigned __int64)m_pSimObject);
        SSList::append(ssList, v7, 1);
      }
      ++v5;
      --size;
    }
    while ( size );
  }
}

// File Line: 208
// RVA: 0x4F4F00
void __fastcall UFG::TSSimObject::Mthd_as_actor(SSInvokedMethod *pScope, UFG::TSActor **ppResult)
{
  SSObjectBase *i_obj_p; // rcx

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *ppResult = UFG::TSActor::SkookumObjFromSimObj((UFG::SimObject *)i_obj_p[2].vfptr);
  }
}

// File Line: 244
// RVA: 0x4E4AB0
void __fastcall UFG::TSSimObject::MthdC_delete(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::qBaseNodeRB *ArgByNameOrInstance; // rax

  ArgByNameOrInstance = UFG::TSSimObject::GetArgByNameOrInstance(pScope, 0);
  if ( ArgByNameOrInstance )
    UFG::Simulation::QueueSimObjectToBeDestroyed(&UFG::gSim, (UFG::SimObject *)ArgByNameOrInstance);
}

// File Line: 259
// RVA: 0x4F9020
void __fastcall UFG::TSSimObject::Mthd_enable_physics(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rcx
  UFG::SimObjectGame *vfptr; // rcx
  __int16 m_Flags; // dx
  UFG::RigidBody *ComponentOfTypeHK; // rax
  unsigned int v7; // edx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = (UFG::SimObjectGame *)i_obj_p[2].vfptr;
  if ( vfptr )
  {
    m_Flags = vfptr->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              vfptr,
                                              UFG::RigidBodyComponent::_TypeUID);
    else
      ComponentOfTypeHK = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(vfptr, UFG::RigidBodyComponent::_TypeUID);
    if ( ComponentOfTypeHK )
    {
      v7 = 0x100;
      if ( (*pScope->i_data.i_array_p)->i_data_p->i_user_data )
        v7 = 0x80;
      UFG::RigidBody::SetMotionType(ComponentOfTypeHK, v7);
    }
  }
}

// File Line: 273
// RVA: 0x4E7090
void __fastcall UFG::TSSimObject::MthdC_getInstances(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSList *v3; // rax
  SSList *v4; // rsi
  UFG::qBaseTreeRB *i; // rax
  unsigned __int64 v6; // rbx
  SSInstance *v7; // rax

  if ( ppResult )
  {
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
      v6 = i ? (unsigned __int64)&i[-1].mNULL : 0i64;
      if ( !v6 )
        break;
      v7 = SSInstance::pool_new(UFG::TSSimObject::mspSimObjectClass, v6);
      SSList::append(v4, v7, 1);
    }
    *ppResult = SSList::as_instance(v4);
  }
}

// File Line: 291
// RVA: 0x4E85D0
void __fastcall UFG::TSSimObject::MthdC_get_prefab_objects(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectGame *SimObject; // rax
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimComponent *v6; // rdi
  SSList *v7; // rbx
  UFG::qSymbol name; // [rsp+48h] [rbp+10h] BYREF
  SSList *v9; // [rsp+50h] [rbp+18h]

  if ( ppResult )
  {
    name.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    SimObject = (UFG::SimObjectGame *)UFG::Simulation::GetSimObject(&UFG::gSim, &name);
    if ( SimObject )
    {
      m_Flags = SimObject->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(SimObject, UFG::PrefabComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(SimObject, UFG::PrefabComponent::_TypeUID);
      v6 = ComponentOfTypeHK;
      if ( ComponentOfTypeHK )
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
        *ppResult = SSList::as_instance(v7);
      }
    }
  }
}

// File Line: 317
// RVA: 0x4E6630
void __fastcall UFG::TSSimObject::MthdC_find_named(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *i_data_p; // rdx
  UFG::qSymbol *p_name; // rax
  UFG::qBaseNodeRB *SimObject; // rax
  UFG::qSymbol name; // [rsp+48h] [rbp+10h] BYREF
  ASymbol result; // [rsp+50h] [rbp+18h] BYREF

  if ( ppResult )
  {
    i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
    if ( i_data_p->i_class_p == SSBrain::c_symbol_class_p )
    {
      name.mUID = i_data_p->i_user_data;
      p_name = &name;
    }
    else
    {
      p_name = (UFG::qSymbol *)ASymbol::create(&result, (AString *)&i_data_p->i_user_data, ATerm_short);
    }
    name.mUID = p_name->mUID;
    SimObject = UFG::Simulation::GetSimObject(&UFG::gSim, &name);
    if ( SimObject )
      *ppResult = SSInstance::pool_new(UFG::TSSimObject::mspSimObjectClass, (unsigned __int64)SimObject);
    else
      *ppResult = SSBrain::c_nil_p;
  }
}

// File Line: 340
// RVA: 0x4E84A0
void __fastcall UFG::TSSimObject::MthdC_get_named_rigidbody(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *p_mNext; // rax
  unsigned __int64 mNext; // rdx

  if ( ppResult )
  {
    p_mNext = (UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *)&UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mNext[-18].mNext;
    if ( &UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mNext[-18].mNext == (UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> **)((char *)&UFG::RigidBodyComponent::s_RigidBodyComponentList - 280) )
    {
LABEL_5:
      *ppResult = SSBrain::c_nil_p;
    }
    else
    {
      while ( 1 )
      {
        mNext = (unsigned __int64)p_mNext[2].mNode.mNext;
        if ( *(_DWORD *)(mNext + 64) == LODWORD((*pScope->i_data.i_array_p)->i_data_p->i_user_data) )
          break;
        p_mNext = (UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *)&p_mNext[18].mNode.mPrev[-18].mNext;
        if ( p_mNext == (UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *)((char *)&UFG::RigidBodyComponent::s_RigidBodyComponentList
                                                                                          - 280) )
          goto LABEL_5;
      }
      *ppResult = SSInstance::pool_new(UFG::TSSimObject::mspSimObjectClass, mNext);
    }
  }
}

// File Line: 376
// RVA: 0x4FD220
void __fastcall UFG::TSSimObject::Mthd_get_health_ratio(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rbx
  float v3; // xmm6_4
  UFG::SimObjectGame *vfptr; // rbx
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rax
  __int16 v8; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v10; // rcx

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    v3 = *(float *)&FLOAT_1_0;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = (UFG::SimObjectGame *)i_obj_p[2].vfptr;
    if ( vfptr )
    {
      m_Flags = vfptr->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = vfptr->m_Components.p[6].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(vfptr, UFG::HealthComponent::_TypeUID);
        else
          m_pComponent = UFG::SimObject::GetComponentOfType(vfptr, UFG::HealthComponent::_TypeUID);
      }
      else
      {
        m_pComponent = vfptr->m_Components.p[6].m_pComponent;
      }
      if ( m_pComponent )
      {
        v3 = *((float *)&m_pComponent[1].m_SafePointerList.mNode.mNext + 1) / *(float *)&m_pComponent[1].m_NameUID;
      }
      else
      {
        v8 = vfptr->m_Flags;
        if ( (v8 & 0x4000) != 0 || v8 < 0 || (v8 & 0x2000) != 0 || (v8 & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(vfptr, UFG::RigidBodyComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(vfptr, UFG::RigidBodyComponent::_TypeUID);
        if ( ComponentOfTypeHK )
        {
          v10 = ComponentOfTypeHK[6].vfptr;
          if ( v10 )
            v3 = *((float *)&v10[33].__vecDelDtor + 1);
          if ( v3 <= 0.0 )
            v3 = 0.0;
        }
      }
    }
    *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(v3));
  }
}

// File Line: 410
// RVA: 0x4FD710
void __fastcall UFG::TSSimObject::Mthd_get_name(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rcx

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    *ppResult = SSSymbol::as_instance((ASymbol *)&i_obj_p[2].vfptr[1].get_obj_type);
  }
}

// File Line: 425
// RVA: 0x4E83B0
void __fastcall UFG::TSSimObject::MthdC_get_named(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::qBaseNodeRB *SimObject; // rax
  UFG::qSymbol name; // [rsp+38h] [rbp+10h] BYREF

  if ( ppResult )
  {
    name.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    SimObject = UFG::Simulation::GetSimObject(&UFG::gSim, &name);
    if ( SimObject )
      *ppResult = SSInstance::pool_new(UFG::TSSimObject::mspSimObjectClass, (unsigned __int64)SimObject);
    else
      *ppResult = SSBrain::c_nil_p;
  }
}

// File Line: 490
// RVA: 0x4FDF20
void __fastcall UFG::TSSimObject::Mthd_get_properties(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  UFG::SceneObjectProperties *is_actor; // rcx
  UFG::qPropertySet *WritableProperties; // rbx

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    is_actor = (UFG::SceneObjectProperties *)i_obj_p[2].vfptr[1].is_actor;
    if ( is_actor )
    {
      WritableProperties = UFG::SceneObjectProperties::GetWritableProperties(is_actor);
      UFG::qPropertySet::AddRef(WritableProperties);
      *ppResult = SSInstance::pool_new(UFG::SkookumMgr::mspPropertySetClass, (unsigned __int64)WritableProperties);
    }
  }
}

// File Line: 508
// RVA: 0x4FF700
void __fastcall UFG::TSSimObject::Mthd_get_xform(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  UFG::TransformNodeComponent *as_instance; // r9
  SSObjectBaseVtbl *vfptr; // rax
  UFG::TransformNodeComponent *v5; // rcx

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    as_instance = 0i64;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = i_obj_p[2].vfptr;
    if ( vfptr )
      as_instance = (UFG::TransformNodeComponent *)vfptr[1].as_instance;
    v5 = &UFG::TransformNodeComponent::sIdentityNode;
    if ( as_instance )
      v5 = as_instance;
    *ppResult = UFG::TSTransform::AsInstance(v5);
  }
}

// File Line: 524
// RVA: 0x5017D0
void __fastcall UFG::TSSimObject::Mthd_is_highlighted(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rcx
  bool IsHighlightSimObject; // al

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    IsHighlightSimObject = UFG::IsHighlightSimObject((UFG::SimObject *)i_obj_p[2].vfptr);
    *ppResult = SSBoolean::pool_new(IsHighlightSimObject);
  }
}

// File Line: 538
// RVA: 0x508B00
void __fastcall UFG::TSSimObject::Mthd_set_is_highlighted(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *vfptr; // rbx
  UFG::RadarSystem *v4; // rax
  UFG::RadarSystem *v5; // rax

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = (UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *)i_obj_p[2].vfptr;
  if ( vfptr )
  {
    if ( (*pScope->i_data.i_array_p)->i_data_p->i_user_data )
    {
      v4 = UFG::RadarSystem::Instance();
      UFG::RadarSystem::AddRimLight(v4, vfptr);
    }
    else
    {
      v5 = UFG::RadarSystem::Instance();
      UFG::RadarSystem::RemoveRimLight(v5, (UFG::SimObject *)vfptr);
    }
  }
}

// File Line: 559
// RVA: 0x4D62A0
void UFG::TSSimObject::BindAtomics(void)
{
  ASymbol rebind; // [rsp+20h] [rbp-18h]
  ASymbol rebinda; // [rsp+20h] [rbp-18h]
  ASymbol rebindb; // [rsp+20h] [rbp-18h]
  ASymbol rebindc; // [rsp+20h] [rbp-18h]
  ASymbol rebindd; // [rsp+20h] [rbp-18h]
  ASymbol rebinde; // [rsp+20h] [rbp-18h]
  ASymbol rebindf; // [rsp+20h] [rbp-18h]

  UFG::TSSimObject::mspSimObjectClass = SSBrain::get_class("SimObject");
  SSClass::register_method_func(
    UFG::TSSimObject::mspSimObjectClass,
    &ASymbol_Actor,
    UFG::TSSimObject::Mthd_as_actor,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSSimObject::mspSimObjectClass,
    "as_actor",
    UFG::TSSimObject::Mthd_as_actor,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSSimObject::mspSimObjectClass,
    "enable_physics",
    UFG::TSSimObject::Mthd_enable_physics,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSSimObject::mspSimObjectClass,
    "get_health_ratio",
    UFG::TSSimObject::Mthd_get_health_ratio,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSSimObject::mspSimObjectClass,
    "get_name",
    UFG::TSSimObject::Mthd_get_name,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSSimObject::mspSimObjectClass,
    "get_properties",
    UFG::TSSimObject::Mthd_get_properties,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSSimObject::mspSimObjectClass,
    "get_xform",
    UFG::TSSimObject::Mthd_get_xform,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSSimObject::mspSimObjectClass,
    "is_highlighted",
    UFG::TSSimObject::Mthd_is_highlighted,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSSimObject::mspSimObjectClass,
    "enable_highlight",
    UFG::TSSimObject::Mthd_set_is_highlighted,
    SSBindFlag_instance_no_rebind);
  LOBYTE(rebind.i_uid) = 0;
  SSClass::register_method_func(
    UFG::TSSimObject::mspSimObjectClass,
    "getInstances",
    UFG::TSSimObject::MthdC_getInstances,
    1,
    rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(
    UFG::TSSimObject::mspSimObjectClass,
    "get_prefab_objects",
    UFG::TSSimObject::MthdC_get_prefab_objects,
    1,
    rebinda);
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_func(
    UFG::TSSimObject::mspSimObjectClass,
    "delete",
    UFG::TSSimObject::MthdC_delete,
    1,
    rebindb);
  LOBYTE(rebindc.i_uid) = 0;
  SSClass::register_method_func(
    UFG::TSSimObject::mspSimObjectClass,
    "find_named",
    UFG::TSSimObject::MthdC_find_named,
    1,
    rebindc);
  LOBYTE(rebindd.i_uid) = 0;
  SSClass::register_method_func(
    UFG::TSSimObject::mspSimObjectClass,
    "find_named_rigidbody",
    UFG::TSSimObject::MthdC_get_named_rigidbody,
    1,
    rebindd);
  LOBYTE(rebinde.i_uid) = 0;
  SSClass::register_method_func(
    UFG::TSSimObject::mspSimObjectClass,
    "get_named",
    UFG::TSSimObject::MthdC_get_named,
    1,
    rebinde);
  LOBYTE(rebindf.i_uid) = 0;
  SSClass::register_method_func(
    UFG::TSSimObject::mspSimObjectClass,
    "get_named_rigidbody",
    UFG::TSSimObject::MthdC_get_named_rigidbody,
    1,
    rebindf);
}

