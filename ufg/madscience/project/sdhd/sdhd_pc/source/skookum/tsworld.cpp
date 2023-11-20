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
      *ppResult = (SSInstance *)SSBoolean::pool_new(1);
    else
      *ppResult = (SSInstance *)SSBoolean::pool_new(0);
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

  v1 = SSBrain::get_class("Metrics");
  SSClass::register_method_func(v1, "simtime_get_frame", UFG::TSMetrics_MthdC_simtime_get_frame, 1, 0);
  SSClass::register_method_func(v1, "simtime_get_scale", UFG::TSMetrics_MthdC_simtime_get_scale, 1, 0);
  SSClass::register_method_func(v1, "simtime_set_scale", UFG::TSMetrics_MthdC_simtime_set_scale, 1, 0);
  SSClass::register_method_func(v1, "simtime_is_paused", UFG::TSMetrics_MthdC_simtime_is_paused, 1, 0);
  SSClass::register_method_func(v1, "simtime_pause", UFG::TSMetrics_MthdC_simtime_pause, 1, 0);
}

// File Line: 249
// RVA: 0x4EEEF0
void __fastcall UFG::TSMetrics_MthdC_simtime_set_scale(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  float v2; // xmm0_4

  v2 = *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  if ( v2 <= 0.0 )
    v2 = 0.0;
  if ( v2 >= UFG::Metrics::msInstance.mSimTimeScaleMax )
    v2 = UFG::Metrics::msInstance.mSimTimeScaleMax;
  UFG::Metrics::msInstance.mSimTimeScaleInGame = v2;
  UFG::Metrics::msInstance.mSimTimeDeltaStep = 0.0;
  UFG::Metrics::msInstance.mSimPausedInGame = 1;
  if ( v2 != 0.0 )
    UFG::Metrics::msInstance.mSimPausedInGame = 0;
}

// File Line: 269
// RVA: 0x512300
UFG::qPropertySet *__fastcall UFG::TSWorld::get_spawn_info(SSInvokedContextBase *pScope, unsigned int argOffset, UFG::qSymbol *pSpawnName, UFG::SceneLayer **ppLayer)
{
  UFG::SceneLayer **v4; // r15
  UFG::qSymbol *v5; // rsi
  unsigned int v6; // ebp
  SSInvokedContextBase *v7; // r14
  SSInstance *v8; // rcx
  UFG::qBaseTreeRB *v9; // rbx
  UFG::qPropertySet *v10; // rdi
  SSInstance *v11; // rdx
  SSClass *v12; // rax
  AStringRef *v13; // rax
  AStringRef *v14; // rbx
  SSInstance *v15; // rbp
  SSClass *v16; // rax
  bool v17; // zf
  AObjReusePool<AStringRef> *v18; // rax
  AObjBlock<AStringRef> *v19; // rcx
  unsigned __int64 v20; // r8
  bool v21; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v22; // rcx
  AObjReusePool<AStringRef> *v23; // rax
  AObjBlock<AStringRef> *v24; // rcx
  unsigned __int64 v25; // r8
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v26; // rcx
  AStringRef *v27; // rax
  const char *v28; // r8
  AObjReusePool<AStringRef> *v29; // rax
  AObjBlock<AStringRef> *v30; // rcx
  unsigned __int64 v31; // r8
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v32; // rcx
  UFG::qSymbol result; // [rsp+78h] [rbp+10h]

  v4 = ppLayer;
  v5 = pSpawnName;
  v6 = argOffset;
  v7 = pScope;
  v8 = pScope->i_data.i_array_p[argOffset]->i_data_p;
  v9 = 0i64;
  if ( v8 )
  {
    if ( v8->i_class_p == UFG::SkookumMgr::mspPropertySetClass )
      v10 = (UFG::qPropertySet *)v8->i_user_data;
    else
      v10 = UFG::PropertySetManager::FindPropertySet((UFG::qSymbol *)&v8->i_user_data);
  }
  else
  {
    v10 = 0i64;
  }
  v11 = v7->i_data.i_array_p[v6 + 2]->i_data_p;
  if ( v11 )
  {
    v12 = v11->i_class_p;
    if ( v12 == UFG::TSSceneLayer::mspSceneLayerClass )
    {
      v9 = (UFG::qBaseTreeRB *)v11->i_user_data;
    }
    else if ( v12 == SSBrain::c_symbol_class_p )
    {
      v9 = UFG::Scene::FindLayer(&UFG::Scene::msDefault, (UFG::qSymbol *)&v11->i_user_data);
    }
  }
  *v4 = (UFG::SceneLayer *)v9;
  v13 = AStringRef::get_empty();
  v14 = v13;
  ++v13->i_ref_count;
  v15 = v7->i_data.i_array_p[v6 + 1]->i_data_p;
  v16 = v15->i_class_p;
  if ( v16 == SSBrain::c_symbol_class_p )
  {
    v5->mUID = v15->i_user_data;
  }
  else if ( v16 == SSBrain::c_string_class_p )
  {
    ++*(_WORD *)(v15->i_user_data + 16);
    v17 = v14->i_ref_count-- == 1;
    if ( v17 )
    {
      if ( v14->i_deallocate )
        AMemory::c_free_func(v14->i_cstr_p);
      v18 = AStringRef::get_pool();
      v19 = v18->i_block_p;
      v20 = (unsigned __int64)v19->i_objects_a;
      if ( (unsigned __int64)v14 < v20
        || (v21 = (unsigned __int64)v14 < v20 + 24i64 * v19->i_size, v22 = &v18->i_pool, !v21) )
      {
        v22 = &v18->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v22, v14);
    }
    v14 = (AStringRef *)v15->i_user_data;
  }
  if ( v5->mUID == -1 )
  {
    if ( v14->i_length )
    {
      if ( *v4 )
      {
        UFG::SceneLayer::GenerateUniqueNameForSkookum(*v4, v14->i_cstr_p, v5);
        goto LABEL_38;
      }
      v28 = v14->i_cstr_p;
    }
    else
    {
      v17 = v14->i_ref_count-- == 1;
      if ( v17 )
      {
        if ( v14->i_deallocate )
          AMemory::c_free_func(v14->i_cstr_p);
        v23 = AStringRef::get_pool();
        v24 = v23->i_block_p;
        v25 = (unsigned __int64)v24->i_objects_a;
        if ( (unsigned __int64)v14 < v25
          || (v21 = (unsigned __int64)v14 < v25 + 24i64 * v24->i_size, v26 = &v23->i_pool, !v21) )
        {
          v26 = &v23->i_exp_pool;
        }
        APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v26, v14);
      }
      v27 = AStringRef::pool_new("_spawn000", 9u, 0xAu, 1u, 0, 1);
      v14 = v27;
      if ( *v4 )
      {
        UFG::SceneLayer::GenerateUniqueNameForSkookum(*v4, v27->i_cstr_p, v5);
        goto LABEL_38;
      }
      v28 = v27->i_cstr_p;
    }
    v5->mUID = UFG::Simulation::GenerateUniqueName(&UFG::gSim, &result, v28)->mUID;
  }
LABEL_38:
  v17 = v14->i_ref_count-- == 1;
  if ( v17 )
  {
    if ( v14->i_deallocate )
      AMemory::c_free_func(v14->i_cstr_p);
    v29 = AStringRef::get_pool();
    v30 = v29->i_block_p;
    v31 = (unsigned __int64)v30->i_objects_a;
    if ( (unsigned __int64)v14 < v31
      || (v21 = (unsigned __int64)v14 < v31 + 24i64 * v30->i_size, v32 = &v29->i_pool, !v21) )
    {
      v32 = &v29->i_exp_pool;
    }
    APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v32, v14);
  }
  return v10;
}

// File Line: 332
// RVA: 0x4F20C0
void __fastcall UFG::TSWorld::MthdC_spawn_object(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rdi
  UFG::qPropertySet *v3; // rax
  UFG::SimObject *v4; // rax
  UFG::SimObject *v5; // rbx
  UFG::TSActor *v6; // rax
  UFG::MarkerBase *v7; // rax
  UFG::qSymbol pSpawnName; // [rsp+48h] [rbp+10h]
  UFG::SceneLayer *ppLayer; // [rsp+50h] [rbp+18h]

  v2 = ppResult;
  pSpawnName.mUID = -1;
  v3 = UFG::TSWorld::get_spawn_info((SSInvokedContextBase *)&pScope->vfptr, 0, &pSpawnName, &ppLayer);
  v4 = UFG::SpawnInfoInterface::SpawnObject(&pSpawnName, v3, 0, ppLayer, 0i64, 0i64);
  v5 = v4;
  if ( v2 )
  {
    v6 = UFG::TSActor::SkookumObjFromSimObj(v4);
    if ( !v6 )
    {
      if ( v5 )
      {
        v7 = (UFG::MarkerBase *)UFG::SimObject::GetComponentOfType(v5, UFG::MarkerBase::_TypeUID);
        if ( v7 )
        {
          *v2 = UFG::TSMarker::AsInstance(v7);
          return;
        }
      }
      v6 = (UFG::TSActor *)SSBrain::c_nil_p;
    }
    *v2 = (SSInstance *)&v6->vfptr;
  }
}

// File Line: 363
// RVA: 0x4F2160
void __fastcall UFG::TSWorld::MthdC_spawn_object_at_xform(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rsi
  SSInvokedMethod *v3; // rbx
  UFG::qPropertySet *v4; // rdi
  UFG::TransformNodeComponent *v5; // rbx
  UFG::SimObject *v6; // rax
  UFG::SimObject *v7; // rbx
  UFG::TSActor *v8; // rax
  UFG::MarkerBase *v9; // rax
  UFG::qSymbol pSpawnName; // [rsp+40h] [rbp+8h]
  UFG::SceneLayer *ppLayer; // [rsp+48h] [rbp+10h]

  v2 = ppResult;
  v3 = pScope;
  pSpawnName.mUID = -1;
  v4 = UFG::TSWorld::get_spawn_info((SSInvokedContextBase *)&pScope->vfptr, 1u, &pSpawnName, &ppLayer);
  v5 = (UFG::TransformNodeComponent *)(*v3->i_data.i_array_p)->i_data_p->i_user_data;
  UFG::TransformNodeComponent::UpdateWorldTransform(v5);
  v6 = UFG::SpawnInfoInterface::SpawnObject(&pSpawnName, v4, &v5->mWorldTransform, 0, ppLayer, 0i64);
  v7 = v6;
  if ( v2 )
  {
    v8 = UFG::TSActor::SkookumObjFromSimObj(v6);
    if ( !v8 )
    {
      if ( v7 )
      {
        v9 = (UFG::MarkerBase *)UFG::SimObject::GetComponentOfType(v7, UFG::MarkerBase::_TypeUID);
        if ( v9 )
        {
          *v2 = UFG::TSMarker::AsInstance(v9);
          return;
        }
      }
      v8 = (UFG::TSActor *)SSBrain::c_nil_p;
    }
    *v2 = (SSInstance *)&v8->vfptr;
  }
}

// File Line: 397
// RVA: 0x4EDFE0
void __fastcall UFG::TSWorld::MthdC_set_hijack_vehicle_price(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rdx
  unsigned int v3; // eax
  int v4; // ebx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v5; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v6; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v7; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h]

  v2 = pScope->i_data.i_array_p;
  v3 = (*v2)->i_data_p->i_user_data;
  v4 = v2[1]->i_data_p->i_user_data;
  pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  pTrackEnumBinding.m_EnumSymbol.mUID = v3;
  *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
  pTrackEnumBinding.m_uEnumUID = 0;
  if ( UFG::gInventoryItemTracksEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&UFG::gInventoryItemTracksEnum, &pTrackEnumBinding);
  }
  else
  {
    v5 = UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.mPrev = v5;
    pTrackEnumBinding.mNext = &UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode;
    UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  }
  if ( pTrackEnumBinding.m_EnumValue == 104 )
    UFG::ItemProfiles::SetCost(eINVENTORY_ITEM_HIJACKED_VEHICLE, v4);
  v6 = pTrackEnumBinding.mPrev;
  v7 = pTrackEnumBinding.mNext;
  pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
  v7->mPrev = v6;
}

// File Line: 420
// RVA: 0x4F28C0
void __fastcall UFG::TSWorld::MthdC_time_get(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  UFG::TimeOfDayManager *v3; // rax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = UFG::TimeOfDayManager::GetInstance();
    *v2 = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(v3->m_SecondsSinceMidnight));
  }
}

// File Line: 430
// RVA: 0x4EE1F0
void __fastcall UFG::TSWorld::MthdC_set_layer_active(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // r8
  SSInstance **v3; // rsi
  const char *v4; // rdi
  bool v5; // bl
  char v6; // bp

  v2 = pScope->i_data.i_array_p;
  v3 = ppResult;
  v4 = *(const char **)(*v2)->i_data_p->i_user_data;
  v5 = v2[1]->i_data_p->i_user_data != 0;
  v6 = UFG::SectionLayout::SetLayerActive(v4, v5);
  UFG::SectionChooser::FlushAltLayer(v4, v5);
  if ( v3 )
    *v3 = (SSInstance *)SSBoolean::pool_new(v6);
}

// File Line: 450
// RVA: 0x4E7B10
void __fastcall UFG::TSWorld::MthdC_get_layer_count(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  unsigned int v3; // eax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = UFG::SectionLayout::GetLayerCount();
    *v2 = SSInstance::pool_new(SSBrain::c_integer_class_p, v3);
  }
}

