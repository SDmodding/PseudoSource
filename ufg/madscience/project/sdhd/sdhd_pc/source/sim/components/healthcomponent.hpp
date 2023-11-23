// File Line: 42
// RVA: 0x51F020
UFG::ComponentIDDesc *__fastcall UFG::HealthComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::HealthComponent::_DescInit )
  {
    UFG::HealthComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::HealthComponent::_DescInit = 1;
    UFG::HealthComponent::_TypeUID = UFG::HealthComponent::_TypeIDesc.mChildBitMask | (UFG::HealthComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::HealthComponent::_HealthComponentTypeUID = UFG::HealthComponent::_TypeIDesc.mChildBitMask | (UFG::HealthComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::HealthComponent::_TypeIDesc;
}

