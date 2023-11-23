// File Line: 267
// RVA: 0x58CB20
void __fastcall UFG::TeleportHander(UFG::Event *thisEvent)
{
  UFG::qSymbol *v2; // rax
  UFG::qBaseNodeRB *SimObject; // rax
  UFG::SimObjectCharacter *v4; // rdi
  __int16 v5; // cx
  UFG::SceneObjectProperties *v6; // rcx
  UFG::TransformNodeComponent *m_pComponent; // rcx
  UFG::AICharacterControllerBaseComponent *v8; // rax
  UFG::RagdollComponent *v9; // rcx
  UFG::CharacterPhysicsComponent *v10; // rcx
  UFG::ActionTreeComponent *v11; // rcx
  UFG::RoadSpaceComponent *v12; // rcx
  UFG::TargetingSystemPedBaseComponent *v13; // rax
  UFG::AILightWeightComponent *ComponentOfTypeHK; // rax
  UFG::RigidBodyComponent *v15; // rax
  UFG::AimingPlayerComponent *v16; // rax
  UFG::CharacterSubjectComponent *v17; // rax
  UFG::InterestPoint *v18; // rcx
  UFG::CarHumanDriverComponent *v19; // rax
  AMD_HD3D *v20; // rax
  UFG::ActorAudioComponent *v21; // rax
  UFG::NavComponent *v22; // rcx
  UFG::CompositeDrawableComponent *v23; // rcx
  UFG::SceneObjectProperties *v24; // rcx
  UFG::TransformNodeComponent *v25; // rcx
  UFG::AICharacterControllerBaseComponent *v26; // rax
  UFG::SensorComponent *v27; // rcx
  UFG::ActionTreeComponent *v28; // rcx
  UFG::RoadSpaceComponent *v29; // rcx
  UFG::VehicleOccupantComponent *v30; // rcx
  UFG::SimComponent *v31; // rcx
  UFG::TargetingSystemPedBaseComponent *v32; // rax
  UFG::RigidBodyComponent *v33; // rax
  UFG::VehicleSubjectComponent *v34; // rax
  UFG::InterestPoint *v35; // rcx
  UFG::CarHumanDriverComponent *v36; // rax
  AMD_HD3D *v37; // rax
  UFG::AIOutlineComponent *v38; // rcx
  UFG::SceneObjectProperties *v39; // rcx
  UFG::TransformNodeComponent *v40; // rcx
  UFG::CharacterPhysicsComponent *v41; // rax
  UFG::ActionTreeComponent *v42; // rcx
  UFG::RigidBodyComponent *ComponentOfType; // rbp
  UFG::TransformNodeComponent *v44; // rbx
  UFG::InterestPoint *v45; // rcx
  UFG::AIOutlineComponent *v46; // rax
  UFG::SceneObjectProperties *v47; // rcx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rcx
  UFG::ActionTreeComponent *v49; // rax
  UFG::RigidBodyComponent *v50; // rax
  UFG::InterestPoint *v51; // rax
  UFG::AILightWeightComponent *v52; // rax
  UFG::AIOutlineComponent *v53; // rax
  Render::DynamicLightComponent *v54; // rax
  Render::IrradianceVolumeComponent *v55; // rax
  UFG::qWiseSymbol result; // [rsp+30h] [rbp+8h] BYREF

  v2 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&result, (unsigned int)thisEvent[1].vfptr);
  SimObject = UFG::Simulation::GetSimObject(&UFG::gSim, v2);
  v4 = (UFG::SimObjectCharacter *)SimObject;
  if ( SimObject )
  {
    v5 = WORD2(SimObject[2].mChild[0]);
    if ( (v5 & 0x4000) != 0 )
    {
      v6 = (UFG::SceneObjectProperties *)SimObject[3].mChild[0]->mChild[1];
      if ( v6 )
        UFG::SceneObjectProperties::OnTeleportEvent(v6, thisEvent);
      m_pComponent = (UFG::TransformNodeComponent *)v4->m_Components.p[2].m_pComponent;
      if ( m_pComponent )
        UFG::TransformNodeComponent::TeleportEventHandler(m_pComponent, thisEvent);
      v8 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v4);
      if ( v8 )
        UFG::AICharacterControllerBaseComponent::TeleportEventHandler(v8, thisEvent);
      v9 = (UFG::RagdollComponent *)v4->m_Components.p[42].m_pComponent;
      if ( v9 )
        UFG::RagdollComponent::TeleportEventHandler(v9, thisEvent);
      v10 = (UFG::CharacterPhysicsComponent *)v4->m_Components.p[27].m_pComponent;
      if ( v10 )
        UFG::CharacterPhysicsComponent::TeleportEventHandler(v10, thisEvent);
      v11 = (UFG::ActionTreeComponent *)v4->m_Components.p[7].m_pComponent;
      if ( v11 )
        UFG::ActionTreeComponent::TeleportEventHandler(v11, thisEvent);
      v12 = (UFG::RoadSpaceComponent *)v4->m_Components.p[24].m_pComponent;
      if ( v12 )
        UFG::RoadSpaceComponent::TeleportEventHandler(v12, thisEvent);
      v13 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedBaseComponent>(v4);
      if ( v13 )
        v13->UFG::TargetingSystemBaseComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[23].__vecDelDtor(
          v13,
          (unsigned int)thisEvent);
      ComponentOfTypeHK = (UFG::AILightWeightComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           v4,
                                                           UFG::AILightWeightComponent::_TypeUID);
      if ( ComponentOfTypeHK )
        UFG::AILightWeightComponent::TeleportEventHandler(ComponentOfTypeHK, thisEvent);
      v15 = (UFG::RigidBodyComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::RigidBodyComponent::_TypeUID);
      if ( v15 )
        UFG::RigidBodyComponent::TeleportEventHandler(v15, thisEvent);
      v16 = UFG::SimObjectCharacter::GetComponent<UFG::AimingPlayerComponent>(v4);
      if ( v16 )
        UFG::AimingPlayerComponent::TeleportEventHandler(v16, thisEvent);
      v17 = UFG::SimObjectCharacter::GetComponent<UFG::CharacterSubjectComponent>(v4);
      if ( v17 )
        UFG::CharacterSubjectComponent::TeleportEventHandler(v17, thisEvent);
      v18 = (UFG::InterestPoint *)v4->m_Components.p[25].m_pComponent;
      if ( v18 )
        UFG::InterestPoint::TeleportEventHandler(v18, thisEvent);
      v19 = UFG::SimObjectCVBase::GetComponent<UFG::CarHumanDriverComponent>(v4);
      if ( v19 )
        UFG::CarHumanDriverComponent::TeleportEventHandler(v19, thisEvent);
      v20 = (AMD_HD3D *)UFG::SimObjectCVBase::GetComponent<UFG::RemoteDriverComponent>(v4);
      if ( v20 )
        _(v20);
      v21 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v4);
      if ( v21 )
        UFG::ActorAudioComponent::TeleportEventHandler(v21, thisEvent);
      v22 = (UFG::NavComponent *)v4->m_Components.p[36].m_pComponent;
      if ( v22 )
        UFG::NavComponent::TeleportEventHandler(v22, thisEvent);
      v23 = (UFG::CompositeDrawableComponent *)v4->m_Components.p[14].m_pComponent;
      if ( v23 )
        UFG::CompositeDrawableComponent::TeleportEventHandler(v23, thisEvent);
    }
    else if ( v5 >= 0 )
    {
      if ( (v5 & 0x2000) != 0 )
      {
        v39 = (UFG::SceneObjectProperties *)SimObject[3].mChild[0]->mChild[1];
        if ( v39 )
          UFG::SceneObjectProperties::OnTeleportEvent(v39, thisEvent);
        v40 = (UFG::TransformNodeComponent *)v4->m_Components.p[2].m_pComponent;
        if ( v40 )
          UFG::TransformNodeComponent::TeleportEventHandler(v40, thisEvent);
        v41 = (UFG::CharacterPhysicsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  v4,
                                                  UFG::CharacterPhysicsComponent::_TypeUID);
        if ( v41 )
          UFG::CharacterPhysicsComponent::TeleportEventHandler(v41, thisEvent);
        v42 = (UFG::ActionTreeComponent *)v4->m_Components.p[6].m_pComponent;
        if ( v42 )
          UFG::ActionTreeComponent::TeleportEventHandler(v42, thisEvent);
        ComponentOfType = (UFG::RigidBodyComponent *)UFG::SimObject::GetComponentOfType(
                                                       v4,
                                                       UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                                                       0,
                                                       0i64);
        if ( ComponentOfType )
        {
          do
          {
            v44 = UFG::SimObject::GetComponentOfType(
                    v4,
                    UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                    0,
                    ComponentOfType);
            UFG::RigidBodyComponent::TeleportEventHandler(ComponentOfType, thisEvent);
            ComponentOfType = (UFG::RigidBodyComponent *)v44;
          }
          while ( v44 );
        }
        v45 = (UFG::InterestPoint *)v4->m_Components.p[10].m_pComponent;
        if ( v45 )
          UFG::InterestPoint::TeleportEventHandler(v45, thisEvent);
        v46 = (UFG::AIOutlineComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::AIOutlineComponent::_TypeUID);
        if ( v46 )
          UFG::AIOutlineComponent::ForceUpdate(v46, thisEvent);
      }
      else
      {
        v47 = (UFG::SceneObjectProperties *)SimObject[2].mChild[1];
        if ( v47 )
          UFG::SceneObjectProperties::OnTeleportEvent(v47, thisEvent);
        m_pTransformNodeComponent = v4->m_pTransformNodeComponent;
        if ( m_pTransformNodeComponent )
          UFG::TransformNodeComponent::TeleportEventHandler(m_pTransformNodeComponent, thisEvent);
        v49 = (UFG::ActionTreeComponent *)UFG::SimObject::GetComponentOfType(v4, UFG::ActionTreeComponent::_TypeUID);
        if ( v49 )
          UFG::ActionTreeComponent::TeleportEventHandler(v49, thisEvent);
        v50 = (UFG::RigidBodyComponent *)UFG::SimObject::GetComponentOfType(v4, UFG::RigidBodyComponent::_TypeUID);
        if ( v50 )
          UFG::RigidBodyComponent::TeleportEventHandler(v50, thisEvent);
        v51 = (UFG::InterestPoint *)UFG::SimObject::GetComponentOfType(v4, UFG::InterestPoint::_TypeUID);
        if ( v51 )
          UFG::InterestPoint::TeleportEventHandler(v51, thisEvent);
        v52 = (UFG::AILightWeightComponent *)UFG::SimObject::GetComponentOfType(
                                               v4,
                                               UFG::AILightWeightComponent::_TypeUID);
        if ( v52 )
          UFG::AILightWeightComponent::TeleportEventHandler(v52, thisEvent);
        v53 = (UFG::AIOutlineComponent *)UFG::SimObject::GetComponentOfType(v4, UFG::AIOutlineComponent::_TypeUID);
        if ( v53 )
          UFG::AIOutlineComponent::ForceUpdate(v53, thisEvent);
        v54 = (Render::DynamicLightComponent *)UFG::SimObject::GetComponentOfType(
                                                 v4,
                                                 Render::DynamicLightComponent::_TypeUID);
        if ( v54 )
          Render::DynamicLightComponent::TeleportEventHandler(v54, thisEvent);
        v55 = (Render::IrradianceVolumeComponent *)UFG::SimObject::GetComponentOfType(
                                                     v4,
                                                     Render::IrradianceVolumeComponent::_TypeUID);
        if ( v55 )
          Render::IrradianceVolumeComponent::TeleportEventHandler(v55, thisEvent);
      }
    }
    else
    {
      v24 = (UFG::SceneObjectProperties *)SimObject[3].mChild[0]->mChild[1];
      if ( v24 )
        UFG::SceneObjectProperties::OnTeleportEvent(v24, thisEvent);
      v25 = (UFG::TransformNodeComponent *)v4->m_Components.p[2].m_pComponent;
      if ( v25 )
        UFG::TransformNodeComponent::TeleportEventHandler(v25, thisEvent);
      v26 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v4);
      if ( v26 )
        UFG::AICharacterControllerBaseComponent::TeleportEventHandler(v26, thisEvent);
      v27 = (UFG::SensorComponent *)v4->m_Components.p[26].m_pComponent;
      if ( v27 )
        UFG::SensorComponent::TeleportEventHandler(v27, thisEvent);
      v28 = (UFG::ActionTreeComponent *)v4->m_Components.p[7].m_pComponent;
      if ( v28 )
        UFG::ActionTreeComponent::TeleportEventHandler(v28, thisEvent);
      v29 = (UFG::RoadSpaceComponent *)v4->m_Components.p[24].m_pComponent;
      if ( v29 )
        UFG::RoadSpaceComponent::TeleportEventHandler(v29, thisEvent);
      v30 = (UFG::VehicleOccupantComponent *)v4->m_Components.p[30].m_pComponent;
      if ( v30 )
        UFG::VehicleOccupantComponent::TeleportEventHandler(v30, thisEvent);
      v31 = v4->m_Components.p[34].m_pComponent;
      if ( v31 )
        v31->vfptr[15].__vecDelDtor(v31, (unsigned int)thisEvent);
      v32 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedBaseComponent>(v4);
      if ( v32 )
        v32->UFG::TargetingSystemBaseComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[23].__vecDelDtor(
          v32,
          (unsigned int)thisEvent);
      v33 = (UFG::RigidBodyComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::RigidBodyComponent::_TypeUID);
      if ( v33 )
        UFG::RigidBodyComponent::TeleportEventHandler(v33, thisEvent);
      v34 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleSubjectComponent>((UFG::SimObjectVehicle *)v4);
      if ( v34 )
        UFG::VehicleSubjectComponent::TeleportEventHandler(v34, thisEvent);
      v35 = (UFG::InterestPoint *)v4->m_Components.p[25].m_pComponent;
      if ( v35 )
        UFG::InterestPoint::TeleportEventHandler(v35, thisEvent);
      v36 = UFG::SimObjectCVBase::GetComponent<UFG::CarHumanDriverComponent>(v4);
      if ( v36 )
        UFG::CarHumanDriverComponent::TeleportEventHandler(v36, thisEvent);
      v37 = (AMD_HD3D *)UFG::SimObjectCVBase::GetComponent<UFG::RemoteDriverComponent>(v4);
      if ( v37 )
        _(v37);
      v38 = (UFG::AIOutlineComponent *)v4->m_Components.p[27].m_pComponent;
      if ( v38 )
        UFG::AIOutlineComponent::ForceUpdate(v38, thisEvent);
    }
  }
}

// File Line: 367
// RVA: 0x15523D0
__int64 UFG::_dynamic_initializer_for__gTeleportChannel__()
{
  UFG::ChannelObj::ChannelObj(&UFG::gTeleportChannel, "EVT_Teleport", "blahblah");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gTeleportChannel__);
}

