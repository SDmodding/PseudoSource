// File Line: 65
// RVA: 0x938B10
void __fastcall Scaleform::HeapPT::AllocEngine::AllocEngine(
        Scaleform::HeapPT::AllocEngine *this,
        Scaleform::SysAllocPaged *sysAlloc,
        Scaleform::MemoryHeapPT *heap,
        char allocFlags,
        unsigned __int64 minAlignSize,
        unsigned __int64 granularity,
        unsigned __int64 reserve,
        unsigned __int64 threshold,
        unsigned __int64 limit)
{
  unsigned __int8 v11; // al
  unsigned __int64 v12; // rcx
  unsigned __int64 v13; // rcx
  unsigned __int64 v14; // rax
  unsigned __int64 v15; // rax
  Scaleform::SysAllocPaged *pSysAlloc; // rcx
  unsigned __int64 v17; // r8
  unsigned __int64 v18; // rcx
  unsigned __int64 v19; // rax
  __int64 v20; // rdx
  unsigned __int64 v21; // rax
  unsigned __int64 v22; // rdx
  unsigned __int64 v23; // rdx
  unsigned __int64 v24; // rdx
  __int64 v25[2]; // [rsp+30h] [rbp-38h] BYREF
  unsigned __int64 v26; // [rsp+40h] [rbp-28h]
  unsigned __int64 v27; // [rsp+48h] [rbp-20h]
  __int64 v28; // [rsp+50h] [rbp-18h]
  _BOOL8 v29; // [rsp+58h] [rbp-10h]
  bool limHandlerOK; // [rsp+88h] [rbp+20h] BYREF

  this->pHeap = heap;
  this->pSysAlloc = sysAlloc;
  this->pBookkeeper = &Scaleform::HeapPT::GlobalRoot->AllocBookkeeper;
  v11 = Scaleform::Alg::UpperBit(minAlignSize);
  this->MinAlignShift = v11;
  this->MinAlignMask = (1i64 << v11) - 1;
  this->Allocator.MinAlignShift = v11;
  this->Allocator.MinAlignMask = (1i64 << v11) - 1;
  this->Allocator.Bin.ListBin1.Mask = 0i64;
  memset(this->Allocator.Bin.ListBin1.Roots, 0, sizeof(this->Allocator.Bin.ListBin1.Roots));
  this->Allocator.Bin.ListBin2.Mask = 0i64;
  memset(this->Allocator.Bin.ListBin2.Roots, 0, sizeof(this->Allocator.Bin.ListBin2.Roots));
  this->Allocator.Bin.TreeBin1.Mask = 0i64;
  memset(this->Allocator.Bin.TreeBin1.Roots, 0, sizeof(this->Allocator.Bin.TreeBin1.Roots));
  this->Allocator.Bin.FreeBlocks = 0i64;
  this->SegmentList.Root.pPrev = (Scaleform::Heap::HeapSegment *)&this->SegmentList;
  this->SegmentList.Root.pNext = (Scaleform::Heap::HeapSegment *)&this->SegmentList;
  this->TinyBlocks[0].Root.pPrev = (Scaleform::HeapPT::AllocEngine::TinyBlock *)this->TinyBlocks;
  this->TinyBlocks[0].Root.pNext = (Scaleform::HeapPT::AllocEngine::TinyBlock *)this->TinyBlocks;
  this->TinyBlocks[1].Root.pNext = (Scaleform::HeapPT::AllocEngine::TinyBlock *)&this->TinyBlocks[1];
  this->TinyBlocks[1].Root.pPrev = (Scaleform::HeapPT::AllocEngine::TinyBlock *)&this->TinyBlocks[1];
  this->TinyBlocks[2].Root.pNext = (Scaleform::HeapPT::AllocEngine::TinyBlock *)&this->TinyBlocks[2];
  this->TinyBlocks[2].Root.pPrev = (Scaleform::HeapPT::AllocEngine::TinyBlock *)&this->TinyBlocks[2];
  this->TinyBlocks[3].Root.pNext = (Scaleform::HeapPT::AllocEngine::TinyBlock *)&this->TinyBlocks[3];
  this->TinyBlocks[3].Root.pPrev = (Scaleform::HeapPT::AllocEngine::TinyBlock *)&this->TinyBlocks[3];
  this->TinyBlocks[4].Root.pNext = (Scaleform::HeapPT::AllocEngine::TinyBlock *)&this->TinyBlocks[4];
  this->TinyBlocks[4].Root.pPrev = (Scaleform::HeapPT::AllocEngine::TinyBlock *)&this->TinyBlocks[4];
  this->TinyBlocks[5].Root.pNext = (Scaleform::HeapPT::AllocEngine::TinyBlock *)&this->TinyBlocks[5];
  this->TinyBlocks[5].Root.pPrev = (Scaleform::HeapPT::AllocEngine::TinyBlock *)&this->TinyBlocks[5];
  this->TinyBlocks[6].Root.pNext = (Scaleform::HeapPT::AllocEngine::TinyBlock *)&this->TinyBlocks[6];
  this->TinyBlocks[6].Root.pPrev = (Scaleform::HeapPT::AllocEngine::TinyBlock *)&this->TinyBlocks[6];
  this->TinyBlocks[7].Root.pNext = (Scaleform::HeapPT::AllocEngine::TinyBlock *)&this->TinyBlocks[7];
  v12 = granularity;
  this->TinyBlocks[7].Root.pPrev = (Scaleform::HeapPT::AllocEngine::TinyBlock *)&this->TinyBlocks[7];
  v13 = (v12 + 4095) & 0xFFFFFFFFFFFFF000ui64;
  this->AllowDynaSize = (allocFlags & 0x20) != 0;
  this->AllowTinyBlocks = (allocFlags & 0x10) != 0;
  v14 = reserve;
  *(_WORD *)&this->Valid = 0;
  this->SysGranularity = 4096i64;
  this->Granularity = v13;
  this->SysDirectThreshold = 0i64;
  this->Footprint = 0i64;
  this->TinyFreeSpace = 0i64;
  this->SysDirectSpace = 0i64;
  this->pCachedBSeg = 0i64;
  this->pCachedTSeg = 0i64;
  this->pLimHandler = 0i64;
  v15 = v13 * ((v13 + v14 - 1) / v13);
  pSysAlloc = this->pSysAlloc;
  this->Reserve = v15;
  this->Threshold = threshold;
  this->Limit = limit;
  v25[0] = 0i64;
  v25[1] = 0i64;
  v26 = 0i64;
  v27 = 0i64;
  v28 = 0i64;
  v29 = 0i64;
  pSysAlloc->vfptr[1].__vecDelDtor(pSysAlloc, (unsigned int)v25);
  v17 = v26;
  v18 = v27;
  this->HasRealloc = v29;
  v19 = this->Granularity;
  this->SysDirectThreshold = v18;
  if ( v17 < 0x1000 )
    v17 = 4096i64;
  v26 = v17;
  this->SysGranularity = v17;
  v20 = v28;
  v21 = v17 * ((v17 + v19 - 1) / v17);
  this->Granularity = v21;
  if ( v20 )
  {
    v22 = (v20 + 4095) & 0xFFFFFFFFFFFFF000ui64;
    v28 = v22;
    if ( v21 > v22 )
    {
      this->Granularity = v22;
      *(_WORD *)&this->AllowTinyBlocks = 0;
    }
  }
  v23 = this->Threshold;
  if ( v23 < 32 * v17 && v23 )
    this->Threshold = 32 * v17;
  if ( v18 )
  {
    if ( this->Threshold > v18 )
      this->Threshold = v18;
    if ( this->Threshold - 1 <= 0xFFE )
      this->Threshold = 4096i64;
    if ( this->Granularity > v18 )
      this->Granularity = (v18 + 4095) & 0xFFFFFFFFFFFFF000ui64;
    if ( v17 > v18 )
      this->SysGranularity = (v18 + 4095) & 0xFFFFFFFFFFFFF000ui64;
    if ( this->Reserve > v18 )
      this->Reserve = v18;
    this->AllowDynaSize = 0;
  }
  v24 = this->Reserve;
  if ( v24 )
    this->Valid = Scaleform::HeapPT::AllocEngine::allocSegmentBitSet(
                    this,
                    v24,
                    minAlignSize,
                    this->Granularity,
                    &limHandlerOK) != 0i64;
  else
    this->Valid = 1;
}

