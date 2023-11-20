// File Line: 26
// RVA: 0x66EDC0
UFG::ComponentIDDesc *__fastcall UFG::CarPhysicsMoverComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !UFG::CarPhysicsMoverComponent::_DescInit )
  {
    v0 = UFG::PhysicsMoverInterface::AccessComponentDesc();
    ++UFG::PhysicsMoverInterface::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::PhysicsMoverInterface::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::CarPhysicsMoverComponent::_TypeIDesc.mBaseTypeIndex = v3[0];
    UFG::CarPhysicsMoverComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::CarPhysicsMoverComponent::_TypeIDesc.mChildren = 0;
    UFG::CarPhysicsMoverComponent::_DescInit = 1;
    UFG::CarPhysicsMoverComponent::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    UFG::CarPhysicsMoverComponent::_CarPhysicsMoverComponentTypeUID = v1 | (LOWORD(v3[0]) << 25);
  }
  return &UFG::CarPhysicsMoverComponent::_TypeIDesc;
}

