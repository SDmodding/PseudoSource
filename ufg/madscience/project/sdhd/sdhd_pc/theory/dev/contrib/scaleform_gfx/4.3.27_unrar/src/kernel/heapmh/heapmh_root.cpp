// File Line: 35
// RVA: 0x988B90
void __fastcall Scaleform::HeapMH::GetMagicHeaders(
        unsigned __int64 pageStart,
        Scaleform::HeapMH::MagicHeadersInfo *headers)
{
  char *v2; // r8
  char *v3; // r10
  char *v4; // r9
  Scaleform::HeapMH::MagicHeader *Header2; // rax
  unsigned int *v6; // rax

  v2 = (char *)((pageStart + 4095) & 0xFFFFFFFFFFFFF000ui64);
  v3 = (char *)((pageStart + 15) & 0xFFFFFFFFFFFFFFF0ui64);
  v4 = (char *)((pageStart + 4096) & 0xFFFFFFFFFFFFFFF0ui64);
  headers->Header1 = 0i64;
  headers->Header2 = 0i64;
  if ( (unsigned __int64)(v2 - v3) > 0x10 )
    headers->Header1 = (Scaleform::HeapMH::MagicHeader *)(v2 - 16);
  Header2 = headers->Header2;
  if ( (unsigned __int64)(v4 - v2) > 0x10 )
    Header2 = (Scaleform::HeapMH::MagicHeader *)((pageStart + 4095) & 0xFFFFFFFFFFFFF000ui64);
  headers->Header2 = Header2;
  v6 = (unsigned int *)(v2 - 80);
  if ( v2 - v3 <= (unsigned __int64)(v4 - v2) )
    v6 = (unsigned int *)(v2 + 16);
  headers->BitSet = v6;
  headers->AlignedStart = v3;
  headers->AlignedEnd = v4;
  headers->Bound = v2;
  headers->Page = 0i64;
}

// File Line: 71
// RVA: 0x9418A0
void __fastcall Scaleform::HeapMH::RootMH::RootMH(Scaleform::HeapMH::RootMH *this, Scaleform::SysAlloc *sysAlloc)
{
  unsigned __int64 *p_SizeMask; // rax

  this->pSysAlloc = sysAlloc;
  Scaleform::Lock::Lock(&this->RootLock.mLock, 0);
  this->FreePages.Root.pPrev = (Scaleform::HeapMH::PageMH *)&this->FreePages;
  this->FreePages.Root.pNext = (Scaleform::HeapMH::PageMH *)&this->FreePages;
  this->TableCount = 0;
  this->HeapTree.Root = 0i64;
  Scaleform::HeapMH::GlobalEmptyPageMH.pHeap = 0i64;
  Scaleform::HeapMH::GlobalEmptyPageMH.Start = 0i64;
  p_SizeMask = &Scaleform::HeapMH::GlobalPageTableMH.Entries[0].SizeMask;
  do
  {
    *(p_SizeMask - 1) = (unsigned __int64)&Scaleform::HeapMH::GlobalEmptyPageMH;
    *p_SizeMask = 0i64;
    p_SizeMask += 2;
  }
  while ( (__int64)p_SizeMask < (__int64)&Scaleform::HeapPT::GlobalRoot );
  Scaleform::HeapMH::GlobalRootMH = this;
}

