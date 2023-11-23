// File Line: 28
// RVA: 0x33F270
UFG::ComponentIDDesc *__fastcall UFG::CharacterControllerInterface::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::CharacterControllerInterface::_DescInit )
  {
    UFG::CharacterControllerInterface::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::CharacterControllerInterface::_DescInit = 1;
    UFG::CharacterControllerInterface::_TypeUID = UFG::CharacterControllerInterface::_TypeIDesc.mChildBitMask | (UFG::CharacterControllerInterface::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::CharacterControllerInterface::_CharacterControllerInterfaceTypeUID = UFG::CharacterControllerInterface::_TypeIDesc.mChildBitMask | (UFG::CharacterControllerInterface::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::CharacterControllerInterface::_TypeIDesc;
}

