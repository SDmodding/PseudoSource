// File Line: 81
// RVA: 0x1467290
__int64 dynamic_initializer_for__SyncedCharacterComponent::s_SyncedCharacterComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__SyncedCharacterComponent::s_SyncedCharacterComponentList__);
}

// File Line: 82
// RVA: 0x1467040
__int64 dynamic_initializer_for__SyncedCharacterComponent::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = SyncedCharacterComponent::AccessComponentDesc();
  *(_DWORD *)&SyncedCharacterComponent::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  SyncedCharacterComponent::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  SyncedCharacterComponent::_TypeIDesc.mChildren = result;
  return result;
}

