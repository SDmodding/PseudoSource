// File Line: 23
// RVA: 0x51F7F0
UFG::ComponentIDDesc *__fastcall UFG::StoreBlipComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::StoreBlipComponent::_DescInit )
  {
    UFG::StoreBlipComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::StoreBlipComponent::_DescInit = 1;
    UFG::StoreBlipComponent::_TypeUID = UFG::StoreBlipComponent::_TypeIDesc.mChildBitMask | (UFG::StoreBlipComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::StoreBlipComponent::_StoreBlipComponentTypeUID = UFG::StoreBlipComponent::_TypeIDesc.mChildBitMask | (UFG::StoreBlipComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::StoreBlipComponent::_TypeIDesc;
}

