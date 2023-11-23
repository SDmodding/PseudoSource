// File Line: 56
// RVA: 0x14B2F80
__int64 UFG::_dynamic_initializer_for__gEntityDeathChannel__()
{
  UFG::ChannelObj::ChannelObj(&UFG::gEntityDeathChannel, "EVT_ENTITY_DEATH", 0i64);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gEntityDeathChannel__);
}

// File Line: 68
// RVA: 0x3632E0
const char *__fastcall UFG::AIEntityComponent::GetTypeName(UFG::AIEntityComponent *this)
{
  return "AIEntityComponent";
}

// File Line: 77
// RVA: 0x32B470
void __fastcall UFG::AIEntityComponent::AIEntityComponent(
        UFG::AIEntityComponent *this,
        unsigned int name_uid,
        UFG::qPropertySet *properties,
        bool startSuspended)
{
  float y; // xmm1_4
  float z; // xmm2_4

  UFG::SimComponent::SimComponent(this, name_uid);
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AIEntityComponent::`vftable;
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&this->m_pTransformNodeComponent);
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0>::RebindingComponentHandle<UFG::ActionTreeComponent,0>(&this->m_pActionTreeComponent);
  UFG::RebindingComponentHandle<UFG::RigidBodyComponent,0>::RebindingComponentHandle<UFG::RigidBodyComponent,0>(&this->m_pRigidBodyComponent);
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>(&this->m_pCharacterAnimationComponent);
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0>::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0>(&this->m_pSimObjectCharacterPropertiesComponent);
  UFG::RebindingComponentHandle<UFG::AttackRightsComponent,0>::RebindingComponentHandle<UFG::AttackRightsComponent,0>(&this->m_pAttackRightsComponent);
  UFG::RebindingComponentHandle<UFG::SceneObjectProperties,0>::RebindingComponentHandle<UFG::SceneObjectProperties,0>(&this->m_pSceneObjectProperties);
  UFG::RebindingComponentHandle<UFG::HealthComponent,0>::RebindingComponentHandle<UFG::HealthComponent,0>(&this->m_pHealthComponent);
  UFG::RebindingComponentHandle<UFG::TargetingSystemPedBaseComponent,0>::RebindingComponentHandle<UFG::TargetingSystemPedBaseComponent,0>(&this->m_pTargetingSystemBaseComponent);
  UFG::RebindingComponentHandle<UFG::CharacterOccupantComponent,0>::RebindingComponentHandle<UFG::CharacterOccupantComponent,0>(&this->m_pCharacterOccupantComponent);
  `eh vector constructor iterator(
    &this->m_WanderData,
    0x78ui64,
    2,
    (void (__fastcall *)(void *))UFG::SidewalkWanderData::GoalInfo::GoalInfo);
  this->m_WanderData.mCrosswalkLanes.m_iIntersectionID.p = 0i64;
  *(_QWORD *)&this->m_WanderData.mCrosswalkLanes.m_iIntersectionID.size = 0i64;
  this->m_WanderData.mCrosswalkLanes.m_aLanes.p = 0i64;
  *(_QWORD *)&this->m_WanderData.mCrosswalkLanes.m_aLanes.size = 0i64;
  this->m_HeadTrackingTarget.m_pTransformNodeComponent.mPrev = &this->m_HeadTrackingTarget.m_pTransformNodeComponent;
  this->m_HeadTrackingTarget.m_pTransformNodeComponent.mNext = &this->m_HeadTrackingTarget.m_pTransformNodeComponent;
  this->m_HeadTrackingTarget.m_pTransformNodeComponent.m_pPointer = 0i64;
  *(_WORD *)&this->m_AIPositionValid = 256;
  this->m_pGroupComponent.mPrev = &this->m_pGroupComponent;
  this->m_pGroupComponent.mNext = &this->m_pGroupComponent;
  this->m_pGroupComponent.m_pPointer = 0i64;
  this->m_pCombatRegion.mPrev = &this->m_pCombatRegion;
  this->m_pCombatRegion.mNext = &this->m_pCombatRegion;
  this->m_pCombatRegion.m_pPointer = 0i64;
  `eh vector constructor iterator(
    this->m_ThreatTargets.p,
    0x20ui64,
    10,
    (void (__fastcall *)(void *))UFG::GameSliceStreamer::DeferScriptDeletionRequest::DeferScriptDeletionRequest);
  this->m_ThreatTargets.size = 0;
  *(_WORD *)&this->m_bCanWander = 0;
  UFG::SimComponent::AddType(this, UFG::AIEntityComponent::_AIEntityComponentTypeUID, "AIEntityComponent");
  this->m_pNearbyCharacter = 0i64;
  this->m_bActive = 0;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->m_vCombatRegionMoveToVec.x = UFG::qVector3::msZero.x;
  this->m_vCombatRegionMoveToVec.y = y;
  this->m_vCombatRegionMoveToVec.z = z;
  UFG::SidewalkWanderData::ClearData(&this->m_WanderData);
  this->m_HeadTrackingTarget.m_Type = eHEAD_TRACK_TYPE_NONE;
}

// File Line: 90
// RVA: 0x3342C0
void __fastcall UFG::AIEntityComponent::~AIEntityComponent(UFG::AIEntityComponent *this)
{
  UFG::qSafePointer<UFG::CombatRegion,UFG::CombatRegion> *p_m_pCombatRegion; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qSafePointer<UFG::GroupComponent,UFG::GroupComponent> *p_m_pGroupComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_m_pTransformNodeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AIEntityComponent::`vftable;
  p_m_pCombatRegion = &this->m_pCombatRegion;
  if ( this->m_pCombatRegion.m_pPointer )
  {
    mPrev = p_m_pCombatRegion->mPrev;
    mNext = p_m_pCombatRegion->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pCombatRegion->mPrev = p_m_pCombatRegion;
    p_m_pCombatRegion->mNext = p_m_pCombatRegion;
  }
  p_m_pCombatRegion->m_pPointer = 0i64;
  this->m_ThreatTargets.size = 0;
  `eh vector destructor iterator(
    this->m_ThreatTargets.p,
    0x20ui64,
    10,
    (void (__fastcall *)(void *))UFG::InterestPointUseDetails::~InterestPointUseDetails);
  if ( p_m_pCombatRegion->m_pPointer )
  {
    v5 = p_m_pCombatRegion->mPrev;
    v6 = p_m_pCombatRegion->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    p_m_pCombatRegion->mPrev = p_m_pCombatRegion;
    p_m_pCombatRegion->mNext = p_m_pCombatRegion;
  }
  p_m_pCombatRegion->m_pPointer = 0i64;
  v7 = p_m_pCombatRegion->mPrev;
  v8 = p_m_pCombatRegion->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  p_m_pCombatRegion->mPrev = p_m_pCombatRegion;
  p_m_pCombatRegion->mNext = p_m_pCombatRegion;
  p_m_pGroupComponent = &this->m_pGroupComponent;
  if ( this->m_pGroupComponent.m_pPointer )
  {
    v10 = p_m_pGroupComponent->mPrev;
    v11 = this->m_pGroupComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    p_m_pGroupComponent->mPrev = p_m_pGroupComponent;
    this->m_pGroupComponent.mNext = &this->m_pGroupComponent;
  }
  this->m_pGroupComponent.m_pPointer = 0i64;
  v12 = p_m_pGroupComponent->mPrev;
  v13 = this->m_pGroupComponent.mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  p_m_pGroupComponent->mPrev = p_m_pGroupComponent;
  this->m_pGroupComponent.mNext = &this->m_pGroupComponent;
  p_m_pTransformNodeComponent = &this->m_HeadTrackingTarget.m_pTransformNodeComponent;
  if ( this->m_HeadTrackingTarget.m_pTransformNodeComponent.m_pPointer )
  {
    v15 = p_m_pTransformNodeComponent->mPrev;
    v16 = this->m_HeadTrackingTarget.m_pTransformNodeComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    p_m_pTransformNodeComponent->mPrev = p_m_pTransformNodeComponent;
    this->m_HeadTrackingTarget.m_pTransformNodeComponent.mNext = &this->m_HeadTrackingTarget.m_pTransformNodeComponent;
  }
  this->m_HeadTrackingTarget.m_pTransformNodeComponent.m_pPointer = 0i64;
  v17 = p_m_pTransformNodeComponent->mPrev;
  v18 = this->m_HeadTrackingTarget.m_pTransformNodeComponent.mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  p_m_pTransformNodeComponent->mPrev = p_m_pTransformNodeComponent;
  this->m_HeadTrackingTarget.m_pTransformNodeComponent.mNext = &this->m_HeadTrackingTarget.m_pTransformNodeComponent;
  UFG::SidewalkWanderData::~SidewalkWanderData(&this->m_WanderData);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pCharacterOccupantComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pTargetingSystemBaseComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pHealthComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pSceneObjectProperties);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pAttackRightsComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pSimObjectCharacterPropertiesComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pCharacterAnimationComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pRigidBodyComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pActionTreeComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>(&this->m_pTransformNodeComponent);
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 98
// RVA: 0x14AED10
__int64 dynamic_initializer_for__AllowedToUseCrosswalksSymbol__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("AllowedToUseCrosswalks", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&AllowedToUseCrosswalksSymbol, v0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__AllowedToUseCrosswalksSymbol__);
}

// File Line: 137
// RVA: 0x378410
void __fastcall UFG::AIEntityComponent::OnAttach(UFG::AIEntityComponent *this, UFG::SimObjectCharacter *object)
{
  UFG::RebindingComponentHandle<UFG::RigidBodyComponent,0> *p_m_pRigidBodyComponent; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *p_m_pCharacterAnimationComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rax
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0> *p_m_pSimObjectCharacterPropertiesComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v17; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rax
  UFG::RebindingComponentHandle<UFG::TargetingSystemPedBaseComponent,0> *p_m_pTargetingSystemBaseComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v20; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v22; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v23; // rax

  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::Bind<UFG::SimObjectCharacter>(
    &this->m_pTransformNodeComponent,
    object);
  p_m_pRigidBodyComponent = &this->m_pRigidBodyComponent;
  if ( this->m_pRigidBodyComponent.m_pSimComponent )
  {
    mPrev = p_m_pRigidBodyComponent->mPrev;
    mNext = this->m_pRigidBodyComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->m_pRigidBodyComponent.m_pSimComponent = 0i64;
LABEL_7:
    this->m_pRigidBodyComponent.m_pSimObject = 0i64;
    this->m_pRigidBodyComponent.mNext = &this->m_pRigidBodyComponent;
    p_m_pRigidBodyComponent->mPrev = p_m_pRigidBodyComponent;
    goto LABEL_8;
  }
  if ( this->m_pRigidBodyComponent.m_pSimObject
    && (p_m_pRigidBodyComponent->mPrev != p_m_pRigidBodyComponent
     || this->m_pRigidBodyComponent.mNext != &this->m_pRigidBodyComponent) )
  {
    v7 = p_m_pRigidBodyComponent->mPrev;
    v8 = this->m_pRigidBodyComponent.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    goto LABEL_7;
  }
LABEL_8:
  this->m_pRigidBodyComponent.m_Changed = 1;
  this->m_pRigidBodyComponent.m_pSimObject = object;
  this->m_pRigidBodyComponent.m_TypeUID = UFG::RigidBodyComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::RigidBodyComponent,0>::BindInternal<UFG::SimObjectCharacter>(
    p_m_pRigidBodyComponent,
    object);
  p_m_pCharacterAnimationComponent = &this->m_pCharacterAnimationComponent;
  if ( this->m_pCharacterAnimationComponent.m_pSimComponent )
  {
    v10 = p_m_pCharacterAnimationComponent->mPrev;
    v11 = this->m_pCharacterAnimationComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    this->m_pCharacterAnimationComponent.m_pSimComponent = 0i64;
LABEL_14:
    this->m_pCharacterAnimationComponent.m_pSimObject = 0i64;
    this->m_pCharacterAnimationComponent.mNext = &this->m_pCharacterAnimationComponent;
    p_m_pCharacterAnimationComponent->mPrev = p_m_pCharacterAnimationComponent;
    goto LABEL_15;
  }
  if ( this->m_pCharacterAnimationComponent.m_pSimObject
    && (p_m_pCharacterAnimationComponent->mPrev != p_m_pCharacterAnimationComponent
     || this->m_pCharacterAnimationComponent.mNext != &this->m_pCharacterAnimationComponent) )
  {
    v12 = p_m_pCharacterAnimationComponent->mPrev;
    v13 = this->m_pCharacterAnimationComponent.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    goto LABEL_14;
  }
LABEL_15:
  this->m_pCharacterAnimationComponent.m_Changed = 1;
  this->m_pCharacterAnimationComponent.m_pSimObject = object;
  this->m_pCharacterAnimationComponent.m_TypeUID = UFG::CharacterAnimationComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>::BindInternal<UFG::SimObjectVehicle>(
    &this->m_pCharacterAnimationComponent,
    object);
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0>::Bind<UFG::SimObjectCharacter>(
    &this->m_pActionTreeComponent,
    object);
  p_m_pSimObjectCharacterPropertiesComponent = &this->m_pSimObjectCharacterPropertiesComponent;
  if ( this->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent )
  {
    v15 = p_m_pSimObjectCharacterPropertiesComponent->mPrev;
    v16 = this->m_pSimObjectCharacterPropertiesComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    this->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent = 0i64;
LABEL_21:
    this->m_pSimObjectCharacterPropertiesComponent.m_pSimObject = 0i64;
    this->m_pSimObjectCharacterPropertiesComponent.mNext = &this->m_pSimObjectCharacterPropertiesComponent;
    p_m_pSimObjectCharacterPropertiesComponent->mPrev = p_m_pSimObjectCharacterPropertiesComponent;
    goto LABEL_22;
  }
  if ( this->m_pSimObjectCharacterPropertiesComponent.m_pSimObject
    && (p_m_pSimObjectCharacterPropertiesComponent->mPrev != p_m_pSimObjectCharacterPropertiesComponent
     || this->m_pSimObjectCharacterPropertiesComponent.mNext != &this->m_pSimObjectCharacterPropertiesComponent) )
  {
    v17 = p_m_pSimObjectCharacterPropertiesComponent->mPrev;
    v18 = this->m_pSimObjectCharacterPropertiesComponent.mNext;
    v17->mNext = v18;
    v18->mPrev = v17;
    goto LABEL_21;
  }
LABEL_22:
  this->m_pSimObjectCharacterPropertiesComponent.m_Changed = 1;
  this->m_pSimObjectCharacterPropertiesComponent.m_pSimObject = object;
  this->m_pSimObjectCharacterPropertiesComponent.m_TypeUID = UFG::SimObjectCharacterPropertiesComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0>::BindInternal<UFG::SimObjectCharacter>(
    &this->m_pSimObjectCharacterPropertiesComponent,
    object);
  UFG::RebindingComponentHandle<UFG::AttackRightsComponent,0>::Bind<UFG::SimObjectCharacter>(
    &this->m_pAttackRightsComponent,
    object);
  UFG::RebindingComponentHandle<UFG::SceneObjectProperties,0>::Bind<UFG::SimObjectCharacter>(
    &this->m_pSceneObjectProperties,
    object);
  UFG::RebindingComponentHandle<UFG::HealthComponent,0>::Bind<UFG::SimObjectCharacter>(
    &this->m_pHealthComponent,
    object);
  p_m_pTargetingSystemBaseComponent = &this->m_pTargetingSystemBaseComponent;
  if ( this->m_pTargetingSystemBaseComponent.m_pSimComponent )
  {
    v20 = p_m_pTargetingSystemBaseComponent->mPrev;
    v21 = this->m_pTargetingSystemBaseComponent.mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    this->m_pTargetingSystemBaseComponent.m_pSimComponent = 0i64;
LABEL_28:
    this->m_pTargetingSystemBaseComponent.m_pSimObject = 0i64;
    this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
    p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
    goto LABEL_29;
  }
  if ( this->m_pTargetingSystemBaseComponent.m_pSimObject
    && (p_m_pTargetingSystemBaseComponent->mPrev != p_m_pTargetingSystemBaseComponent
     || this->m_pTargetingSystemBaseComponent.mNext != &this->m_pTargetingSystemBaseComponent) )
  {
    v22 = p_m_pTargetingSystemBaseComponent->mPrev;
    v23 = this->m_pTargetingSystemBaseComponent.mNext;
    v22->mNext = v23;
    v23->mPrev = v22;
    goto LABEL_28;
  }
LABEL_29:
  this->m_pTargetingSystemBaseComponent.m_Changed = 1;
  this->m_pTargetingSystemBaseComponent.m_pSimObject = object;
  this->m_pTargetingSystemBaseComponent.m_TypeUID = UFG::TargetingSystemPedBaseComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::TargetingSystemPedBaseComponent,0>::BindInternal<UFG::SimObjectCharacter>(
    &this->m_pTargetingSystemBaseComponent,
    object);
  UFG::RebindingComponentHandle<UFG::CharacterOccupantComponent,0>::Bind<UFG::SimObjectCharacter>(
    &this->m_pCharacterOccupantComponent,
    object);
  UFG::NearbyCharacterManager::AddCharacter(UFG::NearbyCharacterManager::s_pInstance, this);
}

// File Line: 161
// RVA: 0x3798C0
void __fastcall UFG::AIEntityComponent::OnDetach(UFG::AIEntityComponent *this)
{
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *p_m_pTransformNodeComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::RebindingComponentHandle<UFG::RigidBodyComponent,0> *p_m_pRigidBodyComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *p_m_pCharacterAnimationComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *p_m_pActionTreeComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v19; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v20; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rax
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0> *p_m_pSimObjectCharacterPropertiesComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v23; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v24; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v25; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v26; // rax
  UFG::RebindingComponentHandle<UFG::AttackRightsComponent,0> *p_m_pAttackRightsComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v28; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v29; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v30; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v31; // rax
  UFG::RebindingComponentHandle<UFG::SceneObjectProperties,0> *p_m_pSceneObjectProperties; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v33; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v34; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v35; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v36; // rax
  UFG::RebindingComponentHandle<UFG::HealthComponent,0> *p_m_pHealthComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v38; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v39; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v40; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v41; // rax
  UFG::RebindingComponentHandle<UFG::TargetingSystemPedBaseComponent,0> *p_m_pTargetingSystemBaseComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v43; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v44; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v45; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v46; // rax
  UFG::RebindingComponentHandle<UFG::CharacterOccupantComponent,0> *p_m_pCharacterOccupantComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v48; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v49; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v50; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v51; // rax
  UFG::qSafePointer<UFG::CombatRegion,UFG::CombatRegion> *p_m_pCombatRegion; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v53; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v54; // rax
  float z; // xmm2_4
  float x; // xmm0_4

  UFG::NearbyCharacterManager::RemoveCharacter(UFG::NearbyCharacterManager::s_pInstance, this);
  p_m_pTransformNodeComponent = &this->m_pTransformNodeComponent;
  if ( this->m_pTransformNodeComponent.m_pSimComponent )
  {
    mPrev = p_m_pTransformNodeComponent->mPrev;
    mNext = this->m_pTransformNodeComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->m_pTransformNodeComponent.m_pSimComponent = 0i64;
LABEL_7:
    this->m_pTransformNodeComponent.m_pSimObject = 0i64;
    this->m_pTransformNodeComponent.mNext = &this->m_pTransformNodeComponent;
    p_m_pTransformNodeComponent->mPrev = p_m_pTransformNodeComponent;
    goto LABEL_8;
  }
  if ( this->m_pTransformNodeComponent.m_pSimObject
    && (p_m_pTransformNodeComponent->mPrev != p_m_pTransformNodeComponent
     || this->m_pTransformNodeComponent.mNext != &this->m_pTransformNodeComponent) )
  {
    v5 = p_m_pTransformNodeComponent->mPrev;
    v6 = this->m_pTransformNodeComponent.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  p_m_pRigidBodyComponent = &this->m_pRigidBodyComponent;
  this->m_pTransformNodeComponent.m_Changed = 1;
  if ( this->m_pRigidBodyComponent.m_pSimComponent )
  {
    v8 = p_m_pRigidBodyComponent->mPrev;
    v9 = this->m_pRigidBodyComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    this->m_pRigidBodyComponent.m_pSimComponent = 0i64;
LABEL_14:
    this->m_pRigidBodyComponent.m_pSimObject = 0i64;
    this->m_pRigidBodyComponent.mNext = &this->m_pRigidBodyComponent;
    p_m_pRigidBodyComponent->mPrev = p_m_pRigidBodyComponent;
    goto LABEL_15;
  }
  if ( this->m_pRigidBodyComponent.m_pSimObject
    && (p_m_pRigidBodyComponent->mPrev != p_m_pRigidBodyComponent
     || this->m_pRigidBodyComponent.mNext != &this->m_pRigidBodyComponent) )
  {
    v10 = p_m_pRigidBodyComponent->mPrev;
    v11 = this->m_pRigidBodyComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    goto LABEL_14;
  }
LABEL_15:
  this->m_pRigidBodyComponent.m_Changed = 1;
  p_m_pCharacterAnimationComponent = &this->m_pCharacterAnimationComponent;
  if ( this->m_pCharacterAnimationComponent.m_pSimComponent )
  {
    v13 = p_m_pCharacterAnimationComponent->mPrev;
    v14 = this->m_pCharacterAnimationComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    this->m_pCharacterAnimationComponent.m_pSimComponent = 0i64;
LABEL_21:
    this->m_pCharacterAnimationComponent.m_pSimObject = 0i64;
    this->m_pCharacterAnimationComponent.mNext = &this->m_pCharacterAnimationComponent;
    p_m_pCharacterAnimationComponent->mPrev = p_m_pCharacterAnimationComponent;
    goto LABEL_22;
  }
  if ( this->m_pCharacterAnimationComponent.m_pSimObject
    && (p_m_pCharacterAnimationComponent->mPrev != p_m_pCharacterAnimationComponent
     || this->m_pCharacterAnimationComponent.mNext != &this->m_pCharacterAnimationComponent) )
  {
    v15 = p_m_pCharacterAnimationComponent->mPrev;
    v16 = this->m_pCharacterAnimationComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    goto LABEL_21;
  }
LABEL_22:
  this->m_pCharacterAnimationComponent.m_Changed = 1;
  p_m_pActionTreeComponent = &this->m_pActionTreeComponent;
  if ( this->m_pActionTreeComponent.m_pSimComponent )
  {
    v18 = p_m_pActionTreeComponent->mPrev;
    v19 = this->m_pActionTreeComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    this->m_pActionTreeComponent.m_pSimComponent = 0i64;
LABEL_28:
    this->m_pActionTreeComponent.m_pSimObject = 0i64;
    this->m_pActionTreeComponent.mNext = &this->m_pActionTreeComponent;
    p_m_pActionTreeComponent->mPrev = p_m_pActionTreeComponent;
    goto LABEL_29;
  }
  if ( this->m_pActionTreeComponent.m_pSimObject
    && (p_m_pActionTreeComponent->mPrev != p_m_pActionTreeComponent
     || this->m_pActionTreeComponent.mNext != &this->m_pActionTreeComponent) )
  {
    v20 = p_m_pActionTreeComponent->mPrev;
    v21 = this->m_pActionTreeComponent.mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    goto LABEL_28;
  }
LABEL_29:
  this->m_pActionTreeComponent.m_Changed = 1;
  p_m_pSimObjectCharacterPropertiesComponent = &this->m_pSimObjectCharacterPropertiesComponent;
  if ( this->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent )
  {
    v23 = p_m_pSimObjectCharacterPropertiesComponent->mPrev;
    v24 = this->m_pSimObjectCharacterPropertiesComponent.mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    this->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent = 0i64;
LABEL_35:
    this->m_pSimObjectCharacterPropertiesComponent.m_pSimObject = 0i64;
    this->m_pSimObjectCharacterPropertiesComponent.mNext = &this->m_pSimObjectCharacterPropertiesComponent;
    p_m_pSimObjectCharacterPropertiesComponent->mPrev = p_m_pSimObjectCharacterPropertiesComponent;
    goto LABEL_36;
  }
  if ( this->m_pSimObjectCharacterPropertiesComponent.m_pSimObject
    && (p_m_pSimObjectCharacterPropertiesComponent->mPrev != p_m_pSimObjectCharacterPropertiesComponent
     || this->m_pSimObjectCharacterPropertiesComponent.mNext != &this->m_pSimObjectCharacterPropertiesComponent) )
  {
    v25 = p_m_pSimObjectCharacterPropertiesComponent->mPrev;
    v26 = this->m_pSimObjectCharacterPropertiesComponent.mNext;
    v25->mNext = v26;
    v26->mPrev = v25;
    goto LABEL_35;
  }
LABEL_36:
  this->m_pSimObjectCharacterPropertiesComponent.m_Changed = 1;
  p_m_pAttackRightsComponent = &this->m_pAttackRightsComponent;
  if ( this->m_pAttackRightsComponent.m_pSimComponent )
  {
    v28 = p_m_pAttackRightsComponent->mPrev;
    v29 = this->m_pAttackRightsComponent.mNext;
    v28->mNext = v29;
    v29->mPrev = v28;
    this->m_pAttackRightsComponent.m_pSimComponent = 0i64;
LABEL_42:
    this->m_pAttackRightsComponent.m_pSimObject = 0i64;
    this->m_pAttackRightsComponent.mNext = &this->m_pAttackRightsComponent;
    p_m_pAttackRightsComponent->mPrev = p_m_pAttackRightsComponent;
    goto LABEL_43;
  }
  if ( this->m_pAttackRightsComponent.m_pSimObject
    && (p_m_pAttackRightsComponent->mPrev != p_m_pAttackRightsComponent
     || this->m_pAttackRightsComponent.mNext != &this->m_pAttackRightsComponent) )
  {
    v30 = p_m_pAttackRightsComponent->mPrev;
    v31 = this->m_pAttackRightsComponent.mNext;
    v30->mNext = v31;
    v31->mPrev = v30;
    goto LABEL_42;
  }
LABEL_43:
  this->m_pAttackRightsComponent.m_Changed = 1;
  p_m_pSceneObjectProperties = &this->m_pSceneObjectProperties;
  if ( this->m_pSceneObjectProperties.m_pSimComponent )
  {
    v33 = p_m_pSceneObjectProperties->mPrev;
    v34 = this->m_pSceneObjectProperties.mNext;
    v33->mNext = v34;
    v34->mPrev = v33;
    this->m_pSceneObjectProperties.m_pSimComponent = 0i64;
LABEL_49:
    this->m_pSceneObjectProperties.m_pSimObject = 0i64;
    this->m_pSceneObjectProperties.mNext = &this->m_pSceneObjectProperties;
    p_m_pSceneObjectProperties->mPrev = p_m_pSceneObjectProperties;
    goto LABEL_50;
  }
  if ( this->m_pSceneObjectProperties.m_pSimObject
    && (p_m_pSceneObjectProperties->mPrev != p_m_pSceneObjectProperties
     || this->m_pSceneObjectProperties.mNext != &this->m_pSceneObjectProperties) )
  {
    v35 = p_m_pSceneObjectProperties->mPrev;
    v36 = this->m_pSceneObjectProperties.mNext;
    v35->mNext = v36;
    v36->mPrev = v35;
    goto LABEL_49;
  }
LABEL_50:
  this->m_pSceneObjectProperties.m_Changed = 1;
  p_m_pHealthComponent = &this->m_pHealthComponent;
  if ( this->m_pHealthComponent.m_pSimComponent )
  {
    v38 = p_m_pHealthComponent->mPrev;
    v39 = this->m_pHealthComponent.mNext;
    v38->mNext = v39;
    v39->mPrev = v38;
    this->m_pHealthComponent.m_pSimComponent = 0i64;
LABEL_56:
    this->m_pHealthComponent.m_pSimObject = 0i64;
    this->m_pHealthComponent.mNext = &this->m_pHealthComponent;
    p_m_pHealthComponent->mPrev = p_m_pHealthComponent;
    goto LABEL_57;
  }
  if ( this->m_pHealthComponent.m_pSimObject
    && (p_m_pHealthComponent->mPrev != p_m_pHealthComponent
     || this->m_pHealthComponent.mNext != &this->m_pHealthComponent) )
  {
    v40 = p_m_pHealthComponent->mPrev;
    v41 = this->m_pHealthComponent.mNext;
    v40->mNext = v41;
    v41->mPrev = v40;
    goto LABEL_56;
  }
LABEL_57:
  this->m_pHealthComponent.m_Changed = 1;
  p_m_pTargetingSystemBaseComponent = &this->m_pTargetingSystemBaseComponent;
  if ( this->m_pTargetingSystemBaseComponent.m_pSimComponent )
  {
    v43 = p_m_pTargetingSystemBaseComponent->mPrev;
    v44 = this->m_pTargetingSystemBaseComponent.mNext;
    v43->mNext = v44;
    v44->mPrev = v43;
    this->m_pTargetingSystemBaseComponent.m_pSimComponent = 0i64;
LABEL_63:
    this->m_pTargetingSystemBaseComponent.m_pSimObject = 0i64;
    this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
    p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
    goto LABEL_64;
  }
  if ( this->m_pTargetingSystemBaseComponent.m_pSimObject
    && (p_m_pTargetingSystemBaseComponent->mPrev != p_m_pTargetingSystemBaseComponent
     || this->m_pTargetingSystemBaseComponent.mNext != &this->m_pTargetingSystemBaseComponent) )
  {
    v45 = p_m_pTargetingSystemBaseComponent->mPrev;
    v46 = this->m_pTargetingSystemBaseComponent.mNext;
    v45->mNext = v46;
    v46->mPrev = v45;
    goto LABEL_63;
  }
LABEL_64:
  this->m_pTargetingSystemBaseComponent.m_Changed = 1;
  p_m_pCharacterOccupantComponent = &this->m_pCharacterOccupantComponent;
  if ( this->m_pCharacterOccupantComponent.m_pSimComponent )
  {
    v48 = p_m_pCharacterOccupantComponent->mPrev;
    v49 = this->m_pCharacterOccupantComponent.mNext;
    v48->mNext = v49;
    v49->mPrev = v48;
    this->m_pCharacterOccupantComponent.m_pSimComponent = 0i64;
LABEL_70:
    this->m_pCharacterOccupantComponent.m_pSimObject = 0i64;
    this->m_pCharacterOccupantComponent.mNext = &this->m_pCharacterOccupantComponent;
    p_m_pCharacterOccupantComponent->mPrev = p_m_pCharacterOccupantComponent;
    goto LABEL_71;
  }
  if ( this->m_pCharacterOccupantComponent.m_pSimObject
    && (p_m_pCharacterOccupantComponent->mPrev != p_m_pCharacterOccupantComponent
     || this->m_pCharacterOccupantComponent.mNext != &this->m_pCharacterOccupantComponent) )
  {
    v50 = p_m_pCharacterOccupantComponent->mPrev;
    v51 = this->m_pCharacterOccupantComponent.mNext;
    v50->mNext = v51;
    v51->mPrev = v50;
    goto LABEL_70;
  }
LABEL_71:
  this->m_pCharacterOccupantComponent.m_Changed = 1;
  p_m_pCombatRegion = &this->m_pCombatRegion;
  if ( this->m_pCombatRegion.m_pPointer )
  {
    v53 = p_m_pCombatRegion->mPrev;
    v54 = this->m_pCombatRegion.mNext;
    v53->mNext = v54;
    v54->mPrev = v53;
    p_m_pCombatRegion->mPrev = p_m_pCombatRegion;
    this->m_pCombatRegion.mNext = &this->m_pCombatRegion;
  }
  this->m_pCombatRegion.m_pPointer = 0i64;
  z = UFG::qVector3::msZero.z;
  x = UFG::qVector3::msZero.x;
  this->m_vCombatRegionMoveToVec.y = UFG::qVector3::msZero.y;
  this->m_vCombatRegionMoveToVec.z = z;
  this->m_vCombatRegionMoveToVec.x = x;
}_pCombatRegion;
    this->m_pCombatRegion.mNext = &this->m_pCombatRegion;
  }
  this->m_pCombatRegion.m_pPointer = 0i64;
  z = UFG::qVector3::msZero.z;
  x = UFG::qVector3::msZero.x;
  this->m_vCombatRegionMoveToVec.y = UFG

// File Line: 187
// RVA: 0x362620
UFG::SimObjectCharacterPropertiesComponent *__fastcall UFG::AIEntityComponent::GetSimObjectCharacterPropertiesComponent(
        UFG::AIEntityComponent *this)
{
  return (UFG::SimObjectCharacterPropertiesComponent *)this->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent;
}

// File Line: 189
// RVA: 0x35FEE0
UFG::HealthComponent *__fastcall UFG::AIEntityComponent::GetHealthComponent(UFG::AIEntityComponent *this)
{
  return (UFG::HealthComponent *)this->m_pHealthComponent.m_pSimComponent;
}

// File Line: 190
// RVA: 0x362BC0
UFG::SimComponent *__fastcall UFG::AIEntityComponent::GetTargetingSystemBaseComponent(UFG::AIEntityComponent *this)
{
  return this->m_pTargetingSystemBaseComponent.m_pSimComponent;
}

// File Line: 191
// RVA: 0x35AFD0
UFG::SimComponent *__fastcall UFG::AIEntityComponent::GetCharacterOccupantComponent(UFG::AIEntityComponent *this)
{
  return this->m_pCharacterOccupantComponent.m_pSimComponent;
}

// File Line: 195
// RVA: 0x359630
UFG::SimComponent *__fastcall UFG::ActiveAIEntityComponent::GetAIActionTreeComponent(
        UFG::ActiveAIEntityComponent *this)
{
  return this->m_pAIActionTreeComponent.m_pSimComponent;
}

// File Line: 203
// RVA: 0x37BC00
void __fastcall UFG::AIEntityComponent::OnSiblingsChanged(UFG::AIEntityComponent *this)
{
  bool v2; // zf

  if ( this->m_pSceneObjectProperties.m_Changed )
  {
    v2 = this->m_pSceneObjectProperties.m_pSimComponent == 0i64;
    this->m_pSceneObjectProperties.m_Changed = 0;
    if ( !v2 && (this->m_Flags & 2) == 0 )
    {
      UFG::NearbyCharacterManager::RemoveCharacter(UFG::NearbyCharacterManager::s_pInstance, this);
      UFG::NearbyCharacterManager::AddCharacter(UFG::NearbyCharacterManager::s_pInstance, this);
    }
  }
}

// File Line: 240
// RVA: 0x34CBF0
bool __fastcall UFG::AIEntityComponent::CanWalkStraightToPoint(
        UFG::AIEntityComponent *this,
        UFG::qVector3 *point,
        UFG::eConstrainToSidewalks constrain_to_sidewalks,
        UFG::qVector3 *last_valid_point)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::SimComponent *ComponentOfType; // rdx
  __int64 v9; // rax
  __int64 v11; // [rsp+40h] [rbp+8h] BYREF

  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
    ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::NavComponent::_TypeUID);
  else
    ComponentOfType = 0i64;
  v9 = *(__int64 *)((char *)&ComponentOfType[2].m_BoundComponentHandles.mNode.mNext + 4);
  v11 = v9;
  if ( constrain_to_sidewalks )
    HIDWORD(v11) |= 0x200u;
  else
    HIDWORD(v11) = HIDWORD(v9) & 0xFFFFFDFF;
  return !UFG::NavManager::ms_pInstance->vfptr->AIRayCastHits(
            UFG::NavManager::ms_pInstance,
            (UFG::HavokNavPosition *)&ComponentOfType[1].m_SafePointerList.mNode.mNext,
            point,
            (UFG::NavParams *)&v11,
            last_valid_point);
}

// File Line: 269
// RVA: 0x3850F0
void __fastcall UFG::AIEntityComponent::SetCombatRegion(UFG::AIEntityComponent *this, UFG::CombatRegion *pRegion)
{
  UFG::qSafePointer<UFG::CombatRegion,UFG::CombatRegion> *p_m_pCombatRegion; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v5; // rax

  p_m_pCombatRegion = &this->m_pCombatRegion;
  if ( this->m_pCombatRegion.m_pPointer )
  {
    mPrev = p_m_pCombatRegion->mPrev;
    mNext = p_m_pCombatRegion->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pCombatRegion->mPrev = p_m_pCombatRegion;
    p_m_pCombatRegion->mNext = p_m_pCombatRegion;
  }
  p_m_pCombatRegion->m_pPointer = pRegion;
  if ( pRegion )
  {
    v5 = pRegion->UFG::qSafePointerNode<UFG::CombatRegion>::m_SafePointerList.UFG::qSafePointerNode<UFG::CombatRegion>::mNode.mPrev;
    v5->mNext = p_m_pCombatRegion;
    p_m_pCombatRegion->mPrev = v5;
    p_m_pCombatRegion->mNext = &pRegion->UFG::qSafePointerNode<UFG::CombatRegion>::m_SafePointerList.UFG::qSafePointerNode<UFG::CombatRegion>::mNode;
    pRegion->UFG::qSafePointerNode<UFG::CombatRegion>::m_SafePointerList.UFG::qSafePointerNode<UFG::CombatRegion>::mNode.mPrev = p_m_pCombatRegion;
  }
}

// File Line: 326
// RVA: 0x3559A0
void __fastcall UFG::AIEntityComponent::EntityDeathHandler(UFG::Event *thisEvent)
{
  UFG::SimObjectCVBase *mNext; // rcx
  __int16 m_Flags; // dx
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax

  mNext = (UFG::SimObjectCVBase *)thisEvent[1].mNext;
  if ( mNext )
  {
    m_Flags = mNext->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(mNext);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            mNext,
                                                            UFG::ActiveAIEntityComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                            mNext,
                                                            UFG::ActiveAIEntityComponent::_TypeUID);
    }
    if ( ComponentOfTypeHK )
      ComponentOfTypeHK->m_KnowledgeBase.m_bEnabled = 0;
  }
}

// File Line: 349
// RVA: 0x386600
void __fastcall UFG::AIEntityComponent::SetHeadTrackingPosition(
        UFG::AIEntityComponent *this,
        UFG::TransformNodeComponent *transform_node_component,
        UFG::qVector3 *offset)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_m_pTransformNodeComponent; // r10
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  float y; // xmm0_4
  float z; // xmm1_4

  p_m_pTransformNodeComponent = &this->m_HeadTrackingTarget.m_pTransformNodeComponent;
  this->m_HeadTrackingTarget.m_Type = eHEAD_TRACK_TYPE_TRANSFORM_NODE;
  if ( this->m_HeadTrackingTarget.m_pTransformNodeComponent.m_pPointer )
  {
    mPrev = p_m_pTransformNodeComponent->mPrev;
    mNext = this->m_HeadTrackingTarget.m_pTransformNodeComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pTransformNodeComponent->mPrev = p_m_pTransformNodeComponent;
    this->m_HeadTrackingTarget.m_pTransformNodeComponent.mNext = &this->m_HeadTrackingTarget.m_pTransformNodeComponent;
  }
  this->m_HeadTrackingTarget.m_pTransformNodeComponent.m_pPointer = transform_node_component;
  if ( transform_node_component )
  {
    v6 = transform_node_component->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
    v6->mNext = p_m_pTransformNodeComponent;
    p_m_pTransformNodeComponent->mPrev = v6;
    this->m_HeadTrackingTarget.m_pTransformNodeComponent.mNext = &transform_node_component->m_SafePointerList.mNode;
    transform_node_component->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = p_m_pTransformNodeComponent;
  }
  y = offset->y;
  z = offset->z;
  this->m_HeadTrackingTarget.m_Offset.x = offset->x;
  this->m_HeadTrackingTarget.m_Offset.y = y;
  this->m_HeadTrackingTarget.m_Offset.z = z;
}

// File Line: 364
// RVA: 0x3865A0
void __fastcall UFG::AIEntityComponent::SetHeadTrackingPosition(UFG::AIEntityComponent *this, UFG::qVector3 *position)
{
  float y; // xmm0_4
  float z; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm1_4

  this->m_HeadTrackingTarget.m_Type = eHEAD_TRACK_TYPE_POSITION;
  y = position->y;
  z = position->z;
  this->m_HeadTrackingTarget.m_Position.x = position->x;
  this->m_HeadTrackingTarget.m_Position.y = y;
  this->m_HeadTrackingTarget.m_Position.z = z;
  v4 = UFG::qVector3::msZero.y;
  v5 = UFG::qVector3::msZero.z;
  this->m_HeadTrackingTarget.m_Offset.x = UFG::qVector3::msZero.x;
  this->m_HeadTrackingTarget.m_Offset.y = v4;
  this->m_HeadTrackingTarget.m_Offset.z = v5;
}

// File Line: 369
// RVA: 0x3891B0
void __fastcall UFG::AIEntityComponent::StopHeadTracking(UFG::AIEntityComponent *this)
{
  this->m_HeadTrackingTarget.m_Type = eHEAD_TRACK_TYPE_NONE;
}

// File Line: 375
// RVA: 0x341190
void __fastcall UFG::AIEntityComponent::AddThreatTarget(
        UFG::AIEntityComponent *this,
        UFG::SimObject *pTarget,
        float radius)
{
  UFG::qFixedArray<UFG::ThreatTarget,10> *p_m_ThreatTargets; // r9
  __int64 v4; // r8
  __int64 size; // r10
  UFG::SimObject **p_m_pPointer; // rax
  int v9; // eax
  __int64 v10; // rbx
  unsigned __int64 v11; // rsi
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> **v12; // r8
  __int64 v13; // r11
  UFG::SimObject *m_pPointer; // r10
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rax
  __int64 v18; // r11
  UFG::SimObject *v19; // r10
  __int64 v20; // rcx
  _QWORD *v21; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v22; // rax
  __int64 v23; // r11
  UFG::SimObject *v24; // r10
  __int64 v25; // rcx
  _QWORD *v26; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v27; // rax
  __int64 v28; // r11
  UFG::SimObject *v29; // r10
  __int64 v30; // rcx
  _QWORD *v31; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v32; // rax
  __int64 v33; // rdx
  char *v34; // rbp
  __int64 v35; // r8
  UFG::SimObject *v36; // r10
  __int64 v37; // rcx
  _QWORD *v38; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v39; // rax
  UFG::ThreatTarget *v40; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v41; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v43; // rax

  p_m_ThreatTargets = &this->m_ThreatTargets;
  v4 = 0i64;
  size = this->m_ThreatTargets.size;
  if ( this->m_ThreatTargets.size )
  {
    p_m_pPointer = &this->m_ThreatTargets.p[0].m_pTarget.m_pPointer;
    while ( *p_m_pPointer != pTarget )
    {
      ++v4;
      p_m_pPointer += 4;
      if ( v4 >= size )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    if ( (int)size < 10 )
      goto LABEL_44;
    v9 = size - 1;
    v10 = (int)size - 1;
    if ( (int)size - 1 >= 0 )
    {
      if ( v9 + 1i64 >= 4 )
      {
        v11 = (unsigned __int64)(v9 + 1i64) >> 2;
        v12 = &(&this->m_ThreatTargets.p[0].m_pTarget.mNext)[4 * v9];
        v10 -= 4 * v11;
        do
        {
          if ( !v12[1] )
          {
            v13 = --p_m_ThreatTargets->size;
            m_pPointer = p_m_ThreatTargets->p[v13].m_pTarget.m_pPointer;
            if ( v12[1] )
            {
              v15 = *(v12 - 1);
              v16 = *v12;
              v15->mNext = *v12;
              v16->mPrev = v15;
              *(v12 - 1) = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v12 - 1);
              *v12 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v12 - 1);
            }
            v12[1] = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)m_pPointer;
            if ( m_pPointer )
            {
              mPrev = m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
              mPrev->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v12 - 1);
              *(v12 - 1) = mPrev;
              *v12 = &m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
              m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v12 - 1);
            }
            *((_DWORD *)v12 + 4) = LODWORD(p_m_ThreatTargets->p[v13].m_Radius);
          }
          if ( !*(v12 - 3) )
          {
            v18 = --p_m_ThreatTargets->size;
            v19 = p_m_ThreatTargets->p[v18].m_pTarget.m_pPointer;
            if ( *(v12 - 3) )
            {
              v20 = (__int64)*(v12 - 5);
              v21 = *(v12 - 4);
              *(_QWORD *)(v20 + 8) = v21;
              *v21 = v20;
              *(v12 - 5) = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v12 - 5);
              *(v12 - 4) = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v12 - 5);
            }
            *(v12 - 3) = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v19;
            if ( v19 )
            {
              v22 = v19->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
              v22->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v12 - 5);
              *(v12 - 5) = v22;
              *(v12 - 4) = &v19->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
              v19->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v12 - 5);
            }
            *((_DWORD *)v12 - 4) = LODWORD(p_m_ThreatTargets->p[v18].m_Radius);
          }
          if ( !*(v12 - 7) )
          {
            v23 = --p_m_ThreatTargets->size;
            v24 = p_m_ThreatTargets->p[v23].m_pTarget.m_pPointer;
            if ( *(v12 - 7) )
            {
              v25 = (__int64)*(v12 - 9);
              v26 = *(v12 - 8);
              *(_QWORD *)(v25 + 8) = v26;
              *v26 = v25;
              *(v12 - 9) = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v12 - 9);
              *(v12 - 8) = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v12 - 9);
            }
            *(v12 - 7) = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v24;
            if ( v24 )
            {
              v27 = v24->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
              v27->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v12 - 9);
              *(v12 - 9) = v27;
              *(v12 - 8) = &v24->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
              v24->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v12 - 9);
            }
            *((_DWORD *)v12 - 12) = LODWORD(p_m_ThreatTargets->p[v23].m_Radius);
          }
          if ( !*(v12 - 11) )
          {
            v28 = --p_m_ThreatTargets->size;
            v29 = p_m_ThreatTargets->p[v28].m_pTarget.m_pPointer;
            if ( *(v12 - 11) )
            {
              v30 = (__int64)*(v12 - 13);
              v31 = *(v12 - 12);
              *(_QWORD *)(v30 + 8) = v31;
              *v31 = v30;
              *(v12 - 13) = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v12 - 13);
              *(v12 - 12) = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v12 - 13);
            }
            *(v12 - 11) = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v29;
            if ( v29 )
            {
              v32 = v29->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
              v32->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v12 - 13);
              *(v12 - 13) = v32;
              *(v12 - 12) = &v29->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
              v29->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v12 - 13);
            }
            *((_DWORD *)v12 - 20) = LODWORD(p_m_ThreatTargets->p[v28].m_Radius);
          }
          v12 -= 16;
          --v11;
        }
        while ( v11 );
      }
      if ( v10 >= 0 )
      {
        v33 = (__int64)&p_m_ThreatTargets->p[v10];
        v34 = (char *)((char *)this - (char *)p_m_ThreatTargets);
        do
        {
          if ( !*(_QWORD *)&v34[v33 + 1008] )
          {
            v35 = --p_m_ThreatTargets->size;
            v36 = p_m_ThreatTargets->p[v35].m_pTarget.m_pPointer;
            if ( *(_QWORD *)(v33 + 16) )
            {
              v37 = *(_QWORD *)v33;
              v38 = *(_QWORD **)(v33 + 8);
              *(_QWORD *)(v37 + 8) = v38;
              *v38 = v37;
              *(_QWORD *)v33 = v33;
              *(_QWORD *)(v33 + 8) = v33;
            }
            *(_QWORD *)(v33 + 16) = v36;
            if ( v36 )
            {
              v39 = v36->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
              v39->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v33;
              *(_QWORD *)v33 = v39;
              *(_QWORD *)(v33 + 8) = &v36->m_SafePointerList;
              v36->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v33;
            }
            *(float *)(v33 + 24) = p_m_ThreatTargets->p[v35].m_Radius;
          }
          v33 -= 32i64;
          --v10;
        }
        while ( v10 >= 0 );
      }
    }
    LODWORD(size) = p_m_ThreatTargets->size;
    if ( (int)p_m_ThreatTargets->size < 10 )
    {
LABEL_44:
      v40 = &p_m_ThreatTargets->p[(unsigned int)size];
      p_m_ThreatTargets->size = size + 1;
      if ( v40->m_pTarget.m_pPointer )
      {
        v41 = v40->m_pTarget.mPrev;
        mNext = v40->m_pTarget.mNext;
        v41->mNext = mNext;
        mNext->mPrev = v41;
        v40->m_pTarget.mPrev = &v40->m_pTarget;
        v40->m_pTarget.mNext = &v40->m_pTarget;
      }
      v40->m_pTarget.m_pPointer = pTarget;
      if ( pTarget )
      {
        v43 = pTarget->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
        v43->mNext = &v40->m_pTarget;
        v40->m_pTarget.mPrev = v43;
        v40->m_pTarget.mNext = &pTarget->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
        pTarget->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = &v40->m_pTarget;
      }
      v40->m_Radius = radius;
    }
  }
}

// File Line: 428
// RVA: 0x34F7E0
void __fastcall UFG::AIEntityComponent::ClearThreatTargets(UFG::AIEntityComponent *this)
{
  this->m_ThreatTargets.size = 0;
}

// File Line: 448
// RVA: 0x14AEA80
__int64 dynamic_initializer_for__UFG::ActiveAIEntityComponent::s_ActiveAIEntityComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::ActiveAIEntityComponent::s_ActiveAIEntityComponentList__);
}

// File Line: 449
// RVA: 0x363460
__int64 __fastcall UFG::ActiveAIEntityComponent::GetTypeSize(UFG::ActiveAIEntityComponent *this)
{
  return 4208i64;
}

// File Line: 453
// RVA: 0x32C350
void __fastcall UFG::ActiveAIEntityComponent::ActiveAIEntityComponent(
        UFG::ActiveAIEntityComponent *this,
        unsigned int name_uid,
        UFG::qPropertySet *properties)
{
  UFG::qNode<UFG::ActiveAIEntityComponent,UFG::ActiveAIEntityComponent> *mPrev; // rax
  bool *v6; // rax
  bool *p_p_m_KnowledgeBase; // rcx
  UFG::SimObject *m_pSimObject; // rbx
  UFG::PedSpawnManager *Instance; // rax
  UFG::TargetingSystemPedBaseComponent *m_pSimComponent; // rcx
  int v11; // eax
  void *p_m_KnowledgeBase; // [rsp+80h] [rbp+18h] BYREF
  UFG::Ticket *p_m_ticketUpdate; // [rsp+88h] [rbp+20h]

  UFG::AIEntityComponent::AIEntityComponent(this, name_uid, properties, 0);
  this->mPrev = &this->UFG::qNode<UFG::ActiveAIEntityComponent,UFG::ActiveAIEntityComponent>;
  this->mNext = &this->UFG::qNode<UFG::ActiveAIEntityComponent,UFG::ActiveAIEntityComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::ActiveAIEntityComponent::`vftable;
  p_m_KnowledgeBase = &this->m_KnowledgeBase;
  this->m_KnowledgeBase.m_pParentSimObject.mPrev = &this->m_KnowledgeBase.m_pParentSimObject;
  this->m_KnowledgeBase.m_pParentSimObject.mNext = &this->m_KnowledgeBase.m_pParentSimObject;
  this->m_KnowledgeBase.m_pParentSimObject.m_pPointer = 0i64;
  this->m_KnowledgeBase.m_bEnabled = 1;
  this->m_KnowledgeBase.m_aHostilePedRecords.p = 0i64;
  *(_QWORD *)&this->m_KnowledgeBase.m_aHostilePedRecords.size = 0i64;
  this->m_KnowledgeBase.m_ticketRefreshHostiles.mPrev = &this->m_KnowledgeBase.m_ticketRefreshHostiles;
  this->m_KnowledgeBase.m_ticketRefreshHostiles.mNext = &this->m_KnowledgeBase.m_ticketRefreshHostiles;
  this->m_KnowledgeBase.m_ticketRefreshHostiles.mTimestamp = 0i64;
  this->m_KnowledgeBase.m_ticketRefreshHostiles.mActiveCallback.m_Closure.m_pthis = 0i64;
  this->m_KnowledgeBase.m_ticketRefreshHostiles.mActiveCallback.m_Closure.m_pFunction = 0i64;
  this->m_KnowledgeBase.m_ticketRefreshHostiles.mInactiveCallback.m_Closure.m_pthis = 0i64;
  this->m_KnowledgeBase.m_ticketRefreshHostiles.mInactiveCallback.m_Closure.m_pFunction = 0i64;
  p_m_ticketUpdate = &this->m_KnowledgeBase.m_ticketUpdate;
  this->m_KnowledgeBase.m_ticketUpdate.mPrev = &this->m_KnowledgeBase.m_ticketUpdate;
  this->m_KnowledgeBase.m_ticketUpdate.mNext = &this->m_KnowledgeBase.m_ticketUpdate;
  this->m_KnowledgeBase.m_ticketUpdate.mTimestamp = 0i64;
  this->m_KnowledgeBase.m_ticketUpdate.mActiveCallback.m_Closure.m_pthis = 0i64;
  this->m_KnowledgeBase.m_ticketUpdate.mActiveCallback.m_Closure.m_pFunction = 0i64;
  this->m_KnowledgeBase.m_ticketUpdate.mInactiveCallback.m_Closure.m_pthis = 0i64;
  this->m_KnowledgeBase.m_ticketUpdate.mInactiveCallback.m_Closure.m_pFunction = 0i64;
  UFG::RebindingComponentHandle<UFG::AIActionTreeComponent,0>::RebindingComponentHandle<UFG::AIActionTreeComponent,0>(&this->m_pAIActionTreeComponent);
  UFG::RebindingComponentHandle<UFG::CharacterControllerInterface,0>::RebindingComponentHandle<UFG::CharacterControllerInterface,0>(&this->m_pCharacterController);
  UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0>::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0>(&this->m_pAICharacterControllerBaseComponent);
  this->m_pCurrentFormationManagerComponent.mPrev = &this->m_pCurrentFormationManagerComponent;
  this->m_pCurrentFormationManagerComponent.mNext = &this->m_pCurrentFormationManagerComponent;
  this->m_pCurrentFormationManagerComponent.m_pPointer = 0i64;
  p_m_KnowledgeBase = &this->m_pCurrentPedFormationManagerComponent;
  this->m_pCurrentPedFormationManagerComponent.mPrev = &this->m_pCurrentPedFormationManagerComponent;
  this->m_pCurrentPedFormationManagerComponent.mNext = &this->m_pCurrentPedFormationManagerComponent;
  this->m_pCurrentPedFormationManagerComponent.m_pPointer = 0i64;
  UFG::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0>::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0>(&this->m_pCharacterPhysicsComponent);
  UFG::RebindingComponentHandle<UFG::HitReactionComponent,0>::RebindingComponentHandle<UFG::HitReactionComponent,0>(&this->m_pHitReactionComponent);
  UFG::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0>::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0>(&this->m_pAIScriptInterfaceComponent);
  UFG::RebindingComponentHandle<UFG::InterestPointUserComponent,0>::RebindingComponentHandle<UFG::InterestPointUserComponent,0>(&this->m_pInterestPointUserComponent);
  p_m_KnowledgeBase = &this->m_pCurrentAttackTarget;
  this->m_pCurrentAttackTarget.mPrev = &this->m_pCurrentAttackTarget;
  this->m_pCurrentAttackTarget.mNext = &this->m_pCurrentAttackTarget;
  this->m_pCurrentAttackTarget.m_pPointer = 0i64;
  `eh vector constructor iterator(
    this->m_pDesiredTarget,
    0x18ui64,
    91,
    (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>);
  p_m_KnowledgeBase = &this->m_SupplementaryAttackTargets;
  this->m_SupplementaryAttackTargets.mNode.mPrev = &this->m_SupplementaryAttackTargets.mNode;
  this->m_SupplementaryAttackTargets.mNode.mNext = &this->m_SupplementaryAttackTargets.mNode;
  mPrev = UFG::ActiveAIEntityComponent::s_ActiveAIEntityComponentList.mNode.mPrev;
  UFG::ActiveAIEntityComponent::s_ActiveAIEntityComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::ActiveAIEntityComponent,UFG::ActiveAIEntityComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::ActiveAIEntityComponent,UFG::ActiveAIEntityComponent> *)&UFG::ActiveAIEntityComponent::s_ActiveAIEntityComponentList;
  UFG::ActiveAIEntityComponent::s_ActiveAIEntityComponentList.mNode.mPrev = &this->UFG::qNode<UFG::ActiveAIEntityComponent,UFG::ActiveAIEntityComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::ActiveAIEntityComponent::_ActiveAIEntityComponentTypeUID,
    "ActiveAIEntityComponent");
  *(_WORD *)this->m_CompletedNavigationTask = 0;
  this->m_MinTimeBetweenUpdateTarget = 0.1;
  this->m_MaxTimeBetweenUpdateTarget = 0.30000001;
  if ( properties )
  {
    this->m_MinTimeBetweenUpdateTarget = 0.1;
    this->m_MaxTimeBetweenUpdateTarget = 0.30000001;
    LOBYTE(p_m_KnowledgeBase) = 0;
    v6 = UFG::qPropertySet::Get<bool>(properties, (UFG::qArray<unsigned long,0> *)&qSymbol_CanWander, DEPTH_RECURSE);
    p_p_m_KnowledgeBase = (bool *)&p_m_KnowledgeBase;
    if ( v6 )
      p_p_m_KnowledgeBase = v6;
    this->m_bCanWander = *p_p_m_KnowledgeBase;
  }
  this->m_CurrentEmotion = eAI_EMOTION_NONE;
  this->m_CurrentObjective = eAI_OBJECTIVE_NONE;
  UFG::NearbyCharacterManager::RemoveCharacter(UFG::NearbyCharacterManager::s_pInstance, this);
  UFG::NearbyCharacterManager::AddCharacter(UFG::NearbyCharacterManager::s_pInstance, this);
  if ( UFG::g_AIObjectiveParams[this->m_CurrentObjective].m_IsHostile )
  {
    m_pSimObject = this->m_pSimObject;
    Instance = UFG::PedSpawnManager::GetInstance();
    UFG::PedSpawnManager::SetSuspendOption(Instance, m_pSimObject, NoSuspend);
  }
  if ( this->m_pTargetingSystemBaseComponent.m_pSimComponent )
  {
    m_pSimComponent = (UFG::TargetingSystemPedBaseComponent *)this->m_pTargetingSystemBaseComponent.m_pSimComponent;
    if ( UFG::g_AIObjectiveParams[0].m_IsHostile )
      UFG::TargetingSystemPedBaseComponent::SetToHighFrequencyUpdate(m_pSimComponent);
    else
      UFG::TargetingSystemPedBaseComponent::SetToLowFrequencyUpdate(m_pSimComponent);
    LOBYTE(this->m_pTargetingSystemBaseComponent.m_pSimComponent[9].vfptr) = 1;
  }
  this->m_PrevObjectiveWasHostile = 0;
  this->m_MaxEngagementDistanceXY = 20.0;
  this->m_MaxEngagementDistanceZ = 2.0;
  this->m_EngagementOverrideEnabled = 0;
  this->m_NextTimeToUpdateAttackTarget = -999999.0;
  this->m_TimeAllowedToKeepAttackingDeadTarget = 0.0;
  *(_QWORD *)&this->m_TargetToStayNear = 0i64;
  this->m_MaxDistanceFromTargetToStayNearHysteresis = 0.0;
  *(_QWORD *)&this->m_ScriptedParkourTypeNearGoal = 0i64;
  this->m_ScriptOverrideFreerunning = 0;
  *(_WORD *)&this->m_IsSpawning = 1;
  this->m_InPropInteractBranch = 0;
  this->m_ChanceOfCleanVault = *UFG::qPropertySet::Get<float>(
                                  properties,
                                  (UFG::qArray<unsigned long,0> *)&SimSym_ChanceOfCleanVault,
                                  DEPTH_RECURSE);
  this->m_CleanNextVault = UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed) < this->m_ChanceOfCleanVault;
  v11 = initted;
  if ( !initted )
    v11 = 1;
  initted = v11;
}

// File Line: 519
// RVA: 0x334FF0
void __fastcall UFG::ActiveAIEntityComponent::~ActiveAIEntityComponent(UFG::ActiveAIEntityComponent *this)
{
  UFG::qNode<UFG::ActiveAIEntityComponent,UFG::ActiveAIEntityComponent> *v2; // rsi
  UFG::qNode<UFG::ActiveAIEntityComponent,UFG::ActiveAIEntityComponent> *mPrev; // rcx
  UFG::qNode<UFG::ActiveAIEntityComponent,UFG::ActiveAIEntityComponent> *mNext; // rax
  UFG::qList<UFG::SupplementaryAttackTarget,UFG::SupplementaryAttackTarget,1,0> *p_m_SupplementaryAttackTargets; // rdi
  UFG::qNode<UFG::SupplementaryAttackTarget,UFG::SupplementaryAttackTarget> *v6; // r8
  UFG::qNode<UFG::SupplementaryAttackTarget,UFG::SupplementaryAttackTarget> *v7; // rcx
  UFG::qNode<UFG::SupplementaryAttackTarget,UFG::SupplementaryAttackTarget> *v8; // rax
  UFG::qNode<UFG::SupplementaryAttackTarget,UFG::SupplementaryAttackTarget> *v9; // r9
  UFG::qNode<UFG::SupplementaryAttackTarget,UFG::SupplementaryAttackTarget> *v10; // rcx
  UFG::qNode<UFG::SupplementaryAttackTarget,UFG::SupplementaryAttackTarget> *v11; // rax
  UFG::qNode<UFG::SupplementaryAttackTarget,UFG::SupplementaryAttackTarget> *v12; // rdx
  UFG::qNode<UFG::SupplementaryAttackTarget,UFG::SupplementaryAttackTarget> *v13; // rax
  UFG::qNode<UFG::SupplementaryAttackTarget,UFG::SupplementaryAttackTarget> *v14; // rdx
  UFG::qNode<UFG::SupplementaryAttackTarget,UFG::SupplementaryAttackTarget> *v15; // rax
  UFG::qNode<UFG::SupplementaryAttackTarget,UFG::SupplementaryAttackTarget> *v16; // rcx
  UFG::qNode<UFG::SupplementaryAttackTarget,UFG::SupplementaryAttackTarget> *v17; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AttackRightsComponent> *p_m_pCurrentAttackTarget; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v22; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::PedFormationManagerComponent> *p_m_pCurrentPedFormationManagerComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v24; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v26; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v27; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::FormationManagerComponent> *p_m_pCurrentFormationManagerComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v29; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v30; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v31; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v32; // rax
  UFG::qNode<UFG::ActiveAIEntityComponent,UFG::ActiveAIEntityComponent> *v33; // rcx
  UFG::qNode<UFG::ActiveAIEntityComponent,UFG::ActiveAIEntityComponent> *v34; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::ActiveAIEntityComponent::`vftable;
  if ( this == UFG::ActiveAIEntityComponent::s_ActiveAIEntityComponentpCurrentIterator )
    UFG::ActiveAIEntityComponent::s_ActiveAIEntityComponentpCurrentIterator = (UFG::ActiveAIEntityComponent *)&this->mPrev[-84].mNext;
  v2 = &this->UFG::qNode<UFG::ActiveAIEntityComponent,UFG::ActiveAIEntityComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  p_m_SupplementaryAttackTargets = &this->m_SupplementaryAttackTargets;
  while ( (UFG::qList<UFG::SupplementaryAttackTarget,UFG::SupplementaryAttackTarget,1,0> *)this->m_SupplementaryAttackTargets.mNode.mNext != &this->m_SupplementaryAttackTargets )
  {
    v6 = this->m_SupplementaryAttackTargets.mNode.mNext;
    v7 = v6->mPrev;
    v8 = v6->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v6->mPrev = v6;
    v6->mNext = v6;
    v9 = v6 + 1;
    if ( v6[2].mPrev )
    {
      v10 = v9->mPrev;
      v11 = v6[1].mNext;
      v10->mNext = v11;
      v11->mPrev = v10;
      v9->mPrev = v9;
      v6[1].mNext = v6 + 1;
    }
    v6[2].mPrev = 0i64;
    v12 = v9->mPrev;
    v13 = v6[1].mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    v9->mPrev = v9;
    v6[1].mNext = v6 + 1;
    v14 = v6->mPrev;
    v15 = v6->mNext;
    v14->mNext = v15;
    v15->mPrev = v14;
    v6->mPrev = v6;
    v6->mNext = v6;
    operator delete[](v6);
  }
  UFG::qList<UFG::SupplementaryAttackTarget,UFG::SupplementaryAttackTarget,1,0>::DeleteNodes((UFG::qList<UFG::CollisionMeshData::DeferredBreakablePartsMark,UFG::CollisionMeshData::DeferredBreakablePartsMark,1,0> *)&this->m_SupplementaryAttackTargets);
  v16 = p_m_SupplementaryAttackTargets->mNode.mPrev;
  v17 = this->m_SupplementaryAttackTargets.mNode.mNext;
  v16->mNext = v17;
  v17->mPrev = v16;
  p_m_SupplementaryAttackTargets->mNode.mPrev = &p_m_SupplementaryAttackTargets->mNode;
  this->m_SupplementaryAttackTargets.mNode.mNext = &this->m_SupplementaryAttackTargets.mNode;
  `eh vector destructor iterator(
    this->m_pDesiredTarget,
    0x18ui64,
    91,
    (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
  p_m_pCurrentAttackTarget = &this->m_pCurrentAttackTarget;
  if ( this->m_pCurrentAttackTarget.m_pPointer )
  {
    v19 = p_m_pCurrentAttackTarget->mPrev;
    v20 = this->m_pCurrentAttackTarget.mNext;
    v19->mNext = v20;
    v20->mPrev = v19;
    p_m_pCurrentAttackTarget->mPrev = p_m_pCurrentAttackTarget;
    this->m_pCurrentAttackTarget.mNext = &this->m_pCurrentAttackTarget;
  }
  this->m_pCurrentAttackTarget.m_pPointer = 0i64;
  v21 = p_m_pCurrentAttackTarget->mPrev;
  v22 = this->m_pCurrentAttackTarget.mNext;
  v21->mNext = v22;
  v22->mPrev = v21;
  p_m_pCurrentAttackTarget->mPrev = p_m_pCurrentAttackTarget;
  this->m_pCurrentAttackTarget.mNext = &this->m_pCurrentAttackTarget;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pInterestPointUserComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pAIScriptInterfaceComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pHitReactionComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pCharacterPhysicsComponent);
  p_m_pCurrentPedFormationManagerComponent = &this->m_pCurrentPedFormationManagerComponent;
  if ( this->m_pCurrentPedFormationManagerComponent.m_pPointer )
  {
    v24 = p_m_pCurrentPedFormationManagerComponent->mPrev;
    v25 = this->m_pCurrentPedFormationManagerComponent.mNext;
    v24->mNext = v25;
    v25->mPrev = v24;
    p_m_pCurrentPedFormationManagerComponent->mPrev = p_m_pCurrentPedFormationManagerComponent;
    this->m_pCurrentPedFormationManagerComponent.mNext = &this->m_pCurrentPedFormationManagerComponent;
  }
  this->m_pCurrentPedFormationManagerComponent.m_pPointer = 0i64;
  v26 = p_m_pCurrentPedFormationManagerComponent->mPrev;
  v27 = this->m_pCurrentPedFormationManagerComponent.mNext;
  v26->mNext = v27;
  v27->mPrev = v26;
  p_m_pCurrentPedFormationManagerComponent->mPrev = p_m_pCurrentPedFormationManagerComponent;
  this->m_pCurrentPedFormationManagerComponent.mNext = &this->m_pCurrentPedFormationManagerComponent;
  p_m_pCurrentFormationManagerComponent = &this->m_pCurrentFormationManagerComponent;
  if ( this->m_pCurrentFormationManagerComponent.m_pPointer )
  {
    v29 = p_m_pCurrentFormationManagerComponent->mPrev;
    v30 = this->m_pCurrentFormationManagerComponent.mNext;
    v29->mNext = v30;
    v30->mPrev = v29;
    p_m_pCurrentFormationManagerComponent->mPrev = p_m_pCurrentFormationManagerComponent;
    this->m_pCurrentFormationManagerComponent.mNext = &this->m_pCurrentFormationManagerComponent;
  }
  this->m_pCurrentFormationManagerComponent.m_pPointer = 0i64;
  v31 = p_m_pCurrentFormationManagerComponent->mPrev;
  v32 = this->m_pCurrentFormationManagerComponent.mNext;
  v31->mNext = v32;
  v32->mPrev = v31;
  p_m_pCurrentFormationManagerComponent->mPrev = p_m_pCurrentFormationManagerComponent;
  this->m_pCurrentFormationManagerComponent.mNext = &this->m_pCurrentFormationManagerComponent;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pAICharacterControllerBaseComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pCharacterController);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pAIActionTreeComponent);
  UFG::PedKnowledgeBase::~PedKnowledgeBase(&this->m_KnowledgeBase);
  v33 = v2->mPrev;
  v34 = v2->mNext;
  v33->mNext = v34;
  v34->mPrev = v33;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::AIEntityComponent::~AIEntityComponent(this);
}

// File Line: 541
// RVA: 0x382840
void __fastcall UFG::ActiveAIEntityComponent::Reset(UFG::ActiveAIEntityComponent *this)
{
  __int64 v2; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *m_pDesiredTarget; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::SimComponent *m_pSimComponent; // rax
  UFG::PedKnowledgeBase *p_m_KnowledgeBase; // rdi
  UFG::PedKnowledgeRecord *p; // rcx
  void *v9; // rbx

  UFG::ActiveAIEntityComponent::SetCurrentObjective(this, eAI_OBJECTIVE_NONE, "ActiveAIEntityComponent::Reset");
  this->m_AIPositionValid = 0;
  v2 = 91i64;
  m_pDesiredTarget = this->m_pDesiredTarget;
  do
  {
    if ( m_pDesiredTarget->m_pPointer )
    {
      mPrev = m_pDesiredTarget->mPrev;
      mNext = m_pDesiredTarget->mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      m_pDesiredTarget->mPrev = m_pDesiredTarget;
      m_pDesiredTarget->mNext = m_pDesiredTarget;
    }
    m_pDesiredTarget->m_pPointer = 0i64;
    ++m_pDesiredTarget;
    --v2;
  }
  while ( v2 );
  this->m_HostilityEnabled = 1;
  *(_WORD *)&this->m_IsSpawning = 1;
  this->m_InPropInteractBranch = 0;
  this->m_NextTimeToUpdateAttackTarget = -999999.0;
  m_pSimComponent = this->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent;
  if ( m_pSimComponent )
    m_pSimComponent[3].m_TypeUID = 0;
  p_m_KnowledgeBase = &this->m_KnowledgeBase;
  this->m_ThreatTargets.size = 0;
  this->m_KnowledgeBase.m_bEnabled = 1;
  p = this->m_KnowledgeBase.m_aHostilePedRecords.p;
  if ( p )
  {
    v9 = (char *)&p[-1] + 48;
    `eh vector destructor iterator(
      p,
      0x38ui64,
      *((_DWORD *)&p[-1] + 12),
      (void (__fastcall *)(void *))UFG::InterestPointUseDetails::~InterestPointUseDetails);
    operator delete[](v9);
  }
  p_m_KnowledgeBase->m_aHostilePedRecords.p = 0i64;
  *(_QWORD *)&p_m_KnowledgeBase->m_aHostilePedRecords.size = 0i64;
  UFG::PedKnowledgeBase::RefreshHostileList(p_m_KnowledgeBase, 0.0);
}

