// File Line: 39
// RVA: 0x595CB0
UFG::ComponentIDDesc *__fastcall UFG::HkAudioEntityComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::HkAudioEntityComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::HkAudioEntityComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::HkAudioEntityComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::HkAudioEntityComponent::_DescInit = 1;
    UFG::HkAudioEntityComponent::_TypeUID = UFG::HkAudioEntityComponent::_TypeIDesc.mChildBitMask | (UFG::HkAudioEntityComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::HkAudioEntityComponent::_HkAudioEntityComponentTypeUID = UFG::HkAudioEntityComponent::_TypeIDesc.mChildBitMask | (UFG::HkAudioEntityComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::HkAudioEntityComponent::_TypeIDesc;
}

