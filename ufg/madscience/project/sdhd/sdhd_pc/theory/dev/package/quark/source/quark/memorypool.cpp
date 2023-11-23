// File Line: 76
// RVA: 0x1467F40
__int64 UFG::_dynamic_initializer_for__gReserveInfoLock__()
{
  UFG::qMutex::qMutex(&gReserveInfoLock, "ReserveInfoLock");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gReserveInfoLock__);
}

// File Line: 99
// RVA: 0x171360
UFG::qList<UFG::qMemoryPool,UFG::qMemoryPool,0,0> *__fastcall UFG::GetMemoryPoolList()
{
  if ( (_S1_21 & 1) == 0 )
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
void __fastcall UFG::qFixedAllocator::Init(
        UFG::qFixedAllocator *this,
        char *buffer,
        int buffer_size,
        int slot_size,
        const char *name)
{
  char *v5; // r10
  __int64 v6; // rcx

  v5 = buffer;
  if ( !this->mBuffer )
  {
    this->mBuffer = buffer;
    this->mFreeListHead = buffer;
    this->mName = name;
    this->mBufferSize = buffer_size;
    this->mSlotSize = slot_size;
    if ( buffer_size / slot_size - 1 > 0 )
    {
      v6 = (unsigned int)(buffer_size / slot_size - 1);
      do
      {
        *(_QWORD *)v5 = &v5[slot_size];
        v5 += slot_size;
        --v6;
      }
      while ( v6 );
    }
    *(_QWORD *)v5 = 0i64;
  }
}

// File Line: 183
// RVA: 0x173000
void __fastcall UFG::qFixedAllocator::Init(
        UFG::qFixedAllocator *this,
        int buffer_size,
        int slot_size,
        const char *name,
        unsigned __int64 allocation_params)
{
  __int64 v6; // rdi
  unsigned __int64 v7; // rsi
  UFG::qMemoryPool *v9; // rcx
  char *v10; // rax
  _QWORD *v11; // rcx
  __int64 v12; // rdx

  v6 = slot_size;
  v7 = buffer_size;
  if ( !this->mBuffer )
  {
    this->mBufferWasAllocated = 1;
    v9 = UFG::gMainMemoryPool;
    if ( !UFG::gMainMemoryPool )
    {
      UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
      v9 = UFG::gMainMemoryPool;
    }
    v10 = (char *)UFG::qMemoryPool::Allocate(v9, v7, name, allocation_params, 1u);
    v11 = v10;
    if ( !this->mBuffer )
    {
      this->mBuffer = v10;
      this->mFreeListHead = v10;
      this->mName = name;
      this->mBufferSize = v7;
      this->mSlotSize = v6;
      if ( (int)v7 / (int)v6 - 1 > 0 )
      {
        v12 = (unsigned int)((int)v7 / (int)v6 - 1);
        do
        {
          *v11 = (char *)v11 + v6;
          v11 = (_QWORD *)((char *)v11 + v6);
          --v12;
        }
        while ( v12 );
      }
      *v11 = 0i64;
    }
  }
}

// File Line: 195
// RVA: 0x167E60
void __fastcall UFG::qFixedAllocator::Close(UFG::qFixedAllocator *this)
{
  char *mBuffer; // rdx

  if ( this->mBufferWasAllocated )
  {
    mBuffer = this->mBuffer;
    if ( mBuffer )
      UFG::qMemoryPool::Free(UFG::gMainMemoryPool, mBuffer);
  }
  this->mBuffer = 0i64;
  this->mBufferSize = 0;
  this->mFreeListHead = 0i64;
  this->mBufferWasAllocated = 0;
}

// File Line: 210
// RVA: 0x17ACA0
void __fastcall UFG::qFixedAllocator::ReportFull(UFG::qFixedAllocator *this)
{
  UFG::qPrintf("* Fixed allocator pool %s out of memory.\n", this->mName);
}

// File Line: 259
// RVA: 0x166410
void __fastcall UFG::AddMemoryTransaction(
        UFG::qMemoryPool *pool,
        unsigned int op,
        void *address,
        unsigned int size,
        const char *name)
{
  __int64 v7; // rsi
  UFG::MemoryTransaction *v8; // r8

  v7 = op;
  if ( UFG::gMemoryTransactions != 0i64 && pool == UFG::gMainMemoryPool )
  {
    v8 = &UFG::gMemoryTransactions[(unsigned int)UFG::qAtomicIncrement((volatile int *)&UFG::gCurrentTransactionIndex)
                                 % UFG::gNumMemoryTransactions];
    v8->mName = name;
    v8->mAddress = address;
    v8->mSize = v7 | (2 * size);
  }
}

// File Line: 366
// RVA: 0x161710
void __fastcall UFG::qMemoryPool::qMemoryPool(UFG::qMemoryPool *this)
{
  UFG::qList<UFG::qMemoryPool,UFG::qMemoryPool,0,0> *i; // rax

  this->mPrev = this;
  this->mNext = this;
  this->mInitializedUID = 0;
  this->mUsePageBasedStompFinder = 0;
  if ( (_S1_21 & 1) == 0 )
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
void __fastcall UFG::qMemoryPool::Init(
        UFG::qMemoryPool *this,
        const char *name,
        unsigned __int64 memory_byte_size,
        int small_block_byte_size,
        int can_small_block_overflow_into_large_block,
        unsigned int InStatList,
        UFG::qMemoryPool *overflow_pool,
        int printWarningOnOverflow,
        bool bInitializeAllocator)
{
  char *v13; // rbx

  v13 = (char *)UFG::qSystemAlloc(memory_byte_size);
  UFG::qMemoryPool::Init(
    this,
    name,
    v13,
    memory_byte_size,
    small_block_byte_size,
    can_small_block_overflow_into_large_block,
    InStatList,
    overflow_pool,
    printWarningOnOverflow,
    bInitializeAllocator);
  this->mAutoAllocatedBuffer = v13;
}

// File Line: 410
// RVA: 0x173250
void __fastcall UFG::qMemoryPool::Init(
        UFG::qMemoryPool *this,
        const char *name,
        char *memory,
        __int64 memory_byte_size,
        int small_block_byte_size,
        int can_small_block_overflow_into_large_block,
        unsigned int InStatList,
        UFG::qMemoryPool *overflow_pool,
        int printWarningOnOverflow,
        bool bInitializeAllocator)
{
  bool v12; // zf
  char *mDataBuffer; // rcx
  UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *mPrev; // rax

  this->mInitializedUID = 0x34566543;
  this->mAutoAllocatedBuffer = 0i64;
  v12 = this->mDataBuffer == 0i64;
  mDataBuffer = this->mDataBuffer;
  this->mData = (UFG::qMemoryPoolData *)mDataBuffer;
  this->mStart = memory;
  this->mEnd = &memory[memory_byte_size];
  this->mOverflowPool = overflow_pool;
  this->mOverflowOccurred = 0;
  this->mPrintWarningOnOverflow = printWarningOnOverflow;
  *(_QWORD *)&this->mNumActiveSpilledAllocs = 0i64;
  *(_QWORD *)&this->mAmountOfSpilledMemory = 0i64;
  this->mFlags = 0;
  if ( !v12 )
    UFG::allocator::allocator((UFG::allocator *)mDataBuffer);
  if ( bInitializeAllocator )
    UFG::allocator::init(
      &this->mData->mAllocator,
      name,
      this->mStart,
      this->mEnd - this->mStart,
      small_block_byte_size,
      can_small_block_overflow_into_large_block);
  if ( (_S1_21 & 1) == 0 )
  {
    _S1_21 |= 1u;
    sMemoryPoolList.mNode.mPrev = (UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *)&sMemoryPoolList;
    sMemoryPoolList.mNode.mNext = (UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *)&sMemoryPoolList;
    atexit(UFG::GetMemoryPoolList_::_2_::_dynamic_atexit_destructor_for__sMemoryPoolList__);
  }
  mPrev = sMemoryPoolList.mNode.mPrev;
  sMemoryPoolList.mNode.mPrev->mNext = this;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *)&sMemoryPoolList;
  sMemoryPoolList.mNode.mPrev = this;
}

// File Line: 450
// RVA: 0x167EA0
void __fastcall UFG::qMemoryPool::Close(UFG::qMemoryPool *this)
{
  UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *mPrev; // rcx
  UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *mNext; // rax
  void *mAutoAllocatedBuffer; // rdx

  if ( (_S1_21 & 1) == 0 )
  {
    _S1_21 |= 1u;
    sMemoryPoolList.mNode.mPrev = (UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *)&sMemoryPoolList;
    sMemoryPoolList.mNode.mNext = (UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *)&sMemoryPoolList;
    atexit(UFG::GetMemoryPoolList_::_2_::_dynamic_atexit_destructor_for__sMemoryPoolList__);
  }
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = this;
  this->mNext = this;
  UFG::allocator::~allocator(&this->mData->mAllocator);
  mAutoAllocatedBuffer = this->mAutoAllocatedBuffer;
  if ( mAutoAllocatedBuffer )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, mAutoAllocatedBuffer);
  this->mInitializedUID = 0;
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
unsigned __int64 __fastcall UFG::qMemoryPool::GetLargestFree(
        UFG::qMemoryPool *this,
        unsigned __int64 allocation_params)
{
  return UFG::allocator::get_largest_free_size(&this->mData->mAllocator);
}

// File Line: 865
// RVA: 0x166B60
UFG::allocator::free_link *__fastcall UFG::qMemoryPool::Allocate(
        UFG::qMemoryPool *this,
        unsigned __int64 size,
        const char *name,
        unsigned __int64 allocation_params,
        unsigned int check_null)
{
  int v8; // edx
  int v9; // r8d
  signed int v10; // ecx
  UFG::allocator::free_link *result; // rax
  unsigned __int64 v13; // rbx
  UFG::allocator::allocation_strategy v14; // r9d
  UFG::allocator::free_link *v15; // rsi
  UFG::qMemoryPool *mOverflowPool; // rcx
  char *v17; // rax
  const char *v18; // r9

  v8 = allocation_params & 1;
  v9 = allocation_params & 2;
  v10 = (unsigned int)allocation_params >> 8;
  if ( !this->mUsePageBasedStompFinder )
  {
    v14 = strategy_bestfit;
    if ( v8 )
    {
      v14 = strategy_lastfit;
    }
    else if ( v9 )
    {
      v14 = strategy_firstfit;
    }
    v15 = UFG::allocator::alloc(&this->mData->mAllocator, size, v10, v14, name);
    UFG::AddMemoryTransaction(this, 0, v15, size, name);
    if ( v15 )
      return v15;
    if ( !size )
      goto LABEL_21;
    mOverflowPool = this->mOverflowPool;
    if ( !mOverflowPool && (allocation_params & 4) == 0 )
      goto LABEL_21;
    this->mOverflowOccurred = 1;
    if ( mOverflowPool )
    {
      v17 = UFG::qMemoryPool::Allocate(mOverflowPool, size, name, allocation_params, check_null);
    }
    else
    {
      if ( (allocation_params & 4) == 0 )
        goto LABEL_21;
      v17 = UFG::qMalloc(size, name, allocation_params & 0xFFFFFFFFFFFFFFFAui64);
    }
    v15 = (UFG::allocator::free_link *)v17;
    if ( v17 )
      return v15;
LABEL_21:
    if ( check_null && size )
    {
      v18 = "NULL name passed in";
      if ( name )
        v18 = name;
      UFG::qPrintf(
        "\nERROR: *** Out of memory ***\nERROR: Pool name      = %s\nERROR: Requested size = %d [%s]\n",
        this->mData->mAllocator.mName,
        size,
        v18);
      __debugbreak();
    }
    return v15;
  }
  result = (UFG::allocator::free_link *)UFG::qVirtualAlloc((size + 0x10FFF) & 0xFFFFFFFFFFFF0000ui64);
  v13 = (unsigned __int64)result;
  if ( result )
  {
    if ( (size & 0xFFF) != 0 )
      v13 = (unsigned __int64)&result[512] - (size & 0xFFF);
    if ( !UFG::qVirtualCommit(
            (void *)(v13 & 0xFFFFFFFFFFFFF000ui64),
            (size + 4095) & 0xFFFFFFFFFFFFF000ui64,
            qVirtualAccess_ReadWrite) )
      return 0i64;
    return (UFG::allocator::free_link *)v13;
  }
  return result;
}

// File Line: 996
// RVA: 0x179A50
UFG::allocator::free_link *__fastcall UFG::qMemoryPool::Realloc(
        UFG::qMemoryPool *this,
        void *mem,
        unsigned __int64 size,
        const char *name,
        unsigned __int64 allocation_params)
{
  unsigned __int64 v5; // rdi
  UFG::allocator::free_link *result; // rax
  UFG::allocator::free_link *v9; // rbx
  unsigned __int64 v10; // rax

  v5 = size;
  result = UFG::qMemoryPool::Allocate(this, size, name, allocation_params, 1u);
  v9 = result;
  if ( mem )
  {
    v10 = UFG::qMemoryPool::Size(this, mem);
    if ( v10 < v5 )
      LODWORD(v5) = v10;
    UFG::qMemCopy(v9, mem, v5);
    UFG::qMemoryPool::Free(this, (char *)mem);
    return v9;
  }
  return result;
}

// File Line: 1010
// RVA: 0x179900
UFG::allocator::free_link *__fastcall UFG::qMemoryPool::Realloc(
        UFG::qMemoryPool *this,
        char *mem,
        unsigned __int64 new_size,
        unsigned __int64 old_size,
        const char *name,
        unsigned __int64 allocation_params)
{
  UFG::allocator::allocation_strategy v7; // edx
  unsigned __int64 v8; // rdi
  UFG::allocator::free_link *v11; // rax
  UFG::allocator::free_link *v12; // rbx
  UFG::allocator::free_link *result; // rax
  UFG::allocator::free_link *v14; // rax
  UFG::allocator::free_link *v15; // rbx

  v7 = strategy_bestfit;
  v8 = old_size;
  if ( this->mEnd != 0i64 && this->mStart != 0i64 && (mem >= this->mEnd || mem < this->mStart) && mem != 0i64 )
  {
    v11 = UFG::qMemoryPool::Allocate(this, new_size, name, allocation_params, 1u);
    v12 = v11;
    if ( mem )
    {
      if ( new_size < v8 )
        LODWORD(v8) = new_size;
      UFG::qMemCopy(v11, mem, v8);
      UFG::qMemoryPool::Free(UFG::gMainMemoryPool, mem);
    }
    return v12;
  }
  else
  {
    if ( (allocation_params & 1) != 0 )
    {
      v7 = strategy_lastfit;
    }
    else if ( (allocation_params & 2) != 0 )
    {
      v7 = strategy_firstfit;
    }
    result = (UFG::allocator::free_link *)UFG::allocator::realloc(
                                            &this->mData->mAllocator,
                                            mem,
                                            new_size,
                                            old_size,
                                            v7,
                                            name);
    if ( !result && new_size )
    {
      v14 = UFG::qMemoryPool::Allocate(this, new_size, name, allocation_params, 1u);
      v15 = v14;
      if ( mem )
      {
        if ( new_size < v8 )
          LODWORD(v8) = new_size;
        UFG::qMemCopy(v14, mem, v8);
        UFG::qMemoryPool::Free(this, mem);
      }
      return v15;
    }
  }
  return result;
}

// File Line: 1059
// RVA: 0x16E720
void __fastcall UFG::qMemoryPool::Free(UFG::qMemoryPool *this, char *ptr)
{
  bool v2; // di
  UFG::qMemoryPool *v3; // rbx
  UFG::qMemoryPool *v5; // r9
  int v6; // eax
  char *name; // rdi
  unsigned int v8; // eax
  UFG::qMemoryPoolData *mData; // r8
  unsigned __int64 mSmallBlockStart; // rax
  void *mpAllocationBase; // rbx
  unsigned __int64 v12; // rdi
  unsigned int v13; // edx
  __int64 v14; // rax
  unsigned __int64 v15; // rax
  UFG::ReserveInfo *v16; // rbx
  unsigned __int64 mNext; // rcx
  UFG::qBasicMemInfo out; // [rsp+30h] [rbp-38h] BYREF

  v2 = ptr != 0i64;
  v3 = this;
  if ( this->mEnd == 0i64 || this->mStart == 0i64 || ptr < this->mEnd && ptr >= this->mStart || ptr == 0i64 )
  {
LABEL_10:
    if ( v2 && UFG::gClearMemoryOnFree )
    {
      v6 = UFG::qMemoryPool::Size(v3, ptr);
      UFG::qMemSet(ptr, -16843010, (v6 + 15) & 0xFFFFFFF0);
    }
    name = UFG::qMemoryPool::GetAllocName(v3, ptr);
    v8 = UFG::qMemoryPool::Size(v3, ptr);
    UFG::AddMemoryTransaction(v3, 1u, ptr, v8, name);
    mData = v3->mData;
    if ( !ptr )
      return;
    mSmallBlockStart = (unsigned __int64)mData->mAllocator.mSmallBlockStart;
    if ( mSmallBlockStart )
    {
      if ( (unsigned __int64)ptr < mSmallBlockStart || ptr >= mData->mAllocator.mSmallBlockEnd )
        goto LABEL_16;
    }
    else
    {
      mNext = (unsigned __int64)mData->mAllocator.mSmallBlockSystemPages.mNode.mNext;
      if ( (UFG::qList<UFG::allocator::system_page_header,UFG::allocator::system_page_header,0,0> *)mNext == &mData->mAllocator.mSmallBlockSystemPages )
      {
LABEL_16:
        UFG::allocator::tree_free(&v3->mData->mAllocator, ptr);
        return;
      }
      while ( (unsigned __int64)ptr < mNext - *(_QWORD *)(mNext + 16) || (unsigned __int64)ptr >= mNext )
      {
        mNext = *(_QWORD *)(mNext + 8);
        if ( (UFG::qList<UFG::allocator::system_page_header,UFG::allocator::system_page_header,0,0> *)mNext == &mData->mAllocator.mSmallBlockSystemPages )
          goto LABEL_16;
      }
    }
    UFG::allocator::bucket_free(&v3->mData->mAllocator, ptr);
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
          "Attempting to free something that isnt in any memory pool (ptr: 0x%8X, %s: 0x%8X - 0x%8X)",
          ptr,
          v3->mData->mAllocator.mName,
          v3->mStart,
          v3->mEnd);
        __debugbreak();
      }
      UFG::qPrintf("WARNING: pool name: %s\n", v3->mData->mAllocator.mName);
      if ( !ptr )
        return;
      v5 = UFG::gMainMemoryPool;
      v3 = UFG::gMainMemoryPool;
    }
    if ( v3->mEnd == 0i64 || v3->mStart == 0i64 || ptr < v3->mEnd && ptr >= v3->mStart || !v2 )
      goto LABEL_10;
  }
  if ( ptr )
  {
    memset(&out, 0, 20);
    memset(&out.mRegionSize, 0, 20);
    UFG::qVirtualQuery(ptr, &out);
    mpAllocationBase = out.mpAllocationBase;
    v12 = (out.mRegionSize + 69631) & 0xFFFFFFFFFFFF0000ui64;
    UFG::qVirtualDecommit(out.mpAllocationBase, out.mRegionSize);
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&gReserveInfoLock);
    v13 = gCircularReserveIndex;
    v14 = gCircularReserveIndex;
    gCircularReserveHistory[v14].mpAllocAddress = mpAllocationBase;
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
}
      }
    }
    while ( v15 >= 0x6400000 );
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&gReserveInfoLock);
  }


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
unsigned __int64 __fastcall UFG::qMemoryPool::Size(UFG::qMemoryPool *this, char *ptr)
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
char *__fastcall UFG::qMemoryPool::GetAllocName(UFG::qMemoryPool *this, char *ptr)
{
  __int64 v2; // rdi
  UFG::qMemoryPool *v4; // r11
  UFG::qMemoryPoolData *mData; // rdx
  unsigned __int64 mSmallBlockStart; // rax
  unsigned __int64 mNext; // rax
  UFG::qList<UFG::allocator::system_page_header,UFG::allocator::system_page_header,0,0> *p_mSmallBlockSystemPages; // rdx

  v2 = 0i64;
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
  mData = v4->mData;
  if ( !ptr )
    return (char *)v2;
  mSmallBlockStart = (unsigned __int64)mData->mAllocator.mSmallBlockStart;
  if ( mSmallBlockStart )
  {
    if ( (unsigned __int64)ptr < mSmallBlockStart || ptr >= mData->mAllocator.mSmallBlockEnd )
      return (char *)*((_QWORD *)ptr - 3);
  }
  else
  {
    mNext = (unsigned __int64)mData->mAllocator.mSmallBlockSystemPages.mNode.mNext;
    p_mSmallBlockSystemPages = &mData->mAllocator.mSmallBlockSystemPages;
    if ( (UFG::qList<UFG::allocator::system_page_header,UFG::allocator::system_page_header,0,0> *)mNext == p_mSmallBlockSystemPages )
      return (char *)*((_QWORD *)ptr - 3);
    while ( (unsigned __int64)ptr < mNext - *(_QWORD *)(mNext + 16) || (unsigned __int64)ptr >= mNext )
    {
      mNext = *(_QWORD *)(mNext + 8);
      if ( (UFG::qList<UFG::allocator::system_page_header,UFG::allocator::system_page_header,0,0> *)mNext == p_mSmallBlockSystemPages )
        return (char *)*((_QWORD *)ptr - 3);
    }
  }
  return &customCaption;
}

