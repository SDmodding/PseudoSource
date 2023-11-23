// File Line: 97
// RVA: 0x33F510
UFG::ComponentIDDesc *__fastcall UFG::InterestPointUserComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::InterestPointUserComponent::_DescInit )
  {
    UFG::InterestPointUserComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::InterestPointUserComponent::_DescInit = 1;
    UFG::InterestPointUserComponent::_TypeUID = UFG::InterestPointUserComponent::_TypeIDesc.mChildBitMask | (UFG::InterestPointUserComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::InterestPointUserComponent::_InterestPointUserComponentTypeUID = UFG::InterestPointUserComponent::_TypeIDesc.mChildBitMask | (UFG::InterestPointUserComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::InterestPointUserComponent::_TypeIDesc;
}

