// File Line: 53
// RVA: 0x9CD320
Scaleform::HeapMH::PageMH *__fastcall Scaleform::HeapMH::AllocEngineMH::allocPageUnlocked(Scaleform::HeapMH::AllocEngineMH *this, bool *limHandlerOK)
{
  bool *v2; // r14
  Scaleform::HeapMH::AllocEngineMH *v3; // rdi
  unsigned __int64 v4; // rcx
  _DWORD *v5; // rax
  _RTL_CRITICAL_SECTION *v6; // rsi
  Scaleform::HeapMH::PageMH *v7; // rbx
  int v8; // edx
  unsigned int v9; // er8
  unsigned __int64 v10; // rax
  int v11; // eax

  v2 = limHandlerOK;
  v3 = this;
  v4 = this->Limit;
  if ( v4 )
  {
    if ( v3->Footprint + 4096 > v4 )
    {
      v5 = v3->pLimHandler;
      if ( v5 )
      {
        ++v5[2];
        *limHandlerOK = (*(__int64 (__fastcall **)(void *, Scaleform::MemoryHeapMH *, unsigned __int64))(*(_QWORD *)v3->pLimHandler + 8i64))(
                          v3->pLimHandler,
                          v3->pHeap,
                          v3->Footprint - v3->Limit + 4096);
        --*((_DWORD *)v3->pLimHandler + 2);
      }
    }
  }
  *v2 = 0;
  v6 = &Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs;
  EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
  v7 = Scaleform::HeapMH::RootMH::AllocPage(Scaleform::HeapMH::GlobalRootMH, v3->pHeap);
  if ( v7 )
  {
    v8 = 0;
    v9 = Scaleform::HeapMH::GlobalRootMH->TableCount;
    if ( v9 )
    {
      while ( 1 )
      {
        v10 = v7 - Scaleform::HeapMH::GlobalPageTableMH.Entries[v8].FirstPage;
        if ( v10 <= Scaleform::HeapMH::GlobalPageTableMH.Entries[v8].SizeMask )
          break;
        if ( ++v8 >= v9 )
          goto LABEL_11;
      }
      v11 = v8 | ((_DWORD)v10 << 7);
    }
    else
    {
LABEL_11:
      v11 = -1;
    }
    Scaleform::HeapMH::AllocBitSet2MH::InitPage(&v3->Allocator, v7, v11);
    v3->Footprint += 4096i64;
    v7->pNext = v3->Pages.Root.pNext;
    v7->pPrev = (Scaleform::HeapMH::PageMH *)&v3->Pages;
    v3->Pages.Root.pNext->pPrev = v7;
    v3->Pages.Root.pNext = v7;
    *v2 = 1;
  }
  LeaveCriticalSection(v6);
  return v7;
}

// File Line: 81
// RVA: 0x9CD0F0
Scaleform::HeapMH::PageMH *__fastcall Scaleform::HeapMH::AllocEngineMH::allocPageLocked(Scaleform::HeapMH::AllocEngineMH *this, bool *limHandlerOK)
{
  bool *v2; // rsi
  Scaleform::HeapMH::AllocEngineMH *v3; // rdi
  unsigned __int64 v4; // rcx
  _RTL_CRITICAL_SECTION *v5; // rbx
  Scaleform::HeapMH::PageMH *result; // rax
  Scaleform::HeapMH::PageMH *v7; // rbx
  int v8; // edx
  unsigned int v9; // er8
  unsigned __int64 v10; // rax
  int v11; // eax

  v2 = limHandlerOK;
  v3 = this;
  v4 = this->Limit;
  if ( v4 && v3->Footprint + 4096 > v4 )
  {
    if ( v3->pLimHandler )
    {
      v5 = &Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs;
      LeaveCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
      ++*((_DWORD *)v3->pLimHandler + 2);
      *v2 = (*(__int64 (__fastcall **)(void *, Scaleform::MemoryHeapMH *, unsigned __int64))(*(_QWORD *)v3->pLimHandler
                                                                                           + 8i64))(
              v3->pLimHandler,
              v3->pHeap,
              v3->Footprint - v3->Limit + 4096);
      --*((_DWORD *)v3->pLimHandler + 2);
      EnterCriticalSection(v5);
    }
  }
  *v2 = 0;
  result = Scaleform::HeapMH::RootMH::AllocPage(Scaleform::HeapMH::GlobalRootMH, v3->pHeap);
  v7 = result;
  if ( result )
  {
    v8 = 0;
    v9 = Scaleform::HeapMH::GlobalRootMH->TableCount;
    if ( v9 )
    {
      while ( 1 )
      {
        v10 = v7 - Scaleform::HeapMH::GlobalPageTableMH.Entries[v8].FirstPage;
        if ( v10 <= Scaleform::HeapMH::GlobalPageTableMH.Entries[v8].SizeMask )
          break;
        if ( ++v8 >= v9 )
          goto LABEL_11;
      }
      v11 = v8 | ((_DWORD)v10 << 7);
    }
    else
    {
LABEL_11:
      v11 = -1;
    }
    Scaleform::HeapMH::AllocBitSet2MH::InitPage(&v3->Allocator, v7, v11);
    v3->Footprint += 4096i64;
    v7->pNext = v3->Pages.Root.pNext;
    v7->pPrev = (Scaleform::HeapMH::PageMH *)&v3->Pages;
    v3->Pages.Root.pNext->pPrev = v7;
    v3->Pages.Root.pNext = v7;
    *v2 = 1;
    result = v7;
  }
  return result;
}

