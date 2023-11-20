// File Line: 37
// RVA: 0x41A040
UFG::ComponentIDDesc *__fastcall UFG::TurfComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::TurfComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::TurfComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::TurfComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::TurfComponent::_DescInit = 1;
    UFG::TurfComponent::_TypeUID = UFG::TurfComponent::_TypeIDesc.mChildBitMask | (UFG::TurfComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::TurfComponent::_TurfComponentTypeUID = UFG::TurfComponent::_TypeIDesc.mChildBitMask | (UFG::TurfComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::TurfComponent::_TypeIDesc;
}

