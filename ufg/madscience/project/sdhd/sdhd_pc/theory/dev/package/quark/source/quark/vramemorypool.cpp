// File Line: 106
// RVA: 0x1467BB0
__int64 UFG::_dynamic_initializer_for__VRAMChannel__()
{
  UFG::VRAMChannel.mLogFilename.mPrev = &UFG::VRAMChannel.mLogFilename;
  UFG::VRAMChannel.mLogFilename.mNext = &UFG::VRAMChannel.mLogFilename;
  *(_QWORD *)&UFG::VRAMChannel.mLogFilename.mMagic = 16909060i64;
  UFG::VRAMChannel.mLogFilename.mData = (char *)UFG::qString::sEmptyString;
  *(_QWORD *)&UFG::VRAMChannel.mLogFilename.mStringHash32 = -1i64;
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__VRAMChannel__);
}

// File Line: 116
// RVA: 0x1623A0
void __fastcall UFG::qVRAMemoryHandle::qVRAMemoryHandle(UFG::qVRAMemoryHandle *this)
{
  this->mPrev = this;
  this->mNext = this;
  this->mData = 0i64;
  *(_DWORD *)&this->mReadOnlyAndPoolID = 0;
  UFG::qPrintChannel::Print(
    &UFG::VRAMChannel,
    OUTPUT_LEVEL_DEBUG,
    "[VRAM Channel] - Creating new empty qVRAMemoryHandle(%p)\n");
}

// File Line: 122
// RVA: 0x1622A0
void __fastcall UFG::qVRAMemoryHandle::qVRAMemoryHandle(UFG::qVRAMemoryHandle *this, UFG::qVRAMemoryHandle *handle)
{
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *mNext; // rax

  this->mPrev = this;
  this->mNext = this;
  this->mData = 0i64;
  *(_DWORD *)&this->mReadOnlyAndPoolID = 0;
  UFG::qVRAMemoryPools::GetAllocatedSize(handle);
  UFG::qVRAMemoryPools::GetAllocatedSize(handle);
  UFG::qPrintChannel::Print(
    &UFG::VRAMChannel,
    OUTPUT_LEVEL_DEBUG,
    "[VRAM Channel] - Creating new qVRAMemoryHandle(%p) from existing handle(%p) - PoolID:0x%02x BlockID:0x%04x Data:%p-%"
    "p AllocatedSize:%u\n");
  if ( handle->mPrev != handle || handle->mNext != handle )
  {
    if ( handle->mData )
    {
      mNext = handle->mNext;
      handle->mNext = this;
      this->mPrev = handle;
      this->mNext = mNext;
      mNext->mPrev = this;
      this->mData = handle->mData;
      this->mReadOnlyAndPoolID = handle->mReadOnlyAndPoolID;
      this->mBlockID = handle->mBlockID;
    }
  }
}

// File Line: 137
// RVA: 0x164800
UFG::qVRAMemoryHandle *__fastcall UFG::qVRAMemoryHandle::operator=(
        UFG::qVRAMemoryHandle *this,
        UFG::qVRAMemoryHandle *handle)
{
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *mNext; // rax

  UFG::qVRAMemoryPools::GetAllocatedSize(handle);
  UFG::qVRAMemoryPools::GetAllocatedSize(handle);
  UFG::qPrintChannel::Print(
    &UFG::VRAMChannel,
    OUTPUT_LEVEL_DEBUG,
    "[VRAM Channel] - Assigning qVRAMemoryHandle(%p) from existing handle(%p) - PoolID:0x%02x BlockID:0x%04x Data:%p-%p A"
    "llocatedSize:%u\n");
  UFG::qVRAMemoryHandle::Close(this);
  if ( handle->mPrev != handle || handle->mNext != handle )
  {
    if ( handle->mData )
    {
      mNext = handle->mNext;
      handle->mNext = this;
      this->mPrev = handle;
      this->mNext = mNext;
      mNext->mPrev = this;
      this->mData = handle->mData;
      this->mReadOnlyAndPoolID = handle->mReadOnlyAndPoolID;
      this->mBlockID = handle->mBlockID;
    }
  }
  return this;
}

// File Line: 157
// RVA: 0x164550
void __fastcall UFG::qVRAMemoryHandle::~qVRAMemoryHandle(UFG::qVRAMemoryHandle *this)
{
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *mPrev; // rcx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *mNext; // rax

  UFG::qVRAMemoryPools::GetAllocatedSize(this);
  UFG::qVRAMemoryPools::GetAllocatedSize(this);
  UFG::qPrintChannel::Print(
    &UFG::VRAMChannel,
    OUTPUT_LEVEL_DEBUG,
    "[VRAM Channel] - Deleting qVRAMemoryHandle(%p) was pointing at - PoolID:0x%02x BlockID:0x%04x Data:%p-%p AllocatedSize:%u\n");
  UFG::qVRAMemoryHandle::Close(this);
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = this;
  this->mNext = this;
}

// File Line: 170
// RVA: 0x16F2E0
// attributes: thunk
unsigned int __fastcall UFG::qVRAMemoryHandle::GetAllocatedSize(UFG::qVRAMemoryHandle *this)
{
  return UFG::qVRAMemoryPools::GetAllocatedSize(this);
}

// File Line: 180
// RVA: 0x1772B0
// attributes: thunk
bool __fastcall UFG::qVRAMemoryHandle::Lock(UFG::qVRAMemoryHandle *this)
{
  return UFG::qVRAMemoryPools::Lock(this);
}

// File Line: 185
// RVA: 0x17F370
// attributes: thunk
bool __fastcall UFG::qVRAMemoryHandle::Unlock(UFG::qVRAMemoryHandle *this)
{
  return UFG::qVRAMemoryPools::Unlock(this);
}

// File Line: 190
// RVA: 0x168110
void __fastcall UFG::qVRAMemoryHandle::Close(UFG::qVRAMemoryHandle *this)
{
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *mNext; // rax
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *mPrev; // rcx

  UFG::qVRAMemoryPools::GetAllocatedSize(this);
  UFG::qVRAMemoryPools::GetAllocatedSize(this);
  UFG::qPrintChannel::Print(
    &UFG::VRAMChannel,
    OUTPUT_LEVEL_DEBUG,
    "[VRAM Channel] - Closing qVRAMemoryHandle(%p) was pointing at - PoolID:0x%02x BlockID:0x%04x Data:%p-%p AllocatedSize:%u\n");
  if ( this->mData )
  {
    mNext = this->mNext;
    mPrev = this->mPrev;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mPrev = this;
    this->mNext = this;
    this->mData = 0i64;
    *(_DWORD *)&this->mReadOnlyAndPoolID = 0;
  }
}

// File Line: 210
// RVA: 0x17CB70
void __fastcall UFG::qVRAMemoryHandle::Set(
        UFG::qVRAMemoryHandle *this,
        char *data,
        unsigned int size,
        unsigned __int16 pool_id,
        unsigned __int16 block_id)
{
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *mPrev; // rcx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *mNext; // rax

  UFG::qPrintChannel::Print(
    &UFG::VRAMChannel,
    OUTPUT_LEVEL_DEBUG,
    "[VRAM Channel] - Setting qVRAMemoryHandle(%p) to point at - PoolID:0x%02x BlockID:0x%04x Data:%p-%p AllocatedSize:%u\n");
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mReadOnlyAndPoolID = pool_id;
  this->mBlockID = block_id;
  this->mPrev = this;
  this->mNext = this;
  this->mData = data;
}

// File Line: 260
// RVA: 0x15FED0
void __fastcall UFG::BlockInfo::BlockInfo(UFG::BlockInfo *this)
{
  this->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mPrev = this;
  this->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mNext = this;
  this->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mPrev = &this->UFG::qNode<UFG::BlockInfo,UFG::Secondary>;
  this->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mNext = &this->UFG::qNode<UFG::BlockInfo,UFG::Secondary>;
  this->mAllocationHandles.mNode.mPrev = &this->mAllocationHandles.mNode;
  this->mAllocationHandles.mNode.mNext = &this->mAllocationHandles.mNode;
  this->mData = 0i64;
  this->mName = 0i64;
  *(_QWORD *)&this->mRequestedSize = 0i64;
  *(_DWORD *)&this->mBlockID = 0xFFFF;
  *(_WORD *)&this->mKeepAliveFrames = 0;
  this->mMemoryPool = 0i64;
  this->mContainedBlocks.mNode.mPrev = &this->mContainedBlocks.mNode;
  this->mContainedBlocks.mNode.mNext = &this->mContainedBlocks.mNode;
  *(_DWORD *)&this->mContainerID = -1;
  this->mCallbackData64 = 0i64;
  this->mCallbackData32 = 0;
}

// File Line: 265
// RVA: 0x162D00
void __fastcall UFG::BlockInfo::~BlockInfo(UFG::BlockInfo *this)
{
  UFG::qList<UFG::BlockInfo,UFG::Primary,1,0> *p_mContainedBlocks; // rbx
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *mPrev; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *mNext; // rax
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v5; // rcx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v6; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v7; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v8; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v9; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v10; // rax

  p_mContainedBlocks = &this->mContainedBlocks;
  UFG::qList<UFG::BlockInfo,UFG::Primary,1,0>::DeleteNodes(&this->mContainedBlocks);
  mPrev = p_mContainedBlocks->mNode.mPrev;
  mNext = p_mContainedBlocks->mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  p_mContainedBlocks->mNode.mPrev = &p_mContainedBlocks->mNode;
  p_mContainedBlocks->mNode.mNext = &p_mContainedBlocks->mNode;
  UFG::qList<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly,1,0>::DeleteNodes(&this->mAllocationHandles);
  v5 = this->mAllocationHandles.mNode.mPrev;
  v6 = this->mAllocationHandles.mNode.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  this->mAllocationHandles.mNode.mPrev = &this->mAllocationHandles.mNode;
  this->mAllocationHandles.mNode.mNext = &this->mAllocationHandles.mNode;
  v7 = this->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mPrev;
  v8 = this->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mPrev = &this->UFG::qNode<UFG::BlockInfo,UFG::Secondary>;
  this->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mNext = &this->UFG::qNode<UFG::BlockInfo,UFG::Secondary>;
  v9 = this->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mPrev;
  v10 = this->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  this->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mPrev = this;
  this->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mNext = this;
}

// File Line: 270
// RVA: 0x17CF20
void __fastcall UFG::BlockInfo::SetFree(UFG::BlockInfo *this)
{
  unsigned int mActualSize; // edi
  char *mData; // rbx

  mActualSize = this->mActualSize;
  mData = this->mData;
  UFG::qPrintChannel::Print(
    &UFG::VRAMChannel,
    OUTPUT_LEVEL_DEBUG,
    "[VRAM Channel] - Setting Block ID:0x%04x to free data:%p size:0x%08x (%9u)\n");
  this->mName = "Free VRAM";
  this->mData = mData;
  this->mRequestedSize = mActualSize;
  this->mActualSize = mActualSize;
  this->mMemoryPool = 0i64;
  this->mContainerID = 0;
  this->mCallbackData64 = 0i64;
  this->mCallbackData32 = 0;
  *(_DWORD *)&this->mUsage = 1;
}

// File Line: 447
// RVA: 0x16B9B0
void __fastcall UFG::BlockInfo::DefragmentMovedTo(UFG::BlockInfo *this, char *new_location)
{
  UFG::BlockInfo *mNext; // rcx
  int v5; // r8d
  UFG::BlockInfo *v6; // rbx
  UFG::qList<UFG::BlockInfo,UFG::Primary,1,0> *p_mContainedBlocks; // rdi
  __int64 v8; // rsi

  UFG::qPrintChannel::Print(
    &UFG::VRAMChannel,
    OUTPUT_LEVEL_NORMAL,
    "[VRAM Channel] - Moving Block ID:0x%04x from %p to %p\n");
  mNext = (UFG::BlockInfo *)this->mAllocationHandles.mNode.mNext;
  v5 = (_DWORD)new_location - LODWORD(this->mData);
  for ( this->mData = new_location;
        mNext != (UFG::BlockInfo *)&this->mAllocationHandles;
        mNext = (UFG::BlockInfo *)mNext->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mNext )
  {
    mNext->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mPrev = (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)this->mData;
  }
  if ( (unsigned __int8)(this->mUsage - 9) <= 1u )
  {
    v6 = (UFG::BlockInfo *)this->mContainedBlocks.mNode.mNext;
    p_mContainedBlocks = &this->mContainedBlocks;
    if ( v6 != (UFG::BlockInfo *)p_mContainedBlocks )
    {
      v8 = v5;
      do
      {
        UFG::BlockInfo::DefragmentMovedTo(v6, &v6->mData[v8]);
        v6 = (UFG::BlockInfo *)v6->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mNext;
      }
      while ( v6 != (UFG::BlockInfo *)p_mContainedBlocks );
    }
  }
}

// File Line: 501
// RVA: 0x178CD0
void __fastcall UFG::BlockInfo::Print(UFG::BlockInfo *this, bool print_container_contents)
{
  unsigned __int8 mUsage; // al
  const char *v5; // r10
  UFG::BlockInfo *mNext; // rbx
  UFG::qList<UFG::BlockInfo,UFG::Primary,1,0> *i; // rdi
  unsigned int mRequestedSize; // [rsp+20h] [rbp-38h]
  unsigned int mActualSize; // [rsp+28h] [rbp-30h]

  mUsage = this->mUsage;
  if ( mUsage == 11 )
  {
    mRequestedSize = this->mRequestedSize;
    UFG::qPrintf(
      "      BlockID:%05u [%p - %p] %9u bytes requested %9u bytes allocated type(%*s) name:(%.64s)\n",
      this->mBlockID,
      this->mData,
      &this->mData[mRequestedSize - 1],
      mRequestedSize,
      this->mActualSize,
      21,
      off_14203C4E8[0],
      this->mName);
  }
  else
  {
    if ( mUsage > 0x12u )
      v5 = "Unknown VRAMType";
    else
      v5 = off_14203C490[mUsage];
    mActualSize = this->mActualSize;
    UFG::qPrintf(
      "    BlockID  :%05u [%p - %p] %9u bytes requested %9u bytes allocated type(%*s) name:(%.64s)\n",
      this->mBlockID,
      this->mData,
      &this->mData[mActualSize - 1],
      this->mRequestedSize,
      mActualSize,
      21,
      v5,
      this->mName);
  }
  if ( print_container_contents )
  {
    mNext = (UFG::BlockInfo *)this->mContainedBlocks.mNode.mNext;
    for ( i = &this->mContainedBlocks;
          mNext != (UFG::BlockInfo *)i;
          mNext = (UFG::BlockInfo *)mNext->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mNext )
    {
      UFG::BlockInfo::Print(mNext, 1);
    }
  }
}

// File Line: 579
// RVA: 0x1623F0
void __fastcall UFG::qVRAMemoryPool::qVRAMemoryPool(UFG::qVRAMemoryPool *this)
{
  const char *v2; // rdx
  int v3; // r8d
  char *mName; // rax
  char v5; // cl

  this->mPrev = this;
  this->mNext = this;
  UFG::qMutex::qMutex(&this->mPoolLock, &customCaption);
  this->mPoolMemory.mPrev = &this->mPoolMemory;
  this->mPoolMemory.mNext = &this->mPoolMemory;
  this->mPoolMemory.mData = 0i64;
  *(_DWORD *)&this->mPoolMemory.mReadOnlyAndPoolID = 0;
  UFG::qPrintChannel::Print(
    &UFG::VRAMChannel,
    OUTPUT_LEVEL_DEBUG,
    "[VRAM Channel] - Creating new empty qVRAMemoryHandle(%p)\n");
  this->mVRAMemoryStart = 0i64;
  this->mVRAMemorySize = 0;
  this->mMainMemoryPool = 0i64;
  this->mOverflowVRAM = 0i64;
  this->mOverflowMain = 0i64;
  this->mUnusedBlocks.mNode.mPrev = &this->mUnusedBlocks.mNode;
  this->mUnusedBlocks.mNode.mNext = &this->mUnusedBlocks.mNode;
  this->mMainMemoryBlocks.mNode.mPrev = &this->mMainMemoryBlocks.mNode;
  this->mMainMemoryBlocks.mNode.mNext = &this->mMainMemoryBlocks.mNode;
  this->mUsedBlocks.mNode.mPrev = &this->mUsedBlocks.mNode;
  this->mUsedBlocks.mNode.mNext = &this->mUsedBlocks.mNode;
  this->mFreeList.mNode.mPrev = &this->mFreeList.mNode;
  this->mFreeList.mNode.mNext = &this->mFreeList.mNode;
  this->mPendingFreeList.mNode.mPrev = &this->mPendingFreeList.mNode;
  this->mPendingFreeList.mNode.mNext = &this->mPendingFreeList.mNode;
  this->mMoveTargetsList.mNode.mPrev = &this->mMoveTargetsList.mNode;
  this->mMoveTargetsList.mNode.mNext = &this->mMoveTargetsList.mNode;
  this->mContainerList.mNode.mPrev = &this->mContainerList.mNode;
  this->mContainerList.mNode.mNext = &this->mContainerList.mNode;
  this->mBlocks = 0i64;
  this->mBlocksMemory = 0i64;
  this->mBlocksMemorySize = 0;
  this->mNumBlocksTotal = -1;
  *(_QWORD *)&this->mMinAlignment = 256i64;
  *(_QWORD *)&this->mLargestFreeBlock = 0i64;
  *(_QWORD *)&this->mPeakUsedMemory = 0i64;
  *(_QWORD *)&this->mAlignmentLoss = 0i64;
  *(_QWORD *)&this->mUsedBlocksCount = 0i64;
  this->mPoolID = -1;
  this->mDefragFreeFrameDelay = 2;
  *(_DWORD *)&this->mDefragAllowed = 1;
  this->mValidate = 0;
  v2 = UFG::qVRAMemoryPool::sUninitializedName;
  v3 = 32;
  mName = this->mName;
  if ( this != (UFG::qVRAMemoryPool *)-312i64 )
  {
    if ( !UFG::qVRAMemoryPool::sUninitializedName )
      goto LABEL_6;
    do
    {
      v5 = *v2;
      *mName++ = *v2++;
      if ( !v5 )
        break;
      --v3;
    }
    while ( v3 > 1 );
    if ( *(mName - 1) )
LABEL_6:
      *mName = 0;
  }
}