// File Line: 108
// RVA: 0x9E36A0
void __fastcall Scaleform::HeapMH::AllocEngineMH::freePage(Scaleform::HeapMH::AllocEngineMH *this, Scaleform::HeapMH::PageMH *page, bool globalLocked)
{
  Scaleform::HeapMH::PageMH *v3; // rdi
  Scaleform::HeapMH::AllocEngineMH *v4; // rsi
  _RTL_CRITICAL_SECTION *v5; // rbx

  v3 = page;
  v4 = this;
  if ( globalLocked )
  {
    Scaleform::HeapMH::AllocBitSet2MH::ReleasePage(&this->Allocator, page->Start);
    v3->pPrev->pNext = v3->pNext;
    v3->pNext->pPrev = v3->pPrev;
    Scaleform::HeapMH::RootMH::FreePage(Scaleform::HeapMH::GlobalRootMH, v3);
  }
  else
  {
    v5 = &Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs;
    EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
    Scaleform::HeapMH::AllocBitSet2MH::ReleasePage(&v4->Allocator, v3->Start);
    v3->pPrev->pNext = v3->pNext;
    v3->pNext->pPrev = v3->pPrev;
    Scaleform::HeapMH::RootMH::FreePage(Scaleform::HeapMH::GlobalRootMH, v3);
    LeaveCriticalSection(v5);
  }
  v4->Footprint -= 4096i64;
}

// File Line: 127
// RVA: 0x9CBD40
Scaleform::HeapMH::BinNodeMH *__fastcall Scaleform::HeapMH::AllocEngineMH::allocFromPage(Scaleform::HeapMH::AllocEngineMH *this, unsigned __int64 size, Scaleform::HeapMH::PageInfoMH *info, bool globalLocked)
{
  bool v4; // di
  Scaleform::HeapMH::PageInfoMH *v5; // r14
  unsigned __int64 v6; // rsi
  Scaleform::HeapMH::AllocEngineMH *v7; // rbx
  Scaleform::HeapMH::BinNodeMH *v8; // rcx
  Scaleform::HeapMH::PageMH *v10; // rax
  Scaleform::HeapMH::MagicHeadersInfo headers; // [rsp+20h] [rbp-58h]
  bool limHandlerOK; // [rsp+80h] [rbp+8h]

  v4 = globalLocked;
  v5 = info;
  v6 = size;
  v7 = this;
  limHandlerOK = 0;
  while ( 1 )
  {
    v8 = Scaleform::HeapMH::AllocBitSet2MH::Alloc(&v7->Allocator, v6, &headers);
    if ( v8 )
      break;
    if ( v4 )
      Scaleform::HeapMH::AllocEngineMH::allocPageLocked(v7, &limHandlerOK);
    else
      Scaleform::HeapMH::AllocEngineMH::allocPageUnlocked(v7, &limHandlerOK);
    if ( !limHandlerOK )
      return 0i64;
  }
  if ( headers.Header1 )
    ++headers.Header1->UseCount;
  if ( headers.Header2 )
    ++headers.Header2->UseCount;
  v10 = headers.Page;
  v5->UsableSize = v6;
  v5->Node = 0i64;
  v5->Page = v10;
  ++v7->UseCount;
  v7->UsedSpace += v6;
  return v8;
}

