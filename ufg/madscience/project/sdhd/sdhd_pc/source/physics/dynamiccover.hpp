// File Line: 122
// RVA: 0x454070
UFG::ComponentIDDesc *__fastcall UFG::DynamicCoverComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::DynamicCoverComponent::_DescInit )
  {
    UFG::DynamicCoverComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::DynamicCoverComponent::_DescInit = 1;
    UFG::DynamicCoverComponent::_TypeUID = UFG::DynamicCoverComponent::_TypeIDesc.mChildBitMask | (UFG::DynamicCoverComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::DynamicCoverComponent::_DynamicCoverComponentTypeUID = UFG::DynamicCoverComponent::_TypeIDesc.mChildBitMask | (UFG::DynamicCoverComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::DynamicCoverComponent::_TypeIDesc;
}

