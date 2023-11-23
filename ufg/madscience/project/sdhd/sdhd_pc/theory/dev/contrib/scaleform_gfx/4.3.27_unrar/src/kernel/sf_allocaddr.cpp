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
// attributes: thunk
void __fastcall Scaleform::AllocAddr::~AllocAddr(Scaleform::AllocAddr *this)
{
  Scaleform::AllocAddr::destroyAll(this);
}

// File Line: 48
// RVA: 0x9E9660
void __fastcall Scaleform::linearizeTree(
        Scaleform::AllocAddrNode *root,
        Scaleform::List<Scaleform::AllocAddrNode,Scaleform::AllocAddrNode> *nodes)
{
  Scaleform::AllocAddrNode *v3; // rbx
  Scaleform::AllocAddrNode *pPrev; // rax

  if ( root )
  {
    v3 = root;
    do
    {
      Scaleform::linearizeTree(v3->AddrChild[0], nodes);
      pPrev = nodes->Root.pPrev;
      v3->pNext = (Scaleform::AllocAddrNode *)nodes;
      v3->pPrev = pPrev;
      nodes->Root.pPrev->pNext = v3;
      nodes->Root.pPrev = v3;
      v3 = v3->AddrChild[1];
    }
    while ( v3 );
  }
}

// File Line: 59
// RVA: 0x9DF7A0
void __fastcall Scaleform::AllocAddr::destroyAll(Scaleform::AllocAddr *this)
{
  Scaleform::AllocAddrNode *Root; // r9
  Scaleform::List<Scaleform::AllocAddrNode,Scaleform::AllocAddrNode> *p_nodes; // rax
  Scaleform::AllocAddrNode *v4; // r9
  Scaleform::List<Scaleform::AllocAddrNode,Scaleform::AllocAddrNode> nodes; // [rsp+20h] [rbp-18h] BYREF

  Root = this->AddrTree.Root;
  nodes.Root.pPrev = (Scaleform::AllocAddrNode *)&nodes;
  p_nodes = &nodes;
  nodes.Root.pNext = (Scaleform::AllocAddrNode *)&nodes;
  if ( Root )
  {
    Scaleform::linearizeTree(Root->AddrChild[0], &nodes);
    v4->pPrev = nodes.Root.pPrev;
    v4->pNext = (Scaleform::AllocAddrNode *)&nodes;
    nodes.Root.pPrev->pNext = v4;
    nodes.Root.pPrev = v4;
    Scaleform::linearizeTree(v4->AddrChild[1], &nodes);
    p_nodes = (Scaleform::List<Scaleform::AllocAddrNode,Scaleform::AllocAddrNode> *)nodes.Root.pNext;
  }
  this->AddrTree.Root = 0i64;
  this->SizeTree.Tree.Root = 0i64;
  if ( p_nodes != &nodes )
  {
    do
    {
      p_nodes->Root.pPrev->pNext = p_nodes->Root.pNext;
      p_nodes->Root.pNext->pPrev = p_nodes->Root.pPrev;
      this->pNodeHeap->vfptr->Free(this->pNodeHeap, p_nodes);
      p_nodes = (Scaleform::List<Scaleform::AllocAddrNode,Scaleform::AllocAddrNode> *)nodes.Root.pNext;
    }
    while ( (Scaleform::List<Scaleform::AllocAddrNode,Scaleform::AllocAddrNode> *)nodes.Root.pNext != &nodes );
  }
}

// File Line: 75
// RVA: 0x9EE740
void __fastcall Scaleform::AllocAddr::pushNode(
        Scaleform::AllocAddr *this,
        Scaleform::AllocAddrNode *node,
        unsigned __int64 addr,
        unsigned __int64 size)
{
  Scaleform::AllocAddrNode *p_AddrTree; // rax
  unsigned __int64 v7; // r9
  Scaleform::AllocAddrNode *pPrev; // rax
  unsigned __int64 v9; // rdx
  unsigned __int64 v10; // rcx
  Scaleform::AllocAddrNode **v11; // r8
  Scaleform::AllocAddrNode *v12; // rcx

  node->Addr = addr;
  node->Size = size;
  Scaleform::RadixTreeMulti<Scaleform::AllocAddrNode,Scaleform::AllocAddr::SizeAccessor>::Insert(&this->SizeTree, node);
  p_AddrTree = (Scaleform::AllocAddrNode *)&this->AddrTree;
  node->AddrChild[1] = 0i64;
  node->AddrChild[0] = 0i64;
  node->AddrParent = 0i64;
  if ( this->AddrTree.Root )
  {
    v7 = node->Addr;
    pPrev = p_AddrTree->pPrev;
    v9 = v7;
    if ( pPrev->Addr != v7 )
    {
      while ( 1 )
      {
        v10 = v9;
        v9 *= 2i64;
        v11 = &pPrev->pPrev + (v10 >> 63);
        v12 = v11[3];
        if ( !v12 )
          break;
        pPrev = v11[3];
        if ( v12->Addr == v7 )
          return;
      }
      v11[3] = node;
      node->AddrParent = pPrev;
    }
  }
  else
  {
    p_AddrTree->pPrev = node;
    node->AddrParent = p_AddrTree;
  }
}