// File Line: 155
// RVA: 0x97E210
void __fastcall Scaleform::HeapPT::AllocEngine::FreeAll(Scaleform::HeapPT::AllocEngine *this)
{
  Scaleform::Heap::HeapSegment *pNext; // rax
  Scaleform::List<Scaleform::Heap::HeapSegment,Scaleform::Heap::HeapSegment> *i; // rdi

  pNext = this->SegmentList.Root.pNext;
  for ( i = &this->SegmentList; pNext != (Scaleform::Heap::HeapSegment *)i; pNext = this->SegmentList.Root.pNext )
    Scaleform::HeapPT::AllocEngine::freeSegment(this, pNext);
  this->Allocator.Bin.ListBin1.Mask = 0i64;
  memset(this->Allocator.Bin.ListBin1.Roots, 0, sizeof(this->Allocator.Bin.ListBin1.Roots));
  this->Allocator.Bin.ListBin2.Mask = 0i64;
  memset(this->Allocator.Bin.ListBin2.Roots, 0, sizeof(this->Allocator.Bin.ListBin2.Roots));
  this->Allocator.Bin.TreeBin1.Mask = 0i64;
  memset(this->Allocator.Bin.TreeBin1.Roots, 0, sizeof(this->Allocator.Bin.TreeBin1.Roots));
  this->Allocator.Bin.FreeBlocks = 0i64;
}

// File Line: 177
// RVA: 0x9CD590
Scaleform::Heap::HeapSegment *__fastcall Scaleform::HeapPT::AllocEngine::allocSegment(
        Scaleform::HeapPT::AllocEngine *this,
        unsigned int segType,
        unsigned __int64 dataSize,
        unsigned __int64 alignSize,
        unsigned __int64 bookkeepingSize,
        bool *limHandlerOK)
{
  unsigned __int64 Limit; // rcx
  Scaleform::LockSafe *p_RootLock; // rbx
  unsigned __int64 v12; // rsi
  char *v13; // rax
  Scaleform::Heap::HeapSegment *v14; // rbx
  unsigned __int64 v15; // rax
  char v16; // al
  unsigned __int64 pData; // rdx

  Limit = this->Limit;
  if ( Limit && dataSize + this->Footprint > Limit && this->pLimHandler )
  {
    p_RootLock = &Scaleform::HeapPT::GlobalRoot->RootLock;
    LeaveCriticalSection(&Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs);
    ++*((_DWORD *)this->pLimHandler + 2);
    *limHandlerOK = (*(__int64 (__fastcall **)(void *, Scaleform::MemoryHeapPT *, unsigned __int64))(*(_QWORD *)this->pLimHandler + 8i64))(
                      this->pLimHandler,
                      this->pHeap,
                      this->Footprint + dataSize - this->Limit);
    --*((_DWORD *)this->pLimHandler + 2);
    EnterCriticalSection(&p_RootLock->mLock.cs);
  }
  *limHandlerOK = 0;
  v12 = (bookkeepingSize + 95) & 0xFFFFFFFFFFFFFFE0ui64;
  v13 = Scaleform::HeapPT::Bookkeeper::Alloc(this->pBookkeeper, v12);
  v14 = (Scaleform::Heap::HeapSegment *)v13;
  if ( !v13 )
    return 0i64;
  *((_QWORD *)v13 + 2) = v12;
  *((_DWORD *)v13 + 6) = segType;
  *((_DWORD *)v13 + 7) = (unsigned __int8)Scaleform::Alg::UpperBit((unsigned int)alignSize);
  v14->UseCount = 0i64;
  v14->pHeap = this->pHeap;
  v14->DataSize = dataSize;
  v14->pData = 0i64;
  if ( !dataSize )
  {
LABEL_14:
    v14->pNext = this->SegmentList.Root.pNext;
    v14->pPrev = (Scaleform::Heap::HeapSegment *)&this->SegmentList;
    this->SegmentList.Root.pNext->pPrev = v14;
    this->SegmentList.Root.pNext = v14;
    this->Footprint += v14->DataSize;
    *limHandlerOK = 1;
    return v14;
  }
  if ( alignSize < 0x1000 )
    alignSize = 4096i64;
  v15 = ((__int64 (__fastcall *)(Scaleform::SysAllocPaged *, unsigned __int64, unsigned __int64))this->pSysAlloc->vfptr[1].initHeapEngine)(
          this->pSysAlloc,
          dataSize,
          alignSize);
  v14->pData = (char *)v15;
  if ( !v15 )
    goto LABEL_12;
  v16 = Scaleform::HeapPT::PageTable::MapRange(Scaleform::HeapPT::GlobalPageTable, v15, v14->DataSize);
  pData = (unsigned __int64)v14->pData;
  if ( v16 )
  {
    Scaleform::HeapPT::PageTable::SetSegmentInRange(Scaleform::HeapPT::GlobalPageTable, pData, v14->DataSize, v14);
    goto LABEL_14;
  }
  ((void (__fastcall *)(Scaleform::SysAllocPaged *, unsigned __int64, unsigned __int64, unsigned __int64, __int64))this->pSysAlloc->vfptr[1].shutdownHeapEngine)(
    this->pSysAlloc,
    pData,
    dataSize,
    alignSize,
    -2i64);
LABEL_12:
  Scaleform::HeapPT::Bookkeeper::Free(this->pBookkeeper, (char *)v14, v12);
  return 0i64;
}

