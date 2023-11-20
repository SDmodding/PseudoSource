// File Line: 34
// RVA: 0x945590
void __fastcall Scaleform::SysAllocStatic::SysAllocStatic(Scaleform::SysAllocStatic *this, void *mem1, unsigned __int64 size1, void *mem2, unsigned __int64 size2, void *mem3, unsigned __int64 size3, void *mem4, unsigned __int64 size4)
{
  void *v9; // rsi
  unsigned __int64 v10; // r14
  void *v11; // rbp
  Scaleform::SysAllocStatic *v12; // rbx
  Scaleform::HeapPT::AllocLite *v13; // rdi
  unsigned __int8 v14; // al
  signed __int64 v15; // rax

  v9 = mem2;
  v10 = size1;
  v11 = mem1;
  v12 = this;
  this->vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAllocBase::`vftable';
  this->vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAllocPaged::`vftable';
  this->vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAllocStatic::`vftable';
  this->MinSize = 4096i64;
  this->NumSegments = 0i64;
  this->pAllocator = 0i64;
  this->TotalSpace = 0i64;
  v13 = (Scaleform::HeapPT::AllocLite *)this->PrivateData;
  if ( this == (Scaleform::SysAllocStatic *)-32i64 )
  {
    v13 = 0i64;
  }
  else
  {
    v14 = Scaleform::Alg::UpperBit(this->MinSize);
    v13->MinShift = v14;
    v15 = 1i64 << v14;
    v13->MinSize = v15;
    v13->MinMask = v15 - 1;
    v13->SizeTree.Tree.Root = 0i64;
    v13->AddrTree.Root = 0i64;
    v13->FreeBlocks = 0i64;
  }
  v12->pAllocator = v13;
  if ( v11 )
    Scaleform::SysAllocStatic::AddMemSegment(v12, v11, v10);
  if ( v9 )
    Scaleform::SysAllocStatic::AddMemSegment(v12, v9, size2);
  if ( mem3 )
    Scaleform::SysAllocStatic::AddMemSegment(v12, mem3, size3);
  if ( mem4 )
    Scaleform::SysAllocStatic::AddMemSegment(v12, mem4, size4);
}

// File Line: 50
// RVA: 0x9456C0
void __fastcall Scaleform::SysAllocStatic::SysAllocStatic(Scaleform::SysAllocStatic *this, unsigned __int64 minSize)
{
  Scaleform::SysAllocStatic *v2; // rbx
  Scaleform::HeapPT::AllocLite *v3; // rdi
  unsigned __int8 v4; // al
  signed __int64 v5; // rax

  v2 = this;
  this->vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAllocBase::`vftable';
  this->vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAllocPaged::`vftable';
  this->vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAllocStatic::`vftable';
  this->MinSize = minSize;
  this->NumSegments = 0i64;
  this->pAllocator = 0i64;
  this->TotalSpace = 0i64;
  v3 = (Scaleform::HeapPT::AllocLite *)this->PrivateData;
  if ( this == (Scaleform::SysAllocStatic *)-32i64 )
  {
    v3 = 0i64;
  }
  else
  {
    v4 = Scaleform::Alg::UpperBit(this->MinSize);
    v3->MinShift = v4;
    v5 = 1i64 << v4;
    v3->MinSize = v5;
    v3->MinMask = v5 - 1;
    v3->SizeTree.Tree.Root = 0i64;
    v3->AddrTree.Root = 0i64;
    v3->FreeBlocks = 0i64;
  }
  v2->pAllocator = v3;
}

