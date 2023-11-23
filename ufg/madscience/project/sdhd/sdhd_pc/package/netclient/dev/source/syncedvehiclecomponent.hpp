// File Line: 75
// RVA: 0x15DDC0
UFG::ComponentIDDesc *__fastcall SyncedVehicleComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !SyncedVehicleComponent::_DescInit )
  {
    v0 = NetSyncedSimObjectComponent::AccessComponentDesc();
    ++NetSyncedSimObjectComponent::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(NetSyncedSimObjectComponent::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&SyncedVehicleComponent::_TypeIDesc.mBaseTypeIndex = v3;
    SyncedVehicleComponent::_TypeIDesc.mChildBitMask = v1;
    SyncedVehicleComponent::_TypeIDesc.mChildren = 0;
    SyncedVehicleComponent::_DescInit = 1;
    SyncedVehicleComponent::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    SyncedVehicleComponent::_SyncedVehicleComponentTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &SyncedVehicleComponent::_TypeIDesc;
}

