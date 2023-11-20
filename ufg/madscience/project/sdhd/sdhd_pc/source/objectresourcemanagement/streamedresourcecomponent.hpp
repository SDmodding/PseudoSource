// File Line: 40
// RVA: 0x438280
UFG::ComponentIDDesc *__fastcall UFG::StreamedResourceComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::StreamedResourceComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::StreamedResourceComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::StreamedResourceComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::StreamedResourceComponent::_DescInit = 1;
    UFG::StreamedResourceComponent::_TypeUID = UFG::StreamedResourceComponent::_TypeIDesc.mChildBitMask | (UFG::StreamedResourceComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::StreamedResourceComponent::_StreamedResourceComponentTypeUID = UFG::StreamedResourceComponent::_TypeIDesc.mChildBitMask | (UFG::StreamedResourceComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::StreamedResourceComponent::_TypeIDesc;
}

// File Line: 158
// RVA: 0x438210
UFG::ComponentIDDesc *__fastcall UFG::ResourcePriorityLockComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::ResourcePriorityLockComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::ResourcePriorityLockComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::ResourcePriorityLockComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::ResourcePriorityLockComponent::_DescInit = 1;
    UFG::ResourcePriorityLockComponent::_TypeUID = UFG::ResourcePriorityLockComponent::_TypeIDesc.mChildBitMask | (UFG::ResourcePriorityLockComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::ResourcePriorityLockComponent::_ResourcePriorityLockComponentTypeUID = UFG::ResourcePriorityLockComponent::_TypeIDesc.mChildBitMask | (UFG::ResourcePriorityLockComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::ResourcePriorityLockComponent::_TypeIDesc;
}

