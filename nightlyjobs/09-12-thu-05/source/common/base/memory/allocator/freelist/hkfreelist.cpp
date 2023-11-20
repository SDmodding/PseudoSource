// File Line: 16
// RVA: 0xC703E0
hkFreeList::Block *__fastcall _sortByAllocationAddress(hkFreeList::Block *headPtr)
{
  hkFreeList::Block *v1; // r8
  signed int i; // er11
  signed int v4; // ebx
  __int64 *v5; // r10
  hkFreeList::Block *v6; // rax
  signed int j; // edx
  signed int v8; // er9
  __int64 *v9; // rcx
  hkFreeList::Block *v10; // [rsp+0h] [rbp-28h]

  v1 = headPtr;
  if ( !headPtr )
    return 0i64;
  for ( i = 1; ; i *= 2 )
  {
    v4 = 0;
    v10 = 0i64;
    v5 = (__int64 *)&v10;
    if ( v1 )
    {
      do
      {
        ++v4;
        v6 = v1;
        for ( j = 0; j < i; ++j )
        {
          if ( !v6 )
            break;
          v6 = v6->m_next;
        }
        v8 = i;
        if ( j > 0 )
        {
          while ( v8 > 0 && v6 )
          {
            if ( v1->m_elementsAlloc > v6->m_elementsAlloc )
            {
              v9 = (__int64 *)v6;
              v6 = v6->m_next;
              --v8;
            }
            else
            {
              v9 = (__int64 *)v1;
              v1 = v1->m_next;
              --j;
            }
            *v5 = (__int64)v9;
            v5 = v9;
            if ( j <= 0 )
              goto LABEL_18;
          }
          for ( ; j > 0; v1 = v1->m_next )
          {
            *v5 = (__int64)v1;
            --j;
            v5 = (__int64 *)v1;
          }
        }
LABEL_18:
        while ( v8 > 0 )
        {
          if ( !v6 )
            break;
          *v5 = (__int64)v6;
          --v8;
          v5 = (__int64 *)v6;
          v6 = v6->m_next;
        }
        v1 = v6;
      }
      while ( v6 );
    }
    *v5 = 0i64;
    if ( v4 <= 1 )
      break;
    v1 = v10;
  }
  return v10;
}

// File Line: 97
// RVA: 0xC6F450
void __fastcall hkFreeList::hkFreeList(hkFreeList *this, unsigned __int64 elementSize, unsigned __int64 align, unsigned __int64 blockSize, hkMemoryAllocator *elementAllocator, hkMemoryAllocator *blockAllocator)
{
  hkFreeList::_init(this, elementSize, align, blockSize, elementAllocator, blockAllocator);
}

// File Line: 102
// RVA: 0xC6F490
void __fastcall hkFreeList::hkFreeList(hkFreeList *this)
{
  this->m_free = 0i64;
  this->m_activeBlocks = 0i64;
  this->m_freeBlocks = 0i64;
  this->m_blockSize = 0i64;
  this->m_align = 0i64;
  this->m_top = 0i64;
  this->m_blockEnd = 0i64;
  this->m_numFreeElements = 0i64;
  this->m_totalNumElements = 0i64;
  this->m_blockAllocator = 0i64;
  this->m_elementAllocator = 0i64;
  this->m_elementSize = 0i64;
}

