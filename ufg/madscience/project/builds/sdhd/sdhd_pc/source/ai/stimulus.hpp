// File Line: 31
// RVA: 0x33B070
void __fastcall UFG::Stimulus::~Stimulus(UFG::Stimulus *this)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pStimulusTarget; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::StimulusEmitterComponent> *p_m_pStimulusProducerStimulusEmitterComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *p_m_pStimulusProducerTargetingSystemBaseComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::InventoryItemComponent> *p_m_pStimulusProducerInventoryItemComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SimObjectCharacterPropertiesComponent> *p_m_pStimulusProducerCharacterPropertiesComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v23; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v24; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v26; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::RigidBodyComponent> *p_m_pStimulusProducerRigidBodyComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v28; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v29; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v30; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v31; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AIEntityComponent> *p_m_pStimulusProducerAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v33; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v34; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v35; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v36; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pStimulusProducer; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v38; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v39; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v40; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v41; // rax
  UFG::qNode<UFG::Event,UFG::Event> *v42; // rcx
  UFG::qNode<UFG::Event,UFG::Event> *v43; // rax

  this->vfptr = (UFG::EventVtbl *)&UFG::Stimulus::`vftable;
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
  p_m_pStimulusProducerStimulusEmitterComponent = &this->m_pStimulusProducerStimulusEmitterComponent;
  if ( this->m_pStimulusProducerStimulusEmitterComponent.m_pPointer )
  {
    v8 = p_m_pStimulusProducerStimulusEmitterComponent->mPrev;
    v9 = this->m_pStimulusProducerStimulusEmitterComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_m_pStimulusProducerStimulusEmitterComponent->mPrev = p_m_pStimulusProducerStimulusEmitterComponent;
    this->m_pStimulusProducerStimulusEmitterComponent.mNext = &this->m_pStimulusProducerStimulusEmitterComponent;
  }
  this->m_pStimulusProducerStimulusEmitterComponent.m_pPointer = 0i64;
  v10 = p_m_pStimulusProducerStimulusEmitterComponent->mPrev;
  v11 = this->m_pStimulusProducerStimulusEmitterComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_m_pStimulusProducerStimulusEmitterComponent->mPrev = p_m_pStimulusProducerStimulusEmitterComponent;
  this->m_pStimulusProducerStimulusEmitterComponent.mNext = &this->m_pStimulusProducerStimulusEmitterComponent;
  p_m_pStimulusProducerTargetingSystemBaseComponent = &this->m_pStimulusProducerTargetingSystemBaseComponent;
  if ( this->m_pStimulusProducerTargetingSystemBaseComponent.m_pPointer )
  {
    v13 = p_m_pStimulusProducerTargetingSystemBaseComponent->mPrev;
    v14 = this->m_pStimulusProducerTargetingSystemBaseComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    p_m_pStimulusProducerTargetingSystemBaseComponent->mPrev = p_m_pStimulusProducerTargetingSystemBaseComponent;
    this->m_pStimulusProducerTargetingSystemBaseComponent.mNext = &this->m_pStimulusProducerTargetingSystemBaseComponent;
  }
  this->m_pStimulusProducerTargetingSystemBaseComponent.m_pPointer = 0i64;
  v15 = p_m_pStimulusProducerTargetingSystemBaseComponent->mPrev;
  v16 = this->m_pStimulusProducerTargetingSystemBaseComponent.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  p_m_pStimulusProducerTargetingSystemBaseComponent->mPrev = p_m_pStimulusProducerTargetingSystemBaseComponent;
  this->m_pStimulusProducerTargetingSystemBaseComponent.mNext = &this->m_pStimulusProducerTargetingSystemBaseComponent;
  p_m_pStimulusProducerInventoryItemComponent = &this->m_pStimulusProducerInventoryItemComponent;
  if ( this->m_pStimulusProducerInventoryItemComponent.m_pPointer )
  {
    v18 = p_m_pStimulusProducerInventoryItemComponent->mPrev;
    v19 = this->m_pStimulusProducerInventoryItemComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    p_m_pStimulusProducerInventoryItemComponent->mPrev = p_m_pStimulusProducerInventoryItemComponent;
    this->m_pStimulusProducerInventoryItemComponent.mNext = &this->m_pStimulusProducerInventoryItemComponent;
  }
  this->m_pStimulusProducerInventoryItemComponent.m_pPointer = 0i64;
  v20 = p_m_pStimulusProducerInventoryItemComponent->mPrev;
  v21 = this->m_pStimulusProducerInventoryItemComponent.mNext;
  v20->mNext = v21;
  v21->mPrev = v20;
  p_m_pStimulusProducerInventoryItemComponent->mPrev = p_m_pStimulusProducerInventoryItemComponent;
  this->m_pStimulusProducerInventoryItemComponent.mNext = &this->m_pStimulusProducerInventoryItemComponent;
  p_m_pStimulusProducerCharacterPropertiesComponent = &this->m_pStimulusProducerCharacterPropertiesComponent;
  if ( this->m_pStimulusProducerCharacterPropertiesComponent.m_pPointer )
  {
    v23 = p_m_pStimulusProducerCharacterPropertiesComponent->mPrev;
    v24 = this->m_pStimulusProducerCharacterPropertiesComponent.mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    p_m_pStimulusProducerCharacterPropertiesComponent->mPrev = p_m_pStimulusProducerCharacterPropertiesComponent;
    this->m_pStimulusProducerCharacterPropertiesComponent.mNext = &this->m_pStimulusProducerCharacterPropertiesComponent;
  }
  this->m_pStimulusProducerCharacterPropertiesComponent.m_pPointer = 0i64;
  v25 = p_m_pStimulusProducerCharacterPropertiesComponent->mPrev;
  v26 = this->m_pStimulusProducerCharacterPropertiesComponent.mNext;
  v25->mNext = v26;
  v26->mPrev = v25;
  p_m_pStimulusProducerCharacterPropertiesComponent->mPrev = p_m_pStimulusProducerCharacterPropertiesComponent;
  this->m_pStimulusProducerCharacterPropertiesComponent.mNext = &this->m_pStimulusProducerCharacterPropertiesComponent;
  p_m_pStimulusProducerRigidBodyComponent = &this->m_pStimulusProducerRigidBodyComponent;
  if ( this->m_pStimulusProducerRigidBodyComponent.m_pPointer )
  {
    v28 = p_m_pStimulusProducerRigidBodyComponent->mPrev;
    v29 = this->m_pStimulusProducerRigidBodyComponent.mNext;
    v28->mNext = v29;
    v29->mPrev = v28;
    p_m_pStimulusProducerRigidBodyComponent->mPrev = p_m_pStimulusProducerRigidBodyComponent;
    this->m_pStimulusProducerRigidBodyComponent.mNext = &this->m_pStimulusProducerRigidBodyComponent;
  }
  this->m_pStimulusProducerRigidBodyComponent.m_pPointer = 0i64;
  v30 = p_m_pStimulusProducerRigidBodyComponent->mPrev;
  v31 = this->m_pStimulusProducerRigidBodyComponent.mNext;
  v30->mNext = v31;
  v31->mPrev = v30;
  p_m_pStimulusProducerRigidBodyComponent->mPrev = p_m_pStimulusProducerRigidBodyComponent;
  this->m_pStimulusProducerRigidBodyComponent.mNext = &this->m_pStimulusProducerRigidBodyComponent;
  p_m_pStimulusProducerAIEntityComponent = &this->m_pStimulusProducerAIEntityComponent;
  if ( this->m_pStimulusProducerAIEntityComponent.m_pPointer )
  {
    v33 = p_m_pStimulusProducerAIEntityComponent->mPrev;
    v34 = this->m_pStimulusProducerAIEntityComponent.mNext;
    v33->mNext = v34;
    v34->mPrev = v33;
    p_m_pStimulusProducerAIEntityComponent->mPrev = p_m_pStimulusProducerAIEntityComponent;
    this->m_pStimulusProducerAIEntityComponent.mNext = &this->m_pStimulusProducerAIEntityComponent;
  }
  this->m_pStimulusProducerAIEntityComponent.m_pPointer = 0i64;
  v35 = p_m_pStimulusProducerAIEntityComponent->mPrev;
  v36 = this->m_pStimulusProducerAIEntityComponent.mNext;
  v35->mNext = v36;
  v36->mPrev = v35;
  p_m_pStimulusProducerAIEntityComponent->mPrev = p_m_pStimulusProducerAIEntityComponent;
  this->m_pStimulusProducerAIEntityComponent.mNext = &this->m_pStimulusProducerAIEntityComponent;
  p_m_pStimulusProducer = &this->m_pStimulusProducer;
  if ( this->m_pStimulusProducer.m_pPointer )
  {
    v38 = p_m_pStimulusProducer->mPrev;
    v39 = this->m_pStimulusProducer.mNext;
    v38->mNext = v39;
    v39->mPrev = v38;
    p_m_pStimulusProducer->mPrev = p_m_pStimulusProducer;
    this->m_pStimulusProducer.mNext = &this->m_pStimulusProducer;
  }
  this->m_pStimulusProducer.m_pPointer = 0i64;
  v40 = p_m_pStimulusProducer->mPrev;
  v41 = this->m_pStimulusProducer.mNext;
  v40->mNext = v41;
  v41->mPrev = v40;
  p_m_pStimulusProducer->mPrev = p_m_pStimulusProducer;
  this->m_pStimulusProducer.mNext = &this->m_pStimulusProducer;
  this->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
  v42 = this->mPrev;
  v43 = this->mNext;
  v42->mNext = v43;
  v43->mPrev = v42;
  this->mPrev = &this->UFG::qNode<UFG::Event,UFG::Event>;
  this->mNext = &this->UFG::qNode<UFG::Event,UFG::Event>;
}

