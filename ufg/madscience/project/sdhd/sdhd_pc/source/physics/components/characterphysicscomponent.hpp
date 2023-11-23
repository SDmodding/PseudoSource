// File Line: 222
// RVA: 0x4520C0
void __fastcall UFG::CharacterPhysicsComponent::operator delete(char *ptr, const char *name)
{
  *(_QWORD *)ptr = UFG::CharacterPhysicsComponent::mAllocator.mFreeListHead;
  --UFG::CharacterPhysicsComponent::mAllocator.mNumSlotsAllocated;
  UFG::CharacterPhysicsComponent::mAllocator.mFreeListHead = ptr;
}

// File Line: 225
// RVA: 0x454000
UFG::ComponentIDDesc *__fastcall UFG::CharacterPhysicsComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::CharacterPhysicsComponent::_DescInit )
  {
    UFG::CharacterPhysicsComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::CharacterPhysicsComponent::_DescInit = 1;
    UFG::CharacterPhysicsComponent::_TypeUID = UFG::CharacterPhysicsComponent::_TypeIDesc.mChildBitMask | (UFG::CharacterPhysicsComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::CharacterPhysicsComponent::_CharacterPhysicsComponentTypeUID = UFG::CharacterPhysicsComponent::_TypeIDesc.mChildBitMask | (UFG::CharacterPhysicsComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::CharacterPhysicsComponent::_TypeIDesc;
}

