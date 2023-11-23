// File Line: 20
// RVA: 0x66EE50
UFG::ComponentIDDesc *__fastcall UFG::HumanDriverComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::HumanDriverComponent::_DescInit )
  {
    v0 = UFG::VehicleDriverInterface::AccessComponentDesc();
    ++UFG::VehicleDriverInterface::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::VehicleDriverInterface::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::HumanDriverComponent::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::HumanDriverComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::HumanDriverComponent::_TypeIDesc.mChildren = 0;
    UFG::HumanDriverComponent::_DescInit = 1;
    UFG::HumanDriverComponent::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::HumanDriverComponent::_HumanDriverComponentTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::HumanDriverComponent::_TypeIDesc;
}

