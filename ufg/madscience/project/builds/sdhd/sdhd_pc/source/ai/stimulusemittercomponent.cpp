// File Line: 26
// RVA: 0x3633E0
const char *__fastcall UFG::StimulusEmitterComponent::GetTypeName(UFG::StimulusEmitterComponent *this)
{
  return "StimulusEmitterComponent";
}

// File Line: 31
// RVA: 0x3320E0
void __fastcall UFG::StimulusEmitterComponent::StimulusEmitterComponent(
        UFG::StimulusEmitterComponent *this,
        unsigned int name_uid,
        UFG::StimulusDescription *stimulus_description,
        UFG::StimulusParameters *stimulus_parameters,
        bool delete_simobject_upon_expiry)
{
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pStimulusTarget; // rsi
  float v11; // xmm1_4
  float v12; // xmm2_4
  float mSimTime_Temp; // xmm2_4
  float m_MaxStimulusDuration; // xmm1_4
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax

  UFG::SimComponent::SimComponent(this, name_uid);
  this->mPrev = &this->UFG::qNode<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList>;
  this->mNext = &this->UFG::qNode<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::StimulusEmitterComponent::`vftable;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->m_StimulusParameters.m_StimulusProducerOffset.x = UFG::qVector3::msZero.x;
  this->m_StimulusParameters.m_StimulusProducerOffset.y = y;
  this->m_StimulusParameters.m_StimulusProducerOffset.z = z;
  this->m_StimulusParameters.m_StimulusEmissionType = eSTIMULUS_EMISSION_NONE;
  this->m_StimulusParameters.m_MaxStimulusDuration = -1.0;
  this->m_StimulusParameters.m_EmitUntilSpeedLessThan = -1.0;
  UFG::RebindingComponentHandle<UFG::AIEntityComponent,0>::RebindingComponentHandle<UFG::AIEntityComponent,0>(&this->m_pAIEntityComponent);
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0>::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0>(&this->m_pCharacterPropertiesComponent);
  UFG::RebindingComponentHandle<UFG::InventoryItemComponent,0>::RebindingComponentHandle<UFG::InventoryItemComponent,0>(&this->m_pInventoryItemComponent);
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>(&this->m_pTargetingSystemBaseComponent);
  UFG::RebindingComponentHandle<UFG::RigidBodyComponent,0>::RebindingComponentHandle<UFG::RigidBodyComponent,0>(&this->m_pRigidBodyComponent);
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>(&this->m_pStimulusTargetingSystem);
  p_m_pStimulusTarget = &this->m_pStimulusTarget;
  this->m_pStimulusTarget.mPrev = &this->m_pStimulusTarget;
  this->m_pStimulusTarget.mNext = &this->m_pStimulusTarget;
  this->m_pStimulusTarget.m_pPointer = 0i64;
  UFG::SimComponent::AddType(
    this,
    UFG::StimulusEmitterComponent::_StimulusEmitterComponentTypeUID,
    "StimulusEmitterComponent");
  this->m_StimulusDescription = *stimulus_description;
  v11 = stimulus_parameters->m_StimulusProducerOffset.y;
  v12 = stimulus_parameters->m_StimulusProducerOffset.z;
  this->m_StimulusParameters.m_StimulusProducerOffset.x = stimulus_parameters->m_StimulusProducerOffset.x;
  this->m_StimulusParameters.m_StimulusProducerOffset.y = v11;
  this->m_StimulusParameters.m_StimulusProducerOffset.z = v12;
  this->m_StimulusParameters.m_StimulusEmissionType = stimulus_parameters->m_StimulusEmissionType;
  this->m_StimulusParameters.m_MaxStimulusDuration = stimulus_parameters->m_MaxStimulusDuration;
  this->m_StimulusParameters.m_EmitUntilSpeedLessThan = stimulus_parameters->m_EmitUntilSpeedLessThan;
  this->m_DeleteSimObjectUponExpiry = delete_simobject_upon_expiry;
  mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
  this->m_StartTime = UFG::Metrics::msInstance.mSimTime_Temp;
  this->m_NextUpdateTime = mSimTime_Temp;
  this->m_ExpiryTime = -1.0;
  m_MaxStimulusDuration = stimulus_parameters->m_MaxStimulusDuration;
  if ( m_MaxStimulusDuration >= 0.0 )
    this->m_ExpiryTime = m_MaxStimulusDuration + mSimTime_Temp;
  this->m_IsTargeted = 0;
  this->m_StimulusTargetType = eTARGET_TYPE_INVALID;
  this->m_pStimulusTargetingSystem.m_pSimComponent = 0i64;
  if ( this->m_pStimulusTarget.m_pPointer )
  {
    mPrev = p_m_pStimulusTarget->mPrev;
    mNext = this->m_pStimulusTarget.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pStimulusTarget->mPrev = p_m_pStimulusTarget;
    this->m_pStimulusTarget.mNext = &this->m_pStimulusTarget;
  }
  this->m_pStimulusTarget.m_pPointer = 0i64;
}

// File Line: 60
// RVA: 0x33B310
void __fastcall UFG::StimulusEmitterComponent::~StimulusEmitterComponent(UFG::StimulusEmitterComponent *this)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pStimulusTarget; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList> *v7; // rcx
  UFG::qNode<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList> *v8; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::StimulusEmitterComponent::`vftable;
  p_m_pStimulusTarget = &this->m_pStimulusTarget;
  if ( this->m_pStimulusTarget.m_pPointer )
  {
    mPrev = p_m_pStimulusTarget->mPrev;
    mNext = p_m_pStimulusTarget->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pStimulusTarget->mPrev = p_m_pStimulusTarget;
    p_m_pStimulusTarget->mNext = p_m_pStimulusTarget;
  }
  p_m_pStimulusTarget->m_pPointer = 0i64;
  v5 = p_m_pStimulusTarget->mPrev;
  v6 = p_m_pStimulusTarget->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pStimulusTarget->mPrev = p_m_pStimulusTarget;
  p_m_pStimulusTarget->mNext = p_m_pStimulusTarget;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pStimulusTargetingSystem);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pRigidBodyComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pTargetingSystemBaseComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pInventoryItemComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pCharacterPropertiesComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pAIEntityComponent);
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList>;
  this->mNext = &this->UFG::qNode<UFG::StimulusEmitterComponent,UFG::StimulusManagerUpdateList>;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 71
