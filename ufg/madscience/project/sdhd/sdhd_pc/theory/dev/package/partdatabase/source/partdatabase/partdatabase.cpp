// File Line: 29
// RVA: 0x154540
void __fastcall UFG::PartRequest::PartRequest(UFG::PartRequest *this)
{
  UFG::qReflectHandle<UFG::PartDefinition> *p_mPartDefHandle; // rbx

  this->mPrev = this;
  this->mNext = this;
  this->mModelDataStreamerHandle = 0i64;
  this->mTextureDataStreamerHandle = 0i64;
  this->mLoadCount = 0;
  p_mPartDefHandle = &this->mPartDefHandle;
  UFG::qReflectHandleBase::qReflectHandleBase(&this->mPartDefHandle);
  p_mPartDefHandle->mTypeUID = UFG::qStringHash64("UFG::PartDefinition", 0xFFFFFFFFFFFFFFFFui64);
  this->mLoadStatus = Undefined;
  this->mLastReferencedFrame = 0;
  this->mInstances.p = 0i64;
  *(_QWORD *)&this->mInstances.size = 0i64;
  UFG::qMemSet(this->mPriorityRefCounts, 0, 0x14u);
}

// File Line: 65
// RVA: 0x158BA0
__int64 __fastcall UFG::PartRequest::GetHighestBucket(UFG::PartRequest *this)
{
  __int64 result; // rax
  unsigned int *i; // rcx

  result = 0i64;
  for ( i = this->mPriorityRefCounts; !*i; ++i )
  {
    result = (unsigned int)(result + 1);
    if ( (unsigned int)result >= 5 )
      return 0i64;
  }
  return result;
}

// File Line: 77
// RVA: 0x1599D0
void __fastcall UFG::PartRequest::OnLoaded(UFG::PartRequest *this)
{
  __int64 i; // r10
  UFG::PartLoader *v3; // r8
  __int64 v4; // rax
  __int64 mPartRequestCount; // rdx
  __int64 v6; // rdx
  __int64 v7; // rcx

  for ( i = 0i64; (unsigned int)i < this->mInstances.size; v3->mPartsDirty = 1 )
  {
    v3 = this->mInstances.p[i];
    v4 = 0i64;
    mPartRequestCount = v3->mPartRequestCount;
    if ( (_DWORD)mPartRequestCount )
    {
      while ( v3->mPartRequests[v4] != this )
      {
        v4 = (unsigned int)(v4 + 1);
        if ( (unsigned int)v4 >= (unsigned int)mPartRequestCount )
          goto LABEL_5;
      }
      v6 = 1i64 << (v4 & 0x3F);
      v7 = (__int64)(int)v4 >> 6;
      v3->mRequestsLoadedFlags.mBits[v7] |= v6;
      v3->mRequestsDispatchEventFlags.mBits[v7] |= v6;
    }
    else
    {
LABEL_5:
      v3->mPartRequests[mPartRequestCount] = this;
      v3->mRequestsLoadedFlags.mBits[(__int64)(int)v3->mPartRequestCount >> 6] |= 1i64 << (v3->mPartRequestCount & 0x3F);
      v3->mRequestsDispatchEventFlags.mBits[(__int64)(int)v3->mPartRequestCount >> 6] |= 1i64 << (v3->mPartRequestCount & 0x3F);
      ++v3->mPartRequestCount;
    }
    i = (unsigned int)(i + 1);
  }
}

// File Line: 87
// RVA: 0x1561F0
void __fastcall UFG::PartRequest::AddDependency(UFG::PartRequest *this, UFG::PartLoader *dependency)
{
  __int64 size; // rbp
  unsigned int capacity; // edx
  unsigned int v5; // ebx
  unsigned int v7; // edx
  UFG::PartLoader **p; // rax

  size = this->mInstances.size;
  capacity = this->mInstances.capacity;
  v5 = size + 1;
  if ( (int)size + 1 > capacity )
  {
    if ( capacity )
      v7 = 2 * capacity;
    else
      v7 = 1;
    for ( ; v7 < v5; v7 *= 2 )
      ;
    if ( v7 <= 2 )
      v7 = 2;
    if ( v7 - v5 > 0x10000 )
      v7 = size + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
      (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mInstances,
      v7,
      "PartRequest::AddDependency");
  }
  p = this->mInstances.p;
  this->mInstances.size = v5;
  p[size] = dependency;
  ++this->mPriorityRefCounts[dependency->mPriority];
  this->mLastReferencedFrame = Illusion::gEngine.mFrameCount;
}

// File Line: 132
// RVA: 0x152FD0
void __fastcall UFG::PartPool::Bucket::Bucket(UFG::PartPool::Bucket *this)
{
  unsigned __int64 v2; // rax
  char *v3; // rax
  UFG::PartRequest **v4; // rdi
  unsigned int i; // r9d

  this->mPriority = 0;
  this->mRequests.p = 0i64;
  *(_QWORD *)&this->mRequests.size = 0i64;
  this->mParent = 0i64;
  this->mChildren.p = 0i64;
  *(_QWORD *)&this->mChildren.size = 0i64;
  if ( this->mRequests.capacity < 0x10 && this->mRequests.size != 16 )
  {
    v2 = 128i64;
    if ( !is_mul_ok(0x10ui64, 8ui64) )
      v2 = -1i64;
    v3 = UFG::qMalloc(v2, "Bucket", 0i64);
    v4 = (UFG::PartRequest **)v3;
    if ( this->mRequests.p )
    {
      for ( i = 0; i < this->mRequests.size; ++i )
        *(_QWORD *)&v3[8 * i] = this->mRequests.p[i];
      operator delete[](this->mRequests.p);
    }
    this->mRequests.p = v4;
    this->mRequests.capacity = 16;
  }
  *(_QWORD *)&this->mMemoryUsageModel = 0i64;
}