// File Line: 241
// RVA: 0x9CDBE0
Scaleform::Heap::HeapSegment *__fastcall Scaleform::HeapPT::AllocEngine::allocSegmentNoGranulator(
        Scaleform::HeapPT::AllocEngine *this,
        unsigned __int64 dataSize,
        unsigned __int64 alignSize,
        bool *limHandlerOK)
{
  unsigned __int64 Limit; // rcx
  _DWORD *pLimHandler; // rax
  Scaleform::LockSafe *p_RootLock; // rbp
  char *v11; // rax
  char *v12; // rbx
  char *v13; // rsi
  __int64 v14; // r12
  unsigned __int64 v15; // rax
  unsigned __int64 v16; // r8
  char v17; // al
  unsigned __int64 v18; // r8
  unsigned __int64 v19; // rdx
  __int64 v20; // rax
  __int64 v22[11]; // [rsp+30h] [rbp-58h] BYREF
  unsigned __int64 v23; // [rsp+90h] [rbp+8h]
  unsigned __int64 val; // [rsp+A8h] [rbp+20h] BYREF

  v22[1] = -2i64;
  Limit = this->Limit;
  if ( Limit )
  {
    if ( dataSize + this->Footprint > Limit )
    {
      pLimHandler = this->pLimHandler;
      if ( pLimHandler )
      {
        ++pLimHandler[2];
        *limHandlerOK = (*(__int64 (__fastcall **)(void *, Scaleform::MemoryHeapPT *, unsigned __int64))(*(_QWORD *)this->pLimHandler + 8i64))(
                          this->pLimHandler,
                          this->pHeap,
                          this->Footprint + dataSize - this->Limit);
        --*((_DWORD *)this->pLimHandler + 2);
      }
    }
  }
  *limHandlerOK = 0;
  p_RootLock = &Scaleform::HeapPT::GlobalRoot->RootLock;
  v22[2] = (__int64)&Scaleform::HeapPT::GlobalRoot->RootLock;
  EnterCriticalSection(&Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs);
  v11 = Scaleform::HeapPT::Bookkeeper::Alloc(this->pBookkeeper, 0x40ui64);
  v12 = v11;
  v13 = 0i64;
  if ( v11 )
  {
    *((_QWORD *)v11 + 2) = 64i64;
    *((_QWORD *)v11 + 3) = 9i64;
    *((_QWORD *)v11 + 4) = 0i64;
    *((_QWORD *)v11 + 5) = this->pHeap;
    *((_QWORD *)v11 + 6) = 0i64;
    *((_QWORD *)v11 + 7) = 0i64;
    if ( dataSize )
    {
      v14 = ((__int64 (__fastcall *)(Scaleform::SysAllocPaged *, unsigned __int64, unsigned __int64, __int64 *, unsigned __int64 *))this->pSysAlloc->vfptr[2].initHeapEngine)(
              this->pSysAlloc,
              dataSize,
              alignSize,
              v22,
              &val);
      *((_QWORD *)v12 + 7) = v14;
      if ( !v14 )
      {
LABEL_12:
        Scaleform::HeapPT::Bookkeeper::Free(this->pBookkeeper, v12, *((_QWORD *)v12 + 2));
        goto LABEL_15;
      }
      v15 = 4096i64;
      if ( alignSize > 0x1000 )
        v15 = alignSize;
      v23 = (~(v15 - 1) & (v14 + v15 - 1)) - v14;
      *((_DWORD *)v12 + 7) = (unsigned __int8)Scaleform::Alg::UpperBit((unsigned int)val);
      *((_QWORD *)v12 + 4) = v23 | 0x80000000;
      v16 = v22[0] - v23;
      *((_QWORD *)v12 + 6) = v22[0] - v23;
      *((_QWORD *)v12 + 7) = v14 + v23;
      v17 = Scaleform::HeapPT::PageTable::MapRange(Scaleform::HeapPT::GlobalPageTable, v14 + v23, v16);
      v18 = *((_QWORD *)v12 + 6);
      v19 = *((_QWORD *)v12 + 7);
      if ( !v17 )
      {
        ((void (__fastcall *)(Scaleform::SysAllocPaged *, unsigned __int64, unsigned __int64, __int64))this->pSysAlloc->vfptr[2].shutdownHeapEngine)(
          this->pSysAlloc,
          v19 - v23,
          v23 + v18,
          1i64 << *((_DWORD *)v12 + 7));
        ((void (__fastcall *)(Scaleform::SysAllocPaged *, _QWORD, unsigned __int64, unsigned __int64))this->pSysAlloc->vfptr[2].shutdownHeapEngine)(
          this->pSysAlloc,
          *((_QWORD *)v12 + 7),
          dataSize,
          alignSize);
        goto LABEL_12;
      }
      Scaleform::HeapPT::PageTable::SetSegmentInRange(
        Scaleform::HeapPT::GlobalPageTable,
        v19,
        v18,
        (Scaleform::Heap::HeapSegment *)v12);
    }
    *((_QWORD *)v12 + 1) = this->SegmentList.Root.pNext;
    *(_QWORD *)v12 = &this->SegmentList;
    this->SegmentList.Root.pNext->pPrev = (Scaleform::Heap::HeapSegment *)v12;
    this->SegmentList.Root.pNext = (Scaleform::Heap::HeapSegment *)v12;
    v20 = *((unsigned int *)v12 + 8);
    LODWORD(v20) = v20 & 0x7FFFFFFF;
    this->Footprint += *((_QWORD *)v12 + 6) + v20;
    *limHandlerOK = 1;
    v13 = v12;
  }
LABEL_15:
  LeaveCriticalSection(&p_RootLock->mLock.cs);
  return (Scaleform::Heap::HeapSegment *)v13;
}

// File Line: 317
// RVA: 0x9CDAD0
Scaleform::Heap::HeapSegment *__fastcall Scaleform::HeapPT::AllocEngine::allocSegmentBitSet(
        Scaleform::HeapPT::AllocEngine *this,
        unsigned __int64 size,
        unsigned __int64 alignSize,
        unsigned __int64 granularity,
        bool *limHandlerOK)
{
  Scaleform::LockSafe *p_RootLock; // r14
  unsigned __int64 v10; // r10
  unsigned __int64 v11; // rax
  unsigned __int64 v12; // r8
  Scaleform::Heap::HeapSegment *v13; // rax
  Scaleform::Heap::HeapSegment *v14; // rbx

  p_RootLock = &Scaleform::HeapPT::GlobalRoot->RootLock;
  EnterCriticalSection(&Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs);
  v10 = this->MinAlignMask + 1;
  if ( alignSize > v10 )
    v10 = alignSize;
  v11 = 0i64;
  if ( v10 > 0x1000 )
    v11 = v10;
  v12 = granularity * (((~(v10 - 1) & (v10 + v11 + size - 1)) + granularity - 1) / granularity);
  v13 = Scaleform::HeapPT::AllocEngine::allocSegment(
          this,
          0xAu,
          v12,
          0x1000ui64,
          4 * ((((v12 + (1i64 << this->Allocator.MinAlignShift) - 1) >> this->Allocator.MinAlignShift) + 15) >> 4),
          limHandlerOK);
  v14 = v13;
  if ( v13 )
    Scaleform::HeapPT::AllocBitSet2::InitSegment(&this->Allocator, v13);
  LeaveCriticalSection(&p_RootLock->mLock.cs);
  return v14;
}

