// File Line: 131
// RVA: 0x514D70
void __fastcall UFG::RebindingComponentHandle<UFG::EncounterUnitComponent,0>::RebindingComponentHandle<UFG::EncounterUnitComponent,0>(
        UFG::RebindingComponentHandle<UFG::EncounterUnitComponent,0> *this)
{
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::RebindingComponentHandle<UFG::EncounterUnitComponent,0> *v4; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rax

  this->mPrev = this;
  this->mNext = this;
  this->m_pSimComponent = 0i64;
  this->m_pSimObject = 0i64;
  this->m_Changed = 0;
  this->m_TypeUID = 0;
  if ( this->m_pSimComponent )
  {
    mPrev = this->mPrev;
    mNext = this->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->m_pSimComponent = 0i64;
LABEL_7:
    this->m_pSimObject = 0i64;
    this->mNext = this;
    this->mPrev = this;
    goto LABEL_8;
  }
  if ( this->m_pSimObject )
  {
    v4 = (UFG::RebindingComponentHandle<UFG::EncounterUnitComponent,0> *)this->mPrev;
    if ( v4 != this || this->mNext != this )
    {
      v5 = this->mNext;
      v4->mNext = v5;
      v5->mPrev = v4;
      goto LABEL_7;
    }
  }
LABEL_8:
  this->m_Changed = 1;
  this->m_TypeUID = UFG::EncounterUnitComponent::_TypeUID;
}

// File Line: 164
// RVA: 0x513970
void __fastcall UFG::RebindingComponentHandle<UFG::VehicleEffectsComponent,0>::BindInternal<UFG::SimObject>(
        UFG::RebindingComponentHandle<UFG::VehicleEffectsComponent,0> *this,
        UFG::SimObject *sim_object)
{
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax

  ComponentOfType = UFG::SimObject::GetComponentOfType(sim_object, UFG::VehicleEffectsComponent::_TypeUID);
  if ( ComponentOfType )
  {
    mPrev = ComponentOfType->m_BoundComponentHandles.mNode.mPrev;
    mPrev->mNext = this;
    this->mPrev = mPrev;
    this->mNext = &ComponentOfType->m_BoundComponentHandles.mNode;
    ComponentOfType->m_BoundComponentHandles.mNode.mPrev = this;
    this->m_pSimComponent = ComponentOfType;
  }
  else
  {
    v6 = sim_object->m_UnboundComponentHandles.mNode.mPrev;
    v6->mNext = this;
    this->mPrev = v6;
    this->mNext = &sim_object->m_UnboundComponentHandles.mNode;
    sim_object->m_UnboundComponentHandles.mNode.mPrev = this;
    this->m_pSimComponent = 0i64;
  }
  this->m_Changed = 1;
}

// File Line: 185
// RVA: 0x447B60
void __fastcall UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::Bind<UFG::SimObjectCharacter>(
        UFG::RebindingComponentHandle<UFG::RagdollComponent,0> *this,
        UFG::SimObjectCharacter *sim_object)
{
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0> *v6; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax
  UFG::SimComponent *m_pComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rax

  if ( this->m_pSimComponent )
  {
    mPrev = this->mPrev;
    mNext = this->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mPrev = this;
    this->mNext = this;
    this->m_pSimComponent = 0i64;
    this->m_pSimObject = 0i64;
  }
  else if ( this->m_pSimObject )
  {
    v6 = (UFG::RebindingComponentHandle<UFG::RagdollComponent,0> *)this->mPrev;
    if ( v6 != this || this->mNext != this )
    {
      v7 = this->mNext;
      v6->mNext = v7;
      v7->mPrev = v6;
      this->mPrev = this;
      this->mNext = this;
      this->m_pSimObject = 0i64;
    }
  }
  this->m_Changed = 1;
  this->m_pSimObject = sim_object;
  this->m_TypeUID = UFG::RagdollComponent::_TypeUID;
  m_pComponent = sim_object->m_Components.p[42].m_pComponent;
  if ( m_pComponent )
  {
    v9 = m_pComponent->m_BoundComponentHandles.mNode.mPrev;
    v9->mNext = this;
    this->mPrev = v9;
    this->mNext = &m_pComponent->m_BoundComponentHandles.mNode;
    m_pComponent->m_BoundComponentHandles.mNode.mPrev = this;
    this->m_pSimComponent = m_pComponent;
  }
  else
  {
    v10 = sim_object->m_UnboundComponentHandles.UFG::SimObjectCVBase::UFG::SimObjectGame::UFG::SimObject::mNode.mPrev;
    v10->mNext = this;
    this->mPrev = v10;
    this->mNext = &sim_object->m_UnboundComponentHandles.UFG::SimObjectCVBase::UFG::SimObjectGame::UFG::SimObject::mNode;
    sim_object->m_UnboundComponentHandles.UFG::SimObjectCVBase::UFG::SimObjectGame::UFG::SimObject::mNode.mPrev = this;
    this->m_pSimComponent = 0i64;
  }
  this->m_Changed = 1;
}

// File Line: 242
// RVA: 0x2DCA00
void __fastcall UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>::Set(
        UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *this,
        UFG::TargetingSystemBaseComponent *component)
{
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // r8
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax

  if ( this->m_pSimComponent )
  {
    mNext = this->mNext;
    mPrev = this->mPrev;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mPrev = this;
    this->mNext = this;
    this->m_pSimComponent = 0i64;
    this->m_pSimObject = 0i64;
  }
  else if ( this->m_pSimObject )
  {
    v5 = (UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *)this->mPrev;
    if ( v5 != this || this->mNext != this )
    {
      v6 = this->mNext;
      v5->mNext = v6;
      v6->mPrev = v5;
      this->mPrev = this;
      this->m_pSimObject = 0i64;
      this->mNext = this;
    }
  }
  this->m_Changed = 1;
  this->m_TypeUID = UFG::TargetingSystemBaseComponent::_TypeUID;
  if ( component )
  {
    v7 = component->m_BoundComponentHandles.mNode.UFG::SimComponent::mPrev;
    v7->mNext = this;
    this->mPrev = v7;
    this->mNext = &component->m_BoundComponentHandles.mNode;
    component->m_BoundComponentHandles.mNode.UFG::SimComponent::mPrev = this;
    this->m_pSimComponent = component;
    this->m_pSimObject = component->m_pSimObject;
    this->m_Changed = 1;
  }
}

