// File Line: 50
// RVA: 0x51F560
UFG::ComponentIDDesc *__fastcall UFG::SimObjectCharacterPropertiesComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !UFG::SimObjectCharacterPropertiesComponent::_DescInit )
  {
    v0 = UFG::SimObjectPropertiesComponent::AccessComponentDesc();
    ++UFG::SimObjectPropertiesComponent::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::SimObjectPropertiesComponent::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::SimObjectCharacterPropertiesComponent::_TypeIDesc.mBaseTypeIndex = v3[0];
    UFG::SimObjectCharacterPropertiesComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::SimObjectCharacterPropertiesComponent::_TypeIDesc.mChildren = 0;
    UFG::SimObjectCharacterPropertiesComponent::_DescInit = 1;
    UFG::SimObjectCharacterPropertiesComponent::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    UFG::SimObjectCharacterPropertiesComponent::_SimObjectCharacterPropertiesComponentTypeUID = v1 | (LOWORD(v3[0]) << 25);
  }
  return &UFG::SimObjectCharacterPropertiesComponent::_TypeIDesc;
}

