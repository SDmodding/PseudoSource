// File Line: 65
// RVA: 0x9935E0
void __fastcall Scaleform::MemoryHeap::InitPT(Scaleform::SysAllocPaged *sysAlloc)
{
  _QWORD *v2; // rax
  int i; // ecx

  if ( !Scaleform::HeapPT::GlobalPageTable && !Scaleform::HeapPT::GlobalRoot )
  {
    Scaleform::HeapPT::PageTableMem[0] = 0i64;
    v2 = &unk_142441208;
    for ( i = 4095; i >= 0; --i )
    {
      *v2 = 0i64;
      v2[1] = 0i64;
      v2 += 2;
    }
    Scaleform::HeapPT::GlobalPageTable = (Scaleform::HeapPT::PageTable *)Scaleform::HeapPT::PageTableMem;
    Scaleform::HeapPT::HeapRoot::HeapRoot(&RootMem, sysAlloc);
  }
}

// File Line: 86
// RVA: 0x95EF60
void Scaleform::MemoryHeap::CleanUpPT(void)
{
  Scaleform::HeapPT::HeapRoot *v0; // rbx

  if ( Scaleform::HeapPT::GlobalPageTable )
  {
    if ( Scaleform::HeapPT::GlobalRoot )
    {
      Scaleform::HeapPT::HeapRoot::DestroyAllArenas(Scaleform::HeapPT::GlobalRoot);
      Scaleform::HeapPT::GlobalPageTable = 0i64;
      v0 = Scaleform::HeapPT::GlobalRoot;
      DeleteCriticalSection(&Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs);
      v0->AllocWrapper.Allocator.vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAllocPaged::`vftable;
      v0->AllocWrapper.Allocator.vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAllocBase::`vftable;
      v0->AllocWrapper.vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAllocPaged::`vftable;
      v0->AllocWrapper.vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAllocBase::`vftable;
      Scaleform::HeapPT::GlobalRoot = 0i64;
    }
  }
}

// File Line: 105
// RVA: 0x969400
Scaleform::MemoryHeap *__fastcall Scaleform::MemoryHeap::CreateRootHeapPT(Scaleform::MemoryHeap::HeapDesc *desc)
{
  Scaleform::LockSafe *p_RootLock; // rbx
  Scaleform::MemoryHeap::HeapDesc desca; // [rsp+30h] [rbp-48h] BYREF

  if ( !Scaleform::HeapPT::GlobalRoot )
    return 0i64;
  p_RootLock = &Scaleform::HeapPT::GlobalRoot->RootLock;
  EnterCriticalSection(&Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs);
  if ( Scaleform::Memory::pGlobalHeap )
  {
    LeaveCriticalSection(&p_RootLock->mLock.cs);
    return 0i64;
  }
  *(_OWORD *)&desca.Flags = *(_OWORD *)&desc->Flags;
  *(_OWORD *)&desca.Granularity = *(_OWORD *)&desc->Granularity;
  *(_OWORD *)&desca.Threshold = *(_OWORD *)&desc->Threshold;
  desca.Arena = desc->Arena;
  desca.HeapId = 1i64;
  Scaleform::Memory::pGlobalHeap = Scaleform::HeapPT::HeapRoot::CreateHeap(
                                     Scaleform::HeapPT::GlobalRoot,
                                     "Global",
                                     0i64,
                                     &desca);
  LeaveCriticalSection(&p_RootLock->mLock.cs);
  return Scaleform::Memory::pGlobalHeap;
}

// File Line: 142
// RVA: 0x9A8340
char __fastcall Scaleform::MemoryHeap::ReleaseRootHeapPT()
{
  Scaleform::LockSafe *p_RootLock; // rbx
  bool v2; // di

  if ( !Scaleform::HeapPT::GlobalRoot )
    return 1;
  p_RootLock = &Scaleform::HeapPT::GlobalRoot->RootLock;
  EnterCriticalSection(&Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs);
  if ( Scaleform::Memory::pGlobalHeap )
  {
    v2 = !Scaleform::Memory::pGlobalHeap->vfptr->dumpMemoryLeaks(Scaleform::Memory::pGlobalHeap);
    Scaleform::Memory::pGlobalHeap->vfptr->destroyItself(Scaleform::Memory::pGlobalHeap);
    Scaleform::Memory::pGlobalHeap = 0i64;
  }
  else
  {
    v2 = 1;
  }
  LeaveCriticalSection(&p_RootLock->mLock.cs);
  return v2;
}

