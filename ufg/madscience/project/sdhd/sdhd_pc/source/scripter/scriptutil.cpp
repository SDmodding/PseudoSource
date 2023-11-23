// File Line: 162
// RVA: 0x5127B0
void __fastcall UFG::SyncLoadCurrentLocation(UFG *this)
{
  UFG::PropSpawnManager *Instance; // rax
  UFG::ObjectResourceManager *v2; // rax
  UFG::PartDatabase *v3; // rax
  UFG *v4; // rcx
  AMD_HD3D *v5; // rcx
  AMD_HD3D *v6; // rcx
  UFG::SimObjectCharacter *LocalPlayer; // rax
  UFG::DataStreamer *v8; // rcx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  int CurrentState; // eax
  UFG *v11; // rcx
  UFG::TriggerUpdateContext *TriggerUpdateContext; // rax
  UFG::TriggerUpdateContext *v13; // rax
  UFG::DataStreamer *v14; // rcx
  UFG::DataStreamer *v15; // rcx
  UFG::qVector3 *LayerLoadPosition; // rbx
  UFG::GeographicalLayerManager *v17; // rax
  AMD_HD3D *v18; // rcx
  UFG::PedSpawnManager *v19; // rax
  UFG::ObjectResourceManager *v20; // rax
  UFG::PartDatabase *v21; // rax
  UFG *v22; // rcx
  UFG::DataStreamer *v23; // rcx
  UFG::TriggerUpdateContext velocity; // [rsp+40h] [rbp-48h] BYREF

  UFG::DataStreamer::BeginTagging(this);
  if ( UFG::PropSpawnManager::GetInstance() )
  {
    Instance = UFG::PropSpawnManager::GetInstance();
    UFG::PropSpawnManager::Update(Instance);
  }
  do
  {
    ((void (__fastcall *)(UFG::BasePhysicsSystem *))UFG::BasePhysicsSystem::mInstance->vfptr->PreFrameUpdate)(UFG::BasePhysicsSystem::mInstance);
    v2 = UFG::ObjectResourceManager::Instance();
    UFG::ObjectResourceManager::Update(v2, 0.0);
    v3 = UFG::PartDatabase::Instance();
    UFG::PartDatabase::Update(v3, 0.0);
    UFG::qFileService(v4);
    UFG::DataStreamer::Service(0.033333335);
    Render::StreamingLoopProcessQueuedOperations(1, 0);
    UFG::EventDispatcher::DispatchAllQueuedEvents(&UFG::EventDispatcher::mInstance);
    UFG::UpdateCamera(0.033333335, v5);
    UFG::qSleep(0x21u);
  }
  while ( !UFG::DataStreamer::IsTaggedStalled() && UFG::DataStreamer::IsTaggedBusy() );
  UFG::UpdateCamera(1.0, v6);
  LocalPlayer = UFG::GetLocalPlayer();
  if ( LocalPlayer )
  {
    m_pTransformNodeComponent = LocalPlayer->m_pTransformNodeComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    velocity.mpPlayer = 0i64;
    velocity.mPlayerPos.x = 0.0;
    CurrentState = UFG::FlowController::GetCurrentState(&UFG::gFlowController);
    UFG::SectionChooser::AddPOV(
      (UFG::qVector3 *)&m_pTransformNodeComponent->mWorldTransform.v3,
      (UFG::qVector3 *)&m_pTransformNodeComponent->mWorldTransform,
      (UFG::qVector3 *)&m_pTransformNodeComponent->mWorldTransform,
      (UFG::qVector3 *)&velocity,
      0.0,
      0i64,
      0,
      CurrentState == uidGameStateInGame_11);
  }
  UFG::DataStreamer::EndTagging(v8);
  UFG::DataStreamer::BeginTagging(eLocationDataTypes_0, 2u);
  do
  {
    UFG::qFileService(v11);
    UFG::DataStreamer::Service(0.033333335);
    Render::StreamingLoopProcessQueuedOperations(1, 0);
    UFG::qSleep(0x21u);
  }
  while ( !UFG::DataStreamer::IsTaggedStalled() && UFG::DataStreamer::IsTaggedBusy() );
  TriggerUpdateContext = UFG::GetTriggerUpdateContext(&velocity);
  UFG::TriggerRegion::UpdateAll(TriggerUpdateContext);
  v13 = UFG::GetTriggerUpdateContext(&velocity);
  UFG::TriggerRegion::UpdateAll(v13);
  UFG::DataStreamer::EndTagging(v14);
  UFG::DataStreamer::BeginTagging(v15);
  do
  {
    ((void (__fastcall *)(UFG::BasePhysicsSystem *))UFG::BasePhysicsSystem::mInstance->vfptr->PreFrameUpdate)(UFG::BasePhysicsSystem::mInstance);
    LayerLoadPosition = UFG::GetLayerLoadPosition((UFG::qVector3 *)&velocity);
    v17 = UFG::GeographicalLayerManager::GetInstance();
    UFG::GeographicalLayerManager::Update(v17, 0.017000001, LayerLoadPosition);
    UFG::UpdateCamera(0.017000001, v18);
    UFG::WheeledVehicleManager::UpdateTrafficSet(UFG::WheeledVehicleManager::m_Instance);
    v19 = UFG::PedSpawnManager::GetInstance();
    UFG::PedSpawnManager::Update(v19, 0.017000001);
    v20 = UFG::ObjectResourceManager::Instance();
    UFG::ObjectResourceManager::Update(v20, 0.017000001);
    v21 = UFG::PartDatabase::Instance();
    UFG::PartDatabase::Update(v21, 0.017000001);
    UFG::qFileService(v22);
    UFG::DataStreamer::Service(0.033333335);
    Render::StreamingLoopProcessQueuedOperations(1, 0);
    UFG::qSleep(0x21u);
  }
  while ( !UFG::DataStreamer::IsTaggedStalled() && UFG::DataStreamer::IsTaggedBusy() );
  UFG::DataStreamer::EndTagging(v23);
}

