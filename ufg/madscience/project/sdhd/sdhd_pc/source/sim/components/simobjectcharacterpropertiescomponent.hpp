// File Line: 50
// RVA: 0x51F560
UFG::ComponentIDDesc *__fastcall UFG::SimObjectCharacterPropertiesComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::SimObjectCharacterPropertiesComponent::_DescInit )
  {
    v0 = UFG::SimObjectPropertiesComponent::AccessComponentDesc();
    ++UFG::SimObjectPropertiesComponent::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::SimObjectPropertiesComponent::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::SimObjectCharacterPropertiesComponent::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::SimObjectCharacterPropertiesComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::SimObjectCharacterPropertiesComponent::_TypeIDesc.mChildren = 0;
    UFG::SimObjectCharacterPropertiesComponent::_DescInit = 1;
    UFG::SimObjectCharacterPropertiesComponent::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::SimObjectCharacterPropertiesComponent::_SimObjectCharacterPropertiesComponentTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::SimObjectCharacterPropertiesComponent::_TypeIDesc;
}

