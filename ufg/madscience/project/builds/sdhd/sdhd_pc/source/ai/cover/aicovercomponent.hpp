// File Line: 25
// RVA: 0x33EE20
UFG::ComponentIDDesc *__fastcall UFG::AICoverComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::AICoverComponent::_DescInit )
  {
    UFG::AICoverComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::AICoverComponent::_DescInit = 1;
    UFG::AICoverComponent::_TypeUID = UFG::AICoverComponent::_TypeIDesc.mChildBitMask | (UFG::AICoverComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::AICoverComponent::_AICoverComponentTypeUID = UFG::AICoverComponent::_TypeIDesc.mChildBitMask | (UFG::AICoverComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::AICoverComponent::_TypeIDesc;
}

