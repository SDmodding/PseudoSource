// File Line: 53
// RVA: 0x9CD320
Scaleform::HeapMH::PageMH *__fastcall Scaleform::HeapMH::AllocEngineMH::allocPageUnlocked(
        Scaleform::HeapMH::AllocEngineMH *this,
        bool *limHandlerOK)
{
  unsigned __int64 Limit; // rcx
  _DWORD *pLimHandler; // rax
  Scaleform::LockSafe *p_RootLock; // rsi
  Scaleform::HeapMH::PageMH *v7; // rbx
  int v8; // edx
  unsigned int TableCount; // r8d
  unsigned __int64 v10; // rax
  int v11; // eax

  Limit = this->Limit;
  if ( Limit )
  {
    if ( this->Footprint + 4096 > Limit )
    {
      pLimHandler = this->pLimHandler;
      if ( pLimHandler )
      {
        ++pLimHandler[2];
        *limHandlerOK = (*(__int64 (__fastcall **)(void *, Scaleform::MemoryHeapMH *, unsigned __int64))(*(_QWORD *)this->pLimHandler + 8i64))(
                          this->pLimHandler,
                          this->pHeap,
                          this->Footprint - this->Limit + 4096);
        --*((_DWORD *)this->pLimHandler + 2);
      }
    }
  }
  *limHandlerOK = 0;
  p_RootLock = &Scaleform::HeapMH::GlobalRootMH->RootLock;
  EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
  v7 = Scaleform::HeapMH::RootMH::AllocPage(Scaleform::HeapMH::GlobalRootMH, this->pHeap);
  if ( v7 )
  {
    v8 = 0;
    TableCount = Scaleform::HeapMH::GlobalRootMH->TableCount;
    if ( TableCount )
    {
      while ( 1 )
      {
        v10 = v7 - Scaleform::HeapMH::GlobalPageTableMH.Entries[v8].FirstPage;
        if ( v10 <= Scaleform::HeapMH::GlobalPageTableMH.Entries[v8].SizeMask )
          break;
        if ( ++v8 >= TableCount )
          goto LABEL_11;
      }
      v11 = v8 | ((_DWORD)v10 << 7);
    }
    else
    {
LABEL_11:
      v11 = -1;
    }
    Scaleform::HeapMH::AllocBitSet2MH::InitPage(&this->Allocator, v7, v11);
    this->Footprint += 4096i64;
    v7->pNext = this->Pages.Root.pNext;
    v7->pPrev = (Scaleform::HeapMH::PageMH *)&this->Pages;
    this->Pages.Root.pNext->pPrev = v7;
    this->Pages.Root.pNext = v7;
    *limHandlerOK = 1;
  }
  LeaveCriticalSection(&p_RootLock->mLock.cs);
  return v7;
}

// File Line: 81
// RVA: 0x9CD0F0
Scaleform::HeapMH::PageMH *__fastcall Scaleform::HeapMH::AllocEngineMH::allocPageLocked(
        Scaleform::HeapMH::AllocEngineMH *this,
        bool *limHandlerOK)
{
  unsigned __int64 Limit; // rcx
  Scaleform::LockSafe *p_RootLock; // rbx
  Scaleform::HeapMH::PageMH *result; // rax
  Scaleform::HeapMH::PageMH *v7; // rbx
  int v8; // edx
  unsigned int TableCount; // r8d
  unsigned __int64 v10; // rax
  int v11; // eax

  Limit = this->Limit;
  if ( Limit && this->Footprint + 4096 > Limit )
  {
    if ( this->pLimHandler )
    {
      p_RootLock = &Scaleform::HeapMH::GlobalRootMH->RootLock;
      LeaveCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
      ++*((_DWORD *)this->pLimHandler + 2);
      *limHandlerOK = (*(__int64 (__fastcall **)(void *, Scaleform::MemoryHeapMH *, unsigned __int64))(*(_QWORD *)this->pLimHandler + 8i64))(
                        this->pLimHandler,
                        this->pHeap,
                        this->Footprint - this->Limit + 4096);
      --*((_DWORD *)this->pLimHandler + 2);
      EnterCriticalSection(&p_RootLock->mLock.cs);
    }
  }
  *limHandlerOK = 0;
  result = Scaleform::HeapMH::RootMH::AllocPage(Scaleform::HeapMH::GlobalRootMH, this->pHeap);
  v7 = result;
  if ( result )
  {
    v8 = 0;
    TableCount = Scaleform::HeapMH::GlobalRootMH->TableCount;
    if ( TableCount )
    {
      while ( 1 )
      {
        v10 = v7 - Scaleform::HeapMH::GlobalPageTableMH.Entries[v8].FirstPage;
        if ( v10 <= Scaleform::HeapMH::GlobalPageTableMH.Entries[v8].SizeMask )
          break;
        if ( ++v8 >= TableCount )
          goto LABEL_11;
      }
      v11 = v8 | ((_DWORD)v10 << 7);
    }
    else
    {
LABEL_11:
      v11 = -1;
    }
    Scaleform::HeapMH::AllocBitSet2MH::InitPage(&this->Allocator, v7, v11);
    this->Footprint += 4096i64;
    v7->pNext = this->Pages.Root.pNext;
    v7->pPrev = (Scaleform::HeapMH::PageMH *)&this->Pages;
    this->Pages.Root.pNext->pPrev = v7;
    this->Pages.Root.pNext = v7;
    *limHandlerOK = 1;
    return v7;
  }
  return result;
}

