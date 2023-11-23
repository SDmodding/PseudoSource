// File Line: 13
// RVA: 0xC7D0B0
void __fastcall hkPaddedAllocator::hkPaddedAllocator(hkPaddedAllocator *this)
{
  this->m_next = 0i64;
  this->vfptr = (hkMemoryAllocatorVtbl *)&hkPaddedAllocator::`vftable;
  this->m_cinfo.m_numQuadsPad = 1;
  this->m_cinfo.m_padPattern = 2147331501;
  this->m_cinfo.m_bodyPattern = 2147094796;
  this->m_cinfo.m_alignPattern = 22;
  this->m_cinfo.m_freePattern = 2147479535;
}

// File Line: 17
// RVA: 0xC7D0F0
void __fastcall hkPaddedAllocator::init(
        hkPaddedAllocator *this,
        hkMemoryAllocator *next,
        hkPaddedAllocator::Cinfo *cinfoPtr)
{
  hkPaddedAllocator::Cinfo *v3; // rdx
  int v4[3]; // [rsp+0h] [rbp-28h] BYREF
  char v5; // [rsp+Ch] [rbp-1Ch]
  int v6; // [rsp+10h] [rbp-18h]

  this->m_next = next;
  v4[0] = 1;
  v4[1] = 2147331501;
  v4[2] = 2147094796;
  v5 = 22;
  v6 = 2147479535;
  v3 = (hkPaddedAllocator::Cinfo *)v4;
  if ( cinfoPtr )
    v3 = cinfoPtr;
  this->m_cinfo = *v3;
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
  int m_numQuadsPad; // r14d
  __int64 v3; // r13
  unsigned int v5; // r14d
  unsigned int v6; // r12d
  __int64 v7; // rax
  unsigned __int64 v8; // rdx
  unsigned int *v9; // rbp
  unsigned int m_padPattern; // eax
  __int64 v11; // rcx
  unsigned int *v12; // rdi
  __int64 v13; // rcx
  unsigned int m_bodyPattern; // eax
  unsigned int *v15; // rdi
  unsigned int v16; // edx
  unsigned int *v17; // rdi
  __int64 v18; // rcx

  m_numQuadsPad = this->m_cinfo.m_numQuadsPad;
  v3 = numBytes;
  this->m_inUse += numBytes;
  v5 = 16 * m_numQuadsPad;
  v6 = (numBytes + 15) & 0xFFFFFFF0;
  this->m_allocated += v6 + 2 * v5;
  v7 = (*((__int64 (__fastcall **)(hkMemoryAllocator *))&this->m_next->vfptr->__vecDelDtor + 1))(this->m_next);
  v8 = (unsigned __int64)(v3 + 3) >> 2;
  v9 = (unsigned int *)v7;
  if ( (int)((v5 >> 2) - 1) >= 0 )
  {
    m_padPattern = this->m_cinfo.m_padPattern;
    v11 = v5 >> 2;
    v12 = v9;
    while ( v11 )
    {
      *v12++ = m_padPattern;
      --v11;
    }
  }
  if ( (int)v8 - 1 >= 0 )
  {
    v13 = (unsigned int)v8;
    m_bodyPattern = this->m_cinfo.m_bodyPattern;
    v15 = &v9[v5 / 4];
    while ( v13 )
    {
      *v15++ = m_bodyPattern;
      --v13;
    }
  }
  hkString::memSet((char *)&v9[v5 / 4] + (unsigned int)v3, (unsigned __int8)this->m_cinfo.m_alignPattern, v6 - v3);
  v17 = (unsigned int *)((char *)&v9[v5 / 4] + v6);
  if ( (int)((v5 >> 2) - 1) >= 0 )
  {
    v18 = v5 >> 2;
    v16 = this->m_cinfo.m_padPattern + 1;
    while ( v18 )
    {
      *v17++ = v16;
      --v18;
    }
  }
  return &v9[v5 / 4];
}

// File Line: 56
// RVA: 0xC7D240
void __fastcall hkPaddedAllocator::blockFree(hkPaddedAllocator *this, _BYTE *p, int numBytes)
{
  int m_numQuadsPad; // r15d
  signed int v5; // r14d
  __int64 v6; // rcx
  char *v8; // rax
  unsigned int *v9; // rbx
  unsigned int m_padPattern; // edi
  signed __int64 v11; // rdx
  __int64 v12; // rax
  __int64 v13; // rcx
  unsigned int m_freePattern; // eax
  unsigned int *v15; // rdi

  m_numQuadsPad = this->m_cinfo.m_numQuadsPad;
  v5 = (numBytes + 15) & 0xFFFFFFF0;
  v6 = (unsigned int)(4 * m_numQuadsPad);
  v8 = &p[v5];
  v9 = (unsigned int *)&p[-16 * m_numQuadsPad];
  if ( (int)v6 > 0 )
  {
    m_padPattern = this->m_cinfo.m_padPattern;
    v11 = (char *)v9 - v8;
    do
    {
      if ( *(_DWORD *)&v8[v11] != m_padPattern )
        __debugbreak();
      if ( *(_DWORD *)v8 != m_padPattern + 1 )
        __debugbreak();
      v8 += 4;
      --v6;
    }
    while ( v6 );
  }
  v12 = numBytes;
  if ( numBytes < (__int64)v5 )
  {
    do
    {
      if ( p[v12] != this->m_cinfo.m_alignPattern )
        __debugbreak();
      ++v12;
    }
    while ( v12 < v5 );
  }
  this->m_inUse -= numBytes;
  this->m_allocated -= v5 + 32 * m_numQuadsPad;
  if ( 8 * m_numQuadsPad - 1 >= 0 )
  {
    v13 = (unsigned int)(8 * m_numQuadsPad);
    m_freePattern = this->m_cinfo.m_freePattern;
    v15 = v9;
    while ( v13 )
    {
      *v15++ = m_freePattern;
      --v13;
    }
  }
  ((void (__fastcall *)(hkMemoryAllocator *, unsigned int *))this->m_next->vfptr->blockFree)(this->m_next, v9);
}

// File Line: 91
// RVA: 0xC7D330
__int64 __fastcall hkPaddedAllocator::isOk(hkPaddedAllocator *this, _BYTE *p, int numBytes)
{
  int m_numQuadsPad; // r10d
  __int64 v4; // rbp
  __int64 v7; // rcx
  __int64 v8; // r11
  char *v9; // rbx
  char *v10; // rdx
  unsigned int m_padPattern; // r8d
  __int64 v12; // rbx
  __int64 v13; // rax

  m_numQuadsPad = this->m_cinfo.m_numQuadsPad;
  v4 = numBytes;
  v7 = 0i64;
  v8 = (int)((numBytes + 15) & 0xFFFFFFF0);
  v9 = &p[-16 * m_numQuadsPad];
  v10 = &p[v8];
  if ( 4 * m_numQuadsPad <= 0 )
  {
LABEL_6:
    v13 = v4;
    if ( v4 >= v8 )
      return 1i64;
    while ( p[v13] == this->m_cinfo.m_alignPattern )
    {
      if ( ++v13 >= v8 )
        return 1i64;
    }
  }
  else
  {
    m_padPattern = this->m_cinfo.m_padPattern;
    v12 = v9 - v10;
    while ( *(_DWORD *)&v10[v12] == m_padPattern && *(_DWORD *)v10 == m_padPattern + 1 )
    {
      ++v7;
      v10 += 4;
      if ( v7 >= 4 * m_numQuadsPad )
        goto LABEL_6;
    }
  }
  return 0i64;
}

// File Line: 124
// RVA: 0xC7D3F0
void __fastcall hkPaddedAllocator::getMemoryStatistics(hkPaddedAllocator *this, hkMemoryAllocator::MemoryStatistics *u)
{
  ((void (__fastcall *)(hkMemoryAllocator *))this->m_next->vfptr->getMemoryStatistics)(this->m_next);
  u->m_allocated = this->m_allocated;
  u->m_inUse = this->m_inUse;
  u->m_available = 0i64;
}

// File Line: 132
// RVA: 0xC7D490
hkPaddedAllocator::Allocation *__fastcall hkPaddedAllocator::getUnderlyingAllocation(
        hkPaddedAllocator *this,
        hkPaddedAllocator::Allocation *result,
        char *obj,
        int numBytes)
{
  int v4; // r10d

  v4 = 16 * this->m_cinfo.m_numQuadsPad;
  result->address = &obj[-16 * this->m_cinfo.m_numQuadsPad];
  result->size = ((numBytes + 15) & 0xFFFFFFF0) + 2 * v4;
  return result;
}

// File Line: 142
// RVA: 0xC7D440
__int64 __fastcall hkPaddedAllocator::getAllocatedSize(hkPaddedAllocator *this, char *obj, int numBytes)
{
  int v3; // ebx

  v3 = 32 * this->m_cinfo.m_numQuadsPad;
  return (unsigned int)this->m_next->vfptr->getAllocatedSize(
                         this->m_next,
                         &obj[-16 * this->m_cinfo.m_numQuadsPad],
                         v3 + ((numBytes + 15) & 0xFFFFFFF0))
       - v3;
}

// File Line: 150
// RVA: 0xC7D480
void __fastcall hkPaddedAllocator::setScrubValues(
        hkPaddedAllocator *this,
        unsigned int bodyValue,
        unsigned int freeValue)
{
  this->m_cinfo.m_bodyPattern = bodyValue;
  this->m_cinfo.m_freePattern = freeValue;
}

