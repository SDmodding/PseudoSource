// File Line: 47
// RVA: 0x51EFB0
UFG::ComponentIDDesc *__fastcall UFG::GunComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::GunComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::GunComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::GunComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::GunComponent::_DescInit = 1;
    UFG::GunComponent::_TypeUID = UFG::GunComponent::_TypeIDesc.mChildBitMask | (UFG::GunComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::GunComponent::_GunComponentTypeUID = UFG::GunComponent::_TypeIDesc.mChildBitMask | (UFG::GunComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::GunComponent::_TypeIDesc;
}

