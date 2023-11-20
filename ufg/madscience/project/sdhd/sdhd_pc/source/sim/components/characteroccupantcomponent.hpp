// File Line: 27
// RVA: 0x51EAB0
UFG::ComponentIDDesc *__fastcall UFG::CharacterOccupantComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::CharacterOccupantComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::CharacterOccupantComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::CharacterOccupantComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::CharacterOccupantComponent::_DescInit = 1;
    UFG::CharacterOccupantComponent::_TypeUID = UFG::CharacterOccupantComponent::_TypeIDesc.mChildBitMask | (UFG::CharacterOccupantComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::CharacterOccupantComponent::_CharacterOccupantComponentTypeUID = UFG::CharacterOccupantComponent::_TypeIDesc.mChildBitMask | (UFG::CharacterOccupantComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::CharacterOccupantComponent::_TypeIDesc;
}

