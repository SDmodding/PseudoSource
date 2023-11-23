// File Line: 27
// RVA: 0x51EAB0
UFG::ComponentIDDesc *__fastcall UFG::CharacterOccupantComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::CharacterOccupantComponent::_DescInit )
  {
    UFG::CharacterOccupantComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::CharacterOccupantComponent::_DescInit = 1;
    UFG::CharacterOccupantComponent::_TypeUID = UFG::CharacterOccupantComponent::_TypeIDesc.mChildBitMask | (UFG::CharacterOccupantComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::CharacterOccupantComponent::_CharacterOccupantComponentTypeUID = UFG::CharacterOccupantComponent::_TypeIDesc.mChildBitMask | (UFG::CharacterOccupantComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::CharacterOccupantComponent::_TypeIDesc;
}

