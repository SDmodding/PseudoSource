// File Line: 131
// RVA: 0x979410
Scaleform::HeapPT::BinLNode *__fastcall Scaleform::HeapPT::ListBin::FindAligned(Scaleform::HeapPT::ListBin *this, Scaleform::HeapPT::BinLNode *root, unsigned __int64 blocks, unsigned __int64 shift, unsigned __int64 alignMask)
{
  Scaleform::HeapPT::BinLNode *v5; // rbx
  Scaleform::HeapPT::BinLNode *v6; // r10
  unsigned __int64 v7; // rsi
  unsigned __int64 v8; // rdi
  unsigned __int64 v9; // rdx
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // r8

  v5 = root;
  v6 = root;
  if ( !root )
    return 0i64;
  v7 = blocks << shift;
  v8 = ~alignMask;
  while ( 1 )
  {
    v9 = v8 & ((unsigned __int64)v6 + alignMask);
    v10 = (v8 & ((unsigned __int64)v6 + alignMask)) - (_QWORD)v6;
    if ( (Scaleform::HeapPT::BinLNode *)(v8 & ((unsigned __int64)v6 + alignMask)) != v6 )
    {
      do
      {
        if ( v10 >= 0x20 )
          break;
        v9 += alignMask + 1;
        v10 += alignMask + 1;
      }
      while ( v10 );
    }
    v11 = v6->ShortSize;
    if ( v11 >= 0x41 )
      v11 = (unsigned __int64)v6[1].pPrev;
    if ( v9 + v7 <= (unsigned __int64)v6 + (v11 << shift) )
      break;
    v6 = v6->pNext;
    if ( v6 == v5 )
      return 0i64;
  }
  return v6;
}

// File Line: 147
// RVA: 0x9A1970
unsigned __int64 __fastcall Scaleform::HeapPT::ListBin::PullBest(Scaleform::HeapPT::ListBin *this, unsigned __int64 idx, unsigned __int64 blocks, unsigned __int64 shift, unsigned __int64 alignMask)
{
  Scaleform::HeapPT::ListBin *v5; // rsi
  unsigned __int64 result; // rax
  unsigned __int64 v7; // r14
  unsigned __int64 v8; // r15
  unsigned __int64 v9; // rbx
  Scaleform::HeapPT::BinLNode **v10; // rdi
  Scaleform::HeapPT::BinLNode *v11; // rdx
  Scaleform::HeapPT::BinLNode *v12; // rax
  signed __int64 v13; // rcx
  Scaleform::HeapPT::BinLNode *v14; // r8

  v5 = this;
  result = this->Mask >> idx;
  v7 = shift;
  v8 = blocks;
  if ( result )
  {
    v9 = idx + (unsigned __int8)Scaleform::Alg::LowerBit(result);
    v10 = &v5->Roots[v9];
    while ( 1 )
    {
      result = (unsigned __int64)Scaleform::HeapPT::ListBin::FindAligned(v5, *v10, v8, v7, alignMask);
      v11 = (Scaleform::HeapPT::BinLNode *)result;
      if ( result )
        break;
      ++v9;
      ++v10;
      if ( v9 >= 0x40 )
        return result;
    }
    v12 = v5->Roots[v9];
    v13 = (signed __int64)v5 + 8 * v9;
    if ( v11 == v12 )
    {
      v14 = v12->pNext;
      if ( v12 == v14 )
      {
        *(_QWORD *)(v13 + 8) = 0i64;
        v5->Mask &= ~(1i64 << v9);
        goto LABEL_10;
      }
      *(_QWORD *)(v13 + 8) = v14;
    }
    v11->pPrev->pNext = v11->pNext;
    v11->pNext->pPrev = v11->pPrev;
LABEL_10:
    result = (unsigned __int64)v11;
  }
  return result;
}

