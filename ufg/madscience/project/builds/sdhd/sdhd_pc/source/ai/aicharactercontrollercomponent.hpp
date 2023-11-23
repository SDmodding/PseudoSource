// File Line: 34
// RVA: 0x33ED00
UFG::ComponentIDDesc *__fastcall UFG::AICharacterControllerBaseComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::AICharacterControllerBaseComponent::_DescInit )
  {
    v0 = UFG::CharacterControllerInterface::AccessComponentDesc();
    ++UFG::CharacterControllerInterface::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::CharacterControllerInterface::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::AICharacterControllerBaseComponent::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::AICharacterControllerBaseComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::AICharacterControllerBaseComponent::_TypeIDesc.mChildren = 0;
    UFG::AICharacterControllerBaseComponent::_DescInit = 1;
    UFG::AICharacterControllerBaseComponent::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::AICharacterControllerBaseComponent::_AICharacterControllerBaseComponentTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::AICharacterControllerBaseComponent::_TypeIDesc;
}

// File Line: 81
// RVA: 0x33ED90
UFG::ComponentIDDesc *__fastcall UFG::AICharacterControllerComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::AICharacterControllerComponent::_DescInit )
  {
    v0 = UFG::AICharacterControllerBaseComponent::AccessComponentDesc();
    ++UFG::CharacterControllerInterface::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::CharacterControllerInterface::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::AICharacterControllerComponent::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::AICharacterControllerComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::AICharacterControllerComponent::_TypeIDesc.mChildren = 0;
    UFG::AICharacterControllerComponent::_DescInit = 1;
    UFG::AICharacterControllerComponent::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::AICharacterControllerComponent::_AICharacterControllerComponentTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::AICharacterControllerComponent::_TypeIDesc;
}

