// File Line: 43
// RVA: 0x93D550
void __fastcall Scaleform::HeapPT::Granulator::Granulator(
        Scaleform::HeapPT::Granulator *this,
        Scaleform::SysAllocPaged *sysAlloc,
        unsigned __int64 minSize,
        unsigned __int64 granularity,
        unsigned __int64 hdrPageSize)
{
  unsigned __int8 v6; // al
  unsigned __int64 v7; // rcx
  unsigned __int64 v8; // rax
  Scaleform::SysAllocPaged *pSysAlloc; // rcx
  unsigned __int64 v10; // r8
  __int64 v11; // rcx
  unsigned __int64 v12; // rax
  unsigned __int64 v13; // rax
  unsigned __int64 v14; // [rsp+20h] [rbp-38h] BYREF
  __int64 v15; // [rsp+28h] [rbp-30h]
  unsigned __int64 v16; // [rsp+30h] [rbp-28h]
  __int64 v17; // [rsp+38h] [rbp-20h]
  __int64 v18; // [rsp+40h] [rbp-18h]
  _BOOL8 v19; // [rsp+48h] [rbp-10h]

  this->pSysAlloc = sysAlloc;
  this->Granularity = granularity;
  this->HdrPageSize = hdrPageSize;
  this->MinAlign = 0i64;
  this->MaxAlign = 0i64;
  this->HasRealloc = 0;
  this->HdrCapacity = (hdrPageSize - 64) >> 6;
  this->HdrList.Root.pPrev = (Scaleform::HeapPT::HdrPage *)&this->HdrList;
  this->HdrList.Root.pNext = (Scaleform::HeapPT::HdrPage *)&this->HdrList;
  this->FreeSeg.Root.AddrChild[0] = &this->FreeSeg.Root;
  this->FreeSeg.Root.AddrChild[1] = &this->FreeSeg.Root;
  this->UsedSeg.Root = 0i64;
  this->Footprint = 0i64;
  v6 = Scaleform::Alg::UpperBit(minSize);
  v7 = v6;
  v8 = 1i64 << v6;
  this->Allocator.MinShift = v7;
  this->Allocator.MinSize = v8;
  this->Allocator.MinMask = v8 - 1;
  this->Allocator.SizeTree.Tree.Root = 0i64;
  this->Allocator.AddrTree.Root = 0i64;
  this->Allocator.FreeBlocks = 0i64;
  pSysAlloc = this->pSysAlloc;
  v14 = 0i64;
  v15 = 0i64;
  v16 = 0i64;
  v17 = 0i64;
  v18 = 0i64;
  v19 = 0i64;
  pSysAlloc->vfptr[1].__vecDelDtor(pSysAlloc, (unsigned int)&v14);
  v10 = v16;
  v11 = v15;
  if ( v16 < 0x1000 )
    v10 = 4096i64;
  v12 = v14;
  if ( !v14 )
    v12 = 1i64;
  this->MinAlign = v12;
  v13 = v11;
  if ( !v11 )
    v13 = 0x8000000000000000ui64;
  this->MaxAlign = v13;
  this->HasRealloc = v19;
  this->Granularity = v10 * ((v10 + this->Granularity - 1) / v10);
}

