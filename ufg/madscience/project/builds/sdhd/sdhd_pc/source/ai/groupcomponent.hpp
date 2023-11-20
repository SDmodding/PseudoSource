// File Line: 84
// RVA: 0x33F430
UFG::ComponentIDDesc *__fastcall UFG::GroupComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::GroupComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::GroupComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::GroupComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::GroupComponent::_DescInit = 1;
    UFG::GroupComponent::_TypeUID = UFG::GroupComponent::_TypeIDesc.mChildBitMask | (UFG::GroupComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::GroupComponent::_GroupComponentTypeUID = UFG::GroupComponent::_TypeIDesc.mChildBitMask | (UFG::GroupComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::GroupComponent::_TypeIDesc;
}

