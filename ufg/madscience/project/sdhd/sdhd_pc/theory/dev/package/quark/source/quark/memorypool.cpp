// File Line: 76
// RVA: 0x1467F40
__int64 UFG::_dynamic_initializer_for__gReserveInfoLock__()
{
  UFG::qMutex::qMutex(&gReserveInfoLock, "ReserveInfoLock");
  return atexit(UFG::_dynamic_atexit_destructor_for__gReserveInfoLock__);
}

// File Line: 99
// RVA: 0x171360
UFG::qList<UFG::qMemoryPool,UFG::qMemoryPool,0,0> *__fastcall UFG::GetMemoryPoolList()
{
  if ( !(_S1_21 & 1) )
  {
    _S1_21 |= 1u;
    sMemoryPoolList.mNode.mPrev = (UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *)&sMemoryPoolList;
    sMemoryPoolList.mNode.mNext = (UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *)&sMemoryPoolList;
    atexit(UFG::GetMemoryPoolList_::_2_::_dynamic_atexit_destructor_for__sMemoryPoolList__);
  }
  return &sMemoryPoolList;
}

// File Line: 148
// RVA: 0x1614D0
void __fastcall UFG::qFixedAllocator::qFixedAllocator(UFG::qFixedAllocator *this)
{
  this->mName = 0i64;
  this->mBuffer = 0i64;
  this->mBufferSize = 0;
  this->mFreeListHead = 0i64;
  *(_QWORD *)&this->mBufferWasAllocated = 0i64;
  this->mMostSlotsAllocated = 0;
}

// File Line: 160
// RVA: 0x1730C0
void __fastcall UFG::qFixedAllocator::Init(UFG::qFixedAllocator *this, void *buffer, int buffer_size, int slot_size, const char *name)
{
  _QWORD *v5; // r10
  __int64 v6; // rcx

  v5 = buffer;
  if ( !this->mBuffer )
  {
    this->mBuffer = (char *)buffer;
    this->mFreeListHead = (char *)buffer;
    this->mName = name;
    this->mBufferSize = buffer_size;
    this->mSlotSize = slot_size;
    if ( buffer_size / slot_size - 1 > 0 )
    {
      v6 = (unsigned int)(buffer_size / slot_size - 1);
      do
      {
        *v5 = (char *)v5 + slot_size;
        v5 = (_QWORD *)((char *)v5 + slot_size);
        --v6;
      }
      while ( v6 );
    }
    *v5 = 0i64;
  }
}

// File Line: 183
// RVA: 0x173000
void __fastcall UFG::qFixedAllocator::Init(UFG::qFixedAllocator *this, int buffer_size, int slot_size, const char *name, unsigned __int64 allocation_params)
{
  const char *v5; // rbp
  __int64 v6; // rdi
  unsigned __int64 v7; // rsi
  UFG::qFixedAllocator *v8; // rbx
  UFG::qMemoryPool *v9; // rcx
  UFG::allocator::free_link *v10; // rax
  UFG::allocator::free_link *v11; // rcx
  __int64 v12; // rdx

  v5 = name;
  v6 = slot_size;
  v7 = buffer_size;
  v8 = this;
  if ( !this->mBuffer )
  {
    this->mBufferWasAllocated = 1;
    v9 = UFG::gMainMemoryPool;
    if ( !UFG::gMainMemoryPool )
    {
      UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
      v9 = UFG::gMainMemoryPool;
    }
    v10 = UFG::qMemoryPool::Allocate(v9, v7, v5, allocation_params, 1u);
    v11 = v10;
    if ( !v8->mBuffer )
    {
      v8->mBuffer = (char *)v10;
      v8->mFreeListHead = (char *)v10;
      v8->mName = v5;
      v8->mBufferSize = v7;
      v8->mSlotSize = v6;
      if ( (signed int)v7 / (signed int)v6 - 1 > 0 )
      {
        v12 = (unsigned int)((signed int)v7 / (signed int)v6 - 1);
        do
        {
          v11->mNext = (UFG::allocator::free_link *)((char *)v11 + v6);
          v11 = (UFG::allocator::free_link *)((char *)v11 + v6);
          --v12;
        }
        while ( v12 );
      }
      v11->mNext = 0i64;
    }
  }
}

// File Line: 195
// RVA: 0x167E60
void __fastcall UFG::qFixedAllocator::Close(UFG::qFixedAllocator *this)
{
  UFG::qFixedAllocator *v1; // rbx
  char *v2; // rdx

  v1 = this;
  if ( this->mBufferWasAllocated )
  {
    v2 = this->mBuffer;
    if ( v2 )
      UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v2);
  }
  v1->mBuffer = 0i64;
  v1->mBufferSize = 0;
  v1->mFreeListHead = 0i64;
  v1->mBufferWasAllocated = 0;
}

// File Line: 210
// RVA: 0x17ACA0
void __fastcall UFG::qFixedAllocator::ReportFull(UFG::qFixedAllocator *this)
{
  UFG::qPrintf("* Fixed allocator pool '%s' out of memory.\n", this->mName);
}

