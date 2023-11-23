// File Line: 34
// RVA: 0x993660
void __fastcall Scaleform::HeapMH::AllocBitSet2MH::InitPage(
        Scaleform::HeapMH::AllocBitSet2MH *this,
        Scaleform::HeapMH::PageMH *page,
        unsigned int index)
{
  char *Start; // rax
  signed __int64 v4; // rbx
  unsigned __int64 v6; // rsi
  unsigned __int64 v7; // r13
  unsigned __int64 v8; // rbp
  unsigned __int64 v9; // r14
  unsigned __int64 v10; // rdi
  void *v11; // r15
  unsigned __int64 v12; // r8
  signed __int64 v13; // r9
  unsigned __int64 v14; // r12
  __int64 v15; // r11
  __int64 v16; // r8
  char *v17; // rcx
  unsigned __int64 v18; // rax
  __int64 v19; // r10
  __int64 v20; // rdx
  unsigned __int64 v21; // rax
  Scaleform::HeapMH::AllocBitSet2MH *v22; // r14
  unsigned __int64 v23; // rax
  __int64 v24; // rdi
  unsigned __int64 v25; // rcx
  _QWORD *v26; // rax
  unsigned __int64 v27; // rbx
  __int64 v28; // r12
  unsigned __int64 *v29; // rcx
  unsigned __int64 v30; // rax
  __int64 v31; // r8
  __int64 v32; // rdx
  unsigned __int64 v33; // rax
  unsigned __int64 v34; // rax
  unsigned __int64 v35; // rcx
  _QWORD *v36; // rax
  unsigned __int64 v37; // r9

  Start = page->Start;
  v4 = 0i64;
  v6 = (unsigned __int64)(Start + 4095) & 0xFFFFFFFFFFFFF000ui64;
  v7 = (unsigned __int64)(Start + 15) & 0xFFFFFFFFFFFFFFF0ui64;
  v8 = (unsigned __int64)(Start + 4096) & 0xFFFFFFFFFFFFFFF0ui64;
  v9 = 0i64;
  if ( v6 - v7 > 0x10 )
    v9 = v6 - 16;
  v10 = 0i64;
  v11 = (void *)(v6 - 80);
  if ( v8 - v6 > 0x10 )
    v10 = (unsigned __int64)(Start + 4095) & 0xFFFFFFFFFFFFF000ui64;
  if ( v6 - v7 <= v8 - v6 )
    v11 = (void *)(v6 + 16);
  memset(v11, 85, 0x40ui64);
  if ( v9 )
  {
    *(_DWORD *)v9 = 24512;
    *(_DWORD *)(v9 + 4) = index;
    *(_QWORD *)(v9 + 8) = 0i64;
  }
  if ( v10 )
  {
    *(_DWORD *)v10 = 24512;
    *(_DWORD *)(v10 + 4) = index;
    *(_QWORD *)(v10 + 8) = 0i64;
  }
  v12 = 0i64;
  v13 = 0i64;
  v14 = 0i64;
  if ( v9 )
  {
    v4 = v7;
    v12 = v9;
  }
  if ( v10 )
  {
    v13 = v10 + 16;
    v14 = v8;
  }
  if ( (unsigned __int64)v11 >= v6 )
    v13 += 64i64;
  else
    v12 -= 64i64;
  v15 = 63i64;
  if ( v4 )
  {
    v16 = v12 - v4;
    v17 = (char *)(v4 + 8 * ((unsigned __int64)v16 >> 3));
    *(_QWORD *)v4 ^= ((unsigned __int8)((unsigned __int64)v16 >> 4) ^ (unsigned __int8)*(_QWORD *)v4) & 0xF;
    *((_QWORD *)v17 - 2) = *(_QWORD *)v4;
    v18 = ((unsigned __int64)v16 >> 8) | *(_QWORD *)(v4 + 8) & 0xFFFFFFFFFFFFFFF0ui64;
    *(_QWORD *)(v4 + 8) = v18;
    *((_QWORD *)v17 - 1) = v18;
    v19 = *(_QWORD *)(v4 + 8) & 0xFi64;
    v20 = *(_QWORD *)v4 & 0xFi64;
    v21 = v20 | (16i64 * (*(_DWORD *)(v4 + 8) & 0xF));
    if ( v21 > 2 )
      *(_QWORD *)(v4 + 16) = page;
    v22 = this;
    v23 = v21 - 1;
    v24 = 63i64;
    if ( v23 < 0x3F )
      v24 = v23;
    v25 = (unsigned __int64)this->Bin.Roots[v24];
    if ( v25 )
    {
      *(_QWORD *)v4 = v25 | v20;
      *(_QWORD *)(v4 + 8) = v19 | *(_QWORD *)(v25 + 8) & 0xFFFFFFFFFFFFFFF0ui64;
      v26 = (_QWORD *)(*(_QWORD *)(v25 + 8) & 0xFFFFFFFFFFFFFFF0ui64);
      *v26 &= 0xFui64;
      *v26 |= v4;
      *(_QWORD *)(v25 + 8) &= 0xFui64;
      *(_QWORD *)(v25 + 8) |= v4;
    }
    else
    {
      *(_QWORD *)(v4 + 8) = v4 | v19;
      *(_QWORD *)v4 = v4 | v20;
    }
    this->Bin.Roots[v24] = (Scaleform::HeapMH::BinNodeMH *)v4;
    v27 = (__int64)(v4 - v7) >> 4;
    this->Bin.Mask |= 1i64 << v24;
    *((_DWORD *)v11 + (v27 >> 4)) &= ~(3 << ((2 * v27) & 0x1E));
    *((_DWORD *)v11 + ((v27 + (v16 >> 4) - 1) >> 4)) &= ~(3 << ((2 * (v27 + (v16 >> 4) - 1)) & 0x1E));
  }
  else
  {
    v22 = this;
  }
  if ( v13 )
  {
    v28 = v14 - v13;
    v29 = (unsigned __int64 *)(v13 + 8 * ((unsigned __int64)v28 >> 3));
    *(_QWORD *)v13 ^= ((unsigned __int8)((unsigned __int64)v28 >> 4) ^ (unsigned __int8)*(_QWORD *)v13) & 0xF;
    *(v29 - 2) = *(_QWORD *)v13;
    v30 = ((unsigned __int64)v28 >> 8) | *(_QWORD *)(v13 + 8) & 0xFFFFFFFFFFFFFFF0ui64;
    *(_QWORD *)(v13 + 8) = v30;
    *(v29 - 1) = v30;
    v31 = *(_QWORD *)(v13 + 8) & 0xFi64;
    v32 = *(_QWORD *)v13 & 0xFi64;
    v33 = v32 | (16i64 * (*(_DWORD *)(v13 + 8) & 0xF));
    if ( v33 > 2 )
      *(_QWORD *)(v13 + 16) = page;
    v34 = v33 - 1;
    if ( v34 < 0x3F )
      v15 = v34;
    v35 = (unsigned __int64)v22->Bin.Roots[v15];
    if ( v35 )
    {
      *(_QWORD *)v13 = v32 | v35;
      *(_QWORD *)(v13 + 8) = v31 | *(_QWORD *)(v35 + 8) & 0xFFFFFFFFFFFFFFF0ui64;
      v36 = (_QWORD *)(*(_QWORD *)(v35 + 8) & 0xFFFFFFFFFFFFFFF0ui64);
      *v36 &= 0xFui64;
      *v36 |= v13;
      *(_QWORD *)(v35 + 8) &= 0xFui64;
      *(_QWORD *)(v35 + 8) |= v13;
    }
    else
    {
      *(_QWORD *)(v13 + 8) = v13 | v31;
      *(_QWORD *)v13 = v13 | v32;
    }
    v22->Bin.Roots[v15] = (Scaleform::HeapMH::BinNodeMH *)v13;
    v37 = (__int64)(v13 - v7) >> 4;
    v22->Bin.Mask |= 1i64 << v15;
    *((_DWORD *)v11 + (v37 >> 4)) &= ~(3 << ((2 * v37) & 0x1E));
    *((_DWORD *)v11 + (((v28 >> 4) + v37 - 1) >> 4)) &= ~(3 << ((2 * ((v28 >> 4) + v37 - 1)) & 0x1E));
  }
}