// File Line: 81
// RVA: 0x9CD880
bool __fastcall Scaleform::HeapPT::Granulator::allocSegment(
        Scaleform::HeapPT::Granulator *this,
        unsigned __int64 size,
        unsigned __int64 alignSize)
{
  unsigned __int64 MinAlign; // r10
  Scaleform::List2<Scaleform::HeapPT::TreeSeg,Scaleform::HeapPT::Granulator::SegListAccessor> *p_FreeSeg; // rbx
  unsigned __int64 HdrPageSize; // rbp
  unsigned __int64 MinSize; // rdi
  unsigned __int64 MaxAlign; // rax
  unsigned __int64 v9; // rcx
  unsigned __int64 v10; // r9
  unsigned __int64 v11; // r11
  __int64 v12; // r15
  unsigned __int64 v13; // r13
  __int64 v14; // rax
  int v15; // r12d
  unsigned __int64 v16; // r14
  Scaleform::HeapPT::HdrPage *v17; // rdi
  unsigned __int64 v18; // r8
  $BBF0D4F735761647AF238B3392AC2FF1 *v19; // rax
  Scaleform::HeapPT::TreeSeg *v20; // rcx
  Scaleform::HeapPT::TreeSeg *v21; // rbx
  char *v22; // rbp
  unsigned __int8 v23; // al
  Scaleform::RadixTree<Scaleform::HeapPT::TreeSeg,Scaleform::HeapPT::Granulator::SegTreeAccessor> *p_UsedSeg; // rcx
  char *v25; // rdx
  char *v26; // rax
  Scaleform::RadixTree<Scaleform::HeapPT::TreeSeg,Scaleform::HeapPT::Granulator::SegTreeAccessor> *v27; // r8
  Scaleform::HeapPT::TreeSeg *Root; // rax
  unsigned __int64 val; // [rsp+50h] [rbp+8h]

  MinAlign = alignSize;
  p_FreeSeg = &this->FreeSeg;
  if ( alignSize < this->MinAlign )
    MinAlign = this->MinAlign;
  if ( (Scaleform::List2<Scaleform::HeapPT::TreeSeg,Scaleform::HeapPT::Granulator::SegListAccessor> *)this->FreeSeg.Root.AddrChild[1] == &this->FreeSeg )
    HdrPageSize = this->HdrPageSize;
  else
    HdrPageSize = 0i64;
  MinSize = this->Allocator.MinSize;
  MaxAlign = this->MaxAlign;
  v9 = 0i64;
  v10 = 0i64;
  v11 = MinAlign;
  if ( MinAlign < MinSize )
    v11 = MinSize;
  v12 = ~(MinSize - 1);
  if ( v11 > MaxAlign )
    v11 = MaxAlign;
  if ( MinAlign > MaxAlign )
    v9 = MinAlign;
  val = v11;
  if ( v11 < MinSize )
    v10 = MinSize;
  if ( v9 <= v10 )
    v9 = 0i64;
  v13 = v12 & (v10
             + this->Granularity
             * (((~(MinAlign - 1) & (size + v9 + HdrPageSize + MinAlign - 1)) + this->Granularity - 1)
              / this->Granularity)
             + MinSize
             - 1);
  v14 = ((__int64 (__fastcall *)(Scaleform::SysAllocPaged *, unsigned __int64, unsigned __int64))this->pSysAlloc->vfptr[1].initHeapEngine)(
          this->pSysAlloc,
          v13,
          v11);
  v15 = v14;
  if ( v14 )
  {
    v16 = v12 & (v14 + v13);
    v17 = (Scaleform::HeapPT::HdrPage *)(v12 & (v14 + MinSize - 1));
    if ( HdrPageSize )
    {
      memset(v17, 0, HdrPageSize);
      v17->UseCount = 0i64;
      v18 = 0i64;
      if ( this->HdrCapacity )
      {
        v19 = &v17[1].8;
        do
        {
          v19[2].pNext = v17;
          v20 = p_FreeSeg->Root.AddrChild[0];
          v19[1].pNext = (Scaleform::HeapPT::HdrPage *)p_FreeSeg;
          v19->pNext = (Scaleform::HeapPT::HdrPage *)v20;
          p_FreeSeg->Root.AddrChild[0]->AddrChild[1] = (Scaleform::HeapPT::TreeSeg *)&v19[-1];
          ++v18;
          p_FreeSeg->Root.AddrChild[0] = (Scaleform::HeapPT::TreeSeg *)&v19[-1];
          v19 += 8;
        }
        while ( v18 < this->HdrCapacity );
      }
      v17->pPrev = this->HdrList.Root.pPrev;
      v17->pNext = (Scaleform::HeapPT::HdrPage *)&this->HdrList;
      this->HdrList.Root.pPrev->pNext = v17;
      this->HdrList.Root.pPrev = v17;
    }
    v21 = this->FreeSeg.Root.AddrChild[1];
    v22 = (char *)v17 + HdrPageSize;
    v21->AddrChild[0]->AddrChild[1] = v21->AddrChild[1];
    v21->AddrChild[1]->AddrChild[0] = v21->AddrChild[0];
    ++v21->Headers->UseCount;
    v21->Buffer = v22;
    v21->Size = v16 - (_QWORD)v22;
    v21->UseCount = 0i64;
    v23 = Scaleform::Alg::UpperBit(val);
    p_UsedSeg = &this->UsedSeg;
    v21->AddrChild[1] = 0i64;
    v21->AddrChild[0] = 0i64;
    v21->AddrParent = 0i64;
    v21->AlignShift = v23;
    v21->HeadBytes = (_DWORD)v17 - v15;
    if ( this->UsedSeg.Root )
    {
      p_UsedSeg = (Scaleform::RadixTree<Scaleform::HeapPT::TreeSeg,Scaleform::HeapPT::Granulator::SegTreeAccessor> *)p_UsedSeg->Root;
      v25 = v22;
      if ( (char *)p_UsedSeg[4].Root == v22 )
      {
LABEL_30:
        Scaleform::HeapPT::AllocLite::pushNode(
          &this->Allocator,
          (Scaleform::HeapPT::DualTNode *)v21->Buffer,
          v21,
          v21->Size >> this->Allocator.MinShift);
        this->Footprint += v13;
        LOBYTE(v14) = 1;
        return v14;
      }
      while ( 1 )
      {
        v26 = v25;
        v25 = (char *)(2i64 * (_QWORD)v25);
        v27 = &p_UsedSeg[(unsigned __int64)v26 >> 63];
        Root = v27[1].Root;
        if ( !Root )
          break;
        p_UsedSeg = (Scaleform::RadixTree<Scaleform::HeapPT::TreeSeg,Scaleform::HeapPT::Granulator::SegTreeAccessor> *)v27[1].Root;
        if ( Root->Buffer == v22 )
          goto LABEL_30;
      }
      v27[1].Root = v21;
    }
    else
    {
      p_UsedSeg->Root = v21;
    }
    v21->AddrParent = (Scaleform::HeapPT::TreeSeg *)p_UsedSeg;
    goto LABEL_30;
  }
  return v14;
}