// File Line: 169
// RVA: 0x9CBC60
Scaleform::HeapMH::BinNodeMH *__fastcall Scaleform::HeapMH::AllocEngineMH::allocFromPage(Scaleform::HeapMH::AllocEngineMH *this, unsigned __int64 size, unsigned __int64 alignSize, Scaleform::HeapMH::PageInfoMH *info, bool globalLocked)
{
  bool v5; // di
  Scaleform::HeapMH::PageInfoMH *v6; // r14
  unsigned __int64 v7; // rbp
  unsigned __int64 v8; // rsi
  Scaleform::HeapMH::AllocEngineMH *v9; // rbx
  Scaleform::HeapMH::BinNodeMH *v10; // rcx
  Scaleform::HeapMH::PageMH *v12; // rax
  Scaleform::HeapMH::MagicHeadersInfo headers; // [rsp+20h] [rbp-58h]
  bool limHandlerOK; // [rsp+80h] [rbp+8h]

  v5 = globalLocked;
  v6 = info;
  v7 = alignSize;
  v8 = size;
  v9 = this;
  limHandlerOK = 0;
  while ( 1 )
  {
    v10 = Scaleform::HeapMH::AllocBitSet2MH::Alloc(&v9->Allocator, v8, v7, &headers);
    if ( v10 )
      break;
    if ( v5 )
      Scaleform::HeapMH::AllocEngineMH::allocPageLocked(v9, &limHandlerOK);
    else
      Scaleform::HeapMH::AllocEngineMH::allocPageUnlocked(v9, &limHandlerOK);
    if ( !limHandlerOK )
      return 0i64;
  }
  if ( headers.Header1 )
    ++headers.Header1->UseCount;
  if ( headers.Header2 )
    ++headers.Header2->UseCount;
  v12 = headers.Page;
  v6->UsableSize = v8;
  v6->Node = 0i64;
  v6->Page = v12;
  ++v9->UseCount;
  v9->UsedSpace += v8;
  return v10;
}

// File Line: 211
// RVA: 0x97DA20
void __fastcall Scaleform::HeapMH::AllocEngineMH::Free(Scaleform::HeapMH::AllocEngineMH *this, Scaleform::HeapMH::PageMH *page, void *ptr, bool globalLocked)
{
  bool v4; // si
  Scaleform::HeapMH::AllocEngineMH *v5; // rbx
  Scaleform::HeapMH::PageMH *v6; // rdi
  __int64 v7; // rax
  int v8; // ecx
  __int64 v9; // rax
  __int64 v10; // [rsp+30h] [rbp-48h]
  __int64 v11; // [rsp+38h] [rbp-40h]
  __int64 v12; // [rsp+80h] [rbp+8h]

  v4 = globalLocked;
  v5 = this;
  v6 = page;
  Scaleform::HeapMH::AllocBitSet2MH::Free(
    &this->Allocator,
    page,
    ptr,
    (Scaleform::HeapMH::MagicHeadersInfo *)&v10,
    (unsigned __int64 *)&v12);
  v5->UsedSpace -= v12;
  v7 = v10;
  v8 = 0;
  if ( v10 )
  {
    --*(_WORD *)(v10 + 2);
    v8 = *(unsigned __int16 *)(v7 + 2);
  }
  v9 = v11;
  if ( v11 )
  {
    --*(_WORD *)(v11 + 2);
    v8 = *(unsigned __int16 *)(v9 + 2);
  }
  if ( !v8 )
    Scaleform::HeapMH::AllocEngineMH::freePage(v5, v6, v4);
  --v5->UseCount;
}

// File Line: 230
// RVA: 0x97D980
void __fastcall Scaleform::HeapMH::AllocEngineMH::Free(Scaleform::HeapMH::AllocEngineMH *this, Scaleform::HeapMH::NodeMH *node, void *ptr, bool __formal)
{
  Scaleform::HeapMH::AllocEngineMH *v4; // rdi
  void *v5; // rsi
  Scaleform::HeapMH::NodeMH *v6; // rbx
  unsigned __int64 v7; // rax
  unsigned __int64 v8; // r9
  signed __int64 v9; // rax
  Scaleform::SysAlloc *v10; // rcx
  char *v11; // r8

  v4 = this;
  v5 = ptr;
  v6 = node;
  Scaleform::RadixTree<Scaleform::HeapMH::NodeMH,Scaleform::HeapMH::TreeNodeAccessor>::Remove(
    (Scaleform::RadixTree<Scaleform::HeapPT::TreeSeg,Scaleform::HeapPT::Granulator::SegTreeAccessor> *)&Scaleform::HeapMH::GlobalRootMH->HeapTree,
    (Scaleform::HeapPT::TreeSeg *)node);
  v7 = v6->pHeap & 3;
  if ( v7 >= 3 )
    v8 = v6->Align;
  else
    v8 = 1i64 << ((unsigned __int8)v7 + 2);
  v9 = 40i64;
  if ( v8 <= 0x10 )
    v9 = 32i64;
  v10 = v4->pSysAlloc;
  --v4->UseCount;
  v11 = (char *)v6 + (unsigned int)v9 - (_QWORD)v5;
  v4->Footprint -= (unsigned __int64)v11;
  v4->UsedSpace += v9 - (_QWORD)v11;
  v10->vfptr[1].initHeapEngine((Scaleform::SysAllocBase *)&v10->vfptr, v5);
}