// File Line: 138
// RVA: 0x15B530
void __fastcall UFG::PartPool::Bucket::UpdateSize(UFG::PartPool::Bucket *this)
{
  __int64 i; // rdi
  __int64 j; // rsi
  UFG::PartRequest *v4; // rbp
  UFG::PartDefinition *mData; // rdi
  unsigned int mModelSize; // eax
  UFG::qReflectObject *v7; // rdi
  int mTypeUID_high; // eax
  unsigned int size; // eax
  unsigned int mMemoryUsageModel; // edx
  unsigned int mMemoryUsageTexture; // r8d
  UFG::PartPool::Bucket **p; // rcx
  __int64 v13; // r9
  UFG::qString v14; // [rsp+28h] [rbp-80h] BYREF
  UFG::qString v15; // [rsp+50h] [rbp-58h] BYREF
  UFG::qString result; // [rsp+78h] [rbp-30h] BYREF

  *(_QWORD *)&this->mMemoryUsageModel = 0i64;
  for ( i = 0i64; (unsigned int)i < this->mChildren.size; i = (unsigned int)(i + 1) )
    UFG::PartPool::Bucket::UpdateSize(this->mChildren.p[i]);
  for ( j = 0i64; (unsigned int)j < this->mRequests.size; j = (unsigned int)(j + 1) )
  {
    v4 = this->mRequests.p[j];
    mData = (UFG::PartDefinition *)v4->mPartDefHandle.mData;
    if ( mData )
    {
      if ( !mData->mModelSize )
      {
        UFG::PartDefinition::GetModelFileName((UFG::PartDefinition *)v4->mPartDefHandle.mData, &result);
        mData->mModelSize = PartDatabase_QueryFileSize(result.mData);
        UFG::PartDefinition::GetTextureFileName(mData, &v15);
        mData->mModelSize += PartDatabase_QueryFileSize(v15.mData);
        UFG::qString::~qString(&v15);
        UFG::qString::~qString(&result);
      }
      mModelSize = mData->mModelSize;
    }
    else
    {
      mModelSize = 0;
    }
    this->mMemoryUsageModel += mModelSize;
    v7 = v4->mPartDefHandle.mData;
    if ( v7 )
    {
      if ( !HIDWORD(v7[2].mTypeUID) )
      {
        UFG::PartDefinition::GetTextureFileName((UFG::PartDefinition *)v4->mPartDefHandle.mData, &v14);
        UFG::qString::ReplaceString(&v14, ".perm.bin", ".temp.bin", 0);
        HIDWORD(v7[2].mTypeUID) = PartDatabase_QueryFileSize(v14.mData);
        UFG::qString::~qString(&v14);
      }
      mTypeUID_high = HIDWORD(v7[2].mTypeUID);
    }
    else
    {
      mTypeUID_high = 0;
    }
    this->mMemoryUsageTexture += mTypeUID_high;
  }
  size = this->mChildren.size;
  if ( size )
  {
    mMemoryUsageModel = this->mMemoryUsageModel;
    mMemoryUsageTexture = this->mMemoryUsageTexture;
    p = this->mChildren.p;
    v13 = size;
    do
    {
      mMemoryUsageModel += (*p)->mMemoryUsageModel;
      this->mMemoryUsageModel = mMemoryUsageModel;
      mMemoryUsageTexture += (*p)->mMemoryUsageTexture;
      this->mMemoryUsageTexture = mMemoryUsageTexture;
      ++p;
      --v13;
    }
    while ( v13 );
  }
}

// File Line: 158
// RVA: 0x15B410
void __fastcall UFG::PartPool::Bucket::UpdatePriority(UFG::PartPool::Bucket *this, unsigned int priority)
{
  __int64 v2; // rbx
  unsigned int v3; // edi

  v2 = 0i64;
  v3 = priority;
  for ( this->mPriority = priority; (unsigned int)v2 < this->mChildren.size; v2 = (unsigned int)(v2 + 1) )
  {
    v3 += v2 + 1;
    UFG::PartPool::Bucket::UpdatePriority(this->mChildren.p[v2], v3);
  }
}

// File Line: 169
// RVA: 0x15AE80
bool __fastcall UFG::SortByReferenceFramePredicate(UFG::PartRequest *a, UFG::PartRequest *b)
{
  return a->mLastReferencedFrame < b->mLastReferencedFrame;
}

// File Line: 196
// RVA: 0x154380
void __fastcall UFG::PartPool::PartPool(UFG::PartPool *this)
{
  unsigned int v2; // edi
  unsigned __int64 v3; // rax
  char *v4; // rsi
  unsigned int i; // r8d
  unsigned __int64 v6; // rax
  char *v7; // rsi
  unsigned int j; // r8d
  unsigned __int64 v9; // rax
  char *v10; // rax
  UFG::PartRequest **v11; // rsi

  v2 = 0;
  this->mQueued.p = 0i64;
  *(_QWORD *)&this->mQueued.size = 0i64;
  this->mLoading.p = 0i64;
  *(_QWORD *)&this->mLoading.size = 0i64;
  this->mLoaded.p = 0i64;
  *(_QWORD *)&this->mLoaded.size = 0i64;
  this->mRequestList.mNode.mPrev = &this->mRequestList.mNode;
  this->mRequestList.mNode.mNext = &this->mRequestList.mNode;
  *(_QWORD *)&this->mMaxModelMemory = 0i64;
  *(_QWORD *)&this->mExternalUsedModelMemory = 0i64;
  this->mFragmentationReservePercentage = 0.050000001;
  *(_WORD *)&this->mStreamerStalled = 256;
  if ( this->mQueued.capacity < 0x20 && this->mQueued.size != 32 )
  {
    v3 = 256i64;
    if ( !is_mul_ok(0x20ui64, 8ui64) )
      v3 = -1i64;
    v4 = UFG::qMalloc(v3, "PartPool", 0i64);
    if ( this->mQueued.p )
    {
      for ( i = 0; i < this->mQueued.size; ++i )
        *(_QWORD *)&v4[8 * i] = this->mQueued.p[i];
      operator delete[](this->mQueued.p);
    }
    this->mQueued.p = (UFG::PartRequest **)v4;
    this->mQueued.capacity = 32;
  }
  if ( this->mLoading.capacity < 0x20 && this->mLoading.size != 32 )
  {
    v6 = 256i64;
    if ( !is_mul_ok(0x20ui64, 8ui64) )
      v6 = -1i64;
    v7 = UFG::qMalloc(v6, "PartPool", 0i64);
    if ( this->mLoading.p )
    {
      for ( j = 0; j < this->mLoading.size; ++j )
        *(_QWORD *)&v7[8 * j] = this->mLoading.p[j];
      operator delete[](this->mLoading.p);
    }
    this->mLoading.p = (UFG::PartRequest **)v7;
    this->mLoading.capacity = 32;
  }
  if ( this->mLoaded.capacity < 0x20 && this->mLoaded.size != 32 )
  {
    v9 = 256i64;
    if ( !is_mul_ok(0x20ui64, 8ui64) )
      v9 = -1i64;
    v10 = UFG::qMalloc(v9, "PartPool", 0i64);
    v11 = (UFG::PartRequest **)v10;
    if ( this->mLoaded.p )
    {
      if ( this->mLoaded.size )
      {
        do
        {
          *(_QWORD *)&v10[8 * v2] = this->mLoaded.p[v2];
          ++v2;
        }
        while ( v2 < this->mLoaded.size );
      }
      operator delete[](this->mLoaded.p);
    }
    this->mLoaded.p = v11;
    this->mLoaded.capacity = 32;
  }
  UFG::PartPool::InitBuckets(this);
}

