// File Line: 31
// RVA: 0x51F8D0
UFG::ComponentIDDesc *__fastcall UFG::TargetingSystemCraneComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::TargetingSystemCraneComponent::_DescInit )
  {
    v0 = UFG::TargetingSystemBaseComponent::AccessComponentDesc();
    ++UFG::TargetingSystemBaseComponent::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::TargetingSystemBaseComponent::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::TargetingSystemCraneComponent::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::TargetingSystemCraneComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::TargetingSystemCraneComponent::_TypeIDesc.mChildren = 0;
    UFG::TargetingSystemCraneComponent::_DescInit = 1;
    UFG::TargetingSystemCraneComponent::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::TargetingSystemCraneComponent::_TargetingSystemCraneComponentTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::TargetingSystemCraneComponent::_TypeIDesc;
}