// File Line: 259
// RVA: 0x166410
void __fastcall UFG::AddMemoryTransaction(UFG::qMemoryPool *pool, unsigned int op, void *address, unsigned int size, const char *name)
{
  unsigned int v5; // ebx
  void *v6; // rdi
  __int64 v7; // rsi
  UFG::MemoryTransaction *v8; // r8

  v5 = size;
  v6 = address;
  v7 = op;
  if ( UFG::gMemoryTransactions != 0i64 && pool == UFG::gMainMemoryPool )
  {
    v8 = &UFG::gMemoryTransactions[(unsigned int)UFG::qAtomicIncrement((volatile int *)&UFG::gCurrentTransactionIndex)
                                 % UFG::gNumMemoryTransactions];
    v8->mName = name;
    v8->mAddress = v6;
    v8->mSize = v7 | 2 * v5;
  }
}

// File Line: 366
// RVA: 0x161710
void __fastcall UFG::qMemoryPool::qMemoryPool(UFG::qMemoryPool *this)
{
  UFG::qList<UFG::qMemoryPool,UFG::qMemoryPool,0,0> *i; // rax

  this->mPrev = (UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *)&this->mPrev;
  this->mInitializedUID = 0;
  this->mUsePageBasedStompFinder = 0;
  if ( !(_S1_21 & 1) )
  {
    _S1_21 |= 1u;
    sMemoryPoolList.mNode.mPrev = (UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *)&sMemoryPoolList;
    sMemoryPoolList.mNode.mNext = (UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *)&sMemoryPoolList;
    atexit(UFG::GetMemoryPoolList_::_2_::_dynamic_atexit_destructor_for__sMemoryPoolList__);
  }
  for ( i = (UFG::qList<UFG::qMemoryPool,UFG::qMemoryPool,0,0> *)sMemoryPoolList.mNode.mNext;
        i != &sMemoryPoolList;
        i = (UFG::qList<UFG::qMemoryPool,UFG::qMemoryPool,0,0> *)i->mNode.mNext )
  {
    ;
  }
}

// File Line: 383
// RVA: 0x16CF10
void __fastcall UFG::qMemoryPool::EnablePageBasedStompDetection(UFG::qMemoryPool *this)
{
  this->mUsePageBasedStompFinder = 1;
  UFG::qMemoryPool::msPageFaultCorruptionDetectorActive = 1;
}

// File Line: 394
// RVA: 0x173370
void __fastcall UFG::qMemoryPool::Init(UFG::qMemoryPool *this, const char *name, __int64 memory_byte_size, int small_block_byte_size, int can_small_block_overflow_into_large_block, unsigned int InStatList, UFG::qMemoryPool *overflow_pool, int printWarningOnOverflow, bool bInitializeAllocator)
{
  UFG::qMemoryPool *v9; // r14
  int v10; // edi
  __int64 v11; // rsi
  const char *v12; // rbp
  void *v13; // rbx

  v9 = this;
  v10 = small_block_byte_size;
  v11 = memory_byte_size;
  v12 = name;
  v13 = UFG::qSystemAlloc(memory_byte_size);
  UFG::qMemoryPool::Init(
    v9,
    v12,
    v13,
    v11,
    v10,
    can_small_block_overflow_into_large_block,
    InStatList,
    overflow_pool,
    printWarningOnOverflow,
    bInitializeAllocator);
  v9->mAutoAllocatedBuffer = v13;
}

// File Line: 410
// RVA: 0x173250
void __fastcall UFG::qMemoryPool::Init(UFG::qMemoryPool *this, const char *name, void *memory, __int64 memory_byte_size, int small_block_byte_size, int can_small_block_overflow_into_large_block, unsigned int InStatList, UFG::qMemoryPool *overflow_pool, int printWarningOnOverflow, bool bInitializeAllocator)
{
  const char *v10; // rdi
  UFG::qMemoryPool *v11; // rbx
  bool v12; // zf
  UFG::allocator *v13; // rcx
  UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *v14; // rax

  v10 = name;
  v11 = this;
  this->mInitializedUID = 0x34566543;
  this->mAutoAllocatedBuffer = 0i64;
  v12 = this->mDataBuffer == 0i64;
  v13 = (UFG::allocator *)this->mDataBuffer;
  v11->mData = (UFG::qMemoryPoolData *)v13;
  v11->mStart = (char *)memory;
  v11->mEnd = (char *)memory + memory_byte_size;
  v11->mOverflowPool = overflow_pool;
  v11->mOverflowOccurred = 0;
  v11->mPrintWarningOnOverflow = printWarningOnOverflow;
  *(_QWORD *)&v11->mNumActiveSpilledAllocs = 0i64;
  *(_QWORD *)&v11->mAmountOfSpilledMemory = 0i64;
  v11->mFlags = 0;
  if ( !v12 )
    UFG::allocator::allocator(v13);
  if ( bInitializeAllocator )
    UFG::allocator::init(
      &v11->mData->mAllocator,
      v10,
      v11->mStart,
      v11->mEnd - v11->mStart,
      small_block_byte_size,
      can_small_block_overflow_into_large_block);
  if ( !(_S1_21 & 1) )
  {
    _S1_21 |= 1u;
    sMemoryPoolList.mNode.mPrev = (UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *)&sMemoryPoolList;
    sMemoryPoolList.mNode.mNext = (UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *)&sMemoryPoolList;
    atexit(UFG::GetMemoryPoolList_::_2_::_dynamic_atexit_destructor_for__sMemoryPoolList__);
  }
  v14 = sMemoryPoolList.mNode.mPrev;
  sMemoryPoolList.mNode.mPrev->mNext = (UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *)&v11->mPrev;
  v11->mPrev = v14;
  v11->mNext = (UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *)&sMemoryPoolList;
  sMemoryPoolList.mNode.mPrev = (UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *)&v11->mPrev;
}

