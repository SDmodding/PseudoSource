// File Line: 28
// RVA: 0x57E6F0
UFG::ComponentIDDesc *__fastcall UFG::AudioEmitterComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::AudioEmitterComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::AudioEmitterComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::AudioEmitterComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::AudioEmitterComponent::_DescInit = 1;
    UFG::AudioEmitterComponent::_TypeUID = UFG::AudioEmitterComponent::_TypeIDesc.mChildBitMask | (UFG::AudioEmitterComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::AudioEmitterComponent::_AudioEmitterComponentTypeUID = UFG::AudioEmitterComponent::_TypeIDesc.mChildBitMask | (UFG::AudioEmitterComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::AudioEmitterComponent::_TypeIDesc;
}

