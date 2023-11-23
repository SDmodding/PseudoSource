// File Line: 99
// RVA: 0x51E7B0
UFG::ComponentIDDesc *__fastcall UFG::AimingBaseComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::AimingBaseComponent::_DescInit )
  {
    UFG::AimingBaseComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::AimingBaseComponent::_DescInit = 1;
    UFG::AimingBaseComponent::_TypeUID = UFG::AimingBaseComponent::_TypeIDesc.mChildBitMask | (UFG::AimingBaseComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::AimingBaseComponent::_AimingBaseComponentTypeUID = UFG::AimingBaseComponent::_TypeIDesc.mChildBitMask | (UFG::AimingBaseComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::AimingBaseComponent::_TypeIDesc;
}

