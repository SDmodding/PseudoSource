// File Line: 66
// RVA: 0x4D6CD0
void UFG::TSSpawnPoint::BindAtomics(void)
{
  UFG::TSSpawnPoint::mspSpawnPointClass = SSBrain::get_class("SpawnPoint");
  SSClass::register_method_func(
    UFG::TSSpawnPoint::mspSpawnPointClass,
    "find_named",
    UFG::TSSpawnPoint::MthdC_find_named,
    1,
    0);
  SSClass::register_method_func(
    UFG::TSSpawnPoint::mspSpawnPointClass,
    "get_named",
    UFG::TSSpawnPoint::MthdC_get_named,
    1,
    0);
  SSClass::register_method_func(UFG::TSSpawnPoint::mspSpawnPointClass, "spawn", UFG::TSSpawnPoint::MthdC_spawn, 1, 0);
  SSClass::register_method_func(
    UFG::TSSpawnPoint::mspSpawnPointClass,
    "set_spawn_target",
    UFG::TSSpawnPoint::MthdC_set_spawn_target,
    1,
    0);
}

// File Line: 86
// RVA: 0x5112B0
AString *__fastcall UFG::TSSpawnPoint_spawnTypeStr(AString *result, UFG::SpawnPoint *pSpawnPoint)
{
  AString *v2; // rbx
  UFG::SceneObjectProperties *v3; // rcx
  UFG::SimObject *v4; // rax
  UFG::SceneObjectProperties *v5; // rax
  UFG::qSymbolUC *v6; // rax
  char *v7; // rax
  unsigned int v8; // eax

  v2 = result;
  v3 = 0i64;
  v4 = pSpawnPoint->m_pSimObject;
  if ( v4 )
    v3 = v4->m_pSceneObj;
  if ( v3->mChildren.mCount && (v5 = UFG::SceneObjectProperties::GetChildAsSceneObject(v3, 0)) != 0i64 )
  {
    v6 = (UFG::qSymbolUC *)UFG::SceneObjectProperties::GetArchetypePropertiesName(v5);
    v7 = UFG::qSymbol::as_cstr_dbg(v6);
    AString::AString(v2, v7);
  }
  else
  {
    v8 = AMemory::c_req_byte_size_func(0x14u);
    v2->i_str_ref_p = AStringRef::pool_new("[empty/no children]", 0x13u, v8, 1u, 0, 1);
  }
  return v2;
}

// File Line: 113
// RVA: 0x4F1E90
void __fastcall UFG::TSSpawnPoint::MthdC_spawn(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rsi
  SSInvokedMethod *v3; // rbx
  SSInstance *v4; // r8
  UFG::SimObject *v5; // rcx
  UFG::SpawnPoint *v6; // rax
  UFG::SpawnPoint *v7; // rdi
  UFG::SimObjectGame *v8; // rax
  UFG::TSActorComponent *v9; // rax
  UFG::TSActor *v10; // rax
  UFG::SimObject *v11; // rax
  UFG::SceneObjectProperties *v12; // rcx
  UFG::SceneObjectProperties *v13; // rax
  UFG::qPropertySet *v14; // rcx
  unsigned int v15; // ecx
  char *v16; // rbx
  char *v17; // rax
  AStringRef *v18; // rbx
  bool v19; // zf
  AObjReusePool<AStringRef> *v20; // rax
  AObjBlock<AStringRef> *v21; // rcx
  unsigned __int64 v22; // rdx
  bool v23; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v24; // rcx
  UFG::SpawnInfoInterface::SpawnPriority pPriority; // [rsp+40h] [rbp+8h]
  AString result; // [rsp+48h] [rbp+10h]

  v2 = ppResult;
  v3 = pScope;
  v4 = (*pScope->i_data.i_array_p)->i_data_p;
  if ( v4 && v4->i_class_p == UFG::TSSimObject::mspSimObjectClass )
  {
    v5 = (UFG::SimObject *)v4->i_user_data;
    if ( !v5 )
      goto LABEL_25;
    v6 = (UFG::SpawnPoint *)UFG::SimObject::GetComponentOfType(v5, UFG::SpawnPoint::_TypeUID);
  }
  else
  {
    v6 = UFG::SpawnPoint::GetNamed((UFG::qSymbol *)&v4->i_user_data);
  }
  v7 = v6;
  if ( v6 )
  {
    v8 = UFG::SpawnPoint::Spawn(
           v6,
           *(_QWORD *)(*(_QWORD *)(*((_QWORD *)v3->i_data.i_array_p + 1) + 8i64) + 32i64) != 0i64,
           1);
    if ( v8 )
    {
      if ( !v2 )
        return;
      v9 = (UFG::TSActorComponent *)UFG::SimObject::GetComponentOfType(
                                      (UFG::SimObject *)&v8->vfptr,
                                      UFG::TSActorComponent::_TypeUID);
      if ( v9 )
      {
        v10 = UFG::TSActorComponent::GetActor(v9);
        goto LABEL_26;
      }
    }
    else
    {
      v11 = v7->m_pSimObject;
      if ( v11 )
        v12 = v11->m_pSceneObj;
      else
        v12 = 0i64;
      v13 = UFG::SceneObjectProperties::GetChildAsSceneObject(v12, 0);
      v14 = v13->mpWritableProperties;
      if ( !v14 )
        v14 = v13->mpConstProperties;
      v15 = UFG::SpawnInfoInterface::GetSpawnPriority(v14, &pPriority)->mUID;
      if ( v15 == qSymbol_Low.mUID || v15 == qSymbol_Medium.mUID )
      {
        v16 = UFG::TSSpawnPoint_spawnTypeStr(&result, v7)->i_str_ref_p->i_cstr_p;
        v17 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v7->i_name);
        UFG::qPrintf("Warning: Low/medium priority spawn point %s couldn't spawn type %s.\n", v17, v16);
        v18 = result.i_str_ref_p;
        v19 = result.i_str_ref_p->i_ref_count == 1;
        --v18->i_ref_count;
        if ( v19 )
        {
          if ( v18->i_deallocate )
            AMemory::c_free_func(v18->i_cstr_p);
          v20 = AStringRef::get_pool();
          v21 = v20->i_block_p;
          v22 = (unsigned __int64)v21->i_objects_a;
          if ( (unsigned __int64)v18 < v22
            || (v23 = (unsigned __int64)v18 < v22 + 24i64 * v21->i_size, v24 = &v20->i_pool, !v23) )
          {
            v24 = &v20->i_exp_pool;
          }
          APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v24, v18);
        }
      }
    }
  }
