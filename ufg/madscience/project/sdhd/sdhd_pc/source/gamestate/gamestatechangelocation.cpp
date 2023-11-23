// File Line: 79
// RVA: 0x410400
void __fastcall UFG::GameStateChangeLocation::OnEnter(UFG::GameStateChangeLocation *this, float deltaSeconds)
{
  UFG::ProgressionTracker *v3; // rax
  UFG::SceneSettings *p_mPendingSceneSettingsLocal; // rdi
  UFG::ProgressionTracker *v5; // rax
  UFG::TiDo *Instance; // rax
  UFG::TiDo *v7; // rax
  UFG::qWiseSymbol result; // [rsp+50h] [rbp+18h] BYREF
  UFG::qWiseSymbol source; // [rsp+58h] [rbp+20h] BYREF

  v3 = UFG::ProgressionTracker::Instance();
  if ( !v3->mbPendingSceneSettingsValid
    || (p_mPendingSceneSettingsLocal = &v3->mPendingSceneSettingsLocal, v3 == (UFG::ProgressionTracker *)-5648i64) )
  {
    this->mSavedAmbientSpawningSetting = UFG::PedSpawnManager::msAmbientSpawningEnable;
    UFG::PedSpawnManager::msAmbientSpawningEnable = 0;
    UFG::PedSpawnManager::msCheckStatusMode = 1;
    goto LABEL_15;
  }
  v5 = UFG::ProgressionTracker::Instance();
  UFG::ProgressionTracker::SetResourceFreezeMode(v5, 1);
  UFG::StreamFileWrapper::SetQueueMode(QUEUE_MODE_SEEK_MINIMIZE);
  _((AMD_HD3D *)1);
  if ( !p_mPendingSceneSettingsLocal->mShowCurtains )
  {
LABEL_15:
    this->mLoadStage = eLS_APPLY_CHANGES;
    return;
  }
  UFG::qWiseSymbol::create_from_string(&result, "loadstart");
  this->mLoadStage = eLS_WAIT_FOR_CURTAINS;
  UFG::qWiseSymbol::create_from_string(&source, "loadfinish");
  UFG::qWiseSymbol::operator=(&stru_14207B268, &source);
  if ( byte_14207B260 != 1 )
  {
    UFG::qWiseSymbol::operator=(&stru_14207B264, &result);
    if ( (_BYTE)word_14207B26C )
    {
      if ( byte_14207B260 && UFG::TiDo::GetIsInstantiated() )
      {
        Instance = UFG::TiDo::GetInstance();
        Instance->vfptr->LoadingGameEnd(Instance, &stru_14207B268);
      }
      if ( (_BYTE)word_14207B26C )
      {
        UFG::qWiseSymbol::operator=(&stru_14207B264, &result);
        if ( UFG::TiDo::GetIsInstantiated() )
        {
          v7 = UFG::TiDo::GetInstance();
          v7->vfptr->LoadingGameStart(v7, &stru_14207B264);
        }
      }
    }
    byte_14207B260 = 1;
  }
  UFG::UIHK_NISOverlay::ShowCurtains(0.0, 1);
  _((AMD_HD3D *)source.mUID);
  _((AMD_HD3D *)result.mUID);
}

// File Line: 110
// RVA: 0x410D90
void __fastcall UFG::GameStateChangeLocation::OnExit(UFG::GameStateChangeLocation *this, float deltaSeconds)
{
  UFG::ProgressionTracker *v2; // rax
  UFG::SceneSettings *p_mPendingSceneSettingsLocal; // rax
  UFG::ProgressionTracker *v4; // rax

  UFG::WheeledVehicleManager::OnChangeLocationFinished(UFG::WheeledVehicleManager::m_Instance);
  v2 = UFG::ProgressionTracker::Instance();
  if ( v2->mbPendingSceneSettingsValid )
  {
    p_mPendingSceneSettingsLocal = &v2->mPendingSceneSettingsLocal;
    if ( p_mPendingSceneSettingsLocal )
    {
      if ( p_mPendingSceneSettingsLocal->mHideCurtains )
      {
        ((void (__fastcall *)(UFG::TiDo *, __int64))UFG::TiDo::m_pInstance->vfptr[1].Close)(
          UFG::TiDo::m_pInstance,
          4i64);
        UFG::UIHK_NISOverlay::HideCurtains(1.0, 0);
      }
      v4 = UFG::ProgressionTracker::Instance();
      v4->mbPendingSceneSettingsValid = 0;
      UFG::SceneSettings::Reset(&v4->mPendingSceneSettingsLocal);
    }
  }
}

