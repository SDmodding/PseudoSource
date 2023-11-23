// File Line: 112
// RVA: 0x9A1BE0
unsigned __int64 __fastcall Scaleform::HeapMH::ListBinMH::PullBest(
        Scaleform::HeapMH::ListBinMH *this,
        unsigned __int64 blocks)
{
  unsigned __int64 v2; // rdx
  __int64 v3; // rdi
  unsigned __int64 result; // rax
  __int64 v6; // rcx
  unsigned __int64 *v7; // r8
  _QWORD *v8; // rdx
  unsigned __int64 v9; // rax

  v2 = blocks - 1;
  v3 = 63i64;
  if ( v2 < 0x3F )
    v3 = v2;
  result = this->Mask >> v3;
  if ( result )
  {
    v6 = v3 + (unsigned __int8)Scaleform::Alg::LowerBit(result);
    v7 = &this->Mask + v6;
    v8 = (_QWORD *)v7[1];
    v9 = v8[1] & 0xFFFFFFFFFFFFFFF0ui64;
    if ( v8 == (_QWORD *)v9 )
    {
      v7[1] = 0i64;
      this->Mask &= ~(1i64 << v6);
    }
    else
    {
      v7[1] = v9;
      *(_QWORD *)((*v8 & 0xFFFFFFFFFFFFFFF0ui64) + 8) = v8[1] ^ (*((_DWORD *)v8 + 2) ^ *(_DWORD *)((*v8 & 0xFFFFFFFFFFFFFFF0ui64)
                                                                                                 + 8)) & 0xF;
      *(_QWORD *)(v8[1] & 0xFFFFFFFFFFFFFFF0ui64) = *v8 ^ (*(_DWORD *)(v8[1] & 0xFFFFFFFFFFFFFFF0ui64) ^ *(_DWORD *)v8) & 0xF;
    }
    return (unsigned __int64)v8;
  }
  return result;
}

// File Line: 131
// RVA: 0x9A1A70
unsigned __int64 __fastcall Scaleform::HeapMH::ListBinMH::PullBest(
        Scaleform::HeapMH::ListBinMH *this,
        unsigned __int64 blocks,
        unsigned __int64 alignMask)
{
  __int64 v3; // rbx
  unsigned __int64 result; // rax
  __int64 v8; // r10
  Scaleform::HeapMH::BinNodeMH **i; // rdi
  unsigned __int64 v10; // r9
  Scaleform::HeapMH::BinNodeMH *v11; // rdx
  unsigned __int64 *v12; // r8
  unsigned __int64 v13; // rdx
  unsigned __int64 v14; // rcx
  unsigned __int64 v15; // rcx

  v3 = 63i64;
  if ( blocks - 1 < 0x3F )
    v3 = blocks - 1;
  result = this->Mask >> v3;
  if ( result )
  {
    v8 = v3 + (unsigned __int8)Scaleform::Alg::LowerBit(result);
    for ( i = &this->Roots[v8]; ; ++i )
    {
      result = (unsigned __int64)*i;
      if ( *i )
        break;
LABEL_8:
      if ( (unsigned __int64)++v8 >= 0x40 )
        return 0i64;
    }
    while ( 1 )
    {
      v10 = *(_QWORD *)(result + 8);
      if ( 16 * blocks + (~alignMask & (result + alignMask)) <= result
                                                              + 16 * (*(_DWORD *)result & 0xF | (16 * (v10 & 0xF))) )
        break;
      result = v10 & 0xFFFFFFFFFFFFFFF0ui64;
      if ( (Scaleform::HeapMH::BinNodeMH *)(v10 & 0xFFFFFFFFFFFFFFF0ui64) == *i )
        goto LABEL_8;
    }
    v11 = this->Roots[v8];
    v12 = &this->Mask + v8;
    if ( (Scaleform::HeapMH::BinNodeMH *)result != v11 )
    {
      v13 = *(_QWORD *)result & 0xFFFFFFFFFFFFFFF0ui64;
      v14 = v10 ^ (*(_DWORD *)(v13 + 8) ^ (unsigned int)v10) & 0xF;
LABEL_14:
      *(_QWORD *)(v13 + 8) = v14;
      *(_QWORD *)(*(_QWORD *)(result + 8) & 0xFFFFFFFFFFFFFFF0ui64) = *(_QWORD *)result ^ (*(_DWORD *)(*(_QWORD *)(result + 8) & 0xFFFFFFFFFFFFFFF0ui64) ^ *(_DWORD *)result) & 0xF;
      return result;
    }
    v15 = v11->Next & 0xFFFFFFFFFFFFFFF0ui64;
    if ( v11 != (Scaleform::HeapMH::BinNodeMH *)v15 )
    {
      v12[1] = v15;
      v13 = *(_QWORD *)result & 0xFFFFFFFFFFFFFFF0ui64;
      v14 = *(_QWORD *)(result + 8) ^ (*(_DWORD *)(v13 + 8) ^ *(_DWORD *)(result + 8)) & 0xF;
      goto LABEL_14;
    }
    v12[1] = 0i64;
    this->Mask &= ~(1i64 << v8);
  }
  return result;
}

