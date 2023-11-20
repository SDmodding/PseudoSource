// File Line: 43
// RVA: 0x93D550
void __fastcall Scaleform::HeapPT::Granulator::Granulator(Scaleform::HeapPT::Granulator *this, Scaleform::SysAllocPaged *sysAlloc, unsigned __int64 minSize, unsigned __int64 granularity, unsigned __int64 hdrPageSize)
{
  Scaleform::HeapPT::Granulator *v5; // rbx
  Scaleform::List<Scaleform::HeapPT::HdrPage,Scaleform::HeapPT::HdrPage> *v6; // rax
  Scaleform::List2<Scaleform::HeapPT::TreeSeg,Scaleform::HeapPT::Granulator::SegListAccessor> *v7; // rax
  unsigned __int8 v8; // al
  unsigned __int64 v9; // rcx
  signed __int64 v10; // rax
  Scaleform::SysAllocPaged *v11; // rcx
  unsigned __int64 v12; // r8
  __int64 v13; // rcx
  signed __int64 v14; // rax
  signed __int64 v15; // rax
  __int64 v16; // [rsp+20h] [rbp-38h]
  __int64 v17; // [rsp+28h] [rbp-30h]
  __int128 v18; // [rsp+30h] [rbp-28h]
  __int64 v19; // [rsp+40h] [rbp-18h]
  _BOOL8 v20; // [rsp+48h] [rbp-10h]

  this->pSysAlloc = sysAlloc;
  this->Granularity = granularity;
  this->HdrPageSize = hdrPageSize;
  this->MinAlign = 0i64;
  this->MaxAlign = 0i64;
  this->HasRealloc = 0;
  v5 = this;
  this->HdrCapacity = (hdrPageSize - 64) >> 6;
  v6 = &this->HdrList;
  v6->Root.pPrev = (Scaleform::HeapPT::HdrPage *)v6;
  v6->Root.pNext = (Scaleform::HeapPT::HdrPage *)v6;
  v7 = &this->FreeSeg;
  v7->Root.AddrChild[0] = &v7->Root;
  v7->Root.AddrChild[1] = &v7->Root;
  this->UsedSeg.Root = 0i64;
  this->Footprint = 0i64;
  v8 = Scaleform::Alg::UpperBit(minSize);
  v9 = v8;
  v10 = 1i64 << v8;
  v5->Allocator.MinShift = v9;
  v5->Allocator.MinSize = v10;
  v5->Allocator.MinMask = v10 - 1;
  v5->Allocator.SizeTree.Tree.Root = 0i64;
  v5->Allocator.AddrTree.Root = 0i64;
  v5->Allocator.FreeBlocks = 0i64;
  v11 = v5->pSysAlloc;
  v16 = 0i64;
  v17 = 0i64;
  v18 = 0ui64;
  v19 = 0i64;
  v20 = 0i64;
  v11->vfptr[1].__vecDelDtor((Scaleform::SysAllocBase *)&v11->vfptr, (unsigned int)&v16);
  v12 = v18;
  v13 = v17;
  if ( (unsigned __int64)v18 < 0x1000 )
    v12 = 4096i64;
  v14 = v16;
  if ( !v16 )
    v14 = 1i64;
  v5->MinAlign = v14;
  v15 = v13;
  if ( !v13 )
    v15 = 0x8000000000000000i64;
  v5->MaxAlign = v15;
  v5->HasRealloc = v20;
  v5->Granularity = v12 * ((v12 + v5->Granularity - 1) / v12);
}

