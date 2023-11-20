// File Line: 33
// RVA: 0x51F100
UFG::ComponentIDDesc *__fastcall UFG::HudComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::HudComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::HudComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::HudComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::HudComponent::_DescInit = 1;
    UFG::HudComponent::_TypeUID = UFG::HudComponent::_TypeIDesc.mChildBitMask | (UFG::HudComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::HudComponent::_HudComponentTypeUID = UFG::HudComponent::_TypeIDesc.mChildBitMask | (UFG::HudComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::HudComponent::_TypeIDesc;
}