// File Line: 341
// RVA: 0x9E37C0
void __fastcall Scaleform::HeapPT::AllocEngine::freeSegment(
        Scaleform::HeapPT::AllocEngine *this,
        Scaleform::Heap::HeapSegment *seg)
{
  unsigned __int64 DataSize; // rsi
  void *pLimHandler; // rcx
  unsigned __int64 UseCount; // rax
  Scaleform::SysAllocPaged *pSysAlloc; // rcx
  __int64 v8; // r9
  unsigned __int64 v9; // rax
  __int64 v10; // r9

  DataSize = seg->DataSize;
  pLimHandler = this->pLimHandler;
  if ( pLimHandler )
    (*(void (__fastcall **)(void *, Scaleform::MemoryHeapPT *, unsigned __int64))(*(_QWORD *)pLimHandler + 16i64))(
      pLimHandler,
      this->pHeap,
      DataSize);
  this->Footprint -= DataSize;
  Scaleform::HeapPT::PageTable::UnmapRange(Scaleform::HeapPT::GlobalPageTable, (unsigned __int64)seg->pData, DataSize);
  UseCount = seg->UseCount;
  pSysAlloc = this->pSysAlloc;
  if ( (UseCount & 0x80000000) != 0 )
  {
    LODWORD(UseCount) = UseCount & 0x7FFFFFFF;
    v8 = 1i64 << seg->Alignment;
    this->Footprint -= UseCount;
    v9 = seg->UseCount;
    LODWORD(v9) = v9 & 0x7FFFFFFF;
    ((void (__fastcall *)(Scaleform::SysAllocPaged *, char *, unsigned __int64, __int64))pSysAlloc->vfptr[2].shutdownHeapEngine)(
      pSysAlloc,
      &seg->pData[-v9],
      v9 + DataSize,
      v8);
  }
  else
  {
    v10 = 4096i64;
    if ( (unsigned __int64)(1i64 << seg->Alignment) > 0x1000 )
      v10 = 1i64 << seg->Alignment;
    ((void (__fastcall *)(Scaleform::SysAllocPaged *, char *, unsigned __int64, __int64))pSysAlloc->vfptr[1].shutdownHeapEngine)(
      pSysAlloc,
      seg->pData,
      DataSize,
      v10);
  }
  seg->pPrev->pNext = seg->pNext;
  seg->pNext->Scaleform::ListNode<Scaleform::Heap::HeapSegment>::$4DACF0AC681F478D61B56964CCCDBEEC::pPrev = seg->pPrev;
  Scaleform::HeapPT::Bookkeeper::Free(this->pBookkeeper, (char *)seg, seg->SelfSize);
}

// File Line: 371
// RVA: 0x9E3D40
void __fastcall Scaleform::HeapPT::AllocEngine::freeSegmentLocked(
        Scaleform::HeapPT::AllocEngine *this,
        Scaleform::Heap::HeapSegment *seg)
{
  Scaleform::LockSafe *p_RootLock; // rsi

  p_RootLock = &Scaleform::HeapPT::GlobalRoot->RootLock;
  EnterCriticalSection(&Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs);
  Scaleform::HeapPT::AllocEngine::freeSegment(this, seg);
  LeaveCriticalSection(&p_RootLock->mLock.cs);
}

// File Line: 379
// RVA: 0x9E3C40
void __fastcall Scaleform::HeapPT::AllocEngine::freeSegmentBitSet(
        Scaleform::HeapPT::AllocEngine *this,
        Scaleform::Heap::HeapSegment *seg)
{
  Scaleform::LockSafe *p_RootLock; // rsi
  Scaleform::Heap::HeapSegment *pCachedBSeg; // rdx

  p_RootLock = &Scaleform::HeapPT::GlobalRoot->RootLock;
  EnterCriticalSection(&Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs);
  pCachedBSeg = this->pCachedBSeg;
  if ( pCachedBSeg && pCachedBSeg != seg && !pCachedBSeg->UseCount )
  {
    Scaleform::HeapPT::FreeBin::Pull(&this->Allocator.Bin, (Scaleform::HeapPT::BinTNode *)pCachedBSeg->pData);
    Scaleform::HeapPT::AllocEngine::freeSegment(this, this->pCachedBSeg);
  }
  this->pCachedBSeg = 0i64;
  if ( this->Footprint - (this->Allocator.Bin.FreeBlocks << this->Allocator.MinAlignShift) == this->TinyFreeSpace
    || seg->DataSize > 4 * this->Granularity )
  {
    if ( this->Footprint >= seg->DataSize + this->Reserve )
    {
      Scaleform::HeapPT::FreeBin::Pull(&this->Allocator.Bin, (Scaleform::HeapPT::BinTNode *)seg->pData);
      Scaleform::HeapPT::AllocEngine::freeSegment(this, seg);
    }
  }
  else
  {
    this->pCachedBSeg = seg;
  }
  LeaveCriticalSection(&p_RootLock->mLock.cs);
}

// File Line: 408
// RVA: 0x9CDF50
char *__fastcall Scaleform::HeapPT::AllocEngine::allocSysDirect(
        Scaleform::HeapPT::AllocEngine *this,
        unsigned __int64 dataSize,
        unsigned __int64 alignSize)
{
  unsigned __int64 SysDirectThreshold; // rax
  Scaleform::Heap::HeapSegment *v7; // rax
  unsigned __int64 v9; // r14
  Scaleform::LockSafe *p_RootLock; // rbx
  Scaleform::Heap::HeapSegment *v11; // rbp
  bool limHandlerOK; // [rsp+70h] [rbp+8h] BYREF
  Scaleform::LockSafe *v13; // [rsp+88h] [rbp+20h]

  limHandlerOK = 0;
  SysDirectThreshold = this->SysDirectThreshold;
  if ( SysDirectThreshold && dataSize >= SysDirectThreshold )
  {
    while ( 1 )
    {
      v7 = Scaleform::HeapPT::AllocEngine::allocSegmentNoGranulator(this, dataSize, alignSize, &limHandlerOK);
      if ( v7 )
        break;
      if ( !limHandlerOK )
        goto LABEL_7;
    }
    this->SysDirectSpace += v7->DataSize;
    return v7->pData;
  }
  else
  {
LABEL_7:
    v9 = this->SysGranularity
       * (((~(alignSize - 1) & (dataSize + alignSize - 1)) + this->SysGranularity - 1)
        / this->SysGranularity);
    limHandlerOK = 0;
    while ( 1 )
    {
      p_RootLock = &Scaleform::HeapPT::GlobalRoot->RootLock;
      v13 = &Scaleform::HeapPT::GlobalRoot->RootLock;
      EnterCriticalSection(&Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs);
      v11 = Scaleform::HeapPT::AllocEngine::allocSegment(this, 9u, v9, alignSize, 0i64, &limHandlerOK);
      LeaveCriticalSection(&p_RootLock->mLock.cs);
      if ( v11 )
        break;
      if ( !limHandlerOK )
        return 0i64;
    }
    this->SysDirectSpace += v11->DataSize;
    return v11->pData;
  }
}

