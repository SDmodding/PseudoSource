// File Line: 99
// RVA: 0x51E7B0
UFG::ComponentIDDesc *__fastcall UFG::AimingBaseComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::AimingBaseComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::AimingBaseComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::AimingBaseComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::AimingBaseComponent::_DescInit = 1;
    UFG::AimingBaseComponent::_TypeUID = UFG::AimingBaseComponent::_TypeIDesc.mChildBitMask | (UFG::AimingBaseComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::AimingBaseComponent::_AimingBaseComponentTypeUID = UFG::AimingBaseComponent::_TypeIDesc.mChildBitMask | (UFG::AimingBaseComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::AimingBaseComponent::_TypeIDesc;
}

