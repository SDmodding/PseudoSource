// File Line: 106
// RVA: 0x1467BB0
__int64 UFG::_dynamic_initializer_for__VRAMChannel__()
{
  UFG::VRAMChannel.mLogFilename.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&UFG::VRAMChannel.mLogFilename.mPrev;
  UFG::VRAMChannel.mLogFilename.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&UFG::VRAMChannel.mLogFilename.mPrev;
  *(_QWORD *)&UFG::VRAMChannel.mLogFilename.mMagic = 16909060i64;
  UFG::VRAMChannel.mLogFilename.mData = (char *)UFG::qString::sEmptyString;
  *(_QWORD *)&UFG::VRAMChannel.mLogFilename.mStringHash32 = -1i64;
  return atexit(UFG::_dynamic_atexit_destructor_for__VRAMChannel__);
}

// File Line: 116
// RVA: 0x1623A0
void __fastcall UFG::qVRAMemoryHandle::qVRAMemoryHandle(UFG::qVRAMemoryHandle *this)
{
  this->mPrev = (UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *)&this->mPrev;
  this->mData = 0i64;
  *(_DWORD *)&this->mReadOnlyAndPoolID = 0;
  UFG::qPrintChannel::Print(
    &UFG::VRAMChannel,
    OUTPUT_LEVEL_DEBUG,
    "[VRAM Channel] - Creating new empty qVRAMemoryHandle(%p)\n");
}

// File Line: 122
// RVA: 0x1622A0
UFG::qVRAMemoryHandle::qVRAMemoryHandle

// File Line: 137
// RVA: 0x164800
UFG::qVRAMemoryHandle *__fastcall UFG::qVRAMemoryHandle::operator=(UFG::qVRAMemoryHandle *this, UFG::qVRAMemoryHandle *handle)
{
  UFG::qVRAMemoryHandle *v2; // r14
  UFG::qVRAMemoryHandle *v3; // rsi
  char *v4; // rbx
  signed __int64 v5; // ST40_8
  char *v6; // ST38_8
  int v7; // ST30_4
  int v8; // ST28_4
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v9; // rax

  v2 = this;
  v3 = handle;
  UFG::qVRAMemoryPools::GetAllocatedSize(handle);
  v4 = v3->mData;
  v5 = (signed __int64)&v4[UFG::qVRAMemoryPools::GetAllocatedSize(v3) - 1];
  v6 = v3->mData;
  v7 = v3->mBlockID;
  v8 = v3->mReadOnlyAndPoolID & 0x7FFF;
  UFG::qPrintChannel::Print(
    &UFG::VRAMChannel,
    OUTPUT_LEVEL_DEBUG,
    "[VRAM Channel] - Assigning qVRAMemoryHandle(%p) from existing handle(%p) - PoolID:0x%02x BlockID:0x%04x Data:%p-%p A"
    "llocatedSize:%u\n");
  UFG::qVRAMemoryHandle::Close(v2);
  if ( (UFG::qVRAMemoryHandle *)v3->mPrev != v3 || (UFG::qVRAMemoryHandle *)v3->mNext != v3 )
  {
    if ( v3->mData )
    {
      v9 = v3->mNext;
      v3->mNext = (UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *)&v2->mPrev;
      v2->mPrev = (UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *)&v3->mPrev;
      v2->mNext = v9;
      v9->mPrev = (UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *)&v2->mPrev;
      v2->mData = v3->mData;
      v2->mReadOnlyAndPoolID = v3->mReadOnlyAndPoolID;
      v2->mBlockID = v3->mBlockID;
    }
  }
  return v2;
}

// File Line: 157
// RVA: 0x164550
void __fastcall UFG::qVRAMemoryHandle::~qVRAMemoryHandle(UFG::qVRAMemoryHandle *this)
{
  UFG::qVRAMemoryHandle *v1; // rsi
  char *v2; // rbx
  signed __int64 v3; // ST38_8
  char *v4; // ST30_8
  int v5; // ST28_4
  int v6; // ST20_4
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v7; // rcx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v8; // rax

  v1 = this;
  UFG::qVRAMemoryPools::GetAllocatedSize(this);
  v2 = v1->mData;
  v3 = (signed __int64)&v2[UFG::qVRAMemoryPools::GetAllocatedSize(v1) - 1];
  v4 = v1->mData;
  v5 = v1->mBlockID;
  v6 = v1->mReadOnlyAndPoolID & 0x7FFF;
  UFG::qPrintChannel::Print(
    &UFG::VRAMChannel,
    OUTPUT_LEVEL_DEBUG,
    "[VRAM Channel] - Deleting qVRAMemoryHandle(%p) was pointing at - PoolID:0x%02x BlockID:0x%04x Data:%p-%p AllocatedSize:%u\n");
  UFG::qVRAMemoryHandle::Close(v1);
  v7 = v1->mPrev;
  v8 = v1->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v1->mPrev = (UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *)&v1->mPrev;
}

// File Line: 170
// RVA: 0x16F2E0
unsigned int __fastcall UFG::qVRAMemoryHandle::GetAllocatedSize(UFG::qVRAMemoryHandle *this)
{
  return UFG::qVRAMemoryPools::GetAllocatedSize(this);
}

// File Line: 180
// RVA: 0x1772B0
bool __fastcall UFG::qVRAMemoryHandle::Lock(UFG::qVRAMemoryHandle *this)
{
  return UFG::qVRAMemoryPools::Lock(this);
}

// File Line: 185
// RVA: 0x17F370
bool __fastcall UFG::qVRAMemoryHandle::Unlock(UFG::qVRAMemoryHandle *this)
{
  return UFG::qVRAMemoryPools::Unlock(this);
}

// File Line: 190
// RVA: 0x168110
void __fastcall UFG::qVRAMemoryHandle::Close(UFG::qVRAMemoryHandle *this)
{
  UFG::qVRAMemoryHandle *v1; // rsi
  char *v2; // rbx
  signed __int64 v3; // ST38_8
  char *v4; // ST30_8
  int v5; // ST28_4
  int v6; // ST20_4
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v7; // rax
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v8; // rcx

  v1 = this;
  UFG::qVRAMemoryPools::GetAllocatedSize(this);
  v2 = v1->mData;
  v3 = (signed __int64)&v2[UFG::qVRAMemoryPools::GetAllocatedSize(v1) - 1];
  v4 = v1->mData;
  v5 = v1->mBlockID;
  v6 = v1->mReadOnlyAndPoolID & 0x7FFF;
  UFG::qPrintChannel::Print(
    &UFG::VRAMChannel,
    OUTPUT_LEVEL_DEBUG,
    "[VRAM Channel] - Closing qVRAMemoryHandle(%p) was pointing at - PoolID:0x%02x BlockID:0x%04x Data:%p-%p AllocatedSize:%u\n");
  if ( v1->mData )
  {
    v7 = v1->mNext;
    v8 = v1->mPrev;
    v8->mNext = v7;
    v7->mPrev = v8;
    v1->mPrev = (UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *)&v1->mPrev;
    v1->mNext = (UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *)&v1->mPrev;
    v1->mData = 0i64;
    *(_DWORD *)&v1->mReadOnlyAndPoolID = 0;
  }
}

// File Line: 210
// RVA: 0x17CB70
void __fastcall UFG::qVRAMemoryHandle::Set(UFG::qVRAMemoryHandle *this, char *data, unsigned int size, unsigned __int16 pool_id, unsigned __int16 block_id)
{
  unsigned __int16 v5; // bp
  UFG::qVRAMemoryHandle *v6; // rsi
  char *v7; // rdi
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v8; // rcx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v9; // rax

  v5 = pool_id;
  v6 = this;
  v7 = data;
  UFG::qPrintChannel::Print(
    &UFG::VRAMChannel,
    OUTPUT_LEVEL_DEBUG,
    "[VRAM Channel] - Setting qVRAMemoryHandle(%p) to point at - PoolID:0x%02x BlockID:0x%04x Data:%p-%p AllocatedSize:%u\n");
  v8 = v6->mPrev;
  v9 = v6->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v6->mReadOnlyAndPoolID = v5;
  v6->mBlockID = block_id;
  v6->mPrev = (UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *)&v6->mPrev;
  v6->mNext = (UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *)&v6->mPrev;
  v6->mData = v7;
}

// File Line: 260
// RVA: 0x15FED0
void __fastcall UFG::BlockInfo::BlockInfo(UFG::BlockInfo *this)
{
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v1; // rax
  UFG::qList<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly,1,0> *v2; // [rsp+28h] [rbp+10h]
  UFG::qList<UFG::BlockInfo,UFG::Primary,1,0> *v3; // [rsp+28h] [rbp+10h]

  this->mPrev = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&this->mPrev;
  v1 = (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  v2 = &this->mAllocationHandles;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  this->mData = 0i64;
  this->mName = 0i64;
  *(_QWORD *)&this->mRequestedSize = 0i64;
  *(_DWORD *)&this->mBlockID = 0xFFFF;
  *(_WORD *)&this->mKeepAliveFrames = 0;
  this->mMemoryPool = 0i64;
  v3 = &this->mContainedBlocks;
  v3->mNode.mPrev = &v3->mNode;
  v3->mNode.mNext = &v3->mNode;
  *(_DWORD *)&this->mContainerID = -1;
  this->mCallbackData64 = 0i64;
  this->mCallbackData32 = 0;
}

// File Line: 265
// RVA: 0x162D00
UFG::BlockInfo::~BlockInfo

// File Line: 270
// RVA: 0x17CF20
void __fastcall UFG::BlockInfo::SetFree(UFG::BlockInfo *this)
{
  unsigned int v1; // edi
  char *v2; // rbx
  __int64 v3; // r9
  UFG::BlockInfo *v4; // rsi

  v1 = this->mActualSize;
  v2 = this->mData;
  v3 = this->mBlockID;
  v4 = this;
  UFG::qPrintChannel::Print(
    &UFG::VRAMChannel,
    OUTPUT_LEVEL_DEBUG,
    "[VRAM Channel] - Setting Block ID:0x%04x to free data:%p size:0x%08x (%9u)\n");
  v4->mName = "Free VRAM";
  v4->mData = v2;
  v4->mRequestedSize = v1;
  v4->mActualSize = v1;
  v4->mMemoryPool = 0i64;
  v4->mContainerID = 0;
  v4->mCallbackData64 = 0i64;
  v4->mCallbackData32 = 0;
  *(_DWORD *)&v4->mUsage = 1;
}

// File Line: 447
// RVA: 0x16B9B0
void __fastcall UFG::BlockInfo::DefragmentMovedTo(UFG::BlockInfo *this, char *new_location)
{
  __int64 v2; // r9
  UFG::BlockInfo *v3; // rdi
  char *v4; // rbx
  char *v5; // ST20_8
  UFG::BlockInfo *v6; // rcx
  int v7; // er8
  UFG::BlockInfo *v8; // rbx
  signed __int64 v9; // rdi
  __int64 v10; // rsi

  v2 = this->mBlockID;
  v3 = this;
  v4 = new_location;
  v5 = this->mData;
  UFG::qPrintChannel::Print(
    &UFG::VRAMChannel,
    OUTPUT_LEVEL_NORMAL,
    "[VRAM Channel] - Moving Block ID:0x%04x from %p to %p\n");
  v6 = (UFG::BlockInfo *)v3->mAllocationHandles.mNode.mNext;
  v7 = (_DWORD)v4 - LODWORD(v3->mData);
  for ( v3->mData = v4; v6 != (UFG::BlockInfo *)&v3->mAllocationHandles; v6 = (UFG::BlockInfo *)v6->mNext )
    v6->mPrev = (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)v3->mData;
  if ( (unsigned __int8)(v3->mUsage - 9) <= 1u )
  {
    v8 = (UFG::BlockInfo *)v3->mContainedBlocks.mNode.mNext;
    v9 = (signed __int64)&v3->mContainedBlocks;
    if ( v8 != (UFG::BlockInfo *)v9 )
    {
      v10 = v7;
      do
      {
        UFG::BlockInfo::DefragmentMovedTo(v8, &v8->mData[v10]);
        v8 = (UFG::BlockInfo *)v8->mNext;
      }
      while ( v8 != (UFG::BlockInfo *)v9 );
    }
  }
}

// File Line: 501
// RVA: 0x178CD0
void __fastcall UFG::BlockInfo::Print(UFG::BlockInfo *this, bool print_container_contents)
{
  unsigned __int8 v2; // al
  bool v3; // bl
  UFG::BlockInfo *v4; // rdi
  const char *v5; // r10
  UFG::BlockInfo *v6; // rbx
  signed __int64 i; // rdi
  __int64 v8; // [rsp+20h] [rbp-38h]
  __int64 v9; // [rsp+28h] [rbp-30h]
  __int64 v10; // [rsp+30h] [rbp-28h]

  v2 = this->mUsage;
  v3 = print_container_contents;
  v4 = this;
  if ( v2 == 11 )
  {
    LODWORD(v10) = 21;
    LODWORD(v9) = this->mActualSize;
    LODWORD(v8) = this->mRequestedSize;
    UFG::qPrintf(
      "      BlockID:%05u [%p - %p] %9u bytes requested %9u bytes allocated type(%*s) name:(%.64s)\n",
      this->mBlockID,
      this->mData,
      &this->mData[this->mRequestedSize - 1],
      v8,
      v9,
      v10,
      off_14203C4E8[0],
      this->mName);
  }
  else
  {
    if ( v2 > 0x12u )
      v5 = "Unknown VRAMType";
    else
      v5 = off_14203C490[v2];
    LODWORD(v10) = 21;
    LODWORD(v9) = this->mActualSize;
    LODWORD(v8) = this->mRequestedSize;
    UFG::qPrintf(
      "    BlockID  :%05u [%p - %p] %9u bytes requested %9u bytes allocated type(%*s) name:(%.64s)\n",
      this->mBlockID,
      this->mData,
      &this->mData[this->mActualSize - 1],
      v8,
      v9,
      v10,
      v5,
      this->mName);
  }
  if ( v3 == 1 )
  {
    v6 = (UFG::BlockInfo *)v4->mContainedBlocks.mNode.mNext;
    for ( i = (signed __int64)&v4->mContainedBlocks; v6 != (UFG::BlockInfo *)i; v6 = (UFG::BlockInfo *)v6->mNext )
      UFG::BlockInfo::Print(v6, 1);
  }
}

// File Line: 579
// RVA: 0x1623F0
void __fastcall UFG::qVRAMemoryPool::qVRAMemoryPool(UFG::qVRAMemoryPool *this)
{
  UFG::qVRAMemoryPool *v1; // rbx
  const char *v2; // rdx
  signed int v3; // er8
  char *v4; // rax
  char v5; // cl
  UFG::qVRAMemoryHandle *v6; // [rsp+48h] [rbp+10h]
  UFG::qList<UFG::BlockInfo,UFG::Primary,1,0> *v7; // [rsp+48h] [rbp+10h]
  UFG::qList<UFG::BlockInfo,UFG::Primary,1,0> *v8; // [rsp+48h] [rbp+10h]
  UFG::qList<UFG::BlockInfo,UFG::Primary,1,0> *v9; // [rsp+48h] [rbp+10h]
  UFG::qList<UFG::BlockInfo,UFG::Secondary,1,0> *v10; // [rsp+48h] [rbp+10h]
  UFG::qList<UFG::BlockInfo,UFG::Secondary,1,0> *v11; // [rsp+48h] [rbp+10h]
  UFG::qList<UFG::BlockInfo,UFG::Secondary,1,0> *v12; // [rsp+48h] [rbp+10h]
  UFG::qList<UFG::BlockInfo,UFG::Secondary,1,0> *v13; // [rsp+48h] [rbp+10h]

  v1 = this;
  this->mPrev = (UFG::qNode<UFG::qVRAMemoryPool,UFG::qVRAMemoryPool> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::qVRAMemoryPool,UFG::qVRAMemoryPool> *)&this->mPrev;
  UFG::qMutex::qMutex(&this->mPoolLock, &customWorldMapCaption);
  v6 = &v1->mPoolMemory;
  v6->mPrev = (UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *)&v6->mPrev;
  v6->mNext = (UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *)&v6->mPrev;
  v1->mPoolMemory.mData = 0i64;
  *(_DWORD *)&v1->mPoolMemory.mReadOnlyAndPoolID = 0;
  UFG::qPrintChannel::Print(
    &UFG::VRAMChannel,
    OUTPUT_LEVEL_DEBUG,
    "[VRAM Channel] - Creating new empty qVRAMemoryHandle(%p)\n");
  v1->mVRAMemoryStart = 0i64;
  v1->mVRAMemorySize = 0;
  v1->mMainMemoryPool = 0i64;
  v1->mOverflowVRAM = 0i64;
  v1->mOverflowMain = 0i64;
  v7 = &v1->mUnusedBlocks;
  v7->mNode.mPrev = &v7->mNode;
  v7->mNode.mNext = &v7->mNode;
  v8 = &v1->mMainMemoryBlocks;
  v8->mNode.mPrev = &v8->mNode;
  v8->mNode.mNext = &v8->mNode;
  v9 = &v1->mUsedBlocks;
  v9->mNode.mPrev = &v9->mNode;
  v9->mNode.mNext = &v9->mNode;
  v10 = &v1->mFreeList;
  v10->mNode.mPrev = &v10->mNode;
  v10->mNode.mNext = &v10->mNode;
  v11 = &v1->mPendingFreeList;
  v11->mNode.mPrev = &v11->mNode;
  v11->mNode.mNext = &v11->mNode;
  v12 = &v1->mMoveTargetsList;
  v12->mNode.mPrev = &v12->mNode;
  v12->mNode.mNext = &v12->mNode;
  v13 = &v1->mContainerList;
  v13->mNode.mPrev = &v13->mNode;
  v13->mNode.mNext = &v13->mNode;
  v1->mBlocks = 0i64;
  v1->mBlocksMemory = 0i64;
  v1->mBlocksMemorySize = 0;
  v1->mNumBlocksTotal = -1;
  *(_QWORD *)&v1->mMinAlignment = 256i64;
  *(_QWORD *)&v1->mLargestFreeBlock = 0i64;
  *(_QWORD *)&v1->mPeakUsedMemory = 0i64;
  *(_QWORD *)&v1->mAlignmentLoss = 0i64;
  *(_QWORD *)&v1->mUsedBlocksCount = 0i64;
  v1->mPoolID = -1;
  v1->mDefragFreeFrameDelay = 2;
  *(_DWORD *)&v1->mDefragAllowed = 1;
  v1->mValidate = 0;
  v2 = UFG::qVRAMemoryPool::sUninitializedName;
  v3 = 32;
  v4 = v1->mName;
  if ( v1 != (UFG::qVRAMemoryPool *)-312i64 )
  {
    if ( !UFG::qVRAMemoryPool::sUninitializedName )
      goto LABEL_9;
    do
    {
      v5 = *v2;
      *v4++ = *v2++;
      if ( !v5 )
        break;
      --v3;
    }
    while ( v3 > 1 );
    if ( *(v4 - 1) )
LABEL_9:
      *v4 = 0;
  }
}

// File Line: 584
// RVA: 0x164610
void __fastcall UFG::qVRAMemoryPool::~qVRAMemoryPool(UFG::qVRAMemoryPool *this)
{
  UFG::qVRAMemoryPool *v1; // rdi
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v2; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v3; // rax
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

  v1 = this;
  UFG::qVRAMemoryPool::Close(this);
  UFG::qList<UFG::BlockInfo,UFG::Secondary,1,0>::DeleteNodes(&v1->mContainerList);
  v2 = v1->mContainerList.mNode.mPrev;
  v3 = v1->mContainerList.mNode.mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->mContainerList.mNode.mPrev = &v1->mContainerList.mNode;
  v1->mContainerList.mNode.mNext = &v1->mContainerList.mNode;
  UFG::qList<UFG::BlockInfo,UFG::Secondary,1,0>::DeleteNodes(&v1->mMoveTargetsList);
  v4 = v1->mMoveTargetsList.mNode.mPrev;
  v5 = v1->mMoveTargetsList.mNode.mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  v1->mMoveTargetsList.mNode.mPrev = &v1->mMoveTargetsList.mNode;
  v1->mMoveTargetsList.mNode.mNext = &v1->mMoveTargetsList.mNode;
  UFG::qList<UFG::BlockInfo,UFG::Secondary,1,0>::DeleteNodes(&v1->mPendingFreeList);
  v6 = v1->mPendingFreeList.mNode.mPrev;
  v7 = v1->mPendingFreeList.mNode.mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v1->mPendingFreeList.mNode.mPrev = &v1->mPendingFreeList.mNode;
  v1->mPendingFreeList.mNode.mNext = &v1->mPendingFreeList.mNode;
  UFG::qList<UFG::BlockInfo,UFG::Secondary,1,0>::DeleteNodes(&v1->mFreeList);
  v8 = v1->mFreeList.mNode.mPrev;
  v9 = v1->mFreeList.mNode.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v1->mFreeList.mNode.mPrev = &v1->mFreeList.mNode;
  v1->mFreeList.mNode.mNext = &v1->mFreeList.mNode;
  UFG::qList<UFG::BlockInfo,UFG::Primary,1,0>::DeleteNodes(&v1->mUsedBlocks);
  v10 = v1->mUsedBlocks.mNode.mPrev;
  v11 = v1->mUsedBlocks.mNode.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v1->mUsedBlocks.mNode.mPrev = &v1->mUsedBlocks.mNode;
  v1->mUsedBlocks.mNode.mNext = &v1->mUsedBlocks.mNode;
  UFG::qList<UFG::BlockInfo,UFG::Primary,1,0>::DeleteNodes(&v1->mMainMemoryBlocks);
  v12 = v1->mMainMemoryBlocks.mNode.mPrev;
  v13 = v1->mMainMemoryBlocks.mNode.mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  v1->mMainMemoryBlocks.mNode.mPrev = &v1->mMainMemoryBlocks.mNode;
  v1->mMainMemoryBlocks.mNode.mNext = &v1->mMainMemoryBlocks.mNode;
  UFG::qList<UFG::BlockInfo,UFG::Primary,1,0>::DeleteNodes(&v1->mUnusedBlocks);
  v14 = v1->mUnusedBlocks.mNode.mPrev;
  v15 = v1->mUnusedBlocks.mNode.mNext;
  v14->mNext = v15;
  v15->mPrev = v14;
  v1->mUnusedBlocks.mNode.mPrev = &v1->mUnusedBlocks.mNode;
  v1->mUnusedBlocks.mNode.mNext = &v1->mUnusedBlocks.mNode;
  UFG::qVRAMemoryHandle::~qVRAMemoryHandle(&v1->mPoolMemory);
  Scaleform::Lock::~Lock((LPCRITICAL_SECTION)&v1->mPoolLock);
  v16 = v1->mPrev;
  v17 = v1->mNext;
  v16->mNext = v17;
  v17->mPrev = v16;
  v1->mPrev = (UFG::qNode<UFG::qVRAMemoryPool,UFG::qVRAMemoryPool> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::qVRAMemoryPool,UFG::qVRAMemoryPool> *)&v1->mPrev;
}

// File Line: 602
// RVA: 0x173750
_BOOL8 __fastcall UFG::qVRAMemoryPool::Init(UFG::qVRAMemoryPool *this, char *vram_start, unsigned int vram_size, const char *name, unsigned __int16 num_blocks, unsigned int min_alignment, char *block_memory, unsigned int block_memory_size)
{
  signed int v8; // ebp
  signed __int16 v9; // r14
  __int64 v10; // rbx
  UFG::qVRAMemoryPool *v11; // rsi
  char *v12; // rdi
  bool v13; // r15
  unsigned __int16 v14; // ax
  signed __int64 v15; // r10
  unsigned int v16; // edx
  char *v18; // [rsp+20h] [rbp-68h]
  __int64 v19; // [rsp+38h] [rbp-50h]
  _QWORD v20[4]; // [rsp+40h] [rbp-48h]
  __int64 v21; // [rsp+50h] [rbp-38h]
  __int64 v22; // [rsp+58h] [rbp-30h]
  char *namea; // [rsp+A8h] [rbp+20h]

  namea = (char *)name;
  v8 = min_alignment;
  v9 = num_blocks;
  LODWORD(v22) = block_memory_size;
  LODWORD(v21) = block_memory_size;
  v10 = vram_size;
  v11 = this;
  v12 = vram_start;
  UFG::qPrintChannel::Print(
    &UFG::VRAMChannel,
    OUTPUT_LEVEL_WARNING,
    "[VRAM Channel] - Init(%p, 0x%08x(%u), '%.64s', %u, %u, %p, 0x%08x(%u))\n");
  v13 = 0;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&v11->mPoolLock);
  UFG::qVRAMemoryPool::AssertValid(v11);
  v14 = -1;
  if ( num_blocks > 0xFFFFu )
    v9 = -1;
  if ( min_alignment < 0x100 )
    v8 = 256;
  if ( v11->mInitialized != 1 )
  {
    if ( !block_memory )
      goto LABEL_20;
    if ( (unsigned __int16)v9 <= 0xFFFFu )
      v14 = v9;
    if ( block_memory_size >= (unsigned int)v14 << 7 )
    {
LABEL_20:
      if ( v12 && (_DWORD)v10 && !UFG::qVRAMemoryPools::OverlapsPool(v12, v10) )
      {
        v15 = ~(v8 - 1i64) & (unsigned __int64)&v12[v8 - 1];
        v11->mVRAMemoryStart = (char *)v15;
        v16 = ~(v8 - 1) & (v10 + (_DWORD)v12 - v15);
        v11->mVRAMemorySize = v16;
        if ( (char *)v15 != v12 || v16 != (_DWORD)v10 )
        {
          LODWORD(v20[0]) = ~(v8 - 1) & (v10 + (_DWORD)v12 - v15);
          LODWORD(v19) = ~(v8 - 1) & (v10 + (_DWORD)v12 - v15);
          LODWORD(v18) = v10;
          UFG::qPrintf(
            "Passed in memory %p-%p of size %d (0x%08x) aligned down to %p-%p of size %d (0x%08x)\n",
            v12,
            &v12[v10 - 1],
            (unsigned int)v10,
            v18,
            ~(v8 - 1i64) & (unsigned __int64)&v12[v8 - 1],
            v16 + v15 - 1,
            v19,
            v20[0],
            block_memory,
            v21,
            v22);
        }
        v13 = UFG::qVRAMemoryPool::CommonInit(v11, namea, v9, v8, block_memory, block_memory_size);
      }
    }
  }
  UFG::qVRAMemoryPool::AssertValid(v11);
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v11->mPoolLock);
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
  return v13;
}

