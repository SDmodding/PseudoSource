// File Line: 66
// RVA: 0x410A90
void __fastcall UFG::GameStateRestoreCheckpoint::OnEnter(UFG::GameStateRestoreCheckpoint *this, float deltaSeconds)
{
  UFG::GameStateRestoreCheckpoint *v2; // rsi
  UFG::TiDo *v3; // rax
  UFG::TiDo *v4; // rax
  char v5; // bp
  UFG::GameSlice *v6; // rdi
  UFG::qSharedStringData *v7; // rbx
  UFG::qSharedStringData *v8; // rbx
  UFG::ProgressionTracker *v9; // rax
  UFG::UI *v10; // rcx
  UFG::qWiseSymbol result; // [rsp+50h] [rbp+8h]
  UFG::qWiseSymbol source; // [rsp+60h] [rbp+18h]

  v2 = this;
  UFG::qWiseSymbol::create_from_string(&result, "loadstart");
  UFG::qWiseSymbol::create_from_string(&source, "loadfinish");
  UFG::qWiseSymbol::operator=(&stru_14207B268, &source);
  if ( unk_14207B260 != 1 )
  {
    UFG::qWiseSymbol::operator=(&stru_14207B264, &result);
    if ( unk_14207B26C )
    {
      if ( unk_14207B260 && (unsigned __int8)UFG::TiDo::GetIsInstantiated() )
      {
        v3 = UFG::TiDo::GetInstance();
        v3->vfptr->LoadingGameEnd(v3, &stru_14207B268);
      }
      if ( unk_14207B26C )
      {
        UFG::qWiseSymbol::operator=(&stru_14207B264, &result);
        if ( (unsigned __int8)UFG::TiDo::GetIsInstantiated() )
        {
          v4 = UFG::TiDo::GetInstance();
          v4->vfptr->LoadingGameStart(v4, &stru_14207B264);
        }
      }
    }
    unk_14207B260 = 1;
  }
  UFG::UIHK_NISOverlay::ShowCurtains(0.0, 1);
  _((AMD_HD3D *)source.mUID);
  unk_14207B26E = 1;
  v5 = 1;
  _((AMD_HD3D *)1);
  v2->mLoadStage = 0;
  v2->mHasNis = 0;
  v6 = UFG::ProgressionTracker::Instance()->mpLastCheckpoint;
  if ( v6 )
  {
    v7 = (UFG::qSharedStringData *)(v6->mNisPath.mText - 48);
    if ( v7 != UFG::qSharedStringData::GetEmptyString() )
    {
LABEL_18:
      v2->mHasNis = v5;
      goto LABEL_19;
    }
    if ( !v6->mpParent && v6->mType > 0 && (signed int)UFG::GameSlice::GetNumChildren(v6) > 0 )
    {
      v8 = (UFG::qSharedStringData *)(UFG::GameSlice::GetChild(v6, 0)->mNisPath.mText - 48);
      if ( v8 == UFG::qSharedStringData::GetEmptyString() || UFG::GameSlice::HasProgressionTrigger(v6) )
        v5 = 0;
      goto LABEL_18;
    }
  }
LABEL_19:
  UFG::SectionChooser::EnableStreamsUpdate(1);
  if ( v2->mHasNis )
  {
    v9 = UFG::ProgressionTracker::Instance();
    UFG::ProgressionTracker::SetResourceFreezeMode(v9, 1);
  }
  UFG::Metrics::msInstance.mSimTimeDeltaLocked = FLOAT_0_033333335;
  *(_QWORD *)UFG::Metrics::msFramesPerSecBuckets = 0i64;
  qword_14235C0D0 = 0i64;
  qword_14235C0D8 = 0i64;
  dword_14235C0E0 = 0;
  UFG::GameStateRestoreCheckpoint::ResetScene();
  UFG::UI::HandleGameCheckpointRestore(v10);
  _((AMD_HD3D *)result.mUID);
}