// File Line: 447
// RVA: 0x9D2110
unsigned __int64 __fastcall Scaleform::HeapPT::AllocEngine::calcDynaSize(Scaleform::HeapPT::AllocEngine *this)
{
  unsigned __int64 Granularity; // rbx
  unsigned __int64 result; // rax

  if ( !this->AllowDynaSize )
    return this->Granularity;
  Granularity = this->Granularity;
  result = 1i64 << Scaleform::Alg::UpperBit(
                     Granularity
                   * ((((this->Footprint
                       - (this->Allocator.Bin.FreeBlocks << this->Allocator.MinAlignShift)
                       - this->TinyFreeSpace
                       + 16) >> 4)
                     + Granularity
                     - 1)
                    / Granularity));
  if ( result < Granularity )
    result = Granularity;
  if ( result > 4 * Granularity )
    return 4 * Granularity;
  return result;
}

// File Line: 490
// RVA: 0x9CB6B0
char *__fastcall Scaleform::HeapPT::AllocEngine::allocBitSet(
        Scaleform::HeapPT::AllocEngine *this,
        unsigned __int64 size)
{
  char *result; // rax
  unsigned __int64 MinAlignMask; // rsi
  unsigned __int64 v6; // rax
  bool limHandlerOK; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::Heap::HeapSegment *allocSeg; // [rsp+60h] [rbp+18h] BYREF

  limHandlerOK = 0;
  while ( 1 )
  {
    result = Scaleform::HeapPT::AllocBitSet2::Alloc(&this->Allocator, size, &allocSeg);
    if ( result )
      break;
    MinAlignMask = this->MinAlignMask;
    v6 = Scaleform::HeapPT::AllocEngine::calcDynaSize(this);
    if ( !Scaleform::HeapPT::AllocEngine::allocSegmentBitSet(this, size, MinAlignMask + 1, v6, &limHandlerOK) )
    {
      if ( !limHandlerOK )
        return 0i64;
      Scaleform::HeapPT::AllocEngine::allocSegmentBitSet(this, size, MinAlignMask + 1, this->Granularity, &limHandlerOK);
    }
    if ( !limHandlerOK )
      return 0i64;
  }
  ++allocSeg->UseCount;
  return result;
}

// File Line: 511
// RVA: 0x9CB5F0
char *__fastcall Scaleform::HeapPT::AllocEngine::allocBitSet(
        Scaleform::HeapPT::AllocEngine *this,
        unsigned __int64 size,
        unsigned __int64 alignSize)
{
  char *result; // rax
  unsigned __int64 v7; // rax
  bool limHandlerOK; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::Heap::HeapSegment *allocSeg; // [rsp+68h] [rbp+20h] BYREF

  limHandlerOK = 0;
  while ( 1 )
  {
    result = Scaleform::HeapPT::AllocBitSet2::Alloc(&this->Allocator, size, alignSize, &allocSeg);
    if ( result )
      break;
    v7 = Scaleform::HeapPT::AllocEngine::calcDynaSize(this);
    if ( !Scaleform::HeapPT::AllocEngine::allocSegmentBitSet(this, size, alignSize, v7, &limHandlerOK) )
    {
      if ( !limHandlerOK )
        return 0i64;
      Scaleform::HeapPT::AllocEngine::allocSegmentBitSet(this, size, alignSize, this->Granularity, &limHandlerOK);
    }
    if ( !limHandlerOK )
      return 0i64;
  }
  ++allocSeg->UseCount;
  return result;
}

// File Line: 532
// RVA: 0x9CDE40
char *__fastcall Scaleform::HeapPT::AllocEngine::allocSegmentTiny(
        Scaleform::HeapPT::AllocEngine *this,
        unsigned int sizeIdx)
{
  Scaleform::LockSafe *p_RootLock; // r14
  unsigned __int64 MinAlignShift; // rcx
  unsigned __int64 v6; // rbx
  __int64 v7; // r8
  char *v8; // rsi
  Scaleform::Heap::HeapSegment *v9; // rax
  unsigned __int64 v10; // r9
  Scaleform::HeapPT::AllocEngine::TinyBlock *pData; // rcx
  Scaleform::List<Scaleform::HeapPT::AllocEngine::TinyBlock,Scaleform::HeapPT::AllocEngine::TinyBlock> *i; // r8
  bool limHandlerOK; // [rsp+68h] [rbp+10h] BYREF

  p_RootLock = &Scaleform::HeapPT::GlobalRoot->RootLock;
  EnterCriticalSection(&Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs);
  MinAlignShift = this->MinAlignShift;
  v6 = (sizeIdx + 1) << MinAlignShift;
  v7 = 4096i64;
  if ( 4 * v6 > 0x1000 )
    v7 = 4i64 * ((sizeIdx + 1) << MinAlignShift);
  v8 = 0i64;
  v9 = Scaleform::HeapPT::AllocEngine::allocSegment(
         this,
         sizeIdx,
         (v7 + 4095) & 0xFFFFFFFFFFFFF000ui64,
         0x1000ui64,
         0i64,
         &limHandlerOK);
  if ( v9 )
  {
    v10 = v9->DataSize / v6;
    pData = (Scaleform::HeapPT::AllocEngine::TinyBlock *)v9->pData;
    for ( i = &this->TinyBlocks[sizeIdx]; v10; --v10 )
    {
      pData->pSegment = v9;
      pData->pPrev = i->Root.pPrev;
      pData->pNext = (Scaleform::HeapPT::AllocEngine::TinyBlock *)i;
      i->Root.pPrev->pNext = pData;
      i->Root.pPrev = pData;
      pData = (Scaleform::HeapPT::AllocEngine::TinyBlock *)((char *)pData + v6);
    }
    this->TinyFreeSpace += v9->DataSize;
    v8 = v9->pData;
  }
  LeaveCriticalSection(&p_RootLock->mLock.cs);
  return v8;
}

// File Line: 567
// RVA: 0x9EFDD0
void __fastcall Scaleform::HeapPT::AllocEngine::releaseSegmentTiny(
        Scaleform::HeapPT::AllocEngine *this,
        Scaleform::Heap::HeapSegment *seg)
{
  unsigned __int64 v4; // r10
  unsigned __int64 v5; // rax
  char *pData; // rdx
  unsigned __int64 i; // r9
  _QWORD *v8; // rcx
  __int64 v9; // rax
  void *pLimHandler; // rcx
  unsigned __int64 DataSize; // rsi
  unsigned __int64 UseCount; // rax
  Scaleform::SysAllocPaged *pSysAlloc; // rcx
  __int64 v14; // r9
  unsigned __int64 v15; // rax
  __int64 v16; // r9

  v4 = (seg->SegType + 1) << this->MinAlignShift;
  v5 = seg->DataSize / v4;
  pData = seg->pData;
  for ( i = v5; i; --i )
  {
    *(_QWORD *)(*(_QWORD *)pData + 8i64) = *((_QWORD *)pData + 1);
    v8 = (_QWORD *)*((_QWORD *)pData + 1);
    v9 = *(_QWORD *)pData;
    pData += v4;
    *v8 = v9;
  }
  pLimHandler = this->pLimHandler;
  this->TinyFreeSpace -= seg->DataSize;
  DataSize = seg->DataSize;
  if ( pLimHandler )
    (*(void (__fastcall **)(void *, Scaleform::MemoryHeapPT *, unsigned __int64, unsigned __int64))(*(_QWORD *)pLimHandler
                                                                                                  + 16i64))(
      pLimHandler,
      this->pHeap,
      seg->DataSize,
      i);
  this->Footprint -= DataSize;
  Scaleform::HeapPT::PageTable::UnmapRange(Scaleform::HeapPT::GlobalPageTable, (unsigned __int64)seg->pData, DataSize);
  UseCount = seg->UseCount;
  pSysAlloc = this->pSysAlloc;
  if ( (UseCount & 0x80000000) != 0 )
  {
    LODWORD(UseCount) = UseCount & 0x7FFFFFFF;
    v14 = 1i64 << seg->Alignment;
    this->Footprint -= UseCount;
    v15 = seg->UseCount;
    LODWORD(v15) = v15 & 0x7FFFFFFF;
    ((void (__fastcall *)(Scaleform::SysAllocPaged *, char *, unsigned __int64, __int64))pSysAlloc->vfptr[2].shutdownHeapEngine)(
      pSysAlloc,
      &seg->pData[-v15],
      v15 + DataSize,
      v14);
  }
  else
  {
    v16 = 4096i64;
    if ( (unsigned __int64)(1i64 << seg->Alignment) > 0x1000 )
      v16 = 1i64 << seg->Alignment;
    ((void (__fastcall *)(Scaleform::SysAllocPaged *, char *, unsigned __int64, __int64))pSysAlloc->vfptr[1].shutdownHeapEngine)(
      pSysAlloc,
      seg->pData,
      DataSize,
      v16);
  }
  seg->pPrev->pNext = seg->pNext;
  seg->pNext->Scaleform::ListNode<Scaleform::Heap::HeapSegment>::$4DACF0AC681F478D61B56964CCCDBEEC::pPrev = seg->pPrev;
  Scaleform::HeapPT::Bookkeeper::Free(this->pBookkeeper, (char *)seg, seg->SelfSize);
}