// File Line: 95
// RVA: 0x9A8160
void __fastcall Scaleform::HeapMH::AllocBitSet2MH::ReleasePage(Scaleform::HeapMH::AllocBitSet2MH *this, char *start)
{
  unsigned __int64 v3; // rbx
  unsigned __int64 v4; // r8
  char *v5; // rcx
  unsigned __int64 v6; // rdi
  unsigned __int64 v7; // rax
  unsigned __int64 v8; // rsi
  char *v9; // rdx

  v3 = (unsigned __int64)(start + 4095) & 0xFFFFFFFFFFFFF000ui64;
  v4 = 0i64;
  v5 = (char *)((unsigned __int64)(start + 15) & 0xFFFFFFFFFFFFFFF0ui64);
  v6 = 0i64;
  if ( v3 - (unsigned __int64)v5 > 0x10 )
    v4 = v3 - 16;
  v7 = ((unsigned __int64)(start + 4096) & 0xFFFFFFFFFFFFFFF0ui64) - v3;
  v8 = v3 - 80;
  if ( v7 > 0x10 )
    v6 = v3;
  if ( v3 - (unsigned __int64)v5 <= v7 )
    v8 = v3 + 16;
  if ( v4 )
    Scaleform::HeapMH::ListBinMH::Pull(&this->Bin, v5);
  if ( v6 )
  {
    v9 = (char *)(v6 + 16);
    if ( v8 > v3 )
      v9 = (char *)(v6 + 80);
    Scaleform::HeapMH::ListBinMH::Pull(&this->Bin, v9);
  }
}