// File Line: 108
// RVA: 0x410EB0
void __fastcall UFG::GameStateRestoreCheckpoint::OnExit(UFG::GameStateRestoreCheckpoint *this, float deltaSeconds)
{
  UFG::qWiseSymbol *v2; // rax
  UFG::TiDo *v3; // rax
  UFG::qWiseSymbol result; // [rsp+50h] [rbp+18h]

  UFG::UI::LockGameplayInput((UFG::UI *)this);
  UFG::UI::ResetInputCounterHack(1);
  if ( !UFG::ProgressionTracker::Instance()->mHoldCurtainPostRestore )
  {
    UFG::qWiseSymbol::create_from_string(&result, "loadfinish");
    UFG::qWiseSymbol::operator=(&stru_14207B268, &result);
    v2 = UFG::qWiseSymbol::get_null();
    if ( unk_14207B260 )
    {
      UFG::qWiseSymbol::operator=(&stru_14207B264, v2);
      if ( unk_14207B26C && unk_14207B260 && (unsigned __int8)UFG::TiDo::GetIsInstantiated() )
      {
        v3 = UFG::TiDo::GetInstance();
        v3->vfptr->LoadingGameEnd(v3, &stru_14207B268);
      }
      unk_14207B260 = 0;
    }
    UFG::UIHK_NISOverlay::HideCurtains(2.5, 1);
    _((AMD_HD3D *)result.mUID);
  }
  UFG::Metrics::msInstance.mSimTimeDeltaLocked = FLOAT_N1_0;
}