// File Line: 458
// RVA: 0x4E7B40
void __fastcall UFG::TSWorld::MthdC_get_layer_name(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rsi
  const char *v3; // rax
  const char *v4; // rdi
  signed __int64 v5; // rbx
  unsigned int v6; // eax
  AStringRef *v7; // rbx
  bool v8; // zf
  AObjReusePool<AStringRef> *v9; // rax
  AObjBlock<AStringRef> *v10; // rcx
  unsigned __int64 v11; // rdx
  bool v12; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v13; // rcx
  AString str; // [rsp+58h] [rbp+10h]

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = UFG::SectionLayout::GetLayerName((*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    v4 = v3;
    v5 = -1i64;
    do
      ++v5;
    while ( v3[v5] );
    v6 = AMemory::c_req_byte_size_func(v5 + 1);
    str.i_str_ref_p = AStringRef::pool_new(v4, v5, v6, 1u, 0, 1);
    *v2 = SSString::as_instance(&str);
    v7 = str.i_str_ref_p;
    v8 = str.i_str_ref_p->i_ref_count == 1;
    --v7->i_ref_count;
    if ( v8 )
    {
      if ( v7->i_deallocate )
        AMemory::c_free_func(v7->i_cstr_p);
      v9 = AStringRef::get_pool();
      v10 = v9->i_block_p;
      v11 = (unsigned __int64)v10->i_objects_a;
      if ( (unsigned __int64)v7 < v11
        || (v12 = (unsigned __int64)v7 < v11 + 24i64 * v10->i_size, v13 = &v9->i_pool, !v12) )
      {
        v13 = &v9->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v13, v7);
    }
  }
}

// File Line: 477
// RVA: 0x4F2940
void __fastcall UFG::TSWorld::MthdC_time_is_day(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  __int128 v3; // xmm0

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = LODWORD(UFG::TimeOfDayManager::GetInstance()->m_SecondsSinceMidnight);
    if ( *(float *)&v3 < 21600.0 || *(float *)&v3 > 64800.0 )
      *v2 = (SSInstance *)SSBoolean::pool_new(0);
    else
      *v2 = (SSInstance *)SSBoolean::pool_new(1);
  }
}

// File Line: 492
// RVA: 0x4F29A0
void __fastcall UFG::TSWorld::MthdC_time_set(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *v2; // rbx
  UFG::TimeOfDayManager *v3; // rax

  v2 = (*pScope->i_data.i_array_p)->i_data_p;
  v3 = UFG::TimeOfDayManager::GetInstance();
  UFG::TimeOfDayManager::SetTime(v3, *(float *)&v2->i_user_data, 0);
  UFG::TidoGame::ResetTODEmitters();
}

// File Line: 504
// RVA: 0x4F2900
void __fastcall UFG::TSWorld::MthdC_time_get_scale(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  UFG::TimeOfDayManager *v3; // rax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = UFG::TimeOfDayManager::GetInstance();
    *v2 = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(v3->m_GameSecondsPerRealSecond));
  }
}

// File Line: 518
// RVA: 0x4F29D0
void __fastcall UFG::TSWorld::MthdC_time_set_scale(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *v2; // rbx
  UFG::TimeOfDayManager *v3; // rax

  v2 = (*pScope->i_data.i_array_p)->i_data_p;
  v3 = UFG::TimeOfDayManager::GetInstance();
  TimePlotPoint::SetTimeValue(v3, *(float *)&v2->i_user_data);
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
  SSInstance **v2; // rbx
  UFG::TimeOfDayManager *v3; // rax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = UFG::TimeOfDayManager::GetInstance();
    *v2 = (SSInstance *)SSBoolean::pool_new(1.0 < v3->m_WeatherState);
  }
}

// File Line: 632
// RVA: 0x4F3370
void __fastcall UFG::TSWorld::MthdC_weather_get_amount(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  UFG::TimeOfDayManager *v3; // rax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = UFG::TimeOfDayManager::GetInstance();
    *v2 = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(v3->m_WeatherState));
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
  UFG::qSymbol skydomeName; // [rsp+30h] [rbp+8h]

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
  SSInstance **v2; // rdi
  int v3; // ebx
  UFG::ProgressionTracker *v4; // rax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    v4 = UFG::ProgressionTracker::Instance();
    *v2 = (SSInstance *)SSBoolean::pool_new(v3 == v4->mSubSetModeType.mUID);
  }
}

// File Line: 705
// RVA: 0x4EE780
void __fastcall UFG::TSWorld::MthdC_set_progression_subset_mode(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  unsigned int v2; // ebx

  v2 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  UFG::ProgressionTracker::Instance()->mSubSetModeType.mUID = v2;
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
  UFG::TimeOfDayManager *v3; // rax
  float v4; // xmm0_4

  v2 = *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v3 = UFG::TimeOfDayManager::GetInstance();
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
  v3->m_WeatherState = v4;
  v3->m_WeatherTarget = v4;
  v3->m_NextWeatherTarget = v4;
}

// File Line: 739
// RVA: 0x4F3590
void __fastcall UFG::TSWorld::MthdC_weather_target(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  float v2; // xmm6_4
  UFG::TimeOfDayManager *v3; // rax

  v2 = *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v3 = UFG::TimeOfDayManager::GetInstance();
  if ( v2 <= 0.0 )
  {
    v2 = 0.0;
  }
  else if ( v2 >= 2.0 )
  {
    v3->m_WeatherTarget = FLOAT_2_0;
    v3->m_NextWeatherTarget = FLOAT_2_0;
    return;
  }
  v3->m_WeatherTarget = v2;
  v3->m_NextWeatherTarget = v2;
}

// File Line: 750
// RVA: 0x4F33E0
void __fastcall UFG::TSWorld::MthdC_weather_lock(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  bool v2; // bl
  UFG::TimeOfDayManager *v3; // rax

  v2 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  v3 = UFG::TimeOfDayManager::GetInstance();
  UFG::TimeOfDayManager::LockWeather(v3, v2);
}

// File Line: 761
// RVA: 0x4F3410
void __fastcall UFG::TSWorld::MthdC_weather_rain_chance(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  float v2; // xmm6_4
  UFG::TimeOfDayManager *v3; // rax

  v2 = *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v3 = UFG::TimeOfDayManager::GetInstance();
  if ( v2 <= 0.0 )
  {
    v2 = 0.0;
  }
  else if ( v2 >= 1.0 )
  {
    LODWORD(v3->m_WeatherChanceOfPrecipitation) = (_DWORD)FLOAT_1_0;
    return;
  }
  v3->m_WeatherChanceOfPrecipitation = v2;
}

// File Line: 773
// RVA: 0x4F3470
void __fastcall UFG::TSWorld::MthdC_weather_randomize_interval(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  int v2; // ebx

  v2 = (signed int)(float)(*(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data + 0.5);
  UFG::TimeOfDayManager::GetInstance()->m_WeatherRandomInterval = v2;
}

// File Line: 787
// RVA: 0x4F35F0
void __fastcall UFG::TSWorld::MthdC_weather_wetness_override(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *v2; // rbx
  UFG::TimeOfDayManager *v3; // rax

  v2 = (*pScope->i_data.i_array_p)->i_data_p;
  v3 = UFG::TimeOfDayManager::GetInstance();
  UFG::TimeOfDayManager::SetSurfaceWetnessOverride(v3, *(float *)&v2->i_user_data, "Script");
}

// File Line: 798
// RVA: 0x4F3530
void __fastcall UFG::TSWorld::MthdC_weather_set_wind(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rdx
  float v3; // xmm7_4
  float v4; // xmm6_4
  UFG::TimeOfDayManager *v5; // rax

  v2 = pScope->i_data.i_array_p;
  v3 = (float)(*(float *)&(*v2)->i_data_p->i_user_data * 3.1415927) * 0.0055555557;
  v4 = *(float *)&v2[1]->i_data_p->i_user_data;
  v5 = UFG::TimeOfDayManager::GetInstance();
  UFG::TimeOfDayManager::SetWind(v5, v3, v4);
}

// File Line: 812
// RVA: 0x4E7C60
void __fastcall UFG::TSWorld::MthdC_get_location_name(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rsi
  UFG::ProgressionTracker *v3; // rax
  const char *v4; // rdi
  signed __int64 v5; // rbx
  unsigned int v6; // eax
  AStringRef *v7; // rbx
  bool v8; // zf
  AObjReusePool<AStringRef> *v9; // rax
  AObjBlock<AStringRef> *v10; // rcx
  unsigned __int64 v11; // rdx
  bool v12; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v13; // rcx
  AString str; // [rsp+58h] [rbp+10h]

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = UFG::ProgressionTracker::Instance();
    v4 = UFG::ProgressionTracker::GetGameSetup(v3)->mLocationDir;
    v5 = -1i64;
    do
      ++v5;
    while ( v4[v5] );
    v6 = AMemory::c_req_byte_size_func(v5 + 1);
    str.i_str_ref_p = AStringRef::pool_new(v4, v5, v6, 1u, 0, 1);
    *v2 = SSString::as_instance(&str);
    v7 = str.i_str_ref_p;
    v8 = str.i_str_ref_p->i_ref_count == 1;
    --v7->i_ref_count;
    if ( v8 )
    {
      if ( v7->i_deallocate )
        AMemory::c_free_func(v7->i_cstr_p);
      v9 = AStringRef::get_pool();
      v10 = v9->i_block_p;
      v11 = (unsigned __int64)v10->i_objects_a;
      if ( (unsigned __int64)v7 < v11
        || (v12 = (unsigned __int64)v7 < v11 + 24i64 * v10->i_size, v13 = &v9->i_pool, !v12) )
      {
        v13 = &v9->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v13, v7);
    }
  }
}

// File Line: 828
// RVA: 0x4E7C30
void __fastcall UFG::TSWorld::MthdC_get_local_player(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  UFG::SimObjectCharacter *v3; // rax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = UFG::GetLocalPlayer();
    *v2 = (SSInstance *)UFG::TSActor::SkookumObjFromSimObj((UFG::SimObject *)&v3->vfptr);
  }
}

// File Line: 844
// RVA: 0x4E9A10
void __fastcall UFG::TSWorld::MthdC_is_simobject_existent(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  int v3; // eax
  UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> **v4; // rcx
  bool v5; // r8

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = UFG::qStringHashUpper32(*(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data, 0xFFFFFFFF);
    v4 = &UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mNext[-18].mNext;
    v5 = 0;
    if ( &UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mNext[-18].mNext != (UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> **)((char *)&UFG::RigidBodyComponent::s_RigidBodyComponentList - 280) )
    {
      while ( *((_DWORD *)v4 + 7) != v3 )
      {
        v4 = &v4[36][-18].mNext;
        if ( v4 == (UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> **)((char *)&UFG::RigidBodyComponent::s_RigidBodyComponentList
                                                                                  - 280) )
        {
          *v2 = (SSInstance *)SSBoolean::pool_new(0);
          return;
        }
      }
      v5 = 1;
    }
    *v2 = (SSInstance *)SSBoolean::pool_new(v5);
  }
}

// File Line: 875
// RVA: 0x4EA3B0
void __fastcall UFG::TSWorld::MthdC_join_group(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSActor *v2; // rdi
  bool v3; // r12
  UFG::qBaseTreeRB *v4; // rsi
  SSInstance **v5; // r15
  SSInvokedMethod *v6; // rbp
  SSClass *v7; // rbx
  SSActor *v8; // rbx
  SSClass *v9; // r14
  UFG::SimObject *v10; // rdi
  UFG::SimObject *v11; // rbx
  unsigned int v12; // edx

  v2 = (SSActor *)(*pScope->i_data.i_array_p)->i_data_p;
  v3 = 0;
  v4 = 0i64;
  v5 = ppResult;
  v6 = pScope;
  if ( !v2 )
    goto LABEL_22;
  v7 = v2->i_class_p;
  if ( v7->vfptr->is_actor_class((SSClassDescBase *)&v7->vfptr) )
    goto LABEL_7;
  if ( v7 == SSBrain::c_symbol_class_p && LODWORD(v2->i_user_data) != -1 )
    v2 = SSActor::find((ASymbol *)&v2->i_user_data);
  else
LABEL_22:
    v2 = 0i64;
LABEL_7:
  v8 = *(SSActor **)(*((_QWORD *)v6->i_data.i_array_p + 1) + 8i64);
  if ( !v8 )
    goto LABEL_12;
  v9 = v8->i_class_p;
  if ( !v9->vfptr->is_actor_class((SSClassDescBase *)&v9->vfptr) )
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
  if ( v2 && v8 )
  {
    v10 = *(UFG::SimObject **)&v2[1].i_icoroutines_to_update.i_count;
    v11 = *(UFG::SimObject **)&v8[1].i_icoroutines_to_update.i_count;
    v12 = *(_DWORD *)(*(_QWORD *)(*((_QWORD *)v6->i_data.i_array_p + 2) + 8i64) + 32i64);
    if ( v12 )
      v4 = UFG::qBaseTreeRB::Get(&UFG::PedFormationManagerComponent::s_Profiles.mTree, v12);
    v3 = UFG::GroupComponent::JoinGroup(v10, v11, (UFG::PedFormationProfile *)v4);
  }
  if ( v5 )
    *v5 = (SSInstance *)SSBoolean::pool_new(v3);
}

