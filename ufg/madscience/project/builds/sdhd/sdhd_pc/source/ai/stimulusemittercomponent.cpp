// File Line: 26
// RVA: 0x3633E0
const char *__fastcall UFG::StimulusEmitterComponent::GetTypeName(UFG::StimulusEmitterComponent *this)
{
  return "StimulusEmitterComponent";
}

// File Line: 31
// RVA: 0x3320E0
void __fastcall UFG::StimulusEmitterComponent::StimulusEmitterComponent(UFG::StimulusEmitterComponent *this, unsigned int name_uid, UFG::StimulusDescription *stimulus_description, UFG::StimulusParameters *stimulus_parameters, bool delete_simobject_upon_expiry)
{
  UFG::StimulusParameters *v5; // rdi
  UFG::StimulusDescription *v6; // rbx
  UFG::StimulusEmitterComponent *v7; // r14
  UFG::qNode<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList> *v8; // rax
  float v9; // xmm1_4
  float v10; // xmm2_4
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v11; // rsi
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v17; // rax

  v5 = stimulus_parameters;
  v6 = stimulus_description;
  v7 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v8 = (UFG::qNode<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList> *)&v7->mPrev;
  v8->mPrev = v8;
  v8->mNext = v8;
  v7->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::StimulusEmitterComponent::`vftable;
  v9 = UFG::qVector3::msZero.y;
  v10 = UFG::qVector3::msZero.z;
  v7->m_StimulusParameters.m_StimulusProducerOffset.x = UFG::qVector3::msZero.x;
  v7->m_StimulusParameters.m_StimulusProducerOffset.y = v9;
  v7->m_StimulusParameters.m_StimulusProducerOffset.z = v10;
  v7->m_StimulusParameters.m_StimulusEmissionType = -1;
  v7->m_StimulusParameters.m_MaxStimulusDuration = -1.0;
  v7->m_StimulusParameters.m_EmitUntilSpeedLessThan = -1.0;
  UFG::RebindingComponentHandle<UFG::AIEntityComponent,0>::RebindingComponentHandle<UFG::AIEntityComponent,0>(&v7->m_pAIEntityComponent);
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0>::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0>(&v7->m_pCharacterPropertiesComponent);
  UFG::RebindingComponentHandle<UFG::InventoryItemComponent,0>::RebindingComponentHandle<UFG::InventoryItemComponent,0>(&v7->m_pInventoryItemComponent);
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>(&v7->m_pTargetingSystemBaseComponent);
  UFG::RebindingComponentHandle<UFG::RigidBodyComponent,0>::RebindingComponentHandle<UFG::RigidBodyComponent,0>(&v7->m_pRigidBodyComponent);
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>(&v7->m_pStimulusTargetingSystem);
  v11 = &v7->m_pStimulusTarget;
  v11->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v11->mPrev;
  v11->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v11->mPrev;
  v7->m_pStimulusTarget.m_pPointer = 0i64;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v7->vfptr,
    UFG::StimulusEmitterComponent::_StimulusEmitterComponentTypeUID,
    "StimulusEmitterComponent");
  *(_QWORD *)&v7->m_StimulusDescription.m_Type = *(_QWORD *)&v6->m_Type;
  v7->m_StimulusDescription.m_Name = v6->m_Name;
  *(_QWORD *)&v7->m_StimulusDescription.m_NameHash = *(_QWORD *)&v6->m_NameHash;
  v7->m_StimulusDescription.m_Desc = v6->m_Desc;
  *(_QWORD *)&v7->m_StimulusDescription.m_MinPerceptionRadiusMetres = *(_QWORD *)&v6->m_MinPerceptionRadiusMetres;
  *(_QWORD *)&v7->m_StimulusDescription.m_PerceptionAngleCosine = *(_QWORD *)&v6->m_PerceptionAngleCosine;
  *(_QWORD *)&v7->m_StimulusDescription.m_EmitterVerticalAngleCosine = *(_QWORD *)&v6->m_EmitterVerticalAngleCosine;
  *(_QWORD *)&v7->m_StimulusDescription.m_DangerRadius = *(_QWORD *)&v6->m_DangerRadius;
  *(_QWORD *)&v7->m_StimulusDescription.m_UseAimDirection = *(_QWORD *)&v6->m_UseAimDirection;
  v12 = v5->m_StimulusProducerOffset.y;
  v13 = v5->m_StimulusProducerOffset.z;
  v7->m_StimulusParameters.m_StimulusProducerOffset.x = v5->m_StimulusProducerOffset.x;
  v7->m_StimulusParameters.m_StimulusProducerOffset.y = v12;
  v7->m_StimulusParameters.m_StimulusProducerOffset.z = v13;
  v7->m_StimulusParameters.m_StimulusEmissionType = v5->m_StimulusEmissionType;
  v7->m_StimulusParameters.m_MaxStimulusDuration = v5->m_MaxStimulusDuration;
  v7->m_StimulusParameters.m_EmitUntilSpeedLessThan = v5->m_EmitUntilSpeedLessThan;
  v7->m_DeleteSimObjectUponExpiry = delete_simobject_upon_expiry;
  v14 = UFG::Metrics::msInstance.mSimTime_Temp;
  v7->m_StartTime = UFG::Metrics::msInstance.mSimTime_Temp;
  v7->m_NextUpdateTime = v14;
  v7->m_ExpiryTime = -1.0;
  v15 = v5->m_MaxStimulusDuration;
  if ( v15 >= 0.0 )
    v7->m_ExpiryTime = v15 + v14;
  v7->m_IsTargeted = 0;
  v7->m_StimulusTargetType = 0;
  v7->m_pStimulusTargetingSystem.m_pSimComponent = 0i64;
  if ( v7->m_pStimulusTarget.m_pPointer )
  {
    v16 = v11->mPrev;
    v17 = v7->m_pStimulusTarget.mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    v11->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v11->mPrev;
    v7->m_pStimulusTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->m_pStimulusTarget.mPrev;
  }
  v7->m_pStimulusTarget.m_pPointer = 0i64;
}

// File Line: 60
// RVA: 0x33B310
void __fastcall UFG::StimulusEmitterComponent::~StimulusEmitterComponent(UFG::StimulusEmitterComponent *this)
{
  UFG::StimulusEmitterComponent *v1; // rbx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList> *v7; // rdx
  UFG::qNode<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList> *v8; // rcx
  UFG::qNode<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList> *v9; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::StimulusEmitterComponent::`vftable;
  v2 = &this->m_pStimulusTarget;
  if ( this->m_pStimulusTarget.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pStimulusTargetingSystem);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pRigidBodyComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pTargetingSystemBaseComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pInventoryItemComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pCharacterPropertiesComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pAIEntityComponent);
  v7 = (UFG::qNode<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList> *)&v1->mPrev;
  v8 = v1->mPrev;
  v9 = v1->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v7->mPrev = v7;
  v7->mNext = v7;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 71
