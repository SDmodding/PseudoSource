// File Line: 56
// RVA: 0x14B2F80
__int64 UFG::_dynamic_initializer_for__gEntityDeathChannel__()
{
  UFG::ChannelObj::ChannelObj(&UFG::gEntityDeathChannel, "EVT_ENTITY_DEATH", 0i64);
  return atexit(UFG::_dynamic_atexit_destructor_for__gEntityDeathChannel__);
}

// File Line: 68
// RVA: 0x3632E0
const char *__fastcall UFG::AIEntityComponent::GetTypeName(UFG::AIEntityComponent *this)
{
  return "AIEntityComponent";
}

// File Line: 77
// RVA: 0x32B470
void __fastcall UFG::AIEntityComponent::AIEntityComponent(UFG::AIEntityComponent *this, unsigned int name_uid, UFG::qPropertySet *properties, bool startSuspended)
{
  UFG::AIEntityComponent *v4; // r14
  signed __int64 v5; // rsi
  signed __int64 v6; // ST40_8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v7; // ST38_8
  UFG::qSafePointer<UFG::GroupComponent,UFG::GroupComponent> *v8; // ST40_8
  UFG::qSafePointer<UFG::CombatRegion,UFG::CombatRegion> *v9; // ST40_8
  float v10; // xmm1_4
  float v11; // xmm2_4

  v4 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v4->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AIEntityComponent::`vftable;
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&v4->m_pTransformNodeComponent);
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0>::RebindingComponentHandle<UFG::ActionTreeComponent,0>(&v4->m_pActionTreeComponent);
  UFG::RebindingComponentHandle<UFG::RigidBodyComponent,0>::RebindingComponentHandle<UFG::RigidBodyComponent,0>(&v4->m_pRigidBodyComponent);
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>(&v4->m_pCharacterAnimationComponent);
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0>::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0>(&v4->m_pSimObjectCharacterPropertiesComponent);
  UFG::RebindingComponentHandle<UFG::AttackRightsComponent,0>::RebindingComponentHandle<UFG::AttackRightsComponent,0>(&v4->m_pAttackRightsComponent);
  UFG::RebindingComponentHandle<UFG::SceneObjectProperties,0>::RebindingComponentHandle<UFG::SceneObjectProperties,0>(&v4->m_pSceneObjectProperties);
  UFG::RebindingComponentHandle<UFG::HealthComponent,0>::RebindingComponentHandle<UFG::HealthComponent,0>(&v4->m_pHealthComponent);
  UFG::RebindingComponentHandle<UFG::TargetingSystemPedBaseComponent,0>::RebindingComponentHandle<UFG::TargetingSystemPedBaseComponent,0>(&v4->m_pTargetingSystemBaseComponent);
  UFG::RebindingComponentHandle<UFG::CharacterOccupantComponent,0>::RebindingComponentHandle<UFG::CharacterOccupantComponent,0>(&v4->m_pCharacterOccupantComponent);
  v5 = (signed __int64)&v4->m_WanderData;
  `eh vector constructor iterator(
    &v4->m_WanderData,
    0x78ui64,
    2,
    (void (__fastcall *)(void *))UFG::SidewalkWanderData::GoalInfo::GoalInfo);
  v6 = (signed __int64)&v4->m_WanderData.mCrosswalkLanes;
  *(_QWORD *)(v6 + 32) = 0i64;
  *(_QWORD *)(v6 + 24) = 0i64;
  *(_QWORD *)(v5 + 312) = 0i64;
  *(_QWORD *)(v5 + 304) = 0i64;
  v7 = &v4->m_HeadTrackingTarget.m_pTransformNodeComponent;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v7->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v4->m_HeadTrackingTarget.m_pTransformNodeComponent.m_pPointer = 0i64;
  *(_WORD *)&v4->m_AIPositionValid = 256;
  v8 = &v4->m_pGroupComponent;
  v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  v8->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  v4->m_pGroupComponent.m_pPointer = 0i64;
  v9 = &v4->m_pCombatRegion;
  v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  v9->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  v4->m_pCombatRegion.m_pPointer = 0i64;
  `eh vector constructor iterator(
    v4->m_ThreatTargets.p,
    0x20ui64,
    10,
    (void (__fastcall *)(void *))UFG::GameSliceStreamer::DeferScriptDeletionRequest::DeferScriptDeletionRequest);
  v4->m_ThreatTargets.size = 0;
  *(_WORD *)&v4->m_bCanWander = 0;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v4->vfptr,
    UFG::AIEntityComponent::_AIEntityComponentTypeUID,
    "AIEntityComponent");
  v4->m_pNearbyCharacter = 0i64;
  v4->m_bActive = 0;
  v10 = UFG::qVector3::msZero.y;
  v11 = UFG::qVector3::msZero.z;
  v4->m_vCombatRegionMoveToVec.x = UFG::qVector3::msZero.x;
  v4->m_vCombatRegionMoveToVec.y = v10;
  v4->m_vCombatRegionMoveToVec.z = v11;
  UFG::SidewalkWanderData::ClearData(&v4->m_WanderData);
  v4->m_HeadTrackingTarget.m_Type = -1;
}

// File Line: 90
// RVA: 0x3342C0
void __fastcall UFG::AIEntityComponent::~AIEntityComponent(UFG::AIEntityComponent *this)
{
  UFG::AIEntityComponent *v1; // rdi
  UFG::qSafePointer<UFG::CombatRegion,UFG::CombatRegion> *v2; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qSafePointer<UFG::GroupComponent,UFG::GroupComponent> *v9; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v14; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AIEntityComponent::`vftable;
  v2 = &this->m_pCombatRegion;
  if ( this->m_pCombatRegion.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
  v1->m_ThreatTargets.size = 0;
  `eh vector destructor iterator(
    v1->m_ThreatTargets.p,
    0x20ui64,
    10,
    (void (__fastcall *)(void *))UFG::InterestPointUseDetails::~InterestPointUseDetails);
  if ( v2->m_pPointer )
  {
    v5 = v2->mPrev;
    v6 = v2->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
  v7 = v2->mPrev;
  v8 = v2->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v9 = &v1->m_pGroupComponent;
  if ( v1->m_pGroupComponent.m_pPointer )
  {
    v10 = v9->mPrev;
    v11 = v1->m_pGroupComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
    v1->m_pGroupComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)&v1->m_pGroupComponent.mPrev;
  }
  v1->m_pGroupComponent.m_pPointer = 0i64;
  v12 = v9->mPrev;
  v13 = v1->m_pGroupComponent.mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  v1->m_pGroupComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::GroupComponent>,UFG::qSafePointerNodeList> *)&v1->m_pGroupComponent.mPrev;
  v14 = &v1->m_HeadTrackingTarget.m_pTransformNodeComponent;
  if ( v1->m_HeadTrackingTarget.m_pTransformNodeComponent.m_pPointer )
  {
    v15 = v14->mPrev;
    v16 = v1->m_HeadTrackingTarget.m_pTransformNodeComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    v14->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v14->mPrev;
    v1->m_HeadTrackingTarget.m_pTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_HeadTrackingTarget.m_pTransformNodeComponent.mPrev;
  }
  v1->m_HeadTrackingTarget.m_pTransformNodeComponent.m_pPointer = 0i64;
  v17 = v14->mPrev;
  v18 = v1->m_HeadTrackingTarget.m_pTransformNodeComponent.mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  v14->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v14->mPrev;
  v1->m_HeadTrackingTarget.m_pTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_HeadTrackingTarget.m_pTransformNodeComponent.mPrev;
  UFG::SidewalkWanderData::~SidewalkWanderData(&v1->m_WanderData);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pCharacterOccupantComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pTargetingSystemBaseComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pHealthComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pSceneObjectProperties);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pAttackRightsComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pSimObjectCharacterPropertiesComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pCharacterAnimationComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pRigidBodyComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pActionTreeComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>(&v1->m_pTransformNodeComponent);
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 98
// RVA: 0x14AED10
__int64 dynamic_initializer_for__AllowedToUseCrosswalksSymbol__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("AllowedToUseCrosswalks", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&AllowedToUseCrosswalksSymbol, v0);
  return atexit(dynamic_atexit_destructor_for__AllowedToUseCrosswalksSymbol__);
}

// File Line: 137
// RVA: 0x378410
void __fastcall UFG::AIEntityComponent::OnAttach(UFG::AIEntityComponent *this, UFG::SimObject *object)
{
  UFG::AIEntityComponent *v2; // rdi
  UFG::SimObjectCharacter *v3; // rbx
  UFG::RebindingComponentHandle<UFG::RigidBodyComponent,0> *v4; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *v9; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rax
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0> *v14; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v17; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rax
  UFG::RebindingComponentHandle<UFG::TargetingSystemPedBaseComponent,0> *v19; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v20; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v22; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v23; // rax

  v2 = this;
  v3 = (UFG::SimObjectCharacter *)object;
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::Bind<UFG::SimObjectCharacter>(
    &this->m_pTransformNodeComponent,
    (UFG::SimObjectCharacter *)object);
  v4 = &v2->m_pRigidBodyComponent;
  if ( v2->m_pRigidBodyComponent.m_pSimComponent )
  {
    v5 = v4->mPrev;
    v6 = v2->m_pRigidBodyComponent.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v2->m_pRigidBodyComponent.m_pSimComponent = 0i64;
LABEL_7:
    v2->m_pRigidBodyComponent.m_pSimObject = 0i64;
    v2->m_pRigidBodyComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pRigidBodyComponent.mPrev;
    v4->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v4->mPrev;
    goto LABEL_8;
  }
  if ( v2->m_pRigidBodyComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::RigidBodyComponent,0> *)v4->mPrev != v4
     || (UFG::RebindingComponentHandle<UFG::RigidBodyComponent,0> *)v2->m_pRigidBodyComponent.mNext != &v2->m_pRigidBodyComponent) )
  {
    v7 = v4->mPrev;
    v8 = v2->m_pRigidBodyComponent.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    goto LABEL_7;
  }
LABEL_8:
  v2->m_pRigidBodyComponent.m_Changed = 1;
  v2->m_pRigidBodyComponent.m_pSimObject = (UFG::SimObject *)&v3->vfptr;
  v2->m_pRigidBodyComponent.m_TypeUID = UFG::RigidBodyComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::RigidBodyComponent,0>::BindInternal<UFG::SimObjectCharacter>(v4, v3);
  v9 = &v2->m_pCharacterAnimationComponent;
  if ( v2->m_pCharacterAnimationComponent.m_pSimComponent )
  {
    v10 = v9->mPrev;
    v11 = v2->m_pCharacterAnimationComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v2->m_pCharacterAnimationComponent.m_pSimComponent = 0i64;
LABEL_14:
    v2->m_pCharacterAnimationComponent.m_pSimObject = 0i64;
    v2->m_pCharacterAnimationComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pCharacterAnimationComponent.mPrev;
    v9->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v9->mPrev;
    goto LABEL_15;
  }
  if ( v2->m_pCharacterAnimationComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *)v9->mPrev != v9
     || (UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *)v2->m_pCharacterAnimationComponent.mNext != &v2->m_pCharacterAnimationComponent) )
  {
    v12 = v9->mPrev;
    v13 = v2->m_pCharacterAnimationComponent.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    goto LABEL_14;
  }
LABEL_15:
  v2->m_pCharacterAnimationComponent.m_Changed = 1;
  v2->m_pCharacterAnimationComponent.m_pSimObject = (UFG::SimObject *)&v3->vfptr;
  v2->m_pCharacterAnimationComponent.m_TypeUID = UFG::CharacterAnimationComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>::BindInternal<UFG::SimObjectVehicle>(
    &v2->m_pCharacterAnimationComponent,
    v3);
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0>::Bind<UFG::SimObjectCharacter>(
    &v2->m_pActionTreeComponent,
    v3);
  v14 = &v2->m_pSimObjectCharacterPropertiesComponent;
  if ( v2->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent )
  {
    v15 = v14->mPrev;
    v16 = v2->m_pSimObjectCharacterPropertiesComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    v2->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent = 0i64;
LABEL_21:
    v2->m_pSimObjectCharacterPropertiesComponent.m_pSimObject = 0i64;
    v2->m_pSimObjectCharacterPropertiesComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pSimObjectCharacterPropertiesComponent.mPrev;
    v14->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v14->mPrev;
    goto LABEL_22;
  }
  if ( v2->m_pSimObjectCharacterPropertiesComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0> *)v14->mPrev != v14
     || (UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0> *)v2->m_pSimObjectCharacterPropertiesComponent.mNext != &v2->m_pSimObjectCharacterPropertiesComponent) )
  {
    v17 = v14->mPrev;
    v18 = v2->m_pSimObjectCharacterPropertiesComponent.mNext;
    v17->mNext = v18;
    v18->mPrev = v17;
    goto LABEL_21;
  }
LABEL_22:
  v2->m_pSimObjectCharacterPropertiesComponent.m_Changed = 1;
  v2->m_pSimObjectCharacterPropertiesComponent.m_pSimObject = (UFG::SimObject *)&v3->vfptr;
  v2->m_pSimObjectCharacterPropertiesComponent.m_TypeUID = UFG::SimObjectCharacterPropertiesComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0>::BindInternal<UFG::SimObjectCharacter>(
    &v2->m_pSimObjectCharacterPropertiesComponent,
    v3);
  UFG::RebindingComponentHandle<UFG::AttackRightsComponent,0>::Bind<UFG::SimObjectCharacter>(
    &v2->m_pAttackRightsComponent,
    v3);
  UFG::RebindingComponentHandle<UFG::SceneObjectProperties,0>::Bind<UFG::SimObjectCharacter>(
    &v2->m_pSceneObjectProperties,
    v3);
  UFG::RebindingComponentHandle<UFG::HealthComponent,0>::Bind<UFG::SimObjectCharacter>(&v2->m_pHealthComponent, v3);
  v19 = &v2->m_pTargetingSystemBaseComponent;
  if ( v2->m_pTargetingSystemBaseComponent.m_pSimComponent )
  {
    v20 = v19->mPrev;
    v21 = v2->m_pTargetingSystemBaseComponent.mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    v2->m_pTargetingSystemBaseComponent.m_pSimComponent = 0i64;
LABEL_28:
    v2->m_pTargetingSystemBaseComponent.m_pSimObject = 0i64;
    v2->m_pTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pTargetingSystemBaseComponent.mPrev;
    v19->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v19->mPrev;
    goto LABEL_29;
  }
  if ( v2->m_pTargetingSystemBaseComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::TargetingSystemPedBaseComponent,0> *)v19->mPrev != v19
     || (UFG::RebindingComponentHandle<UFG::TargetingSystemPedBaseComponent,0> *)v2->m_pTargetingSystemBaseComponent.mNext != &v2->m_pTargetingSystemBaseComponent) )
  {
    v22 = v19->mPrev;
    v23 = v2->m_pTargetingSystemBaseComponent.mNext;
    v22->mNext = v23;
    v23->mPrev = v22;
    goto LABEL_28;
  }
LABEL_29:
  v2->m_pTargetingSystemBaseComponent.m_Changed = 1;
  v2->m_pTargetingSystemBaseComponent.m_pSimObject = (UFG::SimObject *)&v3->vfptr;
  v2->m_pTargetingSystemBaseComponent.m_TypeUID = UFG::TargetingSystemPedBaseComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::TargetingSystemPedBaseComponent,0>::BindInternal<UFG::SimObjectCharacter>(
    &v2->m_pTargetingSystemBaseComponent,
    v3);
  UFG::RebindingComponentHandle<UFG::CharacterOccupantComponent,0>::Bind<UFG::SimObjectCharacter>(
    &v2->m_pCharacterOccupantComponent,
    v3);
  UFG::NearbyCharacterManager::AddCharacter(UFG::NearbyCharacterManager::s_pInstance, v2);
}

// File Line: 161
// RVA: 0x3798C0
void __fastcall UFG::AIEntityComponent::OnDetach(UFG::AIEntityComponent *this)
{
  UFG::AIEntityComponent *v1; // rbx
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *v2; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::RebindingComponentHandle<UFG::RigidBodyComponent,0> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *v12; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *v17; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v19; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v20; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rax
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0> *v22; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v23; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v24; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v25; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v26; // rax
  UFG::RebindingComponentHandle<UFG::AttackRightsComponent,0> *v27; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v28; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v29; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v30; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v31; // rax
  UFG::RebindingComponentHandle<UFG::SceneObjectProperties,0> *v32; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v33; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v34; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v35; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v36; // rax
  UFG::RebindingComponentHandle<UFG::HealthComponent,0> *v37; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v38; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v39; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v40; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v41; // rax
  UFG::RebindingComponentHandle<UFG::TargetingSystemPedBaseComponent,0> *v42; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v43; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v44; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v45; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v46; // rax
  UFG::RebindingComponentHandle<UFG::CharacterOccupantComponent,0> *v47; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v48; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v49; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v50; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v51; // rax
  UFG::qSafePointer<UFG::CombatRegion,UFG::CombatRegion> *v52; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v53; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v54; // rax
  float v55; // xmm2_4
  float v56; // xmm0_4

  v1 = this;
  UFG::NearbyCharacterManager::RemoveCharacter(UFG::NearbyCharacterManager::s_pInstance, this);
  v2 = &v1->m_pTransformNodeComponent;
  if ( v1->m_pTransformNodeComponent.m_pSimComponent )
  {
    v3 = v2->mPrev;
    v4 = v1->m_pTransformNodeComponent.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v1->m_pTransformNodeComponent.m_pSimComponent = 0i64;
LABEL_7:
    v1->m_pTransformNodeComponent.m_pSimObject = 0i64;
    v1->m_pTransformNodeComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->m_pTransformNodeComponent.mPrev;
    v2->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->mPrev;
    goto LABEL_8;
  }
  if ( v1->m_pTransformNodeComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)v2->mPrev != v2
     || (UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)v1->m_pTransformNodeComponent.mNext != &v1->m_pTransformNodeComponent) )
  {
    v5 = v2->mPrev;
    v6 = v1->m_pTransformNodeComponent.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  v7 = &v1->m_pRigidBodyComponent;
  v1->m_pTransformNodeComponent.m_Changed = 1;
  if ( v1->m_pRigidBodyComponent.m_pSimComponent )
  {
    v8 = v7->mPrev;
    v9 = v1->m_pRigidBodyComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v1->m_pRigidBodyComponent.m_pSimComponent = 0i64;
LABEL_14:
    v1->m_pRigidBodyComponent.m_pSimObject = 0i64;
    v1->m_pRigidBodyComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->m_pRigidBodyComponent.mPrev;
    v7->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v7->mPrev;
    goto LABEL_15;
  }
  if ( v1->m_pRigidBodyComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::RigidBodyComponent,0> *)v7->mPrev != v7
     || (UFG::RebindingComponentHandle<UFG::RigidBodyComponent,0> *)v1->m_pRigidBodyComponent.mNext != &v1->m_pRigidBodyComponent) )
  {
    v10 = v7->mPrev;
    v11 = v1->m_pRigidBodyComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    goto LABEL_14;
  }
LABEL_15:
  v1->m_pRigidBodyComponent.m_Changed = 1;
  v12 = &v1->m_pCharacterAnimationComponent;
  if ( v1->m_pCharacterAnimationComponent.m_pSimComponent )
  {
    v13 = v12->mPrev;
    v14 = v1->m_pCharacterAnimationComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v1->m_pCharacterAnimationComponent.m_pSimComponent = 0i64;
LABEL_21:
    v1->m_pCharacterAnimationComponent.m_pSimObject = 0i64;
    v1->m_pCharacterAnimationComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->m_pCharacterAnimationComponent.mPrev;
    v12->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v12->mPrev;
    goto LABEL_22;
  }
  if ( v1->m_pCharacterAnimationComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *)v12->mPrev != v12
     || (UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *)v1->m_pCharacterAnimationComponent.mNext != &v1->m_pCharacterAnimationComponent) )
  {
    v15 = v12->mPrev;
    v16 = v1->m_pCharacterAnimationComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    goto LABEL_21;
  }
LABEL_22:
  v1->m_pCharacterAnimationComponent.m_Changed = 1;
  v17 = &v1->m_pActionTreeComponent;
  if ( v1->m_pActionTreeComponent.m_pSimComponent )
  {
    v18 = v17->mPrev;
    v19 = v1->m_pActionTreeComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    v1->m_pActionTreeComponent.m_pSimComponent = 0i64;
LABEL_28:
    v1->m_pActionTreeComponent.m_pSimObject = 0i64;
    v1->m_pActionTreeComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->m_pActionTreeComponent.mPrev;
    v17->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v17->mPrev;
    goto LABEL_29;
  }
  if ( v1->m_pActionTreeComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *)v17->mPrev != v17
     || (UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *)v1->m_pActionTreeComponent.mNext != &v1->m_pActionTreeComponent) )
  {
    v20 = v17->mPrev;
    v21 = v1->m_pActionTreeComponent.mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    goto LABEL_28;
  }
LABEL_29:
  v1->m_pActionTreeComponent.m_Changed = 1;
  v22 = &v1->m_pSimObjectCharacterPropertiesComponent;
  if ( v1->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent )
  {
    v23 = v22->mPrev;
    v24 = v1->m_pSimObjectCharacterPropertiesComponent.mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    v1->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent = 0i64;
LABEL_35:
    v1->m_pSimObjectCharacterPropertiesComponent.m_pSimObject = 0i64;
    v1->m_pSimObjectCharacterPropertiesComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->m_pSimObjectCharacterPropertiesComponent.mPrev;
    v22->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v22->mPrev;
    goto LABEL_36;
  }
  if ( v1->m_pSimObjectCharacterPropertiesComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0> *)v22->mPrev != v22
     || (UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0> *)v1->m_pSimObjectCharacterPropertiesComponent.mNext != &v1->m_pSimObjectCharacterPropertiesComponent) )
  {
    v25 = v22->mPrev;
    v26 = v1->m_pSimObjectCharacterPropertiesComponent.mNext;
    v25->mNext = v26;
    v26->mPrev = v25;
    goto LABEL_35;
  }
LABEL_36:
  v1->m_pSimObjectCharacterPropertiesComponent.m_Changed = 1;
  v27 = &v1->m_pAttackRightsComponent;
  if ( v1->m_pAttackRightsComponent.m_pSimComponent )
  {
    v28 = v27->mPrev;
    v29 = v1->m_pAttackRightsComponent.mNext;
    v28->mNext = v29;
    v29->mPrev = v28;
    v1->m_pAttackRightsComponent.m_pSimComponent = 0i64;
LABEL_42:
    v1->m_pAttackRightsComponent.m_pSimObject = 0i64;
    v1->m_pAttackRightsComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->m_pAttackRightsComponent.mPrev;
    v27->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v27->mPrev;
    goto LABEL_43;
  }
  if ( v1->m_pAttackRightsComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::AttackRightsComponent,0> *)v27->mPrev != v27
     || (UFG::RebindingComponentHandle<UFG::AttackRightsComponent,0> *)v1->m_pAttackRightsComponent.mNext != &v1->m_pAttackRightsComponent) )
  {
    v30 = v27->mPrev;
    v31 = v1->m_pAttackRightsComponent.mNext;
    v30->mNext = v31;
    v31->mPrev = v30;
    goto LABEL_42;
  }
LABEL_43:
  v1->m_pAttackRightsComponent.m_Changed = 1;
  v32 = &v1->m_pSceneObjectProperties;
  if ( v1->m_pSceneObjectProperties.m_pSimComponent )
  {
    v33 = v32->mPrev;
    v34 = v1->m_pSceneObjectProperties.mNext;
    v33->mNext = v34;
    v34->mPrev = v33;
    v1->m_pSceneObjectProperties.m_pSimComponent = 0i64;
LABEL_49:
    v1->m_pSceneObjectProperties.m_pSimObject = 0i64;
    v1->m_pSceneObjectProperties.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->m_pSceneObjectProperties.mPrev;
    v32->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v32->mPrev;
    goto LABEL_50;
  }
  if ( v1->m_pSceneObjectProperties.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::SceneObjectProperties,0> *)v32->mPrev != v32
     || (UFG::RebindingComponentHandle<UFG::SceneObjectProperties,0> *)v1->m_pSceneObjectProperties.mNext != &v1->m_pSceneObjectProperties) )
  {
    v35 = v32->mPrev;
    v36 = v1->m_pSceneObjectProperties.mNext;
    v35->mNext = v36;
    v36->mPrev = v35;
    goto LABEL_49;
  }
LABEL_50:
  v1->m_pSceneObjectProperties.m_Changed = 1;
  v37 = &v1->m_pHealthComponent;
  if ( v1->m_pHealthComponent.m_pSimComponent )
  {
    v38 = v37->mPrev;
    v39 = v1->m_pHealthComponent.mNext;
    v38->mNext = v39;
    v39->mPrev = v38;
    v1->m_pHealthComponent.m_pSimComponent = 0i64;
LABEL_56:
    v1->m_pHealthComponent.m_pSimObject = 0i64;
    v1->m_pHealthComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->m_pHealthComponent.mPrev;
    v37->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v37->mPrev;
    goto LABEL_57;
  }
  if ( v1->m_pHealthComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::HealthComponent,0> *)v37->mPrev != v37
     || (UFG::RebindingComponentHandle<UFG::HealthComponent,0> *)v1->m_pHealthComponent.mNext != &v1->m_pHealthComponent) )
  {
    v40 = v37->mPrev;
    v41 = v1->m_pHealthComponent.mNext;
    v40->mNext = v41;
    v41->mPrev = v40;
    goto LABEL_56;
  }
LABEL_57:
  v1->m_pHealthComponent.m_Changed = 1;
  v42 = &v1->m_pTargetingSystemBaseComponent;
  if ( v1->m_pTargetingSystemBaseComponent.m_pSimComponent )
  {
    v43 = v42->mPrev;
    v44 = v1->m_pTargetingSystemBaseComponent.mNext;
    v43->mNext = v44;
    v44->mPrev = v43;
    v1->m_pTargetingSystemBaseComponent.m_pSimComponent = 0i64;
LABEL_63:
    v1->m_pTargetingSystemBaseComponent.m_pSimObject = 0i64;
    v1->m_pTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->m_pTargetingSystemBaseComponent.mPrev;
    v42->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v42->mPrev;
    goto LABEL_64;
  }
  if ( v1->m_pTargetingSystemBaseComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::TargetingSystemPedBaseComponent,0> *)v42->mPrev != v42
     || (UFG::RebindingComponentHandle<UFG::TargetingSystemPedBaseComponent,0> *)v1->m_pTargetingSystemBaseComponent.mNext != &v1->m_pTargetingSystemBaseComponent) )
  {
    v45 = v42->mPrev;
    v46 = v1->m_pTargetingSystemBaseComponent.mNext;
    v45->mNext = v46;
    v46->mPrev = v45;
    goto LABEL_63;
  }
LABEL_64:
  v1->m_pTargetingSystemBaseComponent.m_Changed = 1;
  v47 = &v1->m_pCharacterOccupantComponent;
  if ( v1->m_pCharacterOccupantComponent.m_pSimComponent )
  {
    v48 = v47->mPrev;
    v49 = v1->m_pCharacterOccupantComponent.mNext;
    v48->mNext = v49;
    v49->mPrev = v48;
    v1->m_pCharacterOccupantComponent.m_pSimComponent = 0i64;
LABEL_70:
    v1->m_pCharacterOccupantComponent.m_pSimObject = 0i64;
    v1->m_pCharacterOccupantComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->m_pCharacterOccupantComponent.mPrev;
    v47->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v47->mPrev;
    goto LABEL_71;
  }
  if ( v1->m_pCharacterOccupantComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::CharacterOccupantComponent,0> *)v47->mPrev != v47
     || (UFG::RebindingComponentHandle<UFG::CharacterOccupantComponent,0> *)v1->m_pCharacterOccupantComponent.mNext != &v1->m_pCharacterOccupantComponent) )
  {
    v50 = v47->mPrev;
    v51 = v1->m_pCharacterOccupantComponent.mNext;
    v50->mNext = v51;
    v51->mPrev = v50;
    goto LABEL_70;
  }
LABEL_71:
  v1->m_pCharacterOccupantComponent.m_Changed = 1;
  v52 = &v1->m_pCombatRegion;
  if ( v1->m_pCombatRegion.m_pPointer )
  {
    v53 = v52->mPrev;
    v54 = v1->m_pCombatRegion.mNext;
    v53->mNext = v54;
    v54->mPrev = v53;
    v52->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *)&v52->mPrev;
    v1->m_pCombatRegion.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *)&v1->m_pCombatRegion.mPrev;
  }
  v1->m_pCombatRegion.m_pPointer = 0i64;
  v55 = UFG::qVector3::msZero.z;
  v56 = UFG::qVector3::msZero.x;
  v1->m_vCombatRegionMoveToVec.y = UFG::qVector3::msZero.y;
  v1->m_vCombatRegionMoveToVec.z = v55;
  v1->m_vCombatRegionMoveToVec.x = v56;
}

// File Line: 187
// RVA: 0x362620
UFG::SimComponent *__fastcall UFG::AIEntityComponent::GetSimObjectCharacterPropertiesComponent(UFG::AIEntityComponent *this)
{
  return this->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent;
}

// File Line: 189
// RVA: 0x35FEE0
UFG::SimComponent *__fastcall UFG::AIEntityComponent::GetHealthComponent(UFG::AIEntityComponent *this)
{
  return this->m_pHealthComponent.m_pSimComponent;
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
UFG::SimComponent *__fastcall UFG::ActiveAIEntityComponent::GetAIActionTreeComponent(UFG::ActiveAIEntityComponent *this)
{
  return this->m_pAIActionTreeComponent.m_pSimComponent;
}

// File Line: 203
// RVA: 0x37BC00
void __fastcall UFG::AIEntityComponent::OnSiblingsChanged(UFG::AIEntityComponent *this)
{
  UFG::AIEntityComponent *v1; // rbx
  bool v2; // zf

  v1 = this;
  if ( this->m_pSceneObjectProperties.m_Changed )
  {
    v2 = this->m_pSceneObjectProperties.m_pSimComponent == 0i64;
    this->m_pSceneObjectProperties.m_Changed = 0;
    if ( !v2 && !((LOBYTE(this->m_Flags) >> 1) & 1) )
    {
      UFG::NearbyCharacterManager::RemoveCharacter(UFG::NearbyCharacterManager::s_pInstance, this);
      UFG::NearbyCharacterManager::AddCharacter(UFG::NearbyCharacterManager::s_pInstance, v1);
    }
  }
}

// File Line: 240
// RVA: 0x34CBF0
bool __fastcall UFG::AIEntityComponent::CanWalkStraightToPoint(UFG::AIEntityComponent *this, UFG::qVector3 *point, UFG::eConstrainToSidewalks constrain_to_sidewalks, UFG::qVector3 *last_valid_point)
{
  UFG::SimObject *v4; // rcx
  UFG::qVector3 *v5; // rsi
  UFG::eConstrainToSidewalks v6; // edi
  UFG::qVector3 *v7; // rbp
  UFG::SimComponent *v8; // rdx
  __int64 v9; // rax
  __int64 v11; // [rsp+40h] [rbp+8h]

  v4 = this->m_pSimObject;
  v5 = last_valid_point;
  v6 = constrain_to_sidewalks;
  v7 = point;
  if ( v4 )
    v8 = UFG::SimObject::GetComponentOfType(v4, UFG::NavComponent::_TypeUID);
  else
    v8 = 0i64;
  v9 = *(__int64 *)((char *)&v8[2].m_BoundComponentHandles.mNode.mNext + 4);
  v11 = *(__int64 *)((char *)&v8[2].m_BoundComponentHandles.mNode.mNext + 4);
  if ( v6 )
    HIDWORD(v11) |= 0x200u;
  else
    HIDWORD(v11) = HIDWORD(v9) & 0xFFFFFDFF;
  return UFG::NavManager::ms_pInstance->vfptr->AIRayCastHits(
           UFG::NavManager::ms_pInstance,
           (UFG::HavokNavPosition *)&v8[1].m_SafePointerList.mNode.mNext,
           v7,
           (UFG::NavParams *)&v11,
           v5) == 0;
}

// File Line: 269
// RVA: 0x3850F0
void __fastcall UFG::AIEntityComponent::SetCombatRegion(UFG::AIEntityComponent *this, UFG::CombatRegion *pRegion)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v2; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v5; // rax

  v2 = (UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *)&this->m_pCombatRegion.mPrev;
  if ( this->m_pCombatRegion.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = v2;
    v2->mNext = v2;
  }
  v2[1].mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *)pRegion;
  if ( pRegion )
  {
    v5 = pRegion->m_SafePointerList.mNode.mPrev;
    v5->mNext = v2;
    v2->mPrev = v5;
    v2->mNext = &pRegion->m_SafePointerList.mNode;
    pRegion->m_SafePointerList.mNode.mPrev = v2;
  }
}

// File Line: 326
// RVA: 0x3559A0
void __fastcall UFG::AIEntityComponent::EntityDeathHandler(UFG::Event *thisEvent)
{
  UFG::SimObjectCVBase *v1; // rcx
  unsigned __int16 v2; // dx
  UFG::ActiveAIEntityComponent *v3; // rax

  v1 = (UFG::SimObjectCVBase *)thisEvent[1].mNext;
  if ( v1 )
  {
    v2 = v1->m_Flags;
    if ( (v2 >> 14) & 1 )
    {
      v3 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v1);
    }
    else if ( (v2 & 0x8000u) == 0 )
    {
      if ( (v2 >> 13) & 1 )
      {
        v3 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v1->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else if ( (v2 >> 12) & 1 )
      {
        v3 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v1->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else
      {
        v3 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                               (UFG::SimObject *)&v1->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
    }
    else
    {
      v3 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v1);
    }
    if ( v3 )
      v3->m_KnowledgeBase.m_bEnabled = 0;
  }
}

// File Line: 349
// RVA: 0x386600
void __fastcall UFG::AIEntityComponent::SetHeadTrackingPosition(UFG::AIEntityComponent *this, UFG::TransformNodeComponent *transform_node_component, UFG::qVector3 *offset)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // r10
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  float v7; // xmm0_4
  float v8; // xmm1_4

  v3 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&this->m_HeadTrackingTarget.m_pTransformNodeComponent.mPrev;
  this->m_HeadTrackingTarget.m_Type = 0;
  if ( this->m_HeadTrackingTarget.m_pTransformNodeComponent.m_pPointer )
  {
    v4 = v3->mPrev;
    v5 = this->m_HeadTrackingTarget.m_pTransformNodeComponent.mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v3->mPrev = v3;
    this->m_HeadTrackingTarget.m_pTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&this->m_HeadTrackingTarget.m_pTransformNodeComponent.mPrev;
  }
  this->m_HeadTrackingTarget.m_pTransformNodeComponent.m_pPointer = (UFG::SimComponent *)&transform_node_component->vfptr;
  if ( transform_node_component )
  {
    v6 = transform_node_component->m_SafePointerList.mNode.mPrev;
    v6->mNext = v3;
    v3->mPrev = v6;
    this->m_HeadTrackingTarget.m_pTransformNodeComponent.mNext = &transform_node_component->m_SafePointerList.mNode;
    transform_node_component->m_SafePointerList.mNode.mPrev = v3;
  }
  v7 = offset->y;
  v8 = offset->z;
  this->m_HeadTrackingTarget.m_Offset.x = offset->x;
  this->m_HeadTrackingTarget.m_Offset.y = v7;
  this->m_HeadTrackingTarget.m_Offset.z = v8;
}

// File Line: 364
// RVA: 0x3865A0
void __fastcall UFG::AIEntityComponent::SetHeadTrackingPosition(UFG::AIEntityComponent *this, UFG::qVector3 *position)
{
  float v2; // xmm0_4
  float v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm1_4

  this->m_HeadTrackingTarget.m_Type = 1;
  v2 = position->y;
  v3 = position->z;
  this->m_HeadTrackingTarget.m_Position.x = position->x;
  this->m_HeadTrackingTarget.m_Position.y = v2;
  this->m_HeadTrackingTarget.m_Position.z = v3;
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
  this->m_HeadTrackingTarget.m_Type = -1;
}

// File Line: 375
// RVA: 0x341190
void __fastcall UFG::AIEntityComponent::AddThreatTarget(UFG::AIEntityComponent *this, UFG::SimObject *pTarget, float radius)
{
  UFG::qFixedArray<UFG::ThreatTarget,10> *v3; // r9
  __int64 v4; // r8
  UFG::SimObject *v5; // r14
  __int64 v6; // r10
  UFG::AIEntityComponent *v7; // rbp
  UFG::SimObject **v8; // rax
  int v9; // eax
  __int64 v10; // rbx
  unsigned __int64 v11; // rsi
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> **v12; // r8
  signed __int64 v13; // r11
  UFG::SimObject *v14; // r10
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v17; // rax
  signed __int64 v18; // r11
  UFG::SimObject *v19; // r10
  __int64 v20; // rcx
  _QWORD *v21; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v22; // rax
  signed __int64 v23; // r11
  UFG::SimObject *v24; // r10
  __int64 v25; // rcx
  _QWORD *v26; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v27; // rax
  signed __int64 v28; // r11
  UFG::SimObject *v29; // r10
  __int64 v30; // rcx
  _QWORD *v31; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v32; // rax
  signed __int64 v33; // rdx
  signed __int64 v34; // rbp
  signed __int64 v35; // r8
  UFG::SimObject *v36; // r10
  __int64 v37; // rcx
  _QWORD *v38; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v39; // rax
  UFG::ThreatTarget *v40; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v41; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v42; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v43; // rax

  v3 = &this->m_ThreatTargets;
  v4 = 0i64;
  v5 = pTarget;
  v6 = this->m_ThreatTargets.size;
  v7 = this;
  if ( v6 <= 0 )
  {
LABEL_5:
    if ( (signed int)v6 < 10 )
      goto LABEL_51;
    v9 = v6 - 1;
    v10 = (signed int)v6 - 1;
    if ( (signed int)v6 - 1 >= 0 )
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
            v13 = --v3->size;
            v14 = v3->p[v13].m_pTarget.m_pPointer;
            if ( v12[1] )
            {
              v15 = *(v12 - 1);
              v16 = *v12;
              v15->mNext = *v12;
              v16->mPrev = v15;
              *(v12 - 1) = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v12 - 1);
              *v12 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v12 - 1);
            }
            v12[1] = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v14;
            if ( v14 )
            {
              v17 = v14->m_SafePointerList.mNode.mPrev;
              v17->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v12 - 1);
              *(v12 - 1) = v17;
              *v12 = &v14->m_SafePointerList.mNode;
              v14->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v12 - 1);
            }
            *((_DWORD *)v12 + 4) = LODWORD(v3->p[v13].m_Radius);
          }
          if ( !*(v12 - 3) )
          {
            v18 = --v3->size;
            v19 = v3->p[v18].m_pTarget.m_pPointer;
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
              v22 = v19->m_SafePointerList.mNode.mPrev;
              v22->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v12 - 5);
              *(v12 - 5) = v22;
              *(v12 - 4) = &v19->m_SafePointerList.mNode;
              v19->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v12 - 5);
            }
            *((_DWORD *)v12 - 4) = LODWORD(v3->p[v18].m_Radius);
          }
          if ( !*(v12 - 7) )
          {
            v23 = --v3->size;
            v24 = v3->p[v23].m_pTarget.m_pPointer;
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
              v27 = v24->m_SafePointerList.mNode.mPrev;
              v27->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v12 - 9);
              *(v12 - 9) = v27;
              *(v12 - 8) = &v24->m_SafePointerList.mNode;
              v24->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v12 - 9);
            }
            *((_DWORD *)v12 - 12) = LODWORD(v3->p[v23].m_Radius);
          }
          if ( !*(v12 - 11) )
          {
            v28 = --v3->size;
            v29 = v3->p[v28].m_pTarget.m_pPointer;
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
              v32 = v29->m_SafePointerList.mNode.mPrev;
              v32->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v12 - 13);
              *(v12 - 13) = v32;
              *(v12 - 12) = &v29->m_SafePointerList.mNode;
              v29->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v12 - 13);
            }
            *((_DWORD *)v12 - 20) = LODWORD(v3->p[v28].m_Radius);
          }
          v12 -= 16;
          --v11;
        }
        while ( v11 );
      }
      if ( v10 >= 0 )
      {
        v33 = (signed __int64)&v3->p[v10];
        v34 = (char *)v7 - (char *)v3;
        do
        {
          if ( !*(_QWORD *)(v33 + v34 + 1008) )
          {
            v35 = --v3->size;
            v36 = v3->p[v35].m_pTarget.m_pPointer;
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
              v39 = v36->m_SafePointerList.mNode.mPrev;
              v39->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v33;
              *(_QWORD *)v33 = v39;
              *(_QWORD *)(v33 + 8) = (char *)v36 + 8;
              v36->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v33;
            }
            *(float *)(v33 + 24) = v3->p[v35].m_Radius;
          }
          v33 -= 32i64;
          --v10;
        }
        while ( v10 >= 0 );
      }
    }
    LODWORD(v6) = v3->size;
    if ( (signed int)v3->size < 10 )
    {
LABEL_51:
      v40 = &v3->p[(unsigned int)v6];
      v3->size = v6 + 1;
      if ( v40->m_pTarget.m_pPointer )
      {
        v41 = v40->m_pTarget.mPrev;
        v42 = v40->m_pTarget.mNext;
        v41->mNext = v42;
        v42->mPrev = v41;
        v40->m_pTarget.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v40->m_pTarget.mPrev;
        v40->m_pTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v40->m_pTarget.mPrev;
      }
      v40->m_pTarget.m_pPointer = v5;
      if ( v5 )
      {
        v43 = v5->m_SafePointerList.mNode.mPrev;
        v43->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v40->m_pTarget.mPrev;
        v40->m_pTarget.mPrev = v43;
        v40->m_pTarget.mNext = &v5->m_SafePointerList.mNode;
        v5->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v40->m_pTarget.mPrev;
      }
      v40->m_Radius = radius;
    }
  }
  else
  {
    v8 = &this->m_ThreatTargets.p[0].m_pTarget.m_pPointer;
    while ( *v8 != pTarget )
    {
      ++v4;
      v8 += 4;
      if ( v4 >= v6 )
        goto LABEL_5;
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
  return atexit(dynamic_atexit_destructor_for__UFG::ActiveAIEntityComponent::s_ActiveAIEntityComponentList__);
}

// File Line: 449
// RVA: 0x363460
signed __int64 __fastcall UFG::ActiveAIEntityComponent::GetTypeSize(UFG::ActiveAIEntityComponent *this)
{
  return 4208i64;
}

// File Line: 453
// RVA: 0x32C350
void __fastcall UFG::ActiveAIEntityComponent::ActiveAIEntityComponent(UFG::ActiveAIEntityComponent *this, unsigned int name_uid, UFG::qPropertySet *properties)
{
  UFG::qPropertySet *v3; // rsi
  UFG::ActiveAIEntityComponent *v4; // rdi
  UFG::qNode<UFG::ActiveAIEntityComponent,UFG::ActiveAIEntityComponent> *v5; // rbx
  UFG::PedKnowledgeBase *v6; // rcx
  UFG::Ticket *v7; // rax
  UFG::Ticket *v8; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::FormationManagerComponent> *v9; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::PedFormationManagerComponent> *v10; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AttackRightsComponent> *v11; // rax
  UFG::qList<UFG::SupplementaryAttackTarget,UFG::SupplementaryAttackTarget,1,0> *v12; // rax
  UFG::qNode<UFG::ActiveAIEntityComponent,UFG::ActiveAIEntityComponent> *v13; // rax
  bool *v14; // rax
  __int64 *v15; // rcx
  UFG::SimObject *v16; // rbx
  UFG::PedSpawnManager *v17; // rax
  UFG::TargetingSystemPedBaseComponent *v18; // rcx
  signed int v19; // eax
  UFG::qList<UFG::SupplementaryAttackTarget,UFG::SupplementaryAttackTarget,1,0> *v20; // [rsp+80h] [rbp+18h]
  UFG::Ticket *v21; // [rsp+88h] [rbp+20h]

  v3 = properties;
  v4 = this;
  UFG::AIEntityComponent::AIEntityComponent((UFG::AIEntityComponent *)&this->vfptr, name_uid, properties, 0);
  v5 = (UFG::qNode<UFG::ActiveAIEntityComponent,UFG::ActiveAIEntityComponent> *)&v4->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  v4->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::ActiveAIEntityComponent::`vftable;
  v6 = &v4->m_KnowledgeBase;
  v20 = (UFG::qList<UFG::SupplementaryAttackTarget,UFG::SupplementaryAttackTarget,1,0> *)v6;
  v6->m_pParentSimObject.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->m_pParentSimObject.mPrev;
  v6->m_pParentSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->m_pParentSimObject.mPrev;
  v4->m_KnowledgeBase.m_pParentSimObject.m_pPointer = 0i64;
  v4->m_KnowledgeBase.m_bEnabled = 1;
  v4->m_KnowledgeBase.m_aHostilePedRecords.p = 0i64;
  *(_QWORD *)&v4->m_KnowledgeBase.m_aHostilePedRecords.size = 0i64;
  v7 = &v4->m_KnowledgeBase.m_ticketRefreshHostiles;
  v7->mPrev = (UFG::qNode<UFG::Ticket,UFG::Ticket> *)&v7->mPrev;
  v7->mNext = (UFG::qNode<UFG::Ticket,UFG::Ticket> *)&v7->mPrev;
  v6->m_ticketRefreshHostiles.mTimestamp = 0i64;
  v6->m_ticketRefreshHostiles.mActiveCallback.m_Closure.m_pthis = 0i64;
  v6->m_ticketRefreshHostiles.mActiveCallback.m_Closure.m_pFunction = 0i64;
  v6->m_ticketRefreshHostiles.mInactiveCallback.m_Closure.m_pthis = 0i64;
  v6->m_ticketRefreshHostiles.mInactiveCallback.m_Closure.m_pFunction = 0i64;
  v8 = &v4->m_KnowledgeBase.m_ticketUpdate;
  v21 = v8;
  v8->mPrev = (UFG::qNode<UFG::Ticket,UFG::Ticket> *)&v8->mPrev;
  v8->mNext = (UFG::qNode<UFG::Ticket,UFG::Ticket> *)&v8->mPrev;
  v6->m_ticketUpdate.mTimestamp = 0i64;
  v6->m_ticketUpdate.mActiveCallback.m_Closure.m_pthis = 0i64;
  v6->m_ticketUpdate.mActiveCallback.m_Closure.m_pFunction = 0i64;
  v6->m_ticketUpdate.mInactiveCallback.m_Closure.m_pthis = 0i64;
  v6->m_ticketUpdate.mInactiveCallback.m_Closure.m_pFunction = 0i64;
  UFG::RebindingComponentHandle<UFG::AIActionTreeComponent,0>::RebindingComponentHandle<UFG::AIActionTreeComponent,0>(&v4->m_pAIActionTreeComponent);
  UFG::RebindingComponentHandle<UFG::CharacterControllerInterface,0>::RebindingComponentHandle<UFG::CharacterControllerInterface,0>(&v4->m_pCharacterController);
  UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0>::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0>(&v4->m_pAICharacterControllerBaseComponent);
  v9 = &v4->m_pCurrentFormationManagerComponent;
  v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  v9->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  v4->m_pCurrentFormationManagerComponent.m_pPointer = 0i64;
  v10 = &v4->m_pCurrentPedFormationManagerComponent;
  v20 = (UFG::qList<UFG::SupplementaryAttackTarget,UFG::SupplementaryAttackTarget,1,0> *)v10;
  v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  v4->m_pCurrentPedFormationManagerComponent.m_pPointer = 0i64;
  UFG::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0>::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0>(&v4->m_pCharacterPhysicsComponent);
  UFG::RebindingComponentHandle<UFG::HitReactionComponent,0>::RebindingComponentHandle<UFG::HitReactionComponent,0>(&v4->m_pHitReactionComponent);
  UFG::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0>::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0>(&v4->m_pAIScriptInterfaceComponent);
  UFG::RebindingComponentHandle<UFG::InterestPointUserComponent,0>::RebindingComponentHandle<UFG::InterestPointUserComponent,0>(&v4->m_pInterestPointUserComponent);
  v11 = &v4->m_pCurrentAttackTarget;
  v20 = (UFG::qList<UFG::SupplementaryAttackTarget,UFG::SupplementaryAttackTarget,1,0> *)v11;
  v11->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v11->mPrev;
  v11->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v11->mPrev;
  v4->m_pCurrentAttackTarget.m_pPointer = 0i64;
  `eh vector constructor iterator(
    v4->m_pDesiredTarget,
    0x18ui64,
    91,
    (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>);
  v12 = &v4->m_SupplementaryAttackTargets;
  v20 = v12;
  v12->mNode.mPrev = &v12->mNode;
  v12->mNode.mNext = &v12->mNode;
  v13 = UFG::ActiveAIEntityComponent::s_ActiveAIEntityComponentList.mNode.mPrev;
  UFG::ActiveAIEntityComponent::s_ActiveAIEntityComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::ActiveAIEntityComponent,UFG::ActiveAIEntityComponent> *)&v4->mPrev;
  v5->mPrev = v13;
  v4->mNext = (UFG::qNode<UFG::ActiveAIEntityComponent,UFG::ActiveAIEntityComponent> *)&UFG::ActiveAIEntityComponent::s_ActiveAIEntityComponentList;
  UFG::ActiveAIEntityComponent::s_ActiveAIEntityComponentList.mNode.mPrev = (UFG::qNode<UFG::ActiveAIEntityComponent,UFG::ActiveAIEntityComponent> *)&v4->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v4->vfptr,
    UFG::ActiveAIEntityComponent::_ActiveAIEntityComponentTypeUID,
    "ActiveAIEntityComponent");
  *(_WORD *)v4->m_CompletedNavigationTask = 0;
  v4->m_MinTimeBetweenUpdateTarget = 0.1;
  v4->m_MaxTimeBetweenUpdateTarget = 0.30000001;
  if ( v3 )
  {
    v4->m_MinTimeBetweenUpdateTarget = 0.1;
    v4->m_MaxTimeBetweenUpdateTarget = 0.30000001;
    LOBYTE(v20) = 0;
    v14 = UFG::qPropertySet::Get<bool>(v3, (UFG::qSymbol *)&qSymbol_CanWander.mUID, DEPTH_RECURSE);
    v15 = (__int64 *)&v20;
    if ( v14 )
      v15 = (__int64 *)v14;
    v4->m_bCanWander = *(_BYTE *)v15;
  }
  v4->m_CurrentEmotion = 0;
  v4->m_CurrentObjective = 0;
  UFG::NearbyCharacterManager::RemoveCharacter(
    UFG::NearbyCharacterManager::s_pInstance,
    (UFG::AIEntityComponent *)&v4->vfptr);
  UFG::NearbyCharacterManager::AddCharacter(
    UFG::NearbyCharacterManager::s_pInstance,
    (UFG::AIEntityComponent *)&v4->vfptr);
  if ( UFG::g_AIObjectiveParams[v4->m_CurrentObjective].m_IsHostile )
  {
    v16 = v4->m_pSimObject;
    v17 = UFG::PedSpawnManager::GetInstance();
    UFG::PedSpawnManager::SetSuspendOption(v17, v16, NoSuspend);
  }
  if ( v4->m_pTargetingSystemBaseComponent.m_pSimComponent )
  {
    v18 = (UFG::TargetingSystemPedBaseComponent *)v4->m_pTargetingSystemBaseComponent.m_pSimComponent;
    if ( UFG::g_AIObjectiveParams[0].m_IsHostile )
      UFG::TargetingSystemPedBaseComponent::SetToHighFrequencyUpdate(v18);
    else
      UFG::TargetingSystemPedBaseComponent::SetToLowFrequencyUpdate(v18);
    LOBYTE(v4->m_pTargetingSystemBaseComponent.m_pSimComponent[9].vfptr) = 1;
  }
  v4->m_PrevObjectiveWasHostile = 0;
  v4->m_MaxEngagementDistanceXY = 20.0;
  v4->m_MaxEngagementDistanceZ = 2.0;
  v4->m_EngagementOverrideEnabled = 0;
  v4->m_NextTimeToUpdateAttackTarget = -999999.0;
  v4->m_TimeAllowedToKeepAttackingDeadTarget = 0.0;
  *(_QWORD *)&v4->m_TargetToStayNear = 0i64;
  v4->m_MaxDistanceFromTargetToStayNearHysteresis = 0.0;
  *(_QWORD *)&v4->m_ScriptedParkourTypeNearGoal = 0i64;
  v4->m_ScriptOverrideFreerunning = 0;
  *(_WORD *)&v4->m_IsSpawning = 1;
  v4->m_InPropInteractBranch = 0;
  v4->m_ChanceOfCleanVault = *UFG::qPropertySet::Get<float>(
                                v3,
                                (UFG::qSymbol *)&SimSym_ChanceOfCleanVault.mUID,
                                DEPTH_RECURSE);
  v4->m_CleanNextVault = UFG::qRandom(1.0, &UFG::qDefaultSeed) < v4->m_ChanceOfCleanVault;
  v19 = initted;
  if ( !initted )
    v19 = 1;
  initted = v19;
}

// File Line: 519
// RVA: 0x334FF0
void __fastcall UFG::ActiveAIEntityComponent::~ActiveAIEntityComponent(UFG::ActiveAIEntityComponent *this)
{
  UFG::ActiveAIEntityComponent *v1; // rbx
  UFG::qNode<UFG::ActiveAIEntityComponent,UFG::ActiveAIEntityComponent> *v2; // rsi
  UFG::qNode<UFG::ActiveAIEntityComponent,UFG::ActiveAIEntityComponent> *v3; // rcx
  UFG::qNode<UFG::ActiveAIEntityComponent,UFG::ActiveAIEntityComponent> *v4; // rax
  UFG::qList<UFG::SupplementaryAttackTarget,UFG::SupplementaryAttackTarget,1,0> *v5; // rdi
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
  UFG::qSafePointer<UFG::SimComponent,UFG::AttackRightsComponent> *v18; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v22; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::PedFormationManagerComponent> *v23; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v24; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v26; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v27; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::FormationManagerComponent> *v28; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v29; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v30; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v31; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v32; // rax
  UFG::qNode<UFG::ActiveAIEntityComponent,UFG::ActiveAIEntityComponent> *v33; // rcx
  UFG::qNode<UFG::ActiveAIEntityComponent,UFG::ActiveAIEntityComponent> *v34; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::ActiveAIEntityComponent::`vftable;
  if ( this == UFG::ActiveAIEntityComponent::s_ActiveAIEntityComponentpCurrentIterator )
    UFG::ActiveAIEntityComponent::s_ActiveAIEntityComponentpCurrentIterator = (UFG::ActiveAIEntityComponent *)&this->mPrev[-84].mNext;
  v2 = (UFG::qNode<UFG::ActiveAIEntityComponent,UFG::ActiveAIEntityComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = &v1->m_SupplementaryAttackTargets;
  while ( (UFG::qList<UFG::SupplementaryAttackTarget,UFG::SupplementaryAttackTarget,1,0> *)v1->m_SupplementaryAttackTargets.mNode.mNext != &v1->m_SupplementaryAttackTargets )
  {
    v6 = v1->m_SupplementaryAttackTargets.mNode.mNext;
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
  UFG::qList<UFG::SupplementaryAttackTarget,UFG::SupplementaryAttackTarget,1,0>::DeleteNodes((UFG::qList<UFG::CollisionMeshData::DeferredBreakablePartsMark,UFG::CollisionMeshData::DeferredBreakablePartsMark,1,0> *)&v1->m_SupplementaryAttackTargets);
  v16 = v5->mNode.mPrev;
  v17 = v1->m_SupplementaryAttackTargets.mNode.mNext;
  v16->mNext = v17;
  v17->mPrev = v16;
  v5->mNode.mPrev = &v5->mNode;
  v1->m_SupplementaryAttackTargets.mNode.mNext = &v1->m_SupplementaryAttackTargets.mNode;
  `eh vector destructor iterator(
    v1->m_pDesiredTarget,
    0x18ui64,
    91,
    (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
  v18 = &v1->m_pCurrentAttackTarget;
  if ( v1->m_pCurrentAttackTarget.m_pPointer )
  {
    v19 = v18->mPrev;
    v20 = v1->m_pCurrentAttackTarget.mNext;
    v19->mNext = v20;
    v20->mPrev = v19;
    v18->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v18->mPrev;
    v1->m_pCurrentAttackTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pCurrentAttackTarget.mPrev;
  }
  v1->m_pCurrentAttackTarget.m_pPointer = 0i64;
  v21 = v18->mPrev;
  v22 = v1->m_pCurrentAttackTarget.mNext;
  v21->mNext = v22;
  v22->mPrev = v21;
  v18->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v18->mPrev;
  v1->m_pCurrentAttackTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pCurrentAttackTarget.mPrev;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pInterestPointUserComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pAIScriptInterfaceComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pHitReactionComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pCharacterPhysicsComponent);
  v23 = &v1->m_pCurrentPedFormationManagerComponent;
  if ( v1->m_pCurrentPedFormationManagerComponent.m_pPointer )
  {
    v24 = v23->mPrev;
    v25 = v1->m_pCurrentPedFormationManagerComponent.mNext;
    v24->mNext = v25;
    v25->mPrev = v24;
    v23->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v23->mPrev;
    v1->m_pCurrentPedFormationManagerComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pCurrentPedFormationManagerComponent.mPrev;
  }
  v1->m_pCurrentPedFormationManagerComponent.m_pPointer = 0i64;
  v26 = v23->mPrev;
  v27 = v1->m_pCurrentPedFormationManagerComponent.mNext;
  v26->mNext = v27;
  v27->mPrev = v26;
  v23->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v23->mPrev;
  v1->m_pCurrentPedFormationManagerComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pCurrentPedFormationManagerComponent.mPrev;
  v28 = &v1->m_pCurrentFormationManagerComponent;
  if ( v1->m_pCurrentFormationManagerComponent.m_pPointer )
  {
    v29 = v28->mPrev;
    v30 = v1->m_pCurrentFormationManagerComponent.mNext;
    v29->mNext = v30;
    v30->mPrev = v29;
    v28->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v28->mPrev;
    v1->m_pCurrentFormationManagerComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pCurrentFormationManagerComponent.mPrev;
  }
  v1->m_pCurrentFormationManagerComponent.m_pPointer = 0i64;
  v31 = v28->mPrev;
  v32 = v1->m_pCurrentFormationManagerComponent.mNext;
  v31->mNext = v32;
  v32->mPrev = v31;
  v28->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v28->mPrev;
  v1->m_pCurrentFormationManagerComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pCurrentFormationManagerComponent.mPrev;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pAICharacterControllerBaseComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pCharacterController);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pAIActionTreeComponent);
  UFG::PedKnowledgeBase::~PedKnowledgeBase(&v1->m_KnowledgeBase);
  v33 = v2->mPrev;
  v34 = v2->mNext;
  v33->mNext = v34;
  v34->mPrev = v33;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::AIEntityComponent::~AIEntityComponent((UFG::AIEntityComponent *)&v1->vfptr);
}

// File Line: 541
// RVA: 0x382840
void __fastcall UFG::ActiveAIEntityComponent::Reset(UFG::ActiveAIEntityComponent *this)
{
  UFG::ActiveAIEntityComponent *v1; // rbx
  signed __int64 v2; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v3; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::SimComponent *v6; // rax
  signed __int64 v7; // rdi
  UFG::PedKnowledgeRecord *v8; // rcx
  char *v9; // rbx

  v1 = this;
  UFG::ActiveAIEntityComponent::SetCurrentObjective(this, 0, "ActiveAIEntityComponent::Reset");
  v1->m_AIPositionValid = 0;
  v2 = 91i64;
  v3 = v1->m_pDesiredTarget;
  do
  {
    if ( v3->m_pPointer )
    {
      v4 = v3->mPrev;
      v5 = v3->mNext;
      v4->mNext = v5;
      v5->mPrev = v4;
      v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mPrev;
      v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mPrev;
    }
    v3->m_pPointer = 0i64;
    ++v3;
    --v2;
  }
  while ( v2 );
  v1->m_HostilityEnabled = 1;
  *(_WORD *)&v1->m_IsSpawning = 1;
  v1->m_InPropInteractBranch = 0;
  v1->m_NextTimeToUpdateAttackTarget = -999999.0;
  v6 = v1->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent;
  if ( v6 )
    v6[3].m_TypeUID = 0;
  v7 = (signed __int64)&v1->m_KnowledgeBase;
  v1->m_ThreatTargets.size = 0;
  v1->m_KnowledgeBase.m_bEnabled = 1;
  v8 = v1->m_KnowledgeBase.m_aHostilePedRecords.p;
  if ( v8 )
  {
    v9 = (char *)&v8[-1] + 48;
    `eh vector destructor iterator(
      v8,
      0x38ui64,
      *((_DWORD *)&v8[-1] + 12),
      (void (__fastcall *)(void *))UFG::InterestPointUseDetails::~InterestPointUseDetails);
    operator delete[](v9);
  }
  *(_QWORD *)(v7 + 40) = 0i64;
  *(_QWORD *)(v7 + 32) = 0i64;
  UFG::PedKnowledgeBase::RefreshHostileList((UFG::PedKnowledgeBase *)v7, 0.0);
}

// File Line: 565
// RVA: 0x382F00
void __fastcall UFG::ActiveAIEntityComponent::ResetAndLoadProperties(UFG::ActiveAIEntityComponent *this)
{
  UFG::ActiveAIEntityComponent *v1; // rbx
  UFG::SceneObjectProperties *v2; // rdx
  UFG::qPropertySet *v3; // rcx
  bool *v4; // rax
  char *v5; // rcx
  char v6; // al
  UFG::AIActionTreeComponent *v7; // rcx
  char v8; // [rsp+30h] [rbp+8h]

  v1 = this;
  v2 = this->m_pSimObject->m_pSceneObj;
  v3 = v2->mpWritableProperties;
  if ( v3 || (v3 = v2->mpConstProperties) != 0i64 )
  {
    v1->m_MinTimeBetweenUpdateTarget = 0.1;
    v1->m_MaxTimeBetweenUpdateTarget = 0.30000001;
    v8 = 0;
    v4 = UFG::qPropertySet::Get<bool>(v3, (UFG::qSymbol *)&qSymbol_CanWander.mUID, DEPTH_RECURSE);
    v5 = &v8;
    if ( v4 )
      v5 = (char *)v4;
    v6 = *v5;
    v7 = (UFG::AIActionTreeComponent *)v1->m_pAIActionTreeComponent.m_pSimComponent;
    v1->m_bCanWander = v6;
    if ( v7 )
      UFG::AIActionTreeComponent::ResetDefaultTree(v7);
  }
  UFG::ActiveAIEntityComponent::Reset(v1);
}

// File Line: 580
// RVA: 0x378800
void __fastcall UFG::ActiveAIEntityComponent::OnAttach(UFG::ActiveAIEntityComponent *this, UFG::SimObject *object)
{
  UFG::ActiveAIEntityComponent *v2; // rbx
  UFG::SimObjectCharacter *v3; // rdi
  UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0> *v4; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rdx

  v2 = this;
  v3 = (UFG::SimObjectCharacter *)object;
  UFG::RebindingComponentHandle<UFG::CharacterControllerInterface,0>::Bind<UFG::SimObjectCharacter>(
    &this->m_pCharacterController,
    (UFG::SimObjectCharacter *)object);
  v4 = &v2->m_pAICharacterControllerBaseComponent;
  if ( v2->m_pAICharacterControllerBaseComponent.m_pSimComponent )
  {
    v5 = v2->m_pAICharacterControllerBaseComponent.mNext;
    v6 = v4->mPrev;
    v6->mNext = v5;
    v5->mPrev = v6;
    v2->m_pAICharacterControllerBaseComponent.m_pSimComponent = 0i64;
LABEL_7:
    v2->m_pAICharacterControllerBaseComponent.m_pSimObject = 0i64;
    v2->m_pAICharacterControllerBaseComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pAICharacterControllerBaseComponent.mPrev;
    v4->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v4->mPrev;
    goto LABEL_8;
  }
  if ( v2->m_pAICharacterControllerBaseComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0> *)v4->mPrev != v4
     || (UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0> *)v2->m_pAICharacterControllerBaseComponent.mNext != &v2->m_pAICharacterControllerBaseComponent) )
  {
    v7 = v2->m_pAICharacterControllerBaseComponent.mNext;
    v8 = v4->mPrev;
    v8->mNext = v7;
    v7->mPrev = v8;
    goto LABEL_7;
  }
LABEL_8:
  v2->m_pAICharacterControllerBaseComponent.m_Changed = 1;
  v2->m_pAICharacterControllerBaseComponent.m_pSimObject = (UFG::SimObject *)&v3->vfptr;
  v2->m_pAICharacterControllerBaseComponent.m_TypeUID = UFG::AICharacterControllerBaseComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0>::BindInternal<UFG::SimObjectCharacter>(
    v4,
    v3);
  UFG::RebindingComponentHandle<UFG::AIActionTreeComponent,0>::Bind<UFG::SimObjectCharacter>(
    &v2->m_pAIActionTreeComponent,
    v3);
  UFG::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0>::Bind<UFG::SimObjectCharacter>(
    &v2->m_pCharacterPhysicsComponent,
    v3);
  UFG::RebindingComponentHandle<UFG::HitReactionComponent,0>::Bind<UFG::SimObjectCharacter>(
    &v2->m_pHitReactionComponent,
    v3);
  UFG::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0>::Bind<UFG::SimObjectCharacter>(
    &v2->m_pAIScriptInterfaceComponent,
    v3);
  UFG::RebindingComponentHandle<UFG::InterestPointUserComponent,0>::Bind<UFG::SimObjectCharacter>(
    &v2->m_pInterestPointUserComponent,
    v3);
  UFG::AIEntityComponent::OnAttach((UFG::AIEntityComponent *)&v2->vfptr, (UFG::SimObject *)&v3->vfptr);
  UFG::PedKnowledgeBase::OnAttach(&v2->m_KnowledgeBase, (UFG::SimObject *)&v3->vfptr);
}

