// File Line: 58
// RVA: 0x51E940
UFG::ComponentIDDesc *__fastcall UFG::AnimationLODComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::AnimationLODComponent::_DescInit )
  {
    UFG::AnimationLODComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::AnimationLODComponent::_DescInit = 1;
    UFG::AnimationLODComponent::_TypeUID = UFG::AnimationLODComponent::_TypeIDesc.mChildBitMask | (UFG::AnimationLODComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::AnimationLODComponent::_AnimationLODComponentTypeUID = UFG::AnimationLODComponent::_TypeIDesc.mChildBitMask | (UFG::AnimationLODComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::AnimationLODComponent::_TypeIDesc;
}

