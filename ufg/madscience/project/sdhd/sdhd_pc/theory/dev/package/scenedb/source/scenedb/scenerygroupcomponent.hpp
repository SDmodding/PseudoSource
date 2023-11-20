// File Line: 55
// RVA: 0x22FED0
UFG::ComponentIDDesc *__fastcall UFG::SceneryGroupComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::SceneryGroupComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::SceneryGroupComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::SceneryGroupComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::SceneryGroupComponent::_DescInit = 1;
    UFG::SceneryGroupComponent::_TypeUID = UFG::SceneryGroupComponent::_TypeIDesc.mChildBitMask | (UFG::SceneryGroupComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::SceneryGroupComponent::_SceneryGroupComponentTypeUID = UFG::SceneryGroupComponent::_TypeIDesc.mChildBitMask | (UFG::SceneryGroupComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::SceneryGroupComponent::_TypeIDesc;
}

