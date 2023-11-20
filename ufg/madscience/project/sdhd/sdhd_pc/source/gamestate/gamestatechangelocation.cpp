// File Line: 79
// RVA: 0x410400
void __fastcall UFG::GameStateChangeLocation::OnEnter(UFG::GameStateChangeLocation *this, float deltaSeconds)
{
  UFG::GameStateChangeLocation *v2; // rbx
  UFG::ProgressionTracker *v3; // rax
  signed __int64 v4; // rdi
  UFG::ProgressionTracker *v5; // rax
  UFG::TiDo *v6; // rax
  UFG::TiDo *v7; // rax
  UFG::qWiseSymbol result; // [rsp+50h] [rbp+18h]
  UFG::qWiseSymbol source; // [rsp+58h] [rbp+20h]

  v2 = this;
  v3 = UFG::ProgressionTracker::Instance();
  if ( !v3->mbPendingSceneSettingsValid
    || (v4 = (signed __int64)&v3->mPendingSceneSettingsLocal, v3 == (UFG::ProgressionTracker *)-5648i64) )
  {
    v2->mSavedAmbientSpawningSetting = UFG::PedSpawnManager::msAmbientSpawningEnable;
    UFG::PedSpawnManager::msAmbientSpawningEnable = 0;
    UFG::PedSpawnManager::msCheckStatusMode = 1;
    goto LABEL_15;
  }
  v5 = UFG::ProgressionTracker::Instance();
  UFG::ProgressionTracker::SetResourceFreezeMode(v5, 1);
  UFG::StreamFileWrapper::SetQueueMode(QUEUE_MODE_SEEK_MINIMIZE);
  _((AMD_HD3D *)1);
  if ( !*(_BYTE *)(v4 + 53) )
  {
LABEL_15:
    v2->mLoadStage = 1;
    return;
  }
  UFG::qWiseSymbol::create_from_string(&result, "loadstart");
  v2->mLoadStage = 0;
  UFG::qWiseSymbol::create_from_string(&source, "loadfinish");
  UFG::qWiseSymbol::operator=(&stru_14207B268, &source);
  if ( unk_14207B260 != 1 )
  {
    UFG::qWiseSymbol::operator=(&stru_14207B264, &result);
    if ( unk_14207B26C )
    {
      if ( unk_14207B260 && (unsigned __int8)UFG::TiDo::GetIsInstantiated() )
      {
        v6 = UFG::TiDo::GetInstance();
        v6->vfptr->LoadingGameEnd(v6, &stru_14207B268);
      }
      if ( unk_14207B26C )
      {
        UFG::qWiseSymbol::operator=(&stru_14207B264, &result);
        if ( (unsigned __int8)UFG::TiDo::GetIsInstantiated() )
        {
          v7 = UFG::TiDo::GetInstance();
          v7->vfptr->LoadingGameStart(v7, &stru_14207B264);
        }
      }
    }
    unk_14207B260 = 1;
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
  signed __int64 v3; // rax
  UFG::ProgressionTracker *v4; // rax

  UFG::WheeledVehicleManager::OnChangeLocationFinished(UFG::WheeledVehicleManager::m_Instance);
  v2 = UFG::ProgressionTracker::Instance();
  if ( v2->mbPendingSceneSettingsValid )
  {
    v3 = (signed __int64)&v2->mPendingSceneSettingsLocal;
    if ( v3 )
    {
      if ( *(_BYTE *)(v3 + 54) )
      {
        ((void (__fastcall *)(UFG::TiDo *, signed __int64))UFG::TiDo::m_pInstance->vfptr[1].Close)(
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
  UFG::GameStateChangeLocation *v2; // rdi
  UFG::ProgressionTracker *v3; // rax
  int v4; // ebx
  UFG::ObjectResourceManager *v5; // rax
  int v6; // ebx
  UFG::PartDatabase *v7; // rax
  unsigned int v8; // ebx
  int v9; // eax
  UFG::TriggerUpdateContext *v10; // rax
  UFG::GeographicalLayerManager *v11; // rax
  UFG::qVector3 *v12; // rbx
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
  signed __int64 v29; // rcx
  bool v30; // al
  char v31; // al
  bool v32; // al
  UFG::SimObjectCharacter *v33; // rax
  AMD_HD3D *v34; // rcx
  UFG::TransformNodeComponent *v35; // rbx
  int v36; // eax
  UFG::qVector3 velocity; // [rsp+40h] [rbp-68h]
  UFG::qVector3 v38; // [rsp+50h] [rbp-58h]
  UFG::TriggerUpdateContext result; // [rsp+60h] [rbp-48h]
  UFG::TriggerUpdateContext v40; // [rsp+78h] [rbp-30h]

  v2 = this;
  switch ( this->mLoadStage )
  {
    case 0:
      if ( UFG::UIHK_NISOverlay::IsCurtainStable() )
        v2->mLoadStage = 1;
      goto LABEL_29;
    case 1:
      UFG::SectionChooser::EnableStreamsUpdate(1);
      v3 = UFG::ProgressionTracker::Instance();
      if ( v3->mbPendingSceneSettingsValid && v3 != (UFG::ProgressionTracker *)-5648i64 )
        UFG::GameStateChangeLocation::ApplyChanges(v2, deltaSeconds);
      v2->mLoadStage = 2;
      goto LABEL_29;
    case 2:
      v4 = UFG::SectionChooser::GetBytesRemainingToLoad();
      v5 = UFG::ObjectResourceManager::Instance();
      v6 = (unsigned __int64)UFG::ObjectResourceManager::GetBytesRemainingToLoad(v5) + v4;
      v7 = UFG::PartDatabase::Instance();
      v8 = UFG::PartDatabase::GetBytesRemainingToLoad(v7) + v6;
      v9 = UFG::SoundBankManager::GetBytesRemainingToLoad();
      UFG::LoadingLogic::SetLoadLengthHint(&UFG::gLoadingLogic, v9 + v8);
      v2->mLoadStage = 3;
      goto LABEL_29;
    case 3:
      if ( UFG::LoadingLogic::IsComplete(&UFG::gLoadingLogic, 4u) && UFG::UpdateRigs(0x64u) )
        v2->mLoadStage = 4;
      goto LABEL_29;
    case 4:
      v10 = UFG::GetTriggerUpdateContext(&result);
      UFG::TriggerRegion::UpdateAll(v10);
      v11 = UFG::GeographicalLayerManager::GetInstance();
      UFG::GeographicalLayerManager::ClearDeactivationTimers(v11);
      v12 = UFG::GetLayerLoadPosition(&velocity);
      v13 = UFG::GeographicalLayerManager::GetInstance();
      LOBYTE(v12) = UFG::GeographicalLayerManager::Update(v13, deltaSeconds, v12);
      LOBYTE(v12) = UFG::IncrementalActivateManager::Flush() | (unsigned __int8)v12;
      LOBYTE(v12) = UFG::WheeledVehicleManager::UpdateTrafficSet(UFG::WheeledVehicleManager::m_Instance) | (unsigned __int8)v12;
      UFG::PedSpawnManager::Update(UFG::gpPedSpawnManager, deltaSeconds);
      v14 = UFG::PropSpawnManager::GetInstance();
      UFG::PropSpawnManager::Update(v14);
      v15 = UFG::ObjectResourceManager::Instance();
      UFG::ObjectResourceManager::Update(v15, deltaSeconds);
      v16 = UFG::PartDatabase::Instance();
      UFG::PartDatabase::Update(v16, deltaSeconds);
      UFG::StoreMeshHelper::Update();
      if ( !(_BYTE)v12 )
      {
        v17 = UFG::ObjectResourceManager::Instance();
        UFG::ObjectResourceManager::PopulateAmbience(v17);
        v18 = UFG::ObjectResourceManager::Instance();
        v19 = UFG::ObjectResourceManager::GetBytesRemainingToLoad(v18);
        v20 = UFG::SoundBankManager::GetBytesRemainingToLoad();
        UFG::LoadingLogic::SetLoadLengthHint(&UFG::gLoadingLogic, v20 + v19);
        v2->mLoadStage = 5;
      }
      goto LABEL_29;
    case 5:
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
      if ( UFG::LoadingLogic::IsComplete(&UFG::gLoadingLogic, 3u)
        && UFG::SoundBankManager::AreAllImportantBankLoadsComplete()
        && !UFG::StoreMeshHelper::SwapInProgress() )
      {
        v2->mLoadStage = 6;
      }
      goto LABEL_29;
    case 6:
      v28 = UFG::ProgressionTracker::Instance();
      if ( v28->mbPendingSceneSettingsValid
        && (v29 = (signed __int64)&v28->mPendingSceneSettingsLocal, v28 != (UFG::ProgressionTracker *)-5648i64) )
      {
        if ( sAmbientPedEnableLocked )
          goto LABEL_24;
        v30 = v28->mPendingSceneSettingsLocal.mEnableAmbientPedsOnEnd;
        UFG::PedSpawnManager::msCheckStatusMode = 1;
        UFG::PedSpawnManager::msAmbientSpawningEnable = v30;
        v31 = *(_BYTE *)(v29 + 58);
      }
      else
      {
        v32 = v2->mSavedAmbientSpawningSetting;
        UFG::PedSpawnManager::msCheckStatusMode = 1;
        UFG::PedSpawnManager::msAmbientSpawningEnable = v32;
        v31 = v2->mSavedAmbientSpawningSetting;
      }
      UFG::PedSpawnManager::msAmbientStatusCheckEnable = v31;
LABEL_24:
      UFG::PedSpawnManager::msScriptedStatusCheckEnable = 1;
      UFG::PedSpawnManager::RestoreAllScriptedToFullyActive(UFG::gpPedSpawnManager);
      v2->mLoadStage = 7;
LABEL_29:
      if ( v2->mLoadStage > 1 )
      {
        v33 = UFG::GetLocalPlayer();
        if ( v33 )
        {
          v35 = v33->m_pTransformNodeComponent;
          UFG::TransformNodeComponent::UpdateWorldTransform(v33->m_pTransformNodeComponent);
          UFG::TransformNodeComponent::UpdateWorldTransform(v35);
          *(_QWORD *)&velocity.x = 0i64;
          velocity.z = 0.0;
          v36 = UFG::FlowController::GetCurrentState(&UFG::gFlowController);
          UFG::SectionChooser::AddPOV(
            (UFG::qVector3 *)&v35->mWorldTransform.v3,
            (UFG::qVector3 *)&v35->mWorldTransform,
            (UFG::qVector3 *)&v35->mWorldTransform,
            &velocity,
            deltaSeconds,
            0i64,
            7u,
            v36 == uidGameStateInGame_3);
        }
        UFG::UpdateCamera(deltaSeconds, v34);
      }
      return;
    case 7:
      UFG::PedSpawnManager::Update(UFG::gpPedSpawnManager, deltaSeconds);
      if ( !UFG::PedSpawnManager::SpawnsQueued() )
        v2->mLoadStage = 8;
      goto LABEL_29;
    case 8:
      if ( UFG::LoadingLogic::IsComplete(&UFG::gLoadingLogic, 3u) )
      {
        UFG::FlowController::RequestSetNewState(&UFG::gFlowController, uidGameStateInGame_3);
        v2->mLoadStage = 9;
      }
      goto LABEL_29;
    default:
      goto LABEL_29;
  }
}

// File Line: 304
// RVA: 0x411420
void __fastcall UFG::GameStateRestoreCheckpoint::OnPostUpdate(UFG::GameStateRestoreCheckpoint *this, float deltaSeconds)
{
  UFG::LoadingLogic::OnPostUpdate(&UFG::gLoadingLogic, deltaSeconds);
}

// File Line: 309
// RVA: 0x407940
void __fastcall UFG::GameStateChangeLocation::ApplyChanges(UFG::GameStateChangeLocation *this, float deltaSeconds)
{
  UFG::ProgressionTracker *v2; // rax
  UFG::Event *v3; // rsi
  signed __int64 v4; // rdi
  UFG::qSymbol *v5; // rcx
  UFG::qBaseTreeRB *v6; // rax
  UFG::qVector4 *v7; // rbx
  UFG::qVector4 v8; // xmm2
  UFG::qVector4 v9; // xmm1
  UFG::qVector4 v10; // xmm0
  float v11; // xmm1_4
  float v12; // xmm2_4
  UFG::SimObjectCharacter *v13; // rbx
  UFG::allocator::free_link *v14; // rax
  UFG::Event *v15; // rax
  UFG::SimComponent *v16; // rax
  UFG::ProgressionTracker *v17; // rax
  UFG::ProgressionTracker *v18; // rax
  UFG::TimeOfDayManager *v19; // rax
  UFG::TimeOfDayManager *v20; // rbx
  float v21; // xmm1_4
  float v22; // xmm1_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  UFG::ProgressionTracker *v26; // rax
  UFG::qMatrix44 worldXform; // [rsp+38h] [rbp+7h]

  v2 = UFG::ProgressionTracker::Instance();
  v3 = 0i64;
  v4 = (signed __int64)&v2->mPendingSceneSettingsLocal;
  if ( !v2->mbPendingSceneSettingsValid )
    v4 = 0i64;
  worldXform = UFG::qMatrix44::msIdentity;
  v5 = (UFG::qSymbol *)(v4 + 112);
  if ( *(_DWORD *)(v4 + 112) == -1 )
  {
    if ( !*(_BYTE *)(v4 + 121) )
      goto LABEL_22;
    v11 = *(float *)(v4 + 128);
    v12 = *(float *)(v4 + 132);
    worldXform.v3.x = *(float *)(v4 + 124);
    worldXform.v3.y = v11;
    worldXform.v3.z = v12;
    worldXform.v3.w = 1.0;
  }
  else
  {
    v6 = UFG::MarkerBase::GetNamed(v5);
    if ( !v6 )
      goto LABEL_22;
    v7 = (UFG::qVector4 *)v6[1].mNULL.mParent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v6[1].mNULL.mParent);
    v8 = v7[9];
    v9 = v7[10];
    v10 = v7[11];
    worldXform.v0 = v7[8];
    worldXform.v1 = v8;
    worldXform.v2 = v9;
    worldXform.v3 = v10;
  }
  v13 = UFG::GetLocalPlayer();
  if ( v13 )
  {
    v14 = UFG::qMalloc(0x90ui64, "NISManager", 0i64);
    if ( v14 )
    {
      UFG::TeleportEvent::TeleportEvent(
        (UFG::TeleportEvent *)v14,
        &worldXform,
        v13->mNode.mUID,
        0,
        UFG::TeleportEvent::m_Name,
        0);
      v3 = v15;
    }
    UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v3);
    v5 = (UFG::qSymbol *)v13->m_Flags;
    if ( ((unsigned __int16)v5 >> 14) & 1 )
    {
      v16 = v13->m_Components.p[7].m_pComponent;
    }
    else if ( (signed __int16)v5 >= 0 )
    {
      if ( ((unsigned __int16)v5 >> 13) & 1 )
      {
        v16 = v13->m_Components.p[6].m_pComponent;
      }
      else if ( ((unsigned __int16)v5 >> 12) & 1 )
      {
        v16 = UFG::SimObjectGame::GetComponentOfTypeHK(
                (UFG::SimObjectGame *)&v13->vfptr,
                UFG::ActionTreeComponent::_TypeUID);
      }
      else
      {
        v16 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v13->vfptr, UFG::ActionTreeComponent::_TypeUID);
      }
    }
    else
    {
      v16 = v13->m_Components.p[7].m_pComponent;
    }
    if ( v16 )
      ActionController::Stop((ActionController *)&v16[3]);
  }
LABEL_22:
  if ( *(_DWORD *)(v4 + 116) != -1 )
  {
    v17 = UFG::ProgressionTracker::Instance();
    UFG::ProgressionTracker::TeleportVehicle(v17, (UFG::SceneSettings *)v4);
  }
  if ( *(_BYTE *)(v4 + 120) )
  {
    v18 = UFG::ProgressionTracker::Instance();
    UFG::ProgressionTracker::DestroyVehicle(v18);
  }
  UFG::UpdateCamera(1.0, (AMD_HD3D *)v5);
  v19 = UFG::TimeOfDayManager::GetInstance();
  v20 = v19;
  v21 = *(float *)(v4 + 44);
  if ( v21 >= 0.0 )
    UFG::TimeOfDayManager::SetTime(v19, v21, 0);
  if ( *(_BYTE *)(v4 + 48) )
  {
    if ( *(_BYTE *)(v4 + 50) )
      v22 = 0.0;
    else
      v22 = FLOAT_40_0;
    TimePlotPoint::SetTimeValue(v20, v22);
  }
  v23 = *(float *)(v4 + 32);
  if ( v23 >= 0.0 )
  {
    if ( v23 <= 0.0 )
    {
      v23 = 0.0;
    }
    else
    {
      v24 = FLOAT_2_0;
      if ( v23 >= 2.0 )
        goto LABEL_39;
    }
    v24 = v23;
LABEL_39:
    v20->m_WeatherState = v24;
    v20->m_WeatherTarget = v24;
    v20->m_NextWeatherTarget = v24;
  }
  if ( *(_BYTE *)(v4 + 49) )
    UFG::TimeOfDayManager::LockWeather(v20, *(_BYTE *)(v4 + 40));
  v25 = *(float *)(v4 + 36);
  if ( v25 >= 0.0 )
    UFG::TimeOfDayManager::SetSurfaceWetnessOverride(v20, v25, "GameStateChangeLocation::ApplyChanges");
  if ( *(_BYTE *)(v4 + 51) && !sAmbientPedEnableLocked )
  {
    if ( *(_BYTE *)(v4 + 0x3A) )
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
  UFG::WheeledVehicleManager::EnableTrafficSystem(UFG::WheeledVehicleManager::m_Instance, *(_BYTE *)(v4 + 62));
  UFG::GeographicalLayerManager::GetInstance()->mAllowImmediateActivation = 1;
  v26 = UFG::ProgressionTracker::Instance();
  UFG::ProgressionTracker::SetResourceFreezeMode(v26, 0);
}

