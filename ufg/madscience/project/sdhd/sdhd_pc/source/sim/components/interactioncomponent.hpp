// File Line: 49
// RVA: 0x518000
void __fastcall UFG::InteractionPoint::InteractionPoint(UFG::InteractionPoint *this)
{
  UFG::qSafePointerNode<UFG::InteractionPoint>::qSafePointerNode<UFG::InteractionPoint>(this);
  this->vfptr = (UFG::qSafePointerNode<UFG::InteractionPoint>Vtbl *)&UFG::InteractionPoint::`vftable;
  this->m_InteractorList.p = 0i64;
  *(_QWORD *)&this->m_InteractorList.size = 0i64;
  this->m_eInteractionPointUpdate = eINTERACTION_POINT_UPDATE_INVALID;
  this->m_pSimObject.mPrev = &this->m_pSimObject;
  this->m_pSimObject.mNext = &this->m_pSimObject;
  this->m_pSimObject.m_pPointer = 0i64;
  this->m_uBoneUID = UFG::gNullQSymbolUC;
  this->m_eOffsetTarget = eTARGET_TYPE_INVALID;
  this->m_bIsActive = 0;
}

// File Line: 107
// RVA: 0x51F1E0
UFG::ComponentIDDesc *__fastcall UFG::InteractorComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::InteractorComponent::_DescInit )
  {
    UFG::InteractorComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
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
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::InteractableComponent::_DescInit )
  {
    UFG::InteractableComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::InteractableComponent::_DescInit = 1;
    UFG::InteractableComponent::_TypeUID = UFG::InteractableComponent::_TypeIDesc.mChildBitMask | (UFG::InteractableComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::InteractableComponent::_InteractableComponentTypeUID = UFG::InteractableComponent::_TypeIDesc.mChildBitMask | (UFG::InteractableComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::InteractableComponent::_TypeIDesc;
}