// RVA: 0x379270
void __fastcall UFG::StimulusEmitterComponent::OnAttach(UFG::StimulusEmitterComponent *this, UFG::SimObject *object)
{
  UFG::StimulusEmitterComponent *v2; // rdi
  UFG::RebindingComponentHandle<UFG::AIEntityComponent,0> *v3; // rcx
  UFG::SimObject *v4; // rbx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0> *v9; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rax
  UFG::RebindingComponentHandle<UFG::InventoryItemComponent,0> *v14; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v17; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rax
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *v19; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v20; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v22; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v23; // rax
  UFG::RebindingComponentHandle<UFG::RigidBodyComponent,0> *v24; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v25; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v26; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v27; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v28; // rax

  v2 = this;
  v3 = &this->m_pAIEntityComponent;
  v4 = object;
  if ( v3->m_pSimComponent )
  {
    v5 = v3->mPrev;
    v6 = v3->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v3->m_pSimComponent = 0i64;
LABEL_7:
    v3->m_pSimObject = 0i64;
    v3->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->mPrev;
    v3->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->mPrev;
    goto LABEL_8;
  }
  if ( v3->m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::AIEntityComponent,0> *)v3->mPrev != v3
     || (UFG::RebindingComponentHandle<UFG::AIEntityComponent,0> *)v3->mNext != v3) )
  {
    v7 = v3->mPrev;
    v8 = v3->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    goto LABEL_7;
  }
