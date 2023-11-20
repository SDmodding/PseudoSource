// File Line: 35
// RVA: 0x51FB10
UFG::ComponentIDDesc *__fastcall UFG::TargetingSystemPedNPCBaseComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !UFG::TargetingSystemPedNPCBaseComponent::_DescInit )
  {
    v0 = UFG::TargetingSystemPedBaseComponent::AccessComponentDesc();
    ++UFG::TargetingSystemBaseComponent::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::TargetingSystemBaseComponent::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::TargetingSystemPedNPCBaseComponent::_TypeIDesc.mBaseTypeIndex = v3[0];
    UFG::TargetingSystemPedNPCBaseComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::TargetingSystemPedNPCBaseComponent::_TypeIDesc.mChildren = 0;
    UFG::TargetingSystemPedNPCBaseComponent::_DescInit = 1;
    UFG::TargetingSystemPedNPCBaseComponent::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    UFG::TargetingSystemPedNPCBaseComponent::_TargetingSystemPedNPCBaseComponentTypeUID = v1 | (LOWORD(v3[0]) << 25);
  }
  return &UFG::TargetingSystemPedNPCBaseComponent::_TypeIDesc;
}

