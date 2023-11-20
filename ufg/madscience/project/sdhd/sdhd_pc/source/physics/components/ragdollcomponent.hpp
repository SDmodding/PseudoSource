// File Line: 42
// RVA: 0x454230
UFG::ComponentIDDesc *__fastcall UFG::RagdollComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::RagdollComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::RagdollComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::RagdollComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::RagdollComponent::_DescInit = 1;
    UFG::RagdollComponent::_TypeUID = UFG::RagdollComponent::_TypeIDesc.mChildBitMask | (UFG::RagdollComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::RagdollComponent::_RagdollComponentTypeUID = UFG::RagdollComponent::_TypeIDesc.mChildBitMask | (UFG::RagdollComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::RagdollComponent::_TypeIDesc;
}

