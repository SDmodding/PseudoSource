// File Line: 32
// RVA: 0x993EA0
void __fastcall Scaleform::HeapPT::AllocBitSet2::InitSegment(
        Scaleform::HeapPT::AllocBitSet2 *this,
        Scaleform::Heap::HeapSegment *seg)
{
  unsigned __int64 DataSize; // r8
  unsigned __int64 MinAlignShift; // rcx
  unsigned __int64 v6; // rax
  char *pData; // rdx
  unsigned __int64 v8; // rax
  unsigned __int64 v9; // r8

  DataSize = seg->DataSize;
  MinAlignShift = this->MinAlignShift;
  LODWORD(seg[1].pPrev) &= 0xFFFFFFFC;
  *((_DWORD *)&seg[1].pPrev + (((DataSize >> MinAlignShift) - 1) >> 4)) &= ~(3 << ((2 * ((DataSize >> MinAlignShift) - 1)) & 0x1E));
  v6 = seg->DataSize;
  pData = seg->pData;
  v8 = v6 >> this->MinAlignShift;
  v9 = v8 << this->MinAlignShift;
  if ( v8 >= 0x41 )
  {
    *(_DWORD *)&pData[v9 - 4] = 65;
    *((_DWORD *)pData + 6) = 65;
    *(_QWORD *)&pData[v9 - 16] = v8;
    *((_QWORD *)pData + 4) = v8;
  }
  else
  {
    *(_DWORD *)&pData[v9 - 4] = v8;
    *((_DWORD *)pData + 6) = v8;
  }
  *((_QWORD *)pData + 2) = seg;
  Scaleform::HeapPT::FreeBin::Push(&this->Bin, pData);
}

// File Line: 46
// RVA: 0x955CA0
char *__fastcall Scaleform::HeapPT::AllocBitSet2::Alloc(
        Scaleform::HeapPT::AllocBitSet2 *this,
        unsigned __int64 bytes,
        Scaleform::Heap::HeapSegment **allocSeg)
{
  Scaleform::HeapPT::FreeBin *p_Bin; // r12
  unsigned __int64 v5; // rsi
  char *result; // rax
  char *v7; // rdi
  unsigned __int64 MinAlignShift; // rbp
  unsigned __int64 v9; // rbx
  __int64 v10; // r14
  __int64 v11; // r13
  __int64 v12; // r15
  unsigned __int64 v13; // rbx
  unsigned __int64 v14; // rax
  char *v15; // rdx
  _DWORD *v16; // rdx
  unsigned __int64 v17; // rcx

  p_Bin = &this->Bin;
  v5 = bytes;
  result = Scaleform::HeapPT::FreeBin::PullBest(&this->Bin, bytes >> this->MinAlignShift);
  v7 = result;
  if ( result )
  {
    MinAlignShift = this->MinAlignShift;
    v9 = *((unsigned int *)result + 6);
    v10 = *((_QWORD *)result + 2);
    v11 = *(_QWORD *)(v10 + 56);
    v12 = v10 + 64;
    if ( v9 >= 0x41 )
      v9 = *((_QWORD *)result + 4);
    v13 = v9 - (v5 >> MinAlignShift);
    v14 = v13 << MinAlignShift;
    if ( v13 << MinAlignShift < 0x20 )
    {
      v5 += v14;
    }
    else
    {
      v15 = &v7[v5];
      if ( v13 >= 0x41 )
      {
        *(_DWORD *)&v15[v14 - 4] = 65;
        *((_DWORD *)v15 + 6) = 65;
        *(_QWORD *)&v15[v14 - 16] = v13;
        *((_QWORD *)v15 + 4) = v13;
      }
      else
      {
        *(_DWORD *)&v15[v14 - 4] = v13;
        *((_DWORD *)v15 + 6) = v13;
      }
      *((_QWORD *)v15 + 2) = v10;
      Scaleform::HeapPT::FreeBin::Push(p_Bin, v15);
      v16 = (_DWORD *)(v12 + 4 * ((unsigned __int64)((__int64)&v7[v5 - v11] >> MinAlignShift) >> 4));
      v17 = v13 + ((__int64)&v7[v5 - v11] >> MinAlignShift) - 1;
      *v16 &= ~(3 << ((2 * ((__int64)&v7[v5 - v11] >> MinAlignShift)) & 0x1E));
      *(_DWORD *)(v12 + 4 * (v17 >> 4)) &= ~(3 << ((2 * v17) & 0x1E));
    }
    Scaleform::Heap::BitSet2::MarkBusy(
      (unsigned int *)(v10 + 64),
      (__int64)&v7[-v11] >> MinAlignShift,
      v5 >> MinAlignShift,
      0i64);
    *allocSeg = (Scaleform::Heap::HeapSegment *)v10;
    return v7;
  }
  return result;
}