// RVA: 0x379270
void __fastcall UFG::StimulusEmitterComponent::OnAttach(UFG::StimulusEmitterComponent *this, UFG::SimObject *object)
{
  UFG::RebindingComponentHandle<UFG::AIEntityComponent,0> *p_m_pAIEntityComponent; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0> *p_m_pCharacterPropertiesComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rax
  UFG::RebindingComponentHandle<UFG::InventoryItemComponent,0> *p_m_pInventoryItemComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v17; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rax
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *p_m_pTargetingSystemBaseComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v20; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v22; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v23; // rax
  UFG::RebindingComponentHandle<UFG::RigidBodyComponent,0> *p_m_pRigidBodyComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v25; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v26; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v27; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v28; // rax

  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  if ( p_m_pAIEntityComponent->m_pSimComponent )
  {
    mPrev = p_m_pAIEntityComponent->mPrev;
    mNext = p_m_pAIEntityComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAIEntityComponent->m_pSimComponent = 0i64;
LABEL_7:
    p_m_pAIEntityComponent->m_pSimObject = 0i64;
    p_m_pAIEntityComponent->mNext = p_m_pAIEntityComponent;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    goto LABEL_8;
  }
  if ( p_m_pAIEntityComponent->m_pSimObject
    && (p_m_pAIEntityComponent->mPrev != p_m_pAIEntityComponent
     || p_m_pAIEntityComponent->mNext != p_m_pAIEntityComponent) )
  {
    v7 = p_m_pAIEntityComponent->mPrev;
    v8 = p_m_pAIEntityComponent->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    goto LABEL_7;
  }
LABEL_8:
  p_m_pAIEntityComponent->m_Changed = 1;
  p_m_pAIEntityComponent->m_pSimObject = object;
  p_m_pAIEntityComponent->m_TypeUID = UFG::AIEntityComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::AIEntityComponent,0>::BindInternal<UFG::SimObject>(p_m_pAIEntityComponent, object);
  p_m_pCharacterPropertiesComponent = &this->m_pCharacterPropertiesComponent;
  if ( this->m_pCharacterPropertiesComponent.m_pSimComponent )
  {
    v10 = p_m_pCharacterPropertiesComponent->mPrev;
    v11 = this->m_pCharacterPropertiesComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    this->m_pCharacterPropertiesComponent.m_pSimComponent = 0i64;
LABEL_14:
    this->m_pCharacterPropertiesComponent.m_pSimObject = 0i64;
    this->m_pCharacterPropertiesComponent.mNext = &this->m_pCharacterPropertiesComponent;
    p_m_pCharacterPropertiesComponent->mPrev = p_m_pCharacterPropertiesComponent;
    goto LABEL_15;
  }
  if ( this->m_pCharacterPropertiesComponent.m_pSimObject
    && (p_m_pCharacterPropertiesComponent->mPrev != p_m_pCharacterPropertiesComponent
     || this->m_pCharacterPropertiesComponent.mNext != &this->m_pCharacterPropertiesComponent) )
  {
    v12 = p_m_pCharacterPropertiesComponent->mPrev;
    v13 = this->m_pCharacterPropertiesComponent.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    goto LABEL_14;
  }
LABEL_15:
  this->m_pCharacterPropertiesComponent.m_Changed = 1;
  this->m_pCharacterPropertiesComponent.m_pSimObject = object;
  this->m_pCharacterPropertiesComponent.m_TypeUID = UFG::SimObjectCharacterPropertiesComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0>::BindInternal<UFG::SimObject>(
    &this->m_pCharacterPropertiesComponent,
    object);
  p_m_pInventoryItemComponent = &this->m_pInventoryItemComponent;
  if ( this->m_pInventoryItemComponent.m_pSimComponent )
  {
    v15 = p_m_pInventoryItemComponent->mPrev;
    v16 = this->m_pInventoryItemComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    this->m_pInventoryItemComponent.m_pSimComponent = 0i64;
LABEL_21:
    this->m_pInventoryItemComponent.m_pSimObject = 0i64;
    this->m_pInventoryItemComponent.mNext = &this->m_pInventoryItemComponent;
    p_m_pInventoryItemComponent->mPrev = p_m_pInventoryItemComponent;
    goto LABEL_22;
  }
  if ( this->m_pInventoryItemComponent.m_pSimObject
    && (p_m_pInventoryItemComponent->mPrev != p_m_pInventoryItemComponent
     || this->m_pInventoryItemComponent.mNext != &this->m_pInventoryItemComponent) )
  {
    v17 = p_m_pInventoryItemComponent->mPrev;
    v18 = this->m_pInventoryItemComponent.mNext;
    v17->mNext = v18;
    v18->mPrev = v17;
    goto LABEL_21;
  }
LABEL_22:
  this->m_pInventoryItemComponent.m_Changed = 1;
  this->m_pInventoryItemComponent.m_pSimObject = object;
  this->m_pInventoryItemComponent.m_TypeUID = UFG::InventoryItemComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::InventoryItemComponent,0>::BindInternal<UFG::SimObject>(
    &this->m_pInventoryItemComponent,
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
  this->m_pTargetingSystemBaseComponent.m_TypeUID = UFG::TargetingSystemBaseComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>::BindInternal<UFG::SimObject>(
    &this->m_pTargetingSystemBaseComponent,
    object);
  p_m_pRigidBodyComponent = &this->m_pRigidBodyComponent;
  if ( this->m_pRigidBodyComponent.m_pSimComponent )
  {
    v25 = p_m_pRigidBodyComponent->mPrev;
    v26 = this->m_pRigidBodyComponent.mNext;
    v25->mNext = v26;
    v26->mPrev = v25;
    this->m_pRigidBodyComponent.m_pSimComponent = 0i64;
LABEL_35:
    this->m_pRigidBodyComponent.m_pSimObject = 0i64;
    this->m_pRigidBodyComponent.mNext = &this->m_pRigidBodyComponent;
    p_m_pRigidBodyComponent->mPrev = p_m_pRigidBodyComponent;
    goto LABEL_36;
  }
  if ( this->m_pRigidBodyComponent.m_pSimObject
    && (p_m_pRigidBodyComponent->mPrev != p_m_pRigidBodyComponent
     || this->m_pRigidBodyComponent.mNext != &this->m_pRigidBodyComponent) )
  {
    v27 = p_m_pRigidBodyComponent->mPrev;
    v28 = this->m_pRigidBodyComponent.mNext;
    v27->mNext = v28;
    v28->mPrev = v27;
    goto LABEL_35;
  }
LABEL_36:
  this->m_pRigidBodyComponent.m_Changed = 1;
  this->m_pRigidBodyComponent.m_pSimObject = object;
  this->m_pRigidBodyComponent.m_TypeUID = UFG::RigidBodyComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::RigidBodyComponent,0>::BindInternal<UFG::SimObject>(
    &this->m_pRigidBodyComponent,
    object);
}

// File Line: 80
// RVA: 0x37B110
void __fastcall UFG::StimulusEmitterComponent::OnDetach(UFG::StimulusEmitterComponent *this)
{
  UFG::RebindingComponentHandle<UFG::AIEntityComponent,0> *p_m_pAIEntityComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0> *p_m_pCharacterPropertiesComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::RebindingComponentHandle<UFG::InventoryItemComponent,0> *p_m_pInventoryItemComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *p_m_pTargetingSystemBaseComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v19; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v20; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rax
  UFG::RebindingComponentHandle<UFG::RigidBodyComponent,0> *p_m_pRigidBodyComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v23; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v24; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v25; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v26; // rax

  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  if ( this->m_pAIEntityComponent.m_pSimComponent )
  {
    mPrev = p_m_pAIEntityComponent->mPrev;
    mNext = this->m_pAIEntityComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->m_pAIEntityComponent.m_pSimComponent = 0i64;
LABEL_7:
    p_m_pAIEntityComponent->m_pSimObject = 0i64;
    p_m_pAIEntityComponent->mNext = p_m_pAIEntityComponent;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    goto LABEL_8;
  }
  if ( this->m_pAIEntityComponent.m_pSimObject
    && (p_m_pAIEntityComponent->mPrev != p_m_pAIEntityComponent
     || this->m_pAIEntityComponent.mNext != &this->m_pAIEntityComponent) )
  {
    v5 = p_m_pAIEntityComponent->mPrev;
    v6 = p_m_pAIEntityComponent->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  p_m_pCharacterPropertiesComponent = &this->m_pCharacterPropertiesComponent;
  p_m_pAIEntityComponent->m_Changed = 1;
  if ( this->m_pCharacterPropertiesComponent.m_pSimComponent )
  {
    v8 = p_m_pCharacterPropertiesComponent->mPrev;
    v9 = this->m_pCharacterPropertiesComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    this->m_pCharacterPropertiesComponent.m_pSimComponent = 0i64;
LABEL_14:
    this->m_pCharacterPropertiesComponent.m_pSimObject = 0i64;
    this->m_pCharacterPropertiesComponent.mNext = &this->m_pCharacterPropertiesComponent;
    p_m_pCharacterPropertiesComponent->mPrev = p_m_pCharacterPropertiesComponent;
    goto LABEL_15;
  }
  if ( this->m_pCharacterPropertiesComponent.m_pSimObject
    && (p_m_pCharacterPropertiesComponent->mPrev != p_m_pCharacterPropertiesComponent
     || this->m_pCharacterPropertiesComponent.mNext != &this->m_pCharacterPropertiesComponent) )
  {
    v10 = p_m_pCharacterPropertiesComponent->mPrev;
    v11 = this->m_pCharacterPropertiesComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    goto LABEL_14;
  }
LABEL_15:
  this->m_pCharacterPropertiesComponent.m_Changed = 1;
  p_m_pInventoryItemComponent = &this->m_pInventoryItemComponent;
  if ( this->m_pInventoryItemComponent.m_pSimComponent )
  {
    v13 = p_m_pInventoryItemComponent->mPrev;
    v14 = this->m_pInventoryItemComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    this->m_pInventoryItemComponent.m_pSimComponent = 0i64;
LABEL_21:
    this->m_pInventoryItemComponent.m_pSimObject = 0i64;
    this->m_pInventoryItemComponent.mNext = &this->m_pInventoryItemComponent;
    p_m_pInventoryItemComponent->mPrev = p_m_pInventoryItemComponent;
    goto LABEL_22;
  }
  if ( this->m_pInventoryItemComponent.m_pSimObject
    && (p_m_pInventoryItemComponent->mPrev != p_m_pInventoryItemComponent
     || this->m_pInventoryItemComponent.mNext != &this->m_pInventoryItemComponent) )
  {
    v15 = p_m_pInventoryItemComponent->mPrev;
    v16 = this->m_pInventoryItemComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    goto LABEL_21;
  }
LABEL_22:
  this->m_pInventoryItemComponent.m_Changed = 1;
  p_m_pTargetingSystemBaseComponent = &this->m_pTargetingSystemBaseComponent;
  if ( this->m_pTargetingSystemBaseComponent.m_pSimComponent )
  {
    v18 = p_m_pTargetingSystemBaseComponent->mPrev;
    v19 = this->m_pTargetingSystemBaseComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
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
    v20 = p_m_pTargetingSystemBaseComponent->mPrev;
    v21 = this->m_pTargetingSystemBaseComponent.mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    goto LABEL_28;
  }
LABEL_29:
  this->m_pTargetingSystemBaseComponent.m_Changed = 1;
  p_m_pRigidBodyComponent = &this->m_pRigidBodyComponent;
  if ( this->m_pRigidBodyComponent.m_pSimComponent )
  {
    v23 = p_m_pRigidBodyComponent->mPrev;
    v24 = this->m_pRigidBodyComponent.mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    this->m_pRigidBodyComponent.m_pSimComponent = 0i64;
    this->m_pRigidBodyComponent.m_pSimObject = 0i64;
    this->m_pRigidBodyComponent.mNext = &this->m_pRigidBodyComponent;
    p_m_pRigidBodyComponent->mPrev = p_m_pRigidBodyComponent;
    this->m_pRigidBodyComponent.m_Changed = 1;
  }
  else
  {
    if ( this->m_pRigidBodyComponent.m_pSimObject
      && (p_m_pRigidBodyComponent->mPrev != p_m_pRigidBodyComponent
       || this->m_pRigidBodyComponent.mNext != &this->m_pRigidBodyComponent) )
    {
      v25 = p_m_pRigidBodyComponent->mPrev;
      v26 = this->m_pRigidBodyComponent.mNext;
      v25->mNext = v26;
      v26->mPrev = v25;
      this->m_pRigidBodyComponent.m_pSimObject = 0i64;
      this->m_pRigidBodyComponent.mNext = &this->m_pRigidBodyComponent;
      p_m_pRigidBodyComponent->mPrev = p_m_pRigidBodyComponent;
    }
    this->m_pRigidBodyComponent.m_Changed = 1;
  }
}

// File Line: 98
// RVA: 0x386F00
void __fastcall UFG::StimulusEmitterComponent::SetIsTargeted(
        UFG::StimulusEmitterComponent *this,
        UFG::TargetingSystemBaseComponent *targeting_system_component,
        UFG::eTargetTypeEnum target_type)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pStimulusTarget; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax

  this->m_IsTargeted = 0;
  this->m_StimulusTargetType = eTARGET_TYPE_INVALID;
  this->m_pStimulusTargetingSystem.m_pSimComponent = 0i64;
  p_m_pStimulusTarget = &this->m_pStimulusTarget;
  if ( p_m_pStimulusTarget->m_pPointer )
  {
    mPrev = p_m_pStimulusTarget->mPrev;
    mNext = p_m_pStimulusTarget->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pStimulusTarget->mPrev = p_m_pStimulusTarget;
    p_m_pStimulusTarget->mNext = p_m_pStimulusTarget;
  }
  p_m_pStimulusTarget->m_pPointer = 0i64;
  this->m_IsTargeted = 1;
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>::Set(
    &this->m_pStimulusTargetingSystem,
    targeting_system_component);
  this->m_StimulusTargetType = target_type;
}

// File Line: 107
// RVA: 0x386E70
void __fastcall UFG::StimulusEmitterComponent::SetIsTargeted(
        UFG::StimulusEmitterComponent *this,
        UFG::SimObject *target)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pStimulusTarget; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax

  p_m_pStimulusTarget = &this->m_pStimulusTarget;
  this->m_IsTargeted = 0;
  this->m_StimulusTargetType = eTARGET_TYPE_INVALID;
  this->m_pStimulusTargetingSystem.m_pSimComponent = 0i64;
  if ( this->m_pStimulusTarget.m_pPointer )
  {
    mPrev = p_m_pStimulusTarget->mPrev;
    mNext = this->m_pStimulusTarget.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pStimulusTarget->mPrev = p_m_pStimulusTarget;
    this->m_pStimulusTarget.mNext = &this->m_pStimulusTarget;
  }
  this->m_pStimulusTarget.m_pPointer = 0i64;
  this->m_IsTargeted = 1;
  if ( this->m_pStimulusTarget.m_pPointer )
  {
    v5 = p_m_pStimulusTarget->mPrev;
    v6 = p_m_pStimulusTarget->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    p_m_pStimulusTarget->mPrev = p_m_pStimulusTarget;
    p_m_pStimulusTarget->mNext = p_m_pStimulusTarget;
  }
  p_m_pStimulusTarget->m_pPointer = target;
  if ( target )
  {
    v7 = target->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v7->mNext = p_m_pStimulusTarget;
    p_m_pStimulusTarget->mPrev = v7;
    p_m_pStimulusTarget->mNext = &target->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    target->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_m_pStimulusTarget;
  }
}

