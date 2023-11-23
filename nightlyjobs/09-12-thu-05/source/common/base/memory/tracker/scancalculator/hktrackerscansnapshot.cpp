// File Line: 29
// RVA: 0x1302690
void __fastcall hkTrackerScanSnapshot::hkTrackerScanSnapshot(
        hkTrackerScanSnapshot *this,
        hkTrackerSnapshot *snapshot,
        hkTrackerLayoutCalculator *layoutCalc)
{
  char *m_data; // rdi
  int v7; // eax

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkTrackerScanSnapshot::`vftable;
  this->m_blocks.m_data = 0i64;
  this->m_blocks.m_size = 0;
  this->m_blocks.m_capacityAndFlags = 0x80000000;
  this->m_blockMap.m_map.m_elem = 0i64;
  this->m_blockMap.m_map.m_numElems = 0;
  this->m_blockMap.m_map.m_hashMod = -1;
  hkMemorySnapshot::hkMemorySnapshot(&this->m_rawSnapshot, 0i64);
  this->m_references.m_data = 0i64;
  this->m_references.m_size = 0;
  this->m_references.m_capacityAndFlags = 0x80000000;
  hkFreeList::hkFreeList(&this->m_blockFreeList, 0x28ui64, 8ui64, 0x1000ui64, 0i64, 0i64);
  if ( layoutCalc )
    hkReferencedObject::addReference(layoutCalc);
  this->m_layoutCalc.m_pntr = layoutCalc;
  this->m_traceMap.m_map.m_elem = 0i64;
  this->m_traceMap.m_map.m_numElems = 0;
  this->m_traceMap.m_map.m_hashMod = -1;
  this->m_traceText.m_data = 0i64;
  this->m_traceText.m_size = 0;
  this->m_traceText.m_capacityAndFlags = 0x80000000;
  this->m_typeText.m_data = 0i64;
  this->m_typeText.m_size = 0;
  this->m_typeText.m_capacityAndFlags = 0x80000000;
  this->m_memSysStatistics.m_data = 0i64;
  this->m_memSysStatistics.m_size = 0;
  this->m_memSysStatistics.m_capacityAndFlags = 0x80000000;
  hkMemorySnapshot::swap(&this->m_rawSnapshot, &snapshot->m_rawSnapshot);
  if ( snapshot->m_memSysStatistics.m_size )
  {
    m_data = snapshot->m_memSysStatistics.m_data;
    if ( m_data )
    {
      v7 = hkString::strLen(m_data);
      hkArrayBase<char>::_append(&this->m_memSysStatistics, &hkContainerHeapAllocator::s_alloc, m_data, v7 + 1);
    }
  }
}

// File Line: 42
// RVA: 0x1302810
void __fastcall hkTrackerScanSnapshot::hkTrackerScanSnapshot(hkTrackerScanSnapshot *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkTrackerScanSnapshot::`vftable;
  this->m_blocks.m_data = 0i64;
  this->m_blocks.m_size = 0;
  this->m_blocks.m_capacityAndFlags = 0x80000000;
  this->m_blockMap.m_map.m_elem = 0i64;
  this->m_blockMap.m_map.m_numElems = 0;
  this->m_blockMap.m_map.m_hashMod = -1;
  hkMemorySnapshot::hkMemorySnapshot(&this->m_rawSnapshot, 0i64);
  this->m_references.m_data = 0i64;
  this->m_references.m_size = 0;
  this->m_references.m_capacityAndFlags = 0x80000000;
  hkFreeList::hkFreeList(&this->m_blockFreeList, 0x28ui64, 8ui64, 0x1000ui64, 0i64, 0i64);
  this->m_layoutCalc.m_pntr = 0i64;
  this->m_traceMap.m_map.m_elem = 0i64;
  this->m_traceMap.m_map.m_numElems = 0;
  this->m_traceMap.m_map.m_hashMod = -1;
  this->m_traceText.m_data = 0i64;
  this->m_traceText.m_size = 0;
  this->m_traceText.m_capacityAndFlags = 0x80000000;
  this->m_typeText.m_data = 0i64;
  this->m_typeText.m_size = 0;
  this->m_typeText.m_capacityAndFlags = 0x80000000;
  this->m_memSysStatistics.m_data = 0i64;
  this->m_memSysStatistics.m_size = 0;
  this->m_memSysStatistics.m_capacityAndFlags = 0x80000000;
}