// File Line: 130
// RVA: 0x412F80
void __fastcall UFG::GameStateRestoreCheckpoint::OnUpdate(UFG::GameStateRestoreCheckpoint *this, float deltaSeconds)
{
  UFG::GameStateRestoreCheckpoint *v2; // rsi
  UFG::ProgressionTracker *v3; // rax
  UFG::ProgressionTracker *v4; // rbp
  UFG::ProgressionTracker::State v5; // eax
  UFG::SimObjectCharacter *v6; // rax
  AMD_HD3D *v7; // rcx
  UFG::TransformNodeComponent *v8; // rbx
  int v9; // eax
  UFG::ProgressionTracker *v10; // rax
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
  int v26; // ebx
  int v27; // eax
  UFG::TriggerUpdateContext *v28; // rax
  UFG::GeographicalLayerManager *v29; // rax
  UFG::qVector3 *v30; // rbx
  UFG::GeographicalLayerManager *v31; // rax
  UFG::PropSpawnManager *v32; // rax
  UFG::ObjectResourceManager *v33; // rax
  UFG::PartDatabase *v34; // rax
  UFG::ObjectResourceManager *v35; // rax
  UFG::PartDatabase *v36; // rax
  UFG::qVector3 velocity; // [rsp+40h] [rbp-68h]
  UFG::qVector3 v38; // [rsp+50h] [rbp-58h]
  UFG::TriggerUpdateContext result; // [rsp+60h] [rbp-48h]
  UFG::TriggerUpdateContext v40; // [rsp+78h] [rbp-30h]

  v2 = this;
  v3 = UFG::ProgressionTracker::Instance();
  v4 = v3;
  v5 = v3->mState;
  if ( v5 == 8 )
  {
    if ( v2->mHasNis )
    {
      v4->mIsWorldDataRestored = 1;
    }
    else
    {
      v6 = UFG::GetLocalPlayer();
      if ( v6 )
      {
        v8 = v6->m_pTransformNodeComponent;
        UFG::TransformNodeComponent::UpdateWorldTransform(v8);
        UFG::TransformNodeComponent::UpdateWorldTransform(v8);
        *(_QWORD *)&velocity.x = 0i64;
        velocity.z = 0.0;
        v9 = UFG::FlowController::GetCurrentState(&UFG::gFlowController);
        UFG::SectionChooser::AddPOV(
          (UFG::qVector3 *)&v8->mWorldTransform.v3,
          (UFG::qVector3 *)&v8->mWorldTransform,
          (UFG::qVector3 *)&v8->mWorldTransform,
          &velocity,
          deltaSeconds,
          0i64,
          7u,
          v9 == uidGameStateInGame_3);
      }
      UFG::UpdateCamera(deltaSeconds, v7);
      switch ( v2->mLoadStage )
      {
        case 0:
          v2->mLoadStage = 1;
          v10 = UFG::ProgressionTracker::Instance();
          UFG::ProgressionTracker::SetupGlobalAlternateLayer(v10);
          break;
        case 1:
          v11 = UFG::SectionChooser::GetBytesRemainingToLoad();
          v12 = UFG::ObjectResourceManager::Instance();
          v13 = (unsigned __int64)UFG::ObjectResourceManager::GetBytesRemainingToLoad(v12) + v11;
          v14 = UFG::PartDatabase::Instance();
          v15 = UFG::PartDatabase::GetBytesRemainingToLoad(v14) + v13;
          v16 = UFG::SoundBankManager::GetBytesRemainingToLoad();
          UFG::LoadingLogic::SetLoadLengthHint(&UFG::gLoadingLogic, v16 + v15);
          v2->mLoadStage = 2;
          break;
        case 2:
          if ( UFG::LoadingLogic::IsComplete(&UFG::gLoadingLogic, 4u) )
          {
            if ( UFG::UpdateRigs(0x64u) )
            {
              UFG::TSGameSlice::FromCPP_setup_interior_triggers();
              v2->mLoadStage = 3;
            }
          }
          break;
        case 3:
          v17 = UFG::GetTriggerUpdateContext(&result);
          UFG::TriggerRegion::UpdateAll(v17);
          v18 = UFG::GeographicalLayerManager::GetInstance();
          UFG::GeographicalLayerManager::ClearDeactivationTimers(v18);
          UFG::GeographicalLayerManager::GetInstance()->mAllowImmediateActivation = 1;
          v19 = UFG::GetLayerLoadPosition(&velocity);
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
          ((void (*)(void))UFG::AudioListener::sm_pInstance->vfptr->Update)();
          if ( !(_BYTE)v19 )
          {
            v24 = UFG::ObjectResourceManager::Instance();
            UFG::ObjectResourceManager::PopulateAmbience(v24);
            v25 = UFG::ObjectResourceManager::Instance();
            v26 = UFG::ObjectResourceManager::GetBytesRemainingToLoad(v25);
            v27 = UFG::SoundBankManager::GetBytesRemainingToLoad();
            UFG::LoadingLogic::SetLoadLengthHint(&UFG::gLoadingLogic, v27 + v26);
            v2->mLoadStage = 4;
          }
          break;
        case 4:
          v28 = UFG::GetTriggerUpdateContext(&v40);
          UFG::TriggerRegion::UpdateAll(v28);
          v29 = UFG::GeographicalLayerManager::GetInstance();
          UFG::GeographicalLayerManager::ClearDeactivationTimers(v29);
          v30 = UFG::GetLayerLoadPosition(&v38);
          v31 = UFG::GeographicalLayerManager::GetInstance();
          UFG::GeographicalLayerManager::Update(v31, deltaSeconds, v30);
          UFG::IncrementalActivateManager::Flush();
          UFG::WheeledVehicleManager::UpdateTrafficSet(UFG::WheeledVehicleManager::m_Instance);
          UFG::PedSpawnManager::Update(UFG::gpPedSpawnManager, deltaSeconds);
          v32 = UFG::PropSpawnManager::GetInstance();
          UFG::PropSpawnManager::Update(v32);
          v33 = UFG::ObjectResourceManager::Instance();
          UFG::ObjectResourceManager::Update(v33, deltaSeconds);
          v34 = UFG::PartDatabase::Instance();
          UFG::PartDatabase::Update(v34, deltaSeconds);
          UFG::StoreMeshHelper::Update();
          ((void (*)(void))UFG::AudioListener::sm_pInstance->vfptr->Update)();
          if ( UFG::LoadingLogic::IsComplete(&UFG::gLoadingLogic, 3u)
            && !UFG::PedSpawnManager::SpawnsQueued()
            && UFG::SoundBankManager::AreAllImportantBankLoadsComplete() )
          {
            v2->mLoadStage = 5;
          }
          break;
        case 5:
          v4->mIsWorldDataRestored = 1;
          break;
        default:
          return;
      }
    }
  }
  else if ( v5 == 3 )
  {
    v35 = UFG::ObjectResourceManager::Instance();
    UFG::ObjectResourceManager::Update(v35, deltaSeconds);
    v36 = UFG::PartDatabase::Instance();
    UFG::PartDatabase::Update(v36, deltaSeconds);
    UFG::StoreMeshHelper::Update();
    if ( !UFG::StoreMeshHelper::SwapInProgress() )
    {
      if ( v2->mHasNis )
        UFG::FlowController::RequestSetNewState(&UFG::gFlowController, uidGameStateLoadNIS_3);
      else
        UFG::FlowController::RequestSetNewState(&UFG::gFlowController, uidGameStateInGame_3);
    }
  }
}

