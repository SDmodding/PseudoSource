// File Line: 34
// RVA: 0x993660
void __fastcall Scaleform::HeapMH::AllocBitSet2MH::InitPage(Scaleform::HeapMH::AllocBitSet2MH *this, Scaleform::HeapMH::PageMH *page, unsigned int index)
{
  char *v3; // rax
  signed __int64 v4; // rbx
  unsigned int v5; // er12
  unsigned __int64 v6; // rsi
  unsigned __int64 v7; // r13
  unsigned __int64 v8; // rbp
  signed __int64 v9; // r14
  unsigned __int64 v10; // rdi
  void *v11; // r15
  signed __int64 v12; // r8
  signed __int64 v13; // r9
  unsigned __int64 v14; // r12
  signed __int64 v15; // r11
  unsigned __int64 v16; // r8
  signed __int64 v17; // rcx
  unsigned __int64 v18; // rax
  signed __int64 v19; // r10
  signed __int64 v20; // rdx
  unsigned __int64 v21; // rax
  Scaleform::HeapMH::AllocBitSet2MH *v22; // r14
  unsigned __int64 v23; // rax
  signed __int64 v24; // rdi
  unsigned __int64 v25; // rcx
  _QWORD *v26; // rax
  unsigned __int64 v27; // rbx
  unsigned __int64 v28; // r12
  signed __int64 v29; // rcx
  unsigned __int64 v30; // rax
  signed __int64 v31; // r8
  signed __int64 v32; // rdx
  unsigned __int64 v33; // rax
  unsigned __int64 v34; // rax
  Scaleform::HeapMH::BinNodeMH *v35; // rcx
  _QWORD *v36; // rax
  unsigned __int64 v37; // r9
  Scaleform::HeapMH::AllocBitSet2MH *v38; // [rsp+60h] [rbp+8h]
  Scaleform::HeapMH::PageMH *v39; // [rsp+68h] [rbp+10h]

  v39 = page;
  v38 = this;
  v3 = page->Start;
  v4 = 0i64;
  v5 = index;
  v6 = (unsigned __int64)(v3 + 4095) & 0xFFFFFFFFFFFFF000ui64;
  v7 = (unsigned __int64)(v3 + 15) & 0xFFFFFFFFFFFFFFF0ui64;
  v8 = (unsigned __int64)(v3 + 4096) & 0xFFFFFFFFFFFFFFF0ui64;
  v9 = 0i64;
  if ( v6 - v7 > 0x10 )
    v9 = v6 - 16;
  v10 = 0i64;
  v11 = (void *)(v6 - 80);
  if ( v8 - v6 > 0x10 )
    v10 = (unsigned __int64)(v3 + 4095) & 0xFFFFFFFFFFFFF000ui64;
  if ( v6 - v7 <= v8 - v6 )
    v11 = (void *)(v6 + 16);
  memset(v11, 85, 0x40ui64);
  if ( v9 )
  {
    *(_DWORD *)v9 = 24512;
    *(_DWORD *)(v9 + 4) = v5;
    *(_QWORD *)(v9 + 8) = 0i64;
  }
  if ( v10 )
  {
    *(_DWORD *)v10 = 24512;
    *(_DWORD *)(v10 + 4) = v5;
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
    v17 = v4 + 8 * (v16 >> 3);
    *(_QWORD *)v4 ^= ((unsigned __int8)(v16 >> 4) ^ (unsigned __int8)*(_QWORD *)v4) & 0xF;
    *(_QWORD *)(v17 - 16) = *(_QWORD *)v4;
    v18 = (v16 >> 8) | *(_QWORD *)(v4 + 8) & 0xFFFFFFFFFFFFFFF0ui64;
    *(_QWORD *)(v4 + 8) = v18;
    *(_QWORD *)(v17 - 8) = v18;
    v19 = *(_QWORD *)(v4 + 8) & 0xFi64;
    v20 = *(_QWORD *)v4 & 0xFi64;
    v21 = v20 | 16i64 * (*(_DWORD *)(v4 + 8) & 0xF);
    if ( v21 > 2 )
      *(_QWORD *)(v4 + 16) = v39;
    v22 = v38;
    v23 = v21 - 1;
    v24 = 63i64;
    if ( v23 < 0x3F )
      v24 = v23;
    v25 = (unsigned __int64)v38->Bin.Roots[v24];
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
    v38->Bin.Roots[v24] = (Scaleform::HeapMH::BinNodeMH *)v4;
    v27 = (signed __int64)(v4 - v7) >> 4;
    v38->Bin.Mask |= 1i64 << v24;
    *((_DWORD *)v11 + (v27 >> 4)) &= ~(3 << (2 * v27 & 0x1E));
    *((_DWORD *)v11 + ((v27 + ((signed __int64)v16 >> 4) - 1) >> 4)) &= ~(3 << (2
                                                                              * (v27
                                                                               + (unsigned __int64)((signed __int64)v16 >> 4)
                                                                               - 1) & 0x1E));
  }
  else
  {
    v22 = v38;
  }
  if ( v13 )
  {
    v28 = v14 - v13;
    v29 = v13 + 8 * (v28 >> 3);
    *(_QWORD *)v13 ^= ((unsigned __int8)(v28 >> 4) ^ (unsigned __int8)*(_QWORD *)v13) & 0xF;
    *(_QWORD *)(v29 - 16) = *(_QWORD *)v13;
    v30 = (v28 >> 8) | *(_QWORD *)(v13 + 8) & 0xFFFFFFFFFFFFFFF0ui64;
    *(_QWORD *)(v13 + 8) = v30;
    *(_QWORD *)(v29 - 8) = v30;
    v31 = *(_QWORD *)(v13 + 8) & 0xFi64;
    v32 = *(_QWORD *)v13 & 0xFi64;
    v33 = v32 | 16i64 * (*(_DWORD *)(v13 + 8) & 0xF);
    if ( v33 > 2 )
      *(_QWORD *)(v13 + 16) = v39;
    v34 = v33 - 1;
    if ( v34 < 0x3F )
      v15 = v34;
    v35 = v22->Bin.Roots[v15];
    if ( v35 )
    {
      *(_QWORD *)v13 = v32 | (unsigned __int64)v35;
      *(_QWORD *)(v13 + 8) = v31 | v35->Next & 0xFFFFFFFFFFFFFFF0ui64;
      v36 = (_QWORD *)(v35->Next & 0xFFFFFFFFFFFFFFF0ui64);
      *v36 &= 0xFui64;
      *v36 |= v13;
      v35->Next &= 0xFui64;
      v35->Next |= v13;
    }
    else
    {
      *(_QWORD *)(v13 + 8) = v13 | v31;
      *(_QWORD *)v13 = v13 | v32;
    }
    v22->Bin.Roots[v15] = (Scaleform::HeapMH::BinNodeMH *)v13;
    v37 = (signed __int64)(v13 - v7) >> 4;
    v22->Bin.Mask |= 1i64 << v15;
    *((_DWORD *)v11 + (v37 >> 4)) &= ~(3 << (2 * v37 & 0x1E));
    *((_DWORD *)v11 + ((((signed __int64)v28 >> 4) + v37 - 1) >> 4)) &= ~(3 << (2
                                                                              * (((signed __int64)v28 >> 4) + v37 - 1) & 0x1E));
  }
}

