// File Line: 47
// RVA: 0x51EFB0
UFG::ComponentIDDesc *__fastcall UFG::GunComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::GunComponent::_DescInit )
  {
    UFG::GunComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::GunComponent::_DescInit = 1;
    UFG::GunComponent::_TypeUID = UFG::GunComponent::_TypeIDesc.mChildBitMask | (UFG::GunComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::GunComponent::_GunComponentTypeUID = UFG::GunComponent::_TypeIDesc.mChildBitMask | (UFG::GunComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::GunComponent::_TypeIDesc;
}

