// File Line: 30
// RVA: 0x938AF0
void __fastcall Scaleform::AllocAddr::AllocAddr(Scaleform::AllocAddr *this, Scaleform::MemoryHeap *nodeHeap)
{
  this->pNodeHeap = nodeHeap;
  this->SizeTree.Tree.Root = 0i64;
  this->AddrTree.Root = 0i64;
}

// File Line: 42
// RVA: 0x948CF0
void __fastcall Scaleform::AllocAddr::~AllocAddr(Scaleform::AllocAddr *this)
{
  Scaleform::AllocAddr::destroyAll(this);
}

// File Line: 48
// RVA: 0x9E9660
void __fastcall Scaleform::linearizeTree(Scaleform::AllocAddrNode *root, Scaleform::List<Scaleform::AllocAddrNode,Scaleform::AllocAddrNode> *nodes)
{
  Scaleform::List<Scaleform::AllocAddrNode,Scaleform::AllocAddrNode> *v2; // rdi
  Scaleform::AllocAddrNode *v3; // rbx
  Scaleform::AllocAddrNode *v4; // rax

  if ( root )
  {
    v2 = nodes;
    v3 = root;
    do
    {
      Scaleform::linearizeTree(v3->AddrChild[0], v2);
      v4 = v2->Root.pPrev;
      v3->pNext = (Scaleform::AllocAddrNode *)v2;
      v3->pPrev = v4;
      v2->Root.pPrev->pNext = v3;
      v2->Root.pPrev = v3;
      v3 = v3->AddrChild[1];
    }
    while ( v3 );
  }
}

// File Line: 59
// RVA: 0x9DF7A0
void __fastcall Scaleform::AllocAddr::destroyAll(Scaleform::AllocAddr *this)
{
  Scaleform::AllocAddrNode *v1; // r9
  Scaleform::AllocAddr *v2; // rbx
  Scaleform::List<Scaleform::AllocAddrNode,Scaleform::AllocAddrNode> *v3; // rax
  Scaleform::AllocAddrNode *v4; // r9
  Scaleform::List<Scaleform::AllocAddrNode,Scaleform::AllocAddrNode> nodes; // [rsp+20h] [rbp-18h]

  v1 = this->AddrTree.Root;
  v2 = this;
  nodes.Root.pPrev = (Scaleform::AllocAddrNode *)&nodes;
  v3 = &nodes;
  nodes.Root.pNext = (Scaleform::AllocAddrNode *)&nodes;
  if ( v1 )
  {
    Scaleform::linearizeTree(v1->AddrChild[0], &nodes);
    v4->pPrev = nodes.Root.pPrev;
    v4->pNext = (Scaleform::AllocAddrNode *)&nodes;
    nodes.Root.pPrev->pNext = v4;
    nodes.Root.pPrev = v4;
    Scaleform::linearizeTree(v4->AddrChild[1], &nodes);
    v3 = (Scaleform::List<Scaleform::AllocAddrNode,Scaleform::AllocAddrNode> *)nodes.Root.pNext;
  }
  v2->AddrTree.Root = 0i64;
  v2->SizeTree.Tree.Root = 0i64;
  if ( v3 != &nodes )
  {
    do
    {
      v3->Root.pPrev->pNext = v3->Root.pNext;
      v3->Root.pNext->pPrev = v3->Root.pPrev;
      v2->pNodeHeap->vfptr->Free(v2->pNodeHeap, v3);
      v3 = (Scaleform::List<Scaleform::AllocAddrNode,Scaleform::AllocAddrNode> *)nodes.Root.pNext;
    }
    while ( (Scaleform::List<Scaleform::AllocAddrNode,Scaleform::AllocAddrNode> *)nodes.Root.pNext != &nodes );
  }
}

// File Line: 75
// RVA: 0x9EE740
void __fastcall Scaleform::AllocAddr::pushNode(Scaleform::AllocAddr *this, Scaleform::AllocAddrNode *node, unsigned __int64 addr, unsigned __int64 size)
{
  Scaleform::AllocAddr *v4; // rbx
  Scaleform::AllocAddrNode *v5; // rdi
  Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor> *v6; // rax
  unsigned __int64 v7; // r9
  Scaleform::AllocAddrNode *v8; // rax
  unsigned __int64 v9; // rdx
  unsigned __int64 v10; // rcx
  signed __int64 v11; // r8
  Scaleform::AllocAddrNode *v12; // rcx

  v4 = this;
  v5 = node;
  node->Addr = addr;
  node->Size = size;
  Scaleform::RadixTreeMulti<Scaleform::AllocAddrNode,Scaleform::AllocAddr::SizeAccessor>::Insert(&this->SizeTree, node);
  v6 = &v4->AddrTree;
  v5->AddrChild[1] = 0i64;
  v5->AddrChild[0] = 0i64;
  v5->AddrParent = 0i64;
  if ( v4->AddrTree.Root )
  {
    v7 = v5->Addr;
    v8 = v6->Root;
    v9 = v7;
    if ( v8->Addr != v7 )
    {
      while ( 1 )
      {
        v10 = v9;
        v9 *= 2i64;
        v10 >>= 63;
        v11 = (signed __int64)v8 + 8 * v10;
        v12 = v8->AddrChild[v10];
        if ( !v12 )
          break;
        v8 = v12;
        if ( v12->Addr == v7 )
          return;
      }
      *(_QWORD *)(v11 + 24) = v5;
      v5->AddrParent = v8;
    }
  }
  else
  {
    v6->Root = v5;
    v5->AddrParent = (Scaleform::AllocAddrNode *)v6;
  }
}