// File Line: 216
// RVA: 0x9A36D0
void __fastcall Scaleform::HeapPT::TreeBin::PushNode(Scaleform::HeapPT::TreeBin *this, Scaleform::HeapPT::BinTNode *node)
{
  unsigned __int64 v2; // rdi
  Scaleform::HeapPT::TreeBin *v3; // rsi
  Scaleform::HeapPT::BinTNode *v4; // rbx
  unsigned __int64 v5; // rcx
  unsigned __int8 v6; // al
  Scaleform::HeapPT::BinTNode **v7; // rdx
  Scaleform::HeapPT::BinTNode *v8; // rdx
  signed __int64 v9; // rax
  unsigned __int64 v10; // r8
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  Scaleform::HeapPT::BinTNode *v13; // rax
  Scaleform::HeapPT::BinTNode **v14; // rax

  v2 = node->Size;
  v3 = this;
  v4 = node;
  v5 = node->Size >> 6;
  if ( v5 )
  {
    if ( v5 <= 0xFFFFFFFFFFFFFFFFui64 )
    {
      v6 = Scaleform::Alg::UpperBit(v5);
      v5 = ((v2 >> (v6 + 5)) & 1) + 2i64 * v6;
    }
    else
    {
      v5 = 63i64;
    }
  }
  v4->Index = v5;
  v4->Child[1] = 0i64;
  v4->Child[0] = 0i64;
  v7 = &v3->Roots[v5];
  if ( v3->Mask & (1i64 << v5) )
  {
    v8 = *v7;
    if ( v5 < 0x3F )
      v9 = 59 - (v5 >> 1);
    else
      LOBYTE(v9) = 0;
    v10 = v2 << v9;
    if ( v8->Size == v2 )
    {
LABEL_13:
      v14 = (Scaleform::HeapPT::BinTNode **)v8->pNext;
      *v14 = v4;
      v8->pNext = (Scaleform::HeapPT::BinLNode *)&v4->pPrev;
      v4->pNext = (Scaleform::HeapPT::BinLNode *)v14;
      v4->pPrev = (Scaleform::HeapPT::BinLNode *)&v8->pPrev;
      v4->Parent = 0i64;
    }
    else
    {
      while ( 1 )
      {
        v11 = v10;
        v10 *= 2i64;
        v11 >>= 63;
        v12 = (signed __int64)v8 + 8 * v11;
        v13 = v8->Child[v11];
        if ( !v13 )
          break;
        v8 = v13;
        if ( v13->Size == v2 )
          goto LABEL_13;
      }
      *(_QWORD *)(v12 + 48) = v4;
      v4->Parent = v8;
      v4->pPrev = (Scaleform::HeapPT::BinLNode *)&v4->pPrev;
      v4->pNext = (Scaleform::HeapPT::BinLNode *)&v4->pPrev;
    }
  }
  else
  {
    v3->Mask |= 1i64 << v5;
    *v7 = v4;
    v4->Parent = (Scaleform::HeapPT::BinTNode *)v7;
    v4->pPrev = (Scaleform::HeapPT::BinLNode *)&v4->pPrev;
    v4->pNext = (Scaleform::HeapPT::BinLNode *)&v4->pPrev;
  }
}

// File Line: 273
// RVA: 0x9A1CE0
void __fastcall Scaleform::HeapPT::TreeBin::PullNode(Scaleform::HeapPT::TreeBin *this, Scaleform::HeapPT::BinTNode *node)
{
  Scaleform::HeapPT::BinTNode *v2; // r8
  Scaleform::HeapPT::BinTNode *v3; // r10
  __int64 v4; // r11
  Scaleform::HeapPT::TreeBin *v5; // rbx
  Scaleform::HeapPT::BinLNode *v6; // rax
  Scaleform::HeapPT::BinTNode **v7; // r9
  Scaleform::HeapPT::BinTNode *v8; // rcx
  signed __int64 v9; // rax
  unsigned __int64 v10; // rax
  Scaleform::HeapPT::BinTNode *v11; // rax
  Scaleform::HeapPT::BinTNode *v12; // rax

  v2 = (Scaleform::HeapPT::BinTNode *)node->pPrev;
  v3 = node->Parent;
  v4 = 0i64;
  v5 = this;
  if ( (Scaleform::HeapPT::BinTNode *)node->pPrev == node )
  {
    v2 = node->Child[1];
    v7 = &node->Child[1];
    if ( v2 || (v2 = node->Child[0], v7 = node->Child, v2) )
    {
      while ( 1 )
      {
        v8 = v2->Child[1];
        v9 = (signed __int64)&v2->Child[1];
        if ( !v8 )
        {
          v8 = v2->Child[0];
          v9 = (signed __int64)v2->Child;
          if ( !v8 )
            break;
        }
        v7 = (Scaleform::HeapPT::BinTNode **)v9;
        v2 = v8;
      }
      *v7 = 0i64;
    }
  }
  else
  {
    v6 = node->pNext;
    v6->pPrev = (Scaleform::HeapPT::BinLNode *)&v2->pPrev;
    v2->pNext = v6;
  }
  if ( v3 )
  {
    v10 = node->Index;
    if ( node == v5->Roots[v10] )
    {
      v5->Roots[v10] = v2;
      if ( !v2 )
      {
        v5->Mask &= ~(1i64 << node->Index);
        return;
      }
    }
    else
    {
      LOBYTE(v4) = v3->Child[0] != node;
      v3->Child[v4] = v2;
      if ( !v2 )
        return;
    }
    v2->Parent = v3;
    v11 = node->Child[0];
    if ( v11 )
    {
      v2->Child[0] = v11;
      v11->Parent = v2;
    }
    v12 = node->Child[1];
    if ( v12 )
    {
      v2->Child[1] = v12;
      v12->Parent = v2;
    }
  }
}

