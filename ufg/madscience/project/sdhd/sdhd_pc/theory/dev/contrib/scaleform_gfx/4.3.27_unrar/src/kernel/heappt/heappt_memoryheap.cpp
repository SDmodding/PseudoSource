// File Line: 65
// RVA: 0x9935E0
void __fastcall Scaleform::MemoryHeap::InitPT(Scaleform::SysAllocPaged *sysAlloc)
{
  Scaleform::SysAllocPaged *v1; // rdx
  _QWORD *v2; // rax
  signed int v3; // ecx

  v1 = sysAlloc;
  if ( !Scaleform::HeapPT::GlobalPageTable && !Scaleform::HeapPT::GlobalRoot )
  {
    Scaleform::HeapPT::PageTableMem[0] = 0i64;
    v2 = &unk_142441208;
    v3 = 4095;
    do
    {
      *v2 = 0i64;
      v2[1] = 0i64;
      v2 += 2;
      --v3;
    }
    while ( v3 >= 0 );
    Scaleform::HeapPT::GlobalPageTable = (Scaleform::HeapPT::PageTable *)Scaleform::HeapPT::PageTableMem;
    Scaleform::HeapPT::HeapRoot::HeapRoot(&RootMem, v1);
  }
}

// File Line: 86
// RVA: 0x95EF60
void Scaleform::MemoryHeap::CleanUpPT(void)
{
  Scaleform::HeapPT::HeapRoot *v0; // rbx
  Scaleform::HeapPT::SysAllocGranulator *v1; // [rsp+48h] [rbp+10h]

  if ( Scaleform::HeapPT::GlobalPageTable )
  {
    if ( Scaleform::HeapPT::GlobalRoot )
    {
      Scaleform::HeapPT::HeapRoot::DestroyAllArenas(Scaleform::HeapPT::GlobalRoot);
      Scaleform::HeapPT::GlobalPageTable = 0i64;
      v0 = Scaleform::HeapPT::GlobalRoot;
      DeleteCriticalSection(&Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs);
      v1 = &v0->AllocWrapper.Allocator;
      v1->vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAllocPaged::`vftable';
      v1->vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAllocBase::`vftable';
      v0->AllocWrapper.vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAllocPaged::`vftable';
      v0->AllocWrapper.vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAllocBase::`vftable';
      Scaleform::HeapPT::GlobalRoot = 0i64;
    }
  }
}

// File Line: 105
// RVA: 0x969400
Scaleform::MemoryHeap *__fastcall Scaleform::MemoryHeap::CreateRootHeapPT(Scaleform::MemoryHeap::HeapDesc *desc)
{
  Scaleform::MemoryHeap::HeapDesc *v1; // rdi
  _RTL_CRITICAL_SECTION *v2; // rbx
  Scaleform::MemoryHeap::HeapDesc desca; // [rsp+30h] [rbp-48h]

  v1 = desc;
  if ( !Scaleform::HeapPT::GlobalRoot )
    return 0i64;
  v2 = &Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs;
  EnterCriticalSection(&Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs);
  if ( Scaleform::Memory::pGlobalHeap )
  {
    LeaveCriticalSection(v2);
    return 0i64;
  }
  *(_OWORD *)&desca.Flags = *(_OWORD *)&v1->Flags;
  *(_OWORD *)&desca.Granularity = *(_OWORD *)&v1->Granularity;
  *(_OWORD *)&desca.Threshold = *(_OWORD *)&v1->Threshold;
  *(_OWORD *)&desca.HeapId = *(_OWORD *)&v1->HeapId;
  desca.HeapId = 1i64;
  Scaleform::Memory::pGlobalHeap = (Scaleform::MemoryHeap *)Scaleform::HeapPT::HeapRoot::CreateHeap(
                                                              Scaleform::HeapPT::GlobalRoot,
                                                              "Global",
                                                              0i64,
                                                              &desca);
  LeaveCriticalSection(v2);
  return Scaleform::Memory::pGlobalHeap;
}