// File Line: 46
// RVA: 0x1302910
void __fastcall hkTrackerScanSnapshot::~hkTrackerScanSnapshot(hkTrackerScanSnapshot *this)
{
  int m_capacityAndFlags; // r8d
  int v3; // r8d
  int v4; // r8d
  hkTrackerLayoutCalculator *m_pntr; // rcx
  int v6; // r8d
  int v7; // r8d

  this->vfptr = (hkBaseObjectVtbl *)&hkTrackerScanSnapshot::`vftable;
  hkTrackerScanSnapshot::clear(this);
  m_capacityAndFlags = this->m_memSysStatistics.m_capacityAndFlags;
  this->m_memSysStatistics.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_memSysStatistics.m_data,
      m_capacityAndFlags & 0x3FFFFFFF);
  this->m_memSysStatistics.m_data = 0i64;
  this->m_memSysStatistics.m_capacityAndFlags = 0x80000000;
  v3 = this->m_typeText.m_capacityAndFlags;
  this->m_typeText.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_typeText.m_data,
      v3 & 0x3FFFFFFF);
  this->m_typeText.m_data = 0i64;
  this->m_typeText.m_capacityAndFlags = 0x80000000;
  v4 = this->m_traceText.m_capacityAndFlags;
  this->m_traceText.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_traceText.m_data,
      v4 & 0x3FFFFFFF);
  this->m_traceText.m_data = 0i64;
  this->m_traceText.m_capacityAndFlags = 0x80000000;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &this->m_traceMap.m_map,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)&this->m_traceMap);
  m_pntr = this->m_layoutCalc.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_layoutCalc.m_pntr = 0i64;
  hkFreeList::freeAllMemory(&this->m_blockFreeList);
  v6 = this->m_references.m_capacityAndFlags;
  this->m_references.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_references.m_data,
      8 * v6);
  this->m_references.m_data = 0i64;
  this->m_references.m_capacityAndFlags = 0x80000000;
  hkMemorySnapshot::~hkMemorySnapshot(&this->m_rawSnapshot);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &this->m_blockMap.m_map,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)&this->m_blockMap);
  v7 = this->m_blocks.m_capacityAndFlags;
  this->m_blocks.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, this->m_blocks.m_data, 8 * v7);
  this->m_blocks.m_data = 0i64;
  this->m_blocks.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 51
// RVA: 0x1302550
char *__fastcall hkTrackerScanSnapshot::getTraceText(hkTrackerScanSnapshot *this, unsigned __int64 addr)
{
  int v3; // eax

  v3 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
         &this->m_traceMap.m_map,
         addr,
         0xFFFFFFFFFFFFFFFFui64);
  if ( v3 < 0 )
    return 0i64;
  else
    return &this->m_traceText.m_data[v3];
}

// File Line: 61
// RVA: 0x1302590
void __fastcall hkTrackerScanSnapshot::setTraceText(hkTrackerScanSnapshot *this, unsigned __int64 addr, char *text)
{
  hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> *p_m_traceMap; // rsi
  unsigned __int64 m_size; // r12
  hkArray<char,hkContainerHeapAllocator> *p_m_traceText; // rbx
  int v9; // r14d
  __int64 v10; // r15
  int v11; // r9d
  int v12; // eax
  int v13; // eax
  hkResult result; // [rsp+60h] [rbp+8h] BYREF

  p_m_traceMap = &this->m_traceMap;
  if ( (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
          &this->m_traceMap.m_map,
          addr,
          0xFFFFFFFFFFFFFFFFui64) & 0x80000000) != 0i64 )
  {
    m_size = this->m_traceText.m_size;
    p_m_traceText = &this->m_traceText;
    v9 = hkString::strLen(text) + 1;
    v10 = p_m_traceText->m_size;
    v11 = v10 + v9;
    v12 = p_m_traceText->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v12 >= (int)v10 + v9 )
    {
      result.m_enum = HK_SUCCESS;
    }
    else
    {
      v13 = 2 * v12;
      if ( v11 < v13 )
        v11 = v13;
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&p_m_traceText->m_data, v11, 1);
    }
    p_m_traceText->m_size += v9;
    hkString::strCpy(&p_m_traceText->m_data[v10], text);
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
      &p_m_traceMap->m_map,
      &hkContainerHeapAllocator::s_alloc,
      addr,
      m_size);
  }
}

// File Line: 77
// RVA: 0x1302340
void __fastcall hkTrackerScanSnapshot::clear(hkTrackerScanSnapshot *this)
{
  int m_capacityAndFlags; // r8d
  int v3; // r8d

  hkFreeList::freeAll(&this->m_blockFreeList);
  m_capacityAndFlags = this->m_references.m_capacityAndFlags;
  this->m_references.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_references.m_data,
      8 * m_capacityAndFlags);
  this->m_references.m_data = 0i64;
  this->m_references.m_capacityAndFlags = 0x80000000;
  v3 = this->m_blocks.m_capacityAndFlags;
  this->m_blocks.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, this->m_blocks.m_data, 8 * v3);
  this->m_blocks.m_data = 0i64;
  this->m_blocks.m_capacityAndFlags = 0x80000000;
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear(&this->m_blockMap.m_map);
  this->m_typeText.m_size = 0;
}

// File Line: 86
// RVA: 0x13021F0
hkTrackerScanSnapshot::Block *__fastcall hkTrackerScanSnapshot::addBlock(
        hkTrackerScanSnapshot *this,
        hkTrackerTypeTreeNode *type,
        unsigned __int64 start,
        unsigned __int64 size)
{
  hkFreeList *p_m_blockFreeList; // r10
  char *m_free; // rbx
  unsigned __int64 m_elementSize; // rcx

  p_m_blockFreeList = &this->m_blockFreeList;
  m_free = (char *)this->m_blockFreeList.m_free;
  if ( m_free )
  {
    --this->m_blockFreeList.m_numFreeElements;
    p_m_blockFreeList->m_free = *(hkFreeList::Element **)m_free;
  }
  else
  {
    m_free = this->m_blockFreeList.m_top;
    if ( m_free < this->m_blockFreeList.m_blockEnd )
    {
      m_elementSize = this->m_blockFreeList.m_elementSize;
      --p_m_blockFreeList->m_numFreeElements;
      p_m_blockFreeList->m_top = &m_free[m_elementSize];
    }
    else
    {
      m_free = hkFreeList::addSpace(&this->m_blockFreeList);
    }
  }
  if ( m_free )
  {
    *(_QWORD *)m_free = type;
    *((_QWORD *)m_free + 1) = start;
    *((_QWORD *)m_free + 2) = size;
    *((_DWORD *)m_free + 6) = -1;
    *(_QWORD *)(m_free + 28) = 0i64;
  }
  if ( this->m_blocks.m_size == (this->m_blocks.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_blocks.m_data, 8);
  this->m_blocks.m_data[this->m_blocks.m_size++] = (hkTrackerScanSnapshot::Block *)m_free;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
    &this->m_blockMap.m_map,
    &hkContainerHeapAllocator::s_alloc,
    start,
    (unsigned __int64)m_free);
  return (hkTrackerScanSnapshot::Block *)m_free;
}

// File Line: 96
// RVA: 0x13022F0
hkTrackerScanSnapshot::Block *__fastcall hkTrackerScanSnapshot::findBlock(
        hkTrackerScanSnapshot *this,
        unsigned __int64 ptr)
{
  hkPointerMap<void const *,hkTrackerScanSnapshot::Block *,hkContainerHeapAllocator> *p_m_blockMap; // rdi
  hkTrackerScanSnapshot::Block *result; // rax

  p_m_blockMap = &this->m_blockMap;
  result = (hkTrackerScanSnapshot::Block *)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                                             &this->m_blockMap.m_map,
                                             ptr,
                                             0i64);
  if ( !result )
    return (hkTrackerScanSnapshot::Block *)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                                             &p_m_blockMap->m_map,
                                             (ptr - 16) & 0xFFFFFFFFFFFFFFFEui64,
                                             0i64);
  return result;
}

// File Line: 116
// RVA: 0x1302670
char *__fastcall hkTrackerScanSnapshot::getMemorySystemStatistics(hkTrackerScanSnapshot *this)
{
  if ( this->m_memSysStatistics.m_size )
    return this->m_memSysStatistics.m_data;
  else
    return 0i64;
}

// File Line: 128
// RVA: 0x1302C60
hkBool *__fastcall orderBlocks(hkBool *result, hkTrackerScanSnapshot::Block *a, hkTrackerScanSnapshot::Block *b)
{
  const char *m_start; // rax
  const char *v4; // r9

  m_start = a->m_start;
  v4 = b->m_start;
  if ( m_start == v4 )
    result->m_bool = a->m_size > b->m_size;
  else
    result->m_bool = m_start < v4;
  return result;
}

// File Line: 142
// RVA: 0x1302400
void __fastcall hkTrackerScanSnapshot::orderBlocks(hkTrackerScanSnapshot *this)
{
  int m_size; // r8d

  m_size = this->m_blocks.m_size;
  if ( m_size > 1 )
    hkAlgorithm::quickSortRecursive<hkFreeList::Element *,hkBool (*)(hkFreeList::Element const *,hkFreeList::Element const *)>(
      (hkpRigidBody **)this->m_blocks.m_data,
      0,
      m_size - 1,
      (hkBool *(__fastcall *)(hkBool *, hkpRigidBody *, hkpRigidBody *))orderBlocks);
}

// File Line: 147
// RVA: 0x1302430
unsigned __int64 __fastcall hkTrackerScanSnapshot::calcTotalUsed(hkTrackerScanSnapshot *this)
{
  return hkTrackerScanSnapshot::calcOrderedTotalUsed(this->m_blocks.m_data, this->m_blocks.m_size);
}

// File Line: 166
// RVA: 0x1302C40
void __fastcall hkTrackerScanSnapshot::orderBlocks(hkpRigidBody **blocksIn, int numBlocks)
{
  if ( numBlocks > 1 )
    hkAlgorithm::quickSortRecursive<hkFreeList::Element *,hkBool (*)(hkFreeList::Element const *,hkFreeList::Element const *)>(
      blocksIn,
      0,
      numBlocks - 1,
      (hkBool *(__fastcall *)(hkBool *, hkpRigidBody *, hkpRigidBody *))orderBlocks);
}

// File Line: 171
// RVA: 0x1302B00
unsigned __int64 __fastcall hkTrackerScanSnapshot::calcTotalUsed(
        hkTrackerScanSnapshot::Block *const *blocksIn,
        int numBlocks)
{
  void *v4; // rcx
  int v5; // r9d
  void *v6; // rdi
  unsigned __int64 result; // rax
  unsigned __int64 v8; // rbx
  void *dst; // [rsp+30h] [rbp-18h] BYREF
  int numBlocksa; // [rsp+38h] [rbp-10h]
  int v11; // [rsp+3Ch] [rbp-Ch]
  hkResult v12; // [rsp+58h] [rbp+10h] BYREF

  v4 = 0i64;
  v11 = 0x80000000;
  numBlocksa = 0;
  dst = 0i64;
  if ( numBlocks > 0 )
  {
    v5 = numBlocks;
    hkArrayUtil::_reserve(&v12, &hkContainerHeapAllocator::s_alloc, (const void **)&dst, v5, 8);
    v4 = dst;
  }
  numBlocksa = numBlocks;
  hkString::memCpy(v4, blocksIn, 8 * numBlocks);
  hkTrackerScanSnapshot::orderBlocks((hkTrackerScanSnapshot::Block **)dst, numBlocksa);
  v6 = dst;
  result = hkTrackerScanSnapshot::calcOrderedTotalUsed((hkTrackerScanSnapshot::Block *const *)dst, numBlocks);
  numBlocksa = 0;
  v8 = result;
  if ( v11 >= 0 )
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v6, 8 * v11);
    return v8;
  }
  return result;
}

// File Line: 183
// RVA: 0x1302BD0
unsigned __int64 __fastcall hkTrackerScanSnapshot::calcOrderedTotalUsed(
        hkTrackerScanSnapshot::Block **blocks,
        int numBlocks)
{
  hkTrackerScanSnapshot::Block *v4; // r9
  __int64 v5; // rcx
  unsigned __int64 m_size; // r10
  __int64 i; // rbx
  hkTrackerScanSnapshot::Block *v8; // r8
  const char *m_start; // rdx
  const char *v10; // r11

  if ( !numBlocks )
    return 0i64;
  v4 = *blocks;
  v5 = 1i64;
  m_size = v4->m_size;
  for ( i = numBlocks; v5 < i; ++v5 )
  {
    v8 = blocks[v5];
    m_start = v4->m_start;
    v10 = v8->m_start;
    if ( v10 < m_start || v10 >= &m_start[v4->m_size] )
    {
      m_size += v8->m_size;
      v4 = blocks[v5];
    }
  }
  return m_size;
}

// File Line: 227
// RVA: 0x1302450
void __fastcall hkTrackerScanSnapshot::findBlocksByType(
        hkTrackerScanSnapshot *this,
        const char *name,
        hkArray<hkTrackerScanSnapshot::Block *,hkContainerHeapAllocator> *blocksOut)
{
  int v3; // edi
  __int64 v7; // rsi
  hkTrackerScanSnapshot::Block *v8; // r14
  hkBool result; // [rsp+50h] [rbp+8h] BYREF
  hkBool v10; // [rsp+60h] [rbp+18h] BYREF

  v3 = 0;
  blocksOut->m_size = 0;
  if ( this->m_blocks.m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      v8 = this->m_blocks.m_data[v7];
      if ( v8->m_type
        && hkTrackerTypeTreeNode::isNamedType(v8->m_type, &result)->m_bool
        && hkSubString::operator==(&v8->m_type->m_name, &v10, name)->m_bool )
      {
        if ( blocksOut->m_size == (blocksOut->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&blocksOut->m_data, 8);
        blocksOut->m_data[blocksOut->m_size++] = v8;
      }
      ++v3;
      ++v7;
    }
    while ( v3 < this->m_blocks.m_size );
  }
}

// File Line: 244
// RVA: 0x1302510
__int64 __fastcall hkTrackerScanSnapshot::findReferenceIndex(
        hkTrackerScanSnapshot *this,
        hkTrackerScanSnapshot::Block *block,
        hkTrackerScanSnapshot::Block *refdBlock)
{
  __int64 m_numReferences; // r10
  hkTrackerScanSnapshot::Block **m_data; // rax
  unsigned int v5; // ecx
  hkTrackerScanSnapshot::Block **v6; // r9
  __int64 v7; // rax

  m_numReferences = block->m_numReferences;
  if ( (int)m_numReferences <= 0 )
    return 0xFFFFFFFFi64;
  m_data = this->m_references.m_data;
  v5 = 0;
  v6 = &m_data[block->m_startReferenceIndex];
  v7 = 0i64;
  while ( v6[v7] != refdBlock )
  {
    ++v7;
    ++v5;
    if ( v7 >= m_numReferences )
      return 0xFFFFFFFFi64;
  }
  return v5;
}

