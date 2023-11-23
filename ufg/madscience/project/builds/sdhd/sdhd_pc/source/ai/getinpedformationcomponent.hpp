// File Line: 88
// RVA: 0x33F3C0
UFG::ComponentIDDesc *__fastcall UFG::GetInPedFormationComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::GetInPedFormationComponent::_DescInit )
  {
    UFG::GetInPedFormationComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::GetInPedFormationComponent::_DescInit = 1;
    UFG::GetInPedFormationComponent::_TypeUID = UFG::GetInPedFormationComponent::_TypeIDesc.mChildBitMask | (UFG::GetInPedFormationComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::GetInPedFormationComponent::_GetInPedFormationComponentTypeUID = UFG::GetInPedFormationComponent::_TypeIDesc.mChildBitMask | (UFG::GetInPedFormationComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::GetInPedFormationComponent::_TypeIDesc;
}