// File Line: 105
// RVA: 0x9F31F0
void __fastcall Scaleform::AllocAddr::splitNode(Scaleform::AllocAddr *this, Scaleform::AllocAddrNode *node, unsigned __int64 addr, unsigned __int64 size)
{
  unsigned __int64 v4; // rsi
  unsigned __int64 v5; // r8
  unsigned __int64 v6; // rbp
  Scaleform::AllocAddr *v7; // rdi
  unsigned __int64 v8; // rbx
  unsigned __int64 v9; // r9
  Scaleform::AllocAddrNode *v10; // rax

  v4 = addr;
  v5 = node->Addr;
  v6 = size;
  v7 = this;
  v8 = v5 + node->Size - v4 - size;
  v9 = v4 - v5;
  if ( v4 == v5 )
  {
    if ( v8 )
      Scaleform::AllocAddr::pushNode(this, node, v4 + v6, v8);
    else
      ((void (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::AllocAddrNode *, unsigned __int64, unsigned __int64))this->pNodeHeap->vfptr->Free)(
        this->pNodeHeap,
        node,
        v5,
        v9);
  }
  else
  {
    Scaleform::AllocAddr::pushNode(this, node, v5, v9);
    if ( v8 )
    {
      v10 = (Scaleform::AllocAddrNode *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v7->pNodeHeap->vfptr->Alloc)(
                                          v7->pNodeHeap,
                                          80i64);
      Scaleform::AllocAddr::pushNode(v7, v10, v4 + v6, v8);
    }
  }
}

// File Line: 131
// RVA: 0x9E9850
unsigned __int64 __fastcall Scaleform::AllocAddr::mergeNodes(Scaleform::AllocAddr *this, Scaleform::AllocAddrNode *prev, Scaleform::AllocAddrNode *next, unsigned __int64 addr, unsigned __int64 size)
{
  unsigned __int64 v5; // rdi
  Scaleform::AllocAddrNode *v6; // rbp
  Scaleform::AllocAddrNode *v7; // r15
  Scaleform::AllocAddr *v8; // r14
  Scaleform::RadixTreeMulti<Scaleform::AllocAddrNode,Scaleform::AllocAddr::SizeAccessor> *v9; // rcx
  unsigned __int64 v10; // rsi
  unsigned __int64 result; // rax
  unsigned __int64 v12; // rbx
  unsigned __int64 v13; // rbx
  Scaleform::AllocAddrNode *v14; // rax

  v5 = addr;
  v6 = next;
  v7 = prev;
  v8 = this;
  if ( prev )
  {
    v9 = &this->SizeTree;
    if ( next )
    {
      v10 = size + next->Size + prev->Size;
      Scaleform::RadixTreeMulti<Scaleform::AllocAddrNode,Scaleform::AllocAddr::SizeAccessor>::Remove(v9, prev);
      Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor>::Remove(
        (Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor> *)&v8->AddrTree,
        (Scaleform::HeapPT::DualTNode *)v7);
      Scaleform::RadixTreeMulti<Scaleform::AllocAddrNode,Scaleform::AllocAddr::SizeAccessor>::Remove(&v8->SizeTree, v6);
      Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor>::Remove(
        (Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor> *)&v8->AddrTree,
        (Scaleform::HeapPT::DualTNode *)v6);
      Scaleform::AllocAddr::pushNode(v8, v7, v7->Addr, v10);
      v8->pNodeHeap->vfptr->Free(v8->pNodeHeap, v6);
      result = v10;
    }
    else
    {
      v12 = prev->Size + size;
      Scaleform::RadixTreeMulti<Scaleform::AllocAddrNode,Scaleform::AllocAddr::SizeAccessor>::Remove(v9, prev);
      Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor>::Remove(
        (Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor> *)&v8->AddrTree,
        (Scaleform::HeapPT::DualTNode *)v7);
      Scaleform::AllocAddr::pushNode(v8, v7, v7->Addr, v12);
      result = v12;
    }
  }
  else if ( next )
  {
    v13 = next->Size + size;
    Scaleform::RadixTreeMulti<Scaleform::AllocAddrNode,Scaleform::AllocAddr::SizeAccessor>::Remove(
      &this->SizeTree,
      next);
    Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor>::Remove(
      (Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor> *)&v8->AddrTree,
      (Scaleform::HeapPT::DualTNode *)v6);
    Scaleform::AllocAddr::pushNode(v8, v6, v5, v13);
    result = v13;
  }
  else
  {
    v14 = (Scaleform::AllocAddrNode *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))this->pNodeHeap->vfptr->Alloc)(
                                        this->pNodeHeap,
                                        80i64);
    Scaleform::AllocAddr::pushNode(v8, v14, v5, size);
    result = size;
  }
  return result;
}