// File Line: 450
// RVA: 0x167EA0
void __fastcall UFG::qMemoryPool::Close(UFG::qMemoryPool *this)
{
  UFG::qMemoryPool *v1; // rbx
  UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *v2; // rcx
  UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *v3; // rax
  void *v4; // rdx

  v1 = this;
  if ( !(_S1_21 & 1) )
  {
    _S1_21 |= 1u;
    sMemoryPoolList.mNode.mPrev = (UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *)&sMemoryPoolList;
    sMemoryPoolList.mNode.mNext = (UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *)&sMemoryPoolList;
    atexit(UFG::GetMemoryPoolList_::_2_::_dynamic_atexit_destructor_for__sMemoryPoolList__);
  }
  v2 = v1->mPrev;
  v3 = v1->mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->mPrev = (UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *)&v1->mPrev;
  UFG::allocator::~allocator(&v1->mData->mAllocator);
  v4 = v1->mAutoAllocatedBuffer;
  if ( v4 )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v4);
  v1->mInitializedUID = 0;
}

// File Line: 470
// RVA: 0x1713C0
const char *__fastcall UFG::qMemoryPool::GetName(UFG::qMemoryPool *this)
{
  return this->mData->mAllocator.mName;
}

// File Line: 477
// RVA: 0x172BF0
unsigned __int64 __fastcall UFG::qMemoryPool::GetTotalPoolBytes(UFG::qMemoryPool *this)
{
  return this->mData->mAllocator.mStats.mLargePoolNumBytes
       + this->mData->mAllocator.mStats.mSmallPoolNumBytes
       + this->mData->mAllocator.mStats.mLinearAllocNumBytes
       - this->mData->mAllocator.mStats.mSmallSystemAllocNumBytes;
}

// File Line: 479
// RVA: 0x172BD0
unsigned __int64 __fastcall UFG::qMemoryPool::GetTotalFreeBytes(UFG::qMemoryPool *this)
{
  return this->mData->mAllocator.mStats.mLargePoolNumBytes
       + this->mData->mAllocator.mStats.mSmallPoolNumBytes
       - this->mData->mAllocator.mStats.mSmallAllocNumBytes
       - this->mData->mAllocator.mStats.mLargeAllocNumBytes;
}

// File Line: 484
// RVA: 0x170C00
unsigned __int64 __fastcall UFG::qMemoryPool::GetLargeFreeBytes(UFG::qMemoryPool *this)
{
  return this->mData->mAllocator.mStats.mLargePoolNumBytes - this->mData->mAllocator.mStats.mLargeAllocNumBytes;
}

// File Line: 485
// RVA: 0x170C10
unsigned __int64 __fastcall UFG::qMemoryPool::GetLargeHighWaterBytes(UFG::qMemoryPool *this)
{
  return this->mData->mAllocator.mStats.mLargeAllocHighWaterNumBytes
       - this->mData->mAllocator.mStats.mSmallSystemAllocNumBytes;
}

// File Line: 507
// RVA: 0x170C20
unsigned __int64 __fastcall UFG::qMemoryPool::GetLargestFree(UFG::qMemoryPool *this, unsigned __int64 allocation_params)
{
  return UFG::allocator::get_largest_free_size(&this->mData->mAllocator);
}

// File Line: 865
// RVA: 0x166B60
UFG::allocator::free_link *__fastcall UFG::qMemoryPool::Allocate(UFG::qMemoryPool *this, unsigned __int64 size, const char *name, unsigned __int64 allocation_params, unsigned int check_null)
{
  UFG::qMemoryPool *v5; // rbp
  const char *v6; // rax
  unsigned __int64 v7; // rdi
  int v8; // edx
  int v9; // er8
  signed int v10; // ecx
  unsigned __int64 v11; // rbx
  UFG::allocator::free_link *result; // rax
  UFG::allocator::free_link *v13; // rbx
  UFG::allocator::allocation_strategy v14; // er9
  UFG::allocator::free_link *v15; // rsi
  UFG::qMemoryPool *v16; // rcx
  char *v17; // rax
  const char *v18; // r9
  char *v19; // [rsp+50h] [rbp+18h]

  v19 = (char *)name;
  v5 = this;
  v6 = name;
  v7 = size;
  v8 = allocation_params & 1;
  v9 = allocation_params & 2;
  v10 = (unsigned int)allocation_params >> 8;
  v11 = allocation_params;
  if ( !v5->mUsePageBasedStompFinder )
  {
    v14 = 0;
    if ( v8 )
    {
      v14 = 2;
    }
    else if ( v9 )
    {
      v14 = 1;
    }
    v15 = UFG::allocator::alloc(&v5->mData->mAllocator, v7, v10, v14, v6);
    UFG::AddMemoryTransaction(v5, 0, v15, v7, v19);
    if ( v15 )
      return v15;
    if ( !v7 )
      goto LABEL_21;
    v16 = v5->mOverflowPool;
    if ( !v16 && !(v11 & 4) )
      goto LABEL_21;
    v5->mOverflowOccurred = 1;
    if ( v16 )
    {
      v17 = UFG::qMemoryPool::Allocate(v16, v7, v19, v11, check_null);
    }
    else
    {
      if ( !(v11 & 4) )
        goto LABEL_21;
      v17 = UFG::qMalloc(v7, v19, v11 & 0xFFFFFFFFFFFFFFFAui64);
    }
    v15 = (UFG::allocator::free_link *)v17;
    if ( v17 )
      return v15;
LABEL_21:
    if ( check_null && v7 )
    {
      v18 = "NULL name passed in";
      if ( v19 )
        v18 = v19;
      UFG::qPrintf(
        "\nERROR: *** Out of memory ***\nERROR: Pool name      = %s\nERROR: Requested size = %d [%s]\n",
        v5->mData->mAllocator.mName,
        v7,
        v18);
      __debugbreak();
    }
    return v15;
  }
  result = (UFG::allocator::free_link *)UFG::qVirtualAlloc((v7 + 0x10FFF) & 0xFFFFFFFFFFFF0000ui64);
  v13 = result;
  if ( result )
  {
    if ( v7 & 0xFFF )
      v13 = (UFG::allocator::free_link *)((char *)result - (v7 & 0xFFF) + 4096);
    if ( !UFG::qVirtualCommit(
            (void *)((unsigned __int64)v13 & 0xFFFFFFFFFFFFF000ui64),
            (v7 + 4095) & 0xFFFFFFFFFFFFF000ui64,
            qVirtualAccess_ReadWrite) )
      v13 = 0i64;
    result = v13;
  }
  return result;
}