// File Line: 177
// RVA: 0x9E3930
__int64 __fastcall Scaleform::HeapPT::Granulator::freeSegment(
        Scaleform::HeapPT::Granulator *this,
        Scaleform::HeapPT::TreeSeg *seg)
{
  Scaleform::HeapPT::HdrPage *Headers; // r14
  unsigned __int64 v3; // rbp
  unsigned __int8 v6; // r9
  Scaleform::HeapPT::HdrPage *Buffer; // r15
  __int64 HeadBytes; // rdx
  unsigned __int64 HdrPageSize; // r8
  __int64 v10; // rcx
  unsigned __int64 Size; // rbx
  unsigned __int64 v12; // rbx
  char *v13; // r11
  unsigned __int64 v14; // r9
  Scaleform::HeapPT::TreeSeg *Root; // rbx
  __int64 i; // rdx
  unsigned __int64 v17; // rax
  unsigned __int64 v18; // r8
  unsigned __int64 *p_UseCount; // rdx
  unsigned __int64 v20; // r8
  Scaleform::HeapPT::DualTNode *v21; // rsi
  __int64 v22; // rdx
  __int64 v23; // rcx
  unsigned __int64 v24; // r14
  __int64 v25; // r14
  Scaleform::HeapPT::DualTNode *pPrev; // rcx
  __int64 v27; // r14
  Scaleform::HeapPT::DualTNode *pNext; // rax
  Scaleform::HeapPT::DualTNode *Parent; // rdx
  Scaleform::HeapPT::DualTNode *v30; // rax
  Scaleform::HeapPT::DualTNode *v31; // rax
  char *v32; // r11

  Headers = seg->Headers;
  v3 = 0i64;
  v6 = 1;
  if ( (char *)Headers + this->HdrPageSize != seg->Buffer )
  {
    Scaleform::RadixTree<Scaleform::HeapMH::NodeMH,Scaleform::HeapMH::TreeNodeAccessor>::Remove(&this->UsedSeg, seg);
    seg->AddrChild[1] = this->FreeSeg.Root.AddrChild[1];
    seg->AddrChild[0] = &this->FreeSeg.Root;
    this->FreeSeg.Root.AddrChild[1]->AddrChild[0] = seg;
    this->FreeSeg.Root.AddrChild[1] = seg;
    --Headers->UseCount;
    Buffer = (Scaleform::HeapPT::HdrPage *)seg->Buffer;
    HeadBytes = seg->HeadBytes;
    HdrPageSize = 0i64;
    if ( (Scaleform::HeapPT::HdrPage *)((char *)seg->Headers + this->HdrPageSize) == Buffer )
      HdrPageSize = this->HdrPageSize;
    if ( (_DWORD)HeadBytes )
      v10 = this->Allocator.MinSize - HeadBytes;
    else
      v10 = 0i64;
    Size = seg->Size;
    this->Allocator.FreeBlocks -= (unsigned __int64)Buffer[1].pNext;
    v12 = HdrPageSize + v10 + HeadBytes + Size;
    Scaleform::RadixTreeMulti<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor>::Remove(
      &this->Allocator.SizeTree,
      (Scaleform::HeapPT::DualTNode *)Buffer);
    Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::Remove(
      &this->Allocator.AddrTree,
      (Scaleform::HeapPT::DualTNode *)Buffer);
    this->Footprint -= v12;
    v13 = seg->Buffer;
    v14 = 0i64;
    if ( (char *)seg->Headers + this->HdrPageSize == v13 )
      v14 = this->HdrPageSize;
    v6 = ((__int64 (__fastcall *)(Scaleform::SysAllocPaged *, char *, unsigned __int64, __int64))this->pSysAlloc->vfptr[1].shutdownHeapEngine)(
           this->pSysAlloc,
           &v13[-seg->HeadBytes - v14],
           v12,
           1i64 << LOBYTE(seg->AlignShift));
  }
  if ( Headers->UseCount != 1 )
    return v6;
  Root = this->UsedSeg.Root;
  for ( i = (__int64)Headers + this->HdrPageSize; Root; Root = Root->AddrChild[v17 >> 63] )
  {
    if ( Root->Buffer == (char *)Headers + this->HdrPageSize )
      break;
    v17 = i;
    i *= 2i64;
  }
  if ( Root->UseCount )
    return v6;
  Scaleform::RadixTree<Scaleform::HeapMH::NodeMH,Scaleform::HeapMH::TreeNodeAccessor>::Remove(&this->UsedSeg, Root);
  Root->AddrChild[1] = this->FreeSeg.Root.AddrChild[1];
  Root->AddrChild[0] = &this->FreeSeg.Root;
  this->FreeSeg.Root.AddrChild[1]->AddrChild[0] = Root;
  this->FreeSeg.Root.AddrChild[1] = Root;
  v18 = 0i64;
  if ( this->HdrCapacity )
  {
    p_UseCount = &Headers[1].UseCount;
    do
    {
      ++v18;
      *(_QWORD *)(*(p_UseCount - 1) + 16) = *p_UseCount;
      *(_QWORD *)(*p_UseCount + 8) = *(p_UseCount - 1);
      p_UseCount += 8;
    }
    while ( v18 < this->HdrCapacity );
  }
  v20 = 0i64;
  Headers->pPrev->pNext = Headers->pNext;
  Headers->pNext->Scaleform::ListNode<Scaleform::HeapPT::HdrPage>::$BBF0D4F735761647AF238B3392AC2FF1::pPrev = Headers->pPrev;
  v21 = (Scaleform::HeapPT::DualTNode *)Root->Buffer;
  v22 = Root->HeadBytes;
  if ( (Scaleform::HeapPT::DualTNode *)((char *)Root->Headers + this->HdrPageSize) == v21 )
    v20 = this->HdrPageSize;
  if ( (_DWORD)v22 )
    v23 = this->Allocator.MinSize - v22;
  else
    v23 = 0i64;
  v24 = Root->Size;
  this->Allocator.FreeBlocks -= v21->Size;
  v25 = v23 + v22 + v24;
  pPrev = v21->pPrev;
  v27 = v20 + v25;
  if ( v21->pPrev == v21 )
  {
    Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor>::Remove(
      &this->Allocator.SizeTree.Tree,
      v21);
  }
  else
  {
    pNext = v21->pNext;
    pNext->pPrev = pPrev;
    pPrev->pNext = pNext;
    Parent = v21->Parent;
    if ( Parent )
    {
      if ( v21 == this->Allocator.SizeTree.Tree.Root )
        this->Allocator.SizeTree.Tree.Root = pPrev;
      else
        Parent->Child[v21->Parent->Child[0] != v21] = pPrev;
      pPrev->Parent = Parent;
      v30 = v21->Child[0];
      if ( v30 )
      {
        pPrev->Child[0] = v30;
        v30->Parent = pPrev;
      }
      v31 = v21->Child[1];
      if ( v31 )
      {
        pPrev->Child[1] = v31;
        v31->Parent = pPrev;
      }
    }
    v21->Child[1] = 0i64;
    v21->Child[0] = 0i64;
    v21->Parent = 0i64;
  }
  Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::Remove(
    &this->Allocator.AddrTree,
    v21);
  this->Footprint -= v27;
  v32 = Root->Buffer;
  if ( (char *)Root->Headers + this->HdrPageSize == v32 )
    v3 = this->HdrPageSize;
  return ((__int64 (__fastcall *)(Scaleform::SysAllocPaged *, char *, __int64, __int64))this->pSysAlloc->vfptr[1].shutdownHeapEngine)(
           this->pSysAlloc,
           &v32[-Root->HeadBytes - v3],
           v27,
           1i64 << LOBYTE(Root->AlignShift));
}