// File Line: 342
// RVA: 0x9794B0
Scaleform::HeapPT::BinTNode *__fastcall Scaleform::HeapPT::TreeBin::FindBest(Scaleform::HeapPT::TreeBin *this, unsigned __int64 size)
{
  Scaleform::HeapPT::TreeBin *v2; // rbp
  unsigned __int64 v3; // rcx
  Scaleform::HeapPT::BinTNode *v4; // rdi
  unsigned __int64 v5; // rbx
  unsigned __int64 v6; // rsi
  unsigned __int64 v7; // r10
  unsigned __int8 v8; // al
  Scaleform::HeapPT::BinTNode *v9; // rax
  Scaleform::HeapPT::BinTNode *v10; // r9
  signed __int64 v11; // rcx
  unsigned __int64 i; // r8
  Scaleform::HeapPT::BinTNode *v13; // rdx
  signed __int64 v14; // rcx

  v2 = this;
  v3 = size >> 6;
  v4 = 0i64;
  v5 = -(signed __int64)size;
  v6 = size;
  if ( size >> 6 )
  {
    if ( v3 <= 0xFFFFFFFFFFFFFFFFui64 )
    {
      v8 = Scaleform::Alg::UpperBit(v3);
      v7 = ((v6 >> (v8 + 5)) & 1) + 2i64 * v8;
    }
    else
    {
      v7 = 63i64;
    }
  }
  else
  {
    v7 = 0i64;
  }
  v9 = v2->Roots[v7];
  if ( v9 )
  {
    v10 = 0i64;
    if ( v7 < 0x3F )
      v11 = 59 - (v7 >> 1);
    else
      LOBYTE(v11) = 0;
    for ( i = v6 << v11; ; i *= 2i64 )
    {
      if ( v9->Size - v6 < v5 )
      {
        v4 = v9;
        v5 = v9->Size - v6;
        if ( v9->Size == v6 )
          break;
      }
      v13 = v9->Child[1];
      v9 = v9->Child[i >> 63];
      if ( v13 && v13 != v9 )
        v10 = v13;
      if ( !v9 )
      {
        v9 = v10;
        break;
      }
    }
    if ( v9 )
      goto LABEL_24;
    if ( v4 )
      return v4;
  }
  v14 = v2->Mask & ((1i64 << ((unsigned __int8)v7 + 1)) | -(1i64 << ((unsigned __int8)v7 + 1)));
  if ( v14 )
    v9 = v2->Roots[(unsigned __int8)Scaleform::Alg::LowerBit(v14)];
  while ( v9 )
  {
LABEL_24:
    if ( v9->Size - v6 < v5 )
    {
      v5 = v9->Size - v6;
      v4 = v9;
    }
    v9 = v9->Child[v9->Child[0] == 0i64];
  }
  return v4;
}