// File Line: 105
// RVA: 0x9F31F0
void __fastcall Scaleform::AllocAddr::splitNode(
        Scaleform::AllocAddr *this,
        Scaleform::AllocAddrNode *node,
        unsigned __int64 addr,
        unsigned __int64 size)
{
  unsigned __int64 v5; // r8
  unsigned __int64 v8; // rbx
  unsigned __int64 v9; // r9
  Scaleform::AllocAddrNode *v10; // rax

  v5 = node->Addr;
  v8 = v5 + node->Size - addr - size;
  v9 = addr - v5;
  if ( addr == v5 )
  {
    if ( v8 )
      Scaleform::AllocAddr::pushNode(this, node, addr + size, v8);
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
      v10 = (Scaleform::AllocAddrNode *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))this->pNodeHeap->vfptr->Alloc)(
                                          this->pNodeHeap,
                                          80i64);
      Scaleform::AllocAddr::pushNode(this, v10, addr + size, v8);
    }
  }
}

// File Line: 131
// RVA: 0x9E9850
unsigned __int64 __fastcall Scaleform::AllocAddr::mergeNodes(
        Scaleform::AllocAddr *this,
        Scaleform::AllocAddrNode *prev,
        Scaleform::AllocAddrNode *next,
        unsigned __int64 addr,
        unsigned __int64 size)
{
  Scaleform::RadixTreeMulti<Scaleform::AllocAddrNode,Scaleform::AllocAddr::SizeAccessor> *p_SizeTree; // rcx
  unsigned __int64 v10; // rsi
  unsigned __int64 v12; // rbx
  unsigned __int64 v13; // rbx
  Scaleform::AllocAddrNode *v14; // rax

  if ( prev )
  {
    p_SizeTree = &this->SizeTree;
    if ( next )
    {
      v10 = size + next->Size + prev->Size;
      Scaleform::RadixTreeMulti<Scaleform::AllocAddrNode,Scaleform::AllocAddr::SizeAccessor>::Remove(p_SizeTree, prev);
      Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor>::Remove(
        (Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor> *)&this->AddrTree,
        (Scaleform::HeapPT::DualTNode *)prev);
      Scaleform::RadixTreeMulti<Scaleform::AllocAddrNode,Scaleform::AllocAddr::SizeAccessor>::Remove(
        &this->SizeTree,
        next);
      Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor>::Remove(
        (Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor> *)&this->AddrTree,
        (Scaleform::HeapPT::DualTNode *)next);
      Scaleform::AllocAddr::pushNode(this, prev, prev->Addr, v10);
      this->pNodeHeap->vfptr->Free(this->pNodeHeap, next);
      return v10;
    }
    else
    {
      v12 = prev->Size + size;
      Scaleform::RadixTreeMulti<Scaleform::AllocAddrNode,Scaleform::AllocAddr::SizeAccessor>::Remove(p_SizeTree, prev);
      Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor>::Remove(
        (Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor> *)&this->AddrTree,
        (Scaleform::HeapPT::DualTNode *)prev);
      Scaleform::AllocAddr::pushNode(this, prev, prev->Addr, v12);
      return v12;
    }
  }
  else if ( next )
  {
    v13 = next->Size + size;
    Scaleform::RadixTreeMulti<Scaleform::AllocAddrNode,Scaleform::AllocAddr::SizeAccessor>::Remove(
      &this->SizeTree,
      next);
    Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor>::Remove(
      (Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor> *)&this->AddrTree,
      (Scaleform::HeapPT::DualTNode *)next);
    Scaleform::AllocAddr::pushNode(this, next, addr, v13);
    return v13;
  }
  else
  {
    v14 = (Scaleform::AllocAddrNode *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))this->pNodeHeap->vfptr->Alloc)(
                                        this->pNodeHeap,
                                        80i64);
    Scaleform::AllocAddr::pushNode(this, v14, addr, size);
    return size;
  }
}

