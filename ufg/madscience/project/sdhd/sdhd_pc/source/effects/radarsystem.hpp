// File Line: 82
// RVA: 0x3FE650
UFG::ComponentIDDesc *__fastcall UFG::RadarComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::RadarComponent::_DescInit )
  {
    UFG::RadarComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::RadarComponent::_DescInit = 1;
    UFG::RadarComponent::_TypeUID = UFG::RadarComponent::_TypeIDesc.mChildBitMask | (UFG::RadarComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::RadarComponent::_RadarComponentTypeUID = UFG::RadarComponent::_TypeIDesc.mChildBitMask | (UFG::RadarComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::RadarComponent::_TypeIDesc;
}

