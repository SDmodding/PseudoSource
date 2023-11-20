// File Line: 30
// RVA: 0x66EB80
UFG::ComponentIDDesc *__fastcall UFG::BikePhysicsMoverComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !UFG::BikePhysicsMoverComponent::_DescInit )
  {
    v0 = UFG::PhysicsMoverInterface::AccessComponentDesc();
    ++UFG::PhysicsMoverInterface::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::PhysicsMoverInterface::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::BikePhysicsMoverComponent::_TypeIDesc.mBaseTypeIndex = v3[0];
    UFG::BikePhysicsMoverComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::BikePhysicsMoverComponent::_TypeIDesc.mChildren = 0;
    UFG::BikePhysicsMoverComponent::_DescInit = 1;
    UFG::BikePhysicsMoverComponent::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    UFG::BikePhysicsMoverComponent::_BikePhysicsMoverComponentTypeUID = v1 | (LOWORD(v3[0]) << 25);
  }
  return &UFG::BikePhysicsMoverComponent::_TypeIDesc;
}