// File Line: 93
// RVA: 0x97E6A0
void __fastcall Scaleform::HeapMH::RootMH::FreeTables(Scaleform::HeapMH::RootMH *this)
{
  unsigned __int64 *p_SizeMask; // rbx
  __int64 v3; // rdi
  Scaleform::HeapMH::PageMH *v4; // rdx

  p_SizeMask = &Scaleform::HeapMH::GlobalPageTableMH.Entries[0].SizeMask;
  v3 = 128i64;
  do
  {
    v4 = (Scaleform::HeapMH::PageMH *)*(p_SizeMask - 1);
    if ( v4 != &Scaleform::HeapMH::GlobalEmptyPageMH )
      ((void (__fastcall *)(Scaleform::SysAlloc *, Scaleform::HeapMH::PageMH *, unsigned __int64, __int64))this->pSysAlloc->vfptr[1].initHeapEngine)(
        this->pSysAlloc,
        v4,
        32 * (*p_SizeMask + 1),
        8i64);
    *(p_SizeMask - 1) = (unsigned __int64)&Scaleform::HeapMH::GlobalEmptyPageMH;
    *p_SizeMask = 0i64;
    p_SizeMask += 2;
    --v3;
  }
  while ( v3 );
}

// File Line: 122
// RVA: 0x9CD250
bool __fastcall Scaleform::HeapMH::RootMH::allocPagePool(Scaleform::HeapMH::RootMH *this)
{
  unsigned int TableCount; // eax
  Scaleform::HeapMH::PageMH *v3; // rax
  __int64 v4; // rbx
  Scaleform::List<Scaleform::HeapMH::PageMH,Scaleform::HeapMH::PageMH> *p_FreePages; // rdx

  TableCount = this->TableCount;
  if ( TableCount < 0x80 )
  {
    v4 = 128 << (TableCount >> 4);
    v3 = (Scaleform::HeapMH::PageMH *)((__int64 (__fastcall *)(Scaleform::SysAlloc *, __int64, __int64))this->pSysAlloc->vfptr[1].__vecDelDtor)(
                                        this->pSysAlloc,
                                        32 * v4,
                                        8i64);
    if ( v3 )
    {
      Scaleform::HeapMH::GlobalPageTableMH.Entries[this->TableCount].FirstPage = v3;
      Scaleform::HeapMH::GlobalPageTableMH.Entries[this->TableCount].SizeMask = v4 - 1;
      if ( v4 )
      {
        p_FreePages = &this->FreePages;
        do
        {
          v3->pHeap = 0i64;
          v3->Start = 0i64;
          v3->pPrev = p_FreePages->Root.pPrev;
          v3->pNext = (Scaleform::HeapMH::PageMH *)p_FreePages;
          p_FreePages->Root.pPrev->pNext = v3;
          p_FreePages->Root.pPrev = v3++;
          --v4;
        }
        while ( v4 );
      }
      ++this->TableCount;
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
Scaleform::HeapMH::PageMH *__fastcall Scaleform::HeapMH::RootMH::AllocPage(
        Scaleform::HeapMH::RootMH *this,
        Scaleform::MemoryHeapMH *heap)
{
  Scaleform::HeapMH::PageMH *result; // rax
  Scaleform::HeapMH::PageMH *pNext; // rbx
  _WORD *v6; // rdx
  _WORD *v7; // r8
  char *Start; // rax
  unsigned __int64 v9; // r9

  if ( (Scaleform::List<Scaleform::HeapMH::PageMH,Scaleform::HeapMH::PageMH> *)this->FreePages.Root.pNext == &this->FreePages
    && !Scaleform::HeapMH::RootMH::allocPagePool(this) )
  {
    return 0i64;
  }
  pNext = this->FreePages.Root.pNext;
  result = (Scaleform::HeapMH::PageMH *)((__int64 (__fastcall *)(Scaleform::SysAlloc *, __int64, __int64))this->pSysAlloc->vfptr[1].__vecDelDtor)(
                                          this->pSysAlloc,
                                          4096i64,
                                          8i64);
  v6 = 0i64;
  pNext->Start = (char *)result;
  if ( result )
  {
    v7 = 0i64;
    pNext->pPrev->pNext = pNext->pNext;
    pNext->pNext->Scaleform::ListNode<Scaleform::HeapMH::PageMH>::$C06980F5032C4827498798FB8F6B6AFF::pPrev = pNext->pPrev;
    Start = pNext->Start;
    pNext->pHeap = heap;
    v9 = (unsigned __int64)(Start + 4095) & 0xFFFFFFFFFFFFF000ui64;
    if ( v9 - ((unsigned __int64)(Start + 15) & 0xFFFFFFFFFFFFFFF0ui64) > 0x10 )
      v6 = (_WORD *)(v9 - 16);
    if ( ((unsigned __int64)(Start + 4096) & 0xFFFFFFFFFFFFFFF0ui64) - v9 > 0x10 )
      v7 = (_WORD *)((unsigned __int64)(Start + 4095) & 0xFFFFFFFFFFFFF000ui64);
    if ( v6 )
      *v6 = 24512;
    if ( v7 )
      *v7 = 24512;
    return pNext;
  }
  else
  {
    pNext->pHeap = 0i64;
  }
  return result;
}

// File Line: 173
// RVA: 0x97E450
void __fastcall Scaleform::HeapMH::RootMH::FreePage(Scaleform::HeapMH::RootMH *this, Scaleform::HeapMH::PageMH *page)
{
  char *Start; // rax
  unsigned __int64 v5; // rdx
  unsigned __int64 v6; // r10
  _QWORD *v7; // r9
  _QWORD *v8; // rax
  char *v9; // rdx

  Start = page->Start;
  v5 = (unsigned __int64)(Start + 4095) & 0xFFFFFFFFFFFFF000ui64;
  v6 = (unsigned __int64)(Start + 4096) & 0xFFFFFFFFFFFFFFF0ui64;
  v7 = 0i64;
  if ( v5 - ((unsigned __int64)(Start + 15) & 0xFFFFFFFFFFFFFFF0ui64) > 0x10 )
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
  v9 = page->Start;
  page->pHeap = 0i64;
  page->Start = 0i64;
  ((void (__fastcall *)(Scaleform::SysAlloc *, char *, __int64, __int64))this->pSysAlloc->vfptr[1].initHeapEngine)(
    this->pSysAlloc,
    v9,
    4096i64,
    8i64);
  page->pPrev = this->FreePages.Root.pPrev;
  page->pNext = (Scaleform::HeapMH::PageMH *)&this->FreePages;
  this->FreePages.Root.pPrev->pNext = page;
  this->FreePages.Root.pPrev = page;
}

// File Line: 230
// RVA: 0x9AD530
Scaleform::HeapMH::PageMH *__fastcall Scaleform::HeapMH::RootMH::ResolveAddress(
        Scaleform::HeapMH::RootMH *this,
        unsigned __int64 addr)
{
  Scaleform::HeapMH::PageMH *result; // rax

  if ( *(_WORD *)(addr & 0xFFFFFFFFFFFFF000ui64) != 24512
    || (result = &Scaleform::HeapMH::GlobalPageTableMH.Entries[*(_DWORD *)((addr & 0xFFFFFFFFFFFFF000ui64) + 4) & 0x7F].FirstPage[Scaleform::HeapMH::GlobalPageTableMH.Entries[*(_DWORD *)((addr & 0xFFFFFFFFFFFFF000ui64) + 4) & 0x7F].SizeMask & ((unsigned __int64)*(unsigned int *)((addr & 0xFFFFFFFFFFFFF000ui64) + 4) >> 7)],
        addr - (unsigned __int64)result->Start >= 0x1000) )
  {
    if ( *(_WORD *)((addr & 0xFFFFFFFFFFFFF000ui64) + 0xFF0) != 24512 )
      return 0i64;
    result = &Scaleform::HeapMH::GlobalPageTableMH.Entries[*(_DWORD *)((addr & 0xFFFFFFFFFFFFF000ui64) + 0xFF4) & 0x7F].FirstPage[Scaleform::HeapMH::GlobalPageTableMH.Entries[*(_DWORD *)((addr & 0xFFFFFFFFFFFFF000ui64) + 0xFF4) & 0x7F].SizeMask & ((unsigned __int64)*(unsigned int *)((addr & 0xFFFFFFFFFFFFF000ui64) + 0xFF4) >> 7)];
    if ( addr - (unsigned __int64)result->Start >= 0x1000 )
      return 0i64;
  }
  return result;
}

// File Line: 263
// RVA: 0x9675C0
Scaleform::MemoryHeapMH *__fastcall Scaleform::HeapMH::RootMH::CreateHeap(
        Scaleform::HeapMH::RootMH *this,
        const char *name,
        Scaleform::MemoryHeapMH *parent,
        Scaleform::MemoryHeap::HeapDesc *desc)
{
  __int64 v7; // rbx
  __int64 v8; // rsi
  unsigned __int64 v9; // rsi
  Scaleform::MemoryHeapMH *result; // rax
  Scaleform::MemoryHeapMH *v11; // r14
  Scaleform::HeapMH::AllocEngineMH *v12; // r15
  unsigned __int64 Limit; // rdi
  unsigned __int64 MinAlign; // rcx

  v7 = -1i64;
  v8 = -1i64;
  do
    ++v8;
  while ( name[v8] );
  v9 = (v8 + 832) & 0xFFFFFFFFFFFFFFF0ui64;
  result = (Scaleform::MemoryHeapMH *)((__int64 (__fastcall *)(Scaleform::SysAlloc *, unsigned __int64, __int64))this->pSysAlloc->vfptr[1].__vecDelDtor)(
                                        this->pSysAlloc,
                                        v9,
                                        8i64);
  v11 = result;
  if ( result )
  {
    Scaleform::MemoryHeap::MemoryHeap(result);
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
      Limit = desc->Limit;
      MinAlign = desc->MinAlign;
      v12->pSysAlloc = this->pSysAlloc;
      v11[1].pPrev = v11;
      if ( MinAlign < 8 )
        MinAlign = 8i64;
      v11[1].pNext = (Scaleform::MemoryHeap *)MinAlign;
      v11[1].SelfSize = 0i64;
      memset((void *)&v11[1].RefCount, 0, 0x200ui64);
      v11[3].Info.Desc.Arena = (unsigned __int64)&v11[3].Info.Desc.Arena;
      v11[3].Info.pParent = (Scaleform::MemoryHeapMH *)((char *)v11 + 760);
      v11[3].Info.pName = 0i64;
      v11[3].ChildHeaps.Root.Scaleform::MemoryHeap::pPrev = 0i64;
      v11[3].ChildHeaps.Root.pNext = (Scaleform::MemoryHeap *)Limit;
      v11[3].HeapLock.cs.DebugInfo = 0i64;
      *(_QWORD *)&v11[3].HeapLock.cs.LockCount = 0i64;
    }
    v11->SelfSize = v9;
    v11->RefCount = 1;
    v11->pAutoRelease = 0i64;
    *(_QWORD *)&v11->Info.Desc.Flags = *(_QWORD *)&desc->Flags;
    v11->Info.Desc.MinAlign = desc->MinAlign;
    v11->Info.Desc.Granularity = desc->Granularity;
    v11->Info.Desc.Reserve = desc->Reserve;
    v11->Info.Desc.Threshold = desc->Threshold;
    v11->Info.Desc.Limit = desc->Limit;
    v11->Info.Desc.HeapId = desc->HeapId;
    v11->Info.Desc.Arena = desc->Arena;
    v11->Info.pParent = parent;
    v11->Info.pName = (char *)&v11[3].HeapLock.cs.OwningThread;
    v11->UseLocks = (desc->Flags & 1) == 0;
    v11->TrackDebugInfo = (desc->Flags & 0x10) == 0;
    v11->pEngine = v12;
    do
      ++v7;
    while ( name[v7] );
    memmove(&v11[3].HeapLock.cs.OwningThread, name, v7 + 1);
    return v11;
  }
  return result;
}

