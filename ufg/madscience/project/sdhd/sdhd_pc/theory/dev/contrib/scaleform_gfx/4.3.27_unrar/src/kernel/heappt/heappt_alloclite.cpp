// File Line: 52
// RVA: 0x9EE7E0
void __fastcall Scaleform::HeapPT::AllocLite::pushNode(Scaleform::HeapPT::AllocLite *this, Scaleform::HeapPT::DualTNode *node, Scaleform::HeapPT::TreeSeg *seg, unsigned __int64 blocks)
{
  Scaleform::HeapPT::AllocLite *v4; // rdi
  unsigned __int64 v5; // rsi
  Scaleform::HeapPT::DualTNode *v6; // rbx
  Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor> *v7; // rax
  Scaleform::HeapPT::DualTNode *v8; // rdx
  Scaleform::HeapPT::DualTNode *v9; // rcx
  signed __int64 v10; // r8
  Scaleform::HeapPT::DualTNode *v11; // rcx

  v4 = this;
  v5 = blocks;
  v6 = node;
  node->Size = blocks;
  node->ParentSeg = seg;
  Scaleform::RadixTreeMulti<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor>::Insert(
    &this->SizeTree,
    node);
  v7 = &v4->AddrTree;
  v6->AddrChild[1] = 0i64;
  v6->AddrChild[0] = 0i64;
  v6->AddrParent = 0i64;
  if ( !v4->AddrTree.Root )
  {
    v7->Root = v6;
LABEL_8:
    v6->AddrParent = (Scaleform::HeapPT::DualTNode *)v7;
    goto LABEL_9;
  }
  v7 = (Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor> *)v7->Root;
  v8 = v6;
  if ( v7 != (Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor> *)v6 )
  {
    while ( 1 )
    {
      v9 = v8;
      v8 = (Scaleform::HeapPT::DualTNode *)(2i64 * (_QWORD)v8);
      v9 = (Scaleform::HeapPT::DualTNode *)((unsigned __int64)v9 >> 63);
      v10 = (signed __int64)&v7[(_QWORD)v9];
      v11 = v7[(_QWORD)v9 + 6].Root;
      if ( !v11 )
        break;
      v7 = (Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor> *)v11;
      if ( v11 == v6 )
        goto LABEL_9;
    }
    *(_QWORD *)(v10 + 48) = v6;
    goto LABEL_8;
  }
LABEL_9:
  v4->FreeBlocks += v5;
}

// File Line: 63
// RVA: 0x9EE700
void __fastcall Scaleform::HeapPT::AllocLite::pullNode(Scaleform::HeapPT::AllocLite *this, Scaleform::HeapPT::DualTNode *node)
{
  Scaleform::HeapPT::AllocLite *v2; // rbx
  Scaleform::RadixTreeMulti<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor> *v3; // rcx
  Scaleform::HeapPT::DualTNode *v4; // rdi

  v2 = this;
  v3 = &this->SizeTree;
  v3[2].Tree.Root = (Scaleform::HeapPT::DualTNode *)((char *)v3[2].Tree.Root - node->Size);
  v4 = node;
  Scaleform::RadixTreeMulti<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor>::Remove(v3, node);
  Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::Remove(
    &v2->AddrTree,
    v4);
}

