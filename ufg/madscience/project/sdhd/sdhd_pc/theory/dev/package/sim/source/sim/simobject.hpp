// File Line: 81
// RVA: 0x18FD50
void __fastcall UFG::SimObject::operator delete(char *ptr, unsigned __int64 size)
{
  UFG::qMemoryPool::Free(gSimulationMemoryPool, ptr);
}

// File Line: 254
// RVA: 0x452050
UFG::allocator::free_link *__fastcall UFG::SimComponent::operator new(unsigned __int64 size)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  return UFG::qMemoryPool::Allocate(SimulationMemoryPool, size, "SimComponent", 0i64, 1u);
}

// File Line: 305
// RVA: 0x1C00
void __fastcall UFG::SimComponent::Suspend(UFG::SimComponent *this)
{
  this->m_Flags |= 2u;
}

// File Line: 314
// RVA: 0x190BE0
UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *__fastcall UFG::SimComponent::GetSceneObj(
        UFG::SimComponent *this)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *result; // rax

  result = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)this->m_pSimObject;
  if ( result )
    return result[5].mPrev;
  return result;
}

