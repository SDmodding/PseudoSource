// File Line: 81
// RVA: 0x18FD50
void __fastcall UFG::SimObject::operator delete(void *ptr, unsigned __int64 size)
{
  UFG::qMemoryPool::Free(gSimulationMemoryPool, ptr);
}

// File Line: 254
// RVA: 0x452050
UFG::allocator::free_link *__fastcall UFG::SimComponent::operator new(unsigned __int64 size)
{
  unsigned __int64 v1; // rbx
  UFG::qMemoryPool *v2; // rax

  v1 = size;
  v2 = UFG::GetSimulationMemoryPool();
  return UFG::qMemoryPool::Allocate(v2, v1, "SimComponent", 0i64, 1u);
}

// File Line: 305
// RVA: 0x1C00
void __fastcall UFG::SimComponent::Suspend(UFG::SimComponent *this)
{
  this->m_Flags |= 2u;
}

// File Line: 314
// RVA: 0x190BE0
UFG::SceneObjectProperties *__fastcall UFG::SimComponent::GetSceneObj(UFG::SimComponent *this)
{
  UFG::SceneObjectProperties *result; // rax

  result = (UFG::SceneObjectProperties *)this->m_pSimObject;
  if ( result )
    result = (UFG::SceneObjectProperties *)result->mpOwner.mPrev;
  return result;
}

