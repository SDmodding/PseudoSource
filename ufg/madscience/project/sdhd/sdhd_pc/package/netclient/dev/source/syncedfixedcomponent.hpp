// File Line: 67
// RVA: 0x15DCA0
UFG::ComponentIDDesc *__fastcall SyncedFixedComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !SyncedFixedComponent::_DescInit )
  {
    v0 = NetSyncedSimObjectComponent::AccessComponentDesc();
    ++NetSyncedSimObjectComponent::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(NetSyncedSimObjectComponent::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&SyncedFixedComponent::_TypeIDesc.mBaseTypeIndex = v3[0];
    SyncedFixedComponent::_TypeIDesc.mChildBitMask = v1;
    SyncedFixedComponent::_TypeIDesc.mChildren = 0;
    SyncedFixedComponent::_DescInit = 1;
    SyncedFixedComponent::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    SyncedFixedComponent::_SyncedFixedComponentTypeUID = v1 | (LOWORD(v3[0]) << 25);
  }
  return &SyncedFixedComponent::_TypeIDesc;
}

