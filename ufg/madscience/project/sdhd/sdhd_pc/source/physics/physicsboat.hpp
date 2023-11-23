// File Line: 70
// RVA: 0x4520E0
void __fastcall UFG::PhysicsBoat::operator delete(char *ptr, unsigned __int64 size)
{
  if ( ptr < &UFG::PhysicsVehicle::mAllocator.mBuffer[(unsigned __int64)UFG::PhysicsVehicle::mAllocator.mBufferSize]
    && ptr >= UFG::PhysicsVehicle::mAllocator.mBuffer )
  {
    *(_QWORD *)ptr = UFG::PhysicsVehicle::mAllocator.mFreeListHead;
    --UFG::PhysicsVehicle::mAllocator.mNumSlotsAllocated;
    UFG::PhysicsVehicle::mAllocator.mFreeListHead = ptr;
  }
  else
  {
    UFG::qMemoryPool::Free(&gPhysicsMemoryPool, ptr);
  }
}

// File Line: 96
// RVA: 0x46AF30
bool __fastcall UFG::PhysicsBoat::IsInAir(UFG::PhysicsBoat *this)
{
  return (*((_DWORD *)this + 246) & 4) != 0;
}

// File Line: 107
// RVA: 0x466820
float __fastcall UFG::PhysicsBoat::GetHalfSteeringRange(UFG::PhysicsBoat *this)
{
  float result; // xmm0_4

  LODWORD(result) = LODWORD(this->mMaxRudderAngleForSpeed) & _xmm;
  return result;
}

