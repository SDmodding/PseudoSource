// File Line: 47
// RVA: 0x57EC10
UFG::ComponentIDDesc *__fastcall UFG::PowerManagementComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::PowerManagementComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::PowerManagementComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::PowerManagementComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::PowerManagementComponent::_DescInit = 1;
    UFG::PowerManagementComponent::_TypeUID = UFG::PowerManagementComponent::_TypeIDesc.mChildBitMask | (UFG::PowerManagementComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::PowerManagementComponent::_PowerManagementComponentTypeUID = UFG::PowerManagementComponent::_TypeIDesc.mChildBitMask | (UFG::PowerManagementComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::PowerManagementComponent::_TypeIDesc;
}