// File Line: 89
// RVA: 0x955A30
char *__fastcall Scaleform::HeapPT::AllocBitSet2::Alloc(
        Scaleform::HeapPT::AllocBitSet2 *this,
        unsigned __int64 bytes,
        unsigned __int64 alignSize,
        Scaleform::Heap::HeapSegment **allocSeg)
{
  unsigned __int64 MinAlignShift; // r14
  __int64 v5; // rbx
  unsigned __int64 v6; // r15
  char *result; // rax
  char *v8; // rsi
  Scaleform::Heap::HeapSegment *v9; // r13
  char *v10; // rdi
  unsigned __int64 v11; // rcx
  unsigned __int64 v12; // rbx
  unsigned __int64 v13; // rbp
  unsigned __int64 v14; // rbx
  unsigned __int64 v15; // rbp
  unsigned __int64 v16; // rax
  unsigned __int64 v17; // rsi
  __int64 v18; // rdx
  int v19; // eax
  unsigned __int64 v20; // rcx
  unsigned int *v21; // rsi
  char *v22; // rdx
  unsigned __int64 v23; // rbx
  unsigned __int64 v24; // rax
  unsigned int *v25; // rdx
  unsigned __int64 v26; // rcx
  unsigned __int8 v27; // al
  char *pData; // [rsp+70h] [rbp+8h]
  Scaleform::HeapPT::FreeBin *p_Bin; // [rsp+78h] [rbp+10h]

  MinAlignShift = this->MinAlignShift;
  v5 = alignSize - 1;
  v6 = bytes;
  p_Bin = &this->Bin;
  result = Scaleform::HeapPT::FreeBin::PullBest(
             &this->Bin,
             bytes >> this->MinAlignShift,
             this->MinAlignShift,
             alignSize - 1);
  v8 = result;
  if ( result )
  {
    v9 = (Scaleform::Heap::HeapSegment *)*((_QWORD *)result + 2);
    v10 = (char *)(~v5 & (unsigned __int64)&result[v5]);
    pData = v9->pData;
    v11 = v10 - result;
    if ( v10 != result )
    {
      do
      {
        if ( v11 >= 0x20 )
          break;
        v10 += v5 + 1;
        v11 += v5 + 1;
      }
      while ( v11 );
    }
    v12 = *((unsigned int *)result + 6);
    v13 = v10 - result;
    if ( v12 >= 0x41 )
      v12 = *((_QWORD *)result + 4);
    v14 = (unsigned __int64)&result[(v12 << MinAlignShift) - (_QWORD)v10 - v6];
    if ( v13 )
    {
      v15 = v13 >> MinAlignShift;
      v16 = v15 << MinAlignShift;
      if ( v15 >= 0x41 )
      {
        *(_DWORD *)&v8[v16 - 4] = 65;
        *((_DWORD *)v8 + 6) = 65;
        *(_QWORD *)&v8[v16 - 16] = v15;
        *((_QWORD *)v8 + 4) = v15;
      }
      else
      {
        *(_DWORD *)&v8[v16 - 4] = v15;
        *((_DWORD *)v8 + 6) = v15;
      }
      *((_QWORD *)v8 + 2) = v9;
      Scaleform::HeapPT::FreeBin::Push(p_Bin, v8);
      v17 = (v8 - pData) >> MinAlignShift;
      v18 = 4 * (v17 >> 4);
      v19 = 3 << ((2 * v17) & 0x1E);
      v20 = v17 - 1;
      v21 = (unsigned int *)&v9[1];
      *(_DWORD *)((char *)&v9[1].pPrev + v18) &= ~v19;
      *((_DWORD *)&v9[1].pPrev + ((v15 + v20) >> 4)) &= ~(3 << ((2 * (v15 + v20)) & 0x1E));
    }
    else
    {
      v21 = (unsigned int *)&v9[1];
    }
    if ( v14 < 0x20 )
    {
      v6 += v14;
    }
    else
    {
      v22 = &v10[v6];
      v23 = v14 >> MinAlignShift;
      v24 = v23 << MinAlignShift;
      if ( v23 >= 0x41 )
      {
        *(_DWORD *)&v22[v24 - 4] = 65;
        *((_DWORD *)v22 + 6) = 65;
        *(_QWORD *)&v22[v24 - 16] = v23;
        *((_QWORD *)v22 + 4) = v23;
      }
      else
      {
        *(_DWORD *)&v22[v24 - 4] = v23;
        *((_DWORD *)v22 + 6) = v23;
      }
      *((_QWORD *)v22 + 2) = v9;
      Scaleform::HeapPT::FreeBin::Push(p_Bin, v22);
      v25 = &v21[(unsigned __int64)((__int64)(v6 + v10 - pData) >> MinAlignShift) >> 4];
      v26 = ((__int64)(v6 + v10 - pData) >> MinAlignShift) + v23 - 1;
      *v25 &= ~(3 << ((2 * ((__int64)(v6 + v10 - pData) >> MinAlignShift)) & 0x1E));
      v21[v26 >> 4] &= ~(3 << ((2 * v26) & 0x1E));
    }
    v27 = Scaleform::Alg::UpperBit(alignSize);
    Scaleform::Heap::BitSet2::MarkBusy(v21, (v10 - pData) >> MinAlignShift, v6 >> MinAlignShift, v27 - MinAlignShift);
    *allocSeg = v9;
    return v10;
  }
  return result;
}