// File Line: 122
// RVA: 0x956080
Scaleform::HeapMH::BinNodeMH *__fastcall Scaleform::HeapMH::AllocBitSet2MH::Alloc(
        Scaleform::HeapMH::AllocBitSet2MH *this,
        unsigned __int64 bytes,
        Scaleform::HeapMH::MagicHeadersInfo *headers)
{
  unsigned __int64 v5; // r15
  Scaleform::HeapMH::BinNodeMH *result; // rax
  Scaleform::HeapMH::BinNodeMH *v8; // rbx
  Scaleform::HeapMH::PageMH *Page; // rbp
  unsigned __int64 v10; // rdi
  unsigned __int64 v11; // rsi
  __int64 v12; // r8
  __int64 v13; // rcx
  __int64 v14; // r9
  unsigned __int64 v15; // rdx
  _QWORD *v16; // rax
  unsigned int *BitSet; // r8
  unsigned int *v18; // rdx
  unsigned __int64 v19; // rcx

  v5 = bytes >> 4;
  result = Scaleform::HeapMH::ListBinMH::PullBest(&this->Bin, bytes >> 4);
  v8 = result;
  if ( result )
  {
    if ( (result->Prev & 0xF | (16 * (unsigned __int64)(result->Next & 0xF))) <= 2 || (Page = result->Page) == 0i64 )
      Page = Scaleform::HeapMH::RootMH::ResolveAddress(Scaleform::HeapMH::GlobalRootMH, (unsigned __int64)result);
    Scaleform::HeapMH::GetMagicHeaders((unsigned __int64)Page->Start, headers);
    headers->Page = Page;
    v10 = 16 * (v8->Prev & 0xF | (16i64 * (v8->Next & 0xF))) - bytes;
    if ( v10 )
    {
      v11 = (unsigned __int64)v8 + bytes;
      Scaleform::HeapMH::BinNodeMH::MakeNode((char *)v8 + bytes, v10, Page);
      v12 = *(unsigned __int64 *)((_BYTE *)&v8->Next + bytes) & 0xF;
      v13 = *(unsigned __int64 *)((_BYTE *)&v8->Prev + bytes) & 0xF;
      v14 = 63i64;
      if ( (v13 | (16 * (unsigned __int64)(*(_DWORD *)((_BYTE *)&v8->Next + bytes) & 0xF))) - 1 < 0x3F )
        v14 = (v13 | (16i64 * (*(_DWORD *)(v11 + 8) & 0xF))) - 1;
      v15 = (unsigned __int64)this->Bin.Roots[v14];
      if ( v15 )
      {
        *(_QWORD *)v11 = v15 | v13;
        *(_QWORD *)(v11 + 8) = v12 | *(_QWORD *)(v15 + 8) & 0xFFFFFFFFFFFFFFF0ui64;
        v16 = (_QWORD *)(*(_QWORD *)(v15 + 8) & 0xFFFFFFFFFFFFFFF0ui64);
        *v16 &= 0xFui64;
        *v16 |= v11;
        *(_QWORD *)(v15 + 8) &= 0xFui64;
        *(_QWORD *)(v15 + 8) |= v11;
      }
      else
      {
        *(_QWORD *)(v11 + 8) = v11 | v12;
        *(_QWORD *)v11 = v11 | v13;
      }
      this->Bin.Roots[v14] = (Scaleform::HeapMH::BinNodeMH *)v11;
      this->Bin.Mask |= 1i64 << v14;
      BitSet = headers->BitSet;
      v18 = &BitSet[(unsigned __int64)((__int64)(bytes + (char *)v8 - headers->AlignedStart) >> 4) >> 4];
      v19 = (v10 >> 4) + ((__int64)(bytes + (char *)v8 - headers->AlignedStart) >> 4) - 1;
      *v18 &= ~(3 << ((2 * ((__int64)(bytes + (char *)v8 - headers->AlignedStart) >> 4)) & 0x1E));
      BitSet[v19 >> 4] &= ~(3 << ((2 * v19) & 0x1E));
    }
    Scaleform::Heap::BitSet2::MarkBusy(headers->BitSet, ((char *)v8 - headers->AlignedStart) >> 4, v5);
    return v8;
  }
  return result;
}

