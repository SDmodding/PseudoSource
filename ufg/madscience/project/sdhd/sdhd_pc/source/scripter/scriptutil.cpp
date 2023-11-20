// File Line: 162
// RVA: 0x5127B0
void __fastcall UFG::SyncLoadCurrentLocation(UFG *this)
{
  UFG::PropSpawnManager *v1; // rax
  UFG::ObjectResourceManager *v2; // rax
  UFG::PartDatabase *v3; // rax
  UFG *v4; // rcx
  AMD_HD3D *v5; // rcx
  AMD_HD3D *v6; // rcx
  UFG::SimObjectCharacter *v7; // rax
  UFG::DataStreamer *v8; // rcx
  UFG::TransformNodeComponent *v9; // rbx
  int v10; // eax
  UFG *v11; // rcx
  UFG::TriggerUpdateContext *v12; // rax
  UFG::TriggerUpdateContext *v13; // rax
  UFG::DataStreamer *v14; // rcx
  UFG::DataStreamer *v15; // rcx
  UFG::qVector3 *v16; // rbx
  UFG::GeographicalLayerManager *v17; // rax
  AMD_HD3D *v18; // rcx
  UFG::PedSpawnManager *v19; // rax
  UFG::ObjectResourceManager *v20; // rax
  UFG::PartDatabase *v21; // rax
  UFG *v22; // rcx
  UFG::DataStreamer *v23; // rcx
  UFG::qVector3 velocity; // [rsp+40h] [rbp-48h]

  UFG::DataStreamer::BeginTagging(this);
  if ( UFG::PropSpawnManager::GetInstance() )
  {
    v1 = UFG::PropSpawnManager::GetInstance();
    UFG::PropSpawnManager::Update(v1);
  }
  do
  {
    ((void (*)(void))UFG::BasePhysicsSystem::mInstance->vfptr->PreFrameUpdate)();
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
  v7 = UFG::GetLocalPlayer();
  if ( v7 )
  {
    v9 = v7->m_pTransformNodeComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform(v9);
    UFG::TransformNodeComponent::UpdateWorldTransform(v9);
    *(_QWORD *)&velocity.x = 0i64;
    velocity.z = 0.0;
    v10 = UFG::FlowController::GetCurrentState(&UFG::gFlowController);
    UFG::SectionChooser::AddPOV(
      (UFG::qVector3 *)&v9->mWorldTransform.v3,
      (UFG::qVector3 *)&v9->mWorldTransform,
      (UFG::qVector3 *)&v9->mWorldTransform,
      &velocity,
      0.0,
      0i64,
      0,
      v10 == uidGameStateInGame_11);
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
  v12 = UFG::GetTriggerUpdateContext((UFG::TriggerUpdateContext *)&velocity);
  UFG::TriggerRegion::UpdateAll(v12);
  v13 = UFG::GetTriggerUpdateContext((UFG::TriggerUpdateContext *)&velocity);
  UFG::TriggerRegion::UpdateAll(v13);
  UFG::DataStreamer::EndTagging(v14);
  UFG::DataStreamer::BeginTagging(v15);
  do
  {
    ((void (*)(void))UFG::BasePhysicsSystem::mInstance->vfptr->PreFrameUpdate)();
    v16 = UFG::GetLayerLoadPosition(&velocity);
    v17 = UFG::GeographicalLayerManager::GetInstance();
    UFG::GeographicalLayerManager::Update(v17, 0.017000001, v16);
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