// File Line: 297
// RVA: 0x415980
void UFG::GameStateRestoreCheckpoint::ResetScene(void)
{
  UFG::SimObjectCharacter *v0; // rdi
  UFG::GameStatTracker *v1; // rax
  UFG::CopSystem *v2; // rax
  unsigned int v3; // ebp
  UFG::PedSpawnManager *v4; // rbx
  UFG::qNode<UFG::SimObjectCharacterPropertiesComponent,UFG::SimObjectCharacterPropertiesComponent> *v5; // rbx
  UFG::qList<UFG::SimObjectCharacterPropertiesComponent,UFG::SimObjectCharacterPropertiesComponent,1,0> *v6; // rsi
  UFG::SimObject *v7; // rbx
  UFG::SceneObjectProperties *v8; // rcx
  UFG::SceneLayerResource *v9; // rax
  UFG::qList<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface,1,0> *v10; // rbx
  UFG::qList<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface,1,0> *v11; // rsi
  UFG::SimObject *v12; // rbx
  UFG::SceneObjectProperties *v13; // rcx
  UFG::SceneLayerResource *v14; // rax
  UFG::qNode<UFG::InventoryItemComponent,UFG::InventoryItemComponent> *v15; // rbx
  UFG::qList<UFG::InventoryItemComponent,UFG::InventoryItemComponent,1,0> *v16; // rsi
  UFG::qNode<UFG::InventoryItemComponent,UFG::InventoryItemComponent> *v17; // rcx
  UFG::SceneLayerResource *v18; // rax
  UFG::GameStatTracker *v19; // rbx
  unsigned __int16 v20; // dx
  UFG::RagdollComponent *v21; // rax
  unsigned __int16 v22; // cx
  UFG::SimComponent *v23; // rax
  unsigned __int16 v24; // cx
  UFG::HealthComponent *v25; // rax
  UFG::TransformNodeComponent *v26; // rbx
  float v27; // xmm11_4
  float v28; // xmm12_4
  float v29; // xmm13_4
  float v30; // xmm5_4
  __m128 v31; // xmm8
  __m128 v32; // xmm1
  __m128 v33; // xmm2
  float v34; // xmm6_4
  __m128 v35; // xmm7
  float v36; // xmm2_4
  __m128 v37; // xmm5
  float v38; // xmm1_4
  float v39; // xmm9_4
  float v40; // xmm7_4
  float v41; // xmm2_4
  __m128 v42; // xmm6
  __m128 v43; // xmm5
  float v44; // xmm0_4
  __m128 v45; // xmm5
  float v46; // xmm1_4
  __m128 v47; // xmm6
  float v48; // xmm10_4
  __m128 v49; // xmm8
  __m128 v50; // xmm5
  float v51; // xmm1_4
  float v52; // xmm8_4
  float v53; // xmm5_4
  float v54; // xmm8_4
  __m128 v55; // xmm2
  float v56; // xmm3_4
  UFG *v57; // rcx
  UFG::GeographicalLayerManager *v58; // rax
  UFG::TimeOfDayManager *v59; // rax
  UFG::TimeOfDayManager *v60; // rax
  unsigned int v61; // ebx
  const char *v62; // rax
  UFG::qMatrix44 xform; // [rsp+30h] [rbp-D8h]
  UFG::qWiseSymbol result; // [rsp+110h] [rbp+8h]

  KillAllSectionEffects();
  Render::FXManager::KillAllEffects(&Render::gFXManager);
  Render::DecalManager::DestroyDecals(&Render::gDecalManager);
  UFG::RenderWorld::VisualTreatmentPostEffect_StopAllVisualTreatments();
  v0 = UFG::GetLocalPlayer();
  UFG::ResetCameraObjects((UFG::SimObject *)&v0->vfptr);
  v1 = UFG::FactionInterface::Get();
  UFG::FactionInterface::Reset(&v1->mFactionInterface);
  v2 = UFG::CopSystem::Instance();
  ((void (__fastcall *)(UFG::CopSystem *))v2->vfptr[86].__vecDelDtor)(v2);
  sAmbientPedEnableLocked = 0;
  v3 = 1;
  if ( UFG::PedSpawnManager::msAmbientSpawningEnable == 1 )
  {
    v4 = UFG::gpPedSpawnManager;
    UFG::PedSpawnManager::ReInitAmbient(UFG::gpPedSpawnManager);
    UFG::PedSpawnManager::ResetSpawnZones(v4);
    UFG::PedSpawnManager::msAmbientSpawningEnable = 0;
    UFG::PedSpawnManager::msCheckStatusMode = 1;
    UFG::PedSpawnManager::msAmbientStatusCheckEnable = 0;
    UFG::PedSpawnManager::msResourcesSuspended = 1;
    UFG::ObjectResourceManager::Instance()->mEntityStates[0].mUpdateRequired = 1;
  }
  UFG::WheeledVehicleManager::ResetTrafficSystem(UFG::WheeledVehicleManager::m_Instance);
  v5 = UFG::SimObjectCharacterPropertiesComponent::s_SimObjectCharacterPropertiesComponentList.mNode.mNext - 10;
  if ( (UFG::qList<UFG::SimObjectCharacterPropertiesComponent,UFG::SimObjectCharacterPropertiesComponent,1,0> *)&UFG::SimObjectCharacterPropertiesComponent::s_SimObjectCharacterPropertiesComponentList.mNode.mNext[-10] != &UFG::SimObjectCharacterPropertiesComponent::s_SimObjectCharacterPropertiesComponentList - 10 )
  {
    do
    {
      v6 = (UFG::qList<UFG::SimObjectCharacterPropertiesComponent,UFG::SimObjectCharacterPropertiesComponent,1,0> *)&v5[10].mNext[-10];
      v7 = (UFG::SimObject *)v5[2].mNext;
      if ( v7 )
      {
        if ( !UFG::IsAnyLocalPlayer(v7) && !((v7->m_Flags >> 10) & 1) )
        {
          v8 = v7->m_pSceneObj;
          if ( !v8
            || (v9 = UFG::SceneObjectProperties::GetLayer(v8)) == 0i64
            || !((v9->mTypeUID >> 1) & 1)
            || !((v9->mTypeUID >> 13) & 1) )
          {
            UFG::Simulation::QueueSimObjectToBeDestroyed(&UFG::gSim, v7);
          }
        }
      }
      v5 = &v6->mNode;
    }
    while ( v6 != &UFG::SimObjectCharacterPropertiesComponent::s_SimObjectCharacterPropertiesComponentList - 10 );
  }
  v10 = (UFG::qList<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface,1,0> *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList.mNode.mNext[-5].mNext;
  if ( &UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList.mNode.mNext[-5].mNext != (UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface> **)((char *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList - 72) )
  {
    do
    {
      v11 = (UFG::qList<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface,1,0> *)&v10[5].mNode.mPrev[-5].mNext;
      v12 = (UFG::SimObject *)v10[2].mNode.mNext;
      if ( v12 )
      {
        if ( !((v12->m_Flags >> 10) & 1) )
        {
          v13 = v12->m_pSceneObj;
          if ( !v13
            || (v14 = UFG::SceneObjectProperties::GetLayer(v13)) == 0i64
            || !((v14->mTypeUID >> 1) & 1)
            || !((v14->mTypeUID >> 13) & 1) )
          {
            UFG::Simulation::QueueTrackedSimObjectToBeDestroyed(&UFG::gSim, v12);
          }
        }
      }
      v10 = v11;
    }
    while ( v11 != (UFG::qList<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface,1,0> *)((char *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList
                                                                                           - 72) );
  }
  v15 = UFG::InventoryItemComponent::s_InventoryItemComponentList.mNode.mNext - 4;
  if ( (UFG::qList<UFG::InventoryItemComponent,UFG::InventoryItemComponent,1,0> *)&UFG::InventoryItemComponent::s_InventoryItemComponentList.mNode.mNext[-4] != &UFG::InventoryItemComponent::s_InventoryItemComponentList - 4 )
  {
    do
    {
      v16 = (UFG::qList<UFG::InventoryItemComponent,UFG::InventoryItemComponent,1,0> *)&v15[4].mNext[-4];
      v17 = v15[2].mNext;
      if ( SLODWORD(v15[7].mPrev) > 0 && !v15[6].mPrev && !((WORD2(v17[4].mNext) >> 10) & 1) )
      {
        if ( v17 )
          v17 = v17[5].mPrev;
        if ( !v17
          || (v18 = UFG::SceneObjectProperties::GetLayer((UFG::SceneObjectProperties *)v17)) == 0i64
          || !((v18->mTypeUID >> 1) & 1)
          || !((v18->mTypeUID >> 13) & 1) )
        {
          UFG::Simulation::QueueSimObjectToBeDestroyed(&UFG::gSim, (UFG::SimObject *)v15[2].mNext);
        }
      }
      v15 = &v16->mNode;
    }
    while ( v16 != &UFG::InventoryItemComponent::s_InventoryItemComponentList - 4 );
  }
  v19 = UFG::GameStatTracker::Instance();
  *((_BYTE *)v19 + 6216) |= 1u;
  UFG::SimObjectUtility::ReinitializeSimObject((UFG::SimObject *)&v0->vfptr, 1, 0);
  if ( v0 )
  {
    v20 = v0->m_Flags;
    if ( (v20 >> 14) & 1 )
    {
      v21 = (UFG::RagdollComponent *)v0->m_Components.p[42].m_pComponent;
    }
    else if ( (v20 & 0x8000u) == 0 )
    {
      if ( (v20 >> 13) & 1 )
      {
        v21 = (UFG::RagdollComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v0->vfptr,
                                         UFG::RagdollComponent::_TypeUID);
      }
      else if ( (v20 >> 12) & 1 )
      {
        v21 = (UFG::RagdollComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v0->vfptr,
                                         UFG::RagdollComponent::_TypeUID);
      }
      else
      {
        v21 = (UFG::RagdollComponent *)UFG::SimObject::GetComponentOfType(
                                         (UFG::SimObject *)&v0->vfptr,
                                         UFG::RagdollComponent::_TypeUID);
      }
    }
    else
    {
      v21 = (UFG::RagdollComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                       (UFG::SimObjectGame *)&v0->vfptr,
                                       UFG::RagdollComponent::_TypeUID);
    }
    if ( v21 )
      UFG::RagdollComponent::ResetState(v21);
    v22 = v0->m_Flags;
    if ( (v22 >> 14) & 1 )
    {
      v23 = v0->m_Components.p[7].m_pComponent;
    }
    else if ( (v22 & 0x8000u) == 0 )
    {
      if ( (v22 >> 13) & 1 )
      {
        v23 = v0->m_Components.p[6].m_pComponent;
      }
      else if ( (v22 >> 12) & 1 )
      {
        v23 = UFG::SimObjectGame::GetComponentOfTypeHK(
                (UFG::SimObjectGame *)&v0->vfptr,
                UFG::ActionTreeComponent::_TypeUID);
      }
      else
      {
        v23 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v0->vfptr, UFG::ActionTreeComponent::_TypeUID);
      }
    }
    else
    {
      v23 = v0->m_Components.p[7].m_pComponent;
    }
    if ( v23 )
      LOBYTE(v23[2].m_pSimObject) = 0;
  }
  *((_BYTE *)v19 + 6216) &= 0xFEu;
  if ( v0 )
  {
    v24 = v0->m_Flags;
    if ( (v24 >> 14) & 1 )
    {
      v25 = (UFG::HealthComponent *)v0->m_Components.p[6].m_pComponent;
    }
    else if ( (v24 & 0x8000u) == 0 )
    {
      if ( (v24 >> 13) & 1 )
      {
        v25 = (UFG::HealthComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                        (UFG::SimObjectGame *)&v0->vfptr,
                                        UFG::HealthComponent::_TypeUID);
      }
      else if ( (v24 >> 12) & 1 )
      {
        v25 = (UFG::HealthComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                        (UFG::SimObjectGame *)&v0->vfptr,
                                        UFG::HealthComponent::_TypeUID);
      }
      else
      {
        v25 = (UFG::HealthComponent *)UFG::SimObject::GetComponentOfType(
                                        (UFG::SimObject *)&v0->vfptr,
                                        UFG::HealthComponent::_TypeUID);
      }
    }
    else
    {
      v25 = (UFG::HealthComponent *)v0->m_Components.p[6].m_pComponent;
    }
    if ( v25 )
      UFG::HealthComponent::LoadHealthSettings(v25);
    v26 = v0->m_pTransformNodeComponent;
    if ( v26 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(v0->m_pTransformNodeComponent);
      v27 = v26->mWorldTransform.v3.x;
      v28 = v26->mWorldTransform.v3.y;
      v29 = v26->mWorldTransform.v3.z;
      UFG::TransformNodeComponent::UpdateWorldTransform(v26);
      v30 = v26->mWorldTransform.v0.x;
      v31 = (__m128)LODWORD(v26->mWorldTransform.v0.y);
      v32 = v31;
      v32.m128_f32[0] = (float)(v31.m128_f32[0] * v31.m128_f32[0]) + (float)(v30 * v30);
      if ( v32.m128_f32[0] == 0.0 )
      {
        v33 = 0i64;
      }
      else
      {
        v33 = (__m128)(unsigned int)FLOAT_1_0;
        v33.m128_f32[0] = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v32));
      }
      v34 = v33.m128_f32[0] * 0.0;
      v35 = v33;
      v35.m128_f32[0] = v33.m128_f32[0] * v31.m128_f32[0];
      v36 = v33.m128_f32[0] * v30;
      v37 = v35;
      v37.m128_f32[0] = (float)((float)(v35.m128_f32[0] * v35.m128_f32[0]) + (float)(v36 * v36)) + (float)(v34 * v34);
      if ( v37.m128_f32[0] == 0.0 )
        v38 = 0.0;
      else
        v38 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v37));
      v39 = v38 * v34;
      v40 = v35.m128_f32[0] * v38;
      v41 = v36 * v38;
      xform.v0.x = v41;
      xform.v0.y = v40;
      xform.v0.z = v38 * v34;
      xform.v0.w = 0.0;
      v42 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
      v43 = v42;
      v43.m128_f32[0] = (float)((float)(v42.m128_f32[0] * v42.m128_f32[0])
                              + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                      + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
      if ( v43.m128_f32[0] == 0.0 )
      {
        v45 = 0i64;
      }
      else
      {
        LODWORD(v44) = (unsigned __int128)_mm_sqrt_ps(v43);
        v45 = (__m128)(unsigned int)FLOAT_1_0;
        v45.m128_f32[0] = 1.0 / v44;
      }
      v46 = v45.m128_f32[0] * UFG::qVector3::msDirUp.z;
      v49 = v45;
      v49.m128_f32[0] = v45.m128_f32[0] * UFG::qVector3::msDirUp.y;
      v45.m128_f32[0] = v45.m128_f32[0] * UFG::qVector3::msDirUp.x;
      v47 = v45;
      v47.m128_f32[0] = (float)(v45.m128_f32[0] * v40) - (float)(v41 * v49.m128_f32[0]);
      v48 = (float)(v41 * v46) - (float)(v45.m128_f32[0] * v39);
      v49.m128_f32[0] = (float)(v49.m128_f32[0] * v39) - (float)(v46 * v40);
      v50 = v49;
      v50.m128_f32[0] = (float)((float)(v49.m128_f32[0] * v49.m128_f32[0]) + (float)(v48 * v48))
                      + (float)(v47.m128_f32[0] * v47.m128_f32[0]);
      if ( v50.m128_f32[0] == 0.0 )
        v51 = 0.0;
      else
        v51 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v50));
      v47.m128_f32[0] = v47.m128_f32[0] * v51;
      v52 = v49.m128_f32[0] * v51;
      xform.v1.x = v52;
      xform.v1.y = v48 * v51;
      LODWORD(xform.v1.z) = v47.m128_i32[0];
      xform.v1.w = 0.0;
      v53 = (float)(v41 * (float)(v48 * v51)) - (float)(v52 * v40);
      v54 = (float)(v52 * v39) - (float)(v41 * v47.m128_f32[0]);
      v47.m128_f32[0] = (float)(v47.m128_f32[0] * v40) - (float)((float)(v48 * v51) * v39);
      v55 = v47;
      v55.m128_f32[0] = (float)((float)(v47.m128_f32[0] * v47.m128_f32[0]) + (float)(v54 * v54)) + (float)(v53 * v53);
      if ( v55.m128_f32[0] == 0.0 )
        v56 = 0.0;
      else
        v56 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v55));
      xform.v2.x = v47.m128_f32[0] * v56;
      xform.v2.y = v56 * v54;
      xform.v2.z = v56 * v53;
      xform.v2.w = 0.0;
      xform.v3.x = v27;
      xform.v3.y = v28;
      xform.v3.z = v29;
      xform.v3.w = 1.0;
      UFG::SimObjectUtility::Teleport((UFG::SimObject *)&v0->vfptr, &xform);
    }
  }
  UFG::PhysicsSystem::ResetScene((UFG::PhysicsSystem *)UFG::BasePhysicsSystem::mInstance, 0);
  UFG::ResetRigInstances(v57);
  UFG::SceneryGroup::MakeAllVisible();
  v58 = UFG::GeographicalLayerManager::GetInstance();
  UFG::GeographicalLayerManager::DeactivateActiveGeoLayers(v58);
  v59 = UFG::TimeOfDayManager::GetInstance();
  TimePlotPoint::SetTimeValue(v59, 40.0);
  v60 = UFG::TimeOfDayManager::GetInstance();
  UFG::TimeOfDayManager::LockWeather(v60, 0);
  UFG::qWiseSymbol::create_from_string(&result, "stop_mus_score");
  UFG::Music::MusicEvent(result.mUID);
  v61 = UFG::SectionLayout::GetLayerCount();
  if ( v61 > 1 )
  {
    do
    {
      UFG::SectionLayout::SetLayerActive(v3, 0);
      v62 = UFG::SectionLayout::GetLayerName(v3);
      UFG::SectionChooser::FlushAltLayer(v62, 0);
      ++v3;
    }
    while ( v3 < v61 );
  }
  UFG::Scene::OnRestoreCheckpoint(&UFG::Scene::msDefault);
  _((AMD_HD3D *)result.mUID);
}