// File Line: 115
// RVA: 0x392E20
void __fastcall UFG::StimulusEmitterComponent::Update(UFG::StimulusEmitterComponent *this, float timestep)
{
  hkgpIndexedMeshDefinitions::Edge *v2; // rdx
  float mSimTime_Temp; // xmm6_4
  UFG::SimObject *m_pSimObject; // rcx
  bool v6; // si
  bool v7; // bp
  float m_ExpiryTime; // xmm0_4
  bool v9; // r14
  float m_EmitUntilSpeedLessThan; // xmm8_4
  float v11; // xmm0_4
  UFG::SimObject *v12; // rdi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  float x; // xmm1_4
  __m128 y_low; // xmm0
  float z; // xmm2_4
  UFG::qVector3 *Velocity; // rax
  bool v18; // al
  UFG::SimObject *StimulusTarget; // rax
  UFG::SimObject *v20; // rdi
  UFG::allocator::free_link *v21; // rax
  UFG::SimObject *v22; // rdx
  UFG::qVector3 result; // [rsp+28h] [rbp-60h] BYREF

  mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
  v6 = 0;
  if ( this->m_pAIEntityComponent.m_pSimComponent )
  {
    m_pSimObject = this->m_pAIEntityComponent.m_pSimComponent[6].m_pSimObject;
    if ( m_pSimObject )
    {
      if ( Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
             (hkgpIndexedMesh::EdgeBarrier *)m_pSimObject,
             v2) )
      {
        v6 = 1;
      }
    }
  }
  v7 = this->m_IsTargeted && !this->m_pStimulusTargetingSystem.m_pSimComponent && !this->m_pStimulusTarget.m_pPointer;
  m_ExpiryTime = this->m_ExpiryTime;
  v9 = m_ExpiryTime >= 0.0 && mSimTime_Temp > m_ExpiryTime;
  m_EmitUntilSpeedLessThan = this->m_StimulusParameters.m_EmitUntilSpeedLessThan;
  v11 = 0.0;
  v12 = this->m_pSimObject;
  if ( v12 )
  {
    m_pTransformNodeComponent = v12->m_pTransformNodeComponent;
    if ( m_pTransformNodeComponent )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
      x = m_pTransformNodeComponent->mWorldVelocity.x;
      y_low = (__m128)LODWORD(m_pTransformNodeComponent->mWorldVelocity.y);
      z = m_pTransformNodeComponent->mWorldVelocity.z;
LABEL_20:
      y_low.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(x * x)) + (float)(z * z);
      LODWORD(v11) = _mm_sqrt_ps(y_low).m128_u32[0];
      goto LABEL_21;
    }
  }
  if ( this->m_pRigidBodyComponent.m_pSimComponent )
  {
    Velocity = UFG::RigidBody::GetVelocity((UFG::RigidBody *)this->m_pRigidBodyComponent.m_pSimComponent, &result);
    x = Velocity->x;
    y_low = (__m128)LODWORD(Velocity->y);
    z = Velocity->z;
    goto LABEL_20;
  }