// File Line: 904
// RVA: 0x4E5260
void __fastcall UFG::TSWorld::MthdC_enable_sidewalk_node(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  AStringRef *v2; // rbx
  bool v3; // di
  unsigned int v4; // eax
  bool v5; // zf
  AObjReusePool<AStringRef> *v6; // rax
  AObjBlock<AStringRef> *v7; // rcx
  unsigned __int64 v8; // rdx
  bool v9; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v10; // rcx

  v2 = (AStringRef *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  ++v2->i_ref_count;
  v3 = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64) != 0i64;
  v4 = AChecksum::generate_crc32_cstr_upper(v2->i_cstr_p, v2->i_length, 0xFFFFFFFF);
  UFG::AISidewalkGraph::SetNodeActive(v4, v3);
  v5 = v2->i_ref_count-- == 1;
  if ( v5 )
  {
    if ( v2->i_deallocate )
      AMemory::c_free_func(v2->i_cstr_p);
    v6 = AStringRef::get_pool();
    v7 = v6->i_block_p;
    v8 = (unsigned __int64)v7->i_objects_a;
    if ( (unsigned __int64)v2 < v8 || (v9 = (unsigned __int64)v2 < v8 + 24i64 * v7->i_size, v10 = &v6->i_pool, !v9) )
      v10 = &v6->i_exp_pool;
    APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v10, v2);
  }
}