// File Line: 177
// RVA: 0x9660D0
void __fastcall Scaleform::MemoryHeapPT::CreateArena(
        Scaleform::MemoryHeapPT *this,
        unsigned __int64 arena,
        Scaleform::SysAllocPaged *sysAlloc)
{
  Scaleform::HeapPT::HeapRoot::CreateArena(Scaleform::HeapPT::GlobalRoot, arena, sysAlloc);
}

// File Line: 183
// RVA: 0x96D8E0
void __fastcall Scaleform::MemoryHeapPT::DestroyArena(Scaleform::MemoryHeapPT *this, unsigned __int64 arena)
{
  Scaleform::HeapPT::HeapRoot::DestroyArena(Scaleform::HeapPT::GlobalRoot, arena);
}

// File Line: 189
// RVA: 0x95A140
_BOOL8 __fastcall Scaleform::MemoryHeapPT::ArenaIsEmpty(Scaleform::MemoryHeapPT *this, unsigned __int64 arena)
{
  return Scaleform::HeapPT::HeapRoot::ArenaIsEmpty(Scaleform::HeapPT::GlobalRoot, arena);
}

// File Line: 198
// RVA: 0x9674E0
Scaleform::MemoryHeapPT *__fastcall Scaleform::MemoryHeapPT::CreateHeap(
        Scaleform::MemoryHeapPT *this,
        const char *name,
        Scaleform::MemoryHeap::HeapDesc *desc)
{
  Scaleform::LockSafe *p_RootLock; // rbp
  Scaleform::MemoryHeapPT *Heap; // rdi

  p_RootLock = &Scaleform::HeapPT::GlobalRoot->RootLock;
  EnterCriticalSection(&Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs);
  Heap = Scaleform::HeapPT::HeapRoot::CreateHeap(Scaleform::HeapPT::GlobalRoot, name, this, desc);
  if ( Heap )
    ++this->RefCount;
  LeaveCriticalSection(&p_RootLock->mLock.cs);
  if ( Heap )
  {
    EnterCriticalSection(&this->HeapLock.cs);
    Heap->pPrev = this->ChildHeaps.Root.Scaleform::MemoryHeap::pPrev;
    Heap->pNext = (Scaleform::MemoryHeap *)&this->Info.pName;
    this->ChildHeaps.Root.Scaleform::MemoryHeap::pPrev->Scaleform::MemoryHeap::pNext = Heap;
    this->ChildHeaps.Root.Scaleform::MemoryHeap::pPrev = Heap;
    LeaveCriticalSection(&this->HeapLock.cs);
  }
  return Heap;
}

// File Line: 224
// RVA: 0x984910
unsigned __int64 __fastcall Scaleform::MemoryHeapPT::GetFootprint(Scaleform::MemoryHeapPT *this)
{
  Scaleform::Lock *p_HeapLock; // rbx
  unsigned __int64 Footprint; // rdi

  p_HeapLock = &this->HeapLock;
  EnterCriticalSection(&this->HeapLock.cs);
  Footprint = this->pEngine->Footprint;
  LeaveCriticalSection(&p_HeapLock->cs);
  return Footprint;
}

// File Line: 231
// RVA: 0x98DD70
unsigned __int64 __fastcall Scaleform::MemoryHeapPT::GetTotalFootprint(Scaleform::MemoryHeapPT *this)
{
  Scaleform::Lock *p_HeapLock; // rbx
  unsigned __int64 Footprint; // rbp
  Scaleform::MemoryHeap *pNext; // rdi
  Scaleform::List<Scaleform::MemoryHeap,Scaleform::MemoryHeap> *p_ChildHeaps; // rsi
  __int64 v6; // rax

  p_HeapLock = &this->HeapLock;
  EnterCriticalSection(&this->HeapLock.cs);
  Footprint = 0i64;
  if ( (this->Info.Desc.Flags & 0x1000) == 0 )
    Footprint = this->pEngine->Footprint;
  pNext = this->ChildHeaps.Root.pNext;
  p_ChildHeaps = &this->ChildHeaps;
  while ( 1 )
  {
    v6 = p_ChildHeaps ? (__int64)&p_ChildHeaps[-1].Root.8 : 0i64;
    if ( pNext == (Scaleform::MemoryHeap *)v6 )
      break;
    Footprint += pNext->vfptr->GetTotalFootprint(pNext);
    pNext = pNext->pNext;
  }
  LeaveCriticalSection(&p_HeapLock->cs);
  return Footprint;
}