// File Line: 602
// RVA: 0x379EA0
void __fastcall UFG::ActiveAIEntityComponent::OnDetach(UFG::ActiveAIEntityComponent *this)
{
  UFG::RebindingComponentHandle<UFG::CharacterControllerInterface,0> *v1; // r8
  UFG::ActiveAIEntityComponent *v2; // rbx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::RebindingComponentHandle<UFG::AIActionTreeComponent,0> *v12; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0> *v17; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v19; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v20; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rax
  UFG::RebindingComponentHandle<UFG::HitReactionComponent,0> *v22; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v23; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v24; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v25; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v26; // rax
  UFG::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0> *v27; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v28; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v29; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v30; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v31; // rax
  UFG::RebindingComponentHandle<UFG::InterestPointUserComponent,0> *v32; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v33; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v34; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v35; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v36; // rax

  v1 = &this->m_pCharacterController;
  v2 = this;
  if ( this->m_pCharacterController.m_pSimComponent )
  {
    v3 = v1->mPrev;
    v4 = this->m_pCharacterController.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    this->m_pCharacterController.m_pSimComponent = 0i64;
LABEL_7:
    v1->m_pSimObject = 0i64;
    v1->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    v1->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    goto LABEL_8;
  }
  if ( this->m_pCharacterController.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::CharacterControllerInterface,0> *)v1->mPrev != v1
     || (UFG::RebindingComponentHandle<UFG::CharacterControllerInterface,0> *)this->m_pCharacterController.mNext != &this->m_pCharacterController) )
  {
    v5 = v1->mPrev;
    v6 = v1->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  v7 = &v2->m_pAICharacterControllerBaseComponent;
  v1->m_Changed = 1;
  if ( v2->m_pAICharacterControllerBaseComponent.m_pSimComponent )
  {
    v8 = v7->mPrev;
    v9 = v2->m_pAICharacterControllerBaseComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v2->m_pAICharacterControllerBaseComponent.m_pSimComponent = 0i64;
LABEL_14:
    v2->m_pAICharacterControllerBaseComponent.m_pSimObject = 0i64;
    v2->m_pAICharacterControllerBaseComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pAICharacterControllerBaseComponent.mPrev;
    v7->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v7->mPrev;
    goto LABEL_15;
  }
  if ( v2->m_pAICharacterControllerBaseComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0> *)v7->mPrev != v7
     || (UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0> *)v2->m_pAICharacterControllerBaseComponent.mNext != &v2->m_pAICharacterControllerBaseComponent) )
  {
    v10 = v7->mPrev;
    v11 = v2->m_pAICharacterControllerBaseComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    goto LABEL_14;
  }
