// File Line: 44
// RVA: 0x4542A0
UFG::ComponentIDDesc *__fastcall UFG::RigidBodyComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::RigidBodyComponent::_DescInit )
  {
    v0 = UFG::RigidBody::AccessComponentDesc();
    ++UFG::RigidBody::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::RigidBody::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::RigidBodyComponent::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::RigidBodyComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::RigidBodyComponent::_TypeIDesc.mChildren = 0;
    UFG::RigidBodyComponent::_DescInit = 1;
    UFG::RigidBodyComponent::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::RigidBodyComponent::_RigidBodyComponentTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::RigidBodyComponent::_TypeIDesc;
}

// File Line: 50
// RVA: 0x451FE0
UFG::allocator::free_link *__fastcall UFG::RigidBodyComponent::operator new(unsigned __int64 size)
{
  char *mFreeListHead; // rbx

  mFreeListHead = UFG::RigidBodyComponent::mAllocator.mFreeListHead;
  if ( !UFG::RigidBodyComponent::mAllocator.mFreeListHead )
    return UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, size, "RigidBodyComponent", 0i64, 1u);
  UFG::RigidBodyComponent::mAllocator.mFreeListHead = *(char **)UFG::RigidBodyComponent::mAllocator.mFreeListHead;
  if ( UFG::RigidBodyComponent::mAllocator.mMostSlotsAllocated <= ++UFG::RigidBodyComponent::mAllocator.mNumSlotsAllocated )
    UFG::RigidBodyComponent::mAllocator.mMostSlotsAllocated = UFG::RigidBodyComponent::mAllocator.mNumSlotsAllocated;
  return (UFG::allocator::free_link *)mFreeListHead;
}

// File Line: 61
// RVA: 0x452140
void __fastcall UFG::RigidBodyComponent::operator delete(char *ptr, unsigned __int64 size)
{
  if ( ptr < &UFG::RigidBodyComponent::mAllocator.mBuffer[(unsigned __int64)UFG::RigidBodyComponent::mAllocator.mBufferSize]
    && ptr >= UFG::RigidBodyComponent::mAllocator.mBuffer )
  {
    *(_QWORD *)ptr = UFG::RigidBodyComponent::mAllocator.mFreeListHead;
    --UFG::RigidBodyComponent::mAllocator.mNumSlotsAllocated;
    UFG::RigidBodyComponent::mAllocator.mFreeListHead = ptr;
  }
  else
  {
    UFG::qMemoryPool::Free(&gPhysicsMemoryPool, ptr);
  }
}