// File Line: 583
// RVA: 0x9E3DB0
void __fastcall Scaleform::HeapPT::AllocEngine::freeSegmentTiny(
        Scaleform::HeapPT::AllocEngine *this,
        Scaleform::Heap::HeapSegment *seg)
{
  Scaleform::LockSafe *p_RootLock; // rsi
  Scaleform::Heap::HeapSegment *pCachedTSeg; // rdx

  p_RootLock = &Scaleform::HeapPT::GlobalRoot->RootLock;
  EnterCriticalSection(&Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs);
  pCachedTSeg = this->pCachedTSeg;
  if ( pCachedTSeg && pCachedTSeg != seg && !pCachedTSeg->UseCount )
    Scaleform::HeapPT::AllocEngine::releaseSegmentTiny(this, pCachedTSeg);
  this->pCachedTSeg = 0i64;
  if ( this->Footprint - (this->Allocator.Bin.FreeBlocks << this->Allocator.MinAlignShift) == this->TinyFreeSpace )
  {
    if ( this->Footprint >= seg->DataSize + this->Reserve )
      Scaleform::HeapPT::AllocEngine::releaseSegmentTiny(this, seg);
  }
  else
  {
    this->pCachedTSeg = seg;
  }
  LeaveCriticalSection(&p_RootLock->mLock.cs);
}

// File Line: 608
// RVA: 0x9CE080
char *__fastcall Scaleform::HeapPT::AllocEngine::allocTiny(Scaleform::HeapPT::AllocEngine *this, unsigned int sizeIdx)
{
  Scaleform::HeapPT::AllocEngine::TinyBlock *pNext; // r9
  char *result; // rax

  pNext = this->TinyBlocks[sizeIdx].Root.pNext;
  if ( pNext != (Scaleform::HeapPT::AllocEngine::TinyBlock *)&this->TinyBlocks[sizeIdx]
    || (result = Scaleform::HeapPT::AllocEngine::allocSegmentTiny(this, sizeIdx),
        (pNext = (Scaleform::HeapPT::AllocEngine::TinyBlock *)result) != 0i64) )
  {
    pNext->pPrev->pNext = pNext->pNext;
    pNext->pNext->Scaleform::ListNode<Scaleform::HeapPT::AllocEngine::TinyBlock>::$C4113B55679D5D6727D2D1FFFC153E23::pPrev = pNext->pPrev;
    ++pNext->pSegment->UseCount;
    this->TinyFreeSpace -= (sizeIdx + 1) << this->MinAlignShift;
    return (char *)pNext;
  }
  return result;
}

// File Line: 642
// RVA: 0x9EE870
void *__fastcall Scaleform::HeapPT::AllocEngine::reallocGeneral(
        Scaleform::HeapPT::AllocEngine *this,
        Scaleform::Heap::HeapSegment *seg,
        void *oldPtr,
        size_t oldSize,
        unsigned __int64 newSize,
        unsigned __int64 alignShift)
{
  size_t v6; // rdi
  void *result; // rax
  void *v12; // rbx

  v6 = newSize;
  result = Scaleform::HeapPT::AllocEngine::Alloc(this, newSize, 1i64 << alignShift);
  v12 = result;
  if ( result )
  {
    if ( oldSize < newSize )
      v6 = oldSize;
    memmove(result, oldPtr, v6);
    Scaleform::HeapPT::AllocEngine::Free(this, seg, (char *)oldPtr);
    return v12;
  }
  return result;
}

