// File Line: 154
// RVA: 0x6BC6C0
void __fastcall operator delete<512,8>(void *p, Scaleform::StackMemPool<512,8,Scaleform::MemPoolImmediateFree> *pool)
{
  if ( p < pool->Buff || p >= &pool->BuffPtr )
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, p);
}

