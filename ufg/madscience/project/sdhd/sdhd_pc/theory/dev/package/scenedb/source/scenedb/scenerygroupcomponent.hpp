// File Line: 55
// RVA: 0x22FED0
UFG::ComponentIDDesc *__fastcall UFG::SceneryGroupComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::SceneryGroupComponent::_DescInit )
  {
    UFG::SceneryGroupComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::SceneryGroupComponent::_DescInit = 1;
    UFG::SceneryGroupComponent::_TypeUID = UFG::SceneryGroupComponent::_TypeIDesc.mChildBitMask | (UFG::SceneryGroupComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::SceneryGroupComponent::_SceneryGroupComponentTypeUID = UFG::SceneryGroupComponent::_TypeIDesc.mChildBitMask | (UFG::SceneryGroupComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::SceneryGroupComponent::_TypeIDesc;
}