// File Line: 924
// RVA: 0x4E72C0
void __fastcall UFG::TSWorld::MthdC_get_closest_sidewalk_position(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  SSInvokedMethod *v3; // rdi
  SSData **v4; // r9
  float *v5; // rax
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm6_4
  UFG::AISidewalkEdge_Game *v9; // rax
  UFG::AISidewalkEdge_Game *v10; // rax
  UFG::AISidewalkEdge_Game *v11; // rax
  UFG::AISidewalkNode_Game *v12; // rax
  float v13; // xmm1_4
  float v14; // xmm2_4
  UFG::AISidewalkEdge_Game *v15; // rax
  UFG::AISidewalkNode_Game *v16; // rax
  float v17; // xmm1_4
  float v18; // xmm2_4
  UFG::allocator::free_link *v19; // rax
  float v20; // xmm1_4
  float v21; // xmm2_4
  SSInstance *v22; // rax
  bool v23; // cl
  UFG::qResourceInventory *v24; // rax
  UFG::qResourceWarehouse *v25; // rax
  UFG::qVector3 closest_point; // [rsp+20h] [rbp-31h]
  UFG::qVector3 pos; // [rsp+30h] [rbp-21h]
  UFG::qVector3 lA1; // [rsp+40h] [rbp-11h]
  UFG::qVector3 lA0; // [rsp+50h] [rbp-1h]
  UFG::qResourceHandle v30; // [rsp+60h] [rbp+Fh]
  int v31; // [rsp+80h] [rbp+2Fh]
  int v32; // [rsp+84h] [rbp+33h]
  __int64 v33; // [rsp+88h] [rbp+37h]

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = pScope;
    v4 = pScope->i_data.i_array_p;
    v5 = (float *)(*v4)->i_data_p->i_user_data;
    v6 = v5[1];
    v7 = v5[2];
    pos.x = *v5;
    pos.y = v6;
    pos.z = v7;
    v8 = *(float *)&v4[1]->i_data_p->i_user_data;
    UFG::qResourceHandle::qResourceHandle(&v30);
    v31 = 0x1FFFF;
    v32 = -1;
    v33 = 0i64;
    v30.mNameUID = -1;
    UFG::AISidewalkGraph::FindClosestSidewalkConnection(
      &pos,
      v8,
      (UFG::SidewalkCommonHandle<UFG::AISidewalkEdge_Game> *)&v30,
      0xFFu);
    if ( Scaleform::GFx::FontManagerStates::GetStateBagImpl((LOCALNAMESPACE::hkNativeResource *)&v30)
      && (v9 = (UFG::AISidewalkEdge_Game *)Scaleform::GFx::FontManagerStates::GetStateBagImpl((LOCALNAMESPACE::hkNativeResource *)&v30),
          UFG::AISidewalkEdge_Game::GetStartNode(v9))
      && (v10 = (UFG::AISidewalkEdge_Game *)Scaleform::GFx::FontManagerStates::GetStateBagImpl((LOCALNAMESPACE::hkNativeResource *)&v30),
          UFG::AISidewalkEdge_Game::GetEndNode(v10)) )
    {
      v11 = (UFG::AISidewalkEdge_Game *)Scaleform::GFx::FontManagerStates::GetStateBagImpl((LOCALNAMESPACE::hkNativeResource *)&v30);
      v12 = UFG::AISidewalkEdge_Game::GetStartNode(v11);
      v13 = v12->mPos.y;
      v14 = v12->mPos.z;
      lA0.x = v12->mPos.x;
      lA0.y = v13;
      lA0.z = v14;
      v15 = (UFG::AISidewalkEdge_Game *)Scaleform::GFx::FontManagerStates::GetStateBagImpl((LOCALNAMESPACE::hkNativeResource *)&v30);
      v16 = UFG::AISidewalkEdge_Game::GetEndNode(v15);
      v17 = v16->mPos.y;
      v18 = v16->mPos.z;
      lA1.x = v16->mPos.x;
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
      SSInvokedContextBase::set_arg((SSInvokedContextBase *)&v3->vfptr, 2u, v22);
      v23 = 1;
    }
    else
    {
      v23 = 0;
    }
    *v2 = (SSInstance *)SSBoolean::pool_new(v23);
    v24 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result;
    if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result )
    {
      v25 = UFG::qResourceWarehouse::Instance();
      v24 = UFG::qResourceWarehouse::GetInventory(v25, 0x43E99F7Eu);
      `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result = v24;
    }
    UFG::qResourceHandle::Close(&v30, v24);
    UFG::qResourceHandle::~qResourceHandle(&v30);
  }
}

// File Line: 967
// RVA: 0x4ECC40
void __fastcall UFG::TSWorld::MthdC_run_script_test(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rdx
  unsigned int v3; // ebx
  unsigned int v4; // edi
  bool v5; // si
  UFG::qSymbol *v6; // rbx
  UFG::ProgressionTracker *v7; // rax
  UFG::qBaseTreeRB *v8; // rbx
  UFG::ProgressionTracker *v9; // rax
  UFG::ProgressionTracker *v10; // rax
  UFG::qSymbol result; // [rsp+30h] [rbp+8h]

  v2 = pScope->i_data.i_array_p;
  v3 = (*v2)->i_data_p->i_user_data;
  v4 = v2[1]->i_data_p->i_user_data;
  v5 = v2[2]->i_data_p->i_user_data != 0;
  UFG::ProgressionTracker::Instance()->mDEBUGTestScenarioScriptName.mUID = v3;
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
  UFG::qBaseNodeRB *v2; // rdi
  UFG::RoadNetworkResource *v3; // rbx
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v4; // rax

  v2 = UFG::MarkerBase::GetNamed((UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data)[1].mNULL.mParent;
  v3 = UFG::WheeledVehicleNavigationData::GetRoadNetwork(UFG::WheeledVehicleManager::m_Instance->m_NavigationData);
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v2);
  v4 = UFG::RoadNetworkResource::GetClosestSubSegment(v3, (UFG::qVector3 *)&v2[5].mChild[1], 0);
  if ( v4 )
    UFG::WheeledVehicleNavigationData::AddRoadBlocksAroundSegment(
      UFG::WheeledVehicleManager::m_Instance->m_NavigationData,
      (UFG::RoadNetworkSegment *)v4[1].mPrev);
}

// File Line: 1026
// RVA: 0x4EC230
void __fastcall UFG::TSWorld::MthdC_remove_road_block(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::qBaseNodeRB *v2; // rdi
  UFG::RoadNetworkResource *v3; // rbx
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v4; // rax

  v2 = UFG::MarkerBase::GetNamed((UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data)[1].mNULL.mParent;
  v3 = UFG::WheeledVehicleNavigationData::GetRoadNetwork(UFG::WheeledVehicleManager::m_Instance->m_NavigationData);
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v2);
  v4 = UFG::RoadNetworkResource::GetClosestSubSegment(v3, (UFG::qVector3 *)&v2[5].mChild[1], 0);
  if ( v4 )
    UFG::WheeledVehicleNavigationData::RemoveRoadBlocksAroundSegment(
      UFG::WheeledVehicleManager::m_Instance->m_NavigationData,
      (UFG::RoadNetworkSegment *)v4[1].mPrev);
}

// File Line: 1052
// RVA: 0x4ED030
void __fastcall UFG::TSWorld::MthdC_set_all_taxis_occupied(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::VehicleOccupantComponent *v2; // rdi
  UFG::SimObjectCVBase *v3; // rbx
  UFG::qList<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent,1,0> *v4; // rsi
  unsigned __int16 v5; // cx
  UFG::AiDriverComponent *v6; // rax
  int v7; // eax
  int v8; // eax

  v2 = (UFG::VehicleOccupantComponent *)&UFG::VehicleOccupantComponent::s_VehicleOccupantComponentList.mNode.mNext[-4];
  if ( (UFG::qList<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent,1,0> *)&UFG::VehicleOccupantComponent::s_VehicleOccupantComponentList.mNode.mNext[-4] != &UFG::VehicleOccupantComponent::s_VehicleOccupantComponentList - 4 )
  {
    do
    {
      v3 = (UFG::SimObjectCVBase *)v2->m_pSimObject;
      v4 = (UFG::qList<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent,1,0> *)&v2->mNext[-4];
      if ( UFG::SimObjectUtility::IsClassType(v2->m_pSimObject, (UFG::qSymbol *)&qSymbol_Taxi.mUID)
        && !(unsigned int)UFG::VehicleOccupantComponent::GetNumberOfPassengers(v2)
        && v3 )
      {
        v5 = v3->m_Flags;
        if ( (v5 >> 14) & 1 )
        {
          v6 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3);
        }
        else if ( (v5 & 0x8000u) == 0 )
        {
          if ( (v5 >> 13) & 1 )
          {
            v6 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             (UFG::SimObjectGame *)&v3->vfptr,
                                             UFG::AiDriverComponent::_TypeUID);
          }
          else if ( (v5 >> 12) & 1 )
          {
            v6 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             (UFG::SimObjectGame *)&v3->vfptr,
                                             UFG::AiDriverComponent::_TypeUID);
          }
          else
          {
            v6 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                             (UFG::SimObject *)&v3->vfptr,
                                             UFG::AiDriverComponent::_TypeUID);
          }
        }
        else
        {
          v6 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3);
        }
        if ( v6 )
        {
          if ( ((unsigned __int8 (__fastcall *)(UFG::AiDriverComponent *))v6->vfptr[16].__vecDelDtor)(v6) )
          {
            v7 = UFG::VehicleOccupantComponent::GetNumberOfSeats(v2);
            v8 = UFG::qRandom(v7 - 2, &UFG::qDefaultSeed);
            PropertyUtils::SetRuntime<unsigned long>(
              v3->m_pSceneObj,
              (UFG::qSymbol *)&qSymbol_AmbientPassengerCount.mUID,
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
  UFG::qNode<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent> *v2; // rbx
  UFG::qNode<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent> *v3; // rdi
  UFG::SimObjectCVBase *v4; // rbx
  UFG::qList<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent,1,0> *v5; // rdi
  unsigned __int16 v6; // cx
  UFG::AiDriverComponent *v7; // rax

  v2 = UFG::VehicleOccupantComponent::s_VehicleOccupantComponentList.mNode.mNext - 4;
  if ( (UFG::qList<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent,1,0> *)&UFG::VehicleOccupantComponent::s_VehicleOccupantComponentList.mNode.mNext[-4] != &UFG::VehicleOccupantComponent::s_VehicleOccupantComponentList - 4 )
  {
    do
    {
      v3 = v2[4].mNext;
      v4 = (UFG::SimObjectCVBase *)v2[2].mNext;
      v5 = (UFG::qList<UFG::VehicleOccupantComponent,UFG::VehicleOccupantComponent,1,0> *)&v3[-4];
      if ( UFG::SimObjectUtility::IsClassType((UFG::SimObject *)&v4->vfptr, (UFG::qSymbol *)&qSymbol_Taxi.mUID) && v4 )
      {
        v6 = v4->m_Flags;
        if ( (v6 >> 14) & 1 )
        {
          v7 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v4);
        }
        else if ( (v6 & 0x8000u) == 0 )
        {
          if ( (v6 >> 13) & 1 )
          {
            v7 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             (UFG::SimObjectGame *)&v4->vfptr,
                                             UFG::AiDriverComponent::_TypeUID);
          }
          else if ( (v6 >> 12) & 1 )
          {
            v7 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             (UFG::SimObjectGame *)&v4->vfptr,
                                             UFG::AiDriverComponent::_TypeUID);
          }
          else
          {
            v7 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                             (UFG::SimObject *)&v4->vfptr,
                                             UFG::AiDriverComponent::_TypeUID);
          }
        }
        else
        {
          v7 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v4);
        }
        if ( v7
          && ((unsigned __int8 (__fastcall *)(UFG::AiDriverComponent *))v7->vfptr[16].__vecDelDtor)(v7)
          && (unsigned int)UFG::qRandom(100, &UFG::qDefaultSeed) > UFG::VehicleOccupantComponent::msPercentageChanceTaxiOccupation )
        {
          PropertyUtils::SetRuntime<unsigned long>(
            v4->m_pSceneObj,
            (UFG::qSymbol *)&qSymbol_AmbientPassengerCount.mUID,
            0);
        }
      }
      v2 = &v5->mNode;
    }
    while ( v5 != &UFG::VehicleOccupantComponent::s_VehicleOccupantComponentList - 4 );
  }
}

// File Line: 1122
// RVA: 0x4EF3B0
void __fastcall UFG::TSWorld::MthdC_set_transit_targeting_enabled(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::SimObjectCharacter *v3; // rax
  UFG::TargetingSystemPedPlayerComponent *v4; // rax

  v2 = pScope;
  if ( UFG::GetLocalPlayer() )
  {
    v3 = UFG::GetLocalPlayer();
    v4 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedPlayerComponent>((UFG::SimObjectCVBase *)&v3->vfptr);
    if ( v4 )
      v4->m_TransitTargetingDisabledByScript = (*v2->i_data.i_array_p)->i_data_p->i_user_data == 0;
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
  SSInvokedMethod *v2; // r14
  SSInstance **v3; // rsi
  UFG::TransformNodeComponent *v4; // rbx
  UFG::qVector3 *v5; // r15
  UFG::BaseCameraComponent *v6; // rcx
  UFG::Camera *v7; // rdi
  UFG::qMatrix44 *v8; // rbx
  UFG::qMatrix44 *v9; // rax
  int v10; // xmm5_4
  float v11; // xmm12_4
  float v12; // ST40_4
  float v13; // ST44_4
  float v14; // xmm10_4
  float v15; // xmm11_4
  float v16; // xmm13_4
  float v17; // xmm14_4
  float v18; // xmm15_4
  float v19; // ST28_4
  float v20; // ST34_4
  float v21; // ST20_4
  float v22; // xmm0_4
  float v23; // xmm0_4
  float v24; // et1
  float v25; // xmm0_4
  __m128 v26; // xmm2
  float v27; // xmm0_4
  __m128 v28; // xmm2
  float v29; // xmm0_4
  float v30; // xmm4_4
  SSData **v31; // rax
  __m128 v32; // xmm2
  float v33; // xmm0_4
  int v34; // eax
  UFG::qMatrix44 result; // [rsp+50h] [rbp-98h]
  float v36; // [rsp+90h] [rbp-58h]
  float v37; // [rsp+94h] [rbp-54h]
  float v38; // [rsp+98h] [rbp-50h]
  float v39; // [rsp+9Ch] [rbp-4Ch]
  float v40; // [rsp+A0h] [rbp-48h]
  float v41; // [rsp+A4h] [rbp-44h]
  float v42; // [rsp+A8h] [rbp-40h]
  float v43; // [rsp+ACh] [rbp-3Ch]
  float v44; // [rsp+B0h] [rbp-38h]
  float v45; // [rsp+B4h] [rbp-34h]
  float v46; // [rsp+B8h] [rbp-30h]
  float v47; // [rsp+BCh] [rbp-2Ch]
  float v48; // [rsp+C0h] [rbp-28h]
  float v49; // [rsp+C4h] [rbp-24h]
  float v50; // [rsp+C8h] [rbp-20h]
  float v51; // [rsp+CCh] [rbp-1Ch]
  float v52; // [rsp+D0h] [rbp-18h]
  float v53; // [rsp+D4h] [rbp-14h]
  unsigned int vars0; // [rsp+1B0h] [rbp+C8h]
  float v55; // [rsp+1C0h] [rbp+D8h]

  if ( ppResult )
  {
    v2 = pScope;
    v3 = ppResult;
    v4 = (UFG::TransformNodeComponent *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    UFG::TransformNodeComponent::UpdateWorldTransform(v4);
    v5 = (UFG::qVector3 *)&v4->mWorldTransform.v3;
    v6 = UFG::Director::Get()->mCurrentCamera;
    if ( v6 )
      v7 = &v6->mCamera;
    else
      v7 = 0i64;
    v8 = UFG::Camera::GetViewProjection(v7);
    v9 = UFG::Camera::GetWorldView(v7);
    UFG::qMatrix44::operator*(v9, &result, v8);
    v10 = LODWORD(result.v2.z) ^ _xmm[0];
    LODWORD(v11) = COERCE_UNSIGNED_INT(result.v0.x + result.v0.w) ^ _xmm[0];
    LODWORD(v12) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.y) ^ _xmm[0];
    LODWORD(v13) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.y) ^ _xmm[0];
    LODWORD(v14) = COERCE_UNSIGNED_INT(result.v2.x + result.v2.w) ^ _xmm[0];
    LODWORD(v15) = COERCE_UNSIGNED_INT(result.v1.x + result.v1.w) ^ _xmm[0];
    vars0 = COERCE_UNSIGNED_INT(result.v1.y + result.v1.w) ^ _xmm[0];
    LODWORD(v16) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.x) ^ _xmm[0];
    LODWORD(v17) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.x) ^ _xmm[0];
    LODWORD(v55) = COERCE_UNSIGNED_INT(result.v2.y + result.v2.w) ^ _xmm[0];
    LODWORD(v18) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.x) ^ _xmm[0];
    LODWORD(v19) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.y) ^ _xmm[0];
    LODWORD(v20) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.z) ^ _xmm[0];
    LODWORD(v21) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.z) ^ _xmm[0];
    v22 = fsqrt(
            (float)((float)(COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0]))
                  + (float)(COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0])))
          + (float)(*(float *)&v10 * *(float *)&v10));
    result.v3.y = (float)(1.0 / v22) * COERCE_FLOAT(LODWORD(result.v2.x) ^ _xmm[0]);
    result.v2.z = (float)(1.0 / v22) * COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0]);
    result.v3.x = (float)(1.0 / v22) * *(float *)&v10;
    result.v2.w = (float)(1.0 / v22) * COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0]);
    v23 = fsqrt((float)((float)(v11 * v11) + (float)(v15 * v15)) + (float)(v14 * v14));
    LODWORD(v24) = COERCE_UNSIGNED_INT(result.v0.y + result.v0.w) ^ _xmm[0];
    result.v3.z = (float)(1.0 / v23) * v11;
    result.v3.w = (float)(1.0 / v23) * v15;
    v37 = (float)(1.0 / v23) * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v1.z + result.v2.y) ^ _xmm[0]);
    v36 = (float)(1.0 / v23) * v14;
    v25 = fsqrt((float)((float)(v17 * v17) + (float)(v16 * v16)) + (float)(v18 * v18));
    v41 = (float)(1.0 / v25) * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v2.y - result.v1.z) ^ _xmm[0]);
    v38 = (float)(1.0 / v25) * v16;
    v40 = (float)(1.0 / v25) * v18;
    v39 = (float)(1.0 / v25) * v17;
    v26 = (__m128)vars0;
    v26.m128_f32[0] = (float)((float)(v26.m128_f32[0] * v26.m128_f32[0]) + (float)(v24 * v24)) + (float)(v55 * v55);
    LODWORD(v27) = (unsigned __int128)_mm_sqrt_ps(v26);
    v42 = (float)(1.0 / v27) * v24;
    v44 = (float)(1.0 / v27) * v55;
    v43 = (float)(1.0 / v27) * *(float *)&vars0;
    v28 = (__m128)LODWORD(v13);
    v45 = (float)(1.0 / v27) * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v1.w + result.v2.y) ^ _xmm[0]);
    v28.m128_f32[0] = (float)((float)(v28.m128_f32[0] * v28.m128_f32[0]) + (float)(v19 * v19)) + (float)(v12 * v12);
    v29 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v28));
    v49 = v29 * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v2.y - result.v1.w) ^ _xmm[0]);
    v46 = v29 * v19;
    v47 = v29 * v13;
    v48 = v29 * v12;
    LODWORD(v30) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.z) ^ _xmm[0];
    v31 = v2->i_data.i_array_p;
    v32 = (__m128)LODWORD(v20);
    v32.m128_f32[0] = (float)((float)(v32.m128_f32[0] * v32.m128_f32[0]) + (float)(v30 * v30)) + (float)(v21 * v21);
    LODWORD(v33) = (unsigned __int128)_mm_sqrt_ps(v32);
    v53 = (float)(1.0 / v33) * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v2.y - result.v2.x) ^ _xmm[0]);
    v50 = (float)(1.0 / v33) * v20;
    v51 = (float)(1.0 / v33) * v30;
    v52 = (float)(1.0 / v33) * v21;
    v34 = IntersectSphereFrustum(
            (UFG::qVector4 *)((char *)&result.v2 + 8),
            v5,
            *(float *)&v31[1]->i_data_p->i_user_data);
    *v3 = (SSInstance *)SSBoolean::pool_new(v34 != 2);
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
    saved_mode_flag = 0;
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
  unsigned int v2; // ecx

  v2 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  JUMPOUT(v2, -1, UFG::WheeledVehicleManager::ResetMaxTrafficCars);
  UFG::WheeledVehicleManager::SetMaxTrafficCars(v2);
}

// File Line: 1244
// RVA: 0x4EE450
void __fastcall UFG::TSWorld::MthdC_set_max_parked_cars(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  unsigned int v2; // ecx

  v2 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  JUMPOUT(v2, -1, UFG::WheeledVehicleManager::ResetMaxParkedCars);
  UFG::WheeledVehicleManager::SetMaxParkedCars(v2);
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
  SSInstance **v2; // rbx
  UFG::ProgressionTracker *v3; // rax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = UFG::ProgressionTracker::Instance();
    *v2 = (SSInstance *)SSBoolean::pool_new(v3->mIsPossessedPedsEnabled);
  }
}

// File Line: 1295
// RVA: 0x4E3C50
void __fastcall UFG::TSWorld::MthdC_audio_set_music_state(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rdx
  SSInstance *v3; // rdi
  unsigned int v4; // ebx
  unsigned int v5; // eax

  v2 = pScope->i_data.i_array_p;
  v3 = v2[1]->i_data_p;
  v4 = UFG::TiDo::CalcWwiseUid(*(const char **)(*v2)->i_data_p->i_user_data);
  v5 = UFG::TiDo::CalcWwiseUid(*(const char **)v3->i_user_data);
  UFG::Music::SetMusicState(v4, v5);
}

// File Line: 1332
// RVA: 0x4E3B20
void __fastcall UFG::TSWorld::MthdC_audio_is_music_playing(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  int v3; // eax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = ((__int64 (*)(void))UFG::Music::sm_instance->vfptr->CountNumPlayingEvents)();
    *v2 = (SSInstance *)SSBoolean::pool_new(v3 != 0);
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
  UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&UFG::AmbienceAudio::m_instance->vfptr, v2, 0i64, 0, 0i64);
}

// File Line: 1377
// RVA: 0x4E3A70
void __fastcall UFG::TSWorld::MthdC_audio_ambience_rtpc(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rdx
  SSInstance *v3; // rdi
  SSInstance *v4; // rbx
  bool v5; // si
  unsigned int v6; // edx
  float v7; // xmm2_4

  v2 = pScope->i_data.i_array_p;
  v3 = (*v2)->i_data_p;
  v4 = v2[1]->i_data_p;
  v5 = v2[2]->i_data_p->i_user_data != 0;
  if ( (unsigned __int8)UFG::TiDo::GetIsInstantiated() )
  {
    v6 = UFG::TiDo::CalcWwiseUid(*(const char **)v3->i_user_data);
    v7 = *(float *)&v4->i_user_data;
    if ( v5 )
      UFG::TiDo::SetWwiseRtpcValue(UFG::TiDo::m_pInstance, v6, v7, 0xFFFFFFFFFFFFFFFFui64);
    else
      UFG::AudioEntity::SetRtpcValue((UFG::AudioEntity *)&UFG::AmbienceAudio::m_instance->vfptr, v6, v7);
  }
}

// File Line: 1397
// RVA: 0x4E3BA0
void __fastcall UFG::TSWorld::MthdC_audio_load_soundbank(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::qWiseSymbol result; // [rsp+40h] [rbp+8h]

  UFG::qWiseSymbol::create_from_string(&result, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  UFG::TiDo::GetInstance();
  UFG::TiDo::LoadWwiseBank(&result);
  _((AMD_HD3D *)result.mUID);
}

// File Line: 1411
// RVA: 0x4DA560
char __fastcall UFG::TSWorld::Coro_audio_load_soundbank(SSInvokedCoroutine *pScope, hkgpIndexedMeshDefinitions::Edge *a2)
{
  SSInvokedCoroutine *v2; // rbx
  bool v4; // bl
  UFG::qWiseSymbol result; // [rsp+48h] [rbp+10h]

  v2 = pScope;
  if ( Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat((hkgpIndexedMesh::EdgeBarrier *)pScope, a2) )
    return 1;
  UFG::qWiseSymbol::create_from_string(&result, *(const char **)(*v2->i_data.i_array_p)->i_data_p->i_user_data);
  if ( !v2->i_update_count )
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
  UFG::qWiseSymbol result; // [rsp+40h] [rbp+8h]

  UFG::qWiseSymbol::create_from_string(&result, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  v1 = UFG::SoundBankManager::BankLoadRequestFinished(&result);
  _((AMD_HD3D *)result.mUID);
  return v1;
}

// File Line: 1448
// RVA: 0x4DEB10
bool __fastcall UFG::TSWorld::Coro_wait_for_resources(SSInvokedCoroutine *pScope)
{
  unsigned int v1; // eax
  UFG::ProgressionTracker *v2; // rax

  v1 = pScope->i_update_count;
  if ( !v1 )
    return 0;
  if ( v1 == 1 )
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
  UFG::qWiseSymbol result; // [rsp+40h] [rbp+8h]

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
  ASymbol v9; // [rsp+20h] [rbp-18h]
  ASymbol v10; // [rsp+24h] [rbp-14h]
  float user_data; // [rsp+50h] [rbp+18h]
  ASymbol result; // [rsp+58h] [rbp+20h]

  v2 = (_QWORD *)((__int64 (__fastcall *)(SSActorClass *, SSInstance **))SkookumScript::c_world_class_p->vfptr->get_metaclass)(
                   SkookumScript::c_world_class_p,
                   ppResult);
  ASymbol::create(&result, "c_speed_walk", 0xFFFFFFFF, ATerm_long);
  *(float *)&v3 = UFG::GetNaturalMovementSpeed(eMoveType_Walk);
  v4 = SSInstance::pool_new(SSBrain::c_real_class_p, v3);
  v5 = v2[1];
  ++v2;
  (*(void (__fastcall **)(_QWORD *, ASymbol *, SSInstance *))(v5 + 40))(v2, &result, v4);
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
  unsigned int v2; // ecx

  v2 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  UFG::gEnableNavigationLoggingToFile = (v2 >> 1) & 1;
  UFG::gEnableNavigationLoggingToConsole = v2 & 1;
}

// File Line: 1614
// RVA: 0x4ECEC0
void __fastcall UFG::TSWorld::MthdC_section_is_3d(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  unsigned int v3; // eax
  unsigned int v4; // eax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = UFG::SectionChooser::GetCellIndexAtPosition(
           (UFG::qVector3 *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
           0);
    v4 = UFG::SectionLayout::GetFlags(v3);
    *v2 = (SSInstance *)SSBoolean::pool_new((v4 >> 1) & 1);
  }
}

// File Line: 1628
// RVA: 0x4ECD40
void __fastcall UFG::TSWorld::MthdC_section_get_name(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // r14
  unsigned int v3; // eax
  char *v4; // rax
  const char *v5; // rsi
  signed __int64 v6; // rbx
  unsigned int v7; // eax
  char v8; // di
  AString *v9; // rcx
  AStringRef *v10; // rbx
  bool v11; // zf
  AObjReusePool<AStringRef> *v12; // rax
  AObjBlock<AStringRef> *v13; // rcx
  unsigned __int64 v14; // rdx
  bool v15; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v16; // rcx
  AStringRef *v17; // rbx
  AObjReusePool<AStringRef> *v18; // rax
  AObjBlock<AStringRef> *v19; // rcx
  unsigned __int64 v20; // rdx
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v21; // rcx
  AString str; // [rsp+68h] [rbp+10h]
  AStringRef *elem; // [rsp+70h] [rbp+18h]

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = UFG::SectionChooser::GetCellIndexAtPosition(
           (UFG::qVector3 *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
           0);
    v4 = UFG::SectionLayout::GetSectionNameFromCellIndex(v3);
    v5 = v4;
    if ( v4 )
    {
      v6 = -1i64;
      do
        ++v6;
      while ( v4[v6] );
      v7 = AMemory::c_req_byte_size_func(v6 + 1);
      v8 = 1;
      elem = AStringRef::pool_new(v5, v6, v7, 1u, 0, 1);
      v9 = (AString *)&elem;
    }
    else
    {
      str.i_str_ref_p = AStringRef::get_empty();
      ++str.i_str_ref_p->i_ref_count;
      v9 = &str;
      v8 = 2;
    }
    *v2 = SSString::as_instance(v9);
    if ( v8 & 2 )
    {
      v8 &= 0xFDu;
      v10 = str.i_str_ref_p;
      v11 = str.i_str_ref_p->i_ref_count == 1;
      --v10->i_ref_count;
      if ( v11 )
      {
        if ( v10->i_deallocate )
          AMemory::c_free_func(v10->i_cstr_p);
        v12 = AStringRef::get_pool();
        v13 = v12->i_block_p;
        v14 = (unsigned __int64)v13->i_objects_a;
        if ( (unsigned __int64)v10 < v14
          || (v15 = (unsigned __int64)v10 < v14 + 24i64 * v13->i_size, v16 = &v12->i_pool, !v15) )
        {
          v16 = &v12->i_exp_pool;
        }
        APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v16, v10);
      }
    }
    if ( v8 & 1 )
    {
      v17 = elem;
      v11 = elem->i_ref_count == 1;
      --v17->i_ref_count;
      if ( v11 )
      {
        if ( v17->i_deallocate )
          AMemory::c_free_func(v17->i_cstr_p);
        v18 = AStringRef::get_pool();
        v19 = v18->i_block_p;
        v20 = (unsigned __int64)v19->i_objects_a;
        if ( (unsigned __int64)v17 < v20
          || (v15 = (unsigned __int64)v17 < v20 + 24i64 * v19->i_size, v21 = &v18->i_pool, !v15) )
        {
          v21 = &v18->i_exp_pool;
        }
        APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v21, v17);
      }
    }
  }
}

// File Line: 1642
// RVA: 0x4EA560
void __fastcall UFG::TSWorld::MthdC_last_used_vehicle_is_within_range(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // r8
  SSInstance **v3; // rbx
  char v4; // di
  float *v5; // rax
  float v6; // xmm9_4
  float v7; // xmm8_4
  float v8; // xmm10_4
  float v9; // xmm11_4
  UFG::GameStatTracker *v10; // rax
  UFG::GameStatTracker *v11; // rax
  UFG::GameStatTracker *v12; // rax
  float v13; // xmm7_4
  UFG::GameStatTracker *v14; // rax
  float v15; // xmm6_4
  UFG::GameStatTracker *v16; // rax
  float v17; // xmm0_4

  if ( ppResult )
  {
    v2 = pScope->i_data.i_array_p;
    v3 = ppResult;
    v4 = 0;
    v5 = (float *)(*v2)->i_data_p->i_user_data;
    v6 = *v5;
    v7 = v5[1];
    v8 = v5[2];
    v9 = *(float *)&v2[1]->i_data_p->i_user_data;
    v10 = UFG::GameStatTracker::Instance();
    if ( UFG::GameStatTracker::GetStat(v10, LastUsedVehicle)->mValue.mUID != -1 )
    {
      v11 = UFG::GameStatTracker::Instance();
      if ( (unsigned __int8)UFG::GameStatTracker::GetStat(v11, LastUsedVehicleIsCurrentlyUsed) )
      {
        v4 = 1;
      }
      else
      {
        v12 = UFG::GameStatTracker::Instance();
        v13 = UFG::GameStatTracker::GetStat(v12, LastUsedVehicleDismountLocationX);
        v14 = UFG::GameStatTracker::Instance();
        v15 = UFG::GameStatTracker::GetStat(v14, LastUsedVehicleDismountLocationY);
        v16 = UFG::GameStatTracker::Instance();
        v17 = UFG::GameStatTracker::GetStat(v16, LastUsedVehicleDismountLocationZ);
        v4 = (float)(v9 * v9) >= (float)((float)((float)((float)(v7 - v15) * (float)(v7 - v15))
                                               + (float)((float)(v6 - v13) * (float)(v6 - v13)))
                                       + (float)((float)(v8 - v17) * (float)(v8 - v17)));
      }
    }
    *v3 = (SSInstance *)SSBoolean::pool_new(v4);
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
  SSData **v1; // rdx
  unsigned int v2; // edi
  SSInstance *v3; // rcx
  float v4; // xmm7_4
  SSInstance *v5; // rsi
  float v6; // xmm6_4
  UFG::TimeOfDayManager *v7; // rax
  UFG::TimeOfDayManager *v8; // rbx
  float v9; // xmm3_4
  float v10; // xmm2_4
  float v11; // xmm4_4
  float v12; // xmm1_4
  UFG::qResourceInventory *v13; // rax
  UFG::qResourceWarehouse *v14; // rax

  v1 = pScope->i_data.i_array_p;
  v2 = (*v1)->i_data_p->i_user_data;
  v3 = v1[1]->i_data_p;
  v4 = *(float *)&v3->i_user_data;
  v5 = v1[2]->i_data_p;
  v6 = *(float *)&v3->i_user_data;
  v7 = UFG::TimeOfDayManager::GetInstance();
  v8 = v7;
  v9 = *(float *)&v5->i_user_data;
  v10 = 0.0;
  if ( v9 > 0.0 )
  {
    if ( v7->mOverrideStateBlockHandle.mNameUID == v2 )
      v11 = v7->m_OverrideStateBlockAmount;
    else
      v11 = 0.0;
    v6 = *(float *)&FLOAT_1_0;
    v12 = (float)((float)(UFG::Metrics::msRealTimeDelta_Accurate / v9) * (float)(v4 - v11)) + v11;
    if ( v12 < 0.0
      || (v10 = (float)((float)(UFG::Metrics::msRealTimeDelta_Accurate / v9) * (float)(v4 - v11)) + v11, v12 <= 1.0) )
    {
      v6 = v10;
    }
    *(float *)&v5->i_user_data = v9 - UFG::Metrics::msRealTimeDelta_Accurate;
  }
  v7->m_OverrideStateBlockAmount = v6;
  v13 = `UFG::qGetResourceInventory<Illusion::StateBlock>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::StateBlock>'::`2'::result )
  {
    v14 = UFG::qResourceWarehouse::Instance();
    v13 = UFG::qResourceWarehouse::GetInventory(v14, 0x4D04C7F2u);
    `UFG::qGetResourceInventory<Illusion::StateBlock>'::`2'::result = v13;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v8->mOverrideStateBlockHandle.mPrev, 0x4D04C7F2u, v2, v13);
  return v6 == v4;
}