// File Line: 565
// RVA: 0x382F00
void __fastcall UFG::ActiveAIEntityComponent::ResetAndLoadProperties(UFG::ActiveAIEntityComponent *this)
{
  UFG::SceneObjectProperties *m_pSceneObj; // rdx
  UFG::qPropertySet *mpWritableProperties; // rcx
  bool *v4; // rax
  char *v5; // rcx
  char v6; // al
  UFG::AIActionTreeComponent *m_pSimComponent; // rcx
  char v8; // [rsp+30h] [rbp+8h] BYREF

  m_pSceneObj = this->m_pSimObject->m_pSceneObj;
  mpWritableProperties = m_pSceneObj->mpWritableProperties;
  if ( mpWritableProperties || (mpWritableProperties = m_pSceneObj->mpConstProperties) != 0i64 )
  {
    this->m_MinTimeBetweenUpdateTarget = 0.1;
    this->m_MaxTimeBetweenUpdateTarget = 0.30000001;
    v8 = 0;
    v4 = UFG::qPropertySet::Get<bool>(
           mpWritableProperties,
           (UFG::qArray<unsigned long,0> *)&qSymbol_CanWander,
           DEPTH_RECURSE);
    v5 = &v8;
    if ( v4 )
      v5 = (char *)v4;
    v6 = *v5;
    m_pSimComponent = (UFG::AIActionTreeComponent *)this->m_pAIActionTreeComponent.m_pSimComponent;
    this->m_bCanWander = v6;
    if ( m_pSimComponent )
      UFG::AIActionTreeComponent::ResetDefaultTree(m_pSimComponent);
  }
  UFG::ActiveAIEntityComponent::Reset(this);
}

