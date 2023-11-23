// File Line: 31
// RVA: 0x33EF00
UFG::ComponentIDDesc *__fastcall UFG::AILightWeightComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::AILightWeightComponent::_DescInit )
  {
    UFG::AILightWeightComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::AILightWeightComponent::_DescInit = 1;
    UFG::AILightWeightComponent::_TypeUID = UFG::AILightWeightComponent::_TypeIDesc.mChildBitMask | (UFG::AILightWeightComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::AILightWeightComponent::_AILightWeightComponentTypeUID = UFG::AILightWeightComponent::_TypeIDesc.mChildBitMask | (UFG::AILightWeightComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::AILightWeightComponent::_TypeIDesc;
}

