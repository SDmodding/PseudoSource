// File Line: 44
// RVA: 0x2969F0
UFG::ComponentIDDesc *__fastcall UFG::ActionTreeResourcesComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::ActionTreeResourcesComponent::_DescInit )
  {
    UFG::ActionTreeResourcesComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::ActionTreeResourcesComponent::_DescInit = 1;
    UFG::ActionTreeResourcesComponent::_TypeUID = UFG::ActionTreeResourcesComponent::_TypeIDesc.mChildBitMask | (UFG::ActionTreeResourcesComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::ActionTreeResourcesComponent::_ActionTreeResourcesComponentTypeUID = UFG::ActionTreeResourcesComponent::_TypeIDesc.mChildBitMask | (UFG::ActionTreeResourcesComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::ActionTreeResourcesComponent::_TypeIDesc;
}

