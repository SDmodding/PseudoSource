// File Line: 52
// RVA: 0x9EE7E0
void __fastcall Scaleform::HeapPT::AllocLite::pushNode(
        Scaleform::HeapPT::AllocLite *this,
        Scaleform::HeapPT::DualTNode *node,
        Scaleform::HeapPT::TreeSeg *seg,
        unsigned __int64 blocks)
{
  Scaleform::HeapPT::DualTNode *p_AddrTree; // rax
  __int64 v8; // rdx
  unsigned __int64 v9; // rcx
  Scaleform::HeapPT::DualTNode **v10; // r8
  Scaleform::HeapPT::DualTNode *v11; // rcx

  node->Size = blocks;
  node->ParentSeg = seg;
  Scaleform::RadixTreeMulti<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor>::Insert(
    &this->SizeTree,
    node);
  p_AddrTree = (Scaleform::HeapPT::DualTNode *)&this->AddrTree;
  node->AddrChild[1] = 0i64;
  node->AddrChild[0] = 0i64;
  node->AddrParent = 0i64;
  if ( !this->AddrTree.Root )
  {
    p_AddrTree->pPrev = node;
LABEL_8:
    node->AddrParent = p_AddrTree;
    goto LABEL_9;
  }
  p_AddrTree = p_AddrTree->pPrev;
  v8 = (__int64)node;
  if ( p_AddrTree != node )
  {
    while ( 1 )
    {
      v9 = v8;
      v8 *= 2i64;
      v10 = &p_AddrTree->pPrev + (v9 >> 63);
      v11 = v10[6];
      if ( !v11 )
        break;
      p_AddrTree = v10[6];
      if ( v11 == node )
        goto LABEL_9;
    }
    v10[6] = node;
    goto LABEL_8;
  }
LABEL_9:
  this->FreeBlocks += blocks;
}

// File Line: 63
// RVA: 0x9EE700
void __fastcall Scaleform::HeapPT::AllocLite::pullNode(
        Scaleform::HeapPT::AllocLite *this,
        Scaleform::HeapPT::DualTNode *node)
{
  Scaleform::RadixTreeMulti<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor> *p_SizeTree; // rcx

  p_SizeTree = &this->SizeTree;
  p_SizeTree[2].Tree.Root = (Scaleform::HeapPT::DualTNode *)((char *)p_SizeTree[2].Tree.Root - node->Size);
  Scaleform::RadixTreeMulti<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor>::Remove(
    p_SizeTree,
    node);
  Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::Remove(
    &this->AddrTree,
    node);
}

