// File Line: 28
// RVA: 0x9390F0
void __fastcall Scaleform::HeapPT::Bookkeeper::Bookkeeper(
        Scaleform::HeapPT::Bookkeeper *this,
        Scaleform::SysAllocPaged *sysAlloc,
        unsigned __int64 granularity)
{
  Scaleform::SysAllocPaged *pSysAlloc; // rcx
  unsigned __int64 v5; // rcx
  __int64 v6[2]; // [rsp+20h] [rbp-38h] BYREF
  unsigned __int64 v7; // [rsp+30h] [rbp-28h]
  __int64 v8; // [rsp+38h] [rbp-20h]
  __int64 v9; // [rsp+40h] [rbp-18h]
  __int64 v10; // [rsp+48h] [rbp-10h]

  this->pSysAlloc = sysAlloc;
  this->Granularity = granularity;
  this->SegmentList.Root.pPrev = (Scaleform::Heap::HeapSegment *)&this->SegmentList;
  this->SegmentList.Root.pNext = (Scaleform::Heap::HeapSegment *)&this->SegmentList;
  this->Allocator.MinAlignShift = 5i64;
  this->Allocator.MinAlignMask = 31i64;
  this->Allocator.Bin.ListBin1.Mask = 0i64;
  memset(this->Allocator.Bin.ListBin1.Roots, 0, sizeof(this->Allocator.Bin.ListBin1.Roots));
  this->Allocator.Bin.ListBin2.Mask = 0i64;
  memset(this->Allocator.Bin.ListBin2.Roots, 0, sizeof(this->Allocator.Bin.ListBin2.Roots));
  this->Allocator.Bin.TreeBin1.Mask = 0i64;
  memset(this->Allocator.Bin.TreeBin1.Roots, 0, sizeof(this->Allocator.Bin.TreeBin1.Roots));
  this->Allocator.Bin.FreeBlocks = 0i64;
  pSysAlloc = this->pSysAlloc;
  this->Footprint = 0i64;
  v6[0] = 0i64;
  v6[1] = 0i64;
  v7 = 0i64;
  v8 = 0i64;
  v9 = 0i64;
  v10 = 0i64;
  pSysAlloc->vfptr[1].__vecDelDtor(pSysAlloc, (unsigned int)v6);
  v5 = v7;
  if ( v7 < 0x1000 )
    v5 = 4096i64;
  this->Granularity = v5 * ((v5 + this->Granularity - 1) / v5);
}

// File Line: 50
// RVA: 0x9CD770
Scaleform::Heap::HeapSegment *__fastcall Scaleform::HeapPT::Bookkeeper::allocSegment(
        Scaleform::HeapPT::Bookkeeper *this,
        unsigned __int64 dataSize)
{
  unsigned __int64 v4; // rax
  Scaleform::Heap::HeapSegment *v5; // rbx
  unsigned __int64 v7; // rax
  Scaleform::Heap::HeapSegment *pNext; // rax

  v4 = ((__int64 (__fastcall *)(Scaleform::SysAllocPaged *, unsigned __int64, __int64))this->pSysAlloc->vfptr[1].initHeapEngine)(
         this->pSysAlloc,
         dataSize,
         4096i64);
  v5 = (Scaleform::Heap::HeapSegment *)v4;
  if ( !v4 )
    return 0i64;
  *(_QWORD *)(v4 + 16) = dataSize;
  *(_DWORD *)(v4 + 24) = 8;
  *(_DWORD *)(v4 + 28) = 12;
  *(_QWORD *)(v4 + 32) = 0i64;
  *(_QWORD *)(v4 + 40) = 0i64;
  *(_QWORD *)(v4 + 48) = 0i64;
  *(_QWORD *)(v4 + 56) = 0i64;
  if ( !Scaleform::HeapPT::PageTable::MapRange(Scaleform::HeapPT::GlobalPageTable, v4, dataSize) )
  {
    ((void (__fastcall *)(Scaleform::SysAllocPaged *, Scaleform::Heap::HeapSegment *, unsigned __int64, __int64))this->pSysAlloc->vfptr[1].shutdownHeapEngine)(
      this->pSysAlloc,
      v5,
      dataSize,
      4096i64);
    return 0i64;
  }
  Scaleform::HeapPT::PageTable::SetSegmentInRange(
    Scaleform::HeapPT::GlobalPageTable,
    (unsigned __int64)v5,
    dataSize,
    v5);
  v7 = (4 * ((((dataSize + this->Allocator.MinAlignMask) >> this->Allocator.MinAlignShift) + 31) >> 5) + 95) & 0xFFFFFFFFFFFFFFE0ui64;
  v5->pData = (char *)v5 + v7;
  v5->DataSize = dataSize - v7;
  pNext = this->SegmentList.Root.pNext;
  v5->pPrev = (Scaleform::Heap::HeapSegment *)&this->SegmentList;
  v5->pNext = pNext;
  this->SegmentList.Root.pNext->pPrev = v5;
  this->SegmentList.Root.pNext = v5;
  Scaleform::HeapPT::AllocBitSet1::InitSegment(&this->Allocator, v5);
  this->Footprint += v5->SelfSize;
  return v5;
}

