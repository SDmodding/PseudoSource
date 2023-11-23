// File Line: 23
// RVA: 0x9FB00
UFG::ComponentIDDesc *__fastcall UFG::WaterFloatingTrackerBaseComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::WaterFloatingTrackerBaseComponent::_DescInit )
  {
    UFG::WaterFloatingTrackerBaseComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::WaterFloatingTrackerBaseComponent::_DescInit = 1;
    UFG::WaterFloatingTrackerBaseComponent::_TypeUID = UFG::WaterFloatingTrackerBaseComponent::_TypeIDesc.mChildBitMask | (UFG::WaterFloatingTrackerBaseComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::WaterFloatingTrackerBaseComponent::_WaterFloatingTrackerBaseComponentTypeUID = UFG::WaterFloatingTrackerBaseComponent::_TypeIDesc.mChildBitMask | (UFG::WaterFloatingTrackerBaseComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::WaterFloatingTrackerBaseComponent::_TypeIDesc;
}

