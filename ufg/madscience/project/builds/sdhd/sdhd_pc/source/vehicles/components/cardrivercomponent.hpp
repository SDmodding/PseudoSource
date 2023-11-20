// File Line: 19
// RVA: 0x66ED30
UFG::ComponentIDDesc *__fastcall UFG::CarHumanDriverComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !UFG::CarHumanDriverComponent::_DescInit )
  {
    v0 = UFG::HumanDriverComponent::AccessComponentDesc();
    ++UFG::VehicleDriverInterface::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::VehicleDriverInterface::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::CarHumanDriverComponent::_TypeIDesc.mBaseTypeIndex = v3[0];
    UFG::CarHumanDriverComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::CarHumanDriverComponent::_TypeIDesc.mChildren = 0;
    UFG::CarHumanDriverComponent::_DescInit = 1;
    UFG::CarHumanDriverComponent::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    UFG::CarHumanDriverComponent::_CarHumanDriverComponentTypeUID = v1 | (LOWORD(v3[0]) << 25);
  }
  return &UFG::CarHumanDriverComponent::_TypeIDesc;
}

