// File Line: 40
// RVA: 0xC55FD0
void __fastcall hkLifoAllocator::hkLifoAllocator(hkLifoAllocator *this, int slabSize)
{
  this->m_impl = 0i64;
  this->m_slabSize = slabSize;
  this->vfptr = (hkMemoryAllocatorVtbl *)&hkLifoAllocator::`vftable';
}

// File Line: 46
// RVA: 0xC55FF0
void __fastcall hkLifoAllocator::init(hkLifoAllocator *this, hkMemoryAllocator *slabAllocator, hkMemoryAllocator *largeAllocator, hkMemoryAllocator *internalAllocator)
{
  hkMemoryAllocator *v4; // rbp
  hkLifoAllocator *v5; // rbx
  hkMemoryAllocator *v6; // rdi
  hkMemoryAllocator *v7; // rsi
  __int64 v8; // rax

  v4 = slabAllocator;
  v5 = this;
  v6 = internalAllocator;
  v7 = largeAllocator;
  v8 = (*((__int64 (__fastcall **)(hkMemoryAllocator *, signed __int64))&internalAllocator->vfptr->__vecDelDtor + 1))(
         internalAllocator,
         40i64);
  if ( v8 )
  {
    *(_QWORD *)v8 = 0i64;
    *(_DWORD *)(v8 + 8) = 0;
    *(_DWORD *)(v8 + 12) = 2147483648;
    *(_QWORD *)(v8 + 16) = 0i64;
    *(_DWORD *)(v8 + 24) = 0;
    *(_DWORD *)(v8 + 28) = 2147483648;
    *(_DWORD *)(v8 + 32) = 0;
  }
  else
  {
    v8 = 0i64;
  }
  v5->m_slabAllocator = v4;
  v5->m_largeAllocator = v7;
  v5->m_impl = (hkLifoAllocator::Implementation *)v8;
  v5->m_cur = 0i64;
  v5->m_end = 0i64;
  v5->m_firstNonLifoEnd = 0i64;
  v5->m_cachedEmptySlab = 0i64;
  v5->m_internalAllocator = v6;
}

// File Line: 60
// RVA: 0xC56090
void __fastcall hkLifoAllocator::quit(hkLifoAllocator *this, hkMemoryAllocator **allocators)
{
  hkMemoryAllocator **v2; // rsi
  hkLifoAllocator *v3; // rbx
  void *v4; // rdx
  hkLifoAllocator::Implementation *v5; // rdi
  hkMemoryAllocator *v6; // rcx
  int v7; // er8
  hkLifoAllocator::Implementation *v8; // rdi
  int v9; // edx
  hkMemoryAllocator *v10; // rcx

  v2 = allocators;
  v3 = this;
  if ( this->m_cur )
    this->m_internalAllocator->vfptr->blockFree(
      this->m_internalAllocator,
      *this->m_impl->m_slabPtrs.m_data,
      this->m_slabSize);
  v4 = v3->m_cachedEmptySlab;
  if ( v4 )
    v3->m_internalAllocator->vfptr->blockFree(v3->m_internalAllocator, v4, v3->m_slabSize);
  v5 = v3->m_impl;
  v6 = v3->m_internalAllocator;
  v7 = v5->m_slabPtrs.m_capacityAndFlags;
  v5->m_slabPtrs.m_size = 0;
  if ( v7 >= 0 )
    v6->vfptr->bufFree(v6, v5->m_slabPtrs.m_data, 8 * v7);
  v5->m_slabPtrs.m_data = 0i64;
  v5->m_slabPtrs.m_capacityAndFlags = 2147483648;
  v8 = v3->m_impl;
  v9 = v8->m_nonLifoFrees.m_capacityAndFlags;
  v10 = v3->m_internalAllocator;
  v8->m_nonLifoFrees.m_size = 0;
  if ( v9 >= 0 )
    v10->vfptr->bufFree(v10, v8->m_nonLifoFrees.m_data, 24 * (v9 & 0x3FFFFFFF));
  v8->m_nonLifoFrees.m_data = 0i64;
  v8->m_nonLifoFrees.m_capacityAndFlags = 2147483648;
  v3->m_internalAllocator->vfptr->blockFree(v3->m_internalAllocator, v3->m_impl, 40);
  v3->m_impl = 0i64;
  if ( v2 )
  {
    *v2 = v3->m_slabAllocator;
    v2[1] = v3->m_largeAllocator;
    v2[2] = v3->m_internalAllocator;
  }
}

// File Line: 94
// RVA: 0xC561A0
char *__fastcall hkLifoAllocator::blockAlloc(hkLifoAllocator *this, int numBytesIn)
{
  char *result; // rax
  int v3; // er8
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
void __fastcall hkLifoAllocator::blockFree(hkLifoAllocator *this, void *p, int numBytesIn)
{
  int v3; // er9

  v3 = (numBytesIn + 15) & 0xFFFFFFF0;
  if ( numBytesIn > this->m_slabSize || (char *)p + v3 != this->m_cur || this->m_firstNonLifoEnd == p )
    hkLifoAllocator::slowBlockFree(this, p, v3);
  else
    this->m_cur = p;
}

// File Line: 104
// RVA: 0xC56220
char *__fastcall hkLifoAllocator::bufAlloc(hkLifoAllocator *this, int *reqNumBytesInOut)
{
  int v2; // eax
  char *v3; // r8
  int v4; // eax
  char *v5; // rdx

  v2 = (*reqNumBytesInOut + 15) & 0xFFFFFFF0;
  *reqNumBytesInOut = v2;
  v3 = (char *)this->m_cur;
  v4 = (v2 + 15) & 0xFFFFFFF0;
  v5 = &v3[v4];
  if ( v4 > this->m_slabSize || v5 > this->m_end )
    return (char *)hkLifoAllocator::allocateFromNewSlab(this, v4);
  this->m_cur = v5;
  return v3;
}

// File Line: 110
// RVA: 0xC56260
void __fastcall hkLifoAllocator::bufFree(hkLifoAllocator *this, void *p, int numBytes)
{
  int v3; // er9

  v3 = (numBytes + 15) & 0xFFFFFFF0;
  if ( numBytes > this->m_slabSize || (char *)p + v3 != this->m_cur || this->m_firstNonLifoEnd == p )
    hkLifoAllocator::slowBlockFree(this, p, v3);
  else
    this->m_cur = p;
}

// File Line: 115
// RVA: 0xC562A0
void *__fastcall hkLifoAllocator::bufRealloc(hkLifoAllocator *this, void *pold, int oldNumBytes, int *reqNumBytesInOut)
{
  char *v4; // rsi
  signed int v5; // ebp
  int *v6; // r14
  int v7; // edx
  hkLifoAllocator *v8; // rdi
  char *v9; // rcx
  void *result; // rax
  void *v11; // rax
  int v12; // er8
  void *v13; // rbx

  v4 = (char *)pold;
  v5 = (oldNumBytes + 15) & 0xFFFFFFF0;
  v6 = reqNumBytesInOut;
  v7 = (*reqNumBytesInOut + 15) & 0xFFFFFFF0;
  v8 = this;
  *reqNumBytesInOut = v7;
  if ( &v4[v5] != this->m_cur || (v9 = &v4[v7], v9 > v8->m_end) )
  {
    v11 = (void *)(*((__int64 (__fastcall **)(hkLifoAllocator *))&v8->vfptr->__vecDelDtor + 1))(v8);
    v12 = *v6;
    v13 = v11;
    if ( v5 < *v6 )
      v12 = v5;
    hkMemUtil::memCpy(v11, v4, v12);
    v8->vfptr->blockFree((hkMemoryAllocator *)&v8->vfptr, v4, v5);
    result = v13;
  }
  else
  {
    v8->m_cur = v9;
    result = v4;
  }
  return result;
}

// File Line: 136
// RVA: 0xC56350
bool __fastcall hkLifoAllocator::isEmpty(hkLifoAllocator *this)
{
  hkLifoAllocator::Implementation *v1; // rax

  v1 = this->m_impl;
  return !v1->m_nonLifoFrees.m_size && v1->m_slabPtrs.m_size <= 1;
}

// File Line: 141
// RVA: 0xC56370
__int64 __fastcall hkLifoAllocator::numExternalAllocations(hkLifoAllocator *this)
{
  return (unsigned int)this->m_impl->m_numExternalAllocations;
}

// File Line: 146
// RVA: 0xC56380
void *__fastcall hkLifoAllocator::allocateFromNewSlab(hkLifoAllocator *this, int numBytes)
{
  __int64 v2; // rbp
  __int64 v3; // rdx
  hkLifoAllocator *v4; // rbx
  void *result; // rax
  char *v6; // rsi
  hkLifoAllocator::Implementation *v7; // rax
  hkMemoryAllocator *v8; // rcx
  hkLifoAllocator::Implementation *v9; // rdi
  __int64 v10; // rdx
  signed __int64 v11; // r8
  hkLifoAllocator::Implementation *v12; // rdi

  v2 = numBytes;
  v3 = (unsigned int)this->m_slabSize;
  v4 = this;
  if ( (signed int)v2 <= (signed int)v3 )
  {
    v6 = (char *)this->m_cachedEmptySlab;
    if ( v6 )
    {
      this->m_cachedEmptySlab = 0i64;
    }
    else
    {
      v7 = this->m_impl;
      if ( v7->m_slabPtrs.m_size >= 2 )
      {
        ++v7->m_numExternalAllocations;
        v8 = this->m_slabAllocator;
        v3 = (unsigned int)v4->m_slabSize;
      }
      else
      {
        v8 = this->m_internalAllocator;
      }
      v6 = (char *)(*((__int64 (__fastcall **)(hkMemoryAllocator *, __int64))&v8->vfptr->__vecDelDtor + 1))(v8, v3);
    }
    v9 = v4->m_impl;
    if ( v9->m_slabPtrs.m_size )
    {
      if ( v9->m_nonLifoFrees.m_size == (v9->m_nonLifoFrees.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(v4->m_internalAllocator, v4->m_impl, 24);
      v10 = v9->m_nonLifoFrees.m_size;
      v11 = (signed __int64)&v9->m_nonLifoFrees.m_data[v10];
      v9->m_nonLifoFrees.m_size = v10 + 1;
      *(_QWORD *)(v11 + 8) = v6;
      *(_QWORD *)v11 = v4->m_cur;
      *(_DWORD *)(v11 + 16) = v4->m_impl->m_slabPtrs.m_size - 1;
      v4->m_firstNonLifoEnd = v6;
    }
    v12 = v4->m_impl;
    v4->m_end = &v6[v4->m_slabSize];
    v4->m_cur = &v6[v2];
    if ( v12->m_slabPtrs.m_size == (v12->m_slabPtrs.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(v4->m_internalAllocator, &v12->m_slabPtrs, 8);
    v12->m_slabPtrs.m_data[v12->m_slabPtrs.m_size++] = v6;
    result = v6;
  }
  else
  {
    ++this->m_impl->m_numExternalAllocations;
    result = (void *)(*((__int64 (__fastcall **)(hkMemoryAllocator *, _QWORD))&this->m_largeAllocator->vfptr->__vecDelDtor
                      + 1))(
                       this->m_largeAllocator,
                       (unsigned int)v2);
  }
  return result;
}

// File Line: 201
// RVA: 0xC564C0
void __fastcall hkLifoAllocator::popNonLifoFrees(hkLifoAllocator *this)
{
  char *v1; // rdi
  hkLifoAllocator *v2; // rbx
  int v3; // ecx
  __int64 v4; // r8
  signed __int64 v5; // rdx
  hkLifoAllocator::Implementation *v6; // rcx
  hkLifoAllocator::Implementation *v7; // rdx
  void **v8; // rax
  void *v9; // rdx
  hkLifoAllocator::Implementation *v10; // rdx
  hkLifoAllocator::Implementation *v11; // rdx
  char *v12; // r8

  v1 = (char *)this->m_cur;
  v2 = this;
  v3 = this->m_impl->m_nonLifoFrees.m_size - 1;
  v4 = v3;
  if ( v3 >= 0 )
  {
    v5 = v3;
    do
    {
      v6 = v2->m_impl;
      if ( v6->m_nonLifoFrees.m_data[v5].end != v1 )
        break;
      v1 = (char *)v6->m_nonLifoFrees.m_data[v5].start;
      --v6->m_nonLifoFrees.m_size;
      --v5;
      --v4;
    }
    while ( v4 >= 0 );
  }
  for ( ; v2->m_impl->m_slabPtrs.m_size > 1; v2->m_cachedEmptySlab = v10->m_slabPtrs.m_data[v10->m_slabPtrs.m_size-- - 1] )
  {
    v7 = v2->m_impl;
    v8 = v7->m_slabPtrs.m_data;
    if ( v1 != v8[v7->m_slabPtrs.m_size - 1]
      && v1 - (_BYTE *)v8[v7->m_slabPtrs.m_size - 1] <= (unsigned __int64)(signed int)v2->m_slabSize )
    {
      break;
    }
    v9 = v2->m_cachedEmptySlab;
    if ( v9 )
    {
      v2->m_slabAllocator->vfptr->blockFree(v2->m_slabAllocator, v9, v2->m_slabSize);
      --v2->m_impl->m_numExternalAllocations;
    }
    v10 = v2->m_impl;
  }
  v11 = v2->m_impl;
  v2->m_cur = v1;
  if ( v11->m_slabPtrs.m_size )
    v12 = (char *)v11->m_slabPtrs.m_data[v11->m_slabPtrs.m_size - 1] + (signed int)v2->m_slabSize;
  else
    v12 = 0i64;
  v2->m_end = v12;
  if ( v11->m_nonLifoFrees.m_size )
    v2->m_firstNonLifoEnd = (void *)*((_QWORD *)&v11->m_nonLifoFrees.m_data[v11->m_nonLifoFrees.m_size] - 2);
  else
    v2->m_firstNonLifoEnd = 0i64;
}

// File Line: 240
// RVA: 0xC56640
void __fastcall hkLifoAllocator::insertNonLifoFree(hkLifoAllocator *this, void *pstart, int nbytes)
{
  hkLifoAllocator::Implementation *v3; // r12
  signed int v4; // esi
  char *v5; // rdi
  int v6; // er10
  hkLifoAllocator *v7; // r13
  __int64 v8; // r9
  unsigned __int64 v9; // rdx
  void **v10; // rcx
  int v11; // ebx
  char *v12; // rbp
  int v13; // er9
  __int64 v14; // r8
  signed __int64 v15; // rdx
  signed int v16; // eax
  int v17; // er15
  int v18; // eax
  int v19; // er14
  int v20; // er15
  int v21; // eax
  int v22; // er9
  signed __int64 v23; // rbx
  hkLifoAllocator::Implementation::NonLifoFree *v24; // rax
  hkLifoAllocator::Implementation *v25; // rdx
  hkResult result; // [rsp+70h] [rbp+18h]

  v3 = this->m_impl;
  v4 = -1;
  v5 = (char *)pstart;
  v6 = v3->m_slabPtrs.m_size - 1;
  v7 = this;
  v8 = v6;
  if ( v6 >= 0 )
  {
    v9 = this->m_slabSize;
    v10 = &v3->m_slabPtrs.m_data[v6];
    while ( v5 - (_BYTE *)*v10 >= v9 )
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
  v12 = &v5[nbytes];
  v13 = v3->m_nonLifoFrees.m_size - 1;
  v14 = v13;
  if ( v13 >= 0 )
  {
    v15 = (signed __int64)&v3->m_nonLifoFrees.m_data[v13];
    do
    {
      v16 = *(_DWORD *)(v15 + 16);
      if ( v16 == v4 )
      {
        if ( v5 == *(char **)(v15 + 8) )
        {
          *(_QWORD *)(v15 + 8) = v12;
          goto $end_1;
        }
        if ( v12 == *(char **)v15 )
        {
          *(_QWORD *)v15 = v5;
          goto $end_1;
        }
        if ( (unsigned __int64)v5 > *(_QWORD *)v15 )
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
  v17 = v3->m_nonLifoFrees.m_size;
  v18 = v3->m_nonLifoFrees.m_capacityAndFlags & 0x3FFFFFFF;
  v19 = v17 + 1;
  v20 = v17 - v11;
  if ( v19 > v18 )
  {
    if ( v18 >= v19 )
    {
      result.m_enum = 0;
    }
    else
    {
      v21 = 2 * v18;
      v22 = v19;
      if ( v19 < v21 )
        v22 = v21;
      hkArrayUtil::_reserve(&result, v7->m_internalAllocator, v3, v22, 24);
    }
  }
  v23 = v11;
  hkMemUtil::memMove(&v3->m_nonLifoFrees.m_data[v23 + 1], &v3->m_nonLifoFrees.m_data[v23], 24 * v20);
  v24 = v3->m_nonLifoFrees.m_data;
  v3->m_nonLifoFrees.m_size = v19;
  v24[v23].start = v5;
  v24[v23].end = v12;
  v24[v23].slabIndex = v4;
$end_1:
  v25 = v7->m_impl;
  if ( v25->m_nonLifoFrees.m_size )
    v7->m_firstNonLifoEnd = (void *)*((_QWORD *)&v25->m_nonLifoFrees.m_data[v25->m_nonLifoFrees.m_size] - 2);
  else
    v7->m_firstNonLifoEnd = 0i64;
}

// File Line: 301
// RVA: 0xC565F0
void __fastcall hkLifoAllocator::slowBlockFree(hkLifoAllocator *this, void *p, int numBytesIn)
{
  int v3; // er8

  if ( p )
  {
    if ( numBytesIn > this->m_slabSize )
    {
      --this->m_impl->m_numExternalAllocations;
      ((void (*)(void))this->m_largeAllocator->vfptr->blockFree)();
    }
    else
    {
      v3 = (numBytesIn + 15) & 0xFFFFFFF0;
      if ( (char *)p + v3 == this->m_cur )
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

