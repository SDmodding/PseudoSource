// File Line: 68
// RVA: 0x66DB30
char *__fastcall UFG::WayTraversalSearch::operator new(unsigned __int64 size)
{
  char *mFreeListHead; // rbx

  mFreeListHead = UFG::WayTraversal::SearchPool.mFreeListHead;
  if ( UFG::WayTraversal::SearchPool.mFreeListHead )
  {
    UFG::WayTraversal::SearchPool.mFreeListHead = *(char **)UFG::WayTraversal::SearchPool.mFreeListHead;
    if ( UFG::WayTraversal::SearchPool.mMostSlotsAllocated <= ++UFG::WayTraversal::SearchPool.mNumSlotsAllocated )
    {
      UFG::WayTraversal::SearchPool.mMostSlotsAllocated = UFG::WayTraversal::SearchPool.mNumSlotsAllocated;
      return mFreeListHead;
    }
  }
  else
  {
    UFG::qFixedAllocator::ReportFull(&UFG::WayTraversal::SearchPool);
  }
  return mFreeListHead;
}

// File Line: 69
// RVA: 0x66DBA0
void __fastcall UFG::WayTraversalSearch::operator delete(char *ptr)
{
  *(_QWORD *)ptr = UFG::WayTraversal::SearchPool.mFreeListHead;
  --UFG::WayTraversal::SearchPool.mNumSlotsAllocated;
  UFG::WayTraversal::SearchPool.mFreeListHead = ptr;
}

