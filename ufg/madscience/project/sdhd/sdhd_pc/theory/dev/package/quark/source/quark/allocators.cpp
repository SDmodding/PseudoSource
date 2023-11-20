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
  UFG::qRegionAllocator<UFG::qMainPoolAllocator<1>,0>::Block *v1; // rax

  v1 = this->mBlocks;
  if ( this->mBlocks )
  {
    do
      v1 = v1->next;
    while ( v1 );
  }
}

