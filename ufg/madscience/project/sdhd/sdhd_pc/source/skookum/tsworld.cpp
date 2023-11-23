// File Line: 152
// RVA: 0x510910
void __fastcall UFG::TSMetrics_MthdC_simtime_get_frame(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( ppResult )
    *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, UFG::Metrics::msInstance.mSimFrameCount);
}

// File Line: 167
// RVA: 0x510940
void __fastcall UFG::TSMetrics_MthdC_simtime_get_scale(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( ppResult )
    *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(UFG::Metrics::msInstance.mSimTimeScaleInGame));
}

// File Line: 200
// RVA: 0x510980
void __fastcall UFG::TSMetrics_MthdC_simtime_is_paused(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( ppResult )
  {
    if ( UFG::Metrics::msInstance.mSimPausedInGame && UFG::Metrics::msInstance.mSimTimeDeltaStep == 0.0 )
      *ppResult = SSBoolean::pool_new(1);
    else
      *ppResult = SSBoolean::pool_new(0);
  }
}

// File Line: 215
// RVA: 0x5109D0
void __fastcall UFG::TSMetrics_MthdC_simtime_pause(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  bool v2; // zf

  v2 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data == 0;
  UFG::Metrics::msInstance.mSimTimeDeltaStep = 0.0;
  UFG::Metrics::msInstance.mSimPausedInGame = !v2;
}

// File Line: 231
// RVA: 0x510850
void __fastcall UFG::TSMetrics_BindAtomics(UFG *this)
{
  SSClass *v1; // rbx
  ASymbol rebind; // [rsp+20h] [rbp-18h]
  ASymbol rebinda; // [rsp+20h] [rbp-18h]
  ASymbol rebindb; // [rsp+20h] [rbp-18h]
  ASymbol rebindc; // [rsp+20h] [rbp-18h]
  ASymbol rebindd; // [rsp+20h] [rbp-18h]

  LOBYTE(rebind.i_uid) = 0;
  v1 = SSBrain::get_class("Metrics");
  SSClass::register_method_func(v1, "simtime_get_frame", UFG::TSMetrics_MthdC_simtime_get_frame, 1, rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(v1, "simtime_get_scale", UFG::TSMetrics_MthdC_simtime_get_scale, 1, rebinda);
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_func(v1, "simtime_set_scale", UFG::TSMetrics_MthdC_simtime_set_scale, 1, rebindb);
  LOBYTE(rebindc.i_uid) = 0;
  SSClass::register_method_func(v1, "simtime_is_paused", UFG::TSMetrics_MthdC_simtime_is_paused, 1, rebindc);
  LOBYTE(rebindd.i_uid) = 0;
  SSClass::register_method_func(v1, "simtime_pause", UFG::TSMetrics_MthdC_simtime_pause, 1, rebindd);
}

// File Line: 249
// RVA: 0x4EEEF0
void __fastcall UFG::TSMetrics_MthdC_simtime_set_scale(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  float mSimTimeScaleMax; // xmm0_4

  mSimTimeScaleMax = *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  if ( mSimTimeScaleMax <= 0.0 )
    mSimTimeScaleMax = 0.0;
  if ( mSimTimeScaleMax >= UFG::Metrics::msInstance.mSimTimeScaleMax )
    mSimTimeScaleMax = UFG::Metrics::msInstance.mSimTimeScaleMax;
  UFG::Metrics::msInstance.mSimTimeScaleInGame = mSimTimeScaleMax;
  UFG::Metrics::msInstance.mSimTimeDeltaStep = 0.0;
  UFG::Metrics::msInstance.mSimPausedInGame = mSimTimeScaleMax == 0.0;
}

// File Line: 269
// RVA: 0x512300
UFG::qPropertySet *__fastcall UFG::TSWorld::get_spawn_info(
        SSInvokedContextBase *pScope,
        unsigned int argOffset,
        UFG::qSymbol *pSpawnName,
        UFG::qBaseTreeRB **ppLayer)
{
  SSInstance *i_data_p; // rcx
  UFG::qBaseTreeRB *Layer; // rbx
  UFG::qPropertySet *i_user_data; // rdi
  SSInstance *v11; // rdx
  SSClass *i_class_p; // rax
  AStringRef *empty; // rbx
  SSInstance *v14; // rbp
  SSClass *v15; // rax
  bool v16; // zf
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // r8
  bool v20; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx
  AObjReusePool<AStringRef> *v22; // rax
  AObjBlock<AStringRef> *v23; // rcx
  unsigned __int64 v24; // r8
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_pool; // rcx
  AStringRef *v26; // rax
  const char *i_cstr_p; // r8
  AObjReusePool<AStringRef> *v28; // rax
  AObjBlock<AStringRef> *v29; // rcx
  unsigned __int64 v30; // r8
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v31; // rcx
  UFG::qSymbol result; // [rsp+78h] [rbp+10h] BYREF

  i_data_p = pScope->i_data.i_array_p[argOffset]->i_data_p;
  Layer = 0i64;
  if ( i_data_p )
  {
    if ( i_data_p->i_class_p == UFG::SkookumMgr::mspPropertySetClass )
      i_user_data = (UFG::qPropertySet *)i_data_p->i_user_data;
    else
      i_user_data = UFG::PropertySetManager::FindPropertySet((UFG::qSymbol *)&i_data_p->i_user_data);
  }
  else
  {
    i_user_data = 0i64;
  }
  v11 = pScope->i_data.i_array_p[argOffset + 2]->i_data_p;
  if ( v11 )
  {
    i_class_p = v11->i_class_p;
    if ( i_class_p == UFG::TSSceneLayer::mspSceneLayerClass )
    {
      Layer = (UFG::qBaseTreeRB *)v11->i_user_data;
    }
    else if ( i_class_p == SSBrain::c_symbol_class_p )
    {
      Layer = UFG::Scene::FindLayer(&UFG::Scene::msDefault, (UFG::qSymbol *)&v11->i_user_data);
    }
  }
  *ppLayer = Layer;
  empty = AStringRef::get_empty();
  ++empty->i_ref_count;
  v14 = pScope->i_data.i_array_p[argOffset + 1]->i_data_p;
  v15 = v14->i_class_p;
  if ( v15 == SSBrain::c_symbol_class_p )
  {
    pSpawnName->mUID = v14->i_user_data;
  }
  else if ( v15 == SSBrain::c_string_class_p )
  {
    ++*(_WORD *)(v14->i_user_data + 16);
    v16 = empty->i_ref_count-- == 1;
    if ( v16 )
    {
      if ( empty->i_deallocate )
        AMemory::c_free_func(empty->i_cstr_p);
      pool = AStringRef::get_pool();
      i_block_p = pool->i_block_p;
      i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
      if ( (unsigned __int64)empty < i_objects_a
        || (v20 = (unsigned __int64)empty < i_objects_a + 24i64 * i_block_p->i_size, p_i_exp_pool = &pool->i_pool, !v20) )
      {
        p_i_exp_pool = &pool->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, empty);
    }
    empty = (AStringRef *)v14->i_user_data;
  }
  if ( pSpawnName->mUID == -1 )
  {
    if ( empty->i_length )
    {
      if ( *ppLayer )
      {
        UFG::SceneLayer::GenerateUniqueNameForSkookum((UFG::SceneLayer *)*ppLayer, empty->i_cstr_p, pSpawnName);
        goto LABEL_38;
      }
      i_cstr_p = empty->i_cstr_p;
    }
    else
    {
      v16 = empty->i_ref_count-- == 1;
      if ( v16 )
      {
        if ( empty->i_deallocate )
          AMemory::c_free_func(empty->i_cstr_p);
        v22 = AStringRef::get_pool();
        v23 = v22->i_block_p;
        v24 = (unsigned __int64)v23->i_objects_a;
        if ( (unsigned __int64)empty < v24
          || (v20 = (unsigned __int64)empty < v24 + 24i64 * v23->i_size, p_i_pool = &v22->i_pool, !v20) )
        {
          p_i_pool = &v22->i_exp_pool;
        }
        APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_pool, empty);
      }
      v26 = AStringRef::pool_new("_spawn000", 9u, 0xAu, 1u, 0, 1);
      empty = v26;
      if ( *ppLayer )
      {
        UFG::SceneLayer::GenerateUniqueNameForSkookum((UFG::SceneLayer *)*ppLayer, v26->i_cstr_p, pSpawnName);
        goto LABEL_38;
      }
      i_cstr_p = v26->i_cstr_p;
    }
    pSpawnName->mUID = UFG::Simulation::GenerateUniqueName(&UFG::gSim, &result, i_cstr_p)->mUID;
  }
LABEL_38:
  v16 = empty->i_ref_count-- == 1;
  if ( v16 )
  {
    if ( empty->i_deallocate )
      AMemory::c_free_func(empty->i_cstr_p);
    v28 = AStringRef::get_pool();
    v29 = v28->i_block_p;
    v30 = (unsigned __int64)v29->i_objects_a;
    if ( (unsigned __int64)empty < v30
      || (v20 = (unsigned __int64)empty < v30 + 24i64 * v29->i_size, v31 = &v28->i_pool, !v20) )
    {
      v31 = &v28->i_exp_pool;
    }
    APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v31, empty);
  }
  return i_user_data;
}

// File Line: 332
// RVA: 0x4F20C0
void __fastcall UFG::TSWorld::MthdC_spawn_object(SSInvokedMethod *pScope, UFG::TSActor **ppResult)
{
  UFG::qPropertySet *spawn_info; // rax
  UFG::SimObject *v4; // rax
  UFG::SimObject *v5; // rbx
  UFG::TSActor *v6; // rax
  UFG::MarkerBase *ComponentOfType; // rax
  UFG::qSymbol pSpawnName; // [rsp+48h] [rbp+10h] BYREF
  UFG::SceneLayer *ppLayer; // [rsp+50h] [rbp+18h] BYREF

  pSpawnName.mUID = -1;
  spawn_info = UFG::TSWorld::get_spawn_info(pScope, 0, &pSpawnName, &ppLayer);
  v4 = UFG::SpawnInfoInterface::SpawnObject(&pSpawnName, spawn_info, UnReferenced, ppLayer, 0i64, 0i64);
  v5 = v4;
  if ( ppResult )
  {
    v6 = UFG::TSActor::SkookumObjFromSimObj(v4);
    if ( !v6 )
    {
      if ( v5 )
      {
        ComponentOfType = (UFG::MarkerBase *)UFG::SimObject::GetComponentOfType(v5, UFG::MarkerBase::_TypeUID);
        if ( ComponentOfType )
        {
          *ppResult = (UFG::TSActor *)UFG::TSMarker::AsInstance(ComponentOfType);
          return;
        }
      }
      v6 = (UFG::TSActor *)SSBrain::c_nil_p;
    }
    *ppResult = v6;
  }
}

// File Line: 363
// RVA: 0x4F2160
void __fastcall UFG::TSWorld::MthdC_spawn_object_at_xform(SSInvokedMethod *pScope, UFG::TSActor **ppResult)
{
  UFG::qPropertySet *spawn_info; // rdi
  UFG::TransformNodeComponent *i_user_data; // rbx
  UFG::SimObject *v6; // rax
  UFG::SimObject *v7; // rbx
  UFG::TSActor *v8; // rax
  UFG::MarkerBase *ComponentOfType; // rax
  UFG::qSymbol pSpawnName; // [rsp+40h] [rbp+8h] BYREF
  UFG::SceneLayer *ppLayer; // [rsp+48h] [rbp+10h] BYREF

  pSpawnName.mUID = -1;
  spawn_info = UFG::TSWorld::get_spawn_info(pScope, 1u, &pSpawnName, &ppLayer);
  i_user_data = (UFG::TransformNodeComponent *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  UFG::TransformNodeComponent::UpdateWorldTransform(i_user_data);
  v6 = UFG::SpawnInfoInterface::SpawnObject(
         &pSpawnName,
         spawn_info,
         &i_user_data->mWorldTransform,
         UnReferenced,
         ppLayer,
         0i64);
  v7 = v6;
  if ( ppResult )
  {
    v8 = UFG::TSActor::SkookumObjFromSimObj(v6);
    if ( !v8 )
    {
      if ( v7 )
      {
        ComponentOfType = (UFG::MarkerBase *)UFG::SimObject::GetComponentOfType(v7, UFG::MarkerBase::_TypeUID);
        if ( ComponentOfType )
        {
          *ppResult = (UFG::TSActor *)UFG::TSMarker::AsInstance(ComponentOfType);
          return;
        }
      }
      v8 = (UFG::TSActor *)SSBrain::c_nil_p;
    }
    *ppResult = v8;
  }
}

// File Line: 397
// RVA: 0x4EDFE0
void __fastcall UFG::TSWorld::MthdC_set_hijack_vehicle_price(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx
  unsigned int i_user_data; // eax
  int v4; // ebx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mPrev; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v6; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mNext; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h] BYREF

  i_array_p = pScope->i_data.i_array_p;
  i_user_data = (*i_array_p)->i_data_p->i_user_data;
  v4 = i_array_p[1]->i_data_p->i_user_data;
  pTrackEnumBinding.mPrev = &pTrackEnumBinding;
  pTrackEnumBinding.mNext = &pTrackEnumBinding;
  pTrackEnumBinding.m_EnumSymbol.mUID = i_user_data;
  *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
  pTrackEnumBinding.m_uEnumUID = 0;
  if ( UFG::gInventoryItemTracksEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&UFG::gInventoryItemTracksEnum, &pTrackEnumBinding);
  }
  else
  {
    mPrev = UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &pTrackEnumBinding;
    pTrackEnumBinding.mPrev = mPrev;
    pTrackEnumBinding.mNext = &UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode;
    UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &pTrackEnumBinding;
  }
  if ( pTrackEnumBinding.m_EnumValue == 104 )
    UFG::ItemProfiles::SetCost(eINVENTORY_ITEM_HIJACKED_VEHICLE, v4);
  v6 = pTrackEnumBinding.mPrev;
  mNext = pTrackEnumBinding.mNext;
  pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
  mNext->mPrev = v6;
}

// File Line: 420
// RVA: 0x4F28C0
void __fastcall UFG::TSWorld::MthdC_time_get(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TimeOfDayManager *Instance; // rax

  if ( ppResult )
  {
    Instance = UFG::TimeOfDayManager::GetInstance();
    *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(Instance->m_SecondsSinceMidnight));
  }
}

// File Line: 430
// RVA: 0x4EE1F0
void __fastcall UFG::TSWorld::MthdC_set_layer_active(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // r8
  const char *v4; // rdi
  bool v5; // bl
  bool v6; // bp

  i_array_p = pScope->i_data.i_array_p;
  v4 = *(const char **)(*i_array_p)->i_data_p->i_user_data;
  v5 = i_array_p[1]->i_data_p->i_user_data != 0;
  v6 = UFG::SectionLayout::SetLayerActive(v4, v5);
  UFG::SectionChooser::FlushAltLayer(v4, v5);
  if ( ppResult )
    *ppResult = SSBoolean::pool_new(v6);
}

// File Line: 450
// RVA: 0x4E7B10
void __fastcall UFG::TSWorld::MthdC_get_layer_count(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  unsigned int LayerCount; // eax

  if ( ppResult )
  {
    LayerCount = UFG::SectionLayout::GetLayerCount();
    *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, LayerCount);
  }
}