// File Line: 204
// RVA: 0x155370
void __fastcall UFG::PartPool::~PartPool(UFG::PartPool *this)
{
  UFG::PartPool::Bucket *mMasterBucket; // rbx
  UFG::PartPool::Bucket **p; // rcx
  UFG::PartRequest **v4; // rcx
  UFG::PartPool::Bucket *mReservedBucket; // rbx
  UFG::PartPool::Bucket **v6; // rcx
  UFG::PartRequest **v7; // rcx
  UFG::PartPool::Bucket *mCriticalBucket; // rbx
  UFG::PartPool::Bucket **v9; // rcx
  UFG::PartRequest **v10; // rcx
  UFG::PartPool::Bucket *mHighBucket; // rbx
  UFG::PartPool::Bucket **v12; // rcx
  UFG::PartRequest **v13; // rcx
  UFG::PartPool::Bucket *mLowBucket; // rbx
  UFG::PartPool::Bucket **v15; // rcx
  UFG::PartRequest **v16; // rcx
  UFG::qNode<UFG::PartRequest,UFG::PartRequest> *mPrev; // rcx
  UFG::qNode<UFG::PartRequest,UFG::PartRequest> *mNext; // rax
  UFG::PartRequest **v19; // rcx
  UFG::PartRequest **v20; // rcx
  UFG::PartRequest **v21; // rcx

  mMasterBucket = this->mMasterBucket;
  if ( mMasterBucket )
  {
    p = mMasterBucket->mChildren.p;
    if ( p )
      operator delete[](p);
    mMasterBucket->mChildren.p = 0i64;
    *(_QWORD *)&mMasterBucket->mChildren.size = 0i64;
    v4 = mMasterBucket->mRequests.p;
    if ( v4 )
      operator delete[](v4);
    mMasterBucket->mRequests.p = 0i64;
    *(_QWORD *)&mMasterBucket->mRequests.size = 0i64;
    operator delete[](mMasterBucket);
  }
  mReservedBucket = this->mReservedBucket;
  if ( mReservedBucket )
  {
    v6 = mReservedBucket->mChildren.p;
    if ( v6 )
      operator delete[](v6);
    mReservedBucket->mChildren.p = 0i64;
    *(_QWORD *)&mReservedBucket->mChildren.size = 0i64;
    v7 = mReservedBucket->mRequests.p;
    if ( v7 )
      operator delete[](v7);
    mReservedBucket->mRequests.p = 0i64;
    *(_QWORD *)&mReservedBucket->mRequests.size = 0i64;
    operator delete[](mReservedBucket);
  }
  mCriticalBucket = this->mCriticalBucket;
  if ( mCriticalBucket )
  {
    v9 = mCriticalBucket->mChildren.p;
    if ( v9 )
      operator delete[](v9);
    mCriticalBucket->mChildren.p = 0i64;
    *(_QWORD *)&mCriticalBucket->mChildren.size = 0i64;
    v10 = mCriticalBucket->mRequests.p;
    if ( v10 )
      operator delete[](v10);
    mCriticalBucket->mRequests.p = 0i64;
    *(_QWORD *)&mCriticalBucket->mRequests.size = 0i64;
    operator delete[](mCriticalBucket);
  }
  mHighBucket = this->mHighBucket;
  if ( mHighBucket )
  {
    v12 = mHighBucket->mChildren.p;
    if ( v12 )
      operator delete[](v12);
    mHighBucket->mChildren.p = 0i64;
    *(_QWORD *)&mHighBucket->mChildren.size = 0i64;
    v13 = mHighBucket->mRequests.p;
    if ( v13 )
      operator delete[](v13);
    mHighBucket->mRequests.p = 0i64;
    *(_QWORD *)&mHighBucket->mRequests.size = 0i64;
    operator delete[](mHighBucket);
  }
  mLowBucket = this->mLowBucket;
  if ( mLowBucket )
  {
    v15 = mLowBucket->mChildren.p;
    if ( v15 )
      operator delete[](v15);
    mLowBucket->mChildren.p = 0i64;
    *(_QWORD *)&mLowBucket->mChildren.size = 0i64;
    v16 = mLowBucket->mRequests.p;
    if ( v16 )
      operator delete[](v16);
    mLowBucket->mRequests.p = 0i64;
    *(_QWORD *)&mLowBucket->mRequests.size = 0i64;
    operator delete[](mLowBucket);
  }
  UFG::qList<UFG::PartRequest,UFG::PartRequest,1,0>::DeleteNodes(&this->mRequestList);
  mPrev = this->mRequestList.mNode.mPrev;
  mNext = this->mRequestList.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mRequestList.mNode.mPrev = &this->mRequestList.mNode;
  this->mRequestList.mNode.mNext = &this->mRequestList.mNode;
  v19 = this->mLoaded.p;
  if ( v19 )
    operator delete[](v19);
  this->mLoaded.p = 0i64;
  *(_QWORD *)&this->mLoaded.size = 0i64;
  v20 = this->mLoading.p;
  if ( v20 )
    operator delete[](v20);
  this->mLoading.p = 0i64;
  *(_QWORD *)&this->mLoading.size = 0i64;
  v21 = this->mQueued.p;
  if ( v21 )
    operator delete[](v21);
  this->mQueued.p = 0i64;
  *(_QWORD *)&this->mQueued.size = 0i64;
}

// File Line: 223
// RVA: 0x158DB0
__int64 __fastcall UFG::PartPool::GetQueuedBytes(UFG::PartPool *this)
{
  unsigned int v2; // ebx
  __int64 i; // rbp
  UFG::PartDefinition *mData; // rcx
  int ModelSize; // eax
  int v6; // ebx
  UFG::PartRequest *v7; // rcx
  UFG::qReflectObject *v8; // rsi
  int mTypeUID_high; // eax
  __int64 j; // rbp
  UFG::PartRequest *v11; // rcx
  UFG::PartDefinition *v12; // rsi
  unsigned int mModelSize; // eax
  unsigned int v14; // ebx
  UFG::PartRequest *v15; // rcx
  UFG::qReflectObject *v16; // rsi
  int v17; // eax
  UFG::qString result; // [rsp+20h] [rbp-88h] BYREF
  __int64 v20; // [rsp+48h] [rbp-60h]
  UFG::qString v21; // [rsp+50h] [rbp-58h] BYREF
  UFG::qString v22; // [rsp+78h] [rbp-30h] BYREF

  v20 = -2i64;
  v2 = 0;
  for ( i = 0i64; (unsigned int)i < this->mQueued.size; i = (unsigned int)(i + 1) )
  {
    mData = (UFG::PartDefinition *)this->mQueued.p[i]->mPartDefHandle.mData;
    if ( mData )
      ModelSize = UFG::PartDefinition::GetModelSize(mData);
    else
      ModelSize = 0;
    v6 = ModelSize + v2;
    v7 = this->mQueued.p[i];
    v8 = v7->mPartDefHandle.mData;
    if ( v8 )
    {
      if ( !HIDWORD(v8[2].mTypeUID) )
      {
        UFG::PartDefinition::GetTextureFileName((UFG::PartDefinition *)v7->mPartDefHandle.mData, &result);
        UFG::qString::ReplaceString(&result, ".perm.bin", ".temp.bin", 0);
        HIDWORD(v8[2].mTypeUID) = PartDatabase_QueryFileSize(result.mData);
        UFG::qString::~qString(&result);
      }
      mTypeUID_high = HIDWORD(v8[2].mTypeUID);
    }
    else
    {
      mTypeUID_high = 0;
    }
    v2 = mTypeUID_high + v6;
  }
  for ( j = 0i64; (unsigned int)j < this->mLoading.size; j = (unsigned int)(j + 1) )
  {
    v11 = this->mLoading.p[j];
    v12 = (UFG::PartDefinition *)v11->mPartDefHandle.mData;
    if ( v12 )
    {
      if ( !v12->mModelSize )
      {
        UFG::PartDefinition::GetModelFileName((UFG::PartDefinition *)v11->mPartDefHandle.mData, &v22);
        v12->mModelSize = PartDatabase_QueryFileSize(v22.mData);
        UFG::PartDefinition::GetTextureFileName(v12, &v21);
        v12->mModelSize += PartDatabase_QueryFileSize(v21.mData);
        UFG::qString::~qString(&v21);
        UFG::qString::~qString(&v22);
      }
      mModelSize = v12->mModelSize;
    }
    else
    {
      mModelSize = 0;
    }
    v14 = mModelSize + v2;
    v15 = this->mLoading.p[j];
    v16 = v15->mPartDefHandle.mData;
    if ( v16 )
    {
      if ( !HIDWORD(v16[2].mTypeUID) )
      {
        UFG::PartDefinition::GetTextureFileName((UFG::PartDefinition *)v15->mPartDefHandle.mData, &result);
        UFG::qString::ReplaceString(&result, ".perm.bin", ".temp.bin", 0);
        HIDWORD(v16[2].mTypeUID) = PartDatabase_QueryFileSize(result.mData);
        UFG::qString::~qString(&result);
      }
      v17 = HIDWORD(v16[2].mTypeUID);
    }
    else
    {
      v17 = 0;
    }
    v2 = v17 + v14;
  }
  return v2;
}

