// File Line: 35
// RVA: 0x988B90
void __fastcall Scaleform::HeapMH::GetMagicHeaders(unsigned __int64 pageStart, Scaleform::HeapMH::MagicHeadersInfo *headers)
{
  char *v2; // r8
  char *v3; // r10
  char *v4; // r9
  unsigned __int64 v5; // r11
  Scaleform::HeapMH::MagicHeader *v6; // rax
  unsigned int *v7; // rax

  v2 = (char *)((pageStart + 4095) & 0xFFFFFFFFFFFFF000ui64);
  v3 = (char *)((pageStart + 15) & 0xFFFFFFFFFFFFFFF0ui64);
  v4 = (char *)((pageStart + 4096) & 0xFFFFFFFFFFFFFFF0ui64);
  headers->Header1 = 0i64;
  headers->Header2 = 0i64;
  v5 = v2 - v3;
  if ( v5 > 0x10 )
    headers->Header1 = (Scaleform::HeapMH::MagicHeader *)(v2 - 16);
  v6 = headers->Header2;
  if ( (unsigned __int64)(v4 - v2) > 0x10 )
    v6 = (Scaleform::HeapMH::MagicHeader *)((pageStart + 4095) & 0xFFFFFFFFFFFFF000ui64);
  headers->Header2 = v6;
  v7 = (unsigned int *)(v2 - 80);
  if ( v5 <= v4 - v2 )
    v7 = (unsigned int *)(v2 + 16);
  headers->BitSet = v7;
  headers->AlignedStart = v3;
  headers->AlignedEnd = v4;
  headers->Bound = v2;
  headers->Page = 0i64;
}

// File Line: 71
// RVA: 0x9418A0
void __fastcall Scaleform::HeapMH::RootMH::RootMH(Scaleform::HeapMH::RootMH *this, Scaleform::SysAlloc *sysAlloc)
{
  Scaleform::HeapMH::RootMH *v2; // rbx
  Scaleform::List<Scaleform::HeapMH::PageMH,Scaleform::HeapMH::PageMH> *v3; // rax
  unsigned __int64 *v4; // rax

  v2 = this;
  this->pSysAlloc = sysAlloc;
  Scaleform::Lock::Lock(&this->RootLock.mLock, 0);
  v3 = &v2->FreePages;
  v3->Root.pPrev = (Scaleform::HeapMH::PageMH *)v3;
  v3->Root.pNext = (Scaleform::HeapMH::PageMH *)v3;
  v2->TableCount = 0;
  v2->HeapTree.Root = 0i64;
  Scaleform::HeapMH::GlobalEmptyPageMH.pHeap = 0i64;
  Scaleform::HeapMH::GlobalEmptyPageMH.Start = 0i64;
  v4 = &Scaleform::HeapMH::GlobalPageTableMH.Entries[0].SizeMask;
  do
  {
    *(v4 - 1) = (unsigned __int64)&Scaleform::HeapMH::GlobalEmptyPageMH;
    *v4 = 0i64;
    v4 += 2;
  }
  while ( (signed __int64)v4 < (signed __int64)&Scaleform::HeapPT::GlobalRoot );
  Scaleform::HeapMH::GlobalRootMH = v2;
}

// File Line: 93
// RVA: 0x97E6A0
void __fastcall Scaleform::HeapMH::RootMH::FreeTables(Scaleform::HeapMH::RootMH *this)
{
  Scaleform::HeapMH::RootMH *v1; // rsi
  unsigned __int64 *v2; // rbx
  signed __int64 v3; // rdi
  Scaleform::HeapMH::PageMH *v4; // rdx

  v1 = this;
  v2 = &Scaleform::HeapMH::GlobalPageTableMH.Entries[0].SizeMask;
  v3 = 128i64;
  do
  {
    v4 = (Scaleform::HeapMH::PageMH *)*(v2 - 1);
    if ( v4 != &Scaleform::HeapMH::GlobalEmptyPageMH )
      ((void (__fastcall *)(Scaleform::SysAlloc *, Scaleform::HeapMH::PageMH *, unsigned __int64, signed __int64))v1->pSysAlloc->vfptr[1].initHeapEngine)(
        v1->pSysAlloc,
        v4,
        32 * (*v2 + 1),
        8i64);
    *(v2 - 1) = (unsigned __int64)&Scaleform::HeapMH::GlobalEmptyPageMH;
    *v2 = 0i64;
    v2 += 2;
    --v3;
  }
  while ( v3 );
}

