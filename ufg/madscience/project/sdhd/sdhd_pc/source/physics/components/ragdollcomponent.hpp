// File Line: 42
// RVA: 0x454230
UFG::ComponentIDDesc *__fastcall UFG::RagdollComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::RagdollComponent::_DescInit )
  {
    UFG::RagdollComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::RagdollComponent::_DescInit = 1;
    UFG::RagdollComponent::_TypeUID = UFG::RagdollComponent::_TypeIDesc.mChildBitMask | (UFG::RagdollComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::RagdollComponent::_RagdollComponentTypeUID = UFG::RagdollComponent::_TypeIDesc.mChildBitMask | (UFG::RagdollComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::RagdollComponent::_TypeIDesc;
}