// File Line: 657
// RVA: 0x9EF120
char *__fastcall Scaleform::HeapPT::AllocEngine::reallocSysDirect(
        Scaleform::HeapPT::AllocEngine *this,
        Scaleform::Heap::HeapSegment *seg,
        void *oldPtr,
        unsigned __int64 newSize)
{
  __int64 v8; // r13
  unsigned __int64 v9; // rdi
  unsigned __int64 DataSize; // rbp
  unsigned __int64 Limit; // rcx
  _DWORD *pLimHandler; // rax
  char v13; // al
  Scaleform::LockSafe *p_RootLock; // r14
  char *pData; // rdx
  char *v16; // rbx
  unsigned __int64 alignShift; // [rsp+28h] [rbp-40h]

  if ( (seg->UseCount & 0x80000000) != 0 )
    return (char *)Scaleform::HeapPT::AllocEngine::reallocGeneral(
                     this,
                     seg,
                     oldPtr,
                     seg->DataSize,
                     newSize,
                     seg->Alignment);
  v8 = 1i64 << seg->Alignment;
  v9 = this->SysGranularity * (((~(v8 - 1) & (v8 + newSize - 1)) + this->SysGranularity - 1) / this->SysGranularity);
  DataSize = seg->DataSize;
  if ( v9 == DataSize )
    return seg->pData;
  if ( v9 >= DataSize || 2 * v9 >= this->Threshold )
  {
    if ( v9 <= DataSize
      || (Limit = this->Limit) == 0
      || this->Footprint + v9 - DataSize <= Limit
      || (pLimHandler = this->pLimHandler) == 0i64
      || (++pLimHandler[2],
          v13 = (*(__int64 (__fastcall **)(void *, Scaleform::MemoryHeapPT *, unsigned __int64))(*(_QWORD *)this->pLimHandler
                                                                                               + 8i64))(
                  this->pLimHandler,
                  this->pHeap,
                  this->Footprint + v9 - DataSize - this->Limit),
          --*((_DWORD *)this->pLimHandler + 2),
          v13)
      && this->Footprint + v9 - DataSize <= this->Limit )
    {
      p_RootLock = &Scaleform::HeapPT::GlobalRoot->RootLock;
      EnterCriticalSection(&Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs);
      if ( this->HasRealloc
        && ((unsigned __int8 (__fastcall *)(Scaleform::SysAllocPaged *, char *, unsigned __int64, unsigned __int64, __int64))this->pSysAlloc->vfptr[2].__vecDelDtor)(
             this->pSysAlloc,
             seg->pData,
             DataSize,
             v9,
             v8) )
      {
        pData = seg->pData;
        if ( v9 <= DataSize )
        {
          Scaleform::HeapPT::PageTable::RemapRange(
            Scaleform::HeapPT::GlobalPageTable,
            (unsigned __int64)pData,
            v9,
            DataSize);
        }
        else if ( !Scaleform::HeapPT::PageTable::RemapRange(
                     Scaleform::HeapPT::GlobalPageTable,
                     (unsigned __int64)pData,
                     v9,
                     DataSize) )
        {
          ((void (__fastcall *)(Scaleform::SysAllocPaged *, char *, unsigned __int64, unsigned __int64, __int64))this->pSysAlloc->vfptr[2].__vecDelDtor)(
            this->pSysAlloc,
            seg->pData,
            v9,
            DataSize,
            v8);
          v16 = 0i64;
LABEL_21:
          LeaveCriticalSection(&p_RootLock->mLock.cs);
          return v16;
        }
        this->Footprint += v9 - DataSize;
        this->SysDirectSpace += v9 - DataSize;
        seg->DataSize = v9;
        v16 = seg->pData;
        goto LABEL_21;
      }
      LeaveCriticalSection(&p_RootLock->mLock.cs);
    }
    alignShift = seg->Alignment;
    return (char *)Scaleform::HeapPT::AllocEngine::reallocGeneral(this, seg, oldPtr, DataSize, v9, alignShift);
  }
  alignShift = seg->Alignment;
  return (char *)Scaleform::HeapPT::AllocEngine::reallocGeneral(this, seg, oldPtr, DataSize, v9, alignShift);
}

// File Line: 752
// RVA: 0x956360
void *__fastcall Scaleform::HeapPT::AllocEngine::Alloc(Scaleform::HeapPT::AllocEngine *this, unsigned __int64 size)
{
  unsigned __int64 v3; // rdi
  unsigned __int64 MinAlignShift; // rcx
  void *result; // rax

  if ( size < 0x20 )
    size = 32i64;
  v3 = ~this->MinAlignMask & (this->MinAlignMask + size);
  if ( !this->AllowTinyBlocks
    || (MinAlignShift = this->MinAlignShift, v3 > 8i64 << MinAlignShift)
    || (result = Scaleform::HeapPT::AllocEngine::allocTiny(this, (v3 - 1) >> MinAlignShift)) == 0i64
    && (result = Scaleform::HeapPT::AllocEngine::allocTiny(this, (v3 - 1) >> this->MinAlignShift)) == 0i64 )
  {
    if ( v3 >= this->Threshold )
      return Scaleform::HeapPT::AllocEngine::allocSysDirect(this, v3, 0x1000ui64);
    else
      return Scaleform::HeapPT::AllocEngine::allocBitSet(this, v3);
  }
  return result;
}

// File Line: 800
// RVA: 0x956260
void *__fastcall Scaleform::HeapPT::AllocEngine::Alloc(
        Scaleform::HeapPT::AllocEngine *this,
        unsigned __int64 size,
        unsigned __int64 alignSize)
{
  unsigned __int64 MinAlignMask; // rcx
  unsigned __int64 v5; // rdi
  void *result; // rax
  unsigned __int64 v7; // rsi
  unsigned __int64 MinAlignShift; // rcx

  MinAlignMask = this->MinAlignMask;
  v5 = alignSize;
  if ( alignSize - 1 <= MinAlignMask )
    return Scaleform::HeapPT::AllocEngine::Alloc(this, size);
  if ( size < 0x20 )
    size = 32i64;
  if ( alignSize < MinAlignMask + 1 )
    v5 = MinAlignMask + 1;
  if ( size < v5 )
    size = v5;
  v7 = ~(v5 - 1) & (size + v5 - 1);
  if ( !this->AllowTinyBlocks
    || (MinAlignShift = this->MinAlignShift, v7 > 8i64 << MinAlignShift)
    || (result = Scaleform::HeapPT::AllocEngine::allocTiny(this, TinyPow2AllocType[(v7 - 1) >> MinAlignShift])) == 0i64
    && (result = Scaleform::HeapPT::AllocEngine::allocTiny(this, TinyPow2AllocType[(v7 - 1) >> this->MinAlignShift])) == 0i64 )
  {
    if ( v7 >= this->Threshold )
      return Scaleform::HeapPT::AllocEngine::allocSysDirect(this, v7, v5);
    else
      return Scaleform::HeapPT::AllocEngine::allocBitSet(this, v7, v5);
  }
  return result;
}

// File Line: 856
// RVA: 0x9A6220
void *__fastcall Scaleform::HeapPT::AllocEngine::Realloc(
        Scaleform::HeapPT::AllocEngine *this,
        Scaleform::Heap::HeapSegment *seg,
        void *oldPtr,
        unsigned __int64 newSize)
{
  __int64 SegType; // rdx
  unsigned __int64 MinAlignMask; // rax
  unsigned __int64 v9; // rsi
  unsigned __int64 v10; // r9
  void *result; // rax
  unsigned __int64 MinAlignShift; // rbx
  unsigned int AlignShift; // eax
  unsigned __int64 oldSize; // [rsp+50h] [rbp+8h] BYREF

  SegType = seg->SegType;
  if ( newSize < 0x20 )
    newSize = 32i64;
  MinAlignMask = this->MinAlignMask;
  oldSize = 0i64;
  v9 = ~MinAlignMask & (MinAlignMask + newSize);
  if ( (unsigned int)SegType > 7 )
  {
    if ( (_DWORD)SegType == 10 )
    {
      result = Scaleform::HeapPT::AllocBitSet2::ReallocInPlace(&this->Allocator, seg, oldPtr, v9, &oldSize);
      if ( !result )
      {
        MinAlignShift = this->Allocator.MinAlignShift;
        AlignShift = Scaleform::Heap::BitSet2::GetAlignShift(
                       (const unsigned int *)&seg[1],
                       (signed __int64)((__int64)oldPtr - (unsigned __int64)seg->pData) >> MinAlignShift,
                       oldSize >> MinAlignShift);
        return Scaleform::HeapPT::AllocEngine::reallocGeneral(
                 this,
                 seg,
                 oldPtr,
                 oldSize,
                 v9,
                 MinAlignShift + AlignShift);
      }
    }
    else
    {
      return Scaleform::HeapPT::AllocEngine::reallocSysDirect(this, seg, oldPtr, v9);
    }
  }
  else
  {
    v10 = (unsigned int)(((_DWORD)SegType + 1) << this->MinAlignShift);
    if ( v9 > v10 )
      return Scaleform::HeapPT::AllocEngine::reallocGeneral(
               this,
               seg,
               oldPtr,
               v10,
               v9,
               this->MinAlignShift + TinyPow2AllocType[SegType]);
    else
      return oldPtr;
  }
  return result;
}

