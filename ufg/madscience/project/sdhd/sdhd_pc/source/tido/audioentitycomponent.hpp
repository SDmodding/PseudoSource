// File Line: 39
// RVA: 0x595CB0
UFG::ComponentIDDesc *__fastcall UFG::HkAudioEntityComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::HkAudioEntityComponent::_DescInit )
  {
    UFG::HkAudioEntityComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::HkAudioEntityComponent::_DescInit = 1;
    UFG::HkAudioEntityComponent::_TypeUID = UFG::HkAudioEntityComponent::_TypeIDesc.mChildBitMask | (UFG::HkAudioEntityComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::HkAudioEntityComponent::_HkAudioEntityComponentTypeUID = UFG::HkAudioEntityComponent::_TypeIDesc.mChildBitMask | (UFG::HkAudioEntityComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::HkAudioEntityComponent::_TypeIDesc;
}

