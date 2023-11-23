// File Line: 23
// RVA: 0x331EE0
void __fastcall UFG::Stimulus::Stimulus(
        UFG::Stimulus *this,
        UFG::StimulusEmitterComponent *emitter,
        UFG::SimObject *stimulus_target)
{
  const char *m_Name; // r10
  unsigned int v4; // r9d
  float y; // xmm1_4
  float z; // xmm2_4

  m_Name = emitter->m_StimulusDescription.m_Name;
  v4 = UFG::g_StimulusEventHash;
  this->mPrev = &this->UFG::qNode<UFG::Event,UFG::Event>;
  this->mNext = &this->UFG::qNode<UFG::Event,UFG::Event>;
  this->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
  this->m_EventUID = v4;
  this->m_NamePTR = m_Name;
  this->vfptr = (UFG::EventVtbl *)&UFG::Stimulus::`vftable;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->m_StimulusParameters.m_StimulusProducerOffset.x = UFG::qVector3::msZero.x;
  this->m_StimulusParameters.m_StimulusProducerOffset.y = y;
  this->m_StimulusParameters.m_StimulusProducerOffset.z = z;
  this->m_StimulusParameters.m_StimulusEmissionType = eSTIMULUS_EMISSION_NONE;
  this->m_StimulusParameters.m_MaxStimulusDuration = -1.0;
  this->m_StimulusParameters.m_EmitUntilSpeedLessThan = -1.0;
  this->m_pStimulusProducer.mPrev = &this->m_pStimulusProducer;
  this->m_pStimulusProducer.mNext = &this->m_pStimulusProducer;
  this->m_pStimulusProducer.m_pPointer = 0i64;
  this->m_StimulusMask.mBits[0] = 0i64;
  this->m_StimulusMask.mBits[1] = 0i64;
  this->m_pStimulusProducerAIEntityComponent.mPrev = &this->m_pStimulusProducerAIEntityComponent;
  this->m_pStimulusProducerAIEntityComponent.mNext = &this->m_pStimulusProducerAIEntityComponent;
  this->m_pStimulusProducerAIEntityComponent.m_pPointer = 0i64;
  this->m_pStimulusProducerRigidBodyComponent.mPrev = &this->m_pStimulusProducerRigidBodyComponent;
  this->m_pStimulusProducerRigidBodyComponent.mNext = &this->m_pStimulusProducerRigidBodyComponent;
  this->m_pStimulusProducerRigidBodyComponent.m_pPointer = 0i64;
  this->m_pStimulusProducerCharacterPropertiesComponent.mPrev = &this->m_pStimulusProducerCharacterPropertiesComponent;
  this->m_pStimulusProducerCharacterPropertiesComponent.mNext = &this->m_pStimulusProducerCharacterPropertiesComponent;
  this->m_pStimulusProducerCharacterPropertiesComponent.m_pPointer = 0i64;
  this->m_pStimulusProducerInventoryItemComponent.mPrev = &this->m_pStimulusProducerInventoryItemComponent;
  this->m_pStimulusProducerInventoryItemComponent.mNext = &this->m_pStimulusProducerInventoryItemComponent;
  this->m_pStimulusProducerInventoryItemComponent.m_pPointer = 0i64;
  this->m_pStimulusProducerTargetingSystemBaseComponent.mPrev = &this->m_pStimulusProducerTargetingSystemBaseComponent;
  this->m_pStimulusProducerTargetingSystemBaseComponent.mNext = &this->m_pStimulusProducerTargetingSystemBaseComponent;
  this->m_pStimulusProducerTargetingSystemBaseComponent.m_pPointer = 0i64;
  this->m_pStimulusProducerStimulusEmitterComponent.mPrev = &this->m_pStimulusProducerStimulusEmitterComponent;
  this->m_pStimulusProducerStimulusEmitterComponent.mNext = &this->m_pStimulusProducerStimulusEmitterComponent;
  this->m_pStimulusProducerStimulusEmitterComponent.m_pPointer = 0i64;
  this->m_pStimulusTarget.mPrev = &this->m_pStimulusTarget;
  this->m_pStimulusTarget.mNext = &this->m_pStimulusTarget;
  this->m_pStimulusTarget.m_pPointer = 0i64;
  UFG::Stimulus::Init(this, emitter, stimulus_target);
}

// File Line: 28
// RVA: 0x366490
void __fastcall UFG::Stimulus::Init(
        UFG::Stimulus *this,
        UFG::StimulusEmitterComponent *emitter,
        UFG::SimObject *stimulus_target)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pStimulusProducer; // r10
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *p_mNode; // rcx
  UFG::SimComponent *m_pSimComponent; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::AIEntityComponent> *p_m_pStimulusProducerAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::SimComponent *v17; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::SimObjectCharacterPropertiesComponent> *p_m_pStimulusProducerCharacterPropertiesComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::SimComponent *v22; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::InventoryItemComponent> *p_m_pStimulusProducerInventoryItemComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v24; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v26; // rax
  UFG::SimComponent *v27; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *p_m_pStimulusProducerTargetingSystemBaseComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v29; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v30; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v31; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::StimulusEmitterComponent> *p_m_pStimulusProducerStimulusEmitterComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v33; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v34; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v35; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  float y; // xmm0_4
  float z; // xmm1_4
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pStimulusTarget; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v40; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v41; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v42; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v43; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v44; // rax
  UFG::SimObject *v45; // rax
  UFG::RigidBody *v46; // rsi
  float v47; // xmm0_4
  float v48; // xmm1_4
  float v49; // xmm0_4
  float v50; // xmm1_4
  float v51; // xmm0_4
  float v52; // xmm1_4
  UFG::qVector3 *CentreOfMass; // rax
  float v54; // xmm0_4
  float v55; // xmm1_4
  UFG::qVector3 *Velocity; // rax
  float v57; // xmm0_4
  float v58; // xmm1_4
  float x; // xmm0_4
  float v60; // xmm1_4
  UFG::qVector3 result; // [rsp+20h] [rbp-58h] BYREF
  UFG::qMatrix44 mat; // [rsp+30h] [rbp-48h] BYREF

  m_pSimObject = emitter->m_pSimObject;
  p_m_pStimulusProducer = &this->m_pStimulusProducer;
  if ( this->m_pStimulusProducer.m_pPointer )
  {
    mPrev = p_m_pStimulusProducer->mPrev;
    mNext = this->m_pStimulusProducer.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pStimulusProducer->mPrev = p_m_pStimulusProducer;
    this->m_pStimulusProducer.mNext = &this->m_pStimulusProducer;
  }
  this->m_pStimulusProducer.m_pPointer = m_pSimObject;
  if ( m_pSimObject )
  {
    v10 = m_pSimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    p_mNode = &m_pSimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    v10->mNext = p_m_pStimulusProducer;
    p_m_pStimulusProducer->mPrev = v10;
    this->m_pStimulusProducer.mNext = p_mNode;
    p_mNode->mPrev = p_m_pStimulusProducer;
  }
  m_pSimComponent = emitter->m_pAIEntityComponent.m_pSimComponent;
  p_m_pStimulusProducerAIEntityComponent = &this->m_pStimulusProducerAIEntityComponent;
  if ( this->m_pStimulusProducerAIEntityComponent.m_pPointer )
  {
    v14 = p_m_pStimulusProducerAIEntityComponent->mPrev;
    v15 = this->m_pStimulusProducerAIEntityComponent.mNext;
    v14->mNext = v15;
    v15->mPrev = v14;
    p_m_pStimulusProducerAIEntityComponent->mPrev = p_m_pStimulusProducerAIEntityComponent;
    this->m_pStimulusProducerAIEntityComponent.mNext = &this->m_pStimulusProducerAIEntityComponent;
  }
  this->m_pStimulusProducerAIEntityComponent.m_pPointer = m_pSimComponent;
  if ( m_pSimComponent )
  {
    v16 = m_pSimComponent->m_SafePointerList.mNode.mPrev;
    v16->mNext = p_m_pStimulusProducerAIEntityComponent;
    p_m_pStimulusProducerAIEntityComponent->mPrev = v16;
    this->m_pStimulusProducerAIEntityComponent.mNext = &m_pSimComponent->m_SafePointerList.mNode;
    m_pSimComponent->m_SafePointerList.mNode.mPrev = p_m_pStimulusProducerAIEntityComponent;
  }
  v17 = emitter->m_pCharacterPropertiesComponent.m_pSimComponent;
  p_m_pStimulusProducerCharacterPropertiesComponent = &this->m_pStimulusProducerCharacterPropertiesComponent;
  if ( this->m_pStimulusProducerCharacterPropertiesComponent.m_pPointer )
  {
    v19 = p_m_pStimulusProducerCharacterPropertiesComponent->mPrev;
    v20 = this->m_pStimulusProducerCharacterPropertiesComponent.mNext;
    v19->mNext = v20;
    v20->mPrev = v19;
    p_m_pStimulusProducerCharacterPropertiesComponent->mPrev = p_m_pStimulusProducerCharacterPropertiesComponent;
    this->m_pStimulusProducerCharacterPropertiesComponent.mNext = &this->m_pStimulusProducerCharacterPropertiesComponent;
  }
  this->m_pStimulusProducerCharacterPropertiesComponent.m_pPointer = v17;
  if ( v17 )
  {
    v21 = v17->m_SafePointerList.mNode.mPrev;
    v21->mNext = p_m_pStimulusProducerCharacterPropertiesComponent;
    p_m_pStimulusProducerCharacterPropertiesComponent->mPrev = v21;
    this->m_pStimulusProducerCharacterPropertiesComponent.mNext = &v17->m_SafePointerList.mNode;
    v17->m_SafePointerList.mNode.mPrev = p_m_pStimulusProducerCharacterPropertiesComponent;
  }
  v22 = emitter->m_pInventoryItemComponent.m_pSimComponent;
  p_m_pStimulusProducerInventoryItemComponent = &this->m_pStimulusProducerInventoryItemComponent;
  if ( this->m_pStimulusProducerInventoryItemComponent.m_pPointer )
  {
    v24 = p_m_pStimulusProducerInventoryItemComponent->mPrev;
    v25 = this->m_pStimulusProducerInventoryItemComponent.mNext;
    v24->mNext = v25;
    v25->mPrev = v24;
    p_m_pStimulusProducerInventoryItemComponent->mPrev = p_m_pStimulusProducerInventoryItemComponent;
    this->m_pStimulusProducerInventoryItemComponent.mNext = &this->m_pStimulusProducerInventoryItemComponent;
  }
  this->m_pStimulusProducerInventoryItemComponent.m_pPointer = v22;
  if ( v22 )
  {
    v26 = v22->m_SafePointerList.mNode.mPrev;
    v26->mNext = p_m_pStimulusProducerInventoryItemComponent;
    p_m_pStimulusProducerInventoryItemComponent->mPrev = v26;
    this->m_pStimulusProducerInventoryItemComponent.mNext = &v22->m_SafePointerList.mNode;
    v22->m_SafePointerList.mNode.mPrev = p_m_pStimulusProducerInventoryItemComponent;
  }
  v27 = emitter->m_pTargetingSystemBaseComponent.m_pSimComponent;
  p_m_pStimulusProducerTargetingSystemBaseComponent = &this->m_pStimulusProducerTargetingSystemBaseComponent;
  if ( this->m_pStimulusProducerTargetingSystemBaseComponent.m_pPointer )
  {
    v29 = p_m_pStimulusProducerTargetingSystemBaseComponent->mPrev;
    v30 = this->m_pStimulusProducerTargetingSystemBaseComponent.mNext;
    v29->mNext = v30;
    v30->mPrev = v29;
    p_m_pStimulusProducerTargetingSystemBaseComponent->mPrev = p_m_pStimulusProducerTargetingSystemBaseComponent;
    this->m_pStimulusProducerTargetingSystemBaseComponent.mNext = &this->m_pStimulusProducerTargetingSystemBaseComponent;
  }
  this->m_pStimulusProducerTargetingSystemBaseComponent.m_pPointer = v27;
  if ( v27 )
  {
    v31 = v27->m_SafePointerList.mNode.mPrev;
    v31->mNext = p_m_pStimulusProducerTargetingSystemBaseComponent;
    p_m_pStimulusProducerTargetingSystemBaseComponent->mPrev = v31;
    this->m_pStimulusProducerTargetingSystemBaseComponent.mNext = &v27->m_SafePointerList.mNode;
    v27->m_SafePointerList.mNode.mPrev = p_m_pStimulusProducerTargetingSystemBaseComponent;
  }
  p_m_pStimulusProducerStimulusEmitterComponent = &this->m_pStimulusProducerStimulusEmitterComponent;
  if ( this->m_pStimulusProducerStimulusEmitterComponent.m_pPointer )
  {
    v33 = p_m_pStimulusProducerStimulusEmitterComponent->mPrev;
    v34 = this->m_pStimulusProducerStimulusEmitterComponent.mNext;
    v33->mNext = v34;
    v34->mPrev = v33;
    p_m_pStimulusProducerStimulusEmitterComponent->mPrev = p_m_pStimulusProducerStimulusEmitterComponent;
    this->m_pStimulusProducerStimulusEmitterComponent.mNext = &this->m_pStimulusProducerStimulusEmitterComponent;
  }
  this->m_pStimulusProducerStimulusEmitterComponent.m_pPointer = emitter;
  v35 = emitter->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
  v35->mNext = p_m_pStimulusProducerStimulusEmitterComponent;
  p_m_pStimulusProducerStimulusEmitterComponent->mPrev = v35;
  this->m_pStimulusProducerStimulusEmitterComponent.mNext = &emitter->m_SafePointerList.mNode;
  emitter->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = p_m_pStimulusProducerStimulusEmitterComponent;
  m_pTransformNodeComponent = 0i64;
  *(_QWORD *)&this->m_Description.m_Type = *(_QWORD *)&emitter->m_StimulusDescription.m_Type;
  this->m_Description.m_Name = emitter->m_StimulusDescription.m_Name;
  *(_QWORD *)&this->m_Description.m_NameHash = *(_QWORD *)&emitter->m_StimulusDescription.m_NameHash;
  this->m_Description.m_Desc = emitter->m_StimulusDescription.m_Desc;
  *(_QWORD *)&this->m_Description.m_MinPerceptionRadiusMetres = *(_QWORD *)&emitter->m_StimulusDescription.m_MinPerceptionRadiusMetres;
  *(_QWORD *)&this->m_Description.m_PerceptionAngleCosine = *(_QWORD *)&emitter->m_StimulusDescription.m_PerceptionAngleCosine;
  *(_QWORD *)&this->m_Description.m_EmitterVerticalAngleCosine = *(_QWORD *)&emitter->m_StimulusDescription.m_EmitterVerticalAngleCosine;
  *(_QWORD *)&this->m_Description.m_DangerRadius = *(_QWORD *)&emitter->m_StimulusDescription.m_DangerRadius;
  *(_QWORD *)&this->m_Description.m_UseAimDirection = *(_QWORD *)&emitter->m_StimulusDescription.m_UseAimDirection;
  y = emitter->m_StimulusParameters.m_StimulusProducerOffset.y;
  z = emitter->m_StimulusParameters.m_StimulusProducerOffset.z;
  this->m_StimulusParameters.m_StimulusProducerOffset.x = emitter->m_StimulusParameters.m_StimulusProducerOffset.x;
  this->m_StimulusParameters.m_StimulusProducerOffset.y = y;
  this->m_StimulusParameters.m_StimulusProducerOffset.z = z;
  this->m_StimulusParameters.m_StimulusEmissionType = emitter->m_StimulusParameters.m_StimulusEmissionType;
  this->m_StimulusParameters.m_MaxStimulusDuration = emitter->m_StimulusParameters.m_MaxStimulusDuration;
  this->m_StimulusParameters.m_EmitUntilSpeedLessThan = emitter->m_StimulusParameters.m_EmitUntilSpeedLessThan;
  this->m_StimulusMask.mBits[0] = 0i64;
  this->m_StimulusMask.mBits[1] = 0i64;
  this->m_StimulusMask.mBits[(__int64)(int)this->m_Description.m_Type >> 6] |= 1i64 << (this->m_Description.m_Type & 0x3F);
  p_m_pStimulusTarget = &this->m_pStimulusTarget;
  if ( stimulus_target )
  {
    this->m_IsTargeted = 1;
    if ( this->m_pStimulusTarget.m_pPointer )
    {
      v40 = p_m_pStimulusTarget->mPrev;
      v41 = this->m_pStimulusTarget.mNext;
      v40->mNext = v41;
      v41->mPrev = v40;
      p_m_pStimulusTarget->mPrev = p_m_pStimulusTarget;
      this->m_pStimulusTarget.mNext = &this->m_pStimulusTarget;
    }
    this->m_pStimulusTarget.m_pPointer = stimulus_target;
    v42 = stimulus_target->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v42->mNext = p_m_pStimulusTarget;
    p_m_pStimulusTarget->mPrev = v42;
    this->m_pStimulusTarget.mNext = &stimulus_target->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    stimulus_target->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_m_pStimulusTarget;
  }
  else
  {
    this->m_IsTargeted = 0;
    if ( this->m_pStimulusTarget.m_pPointer )
    {
      v43 = p_m_pStimulusTarget->mPrev;
      v44 = this->m_pStimulusTarget.mNext;
      v43->mNext = v44;
      v44->mPrev = v43;
      p_m_pStimulusTarget->mPrev = p_m_pStimulusTarget;
      this->m_pStimulusTarget.mNext = &this->m_pStimulusTarget;
    }
    this->m_pStimulusTarget.m_pPointer = 0i64;
  }
  v45 = emitter->m_pSimObject;
  if ( v45 )
    m_pTransformNodeComponent = v45->m_pTransformNodeComponent;
  v46 = (UFG::RigidBody *)emitter->m_pRigidBodyComponent.m_pSimComponent;
  if ( m_pTransformNodeComponent )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    v47 = m_pTransformNodeComponent->mWorldTransform.v3.y;
    v48 = m_pTransformNodeComponent->mWorldTransform.v3.z;
    this->m_StimulusProducerPosition.x = m_pTransformNodeComponent->mWorldTransform.v3.x;
    this->m_StimulusProducerPosition.y = v47;
    this->m_StimulusProducerPosition.z = v48;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    v49 = m_pTransformNodeComponent->mWorldVelocity.y;
    v50 = m_pTransformNodeComponent->mWorldVelocity.z;
    this->m_StimulusProducerVelocity.x = m_pTransformNodeComponent->mWorldVelocity.x;
    this->m_StimulusProducerVelocity.y = v49;
    this->m_StimulusProducerVelocity.z = v50;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    v51 = m_pTransformNodeComponent->mWorldTransform.v0.y;
    v52 = m_pTransformNodeComponent->mWorldTransform.v0.z;
    this->m_StimulusProducerFacing.x = m_pTransformNodeComponent->mWorldTransform.v0.x;
    this->m_StimulusProducerFacing.y = v51;
    this->m_StimulusProducerFacing.z = v52;
    this->m_StimulusProducerInfoValid = 1;
  }
  else if ( v46 )
  {
    UFG::RigidBody::GetTransform((UFG::RigidBody *)emitter->m_pRigidBodyComponent.m_pSimComponent, &mat);
    CentreOfMass = UFG::RigidBody::GetCentreOfMass(v46, &result);
    v54 = CentreOfMass->y;
    v55 = CentreOfMass->z;
    this->m_StimulusProducerPosition.x = CentreOfMass->x;
    this->m_StimulusProducerPosition.y = v54;
    this->m_StimulusProducerPosition.z = v55;
    Velocity = UFG::RigidBody::GetVelocity(v46, &result);
    v57 = Velocity->y;
    v58 = Velocity->z;
    this->m_StimulusProducerVelocity.x = Velocity->x;
    this->m_StimulusProducerVelocity.y = v57;
    x = mat.v0.x;
    this->m_StimulusProducerVelocity.z = v58;
    v60 = mat.v0.y;
    this->m_StimulusProducerFacing.x = x;
    this->m_StimulusProducerFacing.z = mat.v0.z;
    this->m_StimulusProducerFacing.y = v60;
    this->m_StimulusProducerInfoValid = 1;
  }
  else
  {
    this->m_StimulusProducerInfoValid = 0;
  }
}ocity.z = v58;
    v60 = mat.v0.y;
    this->m_StimulusProducerFacing.x = x;
    this->m_StimulusProducerFacing.z = mat.v0.z;
    this->m_StimulusProducerFacing.y = v60;
    this->m_StimulusProducerInfoValid = 1;
  }
  else
  {
    this->m_StimulusProducerInfoValid