// File Line: 59
// RVA: 0x954560
void __fastcall Scaleform::SysAllocStatic::AddMemSegment(Scaleform::SysAllocStatic *this, void *mem, unsigned __int64 size)
{
  unsigned __int64 v3; // rax
  Scaleform::SysAllocStatic *v4; // rbx
  unsigned __int64 v5; // rcx
  signed __int64 v6; // r9
  unsigned __int64 v7; // rax
  unsigned __int64 v8; // rdx
  signed __int64 v9; // r9
  unsigned __int64 v10; // rcx
  unsigned __int64 v11; // rax
  unsigned __int64 v12; // rax
  char *v13; // rdx

  v3 = this->MinSize;
  v4 = this;
  v5 = (unsigned __int64)mem + v3 - 1;
  v6 = v3 - 1;
  v7 = (unsigned __int64)mem + size;
  v8 = v4->NumSegments;
  v9 = ~v6;
  v10 = v9 & v5;
  v11 = v9 & v7;
  if ( v8 < 4 )
  {
    v12 = v11 - v10;
    v13 = (char *)v4 + 64 * v8;
    *((_QWORD *)v13 + 16) = v10;
    *((_QWORD *)v13 + 17) = v12;
    *((_QWORD *)v13 + 18) = 0i64;
    v4->TotalSpace += v12;
    Scaleform::HeapPT::AllocLite::pushNode(
      v4->pAllocator,
      *((Scaleform::HeapPT::DualTNode **)v13 + 16),
      (Scaleform::HeapPT::TreeSeg *)(v13 + 96),
      *((_QWORD *)v13 + 17) >> v4->pAllocator->MinShift);
    ++v4->NumSegments;
  }
}

// File Line: 76
// RVA: 0x9875C0
void __fastcall Scaleform::SysAllocStatic::GetInfo(Scaleform::SysAllocStatic *this, Scaleform::SysAllocPaged::Info *i)
{
  unsigned __int64 v2; // rcx

  v2 = this->pAllocator->MinSize;
  i->HasRealloc = 1;
  i->MaxAlign = 0i64;
  i->Granularity = 0i64;
  i->MinAlign = v2;
}

// File Line: 86
// RVA: 0x956E10
Scaleform::HeapPT::DualTNode *__fastcall Scaleform::SysAllocStatic::Alloc(Scaleform::SysAllocStatic *this, unsigned __int64 size, unsigned __int64 alignment)
{
  Scaleform::HeapPT::TreeSeg *allocSeg; // [rsp+30h] [rbp+8h]

  return Scaleform::HeapPT::AllocLite::Alloc(this->pAllocator, size, alignment, &allocSeg);
}

// File Line: 95
// RVA: 0x9A71E0
bool __fastcall Scaleform::SysAllocStatic::ReallocInPlace(Scaleform::SysAllocStatic *this, void *oldPtr, unsigned __int64 oldSize, unsigned __int64 newSize, unsigned __int64 alignment)
{
  char *v5; // rsi
  unsigned __int64 v6; // rdx
  unsigned __int64 v7; // r11
  unsigned __int64 *v8; // r10
  signed __int64 v9; // rdi
  Scaleform::HeapPT::AllocLite *v11; // r12
  unsigned __int64 alignSize; // rcx
  signed __int64 v13; // rax
  unsigned __int64 v14; // r15
  unsigned __int64 v15; // r14
  Scaleform::HeapPT::DualTNode *v16; // rax
  Scaleform::HeapPT::DualTNode *v17; // rbx
  char *v18; // rcx
  int v19; // ecx

  v5 = (char *)oldPtr;
  v6 = this->NumSegments;
  v7 = 0i64;
  if ( !v6 )
    return 0;
  v8 = &this->Segments[0][4];
  while ( 1 )
  {
    v9 = (signed __int64)(v8 - 4);
    if ( (unsigned __int64)v5 >= *v8 && (unsigned __int64)v5 < *v8 + v8[1] )
      break;
    ++v7;
    v8 += 8;
    if ( v7 >= v6 )
      return 0;
  }
  v11 = this->pAllocator;
  alignSize = alignment;
  if ( alignment < v11->MinSize )
    alignSize = v11->MinSize;
  v13 = ~(alignSize - 1);
  v14 = v13 & (alignSize + oldSize - 1);
  v15 = v13 & (alignSize + newSize - 1);
  if ( v15 == v14 )
    goto LABEL_16;
  if ( v15 <= v14 )
  {
    Scaleform::HeapPT::AllocLite::Free(v11, (Scaleform::HeapPT::TreeSeg *)(v8 - 4), &v5[v15], v14 - v15, alignSize);
    v19 = &v5[v15 + (*(_QWORD *)&v5[v15 + 72] << v11->MinShift)] == (char *)(*(_QWORD *)(v9 + 32) + *(_QWORD *)(v9 + 40));
    return v19 < 2;
  }
  v16 = Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::FindGrEq(
          &v11->AddrTree,
          (unsigned __int64)&v5[v14]);
  v17 = v16;
  if ( !v16 || v16->ParentSeg != (Scaleform::HeapPT::TreeSeg *)v9 || v16 != (Scaleform::HeapPT::DualTNode *)&v5[v14] )
  {
LABEL_19:
    v19 = (&v5[v14] == (char *)(*(_QWORD *)(v9 + 32) + *(_QWORD *)(v9 + 40))) + 2;
    return v19 < 2;
  }
  v18 = (char *)v16 + (v16->Size << v11->MinShift);
  if ( &v5[v15] > v18 )
  {
    if ( v18 == (char *)(*(_QWORD *)(v9 + 32) + *(_QWORD *)(v9 + 40)) )
    {
      v19 = 3;
      return v19 < 2;
    }
    goto LABEL_19;
  }
  Scaleform::HeapPT::AllocLite::pullNode(v11, v16);
  Scaleform::HeapPT::AllocLite::splitNode(v11, v17, (char *)v17, v15 - v14);
LABEL_16:
  v19 = 0;
  return v19 < 2;
}