LABEL_21:
  v18 = m_EmitUntilSpeedLessThan >= 0.0
     && v11 < m_EmitUntilSpeedLessThan
     && (float)(mSimTime_Temp - this->m_StartTime) > 0.5;
  if ( v6 || v7 || v9 || v18 )
  {
    if ( this->m_DeleteSimObjectUponExpiry && (v22 = this->m_pSimObject) != 0i64 )
      UFG::Simulation::QueueSimObjectToBeDestroyed(&UFG::gSim, v22);
    else
      UFG::Simulation::DestroySimComponent(&UFG::gSim, this);
  }
  else
  {
    StimulusTarget = UFG::StimulusEmitterComponent::GetStimulusTarget(this);
    v20 = StimulusTarget;
    if ( !this->m_IsTargeted || StimulusTarget )
    {
      v21 = UFG::qMalloc(0x198ui64, "Stimulus", 0i64);
      if ( v21 )
        UFG::Stimulus::Stimulus((UFG::Stimulus *)v21, this, v20);
      UFG::EventDispatcher::QueueEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v21);
    }
    this->m_NextUpdateTime = mSimTime_Temp + this->m_StimulusDescription.m_MinTimeBetweenUpdates;
    if ( this->m_StimulusParameters.m_StimulusEmissionType == eSTIMULUS_EMISSION_ONE_OFF )
      UFG::StimulusEmitterComponent::DeleteMe(this);
  }
}