// File Line: 86
// RVA: 0x9EE530
Scaleform::HeapPT::DualTNode *__fastcall Scaleform::HeapPT::AllocLite::pullBest(
        Scaleform::HeapPT::AllocLite *this,
        unsigned __int64 blocks,
        unsigned __int64 alignMask)
{
  Scaleform::HeapPT::DualTNode *v6; // rax
  Scaleform::HeapPT::DualTNode *GrEq; // rbx
  Scaleform::HeapPT::DualTNode *v9; // r9
  unsigned __int64 MinShift; // r15
  unsigned __int64 v11; // rsi
  unsigned __int64 v12; // r8
  unsigned __int64 v13; // rax
  Scaleform::HeapPT::DualTNode *pPrev; // rcx
  Scaleform::HeapPT::DualTNode *pNext; // rax
  Scaleform::HeapPT::DualTNode *Parent; // rdx
  Scaleform::HeapPT::DualTNode *v17; // rax
  Scaleform::HeapPT::DualTNode *v18; // rax

  if ( alignMask > this->MinMask )
  {
    GrEq = Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor>::FindGrEq(
             &this->SizeTree.Tree,
             blocks);
    v9 = GrEq;
    if ( GrEq )
    {
      MinShift = this->MinShift;
      v11 = blocks << this->MinShift;
      while ( 1 )
      {
        v12 = ~alignMask & ((unsigned __int64)GrEq + alignMask);
        v13 = v12 - (_QWORD)GrEq;
        if ( v12 != (_QWORD)GrEq )
        {
          do
          {
            if ( v13 >= 0x80 )
              break;
            v12 += alignMask + 1;
            v13 += alignMask + 1;
          }
          while ( v13 );
        }
        if ( v12 + v11 <= (unsigned __int64)GrEq + (GrEq->Size << MinShift) )
          break;
        GrEq = GrEq->pNext;
        if ( GrEq == v9 )
        {
          GrEq = Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor>::FindGrEq(
                   &this->SizeTree.Tree,
                   GrEq->Size + 1);
          v9 = GrEq;
          if ( !GrEq )
            return GrEq;
        }
      }
      pPrev = GrEq->pPrev;
      if ( GrEq->pPrev == GrEq )
      {
        Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor>::Remove(
          &this->SizeTree.Tree,
          GrEq);
      }
      else
      {
        pNext = GrEq->pNext;
        pNext->pPrev = pPrev;
        pPrev->pNext = pNext;
        Parent = GrEq->Parent;
        if ( Parent )
        {
          if ( GrEq == this->SizeTree.Tree.Root )
            this->SizeTree.Tree.Root = pPrev;
          else
            Parent->Child[GrEq->Parent->Child[0] != GrEq] = pPrev;
          pPrev->Parent = Parent;
          v17 = GrEq->Child[0];
          if ( v17 )
          {
            pPrev->Child[0] = v17;
            v17->Parent = pPrev;
          }
          v18 = GrEq->Child[1];
          if ( v18 )
          {
            pPrev->Child[1] = v18;
            v18->Parent = pPrev;
          }
        }
        GrEq->Child[1] = 0i64;
        GrEq->Child[0] = 0i64;
        GrEq->Parent = 0i64;
      }
      Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::Remove(
        &this->AddrTree,
        GrEq);
      this->FreeBlocks -= GrEq->Size;
    }
  }
  else
  {
    v6 = Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor>::FindGrEq(
           &this->SizeTree.Tree,
           blocks);
    GrEq = v6;
    if ( v6 )
    {
      GrEq = v6->pNext;
      Scaleform::RadixTreeMulti<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor>::Remove(
        &this->SizeTree,
        GrEq);
      if ( GrEq )
      {
        Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::Remove(
          &this->AddrTree,
          GrEq);
        this->FreeBlocks -= GrEq->Size;
        return GrEq;
      }
    }
  }
  return GrEq;
}

// File Line: 149
// RVA: 0x9F3290
void __fastcall Scaleform::HeapPT::AllocLite::splitNode(
        Scaleform::HeapPT::AllocLite *this,
        Scaleform::HeapPT::DualTNode *node,
        Scaleform::HeapPT::DualTNode *start,
        unsigned __int64 size)
{
  Scaleform::HeapPT::TreeSeg *ParentSeg; // rsi
  unsigned __int64 MinShift; // rcx
  unsigned __int64 v9; // rbx

  ParentSeg = node->ParentSeg;
  MinShift = this->MinShift;
  v9 = (unsigned __int64)node + (node->Size << MinShift) - (_QWORD)start - size;
  if ( start != node )
    Scaleform::HeapPT::AllocLite::pushNode(
      this,
      node,
      node->ParentSeg,
      (unsigned __int64)((char *)start - (char *)node) >> MinShift);
  if ( v9 )
    Scaleform::HeapPT::AllocLite::pushNode(
      this,
      (Scaleform::HeapPT::DualTNode *)((char *)start + size),
      ParentSeg,
      v9 >> this->MinShift);
}