// File Line: 584
// RVA: 0x164610
void __fastcall UFG::qVRAMemoryPool::~qVRAMemoryPool(UFG::qVRAMemoryPool *this)
{
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *mPrev; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *mNext; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v4; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v5; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v6; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v7; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v8; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v9; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v10; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v11; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v12; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v13; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v14; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v15; // rax
  UFG::qNode<UFG::qVRAMemoryPool,UFG::qVRAMemoryPool> *v16; // rcx
  UFG::qNode<UFG::qVRAMemoryPool,UFG::qVRAMemoryPool> *v17; // rax

  UFG::qVRAMemoryPool::Close(this);
  UFG::qList<UFG::BlockInfo,UFG::Secondary,1,0>::DeleteNodes(&this->mContainerList);
  mPrev = this->mContainerList.mNode.mPrev;
  mNext = this->mContainerList.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mContainerList.mNode.mPrev = &this->mContainerList.mNode;
  this->mContainerList.mNode.mNext = &this->mContainerList.mNode;
  UFG::qList<UFG::BlockInfo,UFG::Secondary,1,0>::DeleteNodes(&this->mMoveTargetsList);
  v4 = this->mMoveTargetsList.mNode.mPrev;
  v5 = this->mMoveTargetsList.mNode.mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  this->mMoveTargetsList.mNode.mPrev = &this->mMoveTargetsList.mNode;
  this->mMoveTargetsList.mNode.mNext = &this->mMoveTargetsList.mNode;
  UFG::qList<UFG::BlockInfo,UFG::Secondary,1,0>::DeleteNodes(&this->mPendingFreeList);
  v6 = this->mPendingFreeList.mNode.mPrev;
  v7 = this->mPendingFreeList.mNode.mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  this->mPendingFreeList.mNode.mPrev = &this->mPendingFreeList.mNode;
  this->mPendingFreeList.mNode.mNext = &this->mPendingFreeList.mNode;
  UFG::qList<UFG::BlockInfo,UFG::Secondary,1,0>::DeleteNodes(&this->mFreeList);
  v8 = this->mFreeList.mNode.mPrev;
  v9 = this->mFreeList.mNode.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  this->mFreeList.mNode.mPrev = &this->mFreeList.mNode;
  this->mFreeList.mNode.mNext = &this->mFreeList.mNode;
  UFG::qList<UFG::BlockInfo,UFG::Primary,1,0>::DeleteNodes(&this->mUsedBlocks);
  v10 = this->mUsedBlocks.mNode.mPrev;
  v11 = this->mUsedBlocks.mNode.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  this->mUsedBlocks.mNode.mPrev = &this->mUsedBlocks.mNode;
  this->mUsedBlocks.mNode.mNext = &this->mUsedBlocks.mNode;
  UFG::qList<UFG::BlockInfo,UFG::Primary,1,0>::DeleteNodes(&this->mMainMemoryBlocks);
  v12 = this->mMainMemoryBlocks.mNode.mPrev;
  v13 = this->mMainMemoryBlocks.mNode.mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  this->mMainMemoryBlocks.mNode.mPrev = &this->mMainMemoryBlocks.mNode;
  this->mMainMemoryBlocks.mNode.mNext = &this->mMainMemoryBlocks.mNode;
  UFG::qList<UFG::BlockInfo,UFG::Primary,1,0>::DeleteNodes(&this->mUnusedBlocks);
  v14 = this->mUnusedBlocks.mNode.mPrev;
  v15 = this->mUnusedBlocks.mNode.mNext;
  v14->mNext = v15;
  v15->mPrev = v14;
  this->mUnusedBlocks.mNode.mPrev = &this->mUnusedBlocks.mNode;
  this->mUnusedBlocks.mNode.mNext = &this->mUnusedBlocks.mNode;
  UFG::qVRAMemoryHandle::~qVRAMemoryHandle(&this->mPoolMemory);
  Scaleform::Lock::~Lock((LPCRITICAL_SECTION)&this->mPoolLock);
  v16 = this->mPrev;
  v17 = this->mNext;
  v16->mNext = v17;
  v17->mPrev = v16;
  this->mPrev = this;
  this->mNext = this;
}

// File Line: 602
// RVA: 0x173750
__int64 __fastcall UFG::qVRAMemoryPool::Init(
        UFG::qVRAMemoryPool *this,
        char *vram_start,
        unsigned int vram_size,
        const char *name,
        unsigned __int16 num_blocks,
        unsigned int min_alignment,
        char *block_memory,
        unsigned int block_memory_size)
{
  signed int v8; // ebp
  __int64 v9; // rbx
  unsigned __int8 v12; // r15
  char *v13; // r10
  unsigned int v14; // edx
  int v16; // [rsp+40h] [rbp-48h]

  v8 = min_alignment;
  v9 = vram_size;
  UFG::qPrintChannel::Print(
    &UFG::VRAMChannel,
    OUTPUT_LEVEL_WARNING,
    "[VRAM Channel] - Init(%p, 0x%08x(%u), %.64s, %u, %u, %p, 0x%08x(%u))\n");
  v12 = 0;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mPoolLock);
  UFG::qVRAMemoryPool::AssertValid(this);
  if ( min_alignment < 0x100 )
    v8 = 256;
  if ( this->mInitialized != 1
    && (!block_memory || block_memory_size >= num_blocks << 7)
    && vram_start
    && (_DWORD)v9
    && !UFG::qVRAMemoryPools::OverlapsPool(vram_start, v9) )
  {
    v13 = (char *)(~(v8 - 1i64) & (unsigned __int64)&vram_start[v8 - 1]);
    this->mVRAMemoryStart = v13;
    v14 = ~(v8 - 1) & (v9 + (_DWORD)vram_start - (_DWORD)v13);
    this->mVRAMemorySize = v14;
    if ( v13 != vram_start || v14 != (_DWORD)v9 )
    {
      v16 = ~(v8 - 1) & (v9 + (_DWORD)vram_start - (_DWORD)v13);
      UFG::qPrintf(
        "Passed in memory %p-%p of size %d (0x%08x) aligned down to %p-%p of size %d (0x%08x)\n",
        vram_start,
        &vram_start[v9 - 1],
        (unsigned int)v9,
        v9,
        (const void *)(~(v8 - 1i64) & (unsigned __int64)&vram_start[v8 - 1]),
        &v13[v14 - 1],
        v16,
        v16);
    }
    v12 = UFG::qVRAMemoryPool::CommonInit(this, name, num_blocks, v8, block_memory, block_memory_size);
  }
  UFG::qVRAMemoryPool::AssertValid(this);
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mPoolLock);
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
  return v12;
}