// File Line: 126
// RVA: 0x4117F0
void __fastcall UFG::GameStateChangeLocation::OnPreUpdate(UFG::GameStateRestoreCheckpoint *this, float deltaSeconds)
{
  UFG::ProgressionTracker *v2; // rax

  PoseTaskSubmission::BeginFrame();
  v2 = UFG::ProgressionTracker::Instance();
  UFG::ProgressionTracker::Update(v2, deltaSeconds);
}

// File Line: 131
// RVA: 0x411DA0
void __fastcall UFG::GameStateChangeLocation::OnUpdate(UFG::GameStateChangeLocation *this, float deltaSeconds)
{
  UFG::ProgressionTracker *v3; // rax
  int BytesRemainingToLoad; // ebx
  UFG::ObjectResourceManager *v5; // rax
  int v6; // ebx
  UFG::PartDatabase *v7; // rax
  int v8; // ebx
  int v9; // eax
  UFG::TriggerUpdateContext *TriggerUpdateContext; // rax
  UFG::GeographicalLayerManager *Instance; // rax
  UFG::qVector3 *LayerLoadPosition; // rbx
  UFG::GeographicalLayerManager *v13; // rax
  UFG::PropSpawnManager *v14; // rax
  UFG::ObjectResourceManager *v15; // rax
  UFG::PartDatabase *v16; // rax
  UFG::ObjectResourceManager *v17; // rax
  UFG::ObjectResourceManager *v18; // rax
  int v19; // ebx
  int v20; // eax
  UFG::TriggerUpdateContext *v21; // rax
  UFG::GeographicalLayerManager *v22; // rax
  UFG::qVector3 *v23; // rbx
  UFG::GeographicalLayerManager *v24; // rax
  UFG::PropSpawnManager *v25; // rax
  UFG::ObjectResourceManager *v26; // rax
  UFG::PartDatabase *v27; // rax
  UFG::ProgressionTracker *v28; // rax
  UFG::SceneSettings *p_mPendingSceneSettingsLocal; // rcx
  bool mEnableAmbientPedsOnEnd; // al
  bool v31; // al
  bool mSavedAmbientSpawningSetting; // al
  UFG::SimObjectCharacter *LocalPlayer; // rax
  AMD_HD3D *v34; // rcx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  int CurrentState; // eax
  UFG::qVector3 velocity; // [rsp+40h] [rbp-68h] BYREF
  UFG::qVector3 v38; // [rsp+50h] [rbp-58h] BYREF
  UFG::TriggerUpdateContext result; // [rsp+60h] [rbp-48h] BYREF
  UFG::TriggerUpdateContext v40; // [rsp+78h] [rbp-30h] BYREF

  switch ( this->mLoadStage )
  {
    case eLS_WAIT_FOR_CURTAINS:
      if ( UFG::UIHK_NISOverlay::IsCurtainStable() )
        this->mLoadStage = eLS_APPLY_CHANGES;
      goto LABEL_29;
    case eLS_APPLY_CHANGES:
      UFG::SectionChooser::EnableStreamsUpdate(1);
      v3 = UFG::ProgressionTracker::Instance();
      if ( v3->mbPendingSceneSettingsValid && v3 != (UFG::ProgressionTracker *)-5648i64 )
        UFG::GameStateChangeLocation::ApplyChanges(this, deltaSeconds);
      this->mLoadStage = eLS_SETLOADING_HINT;
      goto LABEL_29;
    case eLS_SETLOADING_HINT:
      BytesRemainingToLoad = UFG::SectionChooser::GetBytesRemainingToLoad();
      v5 = UFG::ObjectResourceManager::Instance();
      v6 = UFG::ObjectResourceManager::GetBytesRemainingToLoad(v5) + BytesRemainingToLoad;
      v7 = UFG::PartDatabase::Instance();
      v8 = UFG::PartDatabase::GetBytesRemainingToLoad(v7) + v6;
      v9 = UFG::SoundBankManager::GetBytesRemainingToLoad();
      UFG::LoadingLogic::SetLoadLengthHint(&UFG::gLoadingLogic, v9 + v8);
      this->mLoadStage = eLS_LOCATION_PENDING;
      goto LABEL_29;
    case eLS_LOCATION_PENDING:
      if ( UFG::LoadingLogic::IsComplete(&UFG::gLoadingLogic, 4) && UFG::UpdateRigs(0x64u) )
        this->mLoadStage = eLS_LAYERS_PENDING;
      goto LABEL_29;
    case eLS_LAYERS_PENDING:
      TriggerUpdateContext = UFG::GetTriggerUpdateContext(&result);
      UFG::TriggerRegion::UpdateAll(TriggerUpdateContext);
      Instance = UFG::GeographicalLayerManager::GetInstance();
      UFG::GeographicalLayerManager::ClearDeactivationTimers(Instance);
      LayerLoadPosition = UFG::GetLayerLoadPosition(&velocity);
      v13 = UFG::GeographicalLayerManager::GetInstance();
      LOBYTE(LayerLoadPosition) = UFG::GeographicalLayerManager::Update(v13, deltaSeconds, LayerLoadPosition);
      LOBYTE(LayerLoadPosition) = UFG::IncrementalActivateManager::Flush() | (unsigned __int8)LayerLoadPosition;
      LOBYTE(LayerLoadPosition) = UFG::WheeledVehicleManager::UpdateTrafficSet(UFG::WheeledVehicleManager::m_Instance) | (unsigned __int8)LayerLoadPosition;
      UFG::PedSpawnManager::Update(UFG::gpPedSpawnManager, deltaSeconds);
      v14 = UFG::PropSpawnManager::GetInstance();
      UFG::PropSpawnManager::Update(v14);
      v15 = UFG::ObjectResourceManager::Instance();
      UFG::ObjectResourceManager::Update(v15, deltaSeconds);
      v16 = UFG::PartDatabase::Instance();
      UFG::PartDatabase::Update(v16, deltaSeconds);
      UFG::StoreMeshHelper::Update();
      if ( !(_BYTE)LayerLoadPosition )
      {
        v17 = UFG::ObjectResourceManager::Instance();
        UFG::ObjectResourceManager::PopulateAmbience(v17);
        v18 = UFG::ObjectResourceManager::Instance();
        v19 = UFG::ObjectResourceManager::GetBytesRemainingToLoad(v18);
        v20 = UFG::SoundBankManager::GetBytesRemainingToLoad();
        UFG::LoadingLogic::SetLoadLengthHint(&UFG::gLoadingLogic, v20 + v19);
        this->mLoadStage = eLS_CHARACTER_AND_VEHICLE_RESOURCE_PENDING;
      }
      goto LABEL_29;
    case eLS_CHARACTER_AND_VEHICLE_RESOURCE_PENDING:
      v21 = UFG::GetTriggerUpdateContext(&v40);
      UFG::TriggerRegion::UpdateAll(v21);
      v22 = UFG::GeographicalLayerManager::GetInstance();
      UFG::GeographicalLayerManager::ClearDeactivationTimers(v22);
      v23 = UFG::GetLayerLoadPosition(&v38);
      v24 = UFG::GeographicalLayerManager::GetInstance();
      UFG::GeographicalLayerManager::Update(v24, deltaSeconds, v23);
      UFG::IncrementalActivateManager::Flush();
      UFG::WheeledVehicleManager::UpdateTrafficSet(UFG::WheeledVehicleManager::m_Instance);
      UFG::PedSpawnManager::Update(UFG::gpPedSpawnManager, deltaSeconds);
      v25 = UFG::PropSpawnManager::GetInstance();
      UFG::PropSpawnManager::Update(v25);
      v26 = UFG::ObjectResourceManager::Instance();
      UFG::ObjectResourceManager::Update(v26, deltaSeconds);
      v27 = UFG::PartDatabase::Instance();
      UFG::PartDatabase::Update(v27, deltaSeconds);
      UFG::StoreMeshHelper::Update();
      if ( UFG::LoadingLogic::IsComplete(&UFG::gLoadingLogic, 3)
        && UFG::SoundBankManager::AreAllImportantBankLoadsComplete()
        && !UFG::StoreMeshHelper::SwapInProgress() )
      {
        this->mLoadStage = eLS_APPLY_SPAWN_SETTINGS;
      }
      goto LABEL_29;
    case eLS_APPLY_SPAWN_SETTINGS:
      v28 = UFG::ProgressionTracker::Instance();
      if ( !v28->mbPendingSceneSettingsValid
        || (p_mPendingSceneSettingsLocal = &v28->mPendingSceneSettingsLocal, v28 == (UFG::ProgressionTracker *)-5648i64) )
      {
        mSavedAmbientSpawningSetting = this->mSavedAmbientSpawningSetting;
        UFG::PedSpawnManager::msCheckStatusMode = 1;
        UFG::PedSpawnManager::msAmbientSpawningEnable = mSavedAmbientSpawningSetting;
        v31 = this->mSavedAmbientSpawningSetting;
      }
      else
      {
        if ( sAmbientPedEnableLocked )
          goto LABEL_24;
        mEnableAmbientPedsOnEnd = v28->mPendingSceneSettingsLocal.mEnableAmbientPedsOnEnd;
        UFG::PedSpawnManager::msCheckStatusMode = 1;
        UFG::PedSpawnManager::msAmbientSpawningEnable = mEnableAmbientPedsOnEnd;
        v31 = p_mPendingSceneSettingsLocal->mEnableAmbientPedsOnEnd;
      }
      UFG::PedSpawnManager::msAmbientStatusCheckEnable = v31;
LABEL_24:
      UFG::PedSpawnManager::msScriptedStatusCheckEnable = 1;
      UFG::PedSpawnManager::RestoreAllScriptedToFullyActive(UFG::gpPedSpawnManager);
      this->mLoadStage = eLS_WAIT_FOR_SPAWNER;
LABEL_29:
      if ( this->mLoadStage > eLS_APPLY_CHANGES )
      {
        LocalPlayer = UFG::GetLocalPlayer();
        if ( LocalPlayer )
        {
          m_pTransformNodeComponent = LocalPlayer->m_pTransformNodeComponent;
          UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
          UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
          *(_QWORD *)&velocity.x = 0i64;
          velocity.z = 0.0;
          CurrentState = UFG::FlowController::GetCurrentState(&UFG::gFlowController);
          UFG::SectionChooser::AddPOV(
            (UFG::qVector3 *)&m_pTransformNodeComponent->mWorldTransform.v3,
            (UFG::qVector3 *)&m_pTransformNodeComponent->mWorldTransform,
            (UFG::qVector3 *)&m_pTransformNodeComponent->mWorldTransform,
            &velocity,
            deltaSeconds,
            0i64,
            7,
            CurrentState == uidGameStateInGame_3);
        }
        UFG::UpdateCamera(deltaSeconds, v34);
      }
      return;
    case eLS_WAIT_FOR_SPAWNER:
      UFG::PedSpawnManager::Update(UFG::gpPedSpawnManager, deltaSeconds);
      if ( !UFG::PedSpawnManager::SpawnsQueued() )
        this->mLoadStage = eLS_WAIT_FOR_POI_ANIMATIONS;
      goto LABEL_29;
    case eLS_WAIT_FOR_POI_ANIMATIONS:
      if ( UFG::LoadingLogic::IsComplete(&UFG::gLoadingLogic, 3) )
      {
        UFG::FlowController::RequestSetNewState(&UFG::gFlowController, uidGameStateInGame_3);
        this->mLoadStage = eLS_EXIT;
      }
      goto LABEL_29;
    default:
      goto LABEL_29;
  }
}