// File Line: 898
// RVA: 0x97D8C0
void __fastcall Scaleform::HeapPT::AllocEngine::Free(
        Scaleform::HeapPT::AllocEngine *this,
        Scaleform::Heap::HeapSegment *seg,
        char *ptr)
{
  unsigned int SegType; // eax
  Scaleform::List<Scaleform::HeapPT::AllocEngine::TinyBlock,Scaleform::HeapPT::AllocEngine::TinyBlock> *v6; // r9
  Scaleform::HeapPT::AllocEngine::TinyBlock *pNext; // rax
  bool v8; // zf

  SegType = seg->SegType;
  if ( SegType > 7 )
  {
    if ( SegType == 10 )
    {
      Scaleform::HeapPT::AllocBitSet2::Free(&this->Allocator, seg, ptr);
      v8 = seg->UseCount-- == 1;
      if ( v8 )
        Scaleform::HeapPT::AllocEngine::freeSegmentBitSet(this, seg);
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
    pNext = v6->Root.pNext;
    *(_QWORD *)ptr = v6;
    *((_QWORD *)ptr + 1) = pNext;
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
  Scaleform::Heap::HeapSegment *pCachedBSeg; // rdx
  Scaleform::Heap::HeapSegment *pCachedTSeg; // rdx

  pCachedBSeg = this->pCachedBSeg;
  if ( pCachedBSeg && !pCachedBSeg->UseCount )
  {
    Scaleform::HeapPT::FreeBin::Pull(&this->Allocator.Bin, (Scaleform::HeapPT::BinTNode *)pCachedBSeg->pData);
    Scaleform::HeapPT::AllocEngine::freeSegment(this, this->pCachedBSeg);
  }
  pCachedTSeg = this->pCachedTSeg;
  if ( pCachedTSeg && !pCachedTSeg->UseCount )
    Scaleform::HeapPT::AllocEngine::freeSegmentTiny(this, pCachedTSeg);
  this->pCachedBSeg = 0i64;
  this->pCachedTSeg = 0i64;
}

// File Line: 995
// RVA: 0x9C19A0
void __fastcall Scaleform::HeapPT::AllocEngine::VisitMem(
        Scaleform::HeapPT::AllocEngine *this,
        Scaleform::Heap::MemVisitor *visitor,
        unsigned int flags)
{
  unsigned __int64 v6; // rbp
  Scaleform::HeapPT::Starter *pStarter; // rcx
  Scaleform::Heap::HeapSegment *i; // rbx
  unsigned int SegType; // eax
  unsigned __int64 v10; // rdx
  Scaleform::List<Scaleform::HeapPT::AllocEngine::TinyBlock,Scaleform::HeapPT::AllocEngine::TinyBlock> *TinyBlocks; // rsi
  unsigned __int64 j; // rbx
  Scaleform::Heap::HeapSegment seg; // [rsp+30h] [rbp-58h] BYREF

  if ( (flags & 1) != 0 )
    ((void (__fastcall *)(Scaleform::SysAllocPaged *))this->pSysAlloc->vfptr[4].initHeapEngine)(this->pSysAlloc);
  v6 = 0i64;
  if ( (flags & 2) != 0 )
  {
    pStarter = Scaleform::HeapPT::GlobalPageTable->pStarter;
    seg.SelfSize = 0i64;
    *(_QWORD *)&seg.SegType = 16i64;
    memset(&seg.UseCount, 0, 32);
    Scaleform::HeapPT::AllocLite::visitTree(
      &pStarter->Allocator.Allocator,
      pStarter->Allocator.Allocator.SizeTree.Tree.Root,
      &seg,
      visitor,
      Cat_StarterFree);
  }
  if ( (flags & 4) != 0 )
    Scaleform::HeapPT::Bookkeeper::VisitMem(this->pBookkeeper, visitor, flags);
  if ( (flags & 0x10) != 0 )
  {
    for ( i = this->SegmentList.Root.pNext; i != (Scaleform::Heap::HeapSegment *)&this->SegmentList; i = i->pNext )
    {
      SegType = i->SegType;
      if ( SegType <= 7 )
      {
        visitor->vfptr->Visit(visitor, i, (unsigned __int64)i->pData, i->DataSize, Cat_AllocTiny);
        v10 = i->DataSize % ((i->SegType + 1) << this->MinAlignShift);
        if ( v10 )
          visitor->vfptr->Visit(
            visitor,
            i,
            (unsigned __int64)&i->pData[((i->SegType + 1) << this->MinAlignShift)
                                      * (i->DataSize
                                       / ((i->SegType + 1) << this->MinAlignShift))],
            v10,
            Cat_AllocTinyFree);
      }
      else if ( SegType == 9 )
      {
        visitor->vfptr->Visit(visitor, i, (unsigned __int64)i->pData, i->DataSize, Cat_SystemDirect);
      }
      else if ( SegType == 10 )
      {
        visitor->vfptr->Visit(visitor, i, (unsigned __int64)i->pData, i->DataSize, Cat_AllocBitSet);
      }
    }
    if ( (flags & 0x20) != 0 )
    {
      Scaleform::HeapPT::FreeBin::VisitMem(
        &this->Allocator.Bin,
        visitor,
        this->Allocator.MinAlignShift,
        Cat_AllocBitSetFree);
      TinyBlocks = this->TinyBlocks;
      do
      {
        for ( j = (unsigned __int64)TinyBlocks->Root.pNext;
              (Scaleform::List<Scaleform::HeapPT::AllocEngine::TinyBlock,Scaleform::HeapPT::AllocEngine::TinyBlock> *)j != TinyBlocks;
              j = *(_QWORD *)(j + 8) )
        {
          visitor->vfptr->Visit(
            visitor,
            *(Scaleform::Heap::HeapSegment **)(j + 16),
            j,
            (v6 + 1) << this->MinAlignShift,
            Cat_AllocTinyFree);
        }
        ++v6;
        ++TinyBlocks;
      }
      while ( v6 < 8 );
    }
  }
}

// File Line: 1076
// RVA: 0x9C1E60
void __fastcall Scaleform::HeapPT::AllocEngine::VisitSegments(
        Scaleform::HeapPT::AllocEngine *this,
        Scaleform::Heap::SegVisitor *visitor)
{
  Scaleform::Heap::HeapSegment *pNext; // rbx
  Scaleform::List<Scaleform::Heap::HeapSegment,Scaleform::Heap::HeapSegment> *i; // rbp

  pNext = this->SegmentList.Root.pNext;
  for ( i = &this->SegmentList; pNext != (Scaleform::Heap::HeapSegment *)i; pNext = pNext->pNext )
    visitor->vfptr->Visit(
      visitor,
      5u,
      pNext->pHeap,
      (unsigned __int64)pNext->pData,
      (pNext->DataSize + 4095) & 0xFFFFFFFFFFFFF000ui64);
  Scaleform::HeapPT::FreeBin::VisitUnused(&this->Allocator.Bin, visitor, this->Allocator.MinAlignShift, 0x85u);
}