// File Line: 164
// RVA: 0x97D6B0
void __fastcall Scaleform::HeapMH::AllocBitSet2MH::Free(
        Scaleform::HeapMH::AllocBitSet2MH *this,
        Scaleform::HeapMH::PageMH *page,
        unsigned __int64 ptr,
        Scaleform::HeapMH::MagicHeadersInfo *headers,
        unsigned __int64 *oldSize)
{
  unsigned int *BitSet; // rcx
  signed __int64 v10; // r15
  unsigned __int64 v11; // r15
  unsigned __int64 BlockSize; // rax
  unsigned __int64 v13; // rdi
  unsigned int *v14; // r9
  bool v15; // r9
  bool right; // cl
  __int64 v17; // rdi
  unsigned __int64 v18; // rax
  __int64 v19; // r8
  __int64 v20; // rcx
  unsigned __int64 v21; // rax
  unsigned __int64 v22; // rax
  __int64 v23; // r9
  unsigned __int64 v24; // rdx
  _QWORD *v25; // rax

  Scaleform::HeapMH::GetMagicHeaders((unsigned __int64)page->Start, headers);
  BitSet = headers->BitSet;
  v10 = ptr - (unsigned __int64)headers->AlignedStart;
  headers->Page = page;
  v11 = v10 >> 4;
  BlockSize = Scaleform::Heap::BitSet2::GetBlockSize(BitSet, v11);
  v13 = 16 * BlockSize;
  *oldSize = 16 * BlockSize;
  v14 = headers->BitSet;
  v14[v11 >> 4] &= ~(3 << ((2 * v11) & 0x1E));
  v14[(BlockSize + v11 - 1) >> 4] &= ~(3 << ((2 * (BlockSize + v11 - 1)) & 0x1E));
  v15 = v11 && ((headers->BitSet[(v11 - 1) >> 4] >> ((2 * (v11 - 1)) & 0x1E)) & 3) == 0;
  right = (char *)(v13 + ptr) < headers->AlignedEnd
       && ((headers->BitSet[(BlockSize + v11) >> 4] >> ((2 * (BlockSize + v11)) & 0x1E)) & 3) == 0;
  if ( v15 || right )
  {
    Scaleform::HeapMH::ListBinMH::Merge(&this->Bin, (char *)ptr, v13, v15, right, page);
  }
  else
  {
    v17 = (2 * BlockSize) & 0x1FFFFFFFFFFFFFFFi64;
    *(_QWORD *)ptr ^= ((unsigned __int8)BlockSize ^ (unsigned __int8)*(_QWORD *)ptr) & 0xF;
    *(_QWORD *)(ptr + 8 * v17 - 16) = *(_QWORD *)ptr;
    v18 = ((BlockSize & 0xFFFFFFFFFFFFFFFi64) >> 4) | *(_QWORD *)(ptr + 8) & 0xFFFFFFFFFFFFFFF0ui64;
    *(_QWORD *)(ptr + 8) = v18;
    *(_QWORD *)(ptr + 8 * v17 - 8) = v18;
    v19 = *(_QWORD *)(ptr + 8) & 0xFi64;
    v20 = *(_QWORD *)ptr & 0xFi64;
    v21 = v20 | (16i64 * (*(_DWORD *)(ptr + 8) & 0xF));
    if ( v21 > 2 )
      *(_QWORD *)(ptr + 16) = page;
    v22 = v21 - 1;
    v23 = 63i64;
    if ( v22 < 0x3F )
      v23 = v22;
    v24 = (unsigned __int64)this->Bin.Roots[v23];
    if ( v24 )
    {
      *(_QWORD *)ptr = v24 | v20;
      *(_QWORD *)(ptr + 8) = v19 | *(_QWORD *)(v24 + 8) & 0xFFFFFFFFFFFFFFF0ui64;
      v25 = (_QWORD *)(*(_QWORD *)(v24 + 8) & 0xFFFFFFFFFFFFFFF0ui64);
      *v25 &= 0xFui64;
      *v25 |= ptr;
      *(_QWORD *)(v24 + 8) &= 0xFui64;
      *(_QWORD *)(v24 + 8) |= ptr;
    }
    else
    {
      *(_QWORD *)(ptr + 8) = ptr | v19;
      *(_QWORD *)ptr = ptr | v20;
    }
    this->Bin.Roots[v23] = (Scaleform::HeapMH::BinNodeMH *)ptr;
    this->Bin.Mask |= 1i64 << v23;
  }
}

