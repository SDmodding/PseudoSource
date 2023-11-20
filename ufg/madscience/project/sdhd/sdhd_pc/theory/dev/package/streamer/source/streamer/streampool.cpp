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
    UFG::StreamPool::smBlocks,
    0x58ui64,
    2304,
    (void (__fastcall *)(void *))UFG::BlockHeader::BlockHeader);
  return atexit(dynamic_atexit_destructor_for__UFG::StreamPool::smBlocks__);
}

// File Line: 457
// RVA: 0x22E900
char __fastcall UFG::StreamPool_InitSystem()
{
  UFG::StreamPool **v0; // rax
  signed __int64 v1; // rcx
  UFG::BlockHeader *v2; // rcx
  signed __int64 v3; // rdx
  UFG::BlockHeader **v4; // rax

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
    v4 = &UFG::StreamPool::smBlocks[0].mNextUnused;
    do
    {
      *v4 = v2;
      v4 += 11;
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
char __fastcall UFG::StreamPool_CreatePool(unsigned int pool_index, unsigned __int64 pool_size, unsigned int alignment, bool allowDefrag, const char *pool_name, UFG::qMemoryPool *memory_pool)
{
  bool v6; // bp
  unsigned __int64 v7; // rdi
  unsigned __int64 v8; // r14
  unsigned int v9; // ebx
  UFG::StreamPool **v10; // rsi
  UFG::allocator::free_link *v11; // rax
  UFG::StreamPool *v12; // rax
  UFG::StreamPool *v13; // rbx

  v6 = allowDefrag;
  v7 = alignment;
  v8 = pool_size;
  v9 = pool_index;
  v10 = &UFG::gStreamPools[pool_index];
  if ( !*v10 )
  {
    v11 = UFG::qMalloc(0x178ui64, "StreamPool_CreatePool", 0x800ui64);
    if ( v11 )
    {
      UFG::StreamPool::StreamPool((UFG::StreamPool *)v11, v9);
      v13 = v12;
    }
    else
    {
      v13 = 0i64;
    }
    UFG::StreamPool::Init(v13, v7, v8 / v7, v7, v6, pool_name, memory_pool);
    *v10 = v13;
  }
  return 1;
}

// File Line: 515
// RVA: 0x22E5D0
char __fastcall UFG::StreamPool_CreatePool(unsigned int pool_index, unsigned __int64 page_size, unsigned int page_count, unsigned int alignment, bool allowDefrag, const char *pool_name, UFG::qMemoryPool *memory_pool)
{
  unsigned int v7; // esi
  unsigned int v8; // ebp
  unsigned int v9; // er14
  unsigned int v10; // ebx
  UFG::StreamPool **v11; // rdi
  UFG::allocator::free_link *v12; // rax
  UFG::StreamPool *v13; // rax
  UFG::StreamPool *v14; // rbx

  v7 = alignment;
  v8 = page_count;
  v9 = page_size;
  v10 = pool_index;
  v11 = &UFG::gStreamPools[pool_index];
  if ( !*v11 )
  {
    v12 = UFG::qMalloc(0x178ui64, "StreamPool_CreatePool", 0x800ui64);
    if ( v12 )
    {
      UFG::StreamPool::StreamPool((UFG::StreamPool *)v12, v10);
      v14 = v13;
    }
    else
    {
      v14 = 0i64;
    }
    UFG::StreamPool::Init(v14, v9, v8, v7, allowDefrag, pool_name, memory_pool);
    *v11 = v14;
  }
  return 1;
}

// File Line: 583
// RVA: 0x22E830
void __fastcall UFG::StreamPool_FreeNoCache(unsigned __int64 handle)
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
    v2 = UFG::qBaseTreeRB::Get(&v1->mBlockLookup.mTree, handle);
    UFG::StreamPool::FreeInternal(v1, (UFG::BlockHeader *)v2);
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
  signed __int64 v2; // rbp
  UFG::StreamPool *v3; // rdi
  UFG::BlockHeader *i; // rbx
  unsigned int v5; // eax

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
          v5 = i->mSize;
          *(_DWORD *)&i->mFlags = 0;
          *(_QWORD *)&i->mSizeOriginal = 0i64;
          i->mLargestChunk = 0;
          v3->mSizeByType[2] -= v5;
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
  LOWORD(v3->mNULL.mChild[1]) &= 0xFF7Fu;
  return 1;
}

// File Line: 717
// RVA: 0x22E8A0
void __fastcall UFG::StreamPool_FullDefragDown(unsigned int pool_index)
{
  UFG::StreamPool *v1; // rdx
  unsigned int v2; // eax
  signed int v3; // ecx
  signed __int64 v4; // rax

  v1 = UFG::gStreamPools[pool_index];
  if ( v1->mbAllowDefrag && v1->mDefragState.meState == INACTIVE )
  {
    v2 = v1->mDefragState.mMaxPendingAlloc;
    v3 = 0x7FFFFFFF;
    v1->mDefragState.mMovingBlock = 0i64;
    v1->mDefragState.meState = 4;
    if ( v2 > 0x7FFFFFFF )
      v3 = v2;
    v4 = (signed __int64)&v1->mDefragState.mpStreamPool->mBlockHead;
    v1->mDefragState.mMaxPendingAlloc = v3;
    v1->mDefragState.mCurrentBlock = (UFG::BlockHeader *)v4;
  }
}

// File Line: 794
// RVA: 0x22E770
void __fastcall UFG::StreamPool_DBGDumpAllPools(UFG *this)
{
  UFG::StreamPool **v1; // rdi
  signed __int64 v2; // rsi
  UFG::StreamPool *v3; // rbx
  UFG::BlockHeader *v4; // r9
  signed __int64 v5; // r10
  unsigned int v6; // er11
  unsigned int v7; // er8
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
      v4 = v3->mBlockHead.mNext;
      v5 = (signed __int64)&v3->mBlockHead;
      v6 = 0;
      v7 = 0;
      for ( i = v4; i != (UFG::BlockHeader *)v5; i = i->mNext )
      {
        switch ( i->mType )
        {
          case 0u:
            goto LABEL_21;
          case 1u:
            if ( v7 > v6 )
              v6 = v7;
            v7 = 0;
            continue;
          case 2u:
LABEL_21:
            v7 += i->mSize;
            break;
        }
      }
      v9 = v3->mBlockHead.mNext;
      if ( v4 != (UFG::BlockHeader *)v5 )
      {
        do
          v9 = v9->mNext;
        while ( v9 != (UFG::BlockHeader *)v5 );
        for ( ; v4 != (UFG::BlockHeader *)v5; v4 = v4->mNext )
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
  unsigned int v2; // ebx
  UFG::StreamPool *v3; // rdi
  UFG::BlockHeader *v4; // rax
  signed __int64 v5; // [rsp+60h] [rbp+18h]
  UFG::qList<UFG::DefragState::PendingFreeOp,UFG::DefragState::PendingFreeOp,1,0> *v6; // [rsp+68h] [rbp+20h]

  v2 = pool_index;
  v3 = this;
  this->mPrev = (UFG::qNode<UFG::StreamPool,UFG::StreamPool> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::StreamPool,UFG::StreamPool> *)&this->mPrev;
  *(_QWORD *)&this->mPoolSize = 0i64;
  *(_QWORD *)&this->mDefragReserve = 0i64;
  *(_WORD *)&this->mbAllowDefrag = 0;
  this->mbGPUBlockOnDefag = 1;
  v4 = &this->mBlockHead;
  v4->mNode.mParent = 0i64;
  v4->mNode.mChild[0] = 0i64;
  v4->mNode.mChild[1] = 0i64;
  *(_QWORD *)&v4->mFlags = 0i64;
  v4->mPrev = v4;
  v4->mNext = v4;
  v4->mData = 0i64;
  *(_QWORD *)&v4->mSizeOriginal = 0i64;
  v4->mNextUnused = 0i64;
  v4->mLargestChunk = 0;
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mBlockLookup.mTree);
  v3->mPoolIndex = v2;
  v3->mOwnedDataBuffer = 0i64;
  v5 = (signed __int64)&v3->mDefragState;
  *(_QWORD *)(v5 + 8) = 0i64;
  *(_QWORD *)(v5 + 16) = 0i64;
  *(_QWORD *)(v5 + 24) = 0i64;
  *(_DWORD *)(v5 + 32) = 0;
  v6 = &v3->mDefragState.mPendingFreeOps;
  v6->mNode.mPrev = &v6->mNode;
  v6->mNode.mNext = &v6->mNode;
  v3->mDefragState.mpStreamPool = v3;
  v3->mPoolName[0] = 0;
  *(_QWORD *)v3->mSizeByType = 0i64;
  *(_QWORD *)&v3->mSizeByType[2] = 0i64;
}

// File Line: 905
// RVA: 0x229CF0
char __fastcall UFG::StreamPool::Init(UFG::StreamPool *this, unsigned int pageSize, unsigned int pageCount, unsigned int alignment, bool allowDefrag, const char *poolName, UFG::qMemoryPool *memory_pool)
{
  unsigned int v7; // er14
  unsigned int v8; // ebp
  UFG::StreamPool *v9; // rbx
  unsigned int v10; // edi
  unsigned int v11; // eax
  UFG::allocator::free_link *v12; // rax

  v7 = pageCount;
  v8 = alignment;
  v9 = this;
  v10 = ~(alignment - 1) & (alignment + pageSize - 1);
  v11 = pageCount * v10;
  if ( memory_pool )
    v12 = UFG::qMemoryPool::Allocate(memory_pool, v11, poolName, (unsigned __int64)(alignment & 0xFFFFFF) << 8, 1u);
  else
    v12 = UFG::qMalloc(v11, poolName, (unsigned __int64)(alignment & 0xFFFFFF) << 8);
  v9->mOwnedDataBuffer = v12;
  return UFG::StreamPool::Init(v9, v9->mOwnedDataBuffer, v10, v7, v8, allowDefrag, poolName);
}

// File Line: 923
// RVA: 0x229DC0
char __fastcall UFG::StreamPool::Init(UFG::StreamPool *this, void *dataPtr, unsigned int pageSize, unsigned int pageCount, unsigned int alignment, bool allowDefrag, const char *poolName)
{
  UFG::StreamPool *v7; // rdi
  unsigned __int64 v8; // rsi
  unsigned int v9; // ebx
  UFG::BlockHeader *v10; // rdx
  UFG::BlockHeader *v11; // rcx

  v7 = this;
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
  v11 = v7->mBlockHead.mNext;
  v7->mBlockHead.mNext = v10;
  v10->mPrev = &v7->mBlockHead;
  v10->mNext = v11;
  v11->mPrev = v10;
  return 1;
}

// File Line: 1093
// RVA: 0x228C00
char __fastcall UFG::StreamPool::EmergencyFreeCachedBlock(UFG::StreamPool *this)
{
  UFG::BlockHeader *v1; // rbx
  UFG::BlockHeader *v2; // rsi
  UFG::StreamPool *v3; // rdi
  unsigned int v4; // eax

  v1 = this->mBlockHead.mNext;
  v2 = &this->mBlockHead;
  v3 = this;
  if ( v1 == &this->mBlockHead )
    return 0;
  while ( 1 )
  {
    if ( v1->mType == 2 )
    {
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v3->mBlockLookup,
        (UFG::qBaseNodeVariableRB<unsigned __int64> *)v1);
      v4 = v1->mSize;
      *(_DWORD *)&v1->mFlags = 0;
      *(_QWORD *)&v1->mSizeOriginal = 0i64;
      v1->mLargestChunk = 0;
      v3->mSizeByType[2] -= v4;
      v3->mSizeByType[0] += v1->mSize;
      v1 = UFG::StreamPool::JoinAdjacentFreeBlocks(v3, v1);
      if ( UFG::StreamPool::smFirstUnused )
        break;
    }
    v1 = v1->mNext;
    if ( v1 == v2 )
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
UFG::BlockHeader *__fastcall UFG::StreamPool::AllocFromBlock(UFG::StreamPool *this, UFG::BlockHeader *block, unsigned int sizeOriginal, unsigned int sizeData, const char *streamname, const char *secondary_tagname, unsigned int streamUID, unsigned int flags)
{
  UFG::BlockHeader *v8; // rbx
  unsigned int v9; // er15
  unsigned int v10; // er14
  unsigned int v11; // er13
  UFG::StreamPool *v12; // rsi
  unsigned int v13; // ebp
  unsigned int *v14; // rcx
  UFG::BlockHeader *v15; // rdi
  char *v16; // r12
  int v17; // er14
  UFG::BlockHeader *result; // rax
  unsigned int v19; // edx
  UFG::BlockHeader *v20; // rax
  UFG::BlockHeader *v21; // rax
  UFG::BlockHeader *v22; // rcx
  unsigned int v23; // ecx

  v8 = block;
  v9 = sizeOriginal;
  v10 = block->mSize;
  v11 = sizeData;
  v12 = this;
  v13 = this->mPageSize * ((this->mPageSize + sizeOriginal - 1) / this->mPageSize);
  if ( v10 == v13 )
  {
    v14 = &block->mNode.mUID;
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
    if ( v10 <= v13 )
      return 0i64;
    v16 = (char *)block->mData;
    v17 = v10 - v13;
    result = UFG::StreamPool::AllocBlockHeader();
    v15 = result;
    if ( !result )
      return result;
    v19 = flags;
    if ( _bittest((const signed int *)&v19, 9u) )
    {
      v20 = v8->mNext;
      v8->mNext = v15;
      v15->mPrev = v8;
      v15->mNext = v20;
      v20->mPrev = v15;
      v8->mData = v16;
      v8->mSize = v17;
      *(_DWORD *)&v8->mFlags = 0;
      *(_QWORD *)&v8->mSizeOriginal = 0i64;
      v8->mLargestChunk = 0;
      v8->mNode.mUID = 0;
      v15->mType = 1;
      v14 = &v15->mNode.mUID;
      v15->mSize = v13;
      v15->mSizeOriginal = v9;
      v15->mSizeData = v11;
      v15->mFlags = flags;
      v15->mLargestChunk = 0;
      v15->mNode.mUID = 0;
      v15->mData = &v16[v17];
    }
    else
    {
      v21 = v8->mPrev;
      v22 = v21->mNext;
      v21->mNext = v15;
      v15->mPrev = v21;
      v15->mNext = v22;
      v22->mPrev = v15;
      v15->mFlags = flags;
      v15->mData = v16;
      v15->mSize = v13;
      v15->mSizeOriginal = v9;
      v15->mSizeData = v11;
      v15->mNode.mUID = 0;
      v15->mLargestChunk = 0;
      v14 = &v15->mNode.mUID;
      v15->mType = 1;
      *(_DWORD *)&v8->mFlags = 0;
      v8->mSize = v17;
      *(_QWORD *)&v8->mSizeOriginal = 0i64;
      v8->mLargestChunk = 0;
      v8->mNode.mUID = 0;
      v8->mData = &v16[v13];
    }
  }
  v12->mSizeByType[1] += v13;
  v12->mSizeByType[0] -= v13;
  *v14 = streamUID;
  UFG::qBaseTreeRB::Add(&v12->mBlockLookup.mTree, &v15->mNode);
  v23 = v12->mSizeByType[1];
  result = v15;
  if ( v12->mHighWatermark > v23 )
    v23 = v12->mHighWatermark;
  v12->mHighWatermark = v23;
  return result;
}

// File Line: 1523
// RVA: 0x2294E0
UFG::BlockHeader *__fastcall UFG::StreamPool::FreeCachedData(UFG::StreamPool *this, UFG::BlockHeader *block)
{
  UFG::StreamPool *v2; // rbx
  UFG::BlockHeader *v3; // rdi

  v2 = this;
  v3 = block;
  UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
    (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mBlockLookup,
    (UFG::qBaseNodeVariableRB<unsigned __int64> *)block);
  *(_QWORD *)&v3->mSizeOriginal = 0i64;
  *(_DWORD *)&v3->mFlags = 0;
  v3->mLargestChunk = 0;
  v2->mSizeByType[2] -= v3->mSize;
  v2->mSizeByType[0] += v3->mSize;
  return v3;
}

// File Line: 1561
// RVA: 0x227740
unsigned __int64 __fastcall UFG::StreamPool::Allocate(UFG::StreamPool *this, unsigned int alloc_size, unsigned int data_size, const char *streamname, const char *tag_name, unsigned int flags, unsigned int *restoredSizeBytes)
{
  unsigned int v7; // er13
  UFG::StreamPool *v8; // rsi
  unsigned __int64 result; // rax
  unsigned int v10; // eax
  unsigned int streamUID; // edi
  UFG::qBaseTreeRB *v12; // rax
  int v13; // ecx
  unsigned int v14; // er14
  float v15; // xmm0_4
  unsigned int v16; // eax
  unsigned int v17; // eax
  UFG::BlockHeader *v18; // r15
  signed __int64 v19; // rbp
  UFG::BlockHeader *i; // rbx
  UFG::BlockHeader *j; // rdi
  UFG::BlockHeader *v22; // rcx
  UFG::BlockHeader *v23; // rbx
  unsigned int v24; // eax
  unsigned int v25; // eax
  UFG::StreamPool *v26; // rax
  unsigned __int64 v27; // rcx
  UFG::BlockHeader *v28; // rbp
  UFG::BlockHeader *v29; // rbx
  unsigned int v30; // eax
  UFG::BlockHeader *v31; // r8
  UFG::BlockHeader *k; // rbx
  UFG::BlockHeader *l; // rdi
  UFG::BlockHeader *v34; // rcx
  UFG::BlockHeader *v35; // rbx
  unsigned int v36; // eax
  UFG::BlockHeader *m; // rbp
  UFG::BlockHeader *v38; // rbx
  unsigned int v39; // eax
  UFG::BlockHeader *v40; // r8
  unsigned int v41; // [rsp+40h] [rbp-48h]
  unsigned int v42; // [rsp+90h] [rbp+8h]
  unsigned int sizeData; // [rsp+A0h] [rbp+18h]
  char *v44; // [rsp+A8h] [rbp+20h]

  v44 = (char *)streamname;
  sizeData = data_size;
  v7 = alloc_size;
  *restoredSizeBytes = 0;
  v8 = this;
  if ( this->mDefragState.meState || !alloc_size )
    return -1i64;
  v10 = UFG::GenerateResourceFileUID(ResourceFileContentType_Texture, streamname);
  streamUID = v10;
  v41 = v10;
  if ( v10 && (v12 = UFG::qBaseTreeRB::Get(&v8->mBlockLookup.mTree, v10)) != 0i64 )
  {
    *restoredSizeBytes = HIDWORD(v12->mNULL.mChild[1]);
    v13 = HIDWORD(v12->mNULL.mChild[1]);
    WORD1(v12->mNULL.mChild[1]) = 1;
    v8->mSizeByType[2] -= v13;
    v8->mSizeByType[1] += v13;
    result = v12->mRoot.mUID | ((unsigned __int64)v8->mPoolIndex << 32);
  }
  else
  {
    if ( !UFG::StreamPool::smFirstUnused )
      UFG::StreamPool::EmergencyFreeCachedBlock(v8);
    v14 = v8->mPageSize * ((v8->mPageSize + v7 - 1) / v8->mPageSize);
    v15 = (float)(v8->mSizeByType[0] + v8->mSizeByType[2] - v8->mDefragReserve);
    if ( v15 <= 0.0 )
      v15 = 0.0;
    if ( v14 <= (signed int)v15 )
    {
      v16 = v8->mTopAllocSizeThreshold;
      if ( v16 && v14 <= v16 )
        v17 = flags | 0x200;
      else
        v17 = flags;
      v18 = 0i64;
      v42 = v17;
      v19 = (signed __int64)&v8->mBlockHead;
      if ( _bittest((const signed int *)&v17, 9u) )
      {
        for ( i = v8->mBlockHead.mPrev; i != (UFG::BlockHeader *)v19; i = i->mPrev )
        {
          if ( !i->mType && i->mSize >= v14 )
          {
            v18 = UFG::StreamPool::AllocFromBlock(v8, i, v7, sizeData, v44, tag_name, streamUID, v17);
            if ( v18 )
              goto LABEL_37;
            v17 = v42;
          }
        }
        for ( j = v8->mBlockHead.mPrev; j != (UFG::BlockHeader *)v19; j = j->mPrev )
        {
          if ( !(j->mType & 0xFFFD) )
          {
            v22 = 0i64;
            v23 = j;
            v24 = 0;
            if ( j != (UFG::BlockHeader *)v19 )
            {
              while ( v23->mType != 1 )
              {
                v24 += v23->mSize;
                v22 = v23;
                if ( v24 >= v14 )
                {
                  if ( j->mType == 2 )
                    UFG::StreamPool::FreeCachedData(v8, j);
                  v28 = v23->mPrev;
                  if ( j->mPrev != v28 )
                  {
                    do
                    {
                      v29 = j->mPrev;
                      if ( v29->mType == 2 )
                      {
                        UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
                          (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v8->mBlockLookup,
                          (UFG::qBaseNodeVariableRB<unsigned __int64> *)j->mPrev);
                        v30 = v29->mSize;
                        *(_DWORD *)&v29->mFlags = 0;
                        *(_QWORD *)&v29->mSizeOriginal = 0i64;
                        v29->mLargestChunk = 0;
                        v8->mSizeByType[2] -= v30;
                        v8->mSizeByType[0] += v29->mSize;
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
                    while ( v31->mPrev != v28 );
                  }
                  v18 = UFG::StreamPool::AllocFromBlock(v8, j, v7, sizeData, v44, tag_name, v41, v42);
                  UFG::StreamPool::JoinAdjacentFreeBlocks(v8, v18->mPrev);
                  goto LABEL_37;
                }
                v23 = v23->mPrev;
                if ( v23 == (UFG::BlockHeader *)v19 )
                  break;
              }
            }
            j = v22;
          }
        }
      }
      else
      {
        for ( k = v8->mBlockHead.mNext; k != (UFG::BlockHeader *)v19; k = k->mNext )
        {
          if ( !k->mType && k->mSize >= v14 )
          {
            v18 = UFG::StreamPool::AllocFromBlock(v8, k, v7, sizeData, v44, tag_name, streamUID, v17);
            if ( v18 )
              goto LABEL_37;
            v17 = v42;
          }
        }
        for ( l = v8->mBlockHead.mNext; l != (UFG::BlockHeader *)v19; l = l->mNext )
        {
          if ( !(l->mType & 0xFFFD) )
          {
            v34 = 0i64;
            v35 = l;
            v36 = 0;
            if ( l != (UFG::BlockHeader *)v19 )
            {
              while ( v35->mType != 1 )
              {
                v36 += v35->mSize;
                v34 = v35;
                if ( v36 >= v14 )
                {
                  if ( l->mType == 2 )
                    UFG::StreamPool::FreeCachedData(v8, l);
                  for ( m = v35->mNext; l->mNext != m; UFG::StreamPool::smFirstUnused = v40 )
                  {
                    v38 = l->mNext;
                    if ( v38->mType == 2 )
                    {
                      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
                        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v8->mBlockLookup,
                        (UFG::qBaseNodeVariableRB<unsigned __int64> *)l->mNext);
                      v39 = v38->mSize;
                      *(_DWORD *)&v38->mFlags = 0;
                      *(_QWORD *)&v38->mSizeOriginal = 0i64;
                      v38->mLargestChunk = 0;
                      v8->mSizeByType[2] -= v39;
                      v8->mSizeByType[0] += v38->mSize;
                    }
                    v40 = l->mNext;
                    l->mSize += v40->mSize;
                    v40->mPrev->mNext = v40->mNext;
                    v40->mNext->mPrev = v40->mPrev;
                    v40->mNext = v40;
                    v40->mPrev = v40;
                    v40->mNextUnused = UFG::StreamPool::smFirstUnused;
                  }
                  v18 = UFG::StreamPool::AllocFromBlock(v8, l, v7, sizeData, v44, tag_name, v41, v42);
                  UFG::StreamPool::JoinAdjacentFreeBlocks(v8, v18->mNext);
                  goto LABEL_37;
                }
                v35 = v35->mNext;
                if ( v35 == (UFG::BlockHeader *)v19 )
                  break;
              }
            }
            l = v34;
          }
        }
      }
      if ( v8->mbPotentiallyDefraggable && v8->mDefragState.meState == INACTIVE )
      {
        v25 = v8->mDefragState.mMaxPendingAlloc;
        v8->mDefragState.mMovingBlock = 0i64;
        v8->mDefragState.meState = 4;
        if ( v25 > v7 )
          v7 = v25;
        v26 = v8->mDefragState.mpStreamPool;
        v8->mDefragState.mMaxPendingAlloc = v7;
        v8->mDefragState.mCurrentBlock = &v26->mBlockHead;
      }
LABEL_37:
      *restoredSizeBytes = 0;
      if ( v18 )
        v27 = v18->mNode.mUID | ((unsigned __int64)v8->mPoolIndex << 32);
      else
        v27 = -1i64;
      result = v27;
    }
    else
    {
      result = -1i64;
    }
  }
  return result;
}

// File Line: 1914
// RVA: 0x22A820
UFG::BlockHeader *__fastcall UFG::StreamPool::JoinAdjacentFreeBlocks(UFG::StreamPool *this, UFG::BlockHeader *block)
{
  UFG::BlockHeader *v2; // r8
  UFG::BlockHeader *v3; // r8

  if ( block->mType )
    return block;
  v2 = block->mNext;
  if ( !v2->mType )
  {
    block->mSize += v2->mSize;
    v2->mPrev->mNext = v2->mNext;
    v2->mNext->mPrev = v2->mPrev;
    v2->mNext = v2;
    v2->mPrev = v2;
    v2->mNextUnused = UFG::StreamPool::smFirstUnused;
    UFG::StreamPool::smFirstUnused = v2;
  }
  v3 = block->mPrev;
  if ( v3->mType )
    return block;
  v3->mSize += block->mSize;
  block->mPrev->mNext = block->mNext;
  block->mNext->mPrev = block->mPrev;
  block->mNext = block;
  block->mPrev = block;
  block->mNextUnused = UFG::StreamPool::smFirstUnused;
  UFG::StreamPool::smFirstUnused = block;
  return v3;
}

// File Line: 1936
// RVA: 0x229460
void __fastcall UFG::StreamPool::Free(UFG::StreamPool *this, unsigned __int64 handle)
{
  UFG::StreamPool *v2; // rbx
  UFG::qBaseTreeRB *v3; // rax
  int v4; // ecx

  v2 = this;
  if ( this->mDefragState.meState )
  {
    UFG::DefragState::AddPendingFree(&this->mDefragState, handle, 1);
  }
  else
  {
    if ( (_DWORD)handle )
      v3 = UFG::qBaseTreeRB::Get(&this->mBlockLookup.mTree, handle);
    else
      v3 = 0i64;
    if ( (_QWORD)v3->mNULL.mChild[1] & 0x20 )
    {
      v4 = HIDWORD(v3->mNULL.mChild[1]);
      WORD1(v3->mNULL.mChild[1]) = 2;
      v2->mSizeByType[1] -= v4;
      v2->mSizeByType[2] += v4;
    }
    else
    {
      UFG::StreamPool::FreeInternal(v2, (UFG::BlockHeader *)v3);
    }
    v2->mbPotentiallyDefraggable = v2->mbAllowDefrag;
  }
}

// File Line: 1979
// RVA: 0x229530
UFG::BlockHeader *__fastcall UFG::StreamPool::FreeInternal(UFG::StreamPool *this, UFG::BlockHeader *block)
{
  unsigned int v2; // esi
  UFG::BlockHeader *v3; // rbx
  UFG::StreamPool *v4; // rdi
  unsigned __int16 v5; // ax
  UFG::BlockHeader *result; // rax

  v2 = block->mSize;
  v3 = block;
  v4 = this;
  if ( UFG::gClearMemoryOnFree )
    UFG::qMemSet(block->mData, 253, block->mSizeData);
  v5 = v3->mType;
  if ( v5 == 1 )
  {
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v4->mBlockLookup,
      (UFG::qBaseNodeVariableRB<unsigned __int64> *)v3);
    *(_QWORD *)&v3->mSizeOriginal = 0i64;
    v3->mType = 0;
    v3->mLargestChunk = 0;
    v4->mSizeByType[1] -= v2;
    v4->mSizeByType[0] += v2;
    result = UFG::StreamPool::JoinAdjacentFreeBlocks(v4, v3);
  }
  else if ( v5 == 2 )
  {
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v4->mBlockLookup,
      (UFG::qBaseNodeVariableRB<unsigned __int64> *)v3);
    *(_QWORD *)&v3->mSizeOriginal = 0i64;
    *(_DWORD *)&v3->mFlags = 0;
    v3->mLargestChunk = 0;
    v4->mSizeByType[2] -= v3->mSize;
    v4->mSizeByType[0] += v3->mSize;
    result = UFG::StreamPool::JoinAdjacentFreeBlocks(v4, v3);
  }
  else
  {
    result = 0i64;
  }
  return result;
}

// File Line: 2216
// RVA: 0x228B70
void __fastcall UFG::StreamPool::DumpList(UFG::StreamPool *this)
{
  UFG::StreamPool *v1; // rdi
  UFG::BlockHeader *v2; // rbx
  signed __int64 i; // rdi
  const char *v4; // [rsp+20h] [rbp-28h]
  const char *v5; // [rsp+28h] [rbp-20h]
  const char *v6; // [rsp+30h] [rbp-18h]

  v1 = this;
  v4 = "FREE";
  v5 = "ALOC";
  v6 = "CACH";
  UFG::qPrintf(" Pool %s\n", this->mPoolName);
  v2 = v1->mBlockHead.mNext;
  for ( i = (signed __int64)&v1->mBlockHead; v2 != (UFG::BlockHeader *)i; v2 = v2->mNext )
  {
    UFG::qStringLength(&customWorldMapCaption);
    UFG::qPrintf("%p: %s %08d ", v2->mData, (&v4)[v2->mType], v2->mSize);
  }
}

// File Line: 2540
// RVA: 0x227490
void __fastcall UFG::DefragState::AddPendingFree(UFG::DefragState *this, unsigned __int64 handle, bool possibleToCache)
{
  bool v3; // di
  unsigned __int64 v4; // rsi
  UFG::DefragState *v5; // rbx
  UFG::allocator::free_link *v6; // rax
  UFG::allocator::free_link *v7; // r9
  UFG::qNode<UFG::DefragState::PendingFreeOp,UFG::DefragState::PendingFreeOp> *v8; // rax

  v3 = possibleToCache;
  v4 = handle;
  v5 = this;
  v6 = UFG::qMalloc(0x20ui64, "PendingFreeOp", 0x800ui64);
  v7 = v6;
  if ( v6 )
  {
    v6->mNext = v6;
    v6[1].mNext = v6;
    v6[2].mNext = (UFG::allocator::free_link *)v4;
    LOBYTE(v6[3].mNext) = v3;
  }
  else
  {
    v7 = 0i64;
  }
  v8 = v5->mPendingFreeOps.mNode.mPrev;
  v8->mNext = (UFG::qNode<UFG::DefragState::PendingFreeOp,UFG::DefragState::PendingFreeOp> *)v7;
  v7->mNext = (UFG::allocator::free_link *)v8;
  v7[1].mNext = (UFG::allocator::free_link *)&v5->mPendingFreeOps;
  v5->mPendingFreeOps.mNode.mPrev = (UFG::qNode<UFG::DefragState::PendingFreeOp,UFG::DefragState::PendingFreeOp> *)v7;
}

// File Line: 2547
// RVA: 0x2292F0
void __fastcall UFG::DefragState::FlushPendingFreeOps(UFG::DefragState *this)
{
  UFG::DefragState *v1; // rbp
  char **v2; // r14
  UFG::qNode<UFG::DefragState::PendingFreeOp,UFG::DefragState::PendingFreeOp> *v3; // rbx
  UFG::allocator::free_link *v4; // rsi
  UFG::StreamPool *v5; // rdi
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

  v1 = this;
  v2 = (char **)&this->mPendingFreeOps;
  if ( (UFG::qList<UFG::DefragState::PendingFreeOp,UFG::DefragState::PendingFreeOp,1,0> *)this->mPendingFreeOps.mNode.mNext != &this->mPendingFreeOps )
  {
    do
    {
      v3 = v1->mPendingFreeOps.mNode.mNext;
      if ( LOBYTE(v3[1].mNext) )
      {
        v4 = (UFG::allocator::free_link *)v3[1].mPrev;
        v5 = v1->mpStreamPool;
        if ( v5->mDefragState.meState )
        {
          v6 = UFG::qMalloc(0x20ui64, "PendingFreeOp", 0x800ui64);
          if ( v6 )
          {
            v6->mNext = v6;
            v6[1].mNext = v6;
            v6[2].mNext = v4;
            LOBYTE(v6[3].mNext) = 1;
          }
          v7 = (UFG::allocator::free_link *)v5->mDefragState.mPendingFreeOps.mNode.mPrev;
          v7[1].mNext = v6;
          v6->mNext = v7;
          v6[1].mNext = (UFG::allocator::free_link *)&v5->mDefragState.mPendingFreeOps;
          v5->mDefragState.mPendingFreeOps.mNode.mPrev = (UFG::qNode<UFG::DefragState::PendingFreeOp,UFG::DefragState::PendingFreeOp> *)v6;
        }
        else
        {
          if ( (_DWORD)v4 )
            v8 = UFG::qBaseTreeRB::Get(&v5->mBlockLookup.mTree, (unsigned int)v4);
          else
            v8 = 0i64;
          if ( (_QWORD)v8->mNULL.mChild[1] & 0x20 )
          {
            v9 = HIDWORD(v8->mNULL.mChild[1]);
            WORD1(v8->mNULL.mChild[1]) = 2;
            v5->mSizeByType[1] -= v9;
            v5->mSizeByType[2] += v9;
          }
          else
          {
            UFG::StreamPool::FreeInternal(v5, (UFG::BlockHeader *)v8);
          }
          v5->mbPotentiallyDefraggable = v5->mbAllowDefrag;
        }
      }
      else
      {
        v10 = v3[1].mPrev;
        if ( (_DWORD)v10 )
        {
          v11 = UFG::qBaseTreeRB::Get(&v1->mpStreamPool->mBlockLookup.mTree, (unsigned int)v10);
          if ( v11 )
            UFG::StreamPool::FreeInternal(v1->mpStreamPool, (UFG::BlockHeader *)v11);
        }
      }
      v12 = v3->mPrev;
      v13 = v3->mNext;
      v12->mNext = v13;
      v13->mPrev = v12;
      v3->mPrev = v3;
      v3->mNext = v3;
      v14 = v3->mPrev;
      v15 = v3->mNext;
      v14->mNext = v15;
      v15->mPrev = v14;
      v3->mPrev = v3;
      v3->mNext = v3;
      operator delete[](v3);
    }
    while ( v2[1] != (char *)v2 );
  }
}

// File Line: 2576
// RVA: 0x22DD60
void __fastcall UFG::DefragState::Service(UFG::DefragState *this)
{
  UFG::DefragState *v1; // rbx
  unsigned __int64 v2; // rax
  int v3; // edx
  unsigned __int64 v4; // rdi
  unsigned __int64 v5; // rax

  v1 = this;
  this->mSafeGPUDataTargetStart = 0i64;
  this->mSafeGPUDataTargetSize = 0;
  v2 = UFG::qGetTicks();
  v3 = v1->mFrameDelay;
  v4 = v2;
  if ( v3 > 0 )
    v1->mFrameDelay = v3 - 1;
  if ( v1->mFrameDelay <= 0 )
  {
    while ( 1 )
    {
      switch ( v1->meState )
      {
        case 0:
          v1->mMaxPendingAlloc = 0;
          return;
        case 1:
          if ( v1->mSafeGPUDataTargetStart )
            goto LABEL_13;
          *(_QWORD *)&v1->meState = 0i64;
          UFG::DefragState::FlushPendingFreeOps(v1);
          return;
        case 2:
          v1->meState = 4;
          goto LABEL_10;
        case 3:
          v1->meState = 6;
          goto LABEL_10;
        case 4:
          v5 = UFG::qGetTicks();
          if ( (float)(UFG::qGetTickTime(v4, v5) * 1000.0) > 4.0 )
          {
            if ( v1->mSafeGPUDataTargetStart )
LABEL_13:
              v1->mFrameDelay = 2;
            return;
          }
          UFG::DefragState::MoveToNextBlock(v1);
LABEL_10:
          if ( v1->mFrameDelay > 0 )
            return;
          break;
        case 5:
        case 6:
          UFG::DefragState::BlockMove(v1);
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
  UFG::DefragState *v1; // rbx
  __int64 v2; // rcx
  char *v3; // r9
  unsigned int v4; // er8
  char *v5; // rsi
  char *v6; // rbp
  unsigned int v7; // edi
  unsigned int v8; // eax
  __int64 v9; // rcx
  unsigned __int64 v10; // r8
  __int64 *v11; // r8
  signed __int64 i; // rdx
  __int64 v13; // rax
  char *v14; // rdi
  UFG::BlockHeader *v15; // rax
  UFG::BlockHeader *v16; // rax
  UFG::BlockHeader *v17; // rdx
  UFG::BlockHeader *v18; // rcx
  unsigned int v19; // er8
  UFG::BlockHeader *v20; // rax
  UFG::BlockHeader *v21; // rdx
  UFG::BlockHeader *v22; // rcx
  UFG::BlockHeader *v23; // rax
  UFG::StreamPool *v24; // rax

  v1 = this;
  v2 = this->mCurrentOffset;
  v3 = v1->mTargetDataStart;
  v4 = v1->mSourceDataSize;
  v5 = &v1->mSourceDataStart[v2];
  v6 = &v3[v2];
  v7 = 0;
  if ( v1->mCurrentOffset < v4 )
  {
    do
    {
      if ( &v6[v7 + (unsigned __int64)(((*(_DWORD *)&v5[v7 + 4] + 3) & 0xFFFFFFFC) + 16)] > v5 )
        break;
      v7 += ((*(_DWORD *)&v5[v7 + 4] + 3) & 0xFFFFFFFC) + 16;
    }
    while ( v7 + v1->mCurrentOffset < v4 );
  }
  if ( !v1->mSafeGPUDataTargetStart && v1->mpStreamPool->mbGPUBlockOnDefag )
  {
    v8 = v1->mTargetSize;
    v1->mSafeGPUDataTargetStart = v3;
    v1->mSafeGPUDataTargetSize = v8;
  }
  if ( 0 != (v1->mMovingBlock->mFlags & 0x100) )
    UFG::StreamResourceLoader::PreMove(v5, v7);
  v9 = v7 >> 3;
  if ( v6 <= v5 || (v10 = (unsigned __int64)&v5[8 * v9], (unsigned __int64)v6 >= v10) )
  {
    UFG::qMemCopy(v6, v5, v7);
  }
  else
  {
    v11 = (__int64 *)(v10 - 8);
    for ( i = (signed __int64)&v6[8 * v9 - 8]; (_DWORD)v9; LODWORD(v9) = v9 - 1 )
    {
      v13 = *v11;
      i -= 8i64;
      --v11;
      *(_QWORD *)(i + 8) = v13;
    }
  }
  if ( 0 != (v1->mMovingBlock->mFlags & 0x100) )
    UFG::StreamResourceLoader::PostMove(v6, v7);
  v1->mCurrentOffset += v7;
  if ( v1->mCurrentOffset < v1->mSourceDataSize )
  {
    v24 = v1->mpStreamPool;
    v1->meState = 3;
    if ( v24->mbGPUBlockOnDefag )
      v1->mFrameDelay = 2;
  }
  else
  {
    v14 = (char *)v1->mCurrentBlock->mData;
    UFG::qChunkFileSystem::ExternalChunkMoved(
      v1->mMovingBlock->mNode.mUID,
      (char *)v1->mMovingBlock->mData,
      (char *)v1->mCurrentBlock->mData);
    v15 = UFG::StreamPool::Extract(v1->mpStreamPool, v1->mMovingBlock);
    v1->mMovingBlock->mData = v14;
    UFG::StreamPool::JoinAdjacentFreeBlocks(v1->mpStreamPool, v15);
    v16 = v1->mCurrentBlock;
    v17 = v1->mMovingBlock;
    v18 = v16->mPrev;
    v19 = v16->mSize;
    v20 = v18->mNext;
    v18->mNext = v1->mMovingBlock;
    v17->mPrev = v18;
    v17->mNext = v20;
    v20->mPrev = v17;
    v1->mCurrentBlock->mData = &v14[v1->mMovingBlock->mSize];
    v1->mCurrentBlock->mSize = v19 - v1->mMovingBlock->mSize;
    v21 = v1->mCurrentBlock;
    if ( !v21->mSize )
    {
      v21->mPrev->mNext = v21->mNext;
      v21->mNext->mPrev = v21->mPrev;
      v21->mNext = v21;
      v21->mPrev = v21;
      v22 = v1->mCurrentBlock;
      v22->mNextUnused = UFG::StreamPool::smFirstUnused;
      UFG::StreamPool::smFirstUnused = v22;
    }
    v23 = v1->mMovingBlock;
    v1->meState = 4;
    v1->mMovingBlock = 0i64;
    v1->mCurrentBlock = v23;
  }
  return 0i64;
}

// File Line: 2814
// RVA: 0x22B490
__int64 __fastcall UFG::DefragState::MoveToNextBlock(UFG::DefragState *this)
{
  UFG::DefragState *v1; // rbx
  UFG::BlockHeader *v2; // rcx
  signed __int64 v3; // rax
  UFG::BlockHeader *v4; // rdx
  unsigned __int16 v5; // ax
  UFG::BlockHeader *v6; // r8
  UFG::BlockHeader *v7; // rdx
  unsigned __int16 i; // ax
  UFG::BlockHeader *v9; // rcx
  UFG::BlockHeader *v10; // rdx
  unsigned __int16 v11; // ax
  unsigned int v12; // er8
  unsigned int v13; // er11
  unsigned __int64 v14; // r9
  unsigned __int64 v15; // r10
  unsigned __int64 v16; // rcx
  unsigned int v17; // eax
  signed __int64 v18; // r8
  unsigned __int16 v19; // ax
  UFG::BlockHeader *v20; // r8
  unsigned __int16 v21; // ax
  unsigned int v22; // edx
  unsigned int v23; // er11
  char *v24; // r9
  unsigned __int64 v25; // r10
  unsigned __int64 v26; // rcx
  unsigned int v27; // eax
  UFG::BlockHeader *v28; // rcx
  __int64 result; // rax
  UFG::StreamPool *v30; // r8
  UFG::BlockHeader *v31; // r9
  unsigned int v32; // ecx
  unsigned int v33; // er10
  UFG::BlockHeader *v34; // rax
  UFG::BlockHeader *v35; // rcx
  UFG::BlockHeader *v36; // rax

  v1 = this;
  v2 = this->mCurrentBlock->mNext;
  v3 = (signed __int64)&v1->mpStreamPool->mBlockHead;
  v1->mCurrentBlock = v2;
  if ( v2 == (UFG::BlockHeader *)v3 )
  {
LABEL_46:
    v1->meState = 1;
    return 0i64;
  }
  while ( 1 )
  {
    v4 = v1->mCurrentBlock;
    v5 = v4->mType;
    if ( v5 != 1 )
      break;
    v1->mCurrentBlock = v4->mNext;
LABEL_45:
    if ( v1->mCurrentBlock == &v1->mpStreamPool->mBlockHead )
      goto LABEL_46;
  }
  if ( v5 == 2 )
    v1->mCurrentBlock = UFG::StreamPool::FreeInternal(v1->mpStreamPool, v4);
  v6 = v1->mCurrentBlock;
  v7 = v6->mNext;
  for ( i = v7->mType; i != 1; i = v7->mType )
  {
    if ( i == 3 )
      break;
    if ( i == 2 )
    {
      v1->mCurrentBlock = UFG::StreamPool::FreeInternal(v1->mpStreamPool, v7);
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
      v1->mCurrentBlock = v6;
    }
    v6 = v1->mCurrentBlock;
    v7 = v6->mNext;
  }
  v9 = v1->mCurrentBlock;
  if ( !v9->mType && v9->mSize >= v1->mMaxPendingAlloc )
    goto LABEL_46;
  v10 = v9->mNext;
  if ( v10->mType == 3 )
    goto LABEL_46;
  v11 = v10->mFlags;
  if ( !(v11 & 0x40) || (v11 & 0x80u) != 0 )
    goto LABEL_57;
  v12 = v10->mLargestChunk;
  v13 = LODWORD(v10->mData) - LODWORD(v9->mData);
  if ( !v12 )
  {
    v14 = (unsigned __int64)v10->mData;
    v12 = 0;
    v15 = v14 + v10->mSizeData;
    if ( v14 < v15 )
    {
      do
      {
        v16 = ((*(_DWORD *)(v14 + 4) + 3) & 0xFFFFFFFC) + v14 + 16;
        v17 = ((*(_DWORD *)(v14 + 4) + 3) & 0xFFFFFFFC) + 16;
        v14 += ((*(_DWORD *)(v14 + 4) + 3) & 0xFFFFFFFC) + 16i64;
        if ( v12 <= v17 )
          v12 = v17;
      }
      while ( v16 < v15 );
    }
    v10->mLargestChunk = v12;
  }
  if ( v13 < v12 )
  {
LABEL_57:
    v10 = v10->mNext;
    if ( !v10 )
      goto LABEL_34;
    v18 = (signed __int64)&v1->mpStreamPool->mBlockHead;
    if ( v10 == (UFG::BlockHeader *)v18 )
      goto LABEL_34;
    while ( 1 )
    {
      if ( v10->mType == 1 )
      {
        v19 = v10->mFlags;
        if ( v19 & 0x40 )
        {
          if ( (v19 & 0x80u) == 0 && v10->mSizeData < v1->mCurrentBlock->mSize )
            break;
        }
      }
      v10 = v10->mNext;
      if ( v10 == (UFG::BlockHeader *)v18 )
        goto LABEL_34;
    }
  }
  v1->mMovingBlock = v10;
LABEL_34:
  v20 = v1->mMovingBlock;
  if ( !v1->mMovingBlock )
    goto LABEL_58;
  v21 = v20->mFlags;
  if ( !(v21 & 0x40) || (v21 & 0x80u) != 0 )
    goto LABEL_58;
  v22 = v20->mLargestChunk;
  v23 = LODWORD(v20->mData) - LODWORD(v1->mCurrentBlock->mData);
  if ( !v22 )
  {
    v24 = (char *)v20->mData;
    v22 = 0;
    v25 = (unsigned __int64)&v24[v20->mSizeData];
    if ( (unsigned __int64)v24 < v25 )
    {
      do
      {
        v26 = (unsigned __int64)&v24[((*((_DWORD *)v24 + 1) + 3) & 0xFFFFFFFC) + 16];
        v27 = ((*((_DWORD *)v24 + 1) + 3) & 0xFFFFFFFC) + 16;
        v24 += ((*((_DWORD *)v24 + 1) + 3) & 0xFFFFFFFC) + 16;
        if ( v22 <= v27 )
          v22 = v27;
      }
      while ( v26 < v25 );
    }
    v20->mLargestChunk = v22;
  }
  if ( v23 < v22 )
  {
LABEL_58:
    v28 = v1->mCurrentBlock->mNext;
    v1->mMovingBlock = 0i64;
    v1->mCurrentBlock = v28;
    goto LABEL_45;
  }
  v30 = v1->mpStreamPool;
  if ( v30->mbGPUBlockOnDefag
    && v1->mSafeGPUDataTargetStart
    && ((v31 = v1->mCurrentBlock,
         v32 = (unsigned int)v1->mSafeGPUDataTargetStart,
         v33 = (unsigned int)v31->mData,
         v33 < v32)
     || v33 + v1->mMovingBlock->mSize >= v32 + v1->mSafeGPUDataTargetSize) )
  {
    v34 = v31->mPrev;
    v1->mMovingBlock = 0i64;
    v1->meState = 2;
    v1->mCurrentBlock = v34;
    result = 0i64;
    if ( v30->mbGPUBlockOnDefag )
      v1->mFrameDelay = 2;
  }
  else
  {
    v35 = v1->mMovingBlock;
    v1->meState = 5;
    v1->mCurrentOffset = 0;
    v1->mSourceDataStart = (char *)v35->mData;
    v1->mSourceDataSize = v35->mSizeData;
    v36 = v1->mCurrentBlock;
    v1->mTargetDataStart = (char *)v36->mData;
    v1->mTargetDataSize = v36->mSizeData;
    LODWORD(v35) = v36->mSize;
    result = 0i64;
    v1->mTargetSize = (unsigned int)v35;
  }
  return result;
}

