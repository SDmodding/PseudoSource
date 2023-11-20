// File Line: 54
// RVA: 0x51EA40
UFG::ComponentIDDesc *__fastcall UFG::CharacterEffectsComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::CharacterEffectsComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::CharacterEffectsComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::CharacterEffectsComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::CharacterEffectsComponent::_DescInit = 1;
    UFG::CharacterEffectsComponent::_TypeUID = UFG::CharacterEffectsComponent::_TypeIDesc.mChildBitMask | (UFG::CharacterEffectsComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::CharacterEffectsComponent::_CharacterEffectsComponentTypeUID = UFG::CharacterEffectsComponent::_TypeIDesc.mChildBitMask | (UFG::CharacterEffectsComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::CharacterEffectsComponent::_TypeIDesc;
}