// File Line: 162
// RVA: 0x9A1F10
void __fastcall Scaleform::HeapMH::ListBinMH::Push(
        Scaleform::HeapMH::ListBinMH *this,
        Scaleform::HeapMH::BinNodeMH *node)
{
  __int64 v2; // r11
  __int64 v3; // r9
  __int64 v4; // r8
  unsigned __int64 v6; // rcx
  _QWORD *v7; // rax

  v2 = 63i64;
  v3 = node->Next & 0xF;
  v4 = node->Prev & 0xF;
  if ( (v4 | (16 * (unsigned __int64)(node->Next & 0xF))) - 1 < 0x3F )
    v2 = (v4 | (16i64 * (node->Next & 0xF))) - 1;
  v6 = (unsigned __int64)this->Roots[v2];
  if ( v6 )
  {
    node->Prev = v6 | v4;
    node->Next = v3 | *(_QWORD *)(v6 + 8) & 0xFFFFFFFFFFFFFFF0ui64;
    v7 = (_QWORD *)(*(_QWORD *)(v6 + 8) & 0xFFFFFFFFFFFFFFF0ui64);
    *v7 &= 0xFui64;
    *v7 |= (unsigned __int64)node;
    *(_QWORD *)(v6 + 8) &= 0xFui64;
    *(_QWORD *)(v6 + 8) |= (unsigned __int64)node;
  }
  else
  {
    node->Next = (unsigned __int64)node | v3;
    node->Prev = (unsigned __int64)node | v4;
  }
  this->Roots[v2] = node;
  this->Mask |= 1i64 << v2;
}