// File Line: 108
// RVA: 0x9E36A0
void __fastcall Scaleform::HeapMH::AllocEngineMH::freePage(
        Scaleform::HeapMH::AllocEngineMH *this,
        Scaleform::HeapMH::PageMH *page,
        bool globalLocked)
{
  Scaleform::LockSafe *p_RootLock; // rbx

  if ( globalLocked )
  {
    Scaleform::HeapMH::AllocBitSet2MH::ReleasePage(&this->Allocator, page->Start);
    page->pPrev->pNext = page->pNext;
    page->pNext->Scaleform::ListNode<Scaleform::HeapMH::PageMH>::$C06980F5032C4827498798FB8F6B6AFF::pPrev = page->pPrev;
    Scaleform::HeapMH::RootMH::FreePage(Scaleform::HeapMH::GlobalRootMH, page);
  }
  else
  {
    p_RootLock = &Scaleform::HeapMH::GlobalRootMH->RootLock;
    EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
    Scaleform::HeapMH::AllocBitSet2MH::ReleasePage(&this->Allocator, page->Start);
    page->pPrev->pNext = page->pNext;
    page->pNext->Scaleform::ListNode<Scaleform::HeapMH::PageMH>::$C06980F5032C4827498798FB8F6B6AFF::pPrev = page->pPrev;
    Scaleform::HeapMH::RootMH::FreePage(Scaleform::HeapMH::GlobalRootMH, page);
    LeaveCriticalSection(&p_RootLock->mLock.cs);
  }
  this->Footprint -= 4096i64;
}

// File Line: 127
// RVA: 0x9CBD40
Scaleform::HeapMH::BinNodeMH *__fastcall Scaleform::HeapMH::AllocEngineMH::allocFromPage(
        Scaleform::HeapMH::AllocEngineMH *this,
        unsigned __int64 size,
        Scaleform::HeapMH::PageInfoMH *info,
        bool globalLocked)
{
  Scaleform::HeapMH::BinNodeMH *v8; // rcx
  Scaleform::HeapMH::PageMH *Page; // rax
  Scaleform::HeapMH::MagicHeadersInfo headers; // [rsp+20h] [rbp-58h] BYREF
  bool limHandlerOK; // [rsp+80h] [rbp+8h] BYREF

  limHandlerOK = 0;
  while ( 1 )
  {
    v8 = Scaleform::HeapMH::AllocBitSet2MH::Alloc(&this->Allocator, size, &headers);
    if ( v8 )
      break;
    if ( globalLocked )
      Scaleform::HeapMH::AllocEngineMH::allocPageLocked(this, &limHandlerOK);
    else
      Scaleform::HeapMH::AllocEngineMH::allocPageUnlocked(this, &limHandlerOK);
    if ( !limHandlerOK )
      return 0i64;
  }
  if ( headers.Header1 )
    ++headers.Header1->UseCount;
  if ( headers.Header2 )
    ++headers.Header2->UseCount;
  Page = headers.Page;
  info->UsableSize = size;
  info->Node = 0i64;
  info->Page = Page;
  ++this->UseCount;
  this->UsedSpace += size;
  return v8;
}

