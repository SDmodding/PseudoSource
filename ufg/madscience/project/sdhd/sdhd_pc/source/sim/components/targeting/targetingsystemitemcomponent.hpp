// File Line: 31
// RVA: 0x51F960
UFG::ComponentIDDesc *__fastcall UFG::TargetingSystemItemComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::TargetingSystemItemComponent::_DescInit )
  {
    v0 = UFG::TargetingSystemBaseComponent::AccessComponentDesc();
    ++UFG::TargetingSystemBaseComponent::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::TargetingSystemBaseComponent::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::TargetingSystemItemComponent::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::TargetingSystemItemComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::TargetingSystemItemComponent::_TypeIDesc.mChildren = 0;
    UFG::TargetingSystemItemComponent::_DescInit = 1;
    UFG::TargetingSystemItemComponent::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::TargetingSystemItemComponent::_TargetingSystemItemComponentTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::TargetingSystemItemComponent::_TypeIDesc;
}

