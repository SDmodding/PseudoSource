// File Line: 54
// RVA: 0x33F4A0
UFG::ComponentIDDesc *__fastcall UFG::HasAttackRequestComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::HasAttackRequestComponent::_DescInit )
  {
    UFG::HasAttackRequestComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::HasAttackRequestComponent::_DescInit = 1;
    UFG::HasAttackRequestComponent::_TypeUID = UFG::HasAttackRequestComponent::_TypeIDesc.mChildBitMask | (UFG::HasAttackRequestComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::HasAttackRequestComponent::_HasAttackRequestComponentTypeUID = UFG::HasAttackRequestComponent::_TypeIDesc.mChildBitMask | (UFG::HasAttackRequestComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::HasAttackRequestComponent::_TypeIDesc;
}

