// File Line: 29
// RVA: 0x1302690
void __fastcall hkTrackerScanSnapshot::hkTrackerScanSnapshot(hkTrackerScanSnapshot *this, hkTrackerSnapshot *snapshot, hkTrackerLayoutCalculator *layoutCalc)
{
  hkTrackerSnapshot *v3; // rdi
  hkTrackerScanSnapshot *v4; // rbx
  hkTrackerLayoutCalculator *v5; // rsi
  const char *v6; // rdi
  int v7; // eax

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkTrackerScanSnapshot::`vftable';
  this->m_blocks.m_data = 0i64;
  this->m_blocks.m_size = 0;
  this->m_blocks.m_capacityAndFlags = 2147483648;
  v3 = snapshot;
  v4 = this;
  this->m_blockMap.m_map.m_elem = 0i64;
  this->m_blockMap.m_map.m_numElems = 0;
  this->m_blockMap.m_map.m_hashMod = -1;
  v5 = layoutCalc;
  hkMemorySnapshot::hkMemorySnapshot(&this->m_rawSnapshot, 0i64);
  v4->m_references.m_data = 0i64;
  v4->m_references.m_size = 0;
  v4->m_references.m_capacityAndFlags = 2147483648;
  hkFreeList::hkFreeList(&v4->m_blockFreeList, 0x28ui64, 8ui64, 0x1000ui64, 0i64, 0i64);
  if ( v5 )
    hkReferencedObject::addReference((hkReferencedObject *)&v5->vfptr);
  v4->m_layoutCalc.m_pntr = v5;
  v4->m_traceMap.m_map.m_elem = 0i64;
  v4->m_traceMap.m_map.m_numElems = 0;
  v4->m_traceMap.m_map.m_hashMod = -1;
  v4->m_traceText.m_data = 0i64;
  v4->m_traceText.m_size = 0;
  v4->m_traceText.m_capacityAndFlags = 2147483648;
  v4->m_typeText.m_data = 0i64;
  v4->m_typeText.m_size = 0;
  v4->m_typeText.m_capacityAndFlags = 2147483648;
  v4->m_memSysStatistics.m_data = 0i64;
  v4->m_memSysStatistics.m_size = 0;
  v4->m_memSysStatistics.m_capacityAndFlags = 2147483648;
  hkMemorySnapshot::swap(&v4->m_rawSnapshot, &v3->m_rawSnapshot);
  if ( v3->m_memSysStatistics.m_size )
  {
    v6 = v3->m_memSysStatistics.m_data;
    if ( v6 )
    {
      v7 = hkString::strLen(v6);
      hkArrayBase<char>::_append(
        (hkArrayBase<char> *)&v4->m_memSysStatistics.m_data,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        v6,
        v7 + 1);
    }
  }
}

// File Line: 42
// RVA: 0x1302810
void __fastcall hkTrackerScanSnapshot::hkTrackerScanSnapshot(hkTrackerScanSnapshot *this)
{
  hkTrackerScanSnapshot *v1; // rbx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkTrackerScanSnapshot::`vftable';
  this->m_blocks.m_data = 0i64;
  this->m_blocks.m_size = 0;
  this->m_blocks.m_capacityAndFlags = 2147483648;
  v1 = this;
  this->m_blockMap.m_map.m_elem = 0i64;
  this->m_blockMap.m_map.m_numElems = 0;
  this->m_blockMap.m_map.m_hashMod = -1;
  hkMemorySnapshot::hkMemorySnapshot(&this->m_rawSnapshot, 0i64);
  v1->m_references.m_data = 0i64;
  v1->m_references.m_size = 0;
  v1->m_references.m_capacityAndFlags = 2147483648;
  hkFreeList::hkFreeList(&v1->m_blockFreeList, 0x28ui64, 8ui64, 0x1000ui64, 0i64, 0i64);
  v1->m_layoutCalc.m_pntr = 0i64;
  v1->m_traceMap.m_map.m_elem = 0i64;
  v1->m_traceMap.m_map.m_numElems = 0;
  v1->m_traceMap.m_map.m_hashMod = -1;
  v1->m_traceText.m_data = 0i64;
  v1->m_traceText.m_size = 0;
  v1->m_traceText.m_capacityAndFlags = 2147483648;
  v1->m_typeText.m_data = 0i64;
  v1->m_typeText.m_size = 0;
  v1->m_typeText.m_capacityAndFlags = 2147483648;
  v1->m_memSysStatistics.m_data = 0i64;
  v1->m_memSysStatistics.m_size = 0;
  v1->m_memSysStatistics.m_capacityAndFlags = 2147483648;
}