// File Line: 95
// RVA: 0x9A8160
void __fastcall Scaleform::HeapMH::AllocBitSet2MH::ReleasePage(Scaleform::HeapMH::AllocBitSet2MH *this, char *start)
{
  Scaleform::HeapMH::AllocBitSet2MH *v2; // rbp
  unsigned __int64 v3; // rbx
  signed __int64 v4; // r8
  char *v5; // rcx
  unsigned __int64 v6; // rax
  unsigned __int64 v7; // rdx
  unsigned __int64 v8; // rdi
  unsigned __int64 v9; // rax
  unsigned __int64 v10; // rsi
  char *v11; // rdx

  v2 = this;
  v3 = (unsigned __int64)(start + 4095) & 0xFFFFFFFFFFFFF000ui64;
  v4 = 0i64;
  v5 = (char *)((unsigned __int64)(start + 15) & 0xFFFFFFFFFFFFFFF0ui64);
  v6 = (unsigned __int64)(start + 4096) & 0xFFFFFFFFFFFFFFF0ui64;
  v7 = v3 - (_QWORD)v5;
  v8 = 0i64;
  if ( v7 > 0x10 )
    v4 = v3 - 16;
  v9 = v6 - v3;
  v10 = v3 - 80;
  if ( v9 > 0x10 )
    v8 = v3;
  if ( v7 <= v9 )
    v10 = v3 + 16;
  if ( v4 )
    Scaleform::HeapMH::ListBinMH::Pull(&v2->Bin, v5);
  if ( v8 )
  {
    v11 = (char *)(v8 + 16);
    if ( v10 > v3 )
      v11 = (char *)(v8 + 80);
    Scaleform::HeapMH::ListBinMH::Pull(&v2->Bin, v11);
  }
}

