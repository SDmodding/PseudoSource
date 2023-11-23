// File Line: 131
// RVA: 0x979410
Scaleform::HeapPT::BinLNode *__fastcall Scaleform::HeapPT::ListBin::FindAligned(
        Scaleform::HeapPT::ListBin *this,
        Scaleform::HeapPT::BinLNode *root,
        unsigned __int64 blocks,
        unsigned __int64 shift,
        unsigned __int64 alignMask)
{
  Scaleform::HeapPT::BinLNode *v6; // r10
  unsigned __int64 v7; // rsi
  unsigned __int64 v8; // rdx
  unsigned __int64 v9; // rax
  unsigned __int64 ShortSize; // r8

  v6 = root;
  if ( !root )
    return 0i64;
  v7 = blocks << shift;
  while ( 1 )
  {
    v8 = ~alignMask & ((unsigned __int64)v6 + alignMask);
    v9 = v8 - (_QWORD)v6;
    if ( v8 != (_QWORD)v6 )
    {
      do
      {
        if ( v9 >= 0x20 )
          break;
        v8 += alignMask + 1;
        v9 += alignMask + 1;
      }
      while ( v9 );
    }
    ShortSize = v6->ShortSize;
    if ( ShortSize >= 0x41 )
      ShortSize = (unsigned __int64)v6[1].pPrev;
    if ( v8 + v7 <= (unsigned __int64)v6 + (ShortSize << shift) )
      break;
    v6 = v6->pNext;
    if ( v6 == root )
      return 0i64;
  }
  return v6;
}

// File Line: 147
// RVA: 0x9A1970
unsigned __int64 __fastcall Scaleform::HeapPT::ListBin::PullBest(
        Scaleform::HeapPT::ListBin *this,
        unsigned __int64 idx,
        unsigned __int64 blocks,
        unsigned __int64 shift,
        unsigned __int64 alignMask)
{
  unsigned __int64 result; // rax
  __int64 v9; // rbx
  Scaleform::HeapPT::BinLNode **i; // rdi
  Scaleform::HeapPT::BinLNode *v11; // rdx
  Scaleform::HeapPT::BinLNode *v12; // rax
  unsigned __int64 *v13; // rcx
  Scaleform::HeapPT::BinLNode *pNext; // r8

  result = this->Mask >> idx;
  if ( result )
  {
    v9 = idx + (unsigned __int8)Scaleform::Alg::LowerBit(result);
    for ( i = &this->Roots[v9]; ; ++i )
    {
      result = (unsigned __int64)Scaleform::HeapPT::ListBin::FindAligned(this, *i, blocks, shift, alignMask);
      v11 = (Scaleform::HeapPT::BinLNode *)result;
      if ( result )
        break;
      if ( (unsigned __int64)++v9 >= 0x40 )
        return result;
    }
    v12 = this->Roots[v9];
    v13 = &this->Mask + v9;
    if ( v11 == v12 )
    {
      pNext = v12->pNext;
      if ( v12 == pNext )
      {
        v13[1] = 0i64;
        this->Mask &= ~(1i64 << v9);
        return (unsigned __int64)v11;
      }
      v13[1] = (unsigned __int64)pNext;
    }
    v11->pPrev->pNext = v11->pNext;
    v11->pNext->pPrev = v11->pPrev;
    return (unsigned __int64)v11;
  }
  return result;
}