// File Line: 1306
// RVA: 0x1731A0
void __fastcall UFG::qMemoryPool2::Init(
        UFG::qMemoryPool2 *this,
        const char *name,
        int memory_byte_size,
        int small_block_byte_size,
        int can_small_block_overflow_into_large_block,
        unsigned int InStatList,
        UFG::qMemoryPool *overflow_pool,
        int printWarningOnOverflow)
{
  char *mEnd; // rax

  this->mName = name;
  this->mSmallBlockByteSize = small_block_byte_size;
  this->mOverflowIntoLargeBlock = can_small_block_overflow_into_large_block;
  UFG::qMemoryPool::Init(
    this,
    name,
    memory_byte_size,
    small_block_byte_size,
    can_small_block_overflow_into_large_block,
    InStatList,
    overflow_pool,
    printWarningOnOverflow,
    0);
  mEnd = this->mEnd;
  this->mLinearAllocator = mEnd;
  this->mMemoryEnd = mEnd;
  this->mLinearAllocationMode = 1;
  this->mLostBytes = 0;
  UFG::qMemSet(this->mFreeLists, 0, 0x80u);
  this->mData->mAllocator.UFG::qMemoryPool::mName = name;
}

// File Line: 1341
// RVA: 0x16CE90
void __fastcall UFG::qMemoryPool2::DoneWithLinearAllocations(UFG::qMemoryPool2 *this)
{
  __int64 mLostBytes; // rdx
  char *mLinearAllocator; // r9
  char *mStart; // r8
  const char *mName; // rdx
  UFG::qMemoryPoolData *mData; // rcx
  unsigned __int64 small_block_byte_size; // [rsp+20h] [rbp-18h]
  int can_small_block_overflow_into_large_block; // [rsp+28h] [rbp-10h]

  if ( this->mLinearAllocationMode )
  {
    mLostBytes = (unsigned int)this->mLostBytes;
    if ( (_DWORD)mLostBytes )
      UFG::qPrintf(
        "qMemoryPool2::DoneWithLinearAllocations(): WARNING: lost %d bytes to Free() in the linear allocation region (pool = %s)\n",
        mLostBytes,
        this->mName);
    mLinearAllocator = this->mLinearAllocator;
    mStart = this->mStart;
    mName = this->mName;
    can_small_block_overflow_into_large_block = this->mOverflowIntoLargeBlock;
    small_block_byte_size = this->mSmallBlockByteSize;
    mData = this->mData;
    this->mEnd = mLinearAllocator;
    UFG::allocator::init(
      &mData->mAllocator,
      mName,
      mStart,
      mLinearAllocator - mStart,
      small_block_byte_size,
      can_small_block_overflow_into_large_block);
    this->mLinearAllocationMode = 0;
  }
}

