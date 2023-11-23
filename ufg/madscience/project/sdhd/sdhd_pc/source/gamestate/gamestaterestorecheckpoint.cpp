// File Line: 66
// RVA: 0x410A90
void __fastcall UFG::GameStateRestoreCheckpoint::OnEnter(UFG::GameStateRestoreCheckpoint *this, float deltaSeconds)
{
  UFG::TiDo *Instance; // rax
  UFG::TiDo *v4; // rax
  bool v5; // bp
  UFG::GameSlice *mpLastCheckpoint; // rdi
  UFG::qSharedStringData *v7; // rbx
  UFG::qSharedStringData *v8; // rbx
  UFG::ProgressionTracker *v9; // rax
  UFG::UI *v10; // rcx
  UFG::qWiseSymbol result; // [rsp+50h] [rbp+8h] BYREF
  UFG::qWiseSymbol source; // [rsp+60h] [rbp+18h] BYREF

  UFG::qWiseSymbol::create_from_string(&result, "loadstart");
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
          v4 = UFG::TiDo::GetInstance();
          v4->vfptr->LoadingGameStart(v4, &stru_14207B264);
        }
      }
    }
    byte_14207B260 = 1;
  }
  UFG::UIHK_NISOverlay::ShowCurtains(0.0, 1);
  _((AMD_HD3D *)source.mUID);
  byte_14207B26E = 1;
  v5 = 1;
  _((AMD_HD3D *)1);
  this->mLoadStage = eLS_INIT;
  this->mHasNis = 0;
  mpLastCheckpoint = UFG::ProgressionTracker::Instance()->mpLastCheckpoint;
  if ( mpLastCheckpoint )
  {
    v7 = (UFG::qSharedStringData *)(mpLastCheckpoint->mNisPath.mText - 48);
    if ( v7 != UFG::qSharedStringData::GetEmptyString() )
    {
LABEL_18:
      this->mHasNis = v5;
      goto LABEL_19;
    }
    if ( !mpLastCheckpoint->mpParent
      && mpLastCheckpoint->mType > TYPE_CULL
      && (int)UFG::GameSlice::GetNumChildren(mpLastCheckpoint) > 0 )
    {
      v8 = (UFG::qSharedStringData *)(UFG::GameSlice::GetChild(mpLastCheckpoint, 0)->mNisPath.mText - 48);
      if ( v8 == UFG::qSharedStringData::GetEmptyString() || UFG::GameSlice::HasProgressionTrigger(mpLastCheckpoint) )
        v5 = 0;
      goto LABEL_18;
    }
  }
