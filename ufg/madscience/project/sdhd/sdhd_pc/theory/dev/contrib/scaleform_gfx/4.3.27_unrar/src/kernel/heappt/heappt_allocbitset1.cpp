// File Line: 30
// RVA: 0x993E00
void __fastcall Scaleform::HeapPT::AllocBitSet1::InitSegment(Scaleform::HeapPT::AllocBitSet1 *this, Scaleform::Heap::HeapSegment *seg)
{
  unsigned __int64 v2; // r10
  Scaleform::HeapPT::AllocBitSet1 *v3; // rbx
  unsigned __int64 v4; // rcx
  unsigned __int64 v5; // r10
  Scaleform::Heap::HeapSegment *v6; // r11
  char *v7; // rdx
  unsigned __int64 v8; // rax

  v2 = seg->DataSize;
  v3 = this;
  v4 = this->MinAlignShift;
  LODWORD(seg[1].pPrev) &= 0xFFFFFFFE;
  v5 = v2 >> v4;
  v6 = seg;
  *((_DWORD *)&seg[1].pPrev + ((v5 - 1) >> 5)) &= ~(1 << ((v5 - 1) & 0x1F));
  v7 = seg->pData;
  v8 = v5 << v3->MinAlignShift;
  if ( v5 >= 0x41 )
  {
    *(_DWORD *)&v7[v8 - 4] = 65;
    *((_DWORD *)v7 + 6) = 65;
    *(_QWORD *)&v7[v8 - 16] = v5;
    *((_QWORD *)v7 + 4) = v5;
  }
  else
  {
    *(_DWORD *)&v7[v8 - 4] = v5;
    *((_DWORD *)v7 + 6) = v5;
  }
  *((_QWORD *)v7 + 2) = v6;
  Scaleform::HeapPT::FreeBin::Push(&v3->Bin, v7);
}

// File Line: 44
// RVA: 0x9558C0
char *__fastcall Scaleform::HeapPT::AllocBitSet1::Alloc(Scaleform::HeapPT::AllocBitSet1 *this, unsigned __int64 bytes, Scaleform::Heap::HeapSegment **allocSeg)
{
  unsigned __int64 v3; // r14
  Scaleform::HeapPT::AllocBitSet1 *v4; // r12
  unsigned __int64 v5; // rsi
  Scaleform::Heap::HeapSegment **v6; // r13
  unsigned __int64 v7; // rbp
  char *result; // rax
  char *v9; // rdi
  unsigned __int64 v10; // rbx
  Scaleform::Heap::HeapSegment *v11; // r15
  unsigned __int64 v12; // rbx
  unsigned __int64 v13; // rax
  char *v14; // rdx
  signed __int64 v15; // r8
  unsigned __int64 v16; // rcx
  unsigned __int64 v17; // r9
  signed __int64 v18; // r8

  v3 = this->MinAlignShift;
  v4 = this;
  v5 = bytes;
  v6 = allocSeg;
  v7 = bytes >> this->MinAlignShift;
  result = Scaleform::HeapPT::FreeBin::PullBest(&this->Bin, v7);
  v9 = result;
  if ( result )
  {
    v10 = *((unsigned int *)result + 6);
    v11 = (Scaleform::Heap::HeapSegment *)*((_QWORD *)result + 2);
    if ( v10 >= 0x41 )
      v10 = *((_QWORD *)result + 4);
    v12 = v10 - v7;
    v13 = v12 << v3;
    if ( v12 << v3 < 0x20 )
    {
      v5 += v13;
    }
    else
    {
      v14 = &v9[v5];
      if ( v12 >= 0x41 )
      {
        *(_DWORD *)&v14[v13 - 4] = 65;
        *((_DWORD *)v14 + 6) = 65;
        *(_QWORD *)&v14[v13 - 16] = v12;
        *((_QWORD *)v14 + 4) = v12;
      }
      else
      {
        *(_DWORD *)&v14[v13 - 4] = v12;
        *((_DWORD *)v14 + 6) = v12;
      }
      *((_QWORD *)v14 + 2) = v11;
      Scaleform::HeapPT::FreeBin::Push(&v4->Bin, v14);
      v15 = (signed __int64)v11 + 4 * ((v5 + v9 - v11->pData) >> v3 >> 5);
      v16 = v12 + ((v5 + v9 - v11->pData) >> v3) - 1;
      *(_DWORD *)(v15 + 64) &= ~(1 << (((v5 + v9 - v11->pData) >> v3) & 0x1F));
      *((_DWORD *)&v11[1].pPrev + (v16 >> 5)) &= ~(1 << (v16 & 0x1F));
    }
    v17 = (v9 - v11->pData) >> v3;
    v18 = (signed __int64)v11 + 4 * (v17 >> 5);
    *(_DWORD *)(v18 + 64) |= 1 << (v17 & 0x1F);
    *((_DWORD *)&v11[1].pPrev + (((v5 >> v3) + v17 - 1) >> 5)) |= 1 << (((v5 >> v3) + v17 - 1) & 0x1F);
    *v6 = v11;
    result = v9;
  }
  return result;
}

