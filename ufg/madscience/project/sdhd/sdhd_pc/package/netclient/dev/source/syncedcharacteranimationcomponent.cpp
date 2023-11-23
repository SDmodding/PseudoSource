// File Line: 27
// RVA: 0x1467270
__int64 dynamic_initializer_for__SyncedCharacterAnimationComponent::s_SyncedCharacterAnimationComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__SyncedCharacterAnimationComponent::s_SyncedCharacterAnimationComponentList__);
}

// File Line: 28
// RVA: 0x1467010
__int64 dynamic_initializer_for__SyncedCharacterAnimationComponent::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = SyncedCharacterAnimationComponent::AccessComponentDesc();
  *(_DWORD *)&SyncedCharacterAnimationComponent::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  SyncedCharacterAnimationComponent::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  SyncedCharacterAnimationComponent::_TypeIDesc.mChildren = result;
  return result;
}