// File Line: 207
// RVA: 0x955E00
Scaleform::HeapMH::BinNodeMH *__fastcall Scaleform::HeapMH::AllocBitSet2MH::Alloc(
        Scaleform::HeapMH::AllocBitSet2MH *this,
        unsigned __int64 bytes,
        unsigned __int64 alignSize,
        Scaleform::HeapMH::MagicHeadersInfo *headers)
{
  __int64 v4; // rdi
  unsigned __int64 v6; // r15
  Scaleform::HeapMH::BinNodeMH *result; // rax
  Scaleform::HeapMH::BinNodeMH *v9; // rbx
  Scaleform::HeapMH::PageMH *Page; // rbp
  Scaleform::HeapMH::BinNodeMH *v11; // rsi
  unsigned __int64 v12; // rax
  unsigned __int64 v13; // rdi
  unsigned __int64 v14; // r12
  __int64 v15; // r8
  __int64 v16; // rcx
  __int64 v17; // r9
  unsigned __int64 v18; // rdx
  _QWORD *v19; // rax
  unsigned int *BitSet; // r8
  unsigned __int64 v21; // rbx
  char *v22; // rbx
  unsigned int *v23; // r8
  unsigned int *v24; // rdx
  unsigned __int64 v25; // rcx

  v4 = alignSize - 1;
  v6 = bytes >> 4;
  result = Scaleform::HeapMH::ListBinMH::PullBest(&this->Bin, bytes >> 4, alignSize - 1);
  v9 = result;
  if ( result )
  {
    if ( (result->Prev & 0xF | (16 * (unsigned __int64)(result->Next & 0xF))) <= 2 || (Page = result->Page) == 0i64 )
      Page = Scaleform::HeapMH::RootMH::ResolveAddress(Scaleform::HeapMH::GlobalRootMH, (unsigned __int64)result);
    v11 = (Scaleform::HeapMH::BinNodeMH *)(~v4 & ((unsigned __int64)v9 + v4));
    Scaleform::HeapMH::GetMagicHeaders((unsigned __int64)Page->Start, headers);
    headers->Page = Page;
    v12 = bytes;
    v13 = (unsigned __int64)v9 + 16 * (v9->Prev & 0xF | (16i64 * (v9->Next & 0xF))) - (_QWORD)v11 - bytes;
    v14 = (char *)v11 - (char *)v9;
    if ( v11 != v9 )
    {
      Scaleform::HeapMH::BinNodeMH::MakeNode((char *)v9, (char *)v11 - (char *)v9, Page);
      v15 = v9->Next & 0xF;
      v16 = v9->Prev & 0xF;
      v17 = 63i64;
      if ( (v16 | (16 * (unsigned __int64)(v9->Next & 0xF))) - 1 < 0x3F )
        v17 = (v16 | (16i64 * (v9->Next & 0xF))) - 1;
      v18 = (unsigned __int64)this->Bin.Roots[v17];
      if ( v18 )
      {
        v9->Prev = v18 | v16;
        v9->Next = v15 | *(_QWORD *)(v18 + 8) & 0xFFFFFFFFFFFFFFF0ui64;
        v19 = (_QWORD *)(*(_QWORD *)(v18 + 8) & 0xFFFFFFFFFFFFFFF0ui64);
        *v19 &= 0xFui64;
        *v19 |= (unsigned __int64)v9;
        *(_QWORD *)(v18 + 8) &= 0xFui64;
        *(_QWORD *)(v18 + 8) |= (unsigned __int64)v9;
      }
      else
      {
        v9->Next = (unsigned __int64)v9 | v15;
        v9->Prev = (unsigned __int64)v9 | v16;
      }
      this->Bin.Roots[v17] = v9;
      this->Bin.Mask |= 1i64 << v17;
      BitSet = headers->BitSet;
      v21 = ((char *)v9 - headers->AlignedStart) >> 4;
      BitSet[v21 >> 4] &= ~(3 << ((2 * v21) & 0x1E));
      v12 = bytes;
      BitSet[((v14 >> 4) + v21 - 1) >> 4] &= ~(3 << ((2 * ((v14 >> 4) + v21 - 1)) & 0x1E));
    }
    if ( v13 )
    {
      v22 = (char *)v11 + v12;
      Scaleform::HeapMH::BinNodeMH::MakeNode((char *)v11 + v12, v13, Page);
      Scaleform::HeapMH::ListBinMH::Push(&this->Bin, v22);
      v23 = headers->BitSet;
      v24 = &v23[(unsigned __int64)((__int64)(bytes + (char *)v11 - headers->AlignedStart) >> 4) >> 4];
      v25 = (v13 >> 4) + ((__int64)(bytes + (char *)v11 - headers->AlignedStart) >> 4) - 1;
      *v24 &= ~(3 << ((2 * ((__int64)(bytes + (char *)v11 - headers->AlignedStart) >> 4)) & 0x1E));
      v23[v25 >> 4] &= ~(3 << ((2 * v25) & 0x1E));
    }
    Scaleform::Heap::BitSet2::MarkBusy(headers->BitSet, ((char *)v11 - headers->AlignedStart) >> 4, v6);
    return v11;
  }
  return result;
}