// File Line: 83
// RVA: 0x9E38B0
void __fastcall Scaleform::HeapPT::Bookkeeper::freeSegment(
        Scaleform::HeapPT::Bookkeeper *this,
        Scaleform::Heap::HeapSegment *seg)
{
  Scaleform::SysAllocPaged *pSysAlloc; // rcx

  Scaleform::HeapPT::FreeBin::Pull(&this->Allocator.Bin, (Scaleform::HeapPT::BinTNode *)seg->pData);
  seg->pPrev->pNext = seg->pNext;
  seg->pNext->Scaleform::ListNode<Scaleform::Heap::HeapSegment>::$4DACF0AC681F478D61B56964CCCDBEEC::pPrev = seg->pPrev;
  Scaleform::HeapPT::PageTable::UnmapRange(Scaleform::HeapPT::GlobalPageTable, (unsigned __int64)seg, seg->SelfSize);
  pSysAlloc = this->pSysAlloc;
  this->Footprint -= seg->SelfSize;
  ((void (__fastcall *)(Scaleform::SysAllocPaged *, Scaleform::Heap::HeapSegment *, unsigned __int64, __int64))pSysAlloc->vfptr[1].shutdownHeapEngine)(
    pSysAlloc,
    seg,
    seg->SelfSize,
    4096i64);
}

// File Line: 94
// RVA: 0x956740
char *__fastcall Scaleform::HeapPT::Bookkeeper::Alloc(Scaleform::HeapPT::Bookkeeper *this, unsigned __int64 size)
{
  Scaleform::HeapPT::AllocBitSet1 *p_Allocator; // rsi
  unsigned __int64 v4; // rbx
  unsigned __int64 v5; // rbx
  char *result; // rax
  unsigned __int64 Granularity; // r8
  unsigned __int64 MinAlignMask; // r9
  unsigned __int64 i; // rdx
  char *v10; // rdi
  Scaleform::Heap::HeapSegment *allocSeg; // [rsp+30h] [rbp+8h] BYREF

  p_Allocator = &this->Allocator;
  v4 = size;
  if ( size < 0x20 )
    v4 = 32i64;
  v5 = ~this->Allocator.MinAlignMask & (this->Allocator.MinAlignMask + v4);
  result = Scaleform::HeapPT::AllocBitSet1::Alloc(p_Allocator, v5, &allocSeg);
  if ( result )
  {
    ++allocSeg->UseCount;
  }
  else
  {
    Granularity = this->Granularity;
    MinAlignMask = p_Allocator->MinAlignMask;
    for ( i = Granularity * ((v5 + Granularity - 1) / Granularity);
          i < v5
            + ((4 * ((((MinAlignMask + i) >> p_Allocator->MinAlignShift) + 31) >> 5) + 95) & 0xFFFFFFFFFFFFFFE0ui64);
          i += Granularity )
    {
      ;
    }
    result = (char *)Scaleform::HeapPT::Bookkeeper::allocSegment(this, i);
    v10 = result;
    if ( result )
    {
      result = Scaleform::HeapPT::AllocBitSet1::Alloc(p_Allocator, v5, &allocSeg);
      ++*((_QWORD *)v10 + 4);
    }
  }
  return result;
}

