// File Line: 30
// RVA: 0x51F2C0
UFG::ComponentIDDesc *__fastcall UFG::InventoryItemComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::InventoryItemComponent::_DescInit )
  {
    UFG::InventoryItemComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::InventoryItemComponent::_DescInit = 1;
    UFG::InventoryItemComponent::_TypeUID = UFG::InventoryItemComponent::_TypeIDesc.mChildBitMask | (UFG::InventoryItemComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::InventoryItemComponent::_InventoryItemComponentTypeUID = UFG::InventoryItemComponent::_TypeIDesc.mChildBitMask | (UFG::InventoryItemComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::InventoryItemComponent::_TypeIDesc;
}