// File Line: 996
// RVA: 0x179A50
UFG::allocator::free_link *__fastcall UFG::qMemoryPool::Realloc(UFG::qMemoryPool *this, void *mem, unsigned __int64 size, const char *name, unsigned __int64 allocation_params)
{
  unsigned __int64 v5; // rdi
  void *v6; // rsi
  UFG::qMemoryPool *v7; // rbp
  UFG::allocator::free_link *result; // rax
  UFG::allocator::free_link *v9; // rbx
  unsigned __int64 v10; // rax

  v5 = size;
  v6 = mem;
  v7 = this;
  result = UFG::qMemoryPool::Allocate(this, size, name, allocation_params, 1u);
  v9 = result;
  if ( v6 )
  {
    v10 = UFG::qMemoryPool::Size(v7, v6);
    if ( v10 < v5 )
      LODWORD(v5) = v10;
    UFG::qMemCopy(v9, v6, v5);
    UFG::qMemoryPool::Free(v7, v6);
    result = v9;
  }
  return result;
}

// File Line: 1010
// RVA: 0x179900
char *__fastcall UFG::qMemoryPool::Realloc(UFG::qMemoryPool *this, void *mem, unsigned __int64 new_size, unsigned __int64 old_size, const char *name, unsigned __int64 allocation_params)
{
  char *v6; // rbp
  UFG::allocator::allocation_strategy v7; // edx
  unsigned __int64 v8; // rdi
  unsigned __int64 v9; // rsi
  UFG::qMemoryPool *v10; // r14
  UFG::allocator::free_link *v11; // rax
  char *v12; // rbx
  char *result; // rax
  UFG::allocator::free_link *v14; // rax
  char *v15; // rbx

  v6 = (char *)mem;
  v7 = 0;
  v8 = old_size;
  v9 = new_size;
  v10 = this;
  if ( this->mEnd != 0i64 && this->mStart != 0i64 && (v6 >= this->mEnd || v6 < this->mStart) && v6 != 0i64 )
  {
    v11 = UFG::qMemoryPool::Allocate(this, new_size, name, allocation_params, 1u);
    v12 = (char *)v11;
    if ( v6 )
    {
      if ( v9 < v8 )
        LODWORD(v8) = v9;
      UFG::qMemCopy(v11, v6, v8);
      UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v6);
    }
    result = v12;
  }
  else
  {
    if ( allocation_params & 1 )
    {
      v7 = 2;
    }
    else if ( allocation_params & 2 )
    {
      v7 = 1;
    }
    result = (char *)UFG::allocator::realloc(&this->mData->mAllocator, v6, new_size, old_size, v7, name);
    if ( !result && v9 )
    {
      v14 = UFG::qMemoryPool::Allocate(v10, v9, name, allocation_params, 1u);
      v15 = (char *)v14;
      if ( v6 )
      {
        if ( v9 < v8 )
          LODWORD(v8) = v9;
        UFG::qMemCopy(v14, v6, v8);
        UFG::qMemoryPool::Free(v10, v6);
      }
      result = v15;
    }
  }
  return result;
}