// File Line: 86
// RVA: 0x9EE530
Scaleform::HeapPT::DualTNode *__fastcall Scaleform::HeapPT::AllocLite::pullBest(Scaleform::HeapPT::AllocLite *this, unsigned __int64 blocks, unsigned __int64 alignMask)
{
  unsigned __int64 v3; // rdi
  unsigned __int64 v4; // rsi
  Scaleform::HeapPT::AllocLite *v5; // r14
  Scaleform::HeapPT::DualTNode *v6; // rax
  Scaleform::HeapPT::DualTNode *v7; // rbx
  Scaleform::HeapPT::DualTNode *v9; // r9
  unsigned __int64 v10; // r15
  unsigned __int64 v11; // rbp
  unsigned __int64 v12; // rsi
  unsigned __int64 v13; // r8
  unsigned __int64 v14; // rax
  Scaleform::HeapPT::DualTNode *v15; // rcx
  Scaleform::HeapPT::DualTNode *v16; // rax
  Scaleform::HeapPT::DualTNode *v17; // rdx
  Scaleform::HeapPT::DualTNode *v18; // rax
  Scaleform::HeapPT::DualTNode *v19; // rax

  v3 = alignMask;
  v4 = blocks;
  v5 = this;
  if ( alignMask > this->MinMask )
  {
    v7 = Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor>::FindGrEq(
           &this->SizeTree.Tree,
           blocks);
    v9 = v7;
    if ( v7 )
    {
      v10 = v5->MinShift;
      v11 = ~v3;
      v12 = v4 << v5->MinShift;
      while ( 1 )
      {
        v13 = v11 & ((unsigned __int64)v7 + v3);
        v14 = (v11 & ((unsigned __int64)v7 + v3)) - (_QWORD)v7;
        if ( (Scaleform::HeapPT::DualTNode *)(v11 & ((unsigned __int64)v7 + v3)) != v7 )
        {
          do
          {
            if ( v14 >= 0x80 )
              break;
            v13 += v3 + 1;
            v14 += v3 + 1;
          }
          while ( v14 );
        }
        if ( v13 + v12 <= (unsigned __int64)v7 + (v7->Size << v10) )
          break;
        v7 = v7->pNext;
        if ( v7 == v9 )
        {
          v7 = Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor>::FindGrEq(
                 &v5->SizeTree.Tree,
                 v7->Size + 1);
          v9 = v7;
          if ( !v7 )
            return v7;
        }
      }
      v15 = v7->pPrev;
      if ( v7->pPrev == v7 )
      {
        Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor>::Remove(
          &v5->SizeTree.Tree,
          v7);
      }
      else
      {
        v16 = v7->pNext;
        v16->pPrev = v15;
        v15->pNext = v16;
        v17 = v7->Parent;
        if ( v17 )
        {
          if ( v7 == v5->SizeTree.Tree.Root )
            v5->SizeTree.Tree.Root = v15;
          else
            v17->Child[v7->Parent->Child[0] != v7] = v15;
          v15->Parent = v17;
          v18 = v7->Child[0];
          if ( v18 )
          {
            v15->Child[0] = v18;
            v18->Parent = v15;
          }
          v19 = v7->Child[1];
          if ( v19 )
          {
            v15->Child[1] = v19;
            v19->Parent = v15;
          }
        }
        v7->Child[1] = 0i64;
        v7->Child[0] = 0i64;
        v7->Parent = 0i64;
      }
      Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::Remove(
        &v5->AddrTree,
        v7);
      v5->FreeBlocks -= v7->Size;
    }
  }
  else
  {
    v6 = Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor>::FindGrEq(
           &this->SizeTree.Tree,
           blocks);
    v7 = v6;
    if ( v6 )
    {
      v7 = v6->pNext;
      Scaleform::RadixTreeMulti<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor>::Remove(
        &v5->SizeTree,
        v6->pNext);
      if ( v7 )
      {
        Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::Remove(
          &v5->AddrTree,
          v7);
        v5->FreeBlocks -= v7->Size;
        return v7;
      }
    }
  }
  return v7;
}

// File Line: 149
// RVA: 0x9F3290
void __fastcall Scaleform::HeapPT::AllocLite::splitNode(Scaleform::HeapPT::AllocLite *this, Scaleform::HeapPT::DualTNode *node, char *start, unsigned __int64 size)
{
  Scaleform::HeapPT::TreeSeg *v4; // rsi
  unsigned __int64 v5; // rbp
  Scaleform::HeapPT::AllocLite *v6; // rdi
  unsigned __int64 v7; // rcx
  char *v8; // r14
  unsigned __int64 v9; // rbx

  v4 = node->ParentSeg;
  v5 = size;
  v6 = this;
  v7 = this->MinShift;
  v8 = start;
  v9 = (unsigned __int64)node + (node->Size << v7) - (_QWORD)start - size;
  if ( start != (char *)node )
    Scaleform::HeapPT::AllocLite::pushNode(v6, node, node->ParentSeg, (unsigned __int64)(start - (char *)node) >> v7);
  if ( v9 )
    Scaleform::HeapPT::AllocLite::pushNode(v6, (Scaleform::HeapPT::DualTNode *)&v8[v5], v4, v9 >> v6->MinShift);
}