// File Line: 240
// RVA: 0x15A6B0
UFG::PartRequest *__fastcall UFG::PartPool::RequestLoadPart(
        UFG::PartPool *this,
        UFG::PartDefinition *part,
        UFG::PartLoader *user)
{
  UFG::qNode<UFG::PartRequest,UFG::PartRequest> *mNext; // rbx
  UFG::qList<UFG::PartRequest,UFG::PartRequest,1,0> *p_mRequestList; // rdi
  char *v8; // rax
  UFG::qNode<UFG::PartRequest,UFG::PartRequest> *v9; // rax
  UFG::qNode<UFG::PartRequest,UFG::PartRequest> *mPrev; // rax
  UFG::qPropertySet *item; // [rsp+50h] [rbp+8h] BYREF

  mNext = this->mRequestList.mNode.mNext;
  p_mRequestList = &this->mRequestList;
  if ( mNext != (UFG::qNode<UFG::PartRequest,UFG::PartRequest> *)&this->mRequestList )
  {
    while ( mNext[4].mPrev != (UFG::qNode<UFG::PartRequest,UFG::PartRequest> *)part->mBaseNode.mUID )
    {
      mNext = mNext->mNext;
      if ( mNext == (UFG::qNode<UFG::PartRequest,UFG::PartRequest> *)p_mRequestList )
        goto LABEL_6;
    }
    UFG::PartRequest::AddDependency((UFG::PartRequest *)mNext, user);
    goto LABEL_11;
  }
LABEL_6:
  v8 = UFG::qMalloc(0x80ui64, "PartRequest", 0i64);
  item = (UFG::qPropertySet *)v8;
  if ( v8 )
  {
    UFG::PartRequest::PartRequest((UFG::PartRequest *)v8);
    mNext = v9;
  }
  else
  {
    mNext = 0i64;
  }
  UFG::qReflectHandleBase::Init(
    (UFG::qReflectHandleBase *)&mNext[2].mNext,
    (unsigned __int64)mNext[3].mNext,
    part->mBaseNode.mUID);
  UFG::PartRequest::AddDependency((UFG::PartRequest *)mNext, user);
  mPrev = p_mRequestList->mNode.mPrev;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  mNext->mNext = &p_mRequestList->mNode;
  p_mRequestList->mNode.mPrev = mNext;
  item = (UFG::qPropertySet *)mNext;
  if ( LODWORD(mNext[5].mPrev) != 1 )
  {
    UFG::qArray<UFG::PedSpawningInfo *,0>::Add((UFG::qArray<UFG::qPropertySet *,0> *)this, &item, "qArray.Add");
    LODWORD(mNext[5].mPrev) = 1;
LABEL_11:
    this->mDirty = 1;
  }
  return (UFG::PartRequest *)mNext;
}

// File Line: 262
// RVA: 0x15A7B0
void __fastcall UFG::PartPool::RequestUnLoadPart(UFG::PartPool *this, UFG::PartDefinition *part, UFG::PartLoader *user)
{
  UFG::PartPool *mNext; // rax
  UFG::PartPool *v4; // r9
  unsigned __int64 mUID; // rdx
  unsigned int mMaxModelMemory; // edx
  __int64 v9; // rcx
  __int64 v10; // r8
  unsigned int v11; // eax

  mNext = (UFG::PartPool *)this->mRequestList.mNode.mNext;
  v4 = 0i64;
  if ( mNext != (UFG::PartPool *)&this->mRequestList )
  {
    mUID = part->mBaseNode.mUID;
    while ( mNext->mReservedBucket != (UFG::PartPool::Bucket *)mUID )
    {
      mNext = (UFG::PartPool *)mNext->mQueued.p;
      if ( mNext == (UFG::PartPool *)&this->mRequestList )
        goto LABEL_7;
    }
    v4 = mNext;
  }
LABEL_7:
  mMaxModelMemory = v4->mMaxModelMemory;
  v9 = 0i64;
  if ( mMaxModelMemory )
  {
    v10 = *(_QWORD *)&v4->mExternalUsedModelMemory;
    while ( user != *(UFG::PartLoader **)(v10 + 8 * v9) )
    {
      v9 = (unsigned int)(v9 + 1);
      if ( (unsigned int)v9 >= mMaxModelMemory )
        goto LABEL_16;
    }
    if ( (int)v9 >= 0 )
    {
      *(_QWORD *)(v10 + 8 * v9) = *(_QWORD *)(v10 + 8i64 * (mMaxModelMemory - 1));
      v11 = v4->mMaxModelMemory;
      if ( v11 > 1 )
        v4->mMaxModelMemory = v11 - 1;
      else
        v4->mMaxModelMemory = 0;
    }
  }
LABEL_16:
  --*((_DWORD *)&v4->mHighBucket + user->mPriority + 1);
  LODWORD(v4->mRequestList.mNode.mNext) = Illusion::gEngine.mFrameCount;
  this->mDirty = 1;
}

// File Line: 271
// RVA: 0x1592C0
void __fastcall UFG::PartPool::Init(UFG::PartPool *this, unsigned int maxModelMemory, unsigned int maxTextureMemory)
{
  this->mMaxModelMemory = maxModelMemory;
  this->mMaxTextureMemory = maxTextureMemory;
}