// File Line: 115
// RVA: 0x97E070
char __fastcall Scaleform::SysAllocStatic::Free(Scaleform::SysAllocStatic *this, void *ptr, unsigned __int64 size, unsigned __int64 alignment)
{
  unsigned __int64 v4; // r10
  unsigned __int64 v5; // r11
  unsigned __int64 v6; // r8
  Scaleform::HeapPT::DualTNode *v7; // rbx
  unsigned __int64 *v8; // rax
  Scaleform::HeapPT::TreeSeg *v9; // r15
  Scaleform::HeapPT::AllocLite *v11; // rdi
  unsigned __int64 v12; // rax
  unsigned __int64 v13; // r14
  Scaleform::HeapPT::DualTNode *v14; // rsi
  Scaleform::HeapPT::DualTNode *v15; // rax
  Scaleform::HeapPT::DualTNode *v16; // rbp
  unsigned __int64 v17; // rcx
  unsigned __int64 v18; // r14
  unsigned __int64 v19; // rax
  unsigned __int64 v20; // rax

  v4 = this->NumSegments;
  v5 = size;
  v6 = 0i64;
  v7 = (Scaleform::HeapPT::DualTNode *)ptr;
  if ( !v4 )
    return 0;
  v8 = &this->Segments[0][4];
  while ( 1 )
  {
    v9 = (Scaleform::HeapPT::TreeSeg *)(v8 - 4);
    if ( (unsigned __int64)ptr >= *v8 && (unsigned __int64)ptr < v8[1] + *v8 )
      break;
    ++v6;
    v8 += 8;
    if ( v6 >= v4 )
      return 0;
  }
  v11 = this->pAllocator;
  v12 = v11->MinSize;
  if ( v5 < v12 )
    v5 = v11->MinSize;
  if ( alignment < v12 )
    alignment = v11->MinSize;
  v13 = ~(alignment - 1) & (v5 + alignment - 1);
  v14 = Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::FindLeEq(
          &v11->AddrTree,
          (unsigned __int64)ptr);
  v15 = Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::FindGrEq(
          &v11->AddrTree,
          (unsigned __int64)v7 + v13);
  v16 = v15;
  if ( !v14
    || v14->ParentSeg != v9
    || (Scaleform::HeapPT::DualTNode *)((char *)v14 + (v14->Size << v11->MinShift)) != v7 )
  {
    v14 = 0i64;
  }
  if ( !v15 || v15->ParentSeg != v9 || v15 != (Scaleform::HeapPT::DualTNode *)((char *)v7 + v13) )
    v16 = 0i64;
  v17 = v11->MinShift;
  v7->ParentSeg = v9;
  v18 = v13 >> v17;
  v7->Size = v18;
  if ( v14 )
  {
    v19 = v14->Size;
    v11->FreeBlocks -= v19;
    v18 += v19;
    v7 = v14;
    Scaleform::RadixTreeMulti<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor>::Remove(
      &v11->SizeTree,
      v14);
    Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::Remove(
      &v11->AddrTree,
      v14);
  }
  if ( v16 )
  {
    v20 = v16->Size;
    v11->FreeBlocks -= v20;
    v18 += v20;
    Scaleform::RadixTreeMulti<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor>::Remove(
      &v11->SizeTree,
      v16);
    Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::Remove(
      &v11->AddrTree,
      v16);
  }
  Scaleform::HeapPT::AllocLite::pushNode(v11, v7, v9, v18);
  return 1;
}