// File Line: 510
// RVA: 0x9A1E50
void __fastcall Scaleform::HeapPT::FreeBin::Push(Scaleform::HeapPT::FreeBin *this, char *node)
{
  unsigned __int64 v2; // rax
  Scaleform::HeapPT::FreeBin *v3; // r8
  __int64 v4; // rcx
  signed __int64 v5; // r9
  Scaleform::HeapPT::BinLNode *v6; // rcx
  signed __int64 v7; // r9

  v2 = *((unsigned int *)node + 6);
  v3 = this;
  if ( v2 >= 0x41 )
    v2 = *((_QWORD *)node + 4);
  this->FreeBlocks += v2;
  if ( v2 > 0x40 )
  {
    if ( v2 > 0x80 )
    {
      Scaleform::HeapPT::TreeBin::PushNode(&this->TreeBin1, (Scaleform::HeapPT::BinTNode *)node);
    }
    else
    {
      v6 = this->ListBin1.Roots[v2];
      v7 = v2 - 65;
      if ( v6 )
      {
        *(_QWORD *)node = v6;
        *((_QWORD *)node + 1) = v6->pNext;
        v6->pNext->pPrev = (Scaleform::HeapPT::BinLNode *)node;
        v6->pNext = (Scaleform::HeapPT::BinLNode *)node;
      }
      else
      {
        *((_QWORD *)node + 1) = node;
        *(_QWORD *)node = node;
      }
      v3->ListBin2.Roots[v7] = (Scaleform::HeapPT::BinLNode *)node;
      v3->ListBin2.Mask |= 1i64 << v7;
    }
  }
  else
  {
    v4 = *(&this->ListBin1.Mask + v2);
    v5 = v2 - 1;
    if ( v4 )
    {
      *(_QWORD *)node = v4;
      *((_QWORD *)node + 1) = *(_QWORD *)(v4 + 8);
      **(_QWORD **)(v4 + 8) = node;
      *(_QWORD *)(v4 + 8) = node;
    }
    else
    {
      *((_QWORD *)node + 1) = node;
      *(_QWORD *)node = node;
    }
    v3->ListBin1.Roots[v5] = (Scaleform::HeapPT::BinLNode *)node;
    v3->ListBin1.Mask |= 1i64 << v5;
  }
}

// File Line: 529
// RVA: 0x9A1490
void __fastcall Scaleform::HeapPT::FreeBin::Pull(Scaleform::HeapPT::FreeBin *this, char *node)
{
  unsigned __int64 v2; // rax
  Scaleform::HeapPT::FreeBin *v3; // r8
  signed __int64 v4; // r10
  Scaleform::HeapPT::BinLNode *v5; // rax
  unsigned __int64 *v6; // rcx
  Scaleform::HeapPT::BinLNode *v7; // r9
  signed __int64 v8; // r9
  Scaleform::HeapPT::BinLNode *v9; // rax
  Scaleform::HeapPT::BinLNode *v10; // rcx

  v2 = *((unsigned int *)node + 6);
  v3 = this;
  if ( v2 >= 0x41 )
    v2 = *((_QWORD *)node + 4);
  this->FreeBlocks -= v2;
  if ( v2 > 0x40 )
  {
    if ( v2 > 0x80 )
    {
      Scaleform::HeapPT::TreeBin::PullNode(&this->TreeBin1, (Scaleform::HeapPT::BinTNode *)node);
    }
    else
    {
      v8 = v2 - 65;
      v9 = this->ListBin1.Roots[v2];
      if ( node != (char *)v9 )
        goto LABEL_7;
      v10 = v9->pNext;
      if ( v9 != v10 )
      {
        v3->ListBin2.Roots[v8] = v10;
        goto LABEL_7;
      }
      v3->ListBin2.Roots[v8] = 0i64;
      v3->ListBin2.Mask &= ~(1i64 << v8);
    }
  }
  else
  {
    v4 = v2 - 1;
    v5 = this->ListBin1.Roots[v2 - 1];
    v6 = &this->ListBin1.Mask + v4;
    if ( node != (char *)v5 )
    {
LABEL_7:
      *(_QWORD *)(*(_QWORD *)node + 8i64) = *((_QWORD *)node + 1);
      **((_QWORD **)node + 1) = *(_QWORD *)node;
      return;
    }
    v7 = v5->pNext;
    if ( v5 != v7 )
    {
      v6[1] = (unsigned __int64)v7;
      goto LABEL_7;
    }
    v6[1] = 0i64;
    v3->ListBin1.Mask &= ~(1i64 << v4);
  }
}