// File Line: 122
// RVA: 0x9CD250
bool __fastcall Scaleform::HeapMH::RootMH::allocPagePool(Scaleform::HeapMH::RootMH *this)
{
  unsigned int v1; // eax
  Scaleform::HeapMH::RootMH *v2; // rdi
  Scaleform::HeapMH::PageMH *v3; // rax
  unsigned int v4; // eax
  __int64 v5; // rbx
  signed __int64 v6; // rdx

  v1 = this->TableCount;
  v2 = this;
  if ( v1 < 0x80 )
  {
    v4 = v1 >> 4;
    v5 = 128 << v4;
    v3 = (Scaleform::HeapMH::PageMH *)((__int64 (__fastcall *)(Scaleform::SysAlloc *, __int64, signed __int64))this->pSysAlloc->vfptr[1].__vecDelDtor)(
                                        this->pSysAlloc,
                                        32 * v5,
                                        8i64);
    if ( v3 )
    {
      Scaleform::HeapMH::GlobalPageTableMH.Entries[v2->TableCount].FirstPage = v3;
      Scaleform::HeapMH::GlobalPageTableMH.Entries[v2->TableCount].SizeMask = v5 - 1;
      if ( v5 )
      {
        v6 = (signed __int64)&v2->FreePages;
        do
        {
          v3->pHeap = 0i64;
          v3->Start = 0i64;
          v3->pPrev = *(Scaleform::HeapMH::PageMH **)v6;
          v3->pNext = (Scaleform::HeapMH::PageMH *)v6;
          *(_QWORD *)(*(_QWORD *)v6 + 8i64) = v3;
          *(_QWORD *)v6 = v3;
          ++v3;
          --v5;
        }
        while ( v5 );
      }
      ++v2->TableCount;
      LOBYTE(v3) = 1;
    }
  }
  else
  {
    LOBYTE(v3) = 0;
    LODWORD(MEMORY[4]) = 0;
  }
  return (char)v3;
}

// File Line: 151
// RVA: 0x957D60
Scaleform::HeapMH::PageMH *__fastcall Scaleform::HeapMH::RootMH::AllocPage(Scaleform::HeapMH::RootMH *this, Scaleform::MemoryHeapMH *heap)
{
  Scaleform::MemoryHeapMH *v2; // rsi
  Scaleform::HeapMH::RootMH *v3; // rdi
  Scaleform::HeapMH::PageMH *result; // rax
  Scaleform::HeapMH::PageMH *v5; // rbx
  _WORD *v6; // rdx
  _WORD *v7; // r8
  char *v8; // rax
  unsigned __int64 v9; // r9

  v2 = heap;
  v3 = this;
  if ( (Scaleform::List<Scaleform::HeapMH::PageMH,Scaleform::HeapMH::PageMH> *)this->FreePages.Root.pNext == &this->FreePages
    && !Scaleform::HeapMH::RootMH::allocPagePool(this) )
  {
    return 0i64;
  }
  v5 = v3->FreePages.Root.pNext;
  result = (Scaleform::HeapMH::PageMH *)((__int64 (__fastcall *)(Scaleform::SysAlloc *, signed __int64, signed __int64))v3->pSysAlloc->vfptr[1].__vecDelDtor)(
                                          v3->pSysAlloc,
                                          4096i64,
                                          8i64);
  v6 = 0i64;
  v5->Start = (char *)result;
  if ( result )
  {
    v7 = 0i64;
    v5->pPrev->pNext = v5->pNext;
    v5->pNext->pPrev = v5->pPrev;
    v8 = v5->Start;
    v5->pHeap = v2;
    v9 = (unsigned __int64)(v8 + 4095) & 0xFFFFFFFFFFFFF000ui64;
    if ( v9 - ((unsigned __int64)(v8 + 15) & 0xFFFFFFFFFFFFFFF0ui64) > 0x10 )
      v6 = (_WORD *)(v9 - 16);
    if ( ((unsigned __int64)(v8 + 4096) & 0xFFFFFFFFFFFFFFF0ui64) - v9 > 0x10 )
      v7 = (_WORD *)((unsigned __int64)(v8 + 4095) & 0xFFFFFFFFFFFFF000ui64);
    if ( v6 )
      *v6 = 24512;
    if ( v7 )
      *v7 = 24512;
    result = v5;
  }
  else
  {
    v5->pHeap = 0i64;
  }
  return result;
}