// File Line: 171
// RVA: 0x9A1560
void __fastcall Scaleform::HeapMH::ListBinMH::Pull(Scaleform::HeapMH::ListBinMH *this, char *node)
{
  __int64 v2; // r11
  __int64 v3; // rbx
  __int64 v5; // rax
  unsigned __int64 *v6; // r8
  unsigned __int64 v7; // rcx
  unsigned __int64 v8; // r9
  unsigned __int64 v9; // rax

  v2 = *((_QWORD *)node + 1);
  v3 = 63i64;
  v5 = *(_QWORD *)node & 0xFi64;
  if ( (v5 | (16 * (unsigned __int64)(v2 & 0xF))) - 1 < 0x3F )
    v3 = (v5 | (16 * (*((_QWORD *)node + 1) & 0xFi64))) - 1;
  v6 = &this->Mask + v3;
  v7 = v6[1];
  if ( node == (char *)v7 )
  {
    v9 = *(_QWORD *)(v7 + 8) & 0xFFFFFFFFFFFFFFF0ui64;
    if ( v7 == v9 )
    {
      v6[1] = 0i64;
      this->Mask &= ~(1i64 << v3);
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
void __fastcall Scaleform::HeapMH::ListBinMH::Merge(
        Scaleform::HeapMH::ListBinMH *this,
        char *node,
        unsigned __int64 bytes,
        bool left,
        bool right,
        Scaleform::HeapMH::PageMH *page)
{
  unsigned __int64 v9; // rdi
  unsigned __int64 v10; // rbx
  char *v11; // r15
  unsigned __int64 v12; // r9
  unsigned __int64 v13; // rcx
  char *v14; // rdx
  __int64 v15; // rdx
  unsigned __int64 v16; // rcx
  __int64 v17; // r8
  __int64 v18; // rdx
  __int64 v19; // r9
  unsigned __int64 v20; // rcx
  _QWORD *v21; // rax

  v9 = bytes >> 4;
  v10 = (unsigned __int64)node;
  v11 = node + 8;
  *(_QWORD *)node ^= ((unsigned __int8)(bytes >> 4) ^ (unsigned __int8)*(_QWORD *)node) & 0xF;
  v12 = 2 * (bytes >> 4);
  *(_QWORD *)&node[8 * v12 - 16] = *(_QWORD *)node;
  v13 = (bytes >> 8) | *((_QWORD *)node + 1) & 0xFFFFFFFFFFFFFFF0ui64;
  *((_QWORD *)node + 1) = v13;
  *(_QWORD *)&node[8 * v12 - 8] = v13;
  if ( left )
  {
    v10 = (unsigned __int64)&node[-16 * (*((_DWORD *)node - 4) & 0xF | (16i64 * (*((_DWORD *)node - 2) & 0xF)))];
    v11 = (char *)(v10 + 8);
    v9 += *(_DWORD *)v10 & 0xF | (16i64 * (*(_DWORD *)(v10 + 8) & 0xF));
    Scaleform::HeapMH::ListBinMH::Pull(this, (char *)v10);
  }
  if ( right )
  {
    v14 = &node[16 * (*(_DWORD *)node & 0xF | (16i64 * (*((_DWORD *)node + 2) & 0xF)))];
    v9 += *(_DWORD *)v14 & 0xF | (16i64 * (*((_DWORD *)v14 + 2) & 0xF));
    Scaleform::HeapMH::ListBinMH::Pull(this, v14);
  }
  v15 = 2 * (v9 & 0xFFFFFFFFFFFFFFFi64);
  *(_QWORD *)v10 ^= ((unsigned __int8)v9 ^ (unsigned __int8)*(_QWORD *)v10) & 0xF;
  *(_QWORD *)(v10 + 8 * v15 - 16) = *(_QWORD *)v10;
  v16 = (v9 >> 4) | *(_QWORD *)v11 & 0xFFFFFFFFFFFFFFF0ui64;
  *(_QWORD *)v11 = v16;
  *(_QWORD *)(v10 + 8 * v15 - 8) = v16;
  v17 = *(_QWORD *)v11 & 0xFi64;
  v18 = *(_QWORD *)v10 & 0xFi64;
  if ( (v18 | (16 * (unsigned __int64)(*(_DWORD *)v11 & 0xF))) > 2 )
    *(_QWORD *)(v10 + 16) = page;
  v19 = 63i64;
  if ( v9 - 1 < 0x3F )
    v19 = v9 - 1;
  v20 = (unsigned __int64)this->Roots[v19];
  if ( v20 )
  {
    *(_QWORD *)v10 = v20 | v18;
    *(_QWORD *)v11 = v17 | *(_QWORD *)(v20 + 8) & 0xFFFFFFFFFFFFFFF0ui64;
    v21 = (_QWORD *)(*(_QWORD *)(v20 + 8) & 0xFFFFFFFFFFFFFFF0ui64);
    *v21 &= 0xFui64;
    *v21 |= v10;
    *(_QWORD *)(v20 + 8) &= 0xFui64;
    *(_QWORD *)(v20 + 8) |= v10;
  }
  else
  {
    *(_QWORD *)v11 = v10 | v17;
    *(_QWORD *)v10 = v10 | v18;
  }
  this->Roots[v19] = (Scaleform::HeapMH::BinNodeMH *)v10;
  this->Mask |= 1i64 << v19;
}