// File Line: 1059
// RVA: 0x16E720
void __fastcall UFG::qMemoryPool::Free(UFG::qMemoryPool *this, void *ptr)
{
  bool v2; // di
  UFG::qMemoryPool *v3; // rbx
  char *v4; // rsi
  UFG::qMemoryPool *v5; // r9
  int v6; // eax
  char *name; // rdi
  unsigned int v8; // eax
  UFG::qMemoryPoolData *v9; // r8
  unsigned __int64 v10; // rax
  void *v11; // rbx
  unsigned __int64 v12; // rdi
  unsigned int v13; // edx
  __int64 v14; // rax
  unsigned __int64 v15; // rax
  UFG::ReserveInfo *v16; // rbx
  UFG::qList<UFG::allocator::system_page_header,UFG::allocator::system_page_header,0,0> *v17; // rcx
  UFG::qBasicMemInfo out; // [rsp+30h] [rbp-38h]

  v2 = ptr != 0i64;
  v3 = this;
  v4 = (char *)ptr;
  if ( this->mEnd == 0i64 || this->mStart == 0i64 || ptr < this->mEnd && ptr >= this->mStart || ptr == 0i64 )
  {
LABEL_10:
    if ( v2 && UFG::gClearMemoryOnFree )
    {
      v6 = UFG::qMemoryPool::Size(v3, v4);
      UFG::qMemSet(v4, -16843010, (v6 + 15) & 0xFFFFFFF0);
    }
    name = UFG::qMemoryPool::GetAllocName(v3, v4);
    v8 = UFG::qMemoryPool::Size(v3, v4);
    UFG::AddMemoryTransaction(v3, 1u, v4, v8, name);
    v9 = v3->mData;
    if ( !v4 )
      return;
    v10 = (unsigned __int64)v9->mAllocator.mSmallBlockStart;
    if ( v10 )
    {
      if ( (unsigned __int64)v4 < v10 || v4 >= v9->mAllocator.mSmallBlockEnd )
        goto LABEL_16;
    }
    else
    {
      v17 = (UFG::qList<UFG::allocator::system_page_header,UFG::allocator::system_page_header,0,0> *)v9->mAllocator.mSmallBlockSystemPages.mNode.mNext;
      if ( v17 == &v9->mAllocator.mSmallBlockSystemPages )
      {
LABEL_16:
        UFG::allocator::tree_free(&v3->mData->mAllocator, v4);
        return;
      }
      while ( v4 < (char *)((char *)v17 - (char *)v17[1].mNode.mPrev) || v4 >= (char *)v17 )
      {
        v17 = (UFG::qList<UFG::allocator::system_page_header,UFG::allocator::system_page_header,0,0> *)v17->mNode.mNext;
        if ( v17 == &v9->mAllocator.mSmallBlockSystemPages )
          goto LABEL_16;
      }
    }
    UFG::allocator::bucket_free(&v3->mData->mAllocator, v4);
    return;
  }
  v5 = UFG::gMainMemoryPool;
  while ( !v3->mUsePageBasedStompFinder )
  {
    if ( v3->mOverflowPool )
    {
      v3 = v3->mOverflowPool;
    }
    else
    {
      if ( v3 == v5 )
      {
        UFG::qPrintf(
          "Attempting to free something that isn't in any memory pool (ptr: 0x%8X, %s: 0x%8X - 0x%8X)",
          v4,
          v3->mData->mAllocator.mName,
          v3->mStart,
          v3->mEnd);
        __debugbreak();
        JUMPOUT(loc_14016E8F1);
      }
      UFG::qPrintf("WARNING: pool name: %s\n", v3->mData->mAllocator.mName);
      if ( !v4 )
        return;
      v5 = UFG::gMainMemoryPool;
      v3 = UFG::gMainMemoryPool;
    }
    if ( v3->mEnd == 0i64 || v3->mStart == 0i64 || v4 < v3->mEnd && v4 >= v3->mStart || !v2 )
      goto LABEL_10;
  }
  if ( v4 )
  {
    out.mpBaseAddress = 0i64;
    out.mpAllocationBase = 0i64;
    out.mVirtualAccessAtAllocation = 0;
    *(_OWORD *)&out.mRegionSize = 0ui64;
    out.mVirtualRegionType = 0;
    UFG::qVirtualQuery(v4, &out);
    v11 = out.mpAllocationBase;
    v12 = (out.mRegionSize + 69631) & 0xFFFFFFFFFFFF0000ui64;
    UFG::qVirtualDecommit(out.mpAllocationBase, out.mRegionSize);
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&gReserveInfoLock);
    v13 = gCircularReserveIndex;
    v14 = gCircularReserveIndex;
    gCircularReserveHistory[v14].mpAllocAddress = v11;
    gCircularReserveHistory[v14].mReserveSize = v12;
    v15 = v12 + gTotalReserved;
    gTotalReserved += v12;
    do
    {
      if ( ++v13 >= 0x10000 )
        v13 = 0;
      gCircularReserveIndex = v13;
      v16 = &gCircularReserveHistory[v13];
      if ( v16->mpAllocAddress )
      {
        UFG::qSystemFree(v16->mpAllocAddress);
        v13 = gCircularReserveIndex;
        v15 = gTotalReserved - v16->mReserveSize;
        v16->mpAllocAddress = 0i64;
        v16->mReserveSize = 0i64;
        gTotalReserved = v15;
      }
    }
    while ( v15 >= 0x6400000 );
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&gReserveInfoLock);
  }
}= v15;
      }
    }
    while ( v15 >= 0x64

// File Line: 1188
// RVA: 0x17CFB0
void __fastcall UFG::qMemoryPool::SetMark(UFG::qMemoryPool *this)
{
  UFG::allocator::set_mark(&this->mData->mAllocator);
}

// File Line: 1198
// RVA: 0x172DE0
int __fastcall UFG::qMemoryPool::GetUnmarkedCount(UFG::qMemoryPool *this)
{
  return UFG::allocator::get_unmarked_count(&this->mData->mAllocator);
}

// File Line: 1203
// RVA: 0x17ACB0
void __fastcall UFG::qMemoryPool::ReportUnmarked(UFG::qMemoryPool *this)
{
  UFG::allocator::report_unmarked(&this->mData->mAllocator);
}

// File Line: 1212
// RVA: 0x17D3B0
unsigned __int64 __fastcall UFG::qMemoryPool::Size(UFG::qMemoryPool *this, void *ptr)
{
  if ( this->mEnd == 0i64 || this->mStart == 0i64 || ptr < this->mEnd && ptr >= this->mStart || ptr == 0i64 )
    return UFG::allocator::size(&this->mData->mAllocator, ptr);
  while ( this->mOverflowPool )
  {
    this = this->mOverflowPool;
LABEL_6:
    if ( this->mEnd == 0i64 || this->mStart == 0i64 || ptr < this->mEnd && ptr >= this->mStart || ptr == 0i64 )
      return UFG::allocator::size(&this->mData->mAllocator, ptr);
  }
  if ( this != UFG::gMainMemoryPool )
  {
    this = UFG::gMainMemoryPool;
    goto LABEL_6;
  }
  __debugbreak();
  return 0i64;
}

// File Line: 1266
// RVA: 0x16F170
char *__fastcall UFG::qMemoryPool::GetAllocName(UFG::qMemoryPool *this, void *ptr)
{
  __int64 v2; // rdi
  char *v3; // rbx
  UFG::qMemoryPool *v4; // r11
  UFG::qMemoryPoolData *v5; // rdx
  unsigned __int64 v6; // rax
  unsigned __int64 v8; // rax
  signed __int64 v9; // rdx

  v2 = 0i64;
  v3 = (char *)ptr;
  v4 = this;
  while ( v4->mEnd != 0i64 && v4->mStart != 0i64 && (ptr >= v4->mEnd || ptr < v4->mStart) && ptr != 0i64 )
  {
    if ( v4->mOverflowPool )
    {
      v4 = v4->mOverflowPool;
    }
    else
    {
      if ( v4 == UFG::gMainMemoryPool )
      {
        __debugbreak();
        return "<Unknown>";
      }
      v4 = UFG::gMainMemoryPool;
    }
  }
  v5 = v4->mData;
  if ( !v3 )
    return (char *)v2;
  v6 = (unsigned __int64)v5->mAllocator.mSmallBlockStart;
  if ( v6 )
  {
    if ( (unsigned __int64)v3 < v6 || v3 >= v5->mAllocator.mSmallBlockEnd )
      return (char *)*((_QWORD *)v3 - 3);
  }
  else
  {
    v8 = (unsigned __int64)v5->mAllocator.mSmallBlockSystemPages.mNode.mNext;
    v9 = (signed __int64)&v5->mAllocator.mSmallBlockSystemPages;
    if ( v8 == v9 )
      return (char *)*((_QWORD *)v3 - 3);
    while ( (unsigned __int64)v3 < v8 - *(_QWORD *)(v8 + 16) || (unsigned __int64)v3 >= v8 )
    {
      v8 = *(_QWORD *)(v8 + 8);
      if ( v8 == v9 )
        return (char *)*((_QWORD *)v3 - 3);
    }
  }
  return &customWorldMapCaption;
}

// File Line: 1306
// RVA: 0x1731A0
void __fastcall UFG::qMemoryPool2::Init(UFG::qMemoryPool2 *this, const char *name, int memory_byte_size, int small_block_byte_size, int can_small_block_overflow_into_large_block, unsigned int InStatList, UFG::qMemoryPool *overflow_pool, int printWarningOnOverflow)
{
  const char *v8; // rdi
  UFG::qMemoryPool2 *v9; // rbx
  char *v10; // rax

  v8 = name;
  v9 = this;
  this->mName = name;
  this->mSmallBlockByteSize = small_block_byte_size;
  this->mOverflowIntoLargeBlock = can_small_block_overflow_into_large_block;
  UFG::qMemoryPool::Init(
    (UFG::qMemoryPool *)&this->mPrev,
    name,
    memory_byte_size,
    small_block_byte_size,
    can_small_block_overflow_into_large_block,
    InStatList,
    overflow_pool,
    printWarningOnOverflow,
    0);
  v10 = v9->mEnd;
  v9->mLinearAllocator = v10;
  v9->mMemoryEnd = v10;
  v9->mLinearAllocationMode = 1;
  v9->mLostBytes = 0;
  UFG::qMemSet(v9->mFreeLists, 0, 0x80u);
  v9->mData->mAllocator.mName = v8;
}

// File Line: 1341
// RVA: 0x16CE90
void __fastcall UFG::qMemoryPool2::DoneWithLinearAllocations(UFG::qMemoryPool2 *this)
{
  UFG::qMemoryPool2 *v1; // rbx
  __int64 v2; // rdx
  char *v3; // r9
  char *v4; // r8
  const char *v5; // rdx
  int can_small_block_overflow_into_large_block; // ST28_4
  unsigned __int64 small_block_byte_size; // ST20_8
  UFG::allocator *v8; // rcx

  v1 = this;
  if ( this->mLinearAllocationMode )
  {
    v2 = (unsigned int)this->mLostBytes;
    if ( (_DWORD)v2 )
      UFG::qPrintf(
        "qMemoryPool2::DoneWithLinearAllocations(): WARNING: lost %d bytes to Free() in the linear allocation region (pool = '%s')\n",
        v2,
        this->mName);
    v3 = v1->mLinearAllocator;
    v4 = v1->mStart;
    v5 = v1->mName;
    can_small_block_overflow_into_large_block = v1->mOverflowIntoLargeBlock;
    small_block_byte_size = v1->mSmallBlockByteSize;
    v8 = &v1->mData->mAllocator;
    v1->mEnd = v3;
    UFG::allocator::init(v8, v5, v4, v3 - v4, small_block_byte_size, can_small_block_overflow_into_large_block);
    v1->mLinearAllocationMode = 0;
  }
}

// File Line: 1359
// RVA: 0x166A70
char *__fastcall UFG::qMemoryPool2::Allocate(UFG::qMemoryPool2 *this, unsigned __int64 size, const char *name, unsigned __int64 allocation_params, unsigned int check_null)
{
  unsigned __int64 v5; // rsi
  const char *v6; // rbp
  unsigned __int64 v7; // rdi
  UFG::qMemoryPool2 *v8; // rbx
  unsigned int v9; // ecx
  unsigned __int64 v10; // rax
  signed __int64 v11; // rdx
  char *result; // rax
  char *v13; // rdx
  UFG::qMemoryPoolData *v14; // rcx

  v5 = allocation_params;
  v6 = name;
  v7 = size;
  v8 = this;
  if ( this->mLinearAllocationMode )
  {
    v9 = 4;
    if ( (signed int)((unsigned int)allocation_params >> 8) > 4 )
      v9 = (unsigned int)allocation_params >> 8;
    v10 = size >> 2;
    if ( (signed int)(size >> 2) < 16 )
    {
      v11 = (signed __int64)v8 + 8 * (signed int)v10;
      result = *(char **)(v11 + 9344);
      if ( result )
      {
        *(_QWORD *)(v11 + 9344) = *(_QWORD *)result;
        v8->mLostBytes -= v7;
        return result;
      }
    }
    result = (char *)((_QWORD)&v8->mLinearAllocator[-v7] & (signed int)~(v9 - 1));
    if ( result > v8->mStart + 128 )
    {
      v13 = v8->mMemoryEnd;
      v14 = v8->mData;
      v8->mLinearAllocator = result;
      v14->mAllocator.mStats.mLinearAllocNumBytes = v13 - result;
      return result;
    }
    UFG::qMemoryPool2::DoneWithLinearAllocations(v8);
    allocation_params = v5;
    name = v6;
    size = v7;
    this = v8;
  }
  return UFG::qMemoryPool::Allocate((UFG::qMemoryPool *)&this->mPrev, size, name, allocation_params, check_null);
}

// File Line: 1406
// RVA: 0x16E690
void __fastcall UFG::qMemoryPool2::Free(UFG::qMemoryPool2 *this, void *p, unsigned __int64 size)
{
  char *v3; // r9
  unsigned __int64 v4; // rax
  char *v5; // r8
  unsigned __int64 v6; // rax
  char *v7; // rax
  unsigned __int64 v8; // r8
  UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> **v9; // rcx

  if ( p < this->mLinearAllocator || (v3 = this->mMemoryEnd, p >= v3) )
  {
    UFG::qMemoryPool::Free((UFG::qMemoryPool *)&this->mPrev, p);
  }
  else
  {
    v4 = size + 3;
    v5 = this->mLinearAllocator;
    v6 = v4 & 0xFFFFFFFFFFFFFFFCui64;
    if ( p == v5 )
    {
      v7 = &v5[v6];
      this->mLinearAllocator = v7;
      this->mData->mAllocator.mStats.mLinearAllocNumBytes = v3 - v7;
    }
    else
    {
      this->mLostBytes += v6;
      v8 = v6 >> 2;
      if ( (signed int)(v6 >> 2) >= 16 )
      {
        UFG::qPrintf("qMemoryPool2::Free(): WARNING: couldn't free %d bytes (pool = '%s')\n", v6, this->mName);
      }
      else
      {
        v9 = &this->mPrev + (signed int)v8;
        *(_QWORD *)p = v9[1168];
        v9[1168] = (UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *)p;
      }
    }
  }
}

// File Line: 1450
// RVA: 0x187BE0
UFG::allocator::free_link *__fastcall UFG::qMalloc(unsigned __int64 sizet, const char *name, unsigned __int64 allocation_params)
{
  unsigned __int64 v3; // rsi
  UFG::qMemoryPool *v4; // rcx
  unsigned __int64 v5; // rbx
  const char *v6; // rdi

  v3 = sizet;
  v4 = UFG::gMainMemoryPool;
  v5 = allocation_params;
  v6 = name;
  if ( !UFG::gMainMemoryPool )
  {
    UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
    v4 = UFG::gMainMemoryPool;
  }
  return UFG::qMemoryPool::Allocate(v4, v3, v6, v5, 1u);
}

// File Line: 1487
// RVA: 0x18A1B0
UFG::allocator::free_link *__fastcall UFG::qRealloc(void *mem, unsigned __int64 size, const char *name, unsigned __int64 allocation_params)
{
  return UFG::qMemoryPool::Realloc(UFG::gMainMemoryPool, mem, size, name, allocation_params);
}

// File Line: 1529
// RVA: 0x183FF0
UFG::qMemoryPool *__fastcall UFG::qGetContainingPool(const void *mem)
{
  char *v1; // rbx
  UFG::qMemoryPool *result; // rax

  v1 = (char *)mem;
  if ( !(_S1_21 & 1) )
  {
    _S1_21 |= 1u;
    sMemoryPoolList.mNode.mPrev = (UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *)&sMemoryPoolList;
    sMemoryPoolList.mNode.mNext = (UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *)&sMemoryPoolList;
    atexit(UFG::GetMemoryPoolList_::_2_::_dynamic_atexit_destructor_for__sMemoryPoolList__);
  }
  for ( result = (UFG::qMemoryPool *)sMemoryPoolList.mNode.mNext;
        result != (UFG::qMemoryPool *)&sMemoryPoolList;
        result = (UFG::qMemoryPool *)result->mNext )
  {
    if ( result != UFG::gMainMemoryPool && v1 >= result->mStart && v1 < result->mEnd )
      return result;
  }
  if ( v1 < UFG::gMainMemoryPool->mStart || v1 >= UFG::gMainMemoryPool->mEnd )
    result = 0i64;
  else
    result = UFG::gMainMemoryPool;
  return result;
}

// File Line: 1661
// RVA: 0x189280
void __fastcall UFG::qPrintSummaryMemoryPools(UFG *this)
{
  UFG::qList<UFG::qMemoryPool,UFG::qMemoryPool,0,0> *i; // rax

  if ( !(_S1_21 & 1) )
  {
    _S1_21 |= 1u;
    sMemoryPoolList.mNode.mPrev = (UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *)&sMemoryPoolList;
    sMemoryPoolList.mNode.mNext = (UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *)&sMemoryPoolList;
    atexit(UFG::GetMemoryPoolList_::_2_::_dynamic_atexit_destructor_for__sMemoryPoolList__);
  }
  for ( i = (UFG::qList<UFG::qMemoryPool,UFG::qMemoryPool,0,0> *)sMemoryPoolList.mNode.mNext;
        i != &sMemoryPoolList;
        i = (UFG::qList<UFG::qMemoryPool,UFG::qMemoryPool,0,0> *)i->mNode.mNext )
  {
    ;
  }
}

// File Line: 1721
// RVA: 0x184A70
UFG::qMemoryPool *__fastcall UFG::qGetMemoryPool(UFG::qMemoryPool *prev)
{
  UFG::qMemoryPool *v1; // rbx
  UFG::qMemoryPool *v2; // rcx
  UFG::qMemoryPool *result; // rax

  v1 = prev;
  if ( !(_S1_21 & 1) )
  {
    _S1_21 |= 1u;
    sMemoryPoolList.mNode.mPrev = (UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *)&sMemoryPoolList;
    sMemoryPoolList.mNode.mNext = (UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *)&sMemoryPoolList;
    atexit(UFG::GetMemoryPoolList_::_2_::_dynamic_atexit_destructor_for__sMemoryPoolList__);
  }
  v2 = (UFG::qMemoryPool *)sMemoryPoolList.mNode.mNext;
  if ( v1 )
    v2 = (UFG::qMemoryPool *)v1->mNext;
  result = 0i64;
  if ( v2 != (UFG::qMemoryPool *)&sMemoryPoolList )
    result = v2;
  return result;
}

// File Line: 1838
// RVA: 0x1744A0
void __fastcall UFG::InternalSetupMainMemoryPool(UFG *this)
{
  UFG *v1; // rcx

  if ( (unsigned int)UFG::qAtomicIncrement(&sInitMallocSemaphore) == 1 )
  {
    UFG::gMainMemoryPool = &gMainMemoryPoolBuffer;
    UFG::qMemoryPool::qMemoryPool(&gMainMemoryPoolBuffer);
    UFG::qUserCallback_InitMainPool(v1);
    UFG::qAtomicDecrement(&sInitMallocSemaphore);
  }
  else
  {
    UFG::qAtomicDecrement(&sInitMallocSemaphore);
    while ( sInitMallocSemaphore > 0 )
      UFG::qSleep(1u);
  }
}

// File Line: 1890
// RVA: 0x173AC0
void __fastcall UFG::InitMemorySystem(UFG *this)
{
  UFG::qMemoryPool *v1; // r10
  int v2; // ebx
  unsigned __int64 v3; // rdi
  UFG::allocator::free_link *v4; // rax
  UFG::MemoryTransaction *v5; // rdi

  v1 = UFG::gMainMemoryPool;
  if ( !UFG::gMainMemoryPool )
  {
    UFG::InternalSetupMainMemoryPool(this);
    v1 = UFG::gMainMemoryPool;
  }
  v2 = UFG::gQuarkInitParams.mMemory_NumTransactions;
  if ( UFG::gQuarkInitParams.mMemory_NumTransactions > 0 )
  {
    v3 = 24i64 * UFG::gQuarkInitParams.mMemory_NumTransactions;
    if ( !is_mul_ok(UFG::gQuarkInitParams.mMemory_NumTransactions, 0x18ui64) )
      v3 = -1i64;
    if ( !v1 )
    {
      UFG::InternalSetupMainMemoryPool(this);
      v1 = UFG::gMainMemoryPool;
    }
    v4 = UFG::qMemoryPool::Allocate(v1, v3, "Quark.MemoryTransactions", 0i64, 1u);
    v5 = (UFG::MemoryTransaction *)v4;
    if ( v4 )
    {
      UFG::qMemSet(v4, 0, 24 * v2);
      UFG::gNumMemoryTransactions = v2;
      UFG::gMemoryTransactions = v5;
    }
  }
}