LABEL_8:
  v3->m_Changed = 1;
  v3->m_pSimObject = v4;
  v3->m_TypeUID = UFG::AIEntityComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::AIEntityComponent,0>::BindInternal<UFG::SimObject>(v3, v4);
  v9 = &v2->m_pCharacterPropertiesComponent;
  if ( v2->m_pCharacterPropertiesComponent.m_pSimComponent )
  {
    v10 = v9->mPrev;
    v11 = v2->m_pCharacterPropertiesComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v2->m_pCharacterPropertiesComponent.m_pSimComponent = 0i64;
LABEL_14:
    v2->m_pCharacterPropertiesComponent.m_pSimObject = 0i64;
    v2->m_pCharacterPropertiesComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pCharacterPropertiesComponent.mPrev;
    v9->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v9->mPrev;
    goto LABEL_15;
  }
  if ( v2->m_pCharacterPropertiesComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0> *)v9->mPrev != v9
     || (UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0> *)v2->m_pCharacterPropertiesComponent.mNext != &v2->m_pCharacterPropertiesComponent) )
  {
    v12 = v9->mPrev;
    v13 = v2->m_pCharacterPropertiesComponent.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    goto LABEL_14;
  }
LABEL_15:
  v2->m_pCharacterPropertiesComponent.m_Changed = 1;
  v2->m_pCharacterPropertiesComponent.m_pSimObject = v4;
  v2->m_pCharacterPropertiesComponent.m_TypeUID = UFG::SimObjectCharacterPropertiesComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0>::BindInternal<UFG::SimObject>(
    &v2->m_pCharacterPropertiesComponent,
    v4);
  v14 = &v2->m_pInventoryItemComponent;
  if ( v2->m_pInventoryItemComponent.m_pSimComponent )
  {
    v15 = v14->mPrev;
    v16 = v2->m_pInventoryItemComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    v2->m_pInventoryItemComponent.m_pSimComponent = 0i64;
LABEL_21:
    v2->m_pInventoryItemComponent.m_pSimObject = 0i64;
    v2->m_pInventoryItemComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pInventoryItemComponent.mPrev;
    v14->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v14->mPrev;
    goto LABEL_22;
  }
  if ( v2->m_pInventoryItemComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::InventoryItemComponent,0> *)v14->mPrev != v14
     || (UFG::RebindingComponentHandle<UFG::InventoryItemComponent,0> *)v2->m_pInventoryItemComponent.mNext != &v2->m_pInventoryItemComponent) )
  {
    v17 = v14->mPrev;
    v18 = v2->m_pInventoryItemComponent.mNext;
    v17->mNext = v18;
    v18->mPrev = v17;
    goto LABEL_21;
  }
LABEL_22:
  v2->m_pInventoryItemComponent.m_Changed = 1;
  v2->m_pInventoryItemComponent.m_pSimObject = v4;
  v2->m_pInventoryItemComponent.m_TypeUID = UFG::InventoryItemComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::InventoryItemComponent,0>::BindInternal<UFG::SimObject>(
    &v2->m_pInventoryItemComponent,
    v4);
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
    && ((UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *)v19->mPrev != v19
     || (UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *)v2->m_pTargetingSystemBaseComponent.mNext != &v2->m_pTargetingSystemBaseComponent) )
  {
    v22 = v19->mPrev;
    v23 = v2->m_pTargetingSystemBaseComponent.mNext;
    v22->mNext = v23;
    v23->mPrev = v22;
    goto LABEL_28;
  }
LABEL_29:
  v2->m_pTargetingSystemBaseComponent.m_Changed = 1;
  v2->m_pTargetingSystemBaseComponent.m_pSimObject = v4;
  v2->m_pTargetingSystemBaseComponent.m_TypeUID = UFG::TargetingSystemBaseComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>::BindInternal<UFG::SimObject>(
    &v2->m_pTargetingSystemBaseComponent,
    v4);
  v24 = &v2->m_pRigidBodyComponent;
  if ( v2->m_pRigidBodyComponent.m_pSimComponent )
  {
    v25 = v24->mPrev;
    v26 = v2->m_pRigidBodyComponent.mNext;
    v25->mNext = v26;
    v26->mPrev = v25;
    v2->m_pRigidBodyComponent.m_pSimComponent = 0i64;
LABEL_35:
    v2->m_pRigidBodyComponent.m_pSimObject = 0i64;
    v2->m_pRigidBodyComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pRigidBodyComponent.mPrev;
    v24->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v24->mPrev;
    goto LABEL_36;
  }
  if ( v2->m_pRigidBodyComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::RigidBodyComponent,0> *)v24->mPrev != v24
     || (UFG::RebindingComponentHandle<UFG::RigidBodyComponent,0> *)v2->m_pRigidBodyComponent.mNext != &v2->m_pRigidBodyComponent) )
  {
    v27 = v24->mPrev;
    v28 = v2->m_pRigidBodyComponent.mNext;
    v27->mNext = v28;
    v28->mPrev = v27;
    goto LABEL_35;
  }
