// File Line: 30
// RVA: 0x51F2C0
UFG::ComponentIDDesc *__fastcall UFG::InventoryItemComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::InventoryItemComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::InventoryItemComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::InventoryItemComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::InventoryItemComponent::_DescInit = 1;
    UFG::InventoryItemComponent::_TypeUID = UFG::InventoryItemComponent::_TypeIDesc.mChildBitMask | (UFG::InventoryItemComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::InventoryItemComponent::_InventoryItemComponentTypeUID = UFG::InventoryItemComponent::_TypeIDesc.mChildBitMask | (UFG::InventoryItemComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::InventoryItemComponent::_TypeIDesc;
}

