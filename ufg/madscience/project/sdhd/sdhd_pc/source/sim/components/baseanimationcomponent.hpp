// File Line: 42
// RVA: 0x57E760
UFG::ComponentIDDesc *__fastcall UFG::BaseAnimationComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::BaseAnimationComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::BaseAnimationComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::BaseAnimationComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::BaseAnimationComponent::_DescInit = 1;
    UFG::BaseAnimationComponent::_TypeUID = UFG::BaseAnimationComponent::_TypeIDesc.mChildBitMask | (UFG::BaseAnimationComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::BaseAnimationComponent::_BaseAnimationComponentTypeUID = UFG::BaseAnimationComponent::_TypeIDesc.mChildBitMask | (UFG::BaseAnimationComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::BaseAnimationComponent::_TypeIDesc;
}

