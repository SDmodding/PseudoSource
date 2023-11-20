// File Line: 58
// RVA: 0x51E940
UFG::ComponentIDDesc *__fastcall UFG::AnimationLODComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::AnimationLODComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::AnimationLODComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::AnimationLODComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::AnimationLODComponent::_DescInit = 1;
    UFG::AnimationLODComponent::_TypeUID = UFG::AnimationLODComponent::_TypeIDesc.mChildBitMask | (UFG::AnimationLODComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::AnimationLODComponent::_AnimationLODComponentTypeUID = UFG::AnimationLODComponent::_TypeIDesc.mChildBitMask | (UFG::AnimationLODComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::AnimationLODComponent::_TypeIDesc;
}

