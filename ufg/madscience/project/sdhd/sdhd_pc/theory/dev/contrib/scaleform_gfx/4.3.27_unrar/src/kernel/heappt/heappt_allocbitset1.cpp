// File Line: 30
// RVA: 0x993E00
void __fastcall Scaleform::HeapPT::AllocBitSet1::InitSegment(
        Scaleform::HeapPT::AllocBitSet1 *this,
        Scaleform::Heap::HeapSegment *seg)
{
  unsigned __int64 DataSize; // r10
  unsigned __int64 MinAlignShift; // rcx
  unsigned __int64 v5; // r10
  char *pData; // rdx
  unsigned __int64 v8; // rax

  DataSize = seg->DataSize;
  MinAlignShift = this->MinAlignShift;
  LODWORD(seg[1].pPrev) &= ~1u;
  v5 = DataSize >> MinAlignShift;
  *((_DWORD *)&seg[1].pPrev + ((v5 - 1) >> 5)) &= ~(1 << ((v5 - 1) & 0x1F));
  pData = seg->pData;
  v8 = v5 << this->MinAlignShift;
  if ( v5 >= 0x41 )
  {
    *(_DWORD *)&pData[v8 - 4] = 65;
    *((_DWORD *)pData + 6) = 65;
    *(_QWORD *)&pData[v8 - 16] = v5;
    *((_QWORD *)pData + 4) = v5;
  }
  else
  {
    *(_DWORD *)&pData[v8 - 4] = v5;
    *((_DWORD *)pData + 6) = v5;
  }
  *((_QWORD *)pData + 2) = seg;
  Scaleform::HeapPT::FreeBin::Push(&this->Bin, pData);
}

// File Line: 44
// RVA: 0x9558C0
char *__fastcall Scaleform::HeapPT::AllocBitSet1::Alloc(
        Scaleform::HeapPT::AllocBitSet1 *this,
        unsigned __int64 bytes,
        Scaleform::Heap::HeapSegment **allocSeg)
{
  unsigned __int64 MinAlignShift; // r14
  unsigned __int64 v5; // rsi
  unsigned __int64 v7; // rbp
  char *result; // rax
  char *v9; // rdi
  unsigned __int64 v10; // rbx
  Scaleform::Heap::HeapSegment *v11; // r15
  unsigned __int64 v12; // rbx
  unsigned __int64 v13; // rax
  char *v14; // rdx
  char *v15; // r8
  unsigned __int64 v16; // rcx
  unsigned __int64 v17; // r9

  MinAlignShift = this->MinAlignShift;
  v5 = bytes;
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
    v13 = v12 << MinAlignShift;
    if ( v12 << MinAlignShift < 0x20 )
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
      Scaleform::HeapPT::FreeBin::Push(&this->Bin, v14);
      v15 = (char *)v11 + 4 * ((v5 + v9 - v11->pData) >> MinAlignShift >> 5);
      v16 = v12 + ((v5 + v9 - v11->pData) >> MinAlignShift) - 1;
      *((_DWORD *)v15 + 16) &= ~(1 << (((v5 + v9 - v11->pData) >> MinAlignShift) & 0x1F));
      *((_DWORD *)&v11[1].pPrev + (v16 >> 5)) &= ~(1 << (v16 & 0x1F));
    }
    v17 = (v9 - v11->pData) >> MinAlignShift;
    *((_DWORD *)&v11[1].pPrev + (v17 >> 5)) |= 1 << (v17 & 0x1F);
    *((_DWORD *)&v11[1].pPrev + (((v5 >> MinAlignShift) + v17 - 1) >> 5)) |= 1 << (((v5 >> MinAlignShift) + v17 - 1) & 0x1F);
    *allocSeg = v11;
    return v9;
  }
  return result;
}

// File Line: 80
// RVA: 0x97D3E0
void __fastcall Scaleform::HeapPT::AllocBitSet1::Free(
        Scaleform::HeapPT::AllocBitSet1 *this,
        Scaleform::Heap::HeapSegment *seg,
        char *ptr,
        unsigned __int64 bytes)
{
  unsigned __int64 MinAlignShift; // rcx
  char *v6; // r11
  unsigned __int64 v7; // r10
  unsigned __int64 v10; // rbp
  unsigned __int64 v11; // r8
  bool v12; // r11
  int v13; // eax
  bool v14; // r9
  int v15; // eax
  bool right; // dl
  unsigned __int64 v17; // rax
  Scaleform::HeapPT::FreeBin *p_Bin; // rcx

  MinAlignShift = this->MinAlignShift;
  v6 = &seg->pData[seg->DataSize];
  v7 = bytes >> MinAlignShift;
  v10 = (ptr - seg->pData) >> MinAlignShift;
  *((_DWORD *)&seg[1].pPrev + (v10 >> 5)) &= ~(1 << (v10 & 0x1F));
  v11 = (bytes >> MinAlignShift) + v10;
  *((_DWORD *)&seg[1].pPrev + ((v11 - 1) >> 5)) &= ~(1 << (((bytes >> MinAlignShift) + v10 - 1) & 0x1F));
  v12 = &ptr[bytes] < v6;
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
  v17 = v7 << this->MinAlignShift;
  if ( v7 >= 0x41 )
  {
    *(_DWORD *)&ptr[v17 - 4] = 65;
    *((_DWORD *)ptr + 6) = 65;
    *(_QWORD *)&ptr[v17 - 16] = v7;
    *((_QWORD *)ptr + 4) = v7;
  }
  else
  {
    *(_DWORD *)&ptr[v17 - 4] = v7;
    *((_DWORD *)ptr + 6) = v7;
  }
  *((_QWORD *)ptr + 2) = seg;
  p_Bin = &this->Bin;
  if ( v14 || right )
    Scaleform::HeapPT::FreeBin::Merge(p_Bin, ptr, this->MinAlignShift, v14, right);
  else
    Scaleform::HeapPT::FreeBin::Push(p_Bin, ptr);
}

