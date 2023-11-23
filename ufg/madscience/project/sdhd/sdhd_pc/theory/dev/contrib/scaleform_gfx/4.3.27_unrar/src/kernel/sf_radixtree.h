// File Line: 155
// RVA: 0x9A8570
void __fastcall Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::Remove(
        Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor> *this,
        Scaleform::HeapPT::DualTNode *node)
{
  Scaleform::HeapPT::DualTNode *v2; // r8
  Scaleform::HeapPT::DualTNode **v4; // r9
  Scaleform::HeapPT::DualTNode *v5; // rcx
  Scaleform::HeapPT::DualTNode **AddrChild; // rax
  Scaleform::HeapPT::DualTNode *AddrParent; // rcx
  Scaleform::HeapPT::DualTNode *v8; // rax
  Scaleform::HeapPT::DualTNode *v9; // rax

  v2 = node->AddrChild[1];
  v4 = &node->AddrChild[1];
  if ( v2 || (v2 = node->AddrChild[0], v4 = node->AddrChild, v2) )
  {
    while ( 1 )
    {
      v5 = v2->AddrChild[1];
      AddrChild = &v2->AddrChild[1];
      if ( !v5 )
      {
        v5 = v2->AddrChild[0];
        AddrChild = v2->AddrChild;
        if ( !v5 )
          break;
      }
      v4 = AddrChild;
      v2 = v5;
    }
    *v4 = 0i64;
  }
  AddrParent = node->AddrParent;
  if ( AddrParent )
  {
    if ( node == this->Root )
      this->Root = v2;
    else
      AddrParent->AddrChild[node->AddrParent->AddrChild[0] != node] = v2;
    if ( v2 )
    {
      v2->AddrParent = AddrParent;
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
Scaleform::HeapPT::DualTNode *__fastcall Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::FindGrEq(
        Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor> *this,
        unsigned __int64 key)
{
  Scaleform::HeapPT::DualTNode *Root; // r8
  Scaleform::HeapPT::DualTNode *v3; // rbx
  unsigned __int64 v4; // r9
  Scaleform::HeapPT::DualTNode *v5; // rax
  unsigned __int64 i; // r11
  char *v7; // rcx
  Scaleform::HeapPT::DualTNode *v8; // r10

  Root = this->Root;
  v3 = 0i64;
  v4 = -1i64;
  if ( this->Root )
  {
    v5 = 0i64;
    for ( i = key; ; i *= 2i64 )
    {
      v7 = (char *)Root - key;
      if ( (unsigned __int64)Root >= key && (unsigned __int64)v7 < v4 )
      {
        v3 = Root;
        v4 = (unsigned __int64)Root - key;
        if ( !v7 )
          return Root;
      }
      v8 = Root->AddrChild[1];
      Root = Root->AddrChild[i >> 63];
      if ( v8 && v8 != Root )
        v5 = v8;
      if ( !Root )
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
Scaleform::AllocAddrNode *__fastcall Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor>::FindLeEq(
        Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor> *this,
        unsigned __int64 key)
{
  Scaleform::AllocAddrNode *Root; // r8
  Scaleform::AllocAddrNode *v3; // rbx
  unsigned __int64 v4; // r9
  Scaleform::AllocAddrNode *v6; // rax
  unsigned __int64 i; // r11
  unsigned __int64 v8; // rdx
  Scaleform::AllocAddrNode *v9; // rdx

  Root = this->Root;
  v3 = 0i64;
  v4 = -1i64;
  if ( this->Root )
  {
    v6 = 0i64;
    for ( i = key; ; i *= 2i64 )
    {
      v8 = key - Root->Addr;
      if ( Root->Addr <= key && v8 < v4 )
      {
        v3 = Root;
        v4 = key - Root->Addr;
        if ( !v8 )
          return Root;
      }
      v9 = Root->AddrChild[0];
      Root = Root->AddrChild[i >> 63];
      if ( v9 && v9 != Root )
        v6 = v9;
      if ( !Root )
        break;
    }
    for ( ; v6; v6 = v6->AddrChild[v6->AddrChild[1] != 0i64] )
    {
      if ( v6->Addr <= key && key - v6->Addr < v4 )
      {
        v4 = key - v6->Addr;
        v3 = v6;
      }
    }
  }
  return v3;
}

// File Line: 332
// RVA: 0x9943E0
void __fastcall Scaleform::RadixTreeMulti<Scaleform::AllocAddrNode,Scaleform::AllocAddr::SizeAccessor>::Insert(
        Scaleform::RadixTreeMulti<Scaleform::AllocAddrNode,Scaleform::AllocAddr::SizeAccessor> *this,
        Scaleform::AllocAddrNode *node)
{
  Scaleform::AllocAddrNode *Root; // r8
  unsigned __int64 Size; // r10
  unsigned __int64 v4; // rcx
  unsigned __int64 v5; // rax
  Scaleform::AllocAddrNode **v6; // r9
  Scaleform::AllocAddrNode *v7; // rax
  Scaleform::AllocAddrNode *pNext; // rax

  node->pPrev = node;
  node->pNext = node;
  node->SizeChild[1] = 0i64;
  node->SizeChild[0] = 0i64;
  node->SizeParent = 0i64;
  Root = this->Tree.Root;
  if ( this->Tree.Root )
  {
    Size = node->Size;
    v4 = Size;
    if ( Root->Size == Size )
    {
LABEL_6:
      pNext = Root->pNext;
      node->pPrev = Root;
      node->pNext = pNext;
      Root->pNext = node;
      node->pNext->Scaleform::ListNode<Scaleform::AllocAddrNode>::$CB76B564BFA48AF57507280A09AD5AFD::pPrev = node;
    }
    else
    {
      while ( 1 )
      {
        v5 = v4;
        v4 *= 2i64;
        v6 = &Root->pPrev + (v5 >> 63);
        v7 = v6[6];
        if ( !v7 )
          break;
        Root = v6[6];
        if ( v7->Size == Size )
          goto LABEL_6;
      }
      v6[6] = node;
      node->SizeParent = Root;
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
void __fastcall Scaleform::RadixTreeMulti<Scaleform::AllocAddrNode,Scaleform::AllocAddr::SizeAccessor>::Remove(
        Scaleform::RadixTreeMulti<Scaleform::AllocAddrNode,Scaleform::AllocAddr::SizeAccessor> *this,
        Scaleform::AllocAddrNode *node)
{
  Scaleform::AllocAddrNode *pPrev; // r8
  Scaleform::AllocAddrNode *pNext; // rax
  Scaleform::AllocAddrNode *SizeParent; // r9
  Scaleform::AllocAddrNode *v5; // rax
  Scaleform::AllocAddrNode *v6; // rax

  pPrev = node->pPrev;
  if ( node->pPrev == node )
  {
    Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::Remove(
      (Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor> *)this,
      (Scaleform::HeapPT::DualTNode *)node);
  }
  else
  {
    pNext = node->pNext;
    pNext->pPrev = pPrev;
    pPrev->pNext = pNext;
    SizeParent = node->SizeParent;
    if ( SizeParent )
    {
      if ( node == this->Tree.Root )
        this->Tree.Root = pPrev;
      else
        SizeParent->SizeChild[node->SizeParent->SizeChild[0] != node] = pPrev;
      pPrev->SizeParent = SizeParent;
      v5 = node->SizeChild[0];
      if ( v5 )
      {
        pPrev->SizeChild[0] = v5;
        v5->SizeParent = pPrev;
      }
      v6 = node->SizeChild[1];
      if ( v6 )
      {
        pPrev->SizeChild[1] = v6;
        v6->SizeParent = pPrev;
      }
    }
    node->SizeChild[1] = 0i64;
    node->SizeChild[0] = 0i64;
    node->SizeParent = 0i64;
  }
}