// File Line: 1789
// RVA: 0x4E5370
void __fastcall UFG::TSWorld::MthdC_enable_vehicles_blip(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  SSData **v3; // r8
  bool v4; // si
  __int64 v5; // rax
  __int64 v6; // rax
  UFG::VehiclesBlipComponent *v7; // rcx
  UFG::qList<UFG::VehiclesBlipComponent,UFG::VehiclesBlipComponent,1,0> *v8; // rbx
  UFG::qString v9; // [rsp+38h] [rbp-30h]

  v2 = pScope;
  v3 = pScope->i_data.i_array_p;
  v4 = (*v3)->i_data_p->i_user_data != 0;
  UFG::VehiclesBlipComponent::mVehicleType.mUID = v3[1]->i_data_p->i_user_data;
  UFG::qString::qString(&v9, **(const char ***)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 2) + 8i64) + 32i64));
  UFG::qString::Set(&UFG::VehiclesBlipComponent::mBlipType, *(const char **)(v5 + 24), *(_DWORD *)(v5 + 20), 0i64, 0);
  UFG::qString::~qString(&v9);
  UFG::qString::qString(&v9, **(const char ***)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 3) + 8i64) + 32i64));
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
  UFG::PedSpawnManager *v2; // rax

  v2 = UFG::PedSpawnManager::GetInstance();
  UFG::PedSpawnManager::DisableProxyPeds(v2);
}

// File Line: 1824
// RVA: 0x4EDFB0
void __fastcall UFG::TSWorld::MthdC_set_hi_def_spawning(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  bool v2; // bl
  UFG::PedSpawnManager *v3; // rax

  v2 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  v3 = UFG::PedSpawnManager::GetInstance();
  UFG::PedSpawnManager::SetHighDefSpawning(v3, v2);
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
  UFG::SimObject *v2; // rcx

  v2 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v2 )
    UFG::SimObject::GetComponentOfType(v2, UFG::DebugCameraComponent::_TypeUID);
}

// File Line: 1865
// RVA: 0x4E50F0
void __fastcall UFG::TSWorld::MthdC_enable_proxy_peds(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::PedSpawnManager *v2; // rax

  v2 = UFG::PedSpawnManager::GetInstance();
  UFG::PedSpawnManager::EnableProxyPeds(v2);
}

// File Line: 1876
// RVA: 0x4EBC00
void __fastcall UFG::TSWorld::MthdC_rebalance_ambience(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::PedSpawnManager::msRequestEmergencyDump = 1;
}

// File Line: 1889
// RVA: 0x4E4C80
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
void __fastcall UFG::TSWorld::MthdC_delete_peds_from_deactivated_regions(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::PedSpawnManager *v2; // rax

  v2 = UFG::PedSpawnManager::GetInstance();
  UFG::PedSpawnManager::DeletePedsFromDeactivatedRegions(v2);
}

// File Line: 1946
// RVA: 0x4F2260
void __fastcall UFG::TSWorld::MthdC_spawn_zones_near_camera(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  float v2; // xmm6_4
  UFG::PedSpawnManager *v3; // rax

  v2 = *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v3 = UFG::PedSpawnManager::GetInstance();
  UFG::PedSpawnManager::SpawnZonesNearCamera(v3, v2);
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
  SSActor *v3; // rdi
  SSInstance **v4; // r15
  SSInvokedMethod *v5; // rbp
  SSClass *v6; // rbx
  SSActor *v7; // rbx
  SSClass *v8; // r14

  v2 = 0;
  v3 = (SSActor *)(*pScope->i_data.i_array_p)->i_data_p;
  v4 = ppResult;
  v5 = pScope;
  if ( !v3 )
    goto LABEL_22;
  v6 = v3->i_class_p;
  if ( v6->vfptr->is_actor_class((SSClassDescBase *)&v6->vfptr) )
    goto LABEL_7;
  if ( v6 == SSBrain::c_symbol_class_p && LODWORD(v3->i_user_data) != -1 )
    v3 = SSActor::find((ASymbol *)&v3->i_user_data);
  else
LABEL_22:
    v3 = 0i64;
LABEL_7:
  v7 = *(SSActor **)(*((_QWORD *)v5->i_data.i_array_p + 1) + 8i64);
  if ( !v7 )
    goto LABEL_12;
  v8 = v7->i_class_p;
  if ( !v8->vfptr->is_actor_class((SSClassDescBase *)&v8->vfptr) )
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
  if ( v3 )
  {
    if ( v7 )
    {
      if ( *(_QWORD *)&v3[1].i_icoroutines_to_update.i_count )
      {
        v2 = 0;
        if ( *(_QWORD *)&v7[1].i_icoroutines_to_update.i_count )
          v2 = 1;
      }
    }
  }
  if ( v4 )
    *v4 = (SSInstance *)SSBoolean::pool_new(v2);
}

