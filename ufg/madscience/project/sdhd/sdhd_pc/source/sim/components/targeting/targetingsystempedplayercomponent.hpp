// File Line: 37
// RVA: 0x51FC30
UFG::ComponentIDDesc *__fastcall UFG::TargetingSystemPedPlayerComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !UFG::TargetingSystemPedPlayerComponent::_DescInit )
  {
    v0 = UFG::TargetingSystemPedBaseComponent::AccessComponentDesc();
    ++UFG::TargetingSystemBaseComponent::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::TargetingSystemBaseComponent::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::TargetingSystemPedPlayerComponent::_TypeIDesc.mBaseTypeIndex = v3[0];
    UFG::TargetingSystemPedPlayerComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::TargetingSystemPedPlayerComponent::_TypeIDesc.mChildren = 0;
    UFG::TargetingSystemPedPlayerComponent::_DescInit = 1;
    UFG::TargetingSystemPedPlayerComponent::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    UFG::TargetingSystemPedPlayerComponent::_TargetingSystemPedPlayerComponentTypeUID = v1 | (LOWORD(v3[0]) << 25);
  }
  return &UFG::TargetingSystemPedPlayerComponent::_TypeIDesc;
}