// File Line: 277
// RVA: 0x15AE90
bool __fastcall UFG::SortQueuedRequests(UFG::PartRequest *reqA, UFG::PartRequest *reqB)
{
  unsigned int v4; // r8d
  unsigned int *mPriorityRefCounts; // rax
  unsigned int v6; // r9d
  UFG::PartDefinition *mData; // rcx
  int ModelSize; // r15d
  UFG::PartDefinition *v9; // rdi
  unsigned int mTextureSize; // r14d
  UFG::PartDefinition *v11; // rcx
  int v12; // ebp
  UFG::qReflectObject *v13; // rdi
  int mTypeUID_high; // eax
  UFG::qString result; // [rsp+28h] [rbp-70h] BYREF
  UFG::qString v17; // [rsp+50h] [rbp-48h] BYREF

  v4 = 0;
  mPriorityRefCounts = reqB->mPriorityRefCounts;
  do
  {
    v6 = *(unsigned int *)((char *)mPriorityRefCounts + (char *)reqA - (char *)reqB);
    if ( v6 != *mPriorityRefCounts )
      return v6 > *mPriorityRefCounts;
    ++v4;
    ++mPriorityRefCounts;
  }
  while ( v4 < 5 );
  mData = (UFG::PartDefinition *)reqA->mPartDefHandle.mData;
  if ( mData )
    ModelSize = UFG::PartDefinition::GetModelSize(mData);
  else
    ModelSize = 0;
  v9 = (UFG::PartDefinition *)reqA->mPartDefHandle.mData;
  if ( v9 )
  {
    if ( !v9->mTextureSize )
    {
      UFG::PartDefinition::GetTextureFileName(v9, &result);
      UFG::qString::ReplaceString(&result, ".perm.bin", ".temp.bin", 0);
      v9->mTextureSize = PartDatabase_QueryFileSize(result.mData);
      UFG::qString::~qString(&result);
    }
    mTextureSize = v9->mTextureSize;
  }
  else
  {
    mTextureSize = 0;
  }
  v11 = (UFG::PartDefinition *)reqB->mPartDefHandle.mData;
  if ( v11 )
    v12 = UFG::PartDefinition::GetModelSize(v11);
  else
    v12 = 0;
  v13 = reqB->mPartDefHandle.mData;
  if ( v13 )
  {
    if ( !HIDWORD(v13[2].mTypeUID) )
    {
      UFG::PartDefinition::GetTextureFileName((UFG::PartDefinition *)reqB->mPartDefHandle.mData, &v17);
      UFG::qString::ReplaceString(&v17, ".perm.bin", ".temp.bin", 0);
      HIDWORD(v13[2].mTypeUID) = PartDatabase_QueryFileSize(v17.mData);
      UFG::qString::~qString(&v17);
    }
    mTypeUID_high = HIDWORD(v13[2].mTypeUID);
  }
  else
  {
    mTypeUID_high = 0;
  }
  return mTextureSize + ModelSize < mTypeUID_high + v12;
}

// File Line: 289
// RVA: 0x15B460
void __fastcall UFG::PartPool::UpdateRequests(UFG::PartPool *this)
{
  unsigned int size; // eax
  bool IsStreamingStalled; // al
  __int64 v4; // rsi
  UFG::qPropertySet **v5; // rdi
  Render::IrradianceVolume *dest[513]; // [rsp+20h] [rbp-1008h] BYREF

  if ( this->mDirty )
    UFG::PartPool::UpdateBuckets(this);
  size = this->mLoading.size;
  this->mStreamerStalled = 0;
  if ( this->mQueued.size + size )
  {
    IsStreamingStalled = PartDatabase_IsStreamingStalled();
    this->mStreamerStalled = IsStreamingStalled;
    if ( !IsStreamingStalled )
    {
      v4 = this->mQueued.size;
      if ( (_DWORD)v4 )
      {
        UFG::qMemCopy(dest, this->mQueued.p, 8 * v4);
        UFG::qQuickSortImpl<Render::Light *,bool (*)(Render::Light const *,Render::Light const *)>(
          dest,
          &dest[(int)v4 - 1],
          (bool (__fastcall *)(Render::IrradianceVolume *, Render::IrradianceVolume *))UFG::SortQueuedRequests);
        v5 = (UFG::qPropertySet **)dest;
        do
        {
          UFG::PartPool::QueueRequest(this, *v5++);
          --v4;
        }
        while ( v4 );
        UFG::PartPool::Bucket::UpdateSize(this->mMasterBucket);
      }
    }
  }
}

// File Line: 328
// RVA: 0x15A260
void __fastcall UFG::PartPool::ReloadRequests(UFG::PartPool *this)
{
  UFG::PartRequest *mNext; // rbx
  UFG::qList<UFG::PartRequest,UFG::PartRequest,1,0> *i; // rdi
  UFG::PartRequest *j; // rbx

  mNext = (UFG::PartRequest *)this->mRequestList.mNode.mNext;
  for ( i = &this->mRequestList; mNext != (UFG::PartRequest *)i; mNext = (UFG::PartRequest *)mNext->mNext )
    PartDatabase_ReleaseStream(mNext);
  for ( j = (UFG::PartRequest *)this->mRequestList.mNode.mNext; j != (UFG::PartRequest *)i; j = (UFG::PartRequest *)j->mNext )
    PartDatabase_QueueStream(j);
}

