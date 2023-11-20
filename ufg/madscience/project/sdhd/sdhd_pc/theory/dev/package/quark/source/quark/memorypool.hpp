// File Line: 101
// RVA: 0x1040
char *__fastcall operator new(unsigned __int64 size, const char *name)
{
  return UFG::qMalloc(size, name, 0i64);
}

// File Line: 115
// RVA: 0x164E40
void __fastcall operator delete[](void *mem)
{
  if ( mem )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, mem);
}

// File Line: 573
// RVA: 0x25AE0
void __fastcall UFG::qFixedAllocator::~qFixedAllocator(UFG::qFixedAllocator *this)
{
  UFG::qFixedAllocator::Close(this);
}

