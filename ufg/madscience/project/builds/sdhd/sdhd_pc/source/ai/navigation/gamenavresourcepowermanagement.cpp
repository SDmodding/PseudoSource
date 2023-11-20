// File Line: 10
// RVA: 0x32EA90
void __fastcall UFG::GameNavResourcePowerManagement::GameNavResourcePowerManagement(UFG::GameNavResourcePowerManagement *this, UFG::qSymbol *name, UFG::PowerManagementComponent *pPowerManagementComponent)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::PowerManagementComponent>,UFG::qSafePointerNodeList> *v3; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::PowerManagementComponent>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::PowerManagementComponent>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::PowerManagementComponent>,UFG::qSafePointerNodeList> *v6; // rax

  this->vfptr = (UFG::NavResourceVtbl *)&UFG::NavResource::`vftable;
  this->m_name = (UFG::qSymbol)name->mUID;
  this->m_tag = -1;
  this->vfptr = (UFG::NavResourceVtbl *)&UFG::GameNavResourcePowerManagement::`vftable;
  v3 = (UFG::qNode<UFG::qSafePointerBase<UFG::PowerManagementComponent>,UFG::qSafePointerNodeList> *)&this->mpPowerManagementComponent.mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  this->mpPowerManagementComponent.m_pPointer = 0i64;
  if ( this->mpPowerManagementComponent.m_pPointer )
  {
    v4 = v3->mPrev;
    v5 = v3->mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v3->mPrev = v3;
    v3->mNext = v3;
  }
  v3[1].mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::PowerManagementComponent>,UFG::qSafePointerNodeList> *)pPowerManagementComponent;
  if ( pPowerManagementComponent )
  {
    v6 = pPowerManagementComponent->m_SafePointerList.mNode.mPrev;
    v6->mNext = v3;
    v3->mPrev = v6;
    v3->mNext = &pPowerManagementComponent->m_SafePointerList.mNode;
    pPowerManagementComponent->m_SafePointerList.mNode.mPrev = v3;
  }
}

// File Line: 15
// RVA: 0x337260
void __fastcall UFG::GameNavResourcePowerManagement::~GameNavResourcePowerManagement(UFG::GameNavResourcePowerManagement *this)
{
  UFG::GameNavResourcePowerManagement *v1; // r8
  UFG::qSafePointer<UFG::PowerManagementComponent,UFG::PowerManagementComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::PowerManagementComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::PowerManagementComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::PowerManagementComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::PowerManagementComponent>,UFG::qSafePointerNodeList> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::NavResourceVtbl *)&UFG::GameNavResourcePowerManagement::`vftable;
  v2 = &this->mpPowerManagementComponent;
  if ( this->mpPowerManagementComponent.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::PowerManagementComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::PowerManagementComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::PowerManagementComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::PowerManagementComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v1->vfptr = (UFG::NavResourceVtbl *)&UFG::NavResource::`vftable;
}

// File Line: 19
// RVA: 0x380340
void __fastcall UFG::GameNavResourcePowerManagement::Reference(UFG::GameNavResourcePowerManagement *this)
{
  JUMPOUT(this->mpPowerManagementComponent.m_pPointer, 0i64, UFG::PowerManagementComponent::AddPreventSuspendRefCount);
}

// File Line: 29
// RVA: 0x352140
void __fastcall UFG::GameNavResourcePowerManagement::Dereference(UFG::GameNavResourcePowerManagement *this)
{
  JUMPOUT(
    this->mpPowerManagementComponent.m_pPointer,
    0i64,
    UFG::PowerManagementComponent::RemovePreventSuspendRefCount);
}