// File Line: 81
// RVA: 0x9CD880
bool __fastcall Scaleform::HeapPT::Granulator::allocSegment(Scaleform::HeapPT::Granulator *this, unsigned __int64 size, unsigned __int64 alignSize)
{
  unsigned __int64 v3; // r10
  Scaleform::List2<Scaleform::HeapPT::TreeSeg,Scaleform::HeapPT::Granulator::SegListAccessor> *v4; // rbx
  Scaleform::HeapPT::Granulator *v5; // rsi
  unsigned __int64 v6; // rbp
  unsigned __int64 v7; // rdi
  unsigned __int64 v8; // rax
  unsigned __int64 v9; // rcx
  unsigned __int64 v10; // r9
  unsigned __int64 v11; // r11
  signed __int64 v12; // r15
  unsigned __int64 v13; // r13
  __int64 v14; // rax
  int v15; // er12
  unsigned __int64 v16; // r14
  Scaleform::HeapPT::HdrPage *v17; // rdi
  unsigned __int64 v18; // r8
  $BBF0D4F735761647AF238B3392AC2FF1 *v19; // rax
  Scaleform::HeapPT::TreeSeg *v20; // rcx
  Scaleform::HeapPT::TreeSeg *v21; // rbx
  char *v22; // rbp
  unsigned __int8 v23; // al
  Scaleform::RadixTree<Scaleform::HeapPT::TreeSeg,Scaleform::HeapPT::Granulator::SegTreeAccessor> *v24; // rcx
  char *v25; // rdx
  unsigned __int64 v26; // rax
  signed __int64 v27; // r8
  Scaleform::HeapPT::TreeSeg *v28; // rax
  unsigned __int64 val; // [rsp+50h] [rbp+8h]

  v3 = alignSize;
  v4 = &this->FreeSeg;
  if ( alignSize < this->MinAlign )
    v3 = this->MinAlign;
  v5 = this;
  if ( (Scaleform::List2<Scaleform::HeapPT::TreeSeg,Scaleform::HeapPT::Granulator::SegListAccessor> *)this->FreeSeg.Root.AddrChild[1] == &this->FreeSeg )
    v6 = this->HdrPageSize;
  else
    v6 = 0i64;
  v7 = this->Allocator.MinSize;
  v8 = this->MaxAlign;
  v9 = 0i64;
  v10 = 0i64;
  v11 = v3;
  if ( v3 < v7 )
    v11 = v7;
  v12 = ~(v7 - 1);
  if ( v11 > v8 )
    v11 = v8;
  if ( v3 > v8 )
    v9 = v3;
  val = v11;
  if ( v11 < v7 )
    v10 = v7;
  if ( v9 <= v10 )
    v9 = 0i64;
  v13 = v12 & (v10
             + v5->Granularity * (((~(v3 - 1) & (size + v9 + v6 + v3 - 1)) + v5->Granularity - 1) / v5->Granularity)
             + v7
             - 1);
  v14 = ((__int64 (__fastcall *)(Scaleform::SysAllocPaged *, unsigned __int64, unsigned __int64))v5->pSysAlloc->vfptr[1].initHeapEngine)(
          v5->pSysAlloc,
          v13,
          v11);
  v15 = v14;
  if ( v14 )
  {
    v16 = v12 & (v14 + v13);
    v17 = (Scaleform::HeapPT::HdrPage *)(v12 & (v14 + v7 - 1));
    if ( v6 )
    {
      memset(v17, 0, v6);
      v17->UseCount = 0i64;
      v18 = 0i64;
      if ( v5->HdrCapacity )
      {
        v19 = &v17[1].8;
        do
        {
          v19[2].pNext = v17;
          v20 = v4->Root.AddrChild[0];
          v19[1].pNext = (Scaleform::HeapPT::HdrPage *)v4;
          v19->pNext = (Scaleform::HeapPT::HdrPage *)v20;
          v4->Root.AddrChild[0]->AddrChild[1] = (Scaleform::HeapPT::TreeSeg *)&v19[-1];
          ++v18;
          v4->Root.AddrChild[0] = (Scaleform::HeapPT::TreeSeg *)&v19[-1];
          v19 += 8;
        }
        while ( v18 < v5->HdrCapacity );
      }
      v17->pPrev = v5->HdrList.Root.pPrev;
      v17->pNext = (Scaleform::HeapPT::HdrPage *)&v5->HdrList;
      v5->HdrList.Root.pPrev->pNext = v17;
      v5->HdrList.Root.pPrev = v17;
    }
    v21 = v5->FreeSeg.Root.AddrChild[1];
    v22 = (char *)v17 + v6;
    v21->AddrChild[0]->AddrChild[1] = v21->AddrChild[1];
    v21->AddrChild[1]->AddrChild[0] = v21->AddrChild[0];
    ++v21->Headers->UseCount;
    v21->Buffer = v22;
    v21->Size = v16 - (_QWORD)v22;
    v21->UseCount = 0i64;
    v23 = Scaleform::Alg::UpperBit(val);
    v24 = &v5->UsedSeg;
    v21->AddrChild[1] = 0i64;
    v21->AddrChild[0] = 0i64;
    v21->AddrParent = 0i64;
    v21->AlignShift = v23;
    v21->HeadBytes = (_DWORD)v17 - v15;
    if ( v5->UsedSeg.Root )
    {
      v24 = (Scaleform::RadixTree<Scaleform::HeapPT::TreeSeg,Scaleform::HeapPT::Granulator::SegTreeAccessor> *)v24->Root;
      v25 = v22;
      if ( (char *)v24[4].Root == v22 )
      {
LABEL_30:
        Scaleform::HeapPT::AllocLite::pushNode(
          &v5->Allocator,
          (Scaleform::HeapPT::DualTNode *)v21->Buffer,
          v21,
          v21->Size >> v5->Allocator.MinShift);
        v5->Footprint += v13;
        LOBYTE(v14) = 1;
        return v14;
      }
      while ( 1 )
      {
        v26 = (unsigned __int64)v25;
        v25 = (char *)(2i64 * (_QWORD)v25);
        v26 >>= 63;
        v27 = (signed __int64)&v24[v26];
        v28 = v24[v26 + 1].Root;
        if ( !v28 )
          break;
        v24 = (Scaleform::RadixTree<Scaleform::HeapPT::TreeSeg,Scaleform::HeapPT::Granulator::SegTreeAccessor> *)v28;
        if ( v28->Buffer == v22 )
          goto LABEL_30;
      }
      *(_QWORD *)(v27 + 8) = v21;
    }
    else
    {
      v24->Root = v21;
    }
    v21->AddrParent = (Scaleform::HeapPT::TreeSeg *)v24;
    goto LABEL_30;
  }
  return v14;
}