// File Line: 548
// RVA: 0x9A17B0
char *__fastcall Scaleform::HeapPT::FreeBin::PullBest(Scaleform::HeapPT::FreeBin *this, unsigned __int64 blocks)
{
  unsigned __int64 v2; // rdi
  Scaleform::HeapPT::FreeBin *v3; // rbx
  unsigned __int64 v4; // rax
  unsigned __int64 v5; // rcx
  signed __int64 v6; // rdx
  char *v7; // r8
  char *v8; // rax
  char *result; // rax
  unsigned __int64 v10; // rbp
  unsigned __int64 v11; // rcx
  Scaleform::HeapPT::BinLNode *v12; // rdx
  Scaleform::HeapPT::BinLNode *v13; // rax
  Scaleform::HeapPT::BinTNode *v14; // rax
  Scaleform::HeapPT::BinTNode *v15; // rdi

  v2 = blocks;
  v3 = this;
  if ( blocks > 0x80 )
    goto LABEL_23;
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
      v6 = (signed __int64)v3 + 8 * v5;
      v7 = *(char **)(v6 + 8);
      v8 = (char *)*((_QWORD *)v7 + 1);
      if ( v7 == v8 )
      {
        *(_QWORD *)(v6 + 8) = 0i64;
        v3->ListBin1.Mask &= ~(1i64 << v5);
      }
      else
      {
        *(_QWORD *)(v6 + 8) = v8;
        *(_QWORD *)(*(_QWORD *)v7 + 8i64) = *((_QWORD *)v7 + 1);
        **((_QWORD **)v7 + 1) = *(_QWORD *)v7;
      }
      if ( v7 )
      {
        result = v7;
        v3->FreeBlocks -= *((unsigned int *)v7 + 6);
        return result;
      }
    }
    v10 = 0i64;
  }
  if ( v3->ListBin2.Mask >> v10
    && ((v11 = v10 + (unsigned __int8)Scaleform::Alg::LowerBit(v3->ListBin2.Mask >> v10),
         v12 = v3->ListBin2.Roots[v11],
         v13 = v12->pNext,
         v12 == v13) ? (v3->ListBin2.Roots[v11] = 0i64, v3->ListBin2.Mask &= ~(1i64 << v11)) : (v3->ListBin2.Roots[v11] = v13,
                                                                                                v12->pPrev->pNext = v12->pNext,
                                                                                                v12->pNext->pPrev = v12->pPrev),
        v12) )
  {
    result = (char *)v12;
    v3->FreeBlocks -= (unsigned __int64)v12[1].pPrev;
  }
  else
  {
LABEL_23:
    v14 = Scaleform::HeapPT::TreeBin::FindBest(&v3->TreeBin1, v2);
    v15 = v14;
    if ( v14 )
    {
      v15 = (Scaleform::HeapPT::BinTNode *)v14->pNext;
      Scaleform::HeapPT::TreeBin::PullNode(&v3->TreeBin1, (Scaleform::HeapPT::BinTNode *)v14->pNext);
      if ( v15 )
        v3->FreeBlocks -= v15->Size;
    }
    result = (char *)v15;
  }
  return result;
}

