// File Line: 80
// RVA: 0x33F170
UFG::ComponentIDDesc *__fastcall UFG::AttackRightsComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::AttackRightsComponent::_DescInit )
  {
    UFG::AttackRightsComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::AttackRightsComponent::_DescInit = 1;
    UFG::AttackRightsComponent::_TypeUID = UFG::AttackRightsComponent::_TypeIDesc.mChildBitMask | (UFG::AttackRightsComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::AttackRightsComponent::_AttackRightsComponentTypeUID = UFG::AttackRightsComponent::_TypeIDesc.mChildBitMask | (UFG::AttackRightsComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::AttackRightsComponent::_TypeIDesc;
}

