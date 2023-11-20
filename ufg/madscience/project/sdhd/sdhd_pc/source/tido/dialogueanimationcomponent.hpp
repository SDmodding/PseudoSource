// File Line: 45
// RVA: 0x595C40
UFG::ComponentIDDesc *__fastcall UFG::DialogueAnimationComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::DialogueAnimationComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::DialogueAnimationComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::DialogueAnimationComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::DialogueAnimationComponent::_DescInit = 1;
    UFG::DialogueAnimationComponent::_TypeUID = UFG::DialogueAnimationComponent::_TypeIDesc.mChildBitMask | (UFG::DialogueAnimationComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::DialogueAnimationComponent::_DialogueAnimationComponentTypeUID = UFG::DialogueAnimationComponent::_TypeIDesc.mChildBitMask | (UFG::DialogueAnimationComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::DialogueAnimationComponent::_TypeIDesc;
}