// File Line: 341
// RVA: 0x158800
void __fastcall UFG::PartPool::FlushParts(UFG::PartPool *this, bool forceFlush)
{
  float mFragmentationReservePercentage; // xmm1_4
  unsigned int v4; // ebx
  unsigned int v5; // esi
  UFG::PartPool::Bucket *mMasterBucket; // rax
  unsigned int v7; // r14d
  unsigned int v8; // r15d
  UFG::PartPool::Bucket *mUnReferencedBucket; // rcx
  __int64 size; // rax
  unsigned int v11; // r13d
  unsigned int v12; // ebp
  __int64 v13; // r12
  UFG::PartRequest *v14; // rbx
  UFG::PartDefinition *mData; // rcx
  int ModelSize; // eax
  UFG::qReflectObject *v17; // rsi
  int mTypeUID_high; // eax
  __int64 v19; // rcx
  unsigned int v20; // edx
  UFG::PartRequest **p; // r8
  __int64 v22; // rcx
  unsigned int v23; // edx
  UFG::PartRequest **v24; // r8
  unsigned int v25; // eax
  __int64 v26; // rcx
  unsigned int v27; // edx
  UFG::PartRequest **v28; // r8
  unsigned int v29; // eax
  UFG::qNode<UFG::PartRequest,UFG::PartRequest> *mPrev; // rcx
  UFG::qNode<UFG::PartRequest,UFG::PartRequest> *mNext; // rax
  UFG::PartLoader **v32; // rcx
  UFG::qNode<UFG::PartRequest,UFG::PartRequest> *v33; // rdx
  UFG::qNode<UFG::PartRequest,UFG::PartRequest> *v34; // rax
  UFG::qString result; // [rsp+30h] [rbp-78h] BYREF
  unsigned int v36; // [rsp+B0h] [rbp+8h]
  unsigned int v38; // [rsp+C0h] [rbp+18h]

  mFragmentationReservePercentage = this->mFragmentationReservePercentage;
  v4 = this->mMaxModelMemory - (int)(float)((float)(int)this->mMaxModelMemory * mFragmentationReservePercentage);
  v36 = v4;
  v5 = this->mMaxTextureMemory - (int)(float)((float)(int)this->mMaxTextureMemory * mFragmentationReservePercentage);
  v38 = v5;
  mMasterBucket = this->mMasterBucket;
  v7 = this->mExternalUsedModelMemory + mMasterBucket->mMemoryUsageModel;
  v8 = this->mExternalUsedTextureMemory + mMasterBucket->mMemoryUsageTexture;
  if ( forceFlush || this->mStreamerStalled || v7 > v4 || v8 > v5 )
  {
    if ( this->mDirty )
      UFG::PartPool::UpdateBuckets(this);
    mUnReferencedBucket = this->mUnReferencedBucket;
    size = (int)mUnReferencedBucket->mRequests.size;
    if ( (_DWORD)size )
      UFG::qQuickSortImpl<Render::Light *,bool (*)(Render::Light const *,Render::Light const *)>(
        (Render::IrradianceVolume **)mUnReferencedBucket->mRequests.p,
        (Render::IrradianceVolume **)&mUnReferencedBucket->mRequests.p[size - 1],
        (bool (__fastcall *)(Render::IrradianceVolume *, Render::IrradianceVolume *))UFG::SortByReferenceFramePredicate);
    v11 = this->mUnReferencedBucket->mRequests.size;
    v12 = 0;
    if ( v11 )
    {
      v13 = 0i64;
      do
      {
        if ( !forceFlush && !this->mStreamerStalled && v7 <= v4 && v8 <= v5 )
          break;
        v14 = this->mUnReferencedBucket->mRequests.p[v13];
        mData = (UFG::PartDefinition *)v14->mPartDefHandle.mData;
        if ( mData )
          ModelSize = UFG::PartDefinition::GetModelSize(mData);
        else
          ModelSize = 0;
        v7 -= ModelSize;
        v17 = v14->mPartDefHandle.mData;
        if ( v17 )
        {
          if ( !HIDWORD(v17[2].mTypeUID) )
          {
            UFG::PartDefinition::GetTextureFileName((UFG::PartDefinition *)v14->mPartDefHandle.mData, &result);
            UFG::qString::ReplaceString(&result, ".perm.bin", ".temp.bin", 0);
            HIDWORD(v17[2].mTypeUID) = PartDatabase_QueryFileSize(result.mData);
            UFG::qString::~qString(&result);
          }
          mTypeUID_high = HIDWORD(v17[2].mTypeUID);
        }
        else
        {
          mTypeUID_high = 0;
        }
        v8 -= mTypeUID_high;
        v19 = 0i64;
        v20 = this->mQueued.size;
        if ( this->mQueued.size )
        {
          p = this->mQueued.p;
          while ( v14 != p[v19] )
          {
            v19 = (unsigned int)(v19 + 1);
            if ( (unsigned int)v19 >= v20 )
              goto LABEL_32;
          }
          if ( (int)v19 >= 0 )
          {
            p[v19] = p[v20 - 1];
            if ( this->mQueued.size > 1 )
              --this->mQueued.size;
            else
              this->mQueued.size = 0;
          }
        }
LABEL_32:
        v22 = 0i64;
        v23 = this->mLoading.size;
        if ( v23 )
        {
          v24 = this->mLoading.p;
          while ( v14 != v24[v22] )
          {
            v22 = (unsigned int)(v22 + 1);
            if ( (unsigned int)v22 >= v23 )
              goto LABEL_41;
          }
          if ( (int)v22 >= 0 )
          {
            v24[v22] = v24[v23 - 1];
            v25 = this->mLoading.size;
            if ( v25 > 1 )
              this->mLoading.size = v25 - 1;
            else
              this->mLoading.size = 0;
          }
        }
LABEL_41:
        v26 = 0i64;
        v27 = this->mLoaded.size;
        if ( v27 )
        {
          v28 = this->mLoaded.p;
          while ( v14 != v28[v26] )
          {
            v26 = (unsigned int)(v26 + 1);
            if ( (unsigned int)v26 >= v27 )
              goto LABEL_50;
          }
          if ( (int)v26 >= 0 )
          {
            v28[v26] = v28[v27 - 1];
            v29 = this->mLoaded.size;
            if ( v29 > 1 )
              this->mLoaded.size = v29 - 1;
            else
              this->mLoaded.size = 0;
          }
        }
LABEL_50:
        PartDatabase_ReleaseStream(v14);
        mPrev = v14->mPrev;
        mNext = v14->mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        v14->mPrev = v14;
        v14->mNext = v14;
        v32 = v14->mInstances.p;
        if ( v32 )
          operator delete[](v32);
        v14->mInstances.p = 0i64;
        *(_QWORD *)&v14->mInstances.size = 0i64;
        UFG::qReflectHandleBase::~qReflectHandleBase(&v14->mPartDefHandle);
        v33 = v14->mPrev;
        v34 = v14->mNext;
        v33->mNext = v34;
        v34->mPrev = v33;
        v14->mPrev = v14;
        v14->mNext = v14;
        operator delete[](v14);
        this->mDirty = 1;
        if ( this->mStreamerStalled )
        {
          if ( v12 )
            break;
        }
        ++v12;
        ++v13;
        v4 = v36;
        v5 = v38;
      }
      while ( v12 < v11 );
    }
  }
}

