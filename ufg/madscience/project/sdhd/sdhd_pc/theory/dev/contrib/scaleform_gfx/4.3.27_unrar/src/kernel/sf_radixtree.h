// File Line: 155
// RVA: 0x9A8570
void __fastcall Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::Remove(Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor> *this, Scaleform::HeapPT::DualTNode *node)
{
  Scaleform::HeapPT::DualTNode *v2; // r8
  Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor> *v3; // r11
  Scaleform::HeapPT::DualTNode **v4; // r9
  Scaleform::HeapPT::DualTNode *v5; // rcx
  signed __int64 v6; // rax
  Scaleform::HeapPT::DualTNode *v7; // rcx
  Scaleform::HeapPT::DualTNode *v8; // rax
  Scaleform::HeapPT::DualTNode *v9; // rax

  v2 = node->AddrChild[1];
  v3 = this;
  v4 = &node->AddrChild[1];
  if ( v2 || (v2 = node->AddrChild[0], v4 = node->AddrChild, v2) )
  {
    while ( 1 )
    {
      v5 = v2->AddrChild[1];
      v6 = (signed __int64)&v2->AddrChild[1];
      if ( !v5 )
      {
        v5 = v2->AddrChild[0];
        v6 = (signed __int64)v2->AddrChild;
        if ( !v5 )
          break;
      }
      v4 = (Scaleform::HeapPT::DualTNode **)v6;
      v2 = v5;
    }
    *v4 = 0i64;
  }
  v7 = node->AddrParent;
  if ( v7 )
  {
    if ( node == v3->Root )
      v3->Root = v2;
    else
      v7->AddrChild[node->AddrParent->AddrChild[0] != node] = v2;
    if ( v2 )
    {
      v2->AddrParent = v7;
      v8 = node->AddrChild[0];
      if ( v8 )
      {
        v2->AddrChild[0] = v8;
        v8->AddrParent = v2;
      }
      v9 = node->AddrChild[1];
      if ( v9 )
      {
        v2->AddrChild[1] = v9;
        v9->AddrParent = v2;
      }
    }
  }
  node->AddrChild[1] = 0i64;
  node->AddrChild[0] = 0i64;
  node->AddrParent = 0i64;
}

// File Line: 201
// RVA: 0x979FF0
Scaleform::HeapPT::DualTNode *__fastcall Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::FindGrEq(Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor> *this, unsigned __int64 key)
{
  Scaleform::HeapPT::DualTNode *v2; // r8
  Scaleform::HeapPT::DualTNode *v3; // rbx
  unsigned __int64 v4; // r9
  Scaleform::HeapPT::DualTNode *v5; // rax
  unsigned __int64 i; // r11
  Scaleform::HeapPT::DualTNode *v7; // r10

  v2 = this->Root;
  v3 = 0i64;
  v4 = -1i64;
  if ( this->Root )
  {
    v5 = 0i64;
    for ( i = key; ; i *= 2i64 )
    {
      if ( (unsigned __int64)v2 >= key && (unsigned __int64)v2 - key < v4 )
      {
        v3 = v2;
        v4 = (unsigned __int64)v2 - key;
        if ( v2 == (Scaleform::HeapPT::DualTNode *)key )
          return v2;
      }
      v7 = v2->AddrChild[1];
      v2 = v2->AddrChild[i >> 63];
      if ( v7 && v7 != v2 )
        v5 = v7;
      if ( !v2 )
        break;
    }
    for ( ; v5; v5 = v5->AddrChild[v5->AddrChild[0] == 0i64] )
    {
      if ( (unsigned __int64)v5 >= key && (unsigned __int64)v5 - key < v4 )
      {
        v4 = (unsigned __int64)v5 - key;
        v3 = v5;
      }
    }
  }
  return v3;
}