// File Line: 380
// RVA: 0x583CA0
void __fastcall UFG::InitSim(UFG *this)
{
  void (__fastcall *v1)(fastdelegate::detail::GenericClass *); // rax
  AMD_HD3D *v2; // rcx
  UFG::DaemonManager *v3; // rdi
  UFG::allocator::free_link *v4; // rax
  UFG::RoadNetworkVisibleAreaEdge *v5; // rbx
  fastdelegate::FastDelegate1<UFG::Event *,void> v6; // [rsp+38h] [rbp-30h] BYREF
  void (__fastcall *v7)(UFG::Event *); // [rsp+48h] [rbp-20h]
  void (__fastcall *v8)(fastdelegate::detail::GenericClass *); // [rsp+50h] [rbp-18h]

  UFG::VehicleEffectsComponent::Initialize();
  UFG::SceneObjectProperties::mspActivateFunc = UFG::ComponentFactory::PropertiesOnActivate;
  UFG::SceneObjectProperties::mspDeactivateFunc = (void (__fastcall *)(UFG::SceneObjectProperties *))_;
  UFG::SceneObjectProperties::mspSimObjectFactoryFunc = SimObjectFactory::CreateSimObject;
  UFG::ModelAssetComponent::SetPostComponentFactory(UFG::ComponentFactory::PostComponentFactory);
  v1 = (void (__fastcall *)(fastdelegate::detail::GenericClass *))fastdelegate::FastDelegate1<char const *,void>::InvokeStaticFunction;
  if ( !UFG::TeleportHander )
    v1 = 0i64;
  v8 = v1;
  v7 = UFG::TeleportHander;
  v6.m_Closure.m_pFunction = v1;
  v6.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)UFG::TeleportHander;
  UFG::EventDispatcher::Register(
    &UFG::EventDispatcher::mInstance,
    &v6,
    UFG::gTeleportChannel.mUID,
    UFG::gTeleportChannel.mName,
    0);
  UFG::NavManager::Initialize();
  _(v2);
  UFG::DaemonManager::Create();
  v3 = UFG::DaemonManager::Instance();
  UFG::DaemonManager::BeginInitialization(v3);
  v4 = UFG::qMalloc(0xB0ui64, "GameNavDaemon", 0i64);
  v5 = (UFG::RoadNetworkVisibleAreaEdge *)v4;
  if ( v4 )
  {
    UFG::HavokNavDaemon::HavokNavDaemon((UFG::HavokNavDaemon *)v4);
    v5->mPrev = (UFG::qNode<UFG::RoadNetworkVisibleAreaEdge,UFG::RoadNetworkVisibleAreaEdge> *)&UFG::GameNavDaemon::`vftable;
  }
  else
  {
    v5 = 0i64;
  }
  UFG::DaemonManager::RegisterDaemon((UFG::RoadNetworkVisibleAreaEdgeManager *)v3, v5);
  UFG::DaemonManager::EndInitialization(v3);
}

// File Line: 414
// RVA: 0x588230
void __fastcall UFG::OpenSim(UFG *this)
{
  UFG::NavSystemBase *v1; // rax
  UFG::allocator::free_link *v2; // rax
  UFG::AIQueryManager *v3; // rax
  void (__fastcall *v4)(fastdelegate::detail::GenericClass *); // rax
  UFG::allocator::free_link *v5; // rax
  UFG::AiCollisionEventHandler *v6; // rax
  UFG::StoreFrontTracker *v7; // rax
  UFG::allocator::free_link *v8; // rax
  UFG::PedKnowledgeLOSSystem *v9; // rax
  fastdelegate::FastDelegate1<UFG::Event *,void> v10; // [rsp+38h] [rbp-30h] BYREF
  void (__fastcall *v11)(UFG::Event *); // [rsp+48h] [rbp-20h]
  void (__fastcall *v12)(fastdelegate::detail::GenericClass *); // [rsp+50h] [rbp-18h]

  UFG::InitCameraView(this);
  UFG::NavAvoidanceManager::CreateInstance();
  UFG::NavAvoidanceManager::EnterGame(UFG::NavAvoidanceManager::mspAvoidanceManager);
  (*((void (__fastcall **)(UFG::NavManager *))&UFG::NavManager::ms_pInstance->vfptr->__vecDelDtor + 1))(UFG::NavManager::ms_pInstance);
  v1 = (UFG::NavSystemBase *)UFG::qMalloc(8ui64, "DerivedNavSystem", 0i64);
  if ( v1 )
    v1->vfptr = (UFG::NavSystemBaseVtbl *)&UFG::NavSystemBase::`vftable;
  else
    v1 = 0i64;
  UFG::NavSystemBase::ms_pInstance = v1;
  v2 = UFG::qMalloc(0x20ui64, "AIQueryManager", 0i64);
  if ( v2 )
    UFG::AIQueryManager::AIQueryManager((UFG::AIQueryManager *)v2);
  else
    v3 = 0i64;
  UFG::AIQueryManager::ms_pInstance = v3;
  v4 = (void (__fastcall *)(fastdelegate::detail::GenericClass *))fastdelegate::FastDelegate1<char const *,void>::InvokeStaticFunction;
  if ( !UFG::AIEntityComponent::EntityDeathHandler )
    v4 = 0i64;
  v12 = v4;
  v11 = UFG::AIEntityComponent::EntityDeathHandler;
  v10.m_Closure.m_pFunction = v4;
  v10.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)UFG::AIEntityComponent::EntityDeathHandler;
  UFG::EventDispatcher::Register(&UFG::EventDispatcher::mInstance, &v10, 0x514B87Fu, 0i64, 0);
  v5 = UFG::qMalloc(0x80ui64, "AiCollisionEventHandler", 0i64);
  if ( v5 )
    UFG::AiCollisionEventHandler::AiCollisionEventHandler((UFG::AiCollisionEventHandler *)v5);
  else
    v6 = 0i64;
  g_pCollisionEventHandler = v6;
  v7 = UFG::StoreFrontTracker::Instance();
  UFG::StoreFrontTracker::Init(v7);
  UFG::SimAsyncOcclusionQueryManager::Init();
  v8 = UFG::qMalloc(0x3218ui64, "PedKnowledgeLOSSystem", 0i64);
  if ( v8 )
  {
    UFG::PedKnowledgeLOSSystem::PedKnowledgeLOSSystem((UFG::PedKnowledgeLOSSystem *)v8);
    UFG::PedKnowledgeLOSSystem::ms_pInstance = v9;
  }
  else
  {
    UFG::PedKnowledgeLOSSystem::ms_pInstance = 0i64;
  }
}

// File Line: 442
// RVA: 0x57F7D0
void __fastcall UFG::CloseSim(UFG *this)
{
  AMD_HD3D *v1; // rax
  UFG::AiCollisionEventHandler *v2; // rbx
  void (__fastcall *v3)(fastdelegate::detail::GenericClass *); // rax
  AMD_HD3D *v4; // rcx
  UFG::AIQueryManager *v5; // rbx
  UFG::PedKnowledgeLOSSystem *v6; // rbx
  fastdelegate::FastDelegate1<UFG::Event *,void> v7; // [rsp+20h] [rbp-18h] BYREF

  UFG::SimAsyncOcclusionQueryManager::Destroy();
  v1 = (AMD_HD3D *)UFG::StoreFrontTracker::Instance();
  _(v1);
  v2 = g_pCollisionEventHandler;
  if ( g_pCollisionEventHandler )
  {
    UFG::AiCollisionEventHandler::~AiCollisionEventHandler(g_pCollisionEventHandler);
    operator delete[](v2);
  }
  v3 = (void (__fastcall *)(fastdelegate::detail::GenericClass *))fastdelegate::FastDelegate1<char const *,void>::InvokeStaticFunction;
  v7.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)UFG::AIEntityComponent::EntityDeathHandler;
  if ( !UFG::AIEntityComponent::EntityDeathHandler )
    v3 = 0i64;
  v7.m_Closure.m_pFunction = v3;
  g_pCollisionEventHandler = 0i64;
  UFG::EventDispatcher::UnRegister(&UFG::EventDispatcher::mInstance, &v7, 0x514B87Fu);
  _(v4);
  UFG::Simulation::DestroyAllSimObjects(&UFG::gSim);
  UFG::WheeledVehicleManager::SimJustClosed(UFG::WheeledVehicleManager::m_Instance);
  if ( UFG::NavSystemBase::ms_pInstance )
    ((void (__fastcall *)(UFG::NavSystemBase *, __int64))UFG::NavSystemBase::ms_pInstance->vfptr->~NavSystemBase)(
      UFG::NavSystemBase::ms_pInstance,
      1i64);
  v5 = UFG::AIQueryManager::ms_pInstance;
  UFG::NavSystemBase::ms_pInstance = 0i64;
  if ( UFG::AIQueryManager::ms_pInstance )
  {
    UFG::AIQueryManager::~AIQueryManager(UFG::AIQueryManager::ms_pInstance);
    operator delete[](v5);
  }
  v6 = UFG::PedKnowledgeLOSSystem::ms_pInstance;
  UFG::AIQueryManager::ms_pInstance = 0i64;
  if ( UFG::PedKnowledgeLOSSystem::ms_pInstance )
  {
    UFG::PedKnowledgeLOSSystem::~PedKnowledgeLOSSystem(UFG::PedKnowledgeLOSSystem::ms_pInstance);
    operator delete[](v6);
  }
  UFG::PedKnowledgeLOSSystem::ms_pInstance = 0i64;
  UFG::NavManager::ms_pInstance->vfptr->ExitGame(UFG::NavManager::ms_pInstance);
  UFG::NavAvoidanceManager::DeleteInstance();
}

// File Line: 586
// RVA: 0x58DFD0
void __fastcall UFG::UpdateComponentType_AIAwarenessComponent(float delta_sec)
{
  unsigned __int64 Ticks; // rdi
  UFG::qNode<UFG::AIAwarenessComponent,UFG::AIAwarenessComponent> *v2; // rcx
  unsigned __int64 v3; // rax

  Ticks = UFG::qGetTicks();
  v2 = UFG::AIAwarenessComponent::s_AIAwarenessComponentList.mNode.mNext - 4;
  for ( UFG::AIAwarenessComponent::s_AIAwarenessComponentpCurrentIterator = (UFG::AIAwarenessComponent *)&UFG::AIAwarenessComponent::s_AIAwarenessComponentList.mNode.mNext[-4];
        v2 != (UFG::qNode<UFG::AIAwarenessComponent,UFG::AIAwarenessComponent> *)(&UFG::AIAwarenessComponent::s_AIAwarenessComponentList
                                                                                - 4);
        UFG::AIAwarenessComponent::s_AIAwarenessComponentpCurrentIterator = (UFG::AIAwarenessComponent *)v2 )
  {
    if ( ((__int64)v2[2].mPrev & 3) == 1 )
    {
      UFG::AIAwarenessComponent::Update((UFG::AIAwarenessComponent *)v2, delta_sec);
      v2 = (UFG::qNode<UFG::AIAwarenessComponent,UFG::AIAwarenessComponent> *)UFG::AIAwarenessComponent::s_AIAwarenessComponentpCurrentIterator;
    }
    v2 = v2[4].mNext - 4;
  }
  UFG::AIAwarenessComponent::s_AIAwarenessComponentpCurrentIterator = 0i64;
  v3 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(Ticks, v3);
}

// File Line: 587
// RVA: 0x58E1F0
void __fastcall UFG::UpdateComponentType_ActiveAIEntityComponent(float delta_sec)
{
  unsigned __int64 Ticks; // rdi
  UFG::ActiveAIEntityComponent *p_mNext; // rcx
  unsigned __int64 v3; // rax

  Ticks = UFG::qGetTicks();
  p_mNext = (UFG::ActiveAIEntityComponent *)&UFG::ActiveAIEntityComponent::s_ActiveAIEntityComponentList.mNode.mNext[-84].mNext;
  for ( UFG::ActiveAIEntityComponent::s_ActiveAIEntityComponentpCurrentIterator = (UFG::ActiveAIEntityComponent *)&UFG::ActiveAIEntityComponent::s_ActiveAIEntityComponentList.mNode.mNext[-84].mNext;
        p_mNext != (UFG::ActiveAIEntityComponent *)((char *)&UFG::ActiveAIEntityComponent::s_ActiveAIEntityComponentList
                                                  - 1336);
        UFG::ActiveAIEntityComponent::s_ActiveAIEntityComponentpCurrentIterator = p_mNext )
  {
    if ( (p_mNext->m_Flags & 3) == 1 )
    {
      ((void (__fastcall *)(UFG::ActiveAIEntityComponent *))p_mNext->vfptr[15].__vecDelDtor)(p_mNext);
      p_mNext = UFG::ActiveAIEntityComponent::s_ActiveAIEntityComponentpCurrentIterator;
    }
    p_mNext = (UFG::ActiveAIEntityComponent *)&p_mNext->mNext[-84].mNext;
  }
  UFG::ActiveAIEntityComponent::s_ActiveAIEntityComponentpCurrentIterator = 0i64;
  v3 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(Ticks, v3);
}

// File Line: 589
// RVA: 0x58F110
void __fastcall UFG::UpdateComponentType_InterestPointUserComponent(float delta_sec)
{
  unsigned __int64 Ticks; // rdi
  UFG::qNode<UFG::InterestPointUserComponent,UFG::InterestPointUserComponent> *v2; // rcx
  unsigned __int64 v3; // rax

  Ticks = UFG::qGetTicks();
  v2 = UFG::InterestPointUserComponent::s_InterestPointUserComponentList.mNode.mNext - 4;
  for ( UFG::InterestPointUserComponent::s_InterestPointUserComponentpCurrentIterator = (UFG::InterestPointUserComponent *)&UFG::InterestPointUserComponent::s_InterestPointUserComponentList.mNode.mNext[-4];
        v2 != (UFG::qNode<UFG::InterestPointUserComponent,UFG::InterestPointUserComponent> *)(&UFG::InterestPointUserComponent::s_InterestPointUserComponentList
                                                                                            - 4);
        UFG::InterestPointUserComponent::s_InterestPointUserComponentpCurrentIterator = (UFG::InterestPointUserComponent *)v2 )
  {
    if ( ((__int64)v2[2].mPrev & 3) == 1 )
    {
      UFG::InterestPointUserComponent::Update((UFG::InterestPointUserComponent *)v2, delta_sec);
      v2 = (UFG::qNode<UFG::InterestPointUserComponent,UFG::InterestPointUserComponent> *)UFG::InterestPointUserComponent::s_InterestPointUserComponentpCurrentIterator;
    }
    v2 = v2[4].mNext - 4;
  }
  UFG::InterestPointUserComponent::s_InterestPointUserComponentpCurrentIterator = 0i64;
  v3 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(Ticks, v3);
}

// File Line: 590
// RVA: 0x58EE20
void __fastcall UFG::UpdateComponentType_FormationManagerComponent(float delta_sec)
{
  unsigned __int64 Ticks; // rdi
  UFG::qNode<UFG::FormationManagerComponent,UFG::FormationManagerComponent> *v2; // rcx
  unsigned __int64 v3; // rax

  Ticks = UFG::qGetTicks();
  v2 = UFG::FormationManagerComponent::s_FormationManagerComponentList.mNode.mNext - 4;
  for ( UFG::FormationManagerComponent::s_FormationManagerComponentpCurrentIterator = (UFG::FormationManagerComponent *)&UFG::FormationManagerComponent::s_FormationManagerComponentList.mNode.mNext[-4];
        v2 != (UFG::qNode<UFG::FormationManagerComponent,UFG::FormationManagerComponent> *)(&UFG::FormationManagerComponent::s_FormationManagerComponentList
                                                                                          - 4);
        UFG::FormationManagerComponent::s_FormationManagerComponentpCurrentIterator = (UFG::FormationManagerComponent *)v2 )
  {
    if ( ((__int64)v2[2].mPrev & 3) == 1 )
    {
      ((void (__fastcall *)(UFG::qNode<UFG::FormationManagerComponent,UFG::FormationManagerComponent> *))v2->mPrev[7].mPrev)(v2);
      v2 = (UFG::qNode<UFG::FormationManagerComponent,UFG::FormationManagerComponent> *)UFG::FormationManagerComponent::s_FormationManagerComponentpCurrentIterator;
    }
    v2 = v2[4].mNext - 4;
  }
  UFG::FormationManagerComponent::s_FormationManagerComponentpCurrentIterator = 0i64;
  v3 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(Ticks, v3);
}

// File Line: 591
// RVA: 0x58F270
void __fastcall UFG::UpdateComponentType_PedFormationManagerComponent(float delta_sec)
{
  unsigned __int64 Ticks; // rdi
  UFG::PedFormationManagerComponent *p_mNext; // rdx
  unsigned __int64 v3; // rax

  Ticks = UFG::qGetTicks();
  p_mNext = (UFG::PedFormationManagerComponent *)&UFG::PedFormationManagerComponent::s_PedFormationManagerComponentList.mNode.mNext[-5].mNext;
  for ( UFG::PedFormationManagerComponent::s_PedFormationManagerComponentpCurrentIterator = (UFG::PedFormationManagerComponent *)&UFG::PedFormationManagerComponent::s_PedFormationManagerComponentList.mNode.mNext[-5].mNext;
        p_mNext != (UFG::PedFormationManagerComponent *)((char *)&UFG::PedFormationManagerComponent::s_PedFormationManagerComponentList
                                                       - 72);
        UFG::PedFormationManagerComponent::s_PedFormationManagerComponentpCurrentIterator = p_mNext )
  {
    if ( (p_mNext->m_Flags & 3) == 1 )
    {
      ((void (__fastcall *)(UFG::UpdateInterface *))p_mNext->UFG::UpdateInterface::vfptr->Update)(&p_mNext->UFG::UpdateInterface);
      p_mNext = UFG::PedFormationManagerComponent::s_PedFormationManagerComponentpCurrentIterator;
    }
    p_mNext = (UFG::PedFormationManagerComponent *)&p_mNext->mNext[-5].mNext;
  }
  UFG::PedFormationManagerComponent::s_PedFormationManagerComponentpCurrentIterator = 0i64;
  v3 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(Ticks, v3);
}

// File Line: 592
// RVA: 0x58E4F0
void __fastcall UFG::UpdateComponentType_AttackRightsComponent(float delta_sec)
{
  unsigned __int64 Ticks; // rdi
  UFG::qNode<UFG::AttackRightsComponent,UFG::AttackRightsComponent> *v2; // rcx
  unsigned __int64 v3; // rax

  Ticks = UFG::qGetTicks();
  v2 = UFG::AttackRightsComponent::s_AttackRightsComponentList.mNode.mNext - 4;
  for ( UFG::AttackRightsComponent::s_AttackRightsComponentpCurrentIterator = (UFG::AttackRightsComponent *)&UFG::AttackRightsComponent::s_AttackRightsComponentList.mNode.mNext[-4];
        v2 != (UFG::qNode<UFG::AttackRightsComponent,UFG::AttackRightsComponent> *)(&UFG::AttackRightsComponent::s_AttackRightsComponentList
                                                                                  - 4);
        UFG::AttackRightsComponent::s_AttackRightsComponentpCurrentIterator = (UFG::AttackRightsComponent *)v2 )
  {
    if ( ((__int64)v2[2].mPrev & 3) == 1 )
    {
      ((void (__fastcall *)(UFG::qNode<UFG::AttackRightsComponent,UFG::AttackRightsComponent> *))v2->mPrev[7].mPrev)(v2);
      v2 = (UFG::qNode<UFG::AttackRightsComponent,UFG::AttackRightsComponent> *)UFG::AttackRightsComponent::s_AttackRightsComponentpCurrentIterator;
    }
    v2 = v2[4].mNext - 4;
  }
  UFG::AttackRightsComponent::s_AttackRightsComponentpCurrentIterator = 0i64;
  v3 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(Ticks, v3);
}

