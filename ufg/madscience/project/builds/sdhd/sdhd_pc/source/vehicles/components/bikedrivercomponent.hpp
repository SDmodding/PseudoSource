// File Line: 31
// RVA: 0x66EAF0
UFG::ComponentIDDesc *__fastcall UFG::BikeHumanDriverComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::BikeHumanDriverComponent::_DescInit )
  {
    v0 = UFG::HumanDriverComponent::AccessComponentDesc();
    ++UFG::VehicleDriverInterface::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::VehicleDriverInterface::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::BikeHumanDriverComponent::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::BikeHumanDriverComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::BikeHumanDriverComponent::_TypeIDesc.mChildren = 0;
    UFG::BikeHumanDriverComponent::_DescInit = 1;
    UFG::BikeHumanDriverComponent::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::BikeHumanDriverComponent::_BikeHumanDriverComponentTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::BikeHumanDriverComponent::_TypeIDesc;
}