LABEL_19:
  UFG::SectionChooser::EnableStreamsUpdate(1);
  if ( this->mHasNis )
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
  UFG::qWiseSymbol *null; // rax
  UFG::TiDo *Instance; // rax
  UFG::qWiseSymbol result; // [rsp+50h] [rbp+18h] BYREF

  UFG::UI::LockGameplayInput((UFG::UI *)this);
  UFG::UI::ResetInputCounterHack(1);
  if ( !UFG::ProgressionTracker::Instance()->mHoldCurtainPostRestore )
  {
    UFG::qWiseSymbol::create_from_string(&result, "loadfinish");
    UFG::qWiseSymbol::operator=(&stru_14207B268, &result);
    null = UFG::qWiseSymbol::get_null();
    if ( byte_14207B260 )
    {
      UFG::qWiseSymbol::operator=(&stru_14207B264, null);
      if ( (_BYTE)word_14207B26C && byte_14207B260 && UFG::TiDo::GetIsInstantiated() )
      {
        Instance = UFG::TiDo::GetInstance();
        Instance->vfptr->LoadingGameEnd(Instance, &stru_14207B268);
      }
      byte_14207B260 = 0;
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
  UFG::ProgressionTracker *v3; // rbp
  UFG::ProgressionTracker::State mState; // eax
  UFG::SimObjectCharacter *LocalPlayer; // rax
  AMD_HD3D *v6; // rcx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  int CurrentState; // eax
  UFG::ProgressionTracker *v9; // rax
  int BytesRemainingToLoad; // ebx
  UFG::ObjectResourceManager *v11; // rax
  int v12; // ebx
  UFG::PartDatabase *v13; // rax
  int v14; // ebx
  int v15; // eax
  UFG::TriggerUpdateContext *TriggerUpdateContext; // rax
  UFG::GeographicalLayerManager *Instance; // rax
  UFG::qVector3 *LayerLoadPosition; // rbx
  UFG::GeographicalLayerManager *v19; // rax
  UFG::PropSpawnManager *v20; // rax
  UFG::ObjectResourceManager *v21; // rax
  UFG::PartDatabase *v22; // rax
  UFG::ObjectResourceManager *v23; // rax
  UFG::ObjectResourceManager *v24; // rax
  int v25; // ebx
  int v26; // eax
  UFG::TriggerUpdateContext *v27; // rax
  UFG::GeographicalLayerManager *v28; // rax
  UFG::qVector3 *v29; // rbx
  UFG::GeographicalLayerManager *v30; // rax
  UFG::PropSpawnManager *v31; // rax
  UFG::ObjectResourceManager *v32; // rax
  UFG::PartDatabase *v33; // rax
  UFG::ObjectResourceManager *v34; // rax
  UFG::PartDatabase *v35; // rax
  UFG::qVector3 velocity; // [rsp+40h] [rbp-68h] BYREF
  UFG::qVector3 v37; // [rsp+50h] [rbp-58h] BYREF
  UFG::TriggerUpdateContext result; // [rsp+60h] [rbp-48h] BYREF
  UFG::TriggerUpdateContext v39; // [rsp+78h] [rbp-30h] BYREF

  v3 = UFG::ProgressionTracker::Instance();
  mState = v3->mState;
  if ( mState == 8 )
  {
    if ( this->mHasNis )
    {
      v3->mIsWorldDataRestored = 1;
    }
    else
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
      UFG::UpdateCamera(deltaSeconds, v6);
      switch ( this->mLoadStage )
      {
        case 0:
          this->mLoadStage = eLS_PARENT;
          v9 = UFG::ProgressionTracker::Instance();
          UFG::ProgressionTracker::SetupGlobalAlternateLayer(v9);
          break;
        case 1:
          BytesRemainingToLoad = UFG::SectionChooser::GetBytesRemainingToLoad();
          v11 = UFG::ObjectResourceManager::Instance();
          v12 = UFG::ObjectResourceManager::GetBytesRemainingToLoad(v11) + BytesRemainingToLoad;
          v13 = UFG::PartDatabase::Instance();
          v14 = UFG::PartDatabase::GetBytesRemainingToLoad(v13) + v12;
          v15 = UFG::SoundBankManager::GetBytesRemainingToLoad();
          UFG::LoadingLogic::SetLoadLengthHint(&UFG::gLoadingLogic, v15 + v14);
          this->mLoadStage = eLS_FINAL;
          break;
        case 2:
          if ( UFG::LoadingLogic::IsComplete(&UFG::gLoadingLogic, 4) )
          {
            if ( UFG::UpdateRigs(0x64u) )
            {
              UFG::TSGameSlice::FromCPP_setup_interior_triggers();
              this->mLoadStage = eLS_FINAL|eLS_PARENT;
            }
          }
          break;
        case 3:
          TriggerUpdateContext = UFG::GetTriggerUpdateContext(&result);
          UFG::TriggerRegion::UpdateAll(TriggerUpdateContext);
          Instance = UFG::GeographicalLayerManager::GetInstance();
          UFG::GeographicalLayerManager::ClearDeactivationTimers(Instance);
          UFG::GeographicalLayerManager::GetInstance()->mAllowImmediateActivation = 1;
          LayerLoadPosition = UFG::GetLayerLoadPosition(&velocity);
          v19 = UFG::GeographicalLayerManager::GetInstance();
          LOBYTE(LayerLoadPosition) = UFG::GeographicalLayerManager::Update(v19, deltaSeconds, LayerLoadPosition);
          LOBYTE(LayerLoadPosition) = UFG::IncrementalActivateManager::Flush() | (unsigned __int8)LayerLoadPosition;
          LOBYTE(LayerLoadPosition) = UFG::WheeledVehicleManager::UpdateTrafficSet(UFG::WheeledVehicleManager::m_Instance) | (unsigned __int8)LayerLoadPosition;
          UFG::PedSpawnManager::Update(UFG::gpPedSpawnManager, deltaSeconds);
          v20 = UFG::PropSpawnManager::GetInstance();
          UFG::PropSpawnManager::Update(v20);
          v21 = UFG::ObjectResourceManager::Instance();
          UFG::ObjectResourceManager::Update(v21, deltaSeconds);
          v22 = UFG::PartDatabase::Instance();
          UFG::PartDatabase::Update(v22, deltaSeconds);
          UFG::StoreMeshHelper::Update();
          ((void (__fastcall *)(UFG::AudioListener *))UFG::AudioListener::sm_pInstance->vfptr->Update)(UFG::AudioListener::sm_pInstance);
          if ( !(_BYTE)LayerLoadPosition )
          {
            v23 = UFG::ObjectResourceManager::Instance();
            UFG::ObjectResourceManager::PopulateAmbience(v23);
            v24 = UFG::ObjectResourceManager::Instance();
            v25 = UFG::ObjectResourceManager::GetBytesRemainingToLoad(v24);
            v26 = UFG::SoundBankManager::GetBytesRemainingToLoad();
            UFG::LoadingLogic::SetLoadLengthHint(&UFG::gLoadingLogic, v26 + v25);
            this->mLoadStage = 4;
          }
          break;
        case 4:
          v27 = UFG::GetTriggerUpdateContext(&v39);
          UFG::TriggerRegion::UpdateAll(v27);
          v28 = UFG::GeographicalLayerManager::GetInstance();
          UFG::GeographicalLayerManager::ClearDeactivationTimers(v28);
          v29 = UFG::GetLayerLoadPosition(&v37);
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
          ((void (__fastcall *)(UFG::AudioListener *))UFG::AudioListener::sm_pInstance->vfptr->Update)(UFG::AudioListener::sm_pInstance);
          if ( UFG::LoadingLogic::IsComplete(&UFG::gLoadingLogic, 3)
            && !UFG::PedSpawnManager::SpawnsQueued()
            && UFG::SoundBankManager::AreAllImportantBankLoadsComplete() )
          {
            this->mLoadStage = 5;
          }
          break;
        case 5:
          v3->mIsWorldDataRestored = 1;
          break;
        default:
          return;
      }
    }
  }
  else if ( mState == STATE_COMPLETE )
  {
    v34 = UFG::ObjectResourceManager::Instance();
    UFG::ObjectResourceManager::Update(v34, deltaSeconds);
    v35 = UFG::PartDatabase::Instance();
    UFG::PartDatabase::Update(v35, deltaSeconds);
    UFG::StoreMeshHelper::Update();
    if ( !UFG::StoreMeshHelper::SwapInProgress() )
    {
      if ( this->mHasNis )
        UFG::FlowController::RequestSetNewState(&UFG::gFlowController, uidGameStateLoadNIS_3);
      else
        UFG::FlowController::RequestSetNewState(&UFG::gFlowController, uidGameStateInGame_3);
    }
  }
}questSetNewState(&UFG::gFlowController, uidGameStateInGame_3);
    }
  }
}