// File Line: 580
// RVA: 0x378800
void __fastcall UFG::ActiveAIEntityComponent::OnAttach(
        UFG::ActiveAIEntityComponent *this,
        UFG::SimObjectCharacter *object)
{
  UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0> *p_m_pAICharacterControllerBaseComponent; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rdx

  UFG::RebindingComponentHandle<UFG::CharacterControllerInterface,0>::Bind<UFG::SimObjectCharacter>(
    &this->m_pCharacterController,
    object);
  p_m_pAICharacterControllerBaseComponent = &this->m_pAICharacterControllerBaseComponent;
  if ( this->m_pAICharacterControllerBaseComponent.m_pSimComponent )
  {
    mNext = this->m_pAICharacterControllerBaseComponent.mNext;
    mPrev = p_m_pAICharacterControllerBaseComponent->mPrev;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->m_pAICharacterControllerBaseComponent.m_pSimComponent = 0i64;
LABEL_7:
    this->m_pAICharacterControllerBaseComponent.m_pSimObject = 0i64;
    this->m_pAICharacterControllerBaseComponent.mNext = &this->m_pAICharacterControllerBaseComponent;
    p_m_pAICharacterControllerBaseComponent->mPrev = p_m_pAICharacterControllerBaseComponent;
    goto LABEL_8;
  }
  if ( this->m_pAICharacterControllerBaseComponent.m_pSimObject
    && (p_m_pAICharacterControllerBaseComponent->mPrev != p_m_pAICharacterControllerBaseComponent
     || this->m_pAICharacterControllerBaseComponent.mNext != &this->m_pAICharacterControllerBaseComponent) )
  {
    v7 = this->m_pAICharacterControllerBaseComponent.mNext;
    v8 = p_m_pAICharacterControllerBaseComponent->mPrev;
    v8->mNext = v7;
    v7->mPrev = v8;
    goto LABEL_7;
  }
LABEL_8:
  this->m_pAICharacterControllerBaseComponent.m_Changed = 1;
  this->m_pAICharacterControllerBaseComponent.m_pSimObject = object;
  this->m_pAICharacterControllerBaseComponent.m_TypeUID = UFG::AICharacterControllerBaseComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0>::BindInternal<UFG::SimObjectCharacter>(
    p_m_pAICharacterControllerBaseComponent,
    object);
  UFG::RebindingComponentHandle<UFG::AIActionTreeComponent,0>::Bind<UFG::SimObjectCharacter>(
    &this->m_pAIActionTreeComponent,
    object);
  UFG::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0>::Bind<UFG::SimObjectCharacter>(
    &this->m_pCharacterPhysicsComponent,
    object);
  UFG::RebindingComponentHandle<UFG::HitReactionComponent,0>::Bind<UFG::SimObjectCharacter>(
    &this->m_pHitReactionComponent,
    object);
  UFG::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0>::Bind<UFG::SimObjectCharacter>(
    &this->m_pAIScriptInterfaceComponent,
    object);
  UFG::RebindingComponentHandle<UFG::InterestPointUserComponent,0>::Bind<UFG::SimObjectCharacter>(
    &this->m_pInterestPointUserComponent,
    object);
  UFG::AIEntityComponent::OnAttach(this, object);
  UFG::PedKnowledgeBase::OnAttach(&this->m_KnowledgeBase, object);
}

