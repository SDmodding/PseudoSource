// File Line: 32
// RVA: 0x993EA0
void __fastcall Scaleform::HeapPT::AllocBitSet2::InitSegment(Scaleform::HeapPT::AllocBitSet2 *this, Scaleform::Heap::HeapSegment *seg)
{
  unsigned __int64 v2; // r8
  Scaleform::Heap::HeapSegment *v3; // r10
  Scaleform::HeapPT::AllocBitSet2 *v4; // r11
  unsigned __int64 v5; // rcx
  unsigned __int64 v6; // rax
  char *v7; // rdx
  unsigned __int64 v8; // rax
  unsigned __int64 v9; // r8

  v2 = seg->DataSize;
  v3 = seg;
  v4 = this;
  v5 = this->MinAlignShift;
  LODWORD(seg[1].pPrev) &= 0xFFFFFFFC;
  *((_DWORD *)&seg[1].pPrev + (((v2 >> v5) - 1) >> 4)) &= ~(3 << (2 * ((v2 >> v5) - 1) & 0x1E));
  v6 = seg->DataSize;
  v7 = seg->pData;
  v8 = v6 >> v4->MinAlignShift;
  v9 = v8 << v4->MinAlignShift;
  if ( v8 >= 0x41 )
  {
    *(_DWORD *)&v7[v9 - 4] = 65;
    *((_DWORD *)v7 + 6) = 65;
    *(_QWORD *)&v7[v9 - 16] = v8;
    *((_QWORD *)v7 + 4) = v8;
  }
  else
  {
    *(_DWORD *)&v7[v9 - 4] = v8;
    *((_DWORD *)v7 + 6) = v8;
  }
  *((_QWORD *)v7 + 2) = v3;
  Scaleform::HeapPT::FreeBin::Push(&v4->Bin, v7);
}

// File Line: 46
// RVA: 0x955CA0
char *__fastcall Scaleform::HeapPT::AllocBitSet2::Alloc(Scaleform::HeapPT::AllocBitSet2 *this, unsigned __int64 bytes, Scaleform::Heap::HeapSegment **allocSeg)
{
  Scaleform::HeapPT::AllocBitSet2 *v3; // rbp
  Scaleform::HeapPT::FreeBin *v4; // r12
  unsigned __int64 v5; // rsi
  char *result; // rax
  char *v7; // rdi
  unsigned __int64 v8; // rbp
  unsigned __int64 v9; // rbx
  __int64 v10; // r14
  __int64 v11; // r13
  signed __int64 v12; // r15
  unsigned __int64 v13; // rbx
  unsigned __int64 v14; // rax
  char *v15; // rdx
  _DWORD *v16; // rdx
  unsigned __int64 v17; // rcx
  Scaleform::Heap::HeapSegment **v18; // [rsp+60h] [rbp+18h]

  v18 = allocSeg;
  v3 = this;
  v4 = &this->Bin;
  v5 = bytes;
  result = Scaleform::HeapPT::FreeBin::PullBest(&this->Bin, bytes >> this->MinAlignShift);
  v7 = result;
  if ( result )
  {
    v8 = v3->MinAlignShift;
    v9 = *((unsigned int *)result + 6);
    v10 = *((_QWORD *)result + 2);
    v11 = *(_QWORD *)(v10 + 56);
    v12 = v10 + 64;
    if ( v9 >= 0x41 )
      v9 = *((_QWORD *)result + 4);
    v13 = v9 - (v5 >> v8);
    v14 = v13 << v8;
    if ( v13 << v8 < 0x20 )
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
      Scaleform::HeapPT::FreeBin::Push(v4, v15);
      v16 = (_DWORD *)(v12 + 4 * ((unsigned __int64)((signed __int64)&v7[v5 - v11] >> v8) >> 4));
      v17 = v13 + ((signed __int64)&v7[v5 - v11] >> v8) - 1;
      *v16 &= ~(3 << (2 * (unsigned __int64)((signed __int64)&v7[v5 - v11] >> v8) & 0x1E));
      *(_DWORD *)(v12 + 4 * (v17 >> 4)) &= ~(3 << (2 * v17 & 0x1E));
    }
    Scaleform::Heap::BitSet2::MarkBusy((unsigned int *)(v10 + 64), (signed __int64)&v7[-v11] >> v8, v5 >> v8, 0i64);
    *v18 = (Scaleform::Heap::HeapSegment *)v10;
    result = v7;
  }
  return result;
}

