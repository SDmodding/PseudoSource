// File Line: 34
// RVA: 0x945590
void __fastcall Scaleform::SysAllocStatic::SysAllocStatic(
        Scaleform::SysAllocStatic *this,
        void *mem1,
        unsigned __int64 size1,
        void *mem2,
        unsigned __int64 size2,
        void *mem3,
        unsigned __int64 size3,
        void *mem4,
        unsigned __int64 size4)
{
  Scaleform::HeapPT::AllocLite *PrivateData; // rdi
  unsigned __int8 v14; // al
  __int64 v15; // rax

  this->vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAllocBase::`vftable;
  this->vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAllocPaged::`vftable;
  this->vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAllocStatic::`vftable;
  this->MinSize = 4096i64;
  this->NumSegments = 0i64;
  this->pAllocator = 0i64;
  this->TotalSpace = 0i64;
  PrivateData = (Scaleform::HeapPT::AllocLite *)this->PrivateData;
  if ( this == (Scaleform::SysAllocStatic *)-32i64 )
  {
    PrivateData = 0i64;
  }
  else
  {
    v14 = Scaleform::Alg::UpperBit(this->MinSize);
    PrivateData->MinShift = v14;
    v15 = 1i64 << v14;
    PrivateData->MinSize = v15;
    PrivateData->MinMask = v15 - 1;
    PrivateData->SizeTree.Tree.Root = 0i64;
    PrivateData->AddrTree.Root = 0i64;
    PrivateData->FreeBlocks = 0i64;
  }
  this->pAllocator = PrivateData;
  if ( mem1 )
    Scaleform::SysAllocStatic::AddMemSegment(this, mem1, size1);
  if ( mem2 )
    Scaleform::SysAllocStatic::AddMemSegment(this, mem2, size2);
  if ( mem3 )
    Scaleform::SysAllocStatic::AddMemSegment(this, mem3, size3);
  if ( mem4 )
    Scaleform::SysAllocStatic::AddMemSegment(this, mem4, size4);
}

// File Line: 50
// RVA: 0x9456C0
void __fastcall Scaleform::SysAllocStatic::SysAllocStatic(Scaleform::SysAllocStatic *this, unsigned __int64 minSize)
{
  Scaleform::HeapPT::AllocLite *PrivateData; // rdi
  unsigned __int8 v4; // al
  __int64 v5; // rax

  this->vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAllocBase::`vftable;
  this->vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAllocPaged::`vftable;
  this->vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAllocStatic::`vftable;
  this->MinSize = minSize;
  this->NumSegments = 0i64;
  this->pAllocator = 0i64;
  this->TotalSpace = 0i64;
  PrivateData = (Scaleform::HeapPT::AllocLite *)this->PrivateData;
  if ( this == (Scaleform::SysAllocStatic *)-32i64 )
  {
    PrivateData = 0i64;
  }
  else
  {
    v4 = Scaleform::Alg::UpperBit(this->MinSize);
    PrivateData->MinShift = v4;
    v5 = 1i64 << v4;
    PrivateData->MinSize = v5;
    PrivateData->MinMask = v5 - 1;
    PrivateData->SizeTree.Tree.Root = 0i64;
    PrivateData->AddrTree.Root = 0i64;
    PrivateData->FreeBlocks = 0i64;
  }
  this->pAllocator = PrivateData;
}