// File Line: 602
// RVA: 0x379EA0
void __fastcall UFG::ActiveAIEntityComponent::OnDetach(UFG::ActiveAIEntityComponent *this)
{
  UFG::RebindingComponentHandle<UFG::CharacterControllerInterface,0> *p_m_pCharacterController; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0> *p_m_pAICharacterControllerBaseComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::RebindingComponentHandle<UFG::AIActionTreeComponent,0> *p_m_pAIActionTreeComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0> *p_m_pCharacterPhysicsComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v19; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v20; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rax
  UFG::RebindingComponentHandle<UFG::HitReactionComponent,0> *p_m_pHitReactionComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v23; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v24; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v25; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v26; // rax
  UFG::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0> *p_m_pAIScriptInterfaceComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v28; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v29; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v30; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v31; // rax
  UFG::RebindingComponentHandle<UFG::InterestPointUserComponent,0> *p_m_pInterestPointUserComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v33; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v34; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v35; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v36; // rax

  p_m_pCharacterController = &this->m_pCharacterController;
  if ( this->m_pCharacterController.m_pSimComponent )
  {
    mPrev = p_m_pCharacterController->mPrev;
    mNext = this->m_pCharacterController.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->m_pCharacterController.m_pSimComponent = 0i64;
LABEL_7:
    p_m_pCharacterController->m_pSimObject = 0i64;
    p_m_pCharacterController->mNext = p_m_pCharacterController;
    p_m_pCharacterController->mPrev = p_m_pCharacterController;
    goto LABEL_8;
  }
  if ( this->m_pCharacterController.m_pSimObject
    && (p_m_pCharacterController->mPrev != p_m_pCharacterController
     || this->m_pCharacterController.mNext != &this->m_pCharacterController) )
  {
    v5 = p_m_pCharacterController->mPrev;
    v6 = p_m_pCharacterController->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  p_m_pAICharacterControllerBaseComponent = &this->m_pAICharacterControllerBaseComponent;
  p_m_pCharacterController->m_Changed = 1;
  if ( this->m_pAICharacterControllerBaseComponent.m_pSimComponent )
  {
    v8 = p_m_pAICharacterControllerBaseComponent->mPrev;
    v9 = this->m_pAICharacterControllerBaseComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    this->m_pAICharacterControllerBaseComponent.m_pSimComponent = 0i64;
LABEL_14:
    this->m_pAICharacterControllerBaseComponent.m_pSimObject = 0i64;
    this->m_pAICharacterControllerBaseComponent.mNext = &this->m_pAICharacterControllerBaseComponent;
    p_m_pAICharacterControllerBaseComponent->mPrev = p_m_pAICharacterControllerBaseComponent;
    goto LABEL_15;
  }
  if ( this->m_pAICharacterControllerBaseComponent.m_pSimObject
    && (p_m_pAICharacterControllerBaseComponent->mPrev != p_m_pAICharacterControllerBaseComponent
     || this->m_pAICharacterControllerBaseComponent.mNext != &this->m_pAICharacterControllerBaseComponent) )
  {
    v10 = p_m_pAICharacterControllerBaseComponent->mPrev;
    v11 = this->m_pAICharacterControllerBaseComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    goto LABEL_14;
  }
LABEL_15:
  this->m_pAICharacterControllerBaseComponent.m_Changed = 1;
  p_m_pAIActionTreeComponent = &this->m_pAIActionTreeComponent;
  if ( this->m_pAIActionTreeComponent.m_pSimComponent )
  {
    v13 = p_m_pAIActionTreeComponent->mPrev;
    v14 = this->m_pAIActionTreeComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    this->m_pAIActionTreeComponent.m_pSimComponent = 0i64;
LABEL_21:
    this->m_pAIActionTreeComponent.m_pSimObject = 0i64;
    this->m_pAIActionTreeComponent.mNext = &this->m_pAIActionTreeComponent;
    p_m_pAIActionTreeComponent->mPrev = p_m_pAIActionTreeComponent;
    goto LABEL_22;
  }
  if ( this->m_pAIActionTreeComponent.m_pSimObject
    && (p_m_pAIActionTreeComponent->mPrev != p_m_pAIActionTreeComponent
     || this->m_pAIActionTreeComponent.mNext != &this->m_pAIActionTreeComponent) )
  {
    v15 = p_m_pAIActionTreeComponent->mPrev;
    v16 = this->m_pAIActionTreeComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    goto LABEL_21;
  }
LABEL_22:
  this->m_pAIActionTreeComponent.m_Changed = 1;
  p_m_pCharacterPhysicsComponent = &this->m_pCharacterPhysicsComponent;
  if ( this->m_pCharacterPhysicsComponent.m_pSimComponent )
  {
    v18 = p_m_pCharacterPhysicsComponent->mPrev;
    v19 = this->m_pCharacterPhysicsComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    this->m_pCharacterPhysicsComponent.m_pSimComponent = 0i64;
LABEL_28:
    this->m_pCharacterPhysicsComponent.m_pSimObject = 0i64;
    this->m_pCharacterPhysicsComponent.mNext = &this->m_pCharacterPhysicsComponent;
    p_m_pCharacterPhysicsComponent->mPrev = p_m_pCharacterPhysicsComponent;
    goto LABEL_29;
  }
  if ( this->m_pCharacterPhysicsComponent.m_pSimObject
    && (p_m_pCharacterPhysicsComponent->mPrev != p_m_pCharacterPhysicsComponent
     || this->m_pCharacterPhysicsComponent.mNext != &this->m_pCharacterPhysicsComponent) )
  {
    v20 = p_m_pCharacterPhysicsComponent->mPrev;
    v21 = this->m_pCharacterPhysicsComponent.mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    goto LABEL_28;
  }
LABEL_29:
  this->m_pCharacterPhysicsComponent.m_Changed = 1;
  p_m_pHitReactionComponent = &this->m_pHitReactionComponent;
  if ( this->m_pHitReactionComponent.m_pSimComponent )
  {
    v23 = p_m_pHitReactionComponent->mPrev;
    v24 = this->m_pHitReactionComponent.mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    this->m_pHitReactionComponent.m_pSimComponent = 0i64;
LABEL_35:
    this->m_pHitReactionComponent.m_pSimObject = 0i64;
    this->m_pHitReactionComponent.mNext = &this->m_pHitReactionComponent;
    p_m_pHitReactionComponent->mPrev = p_m_pHitReactionComponent;
    goto LABEL_36;
  }
  if ( this->m_pHitReactionComponent.m_pSimObject
    && (p_m_pHitReactionComponent->mPrev != p_m_pHitReactionComponent
     || this->m_pHitReactionComponent.mNext != &this->m_pHitReactionComponent) )
  {
    v25 = p_m_pHitReactionComponent->mPrev;
    v26 = this->m_pHitReactionComponent.mNext;
    v25->mNext = v26;
    v26->mPrev = v25;
    goto LABEL_35;
  }
LABEL_36:
  this->m_pHitReactionComponent.m_Changed = 1;
  p_m_pAIScriptInterfaceComponent = &this->m_pAIScriptInterfaceComponent;
  if ( this->m_pAIScriptInterfaceComponent.m_pSimComponent )
  {
    v28 = p_m_pAIScriptInterfaceComponent->mPrev;
    v29 = this->m_pAIScriptInterfaceComponent.mNext;
    v28->mNext = v29;
    v29->mPrev = v28;
    this->m_pAIScriptInterfaceComponent.m_pSimComponent = 0i64;
LABEL_42:
    this->m_pAIScriptInterfaceComponent.m_pSimObject = 0i64;
    this->m_pAIScriptInterfaceComponent.mNext = &this->m_pAIScriptInterfaceComponent;
    p_m_pAIScriptInterfaceComponent->mPrev = p_m_pAIScriptInterfaceComponent;
    goto LABEL_43;
  }
  if ( this->m_pAIScriptInterfaceComponent.m_pSimObject
    && (p_m_pAIScriptInterfaceComponent->mPrev != p_m_pAIScriptInterfaceComponent
     || this->m_pAIScriptInterfaceComponent.mNext != &this->m_pAIScriptInterfaceComponent) )
  {
    v30 = p_m_pAIScriptInterfaceComponent->mPrev;
    v31 = this->m_pAIScriptInterfaceComponent.mNext;
    v30->mNext = v31;
    v31->mPrev = v30;
    goto LABEL_42;
  }
LABEL_43:
  this->m_pAIScriptInterfaceComponent.m_Changed = 1;
  p_m_pInterestPointUserComponent = &this->m_pInterestPointUserComponent;
  if ( this->m_pInterestPointUserComponent.m_pSimComponent )
  {
    v33 = p_m_pInterestPointUserComponent->mPrev;
    v34 = this->m_pInterestPointUserComponent.mNext;
    v33->mNext = v34;
    v34->mPrev = v33;
    this->m_pInterestPointUserComponent.m_pSimComponent = 0i64;
LABEL_49:
    this->m_pInterestPointUserComponent.m_pSimObject = 0i64;
    this->m_pInterestPointUserComponent.mNext = &this->m_pInterestPointUserComponent;
    p_m_pInterestPointUserComponent->mPrev = p_m_pInterestPointUserComponent;
    goto LABEL_50;
  }
  if ( this->m_pInterestPointUserComponent.m_pSimObject
    && (p_m_pInterestPointUserComponent->mPrev != p_m_pInterestPointUserComponent
     || this->m_pInterestPointUserComponent.mNext != &this->m_pInterestPointUserComponent) )
  {
    v35 = p_m_pInterestPointUserComponent->mPrev;
    v36 = this->m_pInterestPointUserComponent.mNext;
    v35->mNext = v36;
    v36->mPrev = v35;
    goto LABEL_49;
  }
LABEL_50:
  this->m_pInterestPointUserComponent.m_Changed = 1;
  UFG::PedKnowledgeBase::OnDetach(&this->m_KnowledgeBase);
  UFG::AIEntityComponent::OnDetach(this);
}

// File Line: 621
// RVA: 0x38C890
void __fastcall UFG::ActiveAIEntityComponent::Update(UFG::ActiveAIEntityComponent *this, float delta_sec)
{
  hkgpIndexedMeshDefinitions::Edge *v2; // rdx
  UFG::SimComponent *m_pSimComponent; // rax
  float v5; // xmm0_4
  float v6; // xmm0_4
  UFG::SimComponent *v7; // rcx
  UFG::SimComponent *v8; // rdi
  UFG::SimObjectCVBase *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::AICharacterControllerBaseComponent *v11; // rax
  UFG::AICharacterControllerBaseComponent *v12; // rdi
  UFG::eHeadTrackType m_Type; // eax
  float y; // xmm1_4
  float z; // xmm2_4
  float v16; // xmm0_4
  float *m_pPointer; // rsi
  float v18; // xmm2_4
  float v19; // xmm1_4
  UFG::eAIEmotion mNext; // ecx

  m_pSimComponent = this->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    v5 = *(float *)&m_pSimComponent[3].m_TypeUID;
    if ( v5 > 0.0 )
    {
      v6 = v5 - delta_sec;
      if ( v6 <= 0.0 )
        v6 = 0.0;
      *(float *)&m_pSimComponent[3].m_TypeUID = v6;
    }
  }
  v7 = this->m_pHealthComponent.m_pSimComponent;
  v8 = this->m_pAIActionTreeComponent.m_pSimComponent;
  if ( v7
    && BYTE4(v7[1].m_BoundComponentHandles.mNode.mPrev)
    && !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat((hkgpIndexedMesh::EdgeBarrier *)v7, v2) )
  {
    if ( v8 && v8[3].m_pSimObject )
      ((void (__fastcall *)(UFG::SimComponent *))v8->vfptr[18].__vecDelDtor)(v8);
    UFG::ActiveAIEntityComponent::SetCurrentObjective(this, eAI_OBJECTIVE_NONE, "<Unknown>");
  }
  else
  {
    this->m_CurrentEmotion = eAI_EMOTION_NONE;
    UFG::ActiveAIEntityComponent::UpdateCurrentAttackTarget(this);
  }
  m_pSimObject = (UFG::SimObjectCVBase *)this->m_pSimObject;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      v11 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(m_pSimObject);
    else
      v11 = (UFG::AICharacterControllerBaseComponent *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                                      ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          m_pSimObject,
                                                          UFG::AICharacterControllerBaseComponent::_TypeUID)
                                                      : UFG::SimObject::GetComponentOfType(
                                                          m_pSimObject,
                                                          UFG::AICharacterControllerBaseComponent::_TypeUID));
    v12 = v11;
    if ( v11 )
    {
      m_Type = this->m_HeadTrackingTarget.m_Type;
      if ( m_Type == eHEAD_TRACK_TYPE_POSITION )
      {
        y = this->m_HeadTrackingTarget.m_Position.y;
        z = this->m_HeadTrackingTarget.m_Position.z;
        v16 = this->m_HeadTrackingTarget.m_Offset.x + this->m_HeadTrackingTarget.m_Position.x;
LABEL_28:
        v18 = z + this->m_HeadTrackingTarget.m_Offset.z;
        v19 = y + this->m_HeadTrackingTarget.m_Offset.y;
        v12->m_Intention.mDesiredLookAtPoint.x = v16;
        v12->m_Intention.mDesiredLookAtPoint.y = v19;
        v12->m_Intention.mDesiredLookAtPoint.z = v18;
        v12->m_Intention.mDesireToLookAtPoint = 1;
        v12->m_Intention.mDesiredLookAtPointEye.x = v16;
        v12->m_Intention.mDesiredLookAtPointEye.y = v19;
        v12->m_Intention.mDesiredLookAtPointEye.z = v18;
        v12->m_Intention.mDesireToLookAtPointEye = 1;
        goto LABEL_29;
      }
      if ( m_Type == eHEAD_TRACK_TYPE_TRANSFORM_NODE )
      {
        m_pPointer = (float *)this->m_HeadTrackingTarget.m_pTransformNodeComponent.m_pPointer;
        if ( m_pPointer )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->m_HeadTrackingTarget.m_pTransformNodeComponent.m_pPointer);
          y = m_pPointer[45];
          z = m_pPointer[46];
          v16 = this->m_HeadTrackingTarget.m_Offset.x + m_pPointer[44];
          goto LABEL_28;
        }
      }
    }
  }
