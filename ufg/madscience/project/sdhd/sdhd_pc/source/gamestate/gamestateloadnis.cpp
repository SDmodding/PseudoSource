// File Line: 47
// RVA: 0x410A50
void __fastcall UFG::GameStateLoadNIS::OnEnter(UFG::GameStateLoadNIS *this, float deltaSeconds)
{
  NISManager::eStateEnum mState; // edx

  mState = NISManager::GetInstance()->mState;
  if ( mState >= STATE_INVALID )
  {
    if ( mState <= STATE_NORMAL )
    {
      this->mLoadStage = eLS_WAIT_FOR_CURTAINS;
    }
    else if ( mState <= STATE_COMPLETE )
    {
      this->mLoadStage = eLS_APPLY_CHANGES;
    }
  }
}

// File Line: 84
// RVA: 0x412AF0
void __fastcall UFG::GameStateLoadNIS::OnUpdate(UFG::GameStateLoadNIS *this, float deltaSeconds)
{
  void *v2; // rbx
  NISManager *Instance; // rax
  AMD_HD3D *v6; // rcx
  AnimationDataBase *v7; // rax
  UFG::ObjectResourceManager *v8; // rax
  UFG::PartDatabase *v9; // rax
  UFG::TiDo *v10; // rax
  int BytesRemainingToLoad; // ebx
  UFG::ObjectResourceManager *v12; // rax
  int v13; // ebx
  UFG::PartDatabase *v14; // rax
  int v15; // ebx
  int v16; // eax
  UFG::TriggerUpdateContext *TriggerUpdateContext; // rax
  UFG::GeographicalLayerManager *v18; // rax
  UFG::qVector3 *LayerLoadPosition; // rbx
  UFG::GeographicalLayerManager *v20; // rax
  UFG::PropSpawnManager *v21; // rax
  UFG::ObjectResourceManager *v22; // rax
  UFG::PartDatabase *v23; // rax
  UFG::ObjectResourceManager *v24; // rax
  UFG::ObjectResourceManager *v25; // rax
  unsigned int v26; // eax
  UFG::TriggerUpdateContext *v27; // rax
  UFG::GeographicalLayerManager *v28; // rax
  UFG::qVector3 *v29; // rbx
  UFG::GeographicalLayerManager *v30; // rax
  UFG::PropSpawnManager *v31; // rax
  UFG::ObjectResourceManager *v32; // rax
  UFG::PartDatabase *v33; // rax
  NISManager *v34; // rax
  UFG::BaseCameraComponent *mCurrentCamera; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::BaseCameraComponent *v38; // rax
  int v39; // xmm3_4
  int v40; // xmm1_4
  UFG::BaseCameraComponent *v41; // rax
  float v42; // xmm1_4
  float v43; // xmm2_4
  int CurrentState; // eax
  UFG::TriggerUpdateContext result; // [rsp+40h] [rbp-58h] BYREF
  UFG::qVector3 velocity; // [rsp+58h] [rbp-40h] BYREF
  UFG::qVector3 position; // [rsp+68h] [rbp-30h] BYREF
  UFG::TriggerUpdateContext v48; // [rsp+78h] [rbp-20h] BYREF
  void *retaddr[2]; // [rsp+A8h] [rbp+10h]

  Instance = NISManager::GetInstance();
  NISManager::Update(Instance, deltaSeconds);
  v6 = (AMD_HD3D *)0x140000000i64;
  retaddr[1] = v2;
  switch ( this->mLoadStage )
  {
    case eLS_WAIT_FOR_CURTAINS:
      if ( NISManager::GetInstance()->mState == STATE_DANGER )
        this->mLoadStage = eLS_APPLY_CHANGES;
      break;
    case eLS_APPLY_CHANGES:
      v7 = AnimationDataBase::GetInstance();
      AnimationDataBase::Update(v7, deltaSeconds);
      v8 = UFG::ObjectResourceManager::Instance();
      UFG::ObjectResourceManager::Update(v8, deltaSeconds);
      v9 = UFG::PartDatabase::Instance();
      UFG::PartDatabase::Update(v9, deltaSeconds);
      if ( UFG::TiDo::GetIsInstantiated() )
      {
        v10 = UFG::TiDo::GetInstance();
        ((void (__fastcall *)(UFG::TiDo *))v10->vfptr->UpdateFrame)(v10);
      }
      if ( NISManager::GetInstance()->mState == STATE_COMPLETE || NISManager::GetInstance()->mState == STATE_INVALID )
        this->mLoadStage = eLS_SETLOADING_HINT;
      break;
    case eLS_SETLOADING_HINT:
      BytesRemainingToLoad = UFG::SectionChooser::GetBytesRemainingToLoad();
      v12 = UFG::ObjectResourceManager::Instance();
      v13 = UFG::ObjectResourceManager::GetBytesRemainingToLoad(v12) + BytesRemainingToLoad;
      v14 = UFG::PartDatabase::Instance();
      v15 = UFG::PartDatabase::GetBytesRemainingToLoad(v14) + v13;
      v16 = UFG::SoundBankManager::GetBytesRemainingToLoad();
      UFG::LoadingLogic::SetLoadLengthHint(&UFG::gLoadingLogic, v16 + v15);
      this->mLoadStage = eLS_LOCATION_PENDING;
      break;
    case eLS_LOCATION_PENDING:
      if ( UFG::LoadingLogic::IsComplete(&UFG::gLoadingLogic, 4) && UFG::UpdateRigs(0x64u) )
        this->mLoadStage = eLS_LAYERS_PENDING;
      break;
    case eLS_LAYERS_PENDING:
      TriggerUpdateContext = UFG::GetTriggerUpdateContext(&result);
      UFG::TriggerRegion::UpdateAll(TriggerUpdateContext);
      v18 = UFG::GeographicalLayerManager::GetInstance();
      UFG::GeographicalLayerManager::ClearDeactivationTimers(v18);
      LayerLoadPosition = UFG::GetLayerLoadPosition(&position);
      v20 = UFG::GeographicalLayerManager::GetInstance();
      LOBYTE(LayerLoadPosition) = UFG::GeographicalLayerManager::Update(v20, deltaSeconds, LayerLoadPosition);
      LOBYTE(LayerLoadPosition) = UFG::IncrementalActivateManager::Flush() | (unsigned __int8)LayerLoadPosition;
      LOBYTE(LayerLoadPosition) = UFG::WheeledVehicleManager::UpdateTrafficSet(UFG::WheeledVehicleManager::m_Instance) | (unsigned __int8)LayerLoadPosition;
      UFG::PedSpawnManager::Update(UFG::gpPedSpawnManager, deltaSeconds);
      v21 = UFG::PropSpawnManager::GetInstance();
      UFG::PropSpawnManager::Update(v21);
      v22 = UFG::ObjectResourceManager::Instance();
      UFG::ObjectResourceManager::Update(v22, deltaSeconds);
      v23 = UFG::PartDatabase::Instance();
      UFG::PartDatabase::Update(v23, deltaSeconds);
      UFG::StoreMeshHelper::Update();
      if ( !(_BYTE)LayerLoadPosition )
      {
        v24 = UFG::ObjectResourceManager::Instance();
        UFG::ObjectResourceManager::PopulateAmbience(v24);
        v25 = UFG::ObjectResourceManager::Instance();
        UFG::ObjectResourceManager::GetBytesRemainingToLoad(v25);
        v26 = UFG::SoundBankManager::GetBytesRemainingToLoad();
        UFG::LoadingLogic::SetLoadLengthHint(&UFG::gLoadingLogic, v26);
        this->mLoadStage = eLS_CHARACTER_AND_VEHICLE_RESOURCE_PENDING;
      }
      break;
    case eLS_CHARACTER_AND_VEHICLE_RESOURCE_PENDING:
      v27 = UFG::GetTriggerUpdateContext(&v48);
      UFG::TriggerRegion::UpdateAll(v27);
      v28 = UFG::GeographicalLayerManager::GetInstance();
      UFG::GeographicalLayerManager::ClearDeactivationTimers(v28);
      v29 = UFG::GetLayerLoadPosition(&velocity);
      v30 = UFG::GeographicalLayerManager::GetInstance();
      UFG::GeographicalLayerManager::Update(v30, deltaSeconds, v29);
      UFG::IncrementalActivateManager::Flush();
      UFG::WheeledVehicleManager::UpdateTrafficSet(UFG::WheeledVehicleManager::m_Instance);
      UFG::PedSpawnManager::Update(UFG::gpPedSpawnManager, deltaSeconds);
      v31 = UFG::PropSpawnManager::GetInstance();
      UFG::PropSpawnManager::Update(v31);
      v32 = UFG::ObjectResourceManager::Instance();
      UFG::ObjectResourceManager::Update(v32, deltaSeconds);
      v33 = UFG::PartDatabase::Instance();
      UFG::PartDatabase::Update(v33, deltaSeconds);
      UFG::StoreMeshHelper::Update();
      if ( UFG::LoadingLogic::IsComplete(&UFG::gLoadingLogic, 3)
        && !UFG::PedSpawnManager::SpawnsQueued()
        && UFG::SoundBankManager::AreAllImportantBankLoadsComplete()
        && !UFG::StoreMeshHelper::SwapInProgress() )
      {
        this->mLoadStage = eLS_APPLY_SPAWN_SETTINGS;
      }
      break;
    case eLS_APPLY_SPAWN_SETTINGS:
      NISManager::GetInstance()->mbStreamingComplete = 1;
      v34 = NISManager::GetInstance();
      NISManager::Update(v34, deltaSeconds);
      if ( NISManager::GetInstance()->mState == STATE_INVALID )
        UFG::FlowController::RequestSetNewState(&UFG::gFlowController, uidGameStateInGame_3);
      break;
    default:
      break;
  }
  if ( this->mLoadStage > eLS_APPLY_CHANGES )
  {
    UFG::UpdateCamera(deltaSeconds, v6);
    mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
    if ( mCurrentCamera )
      mCurrentCamera = (UFG::BaseCameraComponent *)((char *)mCurrentCamera + 80);
    y = mCurrentCamera->mCamera.mView.v2.y;
    z = mCurrentCamera->mCamera.mView.v2.z;
    position.x = mCurrentCamera->mCamera.mView.v2.x;
    position.y = y;
    position.z = z;
    v38 = UFG::Director::Get()->mCurrentCamera;
    if ( v38 )
      v38 = (UFG::BaseCameraComponent *)((char *)v38 + 80);
    v39 = LODWORD(v38->mCamera.mView.v1.z) ^ _xmm[0];
    v40 = LODWORD(v38->mCamera.mView.v1.y) ^ _xmm[0];
    LODWORD(result.mpPlayer) = LODWORD(v38->mCamera.mView.v1.x) ^ _xmm[0];
    HIDWORD(result.mpPlayer) = v40;
    LODWORD(result.mPlayerPos.x) = v39;
    v41 = UFG::Director::Get()->mCurrentCamera;
    if ( v41 )
      v41 = (UFG::BaseCameraComponent *)((char *)v41 + 80);
    v42 = v41->mCamera.mPreviousView.v3.y;
    v43 = v41->mCamera.mPreviousView.v3.z;
    velocity.x = v41->mCamera.mPreviousView.v3.x;
    velocity.y = v42;
    velocity.z = v43;
    CurrentState = UFG::FlowController::GetCurrentState(&UFG::gFlowController);
    UFG::SectionChooser::AddPOV(
      &position,
      (UFG::qVector3 *)&result,
      (UFG::qVector3 *)&result,
      &velocity,
      deltaSeconds,
      0i64,
      7,
      CurrentState == uidGameStateInGame_3);
  }
}

