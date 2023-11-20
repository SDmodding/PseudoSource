// File Line: 65
// RVA: 0x938B10
void __fastcall Scaleform::HeapPT::AllocEngine::AllocEngine(Scaleform::HeapPT::AllocEngine *this, Scaleform::SysAllocPaged *sysAlloc, Scaleform::MemoryHeapPT *heap, unsigned int allocFlags, unsigned __int64 minAlignSize, unsigned __int64 granularity, unsigned __int64 reserve, unsigned __int64 threshold, unsigned __int64 limit)
{
  Scaleform::HeapPT::AllocEngine *v9; // rdi
  unsigned int v10; // ebx
  unsigned __int8 v11; // al
  Scaleform::List<Scaleform::HeapPT::AllocEngine::TinyBlock,Scaleform::HeapPT::AllocEngine::TinyBlock> *v12; // rcx
  Scaleform::List<Scaleform::Heap::HeapSegment,Scaleform::Heap::HeapSegment> *v13; // rax
  unsigned __int64 v14; // rcx
  unsigned __int64 v15; // rcx
  unsigned __int64 v16; // rax
  unsigned __int64 v17; // rax
  Scaleform::SysAllocPaged *v18; // rcx
  unsigned __int64 v19; // rcx
  unsigned __int64 v20; // r8
  unsigned __int64 v21; // rax
  __int64 v22; // rdx
  unsigned __int64 v23; // rax
  unsigned __int64 v24; // rdx
  unsigned __int64 v25; // rdx
  unsigned __int64 v26; // rdx
  __int64 v27; // [rsp+30h] [rbp-38h]
  __int64 v28; // [rsp+38h] [rbp-30h]
  __int128 v29; // [rsp+40h] [rbp-28h]
  __int64 v30; // [rsp+50h] [rbp-18h]
  _BOOL8 v31; // [rsp+58h] [rbp-10h]
  bool limHandlerOK; // [rsp+88h] [rbp+20h]

  this->pHeap = heap;
  this->pSysAlloc = sysAlloc;
  v9 = this;
  v10 = allocFlags;
  this->pBookkeeper = &Scaleform::HeapPT::GlobalRoot->AllocBookkeeper;
  v11 = Scaleform::Alg::UpperBit(minAlignSize);
  v9->MinAlignShift = v11;
  v9->MinAlignMask = (1i64 << v11) - 1;
  v9->Allocator.MinAlignShift = v11;
  v9->Allocator.MinAlignMask = (1i64 << v11) - 1;
  v9->Allocator.Bin.ListBin1.Mask = 0i64;
  memset(v9->Allocator.Bin.ListBin1.Roots, 0, 0x200ui64);
  v9->Allocator.Bin.ListBin2.Mask = 0i64;
  memset(v9->Allocator.Bin.ListBin2.Roots, 0, 0x200ui64);
  v9->Allocator.Bin.TreeBin1.Mask = 0i64;
  memset(v9->Allocator.Bin.TreeBin1.Roots, 0, 0x200ui64);
  v9->Allocator.Bin.FreeBlocks = 0i64;
  v12 = v9->TinyBlocks;
  v13 = &v9->SegmentList;
  v13->Root.pPrev = (Scaleform::Heap::HeapSegment *)v13;
  v13->Root.pNext = (Scaleform::Heap::HeapSegment *)v13;
  v12->Root.pPrev = (Scaleform::HeapPT::AllocEngine::TinyBlock *)v12;
  v12->Root.pNext = (Scaleform::HeapPT::AllocEngine::TinyBlock *)v12;
  v12[1].Root.pNext = (Scaleform::HeapPT::AllocEngine::TinyBlock *)&v9->TinyBlocks[1];
  v9->TinyBlocks[1].Root.pPrev = (Scaleform::HeapPT::AllocEngine::TinyBlock *)&v9->TinyBlocks[1];
  v12[2].Root.pNext = (Scaleform::HeapPT::AllocEngine::TinyBlock *)&v9->TinyBlocks[2];
  v9->TinyBlocks[2].Root.pPrev = (Scaleform::HeapPT::AllocEngine::TinyBlock *)&v9->TinyBlocks[2];
  v12[3].Root.pNext = (Scaleform::HeapPT::AllocEngine::TinyBlock *)&v9->TinyBlocks[3];
  v9->TinyBlocks[3].Root.pPrev = (Scaleform::HeapPT::AllocEngine::TinyBlock *)&v9->TinyBlocks[3];
  v12[4].Root.pNext = (Scaleform::HeapPT::AllocEngine::TinyBlock *)&v9->TinyBlocks[4];
  v9->TinyBlocks[4].Root.pPrev = (Scaleform::HeapPT::AllocEngine::TinyBlock *)&v9->TinyBlocks[4];
  v12[5].Root.pNext = (Scaleform::HeapPT::AllocEngine::TinyBlock *)&v9->TinyBlocks[5];
  v9->TinyBlocks[5].Root.pPrev = (Scaleform::HeapPT::AllocEngine::TinyBlock *)&v9->TinyBlocks[5];
  v12[6].Root.pNext = (Scaleform::HeapPT::AllocEngine::TinyBlock *)&v9->TinyBlocks[6];
  v9->TinyBlocks[6].Root.pPrev = (Scaleform::HeapPT::AllocEngine::TinyBlock *)&v9->TinyBlocks[6];
  v12[7].Root.pNext = (Scaleform::HeapPT::AllocEngine::TinyBlock *)&v9->TinyBlocks[7];
  v14 = granularity;
  v9->TinyBlocks[7].Root.pPrev = (Scaleform::HeapPT::AllocEngine::TinyBlock *)&v9->TinyBlocks[7];
  v15 = (v14 + 4095) & 0xFFFFFFFFFFFFF000ui64;
  v9->AllowDynaSize = (v10 >> 5) & 1;
  v9->AllowTinyBlocks = (v10 >> 4) & 1;
  v16 = reserve;
  *(_WORD *)&v9->Valid = 0;
  v9->SysGranularity = 4096i64;
  v9->Granularity = v15;
  v9->SysDirectThreshold = 0i64;
  v9->Footprint = 0i64;
  v9->TinyFreeSpace = 0i64;
  v9->SysDirectSpace = 0i64;
  v9->pCachedBSeg = 0i64;
  v9->pCachedTSeg = 0i64;
  v9->pLimHandler = 0i64;
  v17 = v15 * ((v15 + v16 - 1) / v15);
  v18 = v9->pSysAlloc;
  v9->Reserve = v17;
  v9->Threshold = threshold;
  v9->Limit = limit;
  v27 = 0i64;
  v28 = 0i64;
  v29 = 0ui64;
  v30 = 0i64;
  v31 = 0i64;
  v18->vfptr[1].__vecDelDtor((Scaleform::SysAllocBase *)&v18->vfptr, (unsigned int)&v27);
  v19 = *((_QWORD *)&v29 + 1);
  v20 = v29;
  v9->HasRealloc = v31;
  v21 = v9->Granularity;
  v9->SysDirectThreshold = v19;
  if ( v20 < 0x1000 )
    v20 = 4096i64;
  *(_QWORD *)&v29 = v20;
  v9->SysGranularity = v20;
  v22 = v30;
  v23 = v20 * ((v20 + v21 - 1) / v20);
  v9->Granularity = v23;
  if ( v22 )
  {
    v24 = (v22 + 4095) & 0xFFFFFFFFFFFFF000ui64;
    v30 = v24;
    if ( v23 > v24 )
    {
      v9->Granularity = v24;
      *(_WORD *)&v9->AllowTinyBlocks = 0;
    }
  }
  v25 = v9->Threshold;
  if ( v25 < 32 * v20 && v25 )
    v9->Threshold = 32 * v20;
  if ( v19 )
  {
    if ( v9->Threshold > v19 )
      v9->Threshold = v19;
    if ( v9->Threshold - 1 <= 0xFFE )
      v9->Threshold = 4096i64;
    if ( v9->Granularity > v19 )
      v9->Granularity = (v19 + 4095) & 0xFFFFFFFFFFFFF000ui64;
    if ( v20 > v19 )
      v9->SysGranularity = (v19 + 4095) & 0xFFFFFFFFFFFFF000ui64;
    if ( v9->Reserve > v19 )
      v9->Reserve = v19;
    v9->AllowDynaSize = 0;
  }
  v26 = v9->Reserve;
  if ( v26 )
    v9->Valid = Scaleform::HeapPT::AllocEngine::allocSegmentBitSet(
                  v9,
                  v26,
                  minAlignSize,
                  v9->Granularity,
                  &limHandlerOK) != 0i64;
  else
    v9->Valid = 1;
}

