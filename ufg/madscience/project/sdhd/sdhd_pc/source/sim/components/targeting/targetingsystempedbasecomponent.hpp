// File Line: 167
// RVA: 0x51F9F0
UFG::ComponentIDDesc *__fastcall UFG::TargetingSystemPedBaseComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !UFG::TargetingSystemPedBaseComponent::_DescInit )
  {
    v0 = UFG::TargetingSystemBaseComponent::AccessComponentDesc();
    ++UFG::TargetingSystemBaseComponent::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::TargetingSystemBaseComponent::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::TargetingSystemPedBaseComponent::_TypeIDesc.mBaseTypeIndex = v3[0];
    UFG::TargetingSystemPedBaseComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::TargetingSystemPedBaseComponent::_TypeIDesc.mChildren = 0;
    UFG::TargetingSystemPedBaseComponent::_DescInit = 1;
    UFG::TargetingSystemPedBaseComponent::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    UFG::TargetingSystemPedBaseComponent::_TargetingSystemPedBaseComponentTypeUID = v1 | (LOWORD(v3[0]) << 25);
  }
  return &UFG::TargetingSystemPedBaseComponent::_TypeIDesc;
}

