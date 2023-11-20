// File Line: 28
// RVA: 0x33F270
UFG::ComponentIDDesc *__fastcall UFG::CharacterControllerInterface::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::CharacterControllerInterface::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::CharacterControllerInterface::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::CharacterControllerInterface::_TypeIDesc.mChildren = v0->mChildren;
    UFG::CharacterControllerInterface::_DescInit = 1;
    UFG::CharacterControllerInterface::_TypeUID = UFG::CharacterControllerInterface::_TypeIDesc.mChildBitMask | (UFG::CharacterControllerInterface::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::CharacterControllerInterface::_CharacterControllerInterfaceTypeUID = UFG::CharacterControllerInterface::_TypeIDesc.mChildBitMask | (UFG::CharacterControllerInterface::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::CharacterControllerInterface::_TypeIDesc;
}

