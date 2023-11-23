// File Line: 157
// RVA: 0x162A00
void __fastcall UFG::qRegionAllocator<UFG::qMainPoolAllocator<1>,0>::~qRegionAllocator<UFG::qMainPoolAllocator<1>,0>(
        UFG::qRegionAllocator<UFG::qMainPoolAllocator<1>,0> *this)
{
  UFG::qRegionAllocator<UFG::qMainPoolAllocator<1>,0>::Block *mBlocks; // rdx
  UFG::qRegionAllocator<UFG::qMainPoolAllocator<1>,0>::Block *next; // rbx

  mBlocks = this->mBlocks;
  if ( this->mBlocks )
  {
    do
    {
      next = mBlocks->next;
      UFG::qMemoryPool::Free(UFG::gMainMemoryPool, mBlocks);
      mBlocks = next;
    }
    while ( next );
    this->mBlocks = 0i64;
  }
  else
  {
    this->mBlocks = 0i64;
  }
}

