// File Line: 34
// RVA: 0x51FCC0
UFG::ComponentIDDesc *__fastcall UFG::TargetingSystemVehicleComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::TargetingSystemVehicleComponent::_DescInit )
  {
    v0 = UFG::TargetingSystemBaseComponent::AccessComponentDesc();
    ++UFG::TargetingSystemBaseComponent::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::TargetingSystemBaseComponent::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::TargetingSystemVehicleComponent::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::TargetingSystemVehicleComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::TargetingSystemVehicleComponent::_TypeIDesc.mChildren = 0;
    UFG::TargetingSystemVehicleComponent::_DescInit = 1;
    UFG::TargetingSystemVehicleComponent::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::TargetingSystemVehicleComponent::_TargetingSystemVehicleComponentTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::TargetingSystemVehicleComponent::_TypeIDesc;
}