LABEL_15:
  v2->m_pAICharacterControllerBaseComponent.m_Changed = 1;
  v12 = &v2->m_pAIActionTreeComponent;
  if ( v2->m_pAIActionTreeComponent.m_pSimComponent )
  {
    v13 = v12->mPrev;
    v14 = v2->m_pAIActionTreeComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v2->m_pAIActionTreeComponent.m_pSimComponent = 0i64;
LABEL_21:
    v2->m_pAIActionTreeComponent.m_pSimObject = 0i64;
    v2->m_pAIActionTreeComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pAIActionTreeComponent.mPrev;
    v12->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v12->mPrev;
    goto LABEL_22;
  }
  if ( v2->m_pAIActionTreeComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::AIActionTreeComponent,0> *)v12->mPrev != v12
     || (UFG::RebindingComponentHandle<UFG::AIActionTreeComponent,0> *)v2->m_pAIActionTreeComponent.mNext != &v2->m_pAIActionTreeComponent) )
  {
    v15 = v12->mPrev;
    v16 = v2->m_pAIActionTreeComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    goto LABEL_21;
  }
LABEL_22:
  v2->m_pAIActionTreeComponent.m_Changed = 1;
  v17 = &v2->m_pCharacterPhysicsComponent;
  if ( v2->m_pCharacterPhysicsComponent.m_pSimComponent )
  {
    v18 = v17->mPrev;
    v19 = v2->m_pCharacterPhysicsComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    v2->m_pCharacterPhysicsComponent.m_pSimComponent = 0i64;
LABEL_28:
    v2->m_pCharacterPhysicsComponent.m_pSimObject = 0i64;
    v2->m_pCharacterPhysicsComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pCharacterPhysicsComponent.mPrev;
    v17->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v17->mPrev;
    goto LABEL_29;
  }
  if ( v2->m_pCharacterPhysicsComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0> *)v17->mPrev != v17
     || (UFG::RebindingComponentHandle<UFG::CharacterPhysicsComponent,0> *)v2->m_pCharacterPhysicsComponent.mNext != &v2->m_pCharacterPhysicsComponent) )
  {
    v20 = v17->mPrev;
    v21 = v2->m_pCharacterPhysicsComponent.mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    goto LABEL_28;
  }
