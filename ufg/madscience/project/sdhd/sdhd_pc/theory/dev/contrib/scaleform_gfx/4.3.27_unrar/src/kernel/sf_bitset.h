// File Line: 40
// RVA: 0x773940
void __fastcall Scaleform::FixedBitSetBase<Scaleform::AllocatorDH<unsigned char,341>>::FixedBitSetBase<Scaleform::AllocatorDH<unsigned char,341>>(
        Scaleform::FixedBitSetBase<Scaleform::AllocatorDH<unsigned char,341> > *this,
        Scaleform::FixedBitSetBase<Scaleform::AllocatorDH<unsigned char,341> > *other)
{
  unsigned int BitsCount; // eax
  unsigned int v5; // ebx
  Scaleform::MemoryHeap *v6; // rax
  Scaleform::MemoryHeapVtbl *vfptr; // r9
  char *v8; // rax
  int v9; // [rsp+30h] [rbp+8h] BYREF

  BitsCount = other->BitsCount;
  this->BitsCount = BitsCount;
  v5 = (BitsCount + 7) >> 3;
  v6 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, other->pData);
  vfptr = v6->vfptr;
  v9 = 341;
  v8 = (char *)vfptr->Alloc(v6, v5, (Scaleform::AllocInfo *)&v9);
  this->pData = v8;
  memmove(v8, other->pData, v5);
}

