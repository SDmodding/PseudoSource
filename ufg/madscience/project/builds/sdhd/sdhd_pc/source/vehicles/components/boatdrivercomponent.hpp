// File Line: 18
// RVA: 0x66EC10
UFG::ComponentIDDesc *__fastcall UFG::BoatHumanDriverComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !UFG::BoatHumanDriverComponent::_DescInit )
  {
    v0 = UFG::HumanDriverComponent::AccessComponentDesc();
    ++UFG::VehicleDriverInterface::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::VehicleDriverInterface::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::BoatHumanDriverComponent::_TypeIDesc.mBaseTypeIndex = v3[0];
    UFG::BoatHumanDriverComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::BoatHumanDriverComponent::_TypeIDesc.mChildren = 0;
    UFG::BoatHumanDriverComponent::_DescInit = 1;
    UFG::BoatHumanDriverComponent::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    UFG::BoatHumanDriverComponent::_BoatHumanDriverComponentTypeUID = v1 | (LOWORD(v3[0]) << 25);
  }
  return &UFG::BoatHumanDriverComponent::_TypeIDesc;
}