// File Line: 122
// RVA: 0x956080
Scaleform::HeapMH::BinNodeMH *__fastcall Scaleform::HeapMH::AllocBitSet2MH::Alloc(Scaleform::HeapMH::AllocBitSet2MH *this, unsigned __int64 bytes, Scaleform::HeapMH::MagicHeadersInfo *headers)
{
  unsigned __int64 v3; // r12
  Scaleform::HeapMH::MagicHeadersInfo *v4; // r14
  unsigned __int64 v5; // r15
  Scaleform::HeapMH::AllocBitSet2MH *v6; // r13
  Scaleform::HeapMH::BinNodeMH *result; // rax
  char *v8; // rbx
  Scaleform::HeapMH::PageMH *v9; // rbp
  unsigned __int64 v10; // rdi
  unsigned __int64 v11; // rsi
  signed __int64 v12; // r8
  signed __int64 v13; // rcx
  signed __int64 v14; // r9
  unsigned __int64 v15; // rdx
  _QWORD *v16; // rax
  unsigned int *v17; // r8
  unsigned int *v18; // rdx
  unsigned __int64 v19; // rcx

  v3 = bytes;
  v4 = headers;
  v5 = bytes >> 4;
  v6 = this;
  result = Scaleform::HeapMH::ListBinMH::PullBest(&this->Bin, bytes >> 4);
  v8 = (char *)result;
  if ( result )
  {
    if ( (result->Prev & 0xF | 16 * (unsigned __int64)(result->Next & 0xF)) <= 2 || (v9 = result->Page) == 0i64 )
      v9 = Scaleform::HeapMH::RootMH::ResolveAddress(Scaleform::HeapMH::GlobalRootMH, (unsigned __int64)result);
    Scaleform::HeapMH::GetMagicHeaders((unsigned __int64)v9->Start, v4);
    v4->Page = v9;
    v10 = 16 * (*(_DWORD *)v8 & 0xF | 16i64 * (*((_DWORD *)v8 + 2) & 0xF)) - v3;
    if ( 16 * (*(_DWORD *)v8 & 0xF | 16i64 * (*((_DWORD *)v8 + 2) & 0xF)) != v3 )
    {
      v11 = (unsigned __int64)&v8[v3];
      Scaleform::HeapMH::BinNodeMH::MakeNode(&v8[v3], v10, v9);
      v12 = *(_QWORD *)&v8[v3 + 8] & 0xFi64;
      v13 = *(_QWORD *)&v8[v3] & 0xFi64;
      v14 = 63i64;
      if ( (v13 | 16 * (unsigned __int64)(*(_DWORD *)&v8[v3 + 8] & 0xF)) - 1 < 0x3F )
        v14 = (v13 | 16i64 * (*(_DWORD *)(v11 + 8) & 0xF)) - 1;
      v15 = (unsigned __int64)v6->Bin.Roots[v14];
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
      v6->Bin.Roots[v14] = (Scaleform::HeapMH::BinNodeMH *)v11;
      v6->Bin.Mask |= 1i64 << v14;
      v17 = v4->BitSet;
      v18 = &v17[(unsigned __int64)((signed __int64)(v3 + v8 - v4->AlignedStart) >> 4) >> 4];
      v19 = (v10 >> 4) + ((signed __int64)(v3 + v8 - v4->AlignedStart) >> 4) - 1;
      *v18 &= ~(3 << (2 * (unsigned __int64)((signed __int64)(v3 + v8 - v4->AlignedStart) >> 4) & 0x1E));
      v17[v19 >> 4] &= ~(3 << (2 * v19 & 0x1E));
    }
    Scaleform::Heap::BitSet2::MarkBusy(v4->BitSet, (v8 - v4->AlignedStart) >> 4, v5);
    result = (Scaleform::HeapMH::BinNodeMH *)v8;
  }
  return result;
}