// File Line: 177
// RVA: 0x9E3930
__int64 __fastcall Scaleform::HeapPT::Granulator::freeSegment(Scaleform::HeapPT::Granulator *this, Scaleform::HeapPT::TreeSeg *seg)
{
  Scaleform::HeapPT::HdrPage *v2; // r14
  unsigned __int64 v3; // rbp
  Scaleform::HeapPT::TreeSeg *v4; // rsi
  Scaleform::HeapPT::Granulator *v5; // rdi
  unsigned __int8 v6; // r9
  Scaleform::HeapPT::DualTNode *v7; // r15
  __int64 v8; // rdx
  unsigned __int64 v9; // r8
  unsigned __int64 v10; // rcx
  unsigned __int64 v11; // rbx
  unsigned __int64 v12; // rbx
  char *v13; // r11
  unsigned __int64 v14; // r9
  Scaleform::HeapPT::TreeSeg *v15; // rbx
  signed __int64 i; // rdx
  unsigned __int64 v17; // rax
  unsigned __int64 v18; // r8
  signed __int64 v19; // rdx
  unsigned __int64 v20; // r8
  Scaleform::HeapPT::DualTNode *v21; // rsi
  __int64 v22; // rdx
  unsigned __int64 v23; // rcx
  unsigned __int64 v24; // r14
  unsigned __int64 v25; // r14
  Scaleform::HeapPT::DualTNode *v26; // rcx
  unsigned __int64 v27; // r14
  Scaleform::HeapPT::DualTNode *v28; // rax
  Scaleform::HeapPT::DualTNode *v29; // rdx
  Scaleform::HeapPT::DualTNode *v30; // rax
  Scaleform::HeapPT::DualTNode *v31; // rax
  char *v32; // r11

  v2 = seg->Headers;
  v3 = 0i64;
  v4 = seg;
  v5 = this;
  v6 = 1;
  if ( (char *)v2 + this->HdrPageSize != seg->Buffer )
  {
    Scaleform::RadixTree<Scaleform::HeapMH::NodeMH,Scaleform::HeapMH::TreeNodeAccessor>::Remove(&this->UsedSeg, seg);
    v4->AddrChild[1] = v5->FreeSeg.Root.AddrChild[1];
    v4->AddrChild[0] = &v5->FreeSeg.Root;
    v5->FreeSeg.Root.AddrChild[1]->AddrChild[0] = v4;
    v5->FreeSeg.Root.AddrChild[1] = v4;
    --v2->UseCount;
    v7 = (Scaleform::HeapPT::DualTNode *)v4->Buffer;
    v8 = v4->HeadBytes;
    v9 = 0i64;
    if ( (Scaleform::HeapPT::DualTNode *)((char *)v4->Headers + v5->HdrPageSize) == v7 )
      v9 = v5->HdrPageSize;
    if ( (_DWORD)v8 )
      v10 = v5->Allocator.MinSize - v8;
    else
      v10 = 0i64;
    v11 = v4->Size;
    v5->Allocator.FreeBlocks -= v7->Size;
    v12 = v9 + v10 + v8 + v11;
    Scaleform::RadixTreeMulti<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor>::Remove(
      &v5->Allocator.SizeTree,
      v7);
    Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::Remove(
      &v5->Allocator.AddrTree,
      v7);
    v5->Footprint -= v12;
    v13 = v4->Buffer;
    v14 = 0i64;
    if ( (char *)v4->Headers + v5->HdrPageSize == v13 )
      v14 = v5->HdrPageSize;
    v6 = ((__int64 (__fastcall *)(Scaleform::SysAllocPaged *, char *, unsigned __int64, signed __int64))v5->pSysAlloc->vfptr[1].shutdownHeapEngine)(
           v5->pSysAlloc,
           &v13[-v4->HeadBytes - v14],
           v12,
           1i64 << LOBYTE(v4->AlignShift));
  }
  if ( v2->UseCount != 1 )
    return v6;
  v15 = v5->UsedSeg.Root;
  for ( i = (signed __int64)v2 + v5->HdrPageSize; v15; v15 = v15->AddrChild[v17 >> 63] )
  {
    if ( v15->Buffer == (char *)v2 + v5->HdrPageSize )
      break;
    v17 = i;
    i *= 2i64;
  }
  if ( v15->UseCount )
    return v6;
  Scaleform::RadixTree<Scaleform::HeapMH::NodeMH,Scaleform::HeapMH::TreeNodeAccessor>::Remove(&v5->UsedSeg, v15);
  v15->AddrChild[1] = v5->FreeSeg.Root.AddrChild[1];
  v15->AddrChild[0] = &v5->FreeSeg.Root;
  v5->FreeSeg.Root.AddrChild[1]->AddrChild[0] = v15;
  v5->FreeSeg.Root.AddrChild[1] = v15;
  v18 = 0i64;
  if ( v5->HdrCapacity > 0 )
  {
    v19 = (signed __int64)&v2[1].UseCount;
    do
    {
      ++v18;
      *(_QWORD *)(*(_QWORD *)(v19 - 8) + 16i64) = *(_QWORD *)v19;
      *(_QWORD *)(*(_QWORD *)v19 + 8i64) = *(_QWORD *)(v19 - 8);
      v19 += 64i64;
    }
    while ( v18 < v5->HdrCapacity );
  }
  v20 = 0i64;
  v2->pPrev->pNext = v2->pNext;
  v2->pNext->pPrev = v2->pPrev;
  v21 = (Scaleform::HeapPT::DualTNode *)v15->Buffer;
  v22 = v15->HeadBytes;
  if ( (Scaleform::HeapPT::DualTNode *)((char *)v15->Headers + v5->HdrPageSize) == v21 )
    v20 = v5->HdrPageSize;
  if ( (_DWORD)v22 )
    v23 = v5->Allocator.MinSize - v22;
  else
    v23 = 0i64;
  v24 = v15->Size;
  v5->Allocator.FreeBlocks -= v21->Size;
  v25 = v23 + v22 + v24;
  v26 = v21->pPrev;
  v27 = v20 + v25;
  if ( v21->pPrev == v21 )
  {
    Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor>::Remove(
      &v5->Allocator.SizeTree.Tree,
      v21);
  }
  else
  {
    v28 = v21->pNext;
    v28->pPrev = v26;
    v26->pNext = v28;
    v29 = v21->Parent;
    if ( v29 )
    {
      if ( v21 == v5->Allocator.SizeTree.Tree.Root )
        v5->Allocator.SizeTree.Tree.Root = v26;
      else
        v29->Child[v21->Parent->Child[0] != v21] = v26;
      v26->Parent = v29;
      v30 = v21->Child[0];
      if ( v30 )
      {
        v26->Child[0] = v30;
        v30->Parent = v26;
      }
      v31 = v21->Child[1];
      if ( v31 )
      {
        v26->Child[1] = v31;
        v31->Parent = v26;
      }
    }
    v21->Child[1] = 0i64;
    v21->Child[0] = 0i64;
    v21->Parent = 0i64;
  }
  Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::Remove(
    &v5->Allocator.AddrTree,
    v21);
  v5->Footprint -= v27;
  v32 = v15->Buffer;
  if ( (char *)v15->Headers + v5->HdrPageSize == v32 )
    v3 = v5->HdrPageSize;
  return ((__int64 (__fastcall *)(Scaleform::SysAllocPaged *, char *, unsigned __int64, signed __int64))v5->pSysAlloc->vfptr[1].shutdownHeapEngine)(
           v5->pSysAlloc,
           &v32[-v15->HeadBytes - v3],
           v27,
           1i64 << LOBYTE(v15->AlignShift));
}