// File Line: 216
// RVA: 0x9A36D0
void __fastcall Scaleform::HeapPT::TreeBin::PushNode(
        Scaleform::HeapPT::TreeBin *this,
        Scaleform::HeapPT::BinTNode *node)
{
  unsigned __int64 Size; // rdi
  unsigned __int64 v5; // rcx
  unsigned __int8 v6; // al
  Scaleform::HeapPT::BinTNode *v7; // rdx
  Scaleform::HeapPT::BinTNode *pPrev; // rdx
  __int64 v9; // rax
  unsigned __int64 v10; // r8
  unsigned __int64 v11; // rax
  Scaleform::HeapPT::BinLNode **v12; // rcx
  Scaleform::HeapPT::BinLNode *v13; // rax
  Scaleform::HeapPT::BinLNode *pNext; // rax

  Size = node->Size;
  v5 = Size >> 6;
  if ( Size >> 6 )
  {
    v6 = Scaleform::Alg::UpperBit(v5);
    v5 = ((Size >> (v6 + 5)) & 1) + 2i64 * v6;
  }
  node->Index = v5;
  node->Child[1] = 0i64;
  node->Child[0] = 0i64;
  v7 = (Scaleform::HeapPT::BinTNode *)&this->Roots[v5];
  if ( (this->Mask & (1i64 << v5)) != 0 )
  {
    pPrev = (Scaleform::HeapPT::BinTNode *)v7->pPrev;
    if ( v5 < 0x3F )
      v9 = 59 - (v5 >> 1);
    else
      LOBYTE(v9) = 0;
    v10 = Size << v9;
    if ( pPrev->Size == Size )
    {
LABEL_11:
      pNext = pPrev->pNext;
      pNext->pPrev = node;
      pPrev->pNext = node;
      node->pNext = pNext;
      node->pPrev = pPrev;
      node->Parent = 0i64;
    }
    else
    {
      while ( 1 )
      {
        v11 = v10;
        v10 *= 2i64;
        v12 = &pPrev->pPrev + (v11 >> 63);
        v13 = v12[6];
        if ( !v13 )
          break;
        pPrev = (Scaleform::HeapPT::BinTNode *)v12[6];
        if ( v13[1].pPrev == (Scaleform::HeapPT::BinLNode *)Size )
          goto LABEL_11;
      }
      v12[6] = node;
      node->Parent = pPrev;
      node->pPrev = node;
      node->pNext = node;
    }
  }
  else
  {
    this->Mask |= 1i64 << v5;
    v7->pPrev = node;
    node->Parent = v7;
    node->pPrev = node;
    node->pNext = node;
  }
}

// File Line: 273
// RVA: 0x9A1CE0
void __fastcall Scaleform::HeapPT::TreeBin::PullNode(
        Scaleform::HeapPT::TreeBin *this,
        Scaleform::HeapPT::BinTNode *node)
{
  Scaleform::HeapPT::BinTNode *pPrev; // r8
  Scaleform::HeapPT::BinTNode *Parent; // r10
  __int64 v4; // r11
  Scaleform::HeapPT::BinLNode *pNext; // rax
  Scaleform::HeapPT::BinTNode **v7; // r9
  Scaleform::HeapPT::BinTNode *v8; // rcx
  Scaleform::HeapPT::BinTNode **Child; // rax
  unsigned __int64 Index; // rax
  Scaleform::HeapPT::BinTNode *v11; // rax
  Scaleform::HeapPT::BinTNode *v12; // rax

  pPrev = (Scaleform::HeapPT::BinTNode *)node->pPrev;
  Parent = node->Parent;
  v4 = 0i64;
  if ( node->pPrev == node )
  {
    pPrev = node->Child[1];
    v7 = &node->Child[1];
    if ( pPrev || (pPrev = node->Child[0], v7 = node->Child, pPrev) )
    {
      while ( 1 )
      {
        v8 = pPrev->Child[1];
        Child = &pPrev->Child[1];
        if ( !v8 )
        {
          v8 = pPrev->Child[0];
          Child = pPrev->Child;
          if ( !v8 )
            break;
        }
        v7 = Child;
        pPrev = v8;
      }
      *v7 = 0i64;
    }
  }
  else
  {
    pNext = node->pNext;
    pNext->pPrev = pPrev;
    pPrev->pNext = pNext;
  }
  if ( Parent )
  {
    Index = node->Index;
    if ( node == this->Roots[Index] )
    {
      this->Roots[Index] = pPrev;
      if ( !pPrev )
      {
        this->Mask &= ~(1i64 << node->Index);
        return;
      }
    }
    else
    {
      LOBYTE(v4) = Parent->Child[0] != node;
      Parent->Child[v4] = pPrev;
      if ( !pPrev )
        return;
    }
    pPrev->Parent = Parent;
    v11 = node->Child[0];
    if ( v11 )
    {
      pPrev->Child[0] = v11;
      v11->Parent = pPrev;
    }
    v12 = node->Child[1];
    if ( v12 )
    {
      pPrev->Child[1] = v12;
      v12->Parent = pPrev;
    }
  }
}