// File Line: 155
// RVA: 0x97E210
void __fastcall Scaleform::HeapPT::AllocEngine::FreeAll(Scaleform::HeapPT::AllocEngine *this)
{
  Scaleform::Heap::HeapSegment *v1; // rax
  Scaleform::Heap::HeapSegment *v2; // rdi
  Scaleform::HeapPT::AllocEngine *v3; // rbx

  v1 = this->SegmentList.Root.pNext;
  v2 = (Scaleform::Heap::HeapSegment *)&this->SegmentList;
  v3 = this;
  if ( v1 != (Scaleform::Heap::HeapSegment *)&this->SegmentList )
  {
    do
    {
      Scaleform::HeapPT::AllocEngine::freeSegment(v3, v1);
      v1 = v3->SegmentList.Root.pNext;
    }
    while ( v1 != v2 );
  }
  v3->Allocator.Bin.ListBin1.Mask = 0i64;
  memset(v3->Allocator.Bin.ListBin1.Roots, 0, 0x200ui64);
  v3->Allocator.Bin.ListBin2.Mask = 0i64;
  memset(v3->Allocator.Bin.ListBin2.Roots, 0, 0x200ui64);
  v3->Allocator.Bin.TreeBin1.Mask = 0i64;
  memset(v3->Allocator.Bin.TreeBin1.Roots, 0, 0x200ui64);
  v3->Allocator.Bin.FreeBlocks = 0i64;
}

// File Line: 177
// RVA: 0x9CD590
Scaleform::Heap::HeapSegment *__fastcall Scaleform::HeapPT::AllocEngine::allocSegment(Scaleform::HeapPT::AllocEngine *this, unsigned int segType, unsigned __int64 dataSize, unsigned __int64 alignSize, unsigned __int64 bookkeepingSize, bool *limHandlerOK)
{
  unsigned __int64 v6; // rbp
  unsigned __int64 v7; // r14
  unsigned int v8; // er12
  Scaleform::HeapPT::AllocEngine *v9; // rdi
  unsigned __int64 v10; // rcx
  _RTL_CRITICAL_SECTION *v11; // rbx
  unsigned __int64 v12; // rsi
  char *v13; // rax
  Scaleform::Heap::HeapSegment *v14; // rbx
  char *v15; // rax
  char v16; // al
  unsigned __int64 v17; // rdx

  v6 = alignSize;
  v7 = dataSize;
  v8 = segType;
  v9 = this;
  v10 = this->Limit;
  if ( v10 && dataSize + v9->Footprint > v10 && v9->pLimHandler )
  {
    v11 = &Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs;
    LeaveCriticalSection(&Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs);
    ++*((_DWORD *)v9->pLimHandler + 2);
    *limHandlerOK = (*(__int64 (__fastcall **)(void *, Scaleform::MemoryHeapPT *, unsigned __int64))(*(_QWORD *)v9->pLimHandler + 8i64))(
                      v9->pLimHandler,
                      v9->pHeap,
                      v9->Footprint + v7 - v9->Limit);
    --*((_DWORD *)v9->pLimHandler + 2);
    EnterCriticalSection(v11);
  }
  *limHandlerOK = 0;
  v12 = (bookkeepingSize + 95) & 0xFFFFFFFFFFFFFFE0ui64;
  v13 = Scaleform::HeapPT::Bookkeeper::Alloc(v9->pBookkeeper, v12);
  v14 = (Scaleform::Heap::HeapSegment *)v13;
  if ( !v13 )
    return 0i64;
  *((_QWORD *)v13 + 2) = v12;
  *((_DWORD *)v13 + 6) = v8;
  *((_DWORD *)v13 + 7) = (unsigned __int8)Scaleform::Alg::UpperBit((unsigned int)v6);
  v14->UseCount = 0i64;
  v14->pHeap = v9->pHeap;
  v14->DataSize = v7;
  v14->pData = 0i64;
  if ( !v7 )
  {
LABEL_14:
    v14->pNext = v9->SegmentList.Root.pNext;
    v14->pPrev = (Scaleform::Heap::HeapSegment *)&v9->SegmentList;
    v9->SegmentList.Root.pNext->pPrev = v14;
    v9->SegmentList.Root.pNext = v14;
    v9->Footprint += v14->DataSize;
    *limHandlerOK = 1;
    return v14;
  }
  if ( v6 < 0x1000 )
    v6 = 4096i64;
  v15 = (char *)((__int64 (__fastcall *)(Scaleform::SysAllocPaged *, unsigned __int64, unsigned __int64))v9->pSysAlloc->vfptr[1].initHeapEngine)(
                  v9->pSysAlloc,
                  v7,
                  v6);
  v14->pData = v15;
  if ( !v15 )
    goto LABEL_12;
  v16 = Scaleform::HeapPT::PageTable::MapRange(Scaleform::HeapPT::GlobalPageTable, v15, v14->DataSize);
  v17 = (unsigned __int64)v14->pData;
  if ( v16 )
  {
    Scaleform::HeapPT::PageTable::SetSegmentInRange(Scaleform::HeapPT::GlobalPageTable, v17, v14->DataSize, v14);
    goto LABEL_14;
  }
  ((void (__fastcall *)(Scaleform::SysAllocPaged *, unsigned __int64, unsigned __int64, unsigned __int64, signed __int64))v9->pSysAlloc->vfptr[1].shutdownHeapEngine)(
    v9->pSysAlloc,
    v17,
    v7,
    v6,
    -2i64);
LABEL_12:
  Scaleform::HeapPT::Bookkeeper::Free(v9->pBookkeeper, v14, v12);
  return 0i64;
}

