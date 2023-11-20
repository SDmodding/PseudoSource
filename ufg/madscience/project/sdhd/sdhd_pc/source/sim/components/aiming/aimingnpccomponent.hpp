// File Line: 37
// RVA: 0x51E820
UFG::ComponentIDDesc *__fastcall UFG::AimingNPCComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !UFG::AimingNPCComponent::_DescInit )
  {
    v0 = UFG::AimingBaseComponent::AccessComponentDesc();
    ++UFG::AimingBaseComponent::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::AimingBaseComponent::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::AimingNPCComponent::_TypeIDesc.mBaseTypeIndex = v3[0];
    UFG::AimingNPCComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::AimingNPCComponent::_TypeIDesc.mChildren = 0;
    UFG::AimingNPCComponent::_DescInit = 1;
    UFG::AimingNPCComponent::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    UFG::AimingNPCComponent::_AimingNPCComponentTypeUID = v1 | (LOWORD(v3[0]) << 25);
  }
  return &UFG::AimingNPCComponent::_TypeIDesc;
}

