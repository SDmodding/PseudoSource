// File Line: 25
// RVA: 0x33EE20
UFG::ComponentIDDesc *__fastcall UFG::AICoverComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::AICoverComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::AICoverComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::AICoverComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::AICoverComponent::_DescInit = 1;
    UFG::AICoverComponent::_TypeUID = UFG::AICoverComponent::_TypeIDesc.mChildBitMask | (UFG::AICoverComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::AICoverComponent::_AICoverComponentTypeUID = UFG::AICoverComponent::_TypeIDesc.mChildBitMask | (UFG::AICoverComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::AICoverComponent::_TypeIDesc;
}

