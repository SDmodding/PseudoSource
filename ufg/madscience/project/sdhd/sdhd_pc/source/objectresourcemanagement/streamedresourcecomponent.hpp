// File Line: 40
// RVA: 0x438280
UFG::ComponentIDDesc *__fastcall UFG::StreamedResourceComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::StreamedResourceComponent::_DescInit )
  {
    UFG::StreamedResourceComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
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
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::ResourcePriorityLockComponent::_DescInit )
  {
    UFG::ResourcePriorityLockComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::ResourcePriorityLockComponent::_DescInit = 1;
    UFG::ResourcePriorityLockComponent::_TypeUID = UFG::ResourcePriorityLockComponent::_TypeIDesc.mChildBitMask | (UFG::ResourcePriorityLockComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::ResourcePriorityLockComponent::_ResourcePriorityLockComponentTypeUID = UFG::ResourcePriorityLockComponent::_TypeIDesc.mChildBitMask | (UFG::ResourcePriorityLockComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::ResourcePriorityLockComponent::_TypeIDesc;
}