// File Line: 748
// RVA: 0x1681C0
void __fastcall UFG::qVRAMemoryPool::Close(UFG::qVRAMemoryPool *this)
{
  char *mName; // rdi
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *mNext; // rdx
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *mPrev; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v5; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v6; // rdx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v7; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v8; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v9; // rdx
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v10; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v11; // rax
  UFG::BlockInfo *mBlocks; // rcx
  unsigned int *p_mCallbackData32; // rsi
  const char *v14; // rdx
  int v15; // ecx
  char v16; // al

  mName = this->mName;
  UFG::qPrintChannel::Print(&UFG::VRAMChannel, OUTPUT_LEVEL_WARNING, "[VRAM Channel] - %.64s->Close()\n");
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mPoolLock);
  UFG::qVRAMemoryPool::AssertValid(this);
  if ( this->mInitialized == 1 )
  {
    UFG::qVRAMemoryPool::ForceEmptyPool(this);
    if ( this->mPoolMemory.mData )
      UFG::qVRAMemoryPools::Free(&this->mPoolMemory, 0);
    mNext = this->mUsedBlocks.mNode.mNext;
    this->mVRAMemoryStart = 0i64;
    this->mVRAMemorySize = 0;
    this->mMainMemoryPool = 0i64;
    this->mOverflowVRAM = 0i64;
    this->mOverflowMain = 0i64;
    mPrev = mNext->mPrev;
    v5 = mNext->mNext;
    mPrev->mNext = v5;
    v5->mPrev = mPrev;
    mNext->mPrev = mNext;
    mNext->mNext = mNext;
    v6 = this->mFreeList.mNode.mNext;
    v7 = v6->mPrev;
    v8 = v6->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v6->mPrev = v6;
    for ( v6->mNext = v6;
          (UFG::qList<UFG::BlockInfo,UFG::Primary,1,0> *)this->mUnusedBlocks.mNode.mNext != &this->mUnusedBlocks;
          v9->mNext = v9 )
    {
      v9 = this->mUnusedBlocks.mNode.mNext;
      v10 = v9->mPrev;
      v11 = v9->mNext;
      v10->mNext = v11;
      v11->mPrev = v10;
      v9->mPrev = v9;
    }
    if ( !this->mBlocksMemory )
    {
      mBlocks = this->mBlocks;
      if ( mBlocks )
      {
        p_mCallbackData32 = &mBlocks[-1].mCallbackData32;
        `eh vector destructor iterator(
          mBlocks,
          0x80ui64,
          mBlocks[-1].mCallbackData32,
          (void (__fastcall *)(void *))UFG::BlockInfo::~BlockInfo);
        if ( p_mCallbackData32 )
          UFG::qMemoryPool::Free(UFG::gMainMemoryPool, p_mCallbackData32);
      }
    }
    this->mBlocks = 0i64;
    this->mBlocksMemory = 0i64;
    this->mBlocksMemorySize = 0;
    *(_QWORD *)&this->mMinAlignment = 256i64;
    *(_QWORD *)&this->mLargestFreeBlock = 0i64;
    this->mNumBlocksTotal = -1;
    *(_QWORD *)&this->mPeakUsedMemory = 0i64;
    *(_QWORD *)&this->mAlignmentLoss = 0i64;
    *(_QWORD *)&this->mUsedBlocksCount = 0i64;
    v14 = UFG::qVRAMemoryPool::sUninitializedName;
    v15 = 32;
    if ( mName )
    {
      if ( !UFG::qVRAMemoryPool::sUninitializedName )
        goto LABEL_15;
      do
      {
        v16 = *v14;
        ++mName;
        ++v14;
        *(mName - 1) = v16;
        if ( !v16 )
          break;
        --v15;
      }
      while ( v15 > 1 );
      if ( *(mName - 1) )
LABEL_15:
        *mName = 0;
    }
    UFG::qVRAMemoryPools::sVRAMemoryPools[this->mPoolID] = 0i64;
    *(_WORD *)&this->mNeedsDefragmentUp = 0;
    this->mInitialized = 0;
    this->mPoolID = -1;
  }
  UFG::qVRAMemoryPool::AssertValid(this);
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mPoolLock);
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
}

// File Line: 879
// RVA: 0x16E2A0
char __fastcall UFG::qVRAMemoryPool::ForceEmptyPool(UFG::qVRAMemoryPool *this)
{
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *mNext; // rax
  bool v3; // cl
  bool v4; // zf
  UFG::BlockInfo *v5; // rdx

  UFG::qPrintChannel::Print(&UFG::VRAMChannel, OUTPUT_LEVEL_WARNING, "[VRAM Channel] - %.64s->ForceEmptyPool()\n");
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mPoolLock);
  UFG::qVRAMemoryPool::AssertValid(this);
  if ( this->mInitialized == 1 )
  {
    mNext = this->mUsedBlocks.mNode.mNext;
    v3 = BYTE2(mNext[4].mNext) == 1;
    if ( mNext != this->mUsedBlocks.mNode.mPrev || !v3 )
    {
      while ( 1 )
      {
        v4 = v3;
        while ( 1 )
        {
          v5 = (UFG::BlockInfo *)(v4 ? mNext->mNext : mNext);
          UFG::qVRAMemoryPool::InternalFree(this, v5);
          mNext = this->mUsedBlocks.mNode.mNext;
          v3 = BYTE2(mNext[4].mNext) == 1;
          if ( mNext != this->mUsedBlocks.mNode.mPrev )
            break;
          v4 = v3;
          if ( v3 )
            goto LABEL_10;
        }
      }
    }
  }
LABEL_10:
  UFG::qVRAMemoryPool::AssertValid(this);
  return 1;
}

// File Line: 919
// RVA: 0x166D30
_BOOL8 __fastcall UFG::qVRAMemoryPool::Allocate(
        UFG::qVRAMemoryPool *this,
        UFG::qVRAMemoryHandle *handle,
        unsigned int size,
        unsigned int usage,
        const char *name,
        unsigned int alignment,
        unsigned __int8 flags,
        UFG::qMemoryPool *pool,
        unsigned __int64 user_data_64,
        unsigned int user_data_32)
{
  unsigned __int64 v10; // rsi
  char v13; // di
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *mPrev; // rcx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *mNext; // rax
  signed int mMinAlignment; // ebx
  UFG::BlockInfo *v17; // r10
  UFG::qList<UFG::BlockInfo,UFG::Primary,1,0> *p_mUsedBlocks; // rax
  UFG::BlockInfo *v19; // rdi
  unsigned int mActualSize; // r11d
  unsigned int v21; // r8d
  UFG::BlockInfo *v22; // rdi
  unsigned int v23; // r11d
  unsigned int v24; // r8d
  char i; // al
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v26; // rax
  char *mData; // rbx
  unsigned __int16 mBlockID; // si
  unsigned __int16 mPoolID; // di
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v30; // rcx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v31; // rax
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v32; // rax
  unsigned int mUsedMemory; // eax
  UFG::qMemoryPool *mMainMemoryPool; // rcx
  unsigned __int64 v35; // r9
  UFG::BlockInfo *UnusedBlock; // rax
  char v37; // cl
  UFG::BlockInfo *v38; // rdi
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v39; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v40; // rax
  UFG::qVRAMemoryPool *mOverflowVRAM; // rcx
  UFG::qMemoryPool *mOverflowMain; // rcx
  UFG::BlockInfo *v43; // rax
  UFG::qMemoryPool *v44; // r8
  char v45; // cl
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v46; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v47; // rax
  char *v49; // [rsp+80h] [rbp-38h]
  UFG::BlockInfo *v50; // [rsp+88h] [rbp-30h]
  UFG::qMemoryPool *v51; // [rsp+88h] [rbp-30h]
  bool v52; // [rsp+C0h] [rbp+8h]
  char *poola; // [rsp+F8h] [rbp+40h]

  v10 = size;
  v13 = flags;
  UFG::qPrintChannel::Print(
    &UFG::VRAMChannel,
    OUTPUT_LEVEL_WARNING,
    "[VRAM Channel] - %.64s->Allocate(handle(%p), 0x%08x(%u), %s, %.64s%s, %u, 0x%08x, %s, 0x%016x64, 0x%08x)\n");
  v52 = 0;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mPoolLock);
  UFG::qVRAMemoryPool::AssertValid(this);
  if ( !(_DWORD)v10 )
  {
    UFG::qPrintChannel::Print(
      &UFG::VRAMChannel,
      OUTPUT_LEVEL_ERROR,
      "[VRAM Channel]   Someone requested 0 bytes with name %.64s from pool %.64s\n");
    UFG::qPrintChannel::Print(
      &UFG::VRAMChannel,
      OUTPUT_LEVEL_DEBUG,
      "[VRAM Channel] - Setting qVRAMemoryHandle(%p) to point at - PoolID:0x%02x BlockID:0x%04x Data:%p-%p AllocatedSize:%u\n");
    mPrev = handle->mPrev;
    mNext = handle->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    handle->mPrev = handle;
    handle->mNext = handle;
    handle->mData = 0i64;
    *(_DWORD *)&handle->mReadOnlyAndPoolID = 0;
    goto LABEL_55;
  }
  if ( this->mInitialized == 1 )
  {
    mMinAlignment = alignment;
    if ( this->mMinAlignment > alignment )
      mMinAlignment = this->mMinAlignment;
    if ( usage == 14 )
    {
      mMainMemoryPool = pool;
      v51 = pool;
      if ( !pool )
      {
        mMainMemoryPool = UFG::gMainMemoryPool;
        if ( this->mMainMemoryPool )
          mMainMemoryPool = this->mMainMemoryPool;
        v51 = mMainMemoryPool;
      }
      v35 = (unsigned __int64)(mMinAlignment & 0xFFFFFF) << 8;
      if ( (flags & 2) != 0 )
        v35 |= 1ui64;
      v49 = (char *)UFG::qMemoryPool::Allocate(mMainMemoryPool, v10, name, v35, 0);
      if ( v49 )
      {
        UnusedBlock = UFG::qVRAMemoryPool::GetUnusedBlock(this);
        v37 = 0;
        v38 = UnusedBlock;
        UnusedBlock->mData = v49;
        UnusedBlock->mName = name;
        UnusedBlock->mRequestedSize = v10;
        for ( UnusedBlock->mActualSize = v10; mMinAlignment != 1; ++v37 )
          mMinAlignment = (unsigned int)mMinAlignment >> 1;
        UnusedBlock->mAlignmentShift = v37;
        UnusedBlock->mUsage = 14;
        UnusedBlock->mKeepAliveFrames = 0;
        UnusedBlock->mFlags = flags | 0x10;
        UnusedBlock->mMemoryPool = v51;
        UnusedBlock->mContainerID = 0;
        UnusedBlock->mCallbackData64 = user_data_64;
        UnusedBlock->mCallbackData32 = user_data_32;
        UFG::qVRAMemoryHandle::Set(handle, v49, v10, this->mPoolID, UnusedBlock->mBlockID);
        v39 = v38->mAllocationHandles.mNode.mPrev;
        v39->mNext = handle;
        handle->mPrev = v39;
        handle->mNext = &v38->mAllocationHandles.mNode;
        v38->mAllocationHandles.mNode.mPrev = handle;
        goto LABEL_43;
      }
    }
    else
    {
      v17 = 0i64;
      p_mUsedBlocks = &this->mUsedBlocks;
      v50 = 0i64;
      if ( (flags & 1) != 0 )
      {
        v19 = (UFG::BlockInfo *)&this->mFreeList.mNode.mNext[-1];
        while ( v19 != (UFG::BlockInfo *)p_mUsedBlocks )
        {
          if ( v19->mUsage == 1 )
          {
            mActualSize = v19->mActualSize;
            if ( mActualSize >= (unsigned int)v10 )
            {
              v21 = ~(this->mMinAlignment - 1) & (this->mMinAlignment + v10 - 1);
              if ( (__int64)&v19->mData[mActualSize
                                      - (~(mMinAlignment - 1i64) & (__int64)&v19->mData[mMinAlignment - 1])] >= v21 )
              {
                v17 = UFG::qVRAMemoryPool::SplitFreeBlock(this, v19, v21, mMinAlignment, flags);
                v50 = v17;
              }
              p_mUsedBlocks = &this->mUsedBlocks;
            }
          }
          v19 = (UFG::BlockInfo *)&v19->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mNext[-1];
          if ( v17 )
            goto LABEL_26;
        }
      }
      else
      {
        flags |= 2u;
        v22 = (UFG::BlockInfo *)&this->mFreeList.mNode.mPrev[-1];
        while ( v22 != (UFG::BlockInfo *)p_mUsedBlocks )
        {
          v23 = v22->mActualSize;
          if ( v23 >= (unsigned int)v10 )
          {
            v24 = ~(this->mMinAlignment - 1) & (this->mMinAlignment + v10 - 1);
            if ( (__int64)&v22->mData[v23 - (~(mMinAlignment - 1i64) & (__int64)&v22->mData[mMinAlignment - 1])] >= v24 )
            {
              v17 = UFG::qVRAMemoryPool::SplitFreeBlock(this, v22, v24, mMinAlignment, flags);
              v50 = v17;
            }
            p_mUsedBlocks = &this->mUsedBlocks;
          }
          v22 = (UFG::BlockInfo *)&v22->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mPrev[-1];
          if ( v17 )
          {
LABEL_26:
            v17->mRequestedSize = v10;
            v17->mName = name;
            for ( i = 0; mMinAlignment != 1; ++i )
              mMinAlignment = (unsigned int)mMinAlignment >> 1;
            v17->mAlignmentShift = i;
            v17->mFlags = flags;
            v17->mUsage = usage;
            v17->mMemoryPool = 0i64;
            v17->mContainerID = 0;
            v17->mCallbackData64 = user_data_64;
            v17->mKeepAliveFrames = 0;
            v17->mCallbackData32 = user_data_32;
            if ( usage - 9 <= 1 )
            {
              v26 = this->mContainerList.mNode.mNext;
              this->mContainerList.mNode.mNext = &v17->UFG::qNode<UFG::BlockInfo,UFG::Secondary>;
              v17->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mPrev = &this->mContainerList.mNode;
              v17->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mNext = v26;
              v26->mPrev = &v17->UFG::qNode<UFG::BlockInfo,UFG::Secondary>;
            }
            mData = v17->mData;
            mBlockID = v17->mBlockID;
            mPoolID = this->mPoolID;
            UFG::qPrintChannel::Print(
              &UFG::VRAMChannel,
              OUTPUT_LEVEL_DEBUG,
              "[VRAM Channel] - Setting qVRAMemoryHandle(%p) to point at - PoolID:0x%02x BlockID:0x%04x Data:%p-%p AllocatedSize:%u\n");
            v30 = handle->mPrev;
            v31 = handle->mNext;
            v30->mNext = v31;
            v31->mPrev = v30;
            handle->mPrev = handle;
            handle->mNext = handle;
            handle->mData = mData;
            handle->mReadOnlyAndPoolID = mPoolID;
            handle->mBlockID = mBlockID;
            v32 = v50->mAllocationHandles.mNode.mPrev;
            v32->mNext = handle;
            handle->mPrev = v32;
            handle->mNext = &v50->mAllocationHandles.mNode;
            v50->mAllocationHandles.mNode.mPrev = handle;
            this->mFreeMemory -= v50->mActualSize;
            this->mUsedMemory += v50->mActualSize;
            this->mAllocatedMemory += v50->mRequestedSize;
            this->mAlignmentLoss += v50->mActualSize - v50->mRequestedSize;
            mUsedMemory = this->mUsedMemory;
            if ( mUsedMemory > this->mPeakUsedMemory )
              this->mPeakUsedMemory = mUsedMemory;
            v52 = 1;
            goto LABEL_55;
          }
        }
      }
      v13 = flags;
    }
    mOverflowVRAM = this->mOverflowVRAM;
    if ( !mOverflowVRAM
      || !(v52 = UFG::qVRAMemoryPool::Allocate(
                   mOverflowVRAM,
                   handle,
                   v10,
                   usage,
                   name,
                   alignment,
                   v13,
                   pool,
                   user_data_64,
                   user_data_32)) )
    {
      mOverflowMain = this->mOverflowMain;
      if ( mOverflowMain )
      {
        poola = (char *)UFG::qMemoryPool::Allocate(
                          mOverflowMain,
                          v10,
                          name,
                          (unsigned __int64)(mMinAlignment & 0xFFFFFF) << 8,
                          0);
        if ( poola )
        {
          v43 = UFG::qVRAMemoryPool::GetUnusedBlock(this);
          v44 = this->mOverflowMain;
          v38 = v43;
          v43->mData = poola;
          v45 = 0;
          v43->mName = name;
          v43->mRequestedSize = v10;
          for ( v43->mActualSize = v10; mMinAlignment != 1; ++v45 )
            mMinAlignment = (unsigned int)mMinAlignment >> 1;
          v43->mAlignmentShift = v45;
          v43->mMemoryPool = v44;
          v43->mUsage = 15;
          v43->mFlags = flags | 0x10;
          v43->mKeepAliveFrames = 0;
          v43->mContainerID = 0;
          v43->mCallbackData64 = user_data_64;
          v43->mCallbackData32 = user_data_32;
          UFG::qVRAMemoryHandle::Set(handle, poola, v10, this->mPoolID, v43->mBlockID);
          v46 = v38->mAllocationHandles.mNode.mPrev;
          v46->mNext = handle;
          handle->mPrev = v46;
          handle->mNext = &v38->mAllocationHandles.mNode;
          v38->mAllocationHandles.mNode.mPrev = handle;
          if ( usage - 9 <= 1 )
          {
            v47 = this->mContainerList.mNode.mNext;
            this->mContainerList.mNode.mNext = &v38->UFG::qNode<UFG::BlockInfo,UFG::Secondary>;
            v38->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mPrev = &this->mContainerList.mNode;
            v38->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mNext = v47;
            v47->mPrev = &v38->UFG::qNode<UFG::BlockInfo,UFG::Secondary>;
          }
LABEL_43:
          v52 = 1;
          v40 = this->mMainMemoryBlocks.mNode.mPrev;
          v40->mNext = v38;
          v38->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mPrev = v40;
          v38->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mNext = &this->mMainMemoryBlocks.mNode;
          this->mMainMemoryBlocks.mNode.mPrev = v38;
          this->mUsedMainMemory += v10;
          goto LABEL_55;
        }
      }
      if ( (v13 & 8) != 0 )
        UFG::qPrintChannel::Print(
          &UFG::VRAMChannel,
          OUTPUT_LEVEL_WARNING,
          "Pool %s (Free:%u Largest:%u) is too full for named allocation %s of size %u, allowable fail, try again next frame\n");
      else
        UFG::qVRAMemoryPool::Print(this, 5u);
    }
  }
LABEL_55:
  if ( this->mValidate )
  {
    UFG::qPrintChannel::Print(&UFG::VRAMChannel, OUTPUT_LEVEL_WARNING, "[VRAM Channel] - %.64s->AssertValid()\n");
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mPoolLock);
    if ( this->mInitialized == 1 )
      UFG::qVRAMemoryPool::AssertValidInitialized(this);
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mPoolLock);
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mPoolLock);
  UFG::qPrintChannel::Print(
    &UFG::VRAMChannel,
    OUTPUT_LEVEL_WARNING,
    "[VRAM Channel] -   Allocated 0x%08x(%u) bytes at [%p - %p] named %.64s in pool %.64s\n");
  return v52;
}

// File Line: 1290
// RVA: 0x178B60
__int64 __fastcall UFG::qVRAMemoryPool::PreMove(UFG::qVRAMemoryPool *this, UFG::qVRAMemoryHandle *handle)
{
  unsigned __int8 v4; // si
  unsigned __int16 mNumBlocksTotal; // ax
  unsigned __int16 mBlockID; // cx
  UFG::BlockInfo *Block; // rax
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *mPrev; // rdx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *mNext; // rax

  UFG::qPrintChannel::Print(&UFG::VRAMChannel, OUTPUT_LEVEL_WARNING, "[VRAM Channel] - %.64s->PreMove(handle(%p))\n");
  v4 = 0;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mPoolLock);
  UFG::qVRAMemoryPool::AssertValid(this);
  if ( this->mInitialized == 1 && (handle->mReadOnlyAndPoolID & 0x7FFF) == this->mPoolID )
  {
    mNumBlocksTotal = this->mNumBlocksTotal;
    mBlockID = handle->mBlockID;
    if ( mNumBlocksTotal )
    {
      if ( mBlockID >= mNumBlocksTotal )
        goto LABEL_9;
      Block = &this->mBlocks[(unsigned __int64)mBlockID];
    }
    else
    {
      Block = UFG::qVRAMemoryPools::GetBlock(mBlockID);
    }
    if ( Block )
    {
      mPrev = handle->mPrev;
      mNext = handle->mNext;
      v4 = 1;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      handle->mPrev = handle;
      handle->mNext = handle;
    }
  }
LABEL_9:
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mPoolLock);
  return v4;
}

// File Line: 1318
// RVA: 0x178990
__int64 __fastcall UFG::qVRAMemoryPool::PostMove(UFG::qVRAMemoryPool *this, UFG::qVRAMemoryHandle *handle)
{
  unsigned __int8 v4; // si
  unsigned __int16 mNumBlocksTotal; // ax
  unsigned __int16 mBlockID; // cx
  UFG::BlockInfo *Block; // rax
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *p_mNode; // rdx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *mPrev; // rax

  UFG::qPrintChannel::Print(&UFG::VRAMChannel, OUTPUT_LEVEL_WARNING, "[VRAM Channel] - %.64s->PostMove(handle(%p))\n");
  v4 = 0;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mPoolLock);
  UFG::qVRAMemoryPool::AssertValid(this);
  if ( this->mInitialized == 1 && (handle->mReadOnlyAndPoolID & 0x7FFF) == this->mPoolID )
  {
    mNumBlocksTotal = this->mNumBlocksTotal;
    mBlockID = handle->mBlockID;
    if ( mNumBlocksTotal )
    {
      if ( mBlockID >= mNumBlocksTotal )
        goto LABEL_9;
      Block = &this->mBlocks[(unsigned __int64)mBlockID];
    }
    else
    {
      Block = UFG::qVRAMemoryPools::GetBlock(mBlockID);
    }
    if ( Block )
    {
      handle->mPrev = handle;
      handle->mNext = handle;
      p_mNode = &Block->mAllocationHandles.mNode;
      mPrev = Block->mAllocationHandles.mNode.mPrev;
      v4 = 1;
      mPrev->mNext = handle;
      handle->mPrev = mPrev;
      handle->mNext = p_mNode;
      p_mNode->mPrev = handle;
    }
  }
LABEL_9:
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mPoolLock);
  return v4;
}

// File Line: 1347
// RVA: 0x16EA30
_BOOL8 __fastcall UFG::qVRAMemoryPool::Free(
        UFG::qVRAMemoryPool *this,
        UFG::qVRAMemoryHandle *handle,
        int frames_to_delay)
{
  bool v6; // r14
  unsigned __int16 mNumBlocksTotal; // ax
  unsigned __int16 mBlockID; // cx
  UFG::BlockInfo *Block; // rsi
  char mUsage; // cl
  unsigned __int16 v11; // ax
  unsigned __int16 mContainerID; // cx
  UFG::BlockInfo *v13; // rdi
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *mPrev; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *mNext; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v16; // rax
  bool v17; // al
  int v18; // eax
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v19; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v20; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v21; // rax
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v22; // rcx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v23; // rax
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v24; // rcx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v25; // rax
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v26; // rbx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v27; // rcx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v28; // rax
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v29; // rcx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v30; // rax

  UFG::qPrintChannel::Print(&UFG::VRAMChannel, OUTPUT_LEVEL_WARNING, "[VRAM Channel] - %.64s->Free(handle(%p), %u)\n");
  v6 = 0;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mPoolLock);
  UFG::qVRAMemoryPool::AssertValid(this);
  if ( this->mInitialized == 1 )
  {
    if ( (handle->mReadOnlyAndPoolID & 0x7FFF) != this->mPoolID )
    {
      v17 = UFG::qVRAMemoryPools::Free(handle, frames_to_delay);
      goto LABEL_32;
    }
    mNumBlocksTotal = this->mNumBlocksTotal;
    mBlockID = handle->mBlockID;
    if ( mNumBlocksTotal )
    {
      if ( mBlockID >= mNumBlocksTotal )
        goto LABEL_33;
      Block = &this->mBlocks[(unsigned __int64)mBlockID];
    }
    else
    {
      Block = UFG::qVRAMemoryPools::GetBlock(mBlockID);
    }
    if ( Block )
    {
      mUsage = Block->mUsage;
      if ( mUsage == 11 )
      {
        v11 = this->mNumBlocksTotal;
        mContainerID = Block->mContainerID;
        v13 = 0i64;
        if ( v11 )
        {
          if ( mContainerID < v11 )
            v13 = &this->mBlocks[(unsigned __int64)mContainerID];
        }
        else
        {
          v13 = UFG::qVRAMemoryPools::GetBlock(mContainerID);
        }
        v6 = UFG::qVRAMemoryPool::InternalFree(this, Block);
        if ( v13->mUsage == 9
          && v13->mContainedBlocks.mNode.mNext == (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&v13->mContainedBlocks )
        {
          if ( (v13->mFlags & 0x40) != 0 )
          {
            mPrev = v13->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mPrev;
            mNext = v13->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mNext;
            mPrev->mNext = mNext;
            mNext->mPrev = mPrev;
            v13->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mPrev = &v13->UFG::qNode<UFG::BlockInfo,UFG::Secondary>;
            v13->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mNext = &v13->UFG::qNode<UFG::BlockInfo,UFG::Secondary>;
            v13->mKeepAliveFrames = 1;
            v16 = this->mPendingFreeList.mNode.mPrev;
            v16->mNext = &v13->UFG::qNode<UFG::BlockInfo,UFG::Secondary>;
            v13->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mNext = &this->mPendingFreeList.mNode;
            v13->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mPrev = v16;
            this->mPendingFreeList.mNode.mPrev = &v13->UFG::qNode<UFG::BlockInfo,UFG::Secondary>;
            UFG::qVRAMemoryHandle::Close(handle);
            v6 = 1;
            goto LABEL_33;
          }
          v17 = UFG::qVRAMemoryPool::InternalFree(this, v13);
LABEL_32:
          v6 = v17;
        }
      }
      else
      {
        if ( (Block->mFlags & 0x40) != 0 )
        {
          v18 = 1;
          if ( frames_to_delay )
            v18 = frames_to_delay;
          frames_to_delay = v18;
        }
        if ( !frames_to_delay )
        {
          v17 = UFG::qVRAMemoryPool::InternalFree(this, Block);
          goto LABEL_32;
        }
        if ( (unsigned __int8)(mUsage - 9) <= 1u )
        {
          v19 = Block->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mPrev;
          v20 = Block->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mNext;
          v19->mNext = v20;
          v20->mPrev = v19;
          Block->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mPrev = &Block->UFG::qNode<UFG::BlockInfo,UFG::Secondary>;
          Block->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mNext = &Block->UFG::qNode<UFG::BlockInfo,UFG::Secondary>;
        }
        Block->mKeepAliveFrames = frames_to_delay;
        v21 = this->mPendingFreeList.mNode.mPrev;
        v21->mNext = &Block->UFG::qNode<UFG::BlockInfo,UFG::Secondary>;
        Block->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mPrev = v21;
        Block->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mNext = &this->mPendingFreeList.mNode;
        this->mPendingFreeList.mNode.mPrev = &Block->UFG::qNode<UFG::BlockInfo,UFG::Secondary>;
        if ( (Block->mFlags & 0x40) != 0 )
        {
          v22 = handle->mPrev;
          v23 = handle->mNext;
          v22->mNext = v23;
          v23->mPrev = v22;
          handle->mPrev = handle;
          handle->mNext = handle;
          UFG::qPrintChannel::Print(
            &UFG::VRAMChannel,
            OUTPUT_LEVEL_DEBUG,
            "[VRAM Channel] - Setting qVRAMemoryHandle(%p) to point at - PoolID:0x%02x BlockID:0x%04x Data:%p-%p AllocatedSize:%u\n");
          v24 = handle->mPrev;
          v25 = handle->mNext;
          v6 = 1;
          v24->mNext = v25;
          v25->mPrev = v24;
          handle->mPrev = handle;
          handle->mNext = handle;
          handle->mData = 0i64;
          *(_DWORD *)&handle->mReadOnlyAndPoolID = 0;
        }
        else
        {
          for ( ;
                (UFG::qList<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly,1,0> *)Block->mAllocationHandles.mNode.mNext != &Block->mAllocationHandles;
                LODWORD(v26[1].mNext) = 0 )
          {
            v26 = Block->mAllocationHandles.mNode.mNext;
            v27 = v26->mPrev;
            v28 = v26->mNext;
            v27->mNext = v28;
            v28->mPrev = v27;
            v26->mPrev = v26;
            v26->mNext = v26;
            UFG::qPrintChannel::Print(
              &UFG::VRAMChannel,
              OUTPUT_LEVEL_DEBUG,
              "[VRAM Channel] - Setting qVRAMemoryHandle(%p) to point at - PoolID:0x%02x BlockID:0x%04x Data:%p-%p AllocatedSize:%u\n");
            v29 = v26->mPrev;
            v30 = v26->mNext;
            v29->mNext = v30;
            v30->mPrev = v29;
            v26->mPrev = v26;
            v26->mNext = v26;
            v26[1].mPrev = 0i64;
          }
          v6 = 1;
        }
      }
    }
  }
LABEL_33:
  UFG::qVRAMemoryPool::AssertValid(this);
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mPoolLock);
  return v6;
}

// File Line: 1467
// RVA: 0x1772C0
__int64 __fastcall UFG::qVRAMemoryPool::Lock(UFG::qVRAMemoryPool *this, UFG::qVRAMemoryHandle *handle)
{
  unsigned __int8 v4; // bp
  unsigned __int16 mNumBlocksTotal; // ax
  unsigned __int16 mBlockID; // cx
  UFG::BlockInfo *Block; // rbx

  UFG::qPrintChannel::Print(&UFG::VRAMChannel, OUTPUT_LEVEL_WARNING, "[VRAM Channel] - %.64s->Lock(handle(%p))\n");
  v4 = 0;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mPoolLock);
  UFG::qVRAMemoryPool::AssertValid(this);
  if ( this->mInitialized == 1 && (handle->mReadOnlyAndPoolID & 0x7FFF) == this->mPoolID )
  {
    mNumBlocksTotal = this->mNumBlocksTotal;
    mBlockID = handle->mBlockID;
    if ( mNumBlocksTotal )
    {
      if ( mBlockID >= mNumBlocksTotal )
        goto LABEL_11;
      Block = &this->mBlocks[(unsigned __int64)mBlockID];
    }
    else
    {
      Block = UFG::qVRAMemoryPools::GetBlock(mBlockID);
    }
    if ( Block )
    {
      UFG::qPrintChannel::Print(
        &UFG::VRAMChannel,
        OUTPUT_LEVEL_NORMAL,
        "[VRAM Channel] -   handle(%p) at memory location %p locked\n");
      Block->mFlags |= 0x20u;
      if ( (Block->mFlags & 0x40) != 0 )
      {
        UFG::qPrintChannel::Print(
          &UFG::VRAMChannel,
          OUTPUT_LEVEL_WARNING,
          "[VRAM Channel] -   handle(%p) at memory location %p was pending move, flagging to discard move\n");
        Block->mFlags |= 0x80u;
      }
      v4 = 1;
    }
  }
LABEL_11:
  UFG::qVRAMemoryPool::AssertValid(this);
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mPoolLock);
  return v4;
}

// File Line: 1504
// RVA: 0x17F380
__int64 __fastcall UFG::qVRAMemoryPool::Unlock(UFG::qVRAMemoryPool *this, UFG::qVRAMemoryHandle *handle)
{
  unsigned __int8 v4; // si
  unsigned __int16 mNumBlocksTotal; // ax
  unsigned __int16 mBlockID; // cx
  UFG::BlockInfo *Block; // rax

  UFG::qPrintChannel::Print(&UFG::VRAMChannel, OUTPUT_LEVEL_WARNING, "[VRAM Channel] - %.64s->Unlock(handle(%p))\n");
  v4 = 0;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mPoolLock);
  UFG::qVRAMemoryPool::AssertValid(this);
  if ( this->mInitialized == 1 && (handle->mReadOnlyAndPoolID & 0x7FFF) == this->mPoolID )
  {
    mNumBlocksTotal = this->mNumBlocksTotal;
    mBlockID = handle->mBlockID;
    if ( mNumBlocksTotal )
    {
      if ( mBlockID >= mNumBlocksTotal )
        goto LABEL_9;
      Block = &this->mBlocks[(unsigned __int64)mBlockID];
    }
    else
    {
      Block = UFG::qVRAMemoryPools::GetBlock(mBlockID);
    }
    if ( Block )
    {
      Block->mFlags &= ~0x20u;
      v4 = 1;
    }
  }
LABEL_9:
  UFG::qVRAMemoryPool::AssertValid(this);
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mPoolLock);
  return v4;
}

// File Line: 1533
// RVA: 0x1720C0
__int64 __fastcall UFG::qVRAMemoryPool::GetRequestedSize(UFG::qVRAMemoryPool *this, UFG::qVRAMemoryHandle *handle)
{
  unsigned int mRequestedSize; // edi
  unsigned __int16 mNumBlocksTotal; // ax
  unsigned __int16 mBlockID; // cx
  UFG::BlockInfo *Block; // rax

  mRequestedSize = 0;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mPoolLock);
  UFG::qVRAMemoryPool::AssertValid(this);
  if ( this->mInitialized == 1 && (handle->mReadOnlyAndPoolID & 0x7FFF) == this->mPoolID )
  {
    mNumBlocksTotal = this->mNumBlocksTotal;
    mBlockID = handle->mBlockID;
    if ( mNumBlocksTotal )
    {
      if ( mBlockID >= mNumBlocksTotal )
        goto LABEL_9;
      Block = &this->mBlocks[(unsigned __int64)mBlockID];
    }
    else
    {
      Block = UFG::qVRAMemoryPools::GetBlock(mBlockID);
    }
    if ( Block )
      mRequestedSize = Block->mRequestedSize;
  }
LABEL_9:
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mPoolLock);
  return mRequestedSize;
}

// File Line: 1556
// RVA: 0x16F2F0
__int64 __fastcall UFG::qVRAMemoryPool::GetAllocatedSize(UFG::qVRAMemoryPool *this, UFG::qVRAMemoryHandle *handle)
{
  unsigned int mActualSize; // edi
  unsigned __int16 mNumBlocksTotal; // ax
  unsigned __int16 mBlockID; // cx
  UFG::BlockInfo *Block; // rax

  mActualSize = 0;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mPoolLock);
  UFG::qVRAMemoryPool::AssertValid(this);
  if ( this->mInitialized == 1 && (handle->mReadOnlyAndPoolID & 0x7FFF) == this->mPoolID )
  {
    mNumBlocksTotal = this->mNumBlocksTotal;
    mBlockID = handle->mBlockID;
    if ( mNumBlocksTotal )
    {
      if ( mBlockID >= mNumBlocksTotal )
        goto LABEL_9;
      Block = &this->mBlocks[(unsigned __int64)mBlockID];
    }
    else
    {
      Block = UFG::qVRAMemoryPools::GetBlock(mBlockID);
    }
    if ( Block )
      mActualSize = Block->mActualSize;
  }
LABEL_9:
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mPoolLock);
  return mActualSize;
}

// File Line: 1681
// RVA: 0x17CC20
void __fastcall UFG::qVRAMemoryPool::SetCanDefrag(UFG::qVRAMemoryPool *this, char can_defrag)
{
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mPoolLock);
  this->mDefragAllowed = can_defrag != 0;
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mPoolLock);
}

// File Line: 1752
// RVA: 0x1676D0
void __fastcall UFG::qVRAMemoryPool::AssertValid(UFG::qVRAMemoryPool *this)
{
  if ( this->mValidate )
  {
    UFG::qPrintChannel::Print(&UFG::VRAMChannel, OUTPUT_LEVEL_WARNING, "[VRAM Channel] - %.64s->AssertValid()\n");
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mPoolLock);
    if ( this->mInitialized == 1 )
      UFG::qVRAMemoryPool::AssertValidInitialized(this);
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mPoolLock);
  }
}

// File Line: 1773
// RVA: 0x178DC0
void __fastcall UFG::qVRAMemoryPool::Print(UFG::qVRAMemoryPool *this, char print_flags)
{
  _RTL_CRITICAL_SECTION *p_mPoolLock; // r15
  UFG::qVRAMemoryPool *mOverflowVRAM; // rax
  UFG::qMemoryPool *mOverflowMain; // rdx
  UFG::qMemoryPool *mMainMemoryPool; // rdx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *i; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *j; // rax
  UFG::qList<UFG::BlockInfo,UFG::Secondary,1,0> *p_mMoveTargetsList; // rbp
  bool v11; // si
  UFG::BlockInfo *k; // rbx
  UFG::BlockInfo *mNext; // rbx
  bool m; // si
  UFG::BlockInfo *n; // rbx
  unsigned __int16 v16; // si
  unsigned __int16 mBlockID; // bp
  unsigned __int16 v18; // r14
  unsigned __int16 mNumBlocksTotal; // ax
  UFG::BlockInfo *v20; // rbx
  unsigned __int8 mUsage; // al
  const char *v22; // r10
  unsigned __int16 v23; // ax
  int v24; // ecx
  int v25; // ebx
  __int64 v26; // [rsp+20h] [rbp-58h]
  __int64 v27; // [rsp+28h] [rbp-50h]
  __int64 v28; // [rsp+30h] [rbp-48h]

  p_mPoolLock = (_RTL_CRITICAL_SECTION *)&this->mPoolLock;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mPoolLock);
  UFG::qVRAMemoryPool::AssertValid(this);
  UFG::qPrintf("Summary of Pool %u %s\n", this->mPoolID, this->mName);
  if ( (print_flags & 1) != 0 )
  {
    mOverflowVRAM = this->mOverflowVRAM;
    if ( mOverflowVRAM )
      UFG::qPrintf("  Overflow qVRAMemoryPool ID:%u %s\n", mOverflowVRAM->mPoolID, mOverflowVRAM->mName);
    mOverflowMain = this->mOverflowMain;
    if ( mOverflowMain )
      UFG::qPrintf("  Overflow qMemoryPool %s\n", mOverflowMain->mData->mAllocator.mName);
    mMainMemoryPool = this->mMainMemoryPool;
    if ( mMainMemoryPool )
      UFG::qPrintf("  Main Memory Allocations qMemoryPool %s\n", mMainMemoryPool->mData->mAllocator.mName);
    if ( this->mPoolMemory.mData )
      UFG::qPrintf(
        "  Parent qVRAMemoryPool ID:%u %s\n",
        this->mPoolMemory.mReadOnlyAndPoolID & 0x7FFF,
        UFG::qVRAMemoryPools::sVRAMemoryPools[this->mPoolMemory.mReadOnlyAndPoolID & 0x7FFF]->mName);
    UFG::qPrintf("  Memory Range: %p - %p\n", this->mVRAMemoryStart, &this->mVRAMemoryStart[this->mVRAMemorySize - 1]);
    for ( i = this->mContainerList.mNode.mNext - 1;
          i != (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)&this->mMoveTargetsList;
          i = i[1].mNext - 1 )
    {
      for ( j = i[6].mPrev; j != (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)&i[5].mNext; j = j->mNext )
        ;
    }
  }
  if ( (print_flags & 2) != 0 )
  {
    p_mMoveTargetsList = &this->mMoveTargetsList;
    v11 = (print_flags & 8) != 0;
    if ( (print_flags & 4) != 0 )
      v11 = 0;
    for ( k = (UFG::BlockInfo *)&this->mContainerList.mNode.mNext[-1];
          k != (UFG::BlockInfo *)p_mMoveTargetsList;
          k = (UFG::BlockInfo *)&k->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mNext[-1] )
    {
      UFG::BlockInfo::Print(k, v11);
    }
  }
  if ( (print_flags & 4) != 0 )
  {
    mNext = (UFG::BlockInfo *)this->mUsedBlocks.mNode.mNext;
    for ( m = (print_flags & 8) != 0;
          mNext != (UFG::BlockInfo *)&this->mUsedBlocks;
          mNext = (UFG::BlockInfo *)mNext->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mNext )
    {
      UFG::BlockInfo::Print(mNext, m);
    }
    for ( n = (UFG::BlockInfo *)this->mMainMemoryBlocks.mNode.mNext;
          n != (UFG::BlockInfo *)&this->mMainMemoryBlocks;
          n = (UFG::BlockInfo *)n->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mNext )
    {
      UFG::BlockInfo::Print(n, m);
    }
  }
  if ( (print_flags & 0x10) == 0 )
    goto LABEL_57;
  v16 = 0;
  mBlockID = -1;
  v18 = -1;
  if ( !this->mUsedBlocksMax )
    goto LABEL_51;
  do
  {
    mNumBlocksTotal = this->mNumBlocksTotal;
    if ( mNumBlocksTotal )
    {
      if ( v16 >= mNumBlocksTotal )
        goto LABEL_49;
      v20 = &this->mBlocks[(unsigned __int64)v16];
    }
    else
    {
      v20 = 0i64;
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMBlocksLock);
      if ( UFG::qVRAMemoryPools::sNumBlocksTotal && v16 < UFG::qVRAMemoryPools::sNumBlocksTotal )
        v20 = &UFG::qVRAMemoryPools::sBlocks[(unsigned __int64)v16];
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMBlocksLock);
    }
    if ( v20 )
    {
      if ( v20->mUsage )
      {
        if ( mBlockID != 0xFFFF )
        {
          if ( mBlockID == v18 )
            UFG::qPrintf(
              "    BlockID  :%05u                                                                               type(%*s)\n",
              mBlockID,
              21,
              off_14203C490[0]);
          else
            UFG::qPrintf(
              "    BlockID  :%05u - %05u                                                                       type(%*s)\n",
              mBlockID,
              v18,
              21,
              off_14203C490[0]);
          mBlockID = -1;
          v18 = -1;
        }
        mUsage = v20->mUsage;
        if ( mUsage == 11 )
        {
          LODWORD(v28) = 21;
          LODWORD(v27) = v20->mActualSize;
          LODWORD(v26) = v20->mRequestedSize;
          UFG::qPrintf(
            "      BlockID:%05u [%p - %p] %9u bytes requested %9u bytes allocated type(%*s) name:(%.64s)\n",
            v20->mBlockID,
            v20->mData,
            &v20->mData[(unsigned int)v26 - 1],
            v26,
            v27,
            v28,
            off_14203C4E8[0],
            v20->mName);
        }
        else
        {
          if ( mUsage > 0x12u )
            v22 = "Unknown VRAMType";
          else
            v22 = off_14203C490[mUsage];
          LODWORD(v28) = 21;
          LODWORD(v27) = v20->mActualSize;
          LODWORD(v26) = v20->mRequestedSize;
          UFG::qPrintf(
            "    BlockID  :%05u [%p - %p] %9u bytes requested %9u bytes allocated type(%*s) name:(%.64s)\n",
            v20->mBlockID,
            v20->mData,
            &v20->mData[(unsigned int)v27 - 1],
            v26,
            v27,
            v28,
            v22,
            v20->mName);
        }
      }
      else
      {
        if ( mBlockID == 0xFFFF )
          mBlockID = v20->mBlockID;
        v18 = v20->mBlockID;
      }
    }
LABEL_49:
    ++v16;
  }
  while ( v16 < this->mUsedBlocksMax );
  p_mPoolLock = (_RTL_CRITICAL_SECTION *)&this->mPoolLock;
LABEL_51:
  v23 = this->mNumBlocksTotal;
  if ( v23 )
  {
    v24 = v23;
  }
  else
  {
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMBlocksLock);
    v25 = UFG::qVRAMemoryPools::sNumBlocksTotal;
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMBlocksLock);
    v24 = v25;
  }
  if ( this->mUsedBlocksMax != v24 && !this->mNumBlocksTotal )
  {
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMBlocksLock);
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMBlocksLock);
  }
LABEL_57:
  UFG::qMutex::Unlock(p_mPoolLock);
}

// File Line: 1901
// RVA: 0x1696E0
char __fastcall UFG::qVRAMemoryPool::CommonInit(
        UFG::qVRAMemoryPool *this,
        const char *name,
        unsigned __int16 num_blocks,
        unsigned int min_alignment,
        char *block_memory,
        unsigned int block_memory_size)
{
  unsigned __int64 v10; // rsi
  bool v11; // cf
  unsigned __int64 v12; // rsi
  UFG::qMemoryPool *v13; // rcx
  UFG::allocator::free_link *v14; // rax
  UFG::BlockInfo *v15; // rsi
  unsigned __int16 i; // dx
  UFG::BlockInfo *v17; // rcx
  unsigned __int16 v18; // dx
  UFG::qList<UFG::BlockInfo,UFG::Primary,1,0> *p_mUnusedBlocks; // r8
  UFG::BlockInfo *v20; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *mPrev; // rax
  unsigned __int16 v22; // cx
  unsigned int mVRAMemorySize; // eax
  int v24; // edx
  char *mName; // rcx
  const char *v26; // rdi
  char v27; // al
  UFG::BlockInfo *UnusedBlock; // rsi
  unsigned int v29; // edi
  char *mVRAMemoryStart; // rbx
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v31; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v32; // rax

  if ( num_blocks )
  {
    if ( block_memory )
    {
      this->mBlocks = (UFG::BlockInfo *)block_memory;
      this->mBlocksMemory = block_memory;
      this->mBlocksMemorySize = block_memory_size;
      for ( i = 0; i < num_blocks; ++i )
      {
        v17 = &this->mBlocks[(unsigned __int64)i];
        if ( v17 )
        {
          v17->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mPrev = v17;
          v17->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mNext = v17;
          v17->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mPrev = &v17->UFG::qNode<UFG::BlockInfo,UFG::Secondary>;
          v17->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mNext = &v17->UFG::qNode<UFG::BlockInfo,UFG::Secondary>;
          v17->mAllocationHandles.mNode.mPrev = &v17->mAllocationHandles.mNode;
          v17->mAllocationHandles.mNode.mNext = &v17->mAllocationHandles.mNode;
          v17->mData = 0i64;
          v17->mName = 0i64;
          *(_QWORD *)&v17->mRequestedSize = 0i64;
          *(_DWORD *)&v17->mBlockID = 0xFFFF;
          *(_WORD *)&v17->mKeepAliveFrames = 0;
          v17->mMemoryPool = 0i64;
          v17->mContainedBlocks.mNode.mPrev = &v17->mContainedBlocks.mNode;
          v17->mContainedBlocks.mNode.mNext = &v17->mContainedBlocks.mNode;
          *(_DWORD *)&v17->mContainerID = -1;
          v17->mCallbackData64 = 0i64;
          v17->mCallbackData32 = 0;
        }
      }
    }
    else
    {
      v10 = (unsigned __int64)num_blocks << 7;
      if ( !is_mul_ok(num_blocks, 0x80ui64) )
        v10 = -1i64;
      v11 = __CFADD__(v10, 8i64);
      v12 = v10 + 8;
      if ( v11 )
        v12 = -1i64;
      v13 = UFG::gMainMemoryPool;
      if ( !UFG::gMainMemoryPool )
      {
        UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
        v13 = UFG::gMainMemoryPool;
      }
      v14 = UFG::qMemoryPool::Allocate(v13, v12, "qVRAMemoryPool::mBlocks", 0i64, 1u);
      if ( v14 )
      {
        LODWORD(v14->mNext) = num_blocks;
        v15 = (UFG::BlockInfo *)&v14[1];
        `eh vector constructor iterator(
          &v14[1],
          0x80ui64,
          num_blocks,
          (void (__fastcall *)(void *))UFG::BlockInfo::BlockInfo);
      }
      else
      {
        v15 = 0i64;
      }
      this->mBlocks = v15;
      this->mBlocksMemory = 0i64;
      this->mBlocksMemorySize = 0;
    }
  }
  this->mNumBlocksTotal = num_blocks;
  this->mMinAlignment = min_alignment;
  this->mOverflowVRAM = 0i64;
  this->mOverflowMain = 0i64;
  v18 = 0;
  if ( num_blocks )
  {
    p_mUnusedBlocks = &this->mUnusedBlocks;
    do
    {
      v20 = &this->mBlocks[(unsigned __int64)v18];
      v20->mBlockID = v18;
      mPrev = p_mUnusedBlocks->mNode.mPrev;
      mPrev->mNext = v20;
      v20->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mPrev = mPrev;
      v20->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mNext = &p_mUnusedBlocks->mNode;
      p_mUnusedBlocks->mNode.mPrev = v20;
      ++v18;
    }
    while ( v18 < this->mNumBlocksTotal );
  }
  v22 = 0;
  while ( UFG::qVRAMemoryPools::sVRAMemoryPools[v22] )
  {
    if ( ++v22 >= 0x10u )
      return 0;
  }
  this->mPoolID = v22;
  UFG::qVRAMemoryPools::sVRAMemoryPools[v22] = this;
  mVRAMemorySize = this->mVRAMemorySize;
  this->mFreeMemory = mVRAMemorySize;
  this->mLargestFreeBlock = mVRAMemorySize;
  *(_QWORD *)&this->mUsedMemory = 0i64;
  *(_QWORD *)&this->mAllocatedMemory = 0i64;
  *(_QWORD *)&this->mUsedMainMemory = 0i64;
  *(_DWORD *)&this->mAllocatedBlocksCount = 0;
  v24 = 32;
  mName = this->mName;
  if ( this != (UFG::qVRAMemoryPool *)-312i64 )
  {
    if ( !name )
      goto LABEL_30;
    v26 = (const char *)(name - mName);
    do
    {
      v27 = mName[(_QWORD)v26];
      *mName++ = v27;
      if ( !v27 )
        break;
      --v24;
    }
    while ( v24 > 1 );
    if ( *(mName - 1) )
LABEL_30:
      *mName = 0;
  }
  *(_WORD *)&this->mNeedsDefragmentUp = 0;
  UnusedBlock = UFG::qVRAMemoryPool::GetUnusedBlock(this);
  v29 = this->mVRAMemorySize;
  mVRAMemoryStart = this->mVRAMemoryStart;
  UFG::qPrintChannel::Print(
    &UFG::VRAMChannel,
    OUTPUT_LEVEL_DEBUG,
    "[VRAM Channel] - Setting Block ID:0x%04x to free data:%p size:0x%08x (%9u)\n");
  UnusedBlock->mData = mVRAMemoryStart;
  UnusedBlock->mName = "Free VRAM";
  UnusedBlock->mRequestedSize = v29;
  UnusedBlock->mActualSize = v29;
  *(_DWORD *)&UnusedBlock->mUsage = 1;
  UnusedBlock->mMemoryPool = 0i64;
  UnusedBlock->mContainerID = 0;
  UnusedBlock->mCallbackData64 = 0i64;
  UnusedBlock->mCallbackData32 = 0;
  v31 = this->mUsedBlocks.mNode.mPrev;
  v31->mNext = UnusedBlock;
  UnusedBlock->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mPrev = v31;
  UnusedBlock->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mNext = &this->mUsedBlocks.mNode;
  this->mUsedBlocks.mNode.mPrev = UnusedBlock;
  v32 = this->mFreeList.mNode.mPrev;
  v32->mNext = &UnusedBlock->UFG::qNode<UFG::BlockInfo,UFG::Secondary>;
  UnusedBlock->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mPrev = v32;
  UnusedBlock->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mNext = &this->mFreeList.mNode;
  this->mFreeList.mNode.mPrev = &UnusedBlock->UFG::qNode<UFG::BlockInfo,UFG::Secondary>;
  this->mInitialized = 1;
  return 1;
}