// File Line: 249
// RVA: 0x98EA10
unsigned __int64 __fastcall Scaleform::MemoryHeapPT::GetUsedSpace(Scaleform::MemoryHeapPT *this)
{
  Scaleform::Lock *p_HeapLock; // rbx
  unsigned __int64 v3; // rdi

  p_HeapLock = &this->HeapLock;
  EnterCriticalSection(&this->HeapLock.cs);
  v3 = this->pEngine->Footprint
     - (this->pEngine->Allocator.Bin.FreeBlocks << this->pEngine->Allocator.MinAlignShift)
     - this->pEngine->TinyFreeSpace;
  LeaveCriticalSection(&p_HeapLock->cs);
  return v3;
}

// File Line: 256
// RVA: 0x98DED0
unsigned __int64 __fastcall Scaleform::MemoryHeapPT::GetTotalUsedSpace(Scaleform::MemoryHeapPT *this)
{
  Scaleform::Lock *p_HeapLock; // rbx
  unsigned __int64 v3; // rsi
  Scaleform::MemoryHeap *pNext; // rdi
  Scaleform::List<Scaleform::MemoryHeap,Scaleform::MemoryHeap> *p_ChildHeaps; // rbp
  __int64 v6; // rax

  p_HeapLock = &this->HeapLock;
  EnterCriticalSection(&this->HeapLock.cs);
  v3 = 0i64;
  if ( (this->Info.Desc.Flags & 0x1000) == 0 )
    v3 = this->pEngine->Footprint
       - (this->pEngine->Allocator.Bin.FreeBlocks << this->pEngine->Allocator.MinAlignShift)
       - this->pEngine->TinyFreeSpace;
  pNext = this->ChildHeaps.Root.pNext;
  p_ChildHeaps = &this->ChildHeaps;
  while ( 1 )
  {
    v6 = p_ChildHeaps ? (__int64)&p_ChildHeaps[-1].Root.8 : 0i64;
    if ( pNext == (Scaleform::MemoryHeap *)v6 )
      break;
    v3 += pNext->vfptr->GetTotalUsedSpace(pNext);
    pNext = pNext->pNext;
  }
  LeaveCriticalSection(&p_HeapLock->cs);
  return v3;
}

// File Line: 274
// RVA: 0x9B1620
void __fastcall Scaleform::MemoryHeapPT::SetLimitHandler(
        Scaleform::MemoryHeapPT *this,
        Scaleform::MemoryHeap::LimitHandler *handler)
{
  Scaleform::Lock *p_HeapLock; // rbx

  p_HeapLock = &this->HeapLock;
  EnterCriticalSection(&this->HeapLock.cs);
  this->pEngine->pLimHandler = handler;
  LeaveCriticalSection(&p_HeapLock->cs);
}

// File Line: 281
// RVA: 0x9B1520
void __fastcall Scaleform::MemoryHeapPT::SetLimit(Scaleform::MemoryHeapPT *this, unsigned __int64 newLimit)
{
  Scaleform::Lock *p_HeapLock; // rbx
  Scaleform::HeapPT::AllocEngine *pEngine; // rax
  Scaleform::HeapPT::AllocEngine *v6; // rdi
  unsigned __int64 v7; // rax
  unsigned __int64 v8; // rax

  p_HeapLock = &this->HeapLock;
  EnterCriticalSection(&this->HeapLock.cs);
  if ( newLimit < this->Info.Desc.Limit )
  {
    pEngine = this->pEngine;
    if ( newLimit < pEngine->Footprint )
      newLimit = pEngine->Footprint;
  }
  v6 = this->pEngine;
  v7 = Scaleform::HeapPT::AllocEngine::calcDynaSize(v6);
  v8 = v7 * ((newLimit + v7 - 1) / v7);
  v6->Limit = v8;
  this->Info.Desc.Limit = v8;
  LeaveCriticalSection(&p_HeapLock->cs);
}

// File Line: 293
// RVA: 0x954920
void __fastcall Scaleform::MemoryHeapPT::AddRef(Scaleform::MemoryHeapPT *this)
{
  Scaleform::LockSafe *p_RootLock; // rbx

  p_RootLock = &Scaleform::HeapPT::GlobalRoot->RootLock;
  EnterCriticalSection(&Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs);
  ++this->RefCount;
  LeaveCriticalSection(&p_RootLock->mLock.cs);
}