// File Line: 342
// RVA: 0x9794B0
Scaleform::HeapPT::BinTNode *__fastcall Scaleform::HeapPT::TreeBin::FindBest(
        Scaleform::HeapPT::TreeBin *this,
        unsigned __int64 size)
{
  Scaleform::HeapPT::BinTNode *v3; // rdi
  unsigned __int64 v4; // rbx
  unsigned __int64 v6; // r10
  unsigned __int8 v7; // al
  Scaleform::HeapPT::BinTNode *v8; // rax
  Scaleform::HeapPT::BinTNode *v9; // r9
  __int64 v10; // rcx
  unsigned __int64 i; // r8
  unsigned __int64 v12; // rcx
  Scaleform::HeapPT::BinTNode *v13; // rdx
  unsigned __int64 v14; // rcx

  v3 = 0i64;
  v4 = -(__int64)size;
  if ( size >> 6 )
  {
    v7 = Scaleform::Alg::UpperBit(size >> 6);
    v6 = ((size >> (v7 + 5)) & 1) + 2i64 * v7;
  }
  else
  {
    v6 = 0i64;
  }
  v8 = this->Roots[v6];
  if ( v8 )
  {
    v9 = 0i64;
    if ( v6 < 0x3F )
      v10 = 59 - (v6 >> 1);
    else
      LOBYTE(v10) = 0;
    for ( i = size << v10; ; i *= 2i64 )
    {
      v12 = v8->Size - size;
      if ( v12 < v4 )
      {
        v3 = v8;
        v4 = v8->Size - size;
        if ( !v12 )
          break;
      }
      v13 = v8->Child[1];
      v8 = v8->Child[i >> 63];
      if ( v13 && v13 != v8 )
        v9 = v13;
      if ( !v8 )
      {
        v8 = v9;
        break;
      }
    }
    if ( v8 )
      goto LABEL_22;
    if ( v3 )
      return v3;
  }
  v14 = this->Mask & ((1i64 << ((unsigned __int8)v6 + 1)) | -(1i64 << ((unsigned __int8)v6 + 1)));
  if ( v14 )
    v8 = this->Roots[(unsigned __int8)Scaleform::Alg::LowerBit(v14)];
  while ( v8 )
  {
LABEL_22:
    if ( v8->Size - size < v4 )
    {
      v4 = v8->Size - size;
      v3 = v8;
    }
    v8 = v8->Child[v8->Child[0] == 0i64];
  }
  return v3;
}

// File Line: 510
// RVA: 0x9A1E50
void __fastcall Scaleform::HeapPT::FreeBin::Push(Scaleform::HeapPT::FreeBin *this, Scaleform::HeapPT::BinTNode *node)
{
  unsigned __int64 ShortSize; // rax
  Scaleform::HeapPT::BinLNode *v4; // rcx
  unsigned __int64 v5; // r9
  Scaleform::HeapPT::BinLNode *v6; // rcx
  unsigned __int64 v7; // r9

  ShortSize = node->ShortSize;
  if ( ShortSize >= 0x41 )
    ShortSize = node->Size;
  this->FreeBlocks += ShortSize;
  if ( ShortSize > 0x40 )
  {
    if ( ShortSize > 0x80 )
    {
      Scaleform::HeapPT::TreeBin::PushNode(&this->TreeBin1, node);
    }
    else
    {
      v6 = this->ListBin1.Roots[ShortSize];
      v7 = ShortSize - 65;
      if ( v6 )
      {
        node->pPrev = v6;
        node->pNext = v6->pNext;
        v6->pNext->pPrev = node;
        v6->pNext = node;
      }
      else
      {
        node->pNext = node;
        node->pPrev = node;
      }
      this->ListBin2.Roots[v7] = node;
      this->ListBin2.Mask |= 1i64 << v7;
    }
  }
  else
  {
    v4 = (Scaleform::HeapPT::BinLNode *)*(&this->ListBin1.Mask + ShortSize);
    v5 = ShortSize - 1;
    if ( v4 )
    {
      node->pPrev = v4;
      node->pNext = v4->pNext;
      v4->pNext->pPrev = node;
      v4->pNext = node;
    }
    else
    {
      node->pNext = node;
      node->pPrev = node;
    }
    this->ListBin1.Roots[v5] = node;
    this->ListBin1.Mask |= 1i64 << v5;
  }
}