// File Line: 1993
// RVA: 0x16FF90
__int64 __fastcall UFG::qVRAMemoryPool::GetDefragmentMoves(
        UFG::qVRAMemoryPool *this,
        UFG::qVRAMemoryMoveOrder *moves,
        int moves_count,
        unsigned int requested_total_bytes,
        unsigned int *total_bytes)
{
  UFG::qVRAMemoryMoveOrder *v5; // rbp
  unsigned int v6; // esi
  int v7; // edi
  UFG::qPrintChannel::OutputLevel v9; // edx
  int v10; // r13d
  _RTL_CRITICAL_SECTION *p_mPoolLock; // r12
  char v12; // al
  unsigned int *v13; // r14
  unsigned int v14; // eax
  unsigned int v15; // r8d
  UFG::qVRAMemoryMoveOrder *v16; // r12
  __int64 v17; // r15
  bool found_move_too_large; // [rsp+50h] [rbp-58h] BYREF
  char **p_mData; // [rsp+58h] [rbp-50h]
  char v21; // [rsp+B0h] [rbp+8h]

  v5 = moves;
  v6 = requested_total_bytes;
  v7 = moves_count;
  v9 = OUTPUT_LEVEL_DEBUG;
  if ( v5
    && moves_count > 0
    && (unsigned __int8)this->mNeedsDefragmentUp + (unsigned __int8)this->mNeedsDefragmentDown > 0 )
  {
    v9 = OUTPUT_LEVEL_WARNING;
  }
  UFG::qPrintChannel::Print(&UFG::VRAMChannel, v9, "[VRAM Channel] - %.64s->GetDefragmentMoves(%p, %u)\n");
  v10 = 0;
  if ( v5 && v7 > 0 )
  {
    p_mPoolLock = (_RTL_CRITICAL_SECTION *)&this->mPoolLock;
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mPoolLock);
    UFG::qVRAMemoryPool::AssertValid(this);
    if ( this->mDefragAllowed == 1
      && (unsigned __int8)this->mNeedsDefragmentUp + (unsigned __int8)this->mNeedsDefragmentDown > 0 )
    {
      v12 = 0;
      v21 = 0;
      v13 = total_bytes;
      p_mData = &v5->mTargetHandle.mData;
      do
      {
        if ( v12 )
          break;
        v14 = *v13;
        if ( *v13 >= v6 )
          break;
        v15 = v14 ? v6 - v14 : -1;
        found_move_too_large = 0;
        v16 = &v5[(__int64)v10];
        if ( (unsigned __int8)UFG::qVRAMemoryPool::GetDefragmentMove(this, v16, v15, &found_move_too_large) == 1 )
        {
          UFG::qVRAMemoryPools::GetAllocatedSize(&v16->mTargetHandle);
          UFG::qVRAMemoryPools::GetAllocatedSize(&v16->mSourceHandle);
          v17 = (__int64)p_mData;
          UFG::qPrintChannel::Print(
            &UFG::VRAMChannel,
            OUTPUT_LEVEL_DEBUG,
            "[VRAM Channel]    - Found Move [%04u]%p-%p to [%04u]%p-%p\n");
          v7 = moves_count;
          *total_bytes += UFG::qVRAMemoryPools::GetAllocatedSize(&v16->mSourceHandle);
          v6 = requested_total_bytes;
          v5 = moves;
          v12 = v21;
          ++v10;
          p_mData = (char **)(v17 + 64);
          v13 = total_bytes;
        }
        else
        {
          v12 = 1;
          v21 = 1;
          if ( !found_move_too_large )
            *(_WORD *)&this->mNeedsDefragmentUp = 0;
        }
      }
      while ( v10 < v7 );
      p_mPoolLock = (_RTL_CRITICAL_SECTION *)&this->mPoolLock;
    }
    UFG::qVRAMemoryPool::AssertValid(this);
    UFG::qMutex::Unlock(p_mPoolLock);
  }
  return (unsigned int)v10;
}

