// File Line: 45
// RVA: 0x595C40
UFG::ComponentIDDesc *__fastcall UFG::DialogueAnimationComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::DialogueAnimationComponent::_DescInit )
  {
    UFG::DialogueAnimationComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::DialogueAnimationComponent::_DescInit = 1;
    UFG::DialogueAnimationComponent::_TypeUID = UFG::DialogueAnimationComponent::_TypeIDesc.mChildBitMask | (UFG::DialogueAnimationComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::DialogueAnimationComponent::_DialogueAnimationComponentTypeUID = UFG::DialogueAnimationComponent::_TypeIDesc.mChildBitMask | (UFG::DialogueAnimationComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::DialogueAnimationComponent::_TypeIDesc;
}