LABEL_29:
  v2->m_pCharacterPhysicsComponent.m_Changed = 1;
  v22 = &v2->m_pHitReactionComponent;
  if ( v2->m_pHitReactionComponent.m_pSimComponent )
  {
    v23 = v22->mPrev;
    v24 = v2->m_pHitReactionComponent.mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    v2->m_pHitReactionComponent.m_pSimComponent = 0i64;
LABEL_35:
    v2->m_pHitReactionComponent.m_pSimObject = 0i64;
    v2->m_pHitReactionComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pHitReactionComponent.mPrev;
    v22->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v22->mPrev;
    goto LABEL_36;
  }
  if ( v2->m_pHitReactionComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::HitReactionComponent,0> *)v22->mPrev != v22
     || (UFG::RebindingComponentHandle<UFG::HitReactionComponent,0> *)v2->m_pHitReactionComponent.mNext != &v2->m_pHitReactionComponent) )
  {
    v25 = v22->mPrev;
    v26 = v2->m_pHitReactionComponent.mNext;
    v25->mNext = v26;
    v26->mPrev = v25;
    goto LABEL_35;
  }
LABEL_36:
  v2->m_pHitReactionComponent.m_Changed = 1;
  v27 = &v2->m_pAIScriptInterfaceComponent;
  if ( v2->m_pAIScriptInterfaceComponent.m_pSimComponent )
  {
    v28 = v27->mPrev;
    v29 = v2->m_pAIScriptInterfaceComponent.mNext;
    v28->mNext = v29;
    v29->mPrev = v28;
    v2->m_pAIScriptInterfaceComponent.m_pSimComponent = 0i64;
LABEL_42:
    v2->m_pAIScriptInterfaceComponent.m_pSimObject = 0i64;
    v2->m_pAIScriptInterfaceComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pAIScriptInterfaceComponent.mPrev;
    v27->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v27->mPrev;
    goto LABEL_43;
  }
  if ( v2->m_pAIScriptInterfaceComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0> *)v27->mPrev != v27
     || (UFG::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0> *)v2->m_pAIScriptInterfaceComponent.mNext != &v2->m_pAIScriptInterfaceComponent) )
  {
    v30 = v27->mPrev;
    v31 = v2->m_pAIScriptInterfaceComponent.mNext;
    v30->mNext = v31;
    v31->mPrev = v30;
    goto LABEL_42;
  }