// File Line: 1359
// RVA: 0x166A70
char *__fastcall UFG::qMemoryPool2::Allocate(
        UFG::qMemoryPool2 *this,
        unsigned __int64 size,
        const char *name,
        unsigned __int64 allocation_params,
        unsigned int check_null)
{
  unsigned __int64 v5; // rsi
  const char *v6; // rbp
  unsigned __int64 v7; // rdi
  UFG::qMemoryPool2 *v8; // rbx
  unsigned int v9; // ecx
  UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> **v10; // rdx
  char *result; // rax
  char *mMemoryEnd; // rdx
  UFG::qMemoryPoolData *mData; // rcx

  v5 = allocation_params;
  v6 = name;
  v7 = size;
  v8 = this;
  if ( this->mLinearAllocationMode )
  {
    v9 = 4;
    if ( (unsigned int)allocation_params >> 8 > 4 )
      v9 = (unsigned int)allocation_params >> 8;
    if ( (int)(size >> 2) < 16 )
    {
      v10 = &v8->mPrev + (int)(size >> 2);
      result = (char *)v10[1168];
      if ( result )
      {
        v10[1168] = *(UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> **)result;
        v8->mLostBytes -= v7;
        return result;
      }
    }
    result = (char *)((__int64)&v8->mLinearAllocator[-v7] & (int)~(v9 - 1));
    if ( result > v8->mStart + 128 )
    {
      mMemoryEnd = v8->mMemoryEnd;
      mData = v8->mData;
      v8->mLinearAllocator = result;
      mData->mAllocator.mStats.mLinearAllocNumBytes = mMemoryEnd - result;
      return result;
    }
    UFG::qMemoryPool2::DoneWithLinearAllocations(v8);
    allocation_params = v5;
    name = v6;
    size = v7;
    this = v8;
  }
  return UFG::qMemoryPool::Allocate(this, size, name, allocation_params, check_null);
}