LABEL_29:
  if ( this->m_pAIScriptInterfaceComponent.m_pSimComponent )
  {
    mNext = (UFG::eAIEmotion)this->m_pAIScriptInterfaceComponent.m_pSimComponent[10].m_BoundComponentHandles.mNode.mNext;
    if ( mNext )
      this->m_CurrentEmotion = mNext;
  }
}

// File Line: 700
// RVA: 0x355850
void __fastcall UFG::ActiveAIEntityComponent::EndFrame(UFG::ActiveAIEntityComponent *this)
{
  this->m_IsSpawning = 0;
}

// File Line: 710
// RVA: 0x3852B0
void __fastcall UFG::ActiveAIEntityComponent::SetCurrentObjective(
        UFG::ActiveAIEntityComponent *this,
        UFG::eAIObjective objective,
        const char *caller_debug_name)
{
  __int64 v3; // rsi
  UFG::SimObject *m_pSimObject; // rbx
  UFG::PedSpawnManager *Instance; // rax
  UFG::TargetingSystemPedBaseComponent *m_pSimComponent; // rcx

  v3 = objective;
  this->m_CurrentObjective = objective;
  UFG::NearbyCharacterManager::RemoveCharacter(UFG::NearbyCharacterManager::s_pInstance, this);
  UFG::NearbyCharacterManager::AddCharacter(UFG::NearbyCharacterManager::s_pInstance, this);
  if ( UFG::g_AIObjectiveParams[this->m_CurrentObjective].m_IsHostile )
  {
    m_pSimObject = this->m_pSimObject;
    Instance = UFG::PedSpawnManager::GetInstance();
    UFG::PedSpawnManager::SetSuspendOption(Instance, m_pSimObject, NoSuspend);
  }
  m_pSimComponent = (UFG::TargetingSystemPedBaseComponent *)this->m_pTargetingSystemBaseComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    if ( UFG::g_AIObjectiveParams[v3].m_IsHostile )
      UFG::TargetingSystemPedBaseComponent::SetToHighFrequencyUpdate(m_pSimComponent);
    else
      UFG::TargetingSystemPedBaseComponent::SetToLowFrequencyUpdate(m_pSimComponent);
    LOBYTE(this->m_pTargetingSystemBaseComponent.m_pSimComponent[9].vfptr) = 1;
  }
}