// File Line: 197
// RVA: 0x956680
Scaleform::HeapPT::DualTNode *__fastcall Scaleform::HeapPT::AllocLite::Alloc(Scaleform::HeapPT::AllocLite *this, unsigned __int64 size, unsigned __int64 alignSize, Scaleform::HeapPT::TreeSeg **allocSeg)
{
  unsigned __int64 v4; // rax
  Scaleform::HeapPT::AllocLite *v5; // r14
  unsigned __int64 v6; // rcx
  Scaleform::HeapPT::TreeSeg **v7; // r15
  unsigned __int64 v8; // rdi
  unsigned __int64 v9; // rsi
  unsigned __int64 v10; // rbp
  Scaleform::HeapPT::DualTNode *result; // rax
  char *v12; // rbx
  unsigned __int64 v13; // rcx

  v4 = this->MinSize;
  v5 = this;
  v6 = this->MinShift;
  v7 = allocSeg;
  if ( size < v4 )
    size = v4;
  if ( alignSize < v4 )
    alignSize = v4;
  v8 = alignSize - 1;
  v9 = ~(alignSize - 1);
  v10 = v9 & (size + alignSize - 1);
  result = Scaleform::HeapPT::AllocLite::pullBest(v5, v10 >> v6, alignSize - 1);
  if ( result )
  {
    v12 = (char *)(v9 & ((unsigned __int64)result + v8));
    v13 = (v9 & ((unsigned __int64)result + v8)) - (_QWORD)result;
    if ( (Scaleform::HeapPT::DualTNode *)(v9 & ((unsigned __int64)result + v8)) != result )
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
    *v7 = result->ParentSeg;
    Scaleform::HeapPT::AllocLite::splitNode(v5, result, v12, v10);
    result = (Scaleform::HeapPT::DualTNode *)v12;
  }
  return result;
}

// File Line: 225
// RVA: 0x97DAC0
void __fastcall Scaleform::HeapPT::AllocLite::Free(Scaleform::HeapPT::AllocLite *this, Scaleform::HeapPT::TreeSeg *seg, void *ptr, unsigned __int64 size, unsigned __int64 alignSize)
{
  unsigned __int64 v5; // rax
  Scaleform::HeapPT::DualTNode *v6; // r14
  unsigned __int64 v7; // r8
  Scaleform::HeapPT::TreeSeg *v8; // r15
  Scaleform::HeapPT::AllocLite *v9; // rbx
  unsigned __int64 v10; // rbp
  Scaleform::HeapPT::DualTNode *v11; // rdi
  Scaleform::HeapPT::DualTNode *v12; // rax
  Scaleform::HeapPT::DualTNode *v13; // rsi
  unsigned __int64 v14; // rcx
  unsigned __int64 v15; // rbp
  unsigned __int64 v16; // rax
  unsigned __int64 v17; // rax

  v5 = alignSize;
  v6 = (Scaleform::HeapPT::DualTNode *)ptr;
  v7 = this->MinSize;
  v8 = seg;
  v9 = this;
  if ( size < v7 )
    size = this->MinSize;
  if ( alignSize < v7 )
    v5 = this->MinSize;
  v10 = ~(v5 - 1) & (size + v5 - 1);
  v11 = Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::FindLeEq(
          &this->AddrTree,
          (unsigned __int64)v6);
  v12 = Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::FindGrEq(
          &v9->AddrTree,
          (unsigned __int64)v6 + v10);
  v13 = v12;
  if ( !v11 || v11->ParentSeg != v8 || (Scaleform::HeapPT::DualTNode *)((char *)v11 + (v11->Size << v9->MinShift)) != v6 )
    v11 = 0i64;
  if ( !v12 || v12->ParentSeg != v8 || v12 != (Scaleform::HeapPT::DualTNode *)((char *)v6 + v10) )
    v13 = 0i64;
  v14 = v9->MinShift;
  v6->ParentSeg = v8;
  v15 = v10 >> v14;
  v6->Size = v15;
  if ( v11 )
  {
    v16 = v11->Size;
    v9->FreeBlocks -= v16;
    v15 += v16;
    v6 = v11;
    Scaleform::RadixTreeMulti<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor>::Remove(
      &v9->SizeTree,
      v11);
    Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::Remove(
      &v9->AddrTree,
      v11);
  }
  if ( v13 )
  {
    v17 = v13->Size;
    v9->FreeBlocks -= v17;
    v15 += v17;
    Scaleform::RadixTreeMulti<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor>::Remove(
      &v9->SizeTree,
      v13);
    Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::Remove(
      &v9->AddrTree,
      v13);
  }
  Scaleform::HeapPT::AllocLite::pushNode(v9, v6, v8, v15);
}

