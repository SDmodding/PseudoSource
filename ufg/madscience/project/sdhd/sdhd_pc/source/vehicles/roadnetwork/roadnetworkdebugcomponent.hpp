// File Line: 95
// RVA: 0x644480
UFG::ComponentIDDesc *__fastcall UFG::RoadNetworkDebugComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::RoadNetworkDebugComponent::_DescInit )
  {
    UFG::RoadNetworkDebugComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::RoadNetworkDebugComponent::_DescInit = 1;
    UFG::RoadNetworkDebugComponent::_TypeUID = UFG::RoadNetworkDebugComponent::_TypeIDesc.mChildBitMask | (UFG::RoadNetworkDebugComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::RoadNetworkDebugComponent::_RoadNetworkDebugComponentTypeUID = UFG::RoadNetworkDebugComponent::_TypeIDesc.mChildBitMask | (UFG::RoadNetworkDebugComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::RoadNetworkDebugComponent::_TypeIDesc;
}