// File Line: 305
// RVA: 0x9A7B20
void __fastcall Scaleform::MemoryHeapPT::Release(Scaleform::MemoryHeapPT *this)
{
  Scaleform::MemoryHeap *pParent; // rsi
  Scaleform::LockSafe *p_RootLock; // rbp
  Scaleform::HeapPT::HeapRoot *v5; // rbx
  Scaleform::LockSafe *v6; // rbx
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [rsp+58h] [rbp+10h]

  pParent = this->Info.pParent;
  if ( pParent )
  {
    lpCriticalSection = &pParent->HeapLock.cs;
    EnterCriticalSection(&pParent->HeapLock.cs);
    p_RootLock = &Scaleform::HeapPT::GlobalRoot->RootLock;
    EnterCriticalSection(&Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs);
    if ( this->RefCount-- == 1 )
    {
      this->vfptr->dumpMemoryLeaks(this);
      this->pPrev->Scaleform::MemoryHeap::pNext = this->pNext;
      this->pNext->Scaleform::MemoryHeap::pPrev = this->pPrev;
      v5 = Scaleform::HeapPT::GlobalRoot;
      Scaleform::HeapPT::AllocEngine::FreeAll(this->pEngine);
      this->vfptr->__vecDelDtor(this, 0i64);
      Scaleform::HeapPT::Bookkeeper::Free(&v5->AllocBookkeeper, (char *)this, this->SelfSize);
    }
    else
    {
      pParent = 0i64;
    }
    LeaveCriticalSection(&p_RootLock->mLock.cs);
    LeaveCriticalSection(lpCriticalSection);
    if ( pParent )
      pParent->vfptr->Release(pParent);
  }
  else
  {
    v6 = &Scaleform::HeapPT::GlobalRoot->RootLock;
    EnterCriticalSection(&Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs);
    --this->RefCount;
    LeaveCriticalSection(&v6->mLock.cs);
  }
}

// File Line: 378
// RVA: 0x9DFAD0
void __fastcall Scaleform::MemoryHeapPT::destroyItself(Scaleform::MemoryHeapPT *this)
{
  Scaleform::MemoryHeap *i; // rcx
  char **v3; // rax
  Scaleform::MemoryHeap *pNext; // rbx
  Scaleform::HeapPT::HeapRoot *v5; // rbx

  for ( i = this->ChildHeaps.Root.pNext; ; i = pNext )
  {
    v3 = this == (Scaleform::MemoryHeapPT *)-136i64 ? 0i64 : &this->Info.pName;
    if ( i == (Scaleform::MemoryHeap *)v3 )
      break;
    pNext = i->pNext;
    i->vfptr->destroyItself(i);
  }
  v5 = Scaleform::HeapPT::GlobalRoot;
  Scaleform::HeapPT::AllocEngine::FreeAll(this->pEngine);
  this->vfptr->__vecDelDtor(this, 0i64);
  Scaleform::HeapPT::Bookkeeper::Free(&v5->AllocBookkeeper, (char *)this, this->SelfSize);
}

// File Line: 605
// RVA: 0x956CC0
void *__fastcall Scaleform::MemoryHeapPT::Alloc(
        Scaleform::MemoryHeapPT *this,
        unsigned __int64 size,
        Scaleform::AllocInfo *info)
{
  Scaleform::Lock *p_HeapLock; // rbx
  void *v6; // rdi

  if ( !this->UseLocks )
    return Scaleform::HeapPT::AllocEngine::Alloc(this->pEngine, size);
  p_HeapLock = &this->HeapLock;
  EnterCriticalSection(&this->HeapLock.cs);
  v6 = Scaleform::HeapPT::AllocEngine::Alloc(this->pEngine, size);
  LeaveCriticalSection(&p_HeapLock->cs);
  return v6;
}

// File Line: 625
// RVA: 0x956C30
void *__fastcall Scaleform::MemoryHeapPT::Alloc(
        Scaleform::MemoryHeapPT *this,
        unsigned __int64 size,
        unsigned __int64 align,
        Scaleform::AllocInfo *info)
{
  Scaleform::Lock *p_HeapLock; // rbx
  void *v8; // rdi

  if ( !this->UseLocks )
    return Scaleform::HeapPT::AllocEngine::Alloc(this->pEngine, size, align);
  p_HeapLock = &this->HeapLock;
  EnterCriticalSection(&this->HeapLock.cs);
  v8 = Scaleform::HeapPT::AllocEngine::Alloc(this->pEngine, size, align);
  LeaveCriticalSection(&p_HeapLock->cs);
  return v8;
}