// File Line: 287
// RVA: 0x9A6CC0
signed __int64 __fastcall Scaleform::HeapPT::AllocLite::ReallocInPlace(Scaleform::HeapPT::AllocLite *this, Scaleform::HeapPT::TreeSeg *seg, void *ptr, unsigned __int64 oldSize, unsigned __int64 newSize, unsigned __int64 alignSize)
{
  Scaleform::HeapPT::AllocLite *v6; // r14
  unsigned __int64 v7; // rcx
  char *v8; // r12
  Scaleform::HeapPT::TreeSeg *v9; // rdi
  signed __int64 v10; // r10
  unsigned __int64 v11; // rbp
  unsigned __int64 v12; // rsi
  signed __int64 result; // rax
  Scaleform::HeapPT::DualTNode *v14; // r15
  Scaleform::HeapPT::DualTNode *v15; // rax
  Scaleform::HeapPT::DualTNode *v16; // rbx
  char *v17; // rcx
  char *v18; // rbx

  v6 = this;
  v7 = alignSize;
  v8 = (char *)ptr;
  if ( alignSize < v6->MinSize )
    v7 = v6->MinSize;
  v9 = seg;
  v10 = ~(v7 - 1);
  v11 = v10 & (v7 + oldSize - 1);
  v12 = v10 & (v7 + newSize - 1);
  if ( v12 == v11 )
    return 0i64;
  if ( v12 <= v11 )
  {
    v18 = (char *)ptr + v12;
    Scaleform::HeapPT::AllocLite::Free(v6, seg, (char *)ptr + v12, v11 - v12, v7);
    result = &v8[(*((_QWORD *)v18 + 9) << v6->MinShift) + v12] == &v9->Buffer[v9->Size];
  }
  else
  {
    v14 = (Scaleform::HeapPT::DualTNode *)((char *)ptr + v11);
    v15 = Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::FindGrEq(
            &v6->AddrTree,
            (unsigned __int64)ptr + v11);
    v16 = v15;
    if ( !v15 || v15->ParentSeg != v9 || v15 != v14 )
      goto LABEL_18;
    v17 = (char *)v15 + (v15->Size << v6->MinShift);
    if ( &v8[v12] <= v17 )
    {
      Scaleform::HeapPT::AllocLite::pullNode(v6, v15);
      Scaleform::HeapPT::AllocLite::splitNode(v6, v16, (char *)v16, v12 - v11);
      return 0i64;
    }
    if ( v17 == &v9->Buffer[v9->Size] )
      result = 3i64;
    else
LABEL_18:
      result = (unsigned int)(v14 == (Scaleform::HeapPT::DualTNode *)&v9->Buffer[v9->Size]) + 2;
  }
  return result;
}

// File Line: 344
// RVA: 0x977EF0
void __fastcall Scaleform::HeapPT::AllocLite::Extend(Scaleform::HeapPT::AllocLite *this, Scaleform::HeapPT::TreeSeg *seg, unsigned __int64 incSize)
{
  Scaleform::HeapPT::TreeSeg *v3; // rbx
  Scaleform::HeapPT::AllocLite *v4; // rdi
  char *v5; // rbp
  unsigned __int64 v6; // r14
  Scaleform::HeapPT::DualTNode *v7; // rax
  Scaleform::HeapPT::DualTNode *v8; // rsi
  unsigned __int64 v9; // rax
  Scaleform::HeapPT::DualTNode *v10; // rdx
  unsigned __int64 v11; // r9

  v3 = seg;
  v4 = this;
  v5 = &seg->Buffer[seg->Size];
  v6 = incSize;
  v7 = Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::FindLeEq(
         &this->AddrTree,
         (unsigned __int64)(v5 - 1));
  v8 = v7;
  if ( v7 && v7->ParentSeg == v3 && (v9 = v7->Size, (char *)v8 + (v9 << v4->MinShift) == v5) )
  {
    v4->FreeBlocks -= v9;
    Scaleform::RadixTreeMulti<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor>::Remove(
      &v4->SizeTree,
      v8);
    Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::Remove(
      &v4->AddrTree,
      v8);
    v10 = v8;
    v11 = v8->Size + (v6 >> v4->MinShift);
  }
  else
  {
    v10 = (Scaleform::HeapPT::DualTNode *)v5;
    v11 = v6 >> v4->MinShift;
  }
  Scaleform::HeapPT::AllocLite::pushNode(v4, v10, v3, v11);
  v3->Size += v6;
}