LABEL_36:
  v2->m_pRigidBodyComponent.m_Changed = 1;
  v2->m_pRigidBodyComponent.m_pSimObject = v4;
  v2->m_pRigidBodyComponent.m_TypeUID = UFG::RigidBodyComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::RigidBodyComponent,0>::BindInternal<UFG::SimObject>(&v2->m_pRigidBodyComponent, v4);
}

// File Line: 80
// RVA: 0x37B110
void __fastcall UFG::StimulusEmitterComponent::OnDetach(UFG::StimulusEmitterComponent *this)
{
  UFG::RebindingComponentHandle<UFG::AIEntityComponent,0> *v1; // r8
  UFG::StimulusEmitterComponent *v2; // r9
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::RebindingComponentHandle<UFG::InventoryItemComponent,0> *v12; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *v17; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v19; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v20; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rax
  UFG::RebindingComponentHandle<UFG::RigidBodyComponent,0> *v22; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v23; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v24; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v25; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v26; // rax

  v1 = &this->m_pAIEntityComponent;
  v2 = this;
  if ( this->m_pAIEntityComponent.m_pSimComponent )
  {
    v3 = v1->mPrev;
    v4 = this->m_pAIEntityComponent.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    this->m_pAIEntityComponent.m_pSimComponent = 0i64;
LABEL_7:
    v1->m_pSimObject = 0i64;
    v1->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    v1->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    goto LABEL_8;
  }
  if ( this->m_pAIEntityComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::AIEntityComponent,0> *)v1->mPrev != v1
     || (UFG::RebindingComponentHandle<UFG::AIEntityComponent,0> *)this->m_pAIEntityComponent.mNext != &this->m_pAIEntityComponent) )
  {
    v5 = v1->mPrev;
    v6 = v1->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  v7 = &v2->m_pCharacterPropertiesComponent;
  v1->m_Changed = 1;
  if ( v2->m_pCharacterPropertiesComponent.m_pSimComponent )
  {
    v8 = v7->mPrev;
    v9 = v2->m_pCharacterPropertiesComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v2->m_pCharacterPropertiesComponent.m_pSimComponent = 0i64;
LABEL_14:
    v2->m_pCharacterPropertiesComponent.m_pSimObject = 0i64;
    v2->m_pCharacterPropertiesComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pCharacterPropertiesComponent.mPrev;
    v7->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v7->mPrev;
    goto LABEL_15;
  }
  if ( v2->m_pCharacterPropertiesComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0> *)v7->mPrev != v7
     || (UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0> *)v2->m_pCharacterPropertiesComponent.mNext != &v2->m_pCharacterPropertiesComponent) )
  {
    v10 = v7->mPrev;
    v11 = v2->m_pCharacterPropertiesComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    goto LABEL_14;
  }
LABEL_15:
  v2->m_pCharacterPropertiesComponent.m_Changed = 1;
  v12 = &v2->m_pInventoryItemComponent;
  if ( v2->m_pInventoryItemComponent.m_pSimComponent )
  {
    v13 = v12->mPrev;
    v14 = v2->m_pInventoryItemComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v2->m_pInventoryItemComponent.m_pSimComponent = 0i64;
LABEL_21:
    v2->m_pInventoryItemComponent.m_pSimObject = 0i64;
    v2->m_pInventoryItemComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pInventoryItemComponent.mPrev;
    v12->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v12->mPrev;
    goto LABEL_22;
  }
  if ( v2->m_pInventoryItemComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::InventoryItemComponent,0> *)v12->mPrev != v12
     || (UFG::RebindingComponentHandle<UFG::InventoryItemComponent,0> *)v2->m_pInventoryItemComponent.mNext != &v2->m_pInventoryItemComponent) )
  {
    v15 = v12->mPrev;
    v16 = v2->m_pInventoryItemComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    goto LABEL_21;
  }