// File Line: 238
// RVA: 0x956850
Scaleform::HeapPT::DualTNode *__fastcall Scaleform::HeapPT::Granulator::Alloc(Scaleform::HeapPT::Granulator *this, unsigned __int64 size, unsigned __int64 alignSize)
{
  Scaleform::HeapPT::Granulator *v3; // rsi
  unsigned __int64 v4; // rbx
  unsigned __int64 v5; // rdi
  Scaleform::HeapPT::DualTNode *result; // rax
  Scaleform::HeapPT::TreeSeg *allocSeg; // [rsp+30h] [rbp+8h]

  v3 = this;
  v4 = alignSize;
  v5 = size;
  result = Scaleform::HeapPT::AllocLite::Alloc(&this->Allocator, size, alignSize, &allocSeg);
  if ( result )
    goto LABEL_10;
  if ( !Scaleform::HeapPT::Granulator::allocSegment(v3, v5, v4) )
    return 0i64;
  result = Scaleform::HeapPT::AllocLite::Alloc(&v3->Allocator, v5, v4, &allocSeg);
  if ( result )
    goto LABEL_10;
  if ( !Scaleform::HeapPT::Granulator::allocSegment(v3, v5, v4) )
    return 0i64;
  result = Scaleform::HeapPT::AllocLite::Alloc(&v3->Allocator, v5, v4, &allocSeg);
  if ( result )
LABEL_10:
    ++allocSeg->UseCount;
  return result;
}