// File Line: 173
// RVA: 0x97E450
void __fastcall Scaleform::HeapMH::RootMH::FreePage(Scaleform::HeapMH::RootMH *this, Scaleform::HeapMH::PageMH *page)
{
  char *v2; // rax
  Scaleform::HeapMH::PageMH *v3; // rbx
  Scaleform::HeapMH::RootMH *v4; // rdi
  unsigned __int64 v5; // rdx
  unsigned __int64 v6; // r10
  _QWORD *v7; // r9
  _QWORD *v8; // rax
  char *v9; // rdx

  v2 = page->Start;
  v3 = page;
  v4 = this;
  v5 = (unsigned __int64)(v2 + 4095) & 0xFFFFFFFFFFFFF000ui64;
  v6 = (unsigned __int64)(v2 + 4096) & 0xFFFFFFFFFFFFFFF0ui64;
  v7 = 0i64;
  if ( v5 - ((unsigned __int64)(v2 + 15) & 0xFFFFFFFFFFFFFFF0ui64) > 0x10 )
    v7 = (_QWORD *)(v5 - 16);
  v8 = 0i64;
  if ( v6 - v5 > 0x10 )
    v8 = (_QWORD *)v5;
  if ( v7 )
  {
    *v7 = 0i64;
    v7[1] = 0i64;
  }
  if ( v8 )
  {
    *v8 = 0i64;
    v8[1] = 0i64;
  }
  v9 = v3->Start;
  v3->pHeap = 0i64;
  v3->Start = 0i64;
  ((void (__fastcall *)(Scaleform::SysAlloc *, char *, signed __int64, signed __int64))this->pSysAlloc->vfptr[1].initHeapEngine)(
    this->pSysAlloc,
    v9,
    4096i64,
    8i64);
  v3->pPrev = v4->FreePages.Root.pPrev;
  v3->pNext = (Scaleform::HeapMH::PageMH *)&v4->FreePages;
  v4->FreePages.Root.pPrev->pNext = v3;
  v4->FreePages.Root.pPrev = v3;
}

// File Line: 230
// RVA: 0x9AD530
Scaleform::HeapMH::PageMH *__fastcall Scaleform::HeapMH::RootMH::ResolveAddress(Scaleform::HeapMH::RootMH *this, unsigned __int64 addr)
{
  Scaleform::HeapMH::PageMH *result; // rax

  if ( *(_WORD *)(addr & 0xFFFFFFFFFFFFF000ui64) != 24512
    || (result = &Scaleform::HeapMH::GlobalPageTableMH.Entries[*(_DWORD *)((addr & 0xFFFFFFFFFFFFF000ui64) + 4) & 0x7F].FirstPage[Scaleform::HeapMH::GlobalPageTableMH.Entries[*(_DWORD *)((addr & 0xFFFFFFFFFFFFF000ui64) + 4) & 0x7F].SizeMask & ((unsigned __int64)*(unsigned int *)((addr & 0xFFFFFFFFFFFFF000ui64) + 4) >> 7)],
        addr - (unsigned __int64)result->Start >= 0x1000) )
  {
    if ( *(_WORD *)((addr & 0xFFFFFFFFFFFFF000ui64) + 0xFF0) != 24512
      || (result = &Scaleform::HeapMH::GlobalPageTableMH.Entries[*(_DWORD *)((addr & 0xFFFFFFFFFFFFF000ui64) + 0xFF4) & 0x7F].FirstPage[Scaleform::HeapMH::GlobalPageTableMH.Entries[*(_DWORD *)((addr & 0xFFFFFFFFFFFFF000ui64) + 0xFF4) & 0x7F].SizeMask & ((unsigned __int64)*(unsigned int *)((addr & 0xFFFFFFFFFFFFF000ui64) + 0xFF4) >> 7)],
          addr - (unsigned __int64)result->Start >= 0x1000) )
    {
      result = 0i64;
    }
  }
  return result;
}

