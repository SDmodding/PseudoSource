// File Line: 44
// RVA: 0x2969F0
UFG::ComponentIDDesc *__fastcall UFG::ActionTreeResourcesComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::ActionTreeResourcesComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::ActionTreeResourcesComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::ActionTreeResourcesComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::ActionTreeResourcesComponent::_DescInit = 1;
    UFG::ActionTreeResourcesComponent::_TypeUID = UFG::ActionTreeResourcesComponent::_TypeIDesc.mChildBitMask | (UFG::ActionTreeResourcesComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::ActionTreeResourcesComponent::_ActionTreeResourcesComponentTypeUID = UFG::ActionTreeResourcesComponent::_TypeIDesc.mChildBitMask | (UFG::ActionTreeResourcesComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::ActionTreeResourcesComponent::_TypeIDesc;
}