// File Line: 164
// RVA: 0x97D6B0
void __fastcall Scaleform::HeapMH::AllocBitSet2MH::Free(Scaleform::HeapMH::AllocBitSet2MH *this, Scaleform::HeapMH::PageMH *page, void *ptr, Scaleform::HeapMH::MagicHeadersInfo *headers, unsigned __int64 *oldSize)
{
  Scaleform::HeapMH::PageMH *v5; // r14
  Scaleform::HeapMH::AllocBitSet2MH *v6; // rsi
  Scaleform::HeapMH::MagicHeadersInfo *v7; // rbp
  unsigned __int64 v8; // rbx
  const unsigned int *v9; // rcx
  signed __int64 v10; // r15
  unsigned __int64 v11; // r15
  unsigned __int64 v12; // rax
  unsigned int *v13; // r9
  unsigned int *v14; // rdx
  bool v15; // r9
  bool right; // cl
  signed __int64 v17; // rdi
  unsigned __int64 v18; // rax
  signed __int64 v19; // r8
  signed __int64 v20; // rcx
  unsigned __int64 v21; // rax
  unsigned __int64 v22; // rax
  signed __int64 v23; // r9
  unsigned __int64 v24; // rdx
  _QWORD *v25; // rax

  v5 = page;
  v6 = this;
  v7 = headers;
  v8 = (unsigned __int64)ptr;
  Scaleform::HeapMH::GetMagicHeaders((unsigned __int64)page->Start, headers);
  v9 = v7->BitSet;
  v10 = v8 - (unsigned __int64)v7->AlignedStart;
  v7->Page = v5;
  v11 = v10 >> 4;
  v12 = Scaleform::Heap::BitSet2::GetBlockSize(v9, v11);
  *oldSize = 16 * v12;
  v13 = v7->BitSet;
  v13[v11 >> 4] &= ~(3 << (2 * v11 & 0x1E));
  v14 = &v13[(v12 + v11 - 1) >> 4];
  *v14 &= ~(3 << (2 * (v12 + v11 - 1) & 0x1E));
  v15 = v11 && !((v7->BitSet[(v11 - 1) >> 4] >> (2 * (v11 - 1) & 0x1E)) & 3);
  right = (char *)(16 * v12 + v8) < v7->AlignedEnd && !((v7->BitSet[(v12 + v11) >> 4] >> (2 * (v12 + v11) & 0x1E)) & 3);
  if ( v15 || right )
  {
    Scaleform::HeapMH::ListBinMH::Merge(&v6->Bin, (char *)v8, 16 * v12, v15, right, v5);
  }
  else
  {
    v17 = 2 * v12 & 0x1FFFFFFFFFFFFFFFi64;
    *(_QWORD *)v8 ^= ((unsigned __int8)v12 ^ (unsigned __int8)*(_QWORD *)v8) & 0xF;
    *(_QWORD *)(v8 + 8 * v17 - 16) = *(_QWORD *)v8;
    v18 = ((v12 & 0xFFFFFFFFFFFFFFFi64) >> 4) | *(_QWORD *)(v8 + 8) & 0xFFFFFFFFFFFFFFF0ui64;
    *(_QWORD *)(v8 + 8) = v18;
    *(_QWORD *)(v8 + 8 * v17 - 8) = v18;
    v19 = *(_QWORD *)(v8 + 8) & 0xFi64;
    v20 = *(_QWORD *)v8 & 0xFi64;
    v21 = v20 | 16i64 * (*(_DWORD *)(v8 + 8) & 0xF);
    if ( v21 > 2 )
      *(_QWORD *)(v8 + 16) = v5;
    v22 = v21 - 1;
    v23 = 63i64;
    if ( v22 < 0x3F )
      v23 = v22;
    v24 = (unsigned __int64)v6->Bin.Roots[v23];
    if ( v24 )
    {
      *(_QWORD *)v8 = v24 | v20;
      *(_QWORD *)(v8 + 8) = v19 | *(_QWORD *)(v24 + 8) & 0xFFFFFFFFFFFFFFF0ui64;
      v25 = (_QWORD *)(*(_QWORD *)(v24 + 8) & 0xFFFFFFFFFFFFFFF0ui64);
      *v25 &= 0xFui64;
      *v25 |= v8;
      *(_QWORD *)(v24 + 8) &= 0xFui64;
      *(_QWORD *)(v24 + 8) |= v8;
    }
    else
    {
      *(_QWORD *)(v8 + 8) = v8 | v19;
      *(_QWORD *)v8 = v8 | v20;
    }
    v6->Bin.Roots[v23] = (Scaleform::HeapMH::BinNodeMH *)v8;
    v6->Bin.Mask |= 1i64 << v23;
  }
}