// File Line: 197
// RVA: 0x956680
Scaleform::HeapPT::DualTNode *__fastcall Scaleform::HeapPT::AllocLite::Alloc(
        Scaleform::HeapPT::AllocLite *this,
        unsigned __int64 size,
        unsigned __int64 alignSize,
        Scaleform::HeapPT::TreeSeg **allocSeg)
{
  unsigned __int64 MinSize; // rax
  unsigned __int64 MinShift; // rcx
  __int64 v8; // rdi
  unsigned __int64 v9; // rsi
  unsigned __int64 v10; // rbp
  Scaleform::HeapPT::DualTNode *result; // rax
  char *v12; // rbx
  unsigned __int64 v13; // rcx

  MinSize = this->MinSize;
  MinShift = this->MinShift;
  if ( size < MinSize )
    size = MinSize;
  if ( alignSize < MinSize )
    alignSize = MinSize;
  v8 = alignSize - 1;
  v9 = ~(alignSize - 1);
  v10 = v9 & (size + alignSize - 1);
  result = Scaleform::HeapPT::AllocLite::pullBest(this, v10 >> MinShift, alignSize - 1);
  if ( result )
  {
    v12 = (char *)(v9 & ((unsigned __int64)result + v8));
    v13 = v12 - (char *)result;
    if ( v12 != (char *)result )
    {
      do
      {
        if ( v13 >= 0x80 )
          break;
        v12 += v8 + 1;
        v13 += v8 + 1;
      }
      while ( v13 );
    }
    *allocSeg = result->ParentSeg;
    Scaleform::HeapPT::AllocLite::splitNode(this, result, v12, v10);
    return (Scaleform::HeapPT::DualTNode *)v12;
  }
  return result;
}

// File Line: 225
// RVA: 0x97DAC0
void __fastcall Scaleform::HeapPT::AllocLite::Free(
        Scaleform::HeapPT::AllocLite *this,
        Scaleform::HeapPT::TreeSeg *seg,
        Scaleform::HeapPT::DualTNode *ptr,
        unsigned __int64 size,
        unsigned __int64 alignSize)
{
  unsigned __int64 v5; // rax
  unsigned __int64 MinSize; // r8
  unsigned __int64 v10; // rbp
  Scaleform::HeapPT::DualTNode *LeEq; // rdi
  Scaleform::HeapPT::DualTNode *GrEq; // rax
  Scaleform::HeapPT::DualTNode *v13; // rsi
  unsigned __int64 MinShift; // rcx
  unsigned __int64 v15; // rbp
  unsigned __int64 v16; // rax
  unsigned __int64 v17; // rax

  v5 = alignSize;
  MinSize = this->MinSize;
  if ( size < MinSize )
    size = this->MinSize;
  if ( alignSize < MinSize )
    v5 = this->MinSize;
  v10 = ~(v5 - 1) & (size + v5 - 1);
  LeEq = Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::FindLeEq(
           &this->AddrTree,
           (unsigned __int64)ptr);
  GrEq = Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::FindGrEq(
           &this->AddrTree,
           (unsigned __int64)ptr + v10);
  v13 = GrEq;
  if ( !LeEq
    || LeEq->ParentSeg != seg
    || (Scaleform::HeapPT::DualTNode *)((char *)LeEq + (LeEq->Size << this->MinShift)) != ptr )
  {
    LeEq = 0i64;
  }
  if ( !GrEq || GrEq->ParentSeg != seg || GrEq != (Scaleform::HeapPT::DualTNode *)((char *)ptr + v10) )
    v13 = 0i64;
  MinShift = this->MinShift;
  ptr->ParentSeg = seg;
  v15 = v10 >> MinShift;
  ptr->Size = v15;
  if ( LeEq )
  {
    v16 = LeEq->Size;
    this->FreeBlocks -= v16;
    v15 += v16;
    ptr = LeEq;
    Scaleform::RadixTreeMulti<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor>::Remove(
      &this->SizeTree,
      LeEq);
    Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::Remove(
      &this->AddrTree,
      LeEq);
  }
  if ( v13 )
  {
    v17 = v13->Size;
    this->FreeBlocks -= v17;
    v15 += v17;
    Scaleform::RadixTreeMulti<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor>::Remove(
      &this->SizeTree,
      v13);
    Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::Remove(
      &this->AddrTree,
      v13);
  }
  Scaleform::HeapPT::AllocLite::pushNode(this, ptr, seg, v15);
}