// File Line: 529
// RVA: 0x9A1490
void __fastcall Scaleform::HeapPT::FreeBin::Pull(Scaleform::HeapPT::FreeBin *this, Scaleform::HeapPT::BinTNode *node)
{
  unsigned __int64 ShortSize; // rax
  unsigned __int64 v4; // r10
  Scaleform::HeapPT::BinLNode *v5; // rax
  unsigned __int64 *v6; // rcx
  Scaleform::HeapPT::BinLNode *v7; // r9
  unsigned __int64 v8; // r9
  Scaleform::HeapPT::BinLNode *v9; // rax
  Scaleform::HeapPT::BinLNode *pNext; // rcx

  ShortSize = node->ShortSize;
  if ( ShortSize >= 0x41 )
    ShortSize = node->Size;
  this->FreeBlocks -= ShortSize;
  if ( ShortSize > 0x40 )
  {
    if ( ShortSize > 0x80 )
    {
      Scaleform::HeapPT::TreeBin::PullNode(&this->TreeBin1, node);
    }
    else
    {
      v8 = ShortSize - 65;
      v9 = this->ListBin1.Roots[ShortSize];
      if ( node != v9 )
        goto LABEL_7;
      pNext = v9->pNext;
      if ( v9 != pNext )
      {
        this->ListBin2.Roots[v8] = pNext;
        goto LABEL_7;
      }
      this->ListBin2.Roots[v8] = 0i64;
      this->ListBin2.Mask &= ~(1i64 << v8);
    }
  }
  else
  {
    v4 = ShortSize - 1;
    v5 = this->ListBin1.Roots[ShortSize - 1];
    v6 = &this->ListBin1.Mask + v4;
    if ( node != v5 )
    {
LABEL_7:
      node->pPrev->pNext = node->pNext;
      node->pNext->Scaleform::HeapPT::BinLNode::pPrev = node->pPrev;
      return;
    }
    v7 = v5->pNext;
    if ( v5 != v7 )
    {
      v6[1] = (unsigned __int64)v7;
      goto LABEL_7;
    }
    v6[1] = 0i64;
    this->ListBin1.Mask &= ~(1i64 << v4);
  }
}

