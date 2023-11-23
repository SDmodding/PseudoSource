// File Line: 52
// RVA: 0x14672D0
__int64 dynamic_initializer_for__SyncedObjectComponent::s_SyncedObjectComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__SyncedObjectComponent::s_SyncedObjectComponentList__);
}

// File Line: 53
// RVA: 0x14670A0
__int64 dynamic_initializer_for__SyncedObjectComponent::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = SyncedObjectComponent::AccessComponentDesc();
  *(_DWORD *)&SyncedObjectComponent::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  SyncedObjectComponent::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  SyncedObjectComponent::_TypeIDesc.mChildren = result;
  return result;
}