// File Line: 146
// RVA: 0x97D540
void __fastcall Scaleform::HeapPT::AllocBitSet2::Free(
        Scaleform::HeapPT::AllocBitSet2 *this,
        Scaleform::Heap::HeapSegment *seg,
        char *ptr)
{
  unsigned __int64 MinAlignShift; // r12
  char *v5; // rbx
  Scaleform::Heap::HeapSegment *v6; // r14
  unsigned __int64 v8; // rbp
  unsigned __int64 BlockSize; // r11
  unsigned __int64 v11; // r10
  bool v12; // bl
  bool v13; // r9
  bool right; // dl
  Scaleform::HeapPT::FreeBin *p_Bin; // rcx

  MinAlignShift = this->MinAlignShift;
  v5 = &seg->pData[seg->DataSize];
  v6 = seg + 1;
  v8 = (ptr - seg->pData) >> this->MinAlignShift;
  BlockSize = Scaleform::Heap::BitSet2::GetBlockSize((const unsigned int *)&seg[1], v8);
  *((_DWORD *)&v6->pPrev + (v8 >> 4)) &= ~(3 << ((2 * v8) & 0x1E));
  *((_DWORD *)&v6->pPrev + ((BlockSize + v8 - 1) >> 4)) &= ~(3 << ((2 * (BlockSize + v8 - 1)) & 0x1E));
  v11 = BlockSize << MinAlignShift;
  v12 = &ptr[BlockSize << MinAlignShift] < v5;
  v13 = v8 && ((*((_DWORD *)&v6->pPrev + ((v8 - 1) >> 4)) >> ((2 * (v8 - 1)) & 0x1E)) & 3) == 0;
  right = v12 && ((*((_DWORD *)&v6->pPrev + ((BlockSize + v8) >> 4)) >> ((2 * (BlockSize + v8)) & 0x1E)) & 3) == 0;
  if ( BlockSize >= 0x41 )
  {
    *(_DWORD *)&ptr[v11 - 4] = 65;
    *((_DWORD *)ptr + 6) = 65;
    *(_QWORD *)&ptr[v11 - 16] = BlockSize;
    *((_QWORD *)ptr + 4) = BlockSize;
  }
  else
  {
    *(_DWORD *)&ptr[v11 - 4] = BlockSize;
    *((_DWORD *)ptr + 6) = BlockSize;
  }
  *((_QWORD *)ptr + 2) = seg;
  p_Bin = &this->Bin;
  if ( v13 || right )
    Scaleform::HeapPT::FreeBin::Merge(p_Bin, ptr, MinAlignShift, v13, right);
  else
    Scaleform::HeapPT::FreeBin::Push(p_Bin, ptr);
}

