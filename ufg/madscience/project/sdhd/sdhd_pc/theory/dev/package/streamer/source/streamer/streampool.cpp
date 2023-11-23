// File Line: 175
// RVA: 0x226DC0
void __fastcall UFG::BlockHeader::BlockHeader(UFG::BlockHeader *this)
{
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  *(_QWORD *)&this->mFlags = 0i64;
  this->mData = 0i64;
  *(_QWORD *)&this->mSizeOriginal = 0i64;
  this->mNextUnused = 0i64;
  this->mLargestChunk = 0;
  this->mPrev = this;
  this->mNext = this;
}

// File Line: 399
// RVA: 0x146F7E0
__int64 dynamic_initializer_for__UFG::StreamPool::smBlocks__()
{
  `eh vector constructor iterator(
    (char *)UFG::StreamPool::smBlocks,
    0x58ui64,
    2304,
    (void (__fastcall *)(void *))UFG::BlockHeader::BlockHeader);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::StreamPool::smBlocks__);
}

// File Line: 457
// RVA: 0x22E900
char __fastcall UFG::StreamPool_InitSystem()
{
  UFG::StreamPool **v0; // rax
  __int64 v1; // rcx
  UFG::BlockHeader *v2; // rcx
  __int64 v3; // rdx
  UFG::BlockHeader **p_mNextUnused; // rax

  if ( !UFG::gStreamPoolSystemInitialized )
  {
    v0 = UFG::gStreamPools;
    v1 = 4i64;
    do
    {
      *v0 = 0i64;
      v0[1] = 0i64;
      v0[2] = 0i64;
      v0 += 8;
      *(v0 - 5) = 0i64;
      *(v0 - 4) = 0i64;
      *(v0 - 3) = 0i64;
      *(v0 - 2) = 0i64;
      *(v0 - 1) = 0i64;
      --v1;
    }
    while ( v1 );
    v2 = &UFG::StreamPool::smBlocks[1];
    v3 = 2304i64;
    UFG::StreamPool::smFirstUnused = UFG::StreamPool::smBlocks;
    p_mNextUnused = &UFG::StreamPool::smBlocks[0].mNextUnused;
    do
    {
      *p_mNextUnused = v2;
      p_mNextUnused += 11;
      ++v2;
      --v3;
    }
    while ( v3 );
    UFG::gStreamPoolSystemInitialized = 1;
  }
  return 1;
}

// File Line: 497
// RVA: 0x22E6A0
char __fastcall UFG::StreamPool_CreatePool(
        unsigned int pool_index,
        unsigned __int64 pool_size,
        unsigned int alignment,
        bool allowDefrag,
        const char *pool_name,
        UFG::qMemoryPool *memory_pool)
{
  unsigned __int64 v7; // rdi
  UFG::StreamPool **v10; // rsi
  UFG::allocator::free_link *v11; // rax
  UFG::StreamPool *v12; // rax
  UFG::StreamPool *v13; // rbx

  v7 = alignment;
  v10 = &UFG::gStreamPools[pool_index];
  if ( !*v10 )
  {
    v11 = UFG::qMalloc(0x178ui64, "StreamPool_CreatePool", 0x800ui64);
    if ( v11 )
    {
      UFG::StreamPool::StreamPool((UFG::StreamPool *)v11, pool_index);
      v13 = v12;
    }
    else
    {
      v13 = 0i64;
    }
    UFG::StreamPool::Init(v13, v7, pool_size / v7, v7, allowDefrag, pool_name, memory_pool);
    *v10 = v13;
  }
  return 1;
}

// File Line: 515
// RVA: 0x22E5D0
char __fastcall UFG::StreamPool_CreatePool(
        unsigned int pool_index,
        unsigned __int64 page_size,
        unsigned int page_count,
        unsigned int alignment,
        bool allowDefrag,
        const char *pool_name,
        UFG::qMemoryPool *memory_pool)
{
  unsigned int v9; // r14d
  UFG::StreamPool **v11; // rdi
  UFG::allocator::free_link *v12; // rax
  UFG::StreamPool *v13; // rax
  UFG::StreamPool *v14; // rbx

  v9 = page_size;
  v11 = &UFG::gStreamPools[pool_index];
  if ( !*v11 )
  {
    v12 = UFG::qMalloc(0x178ui64, "StreamPool_CreatePool", 0x800ui64);
    if ( v12 )
    {
      UFG::StreamPool::StreamPool((UFG::StreamPool *)v12, pool_index);
      v14 = v13;
    }
    else
    {
      v14 = 0i64;
    }
    UFG::StreamPool::Init(v14, v9, page_count, alignment, allowDefrag, pool_name, memory_pool);
    *v11 = v14;
  }
  return 1;
}

// File Line: 583
// RVA: 0x22E830
void __fastcall UFG::StreamPool_FreeNoCache(UFG::allocator::free_link *handle)
{
  UFG::StreamPool *v1; // rbx
  UFG::qBaseTreeRB *v2; // rax

  v1 = UFG::gStreamPools[BYTE4(handle) & 0x1F];
  if ( v1->mDefragState.meState )
  {
    UFG::DefragState::AddPendingFree(&v1->mDefragState, handle, 0);
  }
  else if ( (_DWORD)handle )
  {
    v2 = UFG::qBaseTreeRB::Get(&v1->mBlockLookup.mTree, (unsigned int)handle);
    UFG::StreamPool::FreeInternal(v1, (UFG::qBaseNodeVariableRB<unsigned __int64> *)v2);
  }
  else
  {
    UFG::StreamPool::FreeInternal(v1, 0i64);
  }
}

// File Line: 615
// RVA: 0x22E520
void __fastcall UFG::StreamPool_ClearAllCachedData(UFG *this)
{
  UFG::StreamPool **v1; // r14
  __int64 v2; // rbp
  UFG::StreamPool *v3; // rdi
  UFG::BlockHeader *i; // rbx
  unsigned int mSize; // eax

  v1 = UFG::gStreamPools;
  v2 = 32i64;
  do
  {
    v3 = *v1;
    if ( *v1 )
    {
      for ( i = v3->mBlockHead.mNext; i != &v3->mBlockHead; i = i->mNext )
      {
        if ( i->mType == 2 )
        {
          UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
            (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v3->mBlockLookup,
            (UFG::qBaseNodeVariableRB<unsigned __int64> *)i);
          mSize = i->mSize;
          *(_DWORD *)&i->mFlags = 0;
          *(_QWORD *)&i->mSizeOriginal = 0i64;
          i->mLargestChunk = 0;
          v3->mSizeByType[2] -= mSize;
          v3->mSizeByType[0] += i->mSize;
          i = UFG::StreamPool::JoinAdjacentFreeBlocks(v3, i);
        }
      }
    }
    ++v1;
    --v2;
  }
  while ( v2 );
}

// File Line: 697
// RVA: 0x22E990
char __fastcall UFG::StreamPool_Unlock(unsigned __int64 handle)
{
  unsigned int v1; // edx
  UFG::StreamPool *v2; // rcx
  UFG::qBaseTreeRB *v3; // rax

  v1 = handle;
  v2 = UFG::gStreamPools[BYTE4(handle) & 0x1F];
  if ( !v1 )
    return 0;
  v3 = UFG::qBaseTreeRB::Get(&v2->mBlockLookup.mTree, v1);
  if ( !v3 )
    return 0;
  LOWORD(v3->mNULL.mChild[1]) &= ~0x80u;
  return 1;
}

// File Line: 717
// RVA: 0x22E8A0
void __fastcall UFG::StreamPool_FullDefragDown(unsigned int pool_index)
{
  UFG::StreamPool *v1; // rdx
  unsigned int mMaxPendingAlloc; // eax
  int v3; // ecx
  __int64 p_mBlockHead; // rax

  v1 = UFG::gStreamPools[pool_index];
  if ( v1->mbAllowDefrag && v1->mDefragState.meState == INACTIVE )
  {
    mMaxPendingAlloc = v1->mDefragState.mMaxPendingAlloc;
    v3 = 0x7FFFFFFF;
    v1->mDefragState.mMovingBlock = 0i64;
    v1->mDefragState.meState = MOVE_TO_NEXT_BLOCK;
    if ( mMaxPendingAlloc > 0x7FFFFFFF )
      v3 = mMaxPendingAlloc;
    p_mBlockHead = (__int64)&v1->mDefragState.mpStreamPool->mBlockHead;
    v1->mDefragState.mMaxPendingAlloc = v3;
    v1->mDefragState.mCurrentBlock = (UFG::BlockHeader *)p_mBlockHead;
  }
}

// File Line: 794
// RVA: 0x22E770
void __fastcall UFG::StreamPool_DBGDumpAllPools(UFG *this)
{
  UFG::StreamPool **v1; // rdi
  __int64 v2; // rsi
  UFG::StreamPool *v3; // rbx
  UFG::BlockHeader *mNext; // r9
  UFG::BlockHeader *p_mBlockHead; // r10
  unsigned int v6; // r11d
  unsigned int v7; // r8d
  UFG::BlockHeader *i; // rdx
  UFG::BlockHeader *v9; // rax

  v1 = UFG::gStreamPools;
  v2 = 32i64;
  do
  {
    v3 = *v1;
    if ( *v1 )
    {
      UFG::qPrintf("Memory Report: %s\n", v3->mPoolName);
      mNext = v3->mBlockHead.mNext;
      p_mBlockHead = &v3->mBlockHead;
      v6 = 0;
      v7 = 0;
      for ( i = mNext; i != p_mBlockHead; i = i->mNext )
      {
        switch ( i->mType )
        {
          case 0u:
            goto LABEL_7;
          case 1u:
            if ( v7 > v6 )
              v6 = v7;
            v7 = 0;
            break;
          case 2u:
LABEL_7:
            v7 += i->mSize;
            break;
        }
      }
      v9 = v3->mBlockHead.mNext;
      if ( mNext != p_mBlockHead )
      {
        do
          v9 = v9->mNext;
        while ( v9 != p_mBlockHead );
        for ( ; mNext != p_mBlockHead; mNext = mNext->mNext )
          ;
      }
      UFG::StreamPool::DumpList(v3);
    }
    ++v1;
    --v2;
  }
  while ( v2 );
}

// File Line: 876
// RVA: 0x226F50
void __fastcall UFG::StreamPool::StreamPool(UFG::StreamPool *this, unsigned int pool_index)
{
  this->mPrev = this;
  this->mNext = this;
  *(_QWORD *)&this->mPoolSize = 0i64;
  *(_QWORD *)&this->mDefragReserve = 0i64;
  *(_WORD *)&this->mbAllowDefrag = 0;
  this->mbGPUBlockOnDefag = 1;
  this->mBlockHead.mNode.mParent = 0i64;
  this->mBlockHead.mNode.mChild[0] = 0i64;
  this->mBlockHead.mNode.mChild[1] = 0i64;
  *(_QWORD *)&this->mBlockHead.mFlags = 0i64;
  this->mBlockHead.mPrev = &this->mBlockHead;
  this->mBlockHead.mNext = &this->mBlockHead;
  this->mBlockHead.mData = 0i64;
  *(_QWORD *)&this->mBlockHead.mSizeOriginal = 0i64;
  this->mBlockHead.mNextUnused = 0i64;
  this->mBlockHead.mLargestChunk = 0;
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mBlockLookup.mTree);
  this->mPoolIndex = pool_index;
  this->mOwnedDataBuffer = 0i64;
  this->mDefragState.mCurrentBlock = 0i64;
  this->mDefragState.mpStreamPool = 0i64;
  *(_QWORD *)&this->mDefragState.meState = 0i64;
  this->mDefragState.mFrameDelay = 0;
  this->mDefragState.mPendingFreeOps.mNode.mPrev = &this->mDefragState.mPendingFreeOps.mNode;
  this->mDefragState.mPendingFreeOps.mNode.mNext = &this->mDefragState.mPendingFreeOps.mNode;
  this->mDefragState.mpStreamPool = this;
  this->mPoolName[0] = 0;
  *(_QWORD *)this->mSizeByType = 0i64;
  *(_QWORD *)&this->mSizeByType[2] = 0i64;
}

// File Line: 905
// RVA: 0x229CF0
char __fastcall UFG::StreamPool::Init(
        UFG::StreamPool *this,
        unsigned int pageSize,
        unsigned int pageCount,
        unsigned int alignment,
        bool allowDefrag,
        const char *poolName,
        UFG::qMemoryPool *memory_pool)
{
  unsigned int v10; // edi
  unsigned int v11; // eax
  UFG::allocator::free_link *v12; // rax

  v10 = ~(alignment - 1) & (alignment + pageSize - 1);
  v11 = pageCount * v10;
  if ( memory_pool )
    v12 = UFG::qMemoryPool::Allocate(memory_pool, v11, poolName, (unsigned __int64)(alignment & 0xFFFFFF) << 8, 1u);
  else
    v12 = UFG::qMalloc(v11, poolName, (unsigned __int64)(alignment & 0xFFFFFF) << 8);
  this->mOwnedDataBuffer = v12;
  return UFG::StreamPool::Init(this, this->mOwnedDataBuffer, v10, pageCount, alignment, allowDefrag, poolName);
}

// File Line: 923
// RVA: 0x229DC0
char __fastcall UFG::StreamPool::Init(
        UFG::StreamPool *this,
        void *dataPtr,
        unsigned int pageSize,
        unsigned int pageCount,
        unsigned int alignment,
        bool allowDefrag,
        char *poolName)
{
  unsigned __int64 v8; // rsi
  unsigned int v9; // ebx
  UFG::BlockHeader *v10; // rdx
  UFG::BlockHeader *mNext; // rcx

  v8 = ~(alignment - 1i64) & ((unsigned __int64)dataPtr + alignment - 1);
  v9 = ~(alignment - 1) & (pageCount * pageSize + (_DWORD)dataPtr - v8);
  this->mbAllowDefrag = allowDefrag;
  this->mAlignment = alignment;
  this->mPageSize = pageSize;
  this->mPoolSize = v9;
  *(_QWORD *)&this->mSizeByType[1] = 0i64;
  this->mSizeByType[0] = v9;
  this->mHighWatermark = 0;
  this->mBlockHead.mType = 3;
  UFG::qStringCopy(this->mPoolName, 32, poolName, -1);
  v10 = UFG::StreamPool::smFirstUnused;
  if ( UFG::StreamPool::smFirstUnused )
  {
    UFG::StreamPool::smFirstUnused = UFG::StreamPool::smFirstUnused->mNextUnused;
    v10->mNode.mParent = 0i64;
    v10->mNode.mChild[0] = 0i64;
    v10->mNode.mChild[1] = 0i64;
    *(_QWORD *)&v10->mFlags = 0i64;
    v10->mPrev = v10;
    v10->mNext = v10;
    v10->mData = 0i64;
    *(_QWORD *)&v10->mSizeOriginal = 0i64;
    v10->mNextUnused = 0i64;
    v10->mLargestChunk = 0;
    v10->mNextUnused = 0i64;
  }
  v10->mType = 0;
  v10->mData = (void *)v8;
  v10->mSize = v9;
  mNext = this->mBlockHead.mNext;
  this->mBlockHead.mNext = v10;
  v10->mPrev = &this->mBlockHead;
  v10->mNext = mNext;
  mNext->mPrev = v10;
  return 1;
}

// File Line: 1093
// RVA: 0x228C00
char __fastcall UFG::StreamPool::EmergencyFreeCachedBlock(UFG::StreamPool *this)
{
  UFG::BlockHeader *mNext; // rbx
  UFG::BlockHeader *p_mBlockHead; // rsi
  unsigned int mSize; // eax

  mNext = this->mBlockHead.mNext;
  p_mBlockHead = &this->mBlockHead;
  if ( mNext == &this->mBlockHead )
    return 0;
  while ( 1 )
  {
    if ( mNext->mType == 2 )
    {
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mBlockLookup,
        (UFG::qBaseNodeVariableRB<unsigned __int64> *)mNext);
      mSize = mNext->mSize;
      *(_DWORD *)&mNext->mFlags = 0;
      *(_QWORD *)&mNext->mSizeOriginal = 0i64;
      mNext->mLargestChunk = 0;
      this->mSizeByType[2] -= mSize;
      this->mSizeByType[0] += mNext->mSize;
      mNext = UFG::StreamPool::JoinAdjacentFreeBlocks(this, mNext);
      if ( UFG::StreamPool::smFirstUnused )
        break;
    }
    mNext = mNext->mNext;
    if ( mNext == p_mBlockHead )
      return 0;
  }
  return 1;
}

// File Line: 1125
// RVA: 0x227510
UFG::BlockHeader *__fastcall UFG::StreamPool::AllocBlockHeader()
{
  UFG::BlockHeader *v0; // rcx

  v0 = UFG::StreamPool::smFirstUnused;
  if ( UFG::StreamPool::smFirstUnused )
  {
    UFG::StreamPool::smFirstUnused = UFG::StreamPool::smFirstUnused->mNextUnused;
    v0->mNode.mParent = 0i64;
    v0->mNode.mChild[0] = 0i64;
    v0->mNode.mChild[1] = 0i64;
    *(_QWORD *)&v0->mFlags = 0i64;
    v0->mPrev = v0;
    v0->mNext = v0;
    v0->mData = 0i64;
    *(_QWORD *)&v0->mSizeOriginal = 0i64;
    v0->mNextUnused = 0i64;
    v0->mLargestChunk = 0;
    v0->mNextUnused = 0i64;
  }
  return v0;
}

// File Line: 1318
// RVA: 0x229020
UFG::BlockHeader *__fastcall UFG::StreamPool::Extract(UFG::StreamPool *this, UFG::BlockHeader *header)
{
  UFG::BlockHeader *v2; // r8

  v2 = UFG::StreamPool::smFirstUnused;
  if ( UFG::StreamPool::smFirstUnused )
  {
    UFG::StreamPool::smFirstUnused = UFG::StreamPool::smFirstUnused->mNextUnused;
    v2->mNode.mParent = 0i64;
    v2->mNode.mChild[0] = 0i64;
    v2->mNode.mChild[1] = 0i64;
    *(_QWORD *)&v2->mFlags = 0i64;
    v2->mPrev = v2;
    v2->mNext = v2;
    v2->mData = 0i64;
    *(_QWORD *)&v2->mSizeOriginal = 0i64;
    v2->mNextUnused = 0i64;
    v2->mLargestChunk = 0;
    v2->mNextUnused = 0i64;
  }
  v2->mType = 0;
  v2->mPrev = header->mPrev;
  v2->mNext = header->mNext;
  v2->mSize = header->mSize;
  v2->mData = header->mData;
  *(_QWORD *)&v2->mSizeOriginal = 0i64;
  v2->mFlags = 0;
  v2->mLargestChunk = 0;
  v2->mNode.mUID = 0;
  header->mPrev->mNext = v2;
  header->mNext->mPrev = v2;
  header->mPrev = header;
  header->mNext = header;
  return v2;
}

// File Line: 1417
// RVA: 0x227580
UFG::BlockHeader *__fastcall UFG::StreamPool::AllocFromBlock(
        UFG::StreamPool *this,
        UFG::BlockHeader *block,
        unsigned int sizeOriginal,
        unsigned int sizeData,
        const char *streamname,
        const char *secondary_tagname,
        unsigned int streamUID,
        unsigned __int16 flags)
{
  unsigned int mSize; // r14d
  unsigned int v13; // ebp
  unsigned int *p_mUID; // rcx
  UFG::BlockHeader *v15; // rdi
  char *mData; // r12
  signed int v17; // r14d
  UFG::BlockHeader *result; // rax
  UFG::BlockHeader *mNext; // rax
  UFG::BlockHeader *mPrev; // rax
  UFG::BlockHeader *v21; // rcx
  unsigned int mHighWatermark; // ecx

  mSize = block->mSize;
  v13 = this->mPageSize * ((this->mPageSize + sizeOriginal - 1) / this->mPageSize);
  if ( mSize == v13 )
  {
    p_mUID = &block->mNode.mUID;
    v15 = block;
    block->mType = 1;
    block->mSizeOriginal = sizeOriginal;
    block->mSizeData = sizeData;
    block->mLargestChunk = 0;
    block->mNode.mUID = 0;
    block->mFlags = flags;
  }
  else
  {
    if ( mSize <= v13 )
      return 0i64;
    mData = (char *)block->mData;
    v17 = mSize - v13;
    result = UFG::StreamPool::AllocBlockHeader();
    v15 = result;
    if ( !result )
      return result;
    if ( (flags & 0x200) != 0 )
    {
      mNext = block->mNext;
      block->mNext = v15;
      v15->mPrev = block;
      v15->mNext = mNext;
      mNext->mPrev = v15;
      block->mData = mData;
      block->mSize = v17;
      *(_DWORD *)&block->mFlags = 0;
      *(_QWORD *)&block->mSizeOriginal = 0i64;
      block->mLargestChunk = 0;
      block->mNode.mUID = 0;
      v15->mType = 1;
      p_mUID = &v15->mNode.mUID;
      v15->mSize = v13;
      v15->mSizeOriginal = sizeOriginal;
      v15->mSizeData = sizeData;
      v15->mFlags = flags;
      v15->mLargestChunk = 0;
      v15->mNode.mUID = 0;
      v15->mData = &mData[v17];
    }
    else
    {
      mPrev = block->mPrev;
      v21 = mPrev->mNext;
      mPrev->mNext = v15;
      v15->mPrev = mPrev;
      v15->mNext = v21;
      v21->mPrev = v15;
      v15->mFlags = flags;
      v15->mData = mData;
      v15->mSize = v13;
      v15->mSizeOriginal = sizeOriginal;
      v15->mSizeData = sizeData;
      v15->mNode.mUID = 0;
      v15->mLargestChunk = 0;
      p_mUID = &v15->mNode.mUID;
      v15->mType = 1;
      *(_DWORD *)&block->mFlags = 0;
      block->mSize = v17;
      *(_QWORD *)&block->mSizeOriginal = 0i64;
      block->mLargestChunk = 0;
      block->mNode.mUID = 0;
      block->mData = &mData[v13];
    }
  }
  this->mSizeByType[1] += v13;
  this->mSizeByType[0] -= v13;
  *p_mUID = streamUID;
  UFG::qBaseTreeRB::Add(&this->mBlockLookup.mTree, &v15->mNode);
  mHighWatermark = this->mSizeByType[1];
  result = v15;
  if ( this->mHighWatermark > mHighWatermark )
    mHighWatermark = this->mHighWatermark;
  this->mHighWatermark = mHighWatermark;
  return result;
}

// File Line: 1523
// RVA: 0x2294E0
UFG::qBaseNodeVariableRB<unsigned __int64> *__fastcall UFG::StreamPool::FreeCachedData(
        UFG::StreamPool *this,
        UFG::qBaseNodeVariableRB<unsigned __int64> *block)
{
  UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
    (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mBlockLookup,
    block);
  block[1].mUID = 0i64;
  LODWORD(block[1].mChild1) = 0;
  LODWORD(block[2].mParent) = 0;
  this->mSizeByType[2] -= HIDWORD(block[1].mChild1);
  this->mSizeByType[0] += HIDWORD(block[1].mChild1);
  return block;
}

// File Line: 1561
// RVA: 0x227740
unsigned __int64 __fastcall UFG::StreamPool::Allocate(
        UFG::StreamPool *this,
        unsigned int alloc_size,
        unsigned int data_size,
        const char *streamname,
        const char *tag_name,
        unsigned __int16 flags,
        unsigned int *restoredSizeBytes)
{
  unsigned int v7; // r13d
  unsigned int ResourceFileUID; // eax
  unsigned int streamUID; // edi
  UFG::qBaseTreeRB *v12; // rax
  int v13; // ecx
  unsigned int v14; // r14d
  float v15; // xmm0_4
  unsigned int mTopAllocSizeThreshold; // eax
  unsigned __int16 v17; // ax
  UFG::BlockHeader *v18; // r15
  UFG::BlockHeader *p_mBlockHead; // rbp
  UFG::BlockHeader *i; // rbx
  UFG::BlockHeader *j; // rdi
  UFG::BlockHeader *v22; // rcx
  UFG::BlockHeader *v23; // rbx
  unsigned int v24; // eax
  unsigned int mMaxPendingAlloc; // eax
  UFG::StreamPool *mpStreamPool; // rax
  UFG::BlockHeader *mPrev; // rbp
  UFG::BlockHeader *v29; // rbx
  unsigned int mSize; // eax
  UFG::BlockHeader *v31; // r8
  UFG::BlockHeader *k; // rbx
  UFG::BlockHeader *m; // rdi
  UFG::BlockHeader *v34; // rcx
  UFG::BlockHeader *v35; // rbx
  unsigned int v36; // eax
  UFG::BlockHeader *n; // rbp
  UFG::BlockHeader *mNext; // rbx
  unsigned int v39; // eax
  UFG::BlockHeader *v40; // r8
  unsigned int v41; // [rsp+40h] [rbp-48h]
  unsigned __int16 v42; // [rsp+90h] [rbp+8h]

  v7 = alloc_size;
  *restoredSizeBytes = 0;
  if ( this->mDefragState.meState || !alloc_size )
    return -1i64;
  ResourceFileUID = UFG::GenerateResourceFileUID(ResourceFileContentType_Texture, streamname);
  streamUID = ResourceFileUID;
  v41 = ResourceFileUID;
  if ( ResourceFileUID && (v12 = UFG::qBaseTreeRB::Get(&this->mBlockLookup.mTree, ResourceFileUID)) != 0i64 )
  {
    *restoredSizeBytes = HIDWORD(v12->mNULL.mChild[1]);
    v13 = HIDWORD(v12->mNULL.mChild[1]);
    WORD1(v12->mNULL.mChild[1]) = 1;
    this->mSizeByType[2] -= v13;
    this->mSizeByType[1] += v13;
    return v12->mRoot.mUID | ((unsigned __int64)this->mPoolIndex << 32);
  }
  else
  {
    if ( !UFG::StreamPool::smFirstUnused )
      UFG::StreamPool::EmergencyFreeCachedBlock(this);
    v14 = this->mPageSize * ((this->mPageSize + v7 - 1) / this->mPageSize);
    v15 = (float)(this->mSizeByType[0] + this->mSizeByType[2] - this->mDefragReserve);
    if ( v15 <= 0.0 )
      v15 = 0.0;
    if ( v14 <= (int)v15 )
    {
      mTopAllocSizeThreshold = this->mTopAllocSizeThreshold;
      if ( mTopAllocSizeThreshold && v14 <= mTopAllocSizeThreshold )
        v17 = flags | 0x200;
      else
        v17 = flags;
      v18 = 0i64;
      v42 = v17;
      p_mBlockHead = &this->mBlockHead;
      if ( (v17 & 0x200) != 0 )
      {
        for ( i = this->mBlockHead.mPrev; i != p_mBlockHead; i = i->mPrev )
        {
          if ( !i->mType && i->mSize >= v14 )
          {
            v18 = UFG::StreamPool::AllocFromBlock(this, i, v7, data_size, streamname, tag_name, streamUID, v17);
            if ( v18 )
              goto LABEL_37;
            v17 = v42;
          }
        }
        for ( j = this->mBlockHead.mPrev; j != p_mBlockHead; j = j->mPrev )
        {
          if ( (j->mType & 0xFFFD) == 0 )
          {
            v22 = 0i64;
            v23 = j;
            v24 = 0;
            if ( j != p_mBlockHead )
            {
              while ( v23->mType != 1 )
              {
                v24 += v23->mSize;
                v22 = v23;
                if ( v24 >= v14 )
                {
                  if ( j->mType == 2 )
                    UFG::StreamPool::FreeCachedData(this, j);
                  mPrev = v23->mPrev;
                  if ( j->mPrev != mPrev )
                  {
                    do
                    {
                      v29 = j->mPrev;
                      if ( v29->mType == 2 )
                      {
                        UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
                          (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mBlockLookup,
                          (UFG::qBaseNodeVariableRB<unsigned __int64> *)j->mPrev);
                        mSize = v29->mSize;
                        *(_DWORD *)&v29->mFlags = 0;
                        *(_QWORD *)&v29->mSizeOriginal = 0i64;
                        v29->mLargestChunk = 0;
                        this->mSizeByType[2] -= mSize;
                        this->mSizeByType[0] += v29->mSize;
                      }
                      v31 = j->mPrev;
                      v31->mSize += j->mSize;
                      j->mPrev->mNext = j->mNext;
                      j->mNext->mPrev = j->mPrev;
                      j->mNext = j;
                      j->mPrev = j;
                      j->mNextUnused = UFG::StreamPool::smFirstUnused;
                      UFG::StreamPool::smFirstUnused = j;
                      j = v31;
                    }
                    while ( v31->mPrev != mPrev );
                  }
                  v18 = UFG::StreamPool::AllocFromBlock(this, j, v7, data_size, streamname, tag_name, v41, v42);
                  UFG::StreamPool::JoinAdjacentFreeBlocks(this, v18->mPrev);
                  goto LABEL_37;
                }
                v23 = v23->mPrev;
                if ( v23 == p_mBlockHead )
                  break;
              }
            }
            j = v22;
          }
        }
      }
      else
      {
        for ( k = this->mBlockHead.mNext; k != p_mBlockHead; k = k->mNext )
        {
          if ( !k->mType && k->mSize >= v14 )
          {
            v18 = UFG::StreamPool::AllocFromBlock(this, k, v7, data_size, streamname, tag_name, streamUID, v17);
            if ( v18 )
              goto LABEL_37;
            v17 = v42;
          }
        }
        for ( m = this->mBlockHead.mNext; m != p_mBlockHead; m = m->mNext )
        {
          if ( (m->mType & 0xFFFD) == 0 )
          {
            v34 = 0i64;
            v35 = m;
            v36 = 0;
            if ( m != p_mBlockHead )
            {
              while ( v35->mType != 1 )
              {
                v36 += v35->mSize;
                v34 = v35;
                if ( v36 >= v14 )
                {
                  if ( m->mType == 2 )
                    UFG::StreamPool::FreeCachedData(this, m);
                  for ( n = v35->mNext; m->mNext != n; UFG::StreamPool::smFirstUnused = v40 )
                  {
                    mNext = m->mNext;
                    if ( mNext->mType == 2 )
                    {
                      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
                        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mBlockLookup,
                        (UFG::qBaseNodeVariableRB<unsigned __int64> *)m->mNext);
                      v39 = mNext->mSize;
                      *(_DWORD *)&mNext->mFlags = 0;
                      *(_QWORD *)&mNext->mSizeOriginal = 0i64;
                      mNext->mLargestChunk = 0;
                      this->mSizeByType[2] -= v39;
                      this->mSizeByType[0] += mNext->mSize;
                    }
                    v40 = m->mNext;
                    m->mSize += v40->mSize;
                    v40->mPrev->mNext = v40->mNext;
                    v40->mNext->mPrev = v40->mPrev;
                    v40->mNext = v40;
                    v40->mPrev = v40;
                    v40->mNextUnused = UFG::StreamPool::smFirstUnused;
                  }
                  v18 = UFG::StreamPool::AllocFromBlock(this, m, v7, data_size, streamname, tag_name, v41, v42);
                  UFG::StreamPool::JoinAdjacentFreeBlocks(this, v18->mNext);
                  goto LABEL_37;
                }
                v35 = v35->mNext;
                if ( v35 == p_mBlockHead )
                  break;
              }
            }
            m = v34;
          }
        }
      }
      if ( this->mbPotentiallyDefraggable && this->mDefragState.meState == INACTIVE )
      {
        mMaxPendingAlloc = this->mDefragState.mMaxPendingAlloc;
        this->mDefragState.mMovingBlock = 0i64;
        this->mDefragState.meState = MOVE_TO_NEXT_BLOCK;
        if ( mMaxPendingAlloc > v7 )
          v7 = mMaxPendingAlloc;
        mpStreamPool = this->mDefragState.mpStreamPool;
        this->mDefragState.mMaxPendingAlloc = v7;
        this->mDefragState.mCurrentBlock = &mpStreamPool->mBlockHead;
      }
LABEL_37:
      *restoredSizeBytes = 0;
      if ( v18 )
        return v18->mNode.mUID | ((unsigned __int64)this->mPoolIndex << 32);
      else
        return -1i64;
    }
    else
    {
      return -1i64;
    }
  }
}

// File Line: 1914
// RVA: 0x22A820
UFG::BlockHeader *__fastcall UFG::StreamPool::JoinAdjacentFreeBlocks(UFG::StreamPool *this, UFG::BlockHeader *block)
{
  UFG::BlockHeader *mNext; // r8
  UFG::BlockHeader *mPrev; // r8

  if ( block->mType )
    return block;
  mNext = block->mNext;
  if ( !mNext->mType )
  {
    block->mSize += mNext->mSize;
    mNext->mPrev->mNext = mNext->mNext;
    mNext->mNext->mPrev = mNext->mPrev;
    mNext->mNext = mNext;
    mNext->mPrev = mNext;
    mNext->mNextUnused = UFG::StreamPool::smFirstUnused;
    UFG::StreamPool::smFirstUnused = mNext;
  }
  mPrev = block->mPrev;
  if ( mPrev->mType )
    return block;
  mPrev->mSize += block->mSize;
  block->mPrev->mNext = block->mNext;
  block->mNext->mPrev = block->mPrev;
  block->mNext = block;
  block->mPrev = block;
  block->mNextUnused = UFG::StreamPool::smFirstUnused;
  UFG::StreamPool::smFirstUnused = block;
  return mPrev;
}

// File Line: 1936
// RVA: 0x229460
void __fastcall UFG::StreamPool::Free(UFG::StreamPool *this, UFG::allocator::free_link *handle)
{
  UFG::qBaseTreeRB *v3; // rax
  int v4; // ecx

  if ( this->mDefragState.meState )
  {
    UFG::DefragState::AddPendingFree(&this->mDefragState, handle, 1);
  }
  else
  {
    if ( (_DWORD)handle )
      v3 = UFG::qBaseTreeRB::Get(&this->mBlockLookup.mTree, (unsigned int)handle);
    else
      v3 = 0i64;
    if ( ((__int64)v3->mNULL.mChild[1] & 0x20) != 0 )
    {
      v4 = HIDWORD(v3->mNULL.mChild[1]);
      WORD1(v3->mNULL.mChild[1]) = 2;
      this->mSizeByType[1] -= v4;
      this->mSizeByType[2] += v4;
    }
    else
    {
      UFG::StreamPool::FreeInternal(this, (UFG::BlockHeader *)v3);
    }
    this->mbPotentiallyDefraggable = this->mbAllowDefrag;
  }
}

// File Line: 1979
// RVA: 0x229530
UFG::BlockHeader *__fastcall UFG::StreamPool::FreeInternal(
        UFG::StreamPool *this,
        UFG::qBaseNodeVariableRB<unsigned __int64> *block)
{
  unsigned int mChild1_high; // esi
  unsigned __int16 v5; // ax

  mChild1_high = HIDWORD(block[1].mChild1);
  if ( UFG::gClearMemoryOnFree )
    UFG::qMemSet(block[2].mChild[0], 253, HIDWORD(block[1].mUID));
  v5 = WORD1(block[1].mChild1);
  if ( v5 == 1 )
  {
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mBlockLookup,
      block);
    block[1].mUID = 0i64;
    WORD1(block[1].mChild1) = 0;
    LODWORD(block[2].mParent) = 0;
    this->mSizeByType[1] -= mChild1_high;
    this->mSizeByType[0] += mChild1_high;
    return UFG::StreamPool::JoinAdjacentFreeBlocks(this, (UFG::BlockHeader *)block);
  }
  else if ( v5 == 2 )
  {
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mBlockLookup,
      block);
    block[1].mUID = 0i64;
    LODWORD(block[1].mChild1) = 0;
    LODWORD(block[2].mParent) = 0;
    this->mSizeByType[2] -= HIDWORD(block[1].mChild1);
    this->mSizeByType[0] += HIDWORD(block[1].mChild1);
    return UFG::StreamPool::JoinAdjacentFreeBlocks(this, (UFG::BlockHeader *)block);
  }
  else
  {
    return 0i64;
  }
}

// File Line: 2216
// RVA: 0x228B70
void __fastcall UFG::StreamPool::DumpList(UFG::StreamPool *this)
{
  UFG::BlockHeader *mNext; // rbx
  UFG::BlockHeader *i; // rdi
  __int64 v4[5]; // [rsp+20h] [rbp-28h]

  v4[0] = (__int64)"FREE";
  v4[1] = (__int64)"ALOC";
  v4[2] = (__int64)"CACH";
  UFG::qPrintf(" Pool %s\n", this->mPoolName);
  mNext = this->mBlockHead.mNext;
  for ( i = &this->mBlockHead; mNext != i; mNext = mNext->mNext )
  {
    UFG::qStringLength(&customCaption);
    UFG::qPrintf("%p: %s %08d ", mNext->mData, (const char *)v4[mNext->mType], mNext->mSize);
  }
}

// File Line: 2540
// RVA: 0x227490
void __fastcall UFG::DefragState::AddPendingFree(
        UFG::DefragState *this,
        UFG::allocator::free_link *handle,
        bool possibleToCache)
{
  UFG::allocator::free_link *v6; // rax
  UFG::qNode<UFG::DefragState::PendingFreeOp,UFG::DefragState::PendingFreeOp> *v7; // r9
  UFG::qNode<UFG::DefragState::PendingFreeOp,UFG::DefragState::PendingFreeOp> *mPrev; // rax

  v6 = UFG::qMalloc(0x20ui64, "PendingFreeOp", 0x800ui64);
  v7 = (UFG::qNode<UFG::DefragState::PendingFreeOp,UFG::DefragState::PendingFreeOp> *)v6;
  if ( v6 )
  {
    v6->mNext = v6;
    v6[1].mNext = v6;
    v6[2].mNext = handle;
    LOBYTE(v6[3].mNext) = possibleToCache;
  }
  else
  {
    v7 = 0i64;
  }
  mPrev = this->mPendingFreeOps.mNode.mPrev;
  mPrev->mNext = v7;
  v7->mPrev = mPrev;
  v7->mNext = &this->mPendingFreeOps.mNode;
  this->mPendingFreeOps.mNode.mPrev = v7;
}

// File Line: 2547
// RVA: 0x2292F0
void __fastcall UFG::DefragState::FlushPendingFreeOps(UFG::DefragState *this)
{
  UFG::qList<UFG::DefragState::PendingFreeOp,UFG::DefragState::PendingFreeOp,1,0> *p_mPendingFreeOps; // r14
  UFG::qNode<UFG::DefragState::PendingFreeOp,UFG::DefragState::PendingFreeOp> *mNext; // rbx
  UFG::allocator::free_link *mPrev; // rsi
  UFG::StreamPool *mpStreamPool; // rdi
  UFG::allocator::free_link *v6; // rax
  UFG::allocator::free_link *v7; // rcx
  UFG::qBaseTreeRB *v8; // rax
  int v9; // ecx
  UFG::qNode<UFG::DefragState::PendingFreeOp,UFG::DefragState::PendingFreeOp> *v10; // rax
  UFG::qBaseTreeRB *v11; // rax
  UFG::qNode<UFG::DefragState::PendingFreeOp,UFG::DefragState::PendingFreeOp> *v12; // rdx
  UFG::qNode<UFG::DefragState::PendingFreeOp,UFG::DefragState::PendingFreeOp> *v13; // rax
  UFG::qNode<UFG::DefragState::PendingFreeOp,UFG::DefragState::PendingFreeOp> *v14; // rdx
  UFG::qNode<UFG::DefragState::PendingFreeOp,UFG::DefragState::PendingFreeOp> *v15; // rax

  p_mPendingFreeOps = &this->mPendingFreeOps;
  if ( (UFG::qList<UFG::DefragState::PendingFreeOp,UFG::DefragState::PendingFreeOp,1,0> *)this->mPendingFreeOps.mNode.mNext != &this->mPendingFreeOps )
  {
    do
    {
      mNext = this->mPendingFreeOps.mNode.mNext;
      if ( LOBYTE(mNext[1].mNext) )
      {
        mPrev = (UFG::allocator::free_link *)mNext[1].mPrev;
        mpStreamPool = this->mpStreamPool;
        if ( mpStreamPool->mDefragState.meState )
        {
          v6 = UFG::qMalloc(0x20ui64, "PendingFreeOp", 0x800ui64);
          if ( v6 )
          {
            v6->mNext = v6;
            v6[1].mNext = v6;
            v6[2].mNext = mPrev;
            LOBYTE(v6[3].mNext) = 1;
          }
          v7 = (UFG::allocator::free_link *)mpStreamPool->mDefragState.mPendingFreeOps.mNode.mPrev;
          v7[1].mNext = v6;
          v6->mNext = v7;
          v6[1].mNext = (UFG::allocator::free_link *)&mpStreamPool->mDefragState.mPendingFreeOps;
          mpStreamPool->mDefragState.mPendingFreeOps.mNode.mPrev = (UFG::qNode<UFG::DefragState::PendingFreeOp,UFG::DefragState::PendingFreeOp> *)v6;
        }
        else
        {
          if ( (_DWORD)mPrev )
            v8 = UFG::qBaseTreeRB::Get(&mpStreamPool->mBlockLookup.mTree, (unsigned int)mPrev);
          else
            v8 = 0i64;
          if ( ((__int64)v8->mNULL.mChild[1] & 0x20) != 0 )
          {
            v9 = HIDWORD(v8->mNULL.mChild[1]);
            WORD1(v8->mNULL.mChild[1]) = 2;
            mpStreamPool->mSizeByType[1] -= v9;
            mpStreamPool->mSizeByType[2] += v9;
          }
          else
          {
            UFG::StreamPool::FreeInternal(mpStreamPool, (UFG::BlockHeader *)v8);
          }
          mpStreamPool->mbPotentiallyDefraggable = mpStreamPool->mbAllowDefrag;
        }
      }
      else
      {
        v10 = mNext[1].mPrev;
        if ( (_DWORD)v10 )
        {
          v11 = UFG::qBaseTreeRB::Get(&this->mpStreamPool->mBlockLookup.mTree, (unsigned int)v10);
          if ( v11 )
            UFG::StreamPool::FreeInternal(this->mpStreamPool, (UFG::BlockHeader *)v11);
        }
      }
      v12 = mNext->mPrev;
      v13 = mNext->mNext;
      v12->mNext = v13;
      v13->mPrev = v12;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      v14 = mNext->mPrev;
      v15 = mNext->mNext;
      v14->mNext = v15;
      v15->mPrev = v14;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      operator delete[](mNext);
    }
    while ( (UFG::qList<UFG::DefragState::PendingFreeOp,UFG::DefragState::PendingFreeOp,1,0> *)p_mPendingFreeOps->mNode.mNext != p_mPendingFreeOps );
  }
}

// File Line: 2576
// RVA: 0x22DD60
void __fastcall UFG::DefragState::Service(UFG::DefragState *this)
{
  unsigned __int64 Ticks; // rax
  int mFrameDelay; // edx
  unsigned __int64 v4; // rdi
  unsigned __int64 v5; // rax

  this->mSafeGPUDataTargetStart = 0i64;
  this->mSafeGPUDataTargetSize = 0;
  Ticks = UFG::qGetTicks();
  mFrameDelay = this->mFrameDelay;
  v4 = Ticks;
  if ( mFrameDelay > 0 )
    this->mFrameDelay = mFrameDelay - 1;
  if ( this->mFrameDelay <= 0 )
  {
    while ( 1 )
    {
      switch ( this->meState )
      {
        case INACTIVE:
          this->mMaxPendingAlloc = 0;
          return;
        case POST_DEFRAG:
          if ( this->mSafeGPUDataTargetStart )
            goto LABEL_13;
          *(_QWORD *)&this->meState = 0i64;
          UFG::DefragState::FlushPendingFreeOps(this);
          return;
        case WAIT_FRAME:
          this->meState = MOVE_TO_NEXT_BLOCK;
          goto LABEL_10;
        case WAIT_FRAME_BMOVE:
          this->meState = BLOCK_MOVECONTINUE;
          goto LABEL_10;
        case MOVE_TO_NEXT_BLOCK:
          v5 = UFG::qGetTicks();
          if ( (float)(UFG::qGetTickTime(v4, v5) * 1000.0) > 4.0 )
          {
            if ( this->mSafeGPUDataTargetStart )
LABEL_13:
              this->mFrameDelay = 2;
            return;
          }
          UFG::DefragState::MoveToNextBlock(this);
LABEL_10:
          if ( this->mFrameDelay > 0 )
            return;
          break;
        case BLOCK_MOVESTART:
        case BLOCK_MOVECONTINUE:
          UFG::DefragState::BlockMove(this);
          goto LABEL_10;
        default:
          goto LABEL_10;
      }
    }
  }
}

// File Line: 2709
// RVA: 0x2282A0
__int64 __fastcall UFG::DefragState::BlockMove(UFG::DefragState *this)
{
  __int64 mCurrentOffset; // rcx
  char *mTargetDataStart; // r9
  unsigned int mSourceDataSize; // r8d
  char *v5; // rsi
  char *v6; // rbp
  unsigned int v7; // edi
  unsigned int mTargetSize; // eax
  __int64 v9; // rcx
  char *v10; // r8
  char *v11; // r8
  __int64 i; // rdx
  __int64 v13; // rax
  char *mData; // rdi
  UFG::BlockHeader *v15; // rax
  UFG::BlockHeader *mCurrentBlock; // rax
  UFG::BlockHeader *mMovingBlock; // rdx
  UFG::BlockHeader *mPrev; // rcx
  unsigned int mSize; // r8d
  UFG::BlockHeader *mNext; // rax
  UFG::BlockHeader *v21; // rdx
  UFG::BlockHeader *v22; // rcx
  UFG::BlockHeader *v23; // rax
  UFG::StreamPool *mpStreamPool; // rax

  mCurrentOffset = this->mCurrentOffset;
  mTargetDataStart = this->mTargetDataStart;
  mSourceDataSize = this->mSourceDataSize;
  v5 = &this->mSourceDataStart[mCurrentOffset];
  v6 = &mTargetDataStart[mCurrentOffset];
  v7 = 0;
  if ( this->mCurrentOffset < mSourceDataSize )
  {
    do
    {
      if ( &v6[v7 + (unsigned __int64)(((*(_DWORD *)&v5[v7 + 4] + 3) & 0xFFFFFFFC) + 16)] > v5 )
        break;
      v7 += ((*(_DWORD *)&v5[v7 + 4] + 3) & 0xFFFFFFFC) + 16;
    }
    while ( v7 + this->mCurrentOffset < mSourceDataSize );
  }
  if ( !this->mSafeGPUDataTargetStart && this->mpStreamPool->mbGPUBlockOnDefag )
  {
    mTargetSize = this->mTargetSize;
    this->mSafeGPUDataTargetStart = mTargetDataStart;
    this->mSafeGPUDataTargetSize = mTargetSize;
  }
  if ( (this->mMovingBlock->mFlags & 0x100) != 0 )
    UFG::StreamResourceLoader::PreMove(v5, v7);
  v9 = v7 >> 3;
  if ( v6 <= v5 || (v10 = &v5[8 * v9], v6 >= v10) )
  {
    UFG::qMemCopy(v6, v5, v7);
  }
  else
  {
    v11 = v10 - 8;
    for ( i = (__int64)&v6[8 * v9 - 8]; (_DWORD)v9; LODWORD(v9) = v9 - 1 )
    {
      v13 = *(_QWORD *)v11;
      i -= 8i64;
      v11 -= 8;
      *(_QWORD *)(i + 8) = v13;
    }
  }
  if ( (this->mMovingBlock->mFlags & 0x100) != 0 )
    UFG::StreamResourceLoader::PostMove(v6, v7);
  this->mCurrentOffset += v7;
  if ( this->mCurrentOffset < this->mSourceDataSize )
  {
    mpStreamPool = this->mpStreamPool;
    this->meState = WAIT_FRAME_BMOVE;
    if ( mpStreamPool->mbGPUBlockOnDefag )
      this->mFrameDelay = 2;
  }
  else
  {
    mData = (char *)this->mCurrentBlock->mData;
    UFG::qChunkFileSystem::ExternalChunkMoved(this->mMovingBlock->mNode.mUID, (char *)this->mMovingBlock->mData, mData);
    v15 = UFG::StreamPool::Extract(this->mpStreamPool, this->mMovingBlock);
    this->mMovingBlock->mData = mData;
    UFG::StreamPool::JoinAdjacentFreeBlocks(this->mpStreamPool, v15);
    mCurrentBlock = this->mCurrentBlock;
    mMovingBlock = this->mMovingBlock;
    mPrev = mCurrentBlock->mPrev;
    mSize = mCurrentBlock->mSize;
    mNext = mPrev->mNext;
    mPrev->mNext = this->mMovingBlock;
    mMovingBlock->mPrev = mPrev;
    mMovingBlock->mNext = mNext;
    mNext->mPrev = mMovingBlock;
    this->mCurrentBlock->mData = &mData[this->mMovingBlock->mSize];
    this->mCurrentBlock->mSize = mSize - this->mMovingBlock->mSize;
    v21 = this->mCurrentBlock;
    if ( !v21->mSize )
    {
      v21->mPrev->mNext = v21->mNext;
      v21->mNext->mPrev = v21->mPrev;
      v21->mNext = v21;
      v21->mPrev = v21;
      v22 = this->mCurrentBlock;
      v22->mNextUnused = UFG::StreamPool::smFirstUnused;
      UFG::StreamPool::smFirstUnused = v22;
    }
    v23 = this->mMovingBlock;
    this->meState = MOVE_TO_NEXT_BLOCK;
    this->mMovingBlock = 0i64;
    this->mCurrentBlock = v23;
  }
  return 0i64;
}

// File Line: 2814
// RVA: 0x22B490
__int64 __fastcall UFG::DefragState::MoveToNextBlock(UFG::DefragState *this)
{
  UFG::BlockHeader *mNext; // rcx
  UFG::BlockHeader *p_mBlockHead; // rax
  UFG::BlockHeader *mCurrentBlock; // rdx
  unsigned __int16 mType; // ax
  UFG::BlockHeader *v6; // r8
  UFG::BlockHeader *v7; // rdx
  unsigned __int16 i; // ax
  UFG::BlockHeader *v9; // rcx
  UFG::BlockHeader *v10; // rdx
  unsigned __int16 mFlags; // ax
  unsigned int mLargestChunk; // r8d
  unsigned int v13; // r11d
  unsigned __int64 mData; // r9
  unsigned __int64 v15; // r10
  unsigned __int64 v16; // rcx
  unsigned int v17; // eax
  UFG::BlockHeader *v18; // r8
  unsigned __int16 v19; // ax
  UFG::BlockHeader *mMovingBlock; // r8
  unsigned __int16 v21; // ax
  unsigned int v22; // edx
  unsigned int v23; // r11d
  unsigned __int64 v24; // r9
  unsigned __int64 v25; // r10
  unsigned __int64 v26; // rcx
  unsigned int v27; // eax
  UFG::BlockHeader *v28; // rcx
  __int64 result; // rax
  UFG::StreamPool *mpStreamPool; // r8
  UFG::BlockHeader *v31; // r9
  unsigned int mSafeGPUDataTargetStart; // ecx
  unsigned int v33; // r10d
  UFG::BlockHeader *mPrev; // rax
  UFG::BlockHeader *v35; // rcx
  UFG::BlockHeader *v36; // rax

  mNext = this->mCurrentBlock->mNext;
  p_mBlockHead = &this->mpStreamPool->mBlockHead;
  this->mCurrentBlock = mNext;
  if ( mNext == p_mBlockHead )
  {
LABEL_46:
    this->meState = POST_DEFRAG;
    return 0i64;
  }
  while ( 1 )
  {
    mCurrentBlock = this->mCurrentBlock;
    mType = mCurrentBlock->mType;
    if ( mType != 1 )
      break;
    this->mCurrentBlock = mCurrentBlock->mNext;
LABEL_45:
    if ( this->mCurrentBlock == &this->mpStreamPool->mBlockHead )
      goto LABEL_46;
  }
  if ( mType == 2 )
    this->mCurrentBlock = UFG::StreamPool::FreeInternal(
                            this->mpStreamPool,
                            (UFG::qBaseNodeVariableRB<unsigned __int64> *)mCurrentBlock);
  v6 = this->mCurrentBlock;
  v7 = v6->mNext;
  for ( i = v7->mType; i != 1; i = v7->mType )
  {
    if ( i == 3 )
      break;
    if ( i == 2 )
    {
      this->mCurrentBlock = UFG::StreamPool::FreeInternal(
                              this->mpStreamPool,
                              (UFG::qBaseNodeVariableRB<unsigned __int64> *)v7);
    }
    else if ( !i )
    {
      v6->mSize += v7->mSize;
      v7->mPrev->mNext = v7->mNext;
      v7->mNext->mPrev = v7->mPrev;
      v7->mNext = v7;
      v7->mPrev = v7;
      v7->mNextUnused = UFG::StreamPool::smFirstUnused;
      UFG::StreamPool::smFirstUnused = v7;
      this->mCurrentBlock = v6;
    }
    v6 = this->mCurrentBlock;
    v7 = v6->mNext;
  }
  v9 = this->mCurrentBlock;
  if ( !v9->mType && v9->mSize >= this->mMaxPendingAlloc )
    goto LABEL_46;
  v10 = v9->mNext;
  if ( v10->mType == 3 )
    goto LABEL_46;
  mFlags = v10->mFlags;
  if ( (mFlags & 0x40) == 0 || (mFlags & 0x80u) != 0 )
    goto LABEL_25;
  mLargestChunk = v10->mLargestChunk;
  v13 = LODWORD(v10->mData) - LODWORD(v9->mData);
  if ( !mLargestChunk )
  {
    mData = (unsigned __int64)v10->mData;
    mLargestChunk = 0;
    v15 = mData + v10->mSizeData;
    if ( mData < v15 )
    {
      do
      {
        v16 = ((*(_DWORD *)(mData + 4) + 3) & 0xFFFFFFFC) + mData + 16;
        v17 = ((*(_DWORD *)(mData + 4) + 3) & 0xFFFFFFFC) + 16;
        mData = v16;
        if ( mLargestChunk <= v17 )
          mLargestChunk = v17;
      }
      while ( v16 < v15 );
    }
    v10->mLargestChunk = mLargestChunk;
  }
  if ( v13 < mLargestChunk )
  {
LABEL_25:
    v10 = v10->mNext;
    if ( !v10 )
      goto LABEL_34;
    v18 = &this->mpStreamPool->mBlockHead;
    if ( v10 == v18 )
      goto LABEL_34;
    while ( 1 )
    {
      if ( v10->mType == 1 )
      {
        v19 = v10->mFlags;
        if ( (v19 & 0x40) != 0 && (v19 & 0x80u) == 0 && v10->mSizeData < this->mCurrentBlock->mSize )
          break;
      }
      v10 = v10->mNext;
      if ( v10 == v18 )
        goto LABEL_34;
    }
  }
  this->mMovingBlock = v10;
LABEL_34:
  mMovingBlock = this->mMovingBlock;
  if ( !this->mMovingBlock )
    goto LABEL_44;
  v21 = mMovingBlock->mFlags;
  if ( (v21 & 0x40) == 0 || (v21 & 0x80u) != 0 )
    goto LABEL_44;
  v22 = mMovingBlock->mLargestChunk;
  v23 = LODWORD(mMovingBlock->mData) - LODWORD(this->mCurrentBlock->mData);
  if ( !v22 )
  {
    v24 = (unsigned __int64)mMovingBlock->mData;
    v22 = 0;
    v25 = v24 + mMovingBlock->mSizeData;
    if ( v24 < v25 )
    {
      do
      {
        v26 = ((*(_DWORD *)(v24 + 4) + 3) & 0xFFFFFFFC) + v24 + 16;
        v27 = ((*(_DWORD *)(v24 + 4) + 3) & 0xFFFFFFFC) + 16;
        v24 = v26;
        if ( v22 <= v27 )
          v22 = v27;
      }
      while ( v26 < v25 );
    }
    mMovingBlock->mLargestChunk = v22;
  }
  if ( v23 < v22 )
  {
LABEL_44:
    v28 = this->mCurrentBlock->mNext;
    this->mMovingBlock = 0i64;
    this->mCurrentBlock = v28;
    goto LABEL_45;
  }
  mpStreamPool = this->mpStreamPool;
  if ( mpStreamPool->mbGPUBlockOnDefag
    && this->mSafeGPUDataTargetStart
    && ((v31 = this->mCurrentBlock,
         mSafeGPUDataTargetStart = (unsigned int)this->mSafeGPUDataTargetStart,
         v33 = (unsigned int)v31->mData,
         v33 < mSafeGPUDataTargetStart)
     || v33 + this->mMovingBlock->mSize >= mSafeGPUDataTargetStart + this->mSafeGPUDataTargetSize) )
  {
    mPrev = v31->mPrev;
    this->mMovingBlock = 0i64;
    this->meState = WAIT_FRAME;
    this->mCurrentBlock = mPrev;
    result = 0i64;
    if ( mpStreamPool->mbGPUBlockOnDefag )
      this->mFrameDelay = 2;
  }
  else
  {
    v35 = this->mMovingBlock;
    this->meState = BLOCK_MOVESTART;
    this->mCurrentOffset = 0;
    this->mSourceDataStart = (char *)v35->mData;
    this->mSourceDataSize = v35->mSizeData;
    v36 = this->mCurrentBlock;
    this->mTargetDataStart = (char *)v36->mData;
    this->mTargetDataSize = v36->mSizeData;
    LODWORD(v35) = v36->mSize;
    result = 0i64;
    this->mTargetSize = (unsigned int)v35;
  }
  return result;
}