// File Line: 169
// RVA: 0x9CBC60
Scaleform::HeapMH::BinNodeMH *__fastcall Scaleform::HeapMH::AllocEngineMH::allocFromPage(
        Scaleform::HeapMH::AllocEngineMH *this,
        unsigned __int64 size,
        unsigned __int64 alignSize,
        Scaleform::HeapMH::PageInfoMH *info,
        bool globalLocked)
{
  bool v5; // di
  Scaleform::HeapMH::BinNodeMH *v10; // rcx
  Scaleform::HeapMH::PageMH *Page; // rax
  Scaleform::HeapMH::MagicHeadersInfo headers; // [rsp+20h] [rbp-58h] BYREF
  bool limHandlerOK; // [rsp+80h] [rbp+8h] BYREF

  v5 = globalLocked;
  limHandlerOK = 0;
  while ( 1 )
  {
    v10 = Scaleform::HeapMH::AllocBitSet2MH::Alloc(&this->Allocator, size, alignSize, &headers);
    if ( v10 )
      break;
    if ( v5 )
      Scaleform::HeapMH::AllocEngineMH::allocPageLocked(this, &limHandlerOK);
    else
      Scaleform::HeapMH::AllocEngineMH::allocPageUnlocked(this, &limHandlerOK);
    if ( !limHandlerOK )
      return 0i64;
  }
  if ( headers.Header1 )
    ++headers.Header1->UseCount;
  if ( headers.Header2 )
    ++headers.Header2->UseCount;
  Page = headers.Page;
  info->UsableSize = size;
  info->Node = 0i64;
  info->Page = Page;
  ++this->UseCount;
  this->UsedSpace += size;
  return v10;
}

// File Line: 211
// RVA: 0x97DA20
void __fastcall Scaleform::HeapMH::AllocEngineMH::Free(
        Scaleform::HeapMH::AllocEngineMH *this,
        Scaleform::HeapMH::PageMH *page,
        unsigned __int64 ptr,
        bool globalLocked)
{
  Scaleform::HeapMH::MagicHeader *Header1; // rax
  int UseCount; // ecx
  Scaleform::HeapMH::MagicHeader *Header2; // rax
  Scaleform::HeapMH::MagicHeadersInfo v10; // [rsp+30h] [rbp-48h] BYREF
  unsigned __int64 v11; // [rsp+80h] [rbp+8h] BYREF

  Scaleform::HeapMH::AllocBitSet2MH::Free(&this->Allocator, page, ptr, &v10, &v11);
  this->UsedSpace -= v11;
  Header1 = v10.Header1;
  UseCount = 0;
  if ( v10.Header1 )
  {
    --v10.Header1->UseCount;
    UseCount = Header1->UseCount;
  }
  Header2 = v10.Header2;
  if ( v10.Header2 )
  {
    --v10.Header2->UseCount;
    UseCount = Header2->UseCount;
  }
  if ( !UseCount )
    Scaleform::HeapMH::AllocEngineMH::freePage(this, page, globalLocked);
  --this->UseCount;
}

// File Line: 230
// RVA: 0x97D980
void __fastcall Scaleform::HeapMH::AllocEngineMH::Free(
        Scaleform::HeapMH::AllocEngineMH *this,
        Scaleform::HeapPT::TreeSeg *node,
        void *ptr,
        bool __formal)
{
  unsigned __int64 v7; // rax
  unsigned __int64 Buffer; // r9
  __int64 v9; // rax
  Scaleform::SysAlloc *pSysAlloc; // rcx
  char *v11; // r8

  Scaleform::RadixTree<Scaleform::HeapMH::NodeMH,Scaleform::HeapMH::TreeNodeAccessor>::Remove(
    (Scaleform::RadixTree<Scaleform::HeapPT::TreeSeg,Scaleform::HeapPT::Granulator::SegTreeAccessor> *)&Scaleform::HeapMH::GlobalRootMH->HeapTree,
    node);
  v7 = (__int64)node->Headers & 3;
  if ( v7 == 3 )
    Buffer = (unsigned __int64)node->Buffer;
  else
    Buffer = 1i64 << ((unsigned __int8)v7 + 2);
  v9 = 40i64;
  if ( Buffer <= 0x10 )
    v9 = 32i64;
  pSysAlloc = this->pSysAlloc;
  --this->UseCount;
  v11 = (char *)node + (unsigned int)v9 - (_QWORD)ptr;
  this->Footprint -= (unsigned __int64)v11;
  this->UsedSpace += v9 - (_QWORD)v11;
  pSysAlloc->vfptr[1].initHeapEngine(pSysAlloc, ptr);
}