// File Line: 241
// RVA: 0x9CDBE0
Scaleform::Heap::HeapSegment *__fastcall Scaleform::HeapPT::AllocEngine::allocSegmentNoGranulator(Scaleform::HeapPT::AllocEngine *this, unsigned __int64 dataSize, unsigned __int64 alignSize, bool *limHandlerOK)
{
  bool *v4; // r15
  unsigned __int64 v5; // r13
  unsigned __int64 v6; // r14
  Scaleform::HeapPT::AllocEngine *v7; // rdi
  unsigned __int64 v8; // rcx
  _DWORD *v9; // rax
  _RTL_CRITICAL_SECTION *v10; // rbp
  char *v11; // rax
  Scaleform::Heap::HeapSegment *v12; // rbx
  Scaleform::Heap::HeapSegment *v13; // rsi
  __int64 v14; // r12
  signed __int64 v15; // rax
  unsigned __int64 v16; // r8
  char v17; // al
  unsigned __int64 v18; // r8
  unsigned __int64 v19; // rdx
  __int64 v20; // rax
  __int64 v22; // [rsp+30h] [rbp-58h]
  __int64 v23; // [rsp+38h] [rbp-50h]
  Scaleform::LockSafe *v24; // [rsp+40h] [rbp-48h]
  signed __int64 v25; // [rsp+90h] [rbp+8h]
  unsigned __int64 val; // [rsp+A8h] [rbp+20h]

  v23 = -2i64;
  v4 = limHandlerOK;
  v5 = alignSize;
  v6 = dataSize;
  v7 = this;
  v8 = this->Limit;
  if ( v8 )
  {
    if ( dataSize + v7->Footprint > v8 )
    {
      v9 = v7->pLimHandler;
      if ( v9 )
      {
        ++v9[2];
        *limHandlerOK = (*(__int64 (__fastcall **)(void *, Scaleform::MemoryHeapPT *, unsigned __int64))(*(_QWORD *)v7->pLimHandler + 8i64))(
                          v7->pLimHandler,
                          v7->pHeap,
                          v7->Footprint + dataSize - v7->Limit);
        --*((_DWORD *)v7->pLimHandler + 2);
      }
    }
  }
  *v4 = 0;
  v10 = &Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs;
  v24 = &Scaleform::HeapPT::GlobalRoot->RootLock;
  EnterCriticalSection(&Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs);
  v11 = Scaleform::HeapPT::Bookkeeper::Alloc(v7->pBookkeeper, 0x40ui64);
  v12 = (Scaleform::Heap::HeapSegment *)v11;
  v13 = 0i64;
  if ( v11 )
  {
    *((_QWORD *)v11 + 2) = 64i64;
    *((_QWORD *)v11 + 3) = 9i64;
    *((_QWORD *)v11 + 4) = 0i64;
    *((_QWORD *)v11 + 5) = v7->pHeap;
    *((_QWORD *)v11 + 6) = 0i64;
    *((_QWORD *)v11 + 7) = 0i64;
    if ( v6 )
    {
      v14 = ((__int64 (__fastcall *)(Scaleform::SysAllocPaged *, unsigned __int64, unsigned __int64, __int64 *, unsigned __int64 *))v7->pSysAlloc->vfptr[2].initHeapEngine)(
              v7->pSysAlloc,
              v6,
              v5,
              &v22,
              &val);
      v12->pData = (char *)v14;
      if ( !v14 )
      {
LABEL_12:
        Scaleform::HeapPT::Bookkeeper::Free(v7->pBookkeeper, v12, v12->SelfSize);
        goto LABEL_15;
      }
      v15 = 4096i64;
      if ( v5 > 0x1000 )
        v15 = v5;
      v25 = (~(v15 - 1) & (v14 + v15 - 1)) - v14;
      v12->Alignment = (unsigned __int8)Scaleform::Alg::UpperBit((unsigned int)val);
      v12->UseCount = v25 | 0x80000000i64;
      v16 = v22 - v25;
      v12->DataSize = v22 - v25;
      v12->pData = (char *)(v14 + v25);
      v17 = Scaleform::HeapPT::PageTable::MapRange(Scaleform::HeapPT::GlobalPageTable, (void *)(v14 + v25), v16);
      v18 = v12->DataSize;
      v19 = (unsigned __int64)v12->pData;
      if ( !v17 )
      {
        ((void (__fastcall *)(Scaleform::SysAllocPaged *, unsigned __int64, unsigned __int64, signed __int64))v7->pSysAlloc->vfptr[2].shutdownHeapEngine)(
          v7->pSysAlloc,
          v19 - v25,
          v25 + v18,
          1i64 << v12->Alignment);
        ((void (__fastcall *)(Scaleform::SysAllocPaged *, char *, unsigned __int64, unsigned __int64))v7->pSysAlloc->vfptr[2].shutdownHeapEngine)(
          v7->pSysAlloc,
          v12->pData,
          v6,
          v5);
        goto LABEL_12;
      }
      Scaleform::HeapPT::PageTable::SetSegmentInRange(Scaleform::HeapPT::GlobalPageTable, v19, v18, v12);
    }
    v12->pNext = v7->SegmentList.Root.pNext;
    v12->pPrev = (Scaleform::Heap::HeapSegment *)&v7->SegmentList;
    v7->SegmentList.Root.pNext->pPrev = v12;
    v7->SegmentList.Root.pNext = v12;
    v20 = LODWORD(v12->UseCount);
    LODWORD(v20) = v20 & 0x7FFFFFFF;
    v7->Footprint += v12->DataSize + v20;
    *v4 = 1;
    v13 = v12;
  }
LABEL_15:
  LeaveCriticalSection(v10);
  return v13;
}

// File Line: 317
// RVA: 0x9CDAD0
Scaleform::Heap::HeapSegment *__fastcall Scaleform::HeapPT::AllocEngine::allocSegmentBitSet(Scaleform::HeapPT::AllocEngine *this, unsigned __int64 size, unsigned __int64 alignSize, unsigned __int64 granularity, bool *limHandlerOK)
{
  unsigned __int64 v5; // rsi
  unsigned __int64 v6; // rbx
  unsigned __int64 v7; // rdi
  Scaleform::HeapPT::AllocEngine *v8; // rbp
  _RTL_CRITICAL_SECTION *v9; // r14
  unsigned __int64 v10; // r10
  unsigned __int64 v11; // rax
  unsigned __int64 v12; // r8
  Scaleform::Heap::HeapSegment *v13; // rax
  Scaleform::Heap::HeapSegment *v14; // rbx

  v5 = granularity;
  v6 = alignSize;
  v7 = size;
  v8 = this;
  v9 = &Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs;
  EnterCriticalSection(&Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs);
  v10 = v8->MinAlignMask + 1;
  if ( v6 > v10 )
    v10 = v6;
  v11 = 0i64;
  if ( v10 > 0x1000 )
    v11 = v10;
  v12 = v5 * (((~(v10 - 1) & (v10 + v11 + v7 - 1)) + v5 - 1) / v5);
  v13 = Scaleform::HeapPT::AllocEngine::allocSegment(
          v8,
          0xAu,
          v12,
          0x1000ui64,
          4 * ((((v12 + (1i64 << v8->Allocator.MinAlignShift) - 1) >> v8->Allocator.MinAlignShift) + 15) >> 4),
          limHandlerOK);
  v14 = v13;
  if ( v13 )
    Scaleform::HeapPT::AllocBitSet2::InitSegment(&v8->Allocator, v13);
  LeaveCriticalSection(v9);
  return v14;
}