// File Line: 121
// RVA: 0xC6FFC0
void __fastcall hkFreeList::_init(hkFreeList *this, unsigned __int64 elementSize, unsigned __int64 align, unsigned __int64 blockSize, hkMemoryAllocator *elementAllocator, hkMemoryAllocator *blockAllocator)
{
  hkMemoryAllocator *v6; // rax
  unsigned __int64 v7; // rbp
  unsigned __int64 v8; // rdi
  unsigned __int64 v9; // rsi
  hkFreeList *v10; // rbx

  v6 = elementAllocator;
  v7 = blockSize;
  v8 = align;
  v9 = elementSize;
  v10 = this;
  if ( !elementAllocator )
    v6 = (hkMemoryAllocator *)*((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
  v10->m_elementAllocator = v6;
  v10->m_free = 0i64;
  v10->m_activeBlocks = 0i64;
  v10->m_freeBlocks = 0i64;
  v10->m_blockAllocator = blockAllocator;
  v10->m_blockSize = v7;
  v10->m_align = v8;
  v10->m_top = 0i64;
  v10->m_blockEnd = 0i64;
  v10->m_numFreeElements = 0i64;
  v10->m_totalNumElements = 0i64;
  v10->m_lastIncrementalBlock = 0i64;
  if ( v9 >= v8 )
    v8 = (v9 + v8 - 1) & ~(v8 - 1);
  v10->m_elementSize = v8;
  v10->m_numBlockElements = v7 / v8;
}

// File Line: 169
// RVA: 0xC6F4D0
void __fastcall hkFreeList::init(hkFreeList *this, unsigned __int64 elementSize, unsigned __int64 align, unsigned __int64 blockSize, hkMemoryAllocator *elementAllocator, hkMemoryAllocator *blockAllocator)
{
  unsigned __int64 v6; // rbx
  unsigned __int64 v7; // rdi
  unsigned __int64 v8; // rsi
  hkFreeList *v9; // rbp

  v6 = blockSize;
  v7 = align;
  v8 = elementSize;
  v9 = this;
  hkFreeList::freeAllMemory(this);
  hkFreeList::_init(v9, v8, v7, v6, elementAllocator, blockAllocator);
}

// File Line: 175
// RVA: 0xC6FB10
__int64 __fastcall hkFreeList::calcNumBlocks(hkFreeList::Block *blocks)
{
  __int64 result; // rax

  for ( result = 0i64; blocks; result = (unsigned int)(result + 1) )
    blocks = blocks->m_next;
  return result;
}

// File Line: 186
// RVA: 0xC70120
hkBool *__fastcall hkFreeList::_checkFreeBlocks(hkFreeList *this, hkBool *result)
{
  hkBool *v2; // rdi
  hkFreeList *v3; // rbx
  hkFreeList::Element *v5; // r8
  hkFreeList::Block *v6; // rax
  unsigned __int64 v7; // rdx

  v2 = result;
  v3 = this;
  if ( hkFreeList::_calcNumFreeElements(this) != this->m_numFreeElements
    || hkFreeList::_calcTotalNumElements(v3) != v3->m_totalNumElements )
  {
LABEL_2:
    v2->m_bool = 0;
    return v2;
  }
  v5 = v3->m_free;
  if ( v3->m_free )
  {
    while ( !((v3->m_align - 1) & (unsigned __int64)v5) )
    {
      v6 = v3->m_activeBlocks;
      if ( !v6 )
        break;
      while ( 1 )
      {
        v7 = (unsigned __int64)v6->m_elements;
        if ( (unsigned __int64)v5 >= v7 && (unsigned __int64)v5 < v7 + v3->m_elementSize * v6->m_numElements )
          break;
        v6 = v6->m_next;
        if ( !v6 )
        {
          v2->m_bool = 0;
          return v2;
        }
      }
      if ( ((unsigned __int64)v5 - v7) % v3->m_elementSize )
        break;
      v5 = v5->m_next;
      if ( !v5 )
        goto LABEL_13;
    }
    goto LABEL_2;
  }
LABEL_13:
  v2->m_bool = 1;
  return v2;
}

// File Line: 243
// RVA: 0xC6FE50
__int64 __fastcall hkFreeList::_freeBlocks(hkFreeList *this, hkFreeList::Block *cur)
{
  unsigned int v2; // ebp
  hkFreeList::Block *v3; // rdi
  hkFreeList *v4; // rbx
  hkMemoryAllocator *v5; // rcx
  __int64 v6; // r8
  hkFreeList::Block *v7; // rsi

  v2 = 0;
  v3 = cur;
  v4 = this;
  if ( cur )
  {
    do
    {
      v5 = v4->m_elementAllocator;
      v6 = LODWORD(v4->m_blockSize);
      v4->m_totalNumElements -= v3->m_numElements;
      ++v2;
      v4->m_numFreeElements -= v3->m_numElements;
      v7 = v3->m_next;
      if ( v4->m_blockAllocator )
      {
        v5->vfptr->bufFree(v5, v3->m_elementsAlloc, v6);
        v4->m_blockAllocator->vfptr->blockFree(v4->m_blockAllocator, v3, 32);
      }
      else
      {
        v5->vfptr->bufFree(v5, v3, v6);
      }
      v3 = v7;
    }
    while ( v7 );
  }
  return v2;
}

// File Line: 277
// RVA: 0xC6F520
void __fastcall hkFreeList::freeAllMemory(hkFreeList *this)
{
  hkFreeList *v1; // rbx
  hkFreeList::Block *v2; // rdx

  v1 = this;
  hkFreeList::_freeBlocks(this, this->m_activeBlocks);
  v2 = v1->m_freeBlocks;
  v1->m_activeBlocks = 0i64;
  hkFreeList::_freeBlocks(v1, v2);
  v1->m_freeBlocks = 0i64;
  v1->m_free = 0i64;
  v1->m_blockSize = 0i64;
  v1->m_numFreeElements = 0i64;
  v1->m_totalNumElements = 0i64;
  v1->m_top = 0i64;
  v1->m_blockEnd = 0i64;
  v1->m_lastIncrementalBlock = 0i64;
}

// File Line: 299
// RVA: 0xC701F0
__int64 __fastcall hkFreeList::_calcBlockFree(hkFreeList *this, hkFreeList::Block *block)
{
  int v2; // ebx
  hkFreeList *v3; // r14
  hkFreeList::Block *v4; // rbp
  hkLifoAllocator *v5; // rax
  hkpRigidBody **v6; // rdi
  int v7; // er15
  char *v8; // rcx
  char *v9; // r10
  hkFreeList::Element *v10; // rcx
  signed int v11; // esi
  unsigned __int64 v12; // r9
  hkFreeList *v13; // r8
  hkpRigidBody **v14; // rdx
  char *v15; // rcx
  unsigned int v16; // ebx
  hkpRigidBody *v17; // rcx
  signed __int64 i; // rbx
  hkpRigidBody *v19; // rax
  hkLifoAllocator *v20; // rax
  int v21; // er8

  v2 = block->m_numElements;
  v3 = this;
  v4 = block;
  v5 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v6 = (hkpRigidBody **)v5->m_cur;
  v7 = (8 * v2 + 127) & 0xFFFFFF80;
  v8 = (char *)v6 + v7;
  if ( v7 > v5->m_slabSize || v8 > v5->m_end )
    v6 = (hkpRigidBody **)hkLifoAllocator::allocateFromNewSlab(v5, v7);
  else
    v5->m_cur = v8;
  v9 = v4->m_elements;
  v10 = v3->m_free;
  v11 = 0;
  v12 = (unsigned __int64)&v9[v4->m_numElements * v3->m_elementSize];
  v13 = v3;
  if ( v3->m_free )
  {
    v14 = v6;
    do
    {
      if ( v10 < (hkFreeList::Element *)v9 || (unsigned __int64)v10 >= v12 )
      {
        v13 = (hkFreeList *)v10;
      }
      else
      {
        *v14 = (hkpRigidBody *)v10;
        ++v11;
        v13->m_free = v10->m_next;
        ++v14;
      }
      v10 = v10->m_next;
    }
    while ( v10 );
  }
  v15 = v3->m_top;
  if ( v15 < v9 || (unsigned __int64)v15 >= v12 )
  {
    if ( v11 == LODWORD(v4->m_numElements) )
    {
      v16 = 1;
      goto LABEL_25;
    }
  }
  else if ( v11 + (unsigned int)((v3->m_blockEnd - v15) / v3->m_elementSize) == LODWORD(v4->m_numElements) )
  {
    v3->m_top = 0i64;
    v3->m_blockEnd = 0i64;
    v16 = 1;
    goto LABEL_25;
  }
  if ( v11 > 0 )
  {
    if ( v11 > 1 )
      hkAlgorithm::quickSortRecursive<hkFreeList::Element *,hkBool (*)(hkFreeList::Element const *,hkFreeList::Element const *)>(
        v6,
        0,
        v11 - 1,
        (hkBool *(__fastcall *)(hkBool *, hkpRigidBody *, hkpRigidBody *))hkFreeList::_compareElements);
    v17 = *v6;
    for ( i = 1i64; i < v11; v17 = v19 )
    {
      v19 = v6[i++];
      v17->vfptr = (hkBaseObjectVtbl *)v19;
    }
    v6[v11 - 1]->vfptr = (hkBaseObjectVtbl *)v3->m_free;
    v3->m_free = (hkFreeList::Element *)*v6;
  }
  v16 = 0;
LABEL_25:
  v20 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v21 = (v7 + 15) & 0xFFFFFFF0;
  if ( v7 > v20->m_slabSize || (char *)v6 + v21 != v20->m_cur || v20->m_firstNonLifoEnd == v6 )
    hkLifoAllocator::slowBlockFree(v20, v6, v21);
  else
    v20->m_cur = v6;
  return v16;
}

// File Line: 375
// RVA: 0xC703A0
void __fastcall hkFreeList::_moveTopToFree(hkFreeList *this)
{
  char *v1; // rax
  hkFreeList::Element *i; // rdx

  v1 = this->m_top;
  for ( i = this->m_free; v1 < this->m_blockEnd; v1 += this->m_elementSize )
  {
    *(_QWORD *)v1 = i;
    i = (hkFreeList::Element *)v1;
  }
  this->m_free = i;
  this->m_blockEnd = 0i64;
  this->m_top = 0i64;
}

// File Line: 395
// RVA: 0xC6F760
hkBool *__fastcall hkFreeList::incrementalFindGarbage(hkFreeList *this, hkBool *result, int numBlocks, int *numBlocksOut)
{
  int v4; // esi
  int *v5; // r15
  int v6; // ebp
  hkBool *v7; // r14
  hkFreeList *i; // rbx
  hkFreeList::Block **v9; // rdi
  hkFreeList::Block *v10; // rdi

  v4 = 0;
  v5 = numBlocksOut;
  v6 = numBlocks;
  v7 = result;
  for ( i = this; v4 < v6; ++v4 )
  {
    v9 = &i->m_lastIncrementalBlock->m_next;
    if ( v9 )
    {
      v10 = *v9;
      if ( !v10 )
        goto LABEL_13;
      if ( !hkFreeList::_calcBlockFree(i, v10) )
        goto LABEL_9;
      i->m_lastIncrementalBlock->m_next = v10->m_next;
      v10->m_next = i->m_freeBlocks;
      i->m_freeBlocks = v10;
    }
    else
    {
      v10 = i->m_activeBlocks;
      if ( !v10 )
      {
LABEL_13:
        *v5 = v4;
        v7->m_bool = 1;
        i->m_lastIncrementalBlock = 0i64;
        return v7;
      }
      if ( !hkFreeList::_calcBlockFree(i, i->m_activeBlocks) )
      {
LABEL_9:
        i->m_lastIncrementalBlock = v10;
        continue;
      }
      i->m_activeBlocks = v10->m_next;
      v10->m_next = i->m_freeBlocks;
      i->m_freeBlocks = v10;
    }
  }
  *v5 = v4;
  v7->m_bool = i->m_lastIncrementalBlock == 0i64;
  return v7;
}

// File Line: 461
// RVA: 0xC6FD80
unsigned __int64 __fastcall hkFreeList::_calcNumFreeElements(hkFreeList *this)
{
  hkFreeList::Element *v1; // rax
  __int64 v2; // r8
  unsigned __int64 v3; // r8
  hkFreeList::Block *i; // rax

  v1 = this->m_free;
  v2 = 0i64;
  if ( this->m_free )
  {
    do
    {
      v1 = v1->m_next;
      ++v2;
    }
    while ( v1 );
  }
  v3 = (this->m_blockEnd - this->m_top) / this->m_elementSize + v2;
  for ( i = this->m_freeBlocks; i; i = i->m_next )
    v3 += i->m_numElements;
  return v3;
}

// File Line: 486
// RVA: 0xC6FE20
unsigned __int64 __fastcall hkFreeList::_calcTotalNumElements(hkFreeList::Block *cur)
{
  unsigned __int64 result; // rax

  for ( result = 0i64; cur; cur = cur->m_next )
    result += cur->m_numElements;
  return result;
}

// File Line: 497
// RVA: 0xC6FF00
__int64 __fastcall hkFreeList::_calculateBlockAllocatedSize(hkFreeList *this, hkFreeList::Block *cur)
{
  __int64 v2; // rdi
  hkFreeList::Block *v3; // rbx
  hkFreeList *v4; // rsi
  __int64 v5; // rdi
  int v6; // eax
  int v8; // eax

  v2 = 0i64;
  v3 = cur;
  v4 = this;
  if ( !this->m_blockAllocator )
  {
    if ( cur )
    {
      do
      {
        v8 = v4->m_elementAllocator->vfptr->getAllocatedSize(v4->m_elementAllocator, v3, v4->m_blockSize);
        v3 = v3->m_next;
        v2 += v8;
      }
      while ( v3 );
    }
    return v2;
  }
  if ( !cur )
    return v2;
  do
  {
    v5 = v4->m_blockAllocator->vfptr->getAllocatedSize(v4->m_blockAllocator, v3, 32) + v2;
    v6 = v4->m_elementAllocator->vfptr->getAllocatedSize(v4->m_elementAllocator, v3->m_elementsAlloc, v4->m_blockSize);
    v3 = v3->m_next;
    v2 = v6 + v5;
  }
  while ( v3 );
  return v2;
}

// File Line: 528
// RVA: 0xC6FDE0
unsigned __int64 __fastcall hkFreeList::_calcTotalNumElements(hkFreeList *this)
{
  hkFreeList *v1; // rbx
  unsigned __int64 v2; // rdi

  v1 = this;
  v2 = hkFreeList::_calcTotalNumElements(this->m_freeBlocks);
  return v2 + hkFreeList::_calcTotalNumElements(v1->m_activeBlocks);
}

// File Line: 533
// RVA: 0xC6F650
__int64 __fastcall hkFreeList::findGarbage(hkFreeList *this)
{
  hkFreeList *v1; // rbx
  hkFreeList::Block *v2; // rcx
  __int64 result; // rax
  hkFreeList::Element *v4; // rax
  __int64 *v5; // r9
  unsigned int v6; // edi
  __int64 *v7; // r11
  __int64 *v8; // rdx
  hkFreeList::Element *v9; // rcx
  unsigned __int64 v10; // r10
  unsigned __int64 v11; // r8
  bool v12; // zf
  __int64 *v13; // [rsp+20h] [rbp-28h]
  hkFreeList::Element *v14; // [rsp+50h] [rbp+8h]

  v1 = this;
  v2 = this->m_activeBlocks;
  if ( !v2 )
    return 0i64;
  v1->m_activeBlocks = _sortByAllocationAddress(v2);
  hkFreeList::_moveTopToFree(v1);
  v4 = hkAlgorithm::sortList<hkFreeList::Element>(v1->m_free);
  v5 = (__int64 *)v1->m_activeBlocks;
  v6 = 0;
  v7 = (__int64 *)&v13;
  v8 = (__int64 *)&v14;
  v1->m_free = v4;
  v13 = v5;
  v14 = v4;
  if ( v5 )
  {
    do
    {
      v9 = (hkFreeList::Element *)v5[2];
      v10 = v1->m_elementSize;
      v11 = (unsigned __int64)v9 + v10 * v5[3];
      if ( v9 == v4 )
      {
        while ( 1 )
        {
          v12 = v9 == (hkFreeList::Element *)v11;
          if ( (unsigned __int64)v9 >= v11 )
            break;
          v4 = v4->m_next;
          v9 = (hkFreeList::Element *)((char *)v9 + v10);
          if ( v9 != v4 )
            goto LABEL_7;
        }
      }
      else
      {
LABEL_7:
        v12 = v9 == (hkFreeList::Element *)v11;
      }
      if ( v12 )
      {
        ++v6;
        *v7 = *v5;
        *v5 = (__int64)v1->m_freeBlocks;
        v1->m_freeBlocks = (hkFreeList::Block *)v5;
        v5 = (__int64 *)*v7;
        *v8 = (__int64)v4;
      }
      else
      {
        for ( ; v4; v4 = v4->m_next )
        {
          if ( (unsigned __int64)v4 >= v11 )
            break;
        }
        for ( ; (hkFreeList::Element *)*v8 != v4; v8 = (__int64 *)*v8 )
          ;
        v7 = v5;
        v5 = (__int64 *)*v5;
      }
    }
    while ( v5 );
    v5 = v13;
    v4 = v14;
  }
  v1->m_free = v4;
  result = v6;
  v1->m_activeBlocks = (hkFreeList::Block *)v5;
  v1->m_lastIncrementalBlock = 0i64;
  return result;
}

// File Line: 625
// RVA: 0xC70070
void __fastcall hkFreeList::_walkMemoryBlockList(hkFreeList *this, hkFreeList::Block *block, void (__fastcall *callback)(void *, unsigned __int64, bool, int, void *), int pool, void *param)
{
  unsigned __int64 v5; // rax
  unsigned int v6; // er15
  void (__fastcall *v7)(void *, unsigned __int64, bool, int, void *); // r12
  hkFreeList::Block *v8; // rsi
  hkFreeList *v9; // rbp
  char *v10; // rbx
  unsigned __int64 i; // rdi

  if ( block )
  {
    v5 = this->m_elementSize;
    v6 = pool;
    v7 = callback;
    v8 = block;
    v9 = this;
    do
    {
      v10 = v8->m_elements;
      for ( i = (unsigned __int64)&v10[v5 * v8->m_numElements]; (unsigned __int64)v10 < i; v10 += v5 )
      {
        v7(v10, v5, 0, v6, param);
        v5 = v9->m_elementSize;
      }
      v8 = v8->m_next;
    }
    while ( v8 );
  }
}

// File Line: 642
// RVA: 0xC6F9F0
void __fastcall hkFreeList::walkMemory(hkFreeList *this, void (__fastcall *callback)(void *, unsigned __int64, bool, int, void *), int pool, void *param)
{
  void *v4; // rbp
  unsigned int v5; // er15
  void (__fastcall *v6)(void *, unsigned __int64, bool, int, void *); // r12
  hkFreeList *v7; // r14
  hkFreeList::Block *v8; // rcx
  hkFreeList::Element *v9; // rax
  _BOOL8 v10; // r8
  hkFreeList::Block *v11; // r13
  hkFreeList::Element *v12; // rdi
  hkFreeList::Element *v13; // rbx
  unsigned __int64 v14; // rcx
  hkFreeList::Element *i; // rsi

  v4 = param;
  v5 = pool;
  v6 = callback;
  v7 = this;
  hkFreeList::_walkMemoryBlockList(this, this->m_freeBlocks, callback, pool, param);
  v8 = v7->m_activeBlocks;
  if ( v8 || v7->m_free )
  {
    v7->m_activeBlocks = _sortByAllocationAddress(v8);
    hkFreeList::_moveTopToFree(v7);
    v9 = hkAlgorithm::sortList<hkFreeList::Element>(v7->m_free);
    v11 = v7->m_activeBlocks;
    v12 = v9;
    for ( v7->m_free = v9; v11; v11 = v11->m_next )
    {
      v13 = (hkFreeList::Element *)v11->m_elements;
      v14 = v7->m_elementSize;
      for ( i = (hkFreeList::Element *)((char *)v13 + v14 * v11->m_numElements);
            v13 < i;
            v13 = (hkFreeList::Element *)((char *)v13 + v14) )
      {
        if ( v13 == v12 )
        {
          v6(v13, v14, 0, v5, v4);
          v12 = v12->m_next;
        }
        else
        {
          LOBYTE(v10) = 1;
          v6(v13, v14, v10, v5, v4);
        }
        v14 = v7->m_elementSize;
      }
    }
  }
}

// File Line: 690
// RVA: 0xC6F880
__int64 __fastcall hkFreeList::addToSnapshot(hkFreeList *this, hkMemorySnapshot *snap, hkEnum<enum hkMemorySnapshot::StatusBits,signed char> usage, int parentId)
{
  int v4; // er15
  hkMemorySnapshot *v5; // r12
  hkFreeList *v6; // rsi
  hkFreeList::Block *v7; // r14
  unsigned __int64 v8; // rax
  char *v9; // rdi
  char *i; // rbp
  hkFreeList::Block *v11; // rcx
  hkFreeList::Element *v12; // rax
  hkFreeList::Block *v13; // r13
  hkFreeList::Element *v14; // r14
  char *v15; // rdi
  char *j; // rbp
  int size; // [rsp+20h] [rbp-48h]
  char v19; // [rsp+70h] [rbp+8h]
  char v20; // [rsp+80h] [rbp+18h]

  v20 = usage.m_storage;
  v4 = parentId;
  v5 = snap;
  v6 = this;
  v19 = 2;
  if ( usage.m_storage != 1 )
    v19 = usage.m_storage;
  v7 = this->m_freeBlocks;
  if ( v7 )
  {
    v8 = this->m_elementSize;
    do
    {
      v9 = v7->m_elements;
      for ( i = &v9[v8 * v7->m_numElements]; v9 < i; v9 += v8 )
      {
        hkMemorySnapshot::addItem(
          v5,
          v4,
          (hkEnum<enum hkMemorySnapshot::StatusBits,signed char>)v19,
          v9,
          v6->m_elementSize);
        v8 = v6->m_elementSize;
      }
      v7 = v7->m_next;
    }
    while ( v7 );
  }
  v11 = v6->m_activeBlocks;
  if ( v11 || v6->m_free )
  {
    v6->m_activeBlocks = _sortByAllocationAddress(v11);
    hkFreeList::_moveTopToFree(v6);
    v12 = hkAlgorithm::sortList<hkFreeList::Element>(v6->m_free);
    v13 = v6->m_activeBlocks;
    v14 = v12;
    for ( v6->m_free = v12; v13; v13 = v13->m_next )
    {
      v15 = v13->m_elements;
      for ( j = &v15[v6->m_elementSize * v13->m_numElements]; v15 < j; v15 += v6->m_elementSize )
      {
        size = v6->m_elementSize;
        if ( v15 == (char *)v14 )
        {
          hkMemorySnapshot::addItem(v5, v4, (hkEnum<enum hkMemorySnapshot::StatusBits,signed char>)v19, v15, size);
          v14 = v14->m_next;
        }
        else
        {
          hkMemorySnapshot::addItem(v5, v4, (hkEnum<enum hkMemorySnapshot::StatusBits,signed char>)v20, v15, size);
        }
      }
    }
  }
  return 0i64;
}

// File Line: 759
// RVA: 0xC6F850
int __fastcall hkFreeList::freeAllFreeBlocks(hkFreeList *this)
{
  hkFreeList *v1; // rbx
  int result; // eax

  v1 = this;
  result = hkFreeList::_freeBlocks(this, this->m_freeBlocks);
  v1->m_freeBlocks = 0i64;
  return result;
}

// File Line: 767
// RVA: 0xC6FBA0
char *__fastcall hkFreeList::addSpace(hkFreeList *this)
{
  hkFreeList *v1; // rbx
  hkFreeList::Block *v2; // rcx
  char *result; // rax
  unsigned __int64 v4; // rdx
  unsigned __int64 v5; // rcx
  unsigned __int64 v6; // rax
  hkMemoryAllocator *v7; // rcx
  hkFreeList::Block *v8; // rdi
  hkMemoryAllocator *v9; // rcx
  __int64 v10; // rax
  signed __int64 v11; // rcx
  signed __int64 v12; // r8
  unsigned __int64 v13; // rax
  hkMemoryAllocator *v14; // rcx
  unsigned __int64 v15; // rax
  unsigned __int64 v16; // rdx
  int v17; // [rsp+30h] [rbp+8h]
  int v18; // [rsp+38h] [rbp+10h]

  v1 = this;
  v2 = this->m_freeBlocks;
  if ( v2 )
  {
    v1->m_freeBlocks = v2->m_next;
    v1->m_top = v2->m_elements;
    v1->m_blockEnd = &v2->m_elements[v1->m_elementSize * v2->m_numElements];
    v2->m_next = v1->m_activeBlocks;
    result = v1->m_top;
    v4 = v1->m_elementSize;
    --v1->m_numFreeElements;
    v1->m_activeBlocks = v2;
    v1->m_top = &result[v4];
    return result;
  }
  if ( !v1->m_blockSize )
  {
    v5 = v1->m_elementSize;
    v6 = 0x100 / v5;
    if ( 0x100 / v5 < 1 )
      v6 = 1i64;
    v1->m_blockSize = hkFreeList::bestBlockSize(v6 * v5, v1->m_align);
  }
  v7 = v1->m_blockAllocator;
  if ( !v7 )
  {
    v14 = v1->m_elementAllocator;
    v18 = v1->m_blockSize;
    v8 = (hkFreeList::Block *)v14->vfptr->bufAlloc(v14, &v18);
    if ( !v8 )
      return 0i64;
    v15 = v1->m_align;
    v8->m_elementsAlloc = 0i64;
    v11 = ~(v15 - 1) & ((unsigned __int64)&v8->m_numElements + v15 + 7);
    v13 = ((unsigned __int64)v8 + v18 - v11) / v1->m_elementSize;
    goto LABEL_18;
  }
  v8 = (hkFreeList::Block *)(*((__int64 (__fastcall **)(hkMemoryAllocator *, signed __int64))&v7->vfptr->__vecDelDtor + 1))(
                              v7,
                              32i64);
  if ( !v8 )
    return 0i64;
  v9 = v1->m_elementAllocator;
  v17 = v1->m_blockSize;
  v10 = (__int64)v9->vfptr->bufAlloc(v9, &v17);
  v11 = v10;
  if ( !v10 )
  {
    v1->m_blockAllocator->vfptr->blockFree(v1->m_blockAllocator, v8, 32);
    return 0i64;
  }
  v8->m_elementsAlloc = (char *)v10;
  v12 = ~(v1->m_align - 1) & (v10 + v1->m_align - 1);
  if ( v12 == v10 && v17 == LODWORD(v1->m_blockSize) )
  {
    v13 = v1->m_numBlockElements;
LABEL_18:
    v8->m_elements = (char *)v11;
    goto LABEL_19;
  }
  v13 = (v10 + v17 - v12) / v1->m_elementSize;
  v8->m_elements = (char *)v12;
LABEL_19:
  v8->m_numElements = v13;
  v1->m_top = v8->m_elements;
  v1->m_blockEnd = &v8->m_elements[v1->m_elementSize * v8->m_numElements];
  v8->m_next = v1->m_activeBlocks;
  v16 = v1->m_elementSize;
  v1->m_activeBlocks = v8;
  v1->m_totalNumElements += v8->m_numElements;
  v1->m_numFreeElements += v8->m_numElements - 1;
  result = v1->m_top;
  v1->m_top = &result[v16];
  return result;
}

// File Line: 916
// RVA: 0xC6FAF0
unsigned __int64 __fastcall hkFreeList::bestBlockSize(unsigned __int64 elementSpace, unsigned __int64 align)
{
  unsigned __int64 result; // rax

  if ( align > 0x10 )
    result = elementSpace + align + 16;
  else
    result = elementSpace + 32;
  return result;
}

// File Line: 923
// RVA: 0xC6F580
void __fastcall hkFreeList::freeAll(hkFreeList *this)
{
  hkFreeList::Block *v1; // rax
  hkFreeList::Block *v2; // rax

  this->m_numFreeElements = this->m_totalNumElements;
  v1 = this->m_activeBlocks;
  if ( v1 )
  {
    for ( this->m_free = 0i64; v1->m_next; v1 = v1->m_next )
      ;
    v1->m_next = this->m_freeBlocks;
    v2 = this->m_activeBlocks;
    this->m_activeBlocks = 0i64;
    this->m_top = 0i64;
    this->m_blockEnd = 0i64;
    this->m_lastIncrementalBlock = 0i64;
    this->m_freeBlocks = v2;
  }
}

// File Line: 959
// RVA: 0xC6F5D0
void __fastcall hkFreeList::getMemoryStatistics(hkFreeList *this, hkMemoryAllocator::MemoryStatistics *stats)
{
  hkMemoryAllocator::MemoryStatistics *v2; // rsi
  hkFreeList *v3; // rdi
  unsigned __int64 v4; // rbx
  unsigned __int64 v5; // rax
  unsigned __int64 v6; // r8
  __int64 v7; // rcx
  __int64 v8; // rax

  v2 = stats;
  v3 = this;
  v4 = hkFreeList::_calculateBlockAllocatedSize(this, this->m_freeBlocks);
  v2->m_allocated = hkFreeList::_calculateBlockAllocatedSize(v3, v3->m_activeBlocks) + v4;
  v5 = v3->m_numFreeElements;
  v6 = v3->m_totalNumElements;
  v7 = v5 * v3->m_elementSize;
  v2->m_available = v7;
  v2->m_inUse = v3->m_elementSize * (v6 - v5);
  v8 = v3->m_elementSize;
  v2->m_totalAvailable = v7;
  v2->m_largestBlock = v8;
}

// File Line: 980
// RVA: 0xC6FB40
signed __int64 __fastcall hkFreeList::_getSortedBlockHeads(hkFreeList *this, hkFreeList::Block **heads, int numHeads)
{
  hkFreeList *v3; // rbx
  hkFreeList::Block **v4; // rdi
  hkFreeList::Element *v5; // rax
  hkFreeList::Element *v6; // rcx
  hkFreeList::Element *v7; // rax
  hkFreeList::Block *v8; // rcx
  signed __int64 result; // rax
  hkFreeList::Block *v10; // rdx
  __int64 v11; // rcx

  v3 = this;
  v4 = heads;
  v5 = hkAlgorithm::sortList<hkFreeList::Element>((hkFreeList::Element *)this->m_activeBlocks);
  v6 = (hkFreeList::Element *)v3->m_freeBlocks;
  v3->m_activeBlocks = (hkFreeList::Block *)v5;
  v7 = hkAlgorithm::sortList<hkFreeList::Element>(v6);
  v8 = v3->m_activeBlocks;
  v3->m_freeBlocks = (hkFreeList::Block *)v7;
  result = 0i64;
  if ( v8 )
  {
    *v4 = v8;
    result = 1i64;
  }
  v10 = v3->m_freeBlocks;
  if ( v10 )
  {
    v11 = (signed int)result;
    result = (unsigned int)(result + 1);
    v4[v11] = v10;
  }
  return result;
}

