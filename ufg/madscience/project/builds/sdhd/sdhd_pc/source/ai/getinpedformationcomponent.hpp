// File Line: 88
// RVA: 0x33F3C0
UFG::ComponentIDDesc *__fastcall UFG::GetInPedFormationComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::GetInPedFormationComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::GetInPedFormationComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::GetInPedFormationComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::GetInPedFormationComponent::_DescInit = 1;
    UFG::GetInPedFormationComponent::_TypeUID = UFG::GetInPedFormationComponent::_TypeIDesc.mChildBitMask | (UFG::GetInPedFormationComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::GetInPedFormationComponent::_GetInPedFormationComponentTypeUID = UFG::GetInPedFormationComponent::_TypeIDesc.mChildBitMask | (UFG::GetInPedFormationComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::GetInPedFormationComponent::_TypeIDesc;
}

