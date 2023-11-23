// File Line: 25
// RVA: 0x15DBA0
UFG::ComponentIDDesc *__fastcall SyncedCharacterAnimationComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !SyncedCharacterAnimationComponent::_DescInit )
  {
    SyncedCharacterAnimationComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    SyncedCharacterAnimationComponent::_DescInit = 1;
    SyncedCharacterAnimationComponent::_TypeUID = SyncedCharacterAnimationComponent::_TypeIDesc.mChildBitMask | (SyncedCharacterAnimationComponent::_TypeIDesc.mBaseTypeIndex << 25);
    SyncedCharacterAnimationComponent::_SyncedCharacterAnimationComponentTypeUID = SyncedCharacterAnimationComponent::_TypeIDesc.mChildBitMask | (SyncedCharacterAnimationComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &SyncedCharacterAnimationComponent::_TypeIDesc;
}

