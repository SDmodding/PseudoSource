// File Line: 31
// RVA: 0x33EF00
UFG::ComponentIDDesc *__fastcall UFG::AILightWeightComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::AILightWeightComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::AILightWeightComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::AILightWeightComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::AILightWeightComponent::_DescInit = 1;
    UFG::AILightWeightComponent::_TypeUID = UFG::AILightWeightComponent::_TypeIDesc.mChildBitMask | (UFG::AILightWeightComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::AILightWeightComponent::_AILightWeightComponentTypeUID = UFG::AILightWeightComponent::_TypeIDesc.mChildBitMask | (UFG::AILightWeightComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::AILightWeightComponent::_TypeIDesc;
}