LABEL_43:
  v2->m_pAIScriptInterfaceComponent.m_Changed = 1;
  v32 = &v2->m_pInterestPointUserComponent;
  if ( v2->m_pInterestPointUserComponent.m_pSimComponent )
  {
    v33 = v32->mPrev;
    v34 = v2->m_pInterestPointUserComponent.mNext;
    v33->mNext = v34;
    v34->mPrev = v33;
    v2->m_pInterestPointUserComponent.m_pSimComponent = 0i64;
LABEL_49:
    v2->m_pInterestPointUserComponent.m_pSimObject = 0i64;
    v2->m_pInterestPointUserComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pInterestPointUserComponent.mPrev;
    v32->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v32->mPrev;
    goto LABEL_50;
  }
  if ( v2->m_pInterestPointUserComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::InterestPointUserComponent,0> *)v32->mPrev != v32
     || (UFG::RebindingComponentHandle<UFG::InterestPointUserComponent,0> *)v2->m_pInterestPointUserComponent.mNext != &v2->m_pInterestPointUserComponent) )
  {
    v35 = v32->mPrev;
    v36 = v2->m_pInterestPointUserComponent.mNext;
    v35->mNext = v36;
    v36->mPrev = v35;
    goto LABEL_49;
  }
LABEL_50:
  v2->m_pInterestPointUserComponent.m_Changed = 1;
  UFG::PedKnowledgeBase::OnDetach(&v2->m_KnowledgeBase);
  UFG::AIEntityComponent::OnDetach((UFG::AIEntityComponent *)&v2->vfptr);
}

// File Line: 621
// RVA: 0x38C890
void __usercall UFG::ActiveAIEntityComponent::Update(UFG::ActiveAIEntityComponent *this@<rcx>, float delta_sec@<xmm1>, hkgpIndexedMeshDefinitions::Edge *a3@<rdx>)
{
  UFG::SimComponent *v3; // rax
  UFG::ActiveAIEntityComponent *v4; // rbx
  float v5; // xmm0_4
  float v6; // xmm0_4
  UFG::SimComponent *v7; // rcx
  UFG::SimComponent *v8; // rdi
  UFG::SimObjectCVBase *v9; // rcx
  unsigned __int16 v10; // dx
  UFG::AICharacterControllerBaseComponent *v11; // rax
  UFG::AICharacterControllerBaseComponent *v12; // rdi
  UFG::eHeadTrackType v13; // eax
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  float *v17; // rsi
  float v18; // xmm2_4
  float v19; // xmm1_4
  UFG::eAIEmotion v20; // ecx

  v3 = this->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent;
  v4 = this;
  if ( v3 )
  {
    v5 = *(float *)&v3[3].m_TypeUID;
    if ( v5 > 0.0 )
    {
      v6 = v5 - delta_sec;
      if ( v6 <= 0.0 )
        v6 = 0.0;
      *(float *)&v3[3].m_TypeUID = v6;
    }
  }
  v7 = this->m_pHealthComponent.m_pSimComponent;
  v8 = v4->m_pAIActionTreeComponent.m_pSimComponent;
  if ( v7
    && BYTE4(v7[1].m_BoundComponentHandles.mNode.mPrev)
    && !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat((hkgpIndexedMesh::EdgeBarrier *)v7, a3) )
  {
    if ( v8 && v8[3].m_pSimObject )
      ((void (__fastcall *)(UFG::SimComponent *))v8->vfptr[18].__vecDelDtor)(v8);
    UFG::ActiveAIEntityComponent::SetCurrentObjective(v4, 0, "<Unknown>");
  }
  else
  {
    v4->m_CurrentEmotion = 0;
    UFG::ActiveAIEntityComponent::UpdateCurrentAttackTarget(v4);
  }
  v9 = (UFG::SimObjectCVBase *)v4->m_pSimObject;
  if ( v9 )
  {
    v10 = v9->m_Flags;
    if ( (v10 >> 14) & 1 )
    {
      v11 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v9);
    }
    else if ( (v10 & 0x8000u) == 0 )
    {
      if ( (v10 >> 13) & 1 )
        v11 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           (UFG::SimObjectGame *)&v9->vfptr,
                                                           UFG::AICharacterControllerBaseComponent::_TypeUID);
      else
        v11 = (UFG::AICharacterControllerBaseComponent *)((v10 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                              (UFG::SimObjectGame *)&v9->vfptr,
                                                                              UFG::AICharacterControllerBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v9->vfptr, UFG::AICharacterControllerBaseComponent::_TypeUID));
    }
    else
    {
      v11 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v9);
    }
    v12 = v11;
    if ( v11 )
    {
      v13 = v4->m_HeadTrackingTarget.m_Type;
      if ( v13 == 1 )
      {
        v14 = v4->m_HeadTrackingTarget.m_Position.y;
        v15 = v4->m_HeadTrackingTarget.m_Position.z;
        v16 = v4->m_HeadTrackingTarget.m_Offset.x + v4->m_HeadTrackingTarget.m_Position.x;
LABEL_30:
        v18 = v15 + v4->m_HeadTrackingTarget.m_Offset.z;
        v19 = v14 + v4->m_HeadTrackingTarget.m_Offset.y;
        v12->m_Intention.mDesiredLookAtPoint.x = v16;
        v12->m_Intention.mDesiredLookAtPoint.y = v19;
        v12->m_Intention.mDesiredLookAtPoint.z = v18;
        v12->m_Intention.mDesireToLookAtPoint = 1;
        v12->m_Intention.mDesiredLookAtPointEye.x = v16;
        v12->m_Intention.mDesiredLookAtPointEye.y = v19;
        v12->m_Intention.mDesiredLookAtPointEye.z = v18;
        v12->m_Intention.mDesireToLookAtPointEye = 1;
        goto LABEL_31;
      }
      if ( v13 == eHEAD_TRACK_TYPE_TRANSFORM_NODE )
      {
        v17 = (float *)v4->m_HeadTrackingTarget.m_pTransformNodeComponent.m_pPointer;
        if ( v17 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v4->m_HeadTrackingTarget.m_pTransformNodeComponent.m_pPointer);
          v14 = v17[45];
          v15 = v17[46];
          v16 = v4->m_HeadTrackingTarget.m_Offset.x + v17[44];
          goto LABEL_30;
        }
      }
    }
  }
LABEL_31:
  if ( v4->m_pAIScriptInterfaceComponent.m_pSimComponent )
  {
    v20 = (UFG::eAIEmotion)v4->m_pAIScriptInterfaceComponent.m_pSimComponent[10].m_BoundComponentHandles.mNode.mNext;
    if ( v20 )
      v4->m_CurrentEmotion = v20;
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
void __fastcall UFG::ActiveAIEntityComponent::SetCurrentObjective(UFG::ActiveAIEntityComponent *this, UFG::eAIObjective objective, const char *caller_debug_name)
{
  __int64 v3; // rsi
  UFG::ActiveAIEntityComponent *v4; // rdi
  UFG::SimObject *v5; // rbx
  UFG::PedSpawnManager *v6; // rax
  UFG::TargetingSystemPedBaseComponent *v7; // rcx

  v3 = objective;
  v4 = this;
  this->m_CurrentObjective = objective;
  UFG::NearbyCharacterManager::RemoveCharacter(
    UFG::NearbyCharacterManager::s_pInstance,
    (UFG::AIEntityComponent *)&this->vfptr);
  UFG::NearbyCharacterManager::AddCharacter(
    UFG::NearbyCharacterManager::s_pInstance,
    (UFG::AIEntityComponent *)&v4->vfptr);
  if ( UFG::g_AIObjectiveParams[v4->m_CurrentObjective].m_IsHostile )
  {
    v5 = v4->m_pSimObject;
    v6 = UFG::PedSpawnManager::GetInstance();
    UFG::PedSpawnManager::SetSuspendOption(v6, v5, NoSuspend);
  }
  v7 = (UFG::TargetingSystemPedBaseComponent *)v4->m_pTargetingSystemBaseComponent.m_pSimComponent;
  if ( v7 )
  {
    if ( UFG::g_AIObjectiveParams[v3].m_IsHostile )
      UFG::TargetingSystemPedBaseComponent::SetToHighFrequencyUpdate(v7);
    else
      UFG::TargetingSystemPedBaseComponent::SetToLowFrequencyUpdate(v7);
    LOBYTE(v4->m_pTargetingSystemBaseComponent.m_pSimComponent[9].vfptr) = 1;
  }
}

// File Line: 765
// RVA: 0x37EA60
UFG::SimComponent *__fastcall UFG::ActiveAIEntityComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *pSceneObj, bool required)
{
  UFG::SceneObjectProperties *v2; // rbx
  UFG::qMemoryPool *v3; // rax
  UFG::allocator::free_link *v4; // rax
  UFG::qPropertySet *v5; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimComponent *v7; // rdi
  UFG::SimObject *v8; // rdx
  unsigned __int16 v9; // cx
  unsigned int v10; // ebx
  UFG::SimObjectModifier v12; // [rsp+38h] [rbp-30h]

  v2 = pSceneObj;
  v3 = UFG::GetSimulationMemoryPool();
  v4 = UFG::qMemoryPool::Allocate(v3, 0x1070ui64, "ActiveAIEntityComponent", 0i64, 1u);
  if ( v4 )
  {
    v5 = v2->mpWritableProperties;
    if ( !v5 )
      v5 = v2->mpConstProperties;
    UFG::ActiveAIEntityComponent::ActiveAIEntityComponent((UFG::ActiveAIEntityComponent *)v4, v2->m_NameUID, v5);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  v8 = v2->m_pSimObject;
  v9 = v8->m_Flags;
  if ( (v9 >> 14) & 1 || (v9 & 0x8000u) != 0 )
    v10 = 22;
  else
    v10 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v12, v8, 1);
  UFG::SimObjectModifier::AttachComponent(&v12, v7, v10);
  UFG::SimObjectModifier::Close(&v12);
  UFG::SimObjectModifier::~SimObjectModifier(&v12);
  return v7;
}

// File Line: 790
// RVA: 0x385000
void __fastcall UFG::ActiveAIEntityComponent::SetBehaviourTree(UFG::ActiveAIEntityComponent *this, const char *behaviour_tree_name)
{
  UFG::ActiveAIEntityComponent *v2; // rbx
  UFG::SimComponent *v3; // rcx
  const char *v4; // rdi

  v2 = this;
  v3 = this->m_pAIActionTreeComponent.m_pSimComponent;
  v4 = behaviour_tree_name;
  if ( v3 )
  {
    ((void (*)(void))v3->vfptr[18].__vecDelDtor)();
    UFG::AIActionTreeComponent::SetActionTreeFileName(
      (UFG::AIActionTreeComponent *)v2->m_pAIActionTreeComponent.m_pSimComponent,
      v4);
    UFG::AIActionTreeComponent::InitActionTree((UFG::AIActionTreeComponent *)v2->m_pAIActionTreeComponent.m_pSimComponent);
  }
}

