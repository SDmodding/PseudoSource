// File Line: 54
// RVA: 0x51F250
UFG::ComponentIDDesc *__fastcall UFG::InventoryComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::InventoryComponent::_DescInit )
  {
    UFG::InventoryComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::InventoryComponent::_DescInit = 1;
    UFG::InventoryComponent::_TypeUID = UFG::InventoryComponent::_TypeIDesc.mChildBitMask | (UFG::InventoryComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::InventoryComponent::_InventoryComponentTypeUID = UFG::InventoryComponent::_TypeIDesc.mChildBitMask | (UFG::InventoryComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::InventoryComponent::_TypeIDesc;
}

// File Line: 106
// RVA: 0x52FCC0
UFG::qSymbol *__fastcall UFG::InventoryComponent::GetSellableItemProp(
        UFG::InventoryComponent *this,
        UFG::qSymbol *result)
{
  result->mUID = (unsigned int)this->m_SellableItemProp;
  return result;
}

