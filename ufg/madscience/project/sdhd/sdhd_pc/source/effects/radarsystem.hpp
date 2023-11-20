// File Line: 82
// RVA: 0x3FE650
UFG::ComponentIDDesc *__fastcall UFG::RadarComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::RadarComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::RadarComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::RadarComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::RadarComponent::_DescInit = 1;
    UFG::RadarComponent::_TypeUID = UFG::RadarComponent::_TypeIDesc.mChildBitMask | (UFG::RadarComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::RadarComponent::_RadarComponentTypeUID = UFG::RadarComponent::_TypeIDesc.mChildBitMask | (UFG::RadarComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::RadarComponent::_TypeIDesc;
}

