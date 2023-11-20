// File Line: 64
// RVA: 0x1467230
__int64 dynamic_initializer_for__NetPlayerComponent::s_NetPlayerComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__NetPlayerComponent::s_NetPlayerComponentList__);
}

// File Line: 65
// RVA: 0x1466FB0
__int64 dynamic_initializer_for__NetPlayerComponent::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = NetPlayerComponent::AccessComponentDesc();
  *(_DWORD *)&NetPlayerComponent::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  NetPlayerComponent::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  NetPlayerComponent::_TypeIDesc.mChildren = result;
  return result;
}

