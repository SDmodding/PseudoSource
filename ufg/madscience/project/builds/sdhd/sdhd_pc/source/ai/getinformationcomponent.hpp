// File Line: 117
// RVA: 0x33F350
UFG::ComponentIDDesc *__fastcall UFG::GetInFormationComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::GetInFormationComponent::_DescInit )
  {
    UFG::GetInFormationComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::GetInFormationComponent::_DescInit = 1;
    UFG::GetInFormationComponent::_TypeUID = UFG::GetInFormationComponent::_TypeIDesc.mChildBitMask | (UFG::GetInFormationComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::GetInFormationComponent::_GetInFormationComponentTypeUID = UFG::GetInFormationComponent::_TypeIDesc.mChildBitMask | (UFG::GetInFormationComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::GetInFormationComponent::_TypeIDesc;
}

