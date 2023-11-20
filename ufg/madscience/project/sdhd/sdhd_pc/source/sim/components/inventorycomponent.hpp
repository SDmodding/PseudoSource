// File Line: 54
// RVA: 0x51F250
UFG::ComponentIDDesc *__fastcall UFG::InventoryComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::InventoryComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::InventoryComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::InventoryComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::InventoryComponent::_DescInit = 1;
    UFG::InventoryComponent::_TypeUID = UFG::InventoryComponent::_TypeIDesc.mChildBitMask | (UFG::InventoryComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::InventoryComponent::_InventoryComponentTypeUID = UFG::InventoryComponent::_TypeIDesc.mChildBitMask | (UFG::InventoryComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::InventoryComponent::_TypeIDesc;
}

// File Line: 106
// RVA: 0x52FCC0
UFG::qSymbol *__fastcall UFG::InventoryComponent::GetSellableItemProp(UFG::InventoryComponent *this, UFG::qSymbol *result)
{
  result->mUID = (unsigned int)this->m_SellableItemProp;
  return result;
}