// File Line: 1406
// RVA: 0x16E690
void __fastcall UFG::qMemoryPool2::Free(UFG::qMemoryPool2 *this, char *p, unsigned __int64 size)
{
  char *mMemoryEnd; // r9
  __int64 v4; // rax
  char *mLinearAllocator; // r8
  unsigned __int64 v6; // rax
  char *v7; // rax
  UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> **v8; // rcx

  if ( p < this->mLinearAllocator || (mMemoryEnd = this->mMemoryEnd, p >= mMemoryEnd) )
  {
    UFG::qMemoryPool::Free(this, p);
  }
  else
  {
    v4 = size + 3;
    mLinearAllocator = this->mLinearAllocator;
    v6 = v4 & 0xFFFFFFFFFFFFFFFCui64;
    if ( p == mLinearAllocator )
    {
      v7 = &mLinearAllocator[v6];
      this->mLinearAllocator = v7;
      this->mData->mAllocator.mStats.mLinearAllocNumBytes = mMemoryEnd - v7;
    }
    else
    {
      this->mLostBytes += v6;
      if ( (int)(v6 >> 2) >= 16 )
      {
        UFG::qPrintf("qMemoryPool2::Free(): WARNING: couldnt free %d bytes (pool = %s)\n", v6, this->mName);
      }
      else
      {
        v8 = &this->mPrev + (int)(v6 >> 2);
        *(_QWORD *)p = v8[1168];
        v8[1168] = (UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *)p;
      }
    }
  }
}