// File Line: 765
// RVA: 0x37EA60
UFG::ActiveAIEntityComponent *__fastcall UFG::ActiveAIEntityComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *pSceneObj,
        bool required)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v4; // rax
  UFG::qPropertySet *mpWritableProperties; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimComponent *v7; // rdi
  UFG::SimObject *m_pSimObject; // rdx
  __int16 m_Flags; // cx
  unsigned int v10; // ebx
  UFG::SimObjectModifier v12; // [rsp+38h] [rbp-30h] BYREF

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v4 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x1070ui64, "ActiveAIEntityComponent", 0i64, 1u);
  if ( v4 )
  {
    mpWritableProperties = pSceneObj->mpWritableProperties;
    if ( !mpWritableProperties )
      mpWritableProperties = pSceneObj->mpConstProperties;
    UFG::ActiveAIEntityComponent::ActiveAIEntityComponent(
      (UFG::ActiveAIEntityComponent *)v4,
      pSceneObj->m_NameUID,
      mpWritableProperties);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  m_pSimObject = pSceneObj->m_pSimObject;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    v10 = 22;
  else
    v10 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v12, m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v12, v7, v10);
  UFG::SimObjectModifier::Close(&v12);
  UFG::SimObjectModifier::~SimObjectModifier(&v12);
  return (UFG::ActiveAIEntityComponent *)v7;
}

// File Line: 790
// RVA: 0x385000
void __fastcall UFG::ActiveAIEntityComponent::SetBehaviourTree(
        UFG::ActiveAIEntityComponent *this,
        char *behaviour_tree_name)
{
  UFG::SimComponent *m_pSimComponent; // rcx

  m_pSimComponent = this->m_pAIActionTreeComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    ((void (__fastcall *)(UFG::SimComponent *))m_pSimComponent->vfptr[18].__vecDelDtor)(m_pSimComponent);
    UFG::AIActionTreeComponent::SetActionTreeFileName(
      (UFG::AIActionTreeComponent *)this->m_pAIActionTreeComponent.m_pSimComponent,
      behaviour_tree_name);
    UFG::AIActionTreeComponent::InitActionTree((UFG::AIActionTreeComponent *)this->m_pAIActionTreeComponent.m_pSimComponent);
  }
}

// File Line: 896
// RVA: 0x3948E0
void __fastcall UFG::ActiveAIEntityComponent::UpdateCurrentAttackTarget(UFG::ActiveAIEntityComponent *this)
{
  UFG::SimObjectCharacter *m_pSimObject; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AttackRightsComponent> *p_m_pCurrentAttackTarget; // rdi
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  float mSimTime_Temp; // xmm8_4
  float m_NextTimeToUpdateAttackTarget; // xmm1_4
  bool v8; // al
  UFG::SimComponent *m_pSimComponent; // r8
  UFG::SimObject *v10; // rdx
  UFG::SimComponent *m_pPointer; // rcx
  UFG::SimObject *v12; // rcx
  float m_MaxTimeBetweenUpdateTarget; // xmm6_4
  float m_MinTimeBetweenUpdateTarget; // xmm7_4
  float v15; // xmm0_4
  float v16; // xmm6_4
  float v17; // xmm7_4
  float v18; // xmm0_4
  __int64 m_CurrentObjective; // rdx
  UFG::SimComponent *v20; // rax
  bool v21; // al
  bool m_IsHostile; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::AttackRightsComponent> *v23; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v24; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rax
  float v26; // xmm7_4
  UFG::SimObjectGame *v27; // rcx
  UFG::TargetingSystemBaseComponent *m_pComponent; // rax
  __int16 m_Flags; // dx
  bool HasRangedWeaponEquippedWithAmmo; // r12
  UFG::SimComponent *v31; // rbx
  UFG::SimComponent *v32; // r15
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v33; // rbx
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v34; // r14
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v35; // rsi
  UFG::AttackRightsComponent *v36; // rsi
  float v37; // xmm0_4
  UFG::qSafePointer<UFG::SimComponent,UFG::AttackRightsComponent> *v38; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v39; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v40; // rax
  UFG::SimComponent *v41; // rax
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *i; // rax
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v43; // rdx
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v44; // rcx
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v45; // rax
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v46; // rcx
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v47; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v48; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v49; // rax
  _QWORD v50[5]; // [rsp+0h] [rbp-88h] BYREF
  UFG::qList<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList,0,0> list; // [rsp+28h] [rbp-60h] BYREF

  v50[4] = -2i64;
  m_pSimObject = (UFG::SimObjectCharacter *)this->m_pSimObject;
  if ( m_pSimObject && m_pSimObject == LocalPlayer )
  {
    p_m_pCurrentAttackTarget = &this->m_pCurrentAttackTarget;
    if ( this->m_pCurrentAttackTarget.m_pPointer )
    {
      mPrev = p_m_pCurrentAttackTarget->mPrev;
      mNext = p_m_pCurrentAttackTarget->mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_pCurrentAttackTarget->mPrev = p_m_pCurrentAttackTarget;
      p_m_pCurrentAttackTarget->mNext = p_m_pCurrentAttackTarget;
    }
LABEL_76:
    p_m_pCurrentAttackTarget->m_pPointer = 0i64;
    return;
  }
  mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
  m_NextTimeToUpdateAttackTarget = this->m_NextTimeToUpdateAttackTarget;
  v8 = UFG::Metrics::msInstance.mSimTime_Temp >= m_NextTimeToUpdateAttackTarget;
  if ( this->m_pHitReactionComponent.m_pSimComponent )
  {
    m_pSimComponent = this->m_pHitReactionComponent.m_pSimComponent;
    v10 = *(UFG::SimObject **)&m_pSimComponent[3].m_TypeUID;
    m_pPointer = this->m_pCurrentAttackTarget.m_pPointer;
    if ( m_pPointer )
      v12 = m_pPointer->m_pSimObject;
    else
      v12 = 0i64;
    v8 = UFG::Metrics::msInstance.mSimTime_Temp >= m_NextTimeToUpdateAttackTarget
      || v10
      && v10 != v12
      && *(float *)&m_pSimComponent[3].m_Flags < AttackabilityShared::ms_fMaxTimeSinceLastHitToUpdateTargeting;
  }
  if ( v8
    || (float)(UFG::Metrics::msInstance.mSimTime_Temp - m_NextTimeToUpdateAttackTarget) > AttackabilityShared::ms_fStarving )
  {
    m_MaxTimeBetweenUpdateTarget = this->m_MaxTimeBetweenUpdateTarget;
    m_MinTimeBetweenUpdateTarget = this->m_MinTimeBetweenUpdateTarget;
    v15 = m_MaxTimeBetweenUpdateTarget;
    if ( m_MaxTimeBetweenUpdateTarget > m_MinTimeBetweenUpdateTarget )
    {
      v15 = UFG::qRandom(
              m_MaxTimeBetweenUpdateTarget - m_MinTimeBetweenUpdateTarget,
              (unsigned int *)&UFG::qDefaultSeed)
          + m_MinTimeBetweenUpdateTarget;
      if ( v15 <= m_MinTimeBetweenUpdateTarget )
        v15 = m_MinTimeBetweenUpdateTarget;
      if ( v15 >= m_MaxTimeBetweenUpdateTarget )
        v15 = m_MaxTimeBetweenUpdateTarget;
    }
    this->m_NextTimeToUpdateAttackTarget = v15 + mSimTime_Temp;
    v16 = AttackabilityShared::ms_fMaxTimeToKeepAttackingDeadTarget;
    v17 = AttackabilityShared::ms_fMinTimeToKeepAttackingDeadTarget;
    v18 = AttackabilityShared::ms_fMaxTimeToKeepAttackingDeadTarget;
    if ( AttackabilityShared::ms_fMaxTimeToKeepAttackingDeadTarget > AttackabilityShared::ms_fMinTimeToKeepAttackingDeadTarget )
    {
      v18 = UFG::qRandom(
              AttackabilityShared::ms_fMaxTimeToKeepAttackingDeadTarget
            - AttackabilityShared::ms_fMinTimeToKeepAttackingDeadTarget,
              (unsigned int *)&UFG::qDefaultSeed)
          + v17;
      if ( v18 <= v17 )
        v18 = v17;
      if ( v18 >= v16 )
        v18 = v16;
    }
    this->m_TimeAllowedToKeepAttackingDeadTarget = v18;
    m_CurrentObjective = this->m_CurrentObjective;
    v20 = this->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent;
    v21 = v20 && LODWORD(v20[3].m_SafePointerList.mNode.mPrev) != 17
       || UFG::g_AIObjectiveParams[m_CurrentObjective].m_IsHostile;
    if ( !this->m_HostilityEnabled || !v21 || !this->m_pTransformNodeComponent.m_pSimComponent )
    {
      p_m_pCurrentAttackTarget = &this->m_pCurrentAttackTarget;
      if ( p_m_pCurrentAttackTarget->m_pPointer )
      {
        v48 = p_m_pCurrentAttackTarget->mPrev;
        v49 = p_m_pCurrentAttackTarget->mNext;
        v48->mNext = v49;
        v49->mPrev = v48;
        p_m_pCurrentAttackTarget->mPrev = p_m_pCurrentAttackTarget;
        p_m_pCurrentAttackTarget->mNext = p_m_pCurrentAttackTarget;
      }
      goto LABEL_76;
    }
    m_IsHostile = UFG::g_AIObjectiveParams[m_CurrentObjective].m_IsHostile;
    if ( m_IsHostile && !this->m_PrevObjectiveWasHostile )
    {
      v23 = &this->m_pCurrentAttackTarget;
      if ( this->m_pCurrentAttackTarget.m_pPointer )
      {
        v24 = v23->mPrev;
        v25 = this->m_pCurrentAttackTarget.mNext;
        v24->mNext = v25;
        v25->mPrev = v24;
        v23->mPrev = v23;
        this->m_pCurrentAttackTarget.mNext = &this->m_pCurrentAttackTarget;
      }
      this->m_pCurrentAttackTarget.m_pPointer = 0i64;
    }
    this->m_PrevObjectiveWasHostile = m_IsHostile;
    v26 = FLOAT_N1_0;
    v27 = (UFG::SimObjectGame *)this->m_pSimObject;
    if ( v27 )
    {
      m_Flags = v27->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (UFG::TargetingSystemBaseComponent *)v27->m_Components.p[20].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          m_pComponent = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                v27,
                                                                UFG::TargetingSystemBaseComponent::_TypeUID);
        else
          m_pComponent = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                v27,
                                                                UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        m_pComponent = (UFG::TargetingSystemBaseComponent *)v27->m_Components.p[20].m_pComponent;
      }
    }
    else
    {
      m_pComponent = 0i64;
    }
    HasRangedWeaponEquippedWithAmmo = UFG::HasRangedWeaponEquippedWithAmmo(m_pComponent);
    v31 = this->m_pTransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v31);
    list.mNode.mPrev = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *)&list;
    list.mNode.mNext = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *)&list;
    UFG::NearbyCharacterManager::GetNearbyCharacters(
      UFG::NearbyCharacterManager::s_pInstance,
      &list,
      eNEARBY_CHARACTER_FIGHTER,
      (UFG::qVector3 *)&v31[2].m_BoundComponentHandles);
    v32 = 0i64;
    v33 = list.mNode.mNext - 1;
    v34 = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *)&v50[3];
    if ( list.mNode.mNext - 1 != v34 )
    {
      do
      {
        v35 = v33[3].mPrev;
        if ( v35 )
        {
          v36 = (UFG::AttackRightsComponent *)v35[20].mNext;
          v37 = HasRangedWeaponEquippedWithAmmo
              ? UFG::ActiveAIEntityComponent::GetAttackabilityScoreRanged(this, v36)
              : UFG::ActiveAIEntityComponent::GetAttackabilityScoreMelee(this, v36);
          if ( v37 >= 0.0 )
            goto LABEL_63;
          if ( v36 == this->m_pCurrentAttackTarget.m_pPointer )
          {
            v38 = &this->m_pCurrentAttackTarget;
            if ( this->m_pCurrentAttackTarget.m_pPointer )
            {
              v39 = v38->mPrev;
              v40 = this->m_pCurrentAttackTarget.mNext;
              v39->mNext = v40;
              v40->mPrev = v39;
              v38->mPrev = v38;
              this->m_pCurrentAttackTarget.mNext = &this->m_pCurrentAttackTarget;
            }
            this->m_pCurrentAttackTarget.m_pPointer = 0i64;
          }
          if ( v37 >= 0.0 )
          {
LABEL_63:
            if ( v26 < 0.0 || v37 > v26 )
            {
              v32 = v36;
              v26 = v37;
            }
          }
        }
        v33 = v33[1].mNext - 1;
      }
      while ( v33 != v34 );
      if ( v32 )
      {
        v41 = this->m_pCurrentAttackTarget.m_pPointer;
        if ( !v41 || v41->m_pSimObject != v32->m_pSimObject )
        {
          UFG::qSafePointer<Creature,Creature>::operator=(
            (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)&this->m_pCurrentAttackTarget,
            v32);
          if ( this->m_pTargetingSystemBaseComponent.m_pSimComponent )
            LOBYTE(this->m_pTargetingSystemBaseComponent.m_pSimComponent[9].vfptr) = 1;
        }
      }
    }
    for ( i = list.mNode.mNext - 1; list.mNode.mNext - 1 != v34; i = list.mNode.mNext - 1 )
    {
      v43 = i + 1;
      v44 = i[1].mPrev;
      v45 = i[1].mNext;
      v44->mNext = v45;
      v45->mPrev = v44;
      v43->mPrev = v43;
      v43->mNext = v43;
    }
    v46 = list.mNode.mPrev;
    v47 = list.mNode.mNext;
    list.mNode.mPrev->mNext = list.mNode.mNext;
    v47->mPrev = v46;
    list.mNode.mPrev = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *)&list;
    list.mNode.mNext = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *)&list;
  }
}

// File Line: 1058
// RVA: 0x35F310
float __fastcall UFG::ActiveAIEntityComponent::GetEncounterFocusTargetScore(
        UFG::ActiveAIEntityComponent *this,
        UFG::SimObjectGame *pMyself)
{
  UFG::SimObjectGame *v2; // r8
  signed __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int64 v5; // rbx

  v2 = pMyself;
  if ( pMyself
    && ((m_Flags = pMyself->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0
       ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
        ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(pMyself, UFG::EncounterUnitComponent::_TypeUID))
        : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(pMyself, UFG::EncounterUnitComponent::_TypeUID)))
       : (ComponentOfTypeHK = pMyself->m_Components.p[16].m_pComponent))
      : (ComponentOfTypeHK = pMyself->m_Components.p[16].m_pComponent),
        ComponentOfTypeHK
     && (v5 = *(_QWORD *)&ComponentOfTypeHK[1].m_TypeUID) != 0
     && (*(unsigned __int8 (__fastcall **)(__int64, UFG::SimObjectGame *, UFG::SimObjectGame *))(*(_QWORD *)v5 + 48i64))(
          v5,
          pMyself,
          v2)
     && (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v5 + 144i64))(v5)) )
  {
    return gs_fEncounterFocusTargetBonus;
  }
  else
  {
    return 0.0;
  }
}