// File Line: 264
// RVA: 0x97A3E0
Scaleform::AllocAddrNode *__fastcall Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor>::FindLeEq(Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor> *this, unsigned __int64 key)
{
  Scaleform::AllocAddrNode *v2; // r8
  Scaleform::AllocAddrNode *v3; // rbx
  unsigned __int64 v4; // r9
  unsigned __int64 v5; // r10
  Scaleform::AllocAddrNode *v6; // rax
  unsigned __int64 i; // r11
  Scaleform::AllocAddrNode *v8; // rdx

  v2 = this->Root;
  v3 = 0i64;
  v4 = -1i64;
  v5 = key;
  if ( this->Root )
  {
    v6 = 0i64;
    for ( i = key; ; i *= 2i64 )
    {
      if ( v2->Addr <= v5 && v5 - v2->Addr < v4 )
      {
        v3 = v2;
        v4 = v5 - v2->Addr;
        if ( v5 == v2->Addr )
          return v2;
      }
      v8 = v2->AddrChild[0];
      v2 = v2->AddrChild[i >> 63];
      if ( v8 && v8 != v2 )
        v6 = v8;
      if ( !v2 )
        break;
    }
    for ( ; v6; v6 = v6->AddrChild[v6->AddrChild[1] != 0i64] )
    {
      if ( v6->Addr <= v5 && v5 - v6->Addr < v4 )
      {
        v4 = v5 - v6->Addr;
        v3 = v6;
      }
    }
  }
  return v3;
}

// File Line: 332
// RVA: 0x9943E0
void __fastcall Scaleform::RadixTreeMulti<Scaleform::AllocAddrNode,Scaleform::AllocAddr::SizeAccessor>::Insert(Scaleform::RadixTreeMulti<Scaleform::AllocAddrNode,Scaleform::AllocAddr::SizeAccessor> *this, Scaleform::AllocAddrNode *node)
{
  Scaleform::AllocAddrNode *v2; // r8
  unsigned __int64 v3; // r10
  unsigned __int64 v4; // rcx
  unsigned __int64 v5; // rax
  signed __int64 v6; // r9
  Scaleform::AllocAddrNode *v7; // rax
  Scaleform::AllocAddrNode *v8; // rax

  node->pPrev = node;
  node->pNext = node;
  node->SizeChild[1] = 0i64;
  node->SizeChild[0] = 0i64;
  node->SizeParent = 0i64;
  v2 = this->Tree.Root;
  if ( this->Tree.Root )
  {
    v3 = node->Size;
    v4 = v3;
    if ( v2->Size == v3 )
    {
LABEL_6:
      v8 = v2->pNext;
      node->pPrev = v2;
      node->pNext = v8;
      v2->pNext = node;
      node->pNext->pPrev = node;
    }
    else
    {
      while ( 1 )
      {
        v5 = v4;
        v4 *= 2i64;
        v5 >>= 63;
        v6 = (signed __int64)v2 + 8 * v5;
        v7 = v2->SizeChild[v5];
        if ( !v7 )
          break;
        v2 = v7;
        if ( v7->Size == v3 )
          goto LABEL_6;
      }
      *(_QWORD *)(v6 + 48) = node;
      node->SizeParent = v2;
    }
  }
  else
  {
    this->Tree.Root = node;
    node->SizeParent = (Scaleform::AllocAddrNode *)this;
  }
}

// File Line: 351
// RVA: 0x9A87A0
void __fastcall Scaleform::RadixTreeMulti<Scaleform::AllocAddrNode,Scaleform::AllocAddr::SizeAccessor>::Remove(Scaleform::RadixTreeMulti<Scaleform::AllocAddrNode,Scaleform::AllocAddr::SizeAccessor> *this, Scaleform::AllocAddrNode *node)
{
  Scaleform::AllocAddrNode *v2; // r8
  Scaleform::AllocAddrNode *v3; // rax
  Scaleform::AllocAddrNode *v4; // r9
  Scaleform::AllocAddrNode *v5; // rax
  Scaleform::AllocAddrNode *v6; // rax

  v2 = node->pPrev;
  if ( node->pPrev == node )
  {
    Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::Remove(
      (Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor> *)this,
      (Scaleform::HeapPT::DualTNode *)node);
  }
  else
  {
    v3 = node->pNext;
    v3->pPrev = v2;
    v2->pNext = v3;
    v4 = node->SizeParent;
    if ( v4 )
    {
      if ( node == this->Tree.Root )
        this->Tree.Root = v2;
      else
        v4->SizeChild[node->SizeParent->SizeChild[0] != node] = v2;
      v2->SizeParent = v4;
      v5 = node->SizeChild[0];
      if ( v5 )
      {
        v2->SizeChild[0] = v5;
        v5->SizeParent = v2;
      }
      v6 = node->SizeChild[1];
      if ( v6 )
      {
        v2->SizeChild[1] = v6;
        v6->SizeParent = v2;
      }
    }
    node->SizeChild[1] = 0i64;
    node->SizeChild[0] = 0i64;
    node->SizeParent = 0i64;
  }
}