// File Line: 194
// RVA: 0x362790
UFG::SimObject *__fastcall UFG::StimulusEmitterComponent::GetStimulusTarget(UFG::StimulusEmitterComponent *this)
{
  UFG::SimObject *result; // rax
  UFG::SimComponent *m_pSimComponent; // r8
  UFG::SimObject *m_pPointer; // rcx

  result = 0i64;
  if ( this->m_IsTargeted )
  {
    m_pSimComponent = this->m_pStimulusTargetingSystem.m_pSimComponent;
    if ( m_pSimComponent )
    {
      return *(UFG::SimObject **)(56i64
                                * *(unsigned __int8 *)((unsigned int)this->m_StimulusTargetType
                                                     + *(_QWORD *)&m_pSimComponent[1].m_Flags
                                                     + 8i64)
                                + *(_QWORD *)&m_pSimComponent[1].m_TypeUID
                                + 40);
    }
    else
    {
      m_pPointer = this->m_pStimulusTarget.m_pPointer;
      if ( m_pPointer )
        return m_pPointer;
    }
  }
  return result;
}

// File Line: 213
// RVA: 0x351F20
void __fastcall UFG::StimulusEmitterComponent::DeleteMe(UFG::StimulusEmitterComponent *this)
{
  UFG::SimObject *m_pSimObject; // rdx

  if ( this->m_DeleteSimObjectUponExpiry && (m_pSimObject = this->m_pSimObject) != 0i64 )
    UFG::Simulation::QueueSimObjectToBeDestroyed(&UFG::gSim, m_pSimObject);
  else
    UFG::Simulation::DestroySimComponent(&UFG::gSim, this);
}