// File Line: 262
// RVA: 0x9A6A30
char *__fastcall Scaleform::HeapMH::AllocBitSet2MH::ReallocInPlace(
        Scaleform::HeapMH::AllocBitSet2MH *this,
        Scaleform::HeapMH::PageMH *page,
        char *oldPtr,
        unsigned __int64 newSize,
        unsigned __int64 *oldSize,
        Scaleform::HeapMH::MagicHeadersInfo *headers)
{
  unsigned int *Bound; // rax
  char *AlignedStart; // rcx
  char *AlignedEnd; // rdi
  unsigned int *BitSet; // r15
  __int64 v15; // rbp
  unsigned __int64 BlockSize; // rax
  __int64 v17; // rbx
  __int64 v18; // rdi
  unsigned __int64 v19; // rdi
  unsigned __int64 v20; // rbx
  __int64 v22; // r8
  __int64 v23; // r10
  unsigned __int64 v24; // rdi
  unsigned __int64 v25; // rbx
  Scaleform::HeapMH::MagicHeadersInfo *headersa; // [rsp+78h] [rbp+30h]

  Scaleform::HeapMH::GetMagicHeaders((unsigned __int64)page->Start, headers);
  Bound = (unsigned int *)headers->Bound;
  AlignedStart = headers->AlignedStart;
  AlignedEnd = headers->AlignedEnd;
  headers->Page = page;
  headersa = (Scaleform::HeapMH::MagicHeadersInfo *)AlignedStart;
  if ( oldPtr < (char *)Bound )
  {
    AlignedEnd = (char *)(Bound - 4);
    if ( headers->BitSet < Bound )
      AlignedEnd = (char *)(Bound - 20);
  }
  BitSet = headers->BitSet;
  v15 = (oldPtr - AlignedStart) >> 4;
  BlockSize = Scaleform::Heap::BitSet2::GetBlockSize(BitSet, v15);
  v17 = 16 * BlockSize;
  *oldSize = 16 * BlockSize;
  if ( newSize <= 16 * BlockSize )
  {
    if ( newSize < 16 * BlockSize )
    {
      v22 = 0i64;
      v23 = v17 - newSize;
      if ( &oldPtr[v17] < AlignedEnd && ((BitSet[(v15 + BlockSize) >> 4] >> ((2 * (v15 + BlockSize)) & 0x1E)) & 3) == 0 )
        v22 = 16 * (*(_DWORD *)&oldPtr[v17] & 0xF | (16i64 * (*(_DWORD *)&oldPtr[v17 + 8] & 0xF)));
      v24 = v22 + v23;
      if ( v22 + v23 )
      {
        if ( v22 )
          Scaleform::HeapMH::ListBinMH::Pull(&this->Bin, &oldPtr[v17]);
        Scaleform::HeapMH::BinNodeMH::MakeNode((Scaleform::HeapMH::BinNodeMH *)&oldPtr[newSize], v24, page);
        Scaleform::HeapMH::ListBinMH::Push(&this->Bin, (Scaleform::HeapMH::BinNodeMH *)&oldPtr[newSize]);
        Scaleform::Heap::BitSet2::MarkBusy(BitSet, v15, newSize >> 4);
        v25 = (&oldPtr[newSize] - (char *)headersa) >> 4;
        BitSet[v25 >> 4] &= ~(3 << ((2 * v25) & 0x1E));
        BitSet[((v24 >> 4) + v25 - 1) >> 4] &= ~(3 << ((2 * ((v24 >> 4) + v25 - 1)) & 0x1E));
      }
    }
  }
  else
  {
    if ( &oldPtr[v17] >= AlignedEnd )
      return 0i64;
    if ( ((BitSet[(v15 + BlockSize) >> 4] >> ((2 * (v15 + BlockSize)) & 0x1E)) & 3) != 0 )
      return 0i64;
    v18 = 16 * (*(_DWORD *)&oldPtr[v17] & 0xF | (16i64 * (*(_DWORD *)&oldPtr[v17 + 8] & 0xF)));
    if ( newSize > v18 + v17 )
      return 0i64;
    Scaleform::HeapMH::ListBinMH::Pull(&this->Bin, &oldPtr[v17]);
    v19 = v17 + v18 - newSize;
    if ( v19 )
    {
      Scaleform::HeapMH::BinNodeMH::MakeNode((Scaleform::HeapMH::BinNodeMH *)&oldPtr[newSize], v19, page);
      Scaleform::HeapMH::ListBinMH::Push(&this->Bin, (Scaleform::HeapMH::BinNodeMH *)&oldPtr[newSize]);
      v20 = (&oldPtr[newSize] - (char *)headersa) >> 4;
      BitSet[v20 >> 4] &= ~(3 << ((2 * v20) & 0x1E));
      BitSet[((v19 >> 4) + v20 - 1) >> 4] &= ~(3 << ((2 * ((v19 >> 4) + v20 - 1)) & 0x1E));
    }
    Scaleform::Heap::BitSet2::MarkBusy(BitSet, v15, newSize >> 4);
  }
  return oldPtr;
}