// File Line: 287
// RVA: 0x9A6CC0
__int64 __fastcall Scaleform::HeapPT::AllocLite::ReallocInPlace(
        Scaleform::HeapPT::AllocLite *this,
        Scaleform::HeapPT::TreeSeg *seg,
        char *ptr,
        unsigned __int64 oldSize,
        unsigned __int64 newSize,
        unsigned __int64 alignSize)
{
  unsigned __int64 MinSize; // rcx
  __int64 v10; // r10
  unsigned __int64 v11; // rbp
  unsigned __int64 v12; // rsi
  char *v14; // r15
  Scaleform::HeapPT::DualTNode *GrEq; // rax
  Scaleform::HeapPT::DualTNode *v16; // rbx
  char *v17; // rcx
  char *v18; // rbx

  MinSize = alignSize;
  if ( alignSize < this->MinSize )
    MinSize = this->MinSize;
  v10 = ~(MinSize - 1);
  v11 = v10 & (MinSize + oldSize - 1);
  v12 = v10 & (MinSize + newSize - 1);
  if ( v12 == v11 )
    return 0i64;
  if ( v12 <= v11 )
  {
    v18 = &ptr[v12];
    Scaleform::HeapPT::AllocLite::Free(this, seg, (Scaleform::HeapPT::DualTNode *)&ptr[v12], v11 - v12, MinSize);
    return &ptr[(*((_QWORD *)v18 + 9) << this->MinShift) + v12] == &seg->Buffer[seg->Size];
  }
  v14 = &ptr[v11];
  GrEq = Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::FindGrEq(
           &this->AddrTree,
           (unsigned __int64)&ptr[v11]);
  v16 = GrEq;
  if ( !GrEq || GrEq->ParentSeg != seg || GrEq != (Scaleform::HeapPT::DualTNode *)v14 )
    return (unsigned int)(v14 == &seg->Buffer[seg->Size]) + 2;
  v17 = (char *)GrEq + (GrEq->Size << this->MinShift);
  if ( &ptr[v12] > v17 )
  {
    if ( v17 == &seg->Buffer[seg->Size] )
      return 3i64;
    return (unsigned int)(v14 == &seg->Buffer[seg->Size]) + 2;
  }
  Scaleform::HeapPT::AllocLite::pullNode(this, GrEq);
  Scaleform::HeapPT::AllocLite::splitNode(this, v16, (char *)v16, v12 - v11);
  return 0i64;
}

// File Line: 344
// RVA: 0x977EF0
void __fastcall Scaleform::HeapPT::AllocLite::Extend(
        Scaleform::HeapPT::AllocLite *this,
        Scaleform::HeapPT::TreeSeg *seg,
        unsigned __int64 incSize)
{
  char *v5; // rbp
  Scaleform::HeapPT::DualTNode *LeEq; // rax
  Scaleform::HeapPT::DualTNode *v8; // rsi
  unsigned __int64 Size; // rax
  Scaleform::HeapPT::DualTNode *v10; // rdx
  unsigned __int64 v11; // r9

  v5 = &seg->Buffer[seg->Size];
  LeEq = Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::FindLeEq(
           &this->AddrTree,
           (unsigned __int64)(v5 - 1));
  v8 = LeEq;
  if ( LeEq && LeEq->ParentSeg == seg && (Size = LeEq->Size, (char *)v8 + (Size << this->MinShift) == v5) )
  {
    this->FreeBlocks -= Size;
    Scaleform::RadixTreeMulti<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor>::Remove(
      &this->SizeTree,
      v8);
    Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::Remove(
      &this->AddrTree,
      v8);
    v10 = v8;
    v11 = v8->Size + (incSize >> this->MinShift);
  }
  else
  {
    v10 = (Scaleform::HeapPT::DualTNode *)v5;
    v11 = incSize >> this->MinShift;
  }
  Scaleform::HeapPT::AllocLite::pushNode(this, v10, seg, v11);
  seg->Size += incSize;
}