// File Line: 320
// RVA: 0x9CBA80
char *__fastcall Scaleform::HeapMH::AllocEngineMH::allocDirect(Scaleform::HeapMH::AllocEngineMH *this, unsigned __int64 size, unsigned __int64 alignSize, bool *limHandlerOK, Scaleform::HeapMH::PageInfoMH *info)
{
  bool *v5; // r15
  unsigned __int64 v6; // rbp
  Scaleform::HeapMH::AllocEngineMH *v7; // rdi
  unsigned __int64 v8; // rsi
  signed __int64 v9; // r14
  unsigned __int64 v10; // rcx
  _RTL_CRITICAL_SECTION *v11; // rbx
  char *result; // rax
  char *v13; // rbx
  Scaleform::HeapMH::NodeMH *v14; // rax

  v5 = limHandlerOK;
  v6 = alignSize;
  v7 = this;
  v8 = (size + 7) & 0xFFFFFFFFFFFFFFF8ui64;
  v9 = 40i64;
  if ( alignSize <= 0x10 )
    v9 = 32i64;
  v10 = this->Limit;
  if ( v10 && v7->Footprint + v9 + v8 > v10 && v7->pLimHandler )
  {
    v11 = &Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs;
    LeaveCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
    ++*((_DWORD *)v7->pLimHandler + 2);
    *v5 = (*(__int64 (__fastcall **)(void *, Scaleform::MemoryHeapMH *, unsigned __int64))(*(_QWORD *)v7->pLimHandler
                                                                                         + 8i64))(
            v7->pLimHandler,
            v7->pHeap,
            v7->Footprint + v8 + (unsigned int)v9 - v7->Limit);
    --*((_DWORD *)v7->pLimHandler + 2);
    EnterCriticalSection(v11);
  }
  *v5 = 0;
  result = (char *)((__int64 (__fastcall *)(Scaleform::SysAlloc *, unsigned __int64, unsigned __int64))v7->pSysAlloc->vfptr[1].__vecDelDtor)(
                     v7->pSysAlloc,
                     v9 + v8,
                     v6);
  v13 = result;
  if ( result )
  {
    v14 = Scaleform::HeapMH::RootMH::AddToGlobalTree(Scaleform::HeapMH::GlobalRootMH, result, v8, v6, v7->pHeap);
    info->UsableSize = v8;
    info->Page = 0i64;
    info->Node = v14;
    ++v7->UseCount;
    v7->Footprint += v9 + v8;
    v7->UsedSpace += v8;
    *v5 = 1;
    result = v13;
  }
  return result;
}

// File Line: 357
// RVA: 0x956560
void *__fastcall Scaleform::HeapMH::AllocEngineMH::Alloc(Scaleform::HeapMH::AllocEngineMH *this, unsigned __int64 size, Scaleform::HeapMH::PageInfoMH *info, bool globalLocked)
{
  Scaleform::HeapMH::PageInfoMH *v4; // r14
  unsigned __int64 v5; // rdi
  Scaleform::HeapMH::AllocEngineMH *v6; // rbx
  unsigned __int64 v7; // r8
  void *result; // rax
  _RTL_CRITICAL_SECTION *v9; // rbp
  void *v10; // rsi
  bool limHandlerOK; // [rsp+60h] [rbp+8h]

  v4 = info;
  v5 = size;
  v6 = this;
  v7 = this->MinAlignSize;
  if ( v7 > 0x10 )
    return Scaleform::HeapMH::AllocEngineMH::Alloc(this, size, v7, v4, globalLocked);
  if ( size <= 0x200 )
    return Scaleform::HeapMH::AllocEngineMH::allocFromPage(this, (size + 15) & 0xFFFFFFFFFFFFFFF0ui64, v4, globalLocked);
  if ( globalLocked )
  {
    limHandlerOK = 0;
    while ( 1 )
    {
      result = Scaleform::HeapMH::AllocEngineMH::allocDirect(v6, v5, v6->MinAlignSize, &limHandlerOK, v4);
      if ( result )
        break;
      if ( !limHandlerOK )
        goto LABEL_14;
    }
  }
  else
  {
    v9 = &Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs;
    EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
    limHandlerOK = 0;
    do
    {
      v10 = Scaleform::HeapMH::AllocEngineMH::allocDirect(v6, v5, v6->MinAlignSize, &limHandlerOK, v4);
      if ( v10 )
      {
        LeaveCriticalSection(v9);
        return v10;
      }
    }
    while ( limHandlerOK );
    LeaveCriticalSection(v9);
LABEL_14:
    result = 0i64;
  }
  return result;
}

