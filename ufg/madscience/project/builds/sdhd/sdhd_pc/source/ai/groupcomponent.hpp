// File Line: 84
// RVA: 0x33F430
UFG::ComponentIDDesc *__fastcall UFG::GroupComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::GroupComponent::_DescInit )
  {
    UFG::GroupComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::GroupComponent::_DescInit = 1;
    UFG::GroupComponent::_TypeUID = UFG::GroupComponent::_TypeIDesc.mChildBitMask | (UFG::GroupComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::GroupComponent::_GroupComponentTypeUID = UFG::GroupComponent::_TypeIDesc.mChildBitMask | (UFG::GroupComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::GroupComponent::_TypeIDesc;
}

