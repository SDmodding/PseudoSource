// File Line: 37
// RVA: 0x51F6D0
UFG::ComponentIDDesc *__fastcall UFG::SimObjectVehiclePropertiesComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::SimObjectVehiclePropertiesComponent::_DescInit )
  {
    v0 = UFG::SimObjectPropertiesComponent::AccessComponentDesc();
    ++UFG::SimObjectPropertiesComponent::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::SimObjectPropertiesComponent::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::SimObjectVehiclePropertiesComponent::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::SimObjectVehiclePropertiesComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::SimObjectVehiclePropertiesComponent::_TypeIDesc.mChildren = 0;
    UFG::SimObjectVehiclePropertiesComponent::_DescInit = 1;
    UFG::SimObjectVehiclePropertiesComponent::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::SimObjectVehiclePropertiesComponent::_SimObjectVehiclePropertiesComponentTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::SimObjectVehiclePropertiesComponent::_TypeIDesc;
}