// File Line: 236
// RVA: 0x3626E0
bool __fastcall UFG::StimulusEmitterComponent::GetStimulusProducerPosition(
        UFG::StimulusEmitterComponent *this,
        UFG::qVector3 *position)
{
  UFG::SimObject *m_pSimObject; // rbx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  float y; // xmm0_4
  float z; // xmm1_4
  bool v7; // al
  UFG::qVector3 *CentreOfMass; // rax
  float v9; // xmm0_4
  float v10; // xmm1_4
  UFG::qVector3 result; // [rsp+20h] [rbp-18h] BYREF

  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject && (m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent) != 0i64 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    y = m_pTransformNodeComponent->mWorldTransform.v3.y;
    z = m_pTransformNodeComponent->mWorldTransform.v3.z;
    position->x = m_pTransformNodeComponent->mWorldTransform.v3.x;
    v7 = 1;
    position->y = y;
    position->z = z;
  }
  else if ( this->m_pRigidBodyComponent.m_pSimComponent )
  {
    CentreOfMass = UFG::RigidBody::GetCentreOfMass(
                     (UFG::RigidBody *)this->m_pRigidBodyComponent.m_pSimComponent,
                     &result);
    v9 = CentreOfMass->y;
    v10 = CentreOfMass->z;
    position->x = CentreOfMass->x;
    v7 = 1;
    position->y = v9;
    position->z = v10;
  }
  else
  {
    return 0;
  }
  return v7;
}

