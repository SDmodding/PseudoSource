// File Line: 28
// RVA: 0x9390F0
void __fastcall Scaleform::HeapPT::Bookkeeper::Bookkeeper(Scaleform::HeapPT::Bookkeeper *this, Scaleform::SysAllocPaged *sysAlloc, unsigned __int64 granularity)
{
  Scaleform::List<Scaleform::Heap::HeapSegment,Scaleform::Heap::HeapSegment> *v3; // rax
  Scaleform::HeapPT::Bookkeeper *v4; // rbx
  Scaleform::SysAllocPaged *v5; // rcx
  unsigned __int64 v6; // rcx
  __int64 v7; // [rsp+20h] [rbp-38h]
  __int64 v8; // [rsp+28h] [rbp-30h]
  __int128 v9; // [rsp+30h] [rbp-28h]
  __int64 v10; // [rsp+40h] [rbp-18h]
  __int64 v11; // [rsp+48h] [rbp-10h]

  this->pSysAlloc = sysAlloc;
  this->Granularity = granularity;
  v3 = &this->SegmentList;
  v3->Root.pPrev = (Scaleform::Heap::HeapSegment *)v3;
  v3->Root.pNext = (Scaleform::Heap::HeapSegment *)v3;
  this->Allocator.MinAlignShift = 5i64;
  this->Allocator.MinAlignMask = 31i64;
  v4 = this;
  this->Allocator.Bin.ListBin1.Mask = 0i64;
  memset(this->Allocator.Bin.ListBin1.Roots, 0, 0x200ui64);
  v4->Allocator.Bin.ListBin2.Mask = 0i64;
  memset(v4->Allocator.Bin.ListBin2.Roots, 0, 0x200ui64);
  v4->Allocator.Bin.TreeBin1.Mask = 0i64;
  memset(v4->Allocator.Bin.TreeBin1.Roots, 0, 0x200ui64);
  v4->Allocator.Bin.FreeBlocks = 0i64;
  v5 = v4->pSysAlloc;
  v4->Footprint = 0i64;
  v7 = 0i64;
  v8 = 0i64;
  v9 = 0ui64;
  v10 = 0i64;
  v11 = 0i64;
  v5->vfptr[1].__vecDelDtor((Scaleform::SysAllocBase *)&v5->vfptr, (unsigned int)&v7);
  v6 = v9;
  if ( (unsigned __int64)v9 < 0x1000 )
    v6 = 4096i64;
  v4->Granularity = v6 * ((v6 + v4->Granularity - 1) / v6);
}

// File Line: 50
// RVA: 0x9CD770
Scaleform::Heap::HeapSegment *__fastcall Scaleform::HeapPT::Bookkeeper::allocSegment(Scaleform::HeapPT::Bookkeeper *this, unsigned __int64 dataSize)
{
  Scaleform::HeapPT::Bookkeeper *v2; // rsi
  unsigned __int64 v3; // rdi
  __int64 v4; // rax
  Scaleform::Heap::HeapSegment *v5; // rbx
  unsigned __int64 v7; // rax
  Scaleform::Heap::HeapSegment *v8; // rax

  v2 = this;
  v3 = dataSize;
  v4 = ((__int64 (__fastcall *)(Scaleform::SysAllocPaged *, unsigned __int64, signed __int64))this->pSysAlloc->vfptr[1].initHeapEngine)(
         this->pSysAlloc,
         dataSize,
         4096i64);
  v5 = (Scaleform::Heap::HeapSegment *)v4;
  if ( !v4 )
    return 0i64;
  *(_QWORD *)(v4 + 16) = v3;
  *(_DWORD *)(v4 + 24) = 8;
  *(_DWORD *)(v4 + 28) = 12;
  *(_QWORD *)(v4 + 32) = 0i64;
  *(_QWORD *)(v4 + 40) = 0i64;
  *(_QWORD *)(v4 + 48) = 0i64;
  *(_QWORD *)(v4 + 56) = 0i64;
  if ( !Scaleform::HeapPT::PageTable::MapRange(Scaleform::HeapPT::GlobalPageTable, (void *)v4, v3) )
  {
    ((void (__fastcall *)(Scaleform::SysAllocPaged *, Scaleform::Heap::HeapSegment *, unsigned __int64, signed __int64))v2->pSysAlloc->vfptr[1].shutdownHeapEngine)(
      v2->pSysAlloc,
      v5,
      v3,
      4096i64);
    return 0i64;
  }
  Scaleform::HeapPT::PageTable::SetSegmentInRange(Scaleform::HeapPT::GlobalPageTable, (unsigned __int64)v5, v3, v5);
  v7 = (4 * ((((v3 + v2->Allocator.MinAlignMask) >> v2->Allocator.MinAlignShift) + 31) >> 5) + 95) & 0xFFFFFFFFFFFFFFE0ui64;
  v5->pData = (char *)v5 + v7;
  v5->DataSize = v3 - v7;
  v8 = v2->SegmentList.Root.pNext;
  v5->pPrev = (Scaleform::Heap::HeapSegment *)&v2->SegmentList;
  v5->pNext = v8;
  v2->SegmentList.Root.pNext->pPrev = v5;
  v2->SegmentList.Root.pNext = v5;
  Scaleform::HeapPT::AllocBitSet1::InitSegment(&v2->Allocator, v5);
  v2->Footprint += v5->SelfSize;
  return v5;
}