// File Line: 896
// RVA: 0x3948E0
void __fastcall UFG::ActiveAIEntityComponent::UpdateCurrentAttackTarget(UFG::ActiveAIEntityComponent *this)
{
  UFG::ActiveAIEntityComponent *v1; // rdi
  UFG::SimObjectCharacter *v2; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AttackRightsComponent> *v3; // rdi
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax
  float v6; // xmm8_4
  float v7; // xmm1_4
  bool v8; // al
  UFG::SimComponent *v9; // r8
  UFG::SimObject *v10; // rdx
  UFG::SimComponent *v11; // rcx
  UFG::SimObject *v12; // rcx
  float v13; // xmm6_4
  float v14; // xmm7_4
  float v15; // xmm0_4
  float v16; // xmm6_4
  float v17; // xmm7_4
  float v18; // xmm0_4
  __int64 v19; // rdx
  UFG::SimComponent *v20; // rax
  bool v21; // al
  bool v22; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::AttackRightsComponent> *v23; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v24; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rax
  float v26; // xmm7_4
  UFG::SimObjectGame *v27; // rcx
  UFG::TargetingSystemBaseComponent *v28; // rax
  unsigned __int16 v29; // dx
  bool v30; // r12
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
  __int64 v50; // [rsp+0h] [rbp-88h]
  __int64 v51; // [rsp+20h] [rbp-68h]
  UFG::qList<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList,0,0> list; // [rsp+28h] [rbp-60h]

  v51 = -2i64;
  v1 = this;
  v2 = (UFG::SimObjectCharacter *)this->m_pSimObject;
  if ( v2 && v2 == LocalPlayer )
  {
    v3 = &this->m_pCurrentAttackTarget;
    if ( this->m_pCurrentAttackTarget.m_pPointer )
    {
      v4 = v3->mPrev;
      v5 = v3->mNext;
      v4->mNext = v5;
      v5->mPrev = v4;
      v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
      v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
    }
LABEL_77:
    v3->m_pPointer = 0i64;
    return;
  }
  v6 = UFG::Metrics::msInstance.mSimTime_Temp;
  v7 = this->m_NextTimeToUpdateAttackTarget;
  v8 = UFG::Metrics::msInstance.mSimTime_Temp >= v7;
  if ( this->m_pHitReactionComponent.m_pSimComponent )
  {
    v9 = this->m_pHitReactionComponent.m_pSimComponent;
    v10 = *(UFG::SimObject **)&v9[3].m_TypeUID;
    v11 = this->m_pCurrentAttackTarget.m_pPointer;
    if ( v11 )
      v12 = v11->m_pSimObject;
    else
      v12 = 0i64;
    v8 = UFG::Metrics::msInstance.mSimTime_Temp >= v7
      || v10 && v10 != v12 && *(float *)&v9[3].m_Flags < AttackabilityShared::ms_fMaxTimeSinceLastHitToUpdateTargeting;
  }
  if ( v8 || (float)(UFG::Metrics::msInstance.mSimTime_Temp - v7) > AttackabilityShared::ms_fStarving )
  {
    v13 = v1->m_MaxTimeBetweenUpdateTarget;
    v14 = v1->m_MinTimeBetweenUpdateTarget;
    v15 = v13;
    if ( v13 > v14 )
    {
      v15 = UFG::qRandom(v13 - v14, &UFG::qDefaultSeed) + v14;
      if ( v15 <= v14 )
        v15 = v14;
      if ( v15 >= v13 )
        v15 = v13;
    }
    v1->m_NextTimeToUpdateAttackTarget = v15 + v6;
    v16 = AttackabilityShared::ms_fMaxTimeToKeepAttackingDeadTarget;
    v17 = AttackabilityShared::ms_fMinTimeToKeepAttackingDeadTarget;
    v18 = AttackabilityShared::ms_fMaxTimeToKeepAttackingDeadTarget;
    if ( AttackabilityShared::ms_fMaxTimeToKeepAttackingDeadTarget > AttackabilityShared::ms_fMinTimeToKeepAttackingDeadTarget )
    {
      v18 = UFG::qRandom(
              AttackabilityShared::ms_fMaxTimeToKeepAttackingDeadTarget
            - AttackabilityShared::ms_fMinTimeToKeepAttackingDeadTarget,
              &UFG::qDefaultSeed)
          + v17;
      if ( v18 <= v17 )
        v18 = v17;
      if ( v18 >= v16 )
        v18 = v16;
    }
    v1->m_TimeAllowedToKeepAttackingDeadTarget = v18;
    v19 = v1->m_CurrentObjective;
    v20 = v1->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent;
    v21 = v20 && LODWORD(v20[3].m_SafePointerList.mNode.mPrev) != 17 || UFG::g_AIObjectiveParams[v19].m_IsHostile;
    if ( !v1->m_HostilityEnabled || !v21 || !v1->m_pTransformNodeComponent.m_pSimComponent )
    {
      v3 = &v1->m_pCurrentAttackTarget;
      if ( v3->m_pPointer )
      {
        v48 = v3->mPrev;
        v49 = v3->mNext;
        v48->mNext = v49;
        v49->mPrev = v48;
        v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
        v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
      }
      goto LABEL_77;
    }
    v22 = UFG::g_AIObjectiveParams[v19].m_IsHostile;
    if ( v22 && !v1->m_PrevObjectiveWasHostile )
    {
      v23 = &v1->m_pCurrentAttackTarget;
      if ( v1->m_pCurrentAttackTarget.m_pPointer )
      {
        v24 = v23->mPrev;
        v25 = v1->m_pCurrentAttackTarget.mNext;
        v24->mNext = v25;
        v25->mPrev = v24;
        v23->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v23->mPrev;
        v1->m_pCurrentAttackTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pCurrentAttackTarget.mPrev;
      }
      v1->m_pCurrentAttackTarget.m_pPointer = 0i64;
    }
    v1->m_PrevObjectiveWasHostile = v22;
    v26 = FLOAT_N1_0;
    v27 = (UFG::SimObjectGame *)v1->m_pSimObject;
    if ( v27 )
    {
      v29 = v27->m_Flags;
      if ( (v29 >> 14) & 1 )
      {
        v28 = (UFG::TargetingSystemBaseComponent *)v27->m_Components.p[20].m_pComponent;
      }
      else if ( (v29 & 0x8000u) == 0 )
      {
        if ( (v29 >> 13) & 1 )
        {
          v28 = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       v27,
                                                       UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else if ( (v29 >> 12) & 1 )
        {
          v28 = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       v27,
                                                       UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else
        {
          v28 = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                       (UFG::SimObject *)&v27->vfptr,
                                                       UFG::TargetingSystemBaseComponent::_TypeUID);
        }
      }
      else
      {
        v28 = (UFG::TargetingSystemBaseComponent *)v27->m_Components.p[20].m_pComponent;
      }
    }
    else
    {
      v28 = 0i64;
    }
    v30 = UFG::HasRangedWeaponEquippedWithAmmo(v28);
    v31 = v1->m_pTransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v1->m_pTransformNodeComponent.m_pSimComponent);
    list.mNode.mPrev = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *)&list;
    list.mNode.mNext = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *)&list;
    UFG::NearbyCharacterManager::GetNearbyCharacters(
      UFG::NearbyCharacterManager::s_pInstance,
      &list,
      0,
      (UFG::qVector3 *)&v31[2].m_BoundComponentHandles);
    v32 = 0i64;
    v33 = list.mNode.mNext - 1;
    v34 = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *)(&v50 + 3);
    if ( list.mNode.mNext - 1 != v34 )
    {
      do
      {
        v35 = v33[3].mPrev;
        if ( v35 )
        {
          v36 = (UFG::AttackRightsComponent *)v35[20].mNext;
          v37 = v30 ? UFG::ActiveAIEntityComponent::GetAttackabilityScoreRanged(v1, v36) : UFG::ActiveAIEntityComponent::GetAttackabilityScoreMelee(
                                                                                             v1,
                                                                                             v36);
          if ( v37 >= 0.0 )
            goto LABEL_80;
          if ( v36 == (UFG::AttackRightsComponent *)v1->m_pCurrentAttackTarget.m_pPointer )
          {
            v38 = &v1->m_pCurrentAttackTarget;
            if ( v1->m_pCurrentAttackTarget.m_pPointer )
            {
              v39 = v38->mPrev;
              v40 = v1->m_pCurrentAttackTarget.mNext;
              v39->mNext = v40;
              v40->mPrev = v39;
              v38->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v38->mPrev;
              v1->m_pCurrentAttackTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pCurrentAttackTarget.mPrev;
            }
            v1->m_pCurrentAttackTarget.m_pPointer = 0i64;
          }
          if ( v37 >= 0.0 )
          {
LABEL_80:
            if ( v26 < 0.0 || v37 > v26 )
            {
              v32 = (UFG::SimComponent *)&v36->vfptr;
              v26 = v37;
            }
          }
        }
        v33 = v33[1].mNext - 1;
      }
      while ( v33 != v34 );
      if ( v32 )
      {
        v41 = v1->m_pCurrentAttackTarget.m_pPointer;
        if ( !v41 || v41->m_pSimObject != v32->m_pSimObject )
        {
          UFG::qSafePointer<Creature,Creature>::operator=(
            (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)&v1->m_pCurrentAttackTarget,
            v32);
          if ( v1->m_pTargetingSystemBaseComponent.m_pSimComponent )
            LOBYTE(v1->m_pTargetingSystemBaseComponent.m_pSimComponent[9].vfptr) = 1;
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
float __fastcall UFG::ActiveAIEntityComponent::GetEncounterFocusTargetScore(UFG::ActiveAIEntityComponent *this, UFG::SimObject *pMyself)
{
  UFG::SimObject *v2; // r8
  unsigned __int16 v3; // cx
  UFG::SimComponent *v4; // rax
  __int64 v5; // rbx
  float result; // xmm0_4

  v2 = pMyself;
  if ( pMyself
    && ((v3 = pMyself->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = UFG::SimObject::GetComponentOfType(pMyself, UFG::EncounterUnitComponent::_TypeUID)) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)pMyself, UFG::EncounterUnitComponent::_TypeUID))) : (v4 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)pMyself, UFG::EncounterUnitComponent::_TypeUID))) : (v4 = pMyself->m_Components.p[16].m_pComponent)) : (v4 = pMyself->m_Components.p[16].m_pComponent),
        v4
     && (v5 = *(_QWORD *)&v4[1].m_TypeUID) != 0
     && (*(unsigned __int8 (__fastcall **)(__int64, UFG::SimObject *, UFG::SimObject *))(*(_QWORD *)v5 + 48i64))(
          v5,
          pMyself,
          v2)
     && (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v5 + 144i64))(v5)) )
  {
    result = gs_fEncounterFocusTargetBonus;
  }
  else
  {
    result = 0.0;
  }
  return result;
}