// File Line: 341
// RVA: 0x9E37C0
void __fastcall Scaleform::HeapPT::AllocEngine::freeSegment(Scaleform::HeapPT::AllocEngine *this, Scaleform::Heap::HeapSegment *seg)
{
  unsigned __int64 v2; // rsi
  Scaleform::HeapPT::AllocEngine *v3; // rdi
  void *v4; // rcx
  Scaleform::Heap::HeapSegment *v5; // rbx
  unsigned __int64 v6; // rax
  Scaleform::SysAllocPaged *v7; // rcx
  signed __int64 v8; // r9
  unsigned __int64 v9; // rax
  signed __int64 v10; // r9

  v2 = seg->DataSize;
  v3 = this;
  v4 = this->pLimHandler;
  v5 = seg;
  if ( v4 )
    (*(void (__fastcall **)(void *, Scaleform::MemoryHeapPT *, unsigned __int64))(*(_QWORD *)v4 + 16i64))(
      v4,
      v3->pHeap,
      v2);
  v3->Footprint -= v2;
  Scaleform::HeapPT::PageTable::UnmapRange(Scaleform::HeapPT::GlobalPageTable, v5->pData, v2);
  v6 = v5->UseCount;
  v7 = v3->pSysAlloc;
  if ( v6 & 0x80000000 )
  {
    LODWORD(v6) = v6 & 0x7FFFFFFF;
    v8 = 1i64 << v5->Alignment;
    v3->Footprint -= v6;
    v9 = v5->UseCount;
    LODWORD(v9) = v9 & 0x7FFFFFFF;
    ((void (__fastcall *)(Scaleform::SysAllocPaged *, char *, unsigned __int64, signed __int64))v7->vfptr[2].shutdownHeapEngine)(
      v7,
      &v5->pData[-v9],
      v9 + v2,
      v8);
  }
  else
  {
    v10 = 4096i64;
    if ( (unsigned __int64)(1i64 << v5->Alignment) > 0x1000 )
      v10 = 1i64 << v5->Alignment;
    ((void (__fastcall *)(Scaleform::SysAllocPaged *, char *, unsigned __int64, signed __int64))v7->vfptr[1].shutdownHeapEngine)(
      v7,
      v5->pData,
      v2,
      v10);
  }
  v5->pPrev->pNext = v5->pNext;
  v5->pNext->pPrev = v5->pPrev;
  Scaleform::HeapPT::Bookkeeper::Free(v3->pBookkeeper, v5, v5->SelfSize);
}

// File Line: 371
// RVA: 0x9E3D40
void __fastcall Scaleform::HeapPT::AllocEngine::freeSegmentLocked(Scaleform::HeapPT::AllocEngine *this, Scaleform::Heap::HeapSegment *seg)
{
  Scaleform::Heap::HeapSegment *v2; // rbx
  Scaleform::HeapPT::AllocEngine *v3; // rdi
  _RTL_CRITICAL_SECTION *v4; // rsi

  v2 = seg;
  v3 = this;
  v4 = &Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs;
  EnterCriticalSection(&Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs);
  Scaleform::HeapPT::AllocEngine::freeSegment(v3, v2);
  LeaveCriticalSection(v4);
}

// File Line: 379
// RVA: 0x9E3C40
void __fastcall Scaleform::HeapPT::AllocEngine::freeSegmentBitSet(Scaleform::HeapPT::AllocEngine *this, Scaleform::Heap::HeapSegment *seg)
{
  Scaleform::Heap::HeapSegment *v2; // rdi
  Scaleform::HeapPT::AllocEngine *v3; // rbx
  _RTL_CRITICAL_SECTION *v4; // rsi
  Scaleform::Heap::HeapSegment *v5; // rdx

  v2 = seg;
  v3 = this;
  v4 = &Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs;
  EnterCriticalSection(&Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs);
  v5 = v3->pCachedBSeg;
  if ( v5 && v5 != v2 && !v5->UseCount )
  {
    Scaleform::HeapPT::FreeBin::Pull(&v3->Allocator.Bin, v5->pData);
    Scaleform::HeapPT::AllocEngine::freeSegment(v3, v3->pCachedBSeg);
  }
  v3->pCachedBSeg = 0i64;
  if ( v3->Footprint - (v3->Allocator.Bin.FreeBlocks << v3->Allocator.MinAlignShift) == v3->TinyFreeSpace
    || v2->DataSize > 4 * v3->Granularity )
  {
    if ( v3->Footprint >= v2->DataSize + v3->Reserve )
    {
      Scaleform::HeapPT::FreeBin::Pull(&v3->Allocator.Bin, v2->pData);
      Scaleform::HeapPT::AllocEngine::freeSegment(v3, v2);
    }
  }
  else
  {
    v3->pCachedBSeg = v2;
  }
  LeaveCriticalSection(v4);
}

// File Line: 408
// RVA: 0x9CDF50
char *__fastcall Scaleform::HeapPT::AllocEngine::allocSysDirect(Scaleform::HeapPT::AllocEngine *this, unsigned __int64 dataSize, unsigned __int64 alignSize)
{
  unsigned __int64 v3; // rsi
  unsigned __int64 v4; // rbx
  Scaleform::HeapPT::AllocEngine *v5; // rdi
  unsigned __int64 v6; // rax
  Scaleform::Heap::HeapSegment *v7; // rax
  char *result; // rax
  unsigned __int64 v9; // r14
  _RTL_CRITICAL_SECTION *v10; // rbx
  Scaleform::Heap::HeapSegment *v11; // rbp
  bool limHandlerOK; // [rsp+70h] [rbp+8h]
  Scaleform::LockSafe *v13; // [rsp+88h] [rbp+20h]

  v3 = alignSize;
  v4 = dataSize;
  v5 = this;
  limHandlerOK = 0;
  v6 = this->SysDirectThreshold;
  if ( v6 && dataSize >= v6 )
  {
    while ( 1 )
    {
      v7 = Scaleform::HeapPT::AllocEngine::allocSegmentNoGranulator(v5, v4, v3, &limHandlerOK);
      if ( v7 )
        break;
      if ( !limHandlerOK )
        goto LABEL_7;
    }
    v5->SysDirectSpace += v7->DataSize;
    result = v7->pData;
  }
  else
  {
LABEL_7:
    v9 = v5->SysGranularity * (((~(v3 - 1) & (v4 + v3 - 1)) + v5->SysGranularity - 1) / v5->SysGranularity);
    limHandlerOK = 0;
    while ( 1 )
    {
      v10 = &Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs;
      v13 = &Scaleform::HeapPT::GlobalRoot->RootLock;
      EnterCriticalSection(&Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs);
      v11 = Scaleform::HeapPT::AllocEngine::allocSegment(v5, 9u, v9, v3, 0i64, &limHandlerOK);
      LeaveCriticalSection(v10);
      if ( v11 )
        break;
      if ( !limHandlerOK )
        return 0i64;
    }
    v5->SysDirectSpace += v11->DataSize;
    result = v11->pData;
  }
  return result;
}

// File Line: 447
// RVA: 0x9D2110
unsigned __int64 __fastcall Scaleform::HeapPT::AllocEngine::calcDynaSize(Scaleform::HeapPT::AllocEngine *this)
{
  unsigned __int64 v1; // rbx
  unsigned __int64 result; // rax

  if ( !this->AllowDynaSize )
    return this->Granularity;
  v1 = this->Granularity;
  result = 1i64 << Scaleform::Alg::UpperBit(
                     v1
                   * ((((this->Footprint
                       - (this->Allocator.Bin.FreeBlocks << this->Allocator.MinAlignShift)
                       - this->TinyFreeSpace
                       + 16) >> 4)
                     + v1
                     - 1)
                    / v1));
  if ( result < v1 )
    result = v1;
  if ( result > 4 * v1 )
    result = 4 * v1;
  return result;
}

