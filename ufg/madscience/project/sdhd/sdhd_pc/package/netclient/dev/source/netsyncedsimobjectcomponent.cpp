// File Line: 96
// RVA: 0x1467250
__int64 dynamic_initializer_for__NetSyncedSimObjectComponent::s_NetSyncedSimObjectComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__NetSyncedSimObjectComponent::s_NetSyncedSimObjectComponentList__);
}

// File Line: 97
// RVA: 0x1466FE0
__int64 dynamic_initializer_for__NetSyncedSimObjectComponent::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = NetSyncedSimObjectComponent::AccessComponentDesc();
  *(_DWORD *)&NetSyncedSimObjectComponent::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  NetSyncedSimObjectComponent::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  NetSyncedSimObjectComponent::_TypeIDesc.mChildren = result;
  return result;
}

