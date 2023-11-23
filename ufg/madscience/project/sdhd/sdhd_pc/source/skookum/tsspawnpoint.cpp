// File Line: 66
// RVA: 0x4D6CD0
void UFG::TSSpawnPoint::BindAtomics(void)
{
  ASymbol rebind; // [rsp+20h] [rbp-18h]
  ASymbol rebinda; // [rsp+20h] [rbp-18h]
  ASymbol rebindb; // [rsp+20h] [rbp-18h]
  ASymbol rebindc; // [rsp+20h] [rbp-18h]

  LOBYTE(rebind.i_uid) = 0;
  UFG::TSSpawnPoint::mspSpawnPointClass = SSBrain::get_class("SpawnPoint");
  SSClass::register_method_func(
    UFG::TSSpawnPoint::mspSpawnPointClass,
    "find_named",
    UFG::TSSpawnPoint::MthdC_find_named,
    1,
    rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(
    UFG::TSSpawnPoint::mspSpawnPointClass,
    "get_named",
    UFG::TSSpawnPoint::MthdC_get_named,
    1,
    rebinda);
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_func(
    UFG::TSSpawnPoint::mspSpawnPointClass,
    "spawn",
    UFG::TSSpawnPoint::MthdC_spawn,
    1,
    rebindb);
  LOBYTE(rebindc.i_uid) = 0;
  SSClass::register_method_func(
    UFG::TSSpawnPoint::mspSpawnPointClass,
    "set_spawn_target",
    UFG::TSSpawnPoint::MthdC_set_spawn_target,
    1,
    rebindc);
}

// File Line: 86
// RVA: 0x5112B0
AString *__fastcall UFG::TSSpawnPoint_spawnTypeStr(AString *result, UFG::SpawnPoint *pSpawnPoint)
{
  UFG::SceneObjectProperties *m_pSceneObj; // rcx
  UFG::SimObject *m_pSimObject; // rax
  UFG::SceneObjectProperties *ChildAsSceneObject; // rax
  UFG::qSymbolUC *ArchetypePropertiesName; // rax
  char *v7; // rax
  unsigned int v8; // eax

  m_pSceneObj = 0i64;
  m_pSimObject = pSpawnPoint->m_pSimObject;
  if ( m_pSimObject )
    m_pSceneObj = m_pSimObject->m_pSceneObj;
  if ( m_pSceneObj->mChildren.mCount
    && (ChildAsSceneObject = UFG::SceneObjectProperties::GetChildAsSceneObject(m_pSceneObj, 0)) != 0i64 )
  {
    ArchetypePropertiesName = (UFG::qSymbolUC *)UFG::SceneObjectProperties::GetArchetypePropertiesName(ChildAsSceneObject);
    v7 = UFG::qSymbol::as_cstr_dbg(ArchetypePropertiesName);
    AString::AString(result, v7);
  }
  else
  {
    v8 = AMemory::c_req_byte_size_func(0x14u);
    result->i_str_ref_p = AStringRef::pool_new("[empty/no children]", 0x13u, v8, 1u, 0, 1);
  }
  return result;
}

// File Line: 113
// RVA: 0x4F1E90
void __fastcall UFG::TSSpawnPoint::MthdC_spawn(SSInvokedMethod *pScope, UFG::TSActor **ppResult)
{
  SSInstance *i_data_p; // r8
  UFG::SimObject *i_user_data; // rcx
  UFG::SpawnPoint *ComponentOfType; // rax
  UFG::SpawnPoint *v7; // rdi
  UFG::SimObjectGame *v8; // rax
  UFG::TSActorComponent *v9; // rax
  UFG::TSActor *Actor; // rax
  UFG::SimObject *m_pSimObject; // rax
  UFG::SceneObjectProperties *m_pSceneObj; // rcx
  UFG::SceneObjectProperties *ChildAsSceneObject; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qSymbol *SpawnPriority; // rax
  char *i_cstr_p; // rbx
  char *v17; // rax
  AStringRef *i_str_ref_p; // rbx
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v23; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx
  UFG::SpawnInfoInterface::SpawnPriority pPriority; // [rsp+40h] [rbp+8h] BYREF
  AString result; // [rsp+48h] [rbp+10h] BYREF

  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  if ( i_data_p && i_data_p->i_class_p == UFG::TSSimObject::mspSimObjectClass )
  {
    i_user_data = (UFG::SimObject *)i_data_p->i_user_data;
    if ( !i_user_data )
      goto LABEL_25;
    ComponentOfType = (UFG::SpawnPoint *)UFG::SimObject::GetComponentOfType(i_user_data, UFG::SpawnPoint::_TypeUID);
  }
  else
  {
    ComponentOfType = UFG::SpawnPoint::GetNamed((UFG::qSymbol *)&i_data_p->i_user_data);
  }
  v7 = ComponentOfType;
  if ( ComponentOfType )
  {
    v8 = UFG::SpawnPoint::Spawn(
           ComponentOfType,
           *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64) != 0i64,
           1);
    if ( v8 )
    {
      if ( !ppResult )
        return;
      v9 = (UFG::TSActorComponent *)UFG::SimObject::GetComponentOfType(v8, UFG::TSActorComponent::_TypeUID);
      if ( v9 )
      {
        Actor = UFG::TSActorComponent::GetActor(v9);
        goto LABEL_26;
      }
    }
    else
    {
      m_pSimObject = v7->m_pSimObject;
      if ( m_pSimObject )
        m_pSceneObj = m_pSimObject->m_pSceneObj;
      else
        m_pSceneObj = 0i64;
      ChildAsSceneObject = UFG::SceneObjectProperties::GetChildAsSceneObject(m_pSceneObj, 0);
      mpWritableProperties = ChildAsSceneObject->mpWritableProperties;
      if ( !mpWritableProperties )
        mpWritableProperties = ChildAsSceneObject->mpConstProperties;
      SpawnPriority = UFG::SpawnInfoInterface::GetSpawnPriority(mpWritableProperties, &pPriority);
      if ( SpawnPriority->mUID == qSymbol_Low.mUID || SpawnPriority->mUID == qSymbol_Medium.mUID )
      {
        i_cstr_p = UFG::TSSpawnPoint_spawnTypeStr(&result, v7)->i_str_ref_p->i_cstr_p;
        v17 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v7->UFG::qNamed);
        UFG::qPrintf("Warning: Low/medium priority spawn point %s couldnt spawn type %s.\n", v17, i_cstr_p);
        i_str_ref_p = result.i_str_ref_p;
        if ( result.i_str_ref_p->i_ref_count-- == 1 )
        {
          if ( i_str_ref_p->i_deallocate )
            AMemory::c_free_func(i_str_ref_p->i_cstr_p);
          pool = AStringRef::get_pool();
          i_block_p = pool->i_block_p;
          i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
          if ( (unsigned __int64)i_str_ref_p < i_objects_a
            || (v23 = (unsigned __int64)i_str_ref_p < i_objects_a + 24i64 * i_block_p->i_size,
                p_i_exp_pool = &pool->i_pool,
                !v23) )
          {
            p_i_exp_pool = &pool->i_exp_pool;
          }
          APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, i_str_ref_p);
        }
      }
    }
  }
