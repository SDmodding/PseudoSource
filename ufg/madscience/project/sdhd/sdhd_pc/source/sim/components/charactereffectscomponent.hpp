// File Line: 54
// RVA: 0x51EA40
UFG::ComponentIDDesc *__fastcall UFG::CharacterEffectsComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::CharacterEffectsComponent::_DescInit )
  {
    UFG::CharacterEffectsComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::CharacterEffectsComponent::_DescInit = 1;
    UFG::CharacterEffectsComponent::_TypeUID = UFG::CharacterEffectsComponent::_TypeIDesc.mChildBitMask | (UFG::CharacterEffectsComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::CharacterEffectsComponent::_CharacterEffectsComponentTypeUID = UFG::CharacterEffectsComponent::_TypeIDesc.mChildBitMask | (UFG::CharacterEffectsComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::CharacterEffectsComponent::_TypeIDesc;
}

