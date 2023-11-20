// File Line: 61
// RVA: 0x4CC540
UFG::ComponentIDDesc *__fastcall UFG::TSActorComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::TSActorComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::TSActorComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::TSActorComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::TSActorComponent::_DescInit = 1;
    UFG::TSActorComponent::_TypeUID = UFG::TSActorComponent::_TypeIDesc.mChildBitMask | (UFG::TSActorComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::TSActorComponent::_TSActorComponentTypeUID = UFG::TSActorComponent::_TypeIDesc.mChildBitMask | (UFG::TSActorComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::TSActorComponent::_TypeIDesc;
}