// File Line: 490
// RVA: 0x9CB6B0
char *__fastcall Scaleform::HeapPT::AllocEngine::allocBitSet(Scaleform::HeapPT::AllocEngine *this, unsigned __int64 size)
{
  unsigned __int64 v2; // rdi
  Scaleform::HeapPT::AllocEngine *v3; // rbx
  char *result; // rax
  unsigned __int64 v5; // rsi
  unsigned __int64 v6; // rax
  bool limHandlerOK; // [rsp+50h] [rbp+8h]
  Scaleform::Heap::HeapSegment *allocSeg; // [rsp+60h] [rbp+18h]

  v2 = size;
  v3 = this;
  limHandlerOK = 0;
  while ( 1 )
  {
    result = Scaleform::HeapPT::AllocBitSet2::Alloc(&v3->Allocator, v2, &allocSeg);
    if ( result )
      break;
    v5 = v3->MinAlignMask;
    v6 = Scaleform::HeapPT::AllocEngine::calcDynaSize(v3);
    if ( !Scaleform::HeapPT::AllocEngine::allocSegmentBitSet(v3, v2, v5 + 1, v6, &limHandlerOK) )
    {
      if ( !limHandlerOK )
        return 0i64;
      Scaleform::HeapPT::AllocEngine::allocSegmentBitSet(v3, v2, v5 + 1, v3->Granularity, &limHandlerOK);
    }
    if ( !limHandlerOK )
      return 0i64;
  }
  ++allocSeg->UseCount;
  return result;
}

// File Line: 511
// RVA: 0x9CB5F0
char *__fastcall Scaleform::HeapPT::AllocEngine::allocBitSet(Scaleform::HeapPT::AllocEngine *this, unsigned __int64 size, unsigned __int64 alignSize)
{
  unsigned __int64 v3; // rdi
  unsigned __int64 v4; // rsi
  Scaleform::HeapPT::AllocEngine *v5; // rbx
  char *result; // rax
  unsigned __int64 v7; // rax
  bool limHandlerOK; // [rsp+50h] [rbp+8h]
  Scaleform::Heap::HeapSegment *allocSeg; // [rsp+68h] [rbp+20h]

  v3 = alignSize;
  v4 = size;
  v5 = this;
  limHandlerOK = 0;
  while ( 1 )
  {
    result = Scaleform::HeapPT::AllocBitSet2::Alloc(&v5->Allocator, v4, v3, &allocSeg);
    if ( result )
      break;
    v7 = Scaleform::HeapPT::AllocEngine::calcDynaSize(v5);
    if ( !Scaleform::HeapPT::AllocEngine::allocSegmentBitSet(v5, v4, v3, v7, &limHandlerOK) )
    {
      if ( !limHandlerOK )
        return 0i64;
      Scaleform::HeapPT::AllocEngine::allocSegmentBitSet(v5, v4, v3, v5->Granularity, &limHandlerOK);
    }
    if ( !limHandlerOK )
      return 0i64;
  }
  ++allocSeg->UseCount;
  return result;
}

// File Line: 532
// RVA: 0x9CDE40
char *__fastcall Scaleform::HeapPT::AllocEngine::allocSegmentTiny(Scaleform::HeapPT::AllocEngine *this, unsigned int sizeIdx)
{
  unsigned int v2; // ebp
  Scaleform::HeapPT::AllocEngine *v3; // rdi
  _RTL_CRITICAL_SECTION *v4; // r14
  unsigned __int64 v5; // rcx
  unsigned __int64 v6; // rbx
  signed __int64 v7; // r8
  char *v8; // rsi
  Scaleform::Heap::HeapSegment *v9; // rax
  unsigned __int64 v10; // r9
  _QWORD *v11; // rcx
  signed __int64 i; // r8
  bool limHandlerOK; // [rsp+68h] [rbp+10h]

  v2 = sizeIdx;
  v3 = this;
  v4 = &Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs;
  EnterCriticalSection(&Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs);
  v5 = v3->MinAlignShift;
  v6 = (v2 + 1) << v5;
  v7 = 4096i64;
  if ( 4 * v6 > 0x1000 )
    v7 = 4i64 * ((v2 + 1) << v5);
  v8 = 0i64;
  v9 = Scaleform::HeapPT::AllocEngine::allocSegment(
         v3,
         v2,
         (v7 + 4095) & 0xFFFFFFFFFFFFF000ui64,
         0x1000ui64,
         0i64,
         &limHandlerOK);
  if ( v9 )
  {
    v10 = v9->DataSize / v6;
    v11 = v9->pData;
    for ( i = (signed __int64)&v3->TinyBlocks[v2]; v10; --v10 )
    {
      v11[2] = v9;
      *v11 = *(_QWORD *)i;
      v11[1] = i;
      *(_QWORD *)(*(_QWORD *)i + 8i64) = v11;
      *(_QWORD *)i = v11;
      v11 = (_QWORD *)((char *)v11 + v6);
    }
    v3->TinyFreeSpace += v9->DataSize;
    v8 = v9->pData;
  }
  LeaveCriticalSection(v4);
  return v8;
}

// File Line: 567
// RVA: 0x9EFDD0
void __fastcall Scaleform::HeapPT::AllocEngine::releaseSegmentTiny(Scaleform::HeapPT::AllocEngine *this, Scaleform::Heap::HeapSegment *seg)
{
  Scaleform::Heap::HeapSegment *v2; // rbx
  Scaleform::HeapPT::AllocEngine *v3; // rdi
  unsigned __int64 v4; // r10
  unsigned __int64 v5; // rax
  char *v6; // rdx
  unsigned __int64 i; // r9
  _QWORD *v8; // rcx
  __int64 v9; // rax
  void *v10; // rcx
  unsigned __int64 v11; // rsi
  unsigned __int64 v12; // rax
  Scaleform::SysAllocPaged *v13; // rcx
  signed __int64 v14; // r9
  unsigned __int64 v15; // rax
  signed __int64 v16; // r9

  v2 = seg;
  v3 = this;
  v4 = (seg->SegType + 1) << this->MinAlignShift;
  v5 = seg->DataSize / v4;
  v6 = seg->pData;
  for ( i = v5; i; --i )
  {
    *(_QWORD *)(*(_QWORD *)v6 + 8i64) = *((_QWORD *)v6 + 1);
    v8 = (_QWORD *)*((_QWORD *)v6 + 1);
    v9 = *(_QWORD *)v6;
    v6 += v4;
    *v8 = v9;
  }
  v10 = v3->pLimHandler;
  v3->TinyFreeSpace -= v2->DataSize;
  v11 = v2->DataSize;
  if ( v10 )
    (*(void (__fastcall **)(void *, Scaleform::MemoryHeapPT *, unsigned __int64, unsigned __int64))(*(_QWORD *)v10
                                                                                                  + 16i64))(
      v10,
      v3->pHeap,
      v2->DataSize,
      i);
  v3->Footprint -= v11;
  Scaleform::HeapPT::PageTable::UnmapRange(Scaleform::HeapPT::GlobalPageTable, v2->pData, v11);
  v12 = v2->UseCount;
  v13 = v3->pSysAlloc;
  if ( v12 & 0x80000000 )
  {
    LODWORD(v12) = v12 & 0x7FFFFFFF;
    v14 = 1i64 << v2->Alignment;
    v3->Footprint -= v12;
    v15 = v2->UseCount;
    LODWORD(v15) = v15 & 0x7FFFFFFF;
    ((void (__fastcall *)(Scaleform::SysAllocPaged *, char *, unsigned __int64, signed __int64))v13->vfptr[2].shutdownHeapEngine)(
      v13,
      &v2->pData[-v15],
      v15 + v11,
      v14);
  }
  else
  {
    v16 = 4096i64;
    if ( (unsigned __int64)(1i64 << v2->Alignment) > 0x1000 )
      v16 = 1i64 << v2->Alignment;
    ((void (__fastcall *)(Scaleform::SysAllocPaged *, char *, unsigned __int64, signed __int64))v13->vfptr[1].shutdownHeapEngine)(
      v13,
      v2->pData,
      v11,
      v16);
  }
  v2->pPrev->pNext = v2->pNext;
  v2->pNext->pPrev = v2->pPrev;
  Scaleform::HeapPT::Bookkeeper::Free(v3->pBookkeeper, v2, v2->SelfSize);
}