// File Line: 578
// RVA: 0x9A1630
Scaleform::HeapPT::BinLNode *__fastcall Scaleform::HeapPT::FreeBin::PullBest(Scaleform::HeapPT::FreeBin *this, unsigned __int64 blocks, unsigned __int64 shift, unsigned __int64 alignMask)
{
  unsigned __int64 v4; // rdi
  unsigned __int64 v5; // r14
  unsigned __int64 v6; // rsi
  Scaleform::HeapPT::FreeBin *v7; // r15
  Scaleform::HeapPT::BinLNode *result; // rax
  unsigned __int64 v9; // rdx
  Scaleform::HeapPT::BinTNode *v10; // rbx
  Scaleform::HeapPT::BinTNode *v11; // r9
  unsigned __int64 v12; // rsi
  unsigned __int64 v13; // rbp
  unsigned __int64 v14; // rdx
  unsigned __int64 v15; // rax
  unsigned __int64 v16; // r8

  v4 = alignMask;
  v5 = shift;
  v6 = blocks;
  v7 = this;
  if ( blocks > 0x80 )
    goto LABEL_24;
  if ( blocks > 0x40 )
  {
    v9 = blocks - 65;
  }
  else
  {
    result = Scaleform::HeapPT::ListBin::PullBest(&this->ListBin1, blocks - 1, blocks, shift, alignMask);
    if ( result )
    {
      v7->FreeBlocks -= result->ShortSize;
      return result;
    }
    v9 = 0i64;
  }
  result = Scaleform::HeapPT::ListBin::PullBest(&v7->ListBin2, v9, v6, v5, v4);
  if ( result )
  {
    v7->FreeBlocks -= (unsigned __int64)result[1].pPrev;
  }
  else
  {
LABEL_24:
    v10 = Scaleform::HeapPT::TreeBin::FindBest(&v7->TreeBin1, v6);
    v11 = v10;
    if ( v10 )
    {
      v12 = v6 << v5;
      v13 = ~v4;
      while ( 1 )
      {
        v14 = v13 & ((unsigned __int64)v10 + v4);
        v15 = (v13 & ((unsigned __int64)v10 + v4)) - (_QWORD)v10;
        if ( (Scaleform::HeapPT::BinTNode *)(v13 & ((unsigned __int64)v10 + v4)) != v10 )
        {
          do
          {
            if ( v15 >= 0x20 )
              break;
            v14 += v4 + 1;
            v15 += v4 + 1;
          }
          while ( v15 );
        }
        v16 = v10->ShortSize;
        if ( v16 >= 0x41 )
          v16 = v10->Size;
        if ( v14 + v12 <= (unsigned __int64)v10 + (v16 << v5) )
          break;
        v10 = (Scaleform::HeapPT::BinTNode *)v10->pNext;
        if ( v10 == v11 )
        {
          v10 = Scaleform::HeapPT::TreeBin::FindBest(&v7->TreeBin1, v10->Size + 1);
          v11 = v10;
          if ( !v10 )
            goto LABEL_19;
        }
      }
      Scaleform::HeapPT::TreeBin::PullNode(&v7->TreeBin1, v10);
      v7->FreeBlocks -= v10->Size;
      result = (Scaleform::HeapPT::BinLNode *)&v10->pPrev;
    }
    else
    {
LABEL_19:
      result = 0i64;
    }
  }
  return result;
}

// File Line: 667
// RVA: 0x99A8B0
void __fastcall Scaleform::HeapPT::FreeBin::Merge(Scaleform::HeapPT::FreeBin *this, char *node, unsigned __int64 shift, bool left, bool right)
{
  unsigned __int64 v5; // rdi
  char v6; // r14
  char *v7; // rsi
  Scaleform::HeapPT::FreeBin *v8; // rbp
  char *v9; // rbx
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // rax
  unsigned __int64 v12; // rdx
  char *v13; // rdx
  unsigned __int64 v14; // rax
  unsigned __int64 v15; // rax

  v5 = *((unsigned int *)node + 6);
  v6 = shift;
  v7 = node;
  v8 = this;
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
    v12 = *((unsigned int *)v7 + 6);
    if ( v12 >= 0x41 )
      v12 = *((_QWORD *)v7 + 4);
    v13 = &v7[v12 << v6];
    v14 = *((unsigned int *)v13 + 6);
    if ( v14 >= 0x41 )
      v14 = *((_QWORD *)v13 + 4);
    v5 += v14;
    Scaleform::HeapPT::FreeBin::Pull(v8, v13);
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
  Scaleform::HeapPT::FreeBin::Push(v8, v9);
}

// File Line: 713
// RVA: 0x9FB1D0
void __fastcall Scaleform::HeapPT::FreeBin::visitUnusedInTree(Scaleform::HeapPT::FreeBin *this, Scaleform::HeapPT::BinTNode *root, Scaleform::Heap::SegVisitor *visitor, unsigned __int64 shift, unsigned int cat)
{
  unsigned __int64 v5; // rbp
  Scaleform::Heap::SegVisitor *v6; // rsi
  Scaleform::HeapPT::BinTNode *v7; // rdi
  Scaleform::HeapPT::BinTNode *v8; // rbx
  unsigned __int64 v9; // rdx
  Scaleform::HeapPT::FreeBin *v10; // [rsp+40h] [rbp+8h]

  if ( root )
  {
    v10 = this;
    v5 = shift;
    v6 = visitor;
    v7 = root;
    do
    {
      Scaleform::HeapPT::FreeBin::visitUnusedInTree(this, v7->Child[0], v6, v5, cat);
      v8 = v7;
      do
      {
        v9 = v8->ShortSize;
        if ( v9 >= 0x41 )
          v9 = v8->Size;
        if ( (((unsigned __int64)&v8[56].Child[1] + 7) & 0xFFFFFFFFFFFFF000ui64) + 4096 <= (((unsigned __int64)v8
                                                                                           + (v9 << v5)) & 0xFFFFFFFFFFFFF000ui64) )
          ((void (__fastcall *)(Scaleform::Heap::SegVisitor *, _QWORD, Scaleform::MemoryHeapPT *))v6->vfptr->Visit)(
            v6,
            cat,
            v8->pSegment->pHeap);
        v8 = (Scaleform::HeapPT::BinTNode *)v8->pNext;
      }
      while ( v8 != v7 );
      v7 = v7->Child[1];
      this = v10;
    }
    while ( v7 );
  }
}

