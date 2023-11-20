// File Line: 50
// RVA: 0x57E680
UFG::ComponentIDDesc *__fastcall UFG::ActionTreeComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::ActionTreeComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::ActionTreeComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::ActionTreeComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::ActionTreeComponent::_DescInit = 1;
    UFG::ActionTreeComponent::_TypeUID = UFG::ActionTreeComponent::_TypeIDesc.mChildBitMask | (UFG::ActionTreeComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::ActionTreeComponent::_ActionTreeComponentTypeUID = UFG::ActionTreeComponent::_TypeIDesc.mChildBitMask | (UFG::ActionTreeComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::ActionTreeComponent::_TypeIDesc;
}

