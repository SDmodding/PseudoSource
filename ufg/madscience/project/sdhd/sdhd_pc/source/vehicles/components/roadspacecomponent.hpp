// File Line: 35
// RVA: 0x6444F0
UFG::ComponentIDDesc *__fastcall UFG::RoadSpaceComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::RoadSpaceComponent::_DescInit )
  {
    UFG::RoadSpaceComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::RoadSpaceComponent::_DescInit = 1;
    UFG::RoadSpaceComponent::_TypeUID = UFG::RoadSpaceComponent::_TypeIDesc.mChildBitMask | (UFG::RoadSpaceComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::RoadSpaceComponent::_RoadSpaceComponentTypeUID = UFG::RoadSpaceComponent::_TypeIDesc.mChildBitMask | (UFG::RoadSpaceComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::RoadSpaceComponent::_TypeIDesc;
}

