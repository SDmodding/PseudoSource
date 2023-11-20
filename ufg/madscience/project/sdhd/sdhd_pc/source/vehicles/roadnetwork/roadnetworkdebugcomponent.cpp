// File Line: 31
// RVA: 0x15737F0
__int64 dynamic_initializer_for__UFG::RoadNetworkDebugComponent::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = UFG::RoadNetworkDebugComponent::AccessComponentDesc();
  *(_DWORD *)&UFG::RoadNetworkDebugComponent::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  UFG::RoadNetworkDebugComponent::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  UFG::RoadNetworkDebugComponent::_TypeIDesc.mChildren = result;
  return result;
}