// File Line: 280
// RVA: 0x97DCC0
bool __fastcall Scaleform::HeapPT::Granulator::Free(Scaleform::HeapPT::Granulator *this, void *ptr, unsigned __int64 size, unsigned __int64 alignSize)
{
  Scaleform::HeapPT::Granulator *v4; // r14
  unsigned __int64 v5; // rbx
  unsigned __int64 v6; // rdi
  void *v7; // rsi
  Scaleform::HeapPT::TreeSeg *v8; // rbp
  bool v9; // zf
  bool result; // al

  v4 = this;
  v5 = alignSize;
  v6 = size;
  v7 = ptr;
  v8 = Scaleform::RadixTree<Scaleform::HeapPT::TreeSeg,Scaleform::HeapPT::Granulator::SegTreeAccessor>::FindLeEq(
         &this->UsedSeg,
         (unsigned __int64)ptr);
  Scaleform::HeapPT::AllocLite::Free(&v4->Allocator, v8, v7, v6, v5);
  v9 = v8->UseCount-- == 1;
  if ( v9 )
    result = Scaleform::HeapPT::Granulator::freeSegment(v4, v8);
  else
    result = 1;
  return result;
}

// File Line: 298
// RVA: 0x9A6E10
bool __fastcall Scaleform::HeapPT::Granulator::ReallocInPlace(Scaleform::HeapPT::Granulator *this, void *oldPtr, unsigned __int64 oldSize, unsigned __int64 newSize, unsigned __int64 alignSize)
{
  unsigned __int64 v5; // r13
  Scaleform::HeapPT::Granulator *v6; // rdi
  unsigned __int64 v7; // rsi
  unsigned __int64 v8; // r14
  void *v9; // rbx
  Scaleform::HeapPT::TreeSeg *v10; // rax
  Scaleform::HeapPT::TreeSeg *v11; // rbp
  signed int v12; // eax
  signed int v13; // er15
  bool result; // al
  char *v15; // rcx
  __int64 v16; // r10
  unsigned __int64 v17; // r9
  char *v18; // rdx
  unsigned __int64 v19; // rax
  char *v20; // r14
  unsigned __int64 v21; // rax
  unsigned __int64 v22; // r11
  signed __int64 v23; // r8
  unsigned __int64 v24; // rsi
  unsigned __int64 v25; // r10
  unsigned __int64 v26; // rbx
  void *ptr; // [rsp+78h] [rbp+10h]
  unsigned __int64 oldSizea; // [rsp+80h] [rbp+18h]
  unsigned __int64 v29; // [rsp+88h] [rbp+20h]

  v29 = newSize;
  oldSizea = oldSize;
  ptr = oldPtr;
  v5 = alignSize;
  v6 = this;
  v7 = newSize;
  v8 = oldSize;
  if ( alignSize < this->Allocator.MinSize )
    v5 = this->Allocator.MinSize;
  v9 = oldPtr;
  v10 = Scaleform::RadixTree<Scaleform::HeapPT::TreeSeg,Scaleform::HeapPT::Granulator::SegTreeAccessor>::FindLeEq(
          &this->UsedSeg,
          (unsigned __int64)oldPtr);
  v11 = v10;
  v12 = Scaleform::HeapPT::AllocLite::ReallocInPlace(&v6->Allocator, v10, v9, v8, v7, v5);
  v13 = v12;
  if ( !v6->HasRealloc )
    return v12 < 2;
  if ( !v12 )
    return 1;
  v15 = v11->Buffer;
  v16 = v11->HeadBytes;
  v17 = 0i64;
  v18 = (char *)v11->Headers + v6->HdrPageSize;
  v19 = 0i64;
  if ( v18 == v15 )
    v19 = v6->HdrPageSize;
  v20 = &v15[-v16 - v19];
  v21 = 0i64;
  if ( v18 == v15 )
    v21 = v6->HdrPageSize;
  if ( (_DWORD)v16 )
    v17 = v6->Allocator.MinSize - v16;
  v22 = v6->Granularity;
  v23 = ~(v5 - 1);
  v24 = v17 + v21 + v16 + v11->Size;
  v25 = v22 * (((v23 & ((_BYTE *)v9 - v20 + oldSizea + v5 - 1)) + v22 - 1) / v22);
  v26 = v22 * (((v23 & ((_BYTE *)v9 - v20 + v29 + v5 - 1)) + v22 - 1) / v22);
  if ( v13 == 1 )
  {
    if ( v26 < v25 )
    {
      Scaleform::HeapPT::AllocLite::TrimAt(&v6->Allocator, v11, &v20[v26]);
      if ( ((unsigned __int8 (__fastcall *)(Scaleform::SysAllocPaged *, char *, unsigned __int64, unsigned __int64, signed __int64))v6->pSysAlloc->vfptr[2].__vecDelDtor)(
             v6->pSysAlloc,
             v20,
             v24,
             v26,
             1i64 << v11->AlignShift) )
      {
        result = 1;
        v6->Footprint += v26 - v24;
        return result;
      }
      Scaleform::HeapPT::AllocLite::Extend(&v6->Allocator, v11, v24 - v26);
    }
    return 1;
  }
  if ( v13 != 3 )
    return 0;
  for ( ; v26 <= v25; v26 += v22 )
    ;
  if ( !((unsigned __int8 (__fastcall *)(Scaleform::SysAllocPaged *, char *, unsigned __int64, unsigned __int64, signed __int64))v6->pSysAlloc->vfptr[2].__vecDelDtor)(
          v6->pSysAlloc,
          v20,
          v24,
          v26,
          1i64 << v11->AlignShift) )
    return 0;
  v6->Footprint += v26 - v24;
  Scaleform::HeapPT::AllocLite::Extend(&v6->Allocator, v11, v26 - v24);
  Scaleform::HeapPT::AllocLite::ReallocInPlace(&v6->Allocator, v11, ptr, oldSizea, v29, v5);
  return 1;
}