// File Line: 417
// RVA: 0x1592D0
void __fastcall UFG::PartPool::InitBuckets(UFG::PartPool *this)
{
  char *v2; // rax
  unsigned int v3; // edi
  UFG::PartPool::Bucket *v4; // rax
  char *v5; // rax
  UFG::PartPool::Bucket *v6; // rax
  char *v7; // rax
  UFG::PartPool::Bucket *v8; // rax
  char *v9; // rax
  UFG::PartPool::Bucket *v10; // rax
  char *v11; // rax
  UFG::PartPool::Bucket *v12; // rax
  char *v13; // rax
  UFG::PartPool::Bucket *v14; // rax
  UFG::PartPool::Bucket *mMasterBucket; // rsi
  unsigned int i; // ebx

  v2 = UFG::qMalloc(0x38ui64, "Bucket", 0i64);
  v3 = 0;
  if ( v2 )
    UFG::PartPool::Bucket::Bucket((UFG::PartPool::Bucket *)v2);
  else
    v4 = 0i64;
  this->mMasterBucket = v4;
  v5 = UFG::qMalloc(0x38ui64, "Bucket", 0i64);
  if ( v5 )
    UFG::PartPool::Bucket::Bucket((UFG::PartPool::Bucket *)v5);
  else
    v6 = 0i64;
  this->mReservedBucket = v6;
  UFG::PartPool::Bucket::AddChild(this->mMasterBucket, v6);
  v7 = UFG::qMalloc(0x38ui64, "Bucket", 0i64);
  if ( v7 )
    UFG::PartPool::Bucket::Bucket((UFG::PartPool::Bucket *)v7);
  else
    v8 = 0i64;
  this->mUnReferencedBucket = v8;
  UFG::PartPool::Bucket::AddChild(this->mMasterBucket, v8);
  v9 = UFG::qMalloc(0x38ui64, "Bucket", 0i64);
  if ( v9 )
    UFG::PartPool::Bucket::Bucket((UFG::PartPool::Bucket *)v9);
  else
    v10 = 0i64;
  this->mCriticalBucket = v10;
  UFG::PartPool::Bucket::AddChild(this->mMasterBucket, v10);
  v11 = UFG::qMalloc(0x38ui64, "Bucket", 0i64);
  if ( v11 )
    UFG::PartPool::Bucket::Bucket((UFG::PartPool::Bucket *)v11);
  else
    v12 = 0i64;
  this->mHighBucket = v12;
  UFG::PartPool::Bucket::AddChild(this->mMasterBucket, v12);
  v13 = UFG::qMalloc(0x38ui64, "Bucket", 0i64);
  if ( v13 )
    UFG::PartPool::Bucket::Bucket((UFG::PartPool::Bucket *)v13);
  else
    v14 = 0i64;
  this->mLowBucket = v14;
  UFG::PartPool::Bucket::AddChild(this->mMasterBucket, v14);
  UFG::PartPool::Bucket::UpdateSize(this->mMasterBucket);
  mMasterBucket = this->mMasterBucket;
  mMasterBucket->mPriority = 0;
  for ( i = 0; i < mMasterBucket->mChildren.size; ++i )
  {
    v3 += i + 1;
    UFG::PartPool::Bucket::UpdatePriority(mMasterBucket->mChildren.p[i], v3);
  }
}

// File Line: 487
// RVA: 0x159FD0
void __fastcall UFG::PartPool::QueueRequest(UFG::PartPool *this, UFG::qPropertySet *pRequest)
{
  bool v2; // zf
  unsigned int size; // edx
  __int64 v6; // rax
  UFG::PartRequest **p; // r8
  UFG::qPropertySet *item; // [rsp+38h] [rbp+10h] BYREF

  v2 = pRequest->mPropertyMask == 2;
  item = pRequest;
  if ( !v2 )
  {
    size = this->mQueued.size;
    v6 = 0i64;
    if ( this->mQueued.size )
    {
      p = this->mQueued.p;
      while ( pRequest != (UFG::qPropertySet *)p[v6] )
      {
        v6 = (unsigned int)(v6 + 1);
        if ( (unsigned int)v6 >= size )
          goto LABEL_11;
      }
      if ( (int)v6 >= 0 )
      {
        p[(unsigned int)v6] = p[size - 1];
        if ( this->mQueued.size > 1 )
          --this->mQueued.size;
        else
          this->mQueued.size = 0;
      }
    }
LABEL_11:
    UFG::qArray<UFG::PedSpawningInfo *,0>::Add(
      (UFG::qArray<UFG::qPropertySet *,0> *)&this->mLoading,
      &item,
      "qArray.Add");
    pRequest->mPropertyMask = 2;
    this->mDirty = 1;
  }
  PartDatabase_QueueStream((UFG::PartRequest *)pRequest);
}

// File Line: 494
// RVA: 0x159AD0
void __fastcall UFG::PartPool::PartLoadNotification(UFG::PartPool *this, UFG::qPropertySet *pRequest)
{
  bool v2; // zf
  unsigned int size; // edx
  __int64 v6; // rax
  UFG::PartRequest **p; // r8
  unsigned int v8; // eax
  UFG::qPropertySet *item; // [rsp+38h] [rbp+10h] BYREF

  v2 = pRequest->mPropertyMask == 3;
  item = pRequest;
  if ( !v2 )
  {
    size = this->mLoading.size;
    v6 = 0i64;
    if ( size )
    {
      p = this->mLoading.p;
      while ( pRequest != (UFG::qPropertySet *)p[v6] )
      {
        v6 = (unsigned int)(v6 + 1);
        if ( (unsigned int)v6 >= size )
          goto LABEL_11;
      }
      if ( (int)v6 >= 0 )
      {
        p[(unsigned int)v6] = p[size - 1];
        v8 = this->mLoading.size;
        if ( v8 > 1 )
          this->mLoading.size = v8 - 1;
        else
          this->mLoading.size = 0;
      }
    }
LABEL_11:
    UFG::qArray<UFG::PedSpawningInfo *,0>::Add(
      (UFG::qArray<UFG::qPropertySet *,0> *)&this->mLoaded,
      &item,
      "qArray.Add");
    pRequest->mPropertyMask = 3;
    this->mDirty = 1;
  }
}

// File Line: 499
// RVA: 0x15B220
void __fastcall UFG::PartPool::UpdateBuckets(UFG::PartPool *this)
{
  UFG::PartPool *v1; // r13
  UFG::PartPool *mNext; // r15
  UFG::qList<UFG::PartRequest,UFG::PartRequest,1,0> *p_mRequestList; // r13
  UFG::PartRequest **p; // r12
  unsigned int v5; // ecx
  _DWORD *v6; // rax
  __int64 v7; // rdx
  __int64 v8; // rdi
  __int64 v9; // r14
  unsigned int v10; // ebx
  unsigned int v11; // esi
  unsigned int v12; // ebx
  unsigned __int64 v13; // rax
  char *v14; // rax
  char *v15; // rbp
  __int64 i; // r9
  __int64 v17; // r8
  __int64 v18; // rax
  __int64 v19[6]; // [rsp+20h] [rbp-68h]

  v1 = this;
  this->mUnReferencedBucket->mRequests.size = 0;
  this->mReservedBucket->mRequests.size = 0;
  this->mCriticalBucket->mRequests.size = 0;
  this->mHighBucket->mRequests.size = 0;
  this->mLowBucket->mRequests.size = 0;
  mNext = (UFG::PartPool *)this->mRequestList.mNode.mNext;
  v19[0] = (__int64)this->mUnReferencedBucket;
  v19[1] = (__int64)this->mReservedBucket;
  v19[2] = (__int64)this->mCriticalBucket;
  v19[3] = (__int64)this->mHighBucket;
  v19[4] = (__int64)this->mLowBucket;
  if ( mNext != (UFG::PartPool *)&this->mRequestList )
  {
    p_mRequestList = &this->mRequestList;
    do
    {
      p = mNext->mQueued.p;
      v5 = 0;
      v6 = (_DWORD *)&mNext->mHighBucket + 1;
      v7 = 0i64;
      while ( !*v6 )
      {
        ++v5;
        ++v7;
        ++v6;
        if ( v5 >= 5 )
        {
          v7 = 0i64;
          break;
        }
      }
      v8 = v19[v7];
      v9 = *(unsigned int *)(v8 + 16);
      v10 = *(_DWORD *)(v8 + 20);
      v11 = v9 + 1;
      if ( (int)v9 + 1 > v10 )
      {
        if ( v10 )
          v12 = 2 * v10;
        else
          v12 = 1;
        for ( ; v12 < v11; v12 *= 2 )
          ;
        if ( v12 <= 2 )
          v12 = 2;
        if ( v12 - v11 > 0x10000 )
          v12 = v9 + 65537;
        if ( v12 != (_DWORD)v9 )
        {
          v13 = 8i64 * v12;
          if ( !is_mul_ok(v12, 8ui64) )
            v13 = -1i64;
          v14 = UFG::qMalloc(v13, "qArray.Add", 0i64);
          v15 = v14;
          if ( *(_QWORD *)(v8 + 24) )
          {
            for ( i = 0i64;
                  (unsigned int)i < *(_DWORD *)(v8 + 16);
                  *(_QWORD *)&v14[v17] = *(_QWORD *)(v17 + *(_QWORD *)(v8 + 24)) )
            {
              v17 = 8 * i;
              i = (unsigned int)(i + 1);
            }
            operator delete[](*(void **)(v8 + 24));
          }
          *(_QWORD *)(v8 + 24) = v15;
          *(_DWORD *)(v8 + 20) = v12;
        }
      }
      v18 = *(_QWORD *)(v8 + 24);
      *(_DWORD *)(v8 + 16) = v11;
      *(_QWORD *)(v18 + 8 * v9) = mNext;
      mNext = (UFG::PartPool *)p;
    }
    while ( p != (UFG::PartRequest **)p_mRequestList );
    v1 = this;
  }
  UFG::PartPool::Bucket::UpdateSize(v1->mMasterBucket);
}