// File Line: 548
// RVA: 0x9A17B0
Scaleform::HeapPT::BinTNode *__fastcall Scaleform::HeapPT::FreeBin::PullBest(
        Scaleform::HeapPT::FreeBin *this,
        unsigned __int64 blocks)
{
  unsigned __int64 v4; // rax
  unsigned __int64 v5; // rcx
  unsigned __int64 *v6; // rdx
  char *v7; // r8
  char *v8; // rax
  Scaleform::HeapPT::BinTNode *result; // rax
  __int64 v10; // rbp
  __int64 v11; // rcx
  Scaleform::HeapPT::BinLNode *v12; // rdx
  Scaleform::HeapPT::BinLNode *v13; // rax
  Scaleform::HeapPT::BinTNode *Best; // rax
  Scaleform::HeapPT::BinTNode *pNext; // rdi

  if ( blocks > 0x80 )
    goto LABEL_17;
  if ( blocks > 0x40 )
  {
    v10 = blocks - 65;
  }
  else
  {
    v4 = this->ListBin1.Mask >> ((unsigned __int8)blocks - 1);
    if ( v4 )
    {
      v5 = blocks - 1 + (unsigned __int8)Scaleform::Alg::LowerBit(v4);
      v6 = &this->ListBin1.Mask + v5;
      v7 = (char *)v6[1];
      v8 = (char *)*((_QWORD *)v7 + 1);
      if ( v7 == v8 )
      {
        v6[1] = 0i64;
        this->ListBin1.Mask &= ~(1i64 << v5);
      }
      else
      {
        v6[1] = (unsigned __int64)v8;
        *(_QWORD *)(*(_QWORD *)v7 + 8i64) = *((_QWORD *)v7 + 1);
        **((_QWORD **)v7 + 1) = *(_QWORD *)v7;
      }
      if ( v7 )
      {
        result = (Scaleform::HeapPT::BinTNode *)v7;
        this->FreeBlocks -= *((unsigned int *)v7 + 6);
        return result;
      }
    }
    v10 = 0i64;
  }
  if ( this->ListBin2.Mask >> v10
    && ((v11 = v10 + (unsigned __int8)Scaleform::Alg::LowerBit(this->ListBin2.Mask >> v10),
         v12 = this->ListBin2.Roots[v11],
         v13 = v12->pNext,
         v12 == v13)
      ? (Scaleform::HeapPT::BinLNode *)(this->ListBin2.Roots[v11] = 0i64, this->ListBin2.Mask &= ~(1i64 << v11))
      : (this->ListBin2.Roots[v11] = v13, v12->pPrev->pNext = v12->pNext, v12->pNext->pPrev = v12->pPrev),
        v12) )
  {
    result = (Scaleform::HeapPT::BinTNode *)v12;
    this->FreeBlocks -= (unsigned __int64)v12[1].pPrev;
  }
  else
  {
LABEL_17:
    Best = Scaleform::HeapPT::TreeBin::FindBest(&this->TreeBin1, blocks);
    pNext = Best;
    if ( Best )
    {
      pNext = (Scaleform::HeapPT::BinTNode *)Best->pNext;
      Scaleform::HeapPT::TreeBin::PullNode(&this->TreeBin1, pNext);
      if ( pNext )
        this->FreeBlocks -= pNext->Size;
    }
    return pNext;
  }
  return result;
}

// File Line: 578
// RVA: 0x9A1630
Scaleform::HeapPT::BinLNode *__fastcall Scaleform::HeapPT::FreeBin::PullBest(
        Scaleform::HeapPT::FreeBin *this,
        unsigned __int64 blocks,
        unsigned __int64 shift,
        unsigned __int64 alignMask)
{
  Scaleform::HeapPT::BinLNode *result; // rax
  unsigned __int64 v9; // rdx
  Scaleform::HeapPT::BinTNode *Best; // rbx
  Scaleform::HeapPT::BinTNode *v11; // r9
  unsigned __int64 v12; // rsi
  unsigned __int64 v13; // rdx
  unsigned __int64 v14; // rax
  unsigned __int64 ShortSize; // r8

  if ( blocks > 0x80 )
    goto LABEL_9;
  if ( blocks > 0x40 )
  {
    v9 = blocks - 65;
  }
  else
  {
    result = Scaleform::HeapPT::ListBin::PullBest(&this->ListBin1, blocks - 1, blocks, shift, alignMask);
    if ( result )
    {
      this->FreeBlocks -= result->ShortSize;
      return result;
    }
    v9 = 0i64;
  }
  result = Scaleform::HeapPT::ListBin::PullBest(&this->ListBin2, v9, blocks, shift, alignMask);
  if ( result )
  {
    this->FreeBlocks -= (unsigned __int64)result[1].pPrev;
  }
  else
  {
LABEL_9:
    Best = Scaleform::HeapPT::TreeBin::FindBest(&this->TreeBin1, blocks);
    v11 = Best;
    if ( Best )
    {
      v12 = blocks << shift;
      while ( 1 )
      {
        v13 = ~alignMask & ((unsigned __int64)Best + alignMask);
        v14 = v13 - (_QWORD)Best;
        if ( v13 != (_QWORD)Best )
        {
          do
          {
            if ( v14 >= 0x20 )
              break;
            v13 += alignMask + 1;
            v14 += alignMask + 1;
          }
          while ( v14 );
        }
        ShortSize = Best->ShortSize;
        if ( ShortSize >= 0x41 )
          ShortSize = Best->Size;
        if ( v13 + v12 <= (unsigned __int64)Best + (ShortSize << shift) )
          break;
        Best = (Scaleform::HeapPT::BinTNode *)Best->pNext;
        if ( Best == v11 )
        {
          Best = Scaleform::HeapPT::TreeBin::FindBest(&this->TreeBin1, Best->Size + 1);
          v11 = Best;
          if ( !Best )
            return 0i64;
        }
      }
      Scaleform::HeapPT::TreeBin::PullNode(&this->TreeBin1, Best);
      this->FreeBlocks -= Best->Size;
      return Best;
    }
    else
    {
      return 0i64;
    }
  }
  return result;
}

