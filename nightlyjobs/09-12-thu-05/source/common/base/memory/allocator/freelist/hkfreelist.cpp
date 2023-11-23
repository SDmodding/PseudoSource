// File Line: 16
// RVA: 0xC703E0
hkFreeList::Block *__fastcall _sortByAllocationAddress(hkFreeList::Block *headPtr)
{
  hkFreeList::Block *v1; // r8
  int i; // r11d
  int v4; // ebx
  __int64 *v5; // r10
  hkFreeList::Block *v6; // rax
  int j; // edx
  int v8; // r9d
  __int64 *v9; // rcx
  hkFreeList::Block *v10; // [rsp+0h] [rbp-28h] BYREF

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
              goto LABEL_17;
          }
          do
          {
            *v5 = (__int64)v1;
            --j;
            v5 = (__int64 *)v1;
            v1 = v1->m_next;
          }
          while ( j > 0 );
        }
LABEL_17:
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
void __fastcall hkFreeList::hkFreeList(
        hkFreeList *this,
        unsigned __int64 elementSize,
        unsigned __int64 align,
        unsigned __int64 blockSize,
        hkMemoryAllocator *elementAllocator,
        hkMemoryAllocator *blockAllocator)
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
void __fastcall hkFreeList::_init(
        hkFreeList *this,
        unsigned __int64 elementSize,
        unsigned __int64 align,
        unsigned __int64 blockSize,
        hkMemoryAllocator *elementAllocator,
        hkMemoryAllocator *blockAllocator)
{
  hkMemoryAllocator *v6; // rax

  v6 = elementAllocator;
  if ( !elementAllocator )
    v6 = (hkMemoryAllocator *)*((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
  this->m_elementAllocator = v6;
  this->m_free = 0i64;
  this->m_activeBlocks = 0i64;
  this->m_freeBlocks = 0i64;
  this->m_blockAllocator = blockAllocator;
  this->m_blockSize = blockSize;
  this->m_align = align;
  this->m_top = 0i64;
  this->m_blockEnd = 0i64;
  this->m_numFreeElements = 0i64;
  this->m_totalNumElements = 0i64;
  this->m_lastIncrementalBlock = 0i64;
  if ( elementSize >= align )
    align = (elementSize + align - 1) & ~(align - 1);
  this->m_elementSize = align;
  this->m_numBlockElements = blockSize / align;
}

// File Line: 169
// RVA: 0xC6F4D0
void __fastcall hkFreeList::init(
        hkFreeList *this,
        unsigned __int64 elementSize,
        unsigned __int64 align,
        unsigned __int64 blockSize,
        hkMemoryAllocator *elementAllocator,
        hkMemoryAllocator *blockAllocator)
{
  hkFreeList::freeAllMemory(this);
  hkFreeList::_init(this, elementSize, align, blockSize, elementAllocator, blockAllocator);
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
  hkFreeList::Element *m_free; // r8
  hkFreeList::Block *m_activeBlocks; // rax
  char *m_elements; // rdx

  if ( hkFreeList::_calcNumFreeElements(this) != this->m_numFreeElements
    || hkFreeList::_calcTotalNumElements(this) != this->m_totalNumElements )
  {
LABEL_2:
    result->m_bool = 0;
    return result;
  }
  m_free = this->m_free;
  if ( this->m_free )
  {
    while ( ((this->m_align - 1) & (unsigned __int64)m_free) == 0 )
    {
      m_activeBlocks = this->m_activeBlocks;
      if ( !m_activeBlocks )
        break;
      while ( 1 )
      {
        m_elements = m_activeBlocks->m_elements;
        if ( m_free >= (hkFreeList::Element *)m_elements
          && m_free < (hkFreeList::Element *)&m_elements[this->m_elementSize * m_activeBlocks->m_numElements] )
        {
          break;
        }
        m_activeBlocks = m_activeBlocks->m_next;
        if ( !m_activeBlocks )
        {
          result->m_bool = 0;
          return result;
        }
      }
      if ( ((char *)m_free - m_elements) % this->m_elementSize )
        break;
      m_free = m_free->m_next;
      if ( !m_free )
        goto LABEL_13;
    }
    goto LABEL_2;
  }
LABEL_13:
  result->m_bool = 1;
  return result;
}

// File Line: 243
// RVA: 0xC6FE50
__int64 __fastcall hkFreeList::_freeBlocks(hkFreeList *this, hkFreeList::Block *cur)
{
  unsigned int v2; // ebp
  hkFreeList::Block *v3; // rdi
  hkMemoryAllocator *m_elementAllocator; // rcx
  __int64 m_blockSize_low; // r8
  hkFreeList::Block *m_next; // rsi

  v2 = 0;
  v3 = cur;
  if ( cur )
  {
    do
    {
      m_elementAllocator = this->m_elementAllocator;
      m_blockSize_low = LODWORD(this->m_blockSize);
      this->m_totalNumElements -= v3->m_numElements;
      ++v2;
      this->m_numFreeElements -= v3->m_numElements;
      m_next = v3->m_next;
      if ( this->m_blockAllocator )
      {
        m_elementAllocator->vfptr->bufFree(m_elementAllocator, v3->m_elementsAlloc, m_blockSize_low);
        this->m_blockAllocator->vfptr->blockFree(this->m_blockAllocator, v3, 32);
      }
      else
      {
        m_elementAllocator->vfptr->bufFree(m_elementAllocator, v3, m_blockSize_low);
      }
      v3 = m_next;
    }
    while ( m_next );
  }
  return v2;
}

// File Line: 277
// RVA: 0xC6F520
void __fastcall hkFreeList::freeAllMemory(hkFreeList *this)
{
  hkFreeList::Block *m_freeBlocks; // rdx

  hkFreeList::_freeBlocks(this, this->m_activeBlocks);
  m_freeBlocks = this->m_freeBlocks;
  this->m_activeBlocks = 0i64;
  hkFreeList::_freeBlocks(this, m_freeBlocks);
  this->m_freeBlocks = 0i64;
  this->m_free = 0i64;
  this->m_blockSize = 0i64;
  this->m_numFreeElements = 0i64;
  this->m_totalNumElements = 0i64;
  this->m_top = 0i64;
  this->m_blockEnd = 0i64;
  this->m_lastIncrementalBlock = 0i64;
}

// File Line: 299
// RVA: 0xC701F0
__int64 __fastcall hkFreeList::_calcBlockFree(hkFreeList *this, hkFreeList::Block *block)
{
  int m_numElements; // ebx
  hkLifoAllocator *Value; // rax
  hkpRigidBody **m_cur; // rdi
  int v7; // r15d
  char *v8; // rcx
  char *m_elements; // r10
  hkFreeList::Element *m_free; // rcx
  int v11; // esi
  char *v12; // r9
  hkFreeList *v13; // r8
  _QWORD *v14; // rdx
  char *m_top; // rcx
  unsigned int v16; // ebx
  hkpRigidBody *v17; // rcx
  __int64 i; // rbx
  hkpRigidBody *v19; // rax
  hkLifoAllocator *v20; // rax
  int v21; // r8d

  m_numElements = block->m_numElements;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (hkpRigidBody **)Value->m_cur;
  v7 = (8 * m_numElements + 127) & 0xFFFFFF80;
  v8 = (char *)m_cur + v7;
  if ( v7 > Value->m_slabSize || v8 > Value->m_end )
    m_cur = (hkpRigidBody **)hkLifoAllocator::allocateFromNewSlab(Value, v7);
  else
    Value->m_cur = v8;
  m_elements = block->m_elements;
  m_free = this->m_free;
  v11 = 0;
  v12 = &m_elements[block->m_numElements * this->m_elementSize];
  v13 = this;
  if ( this->m_free )
  {
    v14 = m_cur;
    do
    {
      if ( m_free < (hkFreeList::Element *)m_elements || m_free >= (hkFreeList::Element *)v12 )
      {
        v13 = (hkFreeList *)m_free;
      }
      else
      {
        *v14 = m_free;
        ++v11;
        v13->m_free = m_free->m_next;
        ++v14;
      }
      m_free = m_free->m_next;
    }
    while ( m_free );
  }
  m_top = this->m_top;
  if ( m_top < m_elements || m_top >= v12 )
  {
    if ( v11 == LODWORD(block->m_numElements) )
    {
      v16 = 1;
      goto LABEL_25;
    }
  }
  else if ( v11 + (unsigned int)((this->m_blockEnd - m_top) / this->m_elementSize) == LODWORD(block->m_numElements) )
  {
    this->m_top = 0i64;
    this->m_blockEnd = 0i64;
    v16 = 1;
    goto LABEL_25;
  }
  if ( v11 > 0 )
  {
    if ( v11 > 1 )
      hkAlgorithm::quickSortRecursive<hkFreeList::Element *,hkBool (*)(hkFreeList::Element const *,hkFreeList::Element const *)>(
        m_cur,
        0,
        v11 - 1,
        (hkBool *(__fastcall *)(hkBool *, hkpRigidBody *, hkpRigidBody *))hkFreeList::_compareElements);
    v17 = *m_cur;
    for ( i = 1i64; i < v11; v17 = v19 )
    {
      v19 = m_cur[i++];
      v17->vfptr = (hkBaseObjectVtbl *)v19;
    }
    m_cur[v11 - 1]->vfptr = (hkBaseObjectVtbl *)this->m_free;
    this->m_free = (hkFreeList::Element *)*m_cur;
  }
  v16 = 0;
LABEL_25:
  v20 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v21 = (v7 + 15) & 0xFFFFFFF0;
  if ( v7 > v20->m_slabSize || (char *)m_cur + v21 != v20->m_cur || v20->m_firstNonLifoEnd == m_cur )
    hkLifoAllocator::slowBlockFree(v20, (char *)m_cur, v21);
  else
    v20->m_cur = m_cur;
  return v16;
}

// File Line: 375
// RVA: 0xC703A0
void __fastcall hkFreeList::_moveTopToFree(hkFreeList *this)
{
  char *m_top; // rax
  hkFreeList::Element *i; // rdx

  m_top = this->m_top;
  for ( i = this->m_free; m_top < this->m_blockEnd; m_top += this->m_elementSize )
  {
    *(_QWORD *)m_top = i;
    i = (hkFreeList::Element *)m_top;
  }
  this->m_free = i;
  this->m_blockEnd = 0i64;
  this->m_top = 0i64;
}

// File Line: 395
// RVA: 0xC6F760
hkBool *__fastcall hkFreeList::incrementalFindGarbage(
        hkFreeList *this,
        hkBool *result,
        int numBlocks,
        int *numBlocksOut)
{
  int i; // esi
  hkFreeList::Block *m_lastIncrementalBlock; // rdi
  hkFreeList::Block *m_next; // rdi

  for ( i = 0; i < numBlocks; ++i )
  {
    m_lastIncrementalBlock = this->m_lastIncrementalBlock;
    if ( m_lastIncrementalBlock )
    {
      m_next = m_lastIncrementalBlock->m_next;
      if ( !m_next )
        goto LABEL_13;
      if ( !hkFreeList::_calcBlockFree(this, m_next) )
        goto LABEL_9;
      this->m_lastIncrementalBlock->m_next = m_next->m_next;
      m_next->m_next = this->m_freeBlocks;
      this->m_freeBlocks = m_next;
    }
    else
    {
      m_next = this->m_activeBlocks;
      if ( !m_next )
      {
LABEL_13:
        *numBlocksOut = i;
        result->m_bool = 1;
        this->m_lastIncrementalBlock = 0i64;
        return result;
      }
      if ( !hkFreeList::_calcBlockFree(this, this->m_activeBlocks) )
      {
LABEL_9:
        this->m_lastIncrementalBlock = m_next;
        continue;
      }
      this->m_activeBlocks = m_next->m_next;
      m_next->m_next = this->m_freeBlocks;
      this->m_freeBlocks = m_next;
    }
  }
  *numBlocksOut = i;
  result->m_bool = this->m_lastIncrementalBlock == 0i64;
  return result;
}

// File Line: 461
// RVA: 0xC6FD80
__int64 __fastcall hkFreeList::_calcNumFreeElements(hkFreeList *this)
{
  hkFreeList::Element *m_free; // rax
  __int64 i; // r8
  __int64 v3; // r8
  hkFreeList::Block *j; // rax

  m_free = this->m_free;
  for ( i = 0i64; m_free; ++i )
    m_free = m_free->m_next;
  v3 = (this->m_blockEnd - this->m_top) / this->m_elementSize + i;
  for ( j = this->m_freeBlocks; j; j = j->m_next )
    v3 += j->m_numElements;
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
  __int64 v5; // rdi
  int v6; // eax
  int v8; // eax

  v2 = 0i64;
  v3 = cur;
  if ( !this->m_blockAllocator )
  {
    if ( cur )
    {
      do
      {
        v8 = this->m_elementAllocator->vfptr->getAllocatedSize(this->m_elementAllocator, v3, this->m_blockSize);
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
    v5 = this->m_blockAllocator->vfptr->getAllocatedSize(this->m_blockAllocator, v3, 32) + v2;
    v6 = this->m_elementAllocator->vfptr->getAllocatedSize(
           this->m_elementAllocator,
           v3->m_elementsAlloc,
           this->m_blockSize);
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
  unsigned __int64 v2; // rdi

  v2 = hkFreeList::_calcTotalNumElements(this->m_freeBlocks);
  return v2 + hkFreeList::_calcTotalNumElements(this->m_activeBlocks);
}

// File Line: 533
// RVA: 0xC6F650
__int64 __fastcall hkFreeList::findGarbage(hkFreeList *this)
{
  hkFreeList::Block *m_activeBlocks; // rcx
  __int64 result; // rax
  hkFreeList::Element *v4; // rax
  hkFreeList::Block *v5; // r9
  unsigned int v6; // edi
  __int64 *v7; // r11
  __int64 *v8; // rdx
  char *m_elements; // rcx
  unsigned __int64 m_elementSize; // r10
  unsigned __int64 v11; // r8
  bool v12; // zf
  hkFreeList::Block *v13; // [rsp+20h] [rbp-28h] BYREF
  hkFreeList::Element *v14; // [rsp+50h] [rbp+8h] BYREF

  m_activeBlocks = this->m_activeBlocks;
  if ( !m_activeBlocks )
    return 0i64;
  this->m_activeBlocks = _sortByAllocationAddress(m_activeBlocks);
  hkFreeList::_moveTopToFree(this);
  v4 = hkAlgorithm::sortList<hkFreeList::Element>(this->m_free);
  v5 = this->m_activeBlocks;
  v6 = 0;
  v7 = (__int64 *)&v13;
  v8 = (__int64 *)&v14;
  this->m_free = v4;
  v13 = v5;
  v14 = v4;
  if ( v5 )
  {
    do
    {
      m_elements = v5->m_elements;
      m_elementSize = this->m_elementSize;
      v11 = (unsigned __int64)&m_elements[m_elementSize * v5->m_numElements];
      if ( m_elements == (char *)v4 )
      {
        while ( 1 )
        {
          v12 = m_elements == (char *)v11;
          if ( (unsigned __int64)m_elements >= v11 )
            break;
          v4 = v4->m_next;
          m_elements += m_elementSize;
          if ( m_elements != (char *)v4 )
            goto LABEL_7;
        }
      }
      else
      {
LABEL_7:
        v12 = m_elements == (char *)v11;
      }
      if ( v12 )
      {
        ++v6;
        *v7 = (__int64)v5->m_next;
        v5->m_next = this->m_freeBlocks;
        this->m_freeBlocks = v5;
        v5 = (hkFreeList::Block *)*v7;
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
        v7 = (__int64 *)v5;
        v5 = v5->m_next;
      }
    }
    while ( v5 );
    v5 = v13;
    v4 = v14;
  }
  this->m_free = v4;
  result = v6;
  this->m_activeBlocks = v5;
  this->m_lastIncrementalBlock = 0i64;
  return result;
}

// File Line: 625
// RVA: 0xC70070
void __fastcall hkFreeList::_walkMemoryBlockList(
        hkFreeList *this,
        hkFreeList::Block *block,
        void (__fastcall *callback)(void *, unsigned __int64, bool, int, void *),
        int pool,
        void *param)
{
  unsigned __int64 m_elementSize; // rax
  hkFreeList::Block *v8; // rsi
  char *m_elements; // rbx
  char *i; // rdi

  if ( block )
  {
    m_elementSize = this->m_elementSize;
    v8 = block;
    do
    {
      m_elements = v8->m_elements;
      for ( i = &m_elements[m_elementSize * v8->m_numElements]; m_elements < i; m_elements += m_elementSize )
      {
        callback(m_elements, m_elementSize, 0, pool, param);
        m_elementSize = this->m_elementSize;
      }
      v8 = v8->m_next;
    }
    while ( v8 );
  }
}

// File Line: 642
// RVA: 0xC6F9F0
void __fastcall hkFreeList::walkMemory(
        hkFreeList *this,
        void (__fastcall *callback)(void *, unsigned __int64, bool, int, void *),
        int pool,
        void *param)
{
  hkFreeList::Block *m_activeBlocks; // rcx
  hkFreeList::Element *v9; // rax
  _BOOL8 v10; // r8
  hkFreeList::Block *v11; // r13
  hkFreeList::Element *v12; // rdi
  char *m_elements; // rbx
  unsigned __int64 m_elementSize; // rcx
  char *i; // rsi

  hkFreeList::_walkMemoryBlockList(this, this->m_freeBlocks, callback, pool, param);
  m_activeBlocks = this->m_activeBlocks;
  if ( m_activeBlocks || this->m_free )
  {
    this->m_activeBlocks = _sortByAllocationAddress(m_activeBlocks);
    hkFreeList::_moveTopToFree(this);
    v9 = hkAlgorithm::sortList<hkFreeList::Element>(this->m_free);
    v11 = this->m_activeBlocks;
    v12 = v9;
    for ( this->m_free = v9; v11; v11 = v11->m_next )
    {
      m_elements = v11->m_elements;
      m_elementSize = this->m_elementSize;
      for ( i = &m_elements[m_elementSize * v11->m_numElements]; m_elements < i; m_elements += m_elementSize )
      {
        if ( m_elements == (char *)v12 )
        {
          callback(m_elements, m_elementSize, 0, pool, param);
          v12 = v12->m_next;
        }
        else
        {
          LOBYTE(v10) = 1;
          callback(m_elements, m_elementSize, v10, pool, param);
        }
        m_elementSize = this->m_elementSize;
      }
    }
  }
}

// File Line: 690
// RVA: 0xC6F880
__int64 __fastcall hkFreeList::addToSnapshot(
        hkFreeList *this,
        hkMemorySnapshot *snap,
        hkEnum<enum hkMemorySnapshot::StatusBits,signed char> usage,
        int parentId)
{
  hkFreeList::Block *m_freeBlocks; // r14
  unsigned __int64 m_elementSize; // rax
  char *m_elements; // rdi
  char *i; // rbp
  hkFreeList::Block *m_activeBlocks; // rcx
  hkFreeList::Element *v12; // rax
  hkFreeList::Block *v13; // r13
  hkFreeList::Element *v14; // r14
  char *v15; // rdi
  char *j; // rbp
  int size; // [rsp+20h] [rbp-48h]
  char m_storage; // [rsp+70h] [rbp+8h]

  m_storage = 2;
  if ( usage.m_storage != 1 )
    m_storage = usage.m_storage;
  m_freeBlocks = this->m_freeBlocks;
  if ( m_freeBlocks )
  {
    m_elementSize = this->m_elementSize;
    do
    {
      m_elements = m_freeBlocks->m_elements;
      for ( i = &m_elements[m_elementSize * m_freeBlocks->m_numElements]; m_elements < i; m_elements += m_elementSize )
      {
        hkMemorySnapshot::addItem(
          snap,
          parentId,
          (hkEnum<enum hkMemorySnapshot::StatusBits,signed char>)m_storage,
          m_elements,
          this->m_elementSize);
        m_elementSize = this->m_elementSize;
      }
      m_freeBlocks = m_freeBlocks->m_next;
    }
    while ( m_freeBlocks );
  }
  m_activeBlocks = this->m_activeBlocks;
  if ( m_activeBlocks || this->m_free )
  {
    this->m_activeBlocks = _sortByAllocationAddress(m_activeBlocks);
    hkFreeList::_moveTopToFree(this);
    v12 = hkAlgorithm::sortList<hkFreeList::Element>(this->m_free);
    v13 = this->m_activeBlocks;
    v14 = v12;
    for ( this->m_free = v12; v13; v13 = v13->m_next )
    {
      v15 = v13->m_elements;
      for ( j = &v15[this->m_elementSize * v13->m_numElements]; v15 < j; v15 += this->m_elementSize )
      {
        size = this->m_elementSize;
        if ( v15 == (char *)v14 )
        {
          hkMemorySnapshot::addItem(
            snap,
            parentId,
            (hkEnum<enum hkMemorySnapshot::StatusBits,signed char>)m_storage,
            v15,
            size);
          v14 = v14->m_next;
        }
        else
        {
          hkMemorySnapshot::addItem(snap, parentId, usage, v15, size);
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
  int result; // eax

  result = hkFreeList::_freeBlocks(this, this->m_freeBlocks);
  this->m_freeBlocks = 0i64;
  return result;
}

// File Line: 767
// RVA: 0xC6FBA0
char *__fastcall hkFreeList::addSpace(hkFreeList *this)
{
  hkFreeList::Block *m_freeBlocks; // rcx
  char *result; // rax
  unsigned __int64 m_elementSize; // rdx
  unsigned __int64 v5; // rcx
  unsigned __int64 v6; // rax
  hkMemoryAllocator *m_blockAllocator; // rcx
  hkFreeList::Block *v8; // rdi
  hkMemoryAllocator *v9; // rcx
  __int64 v10; // rax
  __int64 v11; // rcx
  unsigned __int64 v12; // r8
  unsigned __int64 m_numBlockElements; // rax
  hkMemoryAllocator *m_elementAllocator; // rcx
  unsigned __int64 m_align; // rax
  unsigned __int64 v16; // rdx
  int v17; // [rsp+30h] [rbp+8h] BYREF
  int m_blockSize; // [rsp+38h] [rbp+10h] BYREF

  m_freeBlocks = this->m_freeBlocks;
  if ( m_freeBlocks )
  {
    this->m_freeBlocks = m_freeBlocks->m_next;
    this->m_top = m_freeBlocks->m_elements;
    this->m_blockEnd = &m_freeBlocks->m_elements[this->m_elementSize * m_freeBlocks->m_numElements];
    m_freeBlocks->m_next = this->m_activeBlocks;
    result = this->m_top;
    m_elementSize = this->m_elementSize;
    --this->m_numFreeElements;
    this->m_activeBlocks = m_freeBlocks;
    this->m_top = &result[m_elementSize];
    return result;
  }
  if ( !this->m_blockSize )
  {
    v5 = this->m_elementSize;
    v6 = 0x100 / v5;
    if ( !(0x100 / v5) )
      v6 = 1i64;
    this->m_blockSize = hkFreeList::bestBlockSize(v6 * v5, this->m_align);
  }
  m_blockAllocator = this->m_blockAllocator;
  if ( !m_blockAllocator )
  {
    m_elementAllocator = this->m_elementAllocator;
    m_blockSize = this->m_blockSize;
    v8 = (hkFreeList::Block *)m_elementAllocator->vfptr->bufAlloc(m_elementAllocator, &m_blockSize);
    if ( !v8 )
      return 0i64;
    m_align = this->m_align;
    v8->m_elementsAlloc = 0i64;
    v11 = ~(m_align - 1) & ((unsigned __int64)&v8->m_numElements + m_align + 7);
    m_numBlockElements = ((unsigned __int64)v8 + m_blockSize - v11) / this->m_elementSize;
    goto LABEL_18;
  }
  v8 = (hkFreeList::Block *)(*((__int64 (__fastcall **)(hkMemoryAllocator *, __int64))&m_blockAllocator->vfptr->__vecDelDtor
                             + 1))(
                              m_blockAllocator,
                              32i64);
  if ( !v8 )
    return 0i64;
  v9 = this->m_elementAllocator;
  v17 = this->m_blockSize;
  v10 = (__int64)v9->vfptr->bufAlloc(v9, &v17);
  v11 = v10;
  if ( !v10 )
  {
    this->m_blockAllocator->vfptr->blockFree(this->m_blockAllocator, v8, 32);
    return 0i64;
  }
  v8->m_elementsAlloc = (char *)v10;
  v12 = ~(this->m_align - 1) & (v10 + this->m_align - 1);
  if ( v12 == v10 && v17 == LODWORD(this->m_blockSize) )
  {
    m_numBlockElements = this->m_numBlockElements;
LABEL_18:
    v8->m_elements = (char *)v11;
    goto LABEL_19;
  }
  m_numBlockElements = (v10 + v17 - v12) / this->m_elementSize;
  v8->m_elements = (char *)v12;
LABEL_19:
  v8->m_numElements = m_numBlockElements;
  this->m_top = v8->m_elements;
  this->m_blockEnd = &v8->m_elements[this->m_elementSize * v8->m_numElements];
  v8->m_next = this->m_activeBlocks;
  v16 = this->m_elementSize;
  this->m_activeBlocks = v8;
  this->m_totalNumElements += v8->m_numElements;
  this->m_numFreeElements += v8->m_numElements - 1;
  result = this->m_top;
  this->m_top = &result[v16];
  return result;
}

// File Line: 916
// RVA: 0xC6FAF0
unsigned __int64 __fastcall hkFreeList::bestBlockSize(unsigned __int64 elementSpace, unsigned __int64 align)
{
  if ( align > 0x10 )
    return elementSpace + align + 16;
  else
    return elementSpace + 32;
}

// File Line: 923
// RVA: 0xC6F580
void __fastcall hkFreeList::freeAll(hkFreeList *this)
{
  hkFreeList::Block *m_activeBlocks; // rax
  hkFreeList::Block *v2; // rax

  this->m_numFreeElements = this->m_totalNumElements;
  m_activeBlocks = this->m_activeBlocks;
  if ( m_activeBlocks )
  {
    for ( this->m_free = 0i64; m_activeBlocks->m_next; m_activeBlocks = m_activeBlocks->m_next )
      ;
    m_activeBlocks->m_next = this->m_freeBlocks;
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
  unsigned __int64 v4; // rbx
  unsigned __int64 m_numFreeElements; // rax
  unsigned __int64 m_totalNumElements; // r8
  __int64 v7; // rcx
  __int64 m_elementSize; // rax

  v4 = hkFreeList::_calculateBlockAllocatedSize(this, this->m_freeBlocks);
  stats->m_allocated = hkFreeList::_calculateBlockAllocatedSize(this, this->m_activeBlocks) + v4;
  m_numFreeElements = this->m_numFreeElements;
  m_totalNumElements = this->m_totalNumElements;
  v7 = m_numFreeElements * this->m_elementSize;
  stats->m_available = v7;
  stats->m_inUse = this->m_elementSize * (m_totalNumElements - m_numFreeElements);
  m_elementSize = this->m_elementSize;
  stats->m_totalAvailable = v7;
  stats->m_largestBlock = m_elementSize;
}

// File Line: 980
// RVA: 0xC6FB40
__int64 __fastcall hkFreeList::_getSortedBlockHeads(hkFreeList *this, hkFreeList::Block **heads, int numHeads)
{
  hkFreeList::Block *v5; // rax
  hkFreeList::Element *m_freeBlocks; // rcx
  hkFreeList::Block *v7; // rax
  hkFreeList::Block *m_activeBlocks; // rcx
  __int64 result; // rax
  hkFreeList::Block *v10; // rdx
  __int64 v11; // rcx

  v5 = (hkFreeList::Block *)hkAlgorithm::sortList<hkFreeList::Element>((hkFreeList::Element *)this->m_activeBlocks);
  m_freeBlocks = (hkFreeList::Element *)this->m_freeBlocks;
  this->m_activeBlocks = v5;
  v7 = (hkFreeList::Block *)hkAlgorithm::sortList<hkFreeList::Element>(m_freeBlocks);
  m_activeBlocks = this->m_activeBlocks;
  this->m_freeBlocks = v7;
  result = 0i64;
  if ( m_activeBlocks )
  {
    *heads = m_activeBlocks;
    result = 1i64;
  }
  v10 = this->m_freeBlocks;
  if ( v10 )
  {
    v11 = (int)result;
    result = (unsigned int)(result + 1);
    heads[v11] = v10;
  }
  return result;
}