// File Line: 1078
// RVA: 0x35A340
float __fastcall UFG::ActiveAIEntityComponent::GetAttackabilityScoreMelee(UFG::ActiveAIEntityComponent *this, UFG::AttackRightsComponent *potential_attack_target)
{
  UFG::AttackRightsComponent *v2; // rsi
  UFG::ActiveAIEntityComponent *v3; // rdi
  float v4; // xmm6_4
  UFG::SimComponent *v5; // rbp
  float v6; // xmm7_4
  signed int v7; // er14
  int v8; // ebx
  UFG::TransformNodeComponent *v9; // rbx
  UFG::SimComponent *v10; // rbp
  __m128 v11; // xmm1
  UFG::SimComponent *v12; // rbx
  __m128 v13; // xmm1
  float v14; // xmm0_4
  float v15; // xmm7_4
  UFG::SimComponent *v16; // rax
  UFG::SimObject *v17; // rcx
  signed int v18; // ecx
  float v19; // xmm6_4
  UFG::SimObjectCharacter *v20; // rax
  UFG::SimObjectGame *v21; // rcx
  unsigned __int16 v22; // dx
  UFG::SimComponent *v23; // rax
  UFG::qString v25; // [rsp+28h] [rbp-60h]

  v2 = potential_attack_target;
  v3 = this;
  v4 = FLOAT_N1_0;
  if ( UFG::ActiveAIEntityComponent::IsEnemyOfMine(this, potential_attack_target)
    && UFG::ActiveAIEntityComponent::CanBeEngagedMelee(v3, v2) )
  {
    v5 = v3->m_pTransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v3->m_pTransformNodeComponent.m_pSimComponent);
    UFG::qString::qString(&v25);
    v6 = 0.0;
    v7 = 0;
    v8 = 0;
    if ( v3->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent )
      v8 = (int)v3->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent[3].m_SafePointerList.mNode.mPrev;
    if ( UFG::GameStatTracker::Instance()->mFactionInterface.mStandings[v8][2] )
    {
      v12 = v2->m_pTransformNodeComponent.m_pSimComponent;
      if ( v12 && v3->m_pTransformNodeComponent.m_pSimComponent )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v2->m_pTransformNodeComponent.m_pSimComponent);
        v13 = (__m128)LODWORD(v5[2].m_BoundComponentHandles.mNode.mPrev);
        v14 = *((float *)&v5[2].m_BoundComponentHandles.mNode.mPrev + 1)
            - *((float *)&v12[2].m_BoundComponentHandles.mNode.mPrev + 1);
        v13.m128_f32[0] = (float)((float)(v13.m128_f32[0] - *(float *)&v12[2].m_BoundComponentHandles.mNode.mPrev)
                                * (float)(v13.m128_f32[0] - *(float *)&v12[2].m_BoundComponentHandles.mNode.mPrev))
                        + (float)(v14 * v14);
        v15 = v3->m_MaxEngagementDistanceXY - COERCE_FLOAT(_mm_sqrt_ps(v13));
        if ( v15 <= 0.0 )
          v15 = 0.0;
        v6 = v15 * AttackabilityMelee::ms_fScoreDistanceScale;
      }
    }
    else
    {
      if ( LocalPlayer )
        v9 = LocalPlayer->m_pTransformNodeComponent;
      else
        v9 = 0i64;
      v10 = v2->m_pTransformNodeComponent.m_pSimComponent;
      if ( v9 && v10 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v2->m_pTransformNodeComponent.m_pSimComponent);
        UFG::TransformNodeComponent::UpdateWorldTransform(v9);
        v11 = (__m128)LODWORD(v10[2].m_BoundComponentHandles.mNode.mPrev);
        v11.m128_f32[0] = (float)((float)(v11.m128_f32[0] - v9->mWorldTransform.v3.x)
                                * (float)(v11.m128_f32[0] - v9->mWorldTransform.v3.x))
                        + (float)((float)(*((float *)&v10[2].m_BoundComponentHandles.mNode.mPrev + 1)
                                        - v9->mWorldTransform.v3.y)
                                * (float)(*((float *)&v10[2].m_BoundComponentHandles.mNode.mPrev + 1)
                                        - v9->mWorldTransform.v3.y));
        LODWORD(v6) = (unsigned __int128)_mm_sqrt_ps(v11);
      }
    }
    if ( v3->m_pHitReactionComponent.m_pSimComponent )
    {
      v16 = v3->m_pHitReactionComponent.m_pSimComponent;
      v17 = *(UFG::SimObject **)&v16[3].m_TypeUID;
      if ( v17 )
      {
        if ( v17 == v2->m_pSimObject && *(float *)&v16[3].m_Flags < AttackabilityMelee::ms_fMaxTimeSinceLastHitForBonus )
          v6 = v6 + AttackabilityMelee::ms_fScoreLastAttackerBonus;
      }
    }
    v18 = AttackabilityMelee::ms_iScoreMaxAttackers
        - (unsigned __int64)UFG::AttackRightsComponent::CountNumDistinctAttackers(v2, v3->m_pSimObject);
    if ( v18 > 0 )
      v7 = v18;
    v19 = (float)v7 * AttackabilityMelee::ms_fScoreNumFreeSlotsScale;
    v4 = (float)(v19 + v6) + UFG::ActiveAIEntityComponent::GetEncounterFocusTargetScore(v3, v3->m_pSimObject);
    if ( UFG::ActiveAIEntityComponent::IsSupplementaryAttackTarget(v3, v2) )
      v4 = v4 + AttackabilityMelee::ms_fScoreScriptedBonus;
    v20 = (UFG::SimObjectCharacter *)v2->m_pSimObject;
    if ( v20 && v20 == LocalPlayer )
      v4 = v4 + AttackabilityMelee::ms_fScorePlayerBonus;
    if ( v3->m_pCharacterOccupantComponent.m_pSimComponent && v2->m_pCharacterOccupantComponent.m_pSimComponent )
      v4 = v4 + AttackabilityMelee::ms_fScoreVehicleContextBonus;
    if ( v2 == (UFG::AttackRightsComponent *)v3->m_pCurrentAttackTarget.m_pPointer )
      v4 = v4 + AttackabilityMelee::ms_fScoreHysteresis;
    v21 = (UFG::SimObjectGame *)v3->m_pSimObject;
    if ( v21 )
    {
      v22 = v21->m_Flags;
      if ( (v22 >> 14) & 1 )
      {
        v23 = v21->m_Components.p[3].m_pComponent;
      }
      else if ( (v22 & 0x8000u) == 0 )
      {
        if ( (v22 >> 13) & 1 )
        {
          v23 = v21->m_Components.p[4].m_pComponent;
        }
        else if ( (v22 >> 12) & 1 )
        {
          v23 = UFG::SimObjectGame::GetComponentOfTypeHK(v21, UFG::SimObjectPropertiesComponent::_TypeUID);
        }
        else
        {
          v23 = UFG::SimObject::GetComponentOfType(
                  (UFG::SimObject *)&v21->vfptr,
                  UFG::SimObjectPropertiesComponent::_TypeUID);
        }
      }
      else
      {
        v23 = v21->m_Components.p[3].m_pComponent;
      }
      if ( v23
        && LODWORD(v23[1].m_SafePointerList.mNode.mNext) == 1
        && BYTE3(v23[2].m_BoundComponentHandles.mNode.mPrev) )
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
float __fastcall UFG::ActiveAIEntityComponent::GetAttackabilityScoreRanged(UFG::ActiveAIEntityComponent *this, UFG::AttackRightsComponent *potential_attack_target)
{
  UFG::AttackRightsComponent *v2; // rbp
  UFG::ActiveAIEntityComponent *v3; // rsi
  float v4; // xmm6_4
  UFG::SimComponent *v5; // rdi
  float v6; // xmm7_4
  UFG::SimComponent *v7; // rbx
  __m128 v8; // xmm1
  float v9; // xmm0_4
  UFG::SimComponent *v10; // rax
  UFG::SimObject *v11; // rcx
  UFG::SimObjectGame *v12; // rcx
  unsigned __int16 v13; // dx
  UFG::SimComponent *v14; // rax
  UFG::SimObject *v15; // rcx
  signed __int64 v16; // rcx
  UFG::SimObject *v17; // r12
  float v18; // xmm7_4
  UFG::SimObjectGame *v19; // rcx
  int v20; // edi
  UFG::SimComponent *v21; // rax
  unsigned __int16 v22; // dx
  int v23; // er14
  UFG::TargetingSimObject *v24; // rbx
  signed __int64 i; // r15
  UFG::SimObjectCVBase *v26; // rax
  unsigned __int16 v27; // dx
  UFG::ActiveAIEntityComponent *v28; // rax
  int v29; // eax
  float v30; // xmm6_4
  UFG::SimObjectCharacter *v31; // rax
  unsigned int v32; // edx
  UFG::PedKnowledgeRecord *v33; // rcx
  float v34; // xmm0_4
  UFG::SimObjectGame *v35; // rcx
  unsigned __int16 v36; // dx
  UFG::SimComponent *v37; // rax
  UFG::qString v39; // [rsp+28h] [rbp-70h]

  v2 = potential_attack_target;
  v3 = this;
  v4 = FLOAT_N1_0;
  if ( !UFG::ActiveAIEntityComponent::IsEnemyOfMine(this, potential_attack_target)
    || !v2
    || !UFG::ActiveAIEntityComponent::CanBeEngagedShared(v3, v2) )
  {
    return v4;
  }
  v5 = v3->m_pTransformNodeComponent.m_pSimComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v3->m_pTransformNodeComponent.m_pSimComponent);
  UFG::qString::qString(&v39);
  v6 = 0.0;
  v7 = v2->m_pTransformNodeComponent.m_pSimComponent;
  if ( v7 && v3->m_pTransformNodeComponent.m_pSimComponent )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v2->m_pTransformNodeComponent.m_pSimComponent);
    v8 = (__m128)LODWORD(v5[2].m_BoundComponentHandles.mNode.mPrev);
    v9 = *((float *)&v5[2].m_BoundComponentHandles.mNode.mPrev + 1)
       - *((float *)&v7[2].m_BoundComponentHandles.mNode.mPrev + 1);
    v8.m128_f32[0] = (float)((float)(v8.m128_f32[0] - *(float *)&v7[2].m_BoundComponentHandles.mNode.mPrev)
                           * (float)(v8.m128_f32[0] - *(float *)&v7[2].m_BoundComponentHandles.mNode.mPrev))
                   + (float)(v9 * v9);
    v6 = AttackabilityRanged::ms_fDistanceDividend / COERCE_FLOAT(_mm_sqrt_ps(v8));
  }
  if ( v3->m_pHitReactionComponent.m_pSimComponent )
  {
    v10 = v3->m_pHitReactionComponent.m_pSimComponent;
    v11 = *(UFG::SimObject **)&v10[3].m_TypeUID;
    if ( v11 )
    {
      if ( v11 == v2->m_pSimObject && *(float *)&v10[3].m_Flags < AttackabilityRanged::ms_fMaxTimeSinceLastHitForBonus )
        v6 = v6 + AttackabilityRanged::ms_fScoreLastAttackerBonus;
    }
  }
  v12 = (UFG::SimObjectGame *)v3->m_pSimObject;
  if ( v12 )
  {
    v13 = v12->m_Flags;
    if ( (v13 >> 14) & 1 )
    {
      v14 = v12->m_Components.p[11].m_pComponent;
    }
    else if ( (v13 & 0x8000u) == 0 )
    {
      if ( (v13 >> 13) & 1 )
        v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::StimulusReceiverComponent::_TypeUID);
      else
        v14 = (v13 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::StimulusReceiverComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v12->vfptr, UFG::StimulusReceiverComponent::_TypeUID);
    }
    else
    {
      v14 = v12->m_Components.p[11].m_pComponent;
    }
    if ( v14 )
    {
      v15 = v14[3].m_pSimObject;
      if ( v15 )
      {
        v16 = (signed __int64)&v15->m_SafePointerWithCallbackList.mNode.mNext;
        if ( v16 )
        {
          if ( *(UFG::SimObject **)(v16 + 24) == v2->m_pSimObject
            && (float)(UFG::Metrics::msInstance.mSimTime_Temp - *(float *)v16) < AttackabilityRanged::ms_fMaxTimeSinceLastShotAtForBonus )
          {
            v6 = v6 + AttackabilityRanged::ms_fScoreLastShotAtBonus;
          }
        }
      }
    }
  }
  v17 = v3->m_pSimObject;
  v18 = v6 + UFG::ActiveAIEntityComponent::GetEncounterFocusTargetScore(v3, v3->m_pSimObject);
  v19 = (UFG::SimObjectGame *)v2->m_pSimObject;
  v20 = 0;
  if ( v19 )
  {
    v22 = v19->m_Flags;
    if ( (v22 >> 14) & 1 )
    {
      v21 = v19->m_Components.p[20].m_pComponent;
    }
    else if ( (v22 & 0x8000u) == 0 )
    {
      if ( (v22 >> 13) & 1 )
      {
        v21 = UFG::SimObjectGame::GetComponentOfTypeHK(v19, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v22 >> 12) & 1 )
      {
        v21 = UFG::SimObjectGame::GetComponentOfTypeHK(v19, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v21 = UFG::SimObject::GetComponentOfType(
                (UFG::SimObject *)&v19->vfptr,
                UFG::TargetingSystemBaseComponent::_TypeUID);
      }
    }
    else
    {
      v21 = v19->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    v21 = 0i64;
  }
  v23 = 0;
  if ( v21 )
  {
    v24 = (UFG::TargetingSimObject *)v21[1].m_BoundComponentHandles.mNode.mPrev;
    for ( i = (signed __int64)&v21[1].m_pSimObject;
          v24 != (UFG::TargetingSimObject *)i;
          v24 = (UFG::TargetingSimObject *)v24->mNext )
    {
      if ( v24->m_eTargetType.mValue == 22 )
      {
        v26 = (UFG::SimObjectCVBase *)UFG::TargetingSimObject::GetOwner(v24);
        if ( v26 )
        {
          if ( v26 != (UFG::SimObjectCVBase *)v17 )
          {
            v27 = v26->m_Flags;
            if ( (v27 >> 14) & 1 )
            {
              v28 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v26);
            }
            else if ( (v27 & 0x8000u) == 0 )
            {
              if ( (v27 >> 13) & 1 )
                v28 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        (UFG::SimObjectGame *)&v26->vfptr,
                                                        UFG::ActiveAIEntityComponent::_TypeUID);
              else
                v28 = (UFG::ActiveAIEntityComponent *)((v27 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                           (UFG::SimObjectGame *)&v26->vfptr,
                                                                           UFG::ActiveAIEntityComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v26->vfptr, UFG::ActiveAIEntityComponent::_TypeUID));
            }
            else
            {
              v28 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v26);
            }
            if ( v28 && UFG::g_AIObjectiveParams[v28->m_CurrentObjective].m_IsHostile )
              ++v23;
          }
        }
      }
    }
  }
  v29 = 0;
  if ( AttackabilityRanged::ms_iScoreMaxAttackers - v23 > 0 )
    v29 = AttackabilityRanged::ms_iScoreMaxAttackers - v23;
  v30 = (float)v29 * AttackabilityRanged::ms_fScoreNumFreeSlotsScale;
  v4 = (float)(v30 + v18) + UFG::ActiveAIEntityComponent::GetEncounterFocusTargetScore(v3, v17);
  if ( UFG::ActiveAIEntityComponent::IsSupplementaryAttackTarget(v3, v2) )
    v4 = v4 + AttackabilityRanged::ms_fScoreScriptedBonus;
  v31 = (UFG::SimObjectCharacter *)v2->m_pSimObject;
  if ( v31 && v31 == LocalPlayer )
    v4 = v4 + AttackabilityRanged::ms_fScorePlayerBonus;
  if ( v3->m_pCharacterOccupantComponent.m_pSimComponent && v2->m_pCharacterOccupantComponent.m_pSimComponent )
    v4 = v4 + AttackabilityRanged::ms_fScoreVehicleContextBonus;
  v32 = v3->m_KnowledgeBase.m_aHostilePedRecords.size;
  if ( v32 )
  {
    do
    {
      v33 = &v3->m_KnowledgeBase.m_aHostilePedRecords.p[v20];
      if ( v31 == (UFG::SimObjectCharacter *)v33->pSimObject.m_pPointer )
        goto LABEL_71;
    }
    while ( ++v20 < v32 );
  }
  v33 = &UFG::PedKnowledgeBase::ms_defaultKnowledgeRecord;
  if ( v31 == (UFG::SimObjectCharacter *)UFG::PedKnowledgeBase::ms_defaultKnowledgeRecord.pSimObject.m_pPointer )
  {
LABEL_71:
    if ( *((_BYTE *)v33 + 48) & 1 )
      goto LABEL_96;
    v34 = (float)(LODWORD(UFG::Metrics::msInstance.mSimTimeMSec) - LODWORD(v33->m_uLastTimeSeen));
    if ( (signed __int64)(UFG::Metrics::msInstance.mSimTimeMSec - v33->m_uLastTimeSeen) < 0 )
      v34 = v34 + 1.8446744e19;
    if ( (float)(v34 * 0.001) < AttackabilityRanged::ms_fMaxTimeSinceLastSeenForBonus )
LABEL_96:
      v4 = v4 + AttackabilityRanged::ms_fScoreVisible;
  }
  if ( v2 == (UFG::AttackRightsComponent *)v3->m_pCurrentAttackTarget.m_pPointer )
    v4 = v4 + AttackabilityRanged::ms_fScoreHysteresis;
  v35 = (UFG::SimObjectGame *)v3->m_pSimObject;
  if ( v35 )
  {
    v36 = v35->m_Flags;
    if ( (v36 >> 14) & 1 )
    {
      v37 = v35->m_Components.p[3].m_pComponent;
    }
    else if ( (v36 & 0x8000u) == 0 )
    {
      if ( (v36 >> 13) & 1 )
      {
        v37 = v35->m_Components.p[4].m_pComponent;
      }
      else if ( (v36 >> 12) & 1 )
      {
        v37 = UFG::SimObjectGame::GetComponentOfTypeHK(v35, UFG::SimObjectPropertiesComponent::_TypeUID);
      }
      else
      {
        v37 = UFG::SimObject::GetComponentOfType(
                (UFG::SimObject *)&v35->vfptr,
                UFG::SimObjectPropertiesComponent::_TypeUID);
      }
    }
    else
    {
      v37 = v35->m_Components.p[3].m_pComponent;
    }
    if ( v37 && LODWORD(v37[1].m_SafePointerList.mNode.mNext) == 1 && BYTE3(v37[2].m_BoundComponentHandles.mNode.mPrev) )
      v4 = 0.0;
  }
  UFG::qString::~qString(&v39);
  return v4;
}

// File Line: 1595
// RVA: 0x36BBB0
char __fastcall UFG::ActiveAIEntityComponent::IsSupplementaryAttackTarget(UFG::ActiveAIEntityComponent *this, UFG::AttackRightsComponent *potential_attack_target)
{
  UFG::AttackRightsComponent *v2; // rsi
  UFG::ActiveAIEntityComponent *v3; // r9
  UFG::qList<UFG::SupplementaryAttackTarget,UFG::SupplementaryAttackTarget,1,0> *v4; // rdi
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rbx
  UFG::AttackRightsComponent *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rdx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rax

  v2 = potential_attack_target;
  v3 = (UFG::ActiveAIEntityComponent *)this->m_SupplementaryAttackTargets.mNode.mNext;
  v4 = &this->m_SupplementaryAttackTargets;
  if ( v3 != (UFG::ActiveAIEntityComponent *)&this->m_SupplementaryAttackTargets )
  {
    do
    {
      v5 = v3->m_SafePointerList.mNode.mPrev;
      v6 = *(UFG::AttackRightsComponent **)&v3->m_Flags;
      if ( v6 )
      {
        if ( v2 == v6 )
          return 1;
      }
      else
      {
        v7 = &v3->m_SafePointerList.mNode.mNext;
        if ( *(_QWORD *)&v3->m_Flags )
        {
          v8 = *v7;
          v9 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **)&v3->m_TypeUID;
          v8->mNext = v9;
          v9->mPrev = v8;
          *v7 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v7;
          *(_QWORD *)&v3->m_TypeUID = (char *)v3 + 16;
        }
        *(_QWORD *)&v3->m_Flags = 0i64;
        v10 = *v7;
        v11 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **)&v3->m_TypeUID;
        v10->mNext = v11;
        v11->mPrev = v10;
        *v7 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v7;
        *(_QWORD *)&v3->m_TypeUID = (char *)v3 + 16;
        v12 = v3->vfptr;
        v13 = v3->m_SafePointerList.mNode.mPrev;
        v12[1].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))v13;
        v13->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v12;
        v3->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)v3;
        v3->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v3;
        operator delete[](v3);
      }
      v3 = (UFG::ActiveAIEntityComponent *)v5;
    }
    while ( v5 != (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v4 );
  }
  return 0;
}

// File Line: 1627
// RVA: 0x340E10
void __fastcall UFG::ActiveAIEntityComponent::AddSupplementaryAttackTarget(UFG::ActiveAIEntityComponent *this, UFG::SimObject *attack_target)
{
  UFG::SimObjectGame *v2; // r8
  UFG::ActiveAIEntityComponent *v3; // rdi
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rbx
  UFG::SimComponent *v6; // rax
  bool v7; // cl
  UFG::qNode<UFG::SupplementaryAttackTarget,UFG::SupplementaryAttackTarget> *v8; // rax
  UFG::qList<UFG::SupplementaryAttackTarget,UFG::SupplementaryAttackTarget,1,0> *v9; // rdi
  UFG::allocator::free_link *v10; // rax
  UFG::allocator::free_link *v11; // rdx
  UFG::allocator::free_link *v12; // r8
  UFG::allocator::free_link *v13; // rcx
  UFG::allocator::free_link *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::allocator::free_link *v16; // rax
  UFG::allocator::free_link *v17; // [rsp+50h] [rbp+18h]

  if ( attack_target )
  {
    v2 = (UFG::SimObjectGame *)attack_target;
    v3 = this;
    v4 = attack_target->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = v2->m_Components.p[46].m_pComponent;
    }
    else
    {
      if ( (v4 & 0x8000u) == 0 )
      {
        if ( (v4 >> 13) & 1 )
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AttackRightsComponent::_TypeUID);
        else
          v6 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AttackRightsComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::AttackRightsComponent::_TypeUID);
      }
      else
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AttackRightsComponent::_TypeUID);
      }
      v5 = v6;
    }
    if ( v5 )
    {
      v7 = 0;
      v8 = v3->m_SupplementaryAttackTargets.mNode.mNext;
      v9 = &v3->m_SupplementaryAttackTargets;
      if ( v8 == (UFG::qNode<UFG::SupplementaryAttackTarget,UFG::SupplementaryAttackTarget> *)v9 )
      {
LABEL_17:
        v10 = UFG::qMalloc(0x28ui64, "SupplementaryAttackTarget", 0i64);
        v11 = v10;
        if ( v10 )
        {
          v10->mNext = v10;
          v10[1].mNext = v10;
          v17 = v10 + 2;
          v17->mNext = v17;
          v17[1].mNext = v17;
          v10[4].mNext = 0i64;
        }
        else
        {
          v11 = 0i64;
        }
        v12 = v11 + 2;
        if ( v11[4].mNext )
        {
          v13 = v12->mNext;
          v14 = v11[3].mNext;
          v13[1].mNext = v14;
          v14->mNext = v13;
          v12->mNext = v12;
          v11[3].mNext = v11 + 2;
        }
        v11[4].mNext = (UFG::allocator::free_link *)v5;
        v15 = v5->m_SafePointerList.mNode.mPrev;
        v15->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v12;
        v12->mNext = (UFG::allocator::free_link *)v15;
        v11[3].mNext = (UFG::allocator::free_link *)&v5->m_SafePointerList;
        v5->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v12;
        v16 = (UFG::allocator::free_link *)v9->mNode.mPrev;
        v16[1].mNext = v11;
        v11->mNext = v16;
        v11[1].mNext = (UFG::allocator::free_link *)v9;
        v9->mNode.mPrev = (UFG::qNode<UFG::SupplementaryAttackTarget,UFG::SupplementaryAttackTarget> *)v11;
      }
      else
      {
        while ( !v7 )
        {
          v7 = v5 == (UFG::SimComponent *)v8[2].mPrev;
          v8 = v8->mNext;
          if ( v8 == (UFG::qNode<UFG::SupplementaryAttackTarget,UFG::SupplementaryAttackTarget> *)v9 )
          {
            if ( v7 )
              return;
            goto LABEL_17;
          }
        }
      }
    }
  }
}