// File Line: 83
// RVA: 0x9E38B0
void __fastcall Scaleform::HeapPT::Bookkeeper::freeSegment(Scaleform::HeapPT::Bookkeeper *this, Scaleform::Heap::HeapSegment *seg)
{
  Scaleform::Heap::HeapSegment *v2; // rdi
  Scaleform::HeapPT::Bookkeeper *v3; // rbx
  Scaleform::SysAllocPaged *v4; // rcx

  v2 = seg;
  v3 = this;
  Scaleform::HeapPT::FreeBin::Pull(&this->Allocator.Bin, seg->pData);
  v2->pPrev->pNext = v2->pNext;
  v2->pNext->pPrev = v2->pPrev;
  Scaleform::HeapPT::PageTable::UnmapRange(Scaleform::HeapPT::GlobalPageTable, v2, v2->SelfSize);
  v4 = v3->pSysAlloc;
  v3->Footprint -= v2->SelfSize;
  ((void (__fastcall *)(Scaleform::SysAllocPaged *, Scaleform::Heap::HeapSegment *, unsigned __int64, signed __int64))v4->vfptr[1].shutdownHeapEngine)(
    v4,
    v2,
    v2->SelfSize,
    4096i64);
}

// File Line: 94
// RVA: 0x956740
char *__fastcall Scaleform::HeapPT::Bookkeeper::Alloc(Scaleform::HeapPT::Bookkeeper *this, unsigned __int64 size)
{
  Scaleform::HeapPT::AllocBitSet1 *v2; // rsi
  Scaleform::HeapPT::Bookkeeper *v3; // rdi
  unsigned __int64 v4; // rbx
  unsigned __int64 v5; // rbx
  char *result; // rax
  unsigned __int64 v7; // r8
  unsigned __int64 v8; // r9
  unsigned __int64 i; // rdx
  char *v10; // rdi
  Scaleform::Heap::HeapSegment *allocSeg; // [rsp+30h] [rbp+8h]

  v2 = &this->Allocator;
  v3 = this;
  v4 = size;
  if ( size < 0x20 )
    v4 = 32i64;
  v5 = ~this->Allocator.MinAlignMask & (this->Allocator.MinAlignMask + v4);
  result = Scaleform::HeapPT::AllocBitSet1::Alloc(v2, v5, &allocSeg);
  if ( result )
  {
    ++allocSeg->UseCount;
  }
  else
  {
    v7 = v3->Granularity;
    v8 = v2->MinAlignMask;
    for ( i = v7 * ((v5 + v7 - 1) / v7);
          i < v5 + ((4 * ((((v8 + i) >> v2->MinAlignShift) + 31) >> 5) + 95) & 0xFFFFFFFFFFFFFFE0ui64);
          i += v7 )
    {
      ;
    }
    result = (char *)Scaleform::HeapPT::Bookkeeper::allocSegment(v3, i);
    v10 = result;
    if ( result )
    {
      result = Scaleform::HeapPT::AllocBitSet1::Alloc(v2, v5, &allocSeg);
      ++*((_QWORD *)v10 + 4);
    }
  }
  return result;
}