// File Line: 645
// RVA: 0x9A6520
void *__fastcall Scaleform::MemoryHeapPT::Realloc(
        Scaleform::MemoryHeapPT *this,
        unsigned __int64 oldPtr,
        unsigned __int64 newSize)
{
  unsigned __int64 v5; // rcx
  unsigned __int64 v6; // r10
  unsigned __int64 v7; // r9
  __int64 v8; // r8
  __int64 v9; // rdx
  Scaleform::HeapPT::HeapHeader1 *pTable; // rcx
  Scaleform::Heap::HeapSegment *pSegment; // rbp
  Scaleform::MemoryHeapPT *pHeap; // rdi
  _RTL_CRITICAL_SECTION *p_cs; // rbx
  void *v14; // rdi

  v5 = oldPtr >> 52;
  v6 = (oldPtr >> 40) & 0xFFF;
  v7 = (oldPtr >> 28) & 0xFFF;
  v8 = (unsigned __int8)(oldPtr >> 20);
  v9 = (unsigned __int8)(oldPtr >> 12);
  pTable = Scaleform::HeapPT::GlobalPageTable->RootTable[v5].pTable[v6].pTable[v7].pTable[v8].pTable;
  pSegment = pTable[v9].pSegment;
  pHeap = pSegment->pHeap;
  if ( !pHeap->UseLocks )
    return Scaleform::HeapPT::AllocEngine::Realloc(pHeap->pEngine, pTable[v9].pSegment, (void *)oldPtr, newSize);
  p_cs = &pHeap->HeapLock.cs;
  EnterCriticalSection(&pHeap->HeapLock.cs);
  v14 = Scaleform::HeapPT::AllocEngine::Realloc(pHeap->pEngine, pSegment, (void *)oldPtr, newSize);
  LeaveCriticalSection(p_cs);
  return v14;
}

// File Line: 674
// RVA: 0x97DED0
void __fastcall Scaleform::MemoryHeapPT::Free(Scaleform::MemoryHeapPT *this, char *ptr)
{
  unsigned __int64 v3; // rcx
  unsigned __int64 v4; // r10
  unsigned __int64 v5; // r9
  __int64 v6; // r8
  __int64 v7; // rdx
  Scaleform::HeapPT::HeapHeader1 *pTable; // rcx
  Scaleform::Heap::HeapSegment *pSegment; // rbp
  Scaleform::MemoryHeapPT *pHeap; // rdi

  if ( ptr )
  {
    v3 = (unsigned __int64)ptr >> 52;
    v4 = ((unsigned __int64)ptr >> 40) & 0xFFF;
    v5 = ((unsigned __int64)ptr >> 28) & 0xFFF;
    v6 = (unsigned __int8)((unsigned __int64)ptr >> 20);
    v7 = (unsigned __int8)((unsigned __int64)ptr >> 12);
    pTable = Scaleform::HeapPT::GlobalPageTable->RootTable[v3].pTable[v4].pTable[v5].pTable[v6].pTable;
    pSegment = pTable[v7].pSegment;
    pHeap = pSegment->pHeap;
    if ( pHeap->UseLocks )
    {
      EnterCriticalSection(&pHeap->HeapLock.cs);
      Scaleform::HeapPT::AllocEngine::Free(pHeap->pEngine, pSegment, ptr);
      LeaveCriticalSection(&pHeap->HeapLock.cs);
    }
    else
    {
      Scaleform::HeapPT::AllocEngine::Free(pHeap->pEngine, pTable[v7].pSegment, ptr);
    }
    if ( ptr == pHeap->pAutoRelease )
      pHeap->vfptr->Release(pHeap);
  }
}

// File Line: 747
// RVA: 0x9578B0
void *__fastcall Scaleform::MemoryHeapPT::AllocAutoHeap(
        Scaleform::MemoryHeapPT *this,
        unsigned __int64 thisPtr,
        unsigned __int64 size,
        Scaleform::AllocInfo *info)
{
  Scaleform::MemoryHeapPT *pHeap; // rdi
  _RTL_CRITICAL_SECTION *p_cs; // rbx
  void *v7; // rdi

  pHeap = Scaleform::HeapPT::GlobalPageTable->RootTable[thisPtr >> 52].pTable[(thisPtr >> 40) & 0xFFF].pTable[(thisPtr >> 28) & 0xFFF].pTable[(unsigned __int8)(thisPtr >> 20)].pTable[(unsigned __int8)(thisPtr >> 12)].pSegment->pHeap;
  if ( !pHeap->UseLocks )
    return Scaleform::HeapPT::AllocEngine::Alloc(pHeap->pEngine, size);
  p_cs = &pHeap->HeapLock.cs;
  EnterCriticalSection(&pHeap->HeapLock.cs);
  v7 = Scaleform::HeapPT::AllocEngine::Alloc(pHeap->pEngine, size);
  LeaveCriticalSection(p_cs);
  return v7;
}