// File Line: 133
// RVA: 0x97DBF0
void __fastcall Scaleform::HeapPT::Bookkeeper::Free(
        Scaleform::HeapPT::Bookkeeper *this,
        char *ptr,
        unsigned __int64 size)
{
  Scaleform::HeapPT::HeapHeader<Scaleform::HeapPT::HeapHeader<Scaleform::HeapPT::HeapHeader<Scaleform::HeapPT::HeapHeader<Scaleform::HeapPT::HeapHeader1,256>,256>,4096>,4096> *v6; // rdx
  Scaleform::HeapPT::HeapHeader<Scaleform::HeapPT::HeapHeader<Scaleform::HeapPT::HeapHeader<Scaleform::HeapPT::HeapHeader1,256>,256>,4096> *v7; // rax
  Scaleform::HeapPT::HeapHeader<Scaleform::HeapPT::HeapHeader<Scaleform::HeapPT::HeapHeader1,256>,256> *v8; // rcx
  Scaleform::HeapPT::HeapHeader<Scaleform::HeapPT::HeapHeader1,256> *v9; // rdx
  Scaleform::Heap::HeapSegment **p_pSegment; // rbx
  Scaleform::Heap::HeapSegment *v11; // rbx

  v6 = &Scaleform::HeapPT::GlobalPageTable->RootTable[(unsigned __int64)ptr >> 52];
  if ( v6
    && (v7 = &v6->pTable[((unsigned __int64)ptr >> 40) & 0xFFF]) != 0i64
    && (v8 = &v7->pTable[((unsigned __int64)ptr >> 28) & 0xFFF]) != 0i64
    && (v9 = &v8->pTable[(unsigned __int8)((unsigned __int64)ptr >> 20)]) != 0i64
    && (p_pSegment = &v9->pTable[(unsigned __int8)((unsigned __int64)ptr >> 12)].pSegment) != 0i64 )
  {
    v11 = *p_pSegment;
  }
  else
  {
    v11 = 0i64;
  }
  if ( size < 0x20 )
    size = 32i64;
  Scaleform::HeapPT::AllocBitSet1::Free(
    &this->Allocator,
    v11,
    ptr,
    ~this->Allocator.MinAlignMask & (this->Allocator.MinAlignMask + size));
  if ( v11->UseCount-- == 1 )
    Scaleform::HeapPT::Bookkeeper::freeSegment(this, v11);
}

// File Line: 149
// RVA: 0x9C1B90
void __fastcall Scaleform::HeapPT::Bookkeeper::VisitMem(
        Scaleform::HeapPT::Bookkeeper *this,
        Scaleform::Heap::MemVisitor *visitor,
        char flags)
{
  Scaleform::Heap::HeapSegment *pNext; // rbx
  Scaleform::List<Scaleform::Heap::HeapSegment,Scaleform::Heap::HeapSegment> *i; // rbp

  if ( (flags & 4) != 0 )
  {
    pNext = this->SegmentList.Root.pNext;
    for ( i = &this->SegmentList; pNext != (Scaleform::Heap::HeapSegment *)i; pNext = pNext->pNext )
      visitor->vfptr->Visit(visitor, pNext, (unsigned __int64)pNext->pData, pNext->DataSize, Cat_Bookkeeper);
    if ( (flags & 8) != 0 )
      Scaleform::HeapPT::FreeBin::VisitMem(
        &this->Allocator.Bin,
        visitor,
        this->Allocator.MinAlignShift,
        Cat_BookkeeperFree);
  }
}

// File Line: 168
// RVA: 0x9C1EF0
void __fastcall Scaleform::HeapPT::Bookkeeper::VisitSegments(
        Scaleform::HeapPT::Bookkeeper *this,
        Scaleform::Heap::SegVisitor *visitor)
{
  Scaleform::Heap::HeapSegment *pNext; // rbx
  Scaleform::List<Scaleform::Heap::HeapSegment,Scaleform::Heap::HeapSegment> *i; // rbp

  pNext = this->SegmentList.Root.pNext;
  for ( i = &this->SegmentList; pNext != (Scaleform::Heap::HeapSegment *)i; pNext = pNext->pNext )
    visitor->vfptr->Visit(visitor, 3u, 0i64, (unsigned __int64)pNext, pNext->SelfSize);
  Scaleform::HeapPT::FreeBin::VisitUnused(&this->Allocator.Bin, visitor, this->Allocator.MinAlignShift, 0x83u);
}