// File Line: 730
// RVA: 0x9C21C0
void __fastcall Scaleform::HeapPT::FreeBin::VisitUnused(Scaleform::HeapPT::FreeBin *this, Scaleform::Heap::SegVisitor *visitor, unsigned __int64 shift, unsigned int cat)
{
  unsigned int v4; // er14
  unsigned __int64 v5; // rbp
  Scaleform::Heap::SegVisitor *v6; // rsi
  Scaleform::HeapPT::FreeBin *v7; // r13
  Scaleform::HeapPT::BinLNode **v8; // r15
  signed __int64 v9; // r12
  __int64 v10; // rdi
  __int64 v11; // rbx
  unsigned __int64 v12; // rax
  unsigned __int64 v13; // rdx
  Scaleform::HeapPT::BinLNode *v14; // rdi
  Scaleform::HeapPT::BinLNode *v15; // rbx
  unsigned __int64 v16; // rax
  unsigned __int64 v17; // rdx

  v4 = cat;
  v5 = shift;
  v6 = visitor;
  v7 = this;
  v8 = this->ListBin2.Roots;
  v9 = 64i64;
  do
  {
    v10 = (__int64)*(v8 - 65);
    v11 = v10;
    if ( v10 )
    {
      v12 = *(unsigned int *)(v10 + 24);
      if ( v12 >= 0x41 )
        v12 = *(_QWORD *)(v10 + 32);
      if ( v12 << v5 >= 0x1000 )
      {
        do
        {
          v13 = *(unsigned int *)(v11 + 24);
          if ( v13 >= 0x41 )
            v13 = *(_QWORD *)(v11 + 32);
          if ( ((v11 + 4095) & 0xFFFFFFFFFFFFF000ui64) + 4096 <= ((v11 + (v13 << v5)) & 0xFFFFFFFFFFFFF000ui64) )
            ((void (__fastcall *)(Scaleform::Heap::SegVisitor *, _QWORD, _QWORD))v6->vfptr->Visit)(
              v6,
              v4,
              *(_QWORD *)(*(_QWORD *)(v11 + 16) + 40i64));
          v11 = *(_QWORD *)(v11 + 8);
        }
        while ( v11 != v10 );
      }
    }
    v14 = *v8;
    v15 = *v8;
    if ( *v8 )
    {
      v16 = v14->ShortSize;
      if ( v16 >= 0x41 )
        v16 = (unsigned __int64)v14[1].pPrev;
      if ( v16 << v5 >= 0x1000 )
      {
        do
        {
          v17 = v15->ShortSize;
          if ( v17 >= 0x41 )
            v17 = (unsigned __int64)v15[1].pPrev;
          if ( (((unsigned __int64)&v15[127].Filler + 3) & 0xFFFFFFFFFFFFF000ui64) + 4096 <= (((unsigned __int64)v15
                                                                                             + (v17 << v5)) & 0xFFFFFFFFFFFFF000ui64) )
            ((void (__fastcall *)(Scaleform::Heap::SegVisitor *, _QWORD, Scaleform::MemoryHeapPT *))v6->vfptr->Visit)(
              v6,
              v4,
              v15->pSegment->pHeap);
          v15 = v15->pNext;
        }
        while ( v15 != v14 );
      }
    }
    Scaleform::HeapPT::FreeBin::visitUnusedInTree(v7, (Scaleform::HeapPT::BinTNode *)v8[65], v6, v5, v4);
    ++v8;
    --v9;
  }
  while ( v9 );
}