// File Line: 413
// RVA: 0x9FAEF0
void __fastcall Scaleform::HeapPT::Granulator::visitSegments(Scaleform::HeapPT::Granulator *this, Scaleform::HeapPT::TreeSeg *node, Scaleform::Heap::SegVisitor *visitor, unsigned int cat)
{
  unsigned int v4; // esi
  Scaleform::Heap::SegVisitor *v5; // rdi
  Scaleform::HeapPT::TreeSeg *v6; // rbx
  Scaleform::HeapPT::Granulator *v7; // rbp
  char *v8; // r9
  unsigned __int64 v9; // r8

  if ( node )
  {
    v4 = cat;
    v5 = visitor;
    v6 = node;
    v7 = this;
    do
    {
      Scaleform::HeapPT::Granulator::visitSegments(v7, v6->AddrChild[0], v5, v4);
      v8 = v6->Buffer;
      v9 = 0i64;
      if ( (char *)v6->Headers + v7->HdrPageSize == v8 )
        v9 = v7->HdrPageSize;
      v5->vfptr->Visit(
        v5,
        v4,
        0i64,
        (unsigned __int64)&v8[-v9 + 4095] & 0xFFFFFFFFFFFFF000ui64,
        (v9 + v6->Size) & 0xFFFFFFFFFFFFF000ui64);
      v6 = v6->AddrChild[1];
    }
    while ( v6 );
  }
}

