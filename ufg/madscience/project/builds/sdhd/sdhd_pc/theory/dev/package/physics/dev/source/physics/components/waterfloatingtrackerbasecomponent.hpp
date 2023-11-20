// File Line: 23
// RVA: 0x9FB00
UFG::ComponentIDDesc *__fastcall UFG::WaterFloatingTrackerBaseComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::WaterFloatingTrackerBaseComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::WaterFloatingTrackerBaseComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::WaterFloatingTrackerBaseComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::WaterFloatingTrackerBaseComponent::_DescInit = 1;
    UFG::WaterFloatingTrackerBaseComponent::_TypeUID = UFG::WaterFloatingTrackerBaseComponent::_TypeIDesc.mChildBitMask | (UFG::WaterFloatingTrackerBaseComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::WaterFloatingTrackerBaseComponent::_WaterFloatingTrackerBaseComponentTypeUID = UFG::WaterFloatingTrackerBaseComponent::_TypeIDesc.mChildBitMask | (UFG::WaterFloatingTrackerBaseComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::WaterFloatingTrackerBaseComponent::_TypeIDesc;
}

