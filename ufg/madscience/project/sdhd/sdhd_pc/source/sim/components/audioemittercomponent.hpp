// File Line: 28
// RVA: 0x57E6F0
UFG::ComponentIDDesc *__fastcall UFG::AudioEmitterComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::AudioEmitterComponent::_DescInit )
  {
    UFG::AudioEmitterComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::AudioEmitterComponent::_DescInit = 1;
    UFG::AudioEmitterComponent::_TypeUID = UFG::AudioEmitterComponent::_TypeIDesc.mChildBitMask | (UFG::AudioEmitterComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::AudioEmitterComponent::_AudioEmitterComponentTypeUID = UFG::AudioEmitterComponent::_TypeIDesc.mChildBitMask | (UFG::AudioEmitterComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::AudioEmitterComponent::_TypeIDesc;
}

