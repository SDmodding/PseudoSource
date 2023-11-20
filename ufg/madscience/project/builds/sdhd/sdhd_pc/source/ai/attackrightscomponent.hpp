// File Line: 80
// RVA: 0x33F170
UFG::ComponentIDDesc *__fastcall UFG::AttackRightsComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::AttackRightsComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::AttackRightsComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::AttackRightsComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::AttackRightsComponent::_DescInit = 1;
    UFG::AttackRightsComponent::_TypeUID = UFG::AttackRightsComponent::_TypeIDesc.mChildBitMask | (UFG::AttackRightsComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::AttackRightsComponent::_AttackRightsComponentTypeUID = UFG::AttackRightsComponent::_TypeIDesc.mChildBitMask | (UFG::AttackRightsComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::AttackRightsComponent::_TypeIDesc;
}