// File Line: 89
// RVA: 0x955A30
char *__fastcall Scaleform::HeapPT::AllocBitSet2::Alloc(Scaleform::HeapPT::AllocBitSet2 *this, unsigned __int64 bytes, unsigned __int64 alignSize, Scaleform::Heap::HeapSegment **allocSeg)
{
  unsigned __int64 v4; // r14
  unsigned __int64 v5; // rbx
  unsigned __int64 v6; // r15
  char *result; // rax
  char *v8; // rsi
  __int64 v9; // r13
  signed __int64 v10; // rdi
  unsigned __int64 v11; // rcx
  unsigned __int64 v12; // rbx
  unsigned __int64 v13; // rbx
  unsigned __int64 v14; // rbp
  unsigned __int64 v15; // rax
  unsigned __int64 v16; // rsi
  signed __int64 v17; // rdx
  signed int v18; // eax
  signed __int64 v19; // rcx
  unsigned int *v20; // rsi
  char *v21; // rdx
  unsigned __int64 v22; // rbx
  unsigned __int64 v23; // rax
  unsigned int *v24; // rdx
  unsigned __int64 v25; // rcx
  unsigned __int8 v26; // al
  __int64 v27; // [rsp+70h] [rbp+8h]
  Scaleform::HeapPT::FreeBin *v28; // [rsp+78h] [rbp+10h]
  unsigned __int64 val; // [rsp+80h] [rbp+18h]
  Scaleform::Heap::HeapSegment **v30; // [rsp+88h] [rbp+20h]

  v30 = allocSeg;
  val = alignSize;
  v4 = this->MinAlignShift;
  v5 = alignSize - 1;
  v6 = bytes;
  v28 = &this->Bin;
  result = Scaleform::HeapPT::FreeBin::PullBest(
             &this->Bin,
             bytes >> this->MinAlignShift,
             this->MinAlignShift,
             alignSize - 1);
  v8 = result;
  if ( result )
  {
    v9 = *((_QWORD *)result + 2);
    v10 = ~v5 & (unsigned __int64)&result[v5];
    v27 = *(_QWORD *)(v9 + 56);
    v11 = v10 - (_QWORD)result;
    if ( (char *)v10 != result )
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
    if ( v12 >= 0x41 )
      v12 = *((_QWORD *)result + 4);
    v13 = (unsigned __int64)&result[(v12 << v4) - v10 - v6];
    if ( (char *)v10 == result )
    {
      v20 = (unsigned int *)(v9 + 64);
    }
    else
    {
      v14 = (unsigned __int64)(v10 - (_QWORD)result) >> v4;
      v15 = v14 << v4;
      if ( v14 >= 0x41 )
      {
        *(_DWORD *)&v8[v15 - 4] = 65;
        *((_DWORD *)v8 + 6) = 65;
        *(_QWORD *)&v8[v15 - 16] = v14;
        *((_QWORD *)v8 + 4) = v14;
      }
      else
      {
        *(_DWORD *)&v8[v15 - 4] = v14;
        *((_DWORD *)v8 + 6) = v14;
      }
      *((_QWORD *)v8 + 2) = v9;
      Scaleform::HeapPT::FreeBin::Push(v28, v8);
      v16 = (signed __int64)&v8[-v27] >> v4;
      v17 = 4 * (v16 >> 4);
      v18 = 3 << (2 * v16 & 0x1E);
      v19 = v16 - 1;
      v20 = (unsigned int *)(v9 + 64);
      *(_DWORD *)(v17 + v9 + 64) &= ~v18;
      *(_DWORD *)(v9 + 64 + 4 * ((v14 + v19) >> 4)) &= ~(3 << (2 * (v14 + v19) & 0x1E));
    }
    if ( v13 < 0x20 )
    {
      v6 += v13;
    }
    else
    {
      v21 = (char *)(v10 + v6);
      v22 = v13 >> v4;
      v23 = v22 << v4;
      if ( v22 >= 0x41 )
      {
        *(_DWORD *)&v21[v23 - 4] = 65;
        *((_DWORD *)v21 + 6) = 65;
        *(_QWORD *)&v21[v23 - 16] = v22;
        *((_QWORD *)v21 + 4) = v22;
      }
      else
      {
        *(_DWORD *)&v21[v23 - 4] = v22;
        *((_DWORD *)v21 + 6) = v22;
      }
      *((_QWORD *)v21 + 2) = v9;
      Scaleform::HeapPT::FreeBin::Push(v28, v21);
      v24 = &v20[(unsigned __int64)((signed __int64)(v6 + v10 - v27) >> v4) >> 4];
      v25 = ((signed __int64)(v6 + v10 - v27) >> v4) + v22 - 1;
      *v24 &= ~(3 << (2 * (unsigned __int64)((signed __int64)(v6 + v10 - v27) >> v4) & 0x1E));
      v20[v25 >> 4] &= ~(3 << (2 * v25 & 0x1E));
    }
    v26 = Scaleform::Alg::UpperBit(val);
    Scaleform::Heap::BitSet2::MarkBusy(v20, (v10 - v27) >> v4, v6 >> v4, v26 - v4);
    *v30 = (Scaleform::Heap::HeapSegment *)v9;
    result = (char *)v10;
  }
  return result;
}