// File Line: 748
// RVA: 0x1681C0
void __fastcall UFG::qVRAMemoryPool::Close(UFG::qVRAMemoryPool *this)
{
  char *v1; // rdi
  UFG::qVRAMemoryPool *v2; // rbx
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v3; // rdx
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v4; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v5; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v6; // rdx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v7; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v8; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v9; // rdx
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v10; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v11; // rax
  UFG::BlockInfo *v12; // rcx
  unsigned int *v13; // rsi
  const char *v14; // rdx
  signed int v15; // ecx
  char v16; // al

  v1 = this->mName;
  v2 = this;
  UFG::qPrintChannel::Print(&UFG::VRAMChannel, OUTPUT_LEVEL_WARNING, "[VRAM Channel] - '%.64s'->Close()\n");
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&v2->mPoolLock);
  UFG::qVRAMemoryPool::AssertValid(v2);
  if ( v2->mInitialized == 1 )
  {
    UFG::qVRAMemoryPool::ForceEmptyPool(v2);
    if ( v2->mPoolMemory.mData )
      UFG::qVRAMemoryPools::Free(&v2->mPoolMemory, 0);
    v3 = v2->mUsedBlocks.mNode.mNext;
    v2->mVRAMemoryStart = 0i64;
    v2->mVRAMemorySize = 0;
    v2->mMainMemoryPool = 0i64;
    v2->mOverflowVRAM = 0i64;
    v2->mOverflowMain = 0i64;
    v4 = v3->mPrev;
    v5 = v3->mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v3->mPrev = v3;
    v3->mNext = v3;
    v6 = v2->mFreeList.mNode.mNext;
    v7 = v6->mPrev;
    v8 = v6->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v6->mPrev = v6;
    for ( v6->mNext = v6;
          (UFG::qList<UFG::BlockInfo,UFG::Primary,1,0> *)v2->mUnusedBlocks.mNode.mNext != &v2->mUnusedBlocks;
          v9->mNext = v9 )
    {
      v9 = v2->mUnusedBlocks.mNode.mNext;
      v10 = v9->mPrev;
      v11 = v9->mNext;
      v10->mNext = v11;
      v11->mPrev = v10;
      v9->mPrev = v9;
    }
    if ( !v2->mBlocksMemory )
    {
      v12 = v2->mBlocks;
      if ( v12 )
      {
        v13 = &v12[-1].mCallbackData32;
        `eh vector destructor iterator'(
          v12,
          0x80ui64,
          v12[-1].mCallbackData32,
          (void (__fastcall *)(void *))UFG::BlockInfo::~BlockInfo);
        if ( v13 )
          UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v13);
      }
    }
    v2->mBlocks = 0i64;
    v2->mBlocksMemory = 0i64;
    v2->mBlocksMemorySize = 0;
    *(_QWORD *)&v2->mMinAlignment = 256i64;
    *(_QWORD *)&v2->mLargestFreeBlock = 0i64;
    v2->mNumBlocksTotal = -1;
    *(_QWORD *)&v2->mPeakUsedMemory = 0i64;
    *(_QWORD *)&v2->mAlignmentLoss = 0i64;
    *(_QWORD *)&v2->mUsedBlocksCount = 0i64;
    v14 = UFG::qVRAMemoryPool::sUninitializedName;
    v15 = 32;
    if ( v1 )
    {
      if ( !UFG::qVRAMemoryPool::sUninitializedName )
        goto LABEL_20;
      do
      {
        v16 = *v14;
        ++v1;
        ++v14;
        *(v1 - 1) = v16;
        if ( !v16 )
          break;
        --v15;
      }
      while ( v15 > 1 );
      if ( *(v1 - 1) )
LABEL_20:
        *v1 = 0;
    }
    UFG::qVRAMemoryPools::sVRAMemoryPools[v2->mPoolID] = 0i64;
    *(_WORD *)&v2->mNeedsDefragmentUp = 0;
    v2->mInitialized = 0;
    v2->mPoolID = -1;
  }
  UFG::qVRAMemoryPool::AssertValid(v2);
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v2->mPoolLock);
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
}

// File Line: 879
// RVA: 0x16E2A0
char __fastcall UFG::qVRAMemoryPool::ForceEmptyPool(UFG::qVRAMemoryPool *this)
{
  UFG::qVRAMemoryPool *v1; // rbx
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v2; // rax
  bool v3; // cl
  bool v4; // zf
  UFG::BlockInfo *v5; // rdx

  v1 = this;
  UFG::qPrintChannel::Print(&UFG::VRAMChannel, OUTPUT_LEVEL_WARNING, "[VRAM Channel] - '%.64s'->ForceEmptyPool()\n");
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&v1->mPoolLock);
  UFG::qVRAMemoryPool::AssertValid(v1);
  if ( v1->mInitialized == 1 )
  {
    v2 = v1->mUsedBlocks.mNode.mNext;
    v3 = BYTE2(v2[4].mNext) == 1;
    if ( v2 != v1->mUsedBlocks.mNode.mPrev || v3 != 1 )
    {
      while ( 1 )
      {
        v4 = v3 == 1;
        while ( 1 )
        {
          v5 = (UFG::BlockInfo *)(v4 ? v2->mNext : v2);
          UFG::qVRAMemoryPool::InternalFree(v1, v5);
          v2 = v1->mUsedBlocks.mNode.mNext;
          v3 = BYTE2(v2[4].mNext) == 1;
          if ( v2 != v1->mUsedBlocks.mNode.mPrev )
            break;
          v4 = v3 == 1;
          if ( v3 == 1 )
            goto LABEL_10;
        }
      }
    }
  }
LABEL_10:
  UFG::qVRAMemoryPool::AssertValid(v1);
  return 1;
}

// File Line: 919
// RVA: 0x166D30
_BOOL8 __fastcall UFG::qVRAMemoryPool::Allocate(UFG::qVRAMemoryPool *this, UFG::qVRAMemoryHandle *handle, unsigned int size, unsigned int usage, const char *name, unsigned int alignment, char flags, UFG::qMemoryPool *pool, unsigned __int64 user_data_64, unsigned int user_data_32)
{
  unsigned __int64 v10; // rsi
  UFG::qVRAMemoryHandle *v11; // rbx
  UFG::qVRAMemoryPool *v12; // rbp
  const char *v13; // rcx
  char *v14; // rdx
  char v15; // di
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v16; // rcx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v17; // rax
  signed int v18; // ebx
  UFG::BlockInfo *v19; // r10
  signed __int64 v20; // rax
  UFG::BlockInfo *v21; // rdi
  unsigned int v22; // er11
  unsigned int v23; // er8
  UFG::BlockInfo *v24; // rdi
  unsigned int v25; // er11
  unsigned int v26; // er8
  char i; // al
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v28; // rdx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v29; // rax
  char *v30; // rbx
  unsigned __int16 v31; // si
  unsigned __int16 v32; // di
  UFG::qMemoryPool *v33; // ST38_8
  UFG::qVRAMemoryHandle *v34; // r8
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v35; // rcx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v36; // rax
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v37; // rax
  unsigned int v38; // eax
  UFG::qMemoryPool *v39; // rcx
  unsigned __int64 v40; // r9
  UFG::BlockInfo *v41; // rax
  char v42; // cl
  UFG::BlockInfo *v43; // rdi
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v44; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v45; // rax
  UFG::qVRAMemoryPool *v46; // rcx
  UFG::qMemoryPool *v47; // rcx
  UFG::BlockInfo *v48; // rax
  UFG::qMemoryPool *v49; // r8
  char v50; // cl
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v51; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v52; // rdx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v53; // rax
  unsigned int v54; // ST28_4
  unsigned int v55; // ST20_4
  signed __int64 v56; // ST30_8
  char *v58; // [rsp+80h] [rbp-38h]
  UFG::BlockInfo *v59; // [rsp+88h] [rbp-30h]
  UFG::qMemoryPool *v60; // [rsp+88h] [rbp-30h]
  bool v61; // [rsp+C0h] [rbp+8h]
  UFG::qVRAMemoryHandle *handlea; // [rsp+C8h] [rbp+10h]
  unsigned int v63; // [rsp+D0h] [rbp+18h]
  unsigned int usagea; // [rsp+D8h] [rbp+20h]
  char *poola; // [rsp+F8h] [rbp+40h]

  usagea = usage;
  v63 = size;
  handlea = handle;
  v10 = size;
  v11 = handle;
  v12 = this;
  if ( pool )
    v13 = pool->mData->mAllocator.mName;
  if ( usage <= 0x12 )
    v14 = off_14203C490[usage];
  v15 = flags;
  UFG::qPrintChannel::Print(
    &UFG::VRAMChannel,
    OUTPUT_LEVEL_WARNING,
    "[VRAM Channel] - '%.64s'->Allocate(handle(%p), 0x%08x(%u), %s, '%.64s'%s, %u, 0x%08x, %s, 0x%016x64, 0x%08x)\n");
  v61 = 0;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&v12->mPoolLock);
  UFG::qVRAMemoryPool::AssertValid(v12);
  if ( !(_DWORD)v10 )
  {
    UFG::qPrintChannel::Print(
      &UFG::VRAMChannel,
      OUTPUT_LEVEL_ERROR,
      "[VRAM Channel]   Someone requested 0 bytes with name %.64s from pool '%.64s'\n");
    UFG::qPrintChannel::Print(
      &UFG::VRAMChannel,
      OUTPUT_LEVEL_DEBUG,
      "[VRAM Channel] - Setting qVRAMemoryHandle(%p) to point at - PoolID:0x%02x BlockID:0x%04x Data:%p-%p AllocatedSize:%u\n");
    v16 = v11->mPrev;
    v17 = v11->mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    v11->mPrev = (UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *)&v11->mPrev;
    v11->mNext = (UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *)&v11->mPrev;
    v11->mData = 0i64;
    *(_DWORD *)&v11->mReadOnlyAndPoolID = 0;
    goto LABEL_61;
  }
  if ( v12->mInitialized == 1 )
  {
    v18 = alignment;
    if ( v12->mMinAlignment > alignment )
      v18 = v12->mMinAlignment;
    if ( usagea == 14 )
    {
      v39 = pool;
      v60 = pool;
      if ( !pool )
      {
        v39 = UFG::gMainMemoryPool;
        if ( v12->mMainMemoryPool )
          v39 = v12->mMainMemoryPool;
        v60 = v39;
      }
      v40 = (unsigned __int64)(v18 & 0xFFFFFF) << 8;
      if ( flags & 2 )
        v40 |= 1ui64;
      v58 = (char *)UFG::qMemoryPool::Allocate(v39, v10, name, v40, 0);
      if ( v58 )
      {
        v41 = UFG::qVRAMemoryPool::GetUnusedBlock(v12);
        v42 = 0;
        v43 = v41;
        v41->mData = v58;
        v41->mName = name;
        v41->mRequestedSize = v10;
        for ( v41->mActualSize = v10; v18 != 1; ++v42 )
          v18 = (unsigned int)v18 >> 1;
        v11 = handlea;
        v41->mAlignmentShift = v42;
        v41->mUsage = 14;
        v41->mKeepAliveFrames = 0;
        v41->mFlags = flags | 0x10;
        v41->mMemoryPool = v60;
        v41->mContainerID = 0;
        v41->mCallbackData64 = user_data_64;
        v41->mCallbackData32 = user_data_32;
        UFG::qVRAMemoryHandle::Set(handlea, v58, v10, v12->mPoolID, v41->mBlockID);
        v44 = v43->mAllocationHandles.mNode.mPrev;
        v44->mNext = (UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *)&handlea->mPrev;
        handlea->mPrev = v44;
        handlea->mNext = &v43->mAllocationHandles.mNode;
        v43->mAllocationHandles.mNode.mPrev = (UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *)&handlea->mPrev;
        goto LABEL_47;
      }
    }
    else
    {
      v19 = 0i64;
      v20 = (signed __int64)&v12->mUsedBlocks;
      v59 = 0i64;
      if ( flags & 1 )
      {
        v21 = (UFG::BlockInfo *)&v12->mFreeList.mNode.mNext[-1];
        while ( v21 != (UFG::BlockInfo *)v20 )
        {
          if ( v21->mUsage == 1 )
          {
            v22 = v21->mActualSize;
            if ( v22 >= (unsigned int)v10 )
            {
              v23 = ~(v12->mMinAlignment - 1) & (v12->mMinAlignment + v10 - 1);
              if ( (_QWORD)&v21->mData[v22 - (~(v18 - 1i64) & (_QWORD)&v21->mData[v18 - 1])] >= v23 )
              {
                v19 = UFG::qVRAMemoryPool::SplitFreeBlock(v12, v21, v23, v18, (unsigned __int8)flags);
                v59 = v19;
              }
              v20 = (signed __int64)&v12->mUsedBlocks;
            }
          }
          v21 = (UFG::BlockInfo *)&v21->mNext[-1];
          if ( v19 )
            goto LABEL_30;
        }
      }
      else
      {
        flags |= 2u;
        v24 = (UFG::BlockInfo *)&v12->mFreeList.mNode.mPrev[-1];
        while ( v24 != (UFG::BlockInfo *)v20 )
        {
          v25 = v24->mActualSize;
          if ( v25 >= (unsigned int)v10 )
          {
            v26 = ~(v12->mMinAlignment - 1) & (v12->mMinAlignment + v10 - 1);
            if ( (_QWORD)&v24->mData[v25 - (~(v18 - 1i64) & (_QWORD)&v24->mData[v18 - 1])] >= v26 )
            {
              v19 = UFG::qVRAMemoryPool::SplitFreeBlock(v12, v24, v26, v18, (unsigned __int8)flags);
              v59 = v19;
            }
            v20 = (signed __int64)&v12->mUsedBlocks;
          }
          v24 = (UFG::BlockInfo *)&v24->mPrev[-1];
          if ( v19 )
            goto LABEL_30;
        }
      }
      if ( v19 )
      {
LABEL_30:
        v19->mRequestedSize = v10;
        v19->mName = name;
        for ( i = 0; v18 != 1; ++i )
          v18 = (unsigned int)v18 >> 1;
        v19->mAlignmentShift = i;
        v19->mFlags = flags;
        v19->mUsage = usagea;
        v19->mMemoryPool = 0i64;
        v19->mContainerID = 0;
        v19->mCallbackData64 = user_data_64;
        v19->mKeepAliveFrames = 0;
        v19->mCallbackData32 = user_data_32;
        if ( usagea - 9 <= 1 )
        {
          v28 = (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)&v19->mPrev;
          v29 = v12->mContainerList.mNode.mNext;
          v12->mContainerList.mNode.mNext = (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)&v19->mPrev;
          v28->mPrev = &v12->mContainerList.mNode;
          v28->mNext = v29;
          v29->mPrev = (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)&v19->mPrev;
        }
        v30 = v19->mData;
        v31 = v19->mBlockID;
        v32 = v12->mPoolID;
        v33 = (UFG::qMemoryPool *)&v30[v19->mActualSize - 1];
        UFG::qPrintChannel::Print(
          &UFG::VRAMChannel,
          OUTPUT_LEVEL_DEBUG,
          "[VRAM Channel] - Setting qVRAMemoryHandle(%p) to point at - PoolID:0x%02x BlockID:0x%04x Data:%p-%p AllocatedSize:%u\n");
        v34 = handlea;
        v35 = handlea->mPrev;
        v36 = handlea->mNext;
        v35->mNext = v36;
        v36->mPrev = v35;
        v34->mPrev = (UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *)&v34->mPrev;
        v34->mNext = (UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *)&v34->mPrev;
        handlea->mData = v30;
        handlea->mReadOnlyAndPoolID = v32;
        handlea->mBlockID = v31;
        v37 = v59->mAllocationHandles.mNode.mPrev;
        v37->mNext = (UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *)&handlea->mPrev;
        handlea->mPrev = v37;
        handlea->mNext = &v59->mAllocationHandles.mNode;
        v59->mAllocationHandles.mNode.mPrev = (UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *)&handlea->mPrev;
        v12->mFreeMemory -= v59->mActualSize;
        v12->mUsedMemory += v59->mActualSize;
        v12->mAllocatedMemory += v59->mRequestedSize;
        v12->mAlignmentLoss += v59->mActualSize - v59->mRequestedSize;
        v38 = v12->mUsedMemory;
        if ( v38 > v12->mPeakUsedMemory )
          v12->mPeakUsedMemory = v38;
        LODWORD(v10) = v63;
        v61 = 1;
        goto LABEL_60;
      }
      v15 = flags;
    }
    v46 = v12->mOverflowVRAM;
    if ( v46 )
    {
      v61 = UFG::qVRAMemoryPool::Allocate(
              v46,
              handlea,
              v10,
              usagea,
              name,
              alignment,
              v15,
              pool,
              user_data_64,
              user_data_32);
      if ( v61 )
      {
LABEL_60:
        v11 = handlea;
        goto LABEL_61;
      }
    }
    v47 = v12->mOverflowMain;
    if ( !v47
      || (poola = (char *)UFG::qMemoryPool::Allocate(v47, v10, name, (unsigned __int64)(v18 & 0xFFFFFF) << 8, 0)) == 0i64 )
    {
      if ( v15 & 8 )
      {
        v54 = v12->mLargestFreeBlock;
        v55 = v12->mFreeMemory;
        UFG::qPrintChannel::Print(
          &UFG::VRAMChannel,
          OUTPUT_LEVEL_WARNING,
          "Pool '%s' (Free:%u Largest:%u) is too full for named allocation '%s' of size %u, allowable fail, try again next frame\n");
        v11 = handlea;
        goto LABEL_61;
      }
      UFG::qVRAMemoryPool::Print(v12, 5u);
      goto LABEL_60;
    }
    v48 = UFG::qVRAMemoryPool::GetUnusedBlock(v12);
    v49 = v12->mOverflowMain;
    v43 = v48;
    v48->mData = poola;
    v50 = 0;
    v48->mName = name;
    v48->mRequestedSize = v10;
    for ( v48->mActualSize = v10; v18 != 1; ++v50 )
      v18 = (unsigned int)v18 >> 1;
    v11 = handlea;
    v48->mAlignmentShift = v50;
    v48->mMemoryPool = v49;
    v48->mUsage = 15;
    v48->mFlags = flags | 0x10;
    v48->mKeepAliveFrames = 0;
    v48->mContainerID = 0;
    v48->mCallbackData64 = user_data_64;
    v48->mCallbackData32 = user_data_32;
    UFG::qVRAMemoryHandle::Set(handlea, poola, v10, v12->mPoolID, v48->mBlockID);
    v51 = v43->mAllocationHandles.mNode.mPrev;
    v51->mNext = (UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *)&handlea->mPrev;
    handlea->mPrev = v51;
    handlea->mNext = &v43->mAllocationHandles.mNode;
    v43->mAllocationHandles.mNode.mPrev = (UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *)&handlea->mPrev;
    if ( usagea - 9 <= 1 )
    {
      v52 = (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)&v43->mPrev;
      v53 = v12->mContainerList.mNode.mNext;
      v12->mContainerList.mNode.mNext = (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)&v43->mPrev;
      v52->mPrev = &v12->mContainerList.mNode;
      v52->mNext = v53;
      v53->mPrev = (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)&v43->mPrev;
    }
LABEL_47:
    v61 = 1;
    v45 = v12->mMainMemoryBlocks.mNode.mPrev;
    v45->mNext = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&v43->mPrev;
    v43->mPrev = v45;
    v43->mNext = &v12->mMainMemoryBlocks.mNode;
    v12->mMainMemoryBlocks.mNode.mPrev = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&v43->mPrev;
    v12->mUsedMainMemory += v10;
  }
LABEL_61:
  if ( v12->mValidate )
  {
    UFG::qPrintChannel::Print(&UFG::VRAMChannel, OUTPUT_LEVEL_WARNING, "[VRAM Channel] - '%.64s'->AssertValid()\n");
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&v12->mPoolLock);
    if ( v12->mInitialized == 1 )
      UFG::qVRAMemoryPool::AssertValidInitialized(v12);
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v12->mPoolLock);
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v12->mPoolLock);
  v56 = (signed __int64)&v11->mData[(unsigned int)v10 - 1];
  UFG::qPrintChannel::Print(
    &UFG::VRAMChannel,
    OUTPUT_LEVEL_WARNING,
    "[VRAM Channel] -   Allocated 0x%08x(%u) bytes at [%p - %p] named '%.64s' in pool '%.64s'\n");
  return v61;
}

// File Line: 1290
// RVA: 0x178B60
__int64 __fastcall UFG::qVRAMemoryPool::PreMove(UFG::qVRAMemoryPool *this, UFG::qVRAMemoryHandle *handle)
{
  UFG::qVRAMemoryPool *v2; // rdi
  UFG::qVRAMemoryHandle *v3; // rbx
  unsigned __int8 v4; // si
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // cx
  UFG::BlockInfo *v7; // rax
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v8; // rdx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v9; // rax

  v2 = this;
  v3 = handle;
  UFG::qPrintChannel::Print(&UFG::VRAMChannel, OUTPUT_LEVEL_WARNING, "[VRAM Channel] - '%.64s'->PreMove(handle(%p))\n");
  v4 = 0;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&v2->mPoolLock);
  UFG::qVRAMemoryPool::AssertValid(v2);
  if ( v2->mInitialized == 1 && (v3->mReadOnlyAndPoolID & 0x7FFF) == v2->mPoolID )
  {
    v5 = v2->mNumBlocksTotal;
    v6 = v3->mBlockID;
    if ( v5 )
    {
      if ( v6 >= v5 )
        goto LABEL_9;
      v7 = &v2->mBlocks[(unsigned __int64)v6];
    }
    else
    {
      v7 = UFG::qVRAMemoryPools::GetBlock(v6);
    }
    if ( v7 )
    {
      v8 = v3->mPrev;
      v9 = v3->mNext;
      v4 = 1;
      v8->mNext = v9;
      v9->mPrev = v8;
      v3->mPrev = (UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *)&v3->mPrev;
      v3->mNext = (UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *)&v3->mPrev;
    }
  }
LABEL_9:
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v2->mPoolLock);
  return v4;
}

// File Line: 1318
// RVA: 0x178990
__int64 __fastcall UFG::qVRAMemoryPool::PostMove(UFG::qVRAMemoryPool *this, UFG::qVRAMemoryHandle *handle)
{
  UFG::qVRAMemoryPool *v2; // rdi
  UFG::qVRAMemoryHandle *v3; // rbx
  unsigned __int8 v4; // si
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // cx
  UFG::BlockInfo *v7; // rax
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v8; // rdx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v9; // rax

  v2 = this;
  v3 = handle;
  UFG::qPrintChannel::Print(&UFG::VRAMChannel, OUTPUT_LEVEL_WARNING, "[VRAM Channel] - '%.64s'->PostMove(handle(%p))\n");
  v4 = 0;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&v2->mPoolLock);
  UFG::qVRAMemoryPool::AssertValid(v2);
  if ( v2->mInitialized == 1 && (v3->mReadOnlyAndPoolID & 0x7FFF) == v2->mPoolID )
  {
    v5 = v2->mNumBlocksTotal;
    v6 = v3->mBlockID;
    if ( v5 )
    {
      if ( v6 >= v5 )
        goto LABEL_9;
      v7 = &v2->mBlocks[(unsigned __int64)v6];
    }
    else
    {
      v7 = UFG::qVRAMemoryPools::GetBlock(v6);
    }
    if ( v7 )
    {
      v3->mPrev = (UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *)&v3->mPrev;
      v3->mNext = (UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *)&v3->mPrev;
      v8 = &v7->mAllocationHandles.mNode;
      v9 = v7->mAllocationHandles.mNode.mPrev;
      v4 = 1;
      v9->mNext = (UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *)&v3->mPrev;
      v3->mPrev = v9;
      v3->mNext = v8;
      v8->mPrev = (UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *)&v3->mPrev;
    }
  }
LABEL_9:
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v2->mPoolLock);
  return v4;
}

// File Line: 1347
// RVA: 0x16EA30
_BOOL8 __fastcall UFG::qVRAMemoryPool::Free(UFG::qVRAMemoryPool *this, UFG::qVRAMemoryHandle *handle, unsigned int frames_to_delay)
{
  unsigned int v3; // edi
  UFG::qVRAMemoryPool *v4; // rbp
  UFG::qVRAMemoryHandle *v5; // rbx
  bool v6; // r14
  unsigned __int16 v7; // ax
  unsigned __int16 v8; // cx
  UFG::BlockInfo *v9; // rsi
  char v10; // cl
  unsigned __int16 v11; // ax
  unsigned __int16 v12; // cx
  UFG::BlockInfo *v13; // rdi
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v14; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v15; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v16; // rdx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v17; // rax
  bool v18; // al
  signed int v19; // eax
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v20; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v21; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v22; // rdx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v23; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v24; // rax
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v25; // rcx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v26; // rax
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v27; // rcx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v28; // rax
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v29; // rbx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v30; // rcx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v31; // rax
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v32; // rcx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v33; // rax

  v3 = frames_to_delay;
  v4 = this;
  v5 = handle;
  UFG::qPrintChannel::Print(&UFG::VRAMChannel, OUTPUT_LEVEL_WARNING, "[VRAM Channel] - '%.64s'->Free(handle(%p), %u)\n");
  v6 = 0;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&v4->mPoolLock);
  UFG::qVRAMemoryPool::AssertValid(v4);
  if ( v4->mInitialized == 1 )
  {
    if ( (v5->mReadOnlyAndPoolID & 0x7FFF) != v4->mPoolID )
    {
      v18 = UFG::qVRAMemoryPools::Free(v5, v3);
      goto LABEL_32;
    }
    v7 = v4->mNumBlocksTotal;
    v8 = v5->mBlockID;
    if ( v7 )
    {
      if ( v8 >= v7 )
        goto LABEL_33;
      v9 = &v4->mBlocks[(unsigned __int64)v8];
    }
    else
    {
      v9 = UFG::qVRAMemoryPools::GetBlock(v8);
    }
    if ( v9 )
    {
      v10 = v9->mUsage;
      if ( v10 == 11 )
      {
        v11 = v4->mNumBlocksTotal;
        v12 = v9->mContainerID;
        v13 = 0i64;
        if ( v11 )
        {
          if ( v12 < v11 )
            v13 = &v4->mBlocks[(unsigned __int64)v12];
        }
        else
        {
          v13 = UFG::qVRAMemoryPools::GetBlock(v12);
        }
        v6 = UFG::qVRAMemoryPool::InternalFree(v4, v9);
        if ( v13->mUsage == 9
          && (UFG::qList<UFG::BlockInfo,UFG::Primary,1,0> *)v13->mContainedBlocks.mNode.mNext == &v13->mContainedBlocks )
        {
          if ( v13->mFlags & 0x40 )
          {
            v14 = v13->mPrev;
            v15 = v13->mNext;
            v16 = (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)&v13->mPrev;
            v14->mNext = v15;
            v15->mPrev = v14;
            v16->mPrev = v16;
            v16->mNext = v16;
            v13->mKeepAliveFrames = 1;
            v17 = v4->mPendingFreeList.mNode.mPrev;
            v17->mNext = (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)&v13->mPrev;
            v16->mNext = &v4->mPendingFreeList.mNode;
            v16->mPrev = v17;
            v4->mPendingFreeList.mNode.mPrev = (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)&v13->mPrev;
            UFG::qVRAMemoryHandle::Close(v5);
            v6 = 1;
            goto LABEL_33;
          }
          v18 = UFG::qVRAMemoryPool::InternalFree(v4, v13);
LABEL_32:
          v6 = v18;
          goto LABEL_33;
        }
      }
      else
      {
        if ( v9->mFlags & 0x40 )
        {
          v19 = 1;
          if ( v3 )
            v19 = v3;
          v3 = v19;
        }
        if ( !v3 )
        {
          v18 = UFG::qVRAMemoryPool::InternalFree(v4, v9);
          goto LABEL_32;
        }
        if ( (unsigned __int8)(v10 - 9) <= 1u )
        {
          v20 = v9->mPrev;
          v21 = v9->mNext;
          v22 = (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)&v9->mPrev;
          v20->mNext = v21;
          v21->mPrev = v20;
          v22->mPrev = v22;
          v22->mNext = v22;
        }
        v9->mKeepAliveFrames = v3;
        v23 = (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)&v9->mPrev;
        v24 = v4->mPendingFreeList.mNode.mPrev;
        v24->mNext = (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)&v9->mPrev;
        v23->mPrev = v24;
        v23->mNext = &v4->mPendingFreeList.mNode;
        v4->mPendingFreeList.mNode.mPrev = (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)&v9->mPrev;
        if ( v9->mFlags & 0x40 )
        {
          v25 = v5->mPrev;
          v26 = v5->mNext;
          v25->mNext = v26;
          v26->mPrev = v25;
          v5->mPrev = (UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *)&v5->mPrev;
          v5->mNext = (UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *)&v5->mPrev;
          UFG::qPrintChannel::Print(
            &UFG::VRAMChannel,
            OUTPUT_LEVEL_DEBUG,
            "[VRAM Channel] - Setting qVRAMemoryHandle(%p) to point at - PoolID:0x%02x BlockID:0x%04x Data:%p-%p AllocatedSize:%u\n");
          v27 = v5->mPrev;
          v28 = v5->mNext;
          v6 = 1;
          v27->mNext = v28;
          v28->mPrev = v27;
          v5->mPrev = (UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *)&v5->mPrev;
          v5->mNext = (UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *)&v5->mPrev;
          v5->mData = 0i64;
          *(_DWORD *)&v5->mReadOnlyAndPoolID = 0;
        }
        else
        {
          for ( ;
                (UFG::qList<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly,1,0> *)v9->mAllocationHandles.mNode.mNext != &v9->mAllocationHandles;
                LODWORD(v29[1].mNext) = 0 )
          {
            v29 = v9->mAllocationHandles.mNode.mNext;
            v30 = v29->mPrev;
            v31 = v29->mNext;
            v30->mNext = v31;
            v31->mPrev = v30;
            v29->mPrev = v29;
            v29->mNext = v29;
            UFG::qPrintChannel::Print(
              &UFG::VRAMChannel,
              OUTPUT_LEVEL_DEBUG,
              "[VRAM Channel] - Setting qVRAMemoryHandle(%p) to point at - PoolID:0x%02x BlockID:0x%04x Data:%p-%p AllocatedSize:%u\n");
            v32 = v29->mPrev;
            v33 = v29->mNext;
            v32->mNext = v33;
            v33->mPrev = v32;
            v29->mPrev = v29;
            v29->mNext = v29;
            v29[1].mPrev = 0i64;
          }
          v6 = 1;
        }
      }
    }
  }
LABEL_33:
  UFG::qVRAMemoryPool::AssertValid(v4);
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v4->mPoolLock);
  return v6;
}

// File Line: 1467
// RVA: 0x1772C0
__int64 __fastcall UFG::qVRAMemoryPool::Lock(UFG::qVRAMemoryPool *this, UFG::qVRAMemoryHandle *handle)
{
  UFG::qVRAMemoryPool *v2; // rdi
  UFG::qVRAMemoryHandle *v3; // rsi
  unsigned __int8 v4; // bp
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // cx
  UFG::BlockInfo *v7; // rbx
  char *v8; // ST20_8
  char *v9; // ST20_8

  v2 = this;
  v3 = handle;
  UFG::qPrintChannel::Print(&UFG::VRAMChannel, OUTPUT_LEVEL_WARNING, "[VRAM Channel] - '%.64s'->Lock(handle(%p))\n");
  v4 = 0;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&v2->mPoolLock);
  UFG::qVRAMemoryPool::AssertValid(v2);
  if ( v2->mInitialized == 1 && (v3->mReadOnlyAndPoolID & 0x7FFF) == v2->mPoolID )
  {
    v5 = v2->mNumBlocksTotal;
    v6 = v3->mBlockID;
    if ( v5 )
    {
      if ( v6 >= v5 )
        goto LABEL_11;
      v7 = &v2->mBlocks[(unsigned __int64)v6];
    }
    else
    {
      v7 = UFG::qVRAMemoryPools::GetBlock(v6);
    }
    if ( v7 )
    {
      v8 = v7->mData;
      UFG::qPrintChannel::Print(
        &UFG::VRAMChannel,
        OUTPUT_LEVEL_NORMAL,
        "[VRAM Channel] -   handle(%p) at memory location %p locked\n");
      v7->mFlags |= 0x20u;
      if ( v7->mFlags & 0x40 )
      {
        v9 = v7->mData;
        UFG::qPrintChannel::Print(
          &UFG::VRAMChannel,
          OUTPUT_LEVEL_WARNING,
          "[VRAM Channel] -   handle(%p) at memory location %p was pending move, flagging to discard move\n");
        v7->mFlags |= 0x80u;
      }
      v4 = 1;
    }
  }
LABEL_11:
  UFG::qVRAMemoryPool::AssertValid(v2);
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v2->mPoolLock);
  return v4;
}

// File Line: 1504
// RVA: 0x17F380
__int64 __fastcall UFG::qVRAMemoryPool::Unlock(UFG::qVRAMemoryPool *this, UFG::qVRAMemoryHandle *handle)
{
  UFG::qVRAMemoryPool *v2; // rbx
  UFG::qVRAMemoryHandle *v3; // rdi
  unsigned __int8 v4; // si
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // cx
  UFG::BlockInfo *v7; // rax

  v2 = this;
  v3 = handle;
  UFG::qPrintChannel::Print(&UFG::VRAMChannel, OUTPUT_LEVEL_WARNING, "[VRAM Channel] - '%.64s'->Unlock(handle(%p))\n");
  v4 = 0;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&v2->mPoolLock);
  UFG::qVRAMemoryPool::AssertValid(v2);
  if ( v2->mInitialized == 1 && (v3->mReadOnlyAndPoolID & 0x7FFF) == v2->mPoolID )
  {
    v5 = v2->mNumBlocksTotal;
    v6 = v3->mBlockID;
    if ( v5 )
    {
      if ( v6 >= v5 )
        goto LABEL_9;
      v7 = &v2->mBlocks[(unsigned __int64)v6];
    }
    else
    {
      v7 = UFG::qVRAMemoryPools::GetBlock(v6);
    }
    if ( v7 )
    {
      v7->mFlags &= 0xDFu;
      v4 = 1;
    }
  }
LABEL_9:
  UFG::qVRAMemoryPool::AssertValid(v2);
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v2->mPoolLock);
  return v4;
}

// File Line: 1533
// RVA: 0x1720C0
__int64 __fastcall UFG::qVRAMemoryPool::GetRequestedSize(UFG::qVRAMemoryPool *this, UFG::qVRAMemoryHandle *handle)
{
  UFG::qVRAMemoryHandle *v2; // rsi
  UFG::qVRAMemoryPool *v3; // rbx
  unsigned int v4; // edi
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // cx
  UFG::BlockInfo *v7; // rax

  v2 = handle;
  v3 = this;
  v4 = 0;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mPoolLock);
  UFG::qVRAMemoryPool::AssertValid(v3);
  if ( v3->mInitialized == 1 && (v2->mReadOnlyAndPoolID & 0x7FFF) == v3->mPoolID )
  {
    v5 = v3->mNumBlocksTotal;
    v6 = v2->mBlockID;
    if ( v5 )
    {
      if ( v6 >= v5 )
        goto LABEL_9;
      v7 = &v3->mBlocks[(unsigned __int64)v6];
    }
    else
    {
      v7 = UFG::qVRAMemoryPools::GetBlock(v6);
    }
    if ( v7 )
      v4 = v7->mRequestedSize;
  }
LABEL_9:
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v3->mPoolLock);
  return v4;
}

// File Line: 1556
// RVA: 0x16F2F0
__int64 __fastcall UFG::qVRAMemoryPool::GetAllocatedSize(UFG::qVRAMemoryPool *this, UFG::qVRAMemoryHandle *handle)
{
  UFG::qVRAMemoryHandle *v2; // rsi
  UFG::qVRAMemoryPool *v3; // rbx
  unsigned int v4; // edi
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // cx
  UFG::BlockInfo *v7; // rax

  v2 = handle;
  v3 = this;
  v4 = 0;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mPoolLock);
  UFG::qVRAMemoryPool::AssertValid(v3);
  if ( v3->mInitialized == 1 && (v2->mReadOnlyAndPoolID & 0x7FFF) == v3->mPoolID )
  {
    v5 = v3->mNumBlocksTotal;
    v6 = v2->mBlockID;
    if ( v5 )
    {
      if ( v6 >= v5 )
        goto LABEL_9;
      v7 = &v3->mBlocks[(unsigned __int64)v6];
    }
    else
    {
      v7 = UFG::qVRAMemoryPools::GetBlock(v6);
    }
    if ( v7 )
      v4 = v7->mActualSize;
  }
LABEL_9:
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v3->mPoolLock);
  return v4;
}

// File Line: 1681
// RVA: 0x17CC20
void __fastcall UFG::qVRAMemoryPool::SetCanDefrag(UFG::qVRAMemoryPool *this, bool can_defrag)
{
  bool v2; // bl
  UFG::qVRAMemoryPool *v3; // rsi

  v2 = can_defrag;
  v3 = this;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mPoolLock);
  v3->mDefragAllowed = v2 != 0;
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v3->mPoolLock);
}

// File Line: 1752
// RVA: 0x1676D0
void __fastcall UFG::qVRAMemoryPool::AssertValid(UFG::qVRAMemoryPool *this)
{
  UFG::qVRAMemoryPool *v1; // rbx

  v1 = this;
  if ( this->mValidate )
  {
    UFG::qPrintChannel::Print(&UFG::VRAMChannel, OUTPUT_LEVEL_WARNING, "[VRAM Channel] - '%.64s'->AssertValid()\n");
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&v1->mPoolLock);
    if ( v1->mInitialized == 1 )
      UFG::qVRAMemoryPool::AssertValidInitialized(v1);
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v1->mPoolLock);
  }
}

// File Line: 1773
// RVA: 0x178DC0
void __fastcall UFG::qVRAMemoryPool::Print(UFG::qVRAMemoryPool *this, unsigned int print_flags)
{
  _RTL_CRITICAL_SECTION *v2; // r15
  unsigned int v3; // er14
  UFG::qVRAMemoryPool *v4; // rdi
  UFG::qVRAMemoryPool *v5; // rax
  UFG::qMemoryPool *v6; // rdx
  UFG::qMemoryPool *v7; // rdx
  signed __int64 i; // rcx
  __int64 j; // rax
  signed __int64 v10; // rbp
  bool v11; // si
  UFG::BlockInfo *k; // rbx
  UFG::BlockInfo *v13; // rbx
  bool l; // si
  UFG::BlockInfo *m; // rbx
  unsigned __int16 v16; // si
  unsigned __int16 v17; // bp
  unsigned __int16 v18; // r14
  unsigned __int16 v19; // ax
  UFG::BlockInfo *v20; // rbx
  unsigned __int8 v21; // al
  const char *v22; // r10
  unsigned __int16 v23; // ax
  int v24; // ecx
  int v25; // ebx
  __int64 v26; // [rsp+20h] [rbp-58h]
  __int64 v27; // [rsp+28h] [rbp-50h]
  __int64 v28; // [rsp+30h] [rbp-48h]

  v2 = (_RTL_CRITICAL_SECTION *)&this->mPoolLock;
  v3 = print_flags;
  v4 = this;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mPoolLock);
  UFG::qVRAMemoryPool::AssertValid(v4);
  UFG::qPrintf("Summary of Pool %u '%s'\n", v4->mPoolID, v4->mName);
  if ( v3 & 1 )
  {
    v5 = v4->mOverflowVRAM;
    if ( v5 )
      UFG::qPrintf("  Overflow qVRAMemoryPool ID:%u '%s'\n", v5->mPoolID, v5->mName);
    v6 = v4->mOverflowMain;
    if ( v6 )
      UFG::qPrintf("  Overflow qMemoryPool '%s'\n", v6->mData->mAllocator.mName);
    v7 = v4->mMainMemoryPool;
    if ( v7 )
      UFG::qPrintf("  Main Memory Allocations qMemoryPool '%s'\n", v7->mData->mAllocator.mName);
    if ( v4->mPoolMemory.mData )
      UFG::qPrintf(
        "  Parent qVRAMemoryPool ID:%u '%s'\n",
        v4->mPoolMemory.mReadOnlyAndPoolID & 0x7FFF,
        UFG::qVRAMemoryPools::sVRAMemoryPools[v4->mPoolMemory.mReadOnlyAndPoolID & 0x7FFF]->mName);
    UFG::qPrintf("  Memory Range: %p - %p\n", v4->mVRAMemoryStart, &v4->mVRAMemoryStart[v4->mVRAMemorySize - 1]);
    for ( i = (signed __int64)&v4->mContainerList.mNode.mNext[-1];
          (UFG::qList<UFG::BlockInfo,UFG::Secondary,1,0> *)i != &v4->mMoveTargetsList;
          i = *(_QWORD *)(i + 24) - 16i64 )
    {
      for ( j = *(_QWORD *)(i + 96); j != i + 88; j = *(_QWORD *)(j + 8) )
        ;
    }
  }
  if ( v3 & 2 )
  {
    v10 = (signed __int64)&v4->mMoveTargetsList;
    v11 = (v3 >> 3) & 1;
    if ( v3 & 4 )
      v11 = 0;
    for ( k = (UFG::BlockInfo *)&v4->mContainerList.mNode.mNext[-1];
          k != (UFG::BlockInfo *)v10;
          k = (UFG::BlockInfo *)&k->mNext[-1] )
    {
      UFG::BlockInfo::Print(k, v11);
    }
  }
  if ( v3 & 4 )
  {
    v13 = (UFG::BlockInfo *)v4->mUsedBlocks.mNode.mNext;
    for ( l = (v3 >> 3) & 1; v13 != (UFG::BlockInfo *)&v4->mUsedBlocks; v13 = (UFG::BlockInfo *)v13->mNext )
      UFG::BlockInfo::Print(v13, l);
    for ( m = (UFG::BlockInfo *)v4->mMainMemoryBlocks.mNode.mNext;
          m != (UFG::BlockInfo *)&v4->mMainMemoryBlocks;
          m = (UFG::BlockInfo *)m->mNext )
    {
      UFG::BlockInfo::Print(m, l);
    }
  }
  if ( !(v3 & 0x10) )
    goto LABEL_57;
  v16 = 0;
  v17 = -1;
  v18 = -1;
  if ( v4->mUsedBlocksMax <= 0u )
    goto LABEL_51;
  do
  {
    v19 = v4->mNumBlocksTotal;
    if ( v19 )
    {
      if ( v16 >= v19 )
        goto LABEL_49;
      v20 = &v4->mBlocks[(unsigned __int64)v16];
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
        if ( v17 != -1 )
        {
          if ( v17 == v18 )
            UFG::qPrintf(
              "    BlockID  :%05u                                                                               type(%*s)\n",
              v17,
              21i64,
              off_14203C490[0]);
          else
            UFG::qPrintf(
              "    BlockID  :%05u - %05u                                                                       type(%*s)\n",
              v17,
              v18,
              21i64,
              off_14203C490[0]);
          v17 = -1;
          v18 = -1;
        }
        v21 = v20->mUsage;
        if ( v21 == 11 )
        {
          LODWORD(v28) = 21;
          LODWORD(v27) = v20->mActualSize;
          LODWORD(v26) = v20->mRequestedSize;
          UFG::qPrintf(
            "      BlockID:%05u [%p - %p] %9u bytes requested %9u bytes allocated type(%*s) name:(%.64s)\n",
            v20->mBlockID,
            v20->mData,
            &v20->mData[v20->mRequestedSize - 1],
            v26,
            v27,
            v28,
            off_14203C4E8[0],
            v20->mName);
        }
        else
        {
          if ( v21 > 0x12u )
            v22 = "Unknown VRAMType";
          else
            v22 = off_14203C490[v21];
          LODWORD(v28) = 21;
          LODWORD(v27) = v20->mActualSize;
          LODWORD(v26) = v20->mRequestedSize;
          UFG::qPrintf(
            "    BlockID  :%05u [%p - %p] %9u bytes requested %9u bytes allocated type(%*s) name:(%.64s)\n",
            v20->mBlockID,
            v20->mData,
            &v20->mData[v20->mActualSize - 1],
            v26,
            v27,
            v28,
            v22,
            v20->mName);
        }
      }
      else
      {
        if ( v17 == -1 )
          v17 = v20->mBlockID;
        v18 = v20->mBlockID;
      }
    }
LABEL_49:
    ++v16;
  }
  while ( v16 < v4->mUsedBlocksMax );
  v2 = (_RTL_CRITICAL_SECTION *)&v4->mPoolLock;
LABEL_51:
  v23 = v4->mNumBlocksTotal;
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
  if ( v4->mUsedBlocksMax != v24 && v4->mNumBlocksTotal <= 0u )
  {
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMBlocksLock);
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMBlocksLock);
  }
LABEL_57:
  UFG::qMutex::Unlock(v2);
}

// File Line: 1901
// RVA: 0x1696E0
UFG::qVRAMemoryPool::CommonInit

// File Line: 1993
// RVA: 0x16FF90
__int64 __fastcall UFG::qVRAMemoryPool::GetDefragmentMoves(UFG::qVRAMemoryPool *this, UFG::qVRAMemoryMoveOrder *moves, int moves_count, unsigned int requested_total_bytes, unsigned int *total_bytes)
{
  UFG::qVRAMemoryMoveOrder *v5; // rbp
  unsigned int v6; // esi
  int v7; // edi
  UFG::qVRAMemoryPool *v8; // rbx
  UFG::qPrintChannel::OutputLevel v9; // edx
  int v10; // er13
  _RTL_CRITICAL_SECTION *v11; // r12
  char v12; // al
  unsigned int *v13; // r14
  char **v14; // r15
  unsigned int v15; // eax
  unsigned int v16; // er8
  UFG::qVRAMemoryHandle *v17; // r12
  char *v18; // r14
  char *v19; // r15
  int v20; // esi
  char *v21; // rbp
  __int64 v22; // r9
  __int64 v23; // r15
  char *v24; // ST20_8
  bool found_move_too_large; // [rsp+50h] [rbp-58h]
  char **v27; // [rsp+58h] [rbp-50h]
  char v28; // [rsp+B0h] [rbp+8h]
  UFG::qVRAMemoryMoveOrder *v29; // [rsp+B8h] [rbp+10h]
  int v30; // [rsp+C0h] [rbp+18h]
  unsigned int v31; // [rsp+C8h] [rbp+20h]

  v31 = requested_total_bytes;
  v30 = moves_count;
  v29 = moves;
  v5 = moves;
  v6 = requested_total_bytes;
  v7 = moves_count;
  v8 = this;
  v9 = 4;
  if ( v5
    && moves_count > 0
    && (unsigned __int8)this->mNeedsDefragmentUp + (unsigned __int8)this->mNeedsDefragmentDown > 0 )
  {
    v9 = 2;
  }
  UFG::qPrintChannel::Print(&UFG::VRAMChannel, v9, "[VRAM Channel] - '%.64s'->GetDefragmentMoves(%p, %u)\n");
  v10 = 0;
  if ( v5 && v7 > 0 )
  {
    v11 = (_RTL_CRITICAL_SECTION *)&v8->mPoolLock;
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&v8->mPoolLock);
    UFG::qVRAMemoryPool::AssertValid(v8);
    if ( v8->mDefragAllowed == 1
      && (unsigned __int8)v8->mNeedsDefragmentUp + (unsigned __int8)v8->mNeedsDefragmentDown > 0 )
    {
      v12 = 0;
      v28 = 0;
      if ( v7 > 0 )
      {
        v13 = total_bytes;
        v14 = &v5->mTargetHandle.mData;
        v27 = &v5->mTargetHandle.mData;
        do
        {
          if ( v12 )
            break;
          v15 = *v13;
          if ( *v13 >= v6 )
            break;
          v16 = v15 ? v6 - v15 : -1;
          found_move_too_large = 0;
          v17 = &v5[(signed __int64)v10].mTargetHandle;
          if ( (unsigned __int8)UFG::qVRAMemoryPool::GetDefragmentMove(
                                  v8,
                                  &v5[(signed __int64)v10],
                                  v16,
                                  &found_move_too_large) == 1 )
          {
            v18 = *v14;
            UFG::qVRAMemoryPools::GetAllocatedSize(v17);
            v19 = *v14;
            v20 = *((unsigned __int16 *)v27 + 5);
            v21 = v27[4];
            UFG::qVRAMemoryPools::GetAllocatedSize(v17 + 1);
            v22 = *((unsigned __int16 *)v27 + 21);
            v23 = (__int64)v27;
            v24 = v27[4];
            UFG::qPrintChannel::Print(
              &UFG::VRAMChannel,
              OUTPUT_LEVEL_DEBUG,
              "[VRAM Channel]    - Found Move [%04u]%p-%p to [%04u]%p-%p\n");
            v7 = v30;
            *total_bytes += UFG::qVRAMemoryPools::GetAllocatedSize(v17 + 1);
            v6 = v31;
            v5 = v29;
            v12 = v28;
            ++v10;
            v14 = (char **)(v23 + 64);
            v27 = v14;
            v13 = total_bytes;
          }
          else
          {
            v12 = 1;
            v28 = 1;
            if ( found_move_too_large != 1 )
              *(_WORD *)&v8->mNeedsDefragmentUp = 0;
          }
        }
        while ( v10 < v7 );
        v11 = (_RTL_CRITICAL_SECTION *)&v8->mPoolLock;
      }
    }
    UFG::qVRAMemoryPool::AssertValid(v8);
    UFG::qMutex::Unlock(v11);
  }
  return (unsigned int)v10;
}

// File Line: 2062
// RVA: 0x16FB00
__int64 __fastcall UFG::qVRAMemoryPool::GetDefragmentMove(UFG::qVRAMemoryPool *this, UFG::qVRAMemoryMoveOrder *move, unsigned int allowable_bytes, bool *found_move_too_large)
{
  unsigned __int8 v4; // si
  bool *v5; // rbx
  unsigned int v6; // edi
  UFG::qVRAMemoryMoveOrder *v7; // r14
  UFG::qVRAMemoryPool *v8; // r13
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v9; // r12
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v10; // rbp
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v11; // r8
  unsigned int v12; // er10
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v13; // r15
  unsigned int v14; // er11
  char v15; // al
  unsigned int v16; // eax
  unsigned int v17; // er9
  unsigned int v18; // er8
  unsigned __int16 v19; // dx
  unsigned __int16 v20; // ax
  UFG::BlockInfo *v21; // rcx
  signed __int64 v22; // r14
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v23; // rbx
  __int16 v24; // si
  unsigned __int16 v25; // di
  UFG::qMemoryPool *pool; // ST38_8
  __int64 v27; // rcx
  _QWORD *v28; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v29; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *i; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v31; // rax
  unsigned int v32; // ebx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v33; // rbp
  unsigned int v34; // edi
  char v35; // cl
  unsigned int v36; // er11
  __int64 v37; // r9
  __int64 v38; // r10
  unsigned int v39; // er11
  unsigned __int64 v40; // r10
  unsigned __int64 v41; // rcx
  unsigned int v42; // er10
  unsigned int v43; // er8
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v44; // rbx
  __int16 v45; // si
  unsigned __int16 v46; // di
  signed __int64 v47; // r14
  UFG::qMemoryPool *v48; // ST38_8
  __int64 v49; // rcx
  _QWORD *v50; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v51; // rax
  UFG::qVRAMemoryMoveOrder *v52; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v54; // [rsp+A0h] [rbp+8h]
  UFG::qVRAMemoryMoveOrder *v55; // [rsp+A8h] [rbp+10h]
  unsigned int v56; // [rsp+B0h] [rbp+18h]
  bool *v57; // [rsp+B8h] [rbp+20h]

  v57 = found_move_too_large;
  v56 = allowable_bytes;
  v55 = move;
  v4 = 0;
  v5 = found_move_too_large;
  v6 = allowable_bytes;
  v7 = move;
  v8 = this;
  if ( (UFG::qList<UFG::BlockInfo,UFG::Primary,1,0> *)&this->mFreeList.mNode.mNext[-1] == &this->mUsedBlocks )
    return 0i64;
  v9 = this->mFreeList.mNode.mPrev - 1;
  v54 = this->mFreeList.mNode.mNext - 1;
  if ( v54 != v9 )
  {
    v10 = this->mFreeList.mNode.mNext - 1;
    do
    {
      if ( v4 || *v5 )
        break;
      v11 = v9->mPrev;
      v12 = -1;
      v13 = 0i64;
      v14 = -1;
      if ( v9->mPrev != v10 )
      {
        do
        {
          v15 = BYTE3(v11[4].mNext);
          if ( v15 & 4 )
          {
            if ( !(v15 & 0x40) && !(v15 & 0x20) && !BYTE4(v11[4].mNext) )
            {
              if ( v15 & 1 )
              {
                v16 = HIDWORD(v11[4].mPrev);
                v17 = (~((1 << BYTE5(v11[4].mNext)) - 1) & (LODWORD(v10[3].mPrev) + (1 << BYTE5(v11[4].mNext)) - 1))
                    - LODWORD(v10[3].mPrev);
                if ( HIDWORD(v10[4].mPrev) - v17 >= v16 )
                {
                  if ( v17 < v12 || v17 == v12 && HIDWORD(v10[4].mPrev) - v16 < v14 )
                  {
                    v14 = HIDWORD(v10[4].mPrev) - v16;
                    v12 = (~((1 << BYTE5(v11[4].mNext)) - 1) & (LODWORD(v10[3].mPrev) + (1 << BYTE5(v11[4].mNext)) - 1))
                        - LODWORD(v10[3].mPrev);
                    v13 = v11;
                  }
                  if ( !v12 && !v14 )
                    break;
                }
              }
            }
          }
          v11 = v11->mPrev;
        }
        while ( v11 != v10 );
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
              v8,
              &v7->mTargetHandle,
              v18,
              0x10u,
              "Move Target",
              1 << BYTE5(v13[4].mNext),
              1,
              0i64,
              0i64,
              0);
            v19 = v8->mNumBlocksTotal;
            v20 = v7->mTargetHandle.mBlockID;
            v21 = 0i64;
            if ( v19 )
            {
              if ( v20 < v19 )
                v21 = &v8->mBlocks[(unsigned __int64)v20];
            }
            else
            {
              v21 = UFG::qVRAMemoryPools::GetBlock(v20);
            }
            v22 = (signed __int64)&v7->mSourceHandle;
            v21->mMoveSourceID = (unsigned __int16)v13[4].mNext;
            v23 = v13[3].mPrev;
            v24 = (__int16)v13[4].mNext;
            v25 = v8->mPoolID;
            pool = (UFG::qMemoryPool *)((char *)v23 + HIDWORD(v13[4].mPrev) - 1);
            UFG::qPrintChannel::Print(
              &UFG::VRAMChannel,
              OUTPUT_LEVEL_DEBUG,
              "[VRAM Channel] - Setting qVRAMemoryHandle(%p) to point at - PoolID:0x%02x BlockID:0x%04x Data:%p-%p AllocatedSize:%u\n");
            v27 = *(_QWORD *)v22;
            v28 = *(_QWORD **)(v22 + 8);
            *(_QWORD *)(v27 + 8) = v28;
            *v28 = v27;
            *(_QWORD *)(v22 + 16) = v23;
            v5 = v57;
            *(_WORD *)(v22 + 24) = v25;
            v6 = v56;
            *(_WORD *)(v22 + 26) = v24;
            *(_QWORD *)v22 = v22;
            *(_QWORD *)(v22 + 8) = v22;
            v29 = v13[2].mPrev;
            v4 = 1;
            v29->mNext = (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)v22;
            *(_QWORD *)v22 = v29;
            *(_QWORD *)(v22 + 8) = v13 + 2;
            v13[2].mPrev = (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)v22;
            BYTE3(v13[4].mNext) |= 0x40u;
            v7 = v55;
          }
        }
      }
      v10 = v10[1].mNext - 1;
    }
    while ( v10 != v9 );
    for ( i = v54; v9 != v54; v9 = v9[1].mPrev - 1 )
    {
      if ( v4 )
        break;
      v31 = i->mNext;
      v32 = -1;
      v33 = 0i64;
      v34 = -1;
      if ( v31 != v9 )
      {
        do
        {
          v35 = BYTE3(v31[4].mNext);
          if ( v35 & 4 )
          {
            if ( !(v35 & 0x40) && !(v35 & 0x20) && !BYTE4(v31[4].mNext) )
            {
              if ( v35 & 2 )
              {
                v36 = HIDWORD(v9[4].mPrev);
                v37 = HIDWORD(v31[4].mPrev);
                v38 = v36;
                v39 = v36 - v37;
                v40 = (unsigned __int64)v9[3].mPrev + v38 - v37;
                v41 = v40 & ~((1 << BYTE5(v31[4].mNext)) - 1i64);
                v42 = v40 - v41;
                if ( v9[3].mPrev <= (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)v41 )
                {
                  if ( v42 < v32 || v42 == v32 && v39 < v34 )
                  {
                    v34 = v39;
                    v32 = v42;
                    v33 = v31;
                  }
                  if ( !v32 && !v34 )
                    break;
                }
              }
            }
          }
          v31 = v31->mNext;
        }
        while ( v31 != v9 );
        if ( v33 )
        {
          v43 = HIDWORD(v33[4].mPrev);
          if ( v43 >= v56 )
          {
            *v57 = 1;
          }
          else
          {
            UFG::qVRAMemoryPool::Allocate(
              v8,
              &v7->mTargetHandle,
              v43,
              0x10u,
              "Move Target",
              1 << BYTE5(v33[4].mNext),
              2,
              0i64,
              0i64,
              0);
            v44 = v33[3].mPrev;
            v45 = (__int16)v33[4].mNext;
            v46 = v8->mPoolID;
            v47 = (signed __int64)&v7->mSourceHandle;
            v48 = (UFG::qMemoryPool *)((char *)v44 + HIDWORD(v33[4].mPrev) - 1);
            UFG::qPrintChannel::Print(
              &UFG::VRAMChannel,
              OUTPUT_LEVEL_DEBUG,
              "[VRAM Channel] - Setting qVRAMemoryHandle(%p) to point at - PoolID:0x%02x BlockID:0x%04x Data:%p-%p AllocatedSize:%u\n");
            v49 = *(_QWORD *)v47;
            v50 = *(_QWORD **)(v47 + 8);
            *(_QWORD *)(v49 + 8) = v50;
            *v50 = v49;
            *(_WORD *)(v47 + 26) = v45;
            *(_QWORD *)v47 = v47;
            *(_QWORD *)(v47 + 8) = v47;
            *(_QWORD *)(v47 + 16) = v44;
            *(_WORD *)(v47 + 24) = v46;
            v51 = v33[2].mPrev;
            v51->mNext = (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)v47;
            *(_QWORD *)v47 = v51;
            *(_QWORD *)(v47 + 8) = v33 + 2;
            v33[2].mPrev = (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)v47;
            BYTE3(v33[4].mNext) |= 0x40u;
            v4 = 1;
          }
        }
      }
      i = v54;
      v7 = v55;
    }
    if ( v4 == 1 )
    {
      v52 = v55;
      v52->mSourceHandle.mReadOnlyAndPoolID |= 0x8000u;
      v52->mTargetHandle.mReadOnlyAndPoolID |= 0x8000u;
    }
  }
  return v4;
}

// File Line: 2243
// RVA: 0x177C10
void __fastcall UFG::qVRAMemoryPool::MoveCompleted(UFG::qVRAMemoryPool *this, UFG::qVRAMemoryMoveOrder *move, void (__fastcall *callback)(UFG::qVRAMemoryHandle *, char *, UFG::VRAMType, unsigned __int64, unsigned int))
{
  void (__fastcall *v3)(UFG::qVRAMemoryHandle *, char *, UFG::VRAMType, unsigned __int64, unsigned int); // r12
  UFG::qVRAMemoryMoveOrder *v4; // rdi
  UFG::qVRAMemoryPool *v5; // r13
  unsigned __int16 v6; // cx
  UFG::BlockInfo *v7; // rsi
  unsigned __int16 v8; // ax
  unsigned __int16 v9; // cx
  UFG::BlockInfo *v10; // rbx
  unsigned __int16 v11; // ax
  char *v12; // r15
  char *v13; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v14; // rdx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v15; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v16; // rax
  __int64 *v17; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v18; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v19; // rax
  __int64 *v20; // rax
  _QWORD *v21; // rax
  UFG::BlockInfo *i; // rbx
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v23; // rdi
  signed __int64 j; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v25; // rbx
  UFG::BlockInfo *k; // rbx
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v27; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v28; // rax
  __int64 *v29; // rcx
  UFG::BlockInfo *v30; // rax
  UFG::qVRAMemoryHandle *l; // rbx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v32; // rcx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v33; // rax
  __int64 *v34; // rcx
  UFG::qVRAMemoryHandle *v35; // rax
  __int64 *v36; // rcx
  __int64 **v37; // rax
  __int64 *v38; // rcx
  __int64 **v39; // rax
  _RTL_CRITICAL_SECTION *v40; // rbx
  __int64 v41; // [rsp+20h] [rbp-79h]
  void (__fastcall *v42)(UFG::qVRAMemoryHandle *, char *, UFG::VRAMType, unsigned __int64, unsigned int); // [rsp+28h] [rbp-71h]
  __int64 *v43; // [rsp+30h] [rbp-69h]
  __int64 **v44; // [rsp+38h] [rbp-61h]
  __int64 *v45; // [rsp+40h] [rbp-59h]
  __int64 **v46; // [rsp+48h] [rbp-51h]
  __int64 *v47; // [rsp+50h] [rbp-49h]
  UFG::qVRAMemoryHandle *v48; // [rsp+58h] [rbp-41h]
  __int128 v49; // [rsp+60h] [rbp-39h]
  __int64 v50; // [rsp+70h] [rbp-29h]
  int v51; // [rsp+78h] [rbp-21h]
  __int16 v52; // [rsp+7Ch] [rbp-1Dh]
  __int64 v53; // [rsp+80h] [rbp-19h]
  __int64 *v54; // [rsp+88h] [rbp-11h]
  UFG::BlockInfo *v55; // [rsp+90h] [rbp-9h]
  int v56; // [rsp+98h] [rbp-1h]
  __int64 v57; // [rsp+A0h] [rbp+7h]
  int v58; // [rsp+A8h] [rbp+Fh]
  __int64 v59; // [rsp+B0h] [rbp+17h]
  char *new_location; // [rsp+100h] [rbp+67h]

  v59 = -2i64;
  v3 = callback;
  v4 = move;
  v5 = this;
  v42 = callback;
  UFG::qPrintChannel::Print(
    &UFG::VRAMChannel,
    OUTPUT_LEVEL_WARNING,
    "[VRAM Channel] - '%.64s'->MoveCompleted(%p, %p)\n");
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&v5->mPoolLock);
  UFG::qVRAMemoryPool::AssertValid(v5);
  v4->mSourceHandle.mReadOnlyAndPoolID &= 0x7FFFu;
  v4->mTargetHandle.mReadOnlyAndPoolID &= 0x7FFFu;
  v6 = v4->mSourceHandle.mBlockID;
  v7 = 0i64;
  v8 = v5->mNumBlocksTotal;
  if ( v8 )
  {
    if ( v6 < v8 )
      v7 = &v5->mBlocks[(unsigned __int64)v6];
  }
  else
  {
    v7 = UFG::qVRAMemoryPools::GetBlock(v6);
  }
  v9 = v4->mTargetHandle.mBlockID;
  v10 = 0i64;
  v11 = v5->mNumBlocksTotal;
  if ( v11 )
  {
    if ( v9 < v11 )
      v10 = &v5->mBlocks[(unsigned __int64)v9];
  }
  else
  {
    v10 = UFG::qVRAMemoryPools::GetBlock(v9);
  }
  v12 = v7->mData;
  v13 = v10->mData;
  new_location = v10->mData;
  v7->mFlags &= 0xBFu;
  if ( v7->mKeepAliveFrames || v7->mFlags < 0 )
  {
    UFG::qPrintChannel::Print(
      &UFG::VRAMChannel,
      OUTPUT_LEVEL_NORMAL,
      "[VRAM Channel] -  Move cancelled by free or lock, memory moved from %p to %p\n");
    v7->mFlags &= 0x7Fu;
    UFG::qVRAMemoryPool::Free(v5, &v4->mTargetHandle, 0);
    UFG::qVRAMemoryHandle::Close(&v4->mSourceHandle);
  }
  else
  {
    HIDWORD(v41) = HIDWORD(v13);
    UFG::qPrintChannel::Print(
      &UFG::VRAMChannel,
      OUTPUT_LEVEL_NORMAL,
      "[VRAM Channel] -  Move still valid, memory moved from %p to %p\n");
    v14 = (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)&v10->mPrev;
    v15 = v10->mPrev;
    v16 = v10->mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    v14->mPrev = v14;
    v14->mNext = v14;
    v43 = (__int64 *)&v43;
    v44 = &v43;
    v45 = (__int64 *)&v45;
    v46 = &v45;
    v47 = (__int64 *)&v47;
    v48 = (UFG::qVRAMemoryHandle *)&v47;
    _mm_store_si128((__m128i *)&v49, (__m128i)0i64);
    v50 = 0i64;
    v51 = 0xFFFF;
    v52 = 0;
    v53 = 0i64;
    v54 = (__int64 *)&v54;
    v55 = (UFG::BlockInfo *)&v54;
    v56 = -1;
    v57 = 0i64;
    v58 = 0;
    v17 = (__int64 *)v10->mPrev;
    v17[1] = (__int64)&v43;
    v43 = v17;
    v44 = (__int64 **)v10;
    v44 = (__int64 **)v10->mNext;
    *v44 = (__int64 *)&v43;
    v10->mPrev = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&v10->mPrev;
    v10->mNext = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&v10->mPrev;
    v18 = v7->mPrev;
    v18->mNext = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&v10->mPrev;
    v10->mPrev = v18;
    v10->mNext = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&v7->mPrev;
    v19 = v7->mNext;
    v10->mNext = v19;
    v19->mPrev = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&v10->mPrev;
    v20 = v43;
    v43[1] = (__int64)v7;
    v7->mPrev = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)v20;
    v21 = v44;
    v7->mNext = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)v44;
    *v21 = v7;
    v43 = (__int64 *)&v43;
    v44 = &v43;
    UFG::BlockInfo::DefragmentMovedTo(v10, v12);
    UFG::BlockInfo::DefragmentMovedTo(v7, new_location);
    UFG::qVRAMemoryHandle::Close(&v4->mSourceHandle);
    v10->mName = "Moved Source VRAM";
    v10->mUsage = 17;
    UFG::qVRAMemoryPool::Free(v5, &v4->mTargetHandle, v5->mDefragFreeFrameDelay);
    if ( v3 )
    {
      for ( i = (UFG::BlockInfo *)v7->mAllocationHandles.mNode.mNext;
            i != (UFG::BlockInfo *)&v7->mAllocationHandles;
            i = (UFG::BlockInfo *)i->mNext )
      {
        LODWORD(v41) = v7->mCallbackData32;
        ((void (__fastcall *)(UFG::BlockInfo *, char *, _QWORD, unsigned __int64, __int64, void (__fastcall *)(UFG::qVRAMemoryHandle *, char *, UFG::VRAMType, unsigned __int64, unsigned int)))v3)(
          i,
          v12,
          (unsigned __int8)v7->mUsage,
          v7->mCallbackData64,
          v41,
          v42);
      }
      v23 = v7->mContainedBlocks.mNode.mNext;
      for ( j = (signed __int64)&v7->mContainedBlocks; v23 != (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)j; v23 = v23->mNext )
      {
        v25 = v23[2].mNext;
        if ( v25 != &v23[2] )
        {
          do
          {
            LODWORD(v41) = v23[7].mNext;
            ((void (__fastcall *)(UFG::qNode<UFG::BlockInfo,UFG::Primary> *, char *, _QWORD, UFG::qNode<UFG::BlockInfo,UFG::Primary> *, __int64, void (__fastcall *)(UFG::qVRAMemoryHandle *, char *, UFG::VRAMType, unsigned __int64, unsigned int)))v3)(
              v25,
              &v12[(unsigned int)v25[1].mPrev - LODWORD(v7->mData)],
              BYTE2(v23[4].mNext),
              v23[7].mPrev,
              v41,
              v42);
            v25 = v25->mNext;
          }
          while ( v25 != &v23[2] );
          j = (signed __int64)&v7->mContainedBlocks;
        }
      }
    }
    for ( k = v55; v55 != (UFG::BlockInfo *)&v54; k = v55 )
    {
      v27 = k->mPrev;
      v28 = k->mNext;
      v27->mNext = v28;
      v28->mPrev = v27;
      k->mPrev = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&k->mPrev;
      k->mNext = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&k->mPrev;
      UFG::BlockInfo::~BlockInfo(k);
      UFG::qMemoryPool::Free(UFG::gMainMemoryPool, k);
    }
    v29 = v54;
    v30 = v55;
    v54[1] = (__int64)v55;
    v30->mPrev = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)v29;
    v54 = (__int64 *)&v54;
    v55 = (UFG::BlockInfo *)&v54;
    for ( l = v48; v48 != (UFG::qVRAMemoryHandle *)&v47; l = v48 )
    {
      v32 = l->mPrev;
      v33 = l->mNext;
      v32->mNext = v33;
      v33->mPrev = v32;
      l->mPrev = (UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *)&l->mPrev;
      l->mNext = (UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *)&l->mPrev;
      UFG::qVRAMemoryHandle::~qVRAMemoryHandle(l);
      UFG::qMemoryPool::Free(UFG::gMainMemoryPool, l);
    }
    v34 = v47;
    v35 = v48;
    v47[1] = (__int64)v48;
    v35->mPrev = (UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *)v34;
    v47 = (__int64 *)&v47;
    v48 = (UFG::qVRAMemoryHandle *)&v47;
    v36 = v45;
    v37 = v46;
    v45[1] = (__int64)v46;
    *v37 = v36;
    v45 = (__int64 *)&v45;
    v46 = &v45;
    v38 = v43;
    v39 = v44;
    v43[1] = (__int64)v44;
    *v39 = v38;
    v43 = (__int64 *)&v43;
    v44 = &v43;
  }
  if ( v5->mValidate )
  {
    UFG::qPrintChannel::Print(&UFG::VRAMChannel, OUTPUT_LEVEL_WARNING, "[VRAM Channel] - '%.64s'->AssertValid()\n");
    v40 = (_RTL_CRITICAL_SECTION *)&v5->mPoolLock;
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&v5->mPoolLock);
    if ( v5->mInitialized == 1 )
      UFG::qVRAMemoryPool::AssertValidInitialized(v5);
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v5->mPoolLock);
  }
  else
  {
    v40 = (_RTL_CRITICAL_SECTION *)&v5->mPoolLock;
  }
  UFG::qMutex::Unlock(v40);
}

// File Line: 2388
// RVA: 0x17DA10
UFG::BlockInfo *__fastcall UFG::qVRAMemoryPool::SplitFreeBlock(UFG::qVRAMemoryPool *this, UFG::BlockInfo *block, unsigned int aligned_size, unsigned int alignment, unsigned int flags)
{
  unsigned int v5; // ebx
  UFG::BlockInfo *v6; // r15
  UFG::qVRAMemoryPool *v7; // rdi
  unsigned int v8; // ecx
  __int64 v9; // r13
  char *v10; // r8
  unsigned int v11; // ebp
  signed __int64 v12; // rdx
  signed __int64 v13; // r12
  int v14; // er12
  char *v15; // rax
  signed __int64 v16; // rdx
  UFG::BlockInfo *v17; // rax
  char *v18; // rdi
  __int64 v19; // r9
  UFG::BlockInfo *v20; // rsi
  __int64 v21; // r9
  char *v22; // rdi
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v23; // rax
  UFG::BlockInfo *v24; // rax
  __int64 v25; // r9
  char *v26; // rdi
  char *v27; // rdi
  __int64 v28; // r9
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v29; // rax
  UFG::BlockInfo *v30; // rax
  char *v31; // rdi
  __int64 v32; // r9
  UFG::BlockInfo *v33; // r14
  __int64 v34; // r9
  char *v35; // rdi
  __int64 v36; // r9
  char *v37; // rdi
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v38; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v39; // rdx
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v40; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v41; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v42; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v43; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v44; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v45; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v46; // rax
  signed __int64 i; // rdx
  UFG::qVRAMemoryPool *v49; // [rsp+80h] [rbp+8h]
  bool v50; // [rsp+98h] [rbp+20h]

  v49 = this;
  v5 = 0;
  v6 = block;
  v7 = this;
  v8 = block->mActualSize;
  v9 = aligned_size;
  v10 = block->mData;
  v11 = 0;
  v12 = ~((signed int)alignment - 1i64);
  v13 = v12 & (unsigned __int64)&v10[alignment - 1];
  v50 = v8 == v7->mLargestFreeBlock;
  if ( (char *)v13 == v10 && (_DWORD)v9 == v8 )
    goto LABEL_16;
  if ( !(flags & 1) )
  {
    if ( flags & 2 )
    {
      v14 = v8 - v9;
      v15 = &v10[v8 - (unsigned int)v9];
      v16 = (unsigned __int64)v15 & v12;
      if ( (char *)v16 != v15 )
      {
        v11 = (_DWORD)v15 - v16;
        v14 = v16 - (_DWORD)v10;
      }
      goto LABEL_10;
    }
LABEL_16:
    v39 = (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)&v6->mPrev;
    goto LABEL_17;
  }
  if ( (char *)v13 == v10 )
  {
    v11 = v8 - v9;
    goto LABEL_11;
  }
  v14 = v13 - LODWORD(v6->mData);
  v11 = v8 - v14 - v9;
LABEL_10:
  if ( !v14 )
  {
LABEL_11:
    if ( v11 )
    {
      v17 = UFG::qVRAMemoryPool::GetUnusedBlock(v7);
      v18 = v6->mData;
      v19 = v17->mBlockID;
      v20 = v17;
      UFG::qPrintChannel::Print(
        &UFG::VRAMChannel,
        OUTPUT_LEVEL_DEBUG,
        "[VRAM Channel] - Setting Block ID:0x%04x to free data:%p size:0x%08x (%9u)\n");
      v20->mData = v18;
      v20->mRequestedSize = v9;
      v20->mActualSize = v9;
      *(_DWORD *)&v20->mUsage = 1;
      v20->mMemoryPool = 0i64;
      v20->mContainerID = 0;
      v20->mCallbackData64 = 0i64;
      v20->mCallbackData32 = 0;
      v20->mName = "Free VRAM";
      v21 = v6->mBlockID;
      v22 = &v6->mData[v9];
      UFG::qPrintChannel::Print(
        &UFG::VRAMChannel,
        OUTPUT_LEVEL_DEBUG,
        "[VRAM Channel] - Setting Block ID:0x%04x to free data:%p size:0x%08x (%9u)\n");
      v23 = v6->mPrev;
      v6->mData = v22;
      v7 = v49;
      v6->mName = "Free VRAM";
      v6->mRequestedSize = v11;
      v6->mActualSize = v11;
      *(_DWORD *)&v6->mUsage = 1;
      v6->mMemoryPool = 0i64;
      v6->mContainerID = 0;
      v6->mCallbackData64 = 0i64;
      v6->mCallbackData32 = 0;
      v23->mNext = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&v20->mPrev;
      v20->mPrev = v23;
      v20->mNext = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&v6->mPrev;
      v6->mPrev = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&v20->mPrev;
      goto LABEL_18;
    }
    goto LABEL_16;
  }
  v24 = UFG::qVRAMemoryPool::GetUnusedBlock(v7);
  v20 = v24;
  if ( !v11 )
  {
    v25 = v24->mBlockID;
    v26 = &v6->mData[v14];
    UFG::qPrintChannel::Print(
      &UFG::VRAMChannel,
      OUTPUT_LEVEL_DEBUG,
      "[VRAM Channel] - Setting Block ID:0x%04x to free data:%p size:0x%08x (%9u)\n");
    v20->mData = v26;
    v20->mRequestedSize = v9;
    v20->mActualSize = v9;
    *(_DWORD *)&v20->mUsage = 1;
    v20->mMemoryPool = 0i64;
    v20->mContainerID = 0;
    v20->mCallbackData64 = 0i64;
    v20->mCallbackData32 = 0;
    v20->mName = "Free VRAM";
    v27 = v6->mData;
    v28 = v6->mBlockID;
    UFG::qPrintChannel::Print(
      &UFG::VRAMChannel,
      OUTPUT_LEVEL_DEBUG,
      "[VRAM Channel] - Setting Block ID:0x%04x to free data:%p size:0x%08x (%9u)\n");
    v29 = v6->mNext;
    v6->mData = v27;
    v7 = v49;
    v6->mName = "Free VRAM";
    v6->mRequestedSize = v14;
    v6->mActualSize = v14;
    *(_DWORD *)&v6->mUsage = 1;
    v6->mMemoryPool = 0i64;
    v6->mContainerID = 0;
    v6->mCallbackData64 = 0i64;
    v6->mCallbackData32 = 0;
    v6->mNext = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&v20->mPrev;
    v20->mNext = v29;
    v20->mPrev = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&v6->mPrev;
    v29->mPrev = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&v20->mPrev;
    goto LABEL_18;
  }
  v30 = UFG::qVRAMemoryPool::GetUnusedBlock(v7);
  v31 = v6->mData;
  v32 = v20->mBlockID;
  v33 = v30;
  UFG::qPrintChannel::Print(
    &UFG::VRAMChannel,
    OUTPUT_LEVEL_DEBUG,
    "[VRAM Channel] - Setting Block ID:0x%04x to free data:%p size:0x%08x (%9u)\n");
  v20->mData = v31;
  v20->mRequestedSize = v14;
  v20->mActualSize = v14;
  *(_DWORD *)&v20->mUsage = 1;
  v20->mMemoryPool = 0i64;
  v20->mContainerID = 0;
  v20->mCallbackData64 = 0i64;
  v20->mCallbackData32 = 0;
  v20->mName = "Free VRAM";
  v34 = v33->mBlockID;
  v35 = &v6->mData[v6->mActualSize - v11];
  UFG::qPrintChannel::Print(
    &UFG::VRAMChannel,
    OUTPUT_LEVEL_DEBUG,
    "[VRAM Channel] - Setting Block ID:0x%04x to free data:%p size:0x%08x (%9u)\n");
  v33->mData = v35;
  v33->mRequestedSize = v11;
  v33->mActualSize = v11;
  *(_DWORD *)&v33->mUsage = 1;
  v33->mMemoryPool = 0i64;
  v33->mContainerID = 0;
  v33->mCallbackData64 = 0i64;
  v33->mCallbackData32 = 0;
  v33->mName = "Free VRAM";
  v36 = v6->mBlockID;
  v37 = &v6->mData[v14];
  UFG::qPrintChannel::Print(
    &UFG::VRAMChannel,
    OUTPUT_LEVEL_DEBUG,
    "[VRAM Channel] - Setting Block ID:0x%04x to free data:%p size:0x%08x (%9u)\n");
  v6->mData = v37;
  v6->mRequestedSize = v9;
  v6->mActualSize = v9;
  *(_DWORD *)&v6->mUsage = 1;
  v6->mMemoryPool = 0i64;
  v6->mContainerID = 0;
  v6->mCallbackData64 = 0i64;
  v6->mCallbackData32 = 0;
  v38 = (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)&v20->mPrev;
  v39 = (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)&v6->mPrev;
  v6->mName = "Free VRAM";
  v40 = v6->mPrev;
  v40->mNext = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&v20->mPrev;
  v20->mPrev = v40;
  v20->mNext = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&v6->mPrev;
  v41 = v6->mNext;
  v6->mPrev = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&v20->mPrev;
  v6->mNext = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&v33->mPrev;
  v33->mNext = v41;
  v33->mPrev = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&v6->mPrev;
  v41->mPrev = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&v33->mPrev;
  v42 = v6->mPrev;
  v42->mNext = (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)&v20->mPrev;
  v38->mPrev = v42;
  v38->mNext = (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)&v6->mPrev;
  v39->mPrev = (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)&v20->mPrev;
  v43 = (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)&v33->mPrev;
  v44 = v6->mNext;
  v7 = v49;
  v39->mNext = (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)&v33->mPrev;
  v43->mNext = v44;
  v43->mPrev = (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)&v6->mPrev;
  v44->mPrev = (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)&v33->mPrev;
LABEL_17:
  v45 = v39->mPrev;
  v46 = v39->mNext;
  v20 = v6;
  v45->mNext = v46;
  v46->mPrev = v45;
  v39->mNext = v39;
  v39->mPrev = v39;
LABEL_18:
  if ( v50 == 1 )
  {
    for ( i = (signed __int64)&v7->mFreeList.mNode.mNext[-1];
          (UFG::qList<UFG::BlockInfo,UFG::Primary,1,0> *)i != &v7->mUsedBlocks;
          i = *(_QWORD *)(i + 24) - 16i64 )
    {
      if ( *(_DWORD *)(i + 68) > v5 )
        v5 = *(_DWORD *)(i + 68);
    }
    v7->mLargestFreeBlock = v5;
  }
  return v20;
}

// File Line: 2539
// RVA: 0x172DF0
UFG::BlockInfo *__fastcall UFG::qVRAMemoryPool::GetUnusedBlock(UFG::qVRAMemoryPool *this)
{
  UFG::qVRAMemoryPool *v1; // rbx
  unsigned __int16 v2; // ax
  UFG::BlockInfo *v3; // rdx
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v4; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v5; // rcx
  UFG::BlockInfo *result; // rax
  unsigned __int16 v7; // cx

  v1 = this;
  if ( this->mNumBlocksTotal )
  {
    if ( (UFG::qList<UFG::BlockInfo,UFG::Primary,1,0> *)this->mUnusedBlocks.mNode.mNext == &this->mUnusedBlocks )
    {
      result = 0i64;
    }
    else
    {
      v2 = ++this->mUsedBlocksCount;
      if ( v2 > this->mUsedBlocksMax )
        this->mUsedBlocksMax = v2;
      v3 = (UFG::BlockInfo *)this->mUnusedBlocks.mNode.mNext;
      v4 = v3->mNext;
      v5 = v3->mPrev;
      v5->mNext = v4;
      v4->mPrev = v5;
      v3->mPrev = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&v3->mPrev;
      v3->mNext = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&v3->mPrev;
      result = v3;
    }
  }
  else
  {
    result = UFG::qVRAMemoryPools::GetUnusedBlock();
    if ( result )
    {
      v7 = ++v1->mUsedBlocksCount;
      if ( v7 > v1->mUsedBlocksMax )
        v1->mUsedBlocksMax = v7;
    }
  }
  return result;
}

// File Line: 2566
// RVA: 0x17BBF0
void __fastcall UFG::qVRAMemoryPool::ReturnUsedBlock(UFG::qVRAMemoryPool *this, UFG::BlockInfo *block)
{
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v2; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v3; // rcx

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
    v2 = &this->mUnusedBlocks.mNode;
    v3 = this->mUnusedBlocks.mNode.mNext;
    v2->mNext = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&block->mPrev;
    block->mPrev = v2;
    block->mNext = v3;
    v3->mPrev = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&block->mPrev;
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
  UFG::BlockInfo *v2; // rbx
  UFG::qVRAMemoryPool *v3; // rbp
  char *v4; // ST30_8
  int v5; // ST28_4
  char v6; // al
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v7; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v8; // rcx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v9; // rdi
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v10; // rcx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v11; // rax
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v12; // rcx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v13; // rax
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v15; // rdi
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v16; // rcx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v17; // rax
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v18; // rcx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v19; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v20; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v21; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v22; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v23; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v24; // rdx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v25; // rdi
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v26; // rcx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v27; // rax
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v28; // rcx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v29; // rax
  UFG::BlockInfo *v30; // rax
  UFG::BlockInfo *v31; // rbx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v32; // rax
  unsigned int v33; // eax
  UFG::qVRAMemoryPool *v34; // [rsp+60h] [rbp+8h]

  v34 = this;
  v2 = block;
  v3 = this;
  v4 = block->mData;
  v5 = block->mBlockID;
  UFG::qPrintChannel::Print(
    &UFG::VRAMChannel,
    OUTPUT_LEVEL_WARNING,
    "[VRAM Channel] - '%.64s'->InternalFree(%p - [%04u]%p)\n");
  v6 = v2->mUsage;
  if ( (unsigned __int8)v6 >= 2u )
  {
    if ( v6 == 11 )
    {
      if ( !v3->mNumBlocksTotal )
        UFG::qVRAMemoryPools::GetBlock(v2->mContainerID);
      v7 = v2->mNext;
      v8 = v2->mPrev;
      v8->mNext = v7;
      v7->mPrev = v8;
      v2->mPrev = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&v2->mPrev;
      v2->mNext = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&v2->mPrev;
      if ( (UFG::qList<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly,1,0> *)v2->mAllocationHandles.mNode.mNext != &v2->mAllocationHandles )
      {
        do
        {
          v9 = v2->mAllocationHandles.mNode.mNext;
          v10 = v9->mPrev;
          v11 = v9->mNext;
          v10->mNext = v11;
          v11->mPrev = v10;
          v9->mPrev = v9;
          v9->mNext = v9;
          UFG::qPrintChannel::Print(
            &UFG::VRAMChannel,
            OUTPUT_LEVEL_DEBUG,
            "[VRAM Channel] - Setting qVRAMemoryHandle(%p) to point at - PoolID:0x%02x BlockID:0x%04x Data:%p-%p AllocatedSize:%u\n");
          v12 = v9->mPrev;
          v13 = v9->mNext;
          v12->mNext = v13;
          v13->mPrev = v12;
          v9->mPrev = v9;
          v9->mNext = v9;
          v9[1].mPrev = 0i64;
          LODWORD(v9[1].mNext) = 0;
        }
        while ( (UFG::qList<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly,1,0> *)v2->mAllocationHandles.mNode.mNext != &v2->mAllocationHandles );
        v3 = v34;
      }
    }
    else
    {
      if ( !(v2->mFlags & 0x10) )
      {
        if ( (unsigned __int8)(v6 - 9) <= 1u )
        {
          v22 = v2->mPrev;
          v23 = v2->mNext;
          v24 = (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)&v2->mPrev;
          v22->mNext = v23;
          v23->mPrev = v22;
          v24->mPrev = v24;
          v24->mNext = v24;
          while ( (UFG::qList<UFG::BlockInfo,UFG::Primary,1,0> *)v2->mContainedBlocks.mNode.mNext != &v2->mContainedBlocks )
            UFG::qVRAMemoryPool::InternalFree(v3, (UFG::BlockInfo *)v2->mContainedBlocks.mNode.mNext);
        }
        if ( (UFG::qList<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly,1,0> *)v2->mAllocationHandles.mNode.mNext != &v2->mAllocationHandles )
        {
          do
          {
            v25 = v2->mAllocationHandles.mNode.mNext;
            v26 = v25->mPrev;
            v27 = v25->mNext;
            v26->mNext = v27;
            v27->mPrev = v26;
            v25->mPrev = v25;
            v25->mNext = v25;
            UFG::qPrintChannel::Print(
              &UFG::VRAMChannel,
              OUTPUT_LEVEL_DEBUG,
              "[VRAM Channel] - Setting qVRAMemoryHandle(%p) to point at - PoolID:0x%02x BlockID:0x%04x Data:%p-%p AllocatedSize:%u\n");
            v28 = v25->mPrev;
            v29 = v25->mNext;
            v28->mNext = v29;
            v29->mPrev = v28;
            v25->mPrev = v25;
            v25->mNext = v25;
            v25[1].mPrev = 0i64;
            LODWORD(v25[1].mNext) = 0;
          }
          while ( (UFG::qList<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly,1,0> *)v2->mAllocationHandles.mNode.mNext != &v2->mAllocationHandles );
          v3 = v34;
        }
        v3->mFreeMemory += v2->mActualSize;
        v3->mUsedMemory -= v2->mActualSize;
        v3->mAllocatedMemory -= v2->mRequestedSize;
        v3->mAlignmentLoss += v2->mRequestedSize - v2->mActualSize;
        UFG::BlockInfo::SetFree(v2);
        v30 = UFG::qVRAMemoryPool::MergeFreeBlock(v3, v2);
        v31 = v30;
        v32 = (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)&v30->mPrev;
        if ( v32->mPrev == v32 && v32->mNext == v32 )
          UFG::qVRAMemoryPool::AddBlockToFreeList(v3, v31);
        v33 = v31->mActualSize;
        if ( v33 > v3->mLargestFreeBlock )
          v3->mLargestFreeBlock = v33;
        if ( v3->mLargestFreeBlock != v3->mFreeMemory )
          *(_WORD *)&v3->mNeedsDefragmentUp = 257;
        return 1;
      }
      if ( (UFG::qList<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly,1,0> *)v2->mAllocationHandles.mNode.mNext != &v2->mAllocationHandles )
      {
        do
        {
          v15 = v2->mAllocationHandles.mNode.mNext;
          v16 = v15->mPrev;
          v17 = v15->mNext;
          v16->mNext = v17;
          v17->mPrev = v16;
          v15->mPrev = v15;
          v15->mNext = v15;
          UFG::qPrintChannel::Print(
            &UFG::VRAMChannel,
            OUTPUT_LEVEL_DEBUG,
            "[VRAM Channel] - Setting qVRAMemoryHandle(%p) to point at - PoolID:0x%02x BlockID:0x%04x Data:%p-%p AllocatedSize:%u\n");
          v18 = v15->mPrev;
          v19 = v15->mNext;
          v18->mNext = v19;
          v19->mPrev = v18;
          v15->mPrev = v15;
          v15->mNext = v15;
          v15[1].mPrev = 0i64;
          LODWORD(v15[1].mNext) = 0;
        }
        while ( (UFG::qList<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly,1,0> *)v2->mAllocationHandles.mNode.mNext != &v2->mAllocationHandles );
        v3 = v34;
      }
      v20 = v2->mPrev;
      v21 = v2->mNext;
      v20->mNext = v21;
      v21->mPrev = v20;
      LODWORD(v21) = v2->mRequestedSize;
      v2->mPrev = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&v2->mPrev;
      v2->mNext = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&v2->mPrev;
      v3->mUsedMainMemory -= (unsigned int)v21;
      UFG::qMemoryPool::Free(v2->mMemoryPool, v2->mData);
    }
    UFG::qVRAMemoryPool::ReturnUsedBlock(v3, v2);
    return 1;
  }
  return 0;
}

// File Line: 2686
// RVA: 0x177A50
UFG::BlockInfo *__fastcall UFG::qVRAMemoryPool::MergeFreeBlock(UFG::qVRAMemoryPool *this, UFG::BlockInfo *block)
{
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v2; // rbp
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v3; // r14
  UFG::qList<UFG::BlockInfo,UFG::Primary,1,0> *v4; // r15
  UFG::BlockInfo *v5; // rsi
  UFG::qVRAMemoryPool *v6; // r13
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v7; // rbx
  __int64 v8; // r9
  unsigned int v9; // edi
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v10; // rdx
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v11; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v12; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v13; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v14; // rax
  char *v15; // rbx
  __int64 v16; // r9
  int v17; // edi
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v18; // r9
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v19; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v20; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v21; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v22; // r8

  v2 = block->mNext;
  v3 = block->mPrev;
  v4 = &this->mUsedBlocks;
  v5 = block;
  v6 = this;
  if ( (UFG::qList<UFG::BlockInfo,UFG::Primary,1,0> *)block->mPrev != &this->mUsedBlocks
    && BYTE2(v3[4].mNext) == block->mUsage )
  {
    v7 = v3[3].mPrev;
    v8 = LOWORD(v3[4].mNext);
    v9 = HIDWORD(v3[4].mPrev) + block->mActualSize;
    UFG::qPrintChannel::Print(
      &UFG::VRAMChannel,
      OUTPUT_LEVEL_DEBUG,
      "[VRAM Channel] - Setting Block ID:0x%04x to free data:%p size:0x%08x (%9u)\n");
    v3[3].mPrev = v7;
    LODWORD(v3[4].mPrev) = v9;
    HIDWORD(v3[4].mPrev) = v9;
    *(_DWORD *)((char *)&v3[4].mNext + 2) = 1;
    v3[5].mPrev = 0i64;
    LOWORD(v3[6].mNext) = 0;
    v3[7].mPrev = 0i64;
    LODWORD(v3[7].mNext) = 0;
    v10 = (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)&v5->mPrev;
    v3[3].mNext = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)"Free VRAM";
    v11 = v5->mPrev;
    v12 = v5->mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    v5->mPrev = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&v5->mPrev;
    v5->mNext = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&v5->mPrev;
    v13 = v5->mPrev;
    v14 = v5->mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v10->mPrev = v10;
    v10->mNext = v10;
    UFG::qVRAMemoryPool::ReturnUsedBlock(v6, v5);
    v5 = (UFG::BlockInfo *)v3;
  }
  if ( v2 == (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)v4 || BYTE2(v2[4].mNext) != v5->mUsage )
    return v5;
  v15 = v5->mData;
  v16 = LOWORD(v2[4].mNext);
  v17 = HIDWORD(v2[4].mPrev) + v5->mActualSize;
  UFG::qPrintChannel::Print(
    &UFG::VRAMChannel,
    OUTPUT_LEVEL_DEBUG,
    "[VRAM Channel] - Setting Block ID:0x%04x to free data:%p size:0x%08x (%9u)\n");
  v2[3].mPrev = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)v15;
  LODWORD(v2[4].mPrev) = v17;
  HIDWORD(v2[4].mPrev) = v17;
  *(_DWORD *)((char *)&v2[4].mNext + 2) = 1;
  v2[5].mPrev = 0i64;
  LOWORD(v2[6].mNext) = 0;
  v2[7].mPrev = 0i64;
  LODWORD(v2[7].mNext) = 0;
  v18 = (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)&v5->mPrev;
  v2[3].mNext = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)"Free VRAM";
  v19 = v5->mPrev;
  v20 = v5->mNext;
  v19->mNext = v20;
  v20->mPrev = v19;
  v5->mPrev = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&v5->mPrev;
  v5->mNext = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&v5->mPrev;
  v21 = v5->mNext;
  v22 = v5->mPrev;
  v22->mNext = v21;
  v21->mPrev = v22;
  v18->mPrev = v18;
  v18->mNext = v18;
  UFG::qVRAMemoryPool::ReturnUsedBlock(v6, v5);
  return (UFG::BlockInfo *)v2;
}

// File Line: 2719
// RVA: 0x165EC0
char __fastcall UFG::qVRAMemoryPool::AddBlockToFreeList(UFG::qVRAMemoryPool *this, UFG::BlockInfo *block)
{
  UFG::BlockInfo *v2; // r9
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v3; // rdx
  UFG::qVRAMemoryPool *v4; // r10
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v5; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v6; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v7; // rdx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v8; // rdx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v9; // rax

  v2 = block;
  v3 = this->mFreeList.mNode.mNext - 1;
  v4 = this;
  if ( v3 != (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)&this->mUsedBlocks )
  {
    while ( v3[3].mPrev <= (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)v2->mData )
    {
      v3 = v3[1].mNext - 1;
      if ( v3 == (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)&this->mUsedBlocks )
        goto LABEL_6;
    }
    v5 = v3[1].mPrev;
    v6 = (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)&v2->mPrev;
    v7 = v3 + 1;
    v5->mNext = (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)&v2->mPrev;
    v6->mPrev = v5;
    v6->mNext = v7;
    v7->mPrev = (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)&v2->mPrev;
  }
LABEL_6:
  v8 = (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)&v2->mPrev;
  if ( v8->mPrev == v8 && (UFG::qNode<UFG::BlockInfo,UFG::Secondary> **)v2->mNext == &v2->mPrev )
  {
    v9 = v4->mFreeList.mNode.mPrev;
    v9->mNext = v8;
    v8->mPrev = v9;
    v2->mNext = &v4->mFreeList.mNode;
    v4->mFreeList.mNode.mPrev = v8;
  }
  return 1;
}

// File Line: 2786
// RVA: 0x167740
void __fastcall UFG::qVRAMemoryPool::AssertValidInitialized(UFG::qVRAMemoryPool *this)
{
  UFG::qVRAMemoryPool *v1; // rbx
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v2; // rax
  signed __int64 v3; // rdx
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *i; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v5; // rcx
  signed __int64 j; // r8
  unsigned int v7; // edx
  signed __int64 k; // rcx
  signed __int64 l; // rax
  UFG::qVRAMemoryPool *m; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v11; // rax
  signed __int64 v12; // rbx
  signed __int64 n; // rax

  v1 = this;
  if ( !this->mNumBlocksTotal )
  {
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMBlocksLock);
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMBlocksLock);
  }
  if ( !v1->mNumBlocksTotal )
  {
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMBlocksLock);
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMBlocksLock);
  }
  v2 = v1->mMainMemoryBlocks.mNode.mNext;
  v3 = (signed __int64)&v1->mMainMemoryBlocks;
  for ( i = v2; i != (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)v3; i = i->mNext )
    ;
  v5 = v1->mUsedBlocks.mNode.mNext;
  for ( j = (signed __int64)&v1->mUsedBlocks; v5 != (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)j; v5 = v5->mNext )
    ;
  for ( ; v2 != (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)v3; v2 = v2->mNext )
    ;
  v7 = 0;
  for ( k = (signed __int64)&v1->mFreeList.mNode.mNext[-1]; k != j; k = *(_QWORD *)(k + 24) - 16i64 )
  {
    if ( *(_DWORD *)(k + 68) > v7 )
      v7 = *(_DWORD *)(k + 68);
  }
  for ( l = (signed __int64)&v1->mPendingFreeList.mNode.mNext[-1];
        (UFG::qList<UFG::BlockInfo,UFG::Secondary,1,0> *)l != &v1->mFreeList;
        l = *(_QWORD *)(l + 24) - 16i64 )
  {
    ;
  }
  for ( m = (UFG::qVRAMemoryPool *)v1->mUnusedBlocks.mNode.mNext;
        m != (UFG::qVRAMemoryPool *)&v1->mUnusedBlocks;
        m = (UFG::qVRAMemoryPool *)m->mNext )
  {
    ;
  }
  v11 = v1->mContainerList.mNode.mNext;
  v12 = (signed __int64)&v1->mMoveTargetsList;
  for ( n = (signed __int64)&v11[-1]; n != v12; n = *(_QWORD *)(n + 24) - 16i64 )
    ;
}

// File Line: 3006
// RVA: 0x1467B80
__int64 dynamic_initializer_for__UFG::qVRAMemoryPools::sVRAMPoolsLock__()
{
  UFG::qMutex::qMutex(&UFG::qVRAMemoryPools::sVRAMPoolsLock, "qVRAMemory::sVRAMPoolsLock");
  return atexit(dynamic_atexit_destructor_for__UFG::qVRAMemoryPools::sVRAMPoolsLock__);
}

// File Line: 3007
// RVA: 0x1467AD0
__int64 dynamic_initializer_for__UFG::qVRAMemoryPools::sMainVRAMemoryPool__()
{
  UFG::qVRAMemoryPool::qVRAMemoryPool(&UFG::qVRAMemoryPools::sMainVRAMemoryPool);
  return atexit(dynamic_atexit_destructor_for__UFG::qVRAMemoryPools::sMainVRAMemoryPool__);
}

// File Line: 3011
// RVA: 0x1467B50
__int64 dynamic_initializer_for__UFG::qVRAMemoryPools::sVRAMBlocksLock__()
{
  UFG::qMutex::qMutex(&UFG::qVRAMemoryPools::sVRAMBlocksLock, "qVRAMemory::sVRAMBlocksLock");
  return atexit(dynamic_atexit_destructor_for__UFG::qVRAMemoryPools::sVRAMBlocksLock__);
}

// File Line: 3012
// RVA: 0x1467B30
__int64 dynamic_initializer_for__UFG::qVRAMemoryPools::sUnusedBlocks__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::qVRAMemoryPools::sUnusedBlocks__);
}

// File Line: 3023
// RVA: 0x173B70
char __fastcall UFG::qVRAMemoryPools::InitSystem(char *main_pool_vram_start, unsigned int main_pool_vram_size, const char *main_pool_name, unsigned __int16 main_pool_num_blocks, unsigned int main_pool_alignment, char *main_pool_block_memory, unsigned int main_pool_block_memory_size, unsigned __int16 common_num_blocks, char *common_block_memory, unsigned int common_block_memory_size)
{
  unsigned __int16 v10; // r14
  const char *v11; // r15
  unsigned int v12; // er12
  char *v13; // r13
  unsigned __int64 v14; // rbx
  unsigned __int8 v15; // cf
  unsigned __int64 v16; // rbx
  UFG::qMemoryPool *v17; // rcx
  UFG::allocator::free_link *v18; // rax
  unsigned __int16 v19; // bx
  UFG::BlockInfo *v20; // rsi
  unsigned __int16 i; // dx
  UFG::BlockInfo *v22; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v23; // rax
  UFG::qList<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly,1,0> *v24; // ST50_8
  UFG::qList<UFG::BlockInfo,UFG::Primary,1,0> *v25; // ST50_8
  UFG::BlockInfo *v26; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v27; // rax
  UFG::qVRAMemoryPool *v28; // rbx

  v10 = main_pool_num_blocks;
  v11 = main_pool_name;
  v12 = main_pool_vram_size;
  v13 = main_pool_vram_start;
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
          v22->mPrev = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&v22->mPrev;
          v22->mNext = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&v22->mPrev;
          v23 = (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)&v22->mPrev;
          v23->mPrev = v23;
          v23->mNext = v23;
          v24 = &v22->mAllocationHandles;
          v24->mNode.mPrev = &v24->mNode;
          v24->mNode.mNext = &v24->mNode;
          v22->mData = 0i64;
          v22->mName = 0i64;
          *(_QWORD *)&v22->mRequestedSize = 0i64;
          *(_DWORD *)&v22->mBlockID = 0xFFFF;
          *(_WORD *)&v22->mKeepAliveFrames = 0;
          v22->mMemoryPool = 0i64;
          v25 = &v22->mContainedBlocks;
          v25->mNode.mPrev = &v25->mNode;
          v25->mNode.mNext = &v25->mNode;
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
        `eh vector constructor iterator'(
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
    if ( common_num_blocks > 0u )
    {
      do
      {
        v26 = &UFG::qVRAMemoryPools::sBlocks[(unsigned __int64)v19];
        v26->mBlockID = v19;
        v27 = UFG::qVRAMemoryPools::sUnusedBlocks.mNode.mPrev;
        UFG::qVRAMemoryPools::sUnusedBlocks.mNode.mPrev->mNext = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&v26->mPrev;
        v26->mPrev = v27;
        v26->mNext = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&UFG::qVRAMemoryPools::sUnusedBlocks;
        UFG::qVRAMemoryPools::sUnusedBlocks.mNode.mPrev = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&v26->mPrev;
        ++v19;
      }
      while ( v19 < UFG::qVRAMemoryPools::sNumBlocksTotal );
    }
  }
  v28 = &UFG::qVRAMemoryPools::sMainVRAMemoryPool;
  if ( (unsigned __int8)UFG::qVRAMemoryPool::Init(
                          &UFG::qVRAMemoryPools::sMainVRAMemoryPool,
                          v13,
                          v12,
                          v11,
                          v10,
                          main_pool_alignment,
                          main_pool_block_memory,
                          main_pool_block_memory_size) != 1 )
    v28 = UFG::gMainVRAMemoryPool;
  UFG::gMainVRAMemoryPool = v28;
  return 1;
}

// File Line: 3080
// RVA: 0x17CEE0
void __fastcall UFG::qVRAMemoryPools::SetDefaultDefragCallback(void (__fastcall *callback)(UFG::qVRAMemoryHandle *, char *, UFG::VRAMType, unsigned __int64, unsigned int))
{
  void (__fastcall *v1)(UFG::qVRAMemoryHandle *, char *, UFG::VRAMType, unsigned __int64, unsigned int); // rbx

  v1 = callback;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
  UFG::qVRAMemoryPools::sVRAMDefaultDefragCallback = v1;
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
}

// File Line: 3132
// RVA: 0x1701F0
__int64 __fastcall UFG::qVRAMemoryPools::GetDefragmentMoves(UFG::qVRAMemoryMoveOrder *moves, int moves_count, unsigned int requested_total_bytes)
{
  int v3; // ebx
  unsigned int v4; // er14
  int v5; // esi
  UFG::qVRAMemoryMoveOrder *v6; // rbp
  int v7; // eax
  signed int v8; // edi
  UFG::qVRAMemoryPool *v9; // rcx
  unsigned int total_bytes; // [rsp+58h] [rbp+10h]

  v3 = 0;
  v4 = requested_total_bytes;
  v5 = moves_count;
  v6 = moves;
  total_bytes = 0;
  if ( moves_count > 0 && moves )
  {
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
    v7 = sCurrentPoolId;
    v8 = 0;
    do
    {
      if ( v3 >= v5 )
        break;
      v9 = UFG::qVRAMemoryPools::sVRAMemoryPools[v7];
      if ( v9 )
      {
        v3 += UFG::qVRAMemoryPool::GetDefragmentMoves(v9, &v6[(signed __int64)v3], v5 - v3, v4, &total_bytes);
        LOBYTE(v7) = sCurrentPoolId;
      }
      ++v8;
      v7 = ((_BYTE)v7 + 1) & 0xF;
      sCurrentPoolId = v7;
    }
    while ( v8 < 16 );
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
  }
  return (unsigned int)v3;
}

// File Line: 3168
// RVA: 0x178100
void __fastcall UFG::qVRAMemoryPools::MovesCompleted(UFG::qVRAMemoryMoveOrder *moves, int moves_count, void (__fastcall *callback)(UFG::qVRAMemoryHandle *, char *, UFG::VRAMType, unsigned __int64, unsigned int))
{
  __int64 v3; // rsi
  UFG::qVRAMemoryMoveOrder *v4; // rbx
  void (__fastcall *v5)(UFG::qVRAMemoryHandle *, char *, UFG::VRAMType, unsigned __int64, unsigned int); // rbp
  unsigned __int16 *v6; // rdi
  UFG::qVRAMemoryPool *v7; // rcx
  void (__fastcall *v8)(UFG::qVRAMemoryHandle *, char *, UFG::VRAMType, unsigned __int64, unsigned int); // r8

  v3 = (unsigned int)moves_count;
  v4 = moves;
  v5 = callback;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
  if ( (signed int)v3 > 0 )
  {
    v6 = &v4->mTargetHandle.mReadOnlyAndPoolID;
    do
    {
      v7 = UFG::qVRAMemoryPools::sVRAMemoryPools[*v6 & 0x7FFF];
      if ( v7 )
      {
        v8 = UFG::qVRAMemoryPools::sVRAMDefaultDefragCallback;
        if ( v5 )
          v8 = v5;
        UFG::qVRAMemoryPool::MoveCompleted(v7, v4, v8);
      }
      ++v4;
      v6 += 32;
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
  signed __int64 v1; // r15
  UFG::qVRAMemoryPool *v2; // rdi
  UFG::BlockInfo *v3; // rdx
  signed __int64 v4; // rbx
  char v5; // al
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v6; // rcx
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v7; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Secondary> *v8; // r8

  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
  v0 = UFG::qVRAMemoryPools::sVRAMemoryPools;
  v1 = 16i64;
  do
  {
    v2 = *v0;
    if ( *v0 )
    {
      UFG::qPrintChannel::Print(&UFG::VRAMChannel, OUTPUT_LEVEL_WARNING, "[VRAM Channel] - '%.64s'->ServiceDeletes()\n");
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&v2->mPoolLock);
      if ( v2->mValidate )
      {
        UFG::qPrintChannel::Print(&UFG::VRAMChannel, OUTPUT_LEVEL_WARNING, "[VRAM Channel] - '%.64s'->AssertValid()\n");
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
          v4 = (signed __int64)&v3->mNext[-1];
          if ( !(v3->mFlags & 0x40) )
          {
            v5 = v3->mKeepAliveFrames;
            if ( (unsigned __int8)v5 <= 1u )
            {
              v6 = v3->mPrev;
              v7 = v3->mNext;
              v8 = (UFG::qNode<UFG::BlockInfo,UFG::Secondary> *)&v3->mPrev;
              v6->mNext = v7;
              v7->mPrev = v6;
              v8->mPrev = v8;
              v8->mNext = v8;
              UFG::qVRAMemoryPool::InternalFree(v2, v3);
            }
            else
            {
              v3->mKeepAliveFrames = v5 - 1;
            }
          }
          v3 = (UFG::BlockInfo *)v4;
        }
        while ( (UFG::qList<UFG::BlockInfo,UFG::Secondary,1,0> *)v4 != &v2->mFreeList );
      }
      if ( v2->mValidate )
      {
        UFG::qPrintChannel::Print(&UFG::VRAMChannel, OUTPUT_LEVEL_WARNING, "[VRAM Channel] - '%.64s'->AssertValid()\n");
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
  UFG::qVRAMemoryHandle *v1; // rbx
  unsigned __int8 v2; // di
  unsigned __int16 v3; // ax
  UFG::qVRAMemoryPool *v4; // rcx

  v1 = handle;
  v2 = 0;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
  if ( v1->mData )
  {
    v3 = v1->mReadOnlyAndPoolID & 0x7FFF;
    if ( v3 < 0x10u )
    {
      v4 = UFG::qVRAMemoryPools::sVRAMemoryPools[v3];
      if ( v4 )
        v2 = UFG::qVRAMemoryPool::Lock(v4, v1);
    }
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
  return v2;
}

// File Line: 3218
// RVA: 0x17F460
__int64 __fastcall UFG::qVRAMemoryPools::Unlock(UFG::qVRAMemoryHandle *handle)
{
  UFG::qVRAMemoryHandle *v1; // rbx
  unsigned __int8 v2; // di
  unsigned __int16 v3; // ax
  UFG::qVRAMemoryPool *v4; // rcx

  v1 = handle;
  v2 = 0;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
  if ( v1->mData )
  {
    v3 = v1->mReadOnlyAndPoolID & 0x7FFF;
    if ( v3 < 0x10u )
    {
      v4 = UFG::qVRAMemoryPools::sVRAMemoryPools[v3];
      if ( v4 )
        v2 = UFG::qVRAMemoryPool::Unlock(v4, v1);
    }
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
  return v2;
}

// File Line: 3236
// RVA: 0x178C50
__int64 __fastcall UFG::qVRAMemoryPools::PreMove(UFG::qVRAMemoryHandle *handle)
{
  UFG::qVRAMemoryHandle *v1; // rbx
  unsigned __int8 v2; // di
  unsigned __int16 v3; // ax
  UFG::qVRAMemoryPool *v4; // rcx

  v1 = handle;
  v2 = 0;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
  if ( v1->mData )
  {
    v3 = v1->mReadOnlyAndPoolID & 0x7FFF;
    if ( v3 < 0x10u )
    {
      v4 = UFG::qVRAMemoryPools::sVRAMemoryPools[v3];
      if ( v4 )
        v2 = UFG::qVRAMemoryPool::PreMove(v4, v1);
    }
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
  return v2;
}

// File Line: 3254
// RVA: 0x178A80
__int64 __fastcall UFG::qVRAMemoryPools::PostMove(UFG::qVRAMemoryHandle *handle)
{
  UFG::qVRAMemoryHandle *v1; // rbx
  unsigned __int8 v2; // di
  unsigned __int16 v3; // ax
  UFG::qVRAMemoryPool *v4; // rcx

  v1 = handle;
  v2 = 0;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
  if ( v1->mData )
  {
    v3 = v1->mReadOnlyAndPoolID & 0x7FFF;
    if ( v3 < 0x10u )
    {
      v4 = UFG::qVRAMemoryPools::sVRAMemoryPools[v3];
      if ( v4 )
        v2 = UFG::qVRAMemoryPool::PostMove(v4, v1);
    }
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
  return v2;
}

// File Line: 3272
// RVA: 0x172170
__int64 __fastcall UFG::qVRAMemoryPools::GetRequestedSize(UFG::qVRAMemoryHandle *handle)
{
  UFG::qVRAMemoryHandle *v1; // rbx
  unsigned int v2; // edi
  unsigned __int16 v3; // ax
  UFG::qVRAMemoryPool *v4; // rcx

  v1 = handle;
  v2 = 0;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
  if ( v1->mData )
  {
    v3 = v1->mReadOnlyAndPoolID & 0x7FFF;
    if ( v3 < 0x10u )
    {
      v4 = UFG::qVRAMemoryPools::sVRAMemoryPools[v3];
      if ( v4 )
        v2 = UFG::qVRAMemoryPool::GetRequestedSize(v4, v1);
    }
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
  return v2;
}

// File Line: 3290
// RVA: 0x16F3A0
__int64 __fastcall UFG::qVRAMemoryPools::GetAllocatedSize(UFG::qVRAMemoryHandle *handle)
{
  UFG::qVRAMemoryHandle *v1; // rbx
  unsigned int v2; // edi
  unsigned __int16 v3; // ax
  UFG::qVRAMemoryPool *v4; // rcx

  v1 = handle;
  v2 = 0;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
  if ( v1->mData )
  {
    v3 = v1->mReadOnlyAndPoolID & 0x7FFF;
    if ( v3 < 0x10u )
    {
      v4 = UFG::qVRAMemoryPools::sVRAMemoryPools[v3];
      if ( v4 )
        v2 = UFG::qVRAMemoryPool::GetAllocatedSize(v4, v1);
    }
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
  return v2;
}

// File Line: 3308
// RVA: 0x167A40
__int64 __fastcall UFG::qVRAMemoryPools::BindWithinContainer(UFG::qVRAMemoryHandle *handle, char *data, unsigned int data_size, const char *name)
{
  char *v4; // rbp
  UFG::qVRAMemoryHandle *v5; // r13
  __int64 v6; // rdi
  unsigned __int8 v7; // si
  unsigned int v8; // er11
  UFG::qVRAMemoryPool *v9; // r14
  UFG::qVRAMemoryPool **v10; // r10
  signed __int64 v11; // r9
  UFG::qVRAMemoryPool *v12; // rdx
  unsigned __int64 v13; // rax
  __int64 v14; // r8
  signed __int64 v15; // rbx
  unsigned __int64 v16; // rcx
  __int64 v17; // rcx
  __int64 v18; // rdx
  UFG::BlockInfo *v19; // rsi
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v20; // rax
  unsigned __int16 v21; // di
  unsigned __int16 v22; // bx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v23; // rax
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v24; // rcx
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v25; // r10
  UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *v26; // rax
  __int64 v28; // [rsp+28h] [rbp-50h]
  __int64 v29; // [rsp+30h] [rbp-48h]
  const char *v30; // [rsp+98h] [rbp+20h]

  v30 = name;
  v4 = data;
  v5 = handle;
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
      v13 = (unsigned __int64)v12->mVRAMemoryStart;
      v14 = v12->mVRAMemorySize;
      if ( v13 <= (unsigned __int64)v4 && v13 + v14 >= (unsigned __int64)&v4[v6] && (unsigned int)v14 < v8 )
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
    HIDWORD(v28) = HIDWORD(v4);
    UFG::qPrintChannel::Print(
      &UFG::VRAMChannel,
      OUTPUT_LEVEL_WARNING,
      "[VRAM Channel] - '%.64s'->BindWithinContainer(handle(%p), %p, 0x%08x(%u), '%.64s'%s)\n");
    v7 = 0;
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&v9->mPoolLock);
    if ( v9->mValidate )
    {
      UFG::qPrintChannel::Print(&UFG::VRAMChannel, OUTPUT_LEVEL_WARNING, "[VRAM Channel] - '%.64s'->AssertValid()\n");
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&v9->mPoolLock);
      if ( v9->mInitialized == 1 )
        UFG::qVRAMemoryPool::AssertValidInitialized(v9);
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v9->mPoolLock);
    }
    if ( v9->mInitialized == 1 )
    {
      v15 = (signed __int64)&v9->mContainerList.mNode.mNext[-1];
      if ( (UFG::qList<UFG::BlockInfo,UFG::Secondary,1,0> *)v15 != &v9->mMoveTargetsList )
      {
        while ( 1 )
        {
          v16 = *(_QWORD *)(v15 + 48);
          if ( v16 <= (unsigned __int64)v4 && v16 + *(unsigned int *)(v15 + 68) > (unsigned __int64)v4 )
            break;
          v15 = *(_QWORD *)(v15 + 24) - 16i64;
          if ( (UFG::qList<UFG::BlockInfo,UFG::Secondary,1,0> *)v15 == &v9->mMoveTargetsList )
            goto LABEL_22;
        }
        v17 = *(unsigned int *)(v15 + 68);
        v18 = *(_QWORD *)(v15 + 48);
        if ( v17 + v18 < (unsigned __int64)&v4[v6] )
        {
          LODWORD(v29) = *(_DWORD *)(v15 + 68);
          LODWORD(v28) = *(_DWORD *)(v15 + 68);
          UFG::qPrintf(
            "WARNING: Requested block of size %u(0x%08x) from %p to %p does not fit within\n"
            "               container of size %u(0x%08x) from %p to %p\n",
            (unsigned int)v6,
            (unsigned int)v6,
            v4,
            &v4[v6],
            v28,
            v29,
            v18,
            v17 + v18,
            &customWorldMapCaption);
        }
        v19 = UFG::qVRAMemoryPool::GetUnusedBlock(v9);
        v20 = *(UFG::qNode<UFG::BlockInfo,UFG::Primary> **)(v15 + 88);
        v20->mNext = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&v19->mPrev;
        v19->mNext = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)(v15 + 88);
        v19->mPrev = v20;
        *(_QWORD *)(v15 + 88) = v19;
        v19->mContainerID = *(_WORD *)(v15 + 72);
        v19->mRequestedSize = v6;
        v21 = v19->mBlockID;
        v19->mName = v30;
        v19->mActualSize = 0;
        v19->mMemoryPool = 0i64;
        v19->mCallbackData64 = 0i64;
        v19->mCallbackData32 = 0;
        v19->mData = v4;
        *(_DWORD *)&v19->mUsage = 11;
        v22 = v9->mPoolID;
        UFG::qPrintChannel::Print(
          &UFG::VRAMChannel,
          OUTPUT_LEVEL_DEBUG,
          "[VRAM Channel] - Setting qVRAMemoryHandle(%p) to point at - PoolID:0x%02x BlockID:0x%04x Data:%p-%p AllocatedSize:%u\n");
        v23 = v5->mNext;
        v24 = v5->mPrev;
        v25 = &v19->mAllocationHandles.mNode;
        v24->mNext = v23;
        v23->mPrev = v24;
        v5->mPrev = (UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *)&v5->mPrev;
        v5->mNext = (UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *)&v5->mPrev;
        v5->mData = v4;
        v5->mReadOnlyAndPoolID = v22;
        v5->mBlockID = v21;
        v26 = v19->mAllocationHandles.mNode.mPrev;
        v7 = 1;
        v26->mNext = (UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *)&v5->mPrev;
        v5->mPrev = v26;
        v5->mNext = v25;
        v25->mPrev = (UFG::qNode<UFG::qVRAMemoryHandle,UFG::qVRAMemoryPoolOnly> *)&v5->mPrev;
      }
    }
LABEL_22:
    if ( v9->mValidate )
    {
      UFG::qPrintChannel::Print(&UFG::VRAMChannel, OUTPUT_LEVEL_WARNING, "[VRAM Channel] - '%.64s'->AssertValid()\n");
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
_BOOL8 __fastcall UFG::qVRAMemoryPools::Free(UFG::qVRAMemoryHandle *handle, unsigned int frames_to_delay)
{
  unsigned int v2; // esi
  UFG::qVRAMemoryHandle *v3; // rbx
  bool v4; // di
  unsigned __int16 v5; // ax
  UFG::qVRAMemoryPool *v6; // rcx

  v2 = frames_to_delay;
  v3 = handle;
  v4 = 0;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMPoolsLock);
  if ( v3->mData )
  {
    v5 = v3->mReadOnlyAndPoolID & 0x7FFF;
    if ( v5 < 0x10u )
    {
      v6 = UFG::qVRAMemoryPools::sVRAMemoryPools[v5];
      if ( v6 )
        v4 = UFG::qVRAMemoryPool::Free(v6, v3, v2);
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
  char *v3; // rdi
  unsigned __int8 v4; // bl
  signed int v5; // er8
  UFG::qVRAMemoryPool **v6; // r9
  UFG::qVRAMemoryPool *v7; // rax
  char *v8; // r10

  v2 = data_size;
  v3 = data;
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
      v8 = v7->mVRAMemoryStart;
      if ( &v8[v7->mVRAMemorySize] > v3 && &v3[v2] > v8 )
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
  unsigned __int16 v1; // di
  UFG::BlockInfo *v2; // rbx

  v1 = block_id;
  v2 = 0i64;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMBlocksLock);
  if ( UFG::qVRAMemoryPools::sNumBlocksTotal && v1 < UFG::qVRAMemoryPools::sNumBlocksTotal )
    v2 = &UFG::qVRAMemoryPools::sBlocks[(unsigned __int64)v1];
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMBlocksLock);
  return v2;
}

// File Line: 3461
// RVA: 0x172E90
UFG::qNode<UFG::BlockInfo,UFG::Primary> *__fastcall UFG::qVRAMemoryPools::GetUnusedBlock()
{
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v0; // rbx
  unsigned __int16 v1; // ax
  unsigned __int16 v2; // cx
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v3; // rax
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v4; // r8
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v5; // rdx

  v0 = 0i64;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMBlocksLock);
  if ( UFG::qVRAMemoryPools::sNumBlocksTotal > 0u )
  {
    v1 = UFG::qVRAMemoryPools::sUsedBlocksMax;
    v2 = UFG::qVRAMemoryPools::sUsedBlocksCount++ + 1;
    if ( UFG::qVRAMemoryPools::sUsedBlocksCount > UFG::qVRAMemoryPools::sUsedBlocksMax )
      v1 = v2;
    UFG::qVRAMemoryPools::sUsedBlocksMax = v1;
    v3 = UFG::qVRAMemoryPools::sUnusedBlocks.mNode.mNext;
    if ( (UFG::qList<UFG::BlockInfo,UFG::Primary,1,0> *)UFG::qVRAMemoryPools::sUnusedBlocks.mNode.mNext != &UFG::qVRAMemoryPools::sUnusedBlocks )
    {
      v4 = UFG::qVRAMemoryPools::sUnusedBlocks.mNode.mNext->mPrev;
      v5 = UFG::qVRAMemoryPools::sUnusedBlocks.mNode.mNext->mNext;
      v0 = UFG::qVRAMemoryPools::sUnusedBlocks.mNode.mNext;
      v4->mNext = v5;
      v5->mPrev = v4;
      v3->mPrev = v3;
      v3->mNext = v3;
    }
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMBlocksLock);
  return v0;
}

// File Line: 3485
// RVA: 0x17BC60
void __fastcall UFG::qVRAMemoryPools::ReturnUsedBlock(UFG::BlockInfo *block)
{
  UFG::BlockInfo *v1; // rbx
  UFG::qNode<UFG::BlockInfo,UFG::Primary> *v2; // rax

  v1 = block;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMBlocksLock);
  if ( UFG::qVRAMemoryPools::sNumBlocksTotal )
  {
    --UFG::qVRAMemoryPools::sUsedBlocksCount;
    v2 = UFG::qVRAMemoryPools::sUnusedBlocks.mNode.mNext;
    UFG::qVRAMemoryPools::sUnusedBlocks.mNode.mNext = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&v1->mPrev;
    v1->mNext = v2;
    v1->mPrev = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&UFG::qVRAMemoryPools::sUnusedBlocks;
    v2->mPrev = (UFG::qNode<UFG::BlockInfo,UFG::Primary> *)&v1->mPrev;
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::qVRAMemoryPools::sVRAMBlocksLock);
}

