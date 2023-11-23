// File Line: 40
// RVA: 0xC55FD0
void __fastcall hkLifoAllocator::hkLifoAllocator(hkLifoAllocator *this, int slabSize)
{
  this->m_impl = 0i64;
  this->m_slabSize = slabSize;
  this->vfptr = (hkMemoryAllocatorVtbl *)&hkLifoAllocator::`vftable;
}

// File Line: 46
// RVA: 0xC55FF0
void __fastcall hkLifoAllocator::init(
        hkLifoAllocator *this,
        hkMemoryAllocator *slabAllocator,
        hkMemoryAllocator *largeAllocator,
        hkMemoryAllocator *internalAllocator)
{
  hkLifoAllocator::Implementation *v8; // rax

  v8 = (hkLifoAllocator::Implementation *)(*((__int64 (__fastcall **)(hkMemoryAllocator *, __int64))&internalAllocator->vfptr->__vecDelDtor
                                           + 1))(
                                            internalAllocator,
                                            40i64);
  if ( v8 )
  {
    v8->m_nonLifoFrees.m_data = 0i64;
    v8->m_nonLifoFrees.m_size = 0;
    v8->m_nonLifoFrees.m_capacityAndFlags = 0x80000000;
    v8->m_slabPtrs.m_data = 0i64;
    v8->m_slabPtrs.m_size = 0;
    v8->m_slabPtrs.m_capacityAndFlags = 0x80000000;
    v8->m_numExternalAllocations = 0;
  }
  else
  {
    v8 = 0i64;
  }
  this->m_slabAllocator = slabAllocator;
  this->m_largeAllocator = largeAllocator;
  this->m_impl = v8;
  this->m_cur = 0i64;
  this->m_end = 0i64;
  this->m_firstNonLifoEnd = 0i64;
  this->m_cachedEmptySlab = 0i64;
  this->m_internalAllocator = internalAllocator;
}

// File Line: 60
// RVA: 0xC56090
void __fastcall hkLifoAllocator::quit(hkLifoAllocator *this, hkMemoryAllocator **allocators)
{
  void *m_cachedEmptySlab; // rdx
  hkLifoAllocator::Implementation *m_impl; // rdi
  hkMemoryAllocator *m_internalAllocator; // rcx
  int m_capacityAndFlags; // r8d
  hkLifoAllocator::Implementation *v8; // rdi
  int v9; // edx
  hkMemoryAllocator *v10; // rcx

  if ( this->m_cur )
    this->m_internalAllocator->vfptr->blockFree(
      this->m_internalAllocator,
      *this->m_impl->m_slabPtrs.m_data,
      this->m_slabSize);
  m_cachedEmptySlab = this->m_cachedEmptySlab;
  if ( m_cachedEmptySlab )
    this->m_internalAllocator->vfptr->blockFree(this->m_internalAllocator, m_cachedEmptySlab, this->m_slabSize);
  m_impl = this->m_impl;
  m_internalAllocator = this->m_internalAllocator;
  m_capacityAndFlags = m_impl->m_slabPtrs.m_capacityAndFlags;
  m_impl->m_slabPtrs.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    m_internalAllocator->vfptr->bufFree(m_internalAllocator, m_impl->m_slabPtrs.m_data, 8 * m_capacityAndFlags);
  m_impl->m_slabPtrs.m_data = 0i64;
  m_impl->m_slabPtrs.m_capacityAndFlags = 0x80000000;
  v8 = this->m_impl;
  v9 = v8->m_nonLifoFrees.m_capacityAndFlags;
  v10 = this->m_internalAllocator;
  v8->m_nonLifoFrees.m_size = 0;
  if ( v9 >= 0 )
    v10->vfptr->bufFree(v10, v8->m_nonLifoFrees.m_data, 24 * (v9 & 0x3FFFFFFF));
  v8->m_nonLifoFrees.m_data = 0i64;
  v8->m_nonLifoFrees.m_capacityAndFlags = 0x80000000;
  this->m_internalAllocator->vfptr->blockFree(this->m_internalAllocator, this->m_impl, 40);
  this->m_impl = 0i64;
  if ( allocators )
  {
    *allocators = this->m_slabAllocator;
    allocators[1] = this->m_largeAllocator;
    allocators[2] = this->m_internalAllocator;
  }
}

// File Line: 94
// RVA: 0xC561A0
char *__fastcall hkLifoAllocator::blockAlloc(hkLifoAllocator *this, int numBytesIn)
{
  char *result; // rax
  int v3; // r8d
  char *v4; // rdx

  result = (char *)this->m_cur;
  v3 = (numBytesIn + 15) & 0xFFFFFFF0;
  v4 = &result[v3];
  if ( v3 > this->m_slabSize || v4 > this->m_end )
    return (char *)hkLifoAllocator::allocateFromNewSlab(this, v3);
  this->m_cur = v4;
  return result;
}

// File Line: 99
// RVA: 0xC561E0
void __fastcall hkLifoAllocator::blockFree(hkLifoAllocator *this, char *p, int numBytesIn)
{
  int v3; // r9d

  v3 = (numBytesIn + 15) & 0xFFFFFFF0;
  if ( numBytesIn > this->m_slabSize || &p[v3] != this->m_cur || this->m_firstNonLifoEnd == p )
    hkLifoAllocator::slowBlockFree(this, p, v3);
  else
    this->m_cur = p;
}

// File Line: 104
// RVA: 0xC56220
char *__fastcall hkLifoAllocator::bufAlloc(hkLifoAllocator *this, unsigned int *reqNumBytesInOut)
{
  unsigned int v2; // eax
  char *m_cur; // r8
  int v4; // eax
  char *v5; // rdx

  v2 = (*reqNumBytesInOut + 15) & 0xFFFFFFF0;
  *reqNumBytesInOut = v2;
  m_cur = (char *)this->m_cur;
  v4 = (v2 + 15) & 0xFFFFFFF0;
  v5 = &m_cur[v4];
  if ( v4 > this->m_slabSize || v5 > this->m_end )
    return (char *)hkLifoAllocator::allocateFromNewSlab(this, v4);
  this->m_cur = v5;
  return m_cur;
}

// File Line: 110
// RVA: 0xC56260
void __fastcall hkLifoAllocator::bufFree(hkLifoAllocator *this, char *p, int numBytes)
{
  int v3; // r9d

  v3 = (numBytes + 15) & 0xFFFFFFF0;
  if ( numBytes > this->m_slabSize || &p[v3] != this->m_cur || this->m_firstNonLifoEnd == p )
    hkLifoAllocator::slowBlockFree(this, p, v3);
  else
    this->m_cur = p;
}

// File Line: 115
// RVA: 0xC562A0
char *__fastcall hkLifoAllocator::bufRealloc(hkLifoAllocator *this, char *pold, int oldNumBytes, int *reqNumBytesInOut)
{
  int v5; // ebp
  signed int v7; // edx
  char *v9; // rcx
  void *v11; // rax
  int v12; // r8d
  void *v13; // rbx

  v5 = (oldNumBytes + 15) & 0xFFFFFFF0;
  v7 = (*reqNumBytesInOut + 15) & 0xFFFFFFF0;
  *reqNumBytesInOut = v7;
  if ( &pold[v5] == this->m_cur && (v9 = &pold[v7], v9 <= this->m_end) )
  {
    this->m_cur = v9;
    return pold;
  }
  else
  {
    v11 = (void *)(*((__int64 (__fastcall **)(hkLifoAllocator *))&this->vfptr->__vecDelDtor + 1))(this);
    v12 = *reqNumBytesInOut;
    v13 = v11;
    if ( v5 < *reqNumBytesInOut )
      v12 = v5;
    hkMemUtil::memCpy(v11, pold, v12);
    this->vfptr->blockFree(this, pold, v5);
    return (char *)v13;
  }
}

// File Line: 136
// RVA: 0xC56350
bool __fastcall hkLifoAllocator::isEmpty(hkLifoAllocator *this)
{
  hkLifoAllocator::Implementation *m_impl; // rax

  m_impl = this->m_impl;
  return !m_impl->m_nonLifoFrees.m_size && m_impl->m_slabPtrs.m_size <= 1;
}

// File Line: 141
// RVA: 0xC56370
__int64 __fastcall hkLifoAllocator::numExternalAllocations(hkLifoAllocator *this)
{
  return (unsigned int)this->m_impl->m_numExternalAllocations;
}

// File Line: 146
// RVA: 0xC56380
__int64 __fastcall hkLifoAllocator::allocateFromNewSlab(hkLifoAllocator *this, int numBytes)
{
  __int64 v2; // rbp
  __int64 m_slabSize; // rdx
  char *m_cachedEmptySlab; // rsi
  hkLifoAllocator::Implementation *m_impl; // rax
  hkMemoryAllocator *m_slabAllocator; // rcx
  hkLifoAllocator::Implementation *v9; // rdi
  __int64 m_size; // rdx
  __int64 v11; // r8
  hkLifoAllocator::Implementation *v12; // rdi

  v2 = numBytes;
  m_slabSize = (unsigned int)this->m_slabSize;
  if ( (int)v2 <= (int)m_slabSize )
  {
    m_cachedEmptySlab = (char *)this->m_cachedEmptySlab;
    if ( m_cachedEmptySlab )
    {
      this->m_cachedEmptySlab = 0i64;
    }
    else
    {
      m_impl = this->m_impl;
      if ( m_impl->m_slabPtrs.m_size >= 2 )
      {
        ++m_impl->m_numExternalAllocations;
        m_slabAllocator = this->m_slabAllocator;
        m_slabSize = (unsigned int)this->m_slabSize;
      }
      else
      {
        m_slabAllocator = this->m_internalAllocator;
      }
      m_cachedEmptySlab = (char *)(*((__int64 (__fastcall **)(hkMemoryAllocator *, __int64))&m_slabAllocator->vfptr->__vecDelDtor
                                   + 1))(
                                    m_slabAllocator,
                                    m_slabSize);
    }
    v9 = this->m_impl;
    if ( v9->m_slabPtrs.m_size )
    {
      if ( v9->m_nonLifoFrees.m_size == (v9->m_nonLifoFrees.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(this->m_internalAllocator, this->m_impl, 24);
      m_size = v9->m_nonLifoFrees.m_size;
      v11 = (__int64)&v9->m_nonLifoFrees.m_data[m_size];
      v9->m_nonLifoFrees.m_size = m_size + 1;
      *(_QWORD *)(v11 + 8) = m_cachedEmptySlab;
      *(_QWORD *)v11 = this->m_cur;
      *(_DWORD *)(v11 + 16) = this->m_impl->m_slabPtrs.m_size - 1;
      this->m_firstNonLifoEnd = m_cachedEmptySlab;
    }
    v12 = this->m_impl;
    this->m_end = &m_cachedEmptySlab[this->m_slabSize];
    this->m_cur = &m_cachedEmptySlab[v2];
    if ( v12->m_slabPtrs.m_size == (v12->m_slabPtrs.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(this->m_internalAllocator, &v12->m_slabPtrs, 8);
    v12->m_slabPtrs.m_data[v12->m_slabPtrs.m_size++] = m_cachedEmptySlab;
    return (__int64)m_cachedEmptySlab;
  }
  else
  {
    ++this->m_impl->m_numExternalAllocations;
    return (*((__int64 (__fastcall **)(hkMemoryAllocator *, _QWORD))&this->m_largeAllocator->vfptr->__vecDelDtor + 1))(
             this->m_largeAllocator,
             (unsigned int)v2);
  }
}

// File Line: 201
// RVA: 0xC564C0
void __fastcall hkLifoAllocator::popNonLifoFrees(hkLifoAllocator *this)
{
  char *m_cur; // rdi
  int v3; // ecx
  __int64 v4; // r8
  __int64 v5; // rdx
  hkLifoAllocator::Implementation *m_impl; // rcx
  hkLifoAllocator::Implementation *v7; // rdx
  void **m_data; // rax
  void *m_cachedEmptySlab; // rdx
  hkLifoAllocator::Implementation *v10; // rdx
  hkLifoAllocator::Implementation *v11; // rdx
  char *v12; // r8

  m_cur = (char *)this->m_cur;
  v3 = this->m_impl->m_nonLifoFrees.m_size - 1;
  v4 = v3;
  if ( v3 >= 0 )
  {
    v5 = v3;
    do
    {
      m_impl = this->m_impl;
      if ( m_impl->m_nonLifoFrees.m_data[v5].end != m_cur )
        break;
      m_cur = (char *)m_impl->m_nonLifoFrees.m_data[v5].start;
      --m_impl->m_nonLifoFrees.m_size;
      --v5;
      --v4;
    }
    while ( v4 >= 0 );
  }
  for ( ; this->m_impl->m_slabPtrs.m_size > 1; this->m_cachedEmptySlab = v10->m_slabPtrs.m_data[--v10->m_slabPtrs.m_size] )
  {
    v7 = this->m_impl;
    m_data = v7->m_slabPtrs.m_data;
    if ( m_cur != m_data[v7->m_slabPtrs.m_size - 1]
      && m_cur - (_BYTE *)m_data[v7->m_slabPtrs.m_size - 1] <= (unsigned __int64)(int)this->m_slabSize )
    {
      break;
    }
    m_cachedEmptySlab = this->m_cachedEmptySlab;
    if ( m_cachedEmptySlab )
    {
      this->m_slabAllocator->vfptr->blockFree(this->m_slabAllocator, m_cachedEmptySlab, this->m_slabSize);
      --this->m_impl->m_numExternalAllocations;
    }
    v10 = this->m_impl;
  }
  v11 = this->m_impl;
  this->m_cur = m_cur;
  if ( v11->m_slabPtrs.m_size )
    v12 = (char *)v11->m_slabPtrs.m_data[v11->m_slabPtrs.m_size - 1] + (int)this->m_slabSize;
  else
    v12 = 0i64;
  this->m_end = v12;
  if ( v11->m_nonLifoFrees.m_size )
    this->m_firstNonLifoEnd = v11->m_nonLifoFrees.m_data[v11->m_nonLifoFrees.m_size - 1].end;
  else
    this->m_firstNonLifoEnd = 0i64;
}

// File Line: 240
// RVA: 0xC56640
void __fastcall hkLifoAllocator::insertNonLifoFree(hkLifoAllocator *this, char *pstart, int nbytes)
{
  hkLifoAllocator::Implementation *m_impl; // r12
  int v4; // esi
  int v6; // r10d
  __int64 v8; // r9
  char *m_slabSize; // rdx
  _QWORD *v10; // rcx
  int v11; // ebx
  char *v12; // rbp
  int v13; // r9d
  __int64 v14; // r8
  __int64 v15; // rdx
  int v16; // eax
  int m_size; // r15d
  int v18; // eax
  int v19; // r14d
  int v20; // r15d
  int v21; // eax
  int v22; // r9d
  __int64 v23; // rbx
  hkLifoAllocator::Implementation::NonLifoFree *m_data; // rax
  hkLifoAllocator::Implementation *v25; // rdx
  hkResult result; // [rsp+70h] [rbp+18h] BYREF

  m_impl = this->m_impl;
  v4 = -1;
  v6 = m_impl->m_slabPtrs.m_size - 1;
  v8 = v6;
  if ( v6 >= 0 )
  {
    m_slabSize = (char *)(int)this->m_slabSize;
    v10 = &m_impl->m_slabPtrs.m_data[v6];
    while ( &pstart[-*v10] >= m_slabSize )
    {
      --v6;
      --v10;
      if ( --v8 < 0 )
        goto LABEL_7;
    }
    v4 = v6;
  }
LABEL_7:
  v11 = 0;
  v12 = &pstart[nbytes];
  v13 = m_impl->m_nonLifoFrees.m_size - 1;
  v14 = v13;
  if ( v13 >= 0 )
  {
    v15 = (__int64)&m_impl->m_nonLifoFrees.m_data[v13];
    do
    {
      v16 = *(_DWORD *)(v15 + 16);
      if ( v16 == v4 )
      {
        if ( pstart == *(char **)(v15 + 8) )
        {
          *(_QWORD *)(v15 + 8) = v12;
          goto $end_1;
        }
        if ( v12 == *(char **)v15 )
        {
          *(_QWORD *)v15 = pstart;
          goto $end_1;
        }
        if ( (unsigned __int64)pstart > *(_QWORD *)v15 )
          goto LABEL_13;
      }
      else if ( v16 < v4 )
      {
LABEL_13:
        v11 = v13 + 1;
        break;
      }
      --v13;
      v15 -= 24i64;
      --v14;
    }
    while ( v14 >= 0 );
  }
  m_size = m_impl->m_nonLifoFrees.m_size;
  v18 = m_impl->m_nonLifoFrees.m_capacityAndFlags & 0x3FFFFFFF;
  v19 = m_size + 1;
  v20 = m_size - v11;
  if ( v19 > v18 )
  {
    v21 = 2 * v18;
    v22 = v19;
    if ( v19 < v21 )
      v22 = v21;
    hkArrayUtil::_reserve(&result, this->m_internalAllocator, m_impl, v22, 24);
  }
  v23 = v11;
  hkMemUtil::memMove(&m_impl->m_nonLifoFrees.m_data[v23 + 1], &m_impl->m_nonLifoFrees.m_data[v23], 24 * v20);
  m_data = m_impl->m_nonLifoFrees.m_data;
  m_impl->m_nonLifoFrees.m_size = v19;
  m_data[v23].start = pstart;
  m_data[v23].end = v12;
  m_data[v23].slabIndex = v4;
$end_1:
  v25 = this->m_impl;
  if ( v25->m_nonLifoFrees.m_size )
    this->m_firstNonLifoEnd = v25->m_nonLifoFrees.m_data[v25->m_nonLifoFrees.m_size - 1].end;
  else
    this->m_firstNonLifoEnd = 0i64;
}

// File Line: 301
// RVA: 0xC565F0
void __fastcall hkLifoAllocator::slowBlockFree(hkLifoAllocator *this, char *p, int numBytesIn)
{
  int v3; // r8d

  if ( p )
  {
    if ( numBytesIn > this->m_slabSize )
    {
      --this->m_impl->m_numExternalAllocations;
      ((void (__fastcall *)(hkMemoryAllocator *))this->m_largeAllocator->vfptr->blockFree)(this->m_largeAllocator);
    }
    else
    {
      v3 = (numBytesIn + 15) & 0xFFFFFFF0;
      if ( &p[v3] == this->m_cur )
      {
        this->m_cur = p;
        hkLifoAllocator::popNonLifoFrees(this);
      }
      else
      {
        hkLifoAllocator::insertNonLifoFree(this, p, v3);
      }
    }
  }
}

