// File Line: 157
// RVA: 0x162A00
void __fastcall UFG::qRegionAllocator<UFG::qMainPoolAllocator<1>,0>::~qRegionAllocator<UFG::qMainPoolAllocator<1>,0>(UFG::qRegionAllocator<UFG::qMainPoolAllocator<1>,0> *this)
{
  UFG::qRegionAllocator<UFG::qMainPoolAllocator<1>,0>::Block *v1; // rdx
  UFG::qRegionAllocator<UFG::qMainPoolAllocator<1>,0> *v2; // rdi
  UFG::qRegionAllocator<UFG::qMainPoolAllocator<1>,0>::Block *v3; // rbx

  v1 = this->mBlocks;
  v2 = this;
  if ( this->mBlocks )
  {
    do
    {
      v3 = v1->next;
      UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v1);
      v1 = v3;
    }
    while ( v3 );
    v2->mBlocks = 0i64;
  }
  else
  {
    this->mBlocks = 0i64;
  }
}