// File Line: 1662
// RVA: 0x3814A0
void __fastcall UFG::ActiveAIEntityComponent::RemoveSupplementaryAttackTarget(UFG::ActiveAIEntityComponent *this, UFG::SimObject *attack_target)
{
  UFG::SimObjectGame *v2; // r8
  unsigned __int16 v3; // dx
  UFG::ActiveAIEntityComponent *v4; // rbp
  UFG::SimComponent *v5; // rsi
  UFG::SimComponent *v6; // rax
  UFG::CollisionMeshData::DeferredBreakablePartsMark *v7; // rbx
  signed __int64 v8; // rbp
  UFG::SimComponent *v9; // rax
  UFG::CollisionMeshData::DeferredBreakablePartsMark *v10; // rdi

  if ( attack_target )
  {
    v2 = (UFG::SimObjectGame *)attack_target;
    v3 = attack_target->m_Flags;
    v4 = this;
    if ( (v3 >> 14) & 1 )
    {
      v5 = v2->m_Components.p[46].m_pComponent;
    }
    else
    {
      if ( (v3 & 0x8000u) == 0 )
      {
        if ( (v3 >> 13) & 1 )
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AttackRightsComponent::_TypeUID);
        else
          v6 = (v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AttackRightsComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::AttackRightsComponent::_TypeUID);
      }
      else
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AttackRightsComponent::_TypeUID);
      }
      v5 = v6;
    }
    if ( v5 )
    {
      v7 = (UFG::CollisionMeshData::DeferredBreakablePartsMark *)v4->m_SupplementaryAttackTargets.mNode.mNext;
      v8 = (signed __int64)&v4->m_SupplementaryAttackTargets;
      if ( v7 != (UFG::CollisionMeshData::DeferredBreakablePartsMark *)v8 )
      {
        do
        {
          v9 = v7->rigidBody.m_pPointer;
          v10 = (UFG::CollisionMeshData::DeferredBreakablePartsMark *)v7->mNext;
          if ( v9 )
          {
            if ( v5 == v9 )
            {
              UFG::SupplementaryAttackTarget::~SupplementaryAttackTarget(v7);
              operator delete[](v7);
              return;
            }
          }
          else
          {
            UFG::SupplementaryAttackTarget::~SupplementaryAttackTarget(v7);
            operator delete[](v7);
          }
          v7 = v10;
        }
        while ( v10 != (UFG::CollisionMeshData::DeferredBreakablePartsMark *)v8 );
      }
    }
  }
}

// File Line: 1705
// RVA: 0x36A740
bool __fastcall UFG::ActiveAIEntityComponent::IsEnemyOfMine(UFG::ActiveAIEntityComponent *this, UFG::SimObject *pSimObject)
{
  UFG::SimObjectGame *v2; // r8
  UFG::ActiveAIEntityComponent *v3; // rbx
  unsigned __int16 v4; // dx
  UFG::AttackRightsComponent *v5; // rax
  bool result; // al

  v2 = (UFG::SimObjectGame *)pSimObject;
  v3 = this;
  if ( pSimObject
    && ((v4 = pSimObject->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = (UFG::AttackRightsComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::AttackRightsComponent::_TypeUID)) : (v5 = (UFG::AttackRightsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AttackRightsComponent::_TypeUID))) : (v5 = (UFG::AttackRightsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AttackRightsComponent::_TypeUID))) : (v5 = (UFG::AttackRightsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AttackRightsComponent::_TypeUID))) : (v5 = (UFG::AttackRightsComponent *)v2->m_Components.p[46].m_pComponent),
        v5) )
  {
    result = UFG::ActiveAIEntityComponent::IsEnemyOfMine(v3, v5);
  }
  else
  {
    result = 0;
  }
  return result;
}

// File Line: 1717
// RVA: 0x36A690
bool __fastcall UFG::ActiveAIEntityComponent::IsEnemyOfMine(UFG::ActiveAIEntityComponent *this, UFG::AttackRightsComponent *potential_attack_target)
{
  UFG::AttackRightsComponent *v2; // rsi
  UFG::ActiveAIEntityComponent *v3; // rbp
  UFG::SimObjectCharacterPropertiesComponent *m_Properties; // rcx
  UFG::ActiveAIEntityComponent *v5; // rax
  UFG::SimObjectCharacterPropertiesComponent *m_PotentialAttackProperties; // rdx
  __int64 v7; // rbx
  __int64 v8; // rdi

  v2 = potential_attack_target;
  v3 = this;
  if ( !potential_attack_target )
    return 0;
  m_Properties = (UFG::SimObjectCharacterPropertiesComponent *)this->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent;
  v5 = (UFG::ActiveAIEntityComponent *)potential_attack_target->m_pAIEntityComponent.m_pSimComponent;
  if ( !m_Properties )
    return 0;
  if ( !v5 )
    return 0;
  m_PotentialAttackProperties = (UFG::SimObjectCharacterPropertiesComponent *)v5->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent;
  if ( !m_PotentialAttackProperties )
    return 0;
  v7 = m_Properties->m_eFactionClass;
  v8 = m_PotentialAttackProperties->m_eFactionClass;
  return UFG::GameStatTracker::Instance()->mFactionInterface.mStandings[0][v8 + 39 * v7] == 2
      || UFG::ActiveAIEntityComponent::IsSupplementaryAttackTarget(v3, v2);
}

// File Line: 1737
// RVA: 0x34BEE0
char __fastcall UFG::ActiveAIEntityComponent::CanBeEngagedShared(UFG::ActiveAIEntityComponent *this, UFG::AttackRightsComponent *potential_attack_target)
{
  UFG::SimComponent *v2; // rax
  UFG::TransformNodeComponent *v3; // rsi
  UFG::ActiveAIEntityComponent *v4; // rdi
  UFG::SimComponent *v5; // rcx
  UFG::AttackRightsComponent *v6; // r9
  UFG::SimObjectCharacter *v7; // rdx
  float v8; // xmm0_4
  UFG::eTargetTypeEnum v10; // eax
  __int64 v11; // rbx
  __int64 v12; // rbx
  float v13; // xmm6_4
  __m128 v14; // xmm1
  float v15; // xmm0_4
  UFG::SimComponent *v16; // rbx
  float v17; // xmm2_4
  __m128 v18; // xmm1

  v2 = potential_attack_target->m_pHealthComponent.m_pSimComponent;
  v3 = (UFG::TransformNodeComponent *)potential_attack_target->m_pTransformNodeComponent.m_pSimComponent;
  v4 = this;
  v5 = potential_attack_target->m_pAIScriptInterfaceComponent.m_pSimComponent;
  v6 = potential_attack_target;
  if ( v2 && BYTE4(v2[1].m_BoundComponentHandles.mNode.mPrev) )
  {
    v7 = (UFG::SimObjectCharacter *)potential_attack_target->m_pSimObject;
    v8 = v4->m_TimeAllowedToKeepAttackingDeadTarget;
    if ( v7 && v7 == LocalPlayer )
      v8 = v8 + AttackabilityShared::ms_fExtraTimeToKeepAttackingDeadPlayer;
    if ( (float)(UFG::Metrics::msInstance.mSimTime_Temp - *(float *)&v2[3].m_pSimObject) >= v8 )
      return 0;
  }
  if ( v5 && (_QWORD)v5[32].m_BoundComponentHandles.mNode.mPrev & 0x20 )
    return 0;
  v10 = v4->m_TargetToStayNear;
  if ( v10 && v4->m_pTargetingSystemBaseComponent.m_pSimComponent )
  {
    if ( !v3 )
      return 1;
    v11 = *(_QWORD *)(56i64
                    * *(unsigned __int8 *)(*(_QWORD *)&v4->m_pTargetingSystemBaseComponent.m_pSimComponent[1].m_Flags
                                         + (unsigned int)v10
                                         + 8i64)
                    + *(_QWORD *)&v4->m_pTargetingSystemBaseComponent.m_pSimComponent[1].m_TypeUID
                    + 40);
    if ( v11 )
    {
      v12 = *(_QWORD *)(v11 + 88);
      if ( v12 )
      {
        v13 = v4->m_MaxDistanceFromTargetToStayNear;
        if ( v6 == (UFG::AttackRightsComponent *)v4->m_pCurrentAttackTarget.m_pPointer )
          v13 = v13 + v4->m_MaxDistanceFromTargetToStayNearHysteresis;
        UFG::TransformNodeComponent::UpdateWorldTransform(v3);
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v12);
        v14 = (__m128)*(unsigned int *)(v12 + 180);
        v15 = *(float *)(v12 + 176) - v3->mWorldTransform.v3.x;
        v14.m128_f32[0] = (float)((float)(v14.m128_f32[0] - v3->mWorldTransform.v3.y)
                                * (float)(v14.m128_f32[0] - v3->mWorldTransform.v3.y))
                        + (float)(v15 * v15);
        if ( COERCE_FLOAT(_mm_sqrt_ps(v14)) > v13 )
          return 0;
      }
    }
  }
  if ( v3 )
  {
    if ( v4->m_pTransformNodeComponent.m_pSimComponent )
    {
      v16 = v4->m_pTransformNodeComponent.m_pSimComponent;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v4->m_pTransformNodeComponent.m_pSimComponent);
      UFG::TransformNodeComponent::UpdateWorldTransform(v3);
      v18 = (__m128)HIDWORD(v16[2].m_BoundComponentHandles.mNode.mPrev);
      v18.m128_f32[0] = v18.m128_f32[0] - v3->mWorldTransform.v3.y;
      if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)&v16[2].m_BoundComponentHandles.mNode.mNext - v3->mWorldTransform.v3.z) & _xmm) >= v4->m_MaxEngagementDistanceZ )
        return 0;
      v17 = *(float *)&v16[2].m_BoundComponentHandles.mNode.mPrev - v3->mWorldTransform.v3.x;
      v18.m128_f32[0] = (float)(v18.m128_f32[0] * v18.m128_f32[0]) + (float)(v17 * v17);
      if ( COERCE_FLOAT(_mm_sqrt_ps(v18)) >= v4->m_MaxEngagementDistanceXY
        && !v4->m_EngagementOverrideEnabled
        && v4->m_CurrentObjective != 1 )
      {
        return 0;
      }
    }
  }
  return 1;
}

// File Line: 1822
// RVA: 0x34BCA0
char __fastcall UFG::ActiveAIEntityComponent::CanBeEngagedMelee(UFG::ActiveAIEntityComponent *this, UFG::AttackRightsComponent *potential_attack_target)
{
  UFG::AttackRightsComponent *v2; // rsi
  UFG::ActiveAIEntityComponent *v3; // rbx
  char result; // al
  UFG::SimComponent *v5; // rax
  __int64 v6; // rbx
  UFG::SimObjectCharacter *v7; // rdi
  unsigned __int16 v8; // cx
  UFG::SimComponent *v9; // rdx
  UFG::SimComponent *v10; // rax
  UFG::SimObjectGame *v11; // rbx
  unsigned __int16 v12; // cx
  UFG::SimComponent *v13; // rsi
  UFG::SimComponent *v14; // rax
  unsigned __int16 v15; // cx
  UFG::SimComponent *v16; // rdx
  UFG::SimComponent *v17; // rax

  v2 = potential_attack_target;
  v3 = this;
  if ( !potential_attack_target || !UFG::ActiveAIEntityComponent::CanBeEngagedShared(this, potential_attack_target) )
    return 0;
  v5 = v3->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent;
  if ( !v5 )
    goto LABEL_48;
  v6 = SLODWORD(v5[3].m_SafePointerList.mNode.mPrev);
  if ( UFG::GameStatTracker::Instance()->mFactionInterface.mStandings[v6][2] != 0 )
    goto LABEL_48;
  v7 = LocalPlayer;
  if ( !LocalPlayer )
    goto LABEL_48;
  v8 = LocalPlayer->m_Flags;
  if ( (v8 >> 14) & 1 )
  {
    v9 = LocalPlayer->m_Components.p[20].m_pComponent;
  }
  else if ( (v8 & 0x8000u) == 0 )
  {
    if ( (v8 >> 13) & 1 )
      v10 = UFG::SimObjectGame::GetComponentOfTypeHK(
              (UFG::SimObjectGame *)&LocalPlayer->vfptr,
              UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v10 = (v8 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                               (UFG::SimObjectGame *)&LocalPlayer->vfptr,
                               UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                (UFG::SimObject *)&LocalPlayer->vfptr,
                                                                                UFG::TargetingSystemBaseComponent::_TypeUID);
    v9 = v10;
  }
  else
  {
    v9 = LocalPlayer->m_Components.p[20].m_pComponent;
  }
  if ( v9
    && (v11 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v9[1].m_Flags + 30i64)
                                     + *(_QWORD *)&v9[1].m_TypeUID
                                     + 40)) != 0i64
    && v11 == (UFG::SimObjectGame *)v2->m_pSimObject
    && ((v12 = v11->m_Flags, !((v12 >> 14) & 1)) ? ((v12 & 0x8000u) == 0 ? (!((v12 >> 13) & 1) ? (!((v12 >> 12) & 1) ? (v14 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v11->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID)) : (v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::TargetingSystemBaseComponent::_TypeUID))) : (v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::TargetingSystemBaseComponent::_TypeUID)),
                                                                            v13 = v14) : (v13 = v11->m_Components.p[20].m_pComponent)) : (v13 = v11->m_Components.p[20].m_pComponent),
        (v15 = v11->m_Flags, !((v15 >> 14) & 1)) ? ((v15 & 0x8000u) == 0 ? (!((v15 >> 13) & 1) ? (!((v15 >> 12) & 1) ? (v17 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v11->vfptr, UFG::HitReactionComponent::_TypeUID)) : (v17 = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::HitReactionComponent::_TypeUID))) : (v17 = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::HitReactionComponent::_TypeUID)),
                                                                            v16 = v17) : (v16 = v11->m_Components.p[15].m_pComponent)) : (v16 = v11->m_Components.p[15].m_pComponent),
        v13
     && v16
     && *(UFG::SimObjectCharacter **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v13[1].m_Flags + 10i64)
                                    + *(_QWORD *)&v13[1].m_TypeUID
                                    + 40) == v7
     && *(float *)&v16[1].m_TypeUID < 5.0) )
  {
    result = 0;
  }
  else
  {
LABEL_48:
    result = 1;
  }
  return result;
}

// File Line: 1906
// RVA: 0x383DB0
void __fastcall UFG::ActiveAIEntityComponent::RestartPoiCooldown(UFG::ActiveAIEntityComponent *this)
{
  UFG::ActiveAIEntityComponent *v1; // rbx
  UFG::SimObject *v2; // rax
  UFG::SceneObjectProperties *v3; // rax
  UFG::qPropertySet *v4; // rcx
  UFG::qPropertySet *v5; // rax
  char *v6; // rax
  UFG::SimObjectCharacterPropertiesComponent *v7; // rbx

  v1 = this;
  if ( !this->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent )
    return;
  v2 = this->m_pSimObject;
  if ( !v2 || (v3 = v2->m_pSceneObj) == 0i64 )
  {
    v4 = 0i64;
LABEL_7:
    if ( !v4 )
      return;
    goto LABEL_8;
  }
  v4 = v3->mpWritableProperties;
  if ( !v4 )
  {
    v4 = v3->mpConstProperties;
    goto LABEL_7;
  }
LABEL_8:
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v4,
         (UFG::qSymbol *)&component_CharacterProperties::sPropertyName.mUID,
         DEPTH_RECURSE);
  if ( v5 )
  {
    v6 = UFG::qPropertySet::GetMemImagePtr(v5);
    if ( v6 )
    {
      v7 = (UFG::SimObjectCharacterPropertiesComponent *)v1->m_pSimObjectCharacterPropertiesComponent.m_pSimComponent;
      v7->m_CharacterStats[2].m_fStat = UFG::GetRandomNumberInRange(*((float *)v6 + 6), *((float *)v6 + 7));
    }
  }
}

// File Line: 2050
// RVA: 0x387A00
void __fastcall UFG::ActiveAIEntityComponent::SetParkourSuccessRate(UFG::ActiveAIEntityComponent *this, float val)
{
  this->m_ChanceOfCleanVault = val;
  this->m_CleanNextVault = UFG::qRandom(1.0, &UFG::qDefaultSeed) < this->m_ChanceOfCleanVault;
}

