// File Line: 15
// RVA: 0xC7D4C0
void __fastcall hkDelayedFreeAllocator::hkDelayedFreeAllocator(hkDelayedFreeAllocator *this)
{
  this->vfptr = (hkMemoryAllocatorVtbl *)&hkDelayedFreeAllocator::`vftable;
  this->m_next = 0i64;
  this->m_kept.m_data = 0i64;
  this->m_kept.m_size = 0;
  this->m_kept.m_capacityAndFlags = 0x80000000;
  this->m_limits.m_randomSeed = 0;
  this->m_limits.m_numAllocsKept = 2048;
  this->m_limits.m_maxBytesKept = 5242880;
  *(_QWORD *)&this->m_limits.m_blockTooBig = 0x100000i64;
  this->m_prng.m_current = 0;
}

// File Line: 19
// RVA: 0xC7D510
void __fastcall hkDelayedFreeAllocator::init(
        hkDelayedFreeAllocator *this,
        hkMemoryAllocator *next,
        hkDelayedFreeAllocator::Limits *limits)
{
  int m_numAllocsKept; // r9d
  int v6; // eax
  hkDelayedFreeAllocator::Limits *v7; // rcx
  unsigned int m_randomSeed; // eax
  int v9[6]; // [rsp+30h] [rbp-18h] BYREF
  hkResult result; // [rsp+50h] [rbp+8h] BYREF

  m_numAllocsKept = this->m_limits.m_numAllocsKept;
  this->m_next = next;
  v6 = this->m_kept.m_capacityAndFlags & 0x3FFFFFFF;
  v9[0] = 0;
  v9[1] = 2048;
  v9[2] = 5242880;
  v9[3] = 0x100000;
  if ( v6 < m_numAllocsKept )
    hkArrayUtil::_reserve(&result, next, (const void **)&this->m_kept.m_data, m_numAllocsKept, 16);
  v7 = (hkDelayedFreeAllocator::Limits *)v9;
  if ( limits )
    v7 = limits;
  this->m_limits.m_randomSeed = v7->m_randomSeed;
  this->m_limits.m_numAllocsKept = v7->m_numAllocsKept;
  this->m_limits.m_maxBytesKept = v7->m_maxBytesKept;
  this->m_limits.m_blockTooBig = v7->m_blockTooBig;
  m_randomSeed = this->m_limits.m_randomSeed;
  this->m_prng.m_seed = m_randomSeed;
  *(_QWORD *)&this->m_prng.m_current = m_randomSeed;
}

// File Line: 29
// RVA: 0xC7D5B0
void __fastcall hkDelayedFreeAllocator::quit(hkDelayedFreeAllocator *this)
{
  int m_capacityAndFlags; // r8d
  hkMemoryAllocator *m_next; // rcx

  ((void (__fastcall *)(hkDelayedFreeAllocator *))this->vfptr[1].__vecDelDtor)(this);
  m_capacityAndFlags = this->m_kept.m_capacityAndFlags;
  m_next = this->m_next;
  this->m_kept.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    m_next->vfptr->bufFree(m_next, this->m_kept.m_data, 16 * m_capacityAndFlags);
  this->m_kept.m_data = 0i64;
  this->m_kept.m_capacityAndFlags = 0x80000000;
  this->m_next = 0i64;
}

// File Line: 36
// RVA: 0xC7D770
void __fastcall hkDelayedFreeAllocator::releaseDelayedFrees(hkDelayedFreeAllocator *this)
{
  int v2; // edi
  __int64 v3; // rsi

  if ( this->m_next )
  {
    v2 = 0;
    if ( this->m_kept.m_size > 0 )
    {
      v3 = 0i64;
      do
      {
        this->m_next->vfptr->blockFree(this->m_next, this->m_kept.m_data[v3].p, this->m_kept.m_data[v3].size);
        ++v2;
        ++v3;
      }
      while ( v2 < this->m_kept.m_size );
    }
    this->m_kept.m_size = 0;
    this->m_curBytesKept = 0;
  }
}

// File Line: 50
// RVA: 0xC7D610
__int64 __fastcall hkDelayedFreeAllocator::blockAlloc(hkDelayedFreeAllocator *this, int numBytes)
{
  this->m_inUse += numBytes;
  return (*((__int64 (__fastcall **)(hkMemoryAllocator *))&this->m_next->vfptr->__vecDelDtor + 1))(this->m_next);
}

// File Line: 56
// RVA: 0xC7D960
__int64 __fastcall blockOk(_DWORD *p, int size)
{
  __int64 v2; // r8

  v2 = 0i64;
  if ( size / 4 <= 0 )
    return 1i64;
  while ( p[v2] == 65262 )
  {
    if ( ++v2 >= size / 4 )
      return 1i64;
  }
  return 0i64;
}

// File Line: 69
// RVA: 0xC7D630
void __fastcall hkDelayedFreeAllocator::blockFree(hkDelayedFreeAllocator *this, _DWORD *pfree, int numBytes)
{
  unsigned int v6; // eax
  int v7; // edx
  hkDelayedFreeAllocator::Alloc *m_data; // rax
  __int64 v9; // rcx
  void *p; // r10
  __int64 v11; // r9
  __int64 v12; // rdi
  __int64 v13; // rdx
  hkDelayedFreeAllocator::Alloc *v14; // rdi
  hkDelayedFreeAllocator::Alloc *v15; // rax
  signed __int64 v16; // rdi
  __int64 v17; // rcx
  int v18; // r9d
  void *v19; // r10
  hkMemoryAllocator *m_next; // rcx
  __int64 v21; // rcx
  _DWORD *v22; // rdi
  hkDelayedFreeAllocator::Alloc *v23; // rcx
  __int64 v24; // [rsp+28h] [rbp-10h]

  this->m_inUse -= numBytes;
  if ( numBytes <= this->m_limits.m_blockTooBig )
  {
    while ( numBytes + this->m_curBytesKept > this->m_limits.m_maxBytesKept
         || this->m_kept.m_size >= this->m_limits.m_numAllocsKept )
    {
      v6 = 1664525 * this->m_prng.m_current + 1013904223;
      this->m_prng.m_current = v6;
      v7 = v6 % this->m_kept.m_size;
      m_data = this->m_kept.m_data;
      v9 = v7;
      p = m_data[v9].p;
      v11 = *(_QWORD *)&m_data[v9].size;
      v12 = --this->m_kept.m_size;
      if ( (_DWORD)v12 != v7 )
      {
        v13 = 2i64;
        v14 = &m_data[v12];
        v15 = &m_data[v9];
        v16 = (char *)v14 - (char *)v15;
        do
        {
          v17 = *(__int64 *)((char *)&v15->p + v16);
          v15 = (hkDelayedFreeAllocator::Alloc *)((char *)v15 + 8);
          *(_QWORD *)&v15[-1].size = v17;
          --v13;
        }
        while ( v13 );
      }
      if ( !blockOk(p, v11) )
        __debugbreak();
      m_next = this->m_next;
      this->m_curBytesKept -= v18;
      m_next->vfptr->blockFree(m_next, v19, v18);
    }
    LODWORD(v24) = numBytes;
    if ( numBytes / 4 - 1 >= 0 )
    {
      v21 = (unsigned int)(numBytes / 4);
      v22 = pfree;
      while ( v21 )
      {
        *v22++ = 65262;
        --v21;
      }
    }
    this->m_curBytesKept += numBytes;
    v23 = &this->m_kept.m_data[this->m_kept.m_size];
    if ( v23 )
    {
      v23->p = pfree;
      *(_QWORD *)&v23->size = v24;
    }
    ++this->m_kept.m_size;
  }
  else
  {
    ((void (__fastcall *)(hkMemoryAllocator *))this->m_next->vfptr->blockFree)(this->m_next);
  }
}

// File Line: 120
// RVA: 0xC7D7F0
__int64 __fastcall hkDelayedFreeAllocator::isOk(hkDelayedFreeAllocator *this)
{
  hkDelayedFreeAllocator::Alloc *m_data; // r9
  hkDelayedFreeAllocator::Alloc *v2; // r9
  __int64 v3; // r10
  __int64 v4; // r11

  if ( this->m_kept.m_size <= 0i64 )
    return 1i64;
  m_data = this->m_kept.m_data;
  while ( blockOk(m_data->p, m_data->size) )
  {
    m_data = v2 + 1;
    if ( v3 + 1 >= v4 )
      return 1i64;
  }
  return 0i64;
}

// File Line: 132
// RVA: 0xC7D840
void __fastcall hkDelayedFreeAllocator::getMemoryStatistics(
        hkDelayedFreeAllocator *this,
        hkMemoryAllocator::MemoryStatistics *u)
{
  __int64 m_inUse; // rax

  u->m_allocated = this->m_inUse + this->m_curBytesKept + 16 * this->m_kept.m_capacityAndFlags;
  m_inUse = this->m_inUse;
  u->m_available = 0i64;
  u->m_inUse = m_inUse;
}

// File Line: 139
// RVA: 0xC7D870
__int64 __fastcall hkDelayedFreeAllocator::getAllocatedSize(
        hkDelayedFreeAllocator *this,
        const void *obj,
        __int64 numBytes)
{
  return ((__int64 (__fastcall *)(hkMemoryAllocator *, const void *, __int64))this->m_next->vfptr->getAllocatedSize)(
           this->m_next,
           obj,
           numBytes);
}

// File Line: 144
// RVA: 0xC7D890
__int64 __fastcall hkDelayedFreeAllocator::addToSnapshot(
        hkDelayedFreeAllocator *this,
        hkMemorySnapshot *snapshot,
        int parentId)
{
  unsigned int v5; // ebx
  int m_capacityAndFlags; // eax
  int v7; // edi
  __int64 v8; // rsi

  v5 = hkMemorySnapshot::addProvider(snapshot, "hkDelayedFreeAllocator", parentId);
  m_capacityAndFlags = this->m_kept.m_capacityAndFlags;
  if ( (m_capacityAndFlags & 0x3FFFFFFF) == 0 )
    return v5;
  hkMemorySnapshot::addItem(snapshot, v5, 0, this->m_kept.m_data, 16 * m_capacityAndFlags);
  v7 = 0;
  if ( this->m_kept.m_size <= 0 )
    return v5;
  v8 = 0i64;
  do
  {
    hkMemorySnapshot::addItem(snapshot, v5, 0, this->m_kept.m_data[v8].p, this->m_kept.m_data[v8].size);
    ++v7;
    ++v8;
  }
  while ( v7 < this->m_kept.m_size );
  return v5;
}