// File Line: 46
// RVA: 0x1302910
void __fastcall hkTrackerScanSnapshot::~hkTrackerScanSnapshot(hkTrackerScanSnapshot *this)
{
  hkTrackerScanSnapshot *v1; // rdi
  int v2; // er8
  int v3; // er8
  int v4; // er8
  hkReferencedObject *v5; // rcx
  int v6; // er8
  int v7; // er8

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkTrackerScanSnapshot::`vftable';
  hkTrackerScanSnapshot::clear(this);
  v2 = v1->m_memSysStatistics.m_capacityAndFlags;
  v1->m_memSysStatistics.m_size = 0;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_memSysStatistics.m_data,
      v2 & 0x3FFFFFFF);
  v1->m_memSysStatistics.m_data = 0i64;
  v1->m_memSysStatistics.m_capacityAndFlags = 2147483648;
  v3 = v1->m_typeText.m_capacityAndFlags;
  v1->m_typeText.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_typeText.m_data,
      v3 & 0x3FFFFFFF);
  v1->m_typeText.m_data = 0i64;
  v1->m_typeText.m_capacityAndFlags = 2147483648;
  v4 = v1->m_traceText.m_capacityAndFlags;
  v1->m_traceText.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_traceText.m_data,
      v4 & 0x3FFFFFFF);
  v1->m_traceText.m_data = 0i64;
  v1->m_traceText.m_capacityAndFlags = 2147483648;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v1->m_traceMap.m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v1->m_traceMap);
  v5 = (hkReferencedObject *)&v1->m_layoutCalc.m_pntr->vfptr;
  if ( v5 )
    hkReferencedObject::removeReference(v5);
  v1->m_layoutCalc.m_pntr = 0i64;
  hkFreeList::freeAllMemory(&v1->m_blockFreeList);
  v6 = v1->m_references.m_capacityAndFlags;
  v1->m_references.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_references.m_data,
      8 * v6);
  v1->m_references.m_data = 0i64;
  v1->m_references.m_capacityAndFlags = 2147483648;
  hkMemorySnapshot::~hkMemorySnapshot(&v1->m_rawSnapshot);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v1->m_blockMap.m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v1->m_blockMap);
  v7 = v1->m_blocks.m_capacityAndFlags;
  v1->m_blocks.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_blocks.m_data,
      8 * v7);
  v1->m_blocks.m_data = 0i64;
  v1->m_blocks.m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 51
// RVA: 0x1302550
char *__fastcall hkTrackerScanSnapshot::getTraceText(hkTrackerScanSnapshot *this, unsigned __int64 addr)
{
  hkTrackerScanSnapshot *v2; // rbx
  int v3; // eax
  char *result; // rax

  v2 = this;
  v3 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
         (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_traceMap.m_map.m_elem,
         addr,
         0xFFFFFFFFFFFFFFFFui64);
  if ( v3 < 0 )
    result = 0i64;
  else
    result = &v2->m_traceText.m_data[v3];
  return result;
}

// File Line: 61
// RVA: 0x1302590
void __fastcall hkTrackerScanSnapshot::setTraceText(hkTrackerScanSnapshot *this, unsigned __int64 addr, const char *text)
{
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v3; // rsi
  const char *v4; // rbp
  hkTrackerScanSnapshot *v5; // rbx
  unsigned __int64 v6; // rdi
  unsigned __int64 v7; // r12
  int v8; // eax
  signed int *v9; // rbx
  int v10; // er14
  __int64 v11; // r15
  int v12; // er9
  int v13; // eax
  int v14; // eax
  hkResult result; // [rsp+60h] [rbp+8h]

  v3 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_traceMap.m_map.m_elem;
  v4 = text;
  v5 = this;
  v6 = addr;
  if ( (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
          (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_traceMap.m_map.m_elem,
          addr,
          0xFFFFFFFFFFFFFFFFui64) & 0x80000000) != 0i64 )
  {
    v7 = v5->m_traceText.m_size;
    v8 = hkString::strLen(v4);
    v9 = (signed int *)&v5->m_traceText;
    v10 = v8 + 1;
    v11 = v9[2];
    v12 = v11 + v8 + 1;
    v13 = v9[3] & 0x3FFFFFFF;
    if ( v13 >= v12 )
    {
      result.m_enum = 0;
    }
    else
    {
      v14 = 2 * v13;
      if ( v12 < v14 )
        v12 = v14;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v9, v12, 1);
    }
    v9[2] += v10;
    hkString::strCpy((char *)(*(_QWORD *)v9 + v11), v4);
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
      v3,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      v6,
      v7);
  }
}

// File Line: 77
// RVA: 0x1302340
void __fastcall hkTrackerScanSnapshot::clear(hkTrackerScanSnapshot *this)
{
  hkTrackerScanSnapshot *v1; // rbx
  int v2; // er8
  int v3; // er8

  v1 = this;
  hkFreeList::freeAll(&this->m_blockFreeList);
  v2 = v1->m_references.m_capacityAndFlags;
  v1->m_references.m_size = 0;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_references.m_data,
      8 * v2);
  v1->m_references.m_data = 0i64;
  v1->m_references.m_capacityAndFlags = 2147483648;
  v3 = v1->m_blocks.m_capacityAndFlags;
  v1->m_blocks.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_blocks.m_data,
      8 * v3);
  v1->m_blocks.m_data = 0i64;
  v1->m_blocks.m_capacityAndFlags = 2147483648;
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear((hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v1->m_blockMap.m_map.m_elem);
  v1->m_typeText.m_size = 0;
}

// File Line: 86
// RVA: 0x13021F0
hkTrackerScanSnapshot::Block *__fastcall hkTrackerScanSnapshot::addBlock(hkTrackerScanSnapshot *this, hkTrackerTypeTreeNode *type, const void *start, unsigned __int64 size)
{
  hkFreeList *v4; // r10
  unsigned __int64 v5; // rdi
  const void *v6; // rbp
  char *v7; // rbx
  hkTrackerTypeTreeNode *v8; // r14
  hkTrackerScanSnapshot *v9; // rsi
  unsigned __int64 v10; // rcx

  v4 = &this->m_blockFreeList;
  v5 = size;
  v6 = start;
  v7 = (char *)this->m_blockFreeList.m_free;
  v8 = type;
  v9 = this;
  if ( v7 )
  {
    --this->m_blockFreeList.m_numFreeElements;
    v4->m_free = *(hkFreeList::Element **)v7;
  }
  else
  {
    v7 = this->m_blockFreeList.m_top;
    if ( v7 < this->m_blockFreeList.m_blockEnd )
    {
      v10 = this->m_blockFreeList.m_elementSize;
      --v4->m_numFreeElements;
      v4->m_top = &v7[v10];
    }
    else
    {
      v7 = hkFreeList::addSpace(&this->m_blockFreeList);
    }
  }
  if ( v7 )
  {
    *(_QWORD *)v7 = v8;
    *((_QWORD *)v7 + 1) = v6;
    *((_QWORD *)v7 + 2) = v5;
    *((_DWORD *)v7 + 6) = -1;
    *(_QWORD *)(v7 + 28) = 0i64;
  }
  if ( v9->m_blocks.m_size == (v9->m_blocks.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v9->m_blocks, 8);
  v9->m_blocks.m_data[v9->m_blocks.m_size++] = (hkTrackerScanSnapshot::Block *)v7;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v9->m_blockMap.m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    (unsigned __int64)v6,
    (unsigned __int64)v7);
  return (hkTrackerScanSnapshot::Block *)v7;
}

// File Line: 96
// RVA: 0x13022F0
hkTrackerScanSnapshot::Block *__fastcall hkTrackerScanSnapshot::findBlock(hkTrackerScanSnapshot *this, const void *ptr)
{
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v2; // rdi
  const void *v3; // rbx
  hkTrackerScanSnapshot::Block *result; // rax

  v2 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_blockMap.m_map.m_elem;
  v3 = ptr;
  result = (hkTrackerScanSnapshot::Block *)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                                             (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_blockMap.m_map.m_elem,
                                             (unsigned __int64)ptr,
                                             0i64);
  if ( !result )
    result = (hkTrackerScanSnapshot::Block *)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                                               v2,
                                               ((_QWORD)v3 - 16) & 0xFFFFFFFFFFFFFFFEui64,
                                               0i64);
  return result;
}

// File Line: 116
// RVA: 0x1302670
char *__fastcall hkTrackerScanSnapshot::getMemorySystemStatistics(hkTrackerScanSnapshot *this)
{
  char *result; // rax

  if ( this->m_memSysStatistics.m_size )
    result = this->m_memSysStatistics.m_data;
  else
    result = 0i64;
  return result;
}

// File Line: 128
// RVA: 0x1302C60
hkBool *__fastcall orderBlocks(hkBool *result, hkTrackerScanSnapshot::Block *a, hkTrackerScanSnapshot::Block *b)
{
  const char *v3; // rax
  const char *v4; // r9

  v3 = a->m_start;
  v4 = b->m_start;
  if ( v3 == v4 )
    result->m_bool = a->m_size > b->m_size;
  else
    result->m_bool = v3 < v4;
  return result;
}

// File Line: 142
// RVA: 0x1302400
void __fastcall hkTrackerScanSnapshot::orderBlocks(hkTrackerScanSnapshot *this)
{
  int v1; // er8

  v1 = this->m_blocks.m_size;
  if ( v1 > 1 )
    hkAlgorithm::quickSortRecursive<hkFreeList::Element *,hkBool (*)(hkFreeList::Element const *,hkFreeList::Element const *)>(
      (hkpRigidBody **)this->m_blocks.m_data,
      0,
      v1 - 1,
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
void __fastcall hkTrackerScanSnapshot::orderBlocks(hkTrackerScanSnapshot::Block **blocksIn, int numBlocks)
{
  if ( numBlocks > 1 )
    hkAlgorithm::quickSortRecursive<hkFreeList::Element *,hkBool (*)(hkFreeList::Element const *,hkFreeList::Element const *)>(
      (hkpRigidBody **)blocksIn,
      0,
      numBlocks - 1,
      (hkBool *(__fastcall *)(hkBool *, hkpRigidBody *, hkpRigidBody *))orderBlocks);
}

// File Line: 171
// RVA: 0x1302B00
unsigned __int64 __fastcall hkTrackerScanSnapshot::calcTotalUsed(hkTrackerScanSnapshot::Block *const *blocksIn, int numBlocks)
{
  hkTrackerScanSnapshot::Block *const *v2; // rdi
  int v3; // ebx
  void *v4; // rcx
  int v5; // er9
  void *v6; // rdi
  unsigned __int64 result; // rax
  unsigned __int64 v8; // rbx
  void *dst; // [rsp+30h] [rbp-18h]
  int numBlocksa; // [rsp+38h] [rbp-10h]
  int v11; // [rsp+3Ch] [rbp-Ch]
  __int64 v12; // [rsp+58h] [rbp+10h]

  v2 = blocksIn;
  v3 = numBlocks;
  v4 = 0i64;
  v11 = 2147483648;
  numBlocksa = 0;
  dst = 0i64;
  if ( numBlocks > 0 )
  {
    v5 = numBlocks;
    if ( numBlocks < 0 )
      v5 = 0;
    hkArrayUtil::_reserve((hkResult *)&v12, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &dst, v5, 8);
    v4 = dst;
  }
  numBlocksa = v3;
  hkString::memCpy(v4, v2, 8 * v3);
  hkTrackerScanSnapshot::orderBlocks((hkTrackerScanSnapshot::Block **)dst, numBlocksa);
  v6 = dst;
  result = hkTrackerScanSnapshot::calcOrderedTotalUsed((hkTrackerScanSnapshot::Block *const *)dst, v3);
  numBlocksa = 0;
  v8 = result;
  if ( v11 >= 0 )
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v6,
      8 * v11);
    result = v8;
  }
  return result;
}

// File Line: 183
// RVA: 0x1302BD0
unsigned __int64 __fastcall hkTrackerScanSnapshot::calcOrderedTotalUsed(hkTrackerScanSnapshot::Block *const *blocks, int numBlocks)
{
  hkTrackerScanSnapshot::Block *const *v2; // rdi
  hkTrackerScanSnapshot::Block *v4; // r9
  signed __int64 v5; // rcx
  unsigned __int64 v6; // r10
  signed __int64 i; // rbx
  hkTrackerScanSnapshot::Block *v8; // r8
  const char *v9; // rdx
  unsigned __int64 v10; // r11

  v2 = blocks;
  if ( !numBlocks )
    return 0i64;
  v4 = *blocks;
  v5 = 1i64;
  v6 = v4->m_size;
  for ( i = numBlocks; v5 < i; ++v5 )
  {
    v8 = v2[v5];
    v9 = v4->m_start;
    v10 = (unsigned __int64)v8->m_start;
    if ( v10 < (unsigned __int64)v9 || v10 >= (unsigned __int64)&v9[v4->m_size] )
    {
      v6 += v8->m_size;
      v4 = v2[v5];
    }
  }
  return v6;
}

// File Line: 227
// RVA: 0x1302450
void __fastcall hkTrackerScanSnapshot::findBlocksByType(hkTrackerScanSnapshot *this, const char *name, hkArray<hkTrackerScanSnapshot::Block *,hkContainerHeapAllocator> *blocksOut)
{
  int v3; // edi
  hkArray<hkTrackerScanSnapshot::Block *,hkContainerHeapAllocator> *v4; // rbx
  const char *v5; // r15
  hkTrackerScanSnapshot *v6; // rbp
  __int64 v7; // rsi
  hkTrackerTypeTreeNode **v8; // r14
  hkBool result; // [rsp+50h] [rbp+8h]
  hkBool v10; // [rsp+60h] [rbp+18h]

  v3 = 0;
  v4 = blocksOut;
  v5 = name;
  blocksOut->m_size = 0;
  v6 = this;
  if ( this->m_blocks.m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      v8 = &v6->m_blocks.m_data[v7]->m_type;
      if ( *v8
        && hkTrackerTypeTreeNode::isNamedType(*v8, &result)->m_bool
        && hkSubString::operator==(&(*v8)->m_name, &v10, v5)->m_bool )
      {
        if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 8);
        v4->m_data[v4->m_size++] = (hkTrackerScanSnapshot::Block *)v8;
      }
      ++v3;
      ++v7;
    }
    while ( v3 < v6->m_blocks.m_size );
  }
}

// File Line: 244
// RVA: 0x1302510
signed __int64 __fastcall hkTrackerScanSnapshot::findReferenceIndex(hkTrackerScanSnapshot *this, hkTrackerScanSnapshot::Block *block, hkTrackerScanSnapshot::Block *refdBlock)
{
  __int64 v3; // r10
  hkTrackerScanSnapshot::Block **v4; // rax
  unsigned int v5; // ecx
  signed __int64 v6; // r9
  __int64 v7; // rax

  v3 = block->m_numReferences;
  if ( (signed int)v3 <= 0 )
    return 0xFFFFFFFFi64;
  v4 = this->m_references.m_data;
  v5 = 0;
  v6 = (signed __int64)&v4[block->m_startReferenceIndex];
  v7 = 0i64;
  if ( (signed int)v3 <= 0 )
    return 0xFFFFFFFFi64;
  while ( *(hkTrackerScanSnapshot::Block **)(v6 + 8 * v7) != refdBlock )
  {
    ++v7;
    ++v5;
    if ( v7 >= v3 )
      return 0xFFFFFFFFi64;
  }
  return v5;
}

