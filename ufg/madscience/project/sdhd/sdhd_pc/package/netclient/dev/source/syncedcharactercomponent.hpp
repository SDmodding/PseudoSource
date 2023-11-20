// File Line: 121
// RVA: 0x15DC10
UFG::ComponentIDDesc *__fastcall SyncedCharacterComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !SyncedCharacterComponent::_DescInit )
  {
    v0 = NetSyncedSimObjectComponent::AccessComponentDesc();
    ++NetSyncedSimObjectComponent::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(NetSyncedSimObjectComponent::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&SyncedCharacterComponent::_TypeIDesc.mBaseTypeIndex = v3;
    SyncedCharacterComponent::_TypeIDesc.mChildBitMask = v1;
    SyncedCharacterComponent::_TypeIDesc.mChildren = 0;
    SyncedCharacterComponent::_DescInit = 1;
    SyncedCharacterComponent::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    SyncedCharacterComponent::_SyncedCharacterComponentTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &SyncedCharacterComponent::_TypeIDesc;
}