// File Line: 146
// RVA: 0x97D540
void __fastcall Scaleform::HeapPT::AllocBitSet2::Free(Scaleform::HeapPT::AllocBitSet2 *this, Scaleform::Heap::HeapSegment *seg, void *ptr)
{
  unsigned __int64 v3; // r12
  Scaleform::HeapPT::AllocBitSet2 *v4; // rsi
  char *v5; // rbx
  Scaleform::Heap::HeapSegment *v6; // r14
  Scaleform::Heap::HeapSegment *v7; // r15
  unsigned __int64 v8; // rbp
  _DWORD *v9; // rdi
  unsigned __int64 v10; // r11
  unsigned __int64 v11; // r10
  bool v12; // bl
  bool v13; // r9
  bool right; // dl
  Scaleform::HeapPT::FreeBin *v15; // rcx

  v3 = this->MinAlignShift;
  v4 = this;
  v5 = &seg->pData[seg->DataSize];
  v6 = seg + 1;
  v7 = seg;
  v8 = (signed __int64)((signed __int64)ptr - (unsigned __int64)seg->pData) >> this->MinAlignShift;
  v9 = ptr;
  v10 = Scaleform::Heap::BitSet2::GetBlockSize((const unsigned int *)&seg[1], v8);
  *((_DWORD *)&v6->pPrev + (v8 >> 4)) &= ~(3 << (2 * v8 & 0x1E));
  *((_DWORD *)&v6->pPrev + ((v10 + v8 - 1) >> 4)) &= ~(3 << (2 * (v10 + v8 - 1) & 0x1E));
  v11 = v10 << v3;
  v12 = (char *)v9 + (v10 << v3) < v5;
  v13 = v8 && !((*((_DWORD *)&v6->pPrev + ((v8 - 1) >> 4)) >> (2 * (v8 - 1) & 0x1E)) & 3);
  right = v12 && !((*((_DWORD *)&v6->pPrev + ((v10 + v8) >> 4)) >> (2 * (v10 + v8) & 0x1E)) & 3);
  if ( v10 >= 0x41 )
  {
    *(_DWORD *)((char *)v9 + v11 - 4) = 65;
    v9[6] = 65;
    *(_QWORD *)((char *)v9 + v11 - 16) = v10;
    *((_QWORD *)v9 + 4) = v10;
  }
  else
  {
    *(_DWORD *)((char *)v9 + v11 - 4) = v10;
    v9[6] = v10;
  }
  *((_QWORD *)v9 + 2) = v7;
  v15 = &v4->Bin;
  if ( v13 || right )
    Scaleform::HeapPT::FreeBin::Merge(v15, (char *)v9, v3, v13, right);
  else
    Scaleform::HeapPT::FreeBin::Push(v15, (char *)v9);
}