LABEL_22:
  v2->m_pInventoryItemComponent.m_Changed = 1;
  v17 = &v2->m_pTargetingSystemBaseComponent;
  if ( v2->m_pTargetingSystemBaseComponent.m_pSimComponent )
  {
    v18 = v17->mPrev;
    v19 = v2->m_pTargetingSystemBaseComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    v2->m_pTargetingSystemBaseComponent.m_pSimComponent = 0i64;
LABEL_28:
    v2->m_pTargetingSystemBaseComponent.m_pSimObject = 0i64;
    v2->m_pTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pTargetingSystemBaseComponent.mPrev;
    v17->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v17->mPrev;
    goto LABEL_29;
  }
  if ( v2->m_pTargetingSystemBaseComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *)v17->mPrev != v17
     || (UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *)v2->m_pTargetingSystemBaseComponent.mNext != &v2->m_pTargetingSystemBaseComponent) )
  {
    v20 = v17->mPrev;
    v21 = v2->m_pTargetingSystemBaseComponent.mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    goto LABEL_28;
  }
LABEL_29:
  v2->m_pTargetingSystemBaseComponent.m_Changed = 1;
  v22 = &v2->m_pRigidBodyComponent;
  if ( v2->m_pRigidBodyComponent.m_pSimComponent )
  {
    v23 = v22->mPrev;
    v24 = v2->m_pRigidBodyComponent.mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    v2->m_pRigidBodyComponent.m_pSimComponent = 0i64;
    v2->m_pRigidBodyComponent.m_pSimObject = 0i64;
    v2->m_pRigidBodyComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pRigidBodyComponent.mPrev;
    v22->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v22->mPrev;
    v2->m_pRigidBodyComponent.m_Changed = 1;
  }
  else
  {
    if ( v2->m_pRigidBodyComponent.m_pSimObject
      && ((UFG::RebindingComponentHandle<UFG::RigidBodyComponent,0> *)v22->mPrev != v22
       || (UFG::RebindingComponentHandle<UFG::RigidBodyComponent,0> *)v2->m_pRigidBodyComponent.mNext != &v2->m_pRigidBodyComponent) )
    {
      v25 = v22->mPrev;
      v26 = v2->m_pRigidBodyComponent.mNext;
      v25->mNext = v26;
      v26->mPrev = v25;
      v2->m_pRigidBodyComponent.m_pSimObject = 0i64;
      v2->m_pRigidBodyComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->m_pRigidBodyComponent.mPrev;
      v22->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v22->mPrev;
    }
    v2->m_pRigidBodyComponent.m_Changed = 1;
  }
}

// File Line: 98
// RVA: 0x386F00
void __fastcall UFG::StimulusEmitterComponent::SetIsTargeted(UFG::StimulusEmitterComponent *this, UFG::TargetingSystemBaseComponent *targeting_system_component, UFG::eTargetTypeEnum target_type)
{
  UFG::StimulusEmitterComponent *v3; // rbx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v4; // rcx
  UFG::eTargetTypeEnum v5; // edi
  UFG::TargetingSystemBaseComponent *v6; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rax

  this->m_IsTargeted = 0;
  v3 = this;
  this->m_StimulusTargetType = 0;
  this->m_pStimulusTargetingSystem.m_pSimComponent = 0i64;
  v4 = &this->m_pStimulusTarget;
  v5 = target_type;
  v6 = targeting_system_component;
  if ( v4->m_pPointer )
  {
    v7 = v4->mPrev;
    v8 = v4->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  }
  v4->m_pPointer = 0i64;
  v3->m_IsTargeted = 1;
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>::Set(&v3->m_pStimulusTargetingSystem, v6);
  v3->m_StimulusTargetType = v5;
}