// File Line: 133
// RVA: 0x97DBF0
void __fastcall Scaleform::HeapPT::Bookkeeper::Free(Scaleform::HeapPT::Bookkeeper *this, void *ptr, unsigned __int64 size)
{
  unsigned __int64 v3; // r10
  unsigned __int64 v4; // r8
  Scaleform::HeapPT::Bookkeeper *v5; // rdi
  Scaleform::HeapPT::HeapHeader<Scaleform::HeapPT::HeapHeader<Scaleform::HeapPT::HeapHeader<Scaleform::HeapPT::HeapHeader<Scaleform::HeapPT::HeapHeader1,256>,256>,4096>,4096> *v6; // rdx
  Scaleform::HeapPT::HeapHeader<Scaleform::HeapPT::HeapHeader<Scaleform::HeapPT::HeapHeader<Scaleform::HeapPT::HeapHeader1,256>,256>,4096> *v7; // rax
  Scaleform::HeapPT::HeapHeader<Scaleform::HeapPT::HeapHeader<Scaleform::HeapPT::HeapHeader1,256>,256> *v8; // rcx
  Scaleform::HeapPT::HeapHeader<Scaleform::HeapPT::HeapHeader1,256> *v9; // rdx
  Scaleform::Heap::HeapSegment **v10; // rbx
  Scaleform::Heap::HeapSegment *v11; // rbx
  bool v12; // zf

  v3 = size;
  v4 = (unsigned __int64)ptr;
  v5 = this;
  v6 = &Scaleform::HeapPT::GlobalPageTable->RootTable[(unsigned __int64)ptr >> 52];
  if ( v6
    && (v7 = &v6->pTable[(v4 >> 40) & 0xFFF]) != 0i64
    && (v8 = &v7->pTable[(v4 >> 28) & 0xFFF]) != 0i64
    && (v9 = &v8->pTable[(unsigned __int8)(v4 >> 20)]) != 0i64
    && (v10 = &v9->pTable[(unsigned __int8)(v4 >> 12)].pSegment) != 0i64 )
  {
    v11 = *v10;
  }
  else
  {
    v11 = 0i64;
  }
  if ( v3 < 0x20 )
    v3 = 32i64;
  Scaleform::HeapPT::AllocBitSet1::Free(
    &v5->Allocator,
    v11,
    (void *)v4,
    ~v5->Allocator.MinAlignMask & (v5->Allocator.MinAlignMask + v3));
  v12 = v11->UseCount-- == 1;
  if ( v12 )
    Scaleform::HeapPT::Bookkeeper::freeSegment(v5, v11);
}

// File Line: 149
// RVA: 0x9C1B90
void __fastcall Scaleform::HeapPT::Bookkeeper::VisitMem(Scaleform::HeapPT::Bookkeeper *this, Scaleform::Heap::MemVisitor *visitor, unsigned int flags)
{
  Scaleform::Heap::HeapSegment *v3; // rbx
  Scaleform::Heap::HeapSegment *v4; // rbp
  char v5; // r14
  Scaleform::Heap::MemVisitor *v6; // rdi
  Scaleform::HeapPT::Bookkeeper *v7; // rsi
  _QWORD v8[3]; // [rsp+20h] [rbp-18h]

  if ( flags & 4 )
  {
    v3 = this->SegmentList.Root.pNext;
    v4 = (Scaleform::Heap::HeapSegment *)&this->SegmentList;
    v5 = flags;
    v6 = visitor;
    v7 = this;
    if ( v3 != (Scaleform::Heap::HeapSegment *)&this->SegmentList )
    {
      do
      {
        LODWORD(v8[0]) = 4;
        v6->vfptr->Visit(
          v6,
          v3,
          (unsigned __int64)v3->pData,
          v3->DataSize,
          (Scaleform::Heap::MemVisitor::Category)v8[0]);
        v3 = v3->pNext;
      }
      while ( v3 != v4 );
    }
    if ( v5 & 8 )
      Scaleform::HeapPT::FreeBin::VisitMem(&v7->Allocator.Bin, v6, v7->Allocator.MinAlignShift, Cat_BookkeeperFree);
  }
}

// File Line: 168
// RVA: 0x9C1EF0
void __fastcall Scaleform::HeapPT::Bookkeeper::VisitSegments(Scaleform::HeapPT::Bookkeeper *this, Scaleform::Heap::SegVisitor *visitor)
{
  Scaleform::Heap::HeapSegment *v2; // rbx
  Scaleform::Heap::HeapSegment *v3; // rbp
  Scaleform::Heap::SegVisitor *v4; // rdi
  Scaleform::HeapPT::Bookkeeper *v5; // rsi

  v2 = this->SegmentList.Root.pNext;
  v3 = (Scaleform::Heap::HeapSegment *)&this->SegmentList;
  v4 = visitor;
  v5 = this;
  if ( v2 != (Scaleform::Heap::HeapSegment *)&this->SegmentList )
  {
    do
    {
      v4->vfptr->Visit(v4, 3u, 0i64, (unsigned __int64)v2, v2->SelfSize);
      v2 = v2->pNext;
    }
    while ( v2 != v3 );
  }
  Scaleform::HeapPT::FreeBin::VisitUnused(&v5->Allocator.Bin, v4, v5->Allocator.MinAlignShift, 0x83u);
}

