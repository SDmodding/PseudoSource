// File Line: 40
// RVA: 0x773940
void __fastcall Scaleform::FixedBitSetBase<Scaleform::AllocatorDH<unsigned char,341>>::FixedBitSetBase<Scaleform::AllocatorDH<unsigned char,341>>(Scaleform::FixedBitSetBase<Scaleform::AllocatorDH<unsigned char,341> > *this, Scaleform::FixedBitSetBase<Scaleform::AllocatorDH<unsigned char,341> > *other)
{
  unsigned int v2; // eax
  Scaleform::FixedBitSetBase<Scaleform::AllocatorDH<unsigned char,341> > *v3; // rsi
  Scaleform::FixedBitSetBase<Scaleform::AllocatorDH<unsigned char,341> > *v4; // rdi
  unsigned int v5; // ebx
  Scaleform::MemoryHeap *v6; // rax
  Scaleform::MemoryHeapVtbl *v7; // r9
  char *v8; // rax
  int v9; // [rsp+30h] [rbp+8h]

  v2 = other->BitsCount;
  v3 = this;
  v4 = other;
  this->BitsCount = v2;
  v5 = (v2 + 7) >> 3;
  v6 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, other->pData);
  v7 = v6->vfptr;
  v9 = 341;
  v8 = (char *)v7->Alloc(v6, v5, (Scaleform::AllocInfo *)&v9);
  v3->pData = v8;
  memmove(v8, v4->pData, v5);
}

