// File Line: 41
// RVA: 0x746C0
UFG::ComponentIDDesc *__fastcall UFG::DropShadowComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::DropShadowComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::DropShadowComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::DropShadowComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::DropShadowComponent::_DescInit = 1;
    UFG::DropShadowComponent::_TypeUID = UFG::DropShadowComponent::_TypeIDesc.mChildBitMask | (UFG::DropShadowComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::DropShadowComponent::_DropShadowComponentTypeUID = UFG::DropShadowComponent::_TypeIDesc.mChildBitMask | (UFG::DropShadowComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::DropShadowComponent::_TypeIDesc;
}

