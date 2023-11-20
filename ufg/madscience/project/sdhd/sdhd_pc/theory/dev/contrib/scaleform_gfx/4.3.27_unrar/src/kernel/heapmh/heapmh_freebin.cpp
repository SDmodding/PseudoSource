// File Line: 112
// RVA: 0x9A1BE0
unsigned __int64 __fastcall Scaleform::HeapMH::ListBinMH::PullBest(Scaleform::HeapMH::ListBinMH *this, unsigned __int64 blocks)
{
  unsigned __int64 v2; // rdx
  signed __int64 v3; // rdi
  Scaleform::HeapMH::ListBinMH *v4; // rbx
  unsigned __int64 result; // rax
  signed __int64 v6; // rcx
  signed __int64 v7; // r8
  Scaleform::HeapMH::BinNodeMH *v8; // rdx
  unsigned __int64 v9; // rax

  v2 = blocks - 1;
  v3 = 63i64;
  v4 = this;
  if ( v2 < 0x3F )
    v3 = v2;
  result = this->Mask >> v3;
  if ( result )
  {
    v6 = v3 + (unsigned __int8)Scaleform::Alg::LowerBit(result);
    v7 = (signed __int64)v4 + 8 * v6;
    v8 = *(Scaleform::HeapMH::BinNodeMH **)(v7 + 8);
    v9 = v8->Next & 0xFFFFFFFFFFFFFFF0ui64;
    if ( v8 == (Scaleform::HeapMH::BinNodeMH *)v9 )
    {
      *(_QWORD *)(v7 + 8) = 0i64;
      v4->Mask &= ~(1i64 << v6);
    }
    else
    {
      *(_QWORD *)(v7 + 8) = v9;
      *(_QWORD *)((v8->Prev & 0xFFFFFFFFFFFFFFF0ui64) + 8) = v8->Next ^ (LODWORD(v8->Next) ^ *(_DWORD *)((v8->Prev & 0xFFFFFFFFFFFFFFF0ui64) + 8)) & 0xF;
      *(_QWORD *)(v8->Next & 0xFFFFFFFFFFFFFFF0ui64) = v8->Prev ^ (*(_DWORD *)(v8->Next & 0xFFFFFFFFFFFFFFF0ui64) ^ LODWORD(v8->Prev)) & 0xF;
    }
    result = (unsigned __int64)v8;
  }
  return result;
}

// File Line: 131
// RVA: 0x9A1A70
unsigned __int64 __fastcall Scaleform::HeapMH::ListBinMH::PullBest(Scaleform::HeapMH::ListBinMH *this, unsigned __int64 blocks, unsigned __int64 alignMask)
{
  unsigned __int64 v3; // rbx
  Scaleform::HeapMH::ListBinMH *v4; // r14
  unsigned __int64 v5; // rsi
  unsigned __int64 v6; // rbp
  unsigned __int64 result; // rax
  unsigned __int64 v8; // r10
  Scaleform::HeapMH::BinNodeMH **v9; // rdi
  unsigned __int64 v10; // r9
  Scaleform::HeapMH::BinNodeMH *v11; // rdx
  signed __int64 v12; // r8
  unsigned __int64 v13; // rdx
  unsigned __int64 v14; // rcx
  unsigned __int64 v15; // rcx

  v3 = 63i64;
  v4 = this;
  v5 = alignMask;
  v6 = blocks;
  if ( blocks - 1 < 0x3F )
    v3 = blocks - 1;
  result = this->Mask >> v3;
  if ( result )
  {
    v8 = v3 + (unsigned __int8)Scaleform::Alg::LowerBit(result);
    v9 = &v4->Roots[v8];
    while ( 1 )
    {
      result = (unsigned __int64)*v9;
      if ( *v9 )
        break;
LABEL_8:
      ++v8;
      ++v9;
      if ( v8 >= 0x40 )
        return 0i64;
    }
    while ( 1 )
    {
      v10 = *(_QWORD *)(result + 8);
      if ( 16 * v6 + (~v5 & (result + v5)) <= result
                                            + 16 * (*(_DWORD *)result & 0xF | 16 * (*(_QWORD *)(result + 8) & 0xFi64)) )
        break;
      result = v10 & 0xFFFFFFFFFFFFFFF0ui64;
      if ( (Scaleform::HeapMH::BinNodeMH *)(v10 & 0xFFFFFFFFFFFFFFF0ui64) == *v9 )
        goto LABEL_8;
    }
    v11 = v4->Roots[v8];
    v12 = (signed __int64)v4 + 8 * v8;
    if ( (Scaleform::HeapMH::BinNodeMH *)result != v11 )
    {
      v13 = *(_QWORD *)result & 0xFFFFFFFFFFFFFFF0ui64;
      v14 = v10 ^ (*(_DWORD *)(v13 + 8) ^ (unsigned int)v10) & 0xF;
LABEL_15:
      *(_QWORD *)(v13 + 8) = v14;
      *(_QWORD *)(*(_QWORD *)(result + 8) & 0xFFFFFFFFFFFFFFF0ui64) = *(_QWORD *)result ^ (*(_DWORD *)(*(_QWORD *)(result + 8) & 0xFFFFFFFFFFFFFFF0ui64) ^ *(_DWORD *)result) & 0xF;
      return result;
    }
    v15 = v11->Next & 0xFFFFFFFFFFFFFFF0ui64;
    if ( v11 != (Scaleform::HeapMH::BinNodeMH *)v15 )
    {
      *(_QWORD *)(v12 + 8) = v15;
      v13 = *(_QWORD *)result & 0xFFFFFFFFFFFFFFF0ui64;
      v14 = *(_QWORD *)(result + 8) ^ (*(_DWORD *)(v13 + 8) ^ *(_DWORD *)(result + 8)) & 0xF;
      goto LABEL_15;
    }
    *(_QWORD *)(v12 + 8) = 0i64;
    v4->Mask &= ~(1i64 << v8);
  }
  return result;
}