// File Line: 59
// RVA: 0x954560
void __fastcall Scaleform::SysAllocStatic::AddMemSegment(
        Scaleform::SysAllocStatic *this,
        char *mem,
        unsigned __int64 size)
{
  unsigned __int64 MinSize; // rax
  unsigned __int64 v5; // rcx
  unsigned __int64 v6; // r9
  unsigned __int64 v7; // rax
  unsigned __int64 NumSegments; // rdx
  unsigned __int64 v9; // r9
  unsigned __int64 v10; // rcx
  unsigned __int64 v11; // rax
  unsigned __int64 v12; // rax
  char *v13; // rdx

  MinSize = this->MinSize;
  v5 = (unsigned __int64)&mem[MinSize - 1];
  v6 = MinSize - 1;
  v7 = (unsigned __int64)&mem[size];
  NumSegments = this->NumSegments;
  v9 = ~v6;
  v10 = v9 & v5;
  v11 = v9 & v7;
  if ( NumSegments < 4 )
  {
    v12 = v11 - v10;
    v13 = (char *)this + 64 * NumSegments;
    *((_QWORD *)v13 + 16) = v10;
    *((_QWORD *)v13 + 17) = v12;
    *((_QWORD *)v13 + 18) = 0i64;
    this->TotalSpace += v12;
    Scaleform::HeapPT::AllocLite::pushNode(
      this->pAllocator,
      *((Scaleform::HeapPT::DualTNode **)v13 + 16),
      (Scaleform::HeapPT::TreeSeg *)(v13 + 96),
      *((_QWORD *)v13 + 17) >> this->pAllocator->MinShift);
    ++this->NumSegments;
  }
}

// File Line: 76
// RVA: 0x9875C0
void __fastcall Scaleform::SysAllocStatic::GetInfo(Scaleform::SysAllocStatic *this, Scaleform::SysAllocPaged::Info *i)
{
  unsigned __int64 MinSize; // rcx

  MinSize = this->pAllocator->MinSize;
  i->HasRealloc = 1;
  i->MaxAlign = 0i64;
  i->Granularity = 0i64;
  i->MinAlign = MinSize;
}

// File Line: 86
// RVA: 0x956E10
Scaleform::HeapPT::DualTNode *__fastcall Scaleform::SysAllocStatic::Alloc(
        Scaleform::SysAllocStatic *this,
        unsigned __int64 size,
        unsigned __int64 alignment)
{
  Scaleform::HeapPT::TreeSeg *allocSeg; // [rsp+30h] [rbp+8h] BYREF

  return Scaleform::HeapPT::AllocLite::Alloc(this->pAllocator, size, alignment, &allocSeg);
}

// File Line: 95
// RVA: 0x9A71E0
bool __fastcall Scaleform::SysAllocStatic::ReallocInPlace(
        Scaleform::SysAllocStatic *this,
        char *oldPtr,
        unsigned __int64 oldSize,
        unsigned __int64 newSize,
        unsigned __int64 alignment)
{
  unsigned __int64 NumSegments; // rdx
  __int64 v7; // r11
  unsigned __int64 *i; // r10
  Scaleform::HeapPT::TreeSeg *v9; // rdi
  Scaleform::HeapPT::AllocLite *pAllocator; // r12
  unsigned __int64 alignSize; // rcx
  __int64 v13; // rax
  unsigned __int64 v14; // r15
  unsigned __int64 v15; // r14
  Scaleform::HeapPT::DualTNode *GrEq; // rax
  Scaleform::HeapPT::DualTNode *v17; // rbx
  char *v18; // rcx
  int v19; // ecx

  NumSegments = this->NumSegments;
  v7 = 0i64;
  if ( !NumSegments )
    return 0;
  for ( i = &this->Segments[0][4]; ; i += 8 )
  {
    v9 = (Scaleform::HeapPT::TreeSeg *)(i - 4);
    if ( (unsigned __int64)oldPtr >= *i && (unsigned __int64)oldPtr < *i + i[1] )
      break;
    if ( ++v7 >= NumSegments )
      return 0;
  }
  pAllocator = this->pAllocator;
  alignSize = alignment;
  if ( alignment < pAllocator->MinSize )
    alignSize = pAllocator->MinSize;
  v13 = ~(alignSize - 1);
  v14 = v13 & (alignSize + oldSize - 1);
  v15 = v13 & (alignSize + newSize - 1);
  if ( v15 == v14 )
    goto LABEL_16;
  if ( v15 <= v14 )
  {
    Scaleform::HeapPT::AllocLite::Free(
      pAllocator,
      (Scaleform::HeapPT::TreeSeg *)(i - 4),
      (Scaleform::HeapPT::DualTNode *)&oldPtr[v15],
      v14 - v15,
      alignSize);
    v19 = &oldPtr[v15 + (*(_QWORD *)&oldPtr[v15 + 72] << pAllocator->MinShift)] == &v9->Buffer[v9->Size];
    return v19 < 2;
  }
  GrEq = Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::FindGrEq(
           &pAllocator->AddrTree,
           (unsigned __int64)&oldPtr[v14]);
  v17 = GrEq;
  if ( !GrEq || GrEq->ParentSeg != v9 || GrEq != (Scaleform::HeapPT::DualTNode *)&oldPtr[v14] )
  {
LABEL_19:
    v19 = (&oldPtr[v14] == &v9->Buffer[v9->Size]) + 2;
    return v19 < 2;
  }
  v18 = (char *)GrEq + (GrEq->Size << pAllocator->MinShift);
  if ( &oldPtr[v15] > v18 )
  {
    if ( v18 == &v9->Buffer[v9->Size] )
    {
      v19 = 3;
      return v19 < 2;
    }
    goto LABEL_19;
  }
  Scaleform::HeapPT::AllocLite::pullNode(pAllocator, GrEq);
  Scaleform::HeapPT::AllocLite::splitNode(pAllocator, v17, (char *)v17, v15 - v14);
LABEL_16:
  v19 = 0;
  return v19 < 2;
}