// File Line: 207
// RVA: 0x955E00
Scaleform::HeapMH::BinNodeMH *__fastcall Scaleform::HeapMH::AllocBitSet2MH::Alloc(Scaleform::HeapMH::AllocBitSet2MH *this, unsigned __int64 bytes, unsigned __int64 alignSize, Scaleform::HeapMH::MagicHeadersInfo *headers)
{
  unsigned __int64 v4; // rdi
  Scaleform::HeapMH::MagicHeadersInfo *v5; // r14
  unsigned __int64 v6; // r15
  Scaleform::HeapMH::AllocBitSet2MH *v7; // r13
  Scaleform::HeapMH::BinNodeMH *result; // rax
  Scaleform::HeapMH::BinNodeMH *v9; // rbx
  Scaleform::HeapMH::PageMH *v10; // rbp
  Scaleform::HeapMH::BinNodeMH *v11; // rsi
  unsigned __int64 v12; // rax
  unsigned __int64 v13; // rdi
  unsigned __int64 v14; // r12
  signed __int64 v15; // r8
  signed __int64 v16; // rcx
  signed __int64 v17; // r9
  unsigned __int64 v18; // rdx
  _QWORD *v19; // rax
  unsigned int *v20; // r8
  unsigned __int64 v21; // rbx
  char *v22; // rbx
  unsigned int *v23; // r8
  unsigned int *v24; // rdx
  unsigned __int64 v25; // rcx
  unsigned __int64 v26; // [rsp+58h] [rbp+10h]

  v26 = bytes;
  v4 = alignSize - 1;
  v5 = headers;
  v6 = bytes >> 4;
  v7 = this;
  result = Scaleform::HeapMH::ListBinMH::PullBest(&this->Bin, bytes >> 4, alignSize - 1);
  v9 = result;
  if ( result )
  {
    if ( (result->Prev & 0xF | 16 * (unsigned __int64)(result->Next & 0xF)) <= 2 || (v10 = result->Page) == 0i64 )
      v10 = Scaleform::HeapMH::RootMH::ResolveAddress(Scaleform::HeapMH::GlobalRootMH, (unsigned __int64)result);
    v11 = (Scaleform::HeapMH::BinNodeMH *)(~v4 & ((unsigned __int64)v9 + v4));
    Scaleform::HeapMH::GetMagicHeaders((unsigned __int64)v10->Start, v5);
    v5->Page = v10;
    v12 = v26;
    v13 = (unsigned __int64)v9 + 16 * (v9->Prev & 0xF | 16i64 * (v9->Next & 0xF)) - (_QWORD)v11 - v26;
    v14 = (char *)v11 - (char *)v9;
    if ( v11 != v9 )
    {
      Scaleform::HeapMH::BinNodeMH::MakeNode((char *)v9, (char *)v11 - (char *)v9, v10);
      v15 = v9->Next & 0xF;
      v16 = v9->Prev & 0xF;
      v17 = 63i64;
      if ( (v16 | 16 * (unsigned __int64)(v9->Next & 0xF)) - 1 < 0x3F )
        v17 = (v16 | 16i64 * (v9->Next & 0xF)) - 1;
      v18 = (unsigned __int64)v7->Bin.Roots[v17];
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
      v7->Bin.Roots[v17] = v9;
      v7->Bin.Mask |= 1i64 << v17;
      v20 = v5->BitSet;
      v21 = ((char *)v9 - v5->AlignedStart) >> 4;
      v20[v21 >> 4] &= ~(3 << (2 * v21 & 0x1E));
      v12 = v26;
      v20[((v14 >> 4) + v21 - 1) >> 4] &= ~(3 << (2 * ((v14 >> 4) + v21 - 1) & 0x1E));
    }
    if ( v13 )
    {
      v22 = (char *)v11 + v12;
      Scaleform::HeapMH::BinNodeMH::MakeNode((char *)v11 + v12, v13, v10);
      Scaleform::HeapMH::ListBinMH::Push(&v7->Bin, v22);
      v23 = v5->BitSet;
      v24 = &v23[(unsigned __int64)((signed __int64)(v26 + (char *)v11 - v5->AlignedStart) >> 4) >> 4];
      v25 = (v13 >> 4) + ((signed __int64)(v26 + (char *)v11 - v5->AlignedStart) >> 4) - 1;
      *v24 &= ~(3 << (2 * (unsigned __int64)((signed __int64)(v26 + (char *)v11 - v5->AlignedStart) >> 4) & 0x1E));
      v23[v25 >> 4] &= ~(3 << (2 * v25 & 0x1E));
    }
    Scaleform::Heap::BitSet2::MarkBusy(v5->BitSet, ((char *)v11 - v5->AlignedStart) >> 4, v6);
    result = v11;
  }
  return result;
}