// File Line: 773
// RVA: 0x9577C0
void *__fastcall Scaleform::MemoryHeapPT::AllocAutoHeap(
        Scaleform::MemoryHeapPT *this,
        unsigned __int64 thisPtr,
        unsigned __int64 size,
        unsigned __int64 align)
{
  Scaleform::MemoryHeapPT *pHeap; // rdi
  _RTL_CRITICAL_SECTION *p_cs; // rbx
  void *v8; // rdi

  pHeap = Scaleform::HeapPT::GlobalPageTable->RootTable[thisPtr >> 52].pTable[(thisPtr >> 40) & 0xFFF].pTable[(thisPtr >> 28) & 0xFFF].pTable[(unsigned __int8)(thisPtr >> 20)].pTable[(unsigned __int8)(thisPtr >> 12)].pSegment->pHeap;
  if ( !pHeap->UseLocks )
    return Scaleform::HeapPT::AllocEngine::Alloc(pHeap->pEngine, size, align);
  p_cs = &pHeap->HeapLock.cs;
  EnterCriticalSection(&pHeap->HeapLock.cs);
  v8 = Scaleform::HeapPT::AllocEngine::Alloc(pHeap->pEngine, size, align);
  LeaveCriticalSection(p_cs);
  return v8;
}

// File Line: 798
// RVA: 0x97FF00
Scaleform::MemoryHeapPT *__fastcall Scaleform::MemoryHeapPT::GetAllocHeap(
        Scaleform::MemoryHeapPT *this,
        unsigned __int64 thisPtr)
{
  return Scaleform::HeapPT::GlobalPageTable->RootTable[thisPtr >> 52].pTable[(thisPtr >> 40) & 0xFFF].pTable[(thisPtr >> 28) & 0xFFF].pTable[(unsigned __int8)(thisPtr >> 20)].pTable[(unsigned __int8)(thisPtr >> 12)].pSegment->pHeap;
}

// File Line: 815
// RVA: 0x98E7D0
unsigned __int64 __fastcall Scaleform::MemoryHeapPT::GetUsableSize(Scaleform::MemoryHeapPT *this, unsigned __int64 ptr)
{
  Scaleform::Heap::HeapSegment *pSegment; // rbp
  Scaleform::MemoryHeapPT *pHeap; // rdi
  _RTL_CRITICAL_SECTION *p_cs; // rbx
  Scaleform::HeapPT::AllocEngine *pEngine; // rdi
  unsigned int SegType; // eax
  unsigned __int64 DataSize; // rsi
  unsigned __int64 MinAlignShift; // rdi
  Scaleform::HeapPT::AllocEngine *v11; // rbx
  unsigned int v12; // eax
  unsigned __int64 v13; // rbx

  pSegment = Scaleform::HeapPT::GlobalPageTable->RootTable[ptr >> 52].pTable[(ptr >> 40) & 0xFFF].pTable[(ptr >> 28) & 0xFFF].pTable[(unsigned __int8)(ptr >> 20)].pTable[(unsigned __int8)(ptr >> 12)].pSegment;
  pHeap = pSegment->pHeap;
  if ( pHeap->UseLocks )
  {
    p_cs = &pHeap->HeapLock.cs;
    EnterCriticalSection(&pHeap->HeapLock.cs);
    pEngine = pHeap->pEngine;
    SegType = pSegment->SegType;
    if ( SegType > 7 )
    {
      if ( SegType == 10 )
      {
        MinAlignShift = pEngine->Allocator.MinAlignShift;
        DataSize = Scaleform::Heap::BitSet2::GetBlockSize(
                     (const unsigned int *)&pSegment[1],
                     (__int64)(ptr - (unsigned __int64)pSegment->pData) >> MinAlignShift) << MinAlignShift;
      }
      else
      {
        DataSize = pSegment->DataSize;
      }
    }
    else
    {
      DataSize = (unsigned __int64)(SegType + 1) << pEngine->MinAlignShift;
    }
    LeaveCriticalSection(p_cs);
    return DataSize;
  }
  else
  {
    v11 = pHeap->pEngine;
    v12 = pSegment->SegType;
    if ( v12 > 7 )
    {
      if ( v12 == 10 )
      {
        v13 = v11->Allocator.MinAlignShift;
        return Scaleform::Heap::BitSet2::GetBlockSize(
                 (const unsigned int *)&pSegment[1],
                 (__int64)(ptr - (unsigned __int64)pSegment->pData) >> v13) << v13;
      }
      else
      {
        return pSegment->DataSize;
      }
    }
    else
    {
      return (unsigned __int64)(v12 + 1) << v11->MinAlignShift;
    }
  }
}

