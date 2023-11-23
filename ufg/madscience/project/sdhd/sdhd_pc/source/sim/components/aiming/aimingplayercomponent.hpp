// File Line: 58
// RVA: 0x51E8B0
UFG::ComponentIDDesc *__fastcall UFG::AimingPlayerComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::AimingPlayerComponent::_DescInit )
  {
    v0 = UFG::AimingBaseComponent::AccessComponentDesc();
    ++UFG::AimingBaseComponent::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::AimingBaseComponent::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::AimingPlayerComponent::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::AimingPlayerComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::AimingPlayerComponent::_TypeIDesc.mChildren = 0;
    UFG::AimingPlayerComponent::_DescInit = 1;
    UFG::AimingPlayerComponent::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::AimingPlayerComponent::_AimingPlayerComponentTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::AimingPlayerComponent::_TypeIDesc;
}