// File Line: 399
// RVA: 0x956420
void *__fastcall Scaleform::HeapMH::AllocEngineMH::Alloc(Scaleform::HeapMH::AllocEngineMH *this, unsigned __int64 size, unsigned __int64 alignSize, Scaleform::HeapMH::PageInfoMH *info, bool globalLocked)
{
  Scaleform::HeapMH::PageInfoMH *v5; // rbp
  unsigned __int64 v6; // rbx
  Scaleform::HeapMH::AllocEngineMH *v7; // r14
  void *result; // rax
  unsigned __int64 v9; // rdi
  _RTL_CRITICAL_SECTION *v10; // r15
  void *v11; // rsi
  bool limHandlerOK; // [rsp+68h] [rbp+10h]

  v5 = info;
  v6 = alignSize;
  v7 = this;
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
        result = Scaleform::HeapMH::AllocEngineMH::allocDirect(v7, v9, v6, &limHandlerOK, v5);
        if ( result )
          break;
        if ( !limHandlerOK )
          goto LABEL_18;
      }
    }
    else
    {
      v10 = &Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs;
      EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
      limHandlerOK = 0;
      do
      {
        v11 = Scaleform::HeapMH::AllocEngineMH::allocDirect(v7, v9, v6, &limHandlerOK, v5);
        if ( v11 )
        {
          LeaveCriticalSection(v10);
          return v11;
        }
      }
      while ( limHandlerOK );
      LeaveCriticalSection(v10);
LABEL_18:
      result = 0i64;
    }
  }
  else
  {
    if ( alignSize < 0x10 )
      v6 = 16i64;
    result = Scaleform::HeapMH::AllocEngineMH::allocFromPage(
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
char *__fastcall Scaleform::HeapMH::AllocEngineMH::reallocInNodeNoLock(Scaleform::HeapMH::AllocEngineMH *this, Scaleform::HeapMH::NodeMH *node, void *oldPtr, unsigned __int64 newSize, Scaleform::HeapMH::PageInfoMH *newInfo)
{
  char *v5; // rbx
  Scaleform::HeapMH::NodeMH *v6; // r13
  Scaleform::HeapMH::AllocEngineMH *v7; // r14
  unsigned __int64 v8; // rax
  unsigned __int64 v9; // rbp
  signed __int64 v10; // r15
  char *v11; // rdi
  unsigned __int64 v12; // rsi
  unsigned __int64 v13; // rcx
  _RTL_CRITICAL_SECTION *v14; // rbx
  char *v15; // rax
  char *v16; // r12
  Scaleform::HeapMH::NodeMH *v17; // rax
  char *v19; // [rsp+90h] [rbp+18h]

  v19 = (char *)oldPtr;
  v5 = (char *)oldPtr;
  v6 = node;
  v7 = this;
  v8 = node->pHeap & 3;
  if ( v8 >= 3 )
    v9 = node->Align;
  else
    v9 = 1i64 << ((unsigned __int8)v8 + 2);
  v10 = 40i64;
  if ( v9 <= 0x10 )
    v10 = 32i64;
  v11 = (char *)node + (unsigned int)v10 - (_QWORD)oldPtr;
  v12 = v10 + ((newSize + 7) & 0xFFFFFFFFFFFFFFF8ui64);
  if ( v12 > (unsigned __int64)v11 )
  {
    v13 = this->Limit;
    if ( v13 )
    {
      if ( v12 + v7->Footprint - (_QWORD)v11 > v13 && v7->pLimHandler )
      {
        v14 = &Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs;
        LeaveCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
        ++*((_DWORD *)v7->pLimHandler + 2);
        (*(void (__fastcall **)(void *, Scaleform::MemoryHeapMH *, unsigned __int64))(*(_QWORD *)v7->pLimHandler + 8i64))(
          v7->pLimHandler,
          v7->pHeap,
          v12 + v7->Footprint - v7->Limit - (_QWORD)v11);
        --*((_DWORD *)v7->pLimHandler + 2);
        EnterCriticalSection(v14);
        v5 = v19;
      }
    }
  }
  Scaleform::RadixTree<Scaleform::HeapMH::NodeMH,Scaleform::HeapMH::TreeNodeAccessor>::Remove(
    (Scaleform::RadixTree<Scaleform::HeapPT::TreeSeg,Scaleform::HeapPT::Granulator::SegTreeAccessor> *)&Scaleform::HeapMH::GlobalRootMH->HeapTree,
    (Scaleform::HeapPT::TreeSeg *)v6);
  v15 = (char *)((__int64 (__fastcall *)(Scaleform::SysAlloc *, char *, char *, unsigned __int64, unsigned __int64))v7->pSysAlloc->vfptr[1].shutdownHeapEngine)(
                  v7->pSysAlloc,
                  v5,
                  v11,
                  v12,
                  v9);
  v16 = v15;
  if ( v15 )
  {
    v17 = Scaleform::HeapMH::RootMH::AddToGlobalTree(Scaleform::HeapMH::GlobalRootMH, v15, v12 - v10, v9, v7->pHeap);
    newInfo->UsableSize = v12 - v10;
    newInfo->Page = 0i64;
    newInfo->Node = v17;
    v7->Footprint += v12 - (_QWORD)v11;
    v7->UsedSpace += v12 - (_QWORD)v11;
  }
  else
  {
    Scaleform::HeapMH::RootMH::AddToGlobalTree(
      Scaleform::HeapMH::GlobalRootMH,
      v5,
      (unsigned __int64)&v11[-v10],
      v9,
      v7->pHeap);
  }
  return v16;
}

// File Line: 549
// RVA: 0x9A6620
void *__fastcall Scaleform::HeapMH::AllocEngineMH::ReallocGeneral(Scaleform::HeapMH::AllocEngineMH *this, Scaleform::HeapMH::PageMH *page, void *oldPtr, unsigned __int64 newSize, Scaleform::HeapMH::PageInfoMH *newInfo, bool globalLocked)
{
  void *v6; // r15
  Scaleform::HeapMH::PageMH *v7; // rdi
  Scaleform::HeapMH::AllocEngineMH *v8; // rsi
  void *result; // rax
  void *v10; // rbx
  char *v11; // rcx
  unsigned __int64 v12; // rdx
  unsigned __int64 v13; // r8
  unsigned __int64 v14; // rcx
  bool v15; // cf
  bool v16; // zf
  const unsigned int *v17; // rcx
  unsigned __int64 v18; // rax
  unsigned __int64 v19; // r8
  unsigned __int64 v20; // rax

  v6 = oldPtr;
  v7 = page;
  v8 = this;
  result = Scaleform::HeapMH::AllocEngineMH::Alloc(this, newSize, newInfo, globalLocked);
  v10 = result;
  if ( result )
  {
    v11 = v7->Start;
    v12 = (unsigned __int64)(v11 + 4095) & 0xFFFFFFFFFFFFF000ui64;
    v13 = (unsigned __int64)(v11 + 15) & 0xFFFFFFFFFFFFFFF0ui64;
    v14 = ((unsigned __int64)(v11 + 4096) & 0xFFFFFFFFFFFFFFF0ui64) - v12;
    v15 = v12 - v13 < v14;
    v16 = v12 - v13 == v14;
    v17 = (const unsigned int *)(v12 - 80);
    if ( v15 || v16 )
      v17 = (const unsigned int *)(v12 + 16);
    v18 = Scaleform::Heap::BitSet2::GetBlockSize(v17, (signed __int64)((signed __int64)v6 - v13) >> 4);
    v19 = newInfo->UsableSize;
    v20 = 16 * v18;
    if ( v20 < v19 )
      v19 = v20;
    memmove(v10, v6, v19);
    Scaleform::HeapMH::AllocEngineMH::Free(v8, v7, v6, globalLocked);
    result = v10;
  }
  return result;
}

