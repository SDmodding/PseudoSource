// File Line: 122
// RVA: 0x454070
UFG::ComponentIDDesc *__fastcall UFG::DynamicCoverComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::DynamicCoverComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::DynamicCoverComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::DynamicCoverComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::DynamicCoverComponent::_DescInit = 1;
    UFG::DynamicCoverComponent::_TypeUID = UFG::DynamicCoverComponent::_TypeIDesc.mChildBitMask | (UFG::DynamicCoverComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::DynamicCoverComponent::_DynamicCoverComponentTypeUID = UFG::DynamicCoverComponent::_TypeIDesc.mChildBitMask | (UFG::DynamicCoverComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::DynamicCoverComponent::_TypeIDesc;
}