LABEL_25:
  Actor = (UFG::TSActor *)SSBrain::c_nil_p;
LABEL_26:
  if ( ppResult )
  {
    ++Actor->i_ref_count;
    *ppResult = Actor;
  }
}

// File Line: 216
// RVA: 0x4E6700
void __fastcall UFG::TSSpawnPoint::MthdC_find_named(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SpawnPoint *Named; // rax

  if ( ppResult )
  {
    Named = UFG::SpawnPoint::GetNamed((UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    if ( Named )
      *ppResult = SSInstance::pool_new(UFG::TSSpawnPoint::mspSpawnPointClass, (unsigned __int64)Named);
    else
      *ppResult = SSBrain::c_nil_p;
  }
}

// File Line: 234
// RVA: 0x4E8410
void __fastcall UFG::TSSpawnPoint::MthdC_get_named(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SpawnPoint *Named; // rax

  if ( ppResult )
  {
    Named = UFG::SpawnPoint::GetNamed((UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    *ppResult = SSInstance::pool_new(UFG::TSSpawnPoint::mspSpawnPointClass, (unsigned __int64)Named);
  }
}

// File Line: 257
// RVA: 0x4EF120
void __fastcall UFG::TSSpawnPoint::MthdC_set_spawn_target(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *i_data_p; // rcx
  UFG::SimObject *i_user_data; // rcx
  UFG::SpawnPoint *ComponentOfType; // rax
  UFG::SpawnPoint *v6; // rbx
  UFG::qPropertySet *PropertySet; // rax
  UFG::qSymbol propSetName; // [rsp+30h] [rbp+8h] BYREF

  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  if ( i_data_p && i_data_p->i_class_p == UFG::TSSimObject::mspSimObjectClass )
  {
    i_user_data = (UFG::SimObject *)i_data_p->i_user_data;
    if ( !i_user_data )
      return;
    ComponentOfType = (UFG::SpawnPoint *)UFG::SimObject::GetComponentOfType(i_user_data, UFG::SpawnPoint::_TypeUID);
  }
  else
  {
    ComponentOfType = UFG::SpawnPoint::GetNamed((UFG::qSymbol *)&i_data_p->i_user_data);
  }
  v6 = ComponentOfType;
  if ( ComponentOfType )
  {
    if ( !Scaleform::GFx::InteractiveObject::GetResourceMovieDef(ComponentOfType) )
    {
      propSetName.mUID = *(_DWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64);
      if ( propSetName.mUID != -1 )
      {
        PropertySet = UFG::PropertySetManager::GetPropertySet(&propSetName);
        if ( PropertySet )
          UFG::SpawnPoint::SetNewSpawnTarget(v6, PropertySet);
      }
    }
  }
}