// File Line: 162
// RVA: 0x9A1F10
void __fastcall Scaleform::HeapMH::ListBinMH::Push(Scaleform::HeapMH::ListBinMH *this, char *node)
{
  signed __int64 v2; // r11
  signed __int64 v3; // r9
  signed __int64 v4; // r8
  Scaleform::HeapMH::ListBinMH *v5; // r10
  unsigned __int64 v6; // rcx
  _QWORD *v7; // rax

  v2 = 63i64;
  v3 = *((_QWORD *)node + 1) & 0xFi64;
  v4 = *(_QWORD *)node & 0xFi64;
  v5 = this;
  if ( (v4 | 16 * (unsigned __int64)(*((_DWORD *)node + 2) & 0xF)) - 1 < 0x3F )
    v2 = (v4 | 16i64 * (*((_DWORD *)node + 2) & 0xF)) - 1;
  v6 = (unsigned __int64)this->Roots[v2];
  if ( v6 )
  {
    *(_QWORD *)node = v6 | v4;
    *((_QWORD *)node + 1) = v3 | *(_QWORD *)(v6 + 8) & 0xFFFFFFFFFFFFFFF0ui64;
    v7 = (_QWORD *)(*(_QWORD *)(v6 + 8) & 0xFFFFFFFFFFFFFFF0ui64);
    *v7 &= 0xFui64;
    *v7 |= (unsigned __int64)node;
    *(_QWORD *)(v6 + 8) &= 0xFui64;
    *(_QWORD *)(v6 + 8) |= (unsigned __int64)node;
  }
  else
  {
    *((_QWORD *)node + 1) = (unsigned __int64)node | v3;
    *(_QWORD *)node = (unsigned __int64)node | v4;
  }
  v5->Roots[v2] = (Scaleform::HeapMH::BinNodeMH *)node;
  v5->Mask |= 1i64 << v2;
}

// File Line: 171
// RVA: 0x9A1560
void __fastcall Scaleform::HeapMH::ListBinMH::Pull(Scaleform::HeapMH::ListBinMH *this, char *node)
{
  __int64 v2; // r11
  signed __int64 v3; // rbx
  Scaleform::HeapMH::ListBinMH *v4; // r10
  signed __int64 v5; // rax
  unsigned __int64 *v6; // r8
  Scaleform::HeapMH::BinNodeMH *v7; // rcx
  unsigned __int64 v8; // r9
  unsigned __int64 v9; // rax

  v2 = *((_QWORD *)node + 1);
  v3 = 63i64;
  v4 = this;
  v5 = *(_QWORD *)node & 0xFi64;
  if ( (v5 | 16 * (*((_QWORD *)node + 1) & 0xFui64)) - 1 < 0x3F )
    v3 = (v5 | 16 * (*((_QWORD *)node + 1) & 0xFi64)) - 1;
  v6 = &this->Mask + v3;
  v7 = this->Roots[v3];
  if ( node == (char *)v7 )
  {
    v9 = v7->Next & 0xFFFFFFFFFFFFFFF0ui64;
    if ( v7 == (Scaleform::HeapMH::BinNodeMH *)v9 )
    {
      v6[1] = 0i64;
      v4->Mask &= ~(1i64 << v3);
    }
    else
    {
      v6[1] = v9;
      *(_QWORD *)((*(_QWORD *)node & 0xFFFFFFFFFFFFFFF0ui64) + 8) = *((_QWORD *)node + 1) ^ (*(_DWORD *)((*(_QWORD *)node & 0xFFFFFFFFFFFFFFF0ui64) + 8) ^ *((_DWORD *)node + 2)) & 0xF;
      *(_QWORD *)(*((_QWORD *)node + 1) & 0xFFFFFFFFFFFFFFF0ui64) = *(_QWORD *)node ^ (*(_DWORD *)(*((_QWORD *)node + 1) & 0xFFFFFFFFFFFFFFF0ui64) ^ *(_DWORD *)node) & 0xF;
    }
  }
  else
  {
    v8 = *(_QWORD *)node & 0xFFFFFFFFFFFFFFF0ui64;
    *(_QWORD *)(v8 + 8) &= 0xFui64;
    *(_QWORD *)(v8 + 8) |= v2 & 0xFFFFFFFFFFFFFFF0ui64;
    *(_QWORD *)(*((_QWORD *)node + 1) & 0xFFFFFFFFFFFFFFF0ui64) = *(_QWORD *)node ^ (*(_DWORD *)node ^ *(_DWORD *)(*((_QWORD *)node + 1) & 0xFFFFFFFFFFFFFFF0ui64)) & 0xF;
  }
}