// File Line: 142
// RVA: 0x9A8340
char __fastcall Scaleform::MemoryHeap::ReleaseRootHeapPT()
{
  _RTL_CRITICAL_SECTION *v1; // rbx
  bool v2; // di

  if ( !Scaleform::HeapPT::GlobalRoot )
    return 1;
  v1 = &Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs;
  EnterCriticalSection(&Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs);
  if ( Scaleform::Memory::pGlobalHeap )
  {
    v2 = ((unsigned __int8 (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->dumpMemoryLeaks)(Scaleform::Memory::pGlobalHeap) == 0;
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->destroyItself)(Scaleform::Memory::pGlobalHeap);
    Scaleform::Memory::pGlobalHeap = 0i64;
  }
  else
  {
    v2 = 1;
  }
  LeaveCriticalSection(v1);
  return v2;
}

// File Line: 177
// RVA: 0x9660D0
void __fastcall Scaleform::MemoryHeapPT::CreateArena(Scaleform::MemoryHeapPT *this, unsigned __int64 arena, Scaleform::SysAllocPaged *sysAlloc)
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
Scaleform::MemoryHeapPT *__fastcall Scaleform::MemoryHeapPT::CreateHeap(Scaleform::MemoryHeapPT *this, const char *name, Scaleform::MemoryHeap::HeapDesc *desc)
{
  Scaleform::MemoryHeap::HeapDesc *v3; // rbx
  const char *v4; // rdi
  Scaleform::MemoryHeapPT *v5; // rsi
  _RTL_CRITICAL_SECTION *v6; // rbp
  Scaleform::MemoryHeapPT *v7; // rdi

  v3 = desc;
  v4 = name;
  v5 = this;
  v6 = &Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs;
  EnterCriticalSection(&Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs);
  v7 = Scaleform::HeapPT::HeapRoot::CreateHeap(Scaleform::HeapPT::GlobalRoot, v4, v5, v3);
  if ( v7 )
    ++v5->RefCount;
  LeaveCriticalSection(v6);
  if ( v7 )
  {
    EnterCriticalSection(&v5->HeapLock.cs);
    v7->pPrev = v5->ChildHeaps.Root.pPrev;
    v7->pNext = (Scaleform::MemoryHeap *)&v5->Info.pName;
    v5->ChildHeaps.Root.pPrev->pNext = (Scaleform::MemoryHeap *)&v7->vfptr;
    v5->ChildHeaps.Root.pPrev = (Scaleform::MemoryHeap *)&v7->vfptr;
    LeaveCriticalSection(&v5->HeapLock.cs);
  }
  return v7;
}

// File Line: 224
// RVA: 0x984910
unsigned __int64 __fastcall Scaleform::MemoryHeapPT::GetFootprint(Scaleform::MemoryHeapPT *this)
{
  Scaleform::MemoryHeapPT *v1; // rdi
  _RTL_CRITICAL_SECTION *v2; // rbx
  unsigned __int64 v3; // rdi

  v1 = this;
  v2 = &this->HeapLock.cs;
  EnterCriticalSection(&this->HeapLock.cs);
  v3 = v1->pEngine->Footprint;
  LeaveCriticalSection(v2);
  return v3;
}

// File Line: 231
// RVA: 0x98DD70
unsigned __int64 __fastcall Scaleform::MemoryHeapPT::GetTotalFootprint(Scaleform::MemoryHeapPT *this)
{
  Scaleform::MemoryHeapPT *v1; // rsi
  _RTL_CRITICAL_SECTION *v2; // rbx
  unsigned __int64 v3; // rbp
  Scaleform::MemoryHeap *v4; // rdi
  signed __int64 v5; // rsi
  signed __int64 v6; // rax

  v1 = this;
  v2 = &this->HeapLock.cs;
  EnterCriticalSection(&this->HeapLock.cs);
  v3 = 0i64;
  if ( !(v1->Info.Desc.Flags & 0x1000) )
    v3 = v1->pEngine->Footprint;
  v4 = v1->ChildHeaps.Root.pNext;
  v5 = (signed __int64)&v1->ChildHeaps;
  while ( 1 )
  {
    v6 = v5 ? v5 - 8 : 0i64;
    if ( v4 == (Scaleform::MemoryHeap *)v6 )
      break;
    v3 += v4->vfptr->GetTotalFootprint(v4);
    v4 = v4->pNext;
  }
  LeaveCriticalSection(v2);
  return v3;
}

// File Line: 249
// RVA: 0x98EA10
unsigned __int64 __fastcall Scaleform::MemoryHeapPT::GetUsedSpace(Scaleform::MemoryHeapPT *this)
{
  Scaleform::MemoryHeapPT *v1; // rdi
  _RTL_CRITICAL_SECTION *v2; // rbx
  unsigned __int64 v3; // rdi

  v1 = this;
  v2 = &this->HeapLock.cs;
  EnterCriticalSection(&this->HeapLock.cs);
  v3 = v1->pEngine->Footprint
     - (v1->pEngine->Allocator.Bin.FreeBlocks << v1->pEngine->Allocator.MinAlignShift)
     - v1->pEngine->TinyFreeSpace;
  LeaveCriticalSection(v2);
  return v3;
}

// File Line: 256
// RVA: 0x98DED0
unsigned __int64 __fastcall Scaleform::MemoryHeapPT::GetTotalUsedSpace(Scaleform::MemoryHeapPT *this)
{
  Scaleform::MemoryHeapPT *v1; // rbp
  _RTL_CRITICAL_SECTION *v2; // rbx
  unsigned __int64 v3; // rsi
  Scaleform::MemoryHeap *v4; // rdi
  signed __int64 v5; // rbp
  signed __int64 v6; // rax

  v1 = this;
  v2 = &this->HeapLock.cs;
  EnterCriticalSection(&this->HeapLock.cs);
  v3 = 0i64;
  if ( !(v1->Info.Desc.Flags & 0x1000) )
    v3 = v1->pEngine->Footprint
       - (v1->pEngine->Allocator.Bin.FreeBlocks << v1->pEngine->Allocator.MinAlignShift)
       - v1->pEngine->TinyFreeSpace;
  v4 = v1->ChildHeaps.Root.pNext;
  v5 = (signed __int64)&v1->ChildHeaps;
  while ( 1 )
  {
    v6 = v5 ? v5 - 8 : 0i64;
    if ( v4 == (Scaleform::MemoryHeap *)v6 )
      break;
    v3 += v4->vfptr->GetTotalUsedSpace(v4);
    v4 = v4->pNext;
  }
  LeaveCriticalSection(v2);
  return v3;
}

// File Line: 274
// RVA: 0x9B1620
void __fastcall Scaleform::MemoryHeapPT::SetLimitHandler(Scaleform::MemoryHeapPT *this, Scaleform::MemoryHeap::LimitHandler *handler)
{
  Scaleform::MemoryHeap::LimitHandler *v2; // rsi
  Scaleform::MemoryHeapPT *v3; // rdi
  _RTL_CRITICAL_SECTION *v4; // rbx

  v2 = handler;
  v3 = this;
  v4 = &this->HeapLock.cs;
  EnterCriticalSection(&this->HeapLock.cs);
  v3->pEngine->pLimHandler = v2;
  LeaveCriticalSection(v4);
}

// File Line: 281
// RVA: 0x9B1520
void __fastcall Scaleform::MemoryHeapPT::SetLimit(Scaleform::MemoryHeapPT *this, unsigned __int64 newLimit)
{
  unsigned __int64 v2; // rsi
  Scaleform::MemoryHeapPT *v3; // rbp
  _RTL_CRITICAL_SECTION *v4; // rbx
  Scaleform::HeapPT::AllocEngine *v5; // rax
  Scaleform::HeapPT::AllocEngine *v6; // rdi
  unsigned __int64 v7; // rax
  unsigned __int64 v8; // rax

  v2 = newLimit;
  v3 = this;
  v4 = &this->HeapLock.cs;
  EnterCriticalSection(&this->HeapLock.cs);
  if ( v2 < v3->Info.Desc.Limit )
  {
    v5 = v3->pEngine;
    if ( v2 < v5->Footprint )
      v2 = v5->Footprint;
  }
  v6 = v3->pEngine;
  v7 = Scaleform::HeapPT::AllocEngine::calcDynaSize(v3->pEngine);
  v8 = v7 * ((v2 + v7 - 1) / v7);
  v6->Limit = v8;
  v3->Info.Desc.Limit = v8;
  LeaveCriticalSection(v4);
}

// File Line: 293
// RVA: 0x954920
void __fastcall Scaleform::MemoryHeapPT::AddRef(Scaleform::MemoryHeapPT *this)
{
  Scaleform::MemoryHeapPT *v1; // rdi
  _RTL_CRITICAL_SECTION *v2; // rbx

  v1 = this;
  v2 = &Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs;
  EnterCriticalSection(&Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs);
  ++v1->RefCount;
  LeaveCriticalSection(v2);
}

// File Line: 305
// RVA: 0x9A7B20
void __fastcall Scaleform::MemoryHeapPT::Release(Scaleform::MemoryHeapPT *this)
{
  Scaleform::MemoryHeapPT *v1; // rdi
  Scaleform::MemoryHeap *v2; // rsi
  _RTL_CRITICAL_SECTION *v3; // rbp
  bool v4; // zf
  __int64 v5; // rax
  Scaleform::HeapPT::HeapRoot *v6; // rbx
  _RTL_CRITICAL_SECTION *v7; // rbx
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [rsp+58h] [rbp+10h]

  v1 = this;
  v2 = this->Info.pParent;
  if ( v2 )
  {
    lpCriticalSection = &v2->HeapLock.cs;
    EnterCriticalSection(&v2->HeapLock.cs);
    v3 = &Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs;
    EnterCriticalSection(&Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs);
    v4 = v1->RefCount-- == 1;
    v5 = v1->RefCount;
    if ( v4 )
    {
      v1->vfptr->dumpMemoryLeaks((Scaleform::MemoryHeap *)&v1->vfptr);
      v1->pPrev->pNext = v1->pNext;
      v1->pNext->pPrev = v1->pPrev;
      v6 = Scaleform::HeapPT::GlobalRoot;
      Scaleform::HeapPT::AllocEngine::FreeAll(v1->pEngine);
      v1->vfptr->__vecDelDtor((Scaleform::MemoryHeap *)&v1->vfptr, 0);
      Scaleform::HeapPT::Bookkeeper::Free(&v6->AllocBookkeeper, v1, v1->SelfSize);
    }
    else
    {
      v2 = 0i64;
    }
    LeaveCriticalSection(v3);
    LeaveCriticalSection(lpCriticalSection);
    if ( v2 )
      v2->vfptr->Release(v2);
  }
  else
  {
    v7 = &Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs;
    EnterCriticalSection(&Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs);
    --v1->RefCount;
    LeaveCriticalSection(v7);
  }
}

// File Line: 378
// RVA: 0x9DFAD0
void __fastcall Scaleform::MemoryHeapPT::destroyItself(Scaleform::MemoryHeapPT *this)
{
  Scaleform::MemoryHeapPT *v1; // rsi
  Scaleform::MemoryHeap *i; // rcx
  signed __int64 v3; // rax
  Scaleform::MemoryHeap *v4; // rbx
  Scaleform::HeapPT::HeapRoot *v5; // rbx

  v1 = this;
  for ( i = this->ChildHeaps.Root.pNext; ; i = v4 )
  {
    v3 = (signed __int64)(v1 == (Scaleform::MemoryHeapPT *)-136i64 ? 0i64 : &v1->Info.pName);
    if ( i == (Scaleform::MemoryHeap *)v3 )
      break;
    v4 = i->pNext;
    ((void (*)(void))i->vfptr->destroyItself)();
  }
  v5 = Scaleform::HeapPT::GlobalRoot;
  Scaleform::HeapPT::AllocEngine::FreeAll(v1->pEngine);
  v1->vfptr->__vecDelDtor((Scaleform::MemoryHeap *)&v1->vfptr, 0);
  Scaleform::HeapPT::Bookkeeper::Free(&v5->AllocBookkeeper, v1, v1->SelfSize);
}

// File Line: 605
// RVA: 0x956CC0
void *__fastcall Scaleform::MemoryHeapPT::Alloc(Scaleform::MemoryHeapPT *this, unsigned __int64 size, Scaleform::AllocInfo *info)
{
  unsigned __int64 v3; // rsi
  Scaleform::MemoryHeapPT *v4; // rdi
  _RTL_CRITICAL_SECTION *v5; // rbx
  void *v6; // rdi

  v3 = size;
  v4 = this;
  if ( !this->UseLocks )
    return Scaleform::HeapPT::AllocEngine::Alloc(this->pEngine, size);
  v5 = &this->HeapLock.cs;
  EnterCriticalSection(&this->HeapLock.cs);
  v6 = Scaleform::HeapPT::AllocEngine::Alloc(v4->pEngine, v3);
  LeaveCriticalSection(v5);
  return v6;
}

// File Line: 625
// RVA: 0x956C30
void *__fastcall Scaleform::MemoryHeapPT::Alloc(Scaleform::MemoryHeapPT *this, unsigned __int64 size, unsigned __int64 align, Scaleform::AllocInfo *info)
{
  unsigned __int64 v4; // rsi
  unsigned __int64 v5; // rbp
  Scaleform::MemoryHeapPT *v6; // rdi
  _RTL_CRITICAL_SECTION *v7; // rbx
  void *v8; // rdi

  v4 = align;
  v5 = size;
  v6 = this;
  if ( !this->UseLocks )
    return Scaleform::HeapPT::AllocEngine::Alloc(this->pEngine, size, align);
  v7 = &this->HeapLock.cs;
  EnterCriticalSection(&this->HeapLock.cs);
  v8 = Scaleform::HeapPT::AllocEngine::Alloc(v6->pEngine, v5, v4);
  LeaveCriticalSection(v7);
  return v8;
}

// File Line: 645
// RVA: 0x9A6520
void *__fastcall Scaleform::MemoryHeapPT::Realloc(Scaleform::MemoryHeapPT *this, void *oldPtr, unsigned __int64 newSize)
{
  unsigned __int64 v3; // r14
  void *v4; // rsi
  unsigned __int64 v5; // rcx
  unsigned __int64 v6; // r10
  unsigned __int64 v7; // r9
  __int64 v8; // r8
  __int64 v9; // rdx
  Scaleform::HeapPT::HeapHeader1 *v10; // rcx
  Scaleform::Heap::HeapSegment *v11; // rbp
  Scaleform::MemoryHeapPT *v12; // rdi
  _RTL_CRITICAL_SECTION *v13; // rbx
  void *v14; // rdi

  v3 = newSize;
  v4 = oldPtr;
  v5 = (unsigned __int64)oldPtr >> 52;
  v6 = ((unsigned __int64)oldPtr >> 40) & 0xFFF;
  v7 = ((unsigned __int64)oldPtr >> 28) & 0xFFF;
  v8 = (unsigned __int8)((unsigned __int64)oldPtr >> 20);
  v9 = (unsigned __int8)((unsigned __int64)oldPtr >> 12);
  v10 = Scaleform::HeapPT::GlobalPageTable->RootTable[v5].pTable[v6].pTable[v7].pTable[v8].pTable;
  v11 = v10[v9].pSegment;
  v12 = v11->pHeap;
  if ( !v12->UseLocks )
    return Scaleform::HeapPT::AllocEngine::Realloc(v12->pEngine, v10[v9].pSegment, v4, v3);
  v13 = &v12->HeapLock.cs;
  EnterCriticalSection(&v12->HeapLock.cs);
  v14 = Scaleform::HeapPT::AllocEngine::Realloc(v12->pEngine, v11, v4, v3);
  LeaveCriticalSection(v13);
  return v14;
}

// File Line: 674
// RVA: 0x97DED0
void __fastcall Scaleform::MemoryHeapPT::Free(Scaleform::MemoryHeapPT *this, void *ptr)
{
  void *v2; // rsi
  unsigned __int64 v3; // rcx
  unsigned __int64 v4; // r10
  unsigned __int64 v5; // r9
  __int64 v6; // r8
  __int64 v7; // rdx
  Scaleform::HeapPT::HeapHeader1 *v8; // rcx
  Scaleform::Heap::HeapSegment *v9; // rbp
  Scaleform::MemoryHeapPT *v10; // rdi

  if ( ptr )
  {
    v2 = ptr;
    v3 = (unsigned __int64)ptr >> 52;
    v4 = ((unsigned __int64)ptr >> 40) & 0xFFF;
    v5 = ((unsigned __int64)ptr >> 28) & 0xFFF;
    v6 = (unsigned __int8)((unsigned __int64)ptr >> 20);
    v7 = (unsigned __int8)((unsigned __int64)ptr >> 12);
    v8 = Scaleform::HeapPT::GlobalPageTable->RootTable[v3].pTable[v4].pTable[v5].pTable[v6].pTable;
    v9 = v8[v7].pSegment;
    v10 = v9->pHeap;
    if ( v10->UseLocks )
    {
      EnterCriticalSection(&v10->HeapLock.cs);
      Scaleform::HeapPT::AllocEngine::Free(v10->pEngine, v9, v2);
      LeaveCriticalSection(&v10->HeapLock.cs);
    }
    else
    {
      Scaleform::HeapPT::AllocEngine::Free(v10->pEngine, v8[v7].pSegment, v2);
    }
    if ( v2 == v10->pAutoRelease )
      v10->vfptr->Release((Scaleform::MemoryHeap *)&v10->vfptr);
  }
}

// File Line: 747
// RVA: 0x9578B0
void *__fastcall Scaleform::MemoryHeapPT::AllocAutoHeap(Scaleform::MemoryHeapPT *this, const void *thisPtr, unsigned __int64 size, Scaleform::AllocInfo *info)
{
  unsigned __int64 v4; // rsi
  Scaleform::MemoryHeapPT *v5; // rdi
  _RTL_CRITICAL_SECTION *v6; // rbx
  void *v7; // rdi

  v4 = size;
  v5 = Scaleform::HeapPT::GlobalPageTable->RootTable[(unsigned __int64)thisPtr >> 52].pTable[((unsigned __int64)thisPtr >> 40) & 0xFFF].pTable[((unsigned __int64)thisPtr >> 28) & 0xFFF].pTable[(unsigned __int8)((unsigned __int64)thisPtr >> 20)].pTable[(unsigned __int8)((unsigned __int64)thisPtr >> 12)].pSegment->pHeap;
  if ( !v5->UseLocks )
    return Scaleform::HeapPT::AllocEngine::Alloc(v5->pEngine, size);
  v6 = &v5->HeapLock.cs;
  EnterCriticalSection(&v5->HeapLock.cs);
  v7 = Scaleform::HeapPT::AllocEngine::Alloc(v5->pEngine, v4);
  LeaveCriticalSection(v6);
  return v7;
}

// File Line: 773
// RVA: 0x9577C0
void *__fastcall Scaleform::MemoryHeapPT::AllocAutoHeap(Scaleform::MemoryHeapPT *this, const void *thisPtr, unsigned __int64 size, unsigned __int64 align)
{
  unsigned __int64 v4; // rsi
  unsigned __int64 v5; // rbp
  Scaleform::MemoryHeapPT *v6; // rdi
  _RTL_CRITICAL_SECTION *v7; // rbx
  void *v8; // rdi

  v4 = align;
  v5 = size;
  v6 = Scaleform::HeapPT::GlobalPageTable->RootTable[(unsigned __int64)thisPtr >> 52].pTable[((unsigned __int64)thisPtr >> 40) & 0xFFF].pTable[((unsigned __int64)thisPtr >> 28) & 0xFFF].pTable[(unsigned __int8)((unsigned __int64)thisPtr >> 20)].pTable[(unsigned __int8)((unsigned __int64)thisPtr >> 12)].pSegment->pHeap;
  if ( !v6->UseLocks )
    return Scaleform::HeapPT::AllocEngine::Alloc(v6->pEngine, size, align);
  v7 = &v6->HeapLock.cs;
  EnterCriticalSection(&v6->HeapLock.cs);
  v8 = Scaleform::HeapPT::AllocEngine::Alloc(v6->pEngine, v5, v4);
  LeaveCriticalSection(v7);
  return v8;
}

// File Line: 798
// RVA: 0x97FF00
Scaleform::MemoryHeapPT *__fastcall Scaleform::MemoryHeapPT::GetAllocHeap(Scaleform::MemoryHeapPT *this, const void *thisPtr)
{
  return Scaleform::HeapPT::GlobalPageTable->RootTable[(unsigned __int64)thisPtr >> 52].pTable[((unsigned __int64)thisPtr >> 40) & 0xFFF].pTable[((unsigned __int64)thisPtr >> 28) & 0xFFF].pTable[(unsigned __int8)((unsigned __int64)thisPtr >> 20)].pTable[(unsigned __int8)((unsigned __int64)thisPtr >> 12)].pSegment->pHeap;
}

// File Line: 815
// RVA: 0x98E7D0
unsigned __int64 __fastcall Scaleform::MemoryHeapPT::GetUsableSize(Scaleform::MemoryHeapPT *this, const void *ptr)
{
  const void *v2; // rsi
  Scaleform::Heap::HeapSegment *v3; // rbp
  Scaleform::MemoryHeapPT *v4; // rdi
  _RTL_CRITICAL_SECTION *v5; // rbx
  Scaleform::HeapPT::AllocEngine *v6; // rdi
  unsigned int v7; // eax
  unsigned __int64 v8; // rsi
  unsigned __int64 v9; // rdi
  unsigned __int64 result; // rax
  Scaleform::HeapPT::AllocEngine *v11; // rbx
  unsigned int v12; // eax
  unsigned __int64 v13; // rbx

  v2 = ptr;
  v3 = Scaleform::HeapPT::GlobalPageTable->RootTable[(unsigned __int64)ptr >> 52].pTable[((unsigned __int64)ptr >> 40) & 0xFFF].pTable[((unsigned __int64)ptr >> 28) & 0xFFF].pTable[(unsigned __int8)((unsigned __int64)ptr >> 20)].pTable[(unsigned __int8)((unsigned __int64)ptr >> 12)].pSegment;
  v4 = v3->pHeap;
  if ( v4->UseLocks )
  {
    v5 = &v4->HeapLock.cs;
    EnterCriticalSection(&v4->HeapLock.cs);
    v6 = v4->pEngine;
    v7 = v3->SegType;
    if ( v7 > 7 )
    {
      if ( v7 == 10 )
      {
        v9 = v6->Allocator.MinAlignShift;
        v8 = Scaleform::Heap::BitSet2::GetBlockSize(
               (const unsigned int *)&v3[1],
               (signed __int64)((signed __int64)v2 - (unsigned __int64)v3->pData) >> v9) << v9;
      }
      else
      {
        v8 = v3->DataSize;
      }
    }
    else
    {
      v8 = (unsigned __int64)(v7 + 1) << v6->MinAlignShift;
    }
    LeaveCriticalSection(v5);
    result = v8;
  }
  else
  {
    v11 = v4->pEngine;
    v12 = v3->SegType;
    if ( v12 > 7 )
    {
      if ( v12 == 10 )
      {
        v13 = v11->Allocator.MinAlignShift;
        result = Scaleform::Heap::BitSet2::GetBlockSize(
                   (const unsigned int *)&v3[1],
                   (signed __int64)((signed __int64)ptr - (unsigned __int64)v3->pData) >> v13) << v13;
      }
      else
      {
        result = v3->DataSize;
      }
    }
    else
    {
      result = (unsigned __int64)(v12 + 1) << v11->MinAlignShift;
    }
  }
  return result;
}

// File Line: 839
// RVA: 0x9EFB80
void __fastcall Scaleform::MemoryHeapPT::releaseCachedMem(Scaleform::MemoryHeapPT *this)
{
  Scaleform::MemoryHeapPT *v1; // rbp
  _RTL_CRITICAL_SECTION *v2; // rbx
  Scaleform::MemoryHeap *i; // rdi
  signed __int64 v4; // rax

  v1 = this;
  v2 = &this->HeapLock.cs;
  EnterCriticalSection(&this->HeapLock.cs);
  for ( i = v1->ChildHeaps.Root.pNext; ; i = i->pNext )
  {
    v4 = (signed __int64)(v1 == (Scaleform::MemoryHeapPT *)-136i64 ? 0i64 : &v1->Info.pName);
    if ( i == (Scaleform::MemoryHeap *)v4 )
      break;
    i->vfptr->releaseCachedMem(i);
  }
  Scaleform::HeapPT::AllocEngine::ReleaseCachedMem(v1->pEngine);
  LeaveCriticalSection(v2);
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
  Scaleform::MemoryHeapPT *v2; // rsi
  _RTL_CRITICAL_SECTION *v3; // rbx
  Scaleform::HeapPT::AllocEngine *v4; // rax
  Scaleform::Heap::HeapSegment *v5; // rdx
  signed __int64 i; // rax
  Scaleform::MemoryHeap *v7; // rdi
  signed __int64 v8; // rsi
  signed __int64 v9; // rax

  v2 = this;
  v3 = &this->HeapLock.cs;
  EnterCriticalSection(&this->HeapLock.cs);
  v4 = v2->pEngine;
  v5 = v4->SegmentList.Root.pNext;
  for ( i = (signed __int64)&v4->SegmentList; v5 != (Scaleform::Heap::HeapSegment *)i; v5 = v5->pNext )
    ;
  v7 = v2->ChildHeaps.Root.pNext;
  v8 = (signed __int64)&v2->ChildHeaps;
  while ( 1 )
  {
    v9 = v8 ? v8 - 8 : 0i64;
    if ( v7 == (Scaleform::MemoryHeap *)v9 )
      break;
    if ( !(v7->Info.Desc.Flags & 0x1000) )
      v7->vfptr->GetTotalFootprint(v7);
    v7 = v7->pNext;
  }
  LeaveCriticalSection(v3);
  return 1;
}

// File Line: 940
// RVA: 0x9C1D30
void __fastcall Scaleform::MemoryHeapPT::VisitMem(Scaleform::MemoryHeapPT *this, Scaleform::Heap::MemVisitor *visitor, unsigned int flags)
{
  unsigned int v3; // edi
  Scaleform::Heap::MemVisitor *v4; // rsi
  Scaleform::MemoryHeapPT *v5; // rbp
  _RTL_CRITICAL_SECTION *v6; // rbx

  v3 = flags;
  v4 = visitor;
  v5 = this;
  v6 = &this->HeapLock.cs;
  EnterCriticalSection(&this->HeapLock.cs);
  Scaleform::HeapPT::AllocEngine::VisitMem(v5->pEngine, v4, v3);
  LeaveCriticalSection(v6);
}

// File Line: 950
// RVA: 0x9C1940
void __fastcall Scaleform::MemoryHeapPT::VisitHeapSegments(Scaleform::MemoryHeapPT *this, Scaleform::Heap::SegVisitor *visitor)
{
  Scaleform::Heap::SegVisitor *v2; // rdi
  Scaleform::MemoryHeapPT *v3; // rsi
  _RTL_CRITICAL_SECTION *v4; // rbx

  v2 = visitor;
  v3 = this;
  v4 = &this->HeapLock.cs;
  EnterCriticalSection(&this->HeapLock.cs);
  Scaleform::HeapPT::AllocEngine::VisitSegments(v3->pEngine, v2);
  LeaveCriticalSection(v4);
}

// File Line: 957
// RVA: 0x9C1E50
void __fastcall Scaleform::MemoryHeapPT::VisitRootSegments(Scaleform::MemoryHeapPT *this, Scaleform::Heap::SegVisitor *visitor)
{
  Scaleform::HeapPT::HeapRoot::VisitSegments(Scaleform::HeapPT::GlobalRoot, visitor);
}

// File Line: 963
// RVA: 0x9E79E0
void __fastcall Scaleform::MemoryHeapPT::getUserDebugStats(Scaleform::MemoryHeapPT *this, Scaleform::MemoryHeap::RootStats *stats)
{
  Scaleform::MemoryHeap::RootStats *v2; // rbp
  Scaleform::MemoryHeapPT *v3; // rsi
  _RTL_CRITICAL_SECTION *v4; // rbx
  Scaleform::MemoryHeap *v5; // rdi
  signed __int64 v6; // rsi
  signed __int64 v7; // rax

  v2 = stats;
  v3 = this;
  v4 = &this->HeapLock.cs;
  EnterCriticalSection(&this->HeapLock.cs);
  if ( v3->Info.Desc.Flags & 0x1000 )
  {
    v2->UserDebugFootprint += v3->pEngine->Footprint;
    v2->UserDebugUsedSpace += v3->pEngine->Footprint
                            - (v3->pEngine->Allocator.Bin.FreeBlocks << v3->pEngine->Allocator.MinAlignShift)
                            - v3->pEngine->TinyFreeSpace;
  }
  v5 = v3->ChildHeaps.Root.pNext;
  v6 = (signed __int64)&v3->ChildHeaps;
  while ( 1 )
  {
    v7 = v6 ? v6 - 8 : 0i64;
    if ( v5 == (Scaleform::MemoryHeap *)v7 )
      break;
    v5->vfptr->getUserDebugStats(v5, v2);
    v5 = v5->pNext;
  }
  LeaveCriticalSection(v4);
}

// File Line: 980
// RVA: 0x98B210
void __fastcall Scaleform::MemoryHeapPT::GetRootStats(Scaleform::MemoryHeapPT *this, Scaleform::MemoryHeap::RootStats *stats)
{
  Scaleform::MemoryHeap::RootStats *v2; // rbx

  v2 = stats;
  Scaleform::HeapPT::HeapRoot::GetStats(Scaleform::HeapPT::GlobalRoot, stats);
  v2->UserDebugFootprint = 0i64;
  v2->UserDebugUsedSpace = 0i64;
  Scaleform::Memory::pGlobalHeap->vfptr->getUserDebugStats(Scaleform::Memory::pGlobalHeap, v2);
}

// File Line: 989
// RVA: 0x9D5AB0
void __fastcall Scaleform::MemoryHeapPT::checkIntegrity(Scaleform::MemoryHeapPT *this)
{
  Scaleform::MemoryHeapPT *v1; // rsi
  _RTL_CRITICAL_SECTION *v2; // rbx
  Scaleform::MemoryHeap *v3; // rdi
  signed __int64 v4; // rsi
  signed __int64 v5; // rax

  v1 = this;
  v2 = &this->HeapLock.cs;
  EnterCriticalSection(&this->HeapLock.cs);
  v3 = v1->ChildHeaps.Root.pNext;
  v4 = (signed __int64)&v1->ChildHeaps;
  while ( 1 )
  {
    v5 = v4 ? v4 - 8 : 0i64;
    if ( v3 == (Scaleform::MemoryHeap *)v5 )
      break;
    v3->vfptr->checkIntegrity(v3);
    v3 = v3->pNext;
  }
  LeaveCriticalSection(v2);
}

// File Line: 1019
// RVA: 0x9E8460
bool __fastcall Scaleform::SysAllocPaged::initHeapEngine(Scaleform::SysAllocPaged *this, const void *heapDesc)
{
  Scaleform::MemoryHeap::HeapDesc *v2; // rbx

  v2 = (Scaleform::MemoryHeap::HeapDesc *)heapDesc;
  Scaleform::MemoryHeap::InitPT(this);
  return Scaleform::MemoryHeap::CreateRootHeapPT(v2) != 0i64;
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