// File Line: 262
// RVA: 0x9A6A30
char *__fastcall Scaleform::HeapMH::AllocBitSet2MH::ReallocInPlace(Scaleform::HeapMH::AllocBitSet2MH *this, Scaleform::HeapMH::PageMH *page, void *oldPtr, unsigned __int64 newSize, unsigned __int64 *oldSize, Scaleform::HeapMH::MagicHeadersInfo *headers)
{
  Scaleform::HeapMH::MagicHeadersInfo *v6; // rbx
  Scaleform::HeapMH::PageMH *v7; // r13
  Scaleform::HeapMH::AllocBitSet2MH *v8; // r12
  unsigned __int64 v9; // rsi
  char *v10; // r14
  char *v11; // rax
  char *v12; // rcx
  char *v13; // rdi
  unsigned int *v14; // r15
  unsigned __int64 v15; // rbp
  unsigned __int64 v16; // rax
  signed __int64 v17; // rbx
  signed __int64 v18; // rdi
  unsigned __int64 v19; // rdi
  unsigned __int64 v20; // rbx
  signed __int64 v22; // r8
  unsigned __int64 v23; // r10
  unsigned __int64 v24; // rdi
  unsigned __int64 v25; // rbx
  Scaleform::HeapMH::MagicHeadersInfo *headersa; // [rsp+78h] [rbp+30h]

  v6 = headers;
  v7 = page;
  v8 = this;
  v9 = newSize;
  v10 = (char *)oldPtr;
  Scaleform::HeapMH::GetMagicHeaders((unsigned __int64)page->Start, headers);
  v11 = headers->Bound;
  v12 = headers->AlignedStart;
  v13 = headers->AlignedEnd;
  headers->Page = v7;
  headersa = (Scaleform::HeapMH::MagicHeadersInfo *)v12;
  if ( v10 < v11 )
  {
    v13 = v11 - 16;
    if ( v6->BitSet < (unsigned int *)v11 )
      v13 = v11 - 80;
  }
  v14 = v6->BitSet;
  v15 = (v10 - v12) >> 4;
  v16 = Scaleform::Heap::BitSet2::GetBlockSize(v6->BitSet, v15);
  v17 = 16 * v16;
  *oldSize = 16 * v16;
  if ( v9 <= 16 * v16 )
  {
    if ( v9 < 16 * v16 )
    {
      v22 = 0i64;
      v23 = v17 - v9;
      if ( &v10[v17] < v13 && !((v14[(v15 + v16) >> 4] >> (2 * (v15 + v16) & 0x1E)) & 3) )
        v22 = 16 * (*(_DWORD *)&v10[v17] & 0xF | 16i64 * (*(_DWORD *)&v10[v17 + 8] & 0xF));
      v24 = v22 + v23;
      if ( v22 + v23 )
      {
        if ( v22 )
          Scaleform::HeapMH::ListBinMH::Pull(&v8->Bin, &v10[v17]);
        Scaleform::HeapMH::BinNodeMH::MakeNode(&v10[v9], v24, v7);
        Scaleform::HeapMH::ListBinMH::Push(&v8->Bin, &v10[v9]);
        Scaleform::Heap::BitSet2::MarkBusy(v14, v15, v9 >> 4);
        v25 = (&v10[v9] - (char *)headersa) >> 4;
        v14[v25 >> 4] &= ~(3 << (2 * v25 & 0x1E));
        v14[((v24 >> 4) + v25 - 1) >> 4] &= ~(3 << (2 * ((v24 >> 4) + v25 - 1) & 0x1E));
      }
    }
  }
  else
  {
    if ( &v10[v17] >= v13 )
      return 0i64;
    if ( (v14[(v15 + v16) >> 4] >> (2 * (v15 + v16) & 0x1E)) & 3 )
      return 0i64;
    v18 = 16 * (*(_DWORD *)&v10[v17] & 0xF | 16i64 * (*(_DWORD *)&v10[v17 + 8] & 0xF));
    if ( v9 > v18 + v17 )
      return 0i64;
    Scaleform::HeapMH::ListBinMH::Pull(&v8->Bin, &v10[v17]);
    v19 = v17 + v18 - v9;
    if ( v19 )
    {
      Scaleform::HeapMH::BinNodeMH::MakeNode(&v10[v9], v19, v7);
      Scaleform::HeapMH::ListBinMH::Push(&v8->Bin, &v10[v9]);
      v20 = (&v10[v9] - (char *)headersa) >> 4;
      v14[v20 >> 4] &= ~(3 << (2 * v20 & 0x1E));
      v14[((v19 >> 4) + v20 - 1) >> 4] &= ~(3 << (2 * ((v19 >> 4) + v20 - 1) & 0x1E));
    }
    Scaleform::Heap::BitSet2::MarkBusy(v14, v15, v9 >> 4);
  }
  return v10;
}

