// File Line: 14
// RVA: 0x66F150
UFG::ComponentIDDesc *__fastcall UFG::VehicleOwnershipComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::VehicleOwnershipComponent::_DescInit )
  {
    UFG::VehicleOwnershipComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::VehicleOwnershipComponent::_DescInit = 1;
    UFG::VehicleOwnershipComponent::_TypeUID = UFG::VehicleOwnershipComponent::_TypeIDesc.mChildBitMask | (UFG::VehicleOwnershipComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::VehicleOwnershipComponent::_VehicleOwnershipComponentTypeUID = UFG::VehicleOwnershipComponent::_TypeIDesc.mChildBitMask | (UFG::VehicleOwnershipComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::VehicleOwnershipComponent::_TypeIDesc;
}

// File Line: 17
// RVA: 0x66D730
void __fastcall UFG::VehicleOwnershipComponent::~VehicleOwnershipComponent(UFG::VehicleOwnershipComponent *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *p_m_PriorityLockComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::VehicleOwnershipComponent::`vftable;
  p_m_PriorityLockComponent = &this->m_PriorityLockComponent;
  if ( this->m_PriorityLockComponent.m_pPointer )
  {
    mPrev = p_m_PriorityLockComponent->mPrev;
    mNext = p_m_PriorityLockComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_PriorityLockComponent->mPrev = p_m_PriorityLockComponent;
    p_m_PriorityLockComponent->mNext = p_m_PriorityLockComponent;
  }
  p_m_PriorityLockComponent->m_pPointer = 0i64;
  v5 = p_m_PriorityLockComponent->mPrev;
  v6 = p_m_PriorityLockComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_PriorityLockComponent->mPrev = p_m_PriorityLockComponent;
  p_m_PriorityLockComponent->mNext = p_m_PriorityLockComponent;
  UFG::SimComponent::~SimComponent(this);
}

