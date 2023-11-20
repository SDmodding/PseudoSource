// File Line: 19
// RVA: 0x66EF50
UFG::ComponentIDDesc *__fastcall UFG::RemoteDriverComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !UFG::RemoteDriverComponent::_DescInit )
  {
    v0 = UFG::VehicleDriverInterface::AccessComponentDesc();
    ++UFG::VehicleDriverInterface::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::VehicleDriverInterface::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::RemoteDriverComponent::_TypeIDesc.mBaseTypeIndex = v3[0];
    UFG::RemoteDriverComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::RemoteDriverComponent::_TypeIDesc.mChildren = 0;
    UFG::RemoteDriverComponent::_DescInit = 1;
    UFG::RemoteDriverComponent::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    UFG::RemoteDriverComponent::_RemoteDriverComponentTypeUID = v1 | (LOWORD(v3[0]) << 25);
  }
  return &UFG::RemoteDriverComponent::_TypeIDesc;
}

// File Line: 35
// RVA: 0x67F210
_BOOL8 __fastcall UFG::RemoteDriverComponent::IsHuman(UFG::RemoteDriverComponent *this)
{
  return this->mReplicatedInput.mHasHumanDriver;
}