// File Line: 263
// RVA: 0x9675C0
Scaleform::MemoryHeapMH *__fastcall Scaleform::HeapMH::RootMH::CreateHeap(Scaleform::HeapMH::RootMH *this, const char *name, Scaleform::MemoryHeapMH *parent, Scaleform::MemoryHeap::HeapDesc *desc)
{
  Scaleform::MemoryHeap::HeapDesc *v4; // r12
  const char *v5; // rbp
  Scaleform::HeapMH::RootMH *v6; // r13
  signed __int64 v7; // rbx
  signed __int64 v8; // rsi
  unsigned __int64 v9; // rsi
  Scaleform::MemoryHeapMH *result; // rax
  Scaleform::MemoryHeapMH *v11; // r14
  Scaleform::HeapMH::AllocEngineMH *v12; // r15
  Scaleform::MemoryHeap *v13; // rdi
  unsigned __int64 v14; // rcx
  unsigned __int64 *v15; // rax
  Scaleform::MemoryHeapMH *v16; // [rsp+80h] [rbp+18h]

  v16 = parent;
  v4 = desc;
  v5 = name;
  v6 = this;
  v7 = -1i64;
  v8 = -1i64;
  do
    ++v8;
  while ( name[v8] );
  v9 = (v8 + 832) & 0xFFFFFFFFFFFFFFF0ui64;
  result = (Scaleform::MemoryHeapMH *)((__int64 (__fastcall *)(Scaleform::SysAlloc *, unsigned __int64, signed __int64))this->pSysAlloc->vfptr[1].__vecDelDtor)(
                                        this->pSysAlloc,
                                        v9,
                                        8i64);
  v11 = result;
  if ( result )
  {
    Scaleform::MemoryHeap::MemoryHeap((Scaleform::MemoryHeap *)&result->vfptr);
    v11->vfptr = (Scaleform::MemoryHeapVtbl *)&Scaleform::MemoryHeapMH::`vftable;
    v11->pEngine = 0i64;
    v11->pDebugStorage = 0i64;
    v12 = (Scaleform::HeapMH::AllocEngineMH *)&v11[1];
    if ( v11 == (Scaleform::MemoryHeapMH *)-216i64 )
    {
      v12 = 0i64;
    }
    else
    {
      v13 = (Scaleform::MemoryHeap *)v4->Limit;
      v14 = v4->MinAlign;
      v12->pSysAlloc = v6->pSysAlloc;
      v11[1].pPrev = (Scaleform::MemoryHeap *)&v11->vfptr;
      if ( v14 < 8 )
        v14 = 8i64;
      v11[1].pNext = (Scaleform::MemoryHeap *)v14;
      v11[1].SelfSize = 0i64;
      memset((void *)&v11[1].RefCount, 0, 0x200ui64);
      v15 = &v11[3].Info.Desc.Arena;
      *v15 = (unsigned __int64)v15;
      v15[1] = (unsigned __int64)v15;
      v11[3].Info.pName = 0i64;
      v11[3].ChildHeaps.Root.pPrev = 0i64;
      v11[3].ChildHeaps.Root.pNext = v13;
      v11[3].HeapLock.cs.DebugInfo = 0i64;
      *(_QWORD *)&v11[3].HeapLock.cs.LockCount = 0i64;
    }
    v11->SelfSize = v9;
    v11->RefCount = 1;
    v11->pAutoRelease = 0i64;
    *(_QWORD *)&v11->Info.Desc.Flags = *(_QWORD *)&v4->Flags;
    v11->Info.Desc.MinAlign = v4->MinAlign;
    v11->Info.Desc.Granularity = v4->Granularity;
    v11->Info.Desc.Reserve = v4->Reserve;
    v11->Info.Desc.Threshold = v4->Threshold;
    v11->Info.Desc.Limit = v4->Limit;
    v11->Info.Desc.HeapId = v4->HeapId;
    v11->Info.Desc.Arena = v4->Arena;
    v11->Info.pParent = (Scaleform::MemoryHeap *)&v16->vfptr;
    v11->Info.pName = (char *)&v11[3].HeapLock.cs.OwningThread;
    v11->UseLocks = ~LOBYTE(v4->Flags) & 1;
    v11->TrackDebugInfo = ~(unsigned __int8)(v4->Flags >> 4) & 1;
    v11->pEngine = v12;
    do
      ++v7;
    while ( v5[v7] );
    memmove(&v11[3].HeapLock.cs.OwningThread, v5, v7 + 1);
    result = v11;
  }
  return result;
}

