// File Line: 67
// RVA: 0x15DCA0
UFG::ComponentIDDesc *__fastcall SyncedFixedComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !SyncedFixedComponent::_DescInit )
  {
    v0 = NetSyncedSimObjectComponent::AccessComponentDesc();
    ++NetSyncedSimObjectComponent::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(NetSyncedSimObjectComponent::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&SyncedFixedComponent::_TypeIDesc.mBaseTypeIndex = v3;
    SyncedFixedComponent::_TypeIDesc.mChildBitMask = v1;
    SyncedFixedComponent::_TypeIDesc.mChildren = 0;
    SyncedFixedComponent::_DescInit = 1;
    SyncedFixedComponent::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    SyncedFixedComponent::_SyncedFixedComponentTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &SyncedFixedComponent::_TypeIDesc;
}