// File Line: 667
// RVA: 0x99A8B0
void __fastcall Scaleform::HeapPT::FreeBin::Merge(
        Scaleform::HeapPT::FreeBin *this,
        char *node,
        unsigned __int64 shift,
        bool left,
        bool right)
{
  unsigned __int64 v5; // rdi
  char v6; // r14
  char *v9; // rbx
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // rax
  unsigned __int64 v12; // rdx
  char *v13; // rdx
  unsigned __int64 v14; // rax
  unsigned __int64 v15; // rax

  v5 = *((unsigned int *)node + 6);
  v6 = shift;
  if ( v5 >= 0x41 )
    v5 = *((_QWORD *)node + 4);
  v9 = node;
  if ( left )
  {
    v10 = *((unsigned int *)node - 1);
    if ( v10 >= 0x41 )
      v10 = *((_QWORD *)node - 2);
    v9 = &node[-(v10 << shift)];
    v11 = *((unsigned int *)v9 + 6);
    if ( v11 >= 0x41 )
      v11 = *((_QWORD *)v9 + 4);
    v5 += v11;
    Scaleform::HeapPT::FreeBin::Pull(this, v9);
  }
  if ( right )
  {
    v12 = *((unsigned int *)node + 6);
    if ( v12 >= 0x41 )
      v12 = *((_QWORD *)node + 4);
    v13 = &node[v12 << v6];
    v14 = *((unsigned int *)v13 + 6);
    if ( v14 >= 0x41 )
      v14 = *((_QWORD *)v13 + 4);
    v5 += v14;
    Scaleform::HeapPT::FreeBin::Pull(this, v13);
  }
  v15 = v5 << v6;
  if ( v5 >= 0x41 )
  {
    *(_DWORD *)&v9[v15 - 4] = 65;
    *((_DWORD *)v9 + 6) = 65;
    *(_QWORD *)&v9[v15 - 16] = v5;
    *((_QWORD *)v9 + 4) = v5;
  }
  else
  {
    *(_DWORD *)&v9[v15 - 4] = v5;
    *((_DWORD *)v9 + 6) = v5;
  }
  Scaleform::HeapPT::FreeBin::Push(this, v9);
}