// File Line: 1078
// RVA: 0x35A340
float __fastcall UFG::ActiveAIEntityComponent::GetAttackabilityScoreMelee(
        UFG::ActiveAIEntityComponent *this,
        UFG::AttackRightsComponent *potential_attack_target)
{
  float v4; // xmm6_4
  UFG::SimComponent *m_pSimComponent; // rbp
  float v6; // xmm7_4
  int v7; // r14d
  int mPrev; // ebx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  UFG::SimComponent *v10; // rbp
  __m128 v11; // xmm1
  UFG::SimComponent *v12; // rbx
  __m128 mPrev_low; // xmm1
  float v14; // xmm0_4
  float v15; // xmm7_4
  UFG::SimComponent *v16; // rax
  UFG::SimObject *v17; // rcx
  int v18; // ecx
  float v19; // xmm6_4
  UFG::SimObjectCharacter *m_pSimObject; // rax
  UFG::SimObjectGame *v21; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  UFG::qString v25; // [rsp+28h] [rbp-60h] BYREF

  v4 = FLOAT_N1_0;
  if ( UFG::ActiveAIEntityComponent::IsEnemyOfMine(this, potential_attack_target)
    && UFG::ActiveAIEntityComponent::CanBeEngagedMelee(this, potential_attack_target) )
  {
    m_pSimComponent = this->m_pTransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pSimComponent);
    UFG::qString::qString(&v25);
    v6 = 0.0;
    v7 = 0;
    mPrev = 0;
    if ( this->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent )
      mPrev = (int)this->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent[3].m_SafePointerList.mNode.mPrev;
    if ( UFG::GameStatTracker::Instance()->mFactionInterface.mStandings[mPrev][2] )
    {
      v12 = potential_attack_target->m_pTransformNodeComponent.m_pSimComponent;
      if ( v12 && this->m_pTransformNodeComponent.m_pSimComponent )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)potential_attack_target->m_pTransformNodeComponent.m_pSimComponent);
        mPrev_low = (__m128)LODWORD(m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev);
        v14 = *((float *)&m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev + 1)
            - *((float *)&v12[2].m_BoundComponentHandles.mNode.mPrev + 1);
        mPrev_low.m128_f32[0] = (float)((float)(mPrev_low.m128_f32[0]
                                              - *(float *)&v12[2].m_BoundComponentHandles.mNode.mPrev)
                                      * (float)(mPrev_low.m128_f32[0]
                                              - *(float *)&v12[2].m_BoundComponentHandles.mNode.mPrev))
                              + (float)(v14 * v14);
        v15 = this->m_MaxEngagementDistanceXY - _mm_sqrt_ps(mPrev_low).m128_f32[0];
        if ( v15 <= 0.0 )
          v15 = 0.0;
        v6 = v15 * AttackabilityMelee::ms_fScoreDistanceScale;
      }
    }
    else
    {
      if ( LocalPlayer )
        m_pTransformNodeComponent = LocalPlayer->m_pTransformNodeComponent;
      else
        m_pTransformNodeComponent = 0i64;
      v10 = potential_attack_target->m_pTransformNodeComponent.m_pSimComponent;
      if ( m_pTransformNodeComponent && v10 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)potential_attack_target->m_pTransformNodeComponent.m_pSimComponent);
        UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
        v11 = (__m128)LODWORD(v10[2].m_BoundComponentHandles.mNode.mPrev);
        v11.m128_f32[0] = (float)((float)(v11.m128_f32[0] - m_pTransformNodeComponent->mWorldTransform.v3.x)
                                * (float)(v11.m128_f32[0] - m_pTransformNodeComponent->mWorldTransform.v3.x))
                        + (float)((float)(*((float *)&v10[2].m_BoundComponentHandles.mNode.mPrev + 1)
                                        - m_pTransformNodeComponent->mWorldTransform.v3.y)
                                * (float)(*((float *)&v10[2].m_BoundComponentHandles.mNode.mPrev + 1)
                                        - m_pTransformNodeComponent->mWorldTransform.v3.y));
        LODWORD(v6) = _mm_sqrt_ps(v11).m128_u32[0];
      }
    }
    if ( this->m_pHitReactionComponent.m_pSimComponent )
    {
      v16 = this->m_pHitReactionComponent.m_pSimComponent;
      v17 = *(UFG::SimObject **)&v16[3].m_TypeUID;
      if ( v17 )
      {
        if ( v17 == potential_attack_target->m_pSimObject
          && *(float *)&v16[3].m_Flags < AttackabilityMelee::ms_fMaxTimeSinceLastHitForBonus )
        {
          v6 = v6 + AttackabilityMelee::ms_fScoreLastAttackerBonus;
        }
      }
    }
    v18 = AttackabilityMelee::ms_iScoreMaxAttackers
        - UFG::AttackRightsComponent::CountNumDistinctAttackers(potential_attack_target, this->m_pSimObject);
    if ( v18 > 0 )
      v7 = v18;
    v19 = (float)v7 * AttackabilityMelee::ms_fScoreNumFreeSlotsScale;
    v4 = (float)(v19 + v6) + UFG::ActiveAIEntityComponent::GetEncounterFocusTargetScore(this, this->m_pSimObject);
    if ( UFG::ActiveAIEntityComponent::IsSupplementaryAttackTarget(this, potential_attack_target) )
      v4 = v4 + AttackabilityMelee::ms_fScoreScriptedBonus;
    m_pSimObject = (UFG::SimObjectCharacter *)potential_attack_target->m_pSimObject;
    if ( m_pSimObject && m_pSimObject == LocalPlayer )
      v4 = v4 + AttackabilityMelee::ms_fScorePlayerBonus;
    if ( this->m_pCharacterOccupantComponent.m_pSimComponent
      && potential_attack_target->m_pCharacterOccupantComponent.m_pSimComponent )
    {
      v4 = v4 + AttackabilityMelee::ms_fScoreVehicleContextBonus;
    }
    if ( potential_attack_target == this->m_pCurrentAttackTarget.m_pPointer )
      v4 = v4 + AttackabilityMelee::ms_fScoreHysteresis;
    v21 = (UFG::SimObjectGame *)this->m_pSimObject;
    if ( v21 )
    {
      m_Flags = v21->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = v21->m_Components.p[3].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
        {
          m_pComponent = v21->m_Components.p[4].m_pComponent;
        }
        else if ( (m_Flags & 0x1000) != 0 )
        {
          m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(v21, UFG::SimObjectPropertiesComponent::_TypeUID);
        }
        else
        {
          m_pComponent = UFG::SimObject::GetComponentOfType(v21, UFG::SimObjectPropertiesComponent::_TypeUID);
        }
      }
      else
      {
        m_pComponent = v21->m_Components.p[3].m_pComponent;
      }
      if ( m_pComponent
        && LODWORD(m_pComponent[1].m_SafePointerList.mNode.mNext) == 1
        && BYTE3(m_pComponent[2].m_BoundComponentHandles.mNode.mPrev) )
      {
        v4 = 0.0;
      }
    }
    UFG::qString::~qString(&v25);
  }
  return v4;
}

// File Line: 1290
// RVA: 0x35A660
float __fastcall UFG::ActiveAIEntityComponent::GetAttackabilityScoreRanged(
        UFG::ActiveAIEntityComponent *this,
        UFG::AttackRightsComponent *potential_attack_target)
{
  float v4; // xmm6_4
  UFG::SimComponent *m_pSimComponent; // rdi
  float v6; // xmm7_4
  UFG::SimComponent *v7; // rbx
  __m128 mPrev_low; // xmm1
  float v9; // xmm0_4
  UFG::SimComponent *v10; // rax
  UFG::SimObject *v11; // rcx
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  UFG::SimObject *v15; // rcx
  UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> **p_mNext; // rcx
  UFG::SimObject *v17; // r12
  float v18; // xmm7_4
  UFG::SimObjectGame *v19; // rcx
  int v20; // edi
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int16 v22; // dx
  int v23; // r14d
  UFG::TargetingSimObject *mPrev; // rbx
  UFG::TargetingSimObject *p_m_pSimObject; // r15
  UFG::SimObjectCVBase *Owner; // rax
  __int16 v27; // dx
  UFG::ActiveAIEntityComponent *v28; // rax
  int v29; // eax
  float v30; // xmm6_4
  UFG::SimObjectCharacter *v31; // rax
  unsigned int size; // edx
  UFG::PedKnowledgeRecord *v33; // rcx
  float v34; // xmm0_4
  UFG::SimObjectGame *v35; // rcx
  __int16 v36; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qString v39; // [rsp+28h] [rbp-70h] BYREF

  v4 = FLOAT_N1_0;
  if ( !UFG::ActiveAIEntityComponent::IsEnemyOfMine(this, potential_attack_target)
    || !potential_attack_target
    || !UFG::ActiveAIEntityComponent::CanBeEngagedShared(this, potential_attack_target) )
  {
    return v4;
  }
  m_pSimComponent = this->m_pTransformNodeComponent.m_pSimComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pSimComponent);
  UFG::qString::qString(&v39);
  v6 = 0.0;
  v7 = potential_attack_target->m_pTransformNodeComponent.m_pSimComponent;
  if ( v7 && this->m_pTransformNodeComponent.m_pSimComponent )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)potential_attack_target->m_pTransformNodeComponent.m_pSimComponent);
    mPrev_low = (__m128)LODWORD(m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev);
    v9 = *((float *)&m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev + 1)
       - *((float *)&v7[2].m_BoundComponentHandles.mNode.mPrev + 1);
    mPrev_low.m128_f32[0] = (float)((float)(mPrev_low.m128_f32[0] - *(float *)&v7[2].m_BoundComponentHandles.mNode.mPrev)
                                  * (float)(mPrev_low.m128_f32[0] - *(float *)&v7[2].m_BoundComponentHandles.mNode.mPrev))
                          + (float)(v9 * v9);
    v6 = AttackabilityRanged::ms_fDistanceDividend / _mm_sqrt_ps(mPrev_low).m128_f32[0];
  }
  if ( this->m_pHitReactionComponent.m_pSimComponent )
  {
    v10 = this->m_pHitReactionComponent.m_pSimComponent;
    v11 = *(UFG::SimObject **)&v10[3].m_TypeUID;
    if ( v11 )
    {
      if ( v11 == potential_attack_target->m_pSimObject
        && *(float *)&v10[3].m_Flags < AttackabilityRanged::ms_fMaxTimeSinceLastHitForBonus )
      {
        v6 = v6 + AttackabilityRanged::ms_fScoreLastAttackerBonus;
      }
    }
  }
  m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pSimObject->m_Components.p[11].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      m_pComponent = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                   ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::StimulusReceiverComponent::_TypeUID)
                   : UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::StimulusReceiverComponent::_TypeUID);
    }
    else
    {
      m_pComponent = m_pSimObject->m_Components.p[11].m_pComponent;
    }
    if ( m_pComponent )
    {
      v15 = m_pComponent[3].m_pSimObject;
      if ( v15 )
      {
        p_mNext = &v15->m_SafePointerWithCallbackList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::mNode.mNext;
        if ( p_mNext )
        {
          if ( p_mNext[3] == (UFG::qNode<UFG::qSafePointerWithCallbacksBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)potential_attack_target->m_pSimObject
            && (float)(UFG::Metrics::msInstance.mSimTime_Temp - *(float *)p_mNext) < AttackabilityRanged::ms_fMaxTimeSinceLastShotAtForBonus )
          {
            v6 = v6 + AttackabilityRanged::ms_fScoreLastShotAtBonus;
          }
        }
      }
    }
  }
  v17 = this->m_pSimObject;
  v18 = v6 + UFG::ActiveAIEntityComponent::GetEncounterFocusTargetScore(this, v17);
  v19 = (UFG::SimObjectGame *)potential_attack_target->m_pSimObject;
  v20 = 0;
  if ( v19 )
  {
    v22 = v19->m_Flags;
    if ( (v22 & 0x4000) != 0 )
    {
      ComponentOfTypeHK = v19->m_Components.p[20].m_pComponent;
    }
    else if ( v22 >= 0 )
    {
      if ( (v22 & 0x2000) != 0 || (v22 & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v19, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v19, UFG::TargetingSystemBaseComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = v19->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    ComponentOfTypeHK = 0i64;
  }
  v23 = 0;
  if ( ComponentOfTypeHK )
  {
    mPrev = (UFG::TargetingSimObject *)ComponentOfTypeHK[1].m_BoundComponentHandles.mNode.mPrev;
    p_m_pSimObject = (UFG::TargetingSimObject *)&ComponentOfTypeHK[1].m_pSimObject;
    if ( mPrev != (UFG::TargetingSimObject *)&ComponentOfTypeHK[1].m_pSimObject )
    {
      do
      {
        if ( mPrev->m_eTargetType.mValue == 22 )
        {
          Owner = (UFG::SimObjectCVBase *)UFG::TargetingSimObject::GetOwner(mPrev);
          if ( Owner )
          {
            if ( Owner != v17 )
            {
              v27 = Owner->m_Flags;
              if ( (v27 & 0x4000) != 0 || v27 < 0 )
                v28 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(Owner);
              else
                v28 = (UFG::ActiveAIEntityComponent *)((v27 & 0x2000) != 0 || (v27 & 0x1000) != 0
                                                     ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         Owner,
                                                         UFG::ActiveAIEntityComponent::_TypeUID)
                                                     : UFG::SimObject::GetComponentOfType(
                                                         Owner,
                                                         UFG::ActiveAIEntityComponent::_TypeUID));
              if ( v28 && UFG::g_AIObjectiveParams[v28->m_CurrentObjective].m_IsHostile )
                ++v23;
            }
          }
        }
        mPrev = (UFG::TargetingSimObject *)mPrev->mNext;
      }
      while ( mPrev != p_m_pSimObject );
    }
  }
  v29 = 0;
  if ( AttackabilityRanged::ms_iScoreMaxAttackers - v23 > 0 )
    v29 = AttackabilityRanged::ms_iScoreMaxAttackers - v23;
  v30 = (float)v29 * AttackabilityRanged::ms_fScoreNumFreeSlotsScale;
  v4 = (float)(v30 + v18) + UFG::ActiveAIEntityComponent::GetEncounterFocusTargetScore(this, v17);
  if ( UFG::ActiveAIEntityComponent::IsSupplementaryAttackTarget(this, potential_attack_target) )
    v4 = v4 + AttackabilityRanged::ms_fScoreScriptedBonus;
  v31 = (UFG::SimObjectCharacter *)potential_attack_target->m_pSimObject;
  if ( v31 && v31 == LocalPlayer )
    v4 = v4 + AttackabilityRanged::ms_fScorePlayerBonus;
  if ( this->m_pCharacterOccupantComponent.m_pSimComponent
    && potential_attack_target->m_pCharacterOccupantComponent.m_pSimComponent )
  {
    v4 = v4 + AttackabilityRanged::ms_fScoreVehicleContextBonus;
  }
  size = this->m_KnowledgeBase.m_aHostilePedRecords.size;
  if ( size )
  {
    do
    {
      v33 = &this->m_KnowledgeBase.m_aHostilePedRecords.p[v20];
      if ( v31 == v33->pSimObject.m_pPointer )
        goto LABEL_67;
    }
    while ( ++v20 < size );
  }
  v33 = &UFG::PedKnowledgeBase::ms_defaultKnowledgeRecord;
  if ( v31 == UFG::PedKnowledgeBase::ms_defaultKnowledgeRecord.pSimObject.m_pPointer )
  {
LABEL_67:
    if ( (*((_BYTE *)v33 + 48) & 1) != 0 )
      goto LABEL_71;
    v34 = (float)(LODWORD(UFG::Metrics::msInstance.mSimTimeMSec) - LODWORD(v33->m_uLastTimeSeen));
    if ( (__int64)(UFG::Metrics::msInstance.mSimTimeMSec - v33->m_uLastTimeSeen) < 0 )
      v34 = v34 + 1.8446744e19;
    if ( (float)(v34 * 0.001) < AttackabilityRanged::ms_fMaxTimeSinceLastSeenForBonus )
LABEL_71:
      v4 = v4 + AttackabilityRanged::ms_fScoreVisible;
  }
  if ( potential_attack_target == this->m_pCurrentAttackTarget.m_pPointer )
    v4 = v4 + AttackabilityRanged::ms_fScoreHysteresis;
  v35 = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( v35 )
  {
    v36 = v35->m_Flags;
    if ( (v36 & 0x4000) != 0 )
    {
      ComponentOfType = v35->m_Components.p[3].m_pComponent;
    }
    else if ( v36 >= 0 )
    {
      if ( (v36 & 0x2000) != 0 )
      {
        ComponentOfType = v35->m_Components.p[4].m_pComponent;
      }
      else if ( (v36 & 0x1000) != 0 )
      {
        ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v35, UFG::SimObjectPropertiesComponent::_TypeUID);
      }
      else
      {
        ComponentOfType = UFG::SimObject::GetComponentOfType(v35, UFG::SimObjectPropertiesComponent::_TypeUID);
      }
    }
    else
    {
      ComponentOfType = v35->m_Components.p[3].m_pComponent;
    }
    if ( ComponentOfType
      && LODWORD(ComponentOfType[1].m_SafePointerList.mNode.mNext) == 1
      && BYTE3(ComponentOfType[2].m_BoundComponentHandles.mNode.mPrev) )
    {
      v4 = 0.0;
    }
  }
  UFG::qString::~qString(&v39);
  return v4;
}

// File Line: 1595
// RVA: 0x36BBB0
char __fastcall UFG::ActiveAIEntityComponent::IsSupplementaryAttackTarget(
        UFG::ActiveAIEntityComponent *this,
        UFG::AttackRightsComponent *potential_attack_target)
{
  UFG::ActiveAIEntityComponent *mNext; // r9
  UFG::qList<UFG::SupplementaryAttackTarget,UFG::SupplementaryAttackTarget,1,0> *p_m_SupplementaryAttackTargets; // rdi
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rbx
  UFG::AttackRightsComponent *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **p_mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rdx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rax

  mNext = (UFG::ActiveAIEntityComponent *)this->m_SupplementaryAttackTargets.mNode.mNext;
  p_m_SupplementaryAttackTargets = &this->m_SupplementaryAttackTargets;
  if ( mNext != (UFG::ActiveAIEntityComponent *)&this->m_SupplementaryAttackTargets )
  {
    do
    {
      mPrev = mNext->m_SafePointerList.mNode.UFG::AIEntityComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
      v6 = *(UFG::AttackRightsComponent **)&mNext->m_Flags;
      if ( v6 )
      {
        if ( potential_attack_target == v6 )
          return 1;
      }
      else
      {
        p_mNext = &mNext->m_SafePointerList.mNode.mNext;
        if ( *(_QWORD *)&mNext->m_Flags )
        {
          v8 = *p_mNext;
          v9 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **)&mNext->m_TypeUID;
          v8->mNext = v9;
          v9->mPrev = v8;
          *p_mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)p_mNext;
          *(_QWORD *)&mNext->m_TypeUID = &mNext->m_SafePointerList.mNode.mNext;
        }
        *(_QWORD *)&mNext->m_Flags = 0i64;
        v10 = *p_mNext;
        v11 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **)&mNext->m_TypeUID;
        v10->mNext = v11;
        v11->mPrev = v10;
        *p_mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)p_mNext;
        *(_QWORD *)&mNext->m_TypeUID = &mNext->m_SafePointerList.mNode.mNext;
        vfptr = mNext->vfptr;
        v13 = mNext->m_SafePointerList.mNode.UFG::AIEntityComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
        vfptr[1].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))v13;
        v13->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)vfptr;
        mNext->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)mNext;
        mNext->m_SafePointerList.mNode.UFG::AIEntityComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)mNext;
        operator delete[](mNext);
      }
      mNext = (UFG::ActiveAIEntityComponent *)mPrev;
    }
    while ( mPrev != (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)p_m_SupplementaryAttackTargets );
  }
  return 0;
}