// File Line: 320
// RVA: 0x9CBA80
char *__fastcall Scaleform::HeapMH::AllocEngineMH::allocDirect(
        Scaleform::HeapMH::AllocEngineMH *this,
        unsigned __int64 size,
        unsigned __int64 alignSize,
        bool *limHandlerOK,
        Scaleform::HeapMH::PageInfoMH *info)
{
  unsigned __int64 v8; // rsi
  __int64 v9; // r14
  unsigned __int64 Limit; // rcx
  Scaleform::LockSafe *p_RootLock; // rbx
  char *result; // rax
  char *v13; // rbx
  Scaleform::HeapMH::NodeMH *v14; // rax

  v8 = (size + 7) & 0xFFFFFFFFFFFFFFF8ui64;
  v9 = 40i64;
  if ( alignSize <= 0x10 )
    v9 = 32i64;
  Limit = this->Limit;
  if ( Limit && this->Footprint + v9 + v8 > Limit && this->pLimHandler )
  {
    p_RootLock = &Scaleform::HeapMH::GlobalRootMH->RootLock;
    LeaveCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
    ++*((_DWORD *)this->pLimHandler + 2);
    *limHandlerOK = (*(__int64 (__fastcall **)(void *, Scaleform::MemoryHeapMH *, unsigned __int64))(*(_QWORD *)this->pLimHandler + 8i64))(
                      this->pLimHandler,
                      this->pHeap,
                      this->Footprint + v8 + (unsigned int)v9 - this->Limit);
    --*((_DWORD *)this->pLimHandler + 2);
    EnterCriticalSection(&p_RootLock->mLock.cs);
  }
  *limHandlerOK = 0;
  result = (char *)((__int64 (__fastcall *)(Scaleform::SysAlloc *, unsigned __int64, unsigned __int64))this->pSysAlloc->vfptr[1].__vecDelDtor)(
                     this->pSysAlloc,
                     v9 + v8,
                     alignSize);
  v13 = result;
  if ( result )
  {
    v14 = Scaleform::HeapMH::RootMH::AddToGlobalTree(
            Scaleform::HeapMH::GlobalRootMH,
            result,
            v8,
            alignSize,
            this->pHeap);
    info->UsableSize = v8;
    info->Page = 0i64;
    info->Node = v14;
    ++this->UseCount;
    this->Footprint += v9 + v8;
    this->UsedSpace += v8;
    *limHandlerOK = 1;
    return v13;
  }
  return result;
}

// File Line: 357
// RVA: 0x956560
void *__fastcall Scaleform::HeapMH::AllocEngineMH::Alloc(
        Scaleform::HeapMH::AllocEngineMH *this,
        unsigned __int64 size,
        Scaleform::HeapMH::PageInfoMH *info,
        bool globalLocked)
{
  unsigned __int64 MinAlignSize; // r8
  void *result; // rax
  Scaleform::LockSafe *p_RootLock; // rbp
  void *v10; // rsi
  bool limHandlerOK; // [rsp+60h] [rbp+8h] BYREF

  MinAlignSize = this->MinAlignSize;
  if ( MinAlignSize > 0x10 )
    return Scaleform::HeapMH::AllocEngineMH::Alloc(this, size, MinAlignSize, info, globalLocked);
  if ( size <= 0x200 )
    return Scaleform::HeapMH::AllocEngineMH::allocFromPage(
             this,
             (size + 15) & 0xFFFFFFFFFFFFFFF0ui64,
             info,
             globalLocked);
  if ( globalLocked )
  {
    limHandlerOK = 0;
    while ( 1 )
    {
      result = Scaleform::HeapMH::AllocEngineMH::allocDirect(this, size, this->MinAlignSize, &limHandlerOK, info);
      if ( result )
        break;
      if ( !limHandlerOK )
        return 0i64;
    }
  }
  else
  {
    p_RootLock = &Scaleform::HeapMH::GlobalRootMH->RootLock;
    EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
    limHandlerOK = 0;
    do
    {
      v10 = Scaleform::HeapMH::AllocEngineMH::allocDirect(this, size, this->MinAlignSize, &limHandlerOK, info);
      if ( v10 )
      {
        LeaveCriticalSection(&p_RootLock->mLock.cs);
        return v10;
      }
    }
    while ( limHandlerOK );
    LeaveCriticalSection(&p_RootLock->mLock.cs);
    return 0i64;
  }
  return result;
}

