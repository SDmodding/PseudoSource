// File Line: 222
// RVA: 0x4520C0
void __fastcall UFG::CharacterPhysicsComponent::operator delete(void *ptr, const char *name)
{
  *(_QWORD *)ptr = UFG::CharacterPhysicsComponent::mAllocator.mFreeListHead;
  --UFG::CharacterPhysicsComponent::mAllocator.mNumSlotsAllocated;
  UFG::CharacterPhysicsComponent::mAllocator.mFreeListHead = (char *)ptr;
}

// File Line: 225
// RVA: 0x454000
UFG::ComponentIDDesc *__fastcall UFG::CharacterPhysicsComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::CharacterPhysicsComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::CharacterPhysicsComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::CharacterPhysicsComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::CharacterPhysicsComponent::_DescInit = 1;
    UFG::CharacterPhysicsComponent::_TypeUID = UFG::CharacterPhysicsComponent::_TypeIDesc.mChildBitMask | (UFG::CharacterPhysicsComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::CharacterPhysicsComponent::_CharacterPhysicsComponentTypeUID = UFG::CharacterPhysicsComponent::_TypeIDesc.mChildBitMask | (UFG::CharacterPhysicsComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::CharacterPhysicsComponent::_TypeIDesc;
}