// File Line: 713
// RVA: 0x9FB1D0
void __fastcall Scaleform::HeapPT::FreeBin::visitUnusedInTree(
        Scaleform::HeapPT::FreeBin *this,
        Scaleform::HeapPT::BinTNode *root,
        Scaleform::Heap::SegVisitor *visitor,
        unsigned __int64 shift,
        unsigned int cat)
{
  Scaleform::HeapPT::BinTNode *v7; // rdi
  Scaleform::HeapPT::BinTNode *pNext; // rbx
  unsigned __int64 ShortSize; // rdx
  Scaleform::HeapPT::FreeBin *v10; // [rsp+40h] [rbp+8h]

  if ( root )
  {
    v10 = this;
    v7 = root;
    do
    {
      Scaleform::HeapPT::FreeBin::visitUnusedInTree(this, v7->Child[0], visitor, shift, cat);
      pNext = v7;
      do
      {
        ShortSize = pNext->ShortSize;
        if ( ShortSize >= 0x41 )
          ShortSize = pNext->Size;
        if ( (((unsigned __int64)&pNext[56].Child[1] + 7) & 0xFFFFFFFFFFFFF000ui64) + 4096 <= (((unsigned __int64)pNext
                                                                                              + (ShortSize << shift)) & 0xFFFFFFFFFFFFF000ui64) )
          ((void (__fastcall *)(Scaleform::Heap::SegVisitor *, _QWORD, Scaleform::MemoryHeapPT *))visitor->vfptr->Visit)(
            visitor,
            cat,
            pNext->pSegment->pHeap);
        pNext = (Scaleform::HeapPT::BinTNode *)pNext->pNext;
      }
      while ( pNext != v7 );
      v7 = v7->Child[1];
      this = v10;
    }
    while ( v7 );
  }
}

// File Line: 730
// RVA: 0x9C21C0
void __fastcall Scaleform::HeapPT::FreeBin::VisitUnused(
        Scaleform::HeapPT::FreeBin *this,
        Scaleform::Heap::SegVisitor *visitor,
        unsigned __int64 shift,
        unsigned int cat)
{
  Scaleform::HeapPT::BinLNode **Roots; // r15
  __int64 v9; // r12
  __int64 v10; // rdi
  __int64 v11; // rbx
  unsigned __int64 v12; // rax
  unsigned __int64 v13; // rdx
  Scaleform::HeapPT::BinLNode *v14; // rdi
  Scaleform::HeapPT::BinLNode *v15; // rbx
  unsigned __int64 ShortSize; // rax
  unsigned __int64 pPrev; // rdx

  Roots = this->ListBin2.Roots;
  v9 = 64i64;
  do
  {
    v10 = (__int64)*(Roots - 65);
    v11 = v10;
    if ( v10 )
    {
      v12 = *(unsigned int *)(v10 + 24);
      if ( v12 >= 0x41 )
        v12 = *(_QWORD *)(v10 + 32);
      if ( v12 << shift >= 0x1000 )
      {
        do
        {
          v13 = *(unsigned int *)(v11 + 24);
          if ( v13 >= 0x41 )
            v13 = *(_QWORD *)(v11 + 32);
          if ( ((v11 + 4095) & 0xFFFFFFFFFFFFF000ui64) + 4096 <= ((v11 + (v13 << shift)) & 0xFFFFFFFFFFFFF000ui64) )
            ((void (__fastcall *)(Scaleform::Heap::SegVisitor *, _QWORD, _QWORD))visitor->vfptr->Visit)(
              visitor,
              cat,
              *(_QWORD *)(*(_QWORD *)(v11 + 16) + 40i64));
          v11 = *(_QWORD *)(v11 + 8);
        }
        while ( v11 != v10 );
      }
    }
    v14 = *Roots;
    v15 = *Roots;
    if ( *Roots )
    {
      ShortSize = v14->ShortSize;
      if ( ShortSize >= 0x41 )
        ShortSize = (unsigned __int64)v14[1].pPrev;
      if ( ShortSize << shift >= 0x1000 )
      {
        do
        {
          pPrev = v15->ShortSize;
          if ( pPrev >= 0x41 )
            pPrev = (unsigned __int64)v15[1].pPrev;
          if ( (((unsigned __int64)&v15[127].Filler + 3) & 0xFFFFFFFFFFFFF000ui64) + 4096 <= (((unsigned __int64)v15
                                                                                             + (pPrev << shift)) & 0xFFFFFFFFFFFFF000ui64) )
            ((void (__fastcall *)(Scaleform::Heap::SegVisitor *, _QWORD, Scaleform::MemoryHeapPT *))visitor->vfptr->Visit)(
              visitor,
              cat,
              v15->pSegment->pHeap);
          v15 = v15->pNext;
        }
        while ( v15 != v14 );
      }
    }
    Scaleform::HeapPT::FreeBin::visitUnusedInTree(this, (Scaleform::HeapPT::BinTNode *)Roots[65], visitor, shift, cat);
    ++Roots;
    --v9;
  }
  while ( v9 );
}

