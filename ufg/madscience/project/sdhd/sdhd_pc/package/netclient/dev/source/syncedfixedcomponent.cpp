// File Line: 39
// RVA: 0x14672B0
__int64 dynamic_initializer_for__SyncedFixedComponent::s_SyncedFixedComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__SyncedFixedComponent::s_SyncedFixedComponentList__);
}

// File Line: 40
// RVA: 0x1467070
__int64 dynamic_initializer_for__SyncedFixedComponent::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = SyncedFixedComponent::AccessComponentDesc();
  *(_DWORD *)&SyncedFixedComponent::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  SyncedFixedComponent::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  SyncedFixedComponent::_TypeIDesc.mChildren = result;
  return result;
}

