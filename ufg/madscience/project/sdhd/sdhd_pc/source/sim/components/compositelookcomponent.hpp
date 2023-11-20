// File Line: 47
// RVA: 0x57E980
UFG::ComponentIDDesc *__fastcall UFG::CompositeLookComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::CompositeLookComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::CompositeLookComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::CompositeLookComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::CompositeLookComponent::_DescInit = 1;
    UFG::CompositeLookComponent::_TypeUID = UFG::CompositeLookComponent::_TypeIDesc.mChildBitMask | (UFG::CompositeLookComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::CompositeLookComponent::_CompositeLookComponentTypeUID = UFG::CompositeLookComponent::_TypeIDesc.mChildBitMask | (UFG::CompositeLookComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::CompositeLookComponent::_TypeIDesc;
}

// File Line: 112
// RVA: 0x57EE10
UFG::ComponentIDDesc *__fastcall UFG::VehicleLookComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::VehicleLookComponent::_DescInit )
  {
    v0 = UFG::CompositeLookComponent::AccessComponentDesc();
    ++UFG::CompositeLookComponent::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::CompositeLookComponent::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::VehicleLookComponent::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::VehicleLookComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::VehicleLookComponent::_TypeIDesc.mChildren = 0;
    UFG::VehicleLookComponent::_DescInit = 1;
    UFG::VehicleLookComponent::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::VehicleLookComponent::_VehicleLookComponentTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::VehicleLookComponent::_TypeIDesc;
}

// File Line: 150
// RVA: 0x57E8F0
UFG::ComponentIDDesc *__fastcall UFG::CharacterLookComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !UFG::CharacterLookComponent::_DescInit )
  {
    v0 = UFG::CompositeLookComponent::AccessComponentDesc();
    ++UFG::CompositeLookComponent::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::CompositeLookComponent::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::CharacterLookComponent::_TypeIDesc.mBaseTypeIndex = v3[0];
    UFG::CharacterLookComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::CharacterLookComponent::_TypeIDesc.mChildren = 0;
    UFG::CharacterLookComponent::_DescInit = 1;
    UFG::CharacterLookComponent::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    UFG::CharacterLookComponent::_CharacterLookComponentTypeUID = v1 | (LOWORD(v3[0]) << 25);
  }
  return &UFG::CharacterLookComponent::_TypeIDesc;
}