// File Line: 205
// RVA: 0x99A9B0
void __fastcall Scaleform::HeapMH::ListBinMH::Merge(Scaleform::HeapMH::ListBinMH *this, char *node, unsigned __int64 bytes, bool left, bool right, Scaleform::HeapMH::PageMH *page)
{
  bool v6; // r10
  Scaleform::HeapMH::ListBinMH *v7; // rsi
  char *v8; // r14
  unsigned __int64 v9; // rdi
  char *v10; // rbx
  char *v11; // r15
  unsigned __int64 v12; // r9
  unsigned __int64 v13; // rcx
  signed __int64 v14; // rdx
  signed __int64 v15; // rdx
  unsigned __int64 v16; // rcx
  signed __int64 v17; // r8
  signed __int64 v18; // rdx
  signed __int64 v19; // r9
  unsigned __int64 v20; // rcx
  _QWORD *v21; // rax

  v6 = left;
  v7 = this;
  v8 = node;
  v9 = bytes >> 4;
  v10 = node;
  v11 = node + 8;
  *(_QWORD *)node ^= ((unsigned __int8)(bytes >> 4) ^ (unsigned __int8)*(_QWORD *)node) & 0xF;
  v12 = 2 * ((bytes >> 4) & 0xFFFFFFFFFFFFFFFi64);
  *(_QWORD *)&node[8 * v12 - 16] = *(_QWORD *)node;
  v13 = (bytes >> 8) | *((_QWORD *)node + 1) & 0xFFFFFFFFFFFFFFF0ui64;
  *((_QWORD *)node + 1) = v13;
  *(_QWORD *)&node[8 * v12 - 8] = v13;
  if ( v6 )
  {
    v10 = &node[-16 * (*((_DWORD *)node - 4) & 0xF | 16i64 * (*((_DWORD *)node - 2) & 0xF))];
    v11 = v10 + 8;
    v9 += *(_DWORD *)v10 & 0xF | 16i64 * (*((_DWORD *)v10 + 2) & 0xF);
    Scaleform::HeapMH::ListBinMH::Pull(
      v7,
      &node[-16 * (*((_DWORD *)node - 4) & 0xF | 16i64 * (*((_DWORD *)node - 2) & 0xF))]);
  }
  if ( right )
  {
    v14 = (signed __int64)&v8[16 * (*(_DWORD *)v8 & 0xF | 16i64 * (*((_DWORD *)v8 + 2) & 0xF))];
    v9 += *(_DWORD *)v14 & 0xF | 16i64 * (*(_DWORD *)(v14 + 8) & 0xF);
    Scaleform::HeapMH::ListBinMH::Pull(v7, (char *)v14);
  }
  v15 = 2 * (v9 & 0xFFFFFFFFFFFFFFFi64);
  *(_QWORD *)v10 ^= ((unsigned __int8)v9 ^ (unsigned __int8)*(_QWORD *)v10) & 0xF;
  *(_QWORD *)&v10[8 * v15 - 16] = *(_QWORD *)v10;
  v16 = (v9 >> 4) | *(_QWORD *)v11 & 0xFFFFFFFFFFFFFFF0ui64;
  *(_QWORD *)v11 = v16;
  *(_QWORD *)&v10[8 * v15 - 8] = v16;
  v17 = *(_QWORD *)v11 & 0xFi64;
  v18 = *(_QWORD *)v10 & 0xFi64;
  if ( (v18 | 16 * (unsigned __int64)(*(_DWORD *)v11 & 0xF)) > 2 )
    *((_QWORD *)v10 + 2) = page;
  v19 = 63i64;
  if ( v9 - 1 < 0x3F )
    v19 = v9 - 1;
  v20 = (unsigned __int64)v7->Roots[v19];
  if ( v20 )
  {
    *(_QWORD *)v10 = v20 | v18;
    *(_QWORD *)v11 = v17 | *(_QWORD *)(v20 + 8) & 0xFFFFFFFFFFFFFFF0ui64;
    v21 = (_QWORD *)(*(_QWORD *)(v20 + 8) & 0xFFFFFFFFFFFFFFF0ui64);
    *v21 &= 0xFui64;
    *v21 |= (unsigned __int64)v10;
    *(_QWORD *)(v20 + 8) &= 0xFui64;
    *(_QWORD *)(v20 + 8) |= (unsigned __int64)v10;
  }
  else
  {
    *(_QWORD *)v11 = (unsigned __int64)v10 | v17;
    *(_QWORD *)v10 = (unsigned __int64)v10 | v18;
  }
  v7->Roots[v19] = (Scaleform::HeapMH::BinNodeMH *)v10;
  v7->Mask |= 1i64 << v19;
}