// File Line: 178
// RVA: 0x9A6700
char *__fastcall Scaleform::HeapPT::AllocBitSet2::ReallocInPlace(
        Scaleform::HeapPT::AllocBitSet2 *this,
        Scaleform::Heap::HeapSegment *seg,
        char *oldPtr,
        unsigned __int64 newSize,
        unsigned __int64 *oldSize)
{
  unsigned __int64 MinAlignShift; // rbp
  unsigned int *v7; // r15
  char *v9; // r13
  __int64 v10; // r12
  unsigned int v11; // eax
  unsigned __int64 v12; // rsi
  unsigned __int64 v13; // rdi
  char *v14; // r8
  unsigned __int64 v15; // rbx
  unsigned __int64 v16; // rbx
  unsigned __int64 v17; // rbx
  char *v18; // rsi
  unsigned __int64 v19; // rbx
  unsigned __int64 v20; // rax
  unsigned __int64 v21; // rsi
  unsigned int *v22; // rdx
  char *v24; // r9
  unsigned __int64 v25; // r8
  unsigned __int64 v26; // r10
  unsigned __int64 v27; // r8
  unsigned __int64 v28; // rbx
  char *v29; // rsi
  unsigned __int64 v30; // rbx
  unsigned __int64 v31; // rax
  unsigned __int64 v32; // rsi
  unsigned int *v33; // rdx
  char *pData; // [rsp+20h] [rbp-58h]
  unsigned __int64 BlockSize; // [rsp+90h] [rbp+18h]
  unsigned __int64 alignShift; // [rsp+98h] [rbp+20h]

  MinAlignShift = this->MinAlignShift;
  v7 = (unsigned int *)&seg[1];
  pData = seg->pData;
  v9 = &pData[seg->DataSize];
  v10 = (oldPtr - pData) >> this->MinAlignShift;
  BlockSize = Scaleform::Heap::BitSet2::GetBlockSize((const unsigned int *)&seg[1], v10);
  v11 = Scaleform::Heap::BitSet2::GetAlignShift(v7, v10, BlockSize);
  alignShift = v11;
  v12 = BlockSize << MinAlignShift;
  *oldSize = BlockSize << MinAlignShift;
  v13 = ~((1i64 << ((unsigned __int8)v11 + (unsigned __int8)MinAlignShift)) - 1) & ((1i64 << ((unsigned __int8)v11
                                                                                            + (unsigned __int8)MinAlignShift))
                                                                                  - 1
                                                                                  + newSize);
  if ( v13 <= BlockSize << MinAlignShift )
  {
    if ( v13 < v12 )
    {
      v24 = &oldPtr[v12];
      v25 = 0i64;
      v26 = v12 - v13;
      if ( &oldPtr[v12] < v9 && ((v7[(v10 + BlockSize) >> 4] >> ((2 * (v10 + BlockSize)) & 0x1E)) & 3) == 0 )
      {
        v27 = *((unsigned int *)v24 + 6);
        if ( v27 >= 0x41 )
          v27 = *((_QWORD *)v24 + 4);
        v25 = v27 << MinAlignShift;
      }
      v28 = v25 + v26;
      if ( v25 + v26 >= 0x20 )
      {
        if ( v25 )
          Scaleform::HeapPT::FreeBin::Pull(&this->Bin, (Scaleform::HeapPT::BinTNode *)&oldPtr[v12]);
        v29 = &oldPtr[v13];
        v30 = v28 >> MinAlignShift;
        v31 = v30 << MinAlignShift;
        if ( v30 >= 0x41 )
        {
          *(_DWORD *)&v29[v31 - 4] = 65;
          *((_DWORD *)v29 + 6) = 65;
          *(_QWORD *)&v29[v31 - 16] = v30;
          *((_QWORD *)v29 + 4) = v30;
        }
        else
        {
          *(_DWORD *)&v29[v31 - 4] = v30;
          *((_DWORD *)v29 + 6) = v30;
        }
        *((_QWORD *)v29 + 2) = seg;
        Scaleform::HeapPT::FreeBin::Push(&this->Bin, (Scaleform::HeapPT::BinTNode *)&oldPtr[v13]);
        Scaleform::Heap::BitSet2::MarkBusy(v7, v10, v13 >> MinAlignShift, alignShift);
        v32 = (v29 - pData) >> MinAlignShift;
        v7[v32 >> 4] &= ~(3 << ((2 * v32) & 0x1E));
        v33 = &v7[(v30 + v32 - 1) >> 4];
        *v33 &= ~(3 << ((2 * (v30 + v32 - 1)) & 0x1E));
      }
    }
  }
  else
  {
    v14 = &oldPtr[v12];
    if ( &oldPtr[v12] >= v9 || ((v7[(v10 + BlockSize) >> 4] >> ((2 * (v10 + BlockSize)) & 0x1E)) & 3) != 0 )
      return 0i64;
    v15 = *((unsigned int *)v14 + 6);
    if ( v15 >= 0x41 )
      v15 = *((_QWORD *)v14 + 4);
    v16 = v15 << MinAlignShift;
    if ( v13 > v16 + v12 )
      return 0i64;
    Scaleform::HeapPT::FreeBin::Pull(&this->Bin, (Scaleform::HeapPT::BinTNode *)&oldPtr[v12]);
    v17 = v12 + v16 - v13;
    if ( v17 < 0x20 )
    {
      v13 += v17;
    }
    else
    {
      v18 = &oldPtr[v13];
      v19 = v17 >> MinAlignShift;
      v20 = v19 << MinAlignShift;
      if ( v19 >= 0x41 )
      {
        *(_DWORD *)&v18[v20 - 4] = 65;
        *((_DWORD *)v18 + 6) = 65;
        *(_QWORD *)&v18[v20 - 16] = v19;
        *((_QWORD *)v18 + 4) = v19;
      }
      else
      {
        *(_DWORD *)&v18[v20 - 4] = v19;
        *((_DWORD *)v18 + 6) = v19;
      }
      *((_QWORD *)v18 + 2) = seg;
      Scaleform::HeapPT::FreeBin::Push(&this->Bin, (Scaleform::HeapPT::BinTNode *)&oldPtr[v13]);
      v21 = (v18 - pData) >> MinAlignShift;
      v7[v21 >> 4] &= ~(3 << ((2 * v21) & 0x1E));
      v22 = &v7[(v19 + v21 - 1) >> 4];
      *v22 &= ~(3 << ((2 * (v19 + v21 - 1)) & 0x1E));
    }
    Scaleform::Heap::BitSet2::MarkBusy(v7, v10, v13 >> MinAlignShift, alignShift);
  }
  return oldPtr;
}