// File Line: 365
// RVA: 0x9BACE0
char __fastcall Scaleform::HeapPT::AllocLite::TrimAt(Scaleform::HeapPT::AllocLite *this, Scaleform::HeapPT::TreeSeg *seg, char *ptrAt)
{
  Scaleform::HeapPT::TreeSeg *v3; // rbp
  Scaleform::HeapPT::AllocLite *v4; // r14
  char *v5; // rdi
  Scaleform::HeapPT::DualTNode *v6; // rax
  Scaleform::HeapPT::DualTNode *v7; // rbx
  unsigned __int64 v8; // rcx
  unsigned __int64 v9; // rsi

  v3 = seg;
  v4 = this;
  v5 = ptrAt;
  v6 = Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::FindLeEq(
         &this->AddrTree,
         (unsigned __int64)ptrAt);
  v7 = v6;
  if ( !v6 || v6->ParentSeg != v3 || v5 < (char *)v6 || v5 >= (char *)v6 + (v6->Size << v4->MinShift) )
    return 0;
  Scaleform::HeapPT::AllocLite::pullNode(v4, v6);
  v8 = v4->MinShift;
  v9 = (unsigned __int64)v7 + (v7->Size << v4->MinShift) - (_QWORD)v5;
  if ( v7 < (Scaleform::HeapPT::DualTNode *)v5 )
  {
    Scaleform::HeapPT::AllocLite::pushNode(v4, v7, v3, (v5 - (char *)v7) >> v8);
    *((_QWORD *)v5 + 8) = v3;
    *((_QWORD *)v5 + 9) = v9 >> v4->MinShift;
  }
  v3->Size -= v9;
  return 1;
}

// File Line: 393
// RVA: 0x9FAFA0
void __fastcall Scaleform::HeapPT::AllocLite::visitTree(Scaleform::HeapPT::AllocLite *this, Scaleform::HeapPT::DualTNode *root, Scaleform::Heap::HeapSegment *seg, Scaleform::Heap::MemVisitor *visitor, Scaleform::Heap::MemVisitor::Category cat)
{
  Scaleform::Heap::MemVisitor *v5; // rbp
  Scaleform::Heap::HeapSegment *v6; // rsi
  Scaleform::HeapPT::DualTNode *v7; // rdi
  Scaleform::HeapPT::DualTNode *v8; // rbx
  _QWORD v9[3]; // [rsp+20h] [rbp-18h]
  Scaleform::HeapPT::AllocLite *v10; // [rsp+40h] [rbp+8h]

  if ( root )
  {
    v10 = this;
    v5 = visitor;
    v6 = seg;
    v7 = root;
    do
    {
      Scaleform::HeapPT::AllocLite::visitTree(this, v7->Child[0], v6, v5, cat);
      v8 = v7;
      do
      {
        v6->DataSize = v8->ParentSeg->Size;
        v6->pData = v8->ParentSeg->Buffer;
        LODWORD(v9[0]) = cat;
        v5->vfptr->Visit(
          v5,
          v6,
          (unsigned __int64)v8,
          v8->Size << v10->MinShift,
          (Scaleform::Heap::MemVisitor::Category)v9[0]);
        v8 = v8->pNext;
      }
      while ( v8 != v7 );
      v7 = v7->Child[1];
      this = v10;
    }
    while ( v7 );
  }
}

// File Line: 443
// RVA: 0x9FB100
void __fastcall Scaleform::HeapPT::AllocLite::visitUnusedInTree(Scaleform::HeapPT::AllocLite *this, Scaleform::HeapPT::DualTNode *root, Scaleform::Heap::SegVisitor *visitor, unsigned int cat)
{
  unsigned int v4; // ebp
  Scaleform::Heap::SegVisitor *v5; // rsi
  Scaleform::HeapPT::DualTNode *v6; // rdi
  Scaleform::HeapPT::AllocLite *v7; // rax
  Scaleform::HeapPT::DualTNode *v8; // rbx
  Scaleform::HeapPT::AllocLite *v9; // [rsp+40h] [rbp+8h]

  if ( root )
  {
    v9 = this;
    v4 = cat;
    v5 = visitor;
    v6 = root;
    v7 = this;
    do
    {
      Scaleform::HeapPT::AllocLite::visitUnusedInTree(v7, v6->Child[0], v5, v4);
      v8 = v6;
      do
      {
        if ( (((unsigned __int64)&v8[51].pVoidNext + 7) & 0xFFFFFFFFFFFFF000ui64) + 4096 <= (((unsigned __int64)v8
                                                                                            + (v8->Size << v9->MinShift)) & 0xFFFFFFFFFFFFF000ui64) )
          ((void (__fastcall *)(Scaleform::Heap::SegVisitor *, _QWORD, _QWORD))v5->vfptr->Visit)(v5, v4, 0i64);
        v8 = v8->pNext;
      }
      while ( v8 != v6 );
      v6 = v6->Child[1];
      v7 = v9;
    }
    while ( v6 );
  }
}

