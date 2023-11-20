// File Line: 14
// RVA: 0x66F150
UFG::ComponentIDDesc *__fastcall UFG::VehicleOwnershipComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::VehicleOwnershipComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::VehicleOwnershipComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::VehicleOwnershipComponent::_TypeIDesc.mChildren = v0->mChildren;
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
  UFG::VehicleOwnershipComponent *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::VehicleOwnershipComponent::`vftable';
  v2 = &this->m_PriorityLockComponent;
  if ( this->m_PriorityLockComponent.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

