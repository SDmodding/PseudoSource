// File Line: 15
// RVA: 0xC7D4C0
void __fastcall hkDelayedFreeAllocator::hkDelayedFreeAllocator(hkDelayedFreeAllocator *this)
{
  this->vfptr = (hkMemoryAllocatorVtbl *)&hkDelayedFreeAllocator::`vftable;
  this->m_next = 0i64;
  this->m_kept.m_data = 0i64;
  this->m_kept.m_size = 0;
  this->m_kept.m_capacityAndFlags = 2147483648;
  this->m_limits.m_randomSeed = 0;
  this->m_limits.m_numAllocsKept = 2048;
  this->m_limits.m_maxBytesKept = 5242880;
  *(_QWORD *)&this->m_limits.m_blockTooBig = 0x100000i64;
  this->m_prng.m_current = 0;
}

// File Line: 19
// RVA: 0xC7D510
void __fastcall hkDelayedFreeAllocator::init(hkDelayedFreeAllocator *this, hkMemoryAllocator *next, hkDelayedFreeAllocator::Limits *limits)
{
  int v3; // er9
  hkDelayedFreeAllocator::Limits *v4; // rdi
  hkDelayedFreeAllocator *v5; // rbx
  int v6; // eax
  int *v7; // rcx
  unsigned int v8; // eax
  int v9; // [rsp+30h] [rbp-18h]
  int v10; // [rsp+34h] [rbp-14h]
  int v11; // [rsp+38h] [rbp-10h]
  int v12; // [rsp+3Ch] [rbp-Ch]
  hkResult result; // [rsp+50h] [rbp+8h]

  v3 = this->m_limits.m_numAllocsKept;
  v4 = limits;
  this->m_next = next;
  v5 = this;
  v6 = this->m_kept.m_capacityAndFlags & 0x3FFFFFFF;
  v9 = 0;
  v10 = 2048;
  v11 = 5242880;
  v12 = 0x100000;
  if ( v6 < v3 )
    hkArrayUtil::_reserve(&result, next, &this->m_kept, v3, 16);
  v7 = &v9;
  if ( v4 )
    v7 = &v4->m_randomSeed;
  v5->m_limits.m_randomSeed = *v7;
  v5->m_limits.m_numAllocsKept = v7[1];
  v5->m_limits.m_maxBytesKept = v7[2];
  v5->m_limits.m_blockTooBig = v7[3];
  v8 = v5->m_limits.m_randomSeed;
  v5->m_prng.m_seed = v8;
  *(_QWORD *)&v5->m_prng.m_current = v8;
}

// File Line: 29
// RVA: 0xC7D5B0
void __fastcall hkDelayedFreeAllocator::quit(hkDelayedFreeAllocator *this)
{
  hkDelayedFreeAllocator *v1; // rbx
  int v2; // er8
  hkMemoryAllocator *v3; // rcx

  v1 = this;
  ((void (*)(void))this->vfptr[1].__vecDelDtor)();
  v2 = v1->m_kept.m_capacityAndFlags;
  v3 = v1->m_next;
  v1->m_kept.m_size = 0;
  if ( v2 >= 0 )
    v3->vfptr->bufFree(v3, v1->m_kept.m_data, 16 * v2);
  v1->m_kept.m_data = 0i64;
  v1->m_kept.m_capacityAndFlags = 2147483648;
  v1->m_next = 0i64;
}

// File Line: 36
// RVA: 0xC7D770
void __fastcall hkDelayedFreeAllocator::releaseDelayedFrees(hkDelayedFreeAllocator *this)
{
  hkDelayedFreeAllocator *v1; // rbx
  int v2; // edi
  __int64 v3; // rsi

  v1 = this;
  if ( this->m_next )
  {
    v2 = 0;
    if ( this->m_kept.m_size > 0 )
    {
      v3 = 0i64;
      do
      {
        v1->m_next->vfptr->blockFree(v1->m_next, v1->m_kept.m_data[v3].p, v1->m_kept.m_data[v3].size);
        ++v2;
        ++v3;
      }
      while ( v2 < v1->m_kept.m_size );
    }
    v1->m_kept.m_size = 0;
    v1->m_curBytesKept = 0;
  }
}

// File Line: 50
// RVA: 0xC7D610
__int64 __fastcall hkDelayedFreeAllocator::blockAlloc(hkDelayedFreeAllocator *this, int numBytes)
{
  this->m_inUse += numBytes;
  return (*((__int64 (**)(void))&this->m_next->vfptr->__vecDelDtor + 1))();
}

// File Line: 56
// RVA: 0xC7D960
signed __int64 __fastcall blockOk(const void *p, int size)
{
  __int64 v2; // r8

  v2 = 0i64;
  if ( size / 4 <= 0 )
    return 1i64;
  while ( *((_DWORD *)p + v2) == 65262 )
  {
    if ( ++v2 >= size / 4 )
      return 1i64;
  }
  return 0i64;
}

// File Line: 69
// RVA: 0xC7D630
void __fastcall hkDelayedFreeAllocator::blockFree(hkDelayedFreeAllocator *this, void *pfree, int numBytes)
{
  int v3; // esi
  _DWORD *v4; // rbp
  hkDelayedFreeAllocator *v5; // rbx
  unsigned int v6; // eax
  int v7; // edx
  hkDelayedFreeAllocator::Alloc *v8; // rax
  signed __int64 v9; // rcx
  void *v10; // r10
  __int64 v11; // r9
  __int64 v12; // rdi
  signed __int64 v13; // rdx
  signed __int64 v14; // rdi
  signed __int64 v15; // rax
  signed __int64 v16; // rdi
  __int64 v17; // rcx
  int v18; // er9
  void *v19; // r10
  hkMemoryAllocator *v20; // rcx
  __int64 v21; // rcx
  _DWORD *v22; // rdi
  hkDelayedFreeAllocator::Alloc *v23; // rcx
  __int64 v24; // [rsp+28h] [rbp-10h]

  this->m_inUse -= numBytes;
  v3 = numBytes;
  v4 = pfree;
  v5 = this;
  if ( numBytes <= this->m_limits.m_blockTooBig )
  {
    while ( v3 + v5->m_curBytesKept > v5->m_limits.m_maxBytesKept || v5->m_kept.m_size >= v5->m_limits.m_numAllocsKept )
    {
      v6 = 1664525 * v5->m_prng.m_current + 1013904223;
      v5->m_prng.m_current = v6;
      v7 = v6 % v5->m_kept.m_size;
      v8 = v5->m_kept.m_data;
      v9 = v7;
      v10 = v8[v9].p;
      v11 = *(_QWORD *)&v8[v9].size;
      v12 = --v5->m_kept.m_size;
      if ( (_DWORD)v12 != v7 )
      {
        v13 = 2i64;
        v14 = (signed __int64)&v8[v12];
        v15 = (signed __int64)&v8[v9];
        v16 = v14 - v15;
        do
        {
          v17 = *(_QWORD *)(v16 + v15);
          v15 += 8i64;
          *(_QWORD *)(v15 - 8) = v17;
          --v13;
        }
        while ( v13 );
      }
      if ( !blockOk(v10, v11) )
        __debugbreak();
      v20 = v5->m_next;
      v5->m_curBytesKept -= v18;
      v20->vfptr->blockFree(v20, v19, v18);
    }
    LODWORD(v24) = v3;
    if ( v3 / 4 - 1 >= 0 )
    {
      v21 = v3 / 4;
      v22 = v4;
      while ( v21 )
      {
        *v22 = 65262;
        ++v22;
        --v21;
      }
    }
    v5->m_curBytesKept += v3;
    v23 = &v5->m_kept.m_data[v5->m_kept.m_size];
    if ( v23 )
    {
      v23->p = v4;
      *(_QWORD *)&v23->size = v24;
    }
    ++v5->m_kept.m_size;
  }
  else
  {
    ((void (*)(void))this->m_next->vfptr->blockFree)();
  }
}

// File Line: 120
// RVA: 0xC7D7F0
signed __int64 __fastcall hkDelayedFreeAllocator::isOk(hkDelayedFreeAllocator *this)
{
  hkDelayedFreeAllocator::Alloc *v1; // r9
  hkDelayedFreeAllocator::Alloc *v2; // r9
  __int64 v3; // r10
  signed __int64 v4; // r11

  if ( this->m_kept.m_size <= 0i64 )
    return 1i64;
  v1 = this->m_kept.m_data;
  while ( blockOk(v1->p, v1->size) )
  {
    v1 = v2 + 1;
    if ( v3 + 1 >= v4 )
      return 1i64;
  }
  return 0i64;
}

// File Line: 132
// RVA: 0xC7D840
void __fastcall hkDelayedFreeAllocator::getMemoryStatistics(hkDelayedFreeAllocator *this, hkMemoryAllocator::MemoryStatistics *u)
{
  __int64 v2; // rax

  u->m_allocated = this->m_inUse + this->m_curBytesKept + 16 * this->m_kept.m_capacityAndFlags;
  v2 = this->m_inUse;
  u->m_available = 0i64;
  u->m_inUse = v2;
}

// File Line: 139
// RVA: 0xC7D870
__int64 __fastcall hkDelayedFreeAllocator::getAllocatedSize(hkDelayedFreeAllocator *this, const void *obj, __int64 numBytes)
{
  return this->m_next->vfptr->getAllocatedSize(this->m_next, obj, numBytes);
}

// File Line: 144
// RVA: 0xC7D890
__int64 __fastcall hkDelayedFreeAllocator::addToSnapshot(hkDelayedFreeAllocator *this, hkMemorySnapshot *snapshot, int parentId)
{
  hkMemorySnapshot *v3; // r14
  hkDelayedFreeAllocator *v4; // rbp
  unsigned int v5; // ebx
  int v6; // eax
  int v7; // edi
  __int64 v8; // rsi

  v3 = snapshot;
  v4 = this;
  v5 = hkMemorySnapshot::addProvider(snapshot, "hkDelayedFreeAllocator", parentId);
  v6 = v4->m_kept.m_capacityAndFlags;
  if ( (v6 & 0x3FFFFFFF) <= 0 )
    return v5;
  hkMemorySnapshot::addItem(v3, v5, 0, v4->m_kept.m_data, 16 * v6);
  v7 = 0;
  if ( v4->m_kept.m_size <= 0 )
    return v5;
  v8 = 0i64;
  do
  {
    hkMemorySnapshot::addItem(v3, v5, 0, v4->m_kept.m_data[v8].p, v4->m_kept.m_data[v8].size);
    ++v7;
    ++v8;
  }
  while ( v7 < v4->m_kept.m_size );
  return v5;
}