// File Line: 115
// RVA: 0x97E070
char __fastcall Scaleform::SysAllocStatic::Free(
        Scaleform::SysAllocStatic *this,
        unsigned __int64 ptr,
        unsigned __int64 size,
        unsigned __int64 alignment)
{
  unsigned __int64 NumSegments; // r10
  __int64 v6; // r8
  Scaleform::HeapPT::DualTNode *v7; // rbx
  unsigned __int64 *i; // rax
  Scaleform::HeapPT::TreeSeg *v9; // r15
  Scaleform::HeapPT::AllocLite *pAllocator; // rdi
  unsigned __int64 MinSize; // rax
  unsigned __int64 v13; // r14
  Scaleform::HeapPT::DualTNode *LeEq; // rsi
  Scaleform::HeapPT::DualTNode *GrEq; // rax
  Scaleform::HeapPT::DualTNode *v16; // rbp
  unsigned __int64 MinShift; // rcx
  unsigned __int64 v18; // r14
  unsigned __int64 v19; // rax
  unsigned __int64 v20; // rax

  NumSegments = this->NumSegments;
  v6 = 0i64;
  v7 = (Scaleform::HeapPT::DualTNode *)ptr;
  if ( !NumSegments )
    return 0;
  for ( i = &this->Segments[0][4]; ; i += 8 )
  {
    v9 = (Scaleform::HeapPT::TreeSeg *)(i - 4);
    if ( ptr >= *i && ptr < i[1] + *i )
      break;
    if ( ++v6 >= NumSegments )
      return 0;
  }
  pAllocator = this->pAllocator;
  MinSize = pAllocator->MinSize;
  if ( size < MinSize )
    size = pAllocator->MinSize;
  if ( alignment < MinSize )
    alignment = pAllocator->MinSize;
  v13 = ~(alignment - 1) & (size + alignment - 1);
  LeEq = Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::FindLeEq(
           &pAllocator->AddrTree,
           ptr);
  GrEq = Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::FindGrEq(
           &pAllocator->AddrTree,
           (unsigned __int64)v7 + v13);
  v16 = GrEq;
  if ( !LeEq
    || LeEq->ParentSeg != v9
    || (Scaleform::HeapPT::DualTNode *)((char *)LeEq + (LeEq->Size << pAllocator->MinShift)) != v7 )
  {
    LeEq = 0i64;
  }
  if ( !GrEq || GrEq->ParentSeg != v9 || GrEq != (Scaleform::HeapPT::DualTNode *)((char *)v7 + v13) )
    v16 = 0i64;
  MinShift = pAllocator->MinShift;
  v7->ParentSeg = v9;
  v18 = v13 >> MinShift;
  v7->Size = v18;
  if ( LeEq )
  {
    v19 = LeEq->Size;
    pAllocator->FreeBlocks -= v19;
    v18 += v19;
    v7 = LeEq;
    Scaleform::RadixTreeMulti<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor>::Remove(
      &pAllocator->SizeTree,
      LeEq);
    Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::Remove(
      &pAllocator->AddrTree,
      LeEq);
  }
  if ( v16 )
  {
    v20 = v16->Size;
    pAllocator->FreeBlocks -= v20;
    v18 += v20;
    Scaleform::RadixTreeMulti<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor>::Remove(
      &pAllocator->SizeTree,
      v16);
    Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::Remove(
      &pAllocator->AddrTree,
      v16);
  }
  Scaleform::HeapPT::AllocLite::pushNode(pAllocator, v7, v9, v18);
  return 1;
}