// File Line: 176
// RVA: 0x955840
unsigned __int64 __fastcall Scaleform::AllocAddr::Alloc(Scaleform::AllocAddr *this, unsigned __int64 size)
{
  Scaleform::AllocAddr *v2; // rsi
  unsigned __int64 v3; // rbp
  Scaleform::AllocAddrNode *v4; // rax
  Scaleform::AllocAddrNode *v5; // rdi
  unsigned __int64 v6; // rbx

  v2 = this;
  v3 = size;
  v4 = Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::SizeAccessor>::FindGrEq(
         &this->SizeTree.Tree,
         size);
  if ( !v4 )
    return -1i64;
  v5 = v4->pNext;
  Scaleform::RadixTreeMulti<Scaleform::AllocAddrNode,Scaleform::AllocAddr::SizeAccessor>::Remove(
    &v2->SizeTree,
    v4->pNext);
  if ( !v5 )
    return -1i64;
  Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor>::Remove(
    (Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor> *)&v2->AddrTree,
    (Scaleform::HeapPT::DualTNode *)v5);
  v6 = v5->Addr;
  Scaleform::AllocAddr::splitNode(v2, v5, v5->Addr, v3);
  return v6;
}

// File Line: 235
// RVA: 0x97D340
unsigned __int64 __fastcall Scaleform::AllocAddr::Free(Scaleform::AllocAddr *this, unsigned __int64 addr, unsigned __int64 size)
{
  unsigned __int64 v3; // rbp
  unsigned __int64 v4; // rsi
  Scaleform::AllocAddr *v5; // r14
  unsigned __int64 v7; // r15
  Scaleform::AllocAddrNode *v8; // rdi
  Scaleform::AllocAddrNode *v9; // rax

  v3 = size;
  v4 = addr;
  v5 = this;
  if ( !size )
    return 0i64;
  v7 = addr + size;
  v8 = Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor>::FindLeEq(
         &this->AddrTree,
         addr);
  v9 = Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor>::FindGrEq(
         &v5->AddrTree,
         v4 + v3);
  if ( !v8 || v8->Addr + v8->Size != v4 )
    v8 = 0i64;
  if ( !v9 || v9->Addr != v7 )
    v9 = 0i64;
  return Scaleform::AllocAddr::mergeNodes(v5, v8, v9, v4, v3);
}

// File Line: 265
// RVA: 0x954A60
void __fastcall Scaleform::AllocAddr::AddSegment(Scaleform::AllocAddr *this, unsigned __int64 addr, unsigned __int64 size)
{
  Scaleform::AllocAddr::Free(this, addr, size);
}

// File Line: 271
// RVA: 0x9AA450
void __fastcall Scaleform::AllocAddr::RemoveSegment(Scaleform::AllocAddr *this, unsigned __int64 addr, unsigned __int64 size)
{
  Scaleform::AllocAddr *v3; // r14
  unsigned __int64 v4; // rsi
  unsigned __int64 v5; // rbp
  Scaleform::AllocAddrNode *v6; // rdi

  v3 = this;
  v4 = size;
  v5 = addr;
  v6 = Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor>::FindLeEq(
         &this->AddrTree,
         addr);
  Scaleform::RadixTreeMulti<Scaleform::AllocAddrNode,Scaleform::AllocAddr::SizeAccessor>::Remove(&v3->SizeTree, v6);
  Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor>::Remove(
    (Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor> *)&v3->AddrTree,
    (Scaleform::HeapPT::DualTNode *)v6);
  Scaleform::AllocAddr::splitNode(v3, v6, v5, v4);
}

// File Line: 281
// RVA: 0x9D5660
void __fastcall Scaleform::calcTreeSize(Scaleform::AllocAddrNode *node, unsigned __int64 *size)
{
  unsigned __int64 *v2; // rdi
  Scaleform::AllocAddrNode *v3; // rbx

  if ( node )
  {
    v2 = size;
    v3 = node;
    do
    {
      *v2 += v3->Size;
      Scaleform::calcTreeSize(v3->AddrChild[0], v2);
      v3 = v3->AddrChild[1];
    }
    while ( v3 );
  }
}

// File Line: 292
// RVA: 0x984D00
unsigned __int64 __fastcall Scaleform::AllocAddr::GetFreeSize(Scaleform::AllocAddr *this)
{
  Scaleform::AllocAddrNode *v1; // r8
  __int64 v2; // r8
  unsigned __int64 size; // [rsp+30h] [rbp+8h]

  v1 = this->AddrTree.Root;
  size = 0i64;
  if ( !v1 )
    return 0i64;
  size = v1->Size;
  Scaleform::calcTreeSize(v1->AddrChild[0], &size);
  Scaleform::calcTreeSize(*(Scaleform::AllocAddrNode **)(v2 + 32), &size);
  return size;
}