// File Line: 2062
// RVA: 0x16FB00
__int64 __fastcall UFG::qVRAMemoryPool::GetDefragmentMove(
        UFG::qVRAMemoryPool *this,
        UFG::qVRAMemoryMoveOrder *move,
        unsigned int allowable_bytes,
        bool *found_move_too_large)
{
  unsigned __int8 v4; // si
  bool *v5; // rbx
  unsigned int v6; // edi
  UFG::qVRAMemoryMoveOrder *v7; // r14
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v9; // r12
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v10; // rbp
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *mPrev; // r8
  unsigned int v12; // r10d
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v13; // r15
  unsigned int v14; // r11d
  char v15; // al
  unsigned int mPrev_high; // eax
  unsigned int v17; // r9d
  unsigned int v18; // r8d
  unsigned __int16 mNumBlocksTotal; // dx
  unsigned __int16 mBlockID; // ax
  UFG::BlockInfo *Block; // rcx
  UFG::qVRAMemoryHandle *p_mSourceHandle; // r14
  char *v23; // rbx
  unsigned __int16 mNext; // si
  unsigned __int16 mPoolID; // di
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v26; // rcx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v27; // rax
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v28; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *i; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v30; // rax
  unsigned int v31; // ebx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v32; // rbp
  unsigned int v33; // edi
  char v34; // cl
  __int64 v35; // r9
  __int64 v36; // r10
  unsigned int v37; // r11d
  unsigned __int64 v38; // r10
  unsigned __int64 v39; // rcx
  unsigned int v40; // r10d
  unsigned int v41; // r8d
  char *v42; // rbx
  unsigned __int16 v43; // si
  unsigned __int16 v44; // di
  UFG::qVRAMemoryHandle *v45; // r14
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v46; // rcx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v47; // rax
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v48; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v50; // [rsp+A0h] [rbp+8h]

  v4 = 0;
  v5 = found_move_too_large;
  v6 = allowable_bytes;
  v7 = move;
  if ( (UFG::qList<UFG::BlockInfo,UFG::Primary,1,0> *)&this->mFreeList.mNode.mNext[-1] == &this->mUsedBlocks )
    return 0i64;
  v9 = this->mFreeList.mNode.mPrev - 1;
  v50 = this->mFreeList.mNode.mNext - 1;
  if ( v50 != v9 )
  {
    v10 = this->mFreeList.mNode.mNext - 1;
    do
    {
      if ( v4 || *v5 )
        break;
      mPrev = v9->mPrev;
      v12 = -1;
      v13 = 0i64;
      v14 = -1;
      if ( v9->mPrev != v10 )
      {
        do
        {
          v15 = BYTE3(mPrev[4].mNext);
          if ( (v15 & 4) != 0 && (v15 & 0x40) == 0 && (v15 & 0x20) == 0 && !BYTE4(mPrev[4].mNext) && (v15 & 1) != 0 )
          {
            mPrev_high = HIDWORD(mPrev[4].mPrev);
            v17 = (~((1 << BYTE5(mPrev[4].mNext)) - 1) & (LODWORD(v10[3].mPrev) + (1 << BYTE5(mPrev[4].mNext)) - 1))
                - LODWORD(v10[3].mPrev);
            if ( HIDWORD(v10[4].mPrev) - v17 >= mPrev_high )
            {
              if ( v17 < v12 || v17 == v12 && HIDWORD(v10[4].mPrev) - mPrev_high < v14 )
              {
                v14 = HIDWORD(v10[4].mPrev) - mPrev_high;
                v12 = (~((1 << BYTE5(mPrev[4].mNext)) - 1) & (LODWORD(v10[3].mPrev) + (1 << BYTE5(mPrev[4].mNext)) - 1))
                    - LODWORD(v10[3].mPrev);
                v13 = mPrev;
              }
              if ( !v12 && !v14 )
                break;
            }
          }
          mPrev = mPrev->mPrev;
        }
        while ( mPrev != v10 );
        if ( v13 )
        {
          v18 = HIDWORD(v13[4].mPrev);
          if ( v18 >= v6 )
          {
            *v5 = 1;
          }
          else
          {
            UFG::qVRAMemoryPool::Allocate(
              this,
              &v7->mTargetHandle,
              v18,
              0x10u,
              "Move Target",
              1 << BYTE5(v13[4].mNext),
              1u,
              0i64,
              0i64,
              0);
            mNumBlocksTotal = this->mNumBlocksTotal;
            mBlockID = v7->mTargetHandle.mBlockID;
            Block = 0i64;
            if ( mNumBlocksTotal )
            {
              if ( mBlockID < mNumBlocksTotal )
                Block = &this->mBlocks[(unsigned __int64)mBlockID];
            }
            else
            {
              Block = UFG::qVRAMemoryPools::GetBlock(mBlockID);
            }
            p_mSourceHandle = &v7->mSourceHandle;
            Block->mMoveSourceID = (unsigned __int16)v13[4].mNext;
            v23 = (char *)v13[3].mPrev;
            mNext = (unsigned __int16)v13[4].mNext;
            mPoolID = this->mPoolID;
            UFG::qPrintChannel::Print(
              &UFG::VRAMChannel,
              OUTPUT_LEVEL_DEBUG,
              "[VRAM Channel] - Setting qVRAMemoryHandle(%p) to point at - PoolID:0x%02x BlockID:0x%04x Data:%p-%p AllocatedSize:%u\n");
            v26 = p_mSourceHandle->mPrev;
            v27 = p_mSourceHandle->mNext;
            v26->mNext = v27;
            v27->mPrev = v26;
            p_mSourceHandle->mData = v23;
            v5 = found_move_too_large;
            p_mSourceHandle->mReadOnlyAndPoolID = mPoolID;
            v6 = allowable_bytes;
            p_mSourceHandle->mBlockID = mNext;
            p_mSourceHandle->mPrev = p_mSourceHandle;
            p_mSourceHandle->mNext = p_mSourceHandle;
            v28 = (UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *)v13[2].mPrev;
            v4 = 1;
            v28->mNext = p_mSourceHandle;
            p_mSourceHandle->mPrev = v28;
            p_mSourceHandle->mNext = (UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *)&v13[2];
            v13[2].mPrev = (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)p_mSourceHandle;
            BYTE3(v13[4].mNext) |= 0x40u;
            v7 = move;
          }
        }
      }
      v10 = v10[1].mNext - 1;
    }
    while ( v10 != v9 );
    for ( i = v50; v9 != v50; v9 = v9[1].mPrev - 1 )
    {
      if ( v4 )
        break;
      v30 = i->mNext;
      v31 = -1;
      v32 = 0i64;
      v33 = -1;
      if ( v30 != v9 )
      {
        do
        {
          v34 = BYTE3(v30[4].mNext);
          if ( (v34 & 4) != 0 && (v34 & 0x40) == 0 && (v34 & 0x20) == 0 && !BYTE4(v30[4].mNext) && (v34 & 2) != 0 )
          {
            v35 = HIDWORD(v30[4].mPrev);
            v36 = HIDWORD(v9[4].mPrev);
            v37 = v36 - v35;
            v38 = (unsigned __int64)v9[3].mPrev + v36 - v35;
            v39 = v38 & ~((1 << BYTE5(v30[4].mNext)) - 1i64);
            v40 = v38 - v39;
            if ( v9[3].mPrev <= (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)v39 )
            {
              if ( v40 < v31 || v40 == v31 && v37 < v33 )
              {
                v33 = v37;
                v31 = v40;
                v32 = v30;
              }
              if ( !v31 && !v33 )
                break;
            }
          }
          v30 = v30->mNext;
        }
        while ( v30 != v9 );
        if ( v32 )
        {
          v41 = HIDWORD(v32[4].mPrev);
          if ( v41 >= allowable_bytes )
          {
            *found_move_too_large = 1;
          }
          else
          {
            UFG::qVRAMemoryPool::Allocate(
              this,
              &v7->mTargetHandle,
              v41,
              0x10u,
              "Move Target",
              1 << BYTE5(v32[4].mNext),
              2u,
              0i64,
              0i64,
              0);
            v42 = (char *)v32[3].mPrev;
            v43 = (unsigned __int16)v32[4].mNext;
            v44 = this->mPoolID;
            v45 = &v7->mSourceHandle;
            UFG::qPrintChannel::Print(
              &UFG::VRAMChannel,
              OUTPUT_LEVEL_DEBUG,
              "[VRAM Channel] - Setting qVRAMemoryHandle(%p) to point at - PoolID:0x%02x BlockID:0x%04x Data:%p-%p AllocatedSize:%u\n");
            v46 = v45->mPrev;
            v47 = v45->mNext;
            v46->mNext = v47;
            v47->mPrev = v46;
            v45->mBlockID = v43;
            v45->mPrev = v45;
            v45->mNext = v45;
            v45->mData = v42;
            v45->mReadOnlyAndPoolID = v44;
            v48 = (UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *)v32[2].mPrev;
            v48->mNext = v45;
            v45->mPrev = v48;
            v45->mNext = (UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *)&v32[2];
            v32[2].mPrev = (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)v45;
            BYTE3(v32[4].mNext) |= 0x40u;
            v4 = 1;
          }
        }
      }
      i = v50;
      v7 = move;
    }
    if ( v4 == 1 )
    {
      move->mSourceHandle.mReadOnlyAndPoolID |= 0x8000u;
      move->mTargetHandle.mReadOnlyAndPoolID |= 0x8000u;
    }
  }
  return v4;
}

// File Line: 2243
// RVA: 0x177C10
void __fastcall UFG::qVRAMemoryPool::MoveCompleted(
        UFG::qVRAMemoryPool *this,
        UFG::qVRAMemoryMoveOrder *move,
        void (__fastcall *callback)(UFG::qVRAMemoryHandle *, char *, UFG::VRAMType, unsigned __int64, unsigned int))
{
  unsigned __int16 mBlockID; // cx
  UFG::BlockInfo *Block; // rsi
  unsigned __int16 mNumBlocksTotal; // ax
  unsigned __int16 v9; // cx
  UFG::BlockInfo *v10; // rbx
  unsigned __int16 v11; // ax
  char *mData; // r15
  char *v13; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *mPrev; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *mNext; // rax
  __int64 *v16; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v17; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v18; // rax
  __int64 *v19; // rax
  _QWORD *v20; // rax
  UFG::BlockInfo *i; // rbx
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v22; // rdi
  UFG::qList<UFG::BlockInfo,UFG::Primary,1,0> *j; // rax
  UFG::qVRAMemoryHandle *v24; // rbx
  UFG::BlockInfo *k; // rbx
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v26; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v27; // rax
  __int64 *v28; // rcx
  UFG::BlockInfo *v29; // rax
  UFG::qVRAMemoryHandle *m; // rbx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v31; // rcx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v32; // rax
  __int64 *v33; // rcx
  UFG::qVRAMemoryHandle *v34; // rax
  __int64 *v35; // rcx
  __int64 **v36; // rax
  __int64 *v37; // rcx
  __int64 **v38; // rax
  _RTL_CRITICAL_SECTION *p_mPoolLock; // rbx
  __int64 v40; // [rsp+20h] [rbp-79h]
  void (__fastcall *v41)(UFG::qVRAMemoryHandle *, char *, UFG::VRAMType, unsigned __int64, unsigned int); // [rsp+28h] [rbp-71h]
  __int64 *v42; // [rsp+30h] [rbp-69h] BYREF
  __int64 **v43; // [rsp+38h] [rbp-61h]
  __int64 *v44; // [rsp+40h] [rbp-59h] BYREF
  __int64 **v45; // [rsp+48h] [rbp-51h]
  __int64 *v46; // [rsp+50h] [rbp-49h] BYREF
  UFG::qVRAMemoryHandle *v47; // [rsp+58h] [rbp-41h]
  __int128 v48; // [rsp+60h] [rbp-39h]
  __int64 v49; // [rsp+70h] [rbp-29h]
  int v50; // [rsp+78h] [rbp-21h]
  __int16 v51; // [rsp+7Ch] [rbp-1Dh]
  __int64 v52; // [rsp+80h] [rbp-19h]
  __int64 *v53; // [rsp+88h] [rbp-11h] BYREF
  UFG::BlockInfo *v54; // [rsp+90h] [rbp-9h]
  int v55; // [rsp+98h] [rbp-1h]
  __int64 v56; // [rsp+A0h] [rbp+7h]
  int v57; // [rsp+A8h] [rbp+Fh]
  __int64 v58; // [rsp+B0h] [rbp+17h]
  char *new_location; // [rsp+100h] [rbp+67h]

  v58 = -2i64;
  v41 = callback;
  UFG::qPrintChannel::Print(
    &UFG::VRAMChannel,
    OUTPUT_LEVEL_WARNING,
    "[VRAM Channel] - %.64s->MoveCompleted(%p, %p)\n");
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mPoolLock);
  UFG::qVRAMemoryPool::AssertValid(this);
  move->mSourceHandle.mReadOnlyAndPoolID &= ~0x8000u;
  move->mTargetHandle.mReadOnlyAndPoolID &= ~0x8000u;
  mBlockID = move->mSourceHandle.mBlockID;
  Block = 0i64;
  mNumBlocksTotal = this->mNumBlocksTotal;
  if ( mNumBlocksTotal )
  {
    if ( mBlockID < mNumBlocksTotal )
      Block = &this->mBlocks[(unsigned __int64)mBlockID];
  }
  else
  {
    Block = UFG::qVRAMemoryPools::GetBlock(mBlockID);
  }
  v9 = move->mTargetHandle.mBlockID;
  v10 = 0i64;
  v11 = this->mNumBlocksTotal;
  if ( v11 )
  {
    if ( v9 < v11 )
      v10 = &this->mBlocks[(unsigned __int64)v9];
  }
  else
  {
    v10 = UFG::qVRAMemoryPools::GetBlock(v9);
  }
  mData = Block->mData;
  v13 = v10->mData;
  new_location = v13;
  Block->mFlags &= ~0x40u;
  if ( Block->mKeepAliveFrames || Block->mFlags < 0 )
  {
    UFG::qPrintChannel::Print(
      &UFG::VRAMChannel,
      OUTPUT_LEVEL_NORMAL,
      "[VRAM Channel] -  Move cancelled by free or lock, memory moved from %p to %p\n");
    Block->mFlags &= ~0x80u;
    UFG::qVRAMemoryPool::Free(this, &move->mTargetHandle, 0);
    UFG::qVRAMemoryHandle::Close(&move->mSourceHandle);
  }
  else
  {
    HIDWORD(v40) = HIDWORD(v13);
    UFG::qPrintChannel::Print(
      &UFG::VRAMChannel,
      OUTPUT_LEVEL_NORMAL,
      "[VRAM Channel] -  Move still valid, memory moved from %p to %p\n");
    mPrev = v10->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mPrev;
    mNext = v10->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    v10->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mPrev = &v10->UFG::qNode<UFG::BlockInfo,UFG::Secondary>;
    v10->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mNext = &v10->UFG::qNode<UFG::BlockInfo,UFG::Secondary>;
    v42 = (__int64 *)&v42;
    v43 = &v42;
    v44 = (__int64 *)&v44;
    v45 = &v44;
    v46 = (__int64 *)&v46;
    v47 = (UFG::qVRAMemoryHandle *)&v46;
    v48 = 0i64;
    v49 = 0i64;
    v50 = 0xFFFF;
    v51 = 0;
    v52 = 0i64;
    v53 = (__int64 *)&v53;
    v54 = (UFG::BlockInfo *)&v53;
    v55 = -1;
    v56 = 0i64;
    v57 = 0;
    v16 = (__int64 *)v10->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mPrev;
    v16[1] = (__int64)&v42;
    v42 = v16;
    v43 = (__int64 **)v10;
    v43 = (__int64 **)v10->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mNext;
    *v43 = (__int64 *)&v42;
    v10->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mPrev = v10;
    v10->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mNext = v10;
    v17 = Block->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mPrev;
    v17->mNext = v10;
    v10->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mPrev = v17;
    v10->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mNext = Block;
    v18 = Block->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mNext;
    v10->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mNext = v18;
    v18->mPrev = v10;
    v19 = v42;
    v42[1] = (__int64)Block;
    Block->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mPrev = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)v19;
    v20 = v43;
    Block->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mNext = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)v43;
    *v20 = Block;
    v42 = (__int64 *)&v42;
    v43 = &v42;
    UFG::BlockInfo::DefragmentMovedTo(v10, mData);
    UFG::BlockInfo::DefragmentMovedTo(Block, new_location);
    UFG::qVRAMemoryHandle::Close(&move->mSourceHandle);
    v10->mName = "Moved Source VRAM";
    v10->mUsage = 17;
    UFG::qVRAMemoryPool::Free(this, &move->mTargetHandle, this->mDefragFreeFrameDelay);
    if ( callback )
    {
      for ( i = (UFG::BlockInfo *)Block->mAllocationHandles.mNode.mNext;
            i != (UFG::BlockInfo *)&Block->mAllocationHandles;
            i = (UFG::BlockInfo *)i->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mNext )
      {
        LODWORD(v40) = Block->mCallbackData32;
        ((void (__fastcall *)(UFG::BlockInfo *, char *, _QWORD, unsigned __int64, __int64, void (__fastcall *)(UFG::qVRAMemoryHandle *, char *, UFG::VRAMType, unsigned __int64, unsigned int)))callback)(
          i,
          mData,
          (unsigned __int8)Block->mUsage,
          Block->mCallbackData64,
          v40,
          v41);
      }
      v22 = Block->mContainedBlocks.mNode.mNext;
      for ( j = &Block->mContainedBlocks; v22 != (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)j; v22 = v22->mNext )
      {
        v24 = (UFG::qVRAMemoryHandle *)v22[2].mNext;
        if ( v24 != (UFG::qVRAMemoryHandle *)&v22[2] )
        {
          do
          {
            LODWORD(v40) = v22[7].mNext;
            callback(
              v24,
              &mData[(unsigned int)v24->mData - LODWORD(Block->mData)],
              (UFG::VRAMType)BYTE2(v22[4].mNext),
              (unsigned __int64)v22[7].mPrev,
              v40);
            v24 = (UFG::qVRAMemoryHandle *)v24->mNext;
          }
          while ( v24 != (UFG::qVRAMemoryHandle *)&v22[2] );
          j = &Block->mContainedBlocks;
        }
      }
    }
    for ( k = v54; v54 != (UFG::BlockInfo *)&v53; k = v54 )
    {
      v26 = k->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mPrev;
      v27 = k->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mNext;
      v26->mNext = v27;
      v27->mPrev = v26;
      k->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mPrev = k;
      k->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mNext = k;
      UFG::BlockInfo::~BlockInfo(k);
      UFG::qMemoryPool::Free(UFG::gMainMemoryPool, (char *)k);
    }
    v28 = v53;
    v29 = v54;
    v53[1] = (__int64)v54;
    v29->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mPrev = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)v28;
    v53 = (__int64 *)&v53;
    v54 = (UFG::BlockInfo *)&v53;
    for ( m = v47; v47 != (UFG::qVRAMemoryHandle *)&v46; m = v47 )
    {
      v31 = m->mPrev;
      v32 = m->mNext;
      v31->mNext = v32;
      v32->mPrev = v31;
      m->mPrev = m;
      m->mNext = m;
      UFG::qVRAMemoryHandle::~qVRAMemoryHandle(m);
      UFG::qMemoryPool::Free(UFG::gMainMemoryPool, (char *)m);
    }
    v33 = v46;
    v34 = v47;
    v46[1] = (__int64)v47;
    v34->mPrev = (UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *)v33;
    v46 = (__int64 *)&v46;
    v47 = (UFG::qVRAMemoryHandle *)&v46;
    v35 = v44;
    v36 = v45;
    v44[1] = (__int64)v45;
    *v36 = v35;
    v44 = (__int64 *)&v44;
    v45 = &v44;
    v37 = v42;
    v38 = v43;
    v42[1] = (__int64)v43;
    *v38 = v37;
    v42 = (__int64 *)&v42;
    v43 = &v42;
  }
  if ( this->mValidate )
  {
    UFG::qPrintChannel::Print(&UFG::VRAMChannel, OUTPUT_LEVEL_WARNING, "[VRAM Channel] - %.64s->AssertValid()\n");
    p_mPoolLock = (_RTL_CRITICAL_SECTION *)&this->mPoolLock;
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mPoolLock);
    if ( this->mInitialized == 1 )
      UFG::qVRAMemoryPool::AssertValidInitialized(this);
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mPoolLock);
  }
  else
  {
    p_mPoolLock = (_RTL_CRITICAL_SECTION *)&this->mPoolLock;
  }
  UFG::qMutex::Unlock(p_mPoolLock);
}