// File Line: 583
// RVA: 0x9E3DB0
void __fastcall Scaleform::HeapPT::AllocEngine::freeSegmentTiny(Scaleform::HeapPT::AllocEngine *this, Scaleform::Heap::HeapSegment *seg)
{
  Scaleform::Heap::HeapSegment *v2; // rdi
  Scaleform::HeapPT::AllocEngine *v3; // rbx
  _RTL_CRITICAL_SECTION *v4; // rsi
  Scaleform::Heap::HeapSegment *v5; // rdx

  v2 = seg;
  v3 = this;
  v4 = &Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs;
  EnterCriticalSection(&Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs);
  v5 = v3->pCachedTSeg;
  if ( v5 && v5 != v2 && !v5->UseCount )
    Scaleform::HeapPT::AllocEngine::releaseSegmentTiny(v3, v5);
  v3->pCachedTSeg = 0i64;
  if ( v3->Footprint - (v3->Allocator.Bin.FreeBlocks << v3->Allocator.MinAlignShift) == v3->TinyFreeSpace )
  {
    if ( v3->Footprint >= v2->DataSize + v3->Reserve )
      Scaleform::HeapPT::AllocEngine::releaseSegmentTiny(v3, v2);
  }
  else
  {
    v3->pCachedTSeg = v2;
  }
  LeaveCriticalSection(v4);
}

// File Line: 608
// RVA: 0x9CE080
char *__fastcall Scaleform::HeapPT::AllocEngine::allocTiny(Scaleform::HeapPT::AllocEngine *this, unsigned int sizeIdx)
{
  unsigned int v2; // edi
  Scaleform::HeapPT::AllocEngine *v3; // rbx
  Scaleform::HeapPT::AllocEngine *v4; // r9
  char *result; // rax

  v2 = sizeIdx;
  v3 = this;
  v4 = (Scaleform::HeapPT::AllocEngine *)*((_QWORD *)&this->pHeap + 2 * (sizeIdx + 103i64));
  if ( v4 != (Scaleform::HeapPT::AllocEngine *)&this->TinyBlocks[sizeIdx]
    || (result = Scaleform::HeapPT::AllocEngine::allocSegmentTiny(this, sizeIdx),
        (v4 = (Scaleform::HeapPT::AllocEngine *)result) != 0i64) )
  {
    v4->pHeap->pPrev = (Scaleform::MemoryHeap *)v4->pSysAlloc;
    v4->pSysAlloc->vfptr = (Scaleform::SysAllocBaseVtbl *)v4->pHeap;
    ++v4->pBookkeeper->Allocator.MinAlignShift;
    v3->TinyFreeSpace -= (v2 + 1) << v3->MinAlignShift;
    result = (char *)v4;
  }
  return result;
}

// File Line: 642
// RVA: 0x9EE870
void *__fastcall Scaleform::HeapPT::AllocEngine::reallocGeneral(Scaleform::HeapPT::AllocEngine *this, Scaleform::Heap::HeapSegment *seg, void *oldPtr, unsigned __int64 oldSize, unsigned __int64 newSize, unsigned __int64 alignShift)
{
  unsigned __int64 v6; // rdi
  Scaleform::HeapPT::AllocEngine *v7; // r14
  void *v8; // rbp
  Scaleform::Heap::HeapSegment *v9; // r15
  unsigned __int64 v10; // rsi
  void *result; // rax
  void *v12; // rbx

  v6 = newSize;
  v7 = this;
  v8 = oldPtr;
  v9 = seg;
  v10 = oldSize;
  result = Scaleform::HeapPT::AllocEngine::Alloc(this, newSize, 1i64 << alignShift);
  v12 = result;
  if ( result )
  {
    if ( v10 < newSize )
      v6 = v10;
    memmove(result, v8, v6);
    Scaleform::HeapPT::AllocEngine::Free(v7, v9, v8);
    result = v12;
  }
  return result;
}

// File Line: 657
// RVA: 0x9EF120
char *__fastcall Scaleform::HeapPT::AllocEngine::reallocSysDirect(Scaleform::HeapPT::AllocEngine *this, Scaleform::Heap::HeapSegment *seg, void *oldPtr, unsigned __int64 newSize)
{
  void *v4; // r15
  Scaleform::Heap::HeapSegment *v5; // rsi
  Scaleform::HeapPT::AllocEngine *v6; // rbx
  signed __int64 v8; // r13
  unsigned __int64 v9; // rdi
  unsigned __int64 v10; // rbp
  unsigned __int64 v11; // rcx
  _DWORD *v12; // rax
  char v13; // al
  _RTL_CRITICAL_SECTION *v14; // r14
  char *v15; // rdx
  char *v16; // rbx
  unsigned __int64 alignShift; // [rsp+28h] [rbp-40h]

  v4 = oldPtr;
  v5 = seg;
  v6 = this;
  if ( seg->UseCount & 0x80000000 )
    return (char *)Scaleform::HeapPT::AllocEngine::reallocGeneral(
                     this,
                     seg,
                     oldPtr,
                     seg->DataSize,
                     newSize,
                     seg->Alignment);
  v8 = 1i64 << seg->Alignment;
  v9 = this->SysGranularity * (((~(v8 - 1) & (v8 + newSize - 1)) + this->SysGranularity - 1) / this->SysGranularity);
  v10 = seg->DataSize;
  if ( v9 == v10 )
    return seg->pData;
  if ( v9 >= v10 || 2 * v9 >= this->Threshold )
  {
    if ( v9 <= v10
      || (v11 = this->Limit) == 0
      || v6->Footprint + v9 - v10 <= v11
      || (v12 = v6->pLimHandler) == 0i64
      || (++v12[2],
          v13 = (*(__int64 (__fastcall **)(void *, Scaleform::MemoryHeapPT *, unsigned __int64))(*(_QWORD *)v6->pLimHandler
                                                                                               + 8i64))(
                  v6->pLimHandler,
                  v6->pHeap,
                  v6->Footprint + v9 - v10 - v6->Limit),
          --*((_DWORD *)v6->pLimHandler + 2),
          v13)
      && v6->Footprint + v9 - v10 <= v6->Limit )
    {
      v14 = &Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs;
      EnterCriticalSection(&Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs);
      if ( v6->HasRealloc
        && ((unsigned __int8 (__fastcall *)(Scaleform::SysAllocPaged *, char *, unsigned __int64, unsigned __int64, signed __int64))v6->pSysAlloc->vfptr[2].__vecDelDtor)(
             v6->pSysAlloc,
             v5->pData,
             v10,
             v9,
             v8) )
      {
        v15 = v5->pData;
        if ( v9 <= v10 )
        {
          Scaleform::HeapPT::PageTable::RemapRange(Scaleform::HeapPT::GlobalPageTable, v15, v9, v10);
        }
        else if ( !Scaleform::HeapPT::PageTable::RemapRange(Scaleform::HeapPT::GlobalPageTable, v15, v9, v10) )
        {
          ((void (__fastcall *)(Scaleform::SysAllocPaged *, char *, unsigned __int64, unsigned __int64, signed __int64))v6->pSysAlloc->vfptr[2].__vecDelDtor)(
            v6->pSysAlloc,
            v5->pData,
            v9,
            v10,
            v8);
          v16 = 0i64;
LABEL_21:
          LeaveCriticalSection(v14);
          return v16;
        }
        v6->Footprint += v9 - v10;
        v6->SysDirectSpace += v9 - v10;
        v5->DataSize = v9;
        v16 = v5->pData;
        goto LABEL_21;
      }
      LeaveCriticalSection(v14);
    }
    alignShift = v5->Alignment;
    return (char *)Scaleform::HeapPT::AllocEngine::reallocGeneral(v6, v5, v4, v10, v9, alignShift);
  }
  alignShift = seg->Alignment;
  return (char *)Scaleform::HeapPT::AllocEngine::reallocGeneral(v6, v5, v4, v10, v9, alignShift);
}