// File Line: 238
// RVA: 0x956850
Scaleform::HeapPT::DualTNode *__fastcall Scaleform::HeapPT::Granulator::Alloc(
        Scaleform::HeapPT::Granulator *this,
        unsigned __int64 size,
        unsigned __int64 alignSize)
{
  Scaleform::HeapPT::DualTNode *result; // rax
  Scaleform::HeapPT::TreeSeg *allocSeg; // [rsp+30h] [rbp+8h] BYREF

  result = Scaleform::HeapPT::AllocLite::Alloc(&this->Allocator, size, alignSize, &allocSeg);
  if ( result )
    goto LABEL_7;
  if ( !Scaleform::HeapPT::Granulator::allocSegment(this, size, alignSize) )
    return 0i64;
  result = Scaleform::HeapPT::AllocLite::Alloc(&this->Allocator, size, alignSize, &allocSeg);
  if ( result )
    goto LABEL_7;
  if ( !Scaleform::HeapPT::Granulator::allocSegment(this, size, alignSize) )
    return 0i64;
  result = Scaleform::HeapPT::AllocLite::Alloc(&this->Allocator, size, alignSize, &allocSeg);
  if ( result )
LABEL_7:
    ++allocSeg->UseCount;
  return result;
}

// File Line: 280
// RVA: 0x97DCC0
bool __fastcall Scaleform::HeapPT::Granulator::Free(
        Scaleform::HeapPT::Granulator *this,
        char *ptr,
        unsigned __int64 size,
        unsigned __int64 alignSize)
{
  Scaleform::HeapPT::TreeSeg *LeEq; // rbp

  LeEq = Scaleform::RadixTree<Scaleform::HeapPT::TreeSeg,Scaleform::HeapPT::Granulator::SegTreeAccessor>::FindLeEq(
           &this->UsedSeg,
           ptr);
  Scaleform::HeapPT::AllocLite::Free(&this->Allocator, LeEq, (Scaleform::HeapPT::DualTNode *)ptr, size, alignSize);
  return LeEq->UseCount-- != 1 || Scaleform::HeapPT::Granulator::freeSegment(this, LeEq);
}

