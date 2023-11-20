// File Line: 95
// RVA: 0x644480
UFG::ComponentIDDesc *__fastcall UFG::RoadNetworkDebugComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::RoadNetworkDebugComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::RoadNetworkDebugComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::RoadNetworkDebugComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::RoadNetworkDebugComponent::_DescInit = 1;
    UFG::RoadNetworkDebugComponent::_TypeUID = UFG::RoadNetworkDebugComponent::_TypeIDesc.mChildBitMask | (UFG::RoadNetworkDebugComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::RoadNetworkDebugComponent::_RoadNetworkDebugComponentTypeUID = UFG::RoadNetworkDebugComponent::_TypeIDesc.mChildBitMask | (UFG::RoadNetworkDebugComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::RoadNetworkDebugComponent::_TypeIDesc;
}