// File Line: 297
// RVA: 0x415980
void UFG::GameStateRestoreCheckpoint::ResetScene(void)
{
  UFG::SimObjectCharacter *LocalPlayer; // rdi
  UFG::GameStatTracker *v1; // rax
  UFG::CopSystem *v2; // rax
  unsigned int v3; // ebp
  UFG::PedSpawnManager *v4; // rbx
  UFG::qNode<UFG::SimObjectCharacterPropertiesComponent,UFG::SimObjectCharacterPropertiesComponent> *p_mNode; // rbx
  UFG::qList<UFG::SimObjectCharacterPropertiesComponent,UFG::SimObjectCharacterPropertiesComponent,1,0> *v6; // rsi
  UFG::SimObjectCharacter *mNext; // rbx
  UFG::SceneObjectProperties *m_pSceneObj; // rcx
  UFG::SceneLayerResource *Layer; // rax
  unsigned int mTypeUID; // ecx
  UFG::qList<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface,1,0> *p_mNext; // rbx
  UFG::qList<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface,1,0> *v12; // rsi
  UFG::SimObject *v13; // rbx
  UFG::SceneObjectProperties *v14; // rcx
  UFG::SceneLayerResource *v15; // rax
  unsigned int v16; // ecx
  UFG::qNode<UFG::InventoryItemComponent,UFG::InventoryItemComponent> *v17; // rbx
  UFG::qList<UFG::InventoryItemComponent,UFG::InventoryItemComponent,1,0> *v18; // rsi
  UFG::qNode<UFG::InventoryItemComponent,UFG::InventoryItemComponent> *mPrev; // rcx
  UFG::SceneLayerResource *v20; // rax
  unsigned int v21; // ecx
  UFG::GameStatTracker *v22; // rbx
  __int16 m_Flags; // dx
  UFG::RagdollComponent *m_pComponent; // rax
  __int16 v25; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int16 v27; // cx
  UFG::HealthComponent *ComponentOfType; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  float x; // xmm11_4
  float y; // xmm12_4
  float z; // xmm13_4
  float v33; // xmm5_4
  __m128 y_low; // xmm8
  __m128 v35; // xmm1
  __m128 v36; // xmm2
  float v37; // xmm6_4
  __m128 v38; // xmm7
  float v39; // xmm2_4
  __m128 v40; // xmm5
  float v41; // xmm1_4
  float v42; // xmm9_4
  float v43; // xmm7_4
  float v44; // xmm2_4
  __m128 x_low; // xmm5
  float v46; // xmm0_4
  __m128 v47; // xmm5
  float v48; // xmm1_4
  __m128 v49; // xmm6
  float v50; // xmm10_4
  __m128 v51; // xmm8
  __m128 v52; // xmm5
  float v53; // xmm1_4
  float v54; // xmm5_4
  float v55; // xmm8_4
  __m128 v56; // xmm2
  float v57; // xmm3_4
  UFG *v58; // rcx
  UFG::GeographicalLayerManager *Instance; // rax
  UFG::TimeOfDayManager *v60; // rax
  UFG::TimeOfDayManager *v61; // rax
  unsigned int LayerCount; // ebx
  const char *LayerName; // rax
  UFG::qMatrix44 xform; // [rsp+30h] [rbp-D8h] BYREF
  UFG::qWiseSymbol result; // [rsp+110h] [rbp+8h] BYREF

  KillAllSectionEffects();
  Render::FXManager::KillAllEffects(&Render::gFXManager);
  Render::DecalManager::DestroyDecals(&Render::gDecalManager);
  UFG::RenderWorld::VisualTreatmentPostEffect_StopAllVisualTreatments();
  LocalPlayer = UFG::GetLocalPlayer();
  UFG::ResetCameraObjects(LocalPlayer);
  v1 = UFG::FactionInterface::Get();
  UFG::FactionInterface::Reset(&v1->mFactionInterface);
  v2 = UFG::CopSystem::Instance();
  ((void (__fastcall *)(UFG::CopSystem *))v2->vfptr[86].__vecDelDtor)(v2);
  sAmbientPedEnableLocked = 0;
  v3 = 1;
  if ( UFG::PedSpawnManager::msAmbientSpawningEnable )
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
  p_mNode = UFG::SimObjectCharacterPropertiesComponent::s_SimObjectCharacterPropertiesComponentList.mNode.mNext - 10;
  if ( (UFG::qList<UFG::SimObjectCharacterPropertiesComponent,UFG::SimObjectCharacterPropertiesComponent,1,0> *)&UFG::SimObjectCharacterPropertiesComponent::s_SimObjectCharacterPropertiesComponentList.mNode.mNext[-10] != &UFG::SimObjectCharacterPropertiesComponent::s_SimObjectCharacterPropertiesComponentList - 10 )
  {
    do
    {
      v6 = (UFG::qList<UFG::SimObjectCharacterPropertiesComponent,UFG::SimObjectCharacterPropertiesComponent,1,0> *)&p_mNode[10].mNext[-10];
      mNext = (UFG::SimObjectCharacter *)p_mNode[2].mNext;
      if ( mNext )
      {
        if ( !UFG::IsAnyLocalPlayer(mNext) && (mNext->m_Flags & 0x400) == 0 )
        {
          m_pSceneObj = mNext->m_pSceneObj;
          if ( !m_pSceneObj
            || (Layer = UFG::SceneObjectProperties::GetLayer(m_pSceneObj)) == 0i64
            || (mTypeUID = Layer->mTypeUID, (mTypeUID & 2) == 0)
            || (mTypeUID & 0x2000) == 0 )
          {
            UFG::Simulation::QueueSimObjectToBeDestroyed(&UFG::gSim, mNext);
          }
        }
      }
      p_mNode = &v6->mNode;
    }
    while ( v6 != &UFG::SimObjectCharacterPropertiesComponent::s_SimObjectCharacterPropertiesComponentList - 10 );
  }
  p_mNext = (UFG::qList<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface,1,0> *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList.mNode.mNext[-5].mNext;
  if ( &UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList.mNode.mNext[-5].mNext != (UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface> **)((char *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList - 72) )
  {
    do
    {
      v12 = (UFG::qList<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface,1,0> *)&p_mNext[5].mNode.mPrev[-5].mNext;
      v13 = (UFG::SimObject *)p_mNext[2].mNode.mNext;
      if ( v13 )
      {
        if ( (v13->m_Flags & 0x400) == 0 )
        {
          v14 = v13->m_pSceneObj;
          if ( !v14
            || (v15 = UFG::SceneObjectProperties::GetLayer(v14)) == 0i64
            || (v16 = v15->mTypeUID, (v16 & 2) == 0)
            || (v16 & 0x2000) == 0 )
          {
            UFG::Simulation::QueueTrackedSimObjectToBeDestroyed(&UFG::gSim, v13);
          }
        }
      }
      p_mNext = v12;
    }
    while ( v12 != (UFG::qList<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface,1,0> *)((char *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList
                                                                                           - 72) );
  }
  v17 = UFG::InventoryItemComponent::s_InventoryItemComponentList.mNode.mNext - 4;
  if ( (UFG::qList<UFG::InventoryItemComponent,UFG::InventoryItemComponent,1,0> *)&UFG::InventoryItemComponent::s_InventoryItemComponentList.mNode.mNext[-4] != &UFG::InventoryItemComponent::s_InventoryItemComponentList - 4 )
  {
    do
    {
      v18 = (UFG::qList<UFG::InventoryItemComponent,UFG::InventoryItemComponent,1,0> *)&v17[4].mNext[-4];
      mPrev = v17[2].mNext;
      if ( SLODWORD(v17[7].mPrev) > 0 && !v17[6].mPrev && (WORD2(mPrev[4].mNext) & 0x400) == 0 )
      {
        if ( mPrev )
          mPrev = mPrev[5].mPrev;
        if ( !mPrev
          || (v20 = UFG::SceneObjectProperties::GetLayer((UFG::SceneObjectProperties *)mPrev)) == 0i64
          || (v21 = v20->mTypeUID, (v21 & 2) == 0)
          || (v21 & 0x2000) == 0 )
        {
          UFG::Simulation::QueueSimObjectToBeDestroyed(&UFG::gSim, (UFG::SimObject *)v17[2].mNext);
        }
      }
      v17 = &v18->mNode;
    }
    while ( v18 != &UFG::InventoryItemComponent::s_InventoryItemComponentList - 4 );
  }
  v22 = UFG::GameStatTracker::Instance();
  *((_BYTE *)v22 + 6216) |= 1u;
  UFG::SimObjectUtility::ReinitializeSimObject(LocalPlayer, 1, 0);
  if ( LocalPlayer )
  {
    m_Flags = LocalPlayer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::RagdollComponent *)LocalPlayer->m_Components.p[42].m_pComponent;
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      m_pComponent = (UFG::RagdollComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                LocalPlayer,
                                                UFG::RagdollComponent::_TypeUID);
    }
    else
    {
      m_pComponent = (UFG::RagdollComponent *)UFG::SimObject::GetComponentOfType(
                                                LocalPlayer,
                                                UFG::RagdollComponent::_TypeUID);
    }
    if ( m_pComponent )
      UFG::RagdollComponent::ResetState(m_pComponent);
    v25 = LocalPlayer->m_Flags;
    if ( (v25 & 0x4000) != 0 )
    {
      ComponentOfTypeHK = LocalPlayer->m_Components.p[7].m_pComponent;
    }
    else if ( v25 >= 0 )
    {
      if ( (v25 & 0x2000) != 0 )
      {
        ComponentOfTypeHK = LocalPlayer->m_Components.p[6].m_pComponent;
      }
      else if ( (v25 & 0x1000) != 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(LocalPlayer, UFG::ActionTreeComponent::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(LocalPlayer, UFG::ActionTreeComponent::_TypeUID);
      }
    }
    else
    {
      ComponentOfTypeHK = LocalPlayer->m_Components.p[7].m_pComponent;
    }
    if ( ComponentOfTypeHK )
      LOBYTE(ComponentOfTypeHK[2].m_pSimObject) = 0;
  }
  *((_BYTE *)v22 + 6216) &= ~1u;
  if ( LocalPlayer )
  {
    v27 = LocalPlayer->m_Flags;
    if ( (v27 & 0x4000) != 0 )
    {
      ComponentOfType = (UFG::HealthComponent *)LocalPlayer->m_Components.p[6].m_pComponent;
    }
    else if ( v27 >= 0 )
    {
      if ( (v27 & 0x2000) != 0 || (v27 & 0x1000) != 0 )
        ComponentOfType = (UFG::HealthComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    LocalPlayer,
                                                    UFG::HealthComponent::_TypeUID);
      else
        ComponentOfType = (UFG::HealthComponent *)UFG::SimObject::GetComponentOfType(
                                                    LocalPlayer,
                                                    UFG::HealthComponent::_TypeUID);
    }
    else
    {
      ComponentOfType = (UFG::HealthComponent *)LocalPlayer->m_Components.p[6].m_pComponent;
    }
    if ( ComponentOfType )
      UFG::HealthComponent::LoadHealthSettings(ComponentOfType);
    m_pTransformNodeComponent = LocalPlayer->m_pTransformNodeComponent;
    if ( m_pTransformNodeComponent )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(LocalPlayer->m_pTransformNodeComponent);
      x = m_pTransformNodeComponent->mWorldTransform.v3.x;
      y = m_pTransformNodeComponent->mWorldTransform.v3.y;
      z = m_pTransformNodeComponent->mWorldTransform.v3.z;
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
      v33 = m_pTransformNodeComponent->mWorldTransform.v0.x;
      y_low = (__m128)LODWORD(m_pTransformNodeComponent->mWorldTransform.v0.y);
      v35 = y_low;
      v35.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v33 * v33);
      if ( v35.m128_f32[0] == 0.0 )
      {
        v36 = 0i64;
      }
      else
      {
        v36 = (__m128)(unsigned int)FLOAT_1_0;
        v36.m128_f32[0] = 1.0 / _mm_sqrt_ps(v35).m128_f32[0];
      }
      v37 = v36.m128_f32[0] * 0.0;
      v38 = v36;
      v38.m128_f32[0] = v36.m128_f32[0] * y_low.m128_f32[0];
      v39 = v36.m128_f32[0] * v33;
      v40 = v38;
      v40.m128_f32[0] = (float)((float)(v38.m128_f32[0] * v38.m128_f32[0]) + (float)(v39 * v39)) + (float)(v37 * v37);
      if ( v40.m128_f32[0] == 0.0 )
        v41 = 0.0;
      else
        v41 = 1.0 / _mm_sqrt_ps(v40).m128_f32[0];
      v42 = v41 * v37;
      v43 = v38.m128_f32[0] * v41;
      v44 = v39 * v41;
      xform.v0.x = v44;
      xform.v0.y = v43;
      xform.v0.z = v41 * v37;
      xform.v0.w = 0.0;
      x_low = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
      x_low.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0])
                                + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                        + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
      if ( x_low.m128_f32[0] == 0.0 )
      {
        v47 = 0i64;
      }
      else
      {
        v46 = _mm_sqrt_ps(x_low).m128_f32[0];
        v47 = (__m128)(unsigned int)FLOAT_1_0;
        v47.m128_f32[0] = 1.0 / v46;
      }
      v48 = v47.m128_f32[0] * UFG::qVector3::msDirUp.z;
      v51 = v47;
      v51.m128_f32[0] = v47.m128_f32[0] * UFG::qVector3::msDirUp.y;
      v47.m128_f32[0] = v47.m128_f32[0] * UFG::qVector3::msDirUp.x;
      v49 = v47;
      v49.m128_f32[0] = (float)(v47.m128_f32[0] * v43) - (float)(v44 * v51.m128_f32[0]);
      v50 = (float)(v44 * v48) - (float)(v47.m128_f32[0] * v42);
      v51.m128_f32[0] = (float)(v51.m128_f32[0] * v42) - (float)(v48 * v43);
      v52 = v51;
      v52.m128_f32[0] = (float)((float)(v51.m128_f32[0] * v51.m128_f32[0]) + (float)(v50 * v50))
                      + (float)(v49.m128_f32[0] * v49.m128_f32[0]);
      if ( v52.m128_f32[0] == 0.0 )
        v53 = 0.0;
      else
        v53 = 1.0 / _mm_sqrt_ps(v52).m128_f32[0];
      xform.v1.x = v51.m128_f32[0] * v53;
      xform.v1.y = v50 * v53;
      xform.v1.z = v49.m128_f32[0] * v53;
      xform.v1.w = 0.0;
      v54 = (float)(v44 * (float)(v50 * v53)) - (float)((float)(v51.m128_f32[0] * v53) * v43);
      v55 = (float)((float)(v51.m128_f32[0] * v53) * v42) - (float)(v44 * (float)(v49.m128_f32[0] * v53));
      v49.m128_f32[0] = (float)((float)(v49.m128_f32[0] * v53) * v43) - (float)((float)(v50 * v53) * v42);
      v56 = v49;
      v56.m128_f32[0] = (float)((float)(v49.m128_f32[0] * v49.m128_f32[0]) + (float)(v55 * v55)) + (float)(v54 * v54);
      if ( v56.m128_f32[0] == 0.0 )
        v57 = 0.0;
      else
        v57 = 1.0 / _mm_sqrt_ps(v56).m128_f32[0];
      xform.v2.x = v49.m128_f32[0] * v57;
      xform.v2.y = v57 * v55;
      xform.v2.z = v57 * v54;
      xform.v2.w = 0.0;
      xform.v3.x = x;
      xform.v3.y = y;
      xform.v3.z = z;
      xform.v3.w = 1.0;
      UFG::SimObjectUtility::Teleport(LocalPlayer, &xform);
    }
  }
  UFG::PhysicsSystem::ResetScene((UFG::PhysicsSystem *)UFG::BasePhysicsSystem::mInstance, PartialReset);
  UFG::ResetRigInstances(v58);
  UFG::SceneryGroup::MakeAllVisible();
  Instance = UFG::GeographicalLayerManager::GetInstance();
  UFG::GeographicalLayerManager::DeactivateActiveGeoLayers(Instance);
  v60 = UFG::TimeOfDayManager::GetInstance();
  TimePlotPoint::SetTimeValue(v60, 40.0);
  v61 = UFG::TimeOfDayManager::GetInstance();
  UFG::TimeOfDayManager::LockWeather(v61, 0);
  UFG::qWiseSymbol::create_from_string(&result, "stop_mus_score");
  UFG::Music::MusicEvent(result.mUID);
  LayerCount = UFG::SectionLayout::GetLayerCount();
  if ( LayerCount > 1 )
  {
    do
    {
      UFG::SectionLayout::SetLayerActive(v3, 0);
      LayerName = UFG::SectionLayout::GetLayerName(v3);
      UFG::SectionChooser::FlushAltLayer(LayerName, 0);
      ++v3;
    }
    while ( v3 < LayerCount );
  }
  UFG::Scene::OnRestoreCheckpoint(&UFG::Scene::msDefault);
  _((AMD_HD3D *)result.mUID);
}

