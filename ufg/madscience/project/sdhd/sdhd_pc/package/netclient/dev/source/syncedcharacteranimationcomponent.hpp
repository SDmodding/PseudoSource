// File Line: 25
// RVA: 0x15DBA0
UFG::ComponentIDDesc *__fastcall SyncedCharacterAnimationComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !SyncedCharacterAnimationComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&SyncedCharacterAnimationComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    SyncedCharacterAnimationComponent::_TypeIDesc.mChildren = v0->mChildren;
    SyncedCharacterAnimationComponent::_DescInit = 1;
    SyncedCharacterAnimationComponent::_TypeUID = SyncedCharacterAnimationComponent::_TypeIDesc.mChildBitMask | (SyncedCharacterAnimationComponent::_TypeIDesc.mBaseTypeIndex << 25);
    SyncedCharacterAnimationComponent::_SyncedCharacterAnimationComponentTypeUID = SyncedCharacterAnimationComponent::_TypeIDesc.mChildBitMask | (SyncedCharacterAnimationComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &SyncedCharacterAnimationComponent::_TypeIDesc;
}

