// File Line: 19
// RVA: 0x66ECA0
UFG::ComponentIDDesc *__fastcall UFG::BoatPhysicsMoverComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::BoatPhysicsMoverComponent::_DescInit )
  {
    v0 = UFG::PhysicsMoverInterface::AccessComponentDesc();
    ++UFG::PhysicsMoverInterface::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::PhysicsMoverInterface::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::BoatPhysicsMoverComponent::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::BoatPhysicsMoverComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::BoatPhysicsMoverComponent::_TypeIDesc.mChildren = 0;
    UFG::BoatPhysicsMoverComponent::_DescInit = 1;
    UFG::BoatPhysicsMoverComponent::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::BoatPhysicsMoverComponent::_BoatPhysicsMoverComponentTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::BoatPhysicsMoverComponent::_TypeIDesc;
}

