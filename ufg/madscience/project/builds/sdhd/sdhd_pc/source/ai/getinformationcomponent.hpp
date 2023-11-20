// File Line: 117
// RVA: 0x33F350
UFG::ComponentIDDesc *__fastcall UFG::GetInFormationComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::GetInFormationComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::GetInFormationComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::GetInFormationComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::GetInFormationComponent::_DescInit = 1;
    UFG::GetInFormationComponent::_TypeUID = UFG::GetInFormationComponent::_TypeIDesc.mChildBitMask | (UFG::GetInFormationComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::GetInFormationComponent::_GetInFormationComponentTypeUID = UFG::GetInFormationComponent::_TypeIDesc.mChildBitMask | (UFG::GetInFormationComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::GetInFormationComponent::_TypeIDesc;
}