LABEL_25:
  v10 = (UFG::TSActor *)SSBrain::c_nil_p;
LABEL_26:
  if ( v2 )
  {
    ++v10->i_ref_count;
    *v2 = (SSInstance *)&v10->vfptr;
  }
}

// File Line: 216
// RVA: 0x4E6700
void __fastcall UFG::TSSpawnPoint::MthdC_find_named(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  UFG::SpawnPoint *v3; // rax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = UFG::SpawnPoint::GetNamed((UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    if ( v3 )
      *v2 = SSInstance::pool_new(UFG::TSSpawnPoint::mspSpawnPointClass, (unsigned __int64)v3);
    else
      *v2 = SSBrain::c_nil_p;
  }
}

// File Line: 234
// RVA: 0x4E8410
void __fastcall UFG::TSSpawnPoint::MthdC_get_named(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  UFG::SpawnPoint *v3; // rax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = UFG::SpawnPoint::GetNamed((UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    *v2 = SSInstance::pool_new(UFG::TSSpawnPoint::mspSpawnPointClass, (unsigned __int64)v3);
  }
}

// File Line: 257
// RVA: 0x4EF120
void __fastcall UFG::TSSpawnPoint::MthdC_set_spawn_target(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rdi
  SSInstance *v3; // rcx
  UFG::SimObject *v4; // rcx
  UFG::SpawnPoint *v5; // rax
  UFG::SpawnPoint *v6; // rbx
  UFG::qPropertySet *v7; // rax
  UFG::qSymbol propSetName; // [rsp+30h] [rbp+8h]

  v2 = pScope;
  v3 = (*pScope->i_data.i_array_p)->i_data_p;
  if ( v3 && v3->i_class_p == UFG::TSSimObject::mspSimObjectClass )
  {
    v4 = (UFG::SimObject *)v3->i_user_data;
    if ( !v4 )
      return;
    v5 = (UFG::SpawnPoint *)UFG::SimObject::GetComponentOfType(v4, UFG::SpawnPoint::_TypeUID);
  }
  else
  {
    v5 = UFG::SpawnPoint::GetNamed((UFG::qSymbol *)&v3->i_user_data);
  }
  v6 = v5;
  if ( v5 )
  {
    if ( !Scaleform::GFx::InteractiveObject::GetResourceMovieDef(v5) )
    {
      propSetName.mUID = *(_DWORD *)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 1) + 8i64) + 32i64);
      if ( propSetName.mUID != -1 )
      {
        v7 = UFG::PropertySetManager::GetPropertySet(&propSetName);
        if ( v7 )
          UFG::SpawnPoint::SetNewSpawnTarget(v6, v7);
      }
    }
  }
}