// File Line: 107
// RVA: 0x386E70
void __fastcall UFG::StimulusEmitterComponent::SetIsTargeted(UFG::StimulusEmitterComponent *this, UFG::SimObject *target)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v2; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v3; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax

  v2 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->m_pStimulusTarget.mPrev;
  this->m_IsTargeted = 0;
  this->m_StimulusTargetType = 0;
  this->m_pStimulusTargetingSystem.m_pSimComponent = 0i64;
  if ( this->m_pStimulusTarget.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = this->m_pStimulusTarget.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = v2;
    this->m_pStimulusTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->m_pStimulusTarget.mPrev;
  }
  this->m_pStimulusTarget.m_pPointer = 0i64;
  this->m_IsTargeted = 1;
  if ( this->m_pStimulusTarget.m_pPointer )
  {
    v5 = v2->mPrev;
    v6 = v2->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v2->mPrev = v2;
    v2->mNext = v2;
  }
  v2[1].mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)target;
  if ( target )
  {
    v7 = target->m_SafePointerList.mNode.mPrev;
    v7->mNext = v2;
    v2->mPrev = v7;
    v2->mNext = &target->m_SafePointerList.mNode;
    target->m_SafePointerList.mNode.mPrev = v2;
  }
}

// File Line: 115
// RVA: 0x392E20
void __usercall UFG::StimulusEmitterComponent::Update(UFG::StimulusEmitterComponent *this@<rcx>, float timestep@<xmm1>, hkgpIndexedMeshDefinitions::Edge *a3@<rdx>)
{
  UFG::StimulusEmitterComponent *v3; // rbx
  float v4; // xmm6_4
  UFG::SimObject *v5; // rcx
  bool v6; // si
  bool v7; // bp
  float v8; // xmm0_4
  bool v9; // r14
  float v10; // xmm8_4
  float v11; // xmm0_4
  UFG::SimObject *v12; // rdi
  UFG::TransformNodeComponent *v13; // rdi
  float v14; // xmm1_4
  __m128 v15; // xmm0
  float v16; // xmm2_4
  UFG::qVector3 *v17; // rax
  bool v18; // al
  UFG::SimObject *v19; // rax
  UFG::SimObject *v20; // rdi
  UFG::allocator::free_link *v21; // rax
  UFG::SimObject *v22; // rdx
  UFG::qVector3 result; // [rsp+28h] [rbp-60h]

  v3 = this;
  v4 = UFG::Metrics::msInstance.mSimTime_Temp;
  v6 = 0;
  if ( this->m_pAIEntityComponent.m_pSimComponent )
  {
    v5 = this->m_pAIEntityComponent.m_pSimComponent[6].m_pSimObject;
    if ( v5 )
    {
      if ( Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat((hkgpIndexedMesh::EdgeBarrier *)v5, a3) )
        v6 = 1;
    }
  }
  v7 = v3->m_IsTargeted && !v3->m_pStimulusTargetingSystem.m_pSimComponent && !v3->m_pStimulusTarget.m_pPointer;
  v8 = v3->m_ExpiryTime;
  v9 = v8 >= 0.0 && v4 > v8;
  v10 = v3->m_StimulusParameters.m_EmitUntilSpeedLessThan;
  v11 = 0.0;
  v12 = v3->m_pSimObject;
  if ( v12 )
  {
    v13 = v12->m_pTransformNodeComponent;
    if ( v13 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(v13);
      v14 = v13->mWorldVelocity.x;
      v15 = (__m128)LODWORD(v13->mWorldVelocity.y);
      v16 = v13->mWorldVelocity.z;
LABEL_20:
      v15.m128_f32[0] = (float)((float)(v15.m128_f32[0] * v15.m128_f32[0]) + (float)(v14 * v14)) + (float)(v16 * v16);
      LODWORD(v11) = (unsigned __int128)_mm_sqrt_ps(v15);
      goto LABEL_21;
    }
  }
  if ( v3->m_pRigidBodyComponent.m_pSimComponent )
  {
    v17 = UFG::RigidBody::GetVelocity((UFG::RigidBody *)v3->m_pRigidBodyComponent.m_pSimComponent, &result);
    v14 = v17->x;
    v15 = (__m128)LODWORD(v17->y);
    v16 = v17->z;
    goto LABEL_20;
  }
LABEL_21:
  v18 = v10 >= 0.0 && v11 < v10 && (float)(v4 - v3->m_StartTime) > 0.5;
  if ( v6 || v7 || v9 || v18 )
  {
    if ( v3->m_DeleteSimObjectUponExpiry && (v22 = v3->m_pSimObject) != 0i64 )
      UFG::Simulation::QueueSimObjectToBeDestroyed(&UFG::gSim, v22);
    else
      UFG::Simulation::DestroySimComponent(&UFG::gSim, (UFG::SimComponent *)&v3->vfptr);
  }
  else
  {
    v19 = UFG::StimulusEmitterComponent::GetStimulusTarget(v3);
    v20 = v19;
    if ( !v3->m_IsTargeted || v19 )
    {
      v21 = UFG::qMalloc(0x198ui64, "Stimulus", 0i64);
      if ( v21 )
        UFG::Stimulus::Stimulus((UFG::Stimulus *)v21, v3, v20);
      UFG::EventDispatcher::QueueEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v21);
    }
    v3->m_NextUpdateTime = v4 + v3->m_StimulusDescription.m_MinTimeBetweenUpdates;
    if ( v3->m_StimulusParameters.m_StimulusEmissionType == eSTIMULUS_EMISSION_ONE_OFF )
      UFG::StimulusEmitterComponent::DeleteMe(v3);
  }
}