// File Line: 2388
// RVA: 0x17DA10
UFG::BlockInfo *__fastcall UFG::qVRAMemoryPool::SplitFreeBlock(
        UFG::qVRAMemoryPool *this,
        UFG::BlockInfo *block,
        unsigned int aligned_size,
        int alignment,
        char flags)
{
  unsigned int v5; // ebx
  UFG::qVRAMemoryPool *v7; // rdi
  unsigned int mActualSize; // ecx
  __int64 v9; // r13
  char *mData; // r8
  unsigned int v11; // ebp
  __int64 v12; // rdx
  __int64 v13; // r12
  unsigned int v14; // r12d
  char *v15; // rax
  __int64 v16; // rdx
  UFG::BlockInfo *UnusedBlock; // rax
  char *v18; // rdi
  UFG::BlockInfo *v19; // rsi
  char *v20; // rdi
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *mPrev; // rax
  char *v22; // rdi
  char *v23; // rdi
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *mNext; // rax
  UFG::BlockInfo *v25; // rax
  char *v26; // rdi
  UFG::BlockInfo *v27; // r14
  char *v28; // rdi
  char *v29; // rdi
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v30; // rdx
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v31; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v32; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v33; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v34; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v35; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v36; // rax
  __int64 i; // rdx
  bool v40; // [rsp+98h] [rbp+20h]

  v5 = 0;
  v7 = this;
  mActualSize = block->mActualSize;
  v9 = aligned_size;
  mData = block->mData;
  v11 = 0;
  v12 = ~(alignment - 1i64);
  v13 = v12 & (unsigned __int64)&mData[alignment - 1];
  v40 = mActualSize == v7->mLargestFreeBlock;
  if ( (char *)v13 == mData && (_DWORD)v9 == mActualSize )
    goto LABEL_16;
  if ( (flags & 1) == 0 )
  {
    if ( (flags & 2) != 0 )
    {
      v14 = mActualSize - v9;
      v15 = &mData[mActualSize - (unsigned int)v9];
      v16 = (unsigned __int64)v15 & v12;
      if ( (char *)v16 != v15 )
      {
        v11 = (_DWORD)v15 - v16;
        v14 = v16 - (_DWORD)mData;
      }
      goto LABEL_10;
    }
LABEL_16:
    v30 = &block->UFG::qNode<UFG::BlockInfo,UFG::Secondary>;
    goto LABEL_17;
  }
  if ( (char *)v13 == mData )
  {
    v11 = mActualSize - v9;
    goto LABEL_11;
  }
  v14 = v13 - LODWORD(block->mData);
  v11 = mActualSize - v14 - v9;
LABEL_10:
  if ( !v14 )
  {
LABEL_11:
    if ( v11 )
    {
      UnusedBlock = UFG::qVRAMemoryPool::GetUnusedBlock(v7);
      v18 = block->mData;
      v19 = UnusedBlock;
      UFG::qPrintChannel::Print(
        &UFG::VRAMChannel,
        OUTPUT_LEVEL_DEBUG,
        "[VRAM Channel] - Setting Block ID:0x%04x to free data:%p size:0x%08x (%9u)\n");
      v19->mData = v18;
      v19->mRequestedSize = v9;
      v19->mActualSize = v9;
      *(_DWORD *)&v19->mUsage = 1;
      v19->mMemoryPool = 0i64;
      v19->mContainerID = 0;
      v19->mCallbackData64 = 0i64;
      v19->mCallbackData32 = 0;
      v19->mName = "Free VRAM";
      v20 = &block->mData[v9];
      UFG::qPrintChannel::Print(
        &UFG::VRAMChannel,
        OUTPUT_LEVEL_DEBUG,
        "[VRAM Channel] - Setting Block ID:0x%04x to free data:%p size:0x%08x (%9u)\n");
      mPrev = block->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mPrev;
      block->mData = v20;
      v7 = this;
      block->mName = "Free VRAM";
      block->mRequestedSize = v11;
      block->mActualSize = v11;
      *(_DWORD *)&block->mUsage = 1;
      block->mMemoryPool = 0i64;
      block->mContainerID = 0;
      block->mCallbackData64 = 0i64;
      block->mCallbackData32 = 0;
      mPrev->mNext = v19;
      v19->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mPrev = mPrev;
      v19->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mNext = block;
      block->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mPrev = v19;
      goto LABEL_18;
    }
    goto LABEL_16;
  }
  v19 = UFG::qVRAMemoryPool::GetUnusedBlock(v7);
  if ( !v11 )
  {
    v22 = &block->mData[v14];
    UFG::qPrintChannel::Print(
      &UFG::VRAMChannel,
      OUTPUT_LEVEL_DEBUG,
      "[VRAM Channel] - Setting Block ID:0x%04x to free data:%p size:0x%08x (%9u)\n");
    v19->mData = v22;
    v19->mRequestedSize = v9;
    v19->mActualSize = v9;
    *(_DWORD *)&v19->mUsage = 1;
    v19->mMemoryPool = 0i64;
    v19->mContainerID = 0;
    v19->mCallbackData64 = 0i64;
    v19->mCallbackData32 = 0;
    v19->mName = "Free VRAM";
    v23 = block->mData;
    UFG::qPrintChannel::Print(
      &UFG::VRAMChannel,
      OUTPUT_LEVEL_DEBUG,
      "[VRAM Channel] - Setting Block ID:0x%04x to free data:%p size:0x%08x (%9u)\n");
    mNext = block->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mNext;
    block->mData = v23;
    v7 = this;
    block->mName = "Free VRAM";
    block->mRequestedSize = v14;
    block->mActualSize = v14;
    *(_DWORD *)&block->mUsage = 1;
    block->mMemoryPool = 0i64;
    block->mContainerID = 0;
    block->mCallbackData64 = 0i64;
    block->mCallbackData32 = 0;
    block->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mNext = v19;
    v19->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mNext = mNext;
    v19->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mPrev = block;
    mNext->mPrev = v19;
    goto LABEL_18;
  }
  v25 = UFG::qVRAMemoryPool::GetUnusedBlock(v7);
  v26 = block->mData;
  v27 = v25;
  UFG::qPrintChannel::Print(
    &UFG::VRAMChannel,
    OUTPUT_LEVEL_DEBUG,
    "[VRAM Channel] - Setting Block ID:0x%04x to free data:%p size:0x%08x (%9u)\n");
  v19->mData = v26;
  v19->mRequestedSize = v14;
  v19->mActualSize = v14;
  *(_DWORD *)&v19->mUsage = 1;
  v19->mMemoryPool = 0i64;
  v19->mContainerID = 0;
  v19->mCallbackData64 = 0i64;
  v19->mCallbackData32 = 0;
  v19->mName = "Free VRAM";
  v28 = &block->mData[block->mActualSize - v11];
  UFG::qPrintChannel::Print(
    &UFG::VRAMChannel,
    OUTPUT_LEVEL_DEBUG,
    "[VRAM Channel] - Setting Block ID:0x%04x to free data:%p size:0x%08x (%9u)\n");
  v27->mData = v28;
  v27->mRequestedSize = v11;
  v27->mActualSize = v11;
  *(_DWORD *)&v27->mUsage = 1;
  v27->mMemoryPool = 0i64;
  v27->mContainerID = 0;
  v27->mCallbackData64 = 0i64;
  v27->mCallbackData32 = 0;
  v27->mName = "Free VRAM";
  v29 = &block->mData[v14];
  UFG::qPrintChannel::Print(
    &UFG::VRAMChannel,
    OUTPUT_LEVEL_DEBUG,
    "[VRAM Channel] - Setting Block ID:0x%04x to free data:%p size:0x%08x (%9u)\n");
  block->mData = v29;
  block->mRequestedSize = v9;
  block->mActualSize = v9;
  *(_DWORD *)&block->mUsage = 1;
  block->mMemoryPool = 0i64;
  block->mContainerID = 0;
  block->mCallbackData64 = 0i64;
  block->mCallbackData32 = 0;
  v30 = &block->UFG::qNode<UFG::BlockInfo,UFG::Secondary>;
  block->mName = "Free VRAM";
  v31 = block->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mPrev;
  v31->mNext = v19;
  v19->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mPrev = v31;
  v19->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mNext = block;
  v32 = block->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mNext;
  block->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mPrev = v19;
  block->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mNext = v27;
  v27->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mNext = v32;
  v27->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mPrev = block;
  v32->mPrev = v27;
  v33 = block->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mPrev;
  v33->mNext = &v19->UFG::qNode<UFG::BlockInfo,UFG::Secondary>;
  v19->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mPrev = v33;
  v19->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mNext = &block->UFG::qNode<UFG::BlockInfo,UFG::Secondary>;
  block->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mPrev = &v19->UFG::qNode<UFG::BlockInfo,UFG::Secondary>;
  v34 = block->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mNext;
  v7 = this;
  block->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mNext = &v27->UFG::qNode<UFG::BlockInfo,UFG::Secondary>;
  v27->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mNext = v34;
  v27->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mPrev = &block->UFG::qNode<UFG::BlockInfo,UFG::Secondary>;
  v34->mPrev = &v27->UFG::qNode<UFG::BlockInfo,UFG::Secondary>;
LABEL_17:
  v35 = v30->mPrev;
  v36 = v30->mNext;
  v19 = block;
  v35->mNext = v36;
  v36->mPrev = v35;
  v30->mNext = v30;
  v30->mPrev = v30;
LABEL_18:
  if ( v40 )
  {
    for ( i = (__int64)&v7->mFreeList.mNode.mNext[-1];
          (UFG::qList<UFG::BlockInfo,UFG::Primary,1,0> *)i != &v7->mUsedBlocks;
          i = *(_QWORD *)(i + 24) - 16i64 )
    {
      if ( *(_DWORD *)(i + 68) > v5 )
        v5 = *(_DWORD *)(i + 68);
    }
    v7->mLargestFreeBlock = v5;
  }
  return v19;
}

// File Line: 2539
// RVA: 0x172DF0
UFG::BlockInfo *__fastcall UFG::qVRAMemoryPool::GetUnusedBlock(UFG::qVRAMemoryPool *this)
{
  unsigned __int16 v2; // ax
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *mNext; // rdx
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v4; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *mPrev; // rcx
  UFG::BlockInfo *result; // rax
  unsigned __int16 v7; // cx

  if ( this->mNumBlocksTotal )
  {
    if ( (UFG::qList<UFG::BlockInfo,UFG::Primary,1,0> *)this->mUnusedBlocks.mNode.mNext == &this->mUnusedBlocks )
    {
      return 0i64;
    }
    else
    {
      v2 = ++this->mUsedBlocksCount;
      if ( v2 > this->mUsedBlocksMax )
        this->mUsedBlocksMax = v2;
      mNext = this->mUnusedBlocks.mNode.mNext;
      v4 = mNext->mNext;
      mPrev = mNext->mPrev;
      mPrev->mNext = v4;
      v4->mPrev = mPrev;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      return (UFG::BlockInfo *)mNext;
    }
  }
  else
  {
    result = UFG::qVRAMemoryPools::GetUnusedBlock();
    if ( result )
    {
      v7 = ++this->mUsedBlocksCount;
      if ( v7 > this->mUsedBlocksMax )
        this->mUsedBlocksMax = v7;
    }
  }
  return result;
}

// File Line: 2566
// RVA: 0x17BBF0
void __fastcall UFG::qVRAMemoryPool::ReturnUsedBlock(UFG::qVRAMemoryPool *this, UFG::BlockInfo *block)
{
  UFG::qList<UFG::BlockInfo,UFG::Primary,1,0> *p_mUnusedBlocks; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *mNext; // rcx

  block->mName = "Unused VRAM BlockInfo";
  block->mData = 0i64;
  *(_QWORD *)&block->mRequestedSize = 0i64;
  *(_DWORD *)&block->mUsage = 0;
  block->mMemoryPool = 0i64;
  block->mContainerID = 0;
  block->mCallbackData64 = 0i64;
  block->mCallbackData32 = 0;
  --this->mUsedBlocksCount;
  if ( this->mNumBlocksTotal )
  {
    p_mUnusedBlocks = &this->mUnusedBlocks;
    mNext = this->mUnusedBlocks.mNode.mNext;
    p_mUnusedBlocks->mNode.mNext = block;
    block->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mPrev = &p_mUnusedBlocks->mNode;
    block->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mNext = mNext;
    mNext->mPrev = block;
  }
  else
  {
    UFG::qVRAMemoryPools::ReturnUsedBlock(block);
  }
}