// File Line: 2000
// RVA: 0x4DA9C0
char __fastcall UFG::TSWorld::Coro_find_character_spawn_position(SSInvokedCoroutine *pScope)
{
  SSData **v1; // r10
  SSInvokedCoroutine *v2; // rbx
  UFG::qVector3 *pResult; // ST20_8
  char result; // al
  SSData **v5; // rdx
  SSInstance *v6; // rcx
  float v7; // xmm0_4
  float v8; // xmm0_4

  v1 = pScope->i_data.i_array_p;
  v2 = pScope;
  pResult = (UFG::qVector3 *)v1[6]->i_data_p->i_user_data;
  if ( (unsigned __int8)UFG::SimObjectUtility::FindSpawnCharacterPosition(
                          (UFG::qVector3 *)(*v1)->i_data_p->i_user_data,
                          *(float *)&v1[1]->i_data_p->i_user_data,
                          *(float *)&v1[2]->i_data_p->i_user_data,
                          v1[3]->i_data_p->i_user_data != 0) )
  {
    *(_QWORD *)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 5) + 8i64) + 32i64) = 1i64;
    result = 1;
  }
  else
  {
    v5 = v2->i_data.i_array_p;
    v6 = v5[4]->i_data_p;
    v7 = *(float *)&v6->i_user_data;
    if ( v7 <= 0.0 || (v8 = v7 - UFG::Metrics::msInstance.mSimTimeDelta, *(float *)&v6->i_user_data = v8, v8 > 0.0) )
    {
      result = 0;
    }
    else
    {
      result = 1;
      v5[5]->i_data_p->i_user_data = 0i64;
    }
  }
  return result;
}

// File Line: 2038
// RVA: 0x4DAB60
char __fastcall UFG::TSWorld::Coro_find_vehicle_spawn_xform(SSInvokedCoroutine *pScope)
{
  SSData **v1; // rbx
  SSInvokedCoroutine *v2; // rdi
  int *index; // ST30_8
  bool canUseAlleyWay; // ST28_1
  char result; // al
  SSData **v6; // rdx
  SSInstance *v7; // rcx
  float v8; // xmm0_4
  float v9; // xmm0_4
  UFG::qMatrix44 m; // [rsp+40h] [rbp-48h]

  v1 = pScope->i_data.i_array_p;
  v2 = pScope;
  index = (int *)&v1[8]->i_data_p->i_user_data;
  canUseAlleyWay = v1[7]->i_data_p->i_user_data != 0;
  if ( (unsigned __int8)UFG::SimObjectUtility::FindSpawnVehicleTransformIterated(
                          (UFG::qVector3 *)(*v1)->i_data_p->i_user_data,
                          *(float *)&v1[1]->i_data_p->i_user_data,
                          *(float *)&v1[2]->i_data_p->i_user_data,
                          v1[3]->i_data_p->i_user_data != 0) )
  {
    UFG::TransformNodeComponent::SetWorldTransform(
      *(UFG::TransformNodeComponent **)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 6) + 8i64) + 32i64),
      &m);
    *(_QWORD *)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 5) + 8i64) + 32i64) = 1i64;
    result = 1;
  }
  else
  {
    v6 = v2->i_data.i_array_p;
    v7 = v6[4]->i_data_p;
    v8 = *(float *)&v7->i_user_data;
    if ( v8 <= 0.0 || (v9 = v8 - UFG::Metrics::msInstance.mSimTimeDelta, *(float *)&v7->i_user_data = v9, v9 > 0.0) )
    {
      result = 0;
    }
    else
    {
      result = 1;
      v6[5]->i_data_p->i_user_data = 0i64;
    }
  }
  return result;
}

// File Line: 2080
// RVA: 0x4DA8E0
char __fastcall UFG::TSWorld::Coro_find_boat_spawn_xform(SSInvokedCoroutine *pScope)
{
  SSData **v1; // r9
  SSInvokedCoroutine *v2; // rbx
  char result; // al
  SSData **v4; // rdx
  SSInstance *v5; // rcx
  float v6; // xmm0_4
  float v7; // xmm0_4
  UFG::qVector3 pos; // [rsp+30h] [rbp-18h]

  v1 = pScope->i_data.i_array_p;
  v2 = pScope;
  if ( UFG::SimObjectUtility::FindSpawnBoatPosition(
         (UFG::qVector3 *)(*v1)->i_data_p->i_user_data,
         *(float *)&v1[1]->i_data_p->i_user_data,
         *(float *)&v1[2]->i_data_p->i_user_data,
         v1[3]->i_data_p->i_user_data != 0,
         &pos) )
  {
    UFG::TransformNodeComponent::SetWorldTranslation(
      *(UFG::TransformNodeComponent **)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 6) + 8i64) + 32i64),
      &pos);
    *(_QWORD *)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 5) + 8i64) + 32i64) = 1i64;
    result = 1;
  }
  else
  {
    v4 = v2->i_data.i_array_p;
    v5 = v4[4]->i_data_p;
    v6 = *(float *)&v5->i_user_data;
    if ( v6 <= 0.0 || (v7 = v6 - UFG::Metrics::msInstance.mSimTimeDelta, *(float *)&v5->i_user_data = v7, v7 > 0.0) )
    {
      result = 0;
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
  UFG::qVector3 *v1; // rbx
  UFG::ProgressionTracker *v3; // rax

  if ( pScope->i_update_count )
    return (unsigned int)UFG::FlowController::GetCurrentState(&UFG::gFlowController) != uidGameStateChangeLocation_10;
  v1 = (UFG::qVector3 *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  if ( !v1 )
    return 1;
  v3 = UFG::ProgressionTracker::Instance();
  UFG::ProgressionTracker::ApplySceneSettings(v3, v1);
  return 0;
}

// File Line: 2141
// RVA: 0x4D9E10
bool __fastcall UFG::TSWorld::Coro_apply_scene_settings(SSInvokedCoroutine *pScope)
{
  SSData **v1; // rdx
  bool v2; // di
  bool v3; // si
  const char ***v4; // r8
  UFG::qSymbol *v5; // rbx
  UFG::ProgressionTracker *v6; // rax
  UFG::qBaseTreeRB *v7; // rax
  UFG::SceneSettings *v8; // rbx
  UFG::ProgressionTracker *v10; // rax
  UFG::qSymbol result; // [rsp+30h] [rbp+8h]

  if ( pScope->i_update_count )
    return (unsigned int)UFG::FlowController::GetCurrentState(&UFG::gFlowController) != uidGameStateChangeLocation_10;
  v1 = pScope->i_data.i_array_p;
  v2 = v1[1]->i_data_p->i_user_data != 0;
  v3 = v1[2]->i_data_p->i_user_data != 0;
  v4 = (const char ***)&(*v1)->i_data_p->i_user_data;
  if ( (*v1)->i_data_p == (SSInstance *)-32i64 || !*((_DWORD *)*v4 + 2) )
    return 1;
  v5 = UFG::qSymbol::create_from_string(&result, **v4);
  v6 = UFG::ProgressionTracker::Instance();
  v7 = UFG::ProgressionTracker::FindSceneSettings(v6, v5);
  v8 = (UFG::SceneSettings *)v7;
  if ( !v7 )
    return 1;
  BYTE5(v7->mNULL.mChild[1]) = v2;
  BYTE6(v7->mNULL.mChild[1]) = v3;
  v10 = UFG::ProgressionTracker::Instance();
  UFG::ProgressionTracker::ApplySceneSettings(v10, v8);
  return 0;
}

// File Line: 2178
// RVA: 0x4DAA90
char __fastcall UFG::TSWorld::Coro_find_random_sidewalk_position(SSInvokedCoroutine *pScope)
{
  SSData **v1; // r10
  SSInvokedCoroutine *v2; // rbx
  char result; // al
  SSData **v4; // rdx
  SSInstance *v5; // rcx
  float v6; // xmm0_4
  float v7; // xmm0_4

  v1 = pScope->i_data.i_array_p;
  v2 = pScope;
  if ( UFG::SimObjectUtility::FindRandomSidewalkPosition(
         (UFG::qVector3 *)(*v1)->i_data_p->i_user_data,
         *(float *)&v1[1]->i_data_p->i_user_data,
         *(float *)&v1[2]->i_data_p->i_user_data,
         v1[3]->i_data_p->i_user_data != 0,
         (UFG::qVector3 *)v1[6]->i_data_p->i_user_data) )
  {
    *(_QWORD *)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 5) + 8i64) + 32i64) = 1i64;
    result = 1;
  }
  else
  {
    v4 = v2->i_data.i_array_p;
    v5 = v4[4]->i_data_p;
    v6 = *(float *)&v5->i_user_data;
    if ( v6 <= 0.0 || (v7 = v6 - UFG::Metrics::msInstance.mSimTimeDelta, *(float *)&v5->i_user_data = v7, v7 > 0.0) )
    {
      result = 0;
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
  SSInvokedCoroutine *v1; // rbx
  SSData **v3; // rdx
  unsigned int *v4; // r8
  bool v5; // zf
  __m128 v6; // xmm2
  __m128 v7; // xmm3
  bool v8; // di
  unsigned int v9; // eax
  bool v10; // cl
  __m128 v11; // xmm1
  hkVector4f hkvClosestPointOut; // [rsp+30h] [rbp-48h]
  hkVector4f hkvPosition; // [rsp+40h] [rbp-38h]
  hkVector4f normalOut; // [rsp+50h] [rbp-28h]
  unsigned int meshUidOut; // [rsp+80h] [rbp+8h]

  v1 = pScope;
  if ( pScope->i_update_count < 0xA )
    return 0;
  v3 = pScope->i_data.i_array_p;
  v4 = (unsigned int *)(*v3)->i_data_p->i_user_data;
  v5 = v3[1]->i_data_p->i_user_data == 0;
  v6 = _mm_unpacklo_ps((__m128)v4[1], (__m128)0i64);
  v7 = _mm_unpacklo_ps((__m128)*v4, (__m128)v4[2]);
  hkvClosestPointOut.m_quad = 0i64;
  v8 = !v5;
  hkvPosition.m_quad = _mm_unpacklo_ps(v7, v6);
  v9 = UFG::HavokAIUtilGame::FindClosestMeshPosition2d(&hkvPosition, 0.2, 0.60000002, &hkvClosestPointOut, &meshUidOut);
  v10 = v9 != -1;
  if ( v9 != -1 && !v8 )
  {
    UFG::HavokAIUtilGame::getFaceNormal(v9, &normalOut);
    v11 = _mm_mul_ps(_xmm, normalOut.m_quad);
    v10 = (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 0)))
                + COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 170))) > cosf(0.34906587);
  }
  *(_QWORD *)(*(_QWORD *)(*((_QWORD *)v1->i_data.i_array_p + 2) + 8i64) + 32i64) = v10;
  return 1;
}

// File Line: 2253
// RVA: 0x4E8970
void __fastcall UFG::TSWorld::MthdC_get_stimulus_radius(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  int v3; // eax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = UFG::StimulusManager::GetStimulusType(*(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    *v2 = SSInstance::pool_new(SSBrain::c_real_class_p, *((unsigned int *)&unk_1423BF9C0 + 18 * v3));
  }
}

// File Line: 2267
// RVA: 0x4E40D0
void __fastcall UFG::TSWorld::MthdC_begin_stimulus_one_off_internal(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rdx
  unsigned __int64 v3; // rbx
  UFG::eStimulusType v4; // eax
  UFG::SimObject *v5; // r9
  UFG::StimulusParameters stimulus_parameters; // [rsp+20h] [rbp-28h]

  v2 = pScope->i_data.i_array_p;
  v3 = (*v2)->i_data_p->i_user_data;
  if ( v3 )
  {
    if ( v2[1]->i_data_p != (SSInstance *)-32i64 )
    {
      v4 = (unsigned int)UFG::StimulusManager::GetStimulusType(*(const char **)v2[1]->i_data_p->i_user_data);
      v5 = *(UFG::SimObject **)(v3 + 40);
      stimulus_parameters.m_StimulusProducerOffset = UFG::qVector3::msZero;
      stimulus_parameters.m_MaxStimulusDuration = -1.0;
      stimulus_parameters.m_EmitUntilSpeedLessThan = -1.0;
      stimulus_parameters.m_StimulusEmissionType = 0;
      UFG::StimulusManager::BeginStimulus(UFG::StimulusManager::s_pInstance, v4, &stimulus_parameters, v5);
    }
  }
}

