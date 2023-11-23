// File Line: 42
// RVA: 0x57E760
UFG::ComponentIDDesc *__fastcall UFG::BaseAnimationComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::BaseAnimationComponent::_DescInit )
  {
    UFG::BaseAnimationComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::BaseAnimationComponent::_DescInit = 1;
    UFG::BaseAnimationComponent::_TypeUID = UFG::BaseAnimationComponent::_TypeIDesc.mChildBitMask | (UFG::BaseAnimationComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::BaseAnimationComponent::_BaseAnimationComponentTypeUID = UFG::BaseAnimationComponent::_TypeIDesc.mChildBitMask | (UFG::BaseAnimationComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::BaseAnimationComponent::_TypeIDesc;
}