// File Line: 2581
// RVA: 0x174150
char __fastcall UFG::qVRAMemoryPool::InternalFree(UFG::qVRAMemoryPool *this, UFG::BlockInfo *block)
{
  UFG::qVRAMemoryPool *v3; // rbp
  char mUsage; // al
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *mNext; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *mPrev; // rcx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v7; // rdi
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v8; // rcx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v9; // rax
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v10; // rcx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v11; // rax
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v13; // rdi
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v14; // rcx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v15; // rax
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v16; // rcx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v17; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v18; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v19; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v20; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v21; // rax
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v22; // rdi
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v23; // rcx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v24; // rax
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v25; // rcx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v26; // rax
  UFG::BlockInfo *v27; // rbx
  unsigned int mActualSize; // eax

  v3 = this;
  UFG::qPrintChannel::Print(
    &UFG::VRAMChannel,
    OUTPUT_LEVEL_WARNING,
    "[VRAM Channel] - %.64s->InternalFree(%p - [%04u]%p)\n");
  mUsage = block->mUsage;
  if ( (unsigned __int8)mUsage >= 2u )
  {
    if ( mUsage == 11 )
    {
      if ( !v3->mNumBlocksTotal )
        UFG::qVRAMemoryPools::GetBlock(block->mContainerID);
      mNext = block->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mNext;
      mPrev = block->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mPrev;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      block->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mPrev = block;
      block->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mNext = block;
      if ( (UFG::qList<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly,1,0> *)block->mAllocationHandles.mNode.mNext != &block->mAllocationHandles )
      {
        do
        {
          v7 = block->mAllocationHandles.mNode.mNext;
          v8 = v7->mPrev;
          v9 = v7->mNext;
          v8->mNext = v9;
          v9->mPrev = v8;
          v7->mPrev = v7;
          v7->mNext = v7;
          UFG::qPrintChannel::Print(
            &UFG::VRAMChannel,
            OUTPUT_LEVEL_DEBUG,
            "[VRAM Channel] - Setting qVRAMemoryHandle(%p) to point at - PoolID:0x%02x BlockID:0x%04x Data:%p-%p AllocatedSize:%u\n");
          v10 = v7->mPrev;
          v11 = v7->mNext;
          v10->mNext = v11;
          v11->mPrev = v10;
          v7->mPrev = v7;
          v7->mNext = v7;
          v7[1].mPrev = 0i64;
          LODWORD(v7[1].mNext) = 0;
        }
        while ( (UFG::qList<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly,1,0> *)block->mAllocationHandles.mNode.mNext != &block->mAllocationHandles );
        v3 = this;
      }
    }
    else
    {
      if ( (block->mFlags & 0x10) == 0 )
      {
        if ( (unsigned __int8)(mUsage - 9) <= 1u )
        {
          v20 = block->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mPrev;
          v21 = block->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mNext;
          v20->mNext = v21;
          v21->mPrev = v20;
          block->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mPrev = &block->UFG::qNode<UFG::BlockInfo,UFG::Secondary>;
          block->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mNext = &block->UFG::qNode<UFG::BlockInfo,UFG::Secondary>;
          while ( block->mContainedBlocks.mNode.mNext != (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&block->mContainedBlocks )
            UFG::qVRAMemoryPool::InternalFree(v3, (UFG::BlockInfo *)block->mContainedBlocks.mNode.mNext);
        }
        if ( (UFG::qList<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly,1,0> *)block->mAllocationHandles.mNode.mNext != &block->mAllocationHandles )
        {
          do
          {
            v22 = block->mAllocationHandles.mNode.mNext;
            v23 = v22->mPrev;
            v24 = v22->mNext;
            v23->mNext = v24;
            v24->mPrev = v23;
            v22->mPrev = v22;
            v22->mNext = v22;
            UFG::qPrintChannel::Print(
              &UFG::VRAMChannel,
              OUTPUT_LEVEL_DEBUG,
              "[VRAM Channel] - Setting qVRAMemoryHandle(%p) to point at - PoolID:0x%02x BlockID:0x%04x Data:%p-%p AllocatedSize:%u\n");
            v25 = v22->mPrev;
            v26 = v22->mNext;
            v25->mNext = v26;
            v26->mPrev = v25;
            v22->mPrev = v22;
            v22->mNext = v22;
            v22[1].mPrev = 0i64;
            LODWORD(v22[1].mNext) = 0;
          }
          while ( (UFG::qList<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly,1,0> *)block->mAllocationHandles.mNode.mNext != &block->mAllocationHandles );
          v3 = this;
        }
        v3->mFreeMemory += block->mActualSize;
        v3->mUsedMemory -= block->mActualSize;
        v3->mAllocatedMemory -= block->mRequestedSize;
        v3->mAlignmentLoss += block->mRequestedSize - block->mActualSize;
        UFG::BlockInfo::SetFree(block);
        v27 = UFG::qVRAMemoryPool::MergeFreeBlock(v3, block);
        if ( v27->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mPrev == &v27->UFG::qNode<UFG::BlockInfo,UFG::Secondary>
          && v27->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mNext == &v27->UFG::qNode<UFG::BlockInfo,UFG::Secondary> )
        {
          UFG::qVRAMemoryPool::AddBlockToFreeList(v3, v27);
        }
        mActualSize = v27->mActualSize;
        if ( mActualSize > v3->mLargestFreeBlock )
          v3->mLargestFreeBlock = mActualSize;
        if ( v3->mLargestFreeBlock != v3->mFreeMemory )
          *(_WORD *)&v3->mNeedsDefragmentUp = 257;
        return 1;
      }
      if ( (UFG::qList<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly,1,0> *)block->mAllocationHandles.mNode.mNext != &block->mAllocationHandles )
      {
        do
        {
          v13 = block->mAllocationHandles.mNode.mNext;
          v14 = v13->mPrev;
          v15 = v13->mNext;
          v14->mNext = v15;
          v15->mPrev = v14;
          v13->mPrev = v13;
          v13->mNext = v13;
          UFG::qPrintChannel::Print(
            &UFG::VRAMChannel,
            OUTPUT_LEVEL_DEBUG,
            "[VRAM Channel] - Setting qVRAMemoryHandle(%p) to point at - PoolID:0x%02x BlockID:0x%04x Data:%p-%p AllocatedSize:%u\n");
          v16 = v13->mPrev;
          v17 = v13->mNext;
          v16->mNext = v17;
          v17->mPrev = v16;
          v13->mPrev = v13;
          v13->mNext = v13;
          v13[1].mPrev = 0i64;
          LODWORD(v13[1].mNext) = 0;
        }
        while ( (UFG::qList<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly,1,0> *)block->mAllocationHandles.mNode.mNext != &block->mAllocationHandles );
        v3 = this;
      }
      v18 = block->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mPrev;
      v19 = block->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mNext;
      v18->mNext = v19;
      v19->mPrev = v18;
      LODWORD(v19) = block->mRequestedSize;
      block->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mPrev = block;
      block->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mNext = block;
      v3->mUsedMainMemory -= (unsigned int)v19;
      UFG::qMemoryPool::Free(block->mMemoryPool, block->mData);
    }
    UFG::qVRAMemoryPool::ReturnUsedBlock(v3, block);
    return 1;
  }
  return 0;
}

// File Line: 2686
// RVA: 0x177A50
UFG::BlockInfo *__fastcall UFG::qVRAMemoryPool::MergeFreeBlock(UFG::qVRAMemoryPool *this, UFG::BlockInfo *block)
{
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *mNext; // rbp
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *mPrev; // r14
  UFG::qList<UFG::BlockInfo,UFG::Primary,1,0> *p_mUsedBlocks; // r15
  UFG::BlockInfo *v5; // rsi
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v7; // rbx
  unsigned int v8; // edi
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v9; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v10; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v11; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v12; // rax
  char *mData; // rbx
  int v14; // edi
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v15; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v16; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v17; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v18; // r8

  mNext = block->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mNext;
  mPrev = block->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mPrev;
  p_mUsedBlocks = &this->mUsedBlocks;
  v5 = block;
  if ( (UFG::qList<UFG::BlockInfo,UFG::Primary,1,0> *)block->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mPrev != &this->mUsedBlocks
    && BYTE2(mPrev[4].mNext) == block->mUsage )
  {
    v7 = mPrev[3].mPrev;
    v8 = HIDWORD(mPrev[4].mPrev) + block->mActualSize;
    UFG::qPrintChannel::Print(
      &UFG::VRAMChannel,
      OUTPUT_LEVEL_DEBUG,
      "[VRAM Channel] - Setting Block ID:0x%04x to free data:%p size:0x%08x (%9u)\n");
    mPrev[3].mPrev = v7;
    LODWORD(mPrev[4].mPrev) = v8;
    HIDWORD(mPrev[4].mPrev) = v8;
    *(_DWORD *)((char *)&mPrev[4].mNext + 2) = 1;
    mPrev[5].mPrev = 0i64;
    LOWORD(mPrev[6].mNext) = 0;
    mPrev[7].mPrev = 0i64;
    LODWORD(mPrev[7].mNext) = 0;
    mPrev[3].mNext = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)"Free VRAM";
    v9 = v5->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mPrev;
    v10 = v5->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    v5->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mPrev = v5;
    v5->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mNext = v5;
    v11 = v5->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mPrev;
    v12 = v5->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    v5->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mPrev = &v5->UFG::qNode<UFG::BlockInfo,UFG::Secondary>;
    v5->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mNext = &v5->UFG::qNode<UFG::BlockInfo,UFG::Secondary>;
    UFG::qVRAMemoryPool::ReturnUsedBlock(this, v5);
    v5 = (UFG::BlockInfo *)mPrev;
  }
  if ( mNext == (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)p_mUsedBlocks || BYTE2(mNext[4].mNext) != v5->mUsage )
    return v5;
  mData = v5->mData;
  v14 = HIDWORD(mNext[4].mPrev) + v5->mActualSize;
  UFG::qPrintChannel::Print(
    &UFG::VRAMChannel,
    OUTPUT_LEVEL_DEBUG,
    "[VRAM Channel] - Setting Block ID:0x%04x to free data:%p size:0x%08x (%9u)\n");
  mNext[3].mPrev = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)mData;
  LODWORD(mNext[4].mPrev) = v14;
  HIDWORD(mNext[4].mPrev) = v14;
  *(_DWORD *)((char *)&mNext[4].mNext + 2) = 1;
  mNext[5].mPrev = 0i64;
  LOWORD(mNext[6].mNext) = 0;
  mNext[7].mPrev = 0i64;
  LODWORD(mNext[7].mNext) = 0;
  mNext[3].mNext = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)"Free VRAM";
  v15 = v5->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mPrev;
  v16 = v5->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  v5->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mPrev = v5;
  v5->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mNext = v5;
  v17 = v5->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mNext;
  v18 = v5->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mPrev;
  v18->mNext = v17;
  v17->mPrev = v18;
  v5->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mPrev = &v5->UFG::qNode<UFG::BlockInfo,UFG::Secondary>;
  v5->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mNext = &v5->UFG::qNode<UFG::BlockInfo,UFG::Secondary>;
  UFG::qVRAMemoryPool::ReturnUsedBlock(this, v5);
  return (UFG::BlockInfo *)mNext;
}  UFG::qVRAMemoryPo

// File Line: 2719
// RVA: 0x165EC0
char __fastcall UFG::qVRAMemoryPool::AddBlockToFreeList(UFG::qVRAMemoryPool *this, UFG::BlockInfo *block)
{
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v3; // rdx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *mPrev; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v5; // rdx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v6; // rdx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v7; // rax

  v3 = this->mFreeList.mNode.mNext - 1;
  if ( v3 != (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)&this->mUsedBlocks )
  {
    while ( v3[3].mPrev <= (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)block->mData )
    {
      v3 = v3[1].mNext - 1;
      if ( v3 == (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)&this->mUsedBlocks )
        goto LABEL_6;
    }
    mPrev = v3[1].mPrev;
    v5 = v3 + 1;
    mPrev->mNext = &block->UFG::qNode<UFG::BlockInfo,UFG::Secondary>;
    block->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mPrev = mPrev;
    block->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mNext = v5;
    v5->mPrev = &block->UFG::qNode<UFG::BlockInfo,UFG::Secondary>;
  }
LABEL_6:
  v6 = &block->UFG::qNode<UFG::BlockInfo,UFG::Secondary>;
  if ( v6->mPrev == v6
    && block->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mNext == &block->UFG::qNode<UFG::BlockInfo,UFG::Secondary> )
  {
    v7 = this->mFreeList.mNode.mPrev;
    v7->mNext = v6;
    v6->mPrev = v7;
    block->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mNext = &this->mFreeList.mNode;
    this->mFreeList.mNode.mPrev = v6;
  }
  return 1;
}

// File Line: 2786
// RVA: 0x167740
void __fastcall UFG::qVRAMemoryPool::AssertValidInitialized(UFG::qVRAMemoryPool *this)
{
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *mNext; // rax
  UFG::qList<UFG::BlockInfo,UFG::Primary,1,0> *p_mMainMemoryBlocks; // rdx
  UFG::qList<UFG::BlockInfo,UFG::Primary,1,0> *v4; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v5; // rcx
  UFG::qList<UFG::BlockInfo,UFG::Primary,1,0> *i; // r8
  unsigned int mPrev_high; // edx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *j; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *k; // rax
  UFG::qVRAMemoryPool *m; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v11; // rax
  UFG::qList<UFG::BlockInfo,UFG::Secondary,1,0> *p_mMoveTargetsList; // rbx
  __int64 n; // rax

  if ( !this->mNumBlocksTotal )
  {
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMBlocksLock);
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMBlocksLock);
  }
  if ( !this->mNumBlocksTotal )
  {
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMBlocksLock);
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMBlocksLock);
  }
  mNext = this->mMainMemoryBlocks.mNode.mNext;
  p_mMainMemoryBlocks = &this->mMainMemoryBlocks;
  v4 = (UFG::qList<UFG::BlockInfo,UFG::Primary,1,0> *)mNext;
  if ( mNext != (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&this->mMainMemoryBlocks )
  {
    do
      v4 = (UFG::qList<UFG::BlockInfo,UFG::Primary,1,0> *)v4->mNode.mNext;
    while ( v4 != p_mMainMemoryBlocks );
  }
  v5 = this->mUsedBlocks.mNode.mNext;
  for ( i = &this->mUsedBlocks; v5 != (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)i; v5 = v5->mNext )
    ;
  for ( ; mNext != (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)p_mMainMemoryBlocks; mNext = mNext->mNext )
    ;
  mPrev_high = 0;
  for ( j = this->mFreeList.mNode.mNext - 1; j != (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)i; j = j[1].mNext - 1 )
  {
    if ( HIDWORD(j[4].mPrev) > mPrev_high )
      mPrev_high = HIDWORD(j[4].mPrev);
  }
  for ( k = this->mPendingFreeList.mNode.mNext - 1;
        k != (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)&this->mFreeList;
        k = k[1].mNext - 1 )
  {
    ;
  }
  for ( m = (UFG::qVRAMemoryPool *)this->mUnusedBlocks.mNode.mNext;
        m != (UFG::qVRAMemoryPool *)&this->mUnusedBlocks;
        m = (UFG::qVRAMemoryPool *)m->mNext )
  {
    ;
  }
  v11 = this->mContainerList.mNode.mNext;
  p_mMoveTargetsList = &this->mMoveTargetsList;
  for ( n = (__int64)&v11[-1];
        (UFG::qList<UFG::BlockInfo,UFG::Secondary,1,0> *)n != p_mMoveTargetsList;
        n = *(_QWORD *)(n + 24) - 16i64 )
  {
    ;
  }
}

// File Line: 3006
// RVA: 0x1467B80
__int64 dynamic_initializer_for__UFG::qVRAMemoryPools::sVRAMPoolsLock__()
{
  UFG::qMutex::qMutex(&UFG::qVRAMemoryPools::sVRAMPoolsLock, "qVRAMemory::sVRAMPoolsLock");
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qVRAMemoryPools::sVRAMPoolsLock__);
}

// File Line: 3007
// RVA: 0x1467AD0
__int64 dynamic_initializer_for__UFG::qVRAMemoryPools::sMainVRAMemoryPool__()
{
  UFG::qVRAMemoryPool::qVRAMemoryPool(&UFG::qVRAMemoryPools::sMainVRAMemoryPool);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qVRAMemoryPools::sMainVRAMemoryPool__);
}

// File Line: 3011
// RVA: 0x1467B50
__int64 dynamic_initializer_for__UFG::qVRAMemoryPools::sVRAMBlocksLock__()
{
  UFG::qMutex::qMutex(&UFG::qVRAMemoryPools::sVRAMBlocksLock, "qVRAMemory::sVRAMBlocksLock");
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qVRAMemoryPools::sVRAMBlocksLock__);
}

// File Line: 3012
// RVA: 0x1467B30
__int64 dynamic_initializer_for__UFG::qVRAMemoryPools::sUnusedBlocks__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qVRAMemoryPools::sUnusedBlocks__);
}