// File Line: 304
// RVA: 0x411420
void __fastcall UFG::GameStateRestoreCheckpoint::OnPostUpdate(
        UFG::GameStateRestoreCheckpoint *this,
        float deltaSeconds)
{
  UFG::LoadingLogic::OnPostUpdate(&UFG::gLoadingLogic, deltaSeconds);
}

// File Line: 309
// RVA: 0x407940
void __fastcall UFG::GameStateChangeLocation::ApplyChanges(UFG::GameStateChangeLocation *this, float deltaSeconds)
{
  UFG::ProgressionTracker *v2; // rax
  UFG::Event *v3; // rsi
  UFG::SceneSettings *p_mPendingSceneSettingsLocal; // rdi
  UFG::qSymbol *p_mTeleportMarker; // rcx
  UFG::qBaseTreeRB *Named; // rax
  UFG::TransformNodeComponent *mParent; // rbx
  UFG::qVector4 v8; // xmm2
  UFG::qVector4 v9; // xmm1
  UFG::qVector4 v10; // xmm0
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::SimObjectCharacter *LocalPlayer; // rbx
  UFG::allocator::free_link *v14; // rax
  UFG::Event *v15; // rax
  UFG::SimComponent *m_pComponent; // rax
  UFG::ProgressionTracker *v17; // rax
  UFG::ProgressionTracker *v18; // rax
  UFG::TimeOfDayManager *Instance; // rax
  UFG::TimeOfDayManager *v20; // rbx
  float mTimeOverrideInSeconds; // xmm1_4
  float v22; // xmm1_4
  float mWeatherOverrideIntensity; // xmm1_4
  float v24; // xmm0_4
  float mWeatherOverrideWetness; // xmm1_4
  UFG::ProgressionTracker *v26; // rax
  UFG::qMatrix44 worldXform; // [rsp+38h] [rbp+7h] BYREF

  v2 = UFG::ProgressionTracker::Instance();
  v3 = 0i64;
  p_mPendingSceneSettingsLocal = &v2->mPendingSceneSettingsLocal;
  if ( !v2->mbPendingSceneSettingsValid )
    p_mPendingSceneSettingsLocal = 0i64;
  worldXform = UFG::qMatrix44::msIdentity;
  p_mTeleportMarker = &p_mPendingSceneSettingsLocal->mTeleportMarker;
  if ( p_mPendingSceneSettingsLocal->mTeleportMarker.mUID == -1 )
  {
    if ( !p_mPendingSceneSettingsLocal->mHasTeleportPositionInternal )
      goto LABEL_22;
    y = p_mPendingSceneSettingsLocal->mTeleportPositionInternal.y;
    z = p_mPendingSceneSettingsLocal->mTeleportPositionInternal.z;
    worldXform.v3.x = p_mPendingSceneSettingsLocal->mTeleportPositionInternal.x;
    worldXform.v3.y = y;
    worldXform.v3.z = z;
    worldXform.v3.w = 1.0;
  }
  else
  {
    Named = UFG::MarkerBase::GetNamed(p_mTeleportMarker);
    if ( !Named )
      goto LABEL_22;
    mParent = (UFG::TransformNodeComponent *)Named[1].mNULL.mParent;
    UFG::TransformNodeComponent::UpdateWorldTransform(mParent);
    v8 = mParent->mWorldTransform.v1;
    v9 = mParent->mWorldTransform.v2;
    v10 = mParent->mWorldTransform.v3;
    worldXform.v0 = mParent->mWorldTransform.v0;
    worldXform.v1 = v8;
    worldXform.v2 = v9;
    worldXform.v3 = v10;
  }
  LocalPlayer = UFG::GetLocalPlayer();
  if ( LocalPlayer )
  {
    v14 = UFG::qMalloc(0x90ui64, "NISManager", 0i64);
    if ( v14 )
    {
      UFG::TeleportEvent::TeleportEvent(
        (UFG::TeleportEvent *)v14,
        &worldXform,
        LocalPlayer->mNode.mUID,
        0,
        UFG::TeleportEvent::m_Name,
        0);
      v3 = v15;
    }
    UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v3);
    p_mTeleportMarker = (UFG::qSymbol *)LocalPlayer->m_Flags;
    if ( ((unsigned __int16)p_mTeleportMarker & 0x4000) != 0 )
    {
      m_pComponent = LocalPlayer->m_Components.p[7].m_pComponent;
    }
    else if ( (__int16)p_mTeleportMarker >= 0 )
    {
      if ( ((unsigned __int16)p_mTeleportMarker & 0x2000) != 0 )
      {
        m_pComponent = LocalPlayer->m_Components.p[6].m_pComponent;
      }
      else if ( ((unsigned __int16)p_mTeleportMarker & 0x1000) != 0 )
      {
        m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(LocalPlayer, UFG::ActionTreeComponent::_TypeUID);
      }
      else
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(LocalPlayer, UFG::ActionTreeComponent::_TypeUID);
      }
    }
    else
    {
      m_pComponent = LocalPlayer->m_Components.p[7].m_pComponent;
    }
    if ( m_pComponent )
      ActionController::Stop((ActionController *)&m_pComponent[3]);
  }
