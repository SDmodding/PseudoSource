// File Line: 72
// RVA: 0x454330
UFG::ComponentIDDesc *__fastcall UFG::SensorComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::SensorComponent::_DescInit )
  {
    UFG::SensorComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::SensorComponent::_DescInit = 1;
    UFG::SensorComponent::_TypeUID = UFG::SensorComponent::_TypeIDesc.mChildBitMask | (UFG::SensorComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::SensorComponent::_SensorComponentTypeUID = UFG::SensorComponent::_TypeIDesc.mChildBitMask | (UFG::SensorComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::SensorComponent::_TypeIDesc;
}