// File Line: 194
// RVA: 0x362790
UFG::SimObject *__fastcall UFG::StimulusEmitterComponent::GetStimulusTarget(UFG::StimulusEmitterComponent *this)
{
  UFG::SimObject *result; // rax
  UFG::SimComponent *v2; // r8
  UFG::SimObject *v3; // rcx

  result = 0i64;
  if ( this->m_IsTargeted )
  {
    v2 = this->m_pStimulusTargetingSystem.m_pSimComponent;
    if ( v2 )
    {
      result = *(UFG::SimObject **)(56i64
                                  * *(unsigned __int8 *)((unsigned int)this->m_StimulusTargetType
                                                       + *(_QWORD *)&v2[1].m_Flags
                                                       + 8i64)
                                  + *(_QWORD *)&v2[1].m_TypeUID
                                  + 40);
    }
    else
    {
      v3 = this->m_pStimulusTarget.m_pPointer;
      if ( v3 )
        result = v3;
    }
  }
  return result;
}

// File Line: 213
// RVA: 0x351F20
void __fastcall UFG::StimulusEmitterComponent::DeleteMe(UFG::StimulusEmitterComponent *this)
{
  UFG::SimObject *v1; // rdx

  if ( this->m_DeleteSimObjectUponExpiry && (v1 = this->m_pSimObject) != 0i64 )
    UFG::Simulation::QueueSimObjectToBeDestroyed(&UFG::gSim, v1);
  else
    UFG::Simulation::DestroySimComponent(&UFG::gSim, (UFG::SimComponent *)&this->vfptr);
}

// File Line: 236
// RVA: 0x3626E0
char __fastcall UFG::StimulusEmitterComponent::GetStimulusProducerPosition(UFG::StimulusEmitterComponent *this, UFG::qVector3 *position)
{
  UFG::SimObject *v2; // rbx
  UFG::qVector3 *v3; // rdi
  UFG::TransformNodeComponent *v4; // rbx
  float v5; // xmm0_4
  float v6; // xmm1_4
  char v7; // al
  UFG::qVector3 *v8; // rax
  float v9; // xmm0_4
  float v10; // xmm1_4
  UFG::qVector3 result; // [rsp+20h] [rbp-18h]

  v2 = this->m_pSimObject;
  v3 = position;
  if ( v2 && (v4 = v2->m_pTransformNodeComponent) != 0i64 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v4);
    v5 = v4->mWorldTransform.v3.y;
    v6 = v4->mWorldTransform.v3.z;
    v3->x = v4->mWorldTransform.v3.x;
    v7 = 1;
    v3->y = v5;
    v3->z = v6;
  }
  else if ( this->m_pRigidBodyComponent.m_pSimComponent )
  {
    v8 = UFG::RigidBody::GetCentreOfMass((UFG::RigidBody *)this->m_pRigidBodyComponent.m_pSimComponent, &result);
    v9 = v8->y;
    v10 = v8->z;
    v3->x = v8->x;
    v7 = 1;
    v3->y = v9;
    v3->z = v10;
  }
  else
  {
    v7 = 0;
  }
  return v7;
}