// File Line: 593
// RVA: 0x58E140
void __fastcall UFG::UpdateComponentType_AIOutlineComponent(float delta_sec)
{
  unsigned __int64 Ticks; // rdi
  UFG::qNode<UFG::AIOutlineComponent,UFG::AIOutlineComponent> *v2; // rcx
  unsigned __int64 v3; // rax

  Ticks = UFG::qGetTicks();
  v2 = UFG::AIOutlineComponent::s_AIOutlineComponentList.mNode.mNext - 4;
  for ( UFG::AIOutlineComponent::s_AIOutlineComponentpCurrentIterator = (UFG::AIOutlineComponent *)&UFG::AIOutlineComponent::s_AIOutlineComponentList.mNode.mNext[-4];
        v2 != (UFG::qNode<UFG::AIOutlineComponent,UFG::AIOutlineComponent> *)(&UFG::AIOutlineComponent::s_AIOutlineComponentList
                                                                            - 4);
        UFG::AIOutlineComponent::s_AIOutlineComponentpCurrentIterator = (UFG::AIOutlineComponent *)v2 )
  {
    if ( ((__int64)v2[2].mPrev & 3) == 1 )
    {
      UFG::AIOutlineComponent::Update((UFG::AIOutlineComponent *)v2, delta_sec);
      v2 = (UFG::qNode<UFG::AIOutlineComponent,UFG::AIOutlineComponent> *)UFG::AIOutlineComponent::s_AIOutlineComponentpCurrentIterator;
    }
    v2 = v2[4].mNext - 4;
  }
  UFG::AIOutlineComponent::s_AIOutlineComponentpCurrentIterator = 0i64;
  v3 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(Ticks, v3);
}

// File Line: 594
// RVA: 0x58F6C0
void __fastcall UFG::UpdateComponentType_RoadSpaceComponent(float delta_sec)
{
  unsigned __int64 Ticks; // rdi
  UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent> *v2; // rcx
  unsigned __int64 v3; // rax

  Ticks = UFG::qGetTicks();
  v2 = UFG::RoadSpaceComponent::s_RoadSpaceComponentList.mNode.mNext - 4;
  for ( UFG::RoadSpaceComponent::s_RoadSpaceComponentpCurrentIterator = (UFG::RoadSpaceComponent *)&UFG::RoadSpaceComponent::s_RoadSpaceComponentList.mNode.mNext[-4];
        v2 != (UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent> *)(&UFG::RoadSpaceComponent::s_RoadSpaceComponentList
                                                                            - 4);
        UFG::RoadSpaceComponent::s_RoadSpaceComponentpCurrentIterator = (UFG::RoadSpaceComponent *)v2 )
  {
    if ( ((__int64)v2[2].mPrev & 3) == 1 )
    {
      UFG::RoadSpaceComponent::Update((UFG::RoadSpaceComponent *)v2, delta_sec);
      v2 = (UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent> *)UFG::RoadSpaceComponent::s_RoadSpaceComponentpCurrentIterator;
    }
    v2 = v2[4].mNext - 4;
  }
  UFG::RoadSpaceComponent::s_RoadSpaceComponentpCurrentIterator = 0i64;
  v3 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(Ticks, v3);
}

// File Line: 595
// RVA: 0x58E370
void __fastcall UFG::UpdateComponentType_AiDriverComponent(float delta_sec)
{
  unsigned __int64 Ticks; // rdi
  UFG::qNode<UFG::AiDriverComponent,UFG::AiDriverComponent> *v2; // rdx
  unsigned __int64 v3; // rax

  Ticks = UFG::qGetTicks();
  v2 = UFG::AiDriverComponent::s_AiDriverComponentList.mNode.mNext - 19;
  for ( UFG::AiDriverComponent::s_AiDriverComponentpCurrentIterator = (UFG::AiDriverComponent *)&UFG::AiDriverComponent::s_AiDriverComponentList.mNode.mNext[-19];
        v2 != (UFG::qNode<UFG::AiDriverComponent,UFG::AiDriverComponent> *)(&UFG::AiDriverComponent::s_AiDriverComponentList
                                                                          - 19);
        UFG::AiDriverComponent::s_AiDriverComponentpCurrentIterator = (UFG::AiDriverComponent *)v2 )
  {
    if ( ((__int64)v2[2].mPrev & 3) == 1 )
    {
      ((void (__fastcall *)(UFG::qNode<UFG::AiDriverComponent,UFG::AiDriverComponent> *))v2[4].mPrev->mPrev)(&v2[4]);
      v2 = (UFG::qNode<UFG::AiDriverComponent,UFG::AiDriverComponent> *)UFG::AiDriverComponent::s_AiDriverComponentpCurrentIterator;
    }
    v2 = v2[19].mNext - 19;
  }
  UFG::AiDriverComponent::s_AiDriverComponentpCurrentIterator = 0i64;
  v3 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(Ticks, v3);
}

// File Line: 596
// RVA: 0x58F050
void __fastcall UFG::UpdateComponentType_HumanDriverComponent(float delta_sec)
{
  unsigned __int64 Ticks; // rdi
  UFG::qNode<UFG::HumanDriverComponent,UFG::HumanDriverComponent> *v2; // rdx
  unsigned __int64 v3; // rax

  Ticks = UFG::qGetTicks();
  v2 = UFG::HumanDriverComponent::s_HumanDriverComponentList.mNode.mNext - 19;
  for ( UFG::HumanDriverComponent::s_HumanDriverComponentpCurrentIterator = (UFG::HumanDriverComponent *)&UFG::HumanDriverComponent::s_HumanDriverComponentList.mNode.mNext[-19];
        v2 != (UFG::qNode<UFG::HumanDriverComponent,UFG::HumanDriverComponent> *)(&UFG::HumanDriverComponent::s_HumanDriverComponentList
                                                                                - 19);
        UFG::HumanDriverComponent::s_HumanDriverComponentpCurrentIterator = (UFG::HumanDriverComponent *)v2 )
  {
    if ( ((__int64)v2[2].mPrev & 3) == 1 )
    {
      ((void (__fastcall *)(UFG::qNode<UFG::HumanDriverComponent,UFG::HumanDriverComponent> *))v2[4].mPrev->mPrev)(&v2[4]);
      v2 = (UFG::qNode<UFG::HumanDriverComponent,UFG::HumanDriverComponent> *)UFG::HumanDriverComponent::s_HumanDriverComponentpCurrentIterator;
    }
    v2 = v2[19].mNext - 19;
  }
  UFG::HumanDriverComponent::s_HumanDriverComponentpCurrentIterator = 0i64;
  v3 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(Ticks, v3);
}

// File Line: 597
// RVA: 0x58F600
void __fastcall UFG::UpdateComponentType_RemoteDriverComponent(float delta_sec)
{
  unsigned __int64 Ticks; // rdi
  UFG::qNode<UFG::RemoteDriverComponent,UFG::RemoteDriverComponent> *v2; // rdx
  unsigned __int64 v3; // rax

  Ticks = UFG::qGetTicks();
  v2 = UFG::RemoteDriverComponent::s_RemoteDriverComponentList.mNode.mNext - 19;
  for ( UFG::RemoteDriverComponent::s_RemoteDriverComponentpCurrentIterator = (UFG::RemoteDriverComponent *)&UFG::RemoteDriverComponent::s_RemoteDriverComponentList.mNode.mNext[-19];
        v2 != (UFG::qNode<UFG::RemoteDriverComponent,UFG::RemoteDriverComponent> *)(&UFG::RemoteDriverComponent::s_RemoteDriverComponentList
                                                                                  - 19);
        UFG::RemoteDriverComponent::s_RemoteDriverComponentpCurrentIterator = (UFG::RemoteDriverComponent *)v2 )
  {
    if ( ((__int64)v2[2].mPrev & 3) == 1 )
    {
      ((void (__fastcall *)(UFG::qNode<UFG::RemoteDriverComponent,UFG::RemoteDriverComponent> *))v2[4].mPrev->mPrev)(&v2[4]);
      v2 = (UFG::qNode<UFG::RemoteDriverComponent,UFG::RemoteDriverComponent> *)UFG::RemoteDriverComponent::s_RemoteDriverComponentpCurrentIterator;
    }
    v2 = v2[19].mNext - 19;
  }
  UFG::RemoteDriverComponent::s_RemoteDriverComponentpCurrentIterator = 0i64;
  v3 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(Ticks, v3);
}

