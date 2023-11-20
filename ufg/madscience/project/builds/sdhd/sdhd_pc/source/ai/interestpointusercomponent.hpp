// File Line: 97
// RVA: 0x33F510
UFG::ComponentIDDesc *__fastcall UFG::InterestPointUserComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::InterestPointUserComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::InterestPointUserComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::InterestPointUserComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::InterestPointUserComponent::_DescInit = 1;
    UFG::InterestPointUserComponent::_TypeUID = UFG::InterestPointUserComponent::_TypeIDesc.mChildBitMask | (UFG::InterestPointUserComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::InterestPointUserComponent::_InterestPointUserComponentTypeUID = UFG::InterestPointUserComponent::_TypeIDesc.mChildBitMask | (UFG::InterestPointUserComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::InterestPointUserComponent::_TypeIDesc;
}