// File Line: 365
// RVA: 0x9BACE0
char __fastcall Scaleform::HeapPT::AllocLite::TrimAt(
        Scaleform::HeapPT::AllocLite *this,
        Scaleform::HeapPT::TreeSeg *seg,
        char *ptrAt)
{
  Scaleform::HeapPT::DualTNode *LeEq; // rax
  Scaleform::HeapPT::DualTNode *v7; // rbx
  unsigned __int64 v8; // rsi

  LeEq = Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::FindLeEq(
           &this->AddrTree,
           (unsigned __int64)ptrAt);
  v7 = LeEq;
  if ( !LeEq || LeEq->ParentSeg != seg || ptrAt < (char *)LeEq || ptrAt >= (char *)LeEq + (LeEq->Size << this->MinShift) )
    return 0;
  Scaleform::HeapPT::AllocLite::pullNode(this, LeEq);
  v8 = (unsigned __int64)v7 + (v7->Size << this->MinShift) - (_QWORD)ptrAt;
  if ( v7 < (Scaleform::HeapPT::DualTNode *)ptrAt )
  {
    Scaleform::HeapPT::AllocLite::pushNode(this, v7, seg, (ptrAt - (char *)v7) >> this->MinShift);
    *((_QWORD *)ptrAt + 8) = seg;
    *((_QWORD *)ptrAt + 9) = v8 >> this->MinShift;
  }
  seg->Size -= v8;
  return 1;
}

// File Line: 393
// RVA: 0x9FAFA0
void __fastcall Scaleform::HeapPT::AllocLite::visitTree(
        Scaleform::HeapPT::AllocLite *this,
        Scaleform::HeapPT::DualTNode *root,
        Scaleform::Heap::HeapSegment *seg,
        Scaleform::Heap::MemVisitor *visitor,
        Scaleform::Heap::MemVisitor::Category cat)
{
  Scaleform::HeapPT::DualTNode *v7; // rdi
  Scaleform::HeapPT::DualTNode *pNext; // rbx
  Scaleform::HeapPT::AllocLite *v9; // [rsp+40h] [rbp+8h]

  if ( root )
  {
    v9 = this;
    v7 = root;
    do
    {
      Scaleform::HeapPT::AllocLite::visitTree(this, v7->Child[0], seg, visitor, cat);
      pNext = v7;
      do
      {
        seg->DataSize = pNext->ParentSeg->Size;
        seg->pData = pNext->ParentSeg->Buffer;
        visitor->vfptr->Visit(visitor, seg, (unsigned __int64)pNext, pNext->Size << v9->MinShift, cat);
        pNext = pNext->pNext;
      }
      while ( pNext != v7 );
      v7 = v7->Child[1];
      this = v9;
    }
    while ( v7 );
  }
}

// File Line: 443
// RVA: 0x9FB100
void __fastcall Scaleform::HeapPT::AllocLite::visitUnusedInTree(
        Scaleform::HeapPT::AllocLite *this,
        Scaleform::HeapPT::DualTNode *root,
        Scaleform::Heap::SegVisitor *visitor,
        unsigned int cat)
{
  Scaleform::HeapPT::DualTNode *v6; // rdi
  Scaleform::HeapPT::AllocLite *v7; // rax
  Scaleform::HeapPT::DualTNode *pNext; // rbx

  if ( root )
  {
    v6 = root;
    v7 = this;
    do
    {
      Scaleform::HeapPT::AllocLite::visitUnusedInTree(v7, v6->Child[0], visitor, cat);
      pNext = v6;
      do
      {
        if ( (((unsigned __int64)&pNext[51].pVoidNext + 7) & 0xFFFFFFFFFFFFF000ui64) + 4096 <= (((unsigned __int64)pNext
                                                                                               + (pNext->Size << this->MinShift)) & 0xFFFFFFFFFFFFF000ui64) )
          ((void (__fastcall *)(Scaleform::Heap::SegVisitor *, _QWORD, _QWORD))visitor->vfptr->Visit)(
            visitor,
            cat,
            0i64);
        pNext = pNext->pNext;
      }
      while ( pNext != v6 );
      v6 = v6->Child[1];
      v7 = this;
    }
    while ( v6 );
  }
}

