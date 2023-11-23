// File Line: 47
// RVA: 0x57EC10
UFG::ComponentIDDesc *__fastcall UFG::PowerManagementComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::PowerManagementComponent::_DescInit )
  {
    UFG::PowerManagementComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::PowerManagementComponent::_DescInit = 1;
    UFG::PowerManagementComponent::_TypeUID = UFG::PowerManagementComponent::_TypeIDesc.mChildBitMask | (UFG::PowerManagementComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::PowerManagementComponent::_PowerManagementComponentTypeUID = UFG::PowerManagementComponent::_TypeIDesc.mChildBitMask | (UFG::PowerManagementComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::PowerManagementComponent::_TypeIDesc;
}