// File Line: 1627
// RVA: 0x340E10
void __fastcall UFG::ActiveAIEntityComponent::AddSupplementaryAttackTarget(
        UFG::ActiveAIEntityComponent *this,
        UFG::SimObjectGame *attack_target)
{
  signed __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *v6; // rax
  bool v7; // cl
  UFG::qNode<UFG::SupplementaryAttackTarget,UFG::SupplementaryAttackTarget> *mNext; // rax
  UFG::qList<UFG::SupplementaryAttackTarget,UFG::SupplementaryAttackTarget,1,0> *p_m_SupplementaryAttackTargets; // rdi
  UFG::allocator::free_link *v10; // rax
  UFG::allocator::free_link *v11; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::allocator::free_link *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::qNode<UFG::SupplementaryAttackTarget,UFG::SupplementaryAttackTarget> *v16; // rax

  if ( attack_target )
  {
    m_Flags = attack_target->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = attack_target->m_Components.p[46].m_pComponent;
    }
    else
    {
      v6 = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(attack_target, UFG::AttackRightsComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(attack_target, UFG::AttackRightsComponent::_TypeUID);
      m_pComponent = v6;
    }
    if ( m_pComponent )
    {
      v7 = 0;
      mNext = this->m_SupplementaryAttackTargets.mNode.mNext;
      p_m_SupplementaryAttackTargets = &this->m_SupplementaryAttackTargets;
      if ( mNext == (UFG::qNode<UFG::SupplementaryAttackTarget,UFG::SupplementaryAttackTarget> *)p_m_SupplementaryAttackTargets )
      {
LABEL_16:
        v10 = UFG::qMalloc(0x28ui64, "SupplementaryAttackTarget", 0i64);
        v11 = v10;
        if ( v10 )
        {
          v10->mNext = v10;
          v10[1].mNext = v10;
          v10[2].mNext = v10 + 2;
          v10[3].mNext = v10 + 2;
          v10[4].mNext = 0i64;
        }
        else
        {
          v11 = 0i64;
        }
        v12 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v11[2];
        if ( v11[4].mNext )
        {
          mPrev = v12->mPrev;
          v14 = v11[3].mNext;
          mPrev->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v14;
          v14->mNext = (UFG::allocator::free_link *)mPrev;
          v12->mPrev = v12;
          v11[3].mNext = v11 + 2;
        }
        v11[4].mNext = (UFG::allocator::free_link *)m_pComponent;
        v15 = m_pComponent->m_SafePointerList.mNode.mPrev;
        v15->mNext = v12;
        v12->mPrev = v15;
        v11[3].mNext = (UFG::allocator::free_link *)&m_pComponent->m_SafePointerList;
        m_pComponent->m_SafePointerList.mNode.mPrev = v12;
        v16 = p_m_SupplementaryAttackTargets->mNode.mPrev;
        v16->mNext = (UFG::qNode<UFG::SupplementaryAttackTarget,UFG::SupplementaryAttackTarget> *)v11;
        v11->mNext = (UFG::allocator::free_link *)v16;
        v11[1].mNext = (UFG::allocator::free_link *)p_m_SupplementaryAttackTargets;
        p_m_SupplementaryAttackTargets->mNode.mPrev = (UFG::qNode<UFG::SupplementaryAttackTarget,UFG::SupplementaryAttackTarget> *)v11;
      }
      else
      {
        while ( !v7 )
        {
          v7 = m_pComponent == (UFG::SimComponent *)mNext[2].mPrev;
          mNext = mNext->mNext;
          if ( mNext == (UFG::qNode<UFG::SupplementaryAttackTarget,UFG::SupplementaryAttackTarget> *)p_m_SupplementaryAttackTargets )
          {
            if ( v7 )
              return;
            goto LABEL_16;
          }
        }
      }
    }
  }
}

// File Line: 1662
// RVA: 0x3814A0
void __fastcall UFG::ActiveAIEntityComponent::RemoveSupplementaryAttackTarget(
        UFG::ActiveAIEntityComponent *this,
        UFG::SimObjectGame *attack_target)
{
  signed __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rsi
  UFG::SimComponent *v6; // rax
  UFG::CollisionMeshData::DeferredBreakablePartsMark *mNext; // rbx
  UFG::qList<UFG::SupplementaryAttackTarget,UFG::SupplementaryAttackTarget,1,0> *p_m_SupplementaryAttackTargets; // rbp
  UFG::SimComponent *m_pPointer; // rax
  UFG::CollisionMeshData::DeferredBreakablePartsMark *v10; // rdi

  if ( attack_target )
  {
    m_Flags = attack_target->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = attack_target->m_Components.p[46].m_pComponent;
    }
    else
    {
      v6 = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(attack_target, UFG::AttackRightsComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(attack_target, UFG::AttackRightsComponent::_TypeUID);
      m_pComponent = v6;
    }
    if ( m_pComponent )
    {
      mNext = (UFG::CollisionMeshData::DeferredBreakablePartsMark *)this->m_SupplementaryAttackTargets.mNode.mNext;
      p_m_SupplementaryAttackTargets = &this->m_SupplementaryAttackTargets;
      if ( mNext != (UFG::CollisionMeshData::DeferredBreakablePartsMark *)p_m_SupplementaryAttackTargets )
      {
        do
        {
          m_pPointer = mNext->rigidBody.m_pPointer;
          v10 = (UFG::CollisionMeshData::DeferredBreakablePartsMark *)mNext->mNext;
          if ( m_pPointer )
          {
            if ( m_pComponent == m_pPointer )
            {
              UFG::SupplementaryAttackTarget::~SupplementaryAttackTarget(mNext);
              operator delete[](mNext);
              return;
            }
          }
          else
          {
            UFG::SupplementaryAttackTarget::~SupplementaryAttackTarget(mNext);
            operator delete[](mNext);
          }
          mNext = v10;
        }
        while ( v10 != (UFG::CollisionMeshData::DeferredBreakablePartsMark *)p_m_SupplementaryAttackTargets );
      }
    }
  }
}

// File Line: 1705
// RVA: 0x36A740
bool __fastcall UFG::ActiveAIEntityComponent::IsEnemyOfMine(
        UFG::ActiveAIEntityComponent *this,
        UFG::SimObjectGame *pSimObject)
{
  signed __int16 m_Flags; // dx
  UFG::AttackRightsComponent *ComponentOfType; // rax
  bool result; // al

  result = pSimObject
        && ((m_Flags = pSimObject->m_Flags, (m_Flags & 0x4000) == 0)
          ? (m_Flags >= 0 && (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0
           ? (ComponentOfType = (UFG::AttackRightsComponent *)UFG::SimObject::GetComponentOfType(
                                                                pSimObject,
                                                                UFG::AttackRightsComponent::_TypeUID))
           : (ComponentOfType = (UFG::AttackRightsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                pSimObject,
                                                                UFG::AttackRightsComponent::_TypeUID)))
          : (ComponentOfType = (UFG::AttackRightsComponent *)pSimObject->m_Components.p[46].m_pComponent),
            ComponentOfType)
        && UFG::ActiveAIEntityComponent::IsEnemyOfMine(this, ComponentOfType);
  return result;
}

// File Line: 1717
// RVA: 0x36A690
bool __fastcall UFG::ActiveAIEntityComponent::IsEnemyOfMine(
        UFG::ActiveAIEntityComponent *this,
        UFG::AttackRightsComponent *potential_attack_target)
{
  UFG::SimObjectCharacterPropertiesComponent *m_Properties; // rcx
  UFG::ActiveAIEntityComponent *m_pSimComponent; // rax
  UFG::SimObjectCharacterPropertiesComponent *m_PotentialAttackProperties; // rdx
  __int64 m_eFactionClass; // rbx
  __int64 v8; // rdi

  if ( !potential_attack_target )
    return 0;
  m_Properties = (UFG::SimObjectCharacterPropertiesComponent *)this->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent;
  m_pSimComponent = (UFG::ActiveAIEntityComponent *)potential_attack_target->m_pAIEntityComponent.m_pSimComponent;
  if ( !m_Properties )
    return 0;
  if ( !m_pSimComponent )
    return 0;
  m_PotentialAttackProperties = (UFG::SimObjectCharacterPropertiesComponent *)m_pSimComponent->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent;
  if ( !m_PotentialAttackProperties )
    return 0;
  m_eFactionClass = m_Properties->m_eFactionClass;
  v8 = m_PotentialAttackProperties->m_eFactionClass;
  return UFG::GameStatTracker::Instance()->mFactionInterface.mStandings[m_eFactionClass][v8] == FACTIONSTANDING_HOSTILE
      || UFG::ActiveAIEntityComponent::IsSupplementaryAttackTarget(this, potential_attack_target);
}

// File Line: 1737
// RVA: 0x34BEE0
char __fastcall UFG::ActiveAIEntityComponent::CanBeEngagedShared(
        UFG::ActiveAIEntityComponent *this,
        UFG::AttackRightsComponent *potential_attack_target)
{
  UFG::SimComponent *m_pSimComponent; // rax
  UFG::TransformNodeComponent *v3; // rsi
  UFG::SimComponent *v5; // rcx
  UFG::SimObjectCharacter *m_pSimObject; // rdx
  float m_TimeAllowedToKeepAttackingDeadTarget; // xmm0_4
  UFG::eTargetTypeEnum m_TargetToStayNear; // eax
  __int64 v11; // rbx
  __int64 v12; // rbx
  float m_MaxDistanceFromTargetToStayNear; // xmm6_4
  __m128 v14; // xmm1
  float v15; // xmm0_4
  UFG::SimComponent *v16; // rbx
  float v17; // xmm2_4
  __m128 mPrev_high; // xmm1

  m_pSimComponent = potential_attack_target->m_pHealthComponent.m_pSimComponent;
  v3 = (UFG::TransformNodeComponent *)potential_attack_target->m_pTransformNodeComponent.m_pSimComponent;
  v5 = potential_attack_target->m_pAIScriptInterfaceComponent.m_pSimComponent;
  if ( m_pSimComponent && BYTE4(m_pSimComponent[1].m_BoundComponentHandles.mNode.mPrev) )
  {
    m_pSimObject = (UFG::SimObjectCharacter *)potential_attack_target->m_pSimObject;
    m_TimeAllowedToKeepAttackingDeadTarget = this->m_TimeAllowedToKeepAttackingDeadTarget;
    if ( m_pSimObject && m_pSimObject == LocalPlayer )
      m_TimeAllowedToKeepAttackingDeadTarget = m_TimeAllowedToKeepAttackingDeadTarget
                                             + AttackabilityShared::ms_fExtraTimeToKeepAttackingDeadPlayer;
    if ( (float)(UFG::Metrics::msInstance.mSimTime_Temp - *(float *)&m_pSimComponent[3].m_pSimObject) >= m_TimeAllowedToKeepAttackingDeadTarget )
      return 0;
  }
  if ( v5 && ((__int64)v5[32].m_BoundComponentHandles.mNode.mPrev & 0x20) != 0 )
    return 0;
  m_TargetToStayNear = this->m_TargetToStayNear;
  if ( m_TargetToStayNear && this->m_pTargetingSystemBaseComponent.m_pSimComponent )
  {
    if ( !v3 )
      return 1;
    v11 = *(_QWORD *)(56i64
                    * *(unsigned __int8 *)(*(_QWORD *)&this->m_pTargetingSystemBaseComponent.m_pSimComponent[1].m_Flags
                                         + (unsigned int)m_TargetToStayNear
                                         + 8i64)
                    + *(_QWORD *)&this->m_pTargetingSystemBaseComponent.m_pSimComponent[1].m_TypeUID
                    + 40);
    if ( v11 )
    {
      v12 = *(_QWORD *)(v11 + 88);
      if ( v12 )
      {
        m_MaxDistanceFromTargetToStayNear = this->m_MaxDistanceFromTargetToStayNear;
        if ( potential_attack_target == this->m_pCurrentAttackTarget.m_pPointer )
          m_MaxDistanceFromTargetToStayNear = m_MaxDistanceFromTargetToStayNear
                                            + this->m_MaxDistanceFromTargetToStayNearHysteresis;
        UFG::TransformNodeComponent::UpdateWorldTransform(v3);
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v12);
        v14 = (__m128)*(unsigned int *)(v12 + 180);
        v15 = *(float *)(v12 + 176) - v3->mWorldTransform.v3.x;
        v14.m128_f32[0] = (float)((float)(v14.m128_f32[0] - v3->mWorldTransform.v3.y)
                                * (float)(v14.m128_f32[0] - v3->mWorldTransform.v3.y))
                        + (float)(v15 * v15);
        if ( _mm_sqrt_ps(v14).m128_f32[0] > m_MaxDistanceFromTargetToStayNear )
          return 0;
      }
    }
  }
  if ( v3 )
  {
    if ( this->m_pTransformNodeComponent.m_pSimComponent )
    {
      v16 = this->m_pTransformNodeComponent.m_pSimComponent;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v16);
      UFG::TransformNodeComponent::UpdateWorldTransform(v3);
      mPrev_high = (__m128)HIDWORD(v16[2].m_BoundComponentHandles.mNode.mPrev);
      mPrev_high.m128_f32[0] = mPrev_high.m128_f32[0] - v3->mWorldTransform.v3.y;
      if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)&v16[2].m_BoundComponentHandles.mNode.mNext - v3->mWorldTransform.v3.z) & _xmm) >= this->m_MaxEngagementDistanceZ )
        return 0;
      v17 = *(float *)&v16[2].m_BoundComponentHandles.mNode.mPrev - v3->mWorldTransform.v3.x;
      mPrev_high.m128_f32[0] = (float)(mPrev_high.m128_f32[0] * mPrev_high.m128_f32[0]) + (float)(v17 * v17);
      if ( _mm_sqrt_ps(mPrev_high).m128_f32[0] >= this->m_MaxEngagementDistanceXY
        && !this->m_EngagementOverrideEnabled
        && this->m_CurrentObjective != eAI_OBJECTIVE_ATTACK_TARGET )
      {
        return 0;
      }
    }
  }
  return 1;
}

// File Line: 1822
// RVA: 0x34BCA0
char __fastcall UFG::ActiveAIEntityComponent::CanBeEngagedMelee(
        UFG::ActiveAIEntityComponent *this,
        UFG::AttackRightsComponent *potential_attack_target)
{
  UFG::SimComponent *m_pSimComponent; // rax
  __int64 mPrev_low; // rbx
  UFG::SimObjectCharacter *v7; // rdi
  signed __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *v10; // rax
  UFG::SimObjectGame *v11; // rbx
  __int16 v12; // cx
  UFG::SimComponent *v13; // rsi
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int16 v15; // cx
  UFG::SimComponent *v16; // rdx
  UFG::SimComponent *ComponentOfType; // rax

  if ( !potential_attack_target || !UFG::ActiveAIEntityComponent::CanBeEngagedShared(this, potential_attack_target) )
    return 0;
  m_pSimComponent = this->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent;
  if ( !m_pSimComponent )
    return 1;
  mPrev_low = SLODWORD(m_pSimComponent[3].m_SafePointerList.mNode.mPrev);
  if ( UFG::GameStatTracker::Instance()->mFactionInterface.mStandings[mPrev_low][2] )
    return 1;
  v7 = LocalPlayer;
  if ( !LocalPlayer )
    return 1;
  m_Flags = LocalPlayer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = LocalPlayer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v10 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
        ? UFG::SimObjectGame::GetComponentOfTypeHK(LocalPlayer, UFG::TargetingSystemBaseComponent::_TypeUID)
        : UFG::SimObject::GetComponentOfType(LocalPlayer, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = v10;
  }
  else
  {
    m_pComponent = LocalPlayer->m_Components.p[20].m_pComponent;
  }
  if ( m_pComponent
    && (v11 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + 30i64)
                                     + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                     + 40)) != 0i64
    && v11 == potential_attack_target->m_pSimObject
    && ((v12 = v11->m_Flags, (v12 & 0x4000) == 0)
      ? (v12 >= 0
       ? ((v12 & 0x2000) != 0 || (v12 & 0x1000) != 0
        ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                 v11,
                                 UFG::TargetingSystemBaseComponent::_TypeUID))
        : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v11, UFG::TargetingSystemBaseComponent::_TypeUID)),
          v13 = ComponentOfTypeHK)
       : (v13 = v11->m_Components.p[20].m_pComponent))
      : (v13 = v11->m_Components.p[20].m_pComponent),
        (v15 = v11->m_Flags, (v15 & 0x4000) == 0)
      ? (v15 >= 0
       ? ((v15 & 0x2000) != 0 || (v15 & 0x1000) != 0
        ? (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::HitReactionComponent::_TypeUID))
        : (ComponentOfType = UFG::SimObject::GetComponentOfType(v11, UFG::HitReactionComponent::_TypeUID)),
          v16 = ComponentOfType)
       : (v16 = v11->m_Components.p[15].m_pComponent))
      : (v16 = v11->m_Components.p[15].m_pComponent),
        v13
     && v16
     && *(UFG::SimObjectCharacter **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v13[1].m_Flags + 10i64)
                                    + *(_QWORD *)&v13[1].m_TypeUID
                                    + 40) == v7
     && *(float *)&v16[1].m_TypeUID < 5.0) )
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

// File Line: 1906
// RVA: 0x383DB0
void __fastcall UFG::ActiveAIEntityComponent::RestartPoiCooldown(UFG::ActiveAIEntityComponent *this)
{
  UFG::SimObject *m_pSimObject; // rax
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v5; // rax
  char *MemImagePtr; // rax
  UFG::SimObjectCharacterPropertiesComponent *m_pSimComponent; // rbx

  if ( !this->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent )
    return;
  m_pSimObject = this->m_pSimObject;
  if ( !m_pSimObject || (m_pSceneObj = m_pSimObject->m_pSceneObj) == 0i64 )
  {
    mpWritableProperties = 0i64;
LABEL_7:
    if ( !mpWritableProperties )
      return;
    goto LABEL_8;
  }
  mpWritableProperties = m_pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
  {
    mpWritableProperties = m_pSceneObj->mpConstProperties;
    goto LABEL_7;
  }
LABEL_8:
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&component_CharacterProperties::sPropertyName,
         DEPTH_RECURSE);
  if ( v5 )
  {
    MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v5);
    if ( MemImagePtr )
    {
      m_pSimComponent = (UFG::SimObjectCharacterPropertiesComponent *)this->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent;
      m_pSimComponent->m_CharacterStats[2].m_fStat = UFG::GetRandomNumberInRange(
                                                       *((float *)MemImagePtr + 6),
                                                       *((float *)MemImagePtr + 7));
    }
  }
}

// File Line: 2050
// RVA: 0x387A00
void __fastcall UFG::ActiveAIEntityComponent::SetParkourSuccessRate(UFG::ActiveAIEntityComponent *this, float val)
{
  this->m_ChanceOfCleanVault = val;
  this->m_CleanNextVault = UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed) < this->m_ChanceOfCleanVault;
}