LABEL_22:
  if ( p_mPendingSceneSettingsLocal->mVehicleTeleportMarker.mUID != -1 )
  {
    v17 = UFG::ProgressionTracker::Instance();
    UFG::ProgressionTracker::TeleportVehicle(v17, p_mPendingSceneSettingsLocal);
  }
  if ( p_mPendingSceneSettingsLocal->mVehicleDestroy )
  {
    v18 = UFG::ProgressionTracker::Instance();
    UFG::ProgressionTracker::DestroyVehicle(v18);
  }
  UFG::UpdateCamera(1.0, (AMD_HD3D *)p_mTeleportMarker);
  Instance = UFG::TimeOfDayManager::GetInstance();
  v20 = Instance;
  mTimeOverrideInSeconds = p_mPendingSceneSettingsLocal->mTimeOverrideInSeconds;
  if ( mTimeOverrideInSeconds >= 0.0 )
    UFG::TimeOfDayManager::SetTime(Instance, mTimeOverrideInSeconds, 0);
  if ( p_mPendingSceneSettingsLocal->mTimeOverrideLockSet )
  {
    if ( p_mPendingSceneSettingsLocal->mTimeOverrideLock )
      v22 = 0.0;
    else
      v22 = FLOAT_40_0;
    TimePlotPoint::SetTimeValue(v20, v22);
  }
  mWeatherOverrideIntensity = p_mPendingSceneSettingsLocal->mWeatherOverrideIntensity;
  if ( mWeatherOverrideIntensity >= 0.0 )
  {
    if ( mWeatherOverrideIntensity <= 0.0 )
    {
      mWeatherOverrideIntensity = 0.0;
    }
    else
    {
      v24 = FLOAT_2_0;
      if ( mWeatherOverrideIntensity >= 2.0 )
        goto LABEL_39;
    }
    v24 = mWeatherOverrideIntensity;
LABEL_39:
    v20->m_WeatherState = v24;
    v20->m_WeatherTarget = v24;
    v20->m_NextWeatherTarget = v24;
  }
  if ( p_mPendingSceneSettingsLocal->mWeatherOverrideLockSet )
    UFG::TimeOfDayManager::LockWeather(v20, p_mPendingSceneSettingsLocal->mWeatherOverrideLock);
  mWeatherOverrideWetness = p_mPendingSceneSettingsLocal->mWeatherOverrideWetness;
  if ( mWeatherOverrideWetness >= 0.0 )
    UFG::TimeOfDayManager::SetSurfaceWetnessOverride(
      v20,
      mWeatherOverrideWetness,
      "GameStateChangeLocation::ApplyChanges");
  if ( p_mPendingSceneSettingsLocal->mResetAmbientPeds && !sAmbientPedEnableLocked )
  {
    if ( p_mPendingSceneSettingsLocal->mEnableAmbientPedsOnEnd )
    {
      UFG::PedSpawnManager::msResourcesSuspended = 0;
      UFG::ObjectResourceManager::Instance()->mEntityStates[0].mUpdateRequired = 1;
      UFG::PedSpawnManager::ResetSpawnZones(UFG::gpPedSpawnManager);
    }
    else
    {
      UFG::PedSpawnManager::ReInitAmbient(UFG::gpPedSpawnManager);
      UFG::PedSpawnManager::msAmbientSpawningEnable = 0;
      UFG::PedSpawnManager::msCheckStatusMode = 1;
      UFG::PedSpawnManager::msResourcesSuspended = 1;
      UFG::ObjectResourceManager::Instance()->mEntityStates[0].mUpdateRequired = 1;
    }
  }
  UFG::WheeledVehicleManager::EnableTrafficSystem(
    UFG::WheeledVehicleManager::m_Instance,
    p_mPendingSceneSettingsLocal->mEnableTrafficOnEnd);
  UFG::GeographicalLayerManager::GetInstance()->mAllowImmediateActivation = 1;
  v26 = UFG::ProgressionTracker::Instance();
  UFG::ProgressionTracker::SetResourceFreezeMode(v26, 0);
}