// File Line: 178
// RVA: 0x9A6700
char *__fastcall Scaleform::HeapPT::AllocBitSet2::ReallocInPlace(Scaleform::HeapPT::AllocBitSet2 *this, Scaleform::Heap::HeapSegment *seg, void *oldPtr, unsigned __int64 newSize, unsigned __int64 *oldSize)
{
  unsigned __int64 v5; // rbp
  char *v6; // r14
  unsigned int *v7; // r15
  unsigned __int64 v8; // rdi
  unsigned __int64 v9; // r13
  unsigned __int64 v10; // r12
  unsigned __int64 v11; // rsi
  unsigned int v12; // eax
  unsigned __int64 v13; // rsi
  unsigned __int64 v14; // rdi
  char *v15; // r8
  unsigned __int64 v16; // rbx
  unsigned __int64 v17; // rbx
  unsigned __int64 v18; // rbx
  char *v19; // rsi
  unsigned __int64 v20; // rbx
  unsigned __int64 v21; // rax
  unsigned __int64 v22; // rsi
  unsigned int *v23; // rdx
  char *v25; // r9
  unsigned __int64 v26; // r8
  unsigned __int64 v27; // r10
  unsigned __int64 v28; // r8
  unsigned __int64 v29; // rbx
  char *v30; // rsi
  unsigned __int64 v31; // rbx
  unsigned __int64 v32; // rax
  unsigned __int64 v33; // rsi
  unsigned int *v34; // rdx
  char *v35; // [rsp+20h] [rbp-58h]
  Scaleform::HeapPT::AllocBitSet2 *v36; // [rsp+80h] [rbp+8h]
  Scaleform::Heap::HeapSegment *v37; // [rsp+88h] [rbp+10h]
  unsigned __int64 v38; // [rsp+90h] [rbp+18h]
  unsigned __int64 alignShift; // [rsp+98h] [rbp+20h]

  v37 = seg;
  v36 = this;
  v5 = this->MinAlignShift;
  v6 = (char *)oldPtr;
  v7 = (unsigned int *)&seg[1];
  v8 = newSize;
  v35 = seg->pData;
  v9 = (unsigned __int64)&v35[seg->DataSize];
  v10 = ((_BYTE *)oldPtr - v35) >> this->MinAlignShift;
  v11 = Scaleform::Heap::BitSet2::GetBlockSize((const unsigned int *)&seg[1], v10);
  v38 = v11;
  v12 = Scaleform::Heap::BitSet2::GetAlignShift(v7, v10, v11);
  alignShift = v12;
  v13 = v11 << v5;
  *oldSize = v13;
  v14 = ~((1i64 << ((unsigned __int8)v12 + (unsigned __int8)v5)) - 1) & ((1i64 << ((unsigned __int8)v12
                                                                                 + (unsigned __int8)v5))
                                                                       - 1
                                                                       + v8);
  if ( v14 <= v13 )
  {
    if ( v14 < v13 )
    {
      v25 = &v6[v13];
      v26 = 0i64;
      v27 = v13 - v14;
      if ( (unsigned __int64)&v6[v13] < v9 && !((v7[(v10 + v38) >> 4] >> (2 * (v10 + v38) & 0x1E)) & 3) )
      {
        v28 = *((unsigned int *)v25 + 6);
        if ( v28 >= 0x41 )
          v28 = *((_QWORD *)v25 + 4);
        v26 = v28 << v5;
      }
      v29 = v26 + v27;
      if ( v26 + v27 >= 0x20 )
      {
        if ( v26 )
          Scaleform::HeapPT::FreeBin::Pull(&v36->Bin, &v6[v13]);
        v30 = &v6[v14];
        v31 = v29 >> v5;
        v32 = v31 << v5;
        if ( v31 >= 0x41 )
        {
          *(_DWORD *)&v30[v32 - 4] = 65;
          *((_DWORD *)v30 + 6) = 65;
          *(_QWORD *)&v30[v32 - 16] = v31;
          *((_QWORD *)v30 + 4) = v31;
        }
        else
        {
          *(_DWORD *)&v30[v32 - 4] = v31;
          *((_DWORD *)v30 + 6) = v31;
        }
        *((_QWORD *)v30 + 2) = v37;
        Scaleform::HeapPT::FreeBin::Push(&v36->Bin, &v6[v14]);
        Scaleform::Heap::BitSet2::MarkBusy(v7, v10, v14 >> v5, alignShift);
        v33 = (v30 - v35) >> v5;
        v7[v33 >> 4] &= ~(3 << (2 * v33 & 0x1E));
        v34 = &v7[(v31 + v33 - 1) >> 4];
        *v34 &= ~(3 << (2 * (v31 + v33 - 1) & 0x1E));
      }
    }
  }
  else
  {
    v15 = &v6[v13];
    if ( (unsigned __int64)&v6[v13] >= v9 || (v7[(v10 + v38) >> 4] >> (2 * (v10 + v38) & 0x1E)) & 3 )
      return 0i64;
    v16 = *((unsigned int *)v15 + 6);
    if ( v16 >= 0x41 )
      v16 = *((_QWORD *)v15 + 4);
    v17 = v16 << v5;
    if ( v14 > v17 + v13 )
      return 0i64;
    Scaleform::HeapPT::FreeBin::Pull(&v36->Bin, &v6[v13]);
    v18 = v13 + v17 - v14;
    if ( v18 < 0x20 )
    {
      v14 += v18;
    }
    else
    {
      v19 = &v6[v14];
      v20 = v18 >> v5;
      v21 = v20 << v5;
      if ( v20 >= 0x41 )
      {
        *(_DWORD *)&v19[v21 - 4] = 65;
        *((_DWORD *)v19 + 6) = 65;
        *(_QWORD *)&v19[v21 - 16] = v20;
        *((_QWORD *)v19 + 4) = v20;
      }
      else
      {
        *(_DWORD *)&v19[v21 - 4] = v20;
        *((_DWORD *)v19 + 6) = v20;
      }
      *((_QWORD *)v19 + 2) = v37;
      Scaleform::HeapPT::FreeBin::Push(&v36->Bin, &v6[v14]);
      v22 = (v19 - v35) >> v5;
      v7[v22 >> 4] &= ~(3 << (2 * v22 & 0x1E));
      v23 = &v7[(v20 + v22 - 1) >> 4];
      *v23 &= ~(3 << (2 * (v20 + v22 - 1) & 0x1E));
    }
    Scaleform::Heap::BitSet2::MarkBusy(v7, v10, v14 >> v5, alignShift);
  }
  return v6;
}

