// File Line: 54
// RVA: 0x33F4A0
UFG::ComponentIDDesc *__fastcall UFG::HasAttackRequestComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::HasAttackRequestComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::HasAttackRequestComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::HasAttackRequestComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::HasAttackRequestComponent::_DescInit = 1;
    UFG::HasAttackRequestComponent::_TypeUID = UFG::HasAttackRequestComponent::_TypeIDesc.mChildBitMask | (UFG::HasAttackRequestComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::HasAttackRequestComponent::_HasAttackRequestComponentTypeUID = UFG::HasAttackRequestComponent::_TypeIDesc.mChildBitMask | (UFG::HasAttackRequestComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::HasAttackRequestComponent::_TypeIDesc;
}

