// File Line: 83
// RVA: 0x15DD30
UFG::ComponentIDDesc *__fastcall SyncedObjectComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !SyncedObjectComponent::_DescInit )
  {
    v0 = NetSyncedSimObjectComponent::AccessComponentDesc();
    ++NetSyncedSimObjectComponent::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(NetSyncedSimObjectComponent::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&SyncedObjectComponent::_TypeIDesc.mBaseTypeIndex = v3[0];
    SyncedObjectComponent::_TypeIDesc.mChildBitMask = v1;
    SyncedObjectComponent::_TypeIDesc.mChildren = 0;
    SyncedObjectComponent::_DescInit = 1;
    SyncedObjectComponent::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    SyncedObjectComponent::_SyncedObjectComponentTypeUID = v1 | (LOWORD(v3[0]) << 25);
  }
  return &SyncedObjectComponent::_TypeIDesc;
}