// File Line: 598
// RVA: 0x58F3E0
void __fastcall UFG::UpdateComponentType_PhysicsMoverInterface(float delta_sec)
{
  unsigned __int64 Ticks; // rdi
  UFG::PhysicsMoverInterface *p_mNext; // rdx
  unsigned __int64 v3; // rax

  Ticks = UFG::qGetTicks();
  p_mNext = (UFG::PhysicsMoverInterface *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList.mNode.mNext[-5].mNext;
  for ( UFG::PhysicsMoverInterface::s_PhysicsMoverInterfacepCurrentIterator = (UFG::PhysicsMoverInterface *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList.mNode.mNext[-5].mNext;
        p_mNext != (UFG::PhysicsMoverInterface *)((char *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList - 72);
        UFG::PhysicsMoverInterface::s_PhysicsMoverInterfacepCurrentIterator = p_mNext )
  {
    if ( (p_mNext->m_Flags & 3) == 1 )
    {
      ((void (__fastcall *)(UFG::UpdateInterface *))p_mNext->UFG::UpdateInterface::vfptr->Update)(&p_mNext->UFG::UpdateInterface);
      p_mNext = UFG::PhysicsMoverInterface::s_PhysicsMoverInterfacepCurrentIterator;
    }
    p_mNext = (UFG::PhysicsMoverInterface *)&p_mNext->mNext[-5].mNext;
  }
  UFG::PhysicsMoverInterface::s_PhysicsMoverInterfacepCurrentIterator = 0i64;
  v3 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(Ticks, v3);
}

// File Line: 599
// RVA: 0x58EC10
void __fastcall UFG::UpdateComponentType_DynamicCoverComponent(float delta_sec)
{
  unsigned __int64 Ticks; // rdi
  UFG::qNode<UFG::DynamicCoverComponent,UFG::DynamicCoverComponent> *v2; // rcx
  unsigned __int64 v3; // rax

  Ticks = UFG::qGetTicks();
  v2 = UFG::DynamicCoverComponent::s_DynamicCoverComponentList.mNode.mNext - 4;
  for ( UFG::DynamicCoverComponent::s_DynamicCoverComponentpCurrentIterator = (UFG::DynamicCoverComponent *)&UFG::DynamicCoverComponent::s_DynamicCoverComponentList.mNode.mNext[-4];
        v2 != (UFG::qNode<UFG::DynamicCoverComponent,UFG::DynamicCoverComponent> *)(&UFG::DynamicCoverComponent::s_DynamicCoverComponentList
                                                                                  - 4);
        UFG::DynamicCoverComponent::s_DynamicCoverComponentpCurrentIterator = (UFG::DynamicCoverComponent *)v2 )
  {
    if ( ((__int64)v2[2].mPrev & 3) == 1 )
    {
      UFG::DynamicCoverComponent::Update((UFG::DynamicCoverComponent *)v2, delta_sec);
      v2 = (UFG::qNode<UFG::DynamicCoverComponent,UFG::DynamicCoverComponent> *)UFG::DynamicCoverComponent::s_DynamicCoverComponentpCurrentIterator;
    }
    v2 = v2[4].mNext - 4;
  }
  UFG::DynamicCoverComponent::s_DynamicCoverComponentpCurrentIterator = 0i64;
  v3 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(Ticks, v3);
}

// File Line: 600
// RVA: 0x58E080
void __fastcall UFG::UpdateComponentType_AICharacterControllerComponent(float delta_sec)
{
  unsigned __int64 Ticks; // rdi
  UFG::AICharacterControllerComponent *p_mNext; // rcx
  unsigned __int64 v3; // rax

  Ticks = UFG::qGetTicks();
  p_mNext = (UFG::AICharacterControllerComponent *)&UFG::AICharacterControllerComponent::s_AICharacterControllerComponentList.mNode.mNext[-68].mNext;
  for ( UFG::AICharacterControllerComponent::s_AICharacterControllerComponentpCurrentIterator = (UFG::AICharacterControllerComponent *)&UFG::AICharacterControllerComponent::s_AICharacterControllerComponentList.mNode.mNext[-68].mNext;
        p_mNext != (UFG::AICharacterControllerComponent *)((char *)&UFG::AICharacterControllerComponent::s_AICharacterControllerComponentList
                                                         - 1080);
        UFG::AICharacterControllerComponent::s_AICharacterControllerComponentpCurrentIterator = p_mNext )
  {
    if ( (p_mNext->m_Flags & 3) == 1 )
    {
      ((void (__fastcall *)(UFG::AICharacterControllerComponent *))p_mNext->vfptr[15].__vecDelDtor)(p_mNext);
      p_mNext = UFG::AICharacterControllerComponent::s_AICharacterControllerComponentpCurrentIterator;
    }
    p_mNext = (UFG::AICharacterControllerComponent *)&p_mNext->UFG::qNode<UFG::AICharacterControllerComponent,UFG::AICharacterControllerComponent>::mNext[-68].mNext;
  }
  UFG::AICharacterControllerComponent::s_AICharacterControllerComponentpCurrentIterator = 0i64;
  v3 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(Ticks, v3);
}

// File Line: 601
// RVA: 0x58EB60
void __fastcall UFG::UpdateComponentType_DialogueAnimationComponent(float delta_sec)
{
  unsigned __int64 Ticks; // rdi
  UFG::qNode<UFG::DialogueAnimationComponent,UFG::DialogueAnimationComponent> *v2; // rcx
  unsigned __int64 v3; // rax

  Ticks = UFG::qGetTicks();
  v2 = UFG::DialogueAnimationComponent::s_DialogueAnimationComponentList.mNode.mNext - 4;
  for ( UFG::DialogueAnimationComponent::s_DialogueAnimationComponentpCurrentIterator = (UFG::DialogueAnimationComponent *)&UFG::DialogueAnimationComponent::s_DialogueAnimationComponentList.mNode.mNext[-4];
        v2 != (UFG::qNode<UFG::DialogueAnimationComponent,UFG::DialogueAnimationComponent> *)(&UFG::DialogueAnimationComponent::s_DialogueAnimationComponentList
                                                                                            - 4);
        UFG::DialogueAnimationComponent::s_DialogueAnimationComponentpCurrentIterator = (UFG::DialogueAnimationComponent *)v2 )
  {
    if ( ((__int64)v2[2].mPrev & 3) == 1 )
    {
      UFG::DialogueAnimationComponent::Update((UFG::DialogueAnimationComponent *)v2, delta_sec);
      v2 = (UFG::qNode<UFG::DialogueAnimationComponent,UFG::DialogueAnimationComponent> *)UFG::DialogueAnimationComponent::s_DialogueAnimationComponentpCurrentIterator;
    }
    v2 = v2[4].mNext - 4;
  }
  UFG::DialogueAnimationComponent::s_DialogueAnimationComponentpCurrentIterator = 0i64;
  v3 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(Ticks, v3);
}

// File Line: 602
// RVA: 0x58F8E0
void __fastcall UFG::UpdateComponentType_TargetingSystemBaseComponent(float delta_sec)
{
  unsigned __int64 Ticks; // rdi
  UFG::TargetingSystemBaseComponent *p_mNext; // rdx
  unsigned __int64 v3; // rax

  Ticks = UFG::qGetTicks();
  p_mNext = (UFG::TargetingSystemBaseComponent *)&UFG::TargetingSystemBaseComponent::s_TargetingSystemBaseComponentList.mNode.mNext[-5].mNext;
  for ( UFG::TargetingSystemBaseComponent::s_TargetingSystemBaseComponentpCurrentIterator = (UFG::TargetingSystemBaseComponent *)&UFG::TargetingSystemBaseComponent::s_TargetingSystemBaseComponentList.mNode.mNext[-5].mNext;
        p_mNext != (UFG::TargetingSystemBaseComponent *)((char *)&UFG::TargetingSystemBaseComponent::s_TargetingSystemBaseComponentList
                                                       - 72);
        UFG::TargetingSystemBaseComponent::s_TargetingSystemBaseComponentpCurrentIterator = p_mNext )
  {
    if ( (p_mNext->m_Flags & 3) == 1 )
    {
      ((void (__fastcall *)(UFG::UpdateInterface *))p_mNext->UFG::UpdateInterface::vfptr->Update)(&p_mNext->UFG::UpdateInterface);
      p_mNext = UFG::TargetingSystemBaseComponent::s_TargetingSystemBaseComponentpCurrentIterator;
    }
    p_mNext = (UFG::TargetingSystemBaseComponent *)&p_mNext->mNext[-5].mNext;
  }
  UFG::TargetingSystemBaseComponent::s_TargetingSystemBaseComponentpCurrentIterator = 0i64;
  v3 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(Ticks, v3);
}

// File Line: 603
// RVA: 0x58F4A0
void __fastcall UFG::UpdateComponentType_PropInteractComponent(float delta_sec)
{
  unsigned __int64 Ticks; // rdi
  UFG::qNode<UFG::PropInteractComponent,UFG::PropInteractComponent> *v2; // rcx
  unsigned __int64 v3; // rax

  Ticks = UFG::qGetTicks();
  v2 = UFG::PropInteractComponent::s_PropInteractComponentList.mNode.mNext - 4;
  for ( UFG::PropInteractComponent::s_PropInteractComponentpCurrentIterator = (UFG::PropInteractComponent *)&UFG::PropInteractComponent::s_PropInteractComponentList.mNode.mNext[-4];
        v2 != (UFG::qNode<UFG::PropInteractComponent,UFG::PropInteractComponent> *)(&UFG::PropInteractComponent::s_PropInteractComponentList
                                                                                  - 4);
        UFG::PropInteractComponent::s_PropInteractComponentpCurrentIterator = (UFG::PropInteractComponent *)v2 )
  {
    if ( ((__int64)v2[2].mPrev & 3) == 1 )
    {
      UFG::PropInteractComponent::Update((UFG::PropInteractComponent *)v2, delta_sec);
      v2 = (UFG::qNode<UFG::PropInteractComponent,UFG::PropInteractComponent> *)UFG::PropInteractComponent::s_PropInteractComponentpCurrentIterator;
    }
    v2 = v2[4].mNext - 4;
  }
  UFG::PropInteractComponent::s_PropInteractComponentpCurrentIterator = 0i64;
  v3 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(Ticks, v3);
}

// File Line: 605
// RVA: 0x58E700
void __fastcall UFG::UpdateComponentType_BoostRegion(float delta_sec)
{
  unsigned __int64 Ticks; // rdi
  UFG::qNode<UFG::BoostRegion,UFG::BoostRegion> *v2; // rcx
  unsigned __int64 v3; // rax

  Ticks = UFG::qGetTicks();
  v2 = UFG::BoostRegion::s_BoostRegionList.mNode.mNext - 7;
  for ( UFG::BoostRegion::s_BoostRegionpCurrentIterator = (UFG::BoostRegion *)&UFG::BoostRegion::s_BoostRegionList.mNode.mNext[-7];
        v2 != (UFG::qNode<UFG::BoostRegion,UFG::BoostRegion> *)(&UFG::BoostRegion::s_BoostRegionList - 7);
        UFG::BoostRegion::s_BoostRegionpCurrentIterator = (UFG::BoostRegion *)v2 )
  {
    if ( ((__int64)v2[2].mPrev & 3) == 1 )
    {
      ((void (__fastcall *)(UFG::qNode<UFG::BoostRegion,UFG::BoostRegion> *))v2->mPrev[8].mNext)(v2);
      v2 = (UFG::qNode<UFG::BoostRegion,UFG::BoostRegion> *)UFG::BoostRegion::s_BoostRegionpCurrentIterator;
    }
    v2 = v2[7].mNext - 7;
  }
  UFG::BoostRegion::s_BoostRegionpCurrentIterator = 0i64;
  v3 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(Ticks, v3);
}

// File Line: 607
// RVA: 0x58ECC0
void __fastcall UFG::UpdateComponentType_FaceActionComponent(float delta_sec)
{
  unsigned __int64 Ticks; // rdi
  UFG::qNode<UFG::FaceActionComponent,UFG::FaceActionComponent> *v2; // rcx
  unsigned __int64 v3; // rax

  Ticks = UFG::qGetTicks();
  v2 = UFG::FaceActionComponent::s_FaceActionComponentList.mNode.mNext - 4;
  for ( UFG::FaceActionComponent::s_FaceActionComponentpCurrentIterator = (UFG::FaceActionComponent *)&UFG::FaceActionComponent::s_FaceActionComponentList.mNode.mNext[-4];
        v2 != (UFG::qNode<UFG::FaceActionComponent,UFG::FaceActionComponent> *)(&UFG::FaceActionComponent::s_FaceActionComponentList
                                                                              - 4);
        UFG::FaceActionComponent::s_FaceActionComponentpCurrentIterator = (UFG::FaceActionComponent *)v2 )
  {
    if ( ((__int64)v2[2].mPrev & 3) == 1 )
    {
      ((void (__fastcall *)(UFG::qNode<UFG::FaceActionComponent,UFG::FaceActionComponent> *))v2->mPrev[7].mPrev)(v2);
      v2 = (UFG::qNode<UFG::FaceActionComponent,UFG::FaceActionComponent> *)UFG::FaceActionComponent::s_FaceActionComponentpCurrentIterator;
    }
    v2 = v2[4].mNext - 4;
  }
  UFG::FaceActionComponent::s_FaceActionComponentpCurrentIterator = 0i64;
  v3 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(Ticks, v3);
}

// File Line: 608
// RVA: 0x58ED70
void __fastcall UFG::UpdateComponentType_FaceMeterComponent(float delta_sec)
{
  unsigned __int64 Ticks; // rdi
  UFG::qNode<UFG::FaceMeterComponent,UFG::FaceMeterComponent> *v2; // rcx
  unsigned __int64 v3; // rax

  Ticks = UFG::qGetTicks();
  v2 = UFG::FaceMeterComponent::s_FaceMeterComponentList.mNode.mNext - 4;
  for ( UFG::FaceMeterComponent::s_FaceMeterComponentpCurrentIterator = (UFG::FaceMeterComponent *)&UFG::FaceMeterComponent::s_FaceMeterComponentList.mNode.mNext[-4];
        v2 != (UFG::qNode<UFG::FaceMeterComponent,UFG::FaceMeterComponent> *)(&UFG::FaceMeterComponent::s_FaceMeterComponentList
                                                                            - 4);
        UFG::FaceMeterComponent::s_FaceMeterComponentpCurrentIterator = (UFG::FaceMeterComponent *)v2 )
  {
    if ( ((__int64)v2[2].mPrev & 3) == 1 )
    {
      ((void (__fastcall *)(UFG::qNode<UFG::FaceMeterComponent,UFG::FaceMeterComponent> *))v2->mPrev[7].mPrev)(v2);
      v2 = (UFG::qNode<UFG::FaceMeterComponent,UFG::FaceMeterComponent> *)UFG::FaceMeterComponent::s_FaceMeterComponentpCurrentIterator;
    }
    v2 = v2[4].mNext - 4;
  }
  UFG::FaceMeterComponent::s_FaceMeterComponentpCurrentIterator = 0i64;
  v3 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(Ticks, v3);
}

// File Line: 609
// RVA: 0x58F1C0
void __fastcall UFG::UpdateComponentType_MissionFailConditionComponent(float delta_sec)
{
  unsigned __int64 Ticks; // rdi
  UFG::qNode<UFG::MissionFailConditionComponent,UFG::MissionFailConditionComponent> *v2; // rcx
  unsigned __int64 v3; // rax

  Ticks = UFG::qGetTicks();
  v2 = UFG::MissionFailConditionComponent::s_MissionFailConditionComponentList.mNode.mNext - 4;
  for ( UFG::MissionFailConditionComponent::s_MissionFailConditionComponentpCurrentIterator = (UFG::MissionFailConditionComponent *)&UFG::MissionFailConditionComponent::s_MissionFailConditionComponentList.mNode.mNext[-4];
        v2 != (UFG::qNode<UFG::MissionFailConditionComponent,UFG::MissionFailConditionComponent> *)(&UFG::MissionFailConditionComponent::s_MissionFailConditionComponentList
                                                                                                  - 4);
        UFG::MissionFailConditionComponent::s_MissionFailConditionComponentpCurrentIterator = (UFG::MissionFailConditionComponent *)v2 )
  {
    if ( ((__int64)v2[2].mPrev & 3) == 1 )
    {
      UFG::MissionFailConditionComponent::Update((UFG::MissionFailConditionComponent *)v2, delta_sec);
      v2 = (UFG::qNode<UFG::MissionFailConditionComponent,UFG::MissionFailConditionComponent> *)UFG::MissionFailConditionComponent::s_MissionFailConditionComponentpCurrentIterator;
    }
    v2 = v2[4].mNext - 4;
  }
  UFG::MissionFailConditionComponent::s_MissionFailConditionComponentpCurrentIterator = 0i64;
  v3 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(Ticks, v3);
}

// File Line: 610
// RVA: 0x58E9E0
void __fastcall UFG::UpdateComponentType_CopRoadBlock(float delta_sec)
{
  unsigned __int64 Ticks; // rdi
  UFG::qNode<UFG::CopRoadBlock,UFG::CopRoadBlock> *v2; // rcx
  unsigned __int64 v3; // rax

  Ticks = UFG::qGetTicks();
  v2 = UFG::CopRoadBlock::s_CopRoadBlockList.mNode.mNext - 7;
  for ( UFG::CopRoadBlock::s_CopRoadBlockpCurrentIterator = (UFG::CopRoadBlock *)&UFG::CopRoadBlock::s_CopRoadBlockList.mNode.mNext[-7];
        v2 != (UFG::qNode<UFG::CopRoadBlock,UFG::CopRoadBlock> *)(&UFG::CopRoadBlock::s_CopRoadBlockList - 7);
        UFG::CopRoadBlock::s_CopRoadBlockpCurrentIterator = (UFG::CopRoadBlock *)v2 )
  {
    if ( ((__int64)v2[2].mPrev & 3) == 1 )
    {
      ((void (__fastcall *)(UFG::qNode<UFG::CopRoadBlock,UFG::CopRoadBlock> *))v2->mPrev[9].mPrev)(v2);
      v2 = (UFG::qNode<UFG::CopRoadBlock,UFG::CopRoadBlock> *)UFG::CopRoadBlock::s_CopRoadBlockpCurrentIterator;
    }
    v2 = v2[7].mNext - 7;
  }
  UFG::CopRoadBlock::s_CopRoadBlockpCurrentIterator = 0i64;
  v3 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(Ticks, v3);
}

// File Line: 611
// RVA: 0x58EAA0
void __fastcall UFG::UpdateComponentType_CopUnitComponent(float delta_sec)
{
  unsigned __int64 Ticks; // rdi
  UFG::CopUnitComponent *p_mNext; // rdx
  unsigned __int64 v3; // rax

  Ticks = UFG::qGetTicks();
  p_mNext = (UFG::CopUnitComponent *)&UFG::CopUnitComponent::s_CopUnitComponentList.mNode.mNext[-5].mNext;
  for ( UFG::CopUnitComponent::s_CopUnitComponentpCurrentIterator = (UFG::CopUnitComponent *)&UFG::CopUnitComponent::s_CopUnitComponentList.mNode.mNext[-5].mNext;
        p_mNext != (UFG::CopUnitComponent *)((char *)&UFG::CopUnitComponent::s_CopUnitComponentList - 72);
        UFG::CopUnitComponent::s_CopUnitComponentpCurrentIterator = p_mNext )
  {
    if ( (p_mNext->m_Flags & 3) == 1 )
    {
      ((void (__fastcall *)(UFG::UpdateInterface *))p_mNext->UFG::UpdateInterface::vfptr->Update)(&p_mNext->UFG::UpdateInterface);
      p_mNext = UFG::CopUnitComponent::s_CopUnitComponentpCurrentIterator;
    }
    p_mNext = (UFG::CopUnitComponent *)&p_mNext->mNext[-5].mNext;
  }
  UFG::CopUnitComponent::s_CopUnitComponentpCurrentIterator = 0i64;
  v3 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(Ticks, v3);
}

// File Line: 619
// RVA: 0x58FB20
void __fastcall UFG::UpdateComponentType_WorldContextComponent(float delta_sec)
{
  unsigned __int64 Ticks; // rdi
  UFG::qNode<UFG::WorldContextComponent,UFG::WorldContextComponent> *v2; // rcx
  unsigned __int64 v3; // rax

  Ticks = UFG::qGetTicks();
  v2 = UFG::WorldContextComponent::s_WorldContextComponentList.mNode.mNext - 4;
  for ( UFG::WorldContextComponent::s_WorldContextComponentpCurrentIterator = (UFG::WorldContextComponent *)&UFG::WorldContextComponent::s_WorldContextComponentList.mNode.mNext[-4];
        v2 != (UFG::qNode<UFG::WorldContextComponent,UFG::WorldContextComponent> *)(&UFG::WorldContextComponent::s_WorldContextComponentList
                                                                                  - 4);
        UFG::WorldContextComponent::s_WorldContextComponentpCurrentIterator = (UFG::WorldContextComponent *)v2 )
  {
    if ( ((__int64)v2[2].mPrev & 3) == 1 )
    {
      UFG::WorldContextComponent::Update((UFG::WorldContextComponent *)v2, delta_sec);
      v2 = (UFG::qNode<UFG::WorldContextComponent,UFG::WorldContextComponent> *)UFG::WorldContextComponent::s_WorldContextComponentpCurrentIterator;
    }
    v2 = v2[4].mNext - 4;
  }
  UFG::WorldContextComponent::s_WorldContextComponentpCurrentIterator = 0i64;
  v3 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(Ticks, v3);
}

// File Line: 622
// RVA: 0x58FA60
void __fastcall UFG::UpdateComponentType_VehicleAudioComponent(float delta_sec)
{
  unsigned __int64 Ticks; // rdi
  UFG::qNode<UFG::VehicleAudioComponent,UFG::VehicleAudioComponent> *v2; // rcx
  unsigned __int64 v3; // rax

  Ticks = UFG::qGetTicks();
  v2 = UFG::VehicleAudioComponent::s_VehicleAudioComponentList.mNode.mNext - 24;
  for ( UFG::VehicleAudioComponent::s_VehicleAudioComponentpCurrentIterator = (UFG::VehicleAudioComponent *)&UFG::VehicleAudioComponent::s_VehicleAudioComponentList.mNode.mNext[-24];
        v2 != (UFG::qNode<UFG::VehicleAudioComponent,UFG::VehicleAudioComponent> *)(&UFG::VehicleAudioComponent::s_VehicleAudioComponentList
                                                                                  - 24);
        UFG::VehicleAudioComponent::s_VehicleAudioComponentpCurrentIterator = (UFG::VehicleAudioComponent *)v2 )
  {
    if ( ((__int64)v2[2].mPrev & 3) == 1 )
    {
      ((void (__fastcall *)(UFG::qNode<UFG::VehicleAudioComponent,UFG::VehicleAudioComponent> *))v2->mPrev[7].mPrev)(v2);
      v2 = (UFG::qNode<UFG::VehicleAudioComponent,UFG::VehicleAudioComponent> *)UFG::VehicleAudioComponent::s_VehicleAudioComponentpCurrentIterator;
    }
    v2 = v2[24].mNext - 24;
  }
  UFG::VehicleAudioComponent::s_VehicleAudioComponentpCurrentIterator = 0i64;
  v3 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(Ticks, v3);
}

// File Line: 623
// RVA: 0x58E2B0
void __fastcall UFG::UpdateComponentType_ActorAudioComponent(float delta_sec)
{
  unsigned __int64 Ticks; // rdi
  UFG::qNode<UFG::ActorAudioComponent,UFG::ActorAudioComponent> *v2; // rcx
  unsigned __int64 v3; // rax

  Ticks = UFG::qGetTicks();
  v2 = UFG::ActorAudioComponent::s_ActorAudioComponentList.mNode.mNext - 24;
  for ( UFG::ActorAudioComponent::s_ActorAudioComponentpCurrentIterator = (UFG::ActorAudioComponent *)&UFG::ActorAudioComponent::s_ActorAudioComponentList.mNode.mNext[-24];
        v2 != (UFG::qNode<UFG::ActorAudioComponent,UFG::ActorAudioComponent> *)(&UFG::ActorAudioComponent::s_ActorAudioComponentList
                                                                              - 24);
        UFG::ActorAudioComponent::s_ActorAudioComponentpCurrentIterator = (UFG::ActorAudioComponent *)v2 )
  {
    if ( ((__int64)v2[2].mPrev & 3) == 1 )
    {
      ((void (__fastcall *)(UFG::qNode<UFG::ActorAudioComponent,UFG::ActorAudioComponent> *))v2->mPrev[7].mPrev)(v2);
      v2 = (UFG::qNode<UFG::ActorAudioComponent,UFG::ActorAudioComponent> *)UFG::ActorAudioComponent::s_ActorAudioComponentpCurrentIterator;
    }
    v2 = v2[24].mNext - 24;
  }
  UFG::ActorAudioComponent::s_ActorAudioComponentpCurrentIterator = 0i64;
  v3 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(Ticks, v3);
}

// File Line: 624
// RVA: 0x58E5A0
void __fastcall UFG::UpdateComponentType_AudioEmitterComponent(float delta_sec)
{
  unsigned __int64 Ticks; // rdi
  UFG::qNode<UFG::AudioEmitterComponent,UFG::AudioEmitterComponent> *v2; // rcx
  unsigned __int64 v3; // rax

  Ticks = UFG::qGetTicks();
  v2 = UFG::AudioEmitterComponent::s_AudioEmitterComponentList.mNode.mNext - 4;
  for ( UFG::AudioEmitterComponent::s_AudioEmitterComponentpCurrentIterator = (UFG::AudioEmitterComponent *)&UFG::AudioEmitterComponent::s_AudioEmitterComponentList.mNode.mNext[-4];
        v2 != (UFG::qNode<UFG::AudioEmitterComponent,UFG::AudioEmitterComponent> *)(&UFG::AudioEmitterComponent::s_AudioEmitterComponentList
                                                                                  - 4);
        UFG::AudioEmitterComponent::s_AudioEmitterComponentpCurrentIterator = (UFG::AudioEmitterComponent *)v2 )
  {
    if ( ((__int64)v2[2].mPrev & 3) == 1 )
    {
      UFG::AudioEmitterComponent::Update((UFG::AudioEmitterComponent *)v2, delta_sec);
      v2 = (UFG::qNode<UFG::AudioEmitterComponent,UFG::AudioEmitterComponent> *)UFG::AudioEmitterComponent::s_AudioEmitterComponentpCurrentIterator;
    }
    v2 = v2[4].mNext - 4;
  }
  UFG::AudioEmitterComponent::s_AudioEmitterComponentpCurrentIterator = 0i64;
  v3 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(Ticks, v3);
}

// File Line: 625
// RVA: 0x58F820
void __fastcall UFG::UpdateComponentType_SimObjectWeaponPropertiesComponent(float delta_sec)
{
  unsigned __int64 Ticks; // rdi
  UFG::SimObjectWeaponPropertiesComponent *p_mNext; // rcx
  unsigned __int64 v3; // rax

  Ticks = UFG::qGetTicks();
  p_mNext = (UFG::SimObjectWeaponPropertiesComponent *)&UFG::SimObjectWeaponPropertiesComponent::s_SimObjectWeaponPropertiesComponentList.mNode.mNext[-10].mNext;
  for ( UFG::SimObjectWeaponPropertiesComponent::s_SimObjectWeaponPropertiesComponentpCurrentIterator = (UFG::SimObjectWeaponPropertiesComponent *)&UFG::SimObjectWeaponPropertiesComponent::s_SimObjectWeaponPropertiesComponentList.mNode.mNext[-10].mNext;
        p_mNext != (UFG::SimObjectWeaponPropertiesComponent *)((char *)&UFG::SimObjectWeaponPropertiesComponent::s_SimObjectWeaponPropertiesComponentList
                                                             - 152);
        UFG::SimObjectWeaponPropertiesComponent::s_SimObjectWeaponPropertiesComponentpCurrentIterator = p_mNext )
  {
    if ( (p_mNext->m_Flags & 3) == 1 )
    {
      UFG::SimObjectWeaponPropertiesComponent::Update(p_mNext, delta_sec);
      p_mNext = UFG::SimObjectWeaponPropertiesComponent::s_SimObjectWeaponPropertiesComponentpCurrentIterator;
    }
    p_mNext = (UFG::SimObjectWeaponPropertiesComponent *)&p_mNext->UFG::qNode<UFG::SimObjectWeaponPropertiesComponent,UFG::SimObjectWeaponPropertiesComponent>::mNext[-10].mNext;
  }
  UFG::SimObjectWeaponPropertiesComponent::s_SimObjectWeaponPropertiesComponentpCurrentIterator = 0i64;
  v3 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(Ticks, v3);
}

// File Line: 626
// RVA: 0x58E870
void __fastcall UFG::UpdateComponentType_CharacterPhysicsComponent(float delta_sec)
{
  unsigned __int64 Ticks; // rdi
  UFG::CharacterPhysicsComponent *p_mNext; // rcx
  unsigned __int64 v3; // rax

  Ticks = UFG::qGetTicks();
  p_mNext = (UFG::CharacterPhysicsComponent *)&UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList.mNode.mNext[-7].mNext;
  for ( UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentpCurrentIterator = (UFG::CharacterPhysicsComponent *)&UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList.mNode.mNext[-7].mNext;
        p_mNext != (UFG::CharacterPhysicsComponent *)((char *)&UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList
                                                    - 104);
        UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentpCurrentIterator = p_mNext )
  {
    if ( (p_mNext->m_Flags & 3) == 1 )
    {
      ((void (__fastcall *)(UFG::CharacterPhysicsComponent *))p_mNext->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[14].__vecDelDtor)(p_mNext);
      p_mNext = UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentpCurrentIterator;
    }
    p_mNext = (UFG::CharacterPhysicsComponent *)&p_mNext->mNext[-7].mNext;
  }
  UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentpCurrentIterator = 0i64;
  v3 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(Ticks, v3);
}

// File Line: 627
// RVA: 0x58F550
void __fastcall UFG::UpdateComponentType_RagdollComponent(float delta_sec)
{
  unsigned __int64 Ticks; // rdi
  UFG::RagdollComponent *p_mNext; // rcx
  unsigned __int64 v3; // rax

  Ticks = UFG::qGetTicks();
  p_mNext = (UFG::RagdollComponent *)&UFG::RagdollComponent::s_RagdollComponentList.mNode.mNext[-6].mNext;
  for ( UFG::RagdollComponent::s_RagdollComponentpCurrentIterator = (UFG::RagdollComponent *)&UFG::RagdollComponent::s_RagdollComponentList.mNode.mNext[-6].mNext;
        p_mNext != (UFG::RagdollComponent *)((char *)&UFG::RagdollComponent::s_RagdollComponentList - 88);
        UFG::RagdollComponent::s_RagdollComponentpCurrentIterator = p_mNext )
  {
    if ( (p_mNext->m_Flags & 3) == 1 )
    {
      UFG::RagdollComponent::Update(p_mNext, delta_sec);
      p_mNext = UFG::RagdollComponent::s_RagdollComponentpCurrentIterator;
    }
    p_mNext = (UFG::RagdollComponent *)&p_mNext->mNext[-6].mNext;
  }
  UFG::RagdollComponent::s_RagdollComponentpCurrentIterator = 0i64;
  v3 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(Ticks, v3);
}

// File Line: 628
// RVA: 0x58F770
void __fastcall UFG::UpdateComponentType_SensorComponent(float delta_sec)
{
  unsigned __int64 Ticks; // rdi
  UFG::qNode<UFG::SensorComponent,UFG::SensorComponent> *v2; // rcx
  unsigned __int64 v3; // rax

  Ticks = UFG::qGetTicks();
  v2 = UFG::SensorComponent::s_SensorComponentList.mNode.mNext - 4;
  for ( UFG::SensorComponent::s_SensorComponentpCurrentIterator = (UFG::SensorComponent *)&UFG::SensorComponent::s_SensorComponentList.mNode.mNext[-4];
        v2 != (UFG::qNode<UFG::SensorComponent,UFG::SensorComponent> *)(&UFG::SensorComponent::s_SensorComponentList - 4);
        UFG::SensorComponent::s_SensorComponentpCurrentIterator = (UFG::SensorComponent *)v2 )
  {
    if ( ((__int64)v2[2].mPrev & 3) == 1 )
    {
      UFG::SensorComponent::Update((UFG::SensorComponent *)v2, delta_sec);
      v2 = (UFG::qNode<UFG::SensorComponent,UFG::SensorComponent> *)UFG::SensorComponent::s_SensorComponentpCurrentIterator;
    }
    v2 = v2[4].mNext - 4;
  }
  UFG::SensorComponent::s_SensorComponentpCurrentIterator = 0i64;
  v3 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(Ticks, v3);
}

// File Line: 629
// RVA: 0x58F330
void __fastcall UFG::UpdateComponentType_PhantomVolumeComponent(float delta_sec)
{
  unsigned __int64 Ticks; // rdi
  UFG::qNode<UFG::PhantomVolumeComponent,UFG::PhantomVolumeComponent> *v2; // rcx
  unsigned __int64 v3; // rax

  Ticks = UFG::qGetTicks();
  v2 = UFG::PhantomVolumeComponent::s_PhantomVolumeComponentList.mNode.mNext - 4;
  for ( UFG::PhantomVolumeComponent::s_PhantomVolumeComponentpCurrentIterator = (UFG::PhantomVolumeComponent *)&UFG::PhantomVolumeComponent::s_PhantomVolumeComponentList.mNode.mNext[-4];
        v2 != (UFG::qNode<UFG::PhantomVolumeComponent,UFG::PhantomVolumeComponent> *)(&UFG::PhantomVolumeComponent::s_PhantomVolumeComponentList
                                                                                    - 4);
        UFG::PhantomVolumeComponent::s_PhantomVolumeComponentpCurrentIterator = (UFG::PhantomVolumeComponent *)v2 )
  {
    if ( ((__int64)v2[2].mPrev & 3) == 1 )
    {
      UFG::PhantomVolumeComponent::Update((UFG::PhantomVolumeComponent *)v2, delta_sec);
      v2 = (UFG::qNode<UFG::PhantomVolumeComponent,UFG::PhantomVolumeComponent> *)UFG::PhantomVolumeComponent::s_PhantomVolumeComponentpCurrentIterator;
    }
    v2 = v2[4].mNext - 4;
  }
  UFG::PhantomVolumeComponent::s_PhantomVolumeComponentpCurrentIterator = 0i64;
  v3 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(Ticks, v3);
}

// File Line: 630
// RVA: 0x58E7C0
void __fastcall UFG::UpdateComponentType_CharacterEffectsComponent(float delta_sec)
{
  unsigned __int64 Ticks; // rdi
  UFG::qNode<UFG::CharacterEffectsComponent,UFG::CharacterEffectsComponent> *v2; // rcx
  unsigned __int64 v3; // rax

  Ticks = UFG::qGetTicks();
  v2 = UFG::CharacterEffectsComponent::s_CharacterEffectsComponentList.mNode.mNext - 4;
  for ( UFG::CharacterEffectsComponent::s_CharacterEffectsComponentpCurrentIterator = (UFG::CharacterEffectsComponent *)&UFG::CharacterEffectsComponent::s_CharacterEffectsComponentList.mNode.mNext[-4];
        v2 != (UFG::qNode<UFG::CharacterEffectsComponent,UFG::CharacterEffectsComponent> *)(&UFG::CharacterEffectsComponent::s_CharacterEffectsComponentList
                                                                                          - 4);
        UFG::CharacterEffectsComponent::s_CharacterEffectsComponentpCurrentIterator = (UFG::CharacterEffectsComponent *)v2 )
  {
    if ( ((__int64)v2[2].mPrev & 3) == 1 )
    {
      UFG::CharacterEffectsComponent::Update((UFG::CharacterEffectsComponent *)v2, delta_sec);
      v2 = (UFG::qNode<UFG::CharacterEffectsComponent,UFG::CharacterEffectsComponent> *)UFG::CharacterEffectsComponent::s_CharacterEffectsComponentpCurrentIterator;
    }
    v2 = v2[4].mNext - 4;
  }
  UFG::CharacterEffectsComponent::s_CharacterEffectsComponentpCurrentIterator = 0i64;
  v3 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(Ticks, v3);
}

// File Line: 631
// RVA: 0x58E920
void __fastcall UFG::UpdateComponentType_CompositeLookComponent(float delta_sec)
{
  unsigned __int64 Ticks; // rdi
  UFG::qNode<UFG::CompositeLookComponent,UFG::CompositeLookComponent> *v2; // rdx
  unsigned __int64 v3; // rax

  Ticks = UFG::qGetTicks();
  v2 = UFG::CompositeLookComponent::s_CompositeLookComponentList.mNode.mNext - 5;
  for ( UFG::CompositeLookComponent::s_CompositeLookComponentpCurrentIterator = (UFG::CompositeLookComponent *)&UFG::CompositeLookComponent::s_CompositeLookComponentList.mNode.mNext[-5];
        v2 != (UFG::qNode<UFG::CompositeLookComponent,UFG::CompositeLookComponent> *)(&UFG::CompositeLookComponent::s_CompositeLookComponentList
                                                                                    - 5);
        UFG::CompositeLookComponent::s_CompositeLookComponentpCurrentIterator = (UFG::CompositeLookComponent *)v2 )
  {
    if ( ((__int64)v2[2].mPrev & 3) == 1 )
    {
      ((void (__fastcall *)(UFG::qNode<UFG::CompositeLookComponent,UFG::CompositeLookComponent> **))v2[4].mNext->mPrev)(&v2[4].mNext);
      v2 = (UFG::qNode<UFG::CompositeLookComponent,UFG::CompositeLookComponent> *)UFG::CompositeLookComponent::s_CompositeLookComponentpCurrentIterator;
    }
    v2 = v2[5].mNext - 5;
  }
  UFG::CompositeLookComponent::s_CompositeLookComponentpCurrentIterator = 0i64;
  v3 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(Ticks, v3);
}

// File Line: 632
// RVA: 0x58EF90
void __fastcall UFG::UpdateComponentType_HudComponent(float delta_sec)
{
  unsigned __int64 Ticks; // rdi
  UFG::HudComponent *p_mNext; // rdx
  unsigned __int64 v3; // rax

  Ticks = UFG::qGetTicks();
  p_mNext = (UFG::HudComponent *)&UFG::HudComponent::s_HudComponentList.mNode.mNext[-5].mNext;
  for ( UFG::HudComponent::s_HudComponentpCurrentIterator = (UFG::HudComponent *)&UFG::HudComponent::s_HudComponentList.mNode.mNext[-5].mNext;
        p_mNext != (UFG::HudComponent *)((char *)&UFG::HudComponent::s_HudComponentList - 72);
        UFG::HudComponent::s_HudComponentpCurrentIterator = p_mNext )
  {
    if ( (p_mNext->m_Flags & 3) == 1 )
    {
      ((void (__fastcall *)(UFG::UpdateInterface *))p_mNext->UFG::UpdateInterface::vfptr->Update)(&p_mNext->UFG::UpdateInterface);
      p_mNext = UFG::HudComponent::s_HudComponentpCurrentIterator;
    }
    p_mNext = (UFG::HudComponent *)&p_mNext->mNext[-5].mNext;
  }
  UFG::HudComponent::s_HudComponentpCurrentIterator = 0i64;
  v3 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(Ticks, v3);
}

// File Line: 636
// RVA: 0x58EED0
void __fastcall UFG::UpdateComponentType_HitReactionComponent(float delta_sec)
{
  unsigned __int64 Ticks; // rdi
  UFG::HitReactionComponent *p_mNext; // rdx
  unsigned __int64 v3; // rax

  Ticks = UFG::qGetTicks();
  p_mNext = (UFG::HitReactionComponent *)&UFG::HitReactionComponent::s_HitReactionComponentList.mNode.mNext[-5].mNext;
  for ( UFG::HitReactionComponent::s_HitReactionComponentpCurrentIterator = (UFG::HitReactionComponent *)&UFG::HitReactionComponent::s_HitReactionComponentList.mNode.mNext[-5].mNext;
        p_mNext != (UFG::HitReactionComponent *)((char *)&UFG::HitReactionComponent::s_HitReactionComponentList - 72);
        UFG::HitReactionComponent::s_HitReactionComponentpCurrentIterator = p_mNext )
  {
    if ( (p_mNext->m_Flags & 3) == 1 )
    {
      ((void (__fastcall *)(UFG::UpdateInterface *))p_mNext->UFG::UpdateInterface::vfptr->Update)(&p_mNext->UFG::UpdateInterface);
      p_mNext = UFG::HitReactionComponent::s_HitReactionComponentpCurrentIterator;
    }
    p_mNext = (UFG::HitReactionComponent *)&p_mNext->mNext[-5].mNext;
  }
  UFG::HitReactionComponent::s_HitReactionComponentpCurrentIterator = 0i64;
  v3 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(Ticks, v3);
}

// File Line: 637
// RVA: 0x58E430
void __fastcall UFG::UpdateComponentType_AimingBaseComponent(float delta_sec)
{
  unsigned __int64 Ticks; // rdi
  UFG::AimingBaseComponent *p_mNext; // rdx
  unsigned __int64 v3; // rax

  Ticks = UFG::qGetTicks();
  p_mNext = (UFG::AimingBaseComponent *)&UFG::AimingBaseComponent::s_AimingBaseComponentList.mNode.mNext[-5].mNext;
  for ( UFG::AimingBaseComponent::s_AimingBaseComponentpCurrentIterator = (UFG::AimingBaseComponent *)&UFG::AimingBaseComponent::s_AimingBaseComponentList.mNode.mNext[-5].mNext;
        p_mNext != (UFG::AimingBaseComponent *)((char *)&UFG::AimingBaseComponent::s_AimingBaseComponentList - 72);
        UFG::AimingBaseComponent::s_AimingBaseComponentpCurrentIterator = p_mNext )
  {
    if ( (p_mNext->m_Flags & 3) == 1 )
    {
      ((void (__fastcall *)(UFG::UpdateInterface *))p_mNext->UFG::UpdateInterface::vfptr->Update)(&p_mNext->UFG::UpdateInterface);
      p_mNext = UFG::AimingBaseComponent::s_AimingBaseComponentpCurrentIterator;
    }
    p_mNext = (UFG::AimingBaseComponent *)&p_mNext->mNext[-5].mNext;
  }
  UFG::AimingBaseComponent::s_AimingBaseComponentpCurrentIterator = 0i64;
  v3 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(Ticks, v3);
}

// File Line: 640
// RVA: 0x58F9A0
void __fastcall UFG::UpdateComponentType_UELComponent(float delta_sec)
{
  unsigned __int64 Ticks; // rdi
  UFG::UELComponent *p_mNext; // rdx
  unsigned __int64 v3; // rax

  Ticks = UFG::qGetTicks();
  p_mNext = (UFG::UELComponent *)&UFG::UELComponent::s_UELComponentList.mNode.mNext[-5].mNext;
  for ( UFG::UELComponent::s_UELComponentpCurrentIterator = (UFG::UELComponent *)&UFG::UELComponent::s_UELComponentList.mNode.mNext[-5].mNext;
        p_mNext != (UFG::UELComponent *)((char *)&UFG::UELComponent::s_UELComponentList - 72);
        UFG::UELComponent::s_UELComponentpCurrentIterator = p_mNext )
  {
    if ( (p_mNext->m_Flags & 3) == 1 )
    {
      ((void (__fastcall *)(UFG::UpdateInterface *))p_mNext->UFG::UpdateInterface::vfptr->Update)(&p_mNext->UFG::UpdateInterface);
      p_mNext = UFG::UELComponent::s_UELComponentpCurrentIterator;
    }
    p_mNext = (UFG::UELComponent *)&p_mNext->mNext[-5].mNext;
  }
  UFG::UELComponent::s_UELComponentpCurrentIterator = 0i64;
  v3 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(Ticks, v3);
}

// File Line: 642
// RVA: 0x58BEC0
void __fastcall UFG::SimUpdateTransforms_DialogueAnimationComponent(UFG *this)
{
  unsigned __int64 Ticks; // rax
  UFG::qNode<UFG::DialogueAnimationComponent,UFG::DialogueAnimationComponent> *p_mNode; // rcx
  unsigned __int64 v3; // rsi
  UFG::qList<UFG::DialogueAnimationComponent,UFG::DialogueAnimationComponent,1,0> *v4; // rbx
  unsigned __int64 v5; // rax

  Ticks = UFG::qGetTicks();
  p_mNode = UFG::DialogueAnimationComponent::s_DialogueAnimationComponentList.mNode.mNext - 4;
  v3 = Ticks;
  if ( (UFG::qList<UFG::DialogueAnimationComponent,UFG::DialogueAnimationComponent,1,0> *)&UFG::DialogueAnimationComponent::s_DialogueAnimationComponentList.mNode.mNext[-4] != &UFG::DialogueAnimationComponent::s_DialogueAnimationComponentList - 4 )
  {
    do
    {
      v4 = (UFG::qList<UFG::DialogueAnimationComponent,UFG::DialogueAnimationComponent,1,0> *)&p_mNode[4].mNext[-4];
      _((AMD_HD3D *)p_mNode);
      p_mNode = &v4->mNode;
    }
    while ( v4 != &UFG::DialogueAnimationComponent::s_DialogueAnimationComponentList - 4 );
  }
  v5 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(v3, v5);
}

// File Line: 644
// RVA: 0x58BF40
void __fastcall UFG::SimUpdateTransforms_RigidBodyComponent(UFG *this)
{
  unsigned __int64 Ticks; // rax
  UFG::RigidBodyComponent *p_mNext; // rcx
  unsigned __int64 v3; // rsi
  UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *v4; // rbx
  unsigned __int64 v5; // rax

  Ticks = UFG::qGetTicks();
  p_mNext = (UFG::RigidBodyComponent *)&UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mNext[-18].mNext;
  v3 = Ticks;
  if ( &UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mNext[-18].mNext != (UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> **)((char *)&UFG::RigidBodyComponent::s_RigidBodyComponentList - 280) )
  {
    do
    {
      v4 = (UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *)&p_mNext->mNext[-18].mNext;
      UFG::RigidBodyComponent::UpdateTransforms(p_mNext);
      p_mNext = (UFG::RigidBodyComponent *)v4;
    }
    while ( v4 != (UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *)((char *)&UFG::RigidBodyComponent::s_RigidBodyComponentList
                                                                                    - 280) );
  }
  v5 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(v3, v5);
}

// File Line: 647
// RVA: 0x58BC70
void __fastcall UFG::SimUpdateTransformsDeltaT_CharacterPhysicsComponent(float deltaT)
{
  unsigned __int64 Ticks; // rsi
  UFG::qList<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent,1,0> *p_mNext; // rcx
  UFG::qList<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent,1,0> *v3; // rbx
  unsigned __int64 v4; // rax

  Ticks = UFG::qGetTicks();
  p_mNext = (UFG::qList<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent,1,0> *)&UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList.mNode.mNext[-7].mNext;
  if ( &UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList.mNode.mNext[-7].mNext != (UFG::qNode<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent> **)((char *)&UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList - 104) )
  {
    do
    {
      v3 = (UFG::qList<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent,1,0> *)&p_mNext[7].mNode.mPrev[-7].mNext;
      ((void (__fastcall *)(UFG::qList<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent,1,0> *))p_mNext->mNode.mPrev[7].mNext)(p_mNext);
      p_mNext = v3;
    }
    while ( v3 != (UFG::qList<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent,1,0> *)((char *)&UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList
                                                                                                  - 104) );
  }
  v4 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(Ticks, v4);
}

// File Line: 648
// RVA: 0x58BD10
void __fastcall UFG::SimUpdateTransformsDeltaT_PhysicsMoverInterface(float deltaT)
{
  unsigned __int64 Ticks; // rsi
  UFG::qList<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface,1,0> *p_mNext; // rcx
  UFG::qList<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface,1,0> *v3; // rbx
  unsigned __int64 v4; // rax

  Ticks = UFG::qGetTicks();
  p_mNext = (UFG::qList<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface,1,0> *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList.mNode.mNext[-5].mNext;
  if ( &UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList.mNode.mNext[-5].mNext != (UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface> **)((char *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList - 72) )
  {
    do
    {
      v3 = (UFG::qList<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface,1,0> *)&p_mNext[5].mNode.mPrev[-5].mNext;
      ((void (__fastcall *)(UFG::qList<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface,1,0> *))p_mNext->mNode.mPrev[8].mPrev)(p_mNext);
      p_mNext = v3;
    }
    while ( v3 != (UFG::qList<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface,1,0> *)((char *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList
                                                                                          - 72) );
  }
  v4 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(Ticks, v4);
}

// File Line: 649
// RVA: 0x58BDB0
void __fastcall UFG::SimUpdateTransformsDeltaT_VehicleEffectsComponent(float deltaT)
{
  unsigned __int64 Ticks; // rsi
  UFG::VehicleEffectsComponent *v2; // rcx
  UFG::qList<UFG::VehicleEffectsComponent,UFG::VehicleEffectsComponent,1,0> *v3; // rbx
  unsigned __int64 v4; // rax

  Ticks = UFG::qGetTicks();
  v2 = (UFG::VehicleEffectsComponent *)&UFG::VehicleEffectsComponent::s_VehicleEffectsComponentList.mNode.mNext[-4];
  if ( (UFG::qList<UFG::VehicleEffectsComponent,UFG::VehicleEffectsComponent,1,0> *)&UFG::VehicleEffectsComponent::s_VehicleEffectsComponentList.mNode.mNext[-4] != &UFG::VehicleEffectsComponent::s_VehicleEffectsComponentList - 4 )
  {
    do
    {
      v3 = (UFG::qList<UFG::VehicleEffectsComponent,UFG::VehicleEffectsComponent,1,0> *)&v2->mNext[-4];
      UFG::VehicleEffectsComponent::UpdateTransforms(v2, deltaT);
      v2 = (UFG::VehicleEffectsComponent *)v3;
    }
    while ( v3 != &UFG::VehicleEffectsComponent::s_VehicleEffectsComponentList - 4 );
  }
  v4 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(Ticks, v4);
}

// File Line: 652
// RVA: 0x58BE50
void __fastcall UFG::SimUpdateTransformsPost_BaseAnimationComponent(UFG *this)
{
  UFG::qNode<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent> *p_mNode; // rax
  Creature *mNext; // rcx
  UFG::qList<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent,1,0> *v3; // rbx

  p_mNode = UFG::BaseAnimationComponent::s_BaseAnimationComponentList.mNode.mNext - 4;
  if ( (UFG::qList<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent,1,0> *)&UFG::BaseAnimationComponent::s_BaseAnimationComponentList.mNode.mNext[-4] != &UFG::BaseAnimationComponent::s_BaseAnimationComponentList - 4 )
  {
    do
    {
      mNext = (Creature *)p_mNode[9].mNext;
      v3 = (UFG::qList<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent,1,0> *)&p_mNode[4].mNext[-4];
      if ( mNext )
      {
        if ( BYTE2(p_mNode[10].mPrev) )
          Creature::UpdateAttachmentPoses(mNext);
      }
      p_mNode = &v3->mNode;
    }
    while ( v3 != &UFG::BaseAnimationComponent::s_BaseAnimationComponentList - 4 );
  }
}

// File Line: 655
// RVA: 0x590AD0
void __fastcall UFG::UpdateSim(
        double sim_time_delta,
        void (__fastcall *fnWaitForRaycastCallback)(__int64, __int64, __int64))
{
  bool mResourceFreezeMode; // si
  unsigned int v5; // ebx
  char *FingerprintDataBlock; // rax
  char *v7; // r10
  char *v8; // r11
  char *v9; // r8
  __int64 v10; // rdx
  signed __int64 v11; // r9
  char *v12; // rcx
  char v13; // al
  char *i; // rcx
  char *v15; // rcx
  char v16; // al
  char *v17; // rcx
  char v18; // al
  char v19; // cl
  unsigned int v20; // r8d
  char v21; // dl
  char v22; // cl
  char v23; // dl
  char v24; // cl
  char v25; // dl
  char v26; // bl
  __int64 v27; // rdx
  char *v28; // rcx
  bool v29; // al
  UFG::GameStatTracker *v30; // rax
  AMD_HD3D *v31; // rcx
  UFG::qList<UFG::ActionTreeComponent,UFG::ActionTreeComponent,1,0> *p_mNext; // rcx
  UFG::qList<UFG::ActionTreeComponent,UFG::ActionTreeComponent,1,0> *v33; // rbx
  UFG::qNode<UFG::CharacterControllerInterface,UFG::CharacterControllerInterface> *p_mNode; // rcx
  UFG::qList<UFG::CharacterControllerInterface,UFG::CharacterControllerInterface,1,0> *v35; // rbx
  UFG::qVector3 *LayerLoadPosition; // rbx
  UFG::GeographicalLayerManager *Instance; // rax
  AMD_HD3D *v38; // rcx
  UFG::OperationManager *v39; // rax
  UFG::InputActionData *v40; // rcx
  UFG::WorldEffectsManager *v41; // rax
  UFG::PedSpawnManager *v42; // rax
  AMD_HD3D *v43; // rax
  UFG::CopSystem *v44; // rax
  UFG::PropSpawnManager *v45; // rax
  UFG::ObjectResourceManager *v46; // rax
  UFG::PartDatabase *v47; // rax
  UFG::WeaponManager *v48; // rax
  NISManager *v49; // rax
  unsigned __int64 Ticks; // rbx
  unsigned __int64 v51; // rax
  AnimationDataBase *v52; // rax
  UFG *v53; // rcx
  unsigned int *v54; // rbx
  UFG::WorldContextComponent *v55; // rcx
  UFG::qList<UFG::WorldContextComponent,UFG::WorldContextComponent,1,0> *v56; // rbx
  NISManager *v57; // rax
  Render::Softbody *j; // rbx
  UFG::PartCompositeBuilder *v59; // rax
  __int64 v60; // rdx
  __int64 v61; // rcx
  __int64 v62; // r8
  UFG::qList<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface,1,0> *v63; // rdi
  UFG::PhysicsVehicle *mNext; // rcx
  UFG::qList<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface,1,0> *v65; // rbx
  UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface> *v66; // rcx
  unsigned __int64 v67; // rax
  UFG::RagdollComponent *v68; // rcx
  unsigned __int64 v69; // rbp
  UFG::qList<UFG::RagdollComponent,UFG::RagdollComponent,1,0> *v70; // rbx
  unsigned __int64 v71; // rax
  UFG *v72; // rcx
  UFG::qNode<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent> *v73; // rax
  Creature *v74; // rcx
  unsigned int *v75; // rbx
  UFG::DoorComponent *v76; // rcx
  UFG::qList<UFG::DoorComponent,UFG::DoorComponent,1,0> *v77; // rbx
  AMD_HD3D *v78; // rcx
  unsigned __int64 v79; // rdi
  UFG::qList<UFG::ActionTreeComponent,UFG::ActionTreeComponent,1,0> *v80; // rcx
  UFG::qList<UFG::ActionTreeComponent,UFG::ActionTreeComponent,1,0> *v81; // rbx
  unsigned __int64 v82; // rax
  unsigned __int64 v83; // rax
  UFG::GunComponent *v84; // rcx
  unsigned __int64 v85; // rsi
  UFG::qList<UFG::GunComponent,UFG::GunComponent,1,0> *v86; // rbx
  unsigned __int64 v87; // rax
  float TickTime; // xmm0_4
  UFG::BulletManager *v89; // rsi
  UFG::WorldEffectsManager *v90; // rax
  UFG::CharacterPhysicsComponent *v91; // rcx
  UFG::qList<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent,1,0> *v92; // rbx
  UFG::TriggerUpdateContext *TriggerUpdateContext; // rax
  __int64 v94; // rdx
  __int64 v95; // rcx
  __int64 v96; // r8
  UFG::ObjectResourceManager *v97; // rax
  UFG::PartDatabase *v98; // rax
  UFG::qVector3 *v99; // rbx
  UFG::GeographicalLayerManager *v100; // rax
  UFG::qList<UFG::ActiveAIEntityComponent,UFG::ActiveAIEntityComponent,1,0> *v101; // rcx
  UFG::qList<UFG::ActiveAIEntityComponent,UFG::ActiveAIEntityComponent,1,0> *v102; // rbx
  UFG::RadarSystem *v103; // rax
  UFG::TriggerUpdateContext result; // [rsp+20h] [rbp-58h] BYREF

  UFG::qMemSet(&UFG::gGameSimMetrics, 0, 0x9Cu);
  if ( *(float *)&sim_time_delta > 0.0 )
    Render::DebugDrawManager::ClearContexts(Render::DebugDrawManager::mInstance, 1u, 1u);
  mResourceFreezeMode = UFG::ProgressionTracker::Instance()->mResourceFreezeMode;
  ((void (__fastcall *)(UFG::NavManager *))UFG::NavManager::ms_pInstance->vfptr->Update)(UFG::NavManager::ms_pInstance);
  UFG::NavManager::ms_pInstance->vfptr->LowHealthDefrag(UFG::NavManager::ms_pInstance);
  v5 = 1431655765;
  strcpy((char *)&result, "0123456789ABCDEF");
  FingerprintDataBlock = UFG::Fingerprint::GetFingerprintDataBlock();
  v7 = FingerprintDataBlock + 16;
  v8 = FingerprintDataBlock;
  v9 = FingerprintDataBlock + 16;
  v10 = 0i64;
  v11 = FingerprintDataBlock - &UFG::Fingerprint::gKeyList[1];
  do
  {
    v9 += 5;
    v12 = &UFG::Fingerprint::gKeyList[v10 + 1];
    v10 += 5i64;
    *(v9 - 5) ^= *(v12 - 1);
    v12[v11 + 17] ^= *v12;
    v12[v11 + 18] ^= v12[1];
    v12[v11 + 19] ^= v12[2];
    v12[v11 + 20] ^= v12[3];
  }
  while ( v10 < 560 );
  v13 = *v7;
  for ( i = v7; *i; v13 = *i )
  {
    if ( i >= v8 + 272 )
      break;
    ++i;
    v5 = v13 ^ __ROL4__(v5, 7);
  }
  v15 = v8 + 272;
  v16 = v8[272];
  if ( v16 )
  {
    do
    {
      if ( v15 >= v8 + 528 )
        break;
      ++v15;
      v5 = v16 ^ __ROL4__(v5, 7);
      v16 = *v15;
    }
    while ( *v15 );
  }
  v17 = v8 + 528;
  v18 = v8[528];
  if ( v18 )
  {
    do
    {
      if ( v17 >= v8 + 544 )
        break;
      ++v17;
      v5 = v18 ^ __ROL4__(v5, 7);
      v18 = *v17;
    }
    while ( *v17 );
  }
  v19 = 1;
  v20 = v5;
  if ( v8[544] != *((_BYTE *)&result.mpPlayer + (v5 & 0xF)) )
    v19 = 0;
  if ( v8[545] != *((_BYTE *)&result.mpPlayer + ((unsigned __int8)v5 >> 4)) )
    v19 = 0;
  v21 = v19;
  if ( v8[546] != *((_BYTE *)&result.mpPlayer + (((unsigned __int64)v5 >> 8) & 0xF)) )
    v21 = 0;
  v22 = v21;
  if ( v8[547] != *((_BYTE *)&result.mpPlayer + ((unsigned __int16)v5 >> 12)) )
    v22 = 0;
  v23 = v22;
  if ( v8[548] != *((_BYTE *)&result.mpPlayer + (((unsigned __int64)v5 >> 16) & 0xF)) )
    v23 = 0;
  v24 = v23;
  if ( v8[549] != *((_BYTE *)&result.mpPlayer + (((unsigned __int64)v5 >> 20) & 0xF)) )
    v24 = 0;
  v25 = v24;
  if ( v8[550] != *((_BYTE *)&result.mpPlayer + (((unsigned __int64)v5 >> 24) & 0xF)) )
    v25 = 0;
  v26 = v25;
  if ( v8[551] != *((_BYTE *)&result.mpPlayer + (v20 >> 28)) )
    v26 = 0;
  v27 = v7 - v8 - 16;
  do
  {
    v7 += 5;
    v28 = &UFG::Fingerprint::gKeyList[v27 + 1];
    v27 += 5i64;
    *(v7 - 5) ^= *(v28 - 1);
    v28[v11 + 17] ^= *v28;
    v28[v11 + 18] ^= v28[1];
    v28[v11 + 19] ^= v28[2];
    v28[v11 + 20] ^= v28[3];
  }
  while ( v27 < 0x230 );
  if ( !v26 )
  {
    if ( UFG::Metrics::msInstance.mSimTimeScaleMax <= 0.0 )
    {
      UFG::Metrics::msInstance.mSimTimeScaleInGame = UFG::Metrics::msInstance.mSimTimeScaleMax;
      v29 = UFG::Metrics::msInstance.mSimTimeScaleMax == 0.0;
    }
    else
    {
      UFG::Metrics::msInstance.mSimTimeScaleInGame = 0.0;
      v29 = 1;
    }
    UFG::Metrics::msInstance.mSimPausedInGame = v29;
    UFG::Metrics::msInstance.mSimTimeDeltaStep = 0.0;
  }
  if ( *(float *)&sim_time_delta > 0.0 )
  {
    ((void (__fastcall *)(UFG::NavSystemBase *))UFG::NavSystemBase::ms_pInstance->vfptr->UpdatePostStreaming)(UFG::NavSystemBase::ms_pInstance);
    v30 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::UpdateSim(v30, *(float *)&sim_time_delta);
    _(v31);
    p_mNext = (UFG::qList<UFG::ActionTreeComponent,UFG::ActionTreeComponent,1,0> *)&UFG::ActionTreeComponent::s_ActionTreeComponentList.mNode.mNext[-10].mNext;
    if ( &UFG::ActionTreeComponent::s_ActionTreeComponentList.mNode.mNext[-10].mNext != (UFG::qNode<UFG::ActionTreeComponent,UFG::ActionTreeComponent> **)((char *)&UFG::ActionTreeComponent::s_ActionTreeComponentList - 152) )
    {
      do
      {
        v33 = (UFG::qList<UFG::ActionTreeComponent,UFG::ActionTreeComponent,1,0> *)&p_mNext[10].mNode.mPrev[-10].mNext;
        ((void (__fastcall *)(UFG::qList<UFG::ActionTreeComponent,UFG::ActionTreeComponent,1,0> *))p_mNext->mNode.mPrev[7].mPrev)(p_mNext);
        p_mNext = v33;
      }
      while ( v33 != (UFG::qList<UFG::ActionTreeComponent,UFG::ActionTreeComponent,1,0> *)((char *)&UFG::ActionTreeComponent::s_ActionTreeComponentList
                                                                                         - 152) );
    }
    UFG::FacialActionTreeComponent::BeginSimFrame();
    p_mNode = UFG::CharacterControllerInterface::s_CharacterControllerInterfaceList.mNode.mNext - 4;
    if ( (UFG::qList<UFG::CharacterControllerInterface,UFG::CharacterControllerInterface,1,0> *)&UFG::CharacterControllerInterface::s_CharacterControllerInterfaceList.mNode.mNext[-4] != &UFG::CharacterControllerInterface::s_CharacterControllerInterfaceList - 4 )
    {
      do
      {
        v35 = (UFG::qList<UFG::CharacterControllerInterface,UFG::CharacterControllerInterface,1,0> *)&p_mNode[4].mNext[-4];
        ((void (__fastcall *)(UFG::qNode<UFG::CharacterControllerInterface,UFG::CharacterControllerInterface> *))p_mNode->mPrev[7].mPrev)(p_mNode);
        p_mNode = &v35->mNode;
      }
      while ( v35 != &UFG::CharacterControllerInterface::s_CharacterControllerInterfaceList - 4 );
    }
    UFG::FormationManagerComponent::BeginFrame();
    UFG::GameStatAction::MissionScoring::Update(*(float *)&sim_time_delta);
    if ( !mResourceFreezeMode )
    {
      LayerLoadPosition = UFG::GetLayerLoadPosition((UFG::qVector3 *)&result);
      Instance = UFG::GeographicalLayerManager::GetInstance();
      UFG::GeographicalLayerManager::Update(Instance, *(float *)&sim_time_delta, LayerLoadPosition);
    }
  }
  UFG::SkookumMgr::Update(*(float *)&sim_time_delta);
  _(v38);
  v39 = UFG::OperationManager::Get();
  UFG::OperationManager::Update(v39, *(float *)&sim_time_delta);
  if ( UFG::WorldContextComponent::s_SimPauseOnSync )
  {
    if ( *(float *)&sim_time_delta > 0.0 )
    {
LABEL_50:
      v41 = UFG::WorldEffectsManager::Get();
      UFG::WorldEffectsManager::BeginFrame(v41, *(float *)&sim_time_delta);
      UFG::PhysicsMoverInterface::UpdateAttacks(*(float *)&sim_time_delta);
      ((void (__fastcall *)(UFG::BasePhysicsSystem *))UFG::BasePhysicsSystem::mInstance->vfptr->PreFrameUpdate)(UFG::BasePhysicsSystem::mInstance);
      if ( !mResourceFreezeMode )
      {
        v42 = UFG::PedSpawnManager::GetInstance();
        UFG::PedSpawnManager::Update(v42, *(float *)&sim_time_delta);
      }
      v43 = (AMD_HD3D *)UFG::GroupManager::GetInstance();
      _(v43);
      v44 = UFG::CopSystem::Instance();
      ((void (__fastcall *)(UFG::CopSystem *))v44->vfptr[10].__vecDelDtor)(v44);
      UFG::ThugsEncounter::UpdateAll(*(float *)&sim_time_delta);
      if ( UFG::PropSpawnManager::GetInstance() && !mResourceFreezeMode )
      {
        v45 = UFG::PropSpawnManager::GetInstance();
        UFG::PropSpawnManager::Update(v45);
      }
      v46 = UFG::ObjectResourceManager::Instance();
      UFG::ObjectResourceManager::Update(v46, *(float *)&sim_time_delta);
      v47 = UFG::PartDatabase::Instance();
      UFG::PartDatabase::Update(v47, *(float *)&sim_time_delta);
      v48 = UFG::WeaponManager::Instance();
      UFG::WeaponManager::Update(v48, *(float *)&sim_time_delta);
      v49 = NISManager::GetInstance();
      NISManager::Update(v49, *(float *)&sim_time_delta);
      UFG::UpdateComponentType_AiDriverComponent(*(float *)&sim_time_delta);
      if ( !mResourceFreezeMode )
        UFG::WheeledVehicleManager::Update(UFG::WheeledVehicleManager::m_Instance, *(const float *)&sim_time_delta);
      UFG::PedKnowledgeLOSSystem::ResetFrame(UFG::PedKnowledgeLOSSystem::ms_pInstance);
      UFG::TicketBoothManager::UpdateBooth(
        UFG::TicketBoothManager::mpSingleton,
        TICKETBOOTH_KNOWLEDGEBASE_REFRESHHOSTILES,
        *(float *)&sim_time_delta);
      UFG::TicketBoothManager::UpdateBooth(
        UFG::TicketBoothManager::mpSingleton,
        TICKETBOOTH_KNOWLEDGEBASE_UPDATE,
        *(float *)&sim_time_delta);
      UFG::PedKnowledgeLOSSystem::SendOffASyncRaycastRequests(UFG::PedKnowledgeLOSSystem::ms_pInstance);
      UFG::AIAwareness::KnowledgeSpace::GlobalUpdate(*(float *)&sim_time_delta);
      UFG::UpdateComponentType_AIAwarenessComponent(*(float *)&sim_time_delta);
      UFG::UpdateComponentType_ActiveAIEntityComponent(*(float *)&sim_time_delta);
      UFG::AIAwarenessComponent::UpdateIntentionsAll(*(float *)&sim_time_delta);
      Ticks = UFG::qGetTicks();
      UFG::SpawnPoint::UpdateAll(*(float *)&sim_time_delta);
      v51 = UFG::qGetTicks();
      UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                                   + UFG::qGetTickTime(Ticks, v51);
      UFG::UpdateComponentType_FormationManagerComponent(*(float *)&sim_time_delta);
      UFG::UpdateComponentType_PedFormationManagerComponent(*(float *)&sim_time_delta);
      UFG::TicketBoothManager::UpdateBooth(
        UFG::TicketBoothManager::mpSingleton,
        TICKETBOOTH_PEDFORMATIONMANANGER_UPDATE,
        *(float *)&sim_time_delta);
      UFG::UpdateComponentType_AttackRightsComponent(*(float *)&sim_time_delta);
      UFG::StimulusManager::Update(UFG::StimulusManager::s_pInstance, *(float *)&sim_time_delta);
      UFG::BattleManager::Update(UFG::BattleManager::s_pInstance, *(float *)&sim_time_delta);
      UFG::UpdateComponentType_AIOutlineComponent(*(float *)&sim_time_delta);
      UFG::TicketBoothManager::UpdateBooth(
        UFG::TicketBoothManager::mpSingleton,
        TICKETBOOTH_PLAYER_AIACTIONTREEUPDATE,
        *(float *)&sim_time_delta);
      UFG::TicketBoothManager::UpdateBooth(
        UFG::TicketBoothManager::mpSingleton,
        TICKETBOOTH_CRITICAL_AIACTIONTREEUPDATE,
        *(float *)&sim_time_delta);
      UFG::TicketBoothManager::UpdateBooth(
        UFG::TicketBoothManager::mpSingleton,
        TICKETBOOTH_NON_CRITICAL_AIACTIONTREEUPDATE,
        *(float *)&sim_time_delta);
      UFG::TicketBoothManager::UpdateBooth(
        UFG::TicketBoothManager::mpSingleton,
        TICKETBOOTH_VEHICLE_AIACTIONTREEUPDATE,
        *(float *)&sim_time_delta);
      UFG::NavAvoidanceManager::Update(UFG::NavAvoidanceManager::mspAvoidanceManager, 0i64, *(float *)&sim_time_delta);
      ((void (__fastcall *)(UFG::NavSystemBase *))UFG::NavSystemBase::ms_pInstance->vfptr->Update)(UFG::NavSystemBase::ms_pInstance);
      UFG::LocalPlayerIsInCombatManager::Update(UFG::LocalPlayerIsInCombatManager::s_pInstance);
      UFG::StoreMeshHelper::Update();
      UFG::AiDriverComponent::m_nNumAmbientSpawnPerFrame = 1;
      ModelType::TryBindMissingModels();
      UFG::UpdateComponentType_RoadSpaceComponent(*(float *)&sim_time_delta);
      UFG::NavAvoidanceManager::Update(UFG::NavAvoidanceManager::mspAvoidanceManager, 1i64, *(float *)&sim_time_delta);
      UFG::UpdateComponentType_HumanDriverComponent(*(float *)&sim_time_delta);
      UFG::UpdateComponentType_RemoteDriverComponent(*(float *)&sim_time_delta);
      UFG::PhysicsMoverInterface::UpdateDetailSettings();
      UFG::UpdateComponentType_PhysicsMoverInterface(*(float *)&sim_time_delta);
      UFG::HealthComponent::UpdateAll(*(float *)&sim_time_delta);
      UFG::UpdateComponentType_FaceActionComponent(*(float *)&sim_time_delta);
      UFG::UpdateComponentType_FaceMeterComponent(*(float *)&sim_time_delta);
      UFG::UpdateComponentType_MissionFailConditionComponent(*(float *)&sim_time_delta);
      UFG::ProgressionTriggerComponent::UpdateAll(*(float *)&sim_time_delta);
      UFG::UpdateComponentType_CopRoadBlock(*(float *)&sim_time_delta);
      UFG::UpdateComponentType_CopUnitComponent(*(float *)&sim_time_delta);
      UFG::CollectibleComponent::UpdateStatus(*(float *)&sim_time_delta);
      UFG::InterestPoint::UpdateInterestPoints(*(float *)&sim_time_delta);
      UFG::UpdateComponentType_InterestPointUserComponent(*(float *)&sim_time_delta);
      UFG::UpdateComponentType_TargetingSystemBaseComponent(*(float *)&sim_time_delta);
      UFG::UpdateComponentType_PropInteractComponent(*(float *)&sim_time_delta);
      UFG::InteractableComponent::UpdateAll(*(float *)&sim_time_delta);
      UFG::UpdateComponentType_BoostRegion(*(float *)&sim_time_delta);
      UFG::NavAvoidanceManager::Update(UFG::NavAvoidanceManager::mspAvoidanceManager, 2i64, *(float *)&sim_time_delta);
      ((void (__fastcall *)(UFG::NavSystemBase *))UFG::NavSystemBase::ms_pInstance->vfptr->PostSteeringUpdate)(UFG::NavSystemBase::ms_pInstance);
      UFG::UpdateComponentType_AICharacterControllerComponent(*(float *)&sim_time_delta);
      UFG::UpdateComponentType_DialogueAnimationComponent(*(float *)&sim_time_delta);
      UFG::PredictiveStreamingStats::Update(
        UFG::PredictiveStreamingStats::ms_pInstance,
        *(const float *)&sim_time_delta);
      UFG::PredictiveStreaming::Update(UFG::PredictiveStreaming::ms_pInstance, *(float *)&sim_time_delta);
      UFG::ActionTreeComponent::UpdateAll(*(float *)&sim_time_delta);
      UFG::ActionTreeResourcesComponent::UpdateAll(*(float *)&sim_time_delta);
      UFG::UpdateComponentType_UELComponent(*(float *)&sim_time_delta);
      UFG::FacialActionTreeComponent::UpdateAll(*(float *)&sim_time_delta);
      v52 = AnimationDataBase::GetInstance();
      AnimationDataBase::Update(v52, *(const float *)&sim_time_delta);
      UFG::AnimationLODComponent::UpdateAll(*(float *)&sim_time_delta);
      UFG::BaseAnimationComponent::UpdateAll(*(float *)&sim_time_delta);
      UFG::AICoverComponent::UpdateAll(*(float *)&sim_time_delta);
      UFG::UpdateComponentType_WorldContextComponent(*(float *)&sim_time_delta);
      UFG::UpdateComponentType_VehicleAudioComponent(*(float *)&sim_time_delta);
      UFG::UpdateComponentType_ActorAudioComponent(*(float *)&sim_time_delta);
      UFG::UpdateComponentType_AudioEmitterComponent(*(float *)&sim_time_delta);
      UFG::UpdateComponentType_SimObjectWeaponPropertiesComponent(*(float *)&sim_time_delta);
      v53 = (UFG *)&UFG::BaseAnimationComponent::s_BaseAnimationComponentList.mNode.mNext[-4];
      if ( (unsigned int *)&UFG::BaseAnimationComponent::s_BaseAnimationComponentList.mNode.mNext[-4] != &UFG::PowerManagementComponent::_PowerManagementComponentTypeUID )
      {
        do
        {
          v54 = (unsigned int *)(*((_QWORD *)v53 + 9) - 64i64);
          (*(void (__fastcall **)(UFG *))(*(_QWORD *)v53 + 112i64))(v53);
          v53 = (UFG *)v54;
        }
        while ( v54 != &UFG::PowerManagementComponent::_PowerManagementComponentTypeUID );
      }
      UFG::SimUpdateTransforms_DialogueAnimationComponent(v53);
      v55 = (UFG::WorldContextComponent *)&UFG::WorldContextComponent::s_WorldContextComponentList.mNode.mNext[-4];
      if ( (UFG::qList<UFG::WorldContextComponent,UFG::WorldContextComponent,1,0> *)&UFG::WorldContextComponent::s_WorldContextComponentList.mNode.mNext[-4] != &UFG::WorldContextComponent::s_WorldContextComponentList - 4 )
      {
        do
        {
          v56 = (UFG::qList<UFG::WorldContextComponent,UFG::WorldContextComponent,1,0> *)&v55->mNext[-4];
          UFG::WorldContextComponent::UpdateTransformsPost(v55);
          v55 = (UFG::WorldContextComponent *)v56;
        }
        while ( v56 != &UFG::WorldContextComponent::s_WorldContextComponentList - 4 );
      }
      UFG::SimUpdateTransformsPost_BaseAnimationComponent((UFG *)v55);
      v57 = NISManager::GetInstance();
      NISManager::UpdateTransforms(v57, *(float *)&sim_time_delta);
      for ( j = (Render::Softbody *)Render::Softbody::s_List.mNode.mNext;
            j != (Render::Softbody *)&Render::Softbody::s_List;
            j = (Render::Softbody *)j->mNext )
      {
        Render::Softbody::SimUpdate(j, *(float *)&sim_time_delta);
      }
      UFG::StreamedResourceComponent::UpdateAll(*(float *)&sim_time_delta);
      v59 = UFG::PartCompositeBuilder::Instance();
      UFG::PartCompositeBuilder::Update(v59, *(float *)&sim_time_delta);
      UFG::UpdateRigs(5u);
      UFG::RagdollFactory::Update(UFG::RagdollFactory::mInstance, *(float *)&sim_time_delta);
      UFG::UpdateComponentType_CharacterPhysicsComponent(*(float *)&sim_time_delta);
      UFG::UpdateComponentType_RagdollComponent(*(float *)&sim_time_delta);
      UFG::UpdateComponentType_SensorComponent(*(float *)&sim_time_delta);
      UFG::UpdateComponentType_PhantomVolumeComponent(*(float *)&sim_time_delta);
      UFG::RigidBodyComponent::UpdateAll(*(float *)&sim_time_delta);
      UFG::UpdateComponentType_CharacterEffectsComponent(*(float *)&sim_time_delta);
      UFG::CharacterPhysicsComponentManager::Update(
        UFG::CharacterPhysicsComponentManager::mInstance,
        *(float *)&sim_time_delta);
      ((void (__fastcall *)(UFG::NavSystemBase *))UFG::NavSystemBase::ms_pInstance->vfptr->WaitForAsyncPathfindCompletion)(UFG::NavSystemBase::ms_pInstance);
      Render::ParticleEmitterManager::UpdateRaycasts(&Render::gParticleEmitterManager);
      UFG::BasePhysicsSystem::StartAsyncRayCasts(UFG::BasePhysicsSystem::mInstance);
      if ( fnWaitForRaycastCallback )
        fnWaitForRaycastCallback(v61, v60, v62);
      UFG::BasePhysicsSystem::WaitForAsyncRayCastCompletion(UFG::BasePhysicsSystem::mInstance);
      UFG::BasePhysicsSystem::DispatchAsyncRayCastResultCallbacks(UFG::BasePhysicsSystem::mInstance);
      UFG::ParkourQueryManager::Update(UFG::ParkourQueryManager::mInstance);
      UFG::ParkourQueryManager::DispatchResults(UFG::ParkourQueryManager::mInstance);
      UFG::UpdateComponentType_DynamicCoverComponent(*(float *)&sim_time_delta);
      v63 = (UFG::qList<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface,1,0> *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList.mNode.mNext[-5].mNext;
      if ( &UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList.mNode.mNext[-5].mNext != (UFG::qNode<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface> **)((char *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList - 72) )
      {
        do
        {
          mNext = (UFG::PhysicsVehicle *)v63[40].mNode.mNext;
          v65 = (UFG::qList<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface,1,0> *)&v63[5].mNode.mPrev[-5].mNext;
          if ( mNext )
            UFG::PhysicsVehicle::DoKeyframes(mNext, *(float *)&sim_time_delta);
          v66 = v63[40].mNode.mNext;
          if ( v66 && (HIDWORD(v66[37].mNext) & 7) == 4 )
            UFG::PhysicsCar::UpdateMotorTargets((UFG::PhysicsCar *)v66);
          v63 = v65;
        }
        while ( v65 != (UFG::qList<UFG::PhysicsMoverInterface,UFG::PhysicsMoverInterface,1,0> *)((char *)&UFG::PhysicsMoverInterface::s_PhysicsMoverInterfaceList
                                                                                               - 72) );
      }
      ((void (__fastcall *)(UFG::BasePhysicsSystem *))UFG::BasePhysicsSystem::mInstance->vfptr->Update)(UFG::BasePhysicsSystem::mInstance);
      if ( UFG::AIQueryManager::ms_pInstance )
        UFG::AIQueryManager::Update(UFG::AIQueryManager::ms_pInstance);
      UFG::SimUpdateTransformsDeltaT_CharacterPhysicsComponent(*(float *)&sim_time_delta);
      UFG::SimUpdateTransformsDeltaT_PhysicsMoverInterface(*(float *)&sim_time_delta);
      v67 = UFG::qGetTicks();
      v68 = (UFG::RagdollComponent *)&UFG::RagdollComponent::s_RagdollComponentList.mNode.mNext[-6].mNext;
      v69 = v67;
      if ( &UFG::RagdollComponent::s_RagdollComponentList.mNode.mNext[-6].mNext != (UFG::qNode<UFG::RagdollComponent,UFG::RagdollComponent> **)((char *)&UFG::RagdollComponent::s_RagdollComponentList - 88) )
      {
        do
        {
          v70 = (UFG::qList<UFG::RagdollComponent,UFG::RagdollComponent,1,0> *)&v68->mNext[-6].mNext;
          UFG::RagdollComponent::UpdateTransforms(v68);
          v68 = (UFG::RagdollComponent *)v70;
        }
        while ( v70 != (UFG::qList<UFG::RagdollComponent,UFG::RagdollComponent,1,0> *)((char *)&UFG::RagdollComponent::s_RagdollComponentList
                                                                                     - 88) );
      }
      v71 = UFG::qGetTicks();
      UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                                   + UFG::qGetTickTime(v69, v71);
      UFG::SimUpdateTransforms_RigidBodyComponent(v72);
      v73 = UFG::BaseAnimationComponent::s_BaseAnimationComponentList.mNode.mNext - 4;
      if ( (unsigned int *)&UFG::BaseAnimationComponent::s_BaseAnimationComponentList.mNode.mNext[-4] != &UFG::PowerManagementComponent::_PowerManagementComponentTypeUID )
      {
        do
        {
          v74 = (Creature *)v73[9].mNext;
          v75 = (unsigned int *)&v73[4].mNext[-4];
          if ( v74 && BYTE2(v73[10].mPrev) )
            Creature::UpdateAttachmentPostPhysics(v74);
          v73 = (UFG::qNode<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent> *)v75;
        }
        while ( v75 != &UFG::PowerManagementComponent::_PowerManagementComponentTypeUID );
      }
      UFG::SimUpdateTransformsDeltaT_VehicleEffectsComponent(*(float *)&sim_time_delta);
      v76 = (UFG::DoorComponent *)&UFG::DoorComponent::s_DoorComponentList.mNode.mNext[-4];
      if ( (UFG::qList<UFG::DoorComponent,UFG::DoorComponent,1,0> *)&UFG::DoorComponent::s_DoorComponentList.mNode.mNext[-4] != &UFG::DoorComponent::s_DoorComponentList - 4 )
      {
        do
        {
          v77 = (UFG::qList<UFG::DoorComponent,UFG::DoorComponent,1,0> *)&v76->mNext[-4];
          UFG::DoorComponent::Update(v76, *(float *)&sim_time_delta);
          v76 = (UFG::DoorComponent *)v77;
        }
        while ( v77 != &UFG::DoorComponent::s_DoorComponentList - 4 );
      }
      UFG::CompositeDrawableComponent::UpdateTransformsAll();
      Render::FXSimComponent::UpdateComponents();
      UFG::UpdateComponentType_CompositeLookComponent(*(float *)&sim_time_delta);
      _(v78);
      UFG::UpdateComponentType_HudComponent(*(float *)&sim_time_delta);
      v79 = UFG::qGetTicks();
      v80 = (UFG::qList<UFG::ActionTreeComponent,UFG::ActionTreeComponent,1,0> *)&UFG::ActionTreeComponent::s_ActionTreeComponentList.mNode.mNext[-10].mNext;
      if ( &UFG::ActionTreeComponent::s_ActionTreeComponentList.mNode.mNext[-10].mNext != (UFG::qNode<UFG::ActionTreeComponent,UFG::ActionTreeComponent> **)((char *)&UFG::ActionTreeComponent::s_ActionTreeComponentList - 152) )
      {
        do
        {
          v81 = (UFG::qList<UFG::ActionTreeComponent,UFG::ActionTreeComponent,1,0> *)&v80[10].mNode.mPrev[-10].mNext;
          ((void (__fastcall *)(UFG::qList<UFG::ActionTreeComponent,UFG::ActionTreeComponent,1,0> *))v80->mNode.mPrev[8].mNext)(v80);
          v80 = v81;
        }
        while ( v81 != (UFG::qList<UFG::ActionTreeComponent,UFG::ActionTreeComponent,1,0> *)((char *)&UFG::ActionTreeComponent::s_ActionTreeComponentList
                                                                                           - 152) );
      }
      v82 = UFG::qGetTicks();
      UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                                   + UFG::qGetTickTime(v79, v82);
      UFG::UpdateComponentType_AimingBaseComponent(*(float *)&sim_time_delta);
      v83 = UFG::qGetTicks();
      v84 = (UFG::GunComponent *)&UFG::GunComponent::s_GunComponentList.mNode.mNext[-4];
      v85 = v83;
      if ( (UFG::qList<UFG::GunComponent,UFG::GunComponent,1,0> *)&UFG::GunComponent::s_GunComponentList.mNode.mNext[-4] != &UFG::GunComponent::s_GunComponentList - 4 )
      {
        do
        {
          v86 = (UFG::qList<UFG::GunComponent,UFG::GunComponent,1,0> *)&v84->mNext[-4];
          UFG::GunComponent::UpdateTransforms(v84);
          v84 = (UFG::GunComponent *)v86;
        }
        while ( v86 != &UFG::GunComponent::s_GunComponentList - 4 );
      }
      v87 = UFG::qGetTicks();
      TickTime = UFG::qGetTickTime(v85, v87);
      v89 = UFG::BulletManager::mInstance;
      UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming + TickTime;
      UFG::BulletManager::PreRayCastUpdate(UFG::BulletManager::mInstance, *(float *)&sim_time_delta);
      v90 = UFG::WorldEffectsManager::Get();
      UFG::WorldEffectsManager::EndFrame(v90, *(float *)&sim_time_delta);
      UFG::BasePhysicsSystem::StartAsyncRayCasts(UFG::BasePhysicsSystem::mInstance);
      v91 = (UFG::CharacterPhysicsComponent *)&UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList.mNode.mNext[-7].mNext;
      if ( &UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList.mNode.mNext[-7].mNext != (UFG::qNode<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent> **)((char *)&UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList - 104) )
      {
        do
        {
          v92 = (UFG::qList<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent,1,0> *)&v91->mNext[-7].mNext;
          UFG::CharacterPhysicsComponent::GrappleFixup(v91, *(float *)&sim_time_delta, sim_time_delta);
          v91 = (UFG::CharacterPhysicsComponent *)v92;
        }
        while ( v92 != (UFG::qList<UFG::CharacterPhysicsComponent,UFG::CharacterPhysicsComponent,1,0> *)((char *)&UFG::CharacterPhysicsComponent::s_CharacterPhysicsComponentList - 104) );
      }
      UFG::BasePhysicsSystem::WaitForAsyncRayCastCompletion(UFG::BasePhysicsSystem::mInstance);
      UFG::BasePhysicsSystem::DispatchAsyncRayCastResultCallbacks(UFG::BasePhysicsSystem::mInstance);
      UFG::BulletManager::PostRayCastUpdate(v89, *(float *)&sim_time_delta);
      UFG::NavManager::ms_pInstance->vfptr->UpdateDynamicObstaclesPre(UFG::NavManager::ms_pInstance);
      UFG::UpdateComponentType_HitReactionComponent(*(float *)&sim_time_delta);
      UFG::PowerManagementComponent::UpdateAll(*(float *)&sim_time_delta);
      UFG::PhysicsMoverInterface::PostFreemanUpdate();
      TriggerUpdateContext = UFG::GetTriggerUpdateContext(&result);
      UFG::TriggerRegion::UpdateAll(TriggerUpdateContext);
      UFG::NavManager::ms_pInstance->vfptr->UpdateDynamicObstaclesPost(UFG::NavManager::ms_pInstance);
      UFG::TSActor::PostFrameCleanup();
      goto LABEL_93;
    }
    v40 = UFG::ActionDef_FreerunDebug.mDataPerController[UFG::gActiveControllerNum];
    if ( v40 && v40->mActionTrue )
    {
      UFG::Metrics::msInstance.mSimPausedDebug = 0;
      UFG::Metrics::msInstance.mSimTimeDeltaStep = 0.0;
    }
  }
  if ( *(float *)&sim_time_delta > 0.0 )
    goto LABEL_50;
  UFG::AIAwareness::KnowledgeSpace::GlobalUpdate(*(float *)&sim_time_delta);
  UFG::NavManager::ms_pInstance->vfptr->UpdateDynamicObstaclesPre(UFG::NavManager::ms_pInstance);
  UFG::NavManager::ms_pInstance->vfptr->UpdateDynamicObstaclesPost(UFG::NavManager::ms_pInstance);
  if ( fnWaitForRaycastCallback )
    fnWaitForRaycastCallback(v95, v94, v96);
  v97 = UFG::ObjectResourceManager::Instance();
  UFG::ObjectResourceManager::Update(v97, *(float *)&sim_time_delta);
  v98 = UFG::PartDatabase::Instance();
  UFG::PartDatabase::Update(v98, *(float *)&sim_time_delta);
  UFG::StreamedResourceComponent::UpdateAll(*(float *)&sim_time_delta);
  UFG::UpdateRigs(5u);
  UFG::CompositeDrawableComponent::UpdateTransformsAll();
  v99 = UFG::GetLayerLoadPosition((UFG::qVector3 *)&result);
  v100 = UFG::GeographicalLayerManager::GetInstance();
  UFG::GeographicalLayerManager::Update(v100, *(float *)&sim_time_delta, v99);
LABEL_93:
  Render::ImpactManager::ApplyDecals(&Render::gImpactManager);
  Render::DecalManager::ProcessClipQueue(&Render::gDecalManager);
  if ( *(float *)&sim_time_delta > 0.0 )
  {
    v101 = (UFG::qList<UFG::ActiveAIEntityComponent,UFG::ActiveAIEntityComponent,1,0> *)&UFG::ActiveAIEntityComponent::s_ActiveAIEntityComponentList.mNode.mNext[-84].mNext;
    if ( &UFG::ActiveAIEntityComponent::s_ActiveAIEntityComponentList.mNode.mNext[-84].mNext != (UFG::qNode<UFG::ActiveAIEntityComponent,UFG::ActiveAIEntityComponent> **)((char *)&UFG::ActiveAIEntityComponent::s_ActiveAIEntityComponentList - 1336) )
    {
      do
      {
        v102 = (UFG::qList<UFG::ActiveAIEntityComponent,UFG::ActiveAIEntityComponent,1,0> *)&v101[84].mNode.mPrev[-84].mNext;
        ((void (__fastcall *)(UFG::qList<UFG::ActiveAIEntityComponent,UFG::ActiveAIEntityComponent,1,0> *))v101->mNode.mPrev[8].mPrev)(v101);
        v101 = v102;
      }
      while ( v102 != (UFG::qList<UFG::ActiveAIEntityComponent,UFG::ActiveAIEntityComponent,1,0> *)((char *)&UFG::ActiveAIEntityComponent::s_ActiveAIEntityComponentList
                                                                                                  - 1336) );
    }
    v103 = UFG::RadarSystem::Instance();
    UFG::RadarSystem::Update(v103, *(float *)&sim_time_delta);
  }
}mponent,1,0> *)&v101[84].mNode.mPrev[-84].mNext;
 

// File Line: 1377
// RVA: 0x590190
void __fastcall UFG::UpdateIsForcedLetterBox(UFG *this)
{
  bool v1; // di
  NISManager *Instance; // rax
  NISInstance *m_pPointer; // rcx
  NISNode *mpNISNode; // rcx
  bool v5; // bp
  UFG::SimComponent *CurrentGameCamera; // rax
  bool v7; // si
  UFG::SimComponent *v8; // rbx
  Render::RenderFrameFeatures features; // [rsp+20h] [rbp-18h] BYREF

  v1 = !UFG::LoadingLogic::IsLoadingScreenUp(&UFG::gLoadingLogic)
    && (unsigned int)UFG::FlowController::GetCurrentState(&UFG::gFlowController) != uidGameStateFE_12
    && !Render::IsLoadScreenRendering();
  Instance = NISManager::GetInstance();
  if ( Instance && (m_pPointer = Instance->mpActiveInstance.m_pPointer) != 0i64 )
    mpNISNode = m_pPointer->mpNISNode;
  else
    mpNISNode = 0i64;
  v5 = Instance
    && Instance->mState == STATE_INCOMPLETE
    && (mpNISNode && mpNISNode->mAllowLetterbox
     || (unsigned __int8)UFG::MovieHandler::IsPlayingNonInMemMovies(&UFG::TheMovieHandler));
  CurrentGameCamera = (UFG::SimComponent *)UFG::GetCurrentGameCamera();
  v7 = 0;
  v8 = CurrentGameCamera;
  if ( CurrentGameCamera
    && UFG::SimComponent::IsType(CurrentGameCamera, UFG::ScriptCameraComponent::_ScriptCameraComponentTypeUID) )
  {
    v7 = LOBYTE(v8[29].m_TypeUID) == 0;
  }
  features = *Render::GetRenderFeatures();
  if ( v5 || !v1 || (features.mForceLetterBox = 0, v7) )
    features.mForceLetterBox = 1;
  Render::SetRenderFeatures(&features);
}

// File Line: 1402
// RVA: 0x58E650
void __fastcall UFG::UpdateComponentType_BaseCameraComponent(float delta_sec)
{
  unsigned __int64 Ticks; // rdi
  UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *v2; // rcx
  unsigned __int64 v3; // rax

  Ticks = UFG::qGetTicks();
  v2 = UFG::BaseCameraComponent::s_BaseCameraComponentList.mNode.mNext - 4;
  for ( UFG::BaseCameraComponent::s_BaseCameraComponentpCurrentIterator = (UFG::BaseCameraComponent *)&UFG::BaseCameraComponent::s_BaseCameraComponentList.mNode.mNext[-4];
        v2 != (UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *)(&UFG::BaseCameraComponent::s_BaseCameraComponentList
                                                                              - 4);
        UFG::BaseCameraComponent::s_BaseCameraComponentpCurrentIterator = (UFG::BaseCameraComponent *)v2 )
  {
    if ( ((__int64)v2[2].mPrev & 3) == 1 )
    {
      ((void (__fastcall *)(UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *))v2->mPrev[7].mNext)(v2);
      v2 = (UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *)UFG::BaseCameraComponent::s_BaseCameraComponentpCurrentIterator;
    }
    v2 = v2[4].mNext - 4;
  }
  UFG::BaseCameraComponent::s_BaseCameraComponentpCurrentIterator = 0i64;
  v3 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(Ticks, v3);
}

// File Line: 1405
// RVA: 0x58DEC0
void __fastcall UFG::UpdateCamera(float real_time_delta)
{
  AMD_HD3D *v1; // rcx
  AMD_HD3D *v2; // rcx

  _(v1);
  _(v2);
  UFG::VehicleSubjectComponent::UpdateAll(real_time_delta);
  UFG::CharacterSubjectComponent::UpdateAll(real_time_delta);
  UFG::GameSubject::UpdateAll(real_time_delta);
  UFG::UpdateComponentType_BaseCameraComponent(real_time_delta);
  UFG::AimingPlayerComponent::UpdateReticlePosition(UFG::Metrics::msInstance.mSimTimeUnscaledDelta);
}

// File Line: 1432
// RVA: 0x58AFE0
void __fastcall UFG::RenderSim(UFG::RenderContext *render_context, Render::View *view)
{
  UFG::DynamicSceneryInstance::DrawAll(view);
  UFG::Director::Get();
  _((AMD_HD3D *)view);
  UFG::PedSpawningInfo::DrawAll(view);
}

// File Line: 1456
// RVA: 0x58B010
void __fastcall UFG::RenderSimDebugOverlay(UFG::RenderContext *render_context, Render::View *view)
{
  UFG::PredictiveStreamingStats::RenderDebug(UFG::PredictiveStreamingStats::ms_pInstance, view);
  UFG::StimulusManager::RenderDebug(UFG::StimulusManager::s_pInstance, view);
  _((AMD_HD3D *)view);
  DrawStats(view, &render_context->mRenderStats);
}