// File Line: 80
// RVA: 0x97D3E0
void __fastcall Scaleform::HeapPT::AllocBitSet1::Free(Scaleform::HeapPT::AllocBitSet1 *this, Scaleform::Heap::HeapSegment *seg, void *ptr, unsigned __int64 bytes)
{
  Scaleform::HeapPT::AllocBitSet1 *v4; // rsi
  unsigned __int64 v5; // rcx
  char *v6; // r11
  unsigned __int64 v7; // r10
  Scaleform::Heap::HeapSegment *v8; // r14
  _DWORD *v9; // rdi
  unsigned __int64 v10; // rbp
  unsigned __int64 v11; // r8
  bool v12; // r11
  int v13; // eax
  bool v14; // r9
  int v15; // eax
  bool right; // dl
  unsigned __int64 v17; // rax
  Scaleform::HeapPT::FreeBin *v18; // rcx

  v4 = this;
  v5 = this->MinAlignShift;
  v6 = &seg->pData[seg->DataSize];
  v7 = bytes >> v5;
  v8 = seg;
  v9 = ptr;
  v10 = (signed __int64)((signed __int64)ptr - (unsigned __int64)seg->pData) >> v5;
  *((_DWORD *)&seg[1].pPrev + (v10 >> 5)) &= ~(1 << (v10 & 0x1F));
  v11 = (bytes >> v5) + v10;
  *((_DWORD *)&seg->pPrev + ((v11 - 1) >> 5) + 16) &= ~(1 << (((bytes >> v5) + v10 - 1) & 0x1F));
  v12 = (char *)v9 + bytes < v6;
  v14 = 0;
  if ( v10 )
  {
    v13 = *((_DWORD *)&seg[1].pPrev + ((v10 - 1) >> 5));
    if ( !_bittest(&v13, ((_BYTE)v10 - 1) & 0x1F) )
      v14 = 1;
  }
  right = 0;
  if ( v12 )
  {
    v15 = *((_DWORD *)&seg[1].pPrev + (v11 >> 5));
    if ( !_bittest(&v15, v11 & 0x1F) )
      right = 1;
  }
  v17 = v7 << v4->MinAlignShift;
  if ( v7 >= 0x41 )
  {
    *(_DWORD *)((char *)v9 + v17 - 4) = 65;
    v9[6] = 65;
    *(_QWORD *)((char *)v9 + v17 - 16) = v7;
    *((_QWORD *)v9 + 4) = v7;
  }
  else
  {
    *(_DWORD *)((char *)v9 + v17 - 4) = v7;
    v9[6] = v7;
  }
  *((_QWORD *)v9 + 2) = v8;
  v18 = &v4->Bin;
  if ( v14 || right )
    Scaleform::HeapPT::FreeBin::Merge(v18, (char *)v9, v4->MinAlignShift, v14, right);
  else
    Scaleform::HeapPT::FreeBin::Push(v18, (char *)v9);
}