// File Line: 839
// RVA: 0x9EFB80
void __fastcall Scaleform::MemoryHeapPT::releaseCachedMem(Scaleform::MemoryHeapPT *this)
{
  Scaleform::Lock *p_HeapLock; // rbx
  Scaleform::MemoryHeap *i; // rdi
  char **v4; // rax

  p_HeapLock = &this->HeapLock;
  EnterCriticalSection(&this->HeapLock.cs);
  for ( i = this->ChildHeaps.Root.pNext; ; i = i->pNext )
  {
    v4 = this == (Scaleform::MemoryHeapPT *)-136i64 ? 0i64 : &this->Info.pName;
    if ( i == (Scaleform::MemoryHeap *)v4 )
      break;
    i->vfptr->releaseCachedMem(i);
  }
  Scaleform::HeapPT::AllocEngine::ReleaseCachedMem(this->pEngine);
  LeaveCriticalSection(&p_HeapLock->cs);
}

// File Line: 852
// RVA: 0x957F60
__int64 __fastcall Scaleform::MemoryHeapPT::AllocSysDirect(Scaleform::MemoryHeapPT *this, unsigned __int64 size)
{
  return Scaleform::HeapPT::HeapRoot::AllocSysDirect(Scaleform::HeapPT::GlobalRoot, size);
}

// File Line: 856
// RVA: 0x97E620
void __fastcall Scaleform::MemoryHeapPT::FreeSysDirect(Scaleform::MemoryHeapPT *this, void *ptr, unsigned __int64 size)
{
  Scaleform::HeapPT::HeapRoot::FreeSysDirect(Scaleform::HeapPT::GlobalRoot, ptr, size);
}

// File Line: 862
// RVA: 0x98BB70
char __fastcall Scaleform::MemoryHeapPT::GetStats(Scaleform::MemoryHeapPT *this, Scaleform::StatBag *bag)
{
  Scaleform::Lock *p_HeapLock; // rbx
  Scaleform::HeapPT::AllocEngine *pEngine; // rax
  Scaleform::Heap::HeapSegment *pNext; // rdx
  Scaleform::List<Scaleform::Heap::HeapSegment,Scaleform::Heap::HeapSegment> *i; // rax
  Scaleform::MemoryHeap *v7; // rdi
  Scaleform::List<Scaleform::MemoryHeap,Scaleform::MemoryHeap> *p_ChildHeaps; // rsi
  __int64 v9; // rax

  p_HeapLock = &this->HeapLock;
  EnterCriticalSection(&this->HeapLock.cs);
  pEngine = this->pEngine;
  pNext = pEngine->SegmentList.Root.pNext;
  for ( i = &pEngine->SegmentList; pNext != (Scaleform::Heap::HeapSegment *)i; pNext = pNext->pNext )
    ;
  v7 = this->ChildHeaps.Root.pNext;
  p_ChildHeaps = &this->ChildHeaps;
  while ( 1 )
  {
    v9 = p_ChildHeaps ? (__int64)&p_ChildHeaps[-1].Root.8 : 0i64;
    if ( v7 == (Scaleform::MemoryHeap *)v9 )
      break;
    if ( (v7->Info.Desc.Flags & 0x1000) == 0 )
      v7->vfptr->GetTotalFootprint(v7);
    v7 = v7->pNext;
  }
  LeaveCriticalSection(&p_HeapLock->cs);
  return 1;
}

// File Line: 940
// RVA: 0x9C1D30
void __fastcall Scaleform::MemoryHeapPT::VisitMem(
        Scaleform::MemoryHeapPT *this,
        Scaleform::Heap::MemVisitor *visitor,
        unsigned int flags)
{
  Scaleform::Lock *p_HeapLock; // rbx

  p_HeapLock = &this->HeapLock;
  EnterCriticalSection(&this->HeapLock.cs);
  Scaleform::HeapPT::AllocEngine::VisitMem(this->pEngine, visitor, flags);
  LeaveCriticalSection(&p_HeapLock->cs);
}

// File Line: 950
// RVA: 0x9C1940
void __fastcall Scaleform::MemoryHeapPT::VisitHeapSegments(
        Scaleform::MemoryHeapPT *this,
        Scaleform::Heap::SegVisitor *visitor)
{
  Scaleform::Lock *p_HeapLock; // rbx

  p_HeapLock = &this->HeapLock;
  EnterCriticalSection(&this->HeapLock.cs);
  Scaleform::HeapPT::AllocEngine::VisitSegments(this->pEngine, visitor);
  LeaveCriticalSection(&p_HeapLock->cs);
}

