// File Line: 47
// RVA: 0xFC730
UFG::ComponentIDDesc *__fastcall UFG::FlowfieldComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::FlowfieldComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::FlowfieldComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::FlowfieldComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::FlowfieldComponent::_DescInit = 1;
    UFG::FlowfieldComponent::_TypeUID = UFG::FlowfieldComponent::_TypeIDesc.mChildBitMask | (UFG::FlowfieldComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::FlowfieldComponent::_FlowfieldComponentTypeUID = UFG::FlowfieldComponent::_TypeIDesc.mChildBitMask | (UFG::FlowfieldComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::FlowfieldComponent::_TypeIDesc;
}

