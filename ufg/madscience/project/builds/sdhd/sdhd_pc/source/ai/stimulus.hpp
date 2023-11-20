// File Line: 31
// RVA: 0x33B070
void __fastcall UFG::Stimulus::~Stimulus(UFG::Stimulus *this)
{
  UFG::Stimulus *v1; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::StimulusEmitterComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::InventoryItemComponent> *v17; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SimObjectCharacterPropertiesComponent> *v22; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v23; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v24; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v26; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::RigidBodyComponent> *v27; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v28; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v29; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v30; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v31; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AIEntityComponent> *v32; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v33; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v34; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v35; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v36; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v37; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v38; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v39; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v40; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v41; // rax
  UFG::qNode<UFG::Event,UFG::Event> *v42; // rdx
  UFG::qNode<UFG::Event,UFG::Event> *v43; // rcx
  UFG::qNode<UFG::Event,UFG::Event> *v44; // rax

  v1 = this;
  this->vfptr = (UFG::EventVtbl *)&UFG::Stimulus::`vftable';
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
  v7 = &v1->m_pStimulusProducerStimulusEmitterComponent;
  if ( v1->m_pStimulusProducerStimulusEmitterComponent.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->m_pStimulusProducerStimulusEmitterComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->m_pStimulusProducerStimulusEmitterComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pStimulusProducerStimulusEmitterComponent.mPrev;
  }
  v1->m_pStimulusProducerStimulusEmitterComponent.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->m_pStimulusProducerStimulusEmitterComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->m_pStimulusProducerStimulusEmitterComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pStimulusProducerStimulusEmitterComponent.mPrev;
  v12 = &v1->m_pStimulusProducerTargetingSystemBaseComponent;
  if ( v1->m_pStimulusProducerTargetingSystemBaseComponent.m_pPointer )
  {
    v13 = v12->mPrev;
    v14 = v1->m_pStimulusProducerTargetingSystemBaseComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
    v1->m_pStimulusProducerTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pStimulusProducerTargetingSystemBaseComponent.mPrev;
  }
  v1->m_pStimulusProducerTargetingSystemBaseComponent.m_pPointer = 0i64;
  v15 = v12->mPrev;
  v16 = v1->m_pStimulusProducerTargetingSystemBaseComponent.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
  v1->m_pStimulusProducerTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pStimulusProducerTargetingSystemBaseComponent.mPrev;
  v17 = &v1->m_pStimulusProducerInventoryItemComponent;
  if ( v1->m_pStimulusProducerInventoryItemComponent.m_pPointer )
  {
    v18 = v17->mPrev;
    v19 = v1->m_pStimulusProducerInventoryItemComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    v17->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
    v1->m_pStimulusProducerInventoryItemComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pStimulusProducerInventoryItemComponent.mPrev;
  }
  v1->m_pStimulusProducerInventoryItemComponent.m_pPointer = 0i64;
  v20 = v17->mPrev;
  v21 = v1->m_pStimulusProducerInventoryItemComponent.mNext;
  v20->mNext = v21;
  v21->mPrev = v20;
  v17->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
  v1->m_pStimulusProducerInventoryItemComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pStimulusProducerInventoryItemComponent.mPrev;
  v22 = &v1->m_pStimulusProducerCharacterPropertiesComponent;
  if ( v1->m_pStimulusProducerCharacterPropertiesComponent.m_pPointer )
  {
    v23 = v22->mPrev;
    v24 = v1->m_pStimulusProducerCharacterPropertiesComponent.mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    v22->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v22->mPrev;
    v1->m_pStimulusProducerCharacterPropertiesComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pStimulusProducerCharacterPropertiesComponent.mPrev;
  }
  v1->m_pStimulusProducerCharacterPropertiesComponent.m_pPointer = 0i64;
  v25 = v22->mPrev;
  v26 = v1->m_pStimulusProducerCharacterPropertiesComponent.mNext;
  v25->mNext = v26;
  v26->mPrev = v25;
  v22->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v22->mPrev;
  v1->m_pStimulusProducerCharacterPropertiesComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pStimulusProducerCharacterPropertiesComponent.mPrev;
  v27 = &v1->m_pStimulusProducerRigidBodyComponent;
  if ( v1->m_pStimulusProducerRigidBodyComponent.m_pPointer )
  {
    v28 = v27->mPrev;
    v29 = v1->m_pStimulusProducerRigidBodyComponent.mNext;
    v28->mNext = v29;
    v29->mPrev = v28;
    v27->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v27->mPrev;
    v1->m_pStimulusProducerRigidBodyComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pStimulusProducerRigidBodyComponent.mPrev;
  }
  v1->m_pStimulusProducerRigidBodyComponent.m_pPointer = 0i64;
  v30 = v27->mPrev;
  v31 = v1->m_pStimulusProducerRigidBodyComponent.mNext;
  v30->mNext = v31;
  v31->mPrev = v30;
  v27->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v27->mPrev;
  v1->m_pStimulusProducerRigidBodyComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pStimulusProducerRigidBodyComponent.mPrev;
  v32 = &v1->m_pStimulusProducerAIEntityComponent;
  if ( v1->m_pStimulusProducerAIEntityComponent.m_pPointer )
  {
    v33 = v32->mPrev;
    v34 = v1->m_pStimulusProducerAIEntityComponent.mNext;
    v33->mNext = v34;
    v34->mPrev = v33;
    v32->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v32->mPrev;
    v1->m_pStimulusProducerAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pStimulusProducerAIEntityComponent.mPrev;
  }
  v1->m_pStimulusProducerAIEntityComponent.m_pPointer = 0i64;
  v35 = v32->mPrev;
  v36 = v1->m_pStimulusProducerAIEntityComponent.mNext;
  v35->mNext = v36;
  v36->mPrev = v35;
  v32->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v32->mPrev;
  v1->m_pStimulusProducerAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pStimulusProducerAIEntityComponent.mPrev;
  v37 = &v1->m_pStimulusProducer;
  if ( v1->m_pStimulusProducer.m_pPointer )
  {
    v38 = v37->mPrev;
    v39 = v1->m_pStimulusProducer.mNext;
    v38->mNext = v39;
    v39->mPrev = v38;
    v37->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v37->mPrev;
    v1->m_pStimulusProducer.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pStimulusProducer.mPrev;
  }
  v1->m_pStimulusProducer.m_pPointer = 0i64;
  v40 = v37->mPrev;
  v41 = v1->m_pStimulusProducer.mNext;
  v40->mNext = v41;
  v41->mPrev = v40;
  v37->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v37->mPrev;
  v1->m_pStimulusProducer.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pStimulusProducer.mPrev;
  v1->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable';
  v42 = (UFG::qNode<UFG::Event,UFG::Event> *)&v1->mPrev;
  v43 = v1->mPrev;
  v44 = v1->mNext;
  v43->mNext = v44;
  v44->mPrev = v43;
  v42->mPrev = v42;
  v42->mNext = v42;
} v44;
  v44->mPrev = v43;
  v42->mPrev = v42;
  v42->mNext = v42;
}

