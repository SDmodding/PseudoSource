// File Line: 10
// RVA: 0x32EA90
void __fastcall UFG::GameNavResourcePowerManagement::GameNavResourcePowerManagement(
        UFG::GameNavResourcePowerManagement *this,
        UFG::qSymbol *name,
        UFG::PowerManagementComponent *pPowerManagementComponent)
{
  UFG::qSafePointer<UFG::PowerManagementComponent,UFG::PowerManagementComponent> *p_mpPowerManagementComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::PowerManagementComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::PowerManagementComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::PowerManagementComponent>,UFG::qSafePointerNodeList> *v6; // rax

  this->vfptr = (UFG::NavResourceVtbl *)&UFG::NavResource::`vftable;
  this->m_name = (UFG::qSymbol)name->mUID;
  this->m_tag = -1;
  this->vfptr = (UFG::NavResourceVtbl *)&UFG::GameNavResourcePowerManagement::`vftable;
  p_mpPowerManagementComponent = &this->mpPowerManagementComponent;
  this->mpPowerManagementComponent.mPrev = &this->mpPowerManagementComponent;
  this->mpPowerManagementComponent.mNext = &this->mpPowerManagementComponent;
  this->mpPowerManagementComponent.m_pPointer = 0i64;
  if ( this->mpPowerManagementComponent.m_pPointer )
  {
    mPrev = p_mpPowerManagementComponent->mPrev;
    mNext = p_mpPowerManagementComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mpPowerManagementComponent->mPrev = p_mpPowerManagementComponent;
    p_mpPowerManagementComponent->mNext = p_mpPowerManagementComponent;
  }
  p_mpPowerManagementComponent->m_pPointer = pPowerManagementComponent;
  if ( pPowerManagementComponent )
  {
    v6 = pPowerManagementComponent->UFG::qSafePointerNode<UFG::PowerManagementComponent>::m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::PowerManagementComponent>::mPrev;
    v6->mNext = p_mpPowerManagementComponent;
    p_mpPowerManagementComponent->mPrev = v6;
    p_mpPowerManagementComponent->mNext = &pPowerManagementComponent->UFG::qSafePointerNode<UFG::PowerManagementComponent>::m_SafePointerList.mNode;
    pPowerManagementComponent->UFG::qSafePointerNode<UFG::PowerManagementComponent>::m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::PowerManagementComponent>::mPrev = p_mpPowerManagementComponent;
  }
}

// File Line: 15
// RVA: 0x337260
void __fastcall UFG::GameNavResourcePowerManagement::~GameNavResourcePowerManagement(
        UFG::GameNavResourcePowerManagement *this)
{
  UFG::qSafePointer<UFG::PowerManagementComponent,UFG::PowerManagementComponent> *p_mpPowerManagementComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::PowerManagementComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::PowerManagementComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::PowerManagementComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::PowerManagementComponent>,UFG::qSafePointerNodeList> *v6; // rax

  this->vfptr = (UFG::NavResourceVtbl *)&UFG::GameNavResourcePowerManagement::`vftable;
  p_mpPowerManagementComponent = &this->mpPowerManagementComponent;
  if ( this->mpPowerManagementComponent.m_pPointer )
  {
    mPrev = p_mpPowerManagementComponent->mPrev;
    mNext = p_mpPowerManagementComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mpPowerManagementComponent->mPrev = p_mpPowerManagementComponent;
    p_mpPowerManagementComponent->mNext = p_mpPowerManagementComponent;
  }
  p_mpPowerManagementComponent->m_pPointer = 0i64;
  v5 = p_mpPowerManagementComponent->mPrev;
  v6 = p_mpPowerManagementComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_mpPowerManagementComponent->mPrev = p_mpPowerManagementComponent;
  p_mpPowerManagementComponent->mNext = p_mpPowerManagementComponent;
  this->vfptr = (UFG::NavResourceVtbl *)&UFG::NavResource::`vftable;
}

// File Line: 19
// RVA: 0x380340
void __fastcall UFG::GameNavResourcePowerManagement::Reference(UFG::GameNavResourcePowerManagement *this)
{
  UFG::PowerManagementComponent *m_pPointer; // rcx

  m_pPointer = this->mpPowerManagementComponent.m_pPointer;
  if ( m_pPointer )
    UFG::PowerManagementComponent::AddPreventSuspendRefCount(m_pPointer);
}

// File Line: 29
// RVA: 0x352140
void __fastcall UFG::GameNavResourcePowerManagement::Dereference(UFG::GameNavResourcePowerManagement *this)
{
  UFG::PowerManagementComponent *m_pPointer; // rcx

  m_pPointer = this->mpPowerManagementComponent.m_pPointer;
  if ( m_pPointer )
    UFG::PowerManagementComponent::RemovePreventSuspendRefCount(m_pPointer);
}

