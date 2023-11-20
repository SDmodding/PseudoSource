// File Line: 47
// RVA: 0x410A50
void __fastcall UFG::GameStateLoadNIS::OnEnter(UFG::GameStateLoadNIS *this, float deltaSeconds)
{
  UFG::GameStateLoadNIS *v2; // rbx
  NISManager::eStateEnum v3; // edx

  v2 = this;
  v3 = NISManager::GetInstance()->mState;
  if ( (signed int)v3 >= 0 )
  {
    if ( (signed int)v3 <= 1 )
    {
      v2->mLoadStage = 0;
    }
    else if ( (signed int)v3 <= 3 )
    {
      v2->mLoadStage = 1;
    }
  }
}

// File Line: 84
// RVA: 0x412AF0
void __usercall UFG::GameStateLoadNIS::OnUpdate(UFG::GameStateLoadNIS *this@<rcx>, float deltaSeconds@<xmm1>, __int64 a3@<rbx>)
{
  UFG::GameStateLoadNIS *v3; // rdi
  float deltaTime; // xmm6_4
  NISManager *v5; // rax
  AMD_HD3D *v6; // rcx
  AnimationDataBase *v7; // rax
  UFG::ObjectResourceManager *v8; // rax
  UFG::PartDatabase *v9; // rax
  UFG::TiDo *v10; // rax
  int v11; // ebx
  UFG::ObjectResourceManager *v12; // rax
  int v13; // ebx
  UFG::PartDatabase *v14; // rax
  unsigned int v15; // ebx
  int v16; // eax
  UFG::TriggerUpdateContext *v17; // rax
  UFG::GeographicalLayerManager *v18; // rax
  UFG::qVector3 *v19; // rbx
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
  UFG::BaseCameraComponent *v35; // rax
  float v36; // xmm1_4
  float v37; // xmm2_4
  UFG::BaseCameraComponent *v38; // rax
  int v39; // xmm3_4
  int v40; // xmm1_4
  UFG::BaseCameraComponent *v41; // rax
  float v42; // xmm1_4
  float v43; // xmm2_4
  int v44; // eax
  UFG::TriggerUpdateContext result; // [rsp+40h] [rbp-58h]
  UFG::qVector3 velocity; // [rsp+58h] [rbp-40h]
  UFG::qVector3 position; // [rsp+68h] [rbp-30h]
  UFG::TriggerUpdateContext v48; // [rsp+78h] [rbp-20h]
  __int64 retaddr_8; // [rsp+B0h] [rbp+18h]

  v3 = this;
  deltaTime = deltaSeconds;
  v5 = NISManager::GetInstance();
  NISManager::Update(v5, deltaSeconds);
  v6 = (AMD_HD3D *)5368709120i64;
  retaddr_8 = a3;
  switch ( v3->mLoadStage )
  {
    case 0:
      if ( NISManager::GetInstance()->mState == 2 )
        v3->mLoadStage = 1;
      break;
    case 1:
      v7 = AnimationDataBase::GetInstance();
      AnimationDataBase::Update(v7, deltaSeconds);
      v8 = UFG::ObjectResourceManager::Instance();
      UFG::ObjectResourceManager::Update(v8, deltaSeconds);
      v9 = UFG::PartDatabase::Instance();
      UFG::PartDatabase::Update(v9, deltaSeconds);
      if ( (unsigned __int8)UFG::TiDo::GetIsInstantiated() )
      {
        v10 = UFG::TiDo::GetInstance();
        ((void (__fastcall *)(UFG::TiDo *))v10->vfptr->UpdateFrame)(v10);
      }
      if ( NISManager::GetInstance()->mState == 3 || NISManager::GetInstance()->mState == STATE_INVALID )
        v3->mLoadStage = 2;
      break;
    case 2:
      v11 = UFG::SectionChooser::GetBytesRemainingToLoad();
      v12 = UFG::ObjectResourceManager::Instance();
      v13 = (unsigned __int64)UFG::ObjectResourceManager::GetBytesRemainingToLoad(v12) + v11;
      v14 = UFG::PartDatabase::Instance();
      v15 = UFG::PartDatabase::GetBytesRemainingToLoad(v14) + v13;
      v16 = UFG::SoundBankManager::GetBytesRemainingToLoad();
      UFG::LoadingLogic::SetLoadLengthHint(&UFG::gLoadingLogic, v16 + v15);
      v3->mLoadStage = 3;
      break;
    case 3:
      if ( UFG::LoadingLogic::IsComplete(&UFG::gLoadingLogic, 4u) && UFG::UpdateRigs(0x64u) )
        v3->mLoadStage = 4;
      break;
    case 4:
      v17 = UFG::GetTriggerUpdateContext(&result);
      UFG::TriggerRegion::UpdateAll(v17);
      v18 = UFG::GeographicalLayerManager::GetInstance();
      UFG::GeographicalLayerManager::ClearDeactivationTimers(v18);
      v19 = UFG::GetLayerLoadPosition(&position);
      v20 = UFG::GeographicalLayerManager::GetInstance();
      LOBYTE(v19) = UFG::GeographicalLayerManager::Update(v20, deltaSeconds, v19);
      LOBYTE(v19) = UFG::IncrementalActivateManager::Flush() | (unsigned __int8)v19;
      LOBYTE(v19) = UFG::WheeledVehicleManager::UpdateTrafficSet(UFG::WheeledVehicleManager::m_Instance) | (unsigned __int8)v19;
      UFG::PedSpawnManager::Update(UFG::gpPedSpawnManager, deltaSeconds);
      v21 = UFG::PropSpawnManager::GetInstance();
      UFG::PropSpawnManager::Update(v21);
      v22 = UFG::ObjectResourceManager::Instance();
      UFG::ObjectResourceManager::Update(v22, deltaSeconds);
      v23 = UFG::PartDatabase::Instance();
      UFG::PartDatabase::Update(v23, deltaSeconds);
      UFG::StoreMeshHelper::Update();
      if ( !(_BYTE)v19 )
      {
        v24 = UFG::ObjectResourceManager::Instance();
        UFG::ObjectResourceManager::PopulateAmbience(v24);
        v25 = UFG::ObjectResourceManager::Instance();
        UFG::ObjectResourceManager::GetBytesRemainingToLoad(v25);
        v26 = UFG::SoundBankManager::GetBytesRemainingToLoad();
        UFG::LoadingLogic::SetLoadLengthHint(&UFG::gLoadingLogic, v26);
        v3->mLoadStage = 5;
      }
      break;
    case 5:
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
      if ( UFG::LoadingLogic::IsComplete(&UFG::gLoadingLogic, 3u)
        && !UFG::PedSpawnManager::SpawnsQueued()
        && UFG::SoundBankManager::AreAllImportantBankLoadsComplete()
        && !UFG::StoreMeshHelper::SwapInProgress() )
      {
        v3->mLoadStage = 6;
      }
      break;
    case 6:
      NISManager::GetInstance()->mbStreamingComplete = 1;
      v34 = NISManager::GetInstance();
      NISManager::Update(v34, deltaSeconds);
      if ( NISManager::GetInstance()->mState == STATE_INVALID )
        UFG::FlowController::RequestSetNewState(&UFG::gFlowController, uidGameStateInGame_3);
      break;
    default:
      break;
  }
  if ( v3->mLoadStage > 1 )
  {
    UFG::UpdateCamera(deltaSeconds, v6);
    v35 = UFG::Director::Get()->mCurrentCamera;
    if ( v35 )
      v35 = (UFG::BaseCameraComponent *)((char *)v35 + 80);
    v36 = v35->mCamera.mView.v2.y;
    v37 = v35->mCamera.mView.v2.z;
    position.x = v35->mCamera.mView.v2.x;
    position.y = v36;
    position.z = v37;
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
    v44 = UFG::FlowController::GetCurrentState(&UFG::gFlowController);
    UFG::SectionChooser::AddPOV(
      &position,
      (UFG::qVector3 *)&result,
      (UFG::qVector3 *)&result,
      &velocity,
      deltaTime,
      0i64,
      7u,
      v44 == uidGameStateInGame_3);
  }
}