// File Line: 2287
// RVA: 0x4E3F70
void __fastcall UFG::TSWorld::MthdC_begin_stimulus_duration_internal(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rdx
  unsigned __int64 v3; // rdi
  SSData *v4; // rax
  float *v5; // rbx
  UFG::eStimulusType v6; // eax
  UFG::SimObject *v7; // r9
  UFG::StimulusParameters stimulus_parameters; // [rsp+20h] [rbp-28h]

  v2 = pScope->i_data.i_array_p;
  v3 = (*v2)->i_data_p->i_user_data;
  v4 = v2[2];
  v5 = (float *)&v4->i_data_p->i_user_data;
  if ( v3 && v2[1]->i_data_p != (SSInstance *)-32i64 && v4->i_data_p != (SSInstance *)-32i64 )
  {
    v6 = (unsigned int)UFG::StimulusManager::GetStimulusType(*(const char **)v2[1]->i_data_p->i_user_data);
    v7 = *(UFG::SimObject **)(v3 + 40);
    stimulus_parameters.m_StimulusProducerOffset = UFG::qVector3::msZero;
    stimulus_parameters.m_StimulusEmissionType = 1;
    stimulus_parameters.m_MaxStimulusDuration = *v5;
    stimulus_parameters.m_EmitUntilSpeedLessThan = FLOAT_N1_0;
    UFG::StimulusManager::BeginStimulus(UFG::StimulusManager::s_pInstance, v6, &stimulus_parameters, v7);
  }
}

// File Line: 2308
// RVA: 0x4E4030
void __fastcall UFG::TSWorld::MthdC_begin_stimulus_internal(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rdx
  unsigned __int64 v3; // rbx
  UFG::eStimulusType v4; // eax
  UFG::SimObject *v5; // r9
  UFG::StimulusParameters stimulus_parameters; // [rsp+20h] [rbp-28h]

  v2 = pScope->i_data.i_array_p;
  v3 = (*v2)->i_data_p->i_user_data;
  if ( v3 )
  {
    if ( v2[1]->i_data_p != (SSInstance *)-32i64 )
    {
      v4 = (unsigned int)UFG::StimulusManager::GetStimulusType(*(const char **)v2[1]->i_data_p->i_user_data);
      v5 = *(UFG::SimObject **)(v3 + 40);
      stimulus_parameters.m_StimulusProducerOffset = UFG::qVector3::msZero;
      stimulus_parameters.m_MaxStimulusDuration = -1.0;
      stimulus_parameters.m_EmitUntilSpeedLessThan = -1.0;
      stimulus_parameters.m_StimulusEmissionType = 1;
      UFG::StimulusManager::BeginStimulus(UFG::StimulusManager::s_pInstance, v4, &stimulus_parameters, v5);
    }
  }
}