// File Line: 399
// RVA: 0x956420
void *__fastcall Scaleform::HeapMH::AllocEngineMH::Alloc(
        Scaleform::HeapMH::AllocEngineMH *this,
        unsigned __int64 size,
        unsigned __int64 alignSize,
        Scaleform::HeapMH::PageInfoMH *info,
        bool globalLocked)
{
  unsigned __int64 v6; // rbx
  void *result; // rax
  unsigned __int64 v9; // rdi
  Scaleform::LockSafe *p_RootLock; // r15
  void *v11; // rsi
  bool limHandlerOK; // [rsp+68h] [rbp+10h] BYREF

  v6 = alignSize;
  if ( size > 0x200 )
  {
    if ( alignSize < 8 )
      v6 = 8i64;
    if ( size < v6 )
      size = v6;
    v9 = (size + 7) & 0xFFFFFFFFFFFFFFF8ui64;
    if ( globalLocked )
    {
      limHandlerOK = 0;
      while ( 1 )
      {
        result = Scaleform::HeapMH::AllocEngineMH::allocDirect(this, v9, v6, &limHandlerOK, info);
        if ( result )
          break;
        if ( !limHandlerOK )
          return 0i64;
      }
    }
    else
    {
      p_RootLock = &Scaleform::HeapMH::GlobalRootMH->RootLock;
      EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
      limHandlerOK = 0;
      do
      {
        v11 = Scaleform::HeapMH::AllocEngineMH::allocDirect(this, v9, v6, &limHandlerOK, info);
        if ( v11 )
        {
          LeaveCriticalSection(&p_RootLock->mLock.cs);
          return v11;
        }
      }
      while ( limHandlerOK );
      LeaveCriticalSection(&p_RootLock->mLock.cs);
      return 0i64;
    }
  }
  else
  {
    if ( alignSize < 0x10 )
      v6 = 16i64;
    return Scaleform::HeapMH::AllocEngineMH::allocFromPage(
             this,
             (size + 15) & 0xFFFFFFFFFFFFFFF0ui64,
             v6,
             info,
             globalLocked);
  }
  return result;
}