// File Line: 1450
// RVA: 0x187BE0
UFG::allocator::free_link *__fastcall UFG::qMalloc(
        unsigned __int64 sizet,
        const char *name,
        unsigned __int64 allocation_params)
{
  UFG::qMemoryPool *v4; // rcx

  v4 = UFG::gMainMemoryPool;
  if ( !UFG::gMainMemoryPool )
  {
    UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
    v4 = UFG::gMainMemoryPool;
  }
  return UFG::qMemoryPool::Allocate(v4, sizet, name, allocation_params, 1u);
}

// File Line: 1487
// RVA: 0x18A1B0
UFG::allocator::free_link *__fastcall UFG::qRealloc(
        void *mem,
        unsigned __int64 size,
        const char *name,
        unsigned __int64 allocation_params)
{
  return UFG::qMemoryPool::Realloc(UFG::gMainMemoryPool, mem, size, name, allocation_params);
}

// File Line: 1529
// RVA: 0x183FF0
UFG::qMemoryPool *__fastcall UFG::qGetContainingPool(char *mem)
{
  UFG::qMemoryPool *result; // rax

  if ( (_S1_21 & 1) == 0 )
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
    if ( result != UFG::gMainMemoryPool && mem >= result->mStart && mem < result->mEnd )
      return result;
  }
  if ( mem < UFG::gMainMemoryPool->mStart || mem >= UFG::gMainMemoryPool->mEnd )
    return 0i64;
  else
    return UFG::gMainMemoryPool;
}