// File Line: 2327
// RVA: 0x4E5630
void __fastcall UFG::TSWorld::MthdC_end_stimulus_internal(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rdx
  unsigned __int64 v3; // rbx
  UFG::eStimulusType v4; // eax

  v2 = pScope->i_data.i_array_p;
  v3 = (*v2)->i_data_p->i_user_data;
  if ( v3 )
  {
    if ( v2[1]->i_data_p != (SSInstance *)-32i64 )
    {
      v4 = (unsigned int)UFG::StimulusManager::GetStimulusType(*(const char **)v2[1]->i_data_p->i_user_data);
      UFG::StimulusManager::EndStimulus(UFG::StimulusManager::s_pInstance, v4, *(UFG::SimObject **)(v3 + 40));
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
  SSInvokedCoroutine *v1; // rdi
  SSInstance *v2; // rbx
  UFG::qPropertySet *v3; // rsi
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
  char result; // al
  SSInstance *v15; // rbp
  __int64 v16; // rbx
  _DWORD *v17; // rcx
  UFG::ObjectResourceManager *v18; // rax
  UFG::qSymbol pSpawnName; // [rsp+50h] [rbp+8h]
  UFG::SceneLayer *ppLayer; // [rsp+58h] [rbp+10h]

  v1 = pScope;
  v2 = (*pScope->i_data.i_array_p)->i_data_p;
  pSpawnName.mUID = -1;
  v3 = UFG::TSWorld::get_spawn_info((SSInvokedContextBase *)&pScope->vfptr, 2u, &pSpawnName, &ppLayer);
  if ( v1->i_update_count )
  {
    *(float *)&v2->i_user_data = *(float *)&v2->i_user_data - UFG::Metrics::msInstance.mSimTimeDelta;
  }
  else
  {
    v4 = UFG::ObjectResourceManager::Instance();
    UFG::ObjectResourceManager::PreLoadCriticalResource(v4, v3);
  }
  v5 = UFG::ObjectResourceManager::Instance();
  if ( UFG::ObjectResourceManager::IsLoaded(v5, v3) )
  {
    v6 = *(UFG::TransformNodeComponent **)(*(_QWORD *)(*((_QWORD *)v1->i_data.i_array_p + 1) + 8i64) + 32i64);
    UFG::TransformNodeComponent::UpdateWorldTransform(v6);
    v7 = UFG::SpawnInfoInterface::SpawnObject(&pSpawnName, v3, &v6->mWorldTransform, 0, ppLayer, 0i64);
    v8 = UFG::ObjectResourceManager::Instance();
    UFG::ObjectResourceManager::ReleaseCriticalResource(v8, v3);
    v9 = SSInstance::pool_new(UFG::TSSimObject::mspSimObjectClass, (unsigned __int64)v7);
    v10 = *((_QWORD *)v1->i_data.i_array_p + 5);
    v11 = v9;
    v12 = *(_DWORD **)(v10 + 8);
    v13 = v12[4]-- == 1;
    if ( v13 )
    {
      v12[4] = 2147483648;
      (*(void (**)(void))(*(_QWORD *)v12 + 112i64))();
    }
    *(_QWORD *)(v10 + 8) = v11;
    result = 1;
  }
  else if ( *(float *)&v2->i_user_data > 0.0 )
  {
    result = 0;
  }
  else
  {
    v15 = SSBrain::c_nil_p;
    v16 = *((_QWORD *)v1->i_data.i_array_p + 5);
    v17 = *(_DWORD **)(v16 + 8);
    v13 = v17[4]-- == 1;
    if ( v13 )
    {
      v17[4] = 2147483648;
      (*(void (**)(void))(*(_QWORD *)v17 + 112i64))();
    }
    *(_QWORD *)(v16 + 8) = v15;
    v18 = UFG::ObjectResourceManager::Instance();
    UFG::ObjectResourceManager::ReleaseCriticalResource(v18, v3);
    result = 1;
  }
  return result;
}

// File Line: 2432
// RVA: 0x4E4170
void __fastcall UFG::TSWorld::MthdC_bind_enums(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSWorld::BindPhysicsObjectPropertiesToEnum();
}

// File Line: 2444
// RVA: 0x4E3380
void __fastcall UFG::TSWorld::MthdC_all_ai_update_attack_targets_now(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::AllAIUpdateAttackTargetsNow((UFG *)pScope);
}

// File Line: 2451
// RVA: 0x4E4B20
void __fastcall UFG::TSWorld::MthdC_disable_bullet_impacts(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::qBaseNodeRB *v2; // rax

  v2 = UFG::TSSimObject::GetArgByNameOrInstance((SSInvokedContextBase *)&pScope->vfptr, 0);
  if ( v2 )
    UFG::BulletManager::DisableBulletImpacts(UFG::BulletManager::mInstance, (UFG::SimObject *)v2);
}

// File Line: 2463
// RVA: 0x4E4CC0
void __fastcall UFG::TSWorld::MthdC_enable_bullet_impacts(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::qBaseNodeRB *v2; // rax

  v2 = UFG::TSSimObject::GetArgByNameOrInstance((SSInvokedContextBase *)&pScope->vfptr, 0);
  if ( v2 )
    UFG::BulletManager::EnableBulletImpacts(UFG::BulletManager::mInstance, (UFG::SimObject *)v2);
}

// File Line: 2482
// RVA: 0x4D95F0
void UFG::TSWorld::BindPhysicsObjectPropertiesToEnum(void)
{
  SSClass *v0; // rax
  SSClass *v1; // rbp
  unsigned int *v2; // rcx
  __int64 v3; // rax
  signed __int64 v4; // r8
  signed __int64 v5; // r10
  unsigned int **v6; // rdx
  unsigned int v7; // er9
  _BOOL8 v8; // r9
  unsigned int *v9; // rbx
  SSInstance *v10; // rdi
  bool v11; // zf
  const char *v12; // rax
  unsigned __int64 v13; // rbx
  UFG::qReflectWarehouse *v14; // rax
  UFG::qReflectInventoryBase *v15; // rax
  UFG::qTree64Base *v16; // r14
  UFG::qTree64Base *v17; // rax
  signed __int64 v18; // rsi
  __int64 v19; // rax
  signed __int64 v20; // rdx
  signed __int64 v21; // r9
  unsigned int v22; // er10
  unsigned int **v23; // rax
  unsigned int v24; // er8
  _BOOL8 v25; // r8
  unsigned int *v26; // rbx
  char *v27; // rax
  unsigned int v28; // eax
  SSInstance *v29; // rdi
  _DWORD *v30; // rcx
  UFG::qTree64Base *v31; // rax
  AStringRef *v32; // rbx
  AObjReusePool<AStringRef> *v33; // rax
  AObjBlock<AStringRef> *v34; // rcx
  unsigned __int64 v35; // rdx
  bool v36; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v37; // rcx
  char buffer_p; // [rsp+40h] [rbp-118h]
  AString v39; // [rsp+160h] [rbp+8h]

  v0 = SSBrain::get_class("ObjectPropertyType");
  v1 = v0->vfptr->get_key_class((SSClassDescBase *)&v0->vfptr);
  AString::AString(&v39, &buffer_p, 0x100u, 0, 0);
  v2 = (unsigned int *)_S15_2;
  if ( !(_S15_2 & 1) )
  {
    _S15_2 |= 1u;
    UFG::qSymbol::create_from_string(&enumInvalid, "invalid");
    atexit(UFG::TSWorld::BindPhysicsObjectPropertiesToEnum_::_2_::_dynamic_atexit_destructor_for__enumInvalid__);
  }
  v3 = v1->i_class_data.i_count;
  if ( !(_DWORD)v3 )
    goto LABEL_16;
  v4 = (signed __int64)v1->i_class_data.i_array_p;
  v5 = v4 + 8 * (v3 - 1);
  while ( 1 )
  {
    v6 = (unsigned int **)(v4 + 8 * ((v5 - v4) >> 4));
    v2 = *v6;
    v7 = **v6;
    if ( enumInvalid.mUID < v7 )
      goto LABEL_10;
    v2 = (unsigned int *)(enumInvalid.mUID == v7);
    v8 = enumInvalid.mUID != v7;
    if ( !v8 )
      break;
    if ( v8 < 0 )
    {
LABEL_10:
      if ( (unsigned int **)v4 == v6 )
        goto LABEL_16;
      v5 = (signed __int64)(v6 - 1);
    }
    else
    {
      if ( (unsigned int **)v5 == v6 )
        goto LABEL_16;
      v4 = (signed __int64)(v6 + 1);
    }
  }
  v9 = *v6;
  if ( *v6 )
  {
    v10 = SSInstance::pool_new(v1, 0xFFFFFFFFui64);
    ++v10->i_ref_count;
    v2 = (unsigned int *)*((_QWORD *)v9 + 2);
    v11 = v2[4]-- == 1;
    if ( v11 )
    {
      v2[4] = 2147483648;
      (*(void (**)(void))(*(_QWORD *)v2 + 112i64))();
    }
    *((_QWORD *)v9 + 2) = v10;
  }
LABEL_16:
  v12 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName((UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *)v2);
  v13 = UFG::qStringHash64(v12, 0xFFFFFFFFFFFFFFFFui64);
  v14 = UFG::qReflectWarehouse::Instance();
  v15 = UFG::qReflectWarehouse::GetInventory(v14, v13);
  v16 = &v15->mItems.mTree;
  v17 = UFG::qTree64Base::GetHead(&v15->mItems.mTree);
  if ( !v17 )
    goto LABEL_33;
  v18 = (signed __int64)&v17[-1].mCount;
  if ( v17 == (UFG::qTree64Base *)8 )
    goto LABEL_33;
  while ( 2 )
  {
    v19 = v1->i_class_data.i_count;
    if ( !(_DWORD)v19 )
      goto LABEL_31;
    v20 = (signed __int64)v1->i_class_data.i_array_p;
    v21 = v20 + 8 * (v19 - 1);
    v22 = *(_DWORD *)(v18 + 336);
    while ( 2 )
    {
      while ( 2 )
      {
        v23 = (unsigned int **)(v20 + 8 * ((v21 - v20) >> 4));
        v24 = **v23;
        if ( v22 < v24 )
        {
LABEL_25:
          if ( (unsigned int **)v20 == v23 )
            goto LABEL_31;
          v21 = (signed __int64)(v23 - 1);
          continue;
        }
        break;
      }
      v25 = v22 != v24;
      if ( v25 )
      {
        if ( v25 >= 0 )
        {
          if ( (unsigned int **)v21 == v23 )
            goto LABEL_31;
          v20 = (signed __int64)(v23 + 1);
          continue;
        }
        goto LABEL_25;
      }
      break;
    }
    v26 = *v23;
    if ( *v23 )
    {
      v27 = UFG::qReflectObject::GetName((UFG::qReflectObject *)v18);
      v28 = UFG::qStringHashUpper32(v27, 0xFFFFFFFF);
      v29 = SSInstance::pool_new(v1, v28);
      ++v29->i_ref_count;
      v30 = (_DWORD *)*((_QWORD *)v26 + 2);
      v11 = v30[4]-- == 1;
      if ( v11 )
      {
        v30[4] = 2147483648;
        (*(void (**)(void))(*(_QWORD *)v30 + 112i64))();
      }
      *((_QWORD *)v26 + 2) = v29;
    }
LABEL_31:
    v31 = UFG::qTree64Base::GetNext(v16, (UFG::qTree64Base::BaseNode *)(v18 + 8));
    if ( v31 )
    {
      v18 = (signed __int64)&v31[-1].mCount;
      if ( v31 != (UFG::qTree64Base *)8 )
        continue;
    }
    break;
  }
LABEL_33:
  v32 = v39.i_str_ref_p;
  v11 = v39.i_str_ref_p->i_ref_count == 1;
  --v32->i_ref_count;
  if ( v11 )
  {
    if ( v32->i_deallocate )
      AMemory::c_free_func(v32->i_cstr_p);
    v33 = AStringRef::get_pool();
    v34 = v33->i_block_p;
    v35 = (unsigned __int64)v34->i_objects_a;
    if ( (unsigned __int64)v32 < v35
      || (v36 = (unsigned __int64)v32 < v35 + 24i64 * v34->i_size, v37 = &v33->i_pool, !v36) )
    {
      v37 = &v33->i_exp_pool;
    }
    APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v37, v32);
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

  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "save",
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))UFG::CustomizeBindings::CustomizeComplete,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "vendor_extortion_hack",
    UFG::TSWorld::MthdC_vendor_extortion_hack,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "enable_spawning_parked_cars",
    UFG::TSWorld::MthdC_enable_spawning_parked_cars,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "get_location_name",
    UFG::TSWorld::MthdC_get_location_name,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "get_local_player",
    UFG::TSWorld::MthdC_get_local_player,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "set_max_traffic_cars",
    UFG::TSWorld::MthdC_set_max_traffic_cars,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "set_max_parked_cars",
    UFG::TSWorld::MthdC_set_max_parked_cars,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "add_road_block",
    UFG::TSWorld::MthdC_add_road_block,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "remove_road_block",
    UFG::TSWorld::MthdC_remove_road_block,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "is_simobject_existent",
    UFG::TSWorld::MthdC_is_simobject_existent,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "join_group",
    UFG::TSWorld::MthdC_join_group,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "enable_LOD_suppression",
    UFG::TSWorld::MthdC_enable_LOD_suppression,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "enable_vehicles_blip",
    UFG::TSWorld::MthdC_enable_vehicles_blip,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "set_hi_def_spawning",
    UFG::TSWorld::MthdC_set_hi_def_spawning,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "facial_animation_disable",
    UFG::TSWorld::MthdC_facial_animation_disable,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "debug_cam_fov",
    UFG::TSWorld::MthdC_debug_cam_fov,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "render_enable_exterior",
    UFG::TSWorld::MthdC_render_enable_exterior,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "render_parkour_handles",
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))_,
    1,
    0);
  SSClass::register_coroutine_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "_apply_scene_settings",
    UFG::TSWorld::Coro_apply_scene_settings,
    0);
  SSClass::register_coroutine_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "_apply_scene_settings_at_position",
    UFG::TSWorld::Coro_apply_scene_settings_at_position,
    0);
  SSClass::register_coroutine_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "_render_override_environment",
    UFG::TSWorld::Coro_render_override_environment,
    0);
  SSClass::register_coroutine_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "_render_override_environment_named",
    UFG::TSWorld::Coro_render_override_environment,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "capture_probes",
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))_,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "enable_decals",
    UFG::TSWorld::MthdC_enable_decals,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "enable_halfsize_aa",
    UFG::TSWorld::MthdC_enable_halfsize_aa,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "render_enable_water",
    UFG::TSWorld::MthdC_render_enable_water,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "section_is_3d",
    UFG::TSWorld::MthdC_section_is_3d,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "section_get_name",
    UFG::TSWorld::MthdC_section_get_name,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "last_used_vehicle_is_within_range",
    UFG::TSWorld::MthdC_last_used_vehicle_is_within_range,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "time_get",
    UFG::TSWorld::MthdC_time_get,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "time_set",
    UFG::TSWorld::MthdC_time_set,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "time_get_scale",
    UFG::TSWorld::MthdC_time_get_scale,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "time_set_scale",
    UFG::TSWorld::MthdC_time_set_scale,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "time_is_day",
    UFG::TSWorld::MthdC_time_is_day,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "enable_near_layer_transitions",
    UFG::TSWorld::MthdC_enable_near_layer_transitions,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "load_cloud_scene",
    UFG::TSWorld::MthdC_load_cloud_scene,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "unload_cloud_scene",
    UFG::TSWorld::MthdC_unload_cloud_scene,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "weather_is_raining",
    UFG::TSWorld::MthdC_weather_is_raining,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "weather_get_amount",
    UFG::TSWorld::MthdC_weather_get_amount,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "weather_set_amount",
    UFG::TSWorld::MthdC_weather_set_amount,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "weather_target",
    UFG::TSWorld::MthdC_weather_target,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "weather_lock",
    UFG::TSWorld::MthdC_weather_lock,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "weather_rain_chance",
    UFG::TSWorld::MthdC_weather_rain_chance,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "weather_randomize_interval",
    UFG::TSWorld::MthdC_weather_randomize_interval,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "weather_wetness_override",
    UFG::TSWorld::MthdC_weather_wetness_override,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "weather_set_wind",
    UFG::TSWorld::MthdC_weather_set_wind,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "weather_render_inside",
    UFG::TSWorld::MthdC_weather_render_inside,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "set_skydome",
    UFG::TSWorld::MthdC_set_skydome,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "release_skydome",
    UFG::TSWorld::MthdC_release_skydome,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "is_progression_subset_mode_active",
    UFG::TSWorld::MthdC_is_progression_subset_mode_active,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "set_progression_subset_mode",
    UFG::TSWorld::MthdC_set_progression_subset_mode,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "clear_progression_subset_mode",
    UFG::TSWorld::MthdC_clear_progression_subset_mode,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "audio_music_play",
    UFG::TSWorld::MthdC_audio_set_music_state,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "audio_set_music_state",
    UFG::TSWorld::MthdC_audio_set_music_state,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "audio_music_event",
    UFG::TSWorld::MthdC_audio_music_event,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "audio_ambience_event",
    UFG::TSWorld::MthdC_audio_ambience_event,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "audio_ambience_rtpc",
    UFG::TSWorld::MthdC_audio_ambience_rtpc,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "audio_load_soundbank",
    UFG::TSWorld::MthdC_audio_load_soundbank,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "audio_unload_soundbank",
    UFG::TSWorld::MthdC_audio_unload_soundbank,
    1,
    0);
  SSClass::register_coroutine_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "_audio_load_soundbank",
    UFG::TSWorld::Coro_audio_load_soundbank,
    0);
  SSClass::register_coroutine_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "_audio_wait_until_soundbank_loaded",
    UFG::TSWorld::Coro_audio_wait_until_soundbank_loaded,
    0);
  SSClass::register_coroutine_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "_wait_for_resources",
    UFG::TSWorld::Coro_wait_for_resources,
    0);
  SSClass::register_coroutine_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "_wait_until_in_game_state",
    UFG::TSWorld::Coro_wait_until_in_game_state,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "audio_enable_health_effects",
    UFG::TSWorld::MthdC_audio_enable_health_effects,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "audio_is_music_playing",
    UFG::TSWorld::MthdC_audio_is_music_playing,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "audio_set_listener_at_camera",
    UFG::TSWorld::MthdC_audio_set_listener_at_camera,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "audio_set_listener_at_player",
    UFG::TSWorld::MthdC_audio_set_listener_at_player,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "audio_set_trigger_point_at_camera",
    UFG::TSWorld::MthdC_audio_set_listener_at_camera,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "audio_set_trigger_point_at_player",
    UFG::TSWorld::MthdC_audio_set_listener_at_player,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "audio_lock_listener_position",
    UFG::TSWorld::MthdC_audio_lock_listener_position,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "audio_unlock_listener_position",
    UFG::TSWorld::MthdC_audio_unlock_listener_position,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "audio_listener_enable_high_speed",
    UFG::TSWorld::MthdC_audio_listener_enable_high_speed,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "audio_listener_disable_high_speed",
    UFG::TSWorld::MthdC_audio_listener_disable_high_speed,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "load_audio_resources_debug",
    UFG::TSWorld::MthdC_audio_load_resources_debug,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "unload_audio_resources_debug",
    UFG::TSWorld::MthdC_audio_unload_resources_debug,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "audio_setup_two_person_conversation",
    UFG::TSWorld::MthdC_audio_setup_two_person_conversation,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "init_constants",
    UFG::TSWorld::MthdC_init_constants,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "enable_navigation_logging",
    UFG::TSWorld::MthdC_enable_navigation_logging,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "enable_script_debugging",
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))_,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "delete_all_ambient_peds",
    UFG::TSWorld::MthdC_delete_all_ambient_peds,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "enable_all_ambient_peds",
    UFG::TSWorld::MthdC_enable_all_ambient_peds,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "dry_fire_near_spawn_zones",
    UFG::TSWorld::MthdC_dry_fire_near_spawn_zones,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "spawn_zones_near_camera",
    UFG::TSWorld::MthdC_spawn_zones_near_camera,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "disable_proxy_peds",
    UFG::TSWorld::MthdC_disable_proxy_peds,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "enable_proxy_peds",
    UFG::TSWorld::MthdC_enable_proxy_peds,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "rebalance_ambience",
    UFG::TSWorld::MthdC_rebalance_ambience,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "set_layer_active",
    UFG::TSWorld::MthdC_set_layer_active,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "get_layer_count",
    UFG::TSWorld::MthdC_get_layer_count,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "get_layer_name",
    UFG::TSWorld::MthdC_get_layer_name,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "delete_peds_from_deactivated_regions",
    UFG::TSWorld::MthdC_delete_peds_from_deactivated_regions,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "clean_up_free_weapons",
    UFG::TSWorld::MthdC_clean_up_free_weapons,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "set_simulation_timescale",
    UFG::TSMetrics_MthdC_simtime_set_scale,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "spawn_object",
    UFG::TSWorld::MthdC_spawn_object,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "spawn_object_at_xform",
    UFG::TSWorld::MthdC_spawn_object_at_xform,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "disable_bullet_impacts",
    UFG::TSWorld::MthdC_disable_bullet_impacts,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "enable_bullet_impacts",
    UFG::TSWorld::MthdC_enable_bullet_impacts,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "get_stimulus_radius",
    UFG::TSWorld::MthdC_get_stimulus_radius,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "begin_stimulus_one_off_internal",
    UFG::TSWorld::MthdC_begin_stimulus_one_off_internal,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "begin_stimulus_duration_internal",
    UFG::TSWorld::MthdC_begin_stimulus_duration_internal,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "begin_stimulus_internal",
    UFG::TSWorld::MthdC_begin_stimulus_internal,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "end_stimulus_internal",
    UFG::TSWorld::MthdC_end_stimulus_internal,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "enable_possessed_peds",
    UFG::TSWorld::MthdC_enable_possessed_peds,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "is_possessed_peds_enabled",
    UFG::TSWorld::MthdC_is_possessed_peds_enabled,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "enable_sidewalk_node",
    UFG::TSWorld::MthdC_enable_sidewalk_node,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "get_closest_sidewalk_position",
    UFG::TSWorld::MthdC_get_closest_sidewalk_position,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "run_script_test",
    UFG::TSWorld::MthdC_run_script_test,
    1,
    0);
  SSClass::register_coroutine_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "_find_character_spawn_position",
    UFG::TSWorld::Coro_find_character_spawn_position,
    0);
  SSClass::register_coroutine_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "_find_vehicle_spawn_xform",
    UFG::TSWorld::Coro_find_vehicle_spawn_xform,
    0);
  SSClass::register_coroutine_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "_find_boat_spawn_xform",
    UFG::TSWorld::Coro_find_boat_spawn_xform,
    0);
  SSClass::register_coroutine_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "_find_random_sidewalk_position",
    UFG::TSWorld::Coro_find_random_sidewalk_position,
    0);
  SSClass::register_coroutine_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "_is_position_on_navmesh",
    UFG::TSWorld::Coro_is_position_on_navmesh,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "reset_taxi_occupancy",
    UFG::TSWorld::MthdC_reset_taxi_occupancy,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "set_all_taxis_occupied",
    UFG::TSWorld::MthdC_set_all_taxis_occupied,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "set_transit_targeting_enabled",
    UFG::TSWorld::MthdC_set_transit_targeting_enabled,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "enable_light_layer",
    UFG::TSWorld::MthdC_enable_light_layer,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "enable_streaming_lookahead",
    UFG::TSWorld::MthdC_enable_streaming_lookahead,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "is_xform_in_view",
    UFG::TSWorld::MthdC_is_xform_in_view,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "set_input_camera_only",
    UFG::TSWorld::MthdC_set_input_camera_only,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "trophy_reward",
    UFG::TSWorld::MthdC_trophy_reward,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "print_snapshot",
    UFG::TSWorld::MthdC_print_snapshot,
    1,
    0);
  SSClass::register_coroutine_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "_spawn_object_at_xform",
    (bool (__fastcall *)(SSInvokedCoroutine *))UFG::TSWorld::Coro_spawn_object_at_xform,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "set_hijack_vehicle_price",
    UFG::TSWorld::MthdC_set_hijack_vehicle_price,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "bind_enums",
    UFG::TSWorld::MthdC_bind_enums,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "all_ai_update_attack_targets_now",
    UFG::TSWorld::MthdC_all_ai_update_attack_targets_now,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "on_launch_chunk_gameplay_completion",
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))_,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "set_volumetric_fog_intensity",
    UFG::TSWorld::MthdC_set_volumetric_fog_intensity,
    1,
    0);
  PhysicsSkookum::RegisterMethods();
  UFG::TSMetrics_BindAtomics(v0);
}