// File Line: 759
// RVA: 0x9FB060
void __fastcall Scaleform::HeapPT::FreeBin::visitTree(Scaleform::HeapPT::FreeBin *this, Scaleform::HeapPT::BinTNode *root, Scaleform::Heap::MemVisitor *visitor, unsigned __int64 shift, Scaleform::Heap::MemVisitor::Category cat)
{
  unsigned __int64 v5; // rax
  Scaleform::Heap::MemVisitor *v6; // rsi
  Scaleform::HeapPT::BinTNode *v7; // rdi
  Scaleform::HeapPT::BinTNode *v8; // rbx
  _QWORD v9[2]; // [rsp+20h] [rbp-28h]
  Scaleform::HeapPT::FreeBin *v10; // [rsp+50h] [rbp+8h]
  unsigned __int64 v11; // [rsp+68h] [rbp+20h]

  if ( root )
  {
    v11 = shift;
    v10 = this;
    v5 = shift;
    v6 = visitor;
    v7 = root;
    do
    {
      Scaleform::HeapPT::FreeBin::visitTree(this, v7->Child[0], v6, v5, cat);
      v8 = v7;
      do
      {
        LODWORD(v9[0]) = cat;
        v6->vfptr->Visit(
          v6,
          v8->pSegment,
          (unsigned __int64)v8,
          v8->Size << v11,
          (Scaleform::Heap::MemVisitor::Category)v9[0]);
        v8 = (Scaleform::HeapPT::BinTNode *)v8->pNext;
      }
      while ( v8 != v7 );
      v7 = v7->Child[1];
      v5 = v11;
      this = v10;
    }
    while ( v7 );
  }
}

// File Line: 778
// RVA: 0x9C1C30
void __fastcall Scaleform::HeapPT::FreeBin::VisitMem(Scaleform::HeapPT::FreeBin *this, Scaleform::Heap::MemVisitor *visitor, unsigned __int64 shift, Scaleform::Heap::MemVisitor::Category cat)
{
  Scaleform::Heap::MemVisitor::Category v4; // ebp
  unsigned __int64 v5; // r14
  Scaleform::Heap::MemVisitor *v6; // rdi
  Scaleform::HeapPT::FreeBin *v7; // r13
  Scaleform::HeapPT::BinLNode **v8; // r15
  signed __int64 v9; // r12
  unsigned __int64 v10; // rsi
  unsigned __int64 v11; // rbx
  Scaleform::HeapPT::BinLNode *v12; // rsi
  unsigned __int64 v13; // rbx
  unsigned __int64 v14; // r9
  __int64 cata[7]; // [rsp+20h] [rbp-38h]

  v4 = cat;
  v5 = shift;
  v6 = visitor;
  v7 = this;
  v8 = this->ListBin2.Roots;
  v9 = 64i64;
  do
  {
    v10 = (unsigned __int64)*(v8 - 65);
    v11 = v10;
    if ( v10 )
    {
      do
      {
        LODWORD(cata[0]) = v4;
        v6->vfptr->Visit(
          v6,
          *(Scaleform::Heap::HeapSegment **)(v11 + 16),
          v11,
          (unsigned __int64)*(unsigned int *)(v11 + 24) << v5,
          (Scaleform::Heap::MemVisitor::Category)cata[0]);
        v11 = *(_QWORD *)(v11 + 8);
      }
      while ( v11 != v10 );
    }
    v12 = *v8;
    v13 = (unsigned __int64)*v8;
    if ( *v8 )
    {
      do
      {
        v14 = *(unsigned int *)(v13 + 24);
        if ( v14 >= 0x41 )
          v14 = *(_QWORD *)(v13 + 32);
        LODWORD(cata[0]) = v4;
        v6->vfptr->Visit(
          v6,
          *(Scaleform::Heap::HeapSegment **)(v13 + 16),
          v13,
          v14 << v5,
          (Scaleform::Heap::MemVisitor::Category)cata[0]);
        v13 = *(_QWORD *)(v13 + 8);
      }
      while ( (Scaleform::HeapPT::BinLNode *)v13 != v12 );
    }
    Scaleform::HeapPT::FreeBin::visitTree(v7, (Scaleform::HeapPT::BinTNode *)v8[65], v6, v5, v4);
    ++v8;
    --v9;
  }
  while ( v9 );
}