// File Line: 957
// RVA: 0x9C1E50
void __fastcall Scaleform::MemoryHeapPT::VisitRootSegments(
        Scaleform::MemoryHeapPT *this,
        Scaleform::Heap::SegVisitor *visitor)
{
  Scaleform::HeapPT::HeapRoot::VisitSegments(Scaleform::HeapPT::GlobalRoot, visitor);
}

// File Line: 963
// RVA: 0x9E79E0
void __fastcall Scaleform::MemoryHeapPT::getUserDebugStats(
        Scaleform::MemoryHeapPT *this,
        Scaleform::MemoryHeap::RootStats *stats)
{
  Scaleform::Lock *p_HeapLock; // rbx
  Scaleform::MemoryHeap *pNext; // rdi
  Scaleform::List<Scaleform::MemoryHeap,Scaleform::MemoryHeap> *p_ChildHeaps; // rsi
  __int64 v7; // rax

  p_HeapLock = &this->HeapLock;
  EnterCriticalSection(&this->HeapLock.cs);
  if ( (this->Info.Desc.Flags & 0x1000) != 0 )
  {
    stats->UserDebugFootprint += this->pEngine->Footprint;
    stats->UserDebugUsedSpace += this->pEngine->Footprint
                               - (this->pEngine->Allocator.Bin.FreeBlocks << this->pEngine->Allocator.MinAlignShift)
                               - this->pEngine->TinyFreeSpace;
  }
  pNext = this->ChildHeaps.Root.pNext;
  p_ChildHeaps = &this->ChildHeaps;
  while ( 1 )
  {
    v7 = p_ChildHeaps ? (__int64)&p_ChildHeaps[-1].Root.8 : 0i64;
    if ( pNext == (Scaleform::MemoryHeap *)v7 )
      break;
    pNext->vfptr->getUserDebugStats(pNext, stats);
    pNext = pNext->pNext;
  }
  LeaveCriticalSection(&p_HeapLock->cs);
}

// File Line: 980
// RVA: 0x98B210
void __fastcall Scaleform::MemoryHeapPT::GetRootStats(
        Scaleform::MemoryHeapPT *this,
        Scaleform::MemoryHeap::RootStats *stats)
{
  Scaleform::HeapPT::HeapRoot::GetStats(Scaleform::HeapPT::GlobalRoot, stats);
  stats->UserDebugFootprint = 0i64;
  stats->UserDebugUsedSpace = 0i64;
  Scaleform::Memory::pGlobalHeap->vfptr->getUserDebugStats(Scaleform::Memory::pGlobalHeap, stats);
}

// File Line: 989
// RVA: 0x9D5AB0
void __fastcall Scaleform::MemoryHeapPT::checkIntegrity(Scaleform::MemoryHeapPT *this)
{
  Scaleform::Lock *p_HeapLock; // rbx
  Scaleform::MemoryHeap *pNext; // rdi
  Scaleform::List<Scaleform::MemoryHeap,Scaleform::MemoryHeap> *p_ChildHeaps; // rsi
  __int64 v5; // rax

  p_HeapLock = &this->HeapLock;
  EnterCriticalSection(&this->HeapLock.cs);
  pNext = this->ChildHeaps.Root.pNext;
  p_ChildHeaps = &this->ChildHeaps;
  while ( 1 )
  {
    v5 = p_ChildHeaps ? (__int64)&p_ChildHeaps[-1].Root.8 : 0i64;
    if ( pNext == (Scaleform::MemoryHeap *)v5 )
      break;
    pNext->vfptr->checkIntegrity(pNext);
    pNext = pNext->pNext;
  }
  LeaveCriticalSection(&p_HeapLock->cs);
}

// File Line: 1019
// RVA: 0x9E8460
bool __fastcall Scaleform::SysAllocPaged::initHeapEngine(
        Scaleform::SysAllocPaged *this,
        Scaleform::MemoryHeap::HeapDesc *heapDesc)
{
  Scaleform::MemoryHeap::InitPT(this);
  return Scaleform::MemoryHeap::CreateRootHeapPT(heapDesc) != 0i64;
}

// File Line: 1027
// RVA: 0x9F24E0
__int64 __fastcall Scaleform::SysAllocPaged::shutdownHeapEngine(Scaleform::SysAllocPaged *this)
{
  unsigned __int8 v1; // bl

  v1 = Scaleform::MemoryHeap::ReleaseRootHeapPT();
  Scaleform::MemoryHeap::CleanUpPT();
  return v1;
}