// File Line: 458
// RVA: 0x4E7B40
void __fastcall UFG::TSWorld::MthdC_get_layer_name(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  const char *LayerName; // rax
  char *v4; // rdi
  __int64 v5; // rbx
  unsigned int v6; // eax
  AStringRef *i_str_ref_p; // rbx
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v12; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx
  AString str; // [rsp+58h] [rbp+10h] BYREF

  if ( ppResult )
  {
    LayerName = UFG::SectionLayout::GetLayerName((*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    v4 = (char *)LayerName;
    v5 = -1i64;
    do
      ++v5;
    while ( LayerName[v5] );
    v6 = AMemory::c_req_byte_size_func(v5 + 1);
    str.i_str_ref_p = AStringRef::pool_new(v4, v5, v6, 1u, 0, 1);
    *ppResult = SSString::as_instance(&str);
    i_str_ref_p = str.i_str_ref_p;
    if ( str.i_str_ref_p->i_ref_count-- == 1 )
    {
      if ( i_str_ref_p->i_deallocate )
        AMemory::c_free_func(i_str_ref_p->i_cstr_p);
      pool = AStringRef::get_pool();
      i_block_p = pool->i_block_p;
      i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
      if ( (unsigned __int64)i_str_ref_p < i_objects_a
        || (v12 = (unsigned __int64)i_str_ref_p < i_objects_a + 24i64 * i_block_p->i_size,
            p_i_exp_pool = &pool->i_pool,
            !v12) )
      {
        p_i_exp_pool = &pool->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, i_str_ref_p);
    }
  }
}

// File Line: 477
// RVA: 0x4F2940
void __fastcall UFG::TSWorld::MthdC_time_is_day(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  float m_SecondsSinceMidnight; // xmm0_4

  if ( ppResult )
  {
    m_SecondsSinceMidnight = UFG::TimeOfDayManager::GetInstance()->m_SecondsSinceMidnight;
    if ( m_SecondsSinceMidnight < 21600.0 || m_SecondsSinceMidnight > 64800.0 )
      *ppResult = SSBoolean::pool_new(0);
    else
      *ppResult = SSBoolean::pool_new(1);
  }
}

// File Line: 492
// RVA: 0x4F29A0
void __fastcall UFG::TSWorld::MthdC_time_set(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *i_data_p; // rbx
  UFG::TimeOfDayManager *Instance; // rax

  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  Instance = UFG::TimeOfDayManager::GetInstance();
  UFG::TimeOfDayManager::SetTime(Instance, *(float *)&i_data_p->i_user_data, 0);
  UFG::TidoGame::ResetTODEmitters();
}

// File Line: 504
// RVA: 0x4F2900
void __fastcall UFG::TSWorld::MthdC_time_get_scale(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TimeOfDayManager *Instance; // rax

  if ( ppResult )
  {
    Instance = UFG::TimeOfDayManager::GetInstance();
    *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(Instance->m_GameSecondsPerRealSecond));
  }
}

// File Line: 518
// RVA: 0x4F29D0
void __fastcall UFG::TSWorld::MthdC_time_set_scale(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *i_data_p; // rbx
  UFG::TimeOfDayManager *Instance; // rax

  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  Instance = UFG::TimeOfDayManager::GetInstance();
  TimePlotPoint::SetTimeValue(Instance, *(float *)&i_data_p->i_user_data);
}

// File Line: 529
// RVA: 0x4E50A0
void __fastcall UFG::TSWorld::MthdC_enable_near_layer_transitions(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::GeographicalLayerManager::GetInstance()->mAllowImmediateActivation = 1;
}

// File Line: 553
// RVA: 0x4E4E40
void __fastcall UFG::TSWorld::MthdC_enable_decals(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  Render::gDecalManager.mEnableDecals = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
}

// File Line: 566
// RVA: 0x4E4FA0
void __fastcall UFG::TSWorld::MthdC_enable_halfsize_aa(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::RenderWorld::msEnableHalfsizeAA = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
}

// File Line: 579
// RVA: 0x4EC2D0
void __fastcall UFG::TSWorld::MthdC_render_enable_water(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::RenderWorld::msEnableWater = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
}

// File Line: 591
// RVA: 0x4EAB20
void __fastcall UFG::TSWorld::MthdC_load_cloud_scene(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  Render::SkyMarshall::LoadCloudScene(
    &Render::SkyMarshall::gSkyMarshall,
    *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 604
// RVA: 0x4F2A80
void __fastcall UFG::TSWorld::MthdC_unload_cloud_scene(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  Render::SkyMarshall::UnloadCloudScene(
    &Render::SkyMarshall::gSkyMarshall,
    *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 617
// RVA: 0x4F33B0
void __fastcall UFG::TSWorld::MthdC_weather_is_raining(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TimeOfDayManager *Instance; // rax

  if ( ppResult )
  {
    Instance = UFG::TimeOfDayManager::GetInstance();
    *ppResult = SSBoolean::pool_new(Instance->m_WeatherState > 1.0);
  }
}

// File Line: 632
// RVA: 0x4F3370
void __fastcall UFG::TSWorld::MthdC_weather_get_amount(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TimeOfDayManager *Instance; // rax

  if ( ppResult )
  {
    Instance = UFG::TimeOfDayManager::GetInstance();
    *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(Instance->m_WeatherState));
  }
}

// File Line: 647
// RVA: 0x4F34A0
void __fastcall UFG::TSWorld::MthdC_weather_render_inside(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  Render::gFXManager.mRenderRainWhileInside = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  if ( Render::gFXManager.mRenderRainWhileInside )
    unk_142143300 = LODWORD(FLOAT_0_55000001);
}

// File Line: 664
// RVA: 0x4EEF50
void __fastcall UFG::TSWorld::MthdC_set_skydome(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::qSymbol skydomeName; // [rsp+30h] [rbp+8h] BYREF

  skydomeName.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  Render::SkyMarshall::SetSkydome(&Render::SkyMarshall::gSkyMarshall, &skydomeName);
}

// File Line: 677
// RVA: 0x4EC1A0
void __fastcall UFG::TSWorld::MthdC_release_skydome(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  Render::SkyMarshall::ReleaseSkydome(&Render::SkyMarshall::gSkyMarshall);
}

// File Line: 688
// RVA: 0x4E9830
void __fastcall UFG::TSWorld::MthdC_is_progression_subset_mode_active(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  int i_user_data; // ebx
  UFG::ProgressionTracker *v4; // rax

  if ( ppResult )
  {
    i_user_data = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    v4 = UFG::ProgressionTracker::Instance();
    *ppResult = SSBoolean::pool_new(i_user_data == v4->mSubSetModeType.mUID);
  }
}

// File Line: 705
// RVA: 0x4EE780
void __fastcall UFG::TSWorld::MthdC_set_progression_subset_mode(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  unsigned int i_user_data; // ebx

  i_user_data = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  UFG::ProgressionTracker::Instance()->mSubSetModeType.mUID = i_user_data;
}

// File Line: 717
// RVA: 0x4E45F0
void __fastcall UFG::TSWorld::MthdC_clear_progression_subset_mode(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::ProgressionTracker *v2; // rax

  v2 = UFG::ProgressionTracker::Instance();
  UFG::qSymbol::set_null(&v2->mSubSetModeType);
}

// File Line: 728
// RVA: 0x4F34D0
void __fastcall UFG::TSWorld::MthdC_weather_set_amount(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  float v2; // xmm6_4
  UFG::TimeOfDayManager *Instance; // rax
  float v4; // xmm0_4

  v2 = *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  Instance = UFG::TimeOfDayManager::GetInstance();
  if ( v2 <= 0.0 )
  {
    v2 = 0.0;
  }
  else
  {
    v4 = FLOAT_2_0;
    if ( v2 >= 2.0 )
      goto LABEL_6;
  }
  v4 = v2;
LABEL_6:
  Instance->m_WeatherState = v4;
  Instance->m_WeatherTarget = v4;
  Instance->m_NextWeatherTarget = v4;
}

// File Line: 739
// RVA: 0x4F3590
void __fastcall UFG::TSWorld::MthdC_weather_target(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  float v2; // xmm6_4
  UFG::TimeOfDayManager *Instance; // rax

  v2 = *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  Instance = UFG::TimeOfDayManager::GetInstance();
  if ( v2 <= 0.0 )
  {
    v2 = 0.0;
  }
  else if ( v2 >= 2.0 )
  {
    Instance->m_WeatherTarget = FLOAT_2_0;
    Instance->m_NextWeatherTarget = FLOAT_2_0;
    return;
  }
  Instance->m_WeatherTarget = v2;
  Instance->m_NextWeatherTarget = v2;
}

// File Line: 750
// RVA: 0x4F33E0
void __fastcall UFG::TSWorld::MthdC_weather_lock(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  bool v2; // bl
  UFG::TimeOfDayManager *Instance; // rax

  v2 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  Instance = UFG::TimeOfDayManager::GetInstance();
  UFG::TimeOfDayManager::LockWeather(Instance, v2);
}

// File Line: 761
// RVA: 0x4F3410
void __fastcall UFG::TSWorld::MthdC_weather_rain_chance(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  float v2; // xmm6_4
  UFG::TimeOfDayManager *Instance; // rax

  v2 = *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  Instance = UFG::TimeOfDayManager::GetInstance();
  if ( v2 <= 0.0 )
  {
    v2 = 0.0;
  }
  else if ( v2 >= 1.0 )
  {
    LODWORD(Instance->m_WeatherChanceOfPrecipitation) = (_DWORD)FLOAT_1_0;
    return;
  }
  Instance->m_WeatherChanceOfPrecipitation = v2;
}

// File Line: 773
// RVA: 0x4F3470
void __fastcall UFG::TSWorld::MthdC_weather_randomize_interval(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  int v2; // ebx

  v2 = (int)(float)(*(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data + 0.5);
  UFG::TimeOfDayManager::GetInstance()->m_WeatherRandomInterval = v2;
}

// File Line: 787
// RVA: 0x4F35F0
void __fastcall UFG::TSWorld::MthdC_weather_wetness_override(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *i_data_p; // rbx
  UFG::TimeOfDayManager *Instance; // rax

  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  Instance = UFG::TimeOfDayManager::GetInstance();
  UFG::TimeOfDayManager::SetSurfaceWetnessOverride(Instance, *(float *)&i_data_p->i_user_data, "Script");
}

// File Line: 798
// RVA: 0x4F3530
void __fastcall UFG::TSWorld::MthdC_weather_set_wind(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx
  float v3; // xmm7_4
  float v4; // xmm6_4
  UFG::TimeOfDayManager *Instance; // rax

  i_array_p = pScope->i_data.i_array_p;
  v3 = (float)(*(float *)&(*i_array_p)->i_data_p->i_user_data * 3.1415927) * 0.0055555557;
  v4 = *(float *)&i_array_p[1]->i_data_p->i_user_data;
  Instance = UFG::TimeOfDayManager::GetInstance();
  UFG::TimeOfDayManager::SetWind(Instance, v3, v4);
}

// File Line: 812
// RVA: 0x4E7C60
void __fastcall UFG::TSWorld::MthdC_get_location_name(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::ProgressionTracker *v3; // rax
  char *mLocationDir; // rdi
  __int64 v5; // rbx
  unsigned int v6; // eax
  AStringRef *i_str_ref_p; // rbx
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v12; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx
  AString str; // [rsp+58h] [rbp+10h] BYREF

  if ( ppResult )
  {
    v3 = UFG::ProgressionTracker::Instance();
    mLocationDir = UFG::ProgressionTracker::GetGameSetup(v3)->mLocationDir;
    v5 = -1i64;
    do
      ++v5;
    while ( mLocationDir[v5] );
    v6 = AMemory::c_req_byte_size_func(v5 + 1);
    str.i_str_ref_p = AStringRef::pool_new(mLocationDir, v5, v6, 1u, 0, 1);
    *ppResult = SSString::as_instance(&str);
    i_str_ref_p = str.i_str_ref_p;
    if ( str.i_str_ref_p->i_ref_count-- == 1 )
    {
      if ( i_str_ref_p->i_deallocate )
        AMemory::c_free_func(i_str_ref_p->i_cstr_p);
      pool = AStringRef::get_pool();
      i_block_p = pool->i_block_p;
      i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
      if ( (unsigned __int64)i_str_ref_p < i_objects_a
        || (v12 = (unsigned __int64)i_str_ref_p < i_objects_a + 24i64 * i_block_p->i_size,
            p_i_exp_pool = &pool->i_pool,
            !v12) )
      {
        p_i_exp_pool = &pool->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, i_str_ref_p);
    }
  }
}

// File Line: 828
// RVA: 0x4E7C30
void __fastcall UFG::TSWorld::MthdC_get_local_player(SSInvokedMethod *pScope, UFG::TSActor **ppResult)
{
  UFG::SimObjectCharacter *LocalPlayer; // rax

  if ( ppResult )
  {
    LocalPlayer = UFG::GetLocalPlayer();
    *ppResult = UFG::TSActor::SkookumObjFromSimObj(LocalPlayer);
  }
}

// File Line: 844
// RVA: 0x4E9A10
void __fastcall UFG::TSWorld::MthdC_is_simobject_existent(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  int v3; // eax
  UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> **p_mNext; // rcx
  bool v5; // r8

  if ( ppResult )
  {
    v3 = UFG::qStringHashUpper32(*(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data, -1);
    p_mNext = &UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mNext[-18].mNext;
    v5 = 0;
    if ( &UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mNext[-18].mNext != (UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> **)((char *)&UFG::RigidBodyComponent::s_RigidBodyComponentList - 280) )
    {
      while ( *((_DWORD *)p_mNext + 7) != v3 )
      {
        p_mNext = &p_mNext[36][-18].mNext;
        if ( p_mNext == (UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> **)((char *)&UFG::RigidBodyComponent::s_RigidBodyComponentList
                                                                                       - 280) )
        {
          *ppResult = SSBoolean::pool_new(0);
          return;
        }
      }
      v5 = 1;
    }
    *ppResult = SSBoolean::pool_new(v5);
  }
}

// File Line: 875
// RVA: 0x4EA3B0
void __fastcall UFG::TSWorld::MthdC_join_group(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSActor *i_data_p; // rdi
  bool v3; // r12
  UFG::qBaseTreeRB *v4; // rsi
  SSClass *i_class_p; // rbx
  SSActor *v8; // rbx
  SSClass *v9; // r14
  UFG::SimObjectGame *v10; // rdi
  UFG::SimObjectGame *v11; // rbx
  unsigned int v12; // edx

  i_data_p = (SSActor *)(*pScope->i_data.i_array_p)->i_data_p;
  v3 = 0;
  v4 = 0i64;
  if ( !i_data_p )
    goto LABEL_6;
  i_class_p = i_data_p->i_class_p;
  if ( i_class_p->vfptr->is_actor_class(i_class_p) )
    goto LABEL_7;
  if ( i_class_p == SSBrain::c_symbol_class_p && LODWORD(i_data_p->i_user_data) != -1 )
    i_data_p = SSActor::find((ASymbol *)&i_data_p->i_user_data);
  else
LABEL_6:
    i_data_p = 0i64;
LABEL_7:
  v8 = *(SSActor **)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64);
  if ( !v8 )
    goto LABEL_12;
  v9 = v8->i_class_p;
  if ( !v9->vfptr->is_actor_class(v9) )
  {
    if ( v9 == SSBrain::c_symbol_class_p && LODWORD(v8->i_user_data) != -1 )
    {
      v8 = SSActor::find((ASymbol *)&v8->i_user_data);
      goto LABEL_13;
    }
LABEL_12:
    v8 = 0i64;
  }
LABEL_13:
  if ( i_data_p && v8 )
  {
    v10 = *(UFG::SimObjectGame **)&i_data_p[1].i_icoroutines_to_update.i_count;
    v11 = *(UFG::SimObjectGame **)&v8[1].i_icoroutines_to_update.i_count;
    v12 = *(_DWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 2) + 8i64) + 32i64);
    if ( v12 )
      v4 = UFG::qBaseTreeRB::Get(&UFG::PedFormationManagerComponent::s_Profiles.mTree, v12);
    v3 = UFG::GroupComponent::JoinGroup(v10, v11, (UFG::PedFormationProfile *)v4);
  }
  if ( ppResult )
    *ppResult = SSBoolean::pool_new(v3);
}

// File Line: 904
// RVA: 0x4E5260
void __fastcall UFG::TSWorld::MthdC_enable_sidewalk_node(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  AStringRef *i_user_data; // rbx
  bool v3; // di
  unsigned int crc32_cstr_upper; // eax
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v9; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx

  i_user_data = (AStringRef *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  ++i_user_data->i_ref_count;
  v3 = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64) != 0i64;
  crc32_cstr_upper = AChecksum::generate_crc32_cstr_upper(i_user_data->i_cstr_p, i_user_data->i_length, 0xFFFFFFFF);
  UFG::AISidewalkGraph::SetNodeActive(crc32_cstr_upper, v3);
  if ( i_user_data->i_ref_count-- == 1 )
  {
    if ( i_user_data->i_deallocate )
      AMemory::c_free_func(i_user_data->i_cstr_p);
    pool = AStringRef::get_pool();
    i_block_p = pool->i_block_p;
    i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
    if ( (unsigned __int64)i_user_data < i_objects_a
      || (v9 = (unsigned __int64)i_user_data < i_objects_a + 24i64 * i_block_p->i_size, p_i_exp_pool = &pool->i_pool,
                                                                                        !v9) )
    {
      p_i_exp_pool = &pool->i_exp_pool;
    }
    APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, i_user_data);
  }
}

// File Line: 924
// RVA: 0x4E72C0
void __fastcall UFG::TSWorld::MthdC_get_closest_sidewalk_position(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // r9
  float *i_user_data; // rax
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm6_4
  UFG::AISidewalkEdge_Game *v9; // rax
  UFG::AISidewalkEdge_Game *v10; // rax
  UFG::AISidewalkEdge_Game *StateBagImpl; // rax
  UFG::AISidewalkNode_Game *StartNode; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::AISidewalkEdge_Game *v15; // rax
  UFG::AISidewalkNode_Game *EndNode; // rax
  float v17; // xmm1_4
  float v18; // xmm2_4
  UFG::allocator::free_link *v19; // rax
  float v20; // xmm1_4
  float v21; // xmm2_4
  SSInstance *v22; // rax
  bool v23; // cl
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v25; // rax
  UFG::qVector3 closest_point; // [rsp+20h] [rbp-31h] BYREF
  UFG::qVector3 pos; // [rsp+30h] [rbp-21h] BYREF
  UFG::qVector3 lA1; // [rsp+40h] [rbp-11h] BYREF
  UFG::qVector3 lA0; // [rsp+50h] [rbp-1h] BYREF
  LOCALNAMESPACE::hkNativeResource v30; // [rsp+60h] [rbp+Fh] BYREF

  if ( ppResult )
  {
    i_array_p = pScope->i_data.i_array_p;
    i_user_data = (float *)(*i_array_p)->i_data_p->i_user_data;
    v6 = i_user_data[1];
    v7 = i_user_data[2];
    pos.x = *i_user_data;
    pos.y = v6;
    pos.z = v7;
    v8 = *(float *)&i_array_p[1]->i_data_p->i_user_data;
    UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v30);
    v30.m_contents = (void *)0xFFFFFFFF0001FFFFi64;
    v30.m_contentsTypeName = 0i64;
    v30.m_data.m_size = -1;
    UFG::AISidewalkGraph::FindClosestSidewalkConnection(
      &pos,
      v8,
      (UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)&v30,
      0xFFu);
    if ( Scaleform::GFx::FontManagerStates::GetStateBagImpl(&v30)
      && (v9 = (UFG::AISidewalkEdge_Game *)Scaleform::GFx::FontManagerStates::GetStateBagImpl(&v30),
          UFG::AISidewalkEdge_Game::GetStartNode(v9))
      && (v10 = (UFG::AISidewalkEdge_Game *)Scaleform::GFx::FontManagerStates::GetStateBagImpl(&v30),
          UFG::AISidewalkEdge_Game::GetEndNode(v10)) )
    {
      StateBagImpl = (UFG::AISidewalkEdge_Game *)Scaleform::GFx::FontManagerStates::GetStateBagImpl(&v30);
      StartNode = UFG::AISidewalkEdge_Game::GetStartNode(StateBagImpl);
      y = StartNode->mPos.y;
      z = StartNode->mPos.z;
      lA0.x = StartNode->mPos.x;
      lA0.y = y;
      lA0.z = z;
      v15 = (UFG::AISidewalkEdge_Game *)Scaleform::GFx::FontManagerStates::GetStateBagImpl(&v30);
      EndNode = UFG::AISidewalkEdge_Game::GetEndNode(v15);
      v17 = EndNode->mPos.y;
      v18 = EndNode->mPos.z;
      lA1.x = EndNode->mPos.x;
      lA1.y = v17;
      lA1.z = v18;
      closest_point = UFG::qVector3::msZero;
      UFG::qGetClosestPointOnSegment(&closest_point, &lA0, &lA1, &pos);
      v19 = UFG::qMalloc(0xCui64, "Skookum.qVector3", 0i64);
      if ( v19 )
      {
        v20 = closest_point.y;
        v21 = closest_point.z;
        *(float *)&v19->mNext = closest_point.x;
        *((float *)&v19->mNext + 1) = v20;
        *(float *)&v19[1].mNext = v21;
      }
      v22 = SSInstance::pool_new(UFG::SkookumMgr::mspVector3Class, (unsigned __int64)v19);
      SSInvokedContextBase::set_arg(pScope, 2u, v22);
      v23 = 1;
    }
    else
    {
      v23 = 0;
    }
    *ppResult = SSBoolean::pool_new(v23);
    Inventory = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
    if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
    {
      v25 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v25, 0x43E99F7Eu);
      `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v30, Inventory);
    UFG::qResourceHandle::~qResourceHandle((UFG::qResourceHandle *)&v30);
  }
}

// File Line: 967
// RVA: 0x4ECC40
void __fastcall UFG::TSWorld::MthdC_run_script_test(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx
  unsigned int i_user_data; // ebx
  unsigned int v4; // edi
  bool v5; // si
  UFG::qSymbol *v6; // rbx
  UFG::ProgressionTracker *v7; // rax
  UFG::qBaseTreeRB *v8; // rbx
  UFG::ProgressionTracker *v9; // rax
  UFG::ProgressionTracker *v10; // rax
  UFG::qSymbol result; // [rsp+30h] [rbp+8h] BYREF

  i_array_p = pScope->i_data.i_array_p;
  i_user_data = (*i_array_p)->i_data_p->i_user_data;
  v4 = i_array_p[1]->i_data_p->i_user_data;
  v5 = i_array_p[2]->i_data_p->i_user_data != 0;
  UFG::ProgressionTracker::Instance()->mDEBUGTestScenarioScriptName.mUID = i_user_data;
  UFG::ProgressionTracker::Instance()->mDEBUGTestScenarioParameter.mUID = v4;
  if ( v5
    && (v6 = UFG::qSymbol::create_from_string(&result, "ScriptTests"),
        v7 = UFG::ProgressionTracker::Instance(),
        (v8 = UFG::ProgressionTracker::Find(v7, v6, 0)) != 0i64) )
  {
    v9 = UFG::ProgressionTracker::Instance();
    UFG::ProgressionTracker::ForceSliceChange(v9, (UFG::GameSlice *)v8, 1);
  }
  else
  {
    v10 = UFG::ProgressionTracker::Instance();
    UFG::ProgressionTracker::DEBUG_LaunchTestScenarioIfAvailable(v10);
  }
}

// File Line: 1001
// RVA: 0x4E32D0
void __fastcall UFG::TSWorld::MthdC_add_road_block(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::qBaseNodeRB *mParent; // rdi
  UFG::RoadNetworkResource *RoadNetwork; // rbx
  UFG::RoadNetworkSubSegment *ClosestSubSegment; // rax

  mParent = UFG::MarkerBase::GetNamed((UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data)[1].mNULL.mParent;
  RoadNetwork = UFG::WheeledVehicleNavigationData::GetRoadNetwork(UFG::WheeledVehicleManager::m_Instance->m_NavigationData);
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)mParent);
  ClosestSubSegment = UFG::RoadNetworkResource::GetClosestSubSegment(
                        RoadNetwork,
                        (UFG::qVector3 *)&mParent[5].mChild[1],
                        0);
  if ( ClosestSubSegment )
    UFG::WheeledVehicleNavigationData::AddRoadBlocksAroundSegment(
      UFG::WheeledVehicleManager::m_Instance->m_NavigationData,
      ClosestSubSegment->mParentNode);
}

// File Line: 1026
// RVA: 0x4EC230
void __fastcall UFG::TSWorld::MthdC_remove_road_block(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::qBaseNodeRB *mParent; // rdi
  UFG::RoadNetworkResource *RoadNetwork; // rbx
  UFG::RoadNetworkSubSegment *ClosestSubSegment; // rax

  mParent = UFG::MarkerBase::GetNamed((UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data)[1].mNULL.mParent;
  RoadNetwork = UFG::WheeledVehicleNavigationData::GetRoadNetwork(UFG::WheeledVehicleManager::m_Instance->m_NavigationData);
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)mParent);
  ClosestSubSegment = UFG::RoadNetworkResource::GetClosestSubSegment(
                        RoadNetwork,
                        (UFG::qVector3 *)&mParent[5].mChild[1],
                        0);
  if ( ClosestSubSegment )
    UFG::WheeledVehicleNavigationData::RemoveRoadBlocksAroundSegment(
      UFG::WheeledVehicleManager::m_Instance->m_NavigationData,
      ClosestSubSegment->mParentNode);
}

// File Line: 1052
// RVA: 0x4ED030
void __fastcall UFG::TSWorld::MthdC_set_all_taxis_occupied(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::VehicleOccupantComponent *v2; // rdi
  UFG::SimObjectCVBase *m_pSimObject; // rbx
  UFG::qList<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent,1,0> *v4; // rsi
  __int16 m_Flags; // cx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax
  int NumberOfSeats; // eax
  int v8; // eax

  v2 = (UFG::VehicleOccupantComponent *)&UFG::VehicleOccupantComponent::s_VehicleOccupantComponentList.mNode.mNext[-4];
  if ( (UFG::qList<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent,1,0> *)&UFG::VehicleOccupantComponent::s_VehicleOccupantComponentList.mNode.mNext[-4] != &UFG::VehicleOccupantComponent::s_VehicleOccupantComponentList - 4 )
  {
    do
    {
      m_pSimObject = (UFG::SimObjectCVBase *)v2->m_pSimObject;
      v4 = (UFG::qList<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent,1,0> *)&v2->mNext[-4];
      if ( UFG::SimObjectUtility::IsClassType(m_pSimObject, &qSymbol_Taxi)
        && !(unsigned int)UFG::VehicleOccupantComponent::GetNumberOfPassengers(v2)
        && m_pSimObject )
      {
        m_Flags = m_pSimObject->m_Flags;
        if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
        {
          ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(m_pSimObject);
        }
        else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        {
          ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          m_pSimObject,
                                                          UFG::AiDriverComponent::_TypeUID);
        }
        else
        {
          ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                          m_pSimObject,
                                                          UFG::AiDriverComponent::_TypeUID);
        }
        if ( ComponentOfTypeHK )
        {
          if ( ((unsigned __int8 (__fastcall *)(UFG::AiDriverComponent *))ComponentOfTypeHK->UFG::VehicleDriverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[16].__vecDelDtor)(ComponentOfTypeHK) )
          {
            NumberOfSeats = UFG::VehicleOccupantComponent::GetNumberOfSeats(v2);
            v8 = UFG::qRandom(NumberOfSeats - 2, (unsigned int *)&UFG::qDefaultSeed);
            PropertyUtils::SetRuntime<unsigned long>(
              m_pSimObject->m_pSceneObj,
              (UFG::qArray<unsigned long,0> *)&qSymbol_AmbientPassengerCount,
              v8 + 1);
          }
        }
      }
      v2 = (UFG::VehicleOccupantComponent *)v4;
    }
    while ( v4 != &UFG::VehicleOccupantComponent::s_VehicleOccupantComponentList - 4 );
  }
}

// File Line: 1092
// RVA: 0x4EC440
void __fastcall UFG::TSWorld::MthdC_reset_taxi_occupancy(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::qNode<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent> *p_mNode; // rbx
  UFG::qNode<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent> *mNext; // rdi
  UFG::SimObjectCVBase *v4; // rbx
  UFG::qList<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent,1,0> *v5; // rdi
  __int16 m_Flags; // cx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax

  p_mNode = UFG::VehicleOccupantComponent::s_VehicleOccupantComponentList.mNode.mNext - 4;
  if ( (UFG::qList<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent,1,0> *)&UFG::VehicleOccupantComponent::s_VehicleOccupantComponentList.mNode.mNext[-4] != &UFG::VehicleOccupantComponent::s_VehicleOccupantComponentList - 4 )
  {
    do
    {
      mNext = p_mNode[4].mNext;
      v4 = (UFG::SimObjectCVBase *)p_mNode[2].mNext;
      v5 = (UFG::qList<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent,1,0> *)&mNext[-4];
      if ( UFG::SimObjectUtility::IsClassType(v4, &qSymbol_Taxi) && v4 )
      {
        m_Flags = v4->m_Flags;
        if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
        {
          ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v4);
        }
        else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        {
          ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          v4,
                                                          UFG::AiDriverComponent::_TypeUID);
        }
        else
        {
          ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                          v4,
                                                          UFG::AiDriverComponent::_TypeUID);
        }
        if ( ComponentOfTypeHK
          && ((unsigned __int8 (__fastcall *)(UFG::AiDriverComponent *))ComponentOfTypeHK->UFG::VehicleDriverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[16].__vecDelDtor)(ComponentOfTypeHK)
          && (unsigned int)UFG::qRandom(0x64u, (unsigned int *)&UFG::qDefaultSeed) > UFG::VehicleOccupantComponent::msPercentageChanceTaxiOccupation )
        {
          PropertyUtils::SetRuntime<unsigned long>(
            v4->m_pSceneObj,
            (UFG::qArray<unsigned long,0> *)&qSymbol_AmbientPassengerCount,
            0);
        }
      }
      p_mNode = &v5->mNode;
    }
    while ( v5 != &UFG::VehicleOccupantComponent::s_VehicleOccupantComponentList - 4 );
  }
}

// File Line: 1122
// RVA: 0x4EF3B0
void __fastcall UFG::TSWorld::MthdC_set_transit_targeting_enabled(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCharacter *LocalPlayer; // rax
  UFG::TargetingSystemPedPlayerComponent *v4; // rax

  if ( UFG::GetLocalPlayer() )
  {
    LocalPlayer = UFG::GetLocalPlayer();
    v4 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedPlayerComponent>(LocalPlayer);
    if ( v4 )
      v4->m_TransitTargetingDisabledByScript = (*pScope->i_data.i_array_p)->i_data_p->i_user_data == 0;
  }
}

// File Line: 1141
// RVA: 0x4E4FC0
void __fastcall UFG::TSWorld::MthdC_enable_light_layer(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  Render::EnableLightLayer(
    (*pScope->i_data.i_array_p)->i_data_p->i_user_data,
    *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64) != 0i64);
}

// File Line: 1149
// RVA: 0x4E5340
void __fastcall UFG::TSWorld::MthdC_enable_streaming_lookahead(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SectionChooser::EnableStreamingLookahead((*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0);
}

// File Line: 1156
// RVA: 0x4E9D90
void __fastcall UFG::TSWorld::MthdC_is_xform_in_view(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TransformNodeComponent *i_user_data; // rbx
  UFG::qVector3 *v5; // r15
  UFG::BaseCameraComponent *mCurrentCamera; // rcx
  UFG::Camera *p_mCamera; // rdi
  UFG::qMatrix44 *ViewProjection; // rbx
  UFG::qMatrix44 *WorldView; // rax
  float v10; // xmm12_4
  float v11; // xmm10_4
  float v12; // xmm11_4
  float v13; // xmm13_4
  float v14; // xmm14_4
  float v15; // xmm15_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm0_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm0_4
  __m128 v23; // xmm2
  float v24; // xmm0_4
  float v25; // xmm4_4
  __m128 v26; // xmm2
  float v27; // xmm0_4
  SSData **i_array_p; // rax
  __m128 v29; // xmm2
  float v30; // xmm8_4
  int v31; // eax
  float v32; // [rsp+20h] [rbp-C8h]
  float v33; // [rsp+2Ch] [rbp-BCh]
  float v34; // [rsp+34h] [rbp-B4h]
  float v35; // [rsp+40h] [rbp-A8h]
  float v36; // [rsp+44h] [rbp-A4h]
  UFG::qMatrix44 result; // [rsp+50h] [rbp-98h] BYREF
  float v38; // [rsp+90h] [rbp-58h]
  float v39; // [rsp+94h] [rbp-54h]
  float v40; // [rsp+98h] [rbp-50h]
  float v41; // [rsp+9Ch] [rbp-4Ch]
  float v42; // [rsp+A0h] [rbp-48h]
  float v43; // [rsp+A4h] [rbp-44h]
  float v44; // [rsp+A8h] [rbp-40h]
  float v45; // [rsp+ACh] [rbp-3Ch]
  float v46; // [rsp+B0h] [rbp-38h]
  float v47; // [rsp+B4h] [rbp-34h]
  float v48; // [rsp+B8h] [rbp-30h]
  float v49; // [rsp+BCh] [rbp-2Ch]
  float v50; // [rsp+C0h] [rbp-28h]
  float v51; // [rsp+C4h] [rbp-24h]
  float v52; // [rsp+C8h] [rbp-20h]
  float v53; // [rsp+CCh] [rbp-1Ch]
  float v54; // [rsp+D0h] [rbp-18h]
  float v55; // [rsp+D4h] [rbp-14h]
  unsigned int vars0; // [rsp+1B0h] [rbp+C8h]
  void *retaddr; // [rsp+1B8h] [rbp+D0h]
  float v58; // [rsp+1C0h] [rbp+D8h]

  if ( ppResult )
  {
    i_user_data = (UFG::TransformNodeComponent *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    UFG::TransformNodeComponent::UpdateWorldTransform(i_user_data);
    v5 = (UFG::qVector3 *)&i_user_data->mWorldTransform.v3;
    mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
    if ( mCurrentCamera )
      p_mCamera = &mCurrentCamera->mCamera;
    else
      p_mCamera = 0i64;
    ViewProjection = UFG::Camera::GetViewProjection(p_mCamera);
    WorldView = UFG::Camera::GetWorldView(p_mCamera);
    UFG::qMatrix44::operator*(WorldView, &result, ViewProjection);
    LODWORD(v10) = COERCE_UNSIGNED_INT(result.v0.x + result.v0.w) ^ _xmm[0];
    LODWORD(v35) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.y) ^ _xmm[0];
    LODWORD(v36) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.y) ^ _xmm[0];
    LODWORD(v11) = COERCE_UNSIGNED_INT(result.v2.x + result.v2.w) ^ _xmm[0];
    LODWORD(retaddr) = COERCE_UNSIGNED_INT(result.v0.y + result.v0.w) ^ _xmm[0];
    LODWORD(v12) = COERCE_UNSIGNED_INT(result.v1.x + result.v1.w) ^ _xmm[0];
    vars0 = COERCE_UNSIGNED_INT(result.v1.y + result.v1.w) ^ _xmm[0];
    LODWORD(v13) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.x) ^ _xmm[0];
    LODWORD(v14) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.x) ^ _xmm[0];
    LODWORD(v58) = COERCE_UNSIGNED_INT(result.v2.y + result.v2.w) ^ _xmm[0];
    LODWORD(v15) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.x) ^ _xmm[0];
    LODWORD(v34) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.z) ^ _xmm[0];
    LODWORD(v33) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.z) ^ _xmm[0];
    LODWORD(v32) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.z) ^ _xmm[0];
    v16 = 1.0
        / fsqrt(
            (float)((float)(COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0]))
                  + (float)(COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0])))
          + (float)(COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0])));
    v17 = v16 * COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0]);
    result.v3.y = v16 * COERCE_FLOAT(LODWORD(result.v2.x) ^ _xmm[0]);
    result.v2.z = v16 * COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0]);
    result.v3.x = v17;
    result.v2.w = v16 * COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0]);
    v18 = fsqrt((float)((float)(v10 * v10) + (float)(v12 * v12)) + (float)(v11 * v11));
    v19 = (float)(1.0 / v18) * v10;
    v20 = (float)(1.0 / v18) * v12;
    v21 = 1.0 / v18;
    result.v3.z = v19;
    result.v3.w = v20;
    v39 = v21 * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v1.z + result.v2.y) ^ _xmm[0]);
    v38 = v21 * v11;
    v22 = fsqrt((float)((float)(v14 * v14) + (float)(v13 * v13)) + (float)(v15 * v15));
    v43 = (float)(1.0 / v22) * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v2.y - result.v1.z) ^ _xmm[0]);
    v40 = (float)(1.0 / v22) * v13;
    v42 = (float)(1.0 / v22) * v15;
    v41 = (float)(1.0 / v22) * v14;
    v23 = (__m128)vars0;
    v23.m128_f32[0] = (float)((float)(v23.m128_f32[0] * v23.m128_f32[0])
                            + (float)(*(float *)&retaddr * *(float *)&retaddr))
                    + (float)(v58 * v58);
    v24 = _mm_sqrt_ps(v23).m128_f32[0];
    LODWORD(v25) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.y) ^ _xmm[0];
    v44 = (float)(1.0 / v24) * *(float *)&retaddr;
    v46 = (float)(1.0 / v24) * v58;
    v45 = (float)(1.0 / v24) * *(float *)&vars0;
    v26 = (__m128)LODWORD(v36);
    v47 = (float)(1.0 / v24) * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v1.w + result.v2.y) ^ _xmm[0]);
    v26.m128_f32[0] = (float)((float)(v26.m128_f32[0] * v26.m128_f32[0]) + (float)(v25 * v25)) + (float)(v35 * v35);
    v27 = 1.0 / _mm_sqrt_ps(v26).m128_f32[0];
    v51 = v27 * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v2.y - result.v1.w) ^ _xmm[0]);
    v48 = v27 * v25;
    v49 = v27 * v36;
    v50 = v27 * v35;
    i_array_p = pScope->i_data.i_array_p;
    v29 = (__m128)LODWORD(v34);
    v29.m128_f32[0] = (float)((float)(v29.m128_f32[0] * v29.m128_f32[0]) + (float)(v33 * v33)) + (float)(v32 * v32);
    v30 = 1.0 / _mm_sqrt_ps(v29).m128_f32[0];
    v55 = v30 * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v2.y - result.v2.x) ^ _xmm[0]);
    v52 = v30 * v34;
    v53 = v30 * v33;
    v54 = v30 * v32;
    v31 = IntersectSphereFrustum((UFG::qVector4 *)&result.v2.z, v5, *(float *)&i_array_p[1]->i_data_p->i_user_data);
    *ppResult = SSBoolean::pool_new(v31 != 2);
  }
}

// File Line: 1174
// RVA: 0x4EE130
void __fastcall UFG::TSWorld::MthdC_set_input_camera_only(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::Controller *v2; // r8

  v2 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
  if ( (*pScope->i_data.i_array_p)->i_data_p->i_user_data )
  {
    if ( v2->m_ActiveMapSet != 2 )
    {
      saved_mode_flag = v2->m_ActiveMapSet;
      UFG::SetInputMode(IM_CAMERA_ONLY, v2->mControllerIndex);
    }
  }
  else if ( saved_mode_flag )
  {
    UFG::SetInputMode(saved_mode_flag, v2->mControllerIndex);
    saved_mode_flag = IM_INVALID;
  }
}

// File Line: 1199
// RVA: 0x4F2A20
void __fastcall UFG::TSWorld::MthdC_trophy_reward(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  int v2; // eax

  v2 = UFG::HKAchievementTrophyManager::mapAchievmentStringToID((*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  if ( v2 > 0 )
    UFG::AchievementTrophyManager::UnlockAchievementTrophy(v2);
}

// File Line: 1209
// RVA: 0x4EB470
void __fastcall UFG::TSWorld::MthdC_print_snapshot(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  AMD_HD3D *v2; // rax

  v2 = (AMD_HD3D *)UFG::GameStatTracker::Instance();
  _(v2);
}

// File Line: 1220
// RVA: 0x4EE470
void __fastcall UFG::TSWorld::MthdC_set_max_traffic_cars(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  unsigned int i_user_data; // ecx

  i_user_data = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  if ( i_user_data == -1 )
    UFG::WheeledVehicleManager::ResetMaxTrafficCars();
  else
    UFG::WheeledVehicleManager::SetMaxTrafficCars(i_user_data);
}

// File Line: 1244
// RVA: 0x4EE450
void __fastcall UFG::TSWorld::MthdC_set_max_parked_cars(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  unsigned int i_user_data; // ecx

  i_user_data = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  if ( i_user_data == -1 )
    UFG::WheeledVehicleManager::ResetMaxParkedCars();
  else
    UFG::WheeledVehicleManager::SetMaxParkedCars(i_user_data);
}

// File Line: 1273
// RVA: 0x4E50C0
void __fastcall UFG::TSWorld::MthdC_enable_possessed_peds(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  bool v2; // bl

  v2 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  UFG::ProgressionTracker::Instance()->mIsPossessedPedsEnabled = v2;
}

// File Line: 1281
// RVA: 0x4E9800
void __fastcall UFG::TSWorld::MthdC_is_possessed_peds_enabled(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::ProgressionTracker *v3; // rax

  if ( ppResult )
  {
    v3 = UFG::ProgressionTracker::Instance();
    *ppResult = SSBoolean::pool_new(v3->mIsPossessedPedsEnabled);
  }
}

// File Line: 1295
// RVA: 0x4E3C50
void __fastcall UFG::TSWorld::MthdC_audio_set_music_state(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx
  SSInstance *i_data_p; // rdi
  unsigned int v4; // ebx
  unsigned int v5; // eax

  i_array_p = pScope->i_data.i_array_p;
  i_data_p = i_array_p[1]->i_data_p;
  v4 = UFG::TiDo::CalcWwiseUid(*(const char **)(*i_array_p)->i_data_p->i_user_data);
  v5 = UFG::TiDo::CalcWwiseUid(*(const char **)i_data_p->i_user_data);
  UFG::Music::SetMusicState(v4, v5);
}

// File Line: 1332
// RVA: 0x4E3B20
void __fastcall UFG::TSWorld::MthdC_audio_is_music_playing(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  unsigned int v3; // eax

  if ( ppResult )
  {
    v3 = UFG::Music::sm_instance->vfptr->CountNumPlayingEvents(UFG::Music::sm_instance);
    *ppResult = SSBoolean::pool_new(v3 != 0);
  }
}

// File Line: 1346
// RVA: 0x4E3B00
void __fastcall UFG::TSWorld::MthdC_audio_enable_health_effects(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::HealthComponent::ms_bEnableAudioEffects = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
}

// File Line: 1354
// RVA: 0x4E3C00
void __fastcall UFG::TSWorld::MthdC_audio_music_event(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  unsigned int v2; // eax

  v2 = UFG::TiDo::CalcWwiseUid(*(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  UFG::Music::MusicEvent(v2);
}

// File Line: 1365
// RVA: 0x4E3A30
void __fastcall UFG::TSWorld::MthdC_audio_ambience_event(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  unsigned int v2; // eax

  v2 = UFG::TiDo::CalcWwiseUid(*(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  UFG::AudioEntity::CreateAndPlayEvent(UFG::AmbienceAudio::m_instance, v2, 0i64, 0, 0i64);
}

// File Line: 1377
// RVA: 0x4E3A70
void __fastcall UFG::TSWorld::MthdC_audio_ambience_rtpc(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx
  SSInstance *i_data_p; // rdi
  SSInstance *v4; // rbx
  bool v5; // si
  unsigned int v6; // edx
  float v7; // xmm2_4

  i_array_p = pScope->i_data.i_array_p;
  i_data_p = (*i_array_p)->i_data_p;
  v4 = i_array_p[1]->i_data_p;
  v5 = i_array_p[2]->i_data_p->i_user_data != 0;
  if ( UFG::TiDo::GetIsInstantiated() )
  {
    v6 = UFG::TiDo::CalcWwiseUid(*(const char **)i_data_p->i_user_data);
    v7 = *(float *)&v4->i_user_data;
    if ( v5 )
      UFG::TiDo::SetWwiseRtpcValue(UFG::TiDo::m_pInstance, v6, v7, 0xFFFFFFFFFFFFFFFFui64);
    else
      UFG::AudioEntity::SetRtpcValue(UFG::AmbienceAudio::m_instance, v6, v7);
  }
}

// File Line: 1397
// RVA: 0x4E3BA0
void __fastcall UFG::TSWorld::MthdC_audio_load_soundbank(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::qWiseSymbol result; // [rsp+40h] [rbp+8h] BYREF

  UFG::qWiseSymbol::create_from_string(&result, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  UFG::TiDo::GetInstance();
  UFG::TiDo::LoadWwiseBank(&result);
  _((AMD_HD3D *)result.mUID);
}

// File Line: 1411
// RVA: 0x4DA560
char __fastcall UFG::TSWorld::Coro_audio_load_soundbank(
        hkgpIndexedMesh::EdgeBarrier *pScope,
        hkgpIndexedMeshDefinitions::Edge *a2)
{
  bool v4; // bl
  UFG::qWiseSymbol result; // [rsp+48h] [rbp+10h] BYREF

  if ( Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(pScope, a2) )
    return 1;
  UFG::qWiseSymbol::create_from_string(
    &result,
    **(const char ***)(*((_QWORD *)pScope[12].vfptr->__vecDelDtor + 1) + 32i64));
  if ( !LODWORD(pScope[14].vfptr) )
  {
    UFG::TiDo::GetInstance();
    UFG::TiDo::LoadWwiseBank(&result);
  }
  v4 = UFG::SoundBankManager::BankLoadRequestFinished(&result);
  _((AMD_HD3D *)result.mUID);
  return v4;
}

// File Line: 1434
// RVA: 0x4DA5D0
_BOOL8 __fastcall UFG::TSWorld::Coro_audio_wait_until_soundbank_loaded(SSInvokedCoroutine *pScope)
{
  bool v1; // bl
  UFG::qWiseSymbol result; // [rsp+40h] [rbp+8h] BYREF

  UFG::qWiseSymbol::create_from_string(&result, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  v1 = UFG::SoundBankManager::BankLoadRequestFinished(&result);
  _((AMD_HD3D *)result.mUID);
  return v1;
}

// File Line: 1448
// RVA: 0x4DEB10
bool __fastcall UFG::TSWorld::Coro_wait_for_resources(SSInvokedCoroutine *pScope)
{
  unsigned int i_update_count; // eax
  UFG::ProgressionTracker *v2; // rax

  i_update_count = pScope->i_update_count;
  if ( !i_update_count )
    return 0;
  if ( i_update_count == 1 )
  {
    v2 = UFG::ProgressionTracker::Instance();
    UFG::ProgressionTracker::WaitForStreamer(v2);
    return 0;
  }
  return (unsigned int)UFG::FlowController::GetCurrentState(&UFG::gFlowController) != uidGameStateChangeLocation_10;
}

// File Line: 1481
// RVA: 0x4E3C30
void __fastcall UFG::TSWorld::MthdC_audio_set_listener_at_camera(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::AudioListener::sm_pInstance->m_positionListenerAtCamera = 1;
}

// File Line: 1487
// RVA: 0x4E3C40
void __fastcall UFG::TSWorld::MthdC_audio_set_listener_at_player(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::AudioListener::sm_pInstance->m_positionListenerAtCamera = 0;
}

// File Line: 1505
// RVA: 0x4E3BF0
void __fastcall UFG::TSWorld::MthdC_audio_lock_listener_position(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::AudioListener::sm_pInstance->m_lockListenerPosition = 1;
}

// File Line: 1511
// RVA: 0x4E3E20
void __fastcall UFG::TSWorld::MthdC_audio_unlock_listener_position(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::AudioListener::sm_pInstance->m_lockListenerPosition = 0;
}

// File Line: 1517
// RVA: 0x4E3B50
void __fastcall UFG::TSWorld::MthdC_audio_listener_disable_high_speed(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::AudioListener::sm_pInstance->m_highSpeedModeEnabled = 0;
}

// File Line: 1523
// RVA: 0x4E3B60
void __fastcall UFG::TSWorld::MthdC_audio_listener_enable_high_speed(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::AudioListener::sm_pInstance->m_highSpeedModeEnabled = 1;
}

// File Line: 1530
// RVA: 0x4E3B70
void __fastcall UFG::TSWorld::MthdC_audio_load_resources_debug(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TidoGame::LoadGameSliceAudioResources(
    *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
    **(const char ***)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64));
}

// File Line: 1538
// RVA: 0x4E3DA0
void __fastcall UFG::TSWorld::MthdC_audio_unload_resources_debug(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TidoGame::UnloadGameSliceAudioResources(
    *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
    **(const char ***)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64));
}

// File Line: 1547
// RVA: 0x4E3DD0
void __fastcall UFG::TSWorld::MthdC_audio_unload_soundbank(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::qWiseSymbol result; // [rsp+40h] [rbp+8h] BYREF

  UFG::qWiseSymbol::create_from_string(&result, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  UFG::TiDo::GetInstance();
  UFG::TiDo::UnloadWwiseBank(&result);
  _((AMD_HD3D *)result.mUID);
}

// File Line: 1562
// RVA: 0x4E9130
void __fastcall UFG::TSWorld::MthdC_init_constants(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  _QWORD *v2; // rbx
  unsigned int v3; // xmm0_4
  SSInstance *v4; // rax
  __int64 v5; // r9
  unsigned int v6; // xmm0_4
  SSInstance *v7; // rax
  SSInstance *v8; // rax
  ASymbol v9; // [rsp+20h] [rbp-18h] BYREF
  ASymbol v10; // [rsp+24h] [rbp-14h] BYREF
  float user_data; // [rsp+50h] [rbp+18h]
  ASymbol result; // [rsp+58h] [rbp+20h] BYREF

  v2 = (_QWORD *)((__int64 (__fastcall *)(SSActorClass *, SSInstance **))SkookumScript::c_world_class_p->vfptr->get_metaclass)(
                   SkookumScript::c_world_class_p,
                   ppResult);
  ASymbol::create(&result, "c_speed_walk", 0xFFFFFFFF, ATerm_long);
  *(float *)&v3 = UFG::GetNaturalMovementSpeed(eMoveType_Walk);
  v4 = SSInstance::pool_new(SSBrain::c_real_class_p, v3);
  v5 = v2[1];
  (*(void (__fastcall **)(_QWORD *, ASymbol *, SSInstance *))(v5 + 40))(++v2, &result, v4);
  ASymbol::create(&v9, "c_speed_jog", 0xFFFFFFFF, ATerm_long);
  *(float *)&v6 = UFG::GetNaturalMovementSpeed(eMoveType_Jog);
  v7 = SSInstance::pool_new(SSBrain::c_real_class_p, v6);
  (*(void (__fastcall **)(_QWORD *, ASymbol *, SSInstance *))(*v2 + 40i64))(v2, &v9, v7);
  ASymbol::create(&v10, "c_speed_run", 0xFFFFFFFF, ATerm_long);
  user_data = UFG::GetNaturalMovementSpeed(eMoveType_Run);
  v8 = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(user_data));
  (*(void (__fastcall **)(_QWORD *, ASymbol *, SSInstance *))(*v2 + 40i64))(v2, &v10, v8);
}

// File Line: 1584
// RVA: 0x4E5070
void __fastcall UFG::TSWorld::MthdC_enable_navigation_logging(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  int i_user_data; // ecx

  i_user_data = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  UFG::gEnableNavigationLoggingToFile = (i_user_data & 2) != 0;
  UFG::gEnableNavigationLoggingToConsole = i_user_data & 1;
}

// File Line: 1614
// RVA: 0x4ECEC0
void __fastcall UFG::TSWorld::MthdC_section_is_3d(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  unsigned int CellIndexAtPosition; // eax
  char Flags; // al

  if ( ppResult )
  {
    CellIndexAtPosition = UFG::SectionChooser::GetCellIndexAtPosition(
                            (UFG::qVector3 *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                            0);
    Flags = UFG::SectionLayout::GetFlags(CellIndexAtPosition);
    *ppResult = SSBoolean::pool_new((Flags & 2) != 0);
  }
}

// File Line: 1628
// RVA: 0x4ECD40
void __fastcall UFG::TSWorld::MthdC_section_get_name(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  unsigned int CellIndexAtPosition; // eax
  char *SectionNameFromCellIndex; // rax
  char *v5; // rsi
  __int64 v6; // rbx
  unsigned int v7; // eax
  char v8; // di
  AString *p_elem; // rcx
  AStringRef *i_str_ref_p; // rbx
  bool v11; // zf
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v15; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx
  AStringRef *v17; // rbx
  AObjReusePool<AStringRef> *v18; // rax
  AObjBlock<AStringRef> *v19; // rcx
  unsigned __int64 v20; // rdx
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_pool; // rcx
  AString str; // [rsp+68h] [rbp+10h] BYREF
  AStringRef *elem; // [rsp+70h] [rbp+18h] BYREF

  if ( ppResult )
  {
    CellIndexAtPosition = UFG::SectionChooser::GetCellIndexAtPosition(
                            (UFG::qVector3 *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                            0);
    SectionNameFromCellIndex = UFG::SectionLayout::GetSectionNameFromCellIndex(CellIndexAtPosition);
    v5 = SectionNameFromCellIndex;
    if ( SectionNameFromCellIndex )
    {
      v6 = -1i64;
      do
        ++v6;
      while ( SectionNameFromCellIndex[v6] );
      v7 = AMemory::c_req_byte_size_func(v6 + 1);
      v8 = 1;
      elem = AStringRef::pool_new(v5, v6, v7, 1u, 0, 1);
      p_elem = (AString *)&elem;
    }
    else
    {
      str.i_str_ref_p = AStringRef::get_empty();
      ++str.i_str_ref_p->i_ref_count;
      p_elem = &str;
      v8 = 2;
    }
    *ppResult = SSString::as_instance(p_elem);
    if ( (v8 & 2) != 0 )
    {
      v8 &= ~2u;
      i_str_ref_p = str.i_str_ref_p;
      v11 = str.i_str_ref_p->i_ref_count-- == 1;
      if ( v11 )
      {
        if ( i_str_ref_p->i_deallocate )
          AMemory::c_free_func(i_str_ref_p->i_cstr_p);
        pool = AStringRef::get_pool();
        i_block_p = pool->i_block_p;
        i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
        if ( (unsigned __int64)i_str_ref_p < i_objects_a
          || (v15 = (unsigned __int64)i_str_ref_p < i_objects_a + 24i64 * i_block_p->i_size,
              p_i_exp_pool = &pool->i_pool,
              !v15) )
        {
          p_i_exp_pool = &pool->i_exp_pool;
        }
        APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, i_str_ref_p);
      }
    }
    if ( (v8 & 1) != 0 )
    {
      v17 = elem;
      v11 = elem->i_ref_count-- == 1;
      if ( v11 )
      {
        if ( v17->i_deallocate )
          AMemory::c_free_func(v17->i_cstr_p);
        v18 = AStringRef::get_pool();
        v19 = v18->i_block_p;
        v20 = (unsigned __int64)v19->i_objects_a;
        if ( (unsigned __int64)v17 < v20
          || (v15 = (unsigned __int64)v17 < v20 + 24i64 * v19->i_size, p_i_pool = &v18->i_pool, !v15) )
        {
          p_i_pool = &v18->i_exp_pool;
        }
        APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_pool, v17);
      }
    }
  }
}

// File Line: 1642
// RVA: 0x4EA560
void __fastcall UFG::TSWorld::MthdC_last_used_vehicle_is_within_range(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // r8
  bool v4; // di
  float *i_user_data; // rax
  float v6; // xmm9_4
  float v7; // xmm8_4
  float v8; // xmm10_4
  float v9; // xmm11_4
  UFG::GameStatTracker *v10; // rax
  UFG::GameStatTracker *v11; // rax
  UFG::GameStatTracker *v12; // rax
  float Stat; // xmm7_4
  UFG::GameStatTracker *v14; // rax
  float v15; // xmm6_4
  UFG::GameStatTracker *v16; // rax
  float v17; // xmm0_4

  if ( ppResult )
  {
    i_array_p = pScope->i_data.i_array_p;
    v4 = 0;
    i_user_data = (float *)(*i_array_p)->i_data_p->i_user_data;
    v6 = *i_user_data;
    v7 = i_user_data[1];
    v8 = i_user_data[2];
    v9 = *(float *)&i_array_p[1]->i_data_p->i_user_data;
    v10 = UFG::GameStatTracker::Instance();
    if ( UFG::GameStatTracker::GetStat(v10, LastUsedVehicle)->mValue.mUID != -1 )
    {
      v11 = UFG::GameStatTracker::Instance();
      if ( UFG::GameStatTracker::GetStat(v11, LastUsedVehicleIsCurrentlyUsed) )
      {
        v4 = 1;
      }
      else
      {
        v12 = UFG::GameStatTracker::Instance();
        Stat = UFG::GameStatTracker::GetStat(v12, LastUsedVehicleDismountLocationX);
        v14 = UFG::GameStatTracker::Instance();
        v15 = UFG::GameStatTracker::GetStat(v14, LastUsedVehicleDismountLocationY);
        v16 = UFG::GameStatTracker::Instance();
        v17 = UFG::GameStatTracker::GetStat(v16, LastUsedVehicleDismountLocationZ);
        v4 = (float)(v9 * v9) >= (float)((float)((float)((float)(v7 - v15) * (float)(v7 - v15))
                                               + (float)((float)(v6 - Stat) * (float)(v6 - Stat)))
                                       + (float)((float)(v8 - v17) * (float)(v8 - v17)));
      }
    }
    *ppResult = SSBoolean::pool_new(v4);
  }
}

// File Line: 1684
// RVA: 0x4EC2B0
void __fastcall UFG::TSWorld::MthdC_render_enable_exterior(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::RenderWorld::SetFlags((*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0);
}

// File Line: 1708
// RVA: 0x4E4C90
void __fastcall UFG::TSWorld::MthdC_enable_LOD_suppression(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SectionChooser::SetSuppressLOD((UFG::SectionChooser::LOD_SUPRESSION)((*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0));
}

// File Line: 1719
// RVA: 0x4DCF20
bool __fastcall UFG::TSWorld::Coro_render_override_environment(SSInvokedCoroutine *pScope)
{
  SSData **i_array_p; // rdx
  unsigned int i_user_data; // edi
  float v3; // xmm7_4
  SSInstance *i_data_p; // rsi
  float v5; // xmm6_4
  UFG::TimeOfDayManager *Instance; // rax
  UFG::TimeOfDayManager *v7; // rbx
  float v8; // xmm3_4
  float v9; // xmm2_4
  float m_OverrideStateBlockAmount; // xmm4_4
  float v11; // xmm1_4
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v13; // rax

  i_array_p = pScope->i_data.i_array_p;
  i_user_data = (*i_array_p)->i_data_p->i_user_data;
  v3 = *(float *)&i_array_p[1]->i_data_p->i_user_data;
  i_data_p = i_array_p[2]->i_data_p;
  v5 = v3;
  Instance = UFG::TimeOfDayManager::GetInstance();
  v7 = Instance;
  v8 = *(float *)&i_data_p->i_user_data;
  v9 = 0.0;
  if ( v8 > 0.0 )
  {
    if ( Instance->mOverrideStateBlockHandle.mNameUID == i_user_data )
      m_OverrideStateBlockAmount = Instance->m_OverrideStateBlockAmount;
    else
      m_OverrideStateBlockAmount = 0.0;
    v5 = *(float *)&FLOAT_1_0;
    v11 = (float)((float)(UFG::Metrics::msRealTimeDelta_Accurate / v8) * (float)(v3 - m_OverrideStateBlockAmount))
        + m_OverrideStateBlockAmount;
    if ( v11 < 0.0
      || (v9 = (float)((float)(UFG::Metrics::msRealTimeDelta_Accurate / v8) * (float)(v3 - m_OverrideStateBlockAmount))
             + m_OverrideStateBlockAmount,
          v11 <= 1.0) )
    {
      v5 = v9;
    }
    *(float *)&i_data_p->i_user_data = v8 - UFG::Metrics::msRealTimeDelta_Accurate;
  }
  Instance->m_OverrideStateBlockAmount = v5;
  Inventory = `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result )
  {
    v13 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v13, 0x4D04C7F2u);
    `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&v7->mOverrideStateBlockHandle, 0x4D04C7F2u, i_user_data, Inventory);
  return v5 == v3;
}

// File Line: 1789
// RVA: 0x4E5370
void __fastcall UFG::TSWorld::MthdC_enable_vehicles_blip(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // r8
  bool v4; // si
  __int64 v5; // rax
  __int64 v6; // rax
  UFG::VehiclesBlipComponent *v7; // rcx
  UFG::qList<UFG::VehiclesBlipComponent,UFG::VehiclesBlipComponent,1,0> *v8; // rbx
  UFG::qString v9; // [rsp+38h] [rbp-30h] BYREF

  i_array_p = pScope->i_data.i_array_p;
  v4 = (*i_array_p)->i_data_p->i_user_data != 0;
  UFG::VehiclesBlipComponent::mVehicleType.mUID = i_array_p[1]->i_data_p->i_user_data;
  UFG::qString::qString(&v9, **(const char ***)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 2) + 8i64) + 32i64));
  UFG::qString::Set(&UFG::VehiclesBlipComponent::mBlipType, *(const char **)(v5 + 24), *(_DWORD *)(v5 + 20), 0i64, 0);
  UFG::qString::~qString(&v9);
  UFG::qString::qString(&v9, **(const char ***)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 3) + 8i64) + 32i64));
  UFG::qString::Set(&UFG::VehiclesBlipComponent::mMapCaption, *(const char **)(v6 + 24), *(_DWORD *)(v6 + 20), 0i64, 0);
  UFG::qString::~qString(&v9);
  v7 = (UFG::VehiclesBlipComponent *)&UFG::VehiclesBlipComponent::s_VehiclesBlipComponentList.mNode.mNext[-4];
  if ( (UFG::qList<UFG::VehiclesBlipComponent,UFG::VehiclesBlipComponent,1,0> *)&UFG::VehiclesBlipComponent::s_VehiclesBlipComponentList.mNode.mNext[-4] != &UFG::VehiclesBlipComponent::s_VehiclesBlipComponentList - 4 )
  {
    do
    {
      v8 = (UFG::qList<UFG::VehiclesBlipComponent,UFG::VehiclesBlipComponent,1,0> *)&v7->mNext[-4];
      UFG::VehiclesBlipComponent::Enable(v7, v4);
      v7 = (UFG::VehiclesBlipComponent *)v8;
    }
    while ( v8 != &UFG::VehiclesBlipComponent::s_VehiclesBlipComponentList - 4 );
  }
  UFG::VehiclesBlipComponent::mVehicleType.mUID = UFG::gNullQSymbol.mUID;
}

// File Line: 1813
// RVA: 0x4E4C00
void __fastcall UFG::TSWorld::MthdC_disable_proxy_peds(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::PedSpawnManager *Instance; // rax

  Instance = UFG::PedSpawnManager::GetInstance();
  UFG::PedSpawnManager::DisableProxyPeds(Instance);
}

// File Line: 1824
// RVA: 0x4EDFB0
void __fastcall UFG::TSWorld::MthdC_set_hi_def_spawning(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  bool v2; // bl
  UFG::PedSpawnManager *Instance; // rax

  v2 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  Instance = UFG::PedSpawnManager::GetInstance();
  UFG::PedSpawnManager::SetHighDefSpawning(Instance, v2);
}

// File Line: 1837
// RVA: 0x4E61B0
void __fastcall UFG::TSWorld::MthdC_facial_animation_disable(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::FacialActionTreeComponent::sDisableFacialAnimation = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
}

// File Line: 1843
// RVA: 0x4E4A80
void __fastcall UFG::TSWorld::MthdC_debug_cam_fov(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *m_pSimObject; // rcx

  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
    UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::DebugCameraComponent::_TypeUID);
}

// File Line: 1865
// RVA: 0x4E50F0
void __fastcall UFG::TSWorld::MthdC_enable_proxy_peds(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::PedSpawnManager *Instance; // rax

  Instance = UFG::PedSpawnManager::GetInstance();
  UFG::PedSpawnManager::EnableProxyPeds(Instance);
}

// File Line: 1876
// RVA: 0x4EBC00
void __fastcall UFG::TSWorld::MthdC_rebalance_ambience(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::PedSpawnManager::msRequestEmergencyDump = 1;
}

// File Line: 1889
// RVA: 0x4E4C80
// attributes: thunk
void __fastcall UFG::TSWorld::MthdC_dry_fire_near_spawn_zones(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::PedSpawnManager::DryFireNearSpawnZones();
}

// File Line: 1901
// RVA: 0x4E4AE0
void __fastcall UFG::TSWorld::MthdC_delete_all_ambient_peds(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::PedSpawning_AmbientPedEnableHelper(0);
}

// File Line: 1918
// RVA: 0x4F3340
void __fastcall UFG::TSWorld::MthdC_vendor_extortion_hack(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::ProgressionTracker *v2; // rax
  UFG::GameSaveLoad *v3; // rax

  v2 = UFG::ProgressionTracker::Instance();
  UFG::ProgressionTracker::VendorExtortionHack(v2);
  v3 = UFG::GameSaveLoad::Instance();
  UFG::GameSaveLoad::SaveAutoGameSlot(v3);
}

// File Line: 1930
// RVA: 0x4E4CB0
void __fastcall UFG::TSWorld::MthdC_enable_all_ambient_peds(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::PedSpawning_AmbientPedEnableHelper(1);
}

// File Line: 1941
// RVA: 0x4E4AF0
void __fastcall UFG::TSWorld::MthdC_delete_peds_from_deactivated_regions(
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::PedSpawnManager *Instance; // rax

  Instance = UFG::PedSpawnManager::GetInstance();
  UFG::PedSpawnManager::DeletePedsFromDeactivatedRegions(Instance);
}

// File Line: 1946
// RVA: 0x4F2260
void __fastcall UFG::TSWorld::MthdC_spawn_zones_near_camera(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  float v2; // xmm6_4
  UFG::PedSpawnManager *Instance; // rax

  v2 = *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  Instance = UFG::PedSpawnManager::GetInstance();
  UFG::PedSpawnManager::SpawnZonesNearCamera(Instance, v2);
}

// File Line: 1954
// RVA: 0x4E42D0
void __fastcall UFG::TSWorld::MthdC_clean_up_free_weapons(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  bool v2; // bl
  UFG::WeaponManager *v3; // rax

  v2 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  v3 = UFG::WeaponManager::Instance();
  UFG::WeaponManager::CleanUpFreeWeapons(v3, v2);
}

// File Line: 1969
// RVA: 0x4E3CA0
void __fastcall UFG::TSWorld::MthdC_audio_setup_two_person_conversation(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  bool v2; // si
  SSActor *i_data_p; // rdi
  SSClass *i_class_p; // rbx
  SSActor *v7; // rbx
  SSClass *v8; // r14

  v2 = 0;
  i_data_p = (SSActor *)(*pScope->i_data.i_array_p)->i_data_p;
  if ( !i_data_p )
    goto LABEL_6;
  i_class_p = i_data_p->i_class_p;
  if ( i_class_p->vfptr->is_actor_class(i_class_p) )
    goto LABEL_7;
  if ( i_class_p == SSBrain::c_symbol_class_p && LODWORD(i_data_p->i_user_data) != -1 )
    i_data_p = SSActor::find((ASymbol *)&i_data_p->i_user_data);
  else
LABEL_6:
    i_data_p = 0i64;
LABEL_7:
  v7 = *(SSActor **)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64);
  if ( !v7 )
    goto LABEL_12;
  v8 = v7->i_class_p;
  if ( !v8->vfptr->is_actor_class(v8) )
  {
    if ( v8 == SSBrain::c_symbol_class_p && LODWORD(v7->i_user_data) != -1 )
    {
      v7 = SSActor::find((ASymbol *)&v7->i_user_data);
      goto LABEL_13;
    }
LABEL_12:
    v7 = 0i64;
  }
LABEL_13:
  if ( i_data_p && v7 && *(_QWORD *)&i_data_p[1].i_icoroutines_to_update.i_count )
    v2 = *(_QWORD *)&v7[1].i_icoroutines_to_update.i_count != 0i64;
  if ( ppResult )
    *ppResult = SSBoolean::pool_new(v2);
}

// File Line: 2000
// RVA: 0x4DA9C0
bool __fastcall UFG::TSWorld::Coro_find_character_spawn_position(SSInvokedCoroutine *pScope)
{
  SSData **i_array_p; // r10
  bool result; // al
  SSData **v4; // rdx
  SSInstance *i_data_p; // rcx
  float v6; // xmm0_4
  float v7; // xmm0_4

  i_array_p = pScope->i_data.i_array_p;
  if ( (unsigned __int8)UFG::SimObjectUtility::FindSpawnCharacterPosition(
                          (UFG::qVector3 *)(*i_array_p)->i_data_p->i_user_data,
                          *(float *)&i_array_p[1]->i_data_p->i_user_data,
                          *(float *)&i_array_p[2]->i_data_p->i_user_data,
                          i_array_p[3]->i_data_p->i_user_data != 0) )
  {
    *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 5) + 8i64) + 32i64) = 1i64;
    return 1;
  }
  else
  {
    v4 = pScope->i_data.i_array_p;
    i_data_p = v4[4]->i_data_p;
    v6 = *(float *)&i_data_p->i_user_data;
    if ( v6 <= 0.0 )
      return 0;
    v7 = v6 - UFG::Metrics::msInstance.mSimTimeDelta;
    *(float *)&i_data_p->i_user_data = v7;
    if ( v7 > 0.0 )
    {
      return 0;
    }
    else
    {
      result = 1;
      v4[5]->i_data_p->i_user_data = 0i64;
    }
  }
  return result;
}

// File Line: 2038
// RVA: 0x4DAB60
bool __fastcall UFG::TSWorld::Coro_find_vehicle_spawn_xform(SSInvokedCoroutine *pScope)
{
  SSData **i_array_p; // rbx
  bool result; // al
  SSData **v4; // rdx
  SSInstance *i_data_p; // rcx
  float v6; // xmm0_4
  float v7; // xmm0_4
  UFG::qMatrix44 m; // [rsp+40h] [rbp-48h] BYREF

  i_array_p = pScope->i_data.i_array_p;
  if ( (unsigned __int8)UFG::SimObjectUtility::FindSpawnVehicleTransformIterated(
                          (UFG::qVector3 *)(*i_array_p)->i_data_p->i_user_data,
                          *(float *)&i_array_p[1]->i_data_p->i_user_data,
                          *(float *)&i_array_p[2]->i_data_p->i_user_data,
                          i_array_p[3]->i_data_p->i_user_data != 0) )
  {
    UFG::TransformNodeComponent::SetWorldTransform(
      *(UFG::TransformNodeComponent **)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 6) + 8i64) + 32i64),
      &m);
    *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 5) + 8i64) + 32i64) = 1i64;
    return 1;
  }
  else
  {
    v4 = pScope->i_data.i_array_p;
    i_data_p = v4[4]->i_data_p;
    v6 = *(float *)&i_data_p->i_user_data;
    if ( v6 <= 0.0 )
      return 0;
    v7 = v6 - UFG::Metrics::msInstance.mSimTimeDelta;
    *(float *)&i_data_p->i_user_data = v7;
    if ( v7 > 0.0 )
    {
      return 0;
    }
    else
    {
      result = 1;
      v4[5]->i_data_p->i_user_data = 0i64;
    }
  }
  return result;
}

// File Line: 2080
// RVA: 0x4DA8E0
bool __fastcall UFG::TSWorld::Coro_find_boat_spawn_xform(SSInvokedCoroutine *pScope)
{
  SSData **i_array_p; // r9
  bool result; // al
  SSData **v4; // rdx
  SSInstance *i_data_p; // rcx
  float v6; // xmm0_4
  float v7; // xmm0_4
  UFG::qVector3 pos; // [rsp+30h] [rbp-18h] BYREF

  i_array_p = pScope->i_data.i_array_p;
  if ( UFG::SimObjectUtility::FindSpawnBoatPosition(
         (UFG::qVector3 *)(*i_array_p)->i_data_p->i_user_data,
         *(float *)&i_array_p[1]->i_data_p->i_user_data,
         *(float *)&i_array_p[2]->i_data_p->i_user_data,
         i_array_p[3]->i_data_p->i_user_data != 0,
         &pos) )
  {
    UFG::TransformNodeComponent::SetWorldTranslation(
      *(UFG::TransformNodeComponent **)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 6) + 8i64) + 32i64),
      &pos);
    *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 5) + 8i64) + 32i64) = 1i64;
    return 1;
  }
  else
  {
    v4 = pScope->i_data.i_array_p;
    i_data_p = v4[4]->i_data_p;
    v6 = *(float *)&i_data_p->i_user_data;
    if ( v6 <= 0.0 )
      return 0;
    v7 = v6 - UFG::Metrics::msInstance.mSimTimeDelta;
    *(float *)&i_data_p->i_user_data = v7;
    if ( v7 > 0.0 )
    {
      return 0;
    }
    else
    {
      result = 1;
      v4[5]->i_data_p->i_user_data = 0i64;
    }
  }
  return result;
}

// File Line: 2123
// RVA: 0x4D9F00
bool __fastcall UFG::TSWorld::Coro_apply_scene_settings_at_position(SSInvokedCoroutine *pScope)
{
  UFG::qVector3 *i_user_data; // rbx
  UFG::ProgressionTracker *v3; // rax

  if ( pScope->i_update_count )
    return (unsigned int)UFG::FlowController::GetCurrentState(&UFG::gFlowController) != uidGameStateChangeLocation_10;
  i_user_data = (UFG::qVector3 *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  if ( !i_user_data )
    return 1;
  v3 = UFG::ProgressionTracker::Instance();
  UFG::ProgressionTracker::ApplySceneSettings(v3, i_user_data);
  return 0;
}

// File Line: 2141
// RVA: 0x4D9E10
bool __fastcall UFG::TSWorld::Coro_apply_scene_settings(SSInvokedCoroutine *pScope)
{
  SSData **i_array_p; // rdx
  bool v2; // di
  bool v3; // si
  const char ***p_i_user_data; // r8
  UFG::qSymbol *v5; // rbx
  UFG::ProgressionTracker *v6; // rax
  UFG::qBaseTreeRB *SceneSettings; // rax
  UFG::SceneSettings *v8; // rbx
  UFG::ProgressionTracker *v10; // rax
  UFG::qSymbol result; // [rsp+30h] [rbp+8h] BYREF

  if ( pScope->i_update_count )
    return (unsigned int)UFG::FlowController::GetCurrentState(&UFG::gFlowController) != uidGameStateChangeLocation_10;
  i_array_p = pScope->i_data.i_array_p;
  v2 = i_array_p[1]->i_data_p->i_user_data != 0;
  v3 = i_array_p[2]->i_data_p->i_user_data != 0;
  p_i_user_data = (const char ***)&(*i_array_p)->i_data_p->i_user_data;
  if ( (*i_array_p)->i_data_p == (SSInstance *)-32i64 || !*((_DWORD *)*p_i_user_data + 2) )
    return 1;
  v5 = UFG::qSymbol::create_from_string(&result, **p_i_user_data);
  v6 = UFG::ProgressionTracker::Instance();
  SceneSettings = UFG::ProgressionTracker::FindSceneSettings(v6, v5);
  v8 = (UFG::SceneSettings *)SceneSettings;
  if ( !SceneSettings )
    return 1;
  BYTE5(SceneSettings->mNULL.mChild[1]) = v2;
  BYTE6(SceneSettings->mNULL.mChild[1]) = v3;
  v10 = UFG::ProgressionTracker::Instance();
  UFG::ProgressionTracker::ApplySceneSettings(v10, v8);
  return 0;
}

// File Line: 2178
// RVA: 0x4DAA90
bool __fastcall UFG::TSWorld::Coro_find_random_sidewalk_position(SSInvokedCoroutine *pScope)
{
  SSData **i_array_p; // r10
  bool result; // al
  SSData **v4; // rdx
  SSInstance *i_data_p; // rcx
  float v6; // xmm0_4
  float v7; // xmm0_4

  i_array_p = pScope->i_data.i_array_p;
  if ( UFG::SimObjectUtility::FindRandomSidewalkPosition(
         (UFG::qVector3 *)(*i_array_p)->i_data_p->i_user_data,
         *(float *)&i_array_p[1]->i_data_p->i_user_data,
         *(float *)&i_array_p[2]->i_data_p->i_user_data,
         i_array_p[3]->i_data_p->i_user_data != 0,
         (UFG::qVector3 *)i_array_p[6]->i_data_p->i_user_data) )
  {
    *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 5) + 8i64) + 32i64) = 1i64;
    return 1;
  }
  else
  {
    v4 = pScope->i_data.i_array_p;
    i_data_p = v4[4]->i_data_p;
    v6 = *(float *)&i_data_p->i_user_data;
    if ( v6 <= 0.0 )
      return 0;
    v7 = v6 - UFG::Metrics::msInstance.mSimTimeDelta;
    *(float *)&i_data_p->i_user_data = v7;
    if ( v7 > 0.0 )
    {
      return 0;
    }
    else
    {
      result = 1;
      v4[5]->i_data_p->i_user_data = 0i64;
    }
  }
  return result;
}

// File Line: 2216
// RVA: 0x4DB830
char __fastcall UFG::TSWorld::Coro_is_position_on_navmesh(SSInvokedCoroutine *pScope)
{
  SSData **i_array_p; // rdx
  unsigned int *i_user_data; // r8
  bool v5; // zf
  __m128 v6; // xmm2
  __m128 v7; // xmm3
  bool v8; // di
  unsigned int ClosestMeshPosition2d; // eax
  bool v10; // cl
  __m128 v11; // xmm1
  hkVector4f hkvClosestPointOut; // [rsp+30h] [rbp-48h] BYREF
  hkVector4f hkvPosition; // [rsp+40h] [rbp-38h] BYREF
  hkVector4f normalOut; // [rsp+50h] [rbp-28h] BYREF
  unsigned int meshUidOut; // [rsp+80h] [rbp+8h] BYREF

  if ( pScope->i_update_count < 0xA )
    return 0;
  i_array_p = pScope->i_data.i_array_p;
  i_user_data = (unsigned int *)(*i_array_p)->i_data_p->i_user_data;
  v5 = i_array_p[1]->i_data_p->i_user_data == 0;
  v6 = _mm_unpacklo_ps((__m128)i_user_data[1], (__m128)0i64);
  v7 = _mm_unpacklo_ps((__m128)*i_user_data, (__m128)i_user_data[2]);
  hkvClosestPointOut.m_quad = 0i64;
  v8 = !v5;
  hkvPosition.m_quad = _mm_unpacklo_ps(v7, v6);
  ClosestMeshPosition2d = UFG::HavokAIUtilGame::FindClosestMeshPosition2d(
                            &hkvPosition,
                            COERCE_DOUBLE((unsigned __int64)LODWORD(FLOAT_0_2)),
                            COERCE_DOUBLE((unsigned __int64)LODWORD(FLOAT_0_60000002)),
                            &hkvClosestPointOut,
                            &meshUidOut);
  v10 = ClosestMeshPosition2d != -1;
  if ( ClosestMeshPosition2d != -1 && !v8 )
  {
    UFG::HavokAIUtilGame::getFaceNormal(ClosestMeshPosition2d, &normalOut);
    v11 = _mm_mul_ps(_xmm, normalOut.m_quad);
    v10 = (float)((float)(_mm_shuffle_ps(v11, v11, 85).m128_f32[0] + _mm_shuffle_ps(v11, v11, 0).m128_f32[0])
                + _mm_shuffle_ps(v11, v11, 170).m128_f32[0]) > cosf(0.34906587);
  }
  *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 2) + 8i64) + 32i64) = v10;
  return 1;
}

// File Line: 2253
// RVA: 0x4E8970
void __fastcall UFG::TSWorld::MthdC_get_stimulus_radius(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  __int64 v3; // rax

  if ( ppResult )
  {
    v3 = 9i64
       * (int)UFG::StimulusManager::GetStimulusType(*(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, dword_1423BF9C0[2 * v3]);
  }
}

// File Line: 2267
// RVA: 0x4E40D0
void __fastcall UFG::TSWorld::MthdC_begin_stimulus_one_off_internal(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx
  unsigned __int64 i_user_data; // rbx
  UFG::eStimulusType StimulusType; // eax
  UFG::SimObject *v5; // r9
  UFG::StimulusParameters stimulus_parameters; // [rsp+20h] [rbp-28h] BYREF

  i_array_p = pScope->i_data.i_array_p;
  i_user_data = (*i_array_p)->i_data_p->i_user_data;
  if ( i_user_data )
  {
    if ( i_array_p[1]->i_data_p != (SSInstance *)-32i64 )
    {
      StimulusType = (unsigned int)UFG::StimulusManager::GetStimulusType(*(const char **)i_array_p[1]->i_data_p->i_user_data);
      v5 = *(UFG::SimObject **)(i_user_data + 40);
      stimulus_parameters.m_StimulusProducerOffset = UFG::qVector3::msZero;
      stimulus_parameters.m_MaxStimulusDuration = -1.0;
      stimulus_parameters.m_EmitUntilSpeedLessThan = -1.0;
      stimulus_parameters.m_StimulusEmissionType = eSTIMULUS_EMISSION_ONE_OFF;
      UFG::StimulusManager::BeginStimulus(UFG::StimulusManager::s_pInstance, StimulusType, &stimulus_parameters, v5);
    }
  }
}

// File Line: 2287
// RVA: 0x4E3F70
void __fastcall UFG::TSWorld::MthdC_begin_stimulus_duration_internal(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx
  unsigned __int64 i_user_data; // rdi
  SSData *v4; // rax
  float *p_i_user_data; // rbx
  UFG::eStimulusType StimulusType; // eax
  UFG::SimObject *v7; // r9
  UFG::StimulusParameters stimulus_parameters; // [rsp+20h] [rbp-28h] BYREF

  i_array_p = pScope->i_data.i_array_p;
  i_user_data = (*i_array_p)->i_data_p->i_user_data;
  v4 = i_array_p[2];
  p_i_user_data = (float *)&v4->i_data_p->i_user_data;
  if ( i_user_data && i_array_p[1]->i_data_p != (SSInstance *)-32i64 && v4->i_data_p != (SSInstance *)-32i64 )
  {
    StimulusType = (unsigned int)UFG::StimulusManager::GetStimulusType(*(const char **)i_array_p[1]->i_data_p->i_user_data);
    v7 = *(UFG::SimObject **)(i_user_data + 40);
    stimulus_parameters.m_StimulusProducerOffset = UFG::qVector3::msZero;
    stimulus_parameters.m_StimulusEmissionType = eSTIMULUS_EMISSION_CONTINUOUS;
    stimulus_parameters.m_MaxStimulusDuration = *p_i_user_data;
    stimulus_parameters.m_EmitUntilSpeedLessThan = FLOAT_N1_0;
    UFG::StimulusManager::BeginStimulus(UFG::StimulusManager::s_pInstance, StimulusType, &stimulus_parameters, v7);
  }
}

// File Line: 2308
// RVA: 0x4E4030
void __fastcall UFG::TSWorld::MthdC_begin_stimulus_internal(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx
  unsigned __int64 i_user_data; // rbx
  UFG::eStimulusType StimulusType; // eax
  UFG::SimObject *v5; // r9
  UFG::StimulusParameters stimulus_parameters; // [rsp+20h] [rbp-28h] BYREF

  i_array_p = pScope->i_data.i_array_p;
  i_user_data = (*i_array_p)->i_data_p->i_user_data;
  if ( i_user_data )
  {
    if ( i_array_p[1]->i_data_p != (SSInstance *)-32i64 )
    {
      StimulusType = (unsigned int)UFG::StimulusManager::GetStimulusType(*(const char **)i_array_p[1]->i_data_p->i_user_data);
      v5 = *(UFG::SimObject **)(i_user_data + 40);
      stimulus_parameters.m_StimulusProducerOffset = UFG::qVector3::msZero;
      stimulus_parameters.m_MaxStimulusDuration = -1.0;
      stimulus_parameters.m_EmitUntilSpeedLessThan = -1.0;
      stimulus_parameters.m_StimulusEmissionType = eSTIMULUS_EMISSION_CONTINUOUS;
      UFG::StimulusManager::BeginStimulus(UFG::StimulusManager::s_pInstance, StimulusType, &stimulus_parameters, v5);
    }
  }
}

// File Line: 2327
// RVA: 0x4E5630
void __fastcall UFG::TSWorld::MthdC_end_stimulus_internal(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx
  unsigned __int64 i_user_data; // rbx
  UFG::eStimulusType StimulusType; // eax

  i_array_p = pScope->i_data.i_array_p;
  i_user_data = (*i_array_p)->i_data_p->i_user_data;
  if ( i_user_data )
  {
    if ( i_array_p[1]->i_data_p != (SSInstance *)-32i64 )
    {
      StimulusType = (unsigned int)UFG::StimulusManager::GetStimulusType(*(const char **)i_array_p[1]->i_data_p->i_user_data);
      UFG::StimulusManager::EndStimulus(
        UFG::StimulusManager::s_pInstance,
        StimulusType,
        *(UFG::SimObject **)(i_user_data + 40));
    }
  }
}

// File Line: 2342
// RVA: 0x4E5320
void __fastcall UFG::TSWorld::MthdC_enable_spawning_parked_cars(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::WheeledVehicleManager::EnableParkedCarSpawning(
    UFG::WheeledVehicleManager::m_Instance,
    (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0);
}

// File Line: 2358
// RVA: 0x4DDE90
char __fastcall UFG::TSWorld::Coro_spawn_object_at_xform(SSInvokedCoroutine *pScope)
{
  SSInstance *i_data_p; // rbx
  UFG::qPropertySet *spawn_info; // rsi
  UFG::ObjectResourceManager *v4; // rax
  UFG::ObjectResourceManager *v5; // rax
  UFG::TransformNodeComponent *v6; // rbx
  UFG::SimObject *v7; // rbx
  UFG::ObjectResourceManager *v8; // rax
  SSInstance *v9; // rax
  __int64 v10; // rbx
  SSInstance *v11; // rsi
  _DWORD *v12; // rcx
  bool v13; // zf
  SSInstance *v15; // rbp
  __int64 v16; // rbx
  _DWORD *v17; // rcx
  UFG::ObjectResourceManager *v18; // rax
  UFG::qSymbol pSpawnName; // [rsp+50h] [rbp+8h] BYREF
  UFG::SceneLayer *ppLayer; // [rsp+58h] [rbp+10h] BYREF

  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  pSpawnName.mUID = -1;
  spawn_info = UFG::TSWorld::get_spawn_info(pScope, 2u, &pSpawnName, &ppLayer);
  if ( pScope->i_update_count )
  {
    *(float *)&i_data_p->i_user_data = *(float *)&i_data_p->i_user_data - UFG::Metrics::msInstance.mSimTimeDelta;
  }
  else
  {
    v4 = UFG::ObjectResourceManager::Instance();
    UFG::ObjectResourceManager::PreLoadCriticalResource(v4, spawn_info);
  }
  v5 = UFG::ObjectResourceManager::Instance();
  if ( UFG::ObjectResourceManager::IsLoaded(v5, spawn_info) )
  {
    v6 = *(UFG::TransformNodeComponent **)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64);
    UFG::TransformNodeComponent::UpdateWorldTransform(v6);
    v7 = UFG::SpawnInfoInterface::SpawnObject(
           &pSpawnName,
           spawn_info,
           &v6->mWorldTransform,
           UnReferenced,
           ppLayer,
           0i64);
    v8 = UFG::ObjectResourceManager::Instance();
    UFG::ObjectResourceManager::ReleaseCriticalResource(v8, spawn_info);
    v9 = SSInstance::pool_new(UFG::TSSimObject::mspSimObjectClass, (unsigned __int64)v7);
    v10 = *((_QWORD *)pScope->i_data.i_array_p + 5);
    v11 = v9;
    v12 = *(_DWORD **)(v10 + 8);
    v13 = v12[4]-- == 1;
    if ( v13 )
    {
      v12[4] = 0x80000000;
      (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v12 + 112i64))(v12);
    }
    *(_QWORD *)(v10 + 8) = v11;
    return 1;
  }
  else if ( *(float *)&i_data_p->i_user_data > 0.0 )
  {
    return 0;
  }
  else
  {
    v15 = SSBrain::c_nil_p;
    v16 = *((_QWORD *)pScope->i_data.i_array_p + 5);
    v17 = *(_DWORD **)(v16 + 8);
    v13 = v17[4]-- == 1;
    if ( v13 )
    {
      v17[4] = 0x80000000;
      (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v17 + 112i64))(v17);
    }
    *(_QWORD *)(v16 + 8) = v15;
    v18 = UFG::ObjectResourceManager::Instance();
    UFG::ObjectResourceManager::ReleaseCriticalResource(v18, spawn_info);
    return 1;
  }
}

// File Line: 2432
// RVA: 0x4E4170
// attributes: thunk
void __fastcall UFG::TSWorld::MthdC_bind_enums(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSWorld::BindPhysicsObjectPropertiesToEnum();
}

// File Line: 2444
// RVA: 0x4E3380
// attributes: thunk
void __fastcall UFG::TSWorld::MthdC_all_ai_update_attack_targets_now(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::AllAIUpdateAttackTargetsNow((UFG *)pScope);
}

// File Line: 2451
// RVA: 0x4E4B20
void __fastcall UFG::TSWorld::MthdC_disable_bullet_impacts(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::qBaseNodeRB *ArgByNameOrInstance; // rax

  ArgByNameOrInstance = UFG::TSSimObject::GetArgByNameOrInstance(pScope, 0);
  if ( ArgByNameOrInstance )
    UFG::BulletManager::DisableBulletImpacts(UFG::BulletManager::mInstance, (UFG::SimObject *)ArgByNameOrInstance);
}

// File Line: 2463
// RVA: 0x4E4CC0
void __fastcall UFG::TSWorld::MthdC_enable_bullet_impacts(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::qBaseNodeRB *ArgByNameOrInstance; // rax

  ArgByNameOrInstance = UFG::TSSimObject::GetArgByNameOrInstance(pScope, 0);
  if ( ArgByNameOrInstance )
    UFG::BulletManager::EnableBulletImpacts(UFG::BulletManager::mInstance, (UFG::SimObject *)ArgByNameOrInstance);
}

// File Line: 2482
// RVA: 0x4D95F0
void UFG::TSWorld::BindPhysicsObjectPropertiesToEnum(void)
{
  SSClass *v0; // rax
  SSClass *v1; // rbp
  unsigned int *v2; // rcx
  __int64 i_count; // rax
  unsigned int **i_array_p; // r8
  unsigned int **v5; // r10
  unsigned int **v6; // rdx
  unsigned int v7; // r9d
  unsigned int *v8; // rbx
  SSInstance *v9; // rdi
  bool v10; // zf
  const char *TypeName; // rax
  unsigned __int64 v12; // rbx
  UFG::qReflectWarehouse *v13; // rax
  UFG::qTree64<UFG::qReflectObject,UFG::qReflectObject,0> *p_mItems; // r14
  UFG::qTree64Base *Head; // rax
  __int64 *p_mCount; // rsi
  __int64 v17; // rax
  SSTypedData **v18; // rdx
  SSTypedData **v19; // r9
  unsigned int v20; // r10d
  SSTypedData **v21; // rax
  unsigned int i_uid; // r8d
  SSTypedData *v23; // rbx
  char *Name; // rax
  unsigned int v25; // eax
  SSInstance *v26; // rdi
  SSInstance *i_data_p; // rcx
  UFG::qTree64Base *Next; // rax
  AStringRef *i_str_ref_p; // rbx
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v33; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx
  char buffer_p[256]; // [rsp+40h] [rbp-118h] BYREF
  AString v36; // [rsp+160h] [rbp+8h] BYREF

  v0 = SSBrain::get_class("ObjectPropertyType");
  v1 = v0->vfptr->get_key_class(v0);
  AString::AString(&v36, buffer_p, 0x100u, 0, 0);
  v2 = (unsigned int *)_S15_2;
  if ( (_S15_2 & 1) == 0 )
  {
    _S15_2 |= 1u;
    UFG::qSymbol::create_from_string(&enumInvalid, "invalid");
    atexit(UFG::TSWorld::BindPhysicsObjectPropertiesToEnum_::_2_::_dynamic_atexit_destructor_for__enumInvalid__);
  }
  i_count = v1->i_class_data.i_count;
  if ( (_DWORD)i_count )
  {
    i_array_p = (unsigned int **)v1->i_class_data.i_array_p;
    v5 = &i_array_p[i_count - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        v6 = &i_array_p[((char *)v5 - (char *)i_array_p) >> 4];
        v2 = *v6;
        v7 = **v6;
        if ( enumInvalid.mUID >= v7 )
          break;
        if ( i_array_p == v6 )
          goto LABEL_15;
        v5 = v6 - 1;
      }
      v2 = (unsigned int *)(enumInvalid.mUID == v7);
      if ( enumInvalid.mUID == v7 )
        break;
      if ( v5 == v6 )
        goto LABEL_15;
      i_array_p = v6 + 1;
    }
    v8 = *v6;
    if ( *v6 )
    {
      v9 = SSInstance::pool_new(v1, 0xFFFFFFFFui64);
      ++v9->i_ref_count;
      v2 = (unsigned int *)*((_QWORD *)v8 + 2);
      v10 = v2[4]-- == 1;
      if ( v10 )
      {
        v2[4] = 0x80000000;
        (*(void (__fastcall **)(unsigned int *))(*(_QWORD *)v2 + 112i64))(v2);
      }
      *((_QWORD *)v8 + 2) = v9;
    }
  }
LABEL_15:
  TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName((UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *)v2);
  v12 = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
  v13 = UFG::qReflectWarehouse::Instance();
  p_mItems = &UFG::qReflectWarehouse::GetInventory(v13, v12)->mItems;
  Head = UFG::qTree64Base::GetHead(&p_mItems->mTree);
  if ( Head )
  {
    p_mCount = &Head[-1].mCount;
    if ( Head != (UFG::qTree64Base *)8 )
    {
      do
      {
        v17 = v1->i_class_data.i_count;
        if ( (_DWORD)v17 )
        {
          v18 = v1->i_class_data.i_array_p;
          v19 = &v18[v17 - 1];
          v20 = *((_DWORD *)p_mCount + 84);
          while ( 1 )
          {
            while ( 1 )
            {
              v21 = &v18[((char *)v19 - (char *)v18) >> 4];
              i_uid = (*v21)->i_name.i_uid;
              if ( v20 >= i_uid )
                break;
              if ( v18 == v21 )
                goto LABEL_29;
              v19 = v21 - 1;
            }
            if ( v20 == i_uid )
              break;
            if ( v19 == v21 )
              goto LABEL_29;
            v18 = v21 + 1;
          }
          v23 = *v21;
          if ( *v21 )
          {
            Name = UFG::qReflectObject::GetName((UFG::qReflectObject *)p_mCount);
            v25 = UFG::qStringHashUpper32(Name, -1);
            v26 = SSInstance::pool_new(v1, v25);
            ++v26->i_ref_count;
            i_data_p = v23->i_data_p;
            v10 = i_data_p->i_ref_count-- == 1;
            if ( v10 )
            {
              i_data_p->i_ref_count = 0x80000000;
              i_data_p->vfptr[1].get_scope_context(i_data_p);
            }
            v23->i_data_p = v26;
          }
        }
LABEL_29:
        Next = UFG::qTree64Base::GetNext(&p_mItems->mTree, (UFG::qTree64Base::BaseNode *)(p_mCount + 1));
        if ( !Next )
          break;
        p_mCount = &Next[-1].mCount;
      }
      while ( Next != (UFG::qTree64Base *)8 );
    }
  }
  i_str_ref_p = v36.i_str_ref_p;
  v10 = v36.i_str_ref_p->i_ref_count-- == 1;
  if ( v10 )
  {
    if ( i_str_ref_p->i_deallocate )
      AMemory::c_free_func(i_str_ref_p->i_cstr_p);
    pool = AStringRef::get_pool();
    i_block_p = pool->i_block_p;
    i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
    if ( (unsigned __int64)i_str_ref_p < i_objects_a
      || (v33 = (unsigned __int64)i_str_ref_p < i_objects_a + 24i64 * i_block_p->i_size,
          p_i_exp_pool = &pool->i_pool,
          !v33) )
    {
      p_i_exp_pool = &pool->i_exp_pool;
    }
    APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, i_str_ref_p);
  }
}

// File Line: 2535
// RVA: 0x4EF4E0
void __fastcall UFG::TSWorld::MthdC_set_volumetric_fog_intensity(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  unk_142163804 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
}

// File Line: 2548
// RVA: 0x4D8560
void UFG::TSWorld::BindAtomics(void)
{
  UFG *v0; // rcx
  ASymbol rebind; // [rsp+20h] [rbp-18h]
  ASymbol rebinda; // [rsp+20h] [rbp-18h]
  ASymbol rebindb; // [rsp+20h] [rbp-18h]
  ASymbol rebindc; // [rsp+20h] [rbp-18h]
  ASymbol rebindd; // [rsp+20h] [rbp-18h]
  ASymbol rebinde; // [rsp+20h] [rbp-18h]
  ASymbol rebindf; // [rsp+20h] [rbp-18h]
  ASymbol rebindg; // [rsp+20h] [rbp-18h]
  ASymbol rebindh; // [rsp+20h] [rbp-18h]
  ASymbol rebindi; // [rsp+20h] [rbp-18h]
  ASymbol rebindj; // [rsp+20h] [rbp-18h]
  ASymbol rebindk; // [rsp+20h] [rbp-18h]
  ASymbol rebindl; // [rsp+20h] [rbp-18h]
  ASymbol rebindm; // [rsp+20h] [rbp-18h]
  ASymbol rebindn; // [rsp+20h] [rbp-18h]
  ASymbol rebindo; // [rsp+20h] [rbp-18h]
  ASymbol rebindp; // [rsp+20h] [rbp-18h]
  ASymbol rebindq; // [rsp+20h] [rbp-18h]
  ASymbol rebindr; // [rsp+20h] [rbp-18h]
  ASymbol rebinds; // [rsp+20h] [rbp-18h]
  ASymbol rebindt; // [rsp+20h] [rbp-18h]
  ASymbol rebindu; // [rsp+20h] [rbp-18h]
  ASymbol rebindv; // [rsp+20h] [rbp-18h]
  ASymbol rebindw; // [rsp+20h] [rbp-18h]
  ASymbol rebindx; // [rsp+20h] [rbp-18h]
  ASymbol rebindy; // [rsp+20h] [rbp-18h]
  ASymbol rebindz; // [rsp+20h] [rbp-18h]
  ASymbol rebindba; // [rsp+20h] [rbp-18h]
  ASymbol rebindbb; // [rsp+20h] [rbp-18h]
  ASymbol rebindbc; // [rsp+20h] [rbp-18h]
  ASymbol rebindbd; // [rsp+20h] [rbp-18h]
  ASymbol rebindbe; // [rsp+20h] [rbp-18h]
  ASymbol rebindbf; // [rsp+20h] [rbp-18h]
  ASymbol rebindbg; // [rsp+20h] [rbp-18h]
  ASymbol rebindbh; // [rsp+20h] [rbp-18h]
  ASymbol rebindbi; // [rsp+20h] [rbp-18h]
  ASymbol rebindbj; // [rsp+20h] [rbp-18h]
  ASymbol rebindbk; // [rsp+20h] [rbp-18h]
  ASymbol rebindbl; // [rsp+20h] [rbp-18h]
  ASymbol rebindbm; // [rsp+20h] [rbp-18h]
  ASymbol rebindbn; // [rsp+20h] [rbp-18h]
  ASymbol rebindbo; // [rsp+20h] [rbp-18h]
  ASymbol rebindbp; // [rsp+20h] [rbp-18h]
  ASymbol rebindbq; // [rsp+20h] [rbp-18h]
  ASymbol rebindbr; // [rsp+20h] [rbp-18h]
  ASymbol rebindbs; // [rsp+20h] [rbp-18h]
  ASymbol rebindbt; // [rsp+20h] [rbp-18h]
  ASymbol rebindbu; // [rsp+20h] [rbp-18h]
  ASymbol rebindbv; // [rsp+20h] [rbp-18h]
  ASymbol rebindbw; // [rsp+20h] [rbp-18h]
  ASymbol rebindbx; // [rsp+20h] [rbp-18h]
  ASymbol rebindby; // [rsp+20h] [rbp-18h]
  ASymbol rebindbz; // [rsp+20h] [rbp-18h]
  ASymbol rebindca; // [rsp+20h] [rbp-18h]
  ASymbol rebindcb; // [rsp+20h] [rbp-18h]
  ASymbol rebindcc; // [rsp+20h] [rbp-18h]
  ASymbol rebindcd; // [rsp+20h] [rbp-18h]
  ASymbol rebindce; // [rsp+20h] [rbp-18h]
  ASymbol rebindcf; // [rsp+20h] [rbp-18h]
  ASymbol rebindcg; // [rsp+20h] [rbp-18h]
  ASymbol rebindch; // [rsp+20h] [rbp-18h]
  ASymbol rebindci; // [rsp+20h] [rbp-18h]
  ASymbol rebindcj; // [rsp+20h] [rbp-18h]
  ASymbol rebindck; // [rsp+20h] [rbp-18h]
  ASymbol rebindcl; // [rsp+20h] [rbp-18h]
  ASymbol rebindcm; // [rsp+20h] [rbp-18h]
  ASymbol rebindcn; // [rsp+20h] [rbp-18h]
  ASymbol rebindco; // [rsp+20h] [rbp-18h]
  ASymbol rebindcp; // [rsp+20h] [rbp-18h]
  ASymbol rebindcq; // [rsp+20h] [rbp-18h]
  ASymbol rebindcr; // [rsp+20h] [rbp-18h]
  ASymbol rebindcs; // [rsp+20h] [rbp-18h]
  ASymbol rebindct; // [rsp+20h] [rbp-18h]
  ASymbol rebindcu; // [rsp+20h] [rbp-18h]
  ASymbol rebindcv; // [rsp+20h] [rbp-18h]
  ASymbol rebindcw; // [rsp+20h] [rbp-18h]
  ASymbol rebindcx; // [rsp+20h] [rbp-18h]
  ASymbol rebindcy; // [rsp+20h] [rbp-18h]
  ASymbol rebindcz; // [rsp+20h] [rbp-18h]
  ASymbol rebindda; // [rsp+20h] [rbp-18h]
  ASymbol rebinddb; // [rsp+20h] [rbp-18h]
  ASymbol rebinddc; // [rsp+20h] [rbp-18h]
  ASymbol rebinddd; // [rsp+20h] [rbp-18h]
  ASymbol rebindde; // [rsp+20h] [rbp-18h]
  ASymbol rebinddf; // [rsp+20h] [rbp-18h]
  ASymbol rebinddg; // [rsp+20h] [rbp-18h]
  ASymbol rebinddh; // [rsp+20h] [rbp-18h]
  ASymbol rebinddi; // [rsp+20h] [rbp-18h]
  ASymbol rebinddj; // [rsp+20h] [rbp-18h]
  ASymbol rebinddk; // [rsp+20h] [rbp-18h]
  ASymbol rebinddl; // [rsp+20h] [rbp-18h]
  ASymbol rebinddm; // [rsp+20h] [rbp-18h]
  ASymbol rebinddn; // [rsp+20h] [rbp-18h]
  ASymbol rebinddo; // [rsp+20h] [rbp-18h]
  ASymbol rebinddp; // [rsp+20h] [rbp-18h]
  ASymbol rebinddq; // [rsp+20h] [rbp-18h]
  ASymbol rebinddr; // [rsp+20h] [rbp-18h]
  ASymbol rebindds; // [rsp+20h] [rbp-18h]
  ASymbol rebinddt; // [rsp+20h] [rbp-18h]
  ASymbol rebinddu; // [rsp+20h] [rbp-18h]
  ASymbol rebinddv; // [rsp+20h] [rbp-18h]
  ASymbol rebinddw; // [rsp+20h] [rbp-18h]
  ASymbol rebinddx; // [rsp+20h] [rbp-18h]
  ASymbol rebinddy; // [rsp+20h] [rbp-18h]
  ASymbol rebinddz; // [rsp+20h] [rbp-18h]
  ASymbol rebindea; // [rsp+20h] [rbp-18h]
  ASymbol rebindeb; // [rsp+20h] [rbp-18h]
  ASymbol rebindec; // [rsp+20h] [rbp-18h]
  ASymbol rebinded; // [rsp+20h] [rbp-18h]
  ASymbol rebindee; // [rsp+20h] [rbp-18h]
  ASymbol rebindef; // [rsp+20h] [rbp-18h]
  ASymbol rebindeg; // [rsp+20h] [rbp-18h]

  LOBYTE(rebind.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "save",
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))UFG::CustomizeBindings::CustomizeComplete,
    1,
    rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "vendor_extortion_hack",
    UFG::TSWorld::MthdC_vendor_extortion_hack,
    1,
    rebinda);
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "enable_spawning_parked_cars",
    UFG::TSWorld::MthdC_enable_spawning_parked_cars,
    1,
    rebindb);
  LOBYTE(rebindc.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "get_location_name",
    UFG::TSWorld::MthdC_get_location_name,
    1,
    rebindc);
  LOBYTE(rebindd.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "get_local_player",
    UFG::TSWorld::MthdC_get_local_player,
    1,
    rebindd);
  LOBYTE(rebinde.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "set_max_traffic_cars",
    UFG::TSWorld::MthdC_set_max_traffic_cars,
    1,
    rebinde);
  LOBYTE(rebindf.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "set_max_parked_cars",
    UFG::TSWorld::MthdC_set_max_parked_cars,
    1,
    rebindf);
  LOBYTE(rebindg.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "add_road_block",
    UFG::TSWorld::MthdC_add_road_block,
    1,
    rebindg);
  LOBYTE(rebindh.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "remove_road_block",
    UFG::TSWorld::MthdC_remove_road_block,
    1,
    rebindh);
  LOBYTE(rebindi.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "is_simobject_existent",
    UFG::TSWorld::MthdC_is_simobject_existent,
    1,
    rebindi);
  LOBYTE(rebindj.i_uid) = 0;
  SSClass::register_method_func(SSBrain::c_world_class_p, "join_group", UFG::TSWorld::MthdC_join_group, 1, rebindj);
  LOBYTE(rebindk.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "enable_LOD_suppression",
    UFG::TSWorld::MthdC_enable_LOD_suppression,
    1,
    rebindk);
  LOBYTE(rebindl.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "enable_vehicles_blip",
    UFG::TSWorld::MthdC_enable_vehicles_blip,
    1,
    rebindl);
  LOBYTE(rebindm.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "set_hi_def_spawning",
    UFG::TSWorld::MthdC_set_hi_def_spawning,
    1,
    rebindm);
  LOBYTE(rebindn.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "facial_animation_disable",
    UFG::TSWorld::MthdC_facial_animation_disable,
    1,
    rebindn);
  LOBYTE(rebindo.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "debug_cam_fov",
    UFG::TSWorld::MthdC_debug_cam_fov,
    1,
    rebindo);
  LOBYTE(rebindp.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "render_enable_exterior",
    UFG::TSWorld::MthdC_render_enable_exterior,
    1,
    rebindp);
  LOBYTE(rebindq.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "render_parkour_handles",
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))_,
    1,
    rebindq);
  SSClass::register_coroutine_func(
    SSBrain::c_world_class_p,
    "_apply_scene_settings",
    UFG::TSWorld::Coro_apply_scene_settings,
    SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    SSBrain::c_world_class_p,
    "_apply_scene_settings_at_position",
    UFG::TSWorld::Coro_apply_scene_settings_at_position,
    SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    SSBrain::c_world_class_p,
    "_render_override_environment",
    UFG::TSWorld::Coro_render_override_environment,
    SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    SSBrain::c_world_class_p,
    "_render_override_environment_named",
    UFG::TSWorld::Coro_render_override_environment,
    SSBindFlag_instance_no_rebind);
  LOBYTE(rebindr.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "capture_probes",
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))_,
    1,
    rebindr);
  LOBYTE(rebinds.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "enable_decals",
    UFG::TSWorld::MthdC_enable_decals,
    1,
    rebinds);
  LOBYTE(rebindt.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "enable_halfsize_aa",
    UFG::TSWorld::MthdC_enable_halfsize_aa,
    1,
    rebindt);
  LOBYTE(rebindu.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "render_enable_water",
    UFG::TSWorld::MthdC_render_enable_water,
    1,
    rebindu);
  LOBYTE(rebindv.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "section_is_3d",
    UFG::TSWorld::MthdC_section_is_3d,
    1,
    rebindv);
  LOBYTE(rebindw.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "section_get_name",
    UFG::TSWorld::MthdC_section_get_name,
    1,
    rebindw);
  LOBYTE(rebindx.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "last_used_vehicle_is_within_range",
    UFG::TSWorld::MthdC_last_used_vehicle_is_within_range,
    1,
    rebindx);
  LOBYTE(rebindy.i_uid) = 0;
  SSClass::register_method_func(SSBrain::c_world_class_p, "time_get", UFG::TSWorld::MthdC_time_get, 1, rebindy);
  LOBYTE(rebindz.i_uid) = 0;
  SSClass::register_method_func(SSBrain::c_world_class_p, "time_set", UFG::TSWorld::MthdC_time_set, 1, rebindz);
  LOBYTE(rebindba.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "time_get_scale",
    UFG::TSWorld::MthdC_time_get_scale,
    1,
    rebindba);
  LOBYTE(rebindbb.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "time_set_scale",
    UFG::TSWorld::MthdC_time_set_scale,
    1,
    rebindbb);
  LOBYTE(rebindbc.i_uid) = 0;
  SSClass::register_method_func(SSBrain::c_world_class_p, "time_is_day", UFG::TSWorld::MthdC_time_is_day, 1, rebindbc);
  LOBYTE(rebindbd.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "enable_near_layer_transitions",
    UFG::TSWorld::MthdC_enable_near_layer_transitions,
    1,
    rebindbd);
  LOBYTE(rebindbe.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "load_cloud_scene",
    UFG::TSWorld::MthdC_load_cloud_scene,
    1,
    rebindbe);
  LOBYTE(rebindbf.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "unload_cloud_scene",
    UFG::TSWorld::MthdC_unload_cloud_scene,
    1,
    rebindbf);
  LOBYTE(rebindbg.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "weather_is_raining",
    UFG::TSWorld::MthdC_weather_is_raining,
    1,
    rebindbg);
  LOBYTE(rebindbh.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "weather_get_amount",
    UFG::TSWorld::MthdC_weather_get_amount,
    1,
    rebindbh);
  LOBYTE(rebindbi.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "weather_set_amount",
    UFG::TSWorld::MthdC_weather_set_amount,
    1,
    rebindbi);
  LOBYTE(rebindbj.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "weather_target",
    UFG::TSWorld::MthdC_weather_target,
    1,
    rebindbj);
  LOBYTE(rebindbk.i_uid) = 0;
  SSClass::register_method_func(SSBrain::c_world_class_p, "weather_lock", UFG::TSWorld::MthdC_weather_lock, 1, rebindbk);
  LOBYTE(rebindbl.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "weather_rain_chance",
    UFG::TSWorld::MthdC_weather_rain_chance,
    1,
    rebindbl);
  LOBYTE(rebindbm.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "weather_randomize_interval",
    UFG::TSWorld::MthdC_weather_randomize_interval,
    1,
    rebindbm);
  LOBYTE(rebindbn.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "weather_wetness_override",
    UFG::TSWorld::MthdC_weather_wetness_override,
    1,
    rebindbn);
  LOBYTE(rebindbo.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "weather_set_wind",
    UFG::TSWorld::MthdC_weather_set_wind,
    1,
    rebindbo);
  LOBYTE(rebindbp.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "weather_render_inside",
    UFG::TSWorld::MthdC_weather_render_inside,
    1,
    rebindbp);
  LOBYTE(rebindbq.i_uid) = 0;
  SSClass::register_method_func(SSBrain::c_world_class_p, "set_skydome", UFG::TSWorld::MthdC_set_skydome, 1, rebindbq);
  LOBYTE(rebindbr.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "release_skydome",
    UFG::TSWorld::MthdC_release_skydome,
    1,
    rebindbr);
  LOBYTE(rebindbs.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "is_progression_subset_mode_active",
    UFG::TSWorld::MthdC_is_progression_subset_mode_active,
    1,
    rebindbs);
  LOBYTE(rebindbt.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "set_progression_subset_mode",
    UFG::TSWorld::MthdC_set_progression_subset_mode,
    1,
    rebindbt);
  LOBYTE(rebindbu.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "clear_progression_subset_mode",
    UFG::TSWorld::MthdC_clear_progression_subset_mode,
    1,
    rebindbu);
  LOBYTE(rebindbv.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "audio_music_play",
    UFG::TSWorld::MthdC_audio_set_music_state,
    1,
    rebindbv);
  LOBYTE(rebindbw.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "audio_set_music_state",
    UFG::TSWorld::MthdC_audio_set_music_state,
    1,
    rebindbw);
  LOBYTE(rebindbx.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "audio_music_event",
    UFG::TSWorld::MthdC_audio_music_event,
    1,
    rebindbx);
  LOBYTE(rebindby.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "audio_ambience_event",
    UFG::TSWorld::MthdC_audio_ambience_event,
    1,
    rebindby);
  LOBYTE(rebindbz.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "audio_ambience_rtpc",
    UFG::TSWorld::MthdC_audio_ambience_rtpc,
    1,
    rebindbz);
  LOBYTE(rebindca.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "audio_load_soundbank",
    UFG::TSWorld::MthdC_audio_load_soundbank,
    1,
    rebindca);
  LOBYTE(rebindcb.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "audio_unload_soundbank",
    UFG::TSWorld::MthdC_audio_unload_soundbank,
    1,
    rebindcb);
  SSClass::register_coroutine_func(
    SSBrain::c_world_class_p,
    "_audio_load_soundbank",
    UFG::TSWorld::Coro_audio_load_soundbank,
    SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    SSBrain::c_world_class_p,
    "_audio_wait_until_soundbank_loaded",
    UFG::TSWorld::Coro_audio_wait_until_soundbank_loaded,
    SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    SSBrain::c_world_class_p,
    "_wait_for_resources",
    UFG::TSWorld::Coro_wait_for_resources,
    SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    SSBrain::c_world_class_p,
    "_wait_until_in_game_state",
    UFG::TSWorld::Coro_wait_until_in_game_state,
    SSBindFlag_instance_no_rebind);
  LOBYTE(rebindcc.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "audio_enable_health_effects",
    UFG::TSWorld::MthdC_audio_enable_health_effects,
    1,
    rebindcc);
  LOBYTE(rebindcd.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "audio_is_music_playing",
    UFG::TSWorld::MthdC_audio_is_music_playing,
    1,
    rebindcd);
  LOBYTE(rebindce.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "audio_set_listener_at_camera",
    UFG::TSWorld::MthdC_audio_set_listener_at_camera,
    1,
    rebindce);
  LOBYTE(rebindcf.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "audio_set_listener_at_player",
    UFG::TSWorld::MthdC_audio_set_listener_at_player,
    1,
    rebindcf);
  LOBYTE(rebindcg.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "audio_set_trigger_point_at_camera",
    UFG::TSWorld::MthdC_audio_set_listener_at_camera,
    1,
    rebindcg);
  LOBYTE(rebindch.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "audio_set_trigger_point_at_player",
    UFG::TSWorld::MthdC_audio_set_listener_at_player,
    1,
    rebindch);
  LOBYTE(rebindci.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "audio_lock_listener_position",
    UFG::TSWorld::MthdC_audio_lock_listener_position,
    1,
    rebindci);
  LOBYTE(rebindcj.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "audio_unlock_listener_position",
    UFG::TSWorld::MthdC_audio_unlock_listener_position,
    1,
    rebindcj);
  LOBYTE(rebindck.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "audio_listener_enable_high_speed",
    UFG::TSWorld::MthdC_audio_listener_enable_high_speed,
    1,
    rebindck);
  LOBYTE(rebindcl.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "audio_listener_disable_high_speed",
    UFG::TSWorld::MthdC_audio_listener_disable_high_speed,
    1,
    rebindcl);
  LOBYTE(rebindcm.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "load_audio_resources_debug",
    UFG::TSWorld::MthdC_audio_load_resources_debug,
    1,
    rebindcm);
  LOBYTE(rebindcn.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "unload_audio_resources_debug",
    UFG::TSWorld::MthdC_audio_unload_resources_debug,
    1,
    rebindcn);
  LOBYTE(rebindco.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "audio_setup_two_person_conversation",
    UFG::TSWorld::MthdC_audio_setup_two_person_conversation,
    1,
    rebindco);
  LOBYTE(rebindcp.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "init_constants",
    UFG::TSWorld::MthdC_init_constants,
    1,
    rebindcp);
  LOBYTE(rebindcq.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "enable_navigation_logging",
    UFG::TSWorld::MthdC_enable_navigation_logging,
    1,
    rebindcq);
  LOBYTE(rebindcr.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "enable_script_debugging",
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))_,
    1,
    rebindcr);
  LOBYTE(rebindcs.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "delete_all_ambient_peds",
    UFG::TSWorld::MthdC_delete_all_ambient_peds,
    1,
    rebindcs);
  LOBYTE(rebindct.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "enable_all_ambient_peds",
    UFG::TSWorld::MthdC_enable_all_ambient_peds,
    1,
    rebindct);
  LOBYTE(rebindcu.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "dry_fire_near_spawn_zones",
    UFG::TSWorld::MthdC_dry_fire_near_spawn_zones,
    1,
    rebindcu);
  LOBYTE(rebindcv.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "spawn_zones_near_camera",
    UFG::TSWorld::MthdC_spawn_zones_near_camera,
    1,
    rebindcv);
  LOBYTE(rebindcw.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "disable_proxy_peds",
    UFG::TSWorld::MthdC_disable_proxy_peds,
    1,
    rebindcw);
  LOBYTE(rebindcx.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "enable_proxy_peds",
    UFG::TSWorld::MthdC_enable_proxy_peds,
    1,
    rebindcx);
  LOBYTE(rebindcy.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "rebalance_ambience",
    UFG::TSWorld::MthdC_rebalance_ambience,
    1,
    rebindcy);
  LOBYTE(rebindcz.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "set_layer_active",
    UFG::TSWorld::MthdC_set_layer_active,
    1,
    rebindcz);
  LOBYTE(rebindda.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "get_layer_count",
    UFG::TSWorld::MthdC_get_layer_count,
    1,
    rebindda);
  LOBYTE(rebinddb.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "get_layer_name",
    UFG::TSWorld::MthdC_get_layer_name,
    1,
    rebinddb);
  LOBYTE(rebinddc.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "delete_peds_from_deactivated_regions",
    UFG::TSWorld::MthdC_delete_peds_from_deactivated_regions,
    1,
    rebinddc);
  LOBYTE(rebinddd.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "clean_up_free_weapons",
    UFG::TSWorld::MthdC_clean_up_free_weapons,
    1,
    rebinddd);
  LOBYTE(rebindde.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "set_simulation_timescale",
    UFG::TSMetrics_MthdC_simtime_set_scale,
    1,
    rebindde);
  LOBYTE(rebinddf.i_uid) = 0;
  SSClass::register_method_func(SSBrain::c_world_class_p, "spawn_object", UFG::TSWorld::MthdC_spawn_object, 1, rebinddf);
  LOBYTE(rebinddg.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "spawn_object_at_xform",
    UFG::TSWorld::MthdC_spawn_object_at_xform,
    1,
    rebinddg);
  LOBYTE(rebinddh.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "disable_bullet_impacts",
    UFG::TSWorld::MthdC_disable_bullet_impacts,
    1,
    rebinddh);
  LOBYTE(rebinddi.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "enable_bullet_impacts",
    UFG::TSWorld::MthdC_enable_bullet_impacts,
    1,
    rebinddi);
  LOBYTE(rebinddj.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "get_stimulus_radius",
    UFG::TSWorld::MthdC_get_stimulus_radius,
    1,
    rebinddj);
  LOBYTE(rebinddk.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "begin_stimulus_one_off_internal",
    UFG::TSWorld::MthdC_begin_stimulus_one_off_internal,
    1,
    rebinddk);
  LOBYTE(rebinddl.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "begin_stimulus_duration_internal",
    UFG::TSWorld::MthdC_begin_stimulus_duration_internal,
    1,
    rebinddl);
  LOBYTE(rebinddm.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "begin_stimulus_internal",
    UFG::TSWorld::MthdC_begin_stimulus_internal,
    1,
    rebinddm);
  LOBYTE(rebinddn.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "end_stimulus_internal",
    UFG::TSWorld::MthdC_end_stimulus_internal,
    1,
    rebinddn);
  LOBYTE(rebinddo.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "enable_possessed_peds",
    UFG::TSWorld::MthdC_enable_possessed_peds,
    1,
    rebinddo);
  LOBYTE(rebinddp.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "is_possessed_peds_enabled",
    UFG::TSWorld::MthdC_is_possessed_peds_enabled,
    1,
    rebinddp);
  LOBYTE(rebinddq.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "enable_sidewalk_node",
    UFG::TSWorld::MthdC_enable_sidewalk_node,
    1,
    rebinddq);
  LOBYTE(rebinddr.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "get_closest_sidewalk_position",
    UFG::TSWorld::MthdC_get_closest_sidewalk_position,
    1,
    rebinddr);
  LOBYTE(rebindds.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "run_script_test",
    UFG::TSWorld::MthdC_run_script_test,
    1,
    rebindds);
  SSClass::register_coroutine_func(
    SSBrain::c_world_class_p,
    "_find_character_spawn_position",
    UFG::TSWorld::Coro_find_character_spawn_position,
    SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    SSBrain::c_world_class_p,
    "_find_vehicle_spawn_xform",
    UFG::TSWorld::Coro_find_vehicle_spawn_xform,
    SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    SSBrain::c_world_class_p,
    "_find_boat_spawn_xform",
    UFG::TSWorld::Coro_find_boat_spawn_xform,
    SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    SSBrain::c_world_class_p,
    "_find_random_sidewalk_position",
    UFG::TSWorld::Coro_find_random_sidewalk_position,
    SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    SSBrain::c_world_class_p,
    "_is_position_on_navmesh",
    UFG::TSWorld::Coro_is_position_on_navmesh,
    SSBindFlag_instance_no_rebind);
  LOBYTE(rebinddt.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "reset_taxi_occupancy",
    UFG::TSWorld::MthdC_reset_taxi_occupancy,
    1,
    rebinddt);
  LOBYTE(rebinddu.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "set_all_taxis_occupied",
    UFG::TSWorld::MthdC_set_all_taxis_occupied,
    1,
    rebinddu);
  LOBYTE(rebinddv.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "set_transit_targeting_enabled",
    UFG::TSWorld::MthdC_set_transit_targeting_enabled,
    1,
    rebinddv);
  LOBYTE(rebinddw.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "enable_light_layer",
    UFG::TSWorld::MthdC_enable_light_layer,
    1,
    rebinddw);
  LOBYTE(rebinddx.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "enable_streaming_lookahead",
    UFG::TSWorld::MthdC_enable_streaming_lookahead,
    1,
    rebinddx);
  LOBYTE(rebinddy.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "is_xform_in_view",
    UFG::TSWorld::MthdC_is_xform_in_view,
    1,
    rebinddy);
  LOBYTE(rebinddz.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "set_input_camera_only",
    UFG::TSWorld::MthdC_set_input_camera_only,
    1,
    rebinddz);
  LOBYTE(rebindea.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "trophy_reward",
    UFG::TSWorld::MthdC_trophy_reward,
    1,
    rebindea);
  LOBYTE(rebindeb.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "print_snapshot",
    UFG::TSWorld::MthdC_print_snapshot,
    1,
    rebindeb);
  SSClass::register_coroutine_func(
    SSBrain::c_world_class_p,
    "_spawn_object_at_xform",
    (bool (__fastcall *)(SSInvokedCoroutine *))UFG::TSWorld::Coro_spawn_object_at_xform,
    SSBindFlag_instance_no_rebind);
  LOBYTE(rebindec.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "set_hijack_vehicle_price",
    UFG::TSWorld::MthdC_set_hijack_vehicle_price,
    1,
    rebindec);
  LOBYTE(rebinded.i_uid) = 0;
  SSClass::register_method_func(SSBrain::c_world_class_p, "bind_enums", UFG::TSWorld::MthdC_bind_enums, 1, rebinded);
  LOBYTE(rebindee.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "all_ai_update_attack_targets_now",
    UFG::TSWorld::MthdC_all_ai_update_attack_targets_now,
    1,
    rebindee);
  LOBYTE(rebindef.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "on_launch_chunk_gameplay_completion",
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))_,
    1,
    rebindef);
  LOBYTE(rebindeg.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "set_volumetric_fog_intensity",
    UFG::TSWorld::MthdC_set_volumetric_fog_intensity,
    1,
    rebindeg);
  PhysicsSkookum::RegisterMethods();
  UFG::TSMetrics_BindAtomics(v0);
}

