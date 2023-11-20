// File Line: 131
// RVA: 0x514D70
void __fastcall UFG::RebindingComponentHandle<UFG::EncounterUnitComponent,0>::RebindingComponentHandle<UFG::EncounterUnitComponent,0>(UFG::RebindingComponentHandle<UFG::EncounterUnitComponent,0> *this)
{
  UFG::RebindingComponentHandle<UFG::EncounterUnitComponent,0> *v1; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v2; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rax

  v1 = this;
  this->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&this->mPrev;
  this->m_pSimComponent = 0i64;
  this->m_pSimObject = 0i64;
  this->m_Changed = 0;
  this->m_TypeUID = 0;
  if ( this->m_pSimComponent )
  {
    v2 = this->mPrev;
    v3 = v1->mNext;
    v2->mNext = v3;
    v3->mPrev = v2;
    v1->m_pSimComponent = 0i64;
LABEL_7:
    v1->m_pSimObject = 0i64;
    v1->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    v1->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    goto LABEL_8;
  }
  if ( this->m_pSimObject )
  {
    v4 = this->mPrev;
    if ( v4 != (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)v1
      || (UFG::RebindingComponentHandle<UFG::EncounterUnitComponent,0> *)v1->mNext != v1 )
    {
      v5 = v1->mNext;
      v4->mNext = v5;
      v5->mPrev = v4;
      goto LABEL_7;
    }
  }
LABEL_8:
  v1->m_Changed = 1;
  v1->m_TypeUID = UFG::EncounterUnitComponent::_TypeUID;
}

// File Line: 164
// RVA: 0x513970
void __fastcall UFG::RebindingComponentHandle<UFG::VehicleEffectsComponent,0>::BindInternal<UFG::SimObject>(UFG::RebindingComponentHandle<UFG::VehicleEffectsComponent,0> *this, UFG::SimObject *sim_object)
{
  UFG::SimObject *v2; // rdi
  UFG::RebindingComponentHandle<UFG::VehicleEffectsComponent,0> *v3; // rbx
  UFG::SimComponent *v4; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax

  v2 = sim_object;
  v3 = this;
  v4 = UFG::SimObject::GetComponentOfType(sim_object, UFG::VehicleEffectsComponent::_TypeUID);
  if ( v4 )
  {
    v5 = v4->m_BoundComponentHandles.mNode.mPrev;
    v5->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->mPrev;
    v3->mPrev = v5;
    v3->mNext = &v4->m_BoundComponentHandles.mNode;
    v4->m_BoundComponentHandles.mNode.mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->mPrev;
    v3->m_pSimComponent = v4;
  }
  else
  {
    v6 = v2->m_UnboundComponentHandles.mNode.mPrev;
    v6->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->mPrev;
    v3->mPrev = v6;
    v3->mNext = &v2->m_UnboundComponentHandles.mNode;
    v2->m_UnboundComponentHandles.mNode.mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->mPrev;
    v3->m_pSimComponent = 0i64;
  }
  v3->m_Changed = 1;
}

// File Line: 185
// RVA: 0x447B60
void __fastcall UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::Bind<UFG::SimObjectCharacter>(UFG::RebindingComponentHandle<UFG::RagdollComponent,0> *this, UFG::SimObjectCharacter *sim_object)
{
  UFG::SimObjectCharacter *v2; // r10
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0> *v3; // r9
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax
  UFG::SimComponent *v8; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rax

  v2 = sim_object;
  v3 = this;
  if ( this->m_pSimComponent )
  {
    v4 = this->mPrev;
    v5 = this->mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    this->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&this->mPrev;
    this->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&this->mPrev;
    this->m_pSimComponent = 0i64;
    this->m_pSimObject = 0i64;
  }
  else if ( this->m_pSimObject )
  {
    v6 = this->mPrev;
    if ( v6 != (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)v3
      || (UFG::RebindingComponentHandle<UFG::RagdollComponent,0> *)v3->mNext != v3 )
    {
      v7 = v3->mNext;
      v6->mNext = v7;
      v7->mPrev = v6;
      v3->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->mPrev;
      v3->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->mPrev;
      v3->m_pSimObject = 0i64;
    }
  }
  v3->m_Changed = 1;
  v3->m_pSimObject = (UFG::SimObject *)&sim_object->vfptr;
  v3->m_TypeUID = UFG::RagdollComponent::_TypeUID;
  v8 = sim_object->m_Components.p[42].m_pComponent;
  if ( v8 )
  {
    v9 = v8->m_BoundComponentHandles.mNode.mPrev;
    v9->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->mPrev;
    v3->mPrev = v9;
    v3->mNext = &v8->m_BoundComponentHandles.mNode;
    v8->m_BoundComponentHandles.mNode.mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->mPrev;
    v3->m_pSimComponent = v8;
  }
  else
  {
    v10 = v2->m_UnboundComponentHandles.mNode.mPrev;
    v10->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->mPrev;
    v3->mPrev = v10;
    v3->mNext = &v2->m_UnboundComponentHandles.mNode;
    v2->m_UnboundComponentHandles.mNode.mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->mPrev;
    v3->m_pSimComponent = 0i64;
  }
  v3->m_Changed = 1;
}

// File Line: 242
// RVA: 0x2DCA00
void __fastcall UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>::Set(UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *this, UFG::TargetingSystemBaseComponent *component)
{
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *v2; // r9
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax

  v2 = this;
  if ( this->m_pSimComponent )
  {
    v3 = this->mNext;
    v4 = this->mPrev;
    v4->mNext = v3;
    v3->mPrev = v4;
    this->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&this->mPrev;
    this->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&this->mPrev;
    this->m_pSimComponent = 0i64;
    this->m_pSimObject = 0i64;
  }
  else if ( this->m_pSimObject )
  {
    v5 = this->mPrev;
    if ( v5 != (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)v2
      || (UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *)v2->mNext != v2 )
    {
      v6 = v2->mNext;
      v5->mNext = v6;
      v6->mPrev = v5;
      v2->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->mPrev;
      v2->m_pSimObject = 0i64;
      v2->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->mPrev;
    }
  }
  v2->m_Changed = 1;
  v2->m_TypeUID = UFG::TargetingSystemBaseComponent::_TypeUID;
  if ( component )
  {
    v7 = component->m_BoundComponentHandles.mNode.mPrev;
    v7->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->mPrev;
    v2->mPrev = v7;
    v2->mNext = &component->m_BoundComponentHandles.mNode;
    component->m_BoundComponentHandles.mNode.mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->mPrev;
    v2->m_pSimComponent = (UFG::SimComponent *)&component->vfptr;
    v2->m_pSimObject = component->m_pSimObject;
    v2->m_Changed = 1;
  }
}