// File Line: 133
// RVA: 0x9C1DF0
void __fastcall Scaleform::SysAllocStatic::VisitMem(
        Scaleform::SysAllocStatic *this,
        Scaleform::Heap::MemVisitor *visitor)
{
  Scaleform::HeapPT::AllocLite *pAllocator; // rcx
  Scaleform::HeapPT::DualTNode *Root; // rdx
  Scaleform::Heap::HeapSegment v5; // [rsp+30h] [rbp-48h] BYREF

  pAllocator = this->pAllocator;
  Root = pAllocator->SizeTree.Tree.Root;
  *(_QWORD *)&v5.SegType = 16i64;
  v5.SelfSize = 0i64;
  memset(&v5.UseCount, 0, 32);
  Scaleform::HeapPT::AllocLite::visitTree(pAllocator, Root, &v5, visitor, Cat_SysAllocFree);
}

// File Line: 141
// RVA: 0x9800D0
unsigned __int64 __fastcall Scaleform::SysAllocStatic::GetBase(Scaleform::SysAllocStatic *this)
{
  unsigned __int64 NumSegments; // r8
  unsigned __int64 result; // rax
  unsigned __int64 *v3; // rdx

  NumSegments = this->NumSegments;
  result = -1i64;
  if ( NumSegments )
  {
    v3 = &this->Segments[0][4];
    do
    {
      if ( *v3 < result )
        result = *v3;
      v3 += 8;
      --NumSegments;
    }
    while ( NumSegments );
  }
  return result;
}

// File Line: 157
// RVA: 0x98B740
unsigned __int64 __fastcall Scaleform::SysAllocStatic::GetSize(Scaleform::SysAllocStatic *this)
{
  signed __int64 NumSegments; // r11
  __int64 v2; // rdx
  __int64 v3; // r9
  unsigned __int64 v4; // rbx
  unsigned __int64 v5; // r10
  unsigned __int64 *v6; // rax
  unsigned __int64 v7; // r8

  NumSegments = this->NumSegments;
  v2 = 0i64;
  v3 = 0i64;
  v4 = 0i64;
  v5 = 0i64;
  if ( NumSegments >= 2 )
  {
    v6 = &this->Segments[1][5];
    v7 = ((unsigned __int64)(NumSegments - 2) >> 1) + 1;
    v5 = 2 * v7;
    do
    {
      v2 += *(v6 - 8);
      v3 += *v6;
      v6 += 16;
      --v7;
    }
    while ( v7 );
  }
  if ( v5 < NumSegments )
    v4 = this->Segments[v5][5];
  return v4 + v3 + v2;
}

// File Line: 169
// RVA: 0x98EAD0
unsigned __int64 __fastcall Scaleform::SysAllocStatic::GetFootprint(Scaleform::HeapPT::SysAllocWrapper *this)
{
  return this->UsedSpace;
}

// File Line: 175
// RVA: 0x98EAB0
unsigned __int64 __fastcall Scaleform::SysAllocStatic::GetUsedSpace(Scaleform::SysAllocStatic *this)
{
  return this->TotalSpace - (this->pAllocator->FreeBlocks << this->pAllocator->MinShift);
}