// File Line: 176
// RVA: 0x955840
unsigned __int64 __fastcall Scaleform::AllocAddr::Alloc(Scaleform::AllocAddr *this, unsigned __int64 size)
{
  Scaleform::AllocAddrNode *GrEq; // rax
  Scaleform::AllocAddrNode *pNext; // rdi
  unsigned __int64 Addr; // rbx

  GrEq = Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::SizeAccessor>::FindGrEq(
           &this->SizeTree.Tree,
           size);
  if ( !GrEq )
    return -1i64;
  pNext = GrEq->pNext;
  Scaleform::RadixTreeMulti<Scaleform::AllocAddrNode,Scaleform::AllocAddr::SizeAccessor>::Remove(&this->SizeTree, pNext);
  if ( !pNext )
    return -1i64;
  Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor>::Remove(
    (Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor> *)&this->AddrTree,
    (Scaleform::HeapPT::DualTNode *)pNext);
  Addr = pNext->Addr;
  Scaleform::AllocAddr::splitNode(this, pNext, Addr, size);
  return Addr;
}

// File Line: 235
// RVA: 0x97D340
unsigned __int64 __fastcall Scaleform::AllocAddr::Free(
        Scaleform::AllocAddr *this,
        unsigned __int64 addr,
        unsigned __int64 size)
{
  __int64 v7; // r15
  Scaleform::AllocAddrNode *LeEq; // rdi
  Scaleform::AllocAddrNode *GrEq; // rax

  if ( !size )
    return 0i64;
  v7 = addr + size;
  LeEq = Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor>::FindLeEq(
           &this->AddrTree,
           addr);
  GrEq = Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor>::FindGrEq(
           &this->AddrTree,
           addr + size);
  if ( !LeEq || LeEq->Addr + LeEq->Size != addr )
    LeEq = 0i64;
  if ( !GrEq || GrEq->Addr != v7 )
    GrEq = 0i64;
  return Scaleform::AllocAddr::mergeNodes(this, LeEq, GrEq, addr, size);
}

// File Line: 265
// RVA: 0x954A60
// attributes: thunk
void __fastcall Scaleform::AllocAddr::AddSegment(
        Scaleform::AllocAddr *this,
        unsigned __int64 addr,
        unsigned __int64 size)
{
  Scaleform::AllocAddr::Free(this, addr, size);
}

// File Line: 271
// RVA: 0x9AA450
void __fastcall Scaleform::AllocAddr::RemoveSegment(
        Scaleform::AllocAddr *this,
        unsigned __int64 addr,
        unsigned __int64 size)
{
  Scaleform::AllocAddrNode *LeEq; // rdi

  LeEq = Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor>::FindLeEq(
           &this->AddrTree,
           addr);
  Scaleform::RadixTreeMulti<Scaleform::AllocAddrNode,Scaleform::AllocAddr::SizeAccessor>::Remove(&this->SizeTree, LeEq);
  Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor>::Remove(
    (Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor> *)&this->AddrTree,
    (Scaleform::HeapPT::DualTNode *)LeEq);
  Scaleform::AllocAddr::splitNode(this, LeEq, addr, size);
}

// File Line: 281
// RVA: 0x9D5660
void __fastcall Scaleform::calcTreeSize(Scaleform::AllocAddrNode *node, unsigned __int64 *size)
{
  Scaleform::AllocAddrNode *v3; // rbx

  if ( node )
  {
    v3 = node;
    do
    {
      *size += v3->Size;
      Scaleform::calcTreeSize(v3->AddrChild[0], size);
      v3 = v3->AddrChild[1];
    }
    while ( v3 );
  }
}

// File Line: 292
// RVA: 0x984D00
unsigned __int64 __fastcall Scaleform::AllocAddr::GetFreeSize(Scaleform::AllocAddr *this)
{
  Scaleform::AllocAddrNode *Root; // r8
  __int64 v2; // r8
  unsigned __int64 size; // [rsp+30h] [rbp+8h] BYREF

  Root = this->AddrTree.Root;
  size = 0i64;
  if ( !Root )
    return 0i64;
  size = Root->Size;
  Scaleform::calcTreeSize(Root->AddrChild[0], &size);
  Scaleform::calcTreeSize(*(Scaleform::AllocAddrNode **)(v2 + 32), &size);
  return size;
}