// File Line: 482
// RVA: 0x9EE900
char *__fastcall Scaleform::HeapMH::AllocEngineMH::reallocInNodeNoLock(
        Scaleform::HeapMH::AllocEngineMH *this,
        Scaleform::HeapPT::TreeSeg *node,
        char *oldPtr,
        unsigned __int64 newSize,
        Scaleform::HeapMH::PageInfoMH *newInfo)
{
  char *v5; // rbx
  unsigned __int64 v8; // rax
  unsigned __int64 Buffer; // rbp
  __int64 v10; // r15
  char *v11; // rdi
  unsigned __int64 v12; // rsi
  unsigned __int64 Limit; // rcx
  Scaleform::LockSafe *p_RootLock; // rbx
  char *v15; // rax
  char *v16; // r12
  Scaleform::HeapMH::NodeMH *v17; // rax

  v5 = oldPtr;
  v8 = (__int64)node->Headers & 3;
  if ( v8 == 3 )
    Buffer = (unsigned __int64)node->Buffer;
  else
    Buffer = 1i64 << ((unsigned __int8)v8 + 2);
  v10 = 40i64;
  if ( Buffer <= 0x10 )
    v10 = 32i64;
  v11 = (char *)node + (unsigned int)v10 - (_QWORD)oldPtr;
  v12 = v10 + ((newSize + 7) & 0xFFFFFFFFFFFFFFF8ui64);
  if ( v12 > (unsigned __int64)v11 )
  {
    Limit = this->Limit;
    if ( Limit )
    {
      if ( v12 + this->Footprint - (_QWORD)v11 > Limit && this->pLimHandler )
      {
        p_RootLock = &Scaleform::HeapMH::GlobalRootMH->RootLock;
        LeaveCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
        ++*((_DWORD *)this->pLimHandler + 2);
        (*(void (__fastcall **)(void *, Scaleform::MemoryHeapMH *, unsigned __int64))(*(_QWORD *)this->pLimHandler + 8i64))(
          this->pLimHandler,
          this->pHeap,
          v12 + this->Footprint - this->Limit - (_QWORD)v11);
        --*((_DWORD *)this->pLimHandler + 2);
        EnterCriticalSection(&p_RootLock->mLock.cs);
        v5 = oldPtr;
      }
    }
  }
  Scaleform::RadixTree<Scaleform::HeapMH::NodeMH,Scaleform::HeapMH::TreeNodeAccessor>::Remove(
    (Scaleform::RadixTree<Scaleform::HeapPT::TreeSeg,Scaleform::HeapPT::Granulator::SegTreeAccessor> *)&Scaleform::HeapMH::GlobalRootMH->HeapTree,
    node);
  v15 = (char *)((__int64 (__fastcall *)(Scaleform::SysAlloc *, char *, char *, unsigned __int64, unsigned __int64))this->pSysAlloc->vfptr[1].shutdownHeapEngine)(
                  this->pSysAlloc,
                  v5,
                  v11,
                  v12,
                  Buffer);
  v16 = v15;
  if ( v15 )
  {
    v17 = Scaleform::HeapMH::RootMH::AddToGlobalTree(
            Scaleform::HeapMH::GlobalRootMH,
            v15,
            v12 - v10,
            Buffer,
            this->pHeap);
    newInfo->UsableSize = v12 - v10;
    newInfo->Page = 0i64;
    newInfo->Node = v17;
    this->Footprint += v12 - (_QWORD)v11;
    this->UsedSpace += v12 - (_QWORD)v11;
  }
  else
  {
    Scaleform::HeapMH::RootMH::AddToGlobalTree(
      Scaleform::HeapMH::GlobalRootMH,
      v5,
      (unsigned __int64)&v11[-v10],
      Buffer,
      this->pHeap);
  }
  return v16;
}

// File Line: 549
// RVA: 0x9A6620
void *__fastcall Scaleform::HeapMH::AllocEngineMH::ReallocGeneral(
        Scaleform::HeapMH::AllocEngineMH *this,
        Scaleform::HeapMH::PageMH *page,
        void *oldPtr,
        unsigned __int64 newSize,
        Scaleform::HeapMH::PageInfoMH *newInfo,
        bool globalLocked)
{
  void *result; // rax
  void *v10; // rbx
  char *Start; // rcx
  unsigned __int64 v12; // rdx
  unsigned __int64 v13; // r8
  bool v14; // cc
  const unsigned int *v15; // rcx
  unsigned __int64 BlockSize; // rax
  unsigned __int64 UsableSize; // r8
  unsigned __int64 v18; // rax

  result = Scaleform::HeapMH::AllocEngineMH::Alloc(this, newSize, newInfo, globalLocked);
  v10 = result;
  if ( result )
  {
    Start = page->Start;
    v12 = (unsigned __int64)(Start + 4095) & 0xFFFFFFFFFFFFF000ui64;
    v13 = (unsigned __int64)(Start + 15) & 0xFFFFFFFFFFFFFFF0ui64;
    v14 = v12 - v13 <= ((unsigned __int64)(Start + 4096) & 0xFFFFFFFFFFFFFFF0ui64) - v12;
    v15 = (const unsigned int *)(v12 - 80);
    if ( v14 )
      v15 = (const unsigned int *)(v12 + 16);
    BlockSize = Scaleform::Heap::BitSet2::GetBlockSize(v15, (__int64)((__int64)oldPtr - v13) >> 4);
    UsableSize = newInfo->UsableSize;
    v18 = 16 * BlockSize;
    if ( v18 < UsableSize )
      UsableSize = v18;
    memmove(v10, oldPtr, UsableSize);
    Scaleform::HeapMH::AllocEngineMH::Free(this, page, (unsigned __int64)oldPtr, globalLocked);
    return v10;
  }
  return result;
}

