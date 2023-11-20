// File Line: 49
// RVA: 0x518000
void __fastcall UFG::InteractionPoint::InteractionPoint(UFG::InteractionPoint *this)
{
  UFG::InteractionPoint *v1; // rbx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v2; // [rsp+48h] [rbp+10h]

  v1 = this;
  UFG::qSafePointerNode<UFG::InteractionPoint>::qSafePointerNode<UFG::InteractionPoint>((UFG::qSafePointerNode<UFG::InteractionPoint> *)&this->vfptr);
  v1->vfptr = (UFG::qSafePointerNode<UFG::InteractionPoint>Vtbl *)&UFG::InteractionPoint::`vftable';
  v1->m_InteractorList.p = 0i64;
  *(_QWORD *)&v1->m_InteractorList.size = 0i64;
  v1->m_eInteractionPointUpdate = 0;
  v2 = &v1->m_pSimObject;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v1->m_pSimObject.m_pPointer = 0i64;
  v1->m_uBoneUID = UFG::gNullQSymbolUC;
  v1->m_eOffsetTarget = 0;
  v1->m_bIsActive = 0;
}

// File Line: 107
// RVA: 0x51F1E0
UFG::ComponentIDDesc *__fastcall UFG::InteractorComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::InteractorComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::InteractorComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::InteractorComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::InteractorComponent::_DescInit = 1;
    UFG::InteractorComponent::_TypeUID = UFG::InteractorComponent::_TypeIDesc.mChildBitMask | (UFG::InteractorComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::InteractorComponent::_InteractorComponentTypeUID = UFG::InteractorComponent::_TypeIDesc.mChildBitMask | (UFG::InteractorComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::InteractorComponent::_TypeIDesc;
}

// File Line: 177
// RVA: 0x51F170
UFG::ComponentIDDesc *__fastcall UFG::InteractableComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::InteractableComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::InteractableComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::InteractableComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::InteractableComponent::_DescInit = 1;
    UFG::InteractableComponent::_TypeUID = UFG::InteractableComponent::_TypeIDesc.mChildBitMask | (UFG::InteractableComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::InteractableComponent::_InteractableComponentTypeUID = UFG::InteractableComponent::_TypeIDesc.mChildBitMask | (UFG::InteractableComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::InteractableComponent::_TypeIDesc;
}

