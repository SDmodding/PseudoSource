// File Line: 29
// RVA: 0x141960
void __fastcall UFG::OneShot::operator delete(void *ptr)
{
  *(_QWORD *)ptr = UFG::gOneShotPool.mFreeListHead;
  --UFG::gOneShotPool.mNumSlotsAllocated;
  UFG::gOneShotPool.mFreeListHead = (char *)ptr;
}