// File Line: 759
// RVA: 0x9FB060
void __fastcall Scaleform::HeapPT::FreeBin::visitTree(
        Scaleform::HeapPT::FreeBin *this,
        Scaleform::HeapPT::BinTNode *root,
        Scaleform::Heap::MemVisitor *visitor,
        unsigned __int64 shift,
        Scaleform::Heap::MemVisitor::Category cat)
{
  unsigned __int64 v5; // rax
  Scaleform::HeapPT::BinTNode *v7; // rdi
  unsigned __int64 v8; // rbx
  Scaleform::HeapPT::FreeBin *v9; // [rsp+50h] [rbp+8h]

  if ( root )
  {
    v9 = this;
    v5 = shift;
    v7 = root;
    do
    {
      Scaleform::HeapPT::FreeBin::visitTree(this, v7->Child[0], visitor, v5, cat);
      v8 = (unsigned __int64)v7;
      do
      {
        visitor->vfptr->Visit(
          visitor,
          *(Scaleform::Heap::HeapSegment **)(v8 + 16),
          v8,
          *(_QWORD *)(v8 + 32) << shift,
          cat);
        v8 = *(_QWORD *)(v8 + 8);
      }
      while ( (Scaleform::HeapPT::BinTNode *)v8 != v7 );
      v7 = v7->Child[1];
      v5 = shift;
      this = v9;
    }
    while ( v7 );
  }
}

// File Line: 778
// RVA: 0x9C1C30
void __fastcall Scaleform::HeapPT::FreeBin::VisitMem(
        Scaleform::HeapPT::FreeBin *this,
        Scaleform::Heap::MemVisitor *visitor,
        unsigned __int64 shift,
        Scaleform::Heap::MemVisitor::Category cat)
{
  Scaleform::HeapPT::BinLNode **Roots; // r15
  __int64 v9; // r12
  unsigned __int64 v10; // rsi
  unsigned __int64 v11; // rbx
  Scaleform::HeapPT::BinLNode *v12; // rsi
  unsigned __int64 v13; // rbx
  unsigned __int64 v14; // r9

  Roots = this->ListBin2.Roots;
  v9 = 64i64;
  do
  {
    v10 = (unsigned __int64)*(Roots - 65);
    v11 = v10;
    if ( v10 )
    {
      do
      {
        visitor->vfptr->Visit(
          visitor,
          *(Scaleform::Heap::HeapSegment **)(v11 + 16),
          v11,
          (unsigned __int64)*(unsigned int *)(v11 + 24) << shift,
          cat);
        v11 = *(_QWORD *)(v11 + 8);
      }
      while ( v11 != v10 );
    }
    v12 = *Roots;
    v13 = (unsigned __int64)*Roots;
    if ( *Roots )
    {
      do
      {
        v14 = *(unsigned int *)(v13 + 24);
        if ( v14 >= 0x41 )
          v14 = *(_QWORD *)(v13 + 32);
        visitor->vfptr->Visit(visitor, *(Scaleform::Heap::HeapSegment **)(v13 + 16), v13, v14 << shift, cat);
        v13 = *(_QWORD *)(v13 + 8);
      }
      while ( (Scaleform::HeapPT::BinLNode *)v13 != v12 );
    }
    Scaleform::HeapPT::FreeBin::visitTree(this, (Scaleform::HeapPT::BinTNode *)Roots[65], visitor, shift, cat);
    ++Roots;
    --v9;
  }
  while ( v9 );
}

