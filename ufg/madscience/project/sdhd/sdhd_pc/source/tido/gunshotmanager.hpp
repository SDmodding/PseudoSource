// File Line: 33
// RVA: 0x594BE0
void __fastcall UFG::GunshotRequest::operator delete(char *ptr)
{
  *(_QWORD *)ptr = UFG::gGunshotRequestPool.mFreeListHead;
  --UFG::gGunshotRequestPool.mNumSlotsAllocated;
  UFG::gGunshotRequestPool.mFreeListHead = ptr;
}

