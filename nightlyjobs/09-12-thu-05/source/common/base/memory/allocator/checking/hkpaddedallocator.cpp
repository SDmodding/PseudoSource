// File Line: 13
// RVA: 0xC7D0B0
void __fastcall hkPaddedAllocator::hkPaddedAllocator(hkPaddedAllocator *this)
{
  this->m_next = 0i64;
  this->vfptr = (hkMemoryAllocatorVtbl *)&hkPaddedAllocator::`vftable';
  this->m_cinfo.m_numQuadsPad = 1;
  this->m_cinfo.m_padPattern = 2147331501;
  this->m_cinfo.m_bodyPattern = 2147094796;
  this->m_cinfo.m_alignPattern = 22;
  this->m_cinfo.m_freePattern = 2147479535;
}

// File Line: 17
// RVA: 0xC7D0F0
void __fastcall hkPaddedAllocator::init(hkPaddedAllocator *this, hkMemoryAllocator *next, hkPaddedAllocator::Cinfo *cinfoPtr)
{
  hkPaddedAllocator::Cinfo *v3; // rdx
  int v4; // [rsp+0h] [rbp-28h]
  int v5; // [rsp+4h] [rbp-24h]
  int v6; // [rsp+8h] [rbp-20h]
  char v7; // [rsp+Ch] [rbp-1Ch]
  int v8; // [rsp+10h] [rbp-18h]

  this->m_next = next;
  v4 = 1;
  v5 = 2147331501;
  v6 = 2147094796;
  v7 = 22;
  v8 = 2147479535;
  v3 = (hkPaddedAllocator::Cinfo *)&v4;
  if ( cinfoPtr )
    v3 = cinfoPtr;
  this->m_cinfo.m_numQuadsPad = v3->m_numQuadsPad;
  this->m_cinfo.m_padPattern = v3->m_padPattern;
  this->m_cinfo.m_bodyPattern = v3->m_bodyPattern;
  *(_DWORD *)&this->m_cinfo.m_alignPattern = *(_DWORD *)&v3->m_alignPattern;
  this->m_cinfo.m_freePattern = v3->m_freePattern;
}

// File Line: 25
// RVA: 0xC7D150
void __fastcall hkPaddedAllocator::quit(hkPaddedAllocator *this)
{
  this->m_next = 0i64;
}

// File Line: 30
// RVA: 0xC7D160
unsigned int *__fastcall hkPaddedAllocator::blockAlloc(hkPaddedAllocator *this, int numBytes)
{
  int v2; // er14
  __int64 v3; // r13
  hkPaddedAllocator *v4; // rsi
  unsigned int v5; // er14
  unsigned int v6; // er12
  __int64 v7; // rax
  unsigned __int64 v8; // rdx
  unsigned int *v9; // rbp
  unsigned int v10; // eax
  __int64 v11; // rcx
  unsigned int *v12; // rdi
  __int64 v13; // rcx
  unsigned int v14; // eax
  unsigned int *v15; // rdi
  int v16; // edx
  int *v17; // rdi
  __int64 v18; // rcx

  v2 = this->m_cinfo.m_numQuadsPad;
  v3 = numBytes;
  v4 = this;
  this->m_inUse += numBytes;
  v5 = 16 * v2;
  v6 = (numBytes + 15) & 0xFFFFFFF0;
  this->m_allocated += v6 + 2 * v5;
  v7 = (*((__int64 (**)(void))&this->m_next->vfptr->__vecDelDtor + 1))();
  v8 = (unsigned __int64)(v3 + 3) >> 2;
  v9 = (unsigned int *)v7;
  if ( (signed int)((v5 >> 2) - 1) >= 0 )
  {
    v10 = v4->m_cinfo.m_padPattern;
    v11 = v5 >> 2;
    v12 = v9;
    while ( v11 )
    {
      *v12 = v10;
      ++v12;
      --v11;
    }
  }
  if ( (signed int)v8 - 1 >= 0 )
  {
    v13 = (unsigned int)v8;
    v14 = v4->m_cinfo.m_bodyPattern;
    v15 = &v9[v5 / 4];
    while ( v13 )
    {
      *v15 = v14;
      ++v15;
      --v13;
    }
  }
  hkString::memSet((char *)&v9[v5 / 4] + (unsigned int)v3, (unsigned __int8)v4->m_cinfo.m_alignPattern, v6 - v3);
  v17 = (int *)((char *)&v9[v5 / 4] + v6);
  if ( (signed int)((v5 >> 2) - 1) >= 0 )
  {
    v18 = v5 >> 2;
    v16 = v4->m_cinfo.m_padPattern + 1;
    while ( v18 )
    {
      *v17 = v16;
      ++v17;
      --v18;
    }
  }
  return &v9[v5 / 4];
}

// File Line: 56
// RVA: 0xC7D240
void __fastcall hkPaddedAllocator::blockFree(hkPaddedAllocator *this, void *p, int numBytes)
{
  int v3; // er15
  hkPaddedAllocator *v4; // r9
  int v5; // ebp
  signed int v6; // er14
  __int64 v7; // rcx
  _BYTE *v8; // r11
  char *v9; // rax
  char *v10; // rbx
  unsigned int v11; // edi
  signed __int64 v12; // rdx
  signed __int64 i; // rax
  __int64 v14; // rcx
  unsigned int v15; // eax
  _DWORD *v16; // rdi

  v3 = this->m_cinfo.m_numQuadsPad;
  v4 = this;
  v5 = 16 * this->m_cinfo.m_numQuadsPad;
  v6 = (numBytes + 15) & 0xFFFFFFF0;
  v7 = (unsigned int)(4 * v3);
  v8 = p;
  v9 = (char *)p + v6;
  v10 = (char *)p - v5;
  if ( (signed int)v7 > 0 )
  {
    v11 = v4->m_cinfo.m_padPattern;
    v12 = v10 - v9;
    do
    {
      if ( *(_DWORD *)&v9[v12] != v11 )
        __debugbreak();
      if ( *(_DWORD *)v9 != v11 + 1 )
        __debugbreak();
      v9 += 4;
      --v7;
    }
    while ( v7 );
  }
  for ( i = numBytes; i < v6; ++i )
  {
    if ( v8[i] != v4->m_cinfo.m_alignPattern )
      __debugbreak();
  }
  v4->m_inUse -= numBytes;
  v4->m_allocated -= v6 + 2 * v5;
  if ( 8 * v3 - 1 >= 0 )
  {
    v14 = (unsigned int)(8 * v3);
    v15 = v4->m_cinfo.m_freePattern;
    v16 = v10;
    while ( v14 )
    {
      *v16 = v15;
      ++v16;
      --v14;
    }
  }
  ((void (__fastcall *)(hkMemoryAllocator *, char *))v4->m_next->vfptr->blockFree)(v4->m_next, v10);
}

// File Line: 91
// RVA: 0xC7D330
signed __int64 __fastcall hkPaddedAllocator::isOk(hkPaddedAllocator *this, const void *p, int numBytes)
{
  int v3; // er10
  __int64 v4; // rbp
  _BYTE *v5; // rdi
  hkPaddedAllocator *v6; // rsi
  int v7; // eax
  signed __int64 v8; // rcx
  __int64 v9; // r11
  char *v10; // rbx
  char *v11; // rdx
  unsigned int v12; // er8
  signed __int64 v13; // rbx
  __int64 v14; // rax

  v3 = this->m_cinfo.m_numQuadsPad;
  v4 = numBytes;
  v5 = p;
  v6 = this;
  v7 = -this->m_cinfo.m_numQuadsPad;
  v8 = 0i64;
  v9 = (signed int)((numBytes + 15) & 0xFFFFFFF0);
  v10 = (char *)p + 16 * v7;
  v11 = (char *)p + v9;
  if ( 4 * v3 <= 0 )
  {
LABEL_6:
    v14 = v4;
    if ( v4 >= v9 )
      return 1i64;
    while ( v5[v14] == v6->m_cinfo.m_alignPattern )
    {
      if ( ++v14 >= v9 )
        return 1i64;
    }
  }
  else
  {
    v12 = v6->m_cinfo.m_padPattern;
    v13 = v10 - v11;
    while ( *(_DWORD *)&v11[v13] == v12 && *(_DWORD *)v11 == v12 + 1 )
    {
      ++v8;
      v11 += 4;
      if ( v8 >= 4 * v3 )
        goto LABEL_6;
    }
  }
  return 0i64;
}

// File Line: 124
// RVA: 0xC7D3F0
void __fastcall hkPaddedAllocator::getMemoryStatistics(hkPaddedAllocator *this, hkMemoryAllocator::MemoryStatistics *u)
{
  hkPaddedAllocator *v2; // rbx
  hkMemoryAllocator::MemoryStatistics *v3; // rdi

  v2 = this;
  v3 = u;
  ((void (*)(void))this->m_next->vfptr->getMemoryStatistics)();
  v3->m_allocated = v2->m_allocated;
  v3->m_inUse = v2->m_inUse;
  v3->m_available = 0i64;
}

// File Line: 132
// RVA: 0xC7D490
hkPaddedAllocator::Allocation *__fastcall hkPaddedAllocator::getUnderlyingAllocation(hkPaddedAllocator *this, hkPaddedAllocator::Allocation *result, const void *obj, int numBytes)
{
  int v4; // er10

  v4 = 16 * this->m_cinfo.m_numQuadsPad;
  result->address = (char *)obj - 16 * this->m_cinfo.m_numQuadsPad;
  result->size = ((numBytes + 15) & 0xFFFFFFF0) + 2 * v4;
  return result;
}

// File Line: 142
// RVA: 0xC7D440
__int64 __fastcall hkPaddedAllocator::getAllocatedSize(hkPaddedAllocator *this, const void *obj, int numBytes)
{
  int v3; // ebx

  v3 = 32 * this->m_cinfo.m_numQuadsPad;
  return (unsigned int)this->m_next->vfptr->getAllocatedSize(
                         this->m_next,
                         (char *)obj - 16 * this->m_cinfo.m_numQuadsPad,
                         v3 + ((numBytes + 15) & 0xFFFFFFF0))
       - v3;
}

// File Line: 150
// RVA: 0xC7D480
void __fastcall hkPaddedAllocator::setScrubValues(hkPaddedAllocator *this, unsigned int bodyValue, unsigned int freeValue)
{
  this->m_cinfo.m_bodyPattern = bodyValue;
  this->m_cinfo.m_freePattern = freeValue;
}

