// File Line: 23
// RVA: 0x161F20
void __fastcall UFG::qStaticInitAllocator::qStaticInitAllocator(UFG::qStaticInitAllocator *this)
{
  this->mBlocks = 0i64;
  this->mTotalAlloc = 0;
  this->mNextAlloc = 0i64;
  this->mEndBlock = 0i64;
}

// File Line: 41
// RVA: 0x16CE70
void __fastcall UFG::qStaticInitAllocator::Done(UFG::qStaticInitAllocator *this)
{
  UFG::qRegionAllocator<UFG::qMainPoolAllocator<1>,0>::Block *i; // rax

  for ( i = this->mBlocks; i; i = i->next )
    ;
}