// File Line: 752
// RVA: 0x956360
void *__fastcall Scaleform::HeapPT::AllocEngine::Alloc(Scaleform::HeapPT::AllocEngine *this, unsigned __int64 size)
{
  Scaleform::HeapPT::AllocEngine *v2; // rbx
  unsigned __int64 v3; // rdi
  unsigned __int64 v4; // rcx
  void *result; // rax

  v2 = this;
  if ( size < 0x20 )
    size = 32i64;
  v3 = ~this->MinAlignMask & (this->MinAlignMask + size);
  if ( !this->AllowTinyBlocks
    || (v4 = this->MinAlignShift, v3 > 8i64 << v4)
    || (result = Scaleform::HeapPT::AllocEngine::allocTiny(v2, (v3 - 1) >> v4)) == 0i64
    && (result = Scaleform::HeapPT::AllocEngine::allocTiny(v2, (v3 - 1) >> v2->MinAlignShift)) == 0i64 )
  {
    if ( v3 >= v2->Threshold )
      result = Scaleform::HeapPT::AllocEngine::allocSysDirect(v2, v3, 0x1000ui64);
    else
      result = Scaleform::HeapPT::AllocEngine::allocBitSet(v2, v3);
  }
  return result;
}

// File Line: 800
// RVA: 0x956260
void *__fastcall Scaleform::HeapPT::AllocEngine::Alloc(Scaleform::HeapPT::AllocEngine *this, unsigned __int64 size, unsigned __int64 alignSize)
{
  Scaleform::HeapPT::AllocEngine *v3; // rbx
  unsigned __int64 v4; // rcx
  unsigned __int64 v5; // rdi
  void *result; // rax
  unsigned __int64 v7; // rsi
  unsigned __int64 v8; // rcx

  v3 = this;
  v4 = this->MinAlignMask;
  v5 = alignSize;
  if ( alignSize - 1 <= v4 )
    return Scaleform::HeapPT::AllocEngine::Alloc(v3, size);
  if ( size < 0x20 )
    size = 32i64;
  if ( alignSize < v4 + 1 )
    v5 = v4 + 1;
  if ( size < v5 )
    size = v5;
  v7 = ~(v5 - 1) & (size + v5 - 1);
  if ( !v3->AllowTinyBlocks
    || (v8 = v3->MinAlignShift, v7 > 8i64 << v8)
    || (result = Scaleform::HeapPT::AllocEngine::allocTiny(v3, TinyPow2AllocType[(v7 - 1) >> v8])) == 0i64
    && (result = Scaleform::HeapPT::AllocEngine::allocTiny(v3, TinyPow2AllocType[(v7 - 1) >> v3->MinAlignShift])) == 0i64 )
  {
    if ( v7 >= v3->Threshold )
      result = Scaleform::HeapPT::AllocEngine::allocSysDirect(v3, v7, v5);
    else
      result = Scaleform::HeapPT::AllocEngine::allocBitSet(v3, v7, v5);
  }
  return result;
}

// File Line: 856
// RVA: 0x9A6220
void *__fastcall Scaleform::HeapPT::AllocEngine::Realloc(Scaleform::HeapPT::AllocEngine *this, Scaleform::Heap::HeapSegment *seg, void *oldPtr, unsigned __int64 newSize)
{
  Scaleform::Heap::HeapSegment *v4; // r15
  __int64 v5; // rdx
  void *v6; // r14
  Scaleform::HeapPT::AllocEngine *v7; // rbp
  unsigned __int64 v8; // rax
  unsigned __int64 v9; // rsi
  unsigned __int64 v10; // r9
  void *result; // rax
  unsigned __int64 v12; // rbx
  unsigned int v13; // eax
  unsigned __int64 oldSize; // [rsp+50h] [rbp+8h]

  v4 = seg;
  v5 = seg->SegType;
  v6 = oldPtr;
  v7 = this;
  if ( newSize < 0x20 )
    newSize = 32i64;
  v8 = this->MinAlignMask;
  oldSize = 0i64;
  v9 = ~v8 & (v8 + newSize);
  if ( (unsigned int)v5 > 7 )
  {
    if ( (_DWORD)v5 == 10 )
    {
      result = Scaleform::HeapPT::AllocBitSet2::ReallocInPlace(&this->Allocator, v4, oldPtr, v9, &oldSize);
      if ( !result )
      {
        v12 = v7->Allocator.MinAlignShift;
        v13 = Scaleform::Heap::BitSet2::GetAlignShift(
                (const unsigned int *)&v4[1],
                (signed __int64)((signed __int64)v6 - (unsigned __int64)v4->pData) >> v7->Allocator.MinAlignShift,
                oldSize >> v7->Allocator.MinAlignShift);
        result = Scaleform::HeapPT::AllocEngine::reallocGeneral(v7, v4, v6, oldSize, v9, v12 + v13);
      }
    }
    else
    {
      result = Scaleform::HeapPT::AllocEngine::reallocSysDirect(this, v4, oldPtr, v9);
    }
  }
  else
  {
    v10 = (unsigned int)(((_DWORD)v5 + 1) << this->MinAlignShift);
    if ( v9 > v10 )
      result = Scaleform::HeapPT::AllocEngine::reallocGeneral(
                 this,
                 v4,
                 oldPtr,
                 v10,
                 v9,
                 this->MinAlignShift + TinyPow2AllocType[v5]);
    else
      result = oldPtr;
  }
  return result;
}

// File Line: 898
// RVA: 0x97D8C0
void __fastcall Scaleform::HeapPT::AllocEngine::Free(Scaleform::HeapPT::AllocEngine *this, Scaleform::Heap::HeapSegment *seg, void *ptr)
{
  unsigned int v3; // eax
  Scaleform::Heap::HeapSegment *v4; // rbx
  Scaleform::HeapPT::AllocEngine *v5; // rdi
  Scaleform::List<Scaleform::HeapPT::AllocEngine::TinyBlock,Scaleform::HeapPT::AllocEngine::TinyBlock> *v6; // r9
  Scaleform::HeapPT::AllocEngine::TinyBlock *v7; // rax
  bool v8; // zf

  v3 = seg->SegType;
  v4 = seg;
  v5 = this;
  if ( v3 > 7 )
  {
    if ( v3 == 10 )
    {
      Scaleform::HeapPT::AllocBitSet2::Free(&this->Allocator, seg, ptr);
      v8 = v4->UseCount-- == 1;
      if ( v8 )
        Scaleform::HeapPT::AllocEngine::freeSegmentBitSet(v5, v4);
    }
    else
    {
      this->SysDirectSpace -= seg->DataSize;
      Scaleform::HeapPT::AllocEngine::freeSegmentLocked(this, seg);
    }
  }
  else
  {
    *((_QWORD *)ptr + 2) = seg;
    v6 = &this->TinyBlocks[seg->SegType];
    v7 = v6->Root.pNext;
    *(_QWORD *)ptr = v6;
    *((_QWORD *)ptr + 1) = v7;
    v6->Root.pNext->pPrev = (Scaleform::HeapPT::AllocEngine::TinyBlock *)ptr;
    v6->Root.pNext = (Scaleform::HeapPT::AllocEngine::TinyBlock *)ptr;
    this->TinyFreeSpace += (seg->SegType + 1) << this->MinAlignShift;
    v8 = seg->UseCount-- == 1;
    if ( v8 )
      Scaleform::HeapPT::AllocEngine::freeSegmentTiny(this, seg);
  }
}

