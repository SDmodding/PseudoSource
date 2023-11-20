// File Line: 35
// RVA: 0x6444F0
UFG::ComponentIDDesc *__fastcall UFG::RoadSpaceComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::RoadSpaceComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::RoadSpaceComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::RoadSpaceComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::RoadSpaceComponent::_DescInit = 1;
    UFG::RoadSpaceComponent::_TypeUID = UFG::RoadSpaceComponent::_TypeIDesc.mChildBitMask | (UFG::RoadSpaceComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::RoadSpaceComponent::_RoadSpaceComponentTypeUID = UFG::RoadSpaceComponent::_TypeIDesc.mChildBitMask | (UFG::RoadSpaceComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::RoadSpaceComponent::_TypeIDesc;
}

