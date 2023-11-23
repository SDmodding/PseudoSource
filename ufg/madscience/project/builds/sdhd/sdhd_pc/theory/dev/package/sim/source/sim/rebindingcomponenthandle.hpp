// File Line: 65
// RVA: 0xB4390
void __fastcall UFG::RebindingComponentHandleBase::Unbind(UFG::RebindingComponentHandleBase *this)
{
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rax

  if ( this->m_pSimComponent )
  {
    mNext = this->mNext;
    mPrev = this->mPrev;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mNext = this;
    this->mPrev = this;
    this->m_Changed = 1;
    this->m_pSimComponent = 0i64;
    this->m_pSimObject = 0i64;
  }
  else
  {
    if ( this->m_pSimObject )
    {
      v3 = this->mPrev;
      if ( this->mPrev != this || this->mNext != this )
      {
        v4 = this->mNext;
        v3->mNext = v4;
        v4->mPrev = v3;
        this->mNext = this;
        this->m_pSimObject = 0i64;
        this->mPrev = this;
      }
    }
    this->m_Changed = 1;
  }
}

// File Line: 131
// RVA: 0x329E70
void __fastcall UFG::RebindingComponentHandle<UFG::InterestPointUserComponent,0>::RebindingComponentHandle<UFG::InterestPointUserComponent,0>(
        UFG::RebindingComponentHandle<UFG::InterestPointUserComponent,0> *this)
{
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::RebindingComponentHandle<UFG::InterestPointUserComponent,0> *v4; // rcx
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
    v4 = (UFG::RebindingComponentHandle<UFG::InterestPointUserComponent,0> *)this->mPrev;
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
  this->m_TypeUID = UFG::InterestPointUserComponent::_TypeUID;
}

// File Line: 136
// RVA: 0x332BB0
void __fastcall UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>(
        UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *this)
{
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *v4; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax

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
    v4 = (UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)this->mPrev;
    if ( v4 != this || this->mNext != this )
    {
      v5 = this->mNext;
      v4->mNext = v5;
      v5->mPrev = v4;
      this->mPrev = this;
      this->mNext = this;
      this->m_pSimObject = 0i64;
    }
  }
  this->m_Changed = 1;
  v6 = this->mPrev;
  v7 = this->mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  this->mPrev = this;
  this->mNext = this;
}

// File Line: 164
// RVA: 0x328AF0
void __fastcall UFG::RebindingComponentHandle<UFG::FormationManagerComponent,0>::BindInternal<UFG::SimObjectCharacter>(
        UFG::RebindingComponentHandle<UFG::FormationManagerComponent,0> *this,
        UFG::SimObjectCharacter *sim_object)
{
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax

  ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(sim_object, UFG::FormationManagerComponent::_TypeUID);
  if ( ComponentOfTypeHK )
  {
    mPrev = ComponentOfTypeHK->m_BoundComponentHandles.mNode.mPrev;
    mPrev->mNext = this;
    this->mPrev = mPrev;
    this->mNext = &ComponentOfTypeHK->m_BoundComponentHandles.mNode;
    ComponentOfTypeHK->m_BoundComponentHandles.mNode.mPrev = this;
    this->m_pSimComponent = ComponentOfTypeHK;
  }
  else
  {
    v6 = sim_object->m_UnboundComponentHandles.UFG::SimObjectCVBase::UFG::SimObjectGame::UFG::SimObject::mNode.mPrev;
    v6->mNext = this;
    this->mPrev = v6;
    this->mNext = &sim_object->m_UnboundComponentHandles.UFG::SimObjectCVBase::UFG::SimObjectGame::UFG::SimObject::mNode;
    sim_object->m_UnboundComponentHandles.UFG::SimObjectCVBase::UFG::SimObjectGame::UFG::SimObject::mNode.mPrev = this;
    this->m_pSimComponent = 0i64;
  }
  this->m_Changed = 1;
}

// File Line: 185
// RVA: 0x327B60
void __fastcall UFG::RebindingComponentHandle<UFG::InterestPointUserComponent,0>::Bind<UFG::SimObjectCharacter>(
        UFG::RebindingComponentHandle<UFG::InterestPointUserComponent,0> *this,
        UFG::SimObjectCharacter *sim_object)
{
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::RebindingComponentHandle<UFG::InterestPointUserComponent,0> *v6; // rcx
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
    v6 = (UFG::RebindingComponentHandle<UFG::InterestPointUserComponent,0> *)this->mPrev;
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
  this->m_TypeUID = UFG::InterestPointUserComponent::_TypeUID;
  m_pComponent = sim_object->m_Components.p[43].m_pComponent;
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
// RVA: 0x384B70
void __fastcall UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0>::Set(
        UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0> *this,
        UFG::SimObjectCharacterPropertiesComponent *component)
{
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // r8
  UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0> *v5; // rcx
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
    v5 = (UFG::RebindingComponentHandle<UFG::SimObjectCharacterPropertiesComponent,0> *)this->mPrev;
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
  this->m_TypeUID = UFG::SimObjectCharacterPropertiesComponent::_TypeUID;
  if ( component )
  {
    v7 = component->m_BoundComponentHandles.mNode.UFG::SimObjectPropertiesComponent::UFG::SimComponent::mPrev;
    v7->mNext = this;
    this->mPrev = v7;
    this->mNext = &component->m_BoundComponentHandles.mNode;
    component->m_BoundComponentHandles.mNode.UFG::SimObjectPropertiesComponent::UFG::SimComponent::mPrev = this;
    this->m_pSimComponent = component;
    this->m_pSimObject = component->m_pSimObject;
    this->m_Changed = 1;
  }
}