// File Line: 298
// RVA: 0x9A6E10
bool __fastcall Scaleform::HeapPT::Granulator::ReallocInPlace(
        Scaleform::HeapPT::Granulator *this,
        char *oldPtr,
        unsigned __int64 oldSize,
        unsigned __int64 newSize,
        unsigned __int64 alignSize)
{
  unsigned __int64 MinSize; // r13
  Scaleform::HeapPT::TreeSeg *LeEq; // rbp
  int v11; // eax
  int v12; // r15d
  bool result; // al
  char *Buffer; // rcx
  __int64 HeadBytes; // r10
  __int64 v16; // r9
  unsigned __int64 v17; // rdx
  unsigned __int64 HdrPageSize; // rax
  unsigned __int64 v19; // r14
  unsigned __int64 v20; // rax
  unsigned __int64 Granularity; // r11
  __int64 v22; // r8
  __int64 v23; // rsi
  unsigned __int64 v24; // r10
  unsigned __int64 v25; // rbx

  MinSize = alignSize;
  if ( alignSize < this->Allocator.MinSize )
    MinSize = this->Allocator.MinSize;
  LeEq = Scaleform::RadixTree<Scaleform::HeapPT::TreeSeg,Scaleform::HeapPT::Granulator::SegTreeAccessor>::FindLeEq(
           &this->UsedSeg,
           oldPtr);
  v11 = Scaleform::HeapPT::AllocLite::ReallocInPlace(&this->Allocator, LeEq, oldPtr, oldSize, newSize, MinSize);
  v12 = v11;
  if ( !this->HasRealloc )
    return v11 < 2;
  if ( !v11 )
    return 1;
  Buffer = LeEq->Buffer;
  HeadBytes = LeEq->HeadBytes;
  v16 = 0i64;
  v17 = (unsigned __int64)LeEq->Headers + this->HdrPageSize;
  HdrPageSize = 0i64;
  if ( (char *)v17 == Buffer )
    HdrPageSize = this->HdrPageSize;
  v19 = (unsigned __int64)&Buffer[-HeadBytes - HdrPageSize];
  v20 = 0i64;
  if ( (char *)v17 == Buffer )
    v20 = this->HdrPageSize;
  if ( (_DWORD)HeadBytes )
    v16 = this->Allocator.MinSize - HeadBytes;
  Granularity = this->Granularity;
  v22 = ~(MinSize - 1);
  v23 = v16 + v20 + HeadBytes + LeEq->Size;
  v24 = Granularity * (((v22 & (unsigned __int64)&oldPtr[oldSize - v19 - 1 + MinSize]) + Granularity - 1) / Granularity);
  v25 = Granularity * (((v22 & (unsigned __int64)&oldPtr[newSize - v19 - 1 + MinSize]) + Granularity - 1) / Granularity);
  if ( v12 == 1 )
  {
    if ( v25 < v24 )
    {
      Scaleform::HeapPT::AllocLite::TrimAt(&this->Allocator, LeEq, (char *)(v25 + v19));
      if ( ((unsigned __int8 (__fastcall *)(Scaleform::SysAllocPaged *, unsigned __int64, __int64, unsigned __int64, __int64))this->pSysAlloc->vfptr[2].__vecDelDtor)(
             this->pSysAlloc,
             v19,
             v23,
             v25,
             1i64 << LeEq->AlignShift) )
      {
        result = 1;
        this->Footprint += v25 - v23;
        return result;
      }
      Scaleform::HeapPT::AllocLite::Extend(&this->Allocator, LeEq, v23 - v25);
    }
    return 1;
  }
  if ( v12 != 3 )
    return 0;
  for ( ; v25 <= v24; v25 += Granularity )
    ;
  if ( !((unsigned __int8 (__fastcall *)(Scaleform::SysAllocPaged *, unsigned __int64, __int64, unsigned __int64, __int64))this->pSysAlloc->vfptr[2].__vecDelDtor)(
          this->pSysAlloc,
          v19,
          v23,
          v25,
          1i64 << LeEq->AlignShift) )
    return 0;
  this->Footprint += v25 - v23;
  Scaleform::HeapPT::AllocLite::Extend(&this->Allocator, LeEq, v25 - v23);
  Scaleform::HeapPT::AllocLite::ReallocInPlace(&this->Allocator, LeEq, oldPtr, oldSize, newSize, MinSize);
  return 1;
}

// File Line: 413
// RVA: 0x9FAEF0
void __fastcall Scaleform::HeapPT::Granulator::visitSegments(
        Scaleform::HeapPT::Granulator *this,
        Scaleform::HeapPT::TreeSeg *node,
        Scaleform::Heap::SegVisitor *visitor,
        unsigned int cat)
{
  Scaleform::HeapPT::TreeSeg *v6; // rbx
  char *Buffer; // r9
  unsigned __int64 HdrPageSize; // r8

  if ( node )
  {
    v6 = node;
    do
    {
      Scaleform::HeapPT::Granulator::visitSegments(this, v6->AddrChild[0], visitor, cat);
      Buffer = v6->Buffer;
      HdrPageSize = 0i64;
      if ( (char *)v6->Headers + this->HdrPageSize == Buffer )
        HdrPageSize = this->HdrPageSize;
      visitor->vfptr->Visit(
        visitor,
        cat,
        0i64,
        (unsigned __int64)&Buffer[-HdrPageSize + 4095] & 0xFFFFFFFFFFFFF000ui64,
        (HdrPageSize + v6->Size) & 0xFFFFFFFFFFFFF000ui64);
      v6 = v6->AddrChild[1];
    }
    while ( v6 );
  }
}