// File Line: 3023
// RVA: 0x173B70
char __fastcall UFG::qVRAMemoryPools::InitSystem(
        char *main_pool_vram_start,
        unsigned int main_pool_vram_size,
        const char *main_pool_name,
        unsigned __int16 main_pool_num_blocks,
        unsigned int main_pool_alignment,
        char *main_pool_block_memory,
        unsigned int main_pool_block_memory_size,
        unsigned __int16 common_num_blocks,
        char *common_block_memory,
        unsigned int common_block_memory_size)
{
  unsigned __int64 v14; // rbx
  bool v15; // cf
  unsigned __int64 v16; // rbx
  UFG::qMemoryPool *v17; // rcx
  UFG::allocator::free_link *v18; // rax
  unsigned __int16 v19; // bx
  UFG::BlockInfo *v20; // rsi
  unsigned __int16 i; // dx
  UFG::BlockInfo *v22; // rcx
  UFG::BlockInfo *v23; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *mPrev; // rax
  UFG::qVRAMemoryPool *v25; // rbx

  if ( common_num_blocks )
  {
    if ( common_block_memory )
    {
      UFG::qVRAMemoryPools::sBlocks = (UFG::BlockInfo *)common_block_memory;
      UFG::qVRAMemoryPools::sBlocksMemory = common_block_memory;
      UFG::qVRAMemoryPools::sBlocksMemorySize = common_block_memory_size;
      v19 = 0;
      for ( i = 0; i < common_num_blocks; ++i )
      {
        v22 = &UFG::qVRAMemoryPools::sBlocks[(unsigned __int64)i];
        if ( v22 )
        {
          v22->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mPrev = v22;
          v22->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mNext = v22;
          v22->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mPrev = &v22->UFG::qNode<UFG::BlockInfo,UFG::Secondary>;
          v22->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mNext = &v22->UFG::qNode<UFG::BlockInfo,UFG::Secondary>;
          v22->mAllocationHandles.mNode.mPrev = &v22->mAllocationHandles.mNode;
          v22->mAllocationHandles.mNode.mNext = &v22->mAllocationHandles.mNode;
          v22->mData = 0i64;
          v22->mName = 0i64;
          *(_QWORD *)&v22->mRequestedSize = 0i64;
          *(_DWORD *)&v22->mBlockID = 0xFFFF;
          *(_WORD *)&v22->mKeepAliveFrames = 0;
          v22->mMemoryPool = 0i64;
          v22->mContainedBlocks.mNode.mPrev = &v22->mContainedBlocks.mNode;
          v22->mContainedBlocks.mNode.mNext = &v22->mContainedBlocks.mNode;
          *(_DWORD *)&v22->mContainerID = -1;
          v22->mCallbackData64 = 0i64;
          v22->mCallbackData32 = 0;
        }
      }
    }
    else
    {
      v14 = (unsigned __int64)common_num_blocks << 7;
      if ( !is_mul_ok(common_num_blocks, 0x80ui64) )
        v14 = -1i64;
      v15 = __CFADD__(v14, 8i64);
      v16 = v14 + 8;
      if ( v15 )
        v16 = -1i64;
      v17 = UFG::gMainMemoryPool;
      if ( !UFG::gMainMemoryPool )
      {
        UFG::InternalSetupMainMemoryPool((UFG *)UFG::gMainMemoryPool);
        v17 = UFG::gMainMemoryPool;
      }
      v18 = UFG::qMemoryPool::Allocate(v17, v16, "qVRAMemoryPool::mBlocks", 0i64, 1u);
      v19 = 0;
      if ( v18 )
      {
        LODWORD(v18->mNext) = common_num_blocks;
        v20 = (UFG::BlockInfo *)&v18[1];
        `eh vector constructor iterator(
          &v18[1],
          0x80ui64,
          common_num_blocks,
          (void (__fastcall *)(void *))UFG::BlockInfo::BlockInfo);
      }
      else
      {
        v20 = 0i64;
      }
      UFG::qVRAMemoryPools::sBlocks = v20;
      UFG::qVRAMemoryPools::sBlocksMemory = 0i64;
      UFG::qVRAMemoryPools::sBlocksMemorySize = 0;
    }
    UFG::qVRAMemoryPools::sNumBlocksTotal = common_num_blocks;
    UFG::qVRAMemoryPools::sUsedBlocksCount = 0;
    UFG::qVRAMemoryPools::sUsedBlocksMax = 0;
    do
    {
      v23 = &UFG::qVRAMemoryPools::sBlocks[(unsigned __int64)v19];
      v23->mBlockID = v19;
      mPrev = UFG::qVRAMemoryPools::sUnusedBlocks.mNode.mPrev;
      UFG::qVRAMemoryPools::sUnusedBlocks.mNode.mPrev->mNext = v23;
      v23->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mPrev = mPrev;
      v23->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mNext = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&UFG::qVRAMemoryPools::sUnusedBlocks;
      UFG::qVRAMemoryPools::sUnusedBlocks.mNode.mPrev = v23;
      ++v19;
    }
    while ( v19 < UFG::qVRAMemoryPools::sNumBlocksTotal );
  }
  v25 = &UFG::qVRAMemoryPools::sMainVRAMemoryPool;
  if ( (unsigned __int8)UFG::qVRAMemoryPool::Init(
                          &UFG::qVRAMemoryPools::sMainVRAMemoryPool,
                          main_pool_vram_start,
                          main_pool_vram_size,
                          main_pool_name,
                          main_pool_num_blocks,
                          main_pool_alignment,
                          main_pool_block_memory,
                          main_pool_block_memory_size) != 1 )
    v25 = UFG::gMainVRAMemoryPool;
  UFG::gMainVRAMemoryPool = v25;
  return 1;
}

// File Line: 3080
// RVA: 0x17CEE0
void __fastcall UFG::qVRAMemoryPools::SetDefaultDefragCallback(
        void (__fastcall *callback)(UFG::qVRAMemoryHandle *, char *, UFG::VRAMType, unsigned __int64, unsigned int))
{
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
  UFG::qVRAMemoryPools::sVRAMDefaultDefragCallback = callback;
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
}

// File Line: 3132
// RVA: 0x1701F0
__int64 __fastcall UFG::qVRAMemoryPools::GetDefragmentMoves(
        UFG::qVRAMemoryMoveOrder *moves,
        int moves_count,
        unsigned int requested_total_bytes)
{
  int v3; // ebx
  int v7; // eax
  int i; // edi
  UFG::qVRAMemoryPool *v9; // rcx
  unsigned int total_bytes; // [rsp+58h] [rbp+10h] BYREF

  v3 = 0;
  total_bytes = 0;
  if ( moves_count > 0 && moves )
  {
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
    v7 = sCurrentPoolId;
    for ( i = 0; i < 16; ++i )
    {
      if ( v3 >= moves_count )
        break;
      v9 = UFG::qVRAMemoryPools::sVRAMemoryPools[v7];
      if ( v9 )
      {
        v3 += UFG::qVRAMemoryPool::GetDefragmentMoves(
                v9,
                &moves[(__int64)v3],
                moves_count - v3,
                requested_total_bytes,
                &total_bytes);
        LOBYTE(v7) = sCurrentPoolId;
      }
      v7 = ((_BYTE)v7 + 1) & 0xF;
      sCurrentPoolId = v7;
    }
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
  }
  return (unsigned int)v3;
}

// File Line: 3168
// RVA: 0x178100
void __fastcall UFG::qVRAMemoryPools::MovesCompleted(
        UFG::qVRAMemoryMoveOrder *moves,
        unsigned int moves_count,
        void (__fastcall *callback)(UFG::qVRAMemoryHandle *, char *, UFG::VRAMType, unsigned __int64, unsigned int))
{
  __int64 v3; // rsi
  unsigned __int16 *p_mReadOnlyAndPoolID; // rdi
  UFG::qVRAMemoryPool *v7; // rcx
  void (__fastcall *v8)(UFG::qVRAMemoryHandle *, char *, UFG::VRAMType, unsigned __int64, unsigned int); // r8

  v3 = moves_count;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
  if ( (int)v3 > 0 )
  {
    p_mReadOnlyAndPoolID = &moves->mTargetHandle.mReadOnlyAndPoolID;
    do
    {
      v7 = UFG::qVRAMemoryPools::sVRAMemoryPools[*p_mReadOnlyAndPoolID & 0x7FFF];
      if ( v7 )
      {
        v8 = UFG::qVRAMemoryPools::sVRAMDefaultDefragCallback;
        if ( callback )
          v8 = callback;
        UFG::qVRAMemoryPool::MoveCompleted(v7, moves, v8);
      }
      ++moves;
      p_mReadOnlyAndPoolID += 32;
      --v3;
    }
    while ( v3 );
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
}

// File Line: 3185
// RVA: 0x17C1F0
void UFG::qVRAMemoryPools::ServiceDeletes(void)
{
  UFG::qVRAMemoryPool **v0; // r14
  __int64 v1; // r15
  UFG::qVRAMemoryPool *v2; // rdi
  UFG::BlockInfo *v3; // rdx
  __int64 v4; // rbx
  char mKeepAliveFrames; // al
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *mPrev; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *mNext; // rax

  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
  v0 = UFG::qVRAMemoryPools::sVRAMemoryPools;
  v1 = 16i64;
  do
  {
    v2 = *v0;
    if ( *v0 )
    {
      UFG::qPrintChannel::Print(&UFG::VRAMChannel, OUTPUT_LEVEL_WARNING, "[VRAM Channel] - %.64s->ServiceDeletes()\n");
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&v2->mPoolLock);
      if ( v2->mValidate )
      {
        UFG::qPrintChannel::Print(&UFG::VRAMChannel, OUTPUT_LEVEL_WARNING, "[VRAM Channel] - %.64s->AssertValid()\n");
        UFG::qMutex::Lock((LPCRITICAL_SECTION)&v2->mPoolLock);
        if ( v2->mInitialized == 1 )
          UFG::qVRAMemoryPool::AssertValidInitialized(v2);
        UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v2->mPoolLock);
      }
      v3 = (UFG::BlockInfo *)&v2->mPendingFreeList.mNode.mNext[-1];
      if ( v3 != (UFG::BlockInfo *)&v2->mFreeList )
      {
        do
        {
          v4 = (__int64)&v3->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mNext[-1];
          if ( (v3->mFlags & 0x40) == 0 )
          {
            mKeepAliveFrames = v3->mKeepAliveFrames;
            if ( (unsigned __int8)mKeepAliveFrames <= 1u )
            {
              mPrev = v3->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mPrev;
              mNext = v3->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mNext;
              mPrev->mNext = mNext;
              mNext->mPrev = mPrev;
              v3->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mPrev = &v3->UFG::qNode<UFG::BlockInfo,UFG::Secondary>;
              v3->UFG::qNode<UFG::BlockInfo,UFG::Secondary>::mNext = &v3->UFG::qNode<UFG::BlockInfo,UFG::Secondary>;
              UFG::qVRAMemoryPool::InternalFree(v2, v3);
            }
            else
            {
              v3->mKeepAliveFrames = mKeepAliveFrames - 1;
            }
          }
          v3 = (UFG::BlockInfo *)v4;
        }
        while ( (UFG::qList<UFG::BlockInfo,UFG::Secondary,1,0> *)v4 != &v2->mFreeList );
      }
      if ( v2->mValidate )
      {
        UFG::qPrintChannel::Print(&UFG::VRAMChannel, OUTPUT_LEVEL_WARNING, "[VRAM Channel] - %.64s->AssertValid()\n");
        UFG::qMutex::Lock((LPCRITICAL_SECTION)&v2->mPoolLock);
        if ( v2->mInitialized == 1 )
          UFG::qVRAMemoryPool::AssertValidInitialized(v2);
        UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v2->mPoolLock);
      }
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v2->mPoolLock);
    }
    ++v0;
    --v1;
  }
  while ( v1 );
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
}

// File Line: 3200
// RVA: 0x177410
__int64 __fastcall UFG::qVRAMemoryPools::Lock(UFG::qVRAMemoryHandle *handle)
{
  unsigned __int8 v2; // di
  unsigned __int16 v3; // ax
  UFG::qVRAMemoryPool *v4; // rcx

  v2 = 0;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
  if ( handle->mData )
  {
    v3 = handle->mReadOnlyAndPoolID & 0x7FFF;
    if ( v3 < 0x10u )
    {
      v4 = UFG::qVRAMemoryPools::sVRAMemoryPools[v3];
      if ( v4 )
        v2 = UFG::qVRAMemoryPool::Lock(v4, handle);
    }
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
  return v2;
}

// File Line: 3218
// RVA: 0x17F460
__int64 __fastcall UFG::qVRAMemoryPools::Unlock(UFG::qVRAMemoryHandle *handle)
{
  unsigned __int8 v2; // di
  unsigned __int16 v3; // ax
  UFG::qVRAMemoryPool *v4; // rcx

  v2 = 0;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
  if ( handle->mData )
  {
    v3 = handle->mReadOnlyAndPoolID & 0x7FFF;
    if ( v3 < 0x10u )
    {
      v4 = UFG::qVRAMemoryPools::sVRAMemoryPools[v3];
      if ( v4 )
        v2 = UFG::qVRAMemoryPool::Unlock(v4, handle);
    }
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
  return v2;
}

// File Line: 3236
// RVA: 0x178C50
__int64 __fastcall UFG::qVRAMemoryPools::PreMove(UFG::qVRAMemoryHandle *handle)
{
  unsigned __int8 v2; // di
  unsigned __int16 v3; // ax
  UFG::qVRAMemoryPool *v4; // rcx

  v2 = 0;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
  if ( handle->mData )
  {
    v3 = handle->mReadOnlyAndPoolID & 0x7FFF;
    if ( v3 < 0x10u )
    {
      v4 = UFG::qVRAMemoryPools::sVRAMemoryPools[v3];
      if ( v4 )
        v2 = UFG::qVRAMemoryPool::PreMove(v4, handle);
    }
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
  return v2;
}

// File Line: 3254
// RVA: 0x178A80
__int64 __fastcall UFG::qVRAMemoryPools::PostMove(UFG::qVRAMemoryHandle *handle)
{
  unsigned __int8 v2; // di
  unsigned __int16 v3; // ax
  UFG::qVRAMemoryPool *v4; // rcx

  v2 = 0;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
  if ( handle->mData )
  {
    v3 = handle->mReadOnlyAndPoolID & 0x7FFF;
    if ( v3 < 0x10u )
    {
      v4 = UFG::qVRAMemoryPools::sVRAMemoryPools[v3];
      if ( v4 )
        v2 = UFG::qVRAMemoryPool::PostMove(v4, handle);
    }
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
  return v2;
}

// File Line: 3272
// RVA: 0x172170
__int64 __fastcall UFG::qVRAMemoryPools::GetRequestedSize(UFG::qVRAMemoryHandle *handle)
{
  unsigned int RequestedSize; // edi
  unsigned __int16 v3; // ax
  UFG::qVRAMemoryPool *v4; // rcx

  RequestedSize = 0;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
  if ( handle->mData )
  {
    v3 = handle->mReadOnlyAndPoolID & 0x7FFF;
    if ( v3 < 0x10u )
    {
      v4 = UFG::qVRAMemoryPools::sVRAMemoryPools[v3];
      if ( v4 )
        RequestedSize = UFG::qVRAMemoryPool::GetRequestedSize(v4, handle);
    }
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
  return RequestedSize;
}

// File Line: 3290
// RVA: 0x16F3A0
__int64 __fastcall UFG::qVRAMemoryPools::GetAllocatedSize(UFG::qVRAMemoryHandle *handle)
{
  unsigned int AllocatedSize; // edi
  unsigned __int16 v3; // ax
  UFG::qVRAMemoryPool *v4; // rcx

  AllocatedSize = 0;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
  if ( handle->mData )
  {
    v3 = handle->mReadOnlyAndPoolID & 0x7FFF;
    if ( v3 < 0x10u )
    {
      v4 = UFG::qVRAMemoryPools::sVRAMemoryPools[v3];
      if ( v4 )
        AllocatedSize = UFG::qVRAMemoryPool::GetAllocatedSize(v4, handle);
    }
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
  return AllocatedSize;
}

// File Line: 3308
// RVA: 0x167A40
__int64 __fastcall UFG::qVRAMemoryPools::BindWithinContainer(
        UFG::qVRAMemoryHandle *handle,
        char *data,
        unsigned int data_size,
        const char *name)
{
  __int64 v6; // rdi
  unsigned __int8 v7; // si
  unsigned int v8; // r11d
  UFG::qVRAMemoryPool *v9; // r14
  UFG::qVRAMemoryPool **v10; // r10
  __int64 v11; // r9
  UFG::qVRAMemoryPool *v12; // rdx
  unsigned __int64 mVRAMemoryStart; // rax
  __int64 mVRAMemorySize; // r8
  __int64 v15; // rbx
  unsigned __int64 v16; // rcx
  __int64 v17; // rcx
  char *v18; // rdx
  UFG::BlockInfo *UnusedBlock; // rsi
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v20; // rax
  unsigned __int16 mBlockID; // di
  unsigned __int16 mPoolID; // bx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *mNext; // rax
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *mPrev; // rcx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *p_mNode; // r10
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v26; // rax
  __int64 v28; // [rsp+28h] [rbp-50h]

  v6 = data_size;
  v7 = 0;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
  v8 = -1;
  v9 = 0i64;
  v10 = UFG::qVRAMemoryPools::sVRAMemoryPools;
  v11 = 16i64;
  do
  {
    v12 = *v10;
    if ( *v10 )
    {
      mVRAMemoryStart = (unsigned __int64)v12->mVRAMemoryStart;
      mVRAMemorySize = v12->mVRAMemorySize;
      if ( mVRAMemoryStart <= (unsigned __int64)data
        && mVRAMemoryStart + mVRAMemorySize >= (unsigned __int64)&data[v6]
        && (unsigned int)mVRAMemorySize < v8 )
      {
        v9 = *v10;
        v8 = v12->mVRAMemorySize;
      }
    }
    ++v10;
    --v11;
  }
  while ( v11 );
  if ( v9 )
  {
    HIDWORD(v28) = HIDWORD(data);
    UFG::qPrintChannel::Print(
      &UFG::VRAMChannel,
      OUTPUT_LEVEL_WARNING,
      "[VRAM Channel] - %.64s->BindWithinContainer(handle(%p), %p, 0x%08x(%u), %.64s%s)\n");
    v7 = 0;
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&v9->mPoolLock);
    if ( v9->mValidate )
    {
      UFG::qPrintChannel::Print(&UFG::VRAMChannel, OUTPUT_LEVEL_WARNING, "[VRAM Channel] - %.64s->AssertValid()\n");
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&v9->mPoolLock);
      if ( v9->mInitialized == 1 )
        UFG::qVRAMemoryPool::AssertValidInitialized(v9);
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v9->mPoolLock);
    }
    if ( v9->mInitialized == 1 )
    {
      v15 = (__int64)&v9->mContainerList.mNode.mNext[-1];
      if ( (UFG::qList<UFG::BlockInfo,UFG::Secondary,1,0> *)v15 != &v9->mMoveTargetsList )
      {
        while ( 1 )
        {
          v16 = *(_QWORD *)(v15 + 48);
          if ( v16 <= (unsigned __int64)data && v16 + *(unsigned int *)(v15 + 68) > (unsigned __int64)data )
            break;
          v15 = *(_QWORD *)(v15 + 24) - 16i64;
          if ( (UFG::qList<UFG::BlockInfo,UFG::Secondary,1,0> *)v15 == &v9->mMoveTargetsList )
            goto LABEL_22;
        }
        v17 = *(unsigned int *)(v15 + 68);
        v18 = *(char **)(v15 + 48);
        if ( &v18[v17] < &data[v6] )
        {
          LODWORD(v28) = *(_DWORD *)(v15 + 68);
          UFG::qPrintf(
            "WARNING: Requested block of size %u(0x%08x) from %p to %p does not fit within\n"
            "               container of size %u(0x%08x) from %p to %p\n",
            (unsigned int)v6,
            (unsigned int)v6,
            data,
            &data[v6],
            v28,
            v17,
            v18,
            &v18[v17]);
        }
        UnusedBlock = UFG::qVRAMemoryPool::GetUnusedBlock(v9);
        v20 = *(UFG::qNode<UFG::BlockInfo,UFG::Primary> **)(v15 + 88);
        v20->mNext = UnusedBlock;
        UnusedBlock->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mNext = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)(v15 + 88);
        UnusedBlock->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mPrev = v20;
        *(_QWORD *)(v15 + 88) = UnusedBlock;
        UnusedBlock->mContainerID = *(_WORD *)(v15 + 72);
        UnusedBlock->mRequestedSize = v6;
        mBlockID = UnusedBlock->mBlockID;
        UnusedBlock->mName = name;
        UnusedBlock->mActualSize = 0;
        UnusedBlock->mMemoryPool = 0i64;
        UnusedBlock->mCallbackData64 = 0i64;
        UnusedBlock->mCallbackData32 = 0;
        UnusedBlock->mData = data;
        *(_DWORD *)&UnusedBlock->mUsage = 11;
        mPoolID = v9->mPoolID;
        UFG::qPrintChannel::Print(
          &UFG::VRAMChannel,
          OUTPUT_LEVEL_DEBUG,
          "[VRAM Channel] - Setting qVRAMemoryHandle(%p) to point at - PoolID:0x%02x BlockID:0x%04x Data:%p-%p AllocatedSize:%u\n");
        mNext = handle->mNext;
        mPrev = handle->mPrev;
        p_mNode = &UnusedBlock->mAllocationHandles.mNode;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        handle->mPrev = handle;
        handle->mNext = handle;
        handle->mData = data;
        handle->mReadOnlyAndPoolID = mPoolID;
        handle->mBlockID = mBlockID;
        v26 = UnusedBlock->mAllocationHandles.mNode.mPrev;
        v7 = 1;
        v26->mNext = handle;
        handle->mPrev = v26;
        handle->mNext = p_mNode;
        p_mNode->mPrev = handle;
      }
    }
LABEL_22:
    if ( v9->mValidate )
    {
      UFG::qPrintChannel::Print(&UFG::VRAMChannel, OUTPUT_LEVEL_WARNING, "[VRAM Channel] - %.64s->AssertValid()\n");
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&v9->mPoolLock);
      if ( v9->mInitialized == 1 )
        UFG::qVRAMemoryPool::AssertValidInitialized(v9);
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v9->mPoolLock);
    }
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v9->mPoolLock);
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
  return v7;
}

// File Line: 3341
// RVA: 0x16ED60
_BOOL8 __fastcall UFG::qVRAMemoryPools::Free(UFG::qVRAMemoryHandle *handle, int frames_to_delay)
{
  bool v4; // di
  unsigned __int16 v5; // ax
  UFG::qVRAMemoryPool *v6; // rcx

  v4 = 0;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
  if ( handle->mData )
  {
    v5 = handle->mReadOnlyAndPoolID & 0x7FFF;
    if ( v5 < 0x10u )
    {
      v6 = UFG::qVRAMemoryPools::sVRAMemoryPools[v5];
      if ( v6 )
        v4 = UFG::qVRAMemoryPool::Free(v6, handle, frames_to_delay);
    }
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
  return v4;
}

// File Line: 3415
// RVA: 0x1788A0
__int64 __fastcall UFG::qVRAMemoryPools::OverlapsPool(char *data, unsigned int data_size)
{
  __int64 v2; // rsi
  unsigned __int8 v4; // bl
  int v5; // r8d
  UFG::qVRAMemoryPool **v6; // r9
  UFG::qVRAMemoryPool *v7; // rax
  char *mVRAMemoryStart; // r10

  v2 = data_size;
  v4 = 0;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
  v5 = 0;
  v6 = UFG::qVRAMemoryPools::sVRAMemoryPools;
  do
  {
    if ( v4 )
      break;
    v7 = *v6;
    if ( *v6 )
    {
      mVRAMemoryStart = v7->mVRAMemoryStart;
      if ( &mVRAMemoryStart[v7->mVRAMemorySize] > data && &data[v2] > mVRAMemoryStart )
        v4 = 1;
    }
    ++v5;
    ++v6;
  }
  while ( v5 < 16 );
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
  return v4;
}

// File Line: 3441
// RVA: 0x16F450
UFG::BlockInfo *__fastcall UFG::qVRAMemoryPools::GetBlock(unsigned __int16 block_id)
{
  UFG::BlockInfo *v2; // rbx

  v2 = 0i64;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMBlocksLock);
  if ( UFG::qVRAMemoryPools::sNumBlocksTotal && block_id < UFG::qVRAMemoryPools::sNumBlocksTotal )
    v2 = &UFG::qVRAMemoryPools::sBlocks[(unsigned __int64)block_id];
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMBlocksLock);
  return v2;
}

// File Line: 3461
// RVA: 0x172E90
UFG::BlockInfo *__fastcall UFG::qVRAMemoryPools::GetUnusedBlock()
{
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v0; // rbx
  unsigned __int16 v1; // ax
  unsigned __int16 v2; // cx
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *mNext; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *mPrev; // r8
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v5; // rdx

  v0 = 0i64;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMBlocksLock);
  if ( UFG::qVRAMemoryPools::sNumBlocksTotal )
  {
    v1 = UFG::qVRAMemoryPools::sUsedBlocksMax;
    v2 = ++UFG::qVRAMemoryPools::sUsedBlocksCount;
    if ( UFG::qVRAMemoryPools::sUsedBlocksCount > UFG::qVRAMemoryPools::sUsedBlocksMax )
      v1 = v2;
    UFG::qVRAMemoryPools::sUsedBlocksMax = v1;
    mNext = UFG::qVRAMemoryPools::sUnusedBlocks.mNode.mNext;
    if ( (UFG::qList<UFG::BlockInfo,UFG::Primary,1,0> *)UFG::qVRAMemoryPools::sUnusedBlocks.mNode.mNext != &UFG::qVRAMemoryPools::sUnusedBlocks )
    {
      mPrev = UFG::qVRAMemoryPools::sUnusedBlocks.mNode.mNext->mPrev;
      v5 = UFG::qVRAMemoryPools::sUnusedBlocks.mNode.mNext->mNext;
      v0 = UFG::qVRAMemoryPools::sUnusedBlocks.mNode.mNext;
      mPrev->mNext = v5;
      v5->mPrev = mPrev;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
    }
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMBlocksLock);
  return (UFG::BlockInfo *)v0;
}

// File Line: 3485
// RVA: 0x17BC60
void __fastcall UFG::qVRAMemoryPools::ReturnUsedBlock(UFG::BlockInfo *block)
{
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *mNext; // rax

  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMBlocksLock);
  if ( UFG::qVRAMemoryPools::sNumBlocksTotal )
  {
    --UFG::qVRAMemoryPools::sUsedBlocksCount;
    mNext = UFG::qVRAMemoryPools::sUnusedBlocks.mNode.mNext;
    UFG::qVRAMemoryPools::sUnusedBlocks.mNode.mNext = block;
    block->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mNext = mNext;
    block->UFG::qNode<UFG::BlockInfo,UFG::Primary>::mPrev = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&UFG::qVRAMemoryPools::sUnusedBlocks;
    mNext->mPrev = block;
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMBlocksLock);
}