// File Line: 536
// RVA: 0x159260
void UFG::PartDatabase::Init(void)
{
  char *v0; // rax
  UFG::PartDatabase *v1; // rbx

  v0 = UFG::qMalloc(0x90ui64, UFG::gGlobalNewName, 0i64);
  v1 = (UFG::PartDatabase *)v0;
  if ( v0 )
  {
    UFG::PartPool::PartPool((UFG::PartPool *)v0);
    UFG::PartDatabase::sInstance = v1;
  }
  else
  {
    UFG::PartDatabase::sInstance = 0i64;
  }
}

// File Line: 542
// RVA: 0x15A0A0
void UFG::PartDatabase::Quit(void)
{
  UFG::PartDatabase *v0; // rbx

  v0 = UFG::PartDatabase::sInstance;
  if ( UFG::PartDatabase::sInstance )
  {
    PartDatabase_ReleaseDatabase();
    UFG::PartPool::~PartPool(&v0->mPool);
    operator delete[](v0);
  }
  UFG::PartDatabase::sInstance = 0i64;
}

// File Line: 549
// RVA: 0x1594D0
UFG::PartDatabase *__fastcall UFG::PartDatabase::Instance()
{
  return UFG::PartDatabase::sInstance;
}

// File Line: 567
// RVA: 0x159200
bool __fastcall UFG::ObjectResourceManager::HasQueue(UFG::PartDatabase *this)
{
  return this->mPool.mQueued.size + this->mPool.mLoading.size != 0;
}

// File Line: 582
// RVA: 0x158AF0
// attributes: thunk
unsigned int __fastcall UFG::PartDatabase::GetBytesRemainingToLoad(UFG::PartDatabase *this)
{
  return UFG::PartPool::GetQueuedBytes(&this->mPool);
}

// File Line: 587
// RVA: 0x15B1E0
void __fastcall UFG::PartDatabase::Update(UFG::PartDatabase *this, float deltaTime)
{
  if ( this->mReloadParts )
  {
    UFG::PartPool::ReloadRequests(&this->mPool);
    this->mReloadParts = 0;
  }
  UFG::PartPool::UpdateRequests(&this->mPool);
  this->mPool.mDirty = 0;
}

// File Line: 601
// RVA: 0x1587F0
// attributes: thunk
void __fastcall UFG::PartDatabase::FlushParts(UFG::PartDatabase *this, bool forceFlush)
{
  UFG::PartPool::FlushParts(&this->mPool, forceFlush);
}

// File Line: 606
// RVA: 0x158D50
UFG::PartDefinition *__fastcall UFG::PartDatabase::GetPartByName(UFG::PartDatabase *this, const char *name)
{
  unsigned __int64 v3; // rbx
  UFG::qReflectWarehouse *v4; // rax
  UFG::qReflectInventoryBase *Inventory; // rax

  v3 = UFG::qStringHash64("UFG::PartDefinition", 0xFFFFFFFFFFFFFFFFui64);
  v4 = UFG::qReflectWarehouse::Instance();
  Inventory = UFG::qReflectWarehouse::GetInventory(v4, v3);
  return (UFG::PartDefinition *)UFG::qReflectInventoryBase::FindObjectByName(Inventory, name);
}

// File Line: 617
// RVA: 0x159AA0
void __fastcall UFG::PartDatabase::OnStreamingComplete(UFG::PartDatabase *this, UFG::PartRequest *pRequest)
{
  UFG::PartRequest::OnLoaded(pRequest);
  UFG::PartPool::PartLoadNotification(&this->mPool, pRequest);
}

// File Line: 628
// RVA: 0x159570
void __fastcall UFG::PartDatabase::ModifyPriorityForPart(
        UFG::PartDatabase *this,
        UFG::PartDefinition *part,
        int oldPriority,
        int newPriority)
{
  UFG::qNode<UFG::PartRequest,UFG::PartRequest> *mNext; // rax

  mNext = this->mPool.mRequestList.mNode.mNext;
  if ( mNext != (UFG::qNode<UFG::PartRequest,UFG::PartRequest> *)&this->mPool.mRequestList )
  {
    while ( mNext[4].mPrev != (UFG::qNode<UFG::PartRequest,UFG::PartRequest> *)part->mBaseNode.mUID )
    {
      mNext = mNext->mNext;
      if ( mNext == (UFG::qNode<UFG::PartRequest,UFG::PartRequest> *)&this->mPool.mRequestList )
        return;
    }
    ++*((_DWORD *)&mNext[5].mPrev + newPriority + 1);
    LODWORD(mNext[6].mNext) = Illusion::gEngine.mFrameCount;
    --*((_DWORD *)&mNext[5].mPrev + oldPriority + 1);
    LODWORD(mNext[6].mNext) = Illusion::gEngine.mFrameCount;
  }
}

// File Line: 638
// RVA: 0x159560
// attributes: thunk
void __fastcall UFG::PartDatabase::LoadDatabase(UFG::PartDatabase *this)
{
  PartDatabase_LoadDatabase();
}

// File Line: 643
// RVA: 0x159480
void __fastcall UFG::PartDatabase::InitPool(UFG::PartDatabase *this)
{
  unsigned int mainMemory; // [rsp+30h] [rbp+8h] BYREF
  unsigned int textureMemory; // [rsp+38h] [rbp+10h] BYREF

  mainMemory = 0;
  textureMemory = 0;
  PartDatabase_QueryPoolSize(&mainMemory, &textureMemory);
  this->mPool.mMaxModelMemory = mainMemory;
  this->mPool.mMaxTextureMemory = textureMemory;
}