// File Line: 1661
// RVA: 0x189280
void __fastcall UFG::qPrintSummaryMemoryPools(UFG *this)
{
  UFG::qList<UFG::qMemoryPool,UFG::qMemoryPool,0,0> *i; // rax

  if ( (_S1_21 & 1) == 0 )
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
UFG::qList<UFG::qMemoryPool,UFG::qMemoryPool,0,0> *__fastcall UFG::qGetMemoryPool(UFG::qMemoryPool *prev)
{
  UFG::qList<UFG::qMemoryPool,UFG::qMemoryPool,0,0> *mNext; // rcx
  UFG::qList<UFG::qMemoryPool,UFG::qMemoryPool,0,0> *result; // rax

  if ( (_S1_21 & 1) == 0 )
  {
    _S1_21 |= 1u;
    sMemoryPoolList.mNode.mPrev = (UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *)&sMemoryPoolList;
    sMemoryPoolList.mNode.mNext = (UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *)&sMemoryPoolList;
    atexit(UFG::GetMemoryPoolList_::_2_::_dynamic_atexit_destructor_for__sMemoryPoolList__);
  }
  mNext = (UFG::qList<UFG::qMemoryPool,UFG::qMemoryPool,0,0> *)sMemoryPoolList.mNode.mNext;
  if ( prev )
    mNext = (UFG::qList<UFG::qMemoryPool,UFG::qMemoryPool,0,0> *)prev->mNext;
  result = 0i64;
  if ( mNext != &sMemoryPoolList )
    return mNext;
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
  int mMemory_NumTransactions; // ebx
  unsigned __int64 v3; // rdi
  UFG::allocator::free_link *v4; // rax
  UFG::MemoryTransaction *v5; // rdi

  v1 = UFG::gMainMemoryPool;
  if ( !UFG::gMainMemoryPool )
  {
    UFG::InternalSetupMainMemoryPool(this);
    v1 = UFG::gMainMemoryPool;
  }
  mMemory_NumTransactions = UFG::gQuarkInitParams.mMemory_NumTransactions;
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
      UFG::qMemSet(v4, 0, 24 * mMemory_NumTransactions);
      UFG::gNumMemoryTransactions = mMemory_NumTransactions;
      UFG::gMemoryTransactions = v5;
    }
  }
}