// File Line: 133
// RVA: 0x9C1DF0
void __fastcall Scaleform::SysAllocStatic::VisitMem(Scaleform::SysAllocStatic *this, Scaleform::Heap::MemVisitor *visitor)
{
  Scaleform::HeapPT::AllocLite *v2; // rcx
  Scaleform::Heap::MemVisitor *v3; // r9
  Scaleform::HeapPT::DualTNode *v4; // rdx
  __int64 v5; // [rsp+30h] [rbp-48h]
  __int64 v6; // [rsp+40h] [rbp-38h]
  __int64 v7; // [rsp+48h] [rbp-30h]
  __int64 v8; // [rsp+50h] [rbp-28h]
  __int64 v9; // [rsp+58h] [rbp-20h]
  __int64 v10; // [rsp+60h] [rbp-18h]
  __int64 v11; // [rsp+68h] [rbp-10h]

  v2 = this->pAllocator;
  v3 = visitor;
  v4 = v2->SizeTree.Tree.Root;
  v7 = 16i64;
  v6 = 0i64;
  v8 = 0i64;
  v9 = 0i64;
  v10 = 0i64;
  v11 = 0i64;
  Scaleform::HeapPT::AllocLite::visitTree(v2, v4, (Scaleform::Heap::HeapSegment *)&v5, v3, Cat_SysAllocFree);
}

// File Line: 141
// RVA: 0x9800D0
unsigned __int64 __fastcall Scaleform::SysAllocStatic::GetBase(Scaleform::SysAllocStatic *this)
{
  unsigned __int64 v1; // r8
  unsigned __int64 result; // rax
  unsigned __int64 *v3; // rdx

  v1 = this->NumSegments;
  result = -1i64;
  if ( v1 )
  {
    v3 = &this->Segments[0][4];
    do
    {
      if ( *v3 < result )
        result = *v3;
      v3 += 8;
      --v1;
    }
    while ( v1 );
  }
  return result;
}

// File Line: 157
// RVA: 0x98B740
unsigned __int64 __fastcall Scaleform::SysAllocStatic::GetSize(Scaleform::SysAllocStatic *this)
{
  unsigned __int64 v1; // r11
  __int64 v2; // rdx
  __int64 v3; // r9
  unsigned __int64 v4; // rbx
  unsigned __int64 v5; // r10
  unsigned __int64 *v6; // rax
  unsigned __int64 v7; // r8

  v1 = this->NumSegments;
  v2 = 0i64;
  v3 = 0i64;
  v4 = 0i64;
  v5 = 0i64;
  if ( (signed __int64)v1 >= 2 )
  {
    v6 = &this->Segments[1][5];
    v7 = ((v1 - 2) >> 1) + 1;
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
  if ( v5 < v1 )
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

