// File Line: 30
// RVA: 0x66EB80
UFG::ComponentIDDesc *__fastcall UFG::BikePhysicsMoverComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::BikePhysicsMoverComponent::_DescInit )
  {
    v0 = UFG::PhysicsMoverInterface::AccessComponentDesc();
    ++UFG::PhysicsMoverInterface::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::PhysicsMoverInterface::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::BikePhysicsMoverComponent::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::BikePhysicsMoverComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::BikePhysicsMoverComponent::_TypeIDesc.mChildren = 0;
    UFG::BikePhysicsMoverComponent::_DescInit = 1;
    UFG::BikePhysicsMoverComponent::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::BikePhysicsMoverComponent::_BikePhysicsMoverComponentTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::BikePhysicsMoverComponent::_TypeIDesc;
}

