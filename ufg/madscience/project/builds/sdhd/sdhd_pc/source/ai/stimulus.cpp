// File Line: 23
// RVA: 0x331EE0
void __fastcall UFG::Stimulus::Stimulus(UFG::Stimulus *this, UFG::StimulusEmitterComponent *emitter, UFG::SimObject *stimulus_target)
{
  const char *v3; // r10
  unsigned int v4; // er9
  UFG::qNode<UFG::Event,UFG::Event> *v5; // rax
  float v6; // xmm1_4
  float v7; // xmm2_4
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v8; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AIEntityComponent> *v9; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::RigidBodyComponent> *v10; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SimObjectCharacterPropertiesComponent> *v11; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::InventoryItemComponent> *v12; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v13; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::StimulusEmitterComponent> *v14; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v15; // rax

  v3 = emitter->m_StimulusDescription.m_Name;
  v4 = UFG::g_StimulusEventHash;
  v5 = (UFG::qNode<UFG::Event,UFG::Event> *)&this->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  this->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
  this->m_EventUID = v4;
  this->m_NamePTR = v3;
  this->vfptr = (UFG::EventVtbl *)&UFG::Stimulus::`vftable;
  v6 = UFG::qVector3::msZero.y;
  v7 = UFG::qVector3::msZero.z;
  this->m_StimulusParameters.m_StimulusProducerOffset.x = UFG::qVector3::msZero.x;
  this->m_StimulusParameters.m_StimulusProducerOffset.y = v6;
  this->m_StimulusParameters.m_StimulusProducerOffset.z = v7;
  this->m_StimulusParameters.m_StimulusEmissionType = -1;
  this->m_StimulusParameters.m_MaxStimulusDuration = -1.0;
  this->m_StimulusParameters.m_EmitUntilSpeedLessThan = -1.0;
  v8 = &this->m_pStimulusProducer;
  v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  v8->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  v8->m_pPointer = 0i64;
  this->m_StimulusMask.mBits[0] = 0i64;
  this->m_StimulusMask.mBits[1] = 0i64;
  v9 = &this->m_pStimulusProducerAIEntityComponent;
  v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  v9->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  this->m_pStimulusProducerAIEntityComponent.m_pPointer = 0i64;
  v10 = &this->m_pStimulusProducerRigidBodyComponent;
  v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  this->m_pStimulusProducerRigidBodyComponent.m_pPointer = 0i64;
  v11 = &this->m_pStimulusProducerCharacterPropertiesComponent;
  v11->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v11->mPrev;
  v11->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v11->mPrev;
  this->m_pStimulusProducerCharacterPropertiesComponent.m_pPointer = 0i64;
  v12 = &this->m_pStimulusProducerInventoryItemComponent;
  v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
  v12->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
  this->m_pStimulusProducerInventoryItemComponent.m_pPointer = 0i64;
  v13 = &this->m_pStimulusProducerTargetingSystemBaseComponent;
  v13->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v13->mPrev;
  v13->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v13->mPrev;
  this->m_pStimulusProducerTargetingSystemBaseComponent.m_pPointer = 0i64;
  v14 = &this->m_pStimulusProducerStimulusEmitterComponent;
  v14->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v14->mPrev;
  v14->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v14->mPrev;
  this->m_pStimulusProducerStimulusEmitterComponent.m_pPointer = 0i64;
  v15 = &this->m_pStimulusTarget;
  v15->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v15->mPrev;
  v15->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v15->mPrev;
  this->m_pStimulusTarget.m_pPointer = 0i64;
  UFG::Stimulus::Init(this, emitter, stimulus_target);
}

// File Line: 28
// RVA: 0x366490
void __fastcall UFG::Stimulus::Init(UFG::Stimulus *this, UFG::StimulusEmitterComponent *emitter, UFG::SimObject *stimulus_target)
{
  UFG::Stimulus *v3; // rbx
  UFG::SimObject *v4; // rcx
  UFG::SimObject *v5; // rsi
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v6; // r10
  UFG::StimulusEmitterComponent *v7; // r11
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qList<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList,1,0> *v11; // rcx
  UFG::SimComponent *v12; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::AIEntityComponent> *v13; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::SimComponent *v17; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::SimObjectCharacterPropertiesComponent> *v18; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::SimComponent *v22; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::InventoryItemComponent> *v23; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v24; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v26; // rax
  UFG::SimComponent *v27; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v28; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v29; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v30; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v31; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::StimulusEmitterComponent> *v32; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v33; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v34; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v35; // rax
  UFG::TransformNodeComponent *v36; // rdi
  float v37; // xmm0_4
  float v38; // xmm1_4
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v39; // rdx
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
  UFG::qVector3 *v53; // rax
  float v54; // xmm0_4
  float v55; // xmm1_4
  UFG::qVector3 *v56; // rax
  float v57; // xmm0_4
  float v58; // xmm1_4
  float v59; // xmm0_4
  float v60; // xmm1_4
  UFG::qVector3 result; // [rsp+20h] [rbp-58h]
  UFG::qMatrix44 mat; // [rsp+30h] [rbp-48h]

  v3 = this;
  v4 = emitter->m_pSimObject;
  v5 = stimulus_target;
  v6 = &v3->m_pStimulusProducer;
  v7 = emitter;
  if ( v3->m_pStimulusProducer.m_pPointer )
  {
    v8 = v6->mPrev;
    v9 = v3->m_pStimulusProducer.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    v3->m_pStimulusProducer.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->m_pStimulusProducer.mPrev;
  }
  v3->m_pStimulusProducer.m_pPointer = v4;
  if ( v4 )
  {
    v10 = v4->m_SafePointerList.mNode.mPrev;
    v11 = &v4->m_SafePointerList;
    v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    v6->mPrev = v10;
    v3->m_pStimulusProducer.mNext = &v11->mNode;
    v11->mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  }
  v12 = emitter->m_pAIEntityComponent.m_pSimComponent;
  v13 = &v3->m_pStimulusProducerAIEntityComponent;
  if ( v3->m_pStimulusProducerAIEntityComponent.m_pPointer )
  {
    v14 = v13->mPrev;
    v15 = v3->m_pStimulusProducerAIEntityComponent.mNext;
    v14->mNext = v15;
    v15->mPrev = v14;
    v13->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v13->mPrev;
    v3->m_pStimulusProducerAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->m_pStimulusProducerAIEntityComponent.mPrev;
  }
  v3->m_pStimulusProducerAIEntityComponent.m_pPointer = v12;
  if ( v12 )
  {
    v16 = v12->m_SafePointerList.mNode.mPrev;
    v16->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v13->mPrev;
    v13->mPrev = v16;
    v3->m_pStimulusProducerAIEntityComponent.mNext = &v12->m_SafePointerList.mNode;
    v12->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v13->mPrev;
  }
  v17 = v7->m_pCharacterPropertiesComponent.m_pSimComponent;
  v18 = &v3->m_pStimulusProducerCharacterPropertiesComponent;
  if ( v3->m_pStimulusProducerCharacterPropertiesComponent.m_pPointer )
  {
    v19 = v18->mPrev;
    v20 = v3->m_pStimulusProducerCharacterPropertiesComponent.mNext;
    v19->mNext = v20;
    v20->mPrev = v19;
    v18->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v18->mPrev;
    v3->m_pStimulusProducerCharacterPropertiesComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->m_pStimulusProducerCharacterPropertiesComponent.mPrev;
  }
  v3->m_pStimulusProducerCharacterPropertiesComponent.m_pPointer = v17;
  if ( v17 )
  {
    v21 = v17->m_SafePointerList.mNode.mPrev;
    v21->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v18->mPrev;
    v18->mPrev = v21;
    v3->m_pStimulusProducerCharacterPropertiesComponent.mNext = &v17->m_SafePointerList.mNode;
    v17->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v18->mPrev;
  }
  v22 = v7->m_pInventoryItemComponent.m_pSimComponent;
  v23 = &v3->m_pStimulusProducerInventoryItemComponent;
  if ( v3->m_pStimulusProducerInventoryItemComponent.m_pPointer )
  {
    v24 = v23->mPrev;
    v25 = v3->m_pStimulusProducerInventoryItemComponent.mNext;
    v24->mNext = v25;
    v25->mPrev = v24;
    v23->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v23->mPrev;
    v3->m_pStimulusProducerInventoryItemComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->m_pStimulusProducerInventoryItemComponent.mPrev;
  }
  v3->m_pStimulusProducerInventoryItemComponent.m_pPointer = v22;
  if ( v22 )
  {
    v26 = v22->m_SafePointerList.mNode.mPrev;
    v26->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v23->mPrev;
    v23->mPrev = v26;
    v3->m_pStimulusProducerInventoryItemComponent.mNext = &v22->m_SafePointerList.mNode;
    v22->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v23->mPrev;
  }
  v27 = v7->m_pTargetingSystemBaseComponent.m_pSimComponent;
  v28 = &v3->m_pStimulusProducerTargetingSystemBaseComponent;
  if ( v3->m_pStimulusProducerTargetingSystemBaseComponent.m_pPointer )
  {
    v29 = v28->mPrev;
    v30 = v3->m_pStimulusProducerTargetingSystemBaseComponent.mNext;
    v29->mNext = v30;
    v30->mPrev = v29;
    v28->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v28->mPrev;
    v3->m_pStimulusProducerTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->m_pStimulusProducerTargetingSystemBaseComponent.mPrev;
  }
  v3->m_pStimulusProducerTargetingSystemBaseComponent.m_pPointer = v27;
  if ( v27 )
  {
    v31 = v27->m_SafePointerList.mNode.mPrev;
    v31->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v28->mPrev;
    v28->mPrev = v31;
    v3->m_pStimulusProducerTargetingSystemBaseComponent.mNext = &v27->m_SafePointerList.mNode;
    v27->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v28->mPrev;
  }
  v32 = &v3->m_pStimulusProducerStimulusEmitterComponent;
  if ( v3->m_pStimulusProducerStimulusEmitterComponent.m_pPointer )
  {
    v33 = v32->mPrev;
    v34 = v3->m_pStimulusProducerStimulusEmitterComponent.mNext;
    v33->mNext = v34;
    v34->mPrev = v33;
    v32->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v32->mPrev;
    v3->m_pStimulusProducerStimulusEmitterComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->m_pStimulusProducerStimulusEmitterComponent.mPrev;
  }
  v3->m_pStimulusProducerStimulusEmitterComponent.m_pPointer = (UFG::SimComponent *)&v7->vfptr;
  v35 = v7->m_SafePointerList.mNode.mPrev;
  v35->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v32->mPrev;
  v32->mPrev = v35;
  v3->m_pStimulusProducerStimulusEmitterComponent.mNext = &v7->m_SafePointerList.mNode;
  v7->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v32->mPrev;
  v36 = 0i64;
  *(_QWORD *)&v3->m_Description.m_Type = *(_QWORD *)&v7->m_StimulusDescription.m_Type;
  v3->m_Description.m_Name = v7->m_StimulusDescription.m_Name;
  *(_QWORD *)&v3->m_Description.m_NameHash = *(_QWORD *)&v7->m_StimulusDescription.m_NameHash;
  v3->m_Description.m_Desc = v7->m_StimulusDescription.m_Desc;
  *(_QWORD *)&v3->m_Description.m_MinPerceptionRadiusMetres = *(_QWORD *)&v7->m_StimulusDescription.m_MinPerceptionRadiusMetres;
  *(_QWORD *)&v3->m_Description.m_PerceptionAngleCosine = *(_QWORD *)&v7->m_StimulusDescription.m_PerceptionAngleCosine;
  *(_QWORD *)&v3->m_Description.m_EmitterVerticalAngleCosine = *(_QWORD *)&v7->m_StimulusDescription.m_EmitterVerticalAngleCosine;
  *(_QWORD *)&v3->m_Description.m_DangerRadius = *(_QWORD *)&v7->m_StimulusDescription.m_DangerRadius;
  *(_QWORD *)&v3->m_Description.m_UseAimDirection = *(_QWORD *)&v7->m_StimulusDescription.m_UseAimDirection;
  v37 = v7->m_StimulusParameters.m_StimulusProducerOffset.y;
  v38 = v7->m_StimulusParameters.m_StimulusProducerOffset.z;
  v3->m_StimulusParameters.m_StimulusProducerOffset.x = v7->m_StimulusParameters.m_StimulusProducerOffset.x;
  v3->m_StimulusParameters.m_StimulusProducerOffset.y = v37;
  v3->m_StimulusParameters.m_StimulusProducerOffset.z = v38;
  v3->m_StimulusParameters.m_StimulusEmissionType = v7->m_StimulusParameters.m_StimulusEmissionType;
  v3->m_StimulusParameters.m_MaxStimulusDuration = v7->m_StimulusParameters.m_MaxStimulusDuration;
  v3->m_StimulusParameters.m_EmitUntilSpeedLessThan = v7->m_StimulusParameters.m_EmitUntilSpeedLessThan;
  v3->m_StimulusMask.mBits[0] = 0i64;
  v3->m_StimulusMask.mBits[1] = 0i64;
  v3->m_StimulusMask.mBits[(signed __int64)(signed int)v3->m_Description.m_Type >> 6] |= 1i64 << (v3->m_Description.m_Type & 0x3F);
  v39 = &v3->m_pStimulusTarget;
  if ( v5 )
  {
    v3->m_IsTargeted = 1;
    if ( v3->m_pStimulusTarget.m_pPointer )
    {
      v40 = v39->mPrev;
      v41 = v3->m_pStimulusTarget.mNext;
      v40->mNext = v41;
      v41->mPrev = v40;
      v39->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v39->mPrev;
      v3->m_pStimulusTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->m_pStimulusTarget.mPrev;
    }
    v3->m_pStimulusTarget.m_pPointer = v5;
    v42 = v5->m_SafePointerList.mNode.mPrev;
    v42->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v39->mPrev;
    v39->mPrev = v42;
    v3->m_pStimulusTarget.mNext = &v5->m_SafePointerList.mNode;
    v5->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v39->mPrev;
  }
  else
  {
    v3->m_IsTargeted = 0;
    if ( v3->m_pStimulusTarget.m_pPointer )
    {
      v43 = v39->mPrev;
      v44 = v3->m_pStimulusTarget.mNext;
      v43->mNext = v44;
      v44->mPrev = v43;
      v39->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v39->mPrev;
      v3->m_pStimulusTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->m_pStimulusTarget.mPrev;
    }
    v3->m_pStimulusTarget.m_pPointer = 0i64;
  }
  v45 = v7->m_pSimObject;
  if ( v45 )
    v36 = v45->m_pTransformNodeComponent;
  v46 = (UFG::RigidBody *)v7->m_pRigidBodyComponent.m_pSimComponent;
  if ( v36 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v36);
    v47 = v36->mWorldTransform.v3.y;
    v48 = v36->mWorldTransform.v3.z;
    v3->m_StimulusProducerPosition.x = v36->mWorldTransform.v3.x;
    v3->m_StimulusProducerPosition.y = v47;
    v3->m_StimulusProducerPosition.z = v48;
    UFG::TransformNodeComponent::UpdateWorldTransform(v36);
    v49 = v36->mWorldVelocity.y;
    v50 = v36->mWorldVelocity.z;
    v3->m_StimulusProducerVelocity.x = v36->mWorldVelocity.x;
    v3->m_StimulusProducerVelocity.y = v49;
    v3->m_StimulusProducerVelocity.z = v50;
    UFG::TransformNodeComponent::UpdateWorldTransform(v36);
    v51 = v36->mWorldTransform.v0.y;
    v52 = v36->mWorldTransform.v0.z;
    v3->m_StimulusProducerFacing.x = v36->mWorldTransform.v0.x;
    v3->m_StimulusProducerFacing.y = v51;
    v3->m_StimulusProducerFacing.z = v52;
    v3->m_StimulusProducerInfoValid = 1;
  }
  else if ( v46 )
  {
    UFG::RigidBody::GetTransform((UFG::RigidBody *)v7->m_pRigidBodyComponent.m_pSimComponent, &mat);
    v53 = UFG::RigidBody::GetCentreOfMass(v46, &result);
    v54 = v53->y;
    v55 = v53->z;
    v3->m_StimulusProducerPosition.x = v53->x;
    v3->m_StimulusProducerPosition.y = v54;
    v3->m_StimulusProducerPosition.z = v55;
    v56 = UFG::RigidBody::GetVelocity(v46, &result);
    v57 = v56->y;
    v58 = v56->z;
    v3->m_StimulusProducerVelocity.x = v56->x;
    v3->m_StimulusProducerVelocity.y = v57;
    v59 = mat.v0.x;
    v3->m_StimulusProducerVelocity.z = v58;
    v60 = mat.v0.y;
    v3->m_StimulusProducerFacing.x = v59;
    v3->m_StimulusProducerFacing.z = mat.v0.z;
    v3->m_StimulusProducerFacing.y = v60;
    v3->m_StimulusProducerInfoValid = 1;
  }
  else
  {
    v3->m_StimulusProducerInfoValid = 0;
  }
}

