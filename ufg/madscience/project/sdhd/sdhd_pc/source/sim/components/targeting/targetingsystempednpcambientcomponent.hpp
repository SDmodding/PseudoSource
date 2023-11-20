// File Line: 35
// RVA: 0x51FA80
UFG::ComponentIDDesc *__fastcall UFG::TargetingSystemPedNPCAmbientComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !UFG::TargetingSystemPedNPCAmbientComponent::_DescInit )
  {
    v0 = UFG::TargetingSystemPedNPCBaseComponent::AccessComponentDesc();
    ++UFG::TargetingSystemBaseComponent::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::TargetingSystemBaseComponent::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::TargetingSystemPedNPCAmbientComponent::_TypeIDesc.mBaseTypeIndex = v3[0];
    UFG::TargetingSystemPedNPCAmbientComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::TargetingSystemPedNPCAmbientComponent::_TypeIDesc.mChildren = 0;
    UFG::TargetingSystemPedNPCAmbientComponent::_DescInit = 1;
    UFG::TargetingSystemPedNPCAmbientComponent::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    UFG::TargetingSystemPedNPCAmbientComponent::_TargetingSystemPedNPCAmbientComponentTypeUID = v1 | (LOWORD(v3[0]) << 25);
  }
  return &UFG::TargetingSystemPedNPCAmbientComponent::_TypeIDesc;
}

