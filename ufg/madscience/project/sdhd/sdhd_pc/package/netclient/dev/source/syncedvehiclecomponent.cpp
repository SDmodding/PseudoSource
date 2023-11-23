// File Line: 53
// RVA: 0x14672F0
__int64 dynamic_initializer_for__SyncedVehicleComponent::s_SyncedVehicleComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__SyncedVehicleComponent::s_SyncedVehicleComponentList__);
}

// File Line: 54
// RVA: 0x14670D0
__int64 dynamic_initializer_for__SyncedVehicleComponent::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = SyncedVehicleComponent::AccessComponentDesc();
  *(_DWORD *)&SyncedVehicleComponent::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  SyncedVehicleComponent::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  SyncedVehicleComponent::_TypeIDesc.mChildren = result;
  return result;
}