// File Line: 976
// RVA: 0x9A7E10
void __fastcall Scaleform::HeapPT::AllocEngine::ReleaseCachedMem(Scaleform::HeapPT::AllocEngine *this)
{
  Scaleform::Heap::HeapSegment *v1; // rdx
  Scaleform::HeapPT::AllocEngine *v2; // rbx
  Scaleform::Heap::HeapSegment *v3; // rdx

  v1 = this->pCachedBSeg;
  v2 = this;
  if ( v1 && !v1->UseCount )
  {
    Scaleform::HeapPT::FreeBin::Pull(&this->Allocator.Bin, v1->pData);
    Scaleform::HeapPT::AllocEngine::freeSegment(v2, v2->pCachedBSeg);
  }
  v3 = v2->pCachedTSeg;
  if ( v3 && !v3->UseCount )
    Scaleform::HeapPT::AllocEngine::freeSegmentTiny(v2, v3);
  v2->pCachedBSeg = 0i64;
  v2->pCachedTSeg = 0i64;
}

// File Line: 995
// RVA: 0x9C19A0
void __fastcall Scaleform::HeapPT::AllocEngine::VisitMem(Scaleform::HeapPT::AllocEngine *this, Scaleform::Heap::MemVisitor *visitor, unsigned int flags)
{
  unsigned int v3; // esi
  Scaleform::Heap::MemVisitor *v4; // rdi
  Scaleform::HeapPT::AllocEngine *v5; // r14
  unsigned __int64 v6; // rbp
  Scaleform::HeapPT::AllocLite *v7; // rcx
  Scaleform::HeapPT::DualTNode *v8; // rdx
  Scaleform::Heap::HeapSegment *i; // rbx
  unsigned int v10; // eax
  unsigned __int64 v11; // rdx
  signed __int64 v12; // rsi
  unsigned __int64 j; // rbx
  _QWORD cat[2]; // [rsp+20h] [rbp-68h]
  Scaleform::Heap::HeapSegment seg; // [rsp+30h] [rbp-58h]

  v3 = flags;
  v4 = visitor;
  v5 = this;
  if ( flags & 1 )
    ((void (*)(void))this->pSysAlloc->vfptr[4].initHeapEngine)();
  v6 = 0i64;
  if ( v3 & 2 )
  {
    v7 = (Scaleform::HeapPT::AllocLite *)Scaleform::HeapPT::GlobalPageTable->pStarter;
    seg.SelfSize = 0i64;
    *(_QWORD *)&seg.SegType = 16i64;
    v7 = (Scaleform::HeapPT::AllocLite *)((char *)v7 + 152);
    seg.UseCount = 0i64;
    seg.pHeap = 0i64;
    v8 = v7->SizeTree.Tree.Root;
    seg.DataSize = 0i64;
    seg.pData = 0i64;
    Scaleform::HeapPT::AllocLite::visitTree(v7, v8, &seg, v4, Cat_StarterFree);
  }
  if ( v3 & 4 )
    Scaleform::HeapPT::Bookkeeper::VisitMem(v5->pBookkeeper, v4, v3);
  if ( v3 & 0x10 )
  {
    for ( i = v5->SegmentList.Root.pNext; i != (Scaleform::Heap::HeapSegment *)&v5->SegmentList; i = i->pNext )
    {
      v10 = i->SegType;
      if ( v10 <= 7 )
      {
        LODWORD(cat[0]) = 9;
        v4->vfptr->Visit(v4, i, (unsigned __int64)i->pData, i->DataSize, (Scaleform::Heap::MemVisitor::Category)cat[0]);
        v11 = i->DataSize % ((i->SegType + 1) << v5->MinAlignShift);
        if ( v11 )
        {
          LODWORD(cat[0]) = 10;
          v4->vfptr->Visit(
            v4,
            i,
            (unsigned __int64)&i->pData[((i->SegType + 1) << v5->MinAlignShift)
                                      * (i->DataSize
                                       / ((i->SegType + 1) << v5->MinAlignShift))],
            v11,
            (Scaleform::Heap::MemVisitor::Category)cat[0]);
        }
      }
      else if ( v10 == 9 )
      {
        LODWORD(cat[0]) = 6;
        v4->vfptr->Visit(v4, i, (unsigned __int64)i->pData, i->DataSize, (Scaleform::Heap::MemVisitor::Category)cat[0]);
      }
      else if ( v10 == 10 )
      {
        LODWORD(cat[0]) = 7;
        v4->vfptr->Visit(v4, i, (unsigned __int64)i->pData, i->DataSize, (Scaleform::Heap::MemVisitor::Category)cat[0]);
      }
    }
    if ( v3 & 0x20 )
    {
      Scaleform::HeapPT::FreeBin::VisitMem(&v5->Allocator.Bin, v4, v5->Allocator.MinAlignShift, Cat_AllocBitSetFree);
      v12 = (signed __int64)v5->TinyBlocks;
      do
      {
        for ( j = *(_QWORD *)(v12 + 8); j != v12; j = *(_QWORD *)(j + 8) )
        {
          LODWORD(cat[0]) = 10;
          v4->vfptr->Visit(
            v4,
            *(Scaleform::Heap::HeapSegment **)(j + 16),
            j,
            (v6 + 1) << v5->MinAlignShift,
            (Scaleform::Heap::MemVisitor::Category)cat[0]);
        }
        ++v6;
        v12 += 16i64;
      }
      while ( v6 < 8 );
    }
  }
}

// File Line: 1076
// RVA: 0x9C1E60
void __fastcall Scaleform::HeapPT::AllocEngine::VisitSegments(Scaleform::HeapPT::AllocEngine *this, Scaleform::Heap::SegVisitor *visitor)
{
  Scaleform::Heap::HeapSegment *v2; // rbx
  Scaleform::Heap::HeapSegment *v3; // rbp
  Scaleform::Heap::SegVisitor *v4; // rdi
  Scaleform::HeapPT::AllocEngine *v5; // rsi

  v2 = this->SegmentList.Root.pNext;
  v3 = (Scaleform::Heap::HeapSegment *)&this->SegmentList;
  v4 = visitor;
  v5 = this;
  if ( v2 != (Scaleform::Heap::HeapSegment *)&this->SegmentList )
  {
    do
    {
      v4->vfptr->Visit(
        v4,
        5u,
        (Scaleform::MemoryHeap *)&v2->pHeap->vfptr,
        (unsigned __int64)v2->pData,
        (v2->DataSize + 4095) & 0xFFFFFFFFFFFFF000ui64);
      v2 = v2->pNext;
    }
    while ( v2 != v3 );
  }
  Scaleform::HeapPT::FreeBin::VisitUnused(&v5->Allocator.Bin, v4, v5->Allocator.MinAlignShift, 0x85u);
}

