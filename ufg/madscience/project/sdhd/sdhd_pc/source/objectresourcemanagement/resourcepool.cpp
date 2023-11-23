// File Line: 49
// RVA: 0x437140
void __fastcall UFG::ResourcePriorityBucket::ResourcePriorityBucket(UFG::ResourcePriorityBucket *this)
{
  unsigned int v2; // ebx
  unsigned __int64 v3; // rax
  UFG::allocator::free_link *v4; // rax
  UFG::ResourceRequest **v5; // rsi

  this->mName.mUID = -1;
  v2 = 0;
  this->mPriority = 0;
  this->mpParent = 0i64;
  this->mChildren.p = 0i64;
  *(_QWORD *)&this->mChildren.size = 0i64;
  this->mResourceRequests.p = 0i64;
  *(_QWORD *)&this->mResourceRequests.size = 0i64;
  this->mReserveSize[1] = -1;
  this->mReserveSize[0] = -1;
  this->mMaxSize[1] = -1;
  this->mMaxSize[0] = -1;
  if ( this->mResourceRequests.capacity < 0x10 && this->mResourceRequests.size != 16 )
  {
    v3 = 128i64;
    if ( !is_mul_ok(0x10ui64, 8ui64) )
      v3 = -1i64;
    v4 = UFG::qMalloc(v3, "ResourcePriorityBucket", 0i64);
    v5 = (UFG::ResourceRequest **)v4;
    if ( this->mResourceRequests.p )
    {
      if ( this->mResourceRequests.size )
      {
        do
        {
          v4[v2] = (UFG::allocator::free_link)this->mResourceRequests.p[v2];
          ++v2;
        }
        while ( v2 < this->mResourceRequests.size );
      }
      operator delete[](this->mResourceRequests.p);
    }
    this->mResourceRequests.p = v5;
    this->mResourceRequests.capacity = 16;
  }
  UFG::qMemSet(this->mMemoryUsage, 0, 0x18u);
}

// File Line: 88
// RVA: 0x4479C0
char __fastcall UFG::ResourcePriorityBucket::WillFitWithinSizeConstraints(
        UFG::ResourcePriorityBucket *this,
        UFG::TrueCrowdSet::Instance *instance)
{
  int v2; // edi
  int v4; // ebx
  int v5; // edi
  int v6; // ebx
  UFG::PartDatabase *v7; // rax
  UFG::PartPool::Bucket *mMasterBucket; // r8
  float v9; // xmm0_4
  int v10; // ecx
  int v11; // r14d
  int v12; // eax
  float v13; // xmm0_4
  int v14; // ebp
  unsigned int mNumParts; // eax
  char v16; // r10
  unsigned int v17; // r11d
  unsigned int v18; // r9d
  UFG::ModelTextureCombination *mPart; // r8
  __int64 v20; // rbx
  __int64 mModelIndex; // rcx
  UFG::TrueCrowdModel *v22; // rdx
  UFG::ResourceRequest *mRequest; // rax
  __int64 mOffset; // rax
  char *v25; // rcx
  char *v26; // rdx
  char *v27; // rax
  __int64 v28; // rcx

  v2 = this->mMaxSize[1];
  if ( v2 == -1 )
    return 1;
  v4 = this->mMaxSize[0];
  if ( v4 == -1 )
    return 1;
  v5 = v2 - (this->mMemoryUsage[0][1] + this->mMemoryUsage[1][1] + this->mMemoryUsage[2][1]);
  v6 = v4 - (this->mMemoryUsage[0][0] + this->mMemoryUsage[1][0] + this->mMemoryUsage[2][0]);
  v7 = UFG::PartDatabase::Instance();
  mMasterBucket = v7->mPool.mMasterBucket;
  v9 = (float)v5;
  v10 = v7->mPool.mMaxModelMemory - mMasterBucket->mMemoryUsageModel - v7->mPool.mExternalUsedModelMemory;
  if ( (float)v5 >= (float)v10 )
    v9 = (float)v10;
  v11 = (int)v9;
  v12 = v7->mPool.mMaxTextureMemory - mMasterBucket->mMemoryUsageTexture - v7->mPool.mExternalUsedTextureMemory;
  v13 = (float)v6;
  if ( (float)v6 >= (float)v12 )
    v13 = (float)v12;
  v14 = (int)v13;
  if ( v11 <= 0 || v14 <= 0 )
    return 0;
  mNumParts = instance->mNumParts;
  v16 = 0;
  v17 = 0;
  v18 = 0;
  if ( !mNumParts )
    return 1;
  mPart = instance->mPart;
  v20 = mNumParts;
  do
  {
    mModelIndex = mPart->mModelIndex;
    if ( (_DWORD)mModelIndex != -1 )
    {
      v22 = *(UFG::TrueCrowdModel **)(*(_QWORD *)((char *)&mPart[2].mModelIndex
                                                + (unsigned __int64)instance->mSet
                                                - (_QWORD)instance)
                                    + 8 * mModelIndex);
      mRequest = v22->mRequest;
      if ( !mRequest || mRequest->mLoadStatus != Loaded )
      {
        v17 += v22->mModelSize;
        v18 += v22->mTextureSize;
      }
      if ( v22->mNumTextureSets )
      {
        mOffset = v22->mTextureSets.mOffset;
        if ( mOffset )
          v25 = (char *)&v22->mTextureSets + mOffset;
        else
          v25 = 0i64;
        v26 = &v25[8 * mPart->mTextureSetIndex];
        if ( *(_QWORD *)v26 )
          v27 = &v26[*(_QWORD *)v26];
        else
          v27 = 0i64;
        v28 = *((_QWORD *)v27 + 1);
        if ( !v28 || *(_DWORD *)(v28 + 20) != 3 )
          v18 += *((_DWORD *)v27 + 5);
      }
    }
    ++mPart;
    --v20;
  }
  while ( v20 );
  if ( v17 <= v11 && v18 <= v14 )
    return 1;
  return v16;
}

// File Line: 109
// RVA: 0x447210
void __fastcall UFG::ResourcePriorityBucket::UpdateSize(UFG::ResourcePriorityBucket *this)
{
  __int64 v2; // rsi
  unsigned int i; // edi
  unsigned int j; // r8d
  UFG::ResourceRequest *v5; // r9
  UFG::TrueCrowdResource *mResource; // rdx
  char *v7; // rcx
  char *v8; // rdx
  unsigned int (*mMemoryUsage)[2]; // rax
  __int64 v10; // r9

  UFG::qMemSet(this->mMemoryUsage, 0, 0x18u);
  v2 = 0i64;
  for ( i = 0; i < this->mChildren.size; ++i )
    UFG::ResourcePriorityBucket::UpdateSize(this->mChildren.p[i]);
  for ( j = 0; j < this->mResourceRequests.size; *((_DWORD *)v8 + 6) += v5->mResource->mTextureSize )
  {
    v5 = this->mResourceRequests.p[j];
    mResource = v5->mResource;
    if ( v5->mType == Model )
    {
      v7 = (char *)this + 8 * (int)mResource->mType.mValue;
      *((_DWORD *)v7 + 7) += mResource->mModelSize;
    }
    ++j;
    v8 = (char *)this + 8 * (int)mResource->mType.mValue;
  }
  if ( this->mChildren.size )
  {
    do
    {
      mMemoryUsage = this->mMemoryUsage;
      v10 = 3i64;
      do
      {
        ++mMemoryUsage;
        (*mMemoryUsage)[-1] += *(int *)((char *)&this->mChildren.p[v2]->mMaxSize[-5]
                                      + (unsigned __int64)mMemoryUsage
                                      - (_QWORD)this);
        (*mMemoryUsage)[-2] += *(unsigned int *)((char *)&(*mMemoryUsage)[-2]
                                               + (char *)this->mChildren.p[v2]
                                               - (char *)this);
        --v10;
      }
      while ( v10 );
      v2 = (unsigned int)(v2 + 1);
    }
    while ( (unsigned int)v2 < this->mChildren.size );
  }
}

// File Line: 137
// RVA: 0x446670
void __fastcall UFG::ResourcePriorityBucket::UpdatePriority(UFG::ResourcePriorityBucket *this, unsigned int priority)
{
  __int64 v2; // rbx
  unsigned int v3; // edi

  v2 = 0i64;
  v3 = priority;
  for ( this->mPriority = priority; (unsigned int)v2 < this->mChildren.size; v2 = (unsigned int)(v2 + 1) )
  {
    v3 += v2 + 1;
    UFG::ResourcePriorityBucket::UpdatePriority(this->mChildren.p[v2], v3);
  }
}

// File Line: 148
// RVA: 0x443410
bool __fastcall UFG::SortByReferenceFramePredicate(UFG::ResourceRequest *a, UFG::ResourceRequest *b)
{
  return a->mLastReferencedFrame < b->mLastReferencedFrame;
}

// File Line: 234
// RVA: 0x436EB0
void __fastcall UFG::ResourcePool::ResourcePool(UFG::ResourcePool *this)
{
  UFG::qList<UFG::PreloadRequest,UFG::PreloadRequest,1,0> *p_mEmptyRequestList; // rdi
  unsigned __int64 v3; // rax
  UFG::ResourceRequest **v4; // rsi
  unsigned int i; // r8d
  unsigned __int64 v6; // rax
  UFG::ResourceRequest **v7; // rsi
  unsigned int j; // r8d
  unsigned __int64 v9; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::ResourceRequest **v11; // rsi
  unsigned int k; // r9d
  __int64 v13; // rsi
  UFG::allocator::free_link *v14; // rax
  UFG::allocator::free_link *v15; // rcx
  int v16; // edx
  UFG::allocator::free_link *v17; // rax
  UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *mPrev; // rax

  this->mQueued.p = 0i64;
  *(_QWORD *)&this->mQueued.size = 0i64;
  this->mLoading.p = 0i64;
  *(_QWORD *)&this->mLoading.size = 0i64;
  this->mLoaded.p = 0i64;
  *(_QWORD *)&this->mLoaded.size = 0i64;
  this->mRequestList.mNode.mPrev = &this->mRequestList.mNode;
  this->mRequestList.mNode.mNext = &this->mRequestList.mNode;
  this->mEntityStates.p = 0i64;
  *(_QWORD *)&this->mEntityStates.size = 0i64;
  p_mEmptyRequestList = &this->mEmptyRequestList;
  this->mEmptyRequestList.mNode.mPrev = &this->mEmptyRequestList.mNode;
  this->mEmptyRequestList.mNode.mNext = &this->mEmptyRequestList.mNode;
  *(_QWORD *)&this->mMaxModelMemory = 0i64;
  *(_QWORD *)&this->mAmbientModelMemoryLimit = 0i64;
  this->mFragmentationReservePercentage = 0.15000001;
  *(_WORD *)&this->mStreamerStalled = 256;
  if ( this->mQueued.capacity < 0x20 && this->mQueued.size != 32 )
  {
    v3 = 256i64;
    if ( !is_mul_ok(0x20ui64, 8ui64) )
      v3 = -1i64;
    v4 = (UFG::ResourceRequest **)UFG::qMalloc(v3, "ResourcePool", 0i64);
    if ( this->mQueued.p )
    {
      for ( i = 0; i < this->mQueued.size; ++i )
        v4[i] = this->mQueued.p[i];
      operator delete[](this->mQueued.p);
    }
    this->mQueued.p = v4;
    this->mQueued.capacity = 32;
  }
  if ( this->mLoading.capacity < 0x20 && this->mLoading.size != 32 )
  {
    v6 = 256i64;
    if ( !is_mul_ok(0x20ui64, 8ui64) )
      v6 = -1i64;
    v7 = (UFG::ResourceRequest **)UFG::qMalloc(v6, "ResourcePool", 0i64);
    if ( this->mLoading.p )
    {
      for ( j = 0; j < this->mLoading.size; ++j )
        v7[j] = this->mLoading.p[j];
      operator delete[](this->mLoading.p);
    }
    this->mLoading.p = v7;
    this->mLoading.capacity = 32;
  }
  if ( this->mLoaded.capacity < 0x20 && this->mLoaded.size != 32 )
  {
    v9 = 256i64;
    if ( !is_mul_ok(0x20ui64, 8ui64) )
      v9 = -1i64;
    v10 = UFG::qMalloc(v9, "ResourcePool", 0i64);
    v11 = (UFG::ResourceRequest **)v10;
    if ( this->mLoaded.p )
    {
      for ( k = 0; k < this->mLoaded.size; ++k )
        v10[k] = (UFG::allocator::free_link)this->mLoaded.p[k];
      operator delete[](this->mLoaded.p);
    }
    this->mLoaded.p = v11;
    this->mLoaded.capacity = 32;
  }
  UFG::ResourcePool::InitPriorityBuckets(this);
  v13 = 128i64;
  do
  {
    v14 = UFG::qMalloc(0x148ui64, "PreloadRequest", 0i64);
    v15 = v14;
    if ( v14 )
    {
      v14->mNext = v14;
      v14[1].mNext = v14;
      v16 = 15;
      v17 = v14 + 8;
      do
      {
        v17[-1].mNext = 0i64;
        v17->mNext = 0i64;
        v17 += 2;
        --v16;
      }
      while ( v16 >= 0 );
      LODWORD(v15[40].mNext) = -1;
      BYTE1(v15[39].mNext) = 0;
      BYTE4(v15[40].mNext) = 0;
      HIDWORD(v15[39].mNext) = 0;
      v15[2].mNext = 0i64;
      LODWORD(v15[3].mNext) = 0;
      v15[4].mNext = 0i64;
      LODWORD(v15[5].mNext) = 0;
    }
    else
    {
      v15 = 0i64;
    }
    mPrev = p_mEmptyRequestList->mNode.mPrev;
    mPrev->mNext = (UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *)v15;
    v15->mNext = (UFG::allocator::free_link *)mPrev;
    v15[1].mNext = (UFG::allocator::free_link *)p_mEmptyRequestList;
    p_mEmptyRequestList->mNode.mPrev = (UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *)v15;
    --v13;
  }
  while ( v13 );
}RequestList->mNode.mPrev = (UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *)v15;
    --v13;
  }
  while ( v13 );

// File Line: 247
// RVA: 0x437D00
void __fastcall UFG::ResourcePool::~ResourcePool(UFG::ResourcePool *this)
{
  UFG::ResourcePriorityBucket *mMasterBucket; // rbx
  UFG::ResourceRequest **p; // rcx
  UFG::ResourcePriorityBucket **v4; // rcx
  UFG::ResourcePriorityBucket *mReservedBucket; // rbx
  UFG::ResourceRequest **v6; // rcx
  UFG::ResourcePriorityBucket **v7; // rcx
  UFG::ResourcePriorityBucket *mCriticalBucket; // rbx
  UFG::ResourceRequest **v9; // rcx
  UFG::ResourcePriorityBucket **v10; // rcx
  UFG::ResourcePriorityBucket *mHighBucket; // rbx
  UFG::ResourceRequest **v12; // rcx
  UFG::ResourcePriorityBucket **v13; // rcx
  UFG::ResourcePriorityBucket *mLowBucket; // rbx
  UFG::ResourceRequest **v15; // rcx
  UFG::ResourcePriorityBucket **v16; // rcx
  UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *mPrev; // rcx
  UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *mNext; // rax
  UFG::EntityTypeState **v19; // rcx
  UFG::qNode<UFG::ResourceRequest,UFG::ResourceRequest> *v20; // rcx
  UFG::qNode<UFG::ResourceRequest,UFG::ResourceRequest> *v21; // rax
  UFG::ResourceRequest **v22; // rcx
  UFG::ResourceRequest **v23; // rcx
  UFG::ResourceRequest **v24; // rcx

  mMasterBucket = this->mMasterBucket;
  if ( mMasterBucket )
  {
    p = mMasterBucket->mResourceRequests.p;
    if ( p )
      operator delete[](p);
    mMasterBucket->mResourceRequests.p = 0i64;
    *(_QWORD *)&mMasterBucket->mResourceRequests.size = 0i64;
    v4 = mMasterBucket->mChildren.p;
    if ( v4 )
      operator delete[](v4);
    mMasterBucket->mChildren.p = 0i64;
    *(_QWORD *)&mMasterBucket->mChildren.size = 0i64;
    operator delete[](mMasterBucket);
  }
  mReservedBucket = this->mReservedBucket;
  if ( mReservedBucket )
  {
    v6 = mReservedBucket->mResourceRequests.p;
    if ( v6 )
      operator delete[](v6);
    mReservedBucket->mResourceRequests.p = 0i64;
    *(_QWORD *)&mReservedBucket->mResourceRequests.size = 0i64;
    v7 = mReservedBucket->mChildren.p;
    if ( v7 )
      operator delete[](v7);
    mReservedBucket->mChildren.p = 0i64;
    *(_QWORD *)&mReservedBucket->mChildren.size = 0i64;
    operator delete[](mReservedBucket);
  }
  mCriticalBucket = this->mCriticalBucket;
  if ( mCriticalBucket )
  {
    v9 = mCriticalBucket->mResourceRequests.p;
    if ( v9 )
      operator delete[](v9);
    mCriticalBucket->mResourceRequests.p = 0i64;
    *(_QWORD *)&mCriticalBucket->mResourceRequests.size = 0i64;
    v10 = mCriticalBucket->mChildren.p;
    if ( v10 )
      operator delete[](v10);
    mCriticalBucket->mChildren.p = 0i64;
    *(_QWORD *)&mCriticalBucket->mChildren.size = 0i64;
    operator delete[](mCriticalBucket);
  }
  mHighBucket = this->mHighBucket;
  if ( mHighBucket )
  {
    v12 = mHighBucket->mResourceRequests.p;
    if ( v12 )
      operator delete[](v12);
    mHighBucket->mResourceRequests.p = 0i64;
    *(_QWORD *)&mHighBucket->mResourceRequests.size = 0i64;
    v13 = mHighBucket->mChildren.p;
    if ( v13 )
      operator delete[](v13);
    mHighBucket->mChildren.p = 0i64;
    *(_QWORD *)&mHighBucket->mChildren.size = 0i64;
    operator delete[](mHighBucket);
  }
  mLowBucket = this->mLowBucket;
  if ( mLowBucket )
  {
    v15 = mLowBucket->mResourceRequests.p;
    if ( v15 )
      operator delete[](v15);
    mLowBucket->mResourceRequests.p = 0i64;
    *(_QWORD *)&mLowBucket->mResourceRequests.size = 0i64;
    v16 = mLowBucket->mChildren.p;
    if ( v16 )
      operator delete[](v16);
    mLowBucket->mChildren.p = 0i64;
    *(_QWORD *)&mLowBucket->mChildren.size = 0i64;
    operator delete[](mLowBucket);
  }
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&this->mEmptyRequestList);
  mPrev = this->mEmptyRequestList.mNode.mPrev;
  mNext = this->mEmptyRequestList.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mEmptyRequestList.mNode.mPrev = &this->mEmptyRequestList.mNode;
  this->mEmptyRequestList.mNode.mNext = &this->mEmptyRequestList.mNode;
  v19 = this->mEntityStates.p;
  if ( v19 )
    operator delete[](v19);
  this->mEntityStates.p = 0i64;
  *(_QWORD *)&this->mEntityStates.size = 0i64;
  UFG::qList<UFG::ResourceRequest,UFG::ResourceRequest,1,0>::DeleteNodes(&this->mRequestList);
  v20 = this->mRequestList.mNode.mPrev;
  v21 = this->mRequestList.mNode.mNext;
  v20->mNext = v21;
  v21->mPrev = v20;
  this->mRequestList.mNode.mPrev = &this->mRequestList.mNode;
  this->mRequestList.mNode.mNext = &this->mRequestList.mNode;
  v22 = this->mLoaded.p;
  if ( v22 )
    operator delete[](v22);
  this->mLoaded.p = 0i64;
  *(_QWORD *)&this->mLoaded.size = 0i64;
  v23 = this->mLoading.p;
  if ( v23 )
    operator delete[](v23);
  this->mLoading.p = 0i64;
  *(_QWORD *)&this->mLoading.size = 0i64;
  v24 = this->mQueued.p;
  if ( v24 )
    operator delete[](v24);
  this->mQueued.p = 0i64;
  *(_QWORD *)&this->mQueued.size = 0i64;
}

// File Line: 256
// RVA: 0x43EE10
void __fastcall UFG::ResourcePool::InitPriorityBuckets(UFG::ResourcePool *this)
{
  UFG::allocator::free_link *v2; // rax
  unsigned int v3; // edi
  UFG::ResourcePriorityBucket *v4; // rax
  UFG::allocator::free_link *v5; // rax
  UFG::ResourcePriorityBucket *v6; // rax
  UFG::allocator::free_link *v7; // rax
  UFG::ResourcePriorityBucket *v8; // rax
  UFG::allocator::free_link *v9; // rax
  UFG::ResourcePriorityBucket *v10; // rax
  UFG::allocator::free_link *v11; // rax
  UFG::ResourcePriorityBucket *v12; // rax
  UFG::allocator::free_link *v13; // rax
  UFG::ResourcePriorityBucket *v14; // rax
  UFG::ResourcePriorityBucket *mMasterBucket; // rsi
  unsigned int i; // ebx

  v2 = UFG::qMalloc(0x58ui64, "ResourcePriorityBucket", 0i64);
  v3 = 0;
  if ( v2 )
    UFG::ResourcePriorityBucket::ResourcePriorityBucket((UFG::ResourcePriorityBucket *)v2);
  else
    v4 = 0i64;
  this->mMasterBucket = v4;
  v5 = UFG::qMalloc(0x58ui64, "ResourcePriorityBucket", 0i64);
  if ( v5 )
    UFG::ResourcePriorityBucket::ResourcePriorityBucket((UFG::ResourcePriorityBucket *)v5);
  else
    v6 = 0i64;
  this->mReservedBucket = v6;
  UFG::ResourcePriorityBucket::AddChild(this->mMasterBucket, v6);
  v7 = UFG::qMalloc(0x58ui64, "ResourcePriorityBucket", 0i64);
  if ( v7 )
    UFG::ResourcePriorityBucket::ResourcePriorityBucket((UFG::ResourcePriorityBucket *)v7);
  else
    v8 = 0i64;
  this->mUnReferencedBucket = v8;
  UFG::ResourcePriorityBucket::AddChild(this->mMasterBucket, v8);
  v9 = UFG::qMalloc(0x58ui64, "ResourcePriorityBucket", 0i64);
  if ( v9 )
    UFG::ResourcePriorityBucket::ResourcePriorityBucket((UFG::ResourcePriorityBucket *)v9);
  else
    v10 = 0i64;
  this->mCriticalBucket = v10;
  UFG::ResourcePriorityBucket::AddChild(this->mMasterBucket, v10);
  v11 = UFG::qMalloc(0x58ui64, "ResourcePriorityBucket", 0i64);
  if ( v11 )
    UFG::ResourcePriorityBucket::ResourcePriorityBucket((UFG::ResourcePriorityBucket *)v11);
  else
    v12 = 0i64;
  this->mHighBucket = v12;
  UFG::ResourcePriorityBucket::AddChild(this->mMasterBucket, v12);
  v13 = UFG::qMalloc(0x58ui64, "ResourcePriorityBucket", 0i64);
  if ( v13 )
    UFG::ResourcePriorityBucket::ResourcePriorityBucket((UFG::ResourcePriorityBucket *)v13);
  else
    v14 = 0i64;
  this->mLowBucket = v14;
  UFG::ResourcePriorityBucket::AddChild(this->mMasterBucket, v14);
  UFG::ResourcePriorityBucket::UpdateSize(this->mMasterBucket);
  mMasterBucket = this->mMasterBucket;
  mMasterBucket->mPriority = 0;
  for ( i = 0; i < mMasterBucket->mChildren.size; ++i )
  {
    v3 += i + 1;
    UFG::ResourcePriorityBucket::UpdatePriority(mMasterBucket->mChildren.p[i], v3);
  }
}

// File Line: 275
// RVA: 0x43E2D0
void __fastcall UFG::ResourcePool::Init(
        UFG::ResourcePool *this,
        UFG::StreamingMemory::DATA_TYPE streamingPool,
        UFG::StreamingMemory::DATA_TYPE streamingPoolVRam,
        UFG::qArray<UFG::EntityTypeState *,0> *resourceDescriptorList)
{
  UFG::ResourcePool *v7; // r13
  UFG::qArray<UFG::EntityTypeState *,0> *p_mEntityStates; // rdi
  __int64 v9; // rbp
  __int64 size; // r15
  unsigned int v11; // esi
  unsigned int capacity; // ebx
  unsigned int v13; // ebx
  unsigned __int64 v14; // rax
  UFG::allocator::free_link *v15; // rax
  UFG::EntityTypeState **v16; // r14
  __int64 i; // r9
  unsigned int v18; // eax
  int v19; // edi
  __int64 v20; // rax
  unsigned __int64 v21; // kr00_8
  bool v22; // cf
  unsigned __int64 v23; // rax
  UFG::allocator::free_link *v24; // rax
  UFG::qArray<UFG::PreloadRequest *,0> *v25; // rbx
  unsigned int j; // esi
  __int64 v27; // rbx
  unsigned __int64 v28; // rax
  UFG::allocator::free_link *v29; // rax
  UFG::allocator::free_link *v30; // rdi
  __int64 k; // r9
  UFG::EntityTypeState **p; // [rsp+98h] [rbp+20h]

  v7 = this;
  this->mMaxModelMemory = (int)(float)((float)(int)UFG::PartDatabase::Instance()->mPool.mMaxModelMemory * 0.94999999);
  v7->mMaxTextureMemory = (int)(float)((float)(int)UFG::PartDatabase::Instance()->mPool.mMaxTextureMemory * 0.94999999);
  v7->mStreamingPoolId = streamingPool;
  v7->mStreamingPoolIdVRam = streamingPoolVRam;
  *(_QWORD *)&v7->mAmbientModelMemoryLimit = 0i64;
  p_mEntityStates = &v7->mEntityStates;
  if ( resourceDescriptorList->size > v7->mEntityStates.capacity )
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
      (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&v7->mEntityStates,
      resourceDescriptorList->size,
      "ResourcePool");
  v9 = 0i64;
  if ( resourceDescriptorList->size )
  {
    do
    {
      p = resourceDescriptorList->p;
      size = p_mEntityStates->size;
      v11 = size + 1;
      capacity = v7->mEntityStates.capacity;
      if ( (int)size + 1 > capacity )
      {
        if ( capacity )
          v13 = 2 * capacity;
        else
          v13 = 1;
        for ( ; v13 < v11; v13 *= 2 )
          ;
        if ( v13 <= 2 )
          v13 = 2;
        if ( v13 - v11 > 0x10000 )
          v13 = size + 65537;
        if ( v13 != (_DWORD)size )
        {
          v14 = 8i64 * v13;
          if ( !is_mul_ok(v13, 8ui64) )
            v14 = -1i64;
          v15 = UFG::qMalloc(v14, "qArray.Add", 0i64);
          v16 = (UFG::EntityTypeState **)v15;
          if ( v7->mEntityStates.p )
          {
            for ( i = 0i64; (unsigned int)i < p_mEntityStates->size; i = (unsigned int)(i + 1) )
              v15[i] = (UFG::allocator::free_link)v7->mEntityStates.p[i];
            operator delete[](v7->mEntityStates.p);
          }
          v7->mEntityStates.p = v16;
          v7->mEntityStates.capacity = v13;
        }
      }
      p_mEntityStates->size = v11;
      v7->mEntityStates.p[size] = p[v9];
      v9 = (unsigned int)(v9 + 1);
    }
    while ( (unsigned int)v9 < resourceDescriptorList->size );
    v7 = this;
  }
  v18 = resourceDescriptorList->size + 3;
  v7->mNumPreloadBuckets = v18;
  v19 = v18;
  v21 = v18;
  v20 = 16i64 * v18;
  if ( !is_mul_ok(v21, 0x10ui64) )
    v20 = -1i64;
  v22 = __CFADD__(v20, 8i64);
  v23 = v20 + 8;
  if ( v22 )
    v23 = -1i64;
  v24 = UFG::qMalloc(v23, "qArray", 0i64);
  if ( v24 )
  {
    LODWORD(v24->mNext) = v19;
    v25 = (UFG::qArray<UFG::PreloadRequest *,0> *)&v24[1];
    `eh vector constructor iterator(
      &v24[1],
      0x10ui64,
      v19,
      (void (__fastcall *)(void *))UFG::qArray<UFG::qSymbolUC,0>::qArray<UFG::qSymbolUC,0>);
  }
  else
  {
    v25 = 0i64;
  }
  v7->mPreloadBuckets = v25;
  for ( j = 0; j < v7->mNumPreloadBuckets; ++j )
  {
    v27 = (__int64)&v7->mPreloadBuckets[j];
    if ( *(_DWORD *)(v27 + 4) < 0x20u && *(_DWORD *)v27 != 32 )
    {
      v28 = 256i64;
      if ( !is_mul_ok(0x20ui64, 8ui64) )
        v28 = -1i64;
      v29 = UFG::qMalloc(v28, "ResourcePool", 0i64);
      v30 = v29;
      if ( *(_QWORD *)(v27 + 8) )
      {
        for ( k = 0i64; (unsigned int)k < *(_DWORD *)v27; k = (unsigned int)(k + 1) )
          v29[k] = *(UFG::allocator::free_link *)(*(_QWORD *)(v27 + 8) + 8 * k);
        operator delete[](*(void **)(v27 + 8));
      }
      *(_QWORD *)(v27 + 8) = v30;
      *(_DWORD *)(v27 + 4) = 32;
    }
  }
}

// File Line: 316
// RVA: 0x4459D0
void __fastcall UFG::ResourcePool::UpdateBuckets(UFG::ResourcePool *this)
{
  UFG::ResourcePool *v1; // r13
  UFG::ResourcePool *mNext; // r15
  UFG::qList<UFG::ResourceRequest,UFG::ResourceRequest,1,0> *p_mRequestList; // r13
  UFG::ResourceRequest **p; // r12
  unsigned int v5; // ecx
  _DWORD *v6; // rax
  __int64 v7; // rdx
  __int64 v8; // rdi
  __int64 v9; // r14
  unsigned int v10; // ebx
  unsigned int v11; // esi
  unsigned int v12; // ebx
  unsigned __int64 v13; // rax
  UFG::allocator::free_link *v14; // rax
  UFG::allocator::free_link *v15; // rbp
  __int64 i; // r9
  __int64 v17; // r8
  __int64 v18; // rax
  __int64 v19[6]; // [rsp+20h] [rbp-68h]

  v1 = this;
  this->mUnReferencedBucket->mResourceRequests.size = 0;
  this->mReservedBucket->mResourceRequests.size = 0;
  this->mCriticalBucket->mResourceRequests.size = 0;
  this->mHighBucket->mResourceRequests.size = 0;
  this->mLowBucket->mResourceRequests.size = 0;
  mNext = (UFG::ResourcePool *)this->mRequestList.mNode.mNext;
  v19[0] = (__int64)this->mUnReferencedBucket;
  v19[1] = (__int64)this->mReservedBucket;
  v19[2] = (__int64)this->mCriticalBucket;
  v19[3] = (__int64)this->mHighBucket;
  v19[4] = (__int64)this->mLowBucket;
  if ( mNext != (UFG::ResourcePool *)&this->mRequestList )
  {
    p_mRequestList = &this->mRequestList;
    do
    {
      p = mNext->mQueued.p;
      v5 = 0;
      v6 = (_DWORD *)&mNext->mRequestList.mNode.mPrev + 1;
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
      v9 = *(unsigned int *)(v8 + 72);
      v10 = *(_DWORD *)(v8 + 76);
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
          if ( *(_QWORD *)(v8 + 80) )
          {
            for ( i = 0i64;
                  (unsigned int)i < *(_DWORD *)(v8 + 72);
                  v14[v17] = *(UFG::allocator::free_link *)(v17 * 8 + *(_QWORD *)(v8 + 80)) )
            {
              v17 = i;
              i = (unsigned int)(i + 1);
            }
            operator delete[](*(void **)(v8 + 80));
          }
          *(_QWORD *)(v8 + 80) = v15;
          *(_DWORD *)(v8 + 76) = v12;
        }
      }
      v18 = *(_QWORD *)(v8 + 80);
      *(_DWORD *)(v8 + 72) = v11;
      *(_QWORD *)(v18 + 8 * v9) = mNext;
      mNext = (UFG::ResourcePool *)p;
    }
    while ( p != (UFG::ResourceRequest **)p_mRequestList );
    v1 = this;
  }
  UFG::ResourcePriorityBucket::UpdateSize(v1->mMasterBucket);
}

// File Line: 344
// RVA: 0x443420
bool __fastcall UFG::SortQueuedRequests(UFG::ResourceRequest *reqA, UFG::ResourceRequest *reqB)
{
  unsigned int *mPriorityRefCounts; // rax
  unsigned int v3; // r8d
  unsigned int v4; // r9d

  mPriorityRefCounts = reqB->mPriorityRefCounts;
  v3 = 0;
  while ( 1 )
  {
    v4 = *(unsigned int *)((char *)mPriorityRefCounts + (char *)reqA - (char *)reqB);
    if ( v4 != *mPriorityRefCounts )
      break;
    ++v3;
    ++mPriorityRefCounts;
    if ( v3 >= 5 )
      return reqA->mResource->mModelSize + reqA->mResource->mTextureSize < reqB->mResource->mModelSize
                                                                         + reqB->mResource->mTextureSize;
  }
  return v4 > *mPriorityRefCounts;
}

// File Line: 356
// RVA: 0x447110
void __fastcall UFG::ResourcePool::UpdateRequests(UFG::ResourcePool *this)
{
  unsigned int size; // eax
  char IsStalled; // al
  __int64 v4; // rsi
  UFG::qPropertySet **v5; // rdi
  Render::IrradianceVolume *dest[513]; // [rsp+20h] [rbp-1008h] BYREF
  UFG::StreamingMemory::DATA_TYPE dataTypes; // [rsp+1030h] [rbp+8h] BYREF
  UFG::StreamingMemory::DATA_TYPE mStreamingPoolIdVRam; // [rsp+1034h] [rbp+Ch]

  if ( this->mDirty )
    UFG::ResourcePool::UpdateBuckets(this);
  size = this->mLoading.size;
  this->mStreamerStalled = 0;
  if ( this->mQueued.size + size )
  {
    dataTypes = this->mStreamingPoolId;
    mStreamingPoolIdVRam = this->mStreamingPoolIdVRam;
    IsStalled = UFG::DataStreamer::IsStalled(&dataTypes, 2u);
    this->mStreamerStalled = IsStalled;
    if ( !IsStalled )
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
          UFG::ResourcePool::QueueRequest(this, *v5++);
          --v4;
        }
        while ( v4 );
        UFG::ResourcePriorityBucket::UpdateSize(this->mMasterBucket);
      }
    }
  }
}

// File Line: 400
// RVA: 0x43CE40
void __fastcall UFG::ResourcePool::FlushResources(UFG::ResourcePool *this, bool forceFlush)
{
  float mFragmentationReservePercentage; // xmm1_4
  bool v3; // r14
  unsigned int v5; // edi
  unsigned int v6; // ebx
  UFG::ResourcePriorityBucket *mMasterBucket; // rax
  unsigned int v8; // r13d
  unsigned int v9; // r12d
  UFG::ResourcePriorityBucket *mUnReferencedBucket; // rcx
  __int64 size; // rax
  unsigned int v12; // ebp
  __int64 v13; // r15
  unsigned int v14; // edx
  UFG::ResourceRequest *v15; // r14
  __int64 v16; // rcx
  UFG::TrueCrowdResource *mResource; // rax
  UFG::ResourceRequest **p; // r8
  unsigned int v19; // edx
  __int64 v20; // rcx
  UFG::ResourceRequest **v21; // r8
  unsigned int v22; // eax
  unsigned int v23; // edx
  __int64 v24; // rcx
  UFG::ResourceRequest **v25; // r8
  unsigned int v26; // eax
  UFG::TrueCrowdResource *v27; // rax
  unsigned int mTextureSize; // edi
  unsigned int mModelSize; // ebx
  UFG::PartDatabase *v30; // rax
  UFG::qNode<UFG::ResourceRequest,UFG::ResourceRequest> *mPrev; // rdx
  UFG::qNode<UFG::ResourceRequest,UFG::ResourceRequest> *mNext; // rax
  bool v33; // zf
  unsigned int v34; // [rsp+70h] [rbp+8h]
  unsigned int v36; // [rsp+80h] [rbp+18h]
  unsigned int v37; // [rsp+88h] [rbp+20h]

  mFragmentationReservePercentage = this->mFragmentationReservePercentage;
  v3 = forceFlush;
  v5 = this->mMaxModelMemory - (int)(float)((float)(int)this->mMaxModelMemory * mFragmentationReservePercentage);
  v37 = v5;
  v6 = this->mMaxTextureMemory - (int)(float)((float)(int)this->mMaxTextureMemory * mFragmentationReservePercentage);
  mMasterBucket = this->mMasterBucket;
  v36 = v6;
  v8 = mMasterBucket->mMemoryUsage[0][1] + mMasterBucket->mMemoryUsage[1][1] + mMasterBucket->mMemoryUsage[2][1];
  v9 = mMasterBucket->mMemoryUsage[0][0] + mMasterBucket->mMemoryUsage[1][0] + mMasterBucket->mMemoryUsage[2][0];
  if ( forceFlush || this->mStreamerStalled || v8 > v5 || v9 > v6 )
  {
    if ( this->mDirty )
      UFG::ResourcePool::UpdateBuckets(this);
    mUnReferencedBucket = this->mUnReferencedBucket;
    size = (int)mUnReferencedBucket->mResourceRequests.size;
    if ( (_DWORD)size )
      UFG::qQuickSortImpl<Render::Light *,bool (*)(Render::Light const *,Render::Light const *)>(
        (Render::IrradianceVolume **)mUnReferencedBucket->mResourceRequests.p,
        (Render::IrradianceVolume **)&mUnReferencedBucket->mResourceRequests.p[size - 1],
        (bool (__fastcall *)(Render::IrradianceVolume *, Render::IrradianceVolume *))UFG::SortByReferenceFramePredicate);
    v12 = 0;
    v34 = this->mUnReferencedBucket->mResourceRequests.size;
    if ( v34 )
    {
      v13 = 0i64;
      do
      {
        if ( !v3 && !this->mStreamerStalled && v8 <= v5 && v9 <= v6 )
          break;
        v14 = this->mQueued.size;
        v15 = this->mUnReferencedBucket->mResourceRequests.p[v13];
        v16 = 0i64;
        mResource = v15->mResource;
        v8 -= mResource->mModelSize;
        v9 -= mResource->mTextureSize;
        if ( this->mQueued.size )
        {
          p = this->mQueued.p;
          while ( v15 != p[v16] )
          {
            v16 = (unsigned int)(v16 + 1);
            if ( (unsigned int)v16 >= v14 )
              goto LABEL_24;
          }
          if ( (int)v16 >= 0 )
          {
            p[v16] = p[v14 - 1];
            if ( this->mQueued.size > 1 )
              --this->mQueued.size;
            else
              this->mQueued.size = 0;
          }
        }
LABEL_24:
        v19 = this->mLoading.size;
        v20 = 0i64;
        if ( v19 )
        {
          v21 = this->mLoading.p;
          while ( v15 != v21[v20] )
          {
            v20 = (unsigned int)(v20 + 1);
            if ( (unsigned int)v20 >= v19 )
              goto LABEL_33;
          }
          if ( (int)v20 >= 0 )
          {
            v21[v20] = v21[v19 - 1];
            v22 = this->mLoading.size;
            if ( v22 > 1 )
              this->mLoading.size = v22 - 1;
            else
              this->mLoading.size = 0;
          }
        }
LABEL_33:
        v23 = this->mLoaded.size;
        v24 = 0i64;
        if ( v23 )
        {
          v25 = this->mLoaded.p;
          while ( v15 != v25[v24] )
          {
            v24 = (unsigned int)(v24 + 1);
            if ( (unsigned int)v24 >= v23 )
              goto LABEL_42;
          }
          if ( (int)v24 >= 0 )
          {
            v25[v24] = v25[v23 - 1];
            v26 = this->mLoaded.size;
            if ( v26 > 1 )
              this->mLoaded.size = v26 - 1;
            else
              this->mLoaded.size = 0;
          }
        }
LABEL_42:
        v27 = v15->mResource;
        mTextureSize = v27->mTextureSize;
        mModelSize = v27->mModelSize;
        v30 = UFG::PartDatabase::Instance();
        v30->mPool.mExternalUsedModelMemory -= mModelSize;
        v30->mPool.mExternalUsedTextureMemory -= mTextureSize;
        v15->mResource->mRequest = 0i64;
        v15->mResource = 0i64;
        UFG::DataStreamer::ReleaseStream(&v15->mDataStreamerHandle);
        mPrev = v15->mPrev;
        mNext = v15->mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        v15->mPrev = v15;
        v15->mNext = v15;
        UFG::ResourceRequest::~ResourceRequest(v15);
        operator delete[](v15);
        v33 = !this->mStreamerStalled;
        this->mDirty = 1;
        if ( !v33 )
        {
          if ( v12 )
            break;
        }
        v6 = v36;
        v5 = v37;
        v3 = forceFlush;
        ++v12;
        ++v13;
      }
      while ( v12 < v34 );
    }
  }
}

// File Line: 499
// RVA: 0x441020
void __fastcall UFG::ResourcePool::QueueRequest(UFG::ResourcePool *this, UFG::qPropertySet *pRequest)
{
  unsigned int *v4; // r8
  unsigned int v5; // eax
  UFG::DataStreamer::PRIORITY v6; // esi
  unsigned int v7; // eax
  unsigned int v8; // eax
  bool v9; // zf
  unsigned int size; // edx
  __int64 v11; // rcx
  UFG::ResourceRequest **p; // r8
  UFG::StreamingMemory::DATA_TYPE mStreamingPoolId; // r8d
  unsigned int flags; // eax
  UFG::TrueCrowdResource *mOffset; // rax
  unsigned int mTextureSize; // edi
  unsigned int mModelSize; // ebx
  UFG::PartDatabase *v18; // rax
  char dest[128]; // [rsp+40h] [rbp-88h] BYREF
  UFG::qPropertySet *item; // [rsp+D8h] [rbp+10h] BYREF

  UFG::qSPrintf(dest, "%s.perm.bin", (const char *)&pRequest[2]);
  v4 = (unsigned int *)&pRequest[1].mOwner.mOffset + 1;
  v5 = 0;
  while ( !*v4 )
  {
    ++v5;
    ++v4;
    if ( v5 >= 5 )
    {
      v5 = 0;
      break;
    }
  }
  v6 = DEFAULT_PRIORITY;
  v7 = v5 - 1;
  if ( v7 && (v8 = v7 - 1) != 0 )
  {
    if ( v8 == 1 )
      v6 = 12286;
  }
  else
  {
    v6 = 12287;
  }
  v9 = HIDWORD(pRequest->mPrev) == 2;
  item = pRequest;
  if ( !v9 )
  {
    size = this->mQueued.size;
    v11 = 0i64;
    if ( this->mQueued.size )
    {
      p = this->mQueued.p;
      while ( pRequest != (UFG::qPropertySet *)p[v11] )
      {
        v11 = (unsigned int)(v11 + 1);
        if ( (unsigned int)v11 >= size )
          goto LABEL_20;
      }
      if ( (int)v11 >= 0 )
      {
        p[v11] = p[size - 1];
        if ( this->mQueued.size > 1 )
          --this->mQueued.size;
        else
          this->mQueued.size = 0;
      }
    }
LABEL_20:
    UFG::qArray<UFG::PedSpawningInfo *,0>::Add(
      (UFG::qArray<UFG::qPropertySet *,0> *)&this->mLoading,
      &item,
      "qArray.Add");
    HIDWORD(pRequest->mPrev) = 2;
    this->mDirty = 1;
  }
  if ( LODWORD(pRequest->mNext) )
    mStreamingPoolId = this->mStreamingPoolId;
  else
    mStreamingPoolId = this->mStreamingPoolIdVRam;
  flags = 3;
  if ( !*(_DWORD *)(pRequest->mParents.mOffset + 36) )
    flags = 0;
  UFG::DataStreamer::QueueStream(
    (UFG::DataStreamer::Handle *)&pRequest[1].mValues,
    dest,
    mStreamingPoolId,
    v6,
    flags,
    UFG::ResourcePool::ResourceHasBeenLoaded,
    pRequest);
  mOffset = (UFG::TrueCrowdResource *)pRequest->mParents.mOffset;
  mTextureSize = mOffset->mTextureSize;
  mModelSize = mOffset->mModelSize;
  v18 = UFG::PartDatabase::Instance();
  v18->mPool.mExternalUsedModelMemory += mModelSize;
  v18->mPool.mExternalUsedTextureMemory += mTextureSize;
}

// File Line: 543
// RVA: 0x442EA0
void __fastcall UFG::ResourcePool::ResourceHasBeenLoaded(
        UFG::DataStreamer::Handle *handle,
        UFG::ResourceRequest *callbackParam)
{
  UFG::ResourceRequest::OnLoaded(callbackParam);
  UFG::ResourcePool::ResourceLoadNotification(&UFG::ObjectResourceManager::sInstance->mPool, callbackParam);
}

// File Line: 552
// RVA: 0x442ED0
void __fastcall UFG::ResourcePool::ResourceLoadNotification(UFG::ResourcePool *this, UFG::qPropertySet *pRequest)
{
  bool v2; // zf
  unsigned int size; // edx
  __int64 v6; // rax
  UFG::ResourceRequest **p; // r8
  unsigned int v8; // eax
  UFG::qPropertySet *item; // [rsp+38h] [rbp+10h] BYREF

  v2 = HIDWORD(pRequest->mPrev) == 3;
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
    HIDWORD(pRequest->mPrev) = 3;
    this->mDirty = 1;
  }
}

// File Line: 600
// RVA: 0x442600
UFG::ResourceRequest *__fastcall UFG::ResourcePool::RequestLoadResource(
        UFG::ResourcePool *this,
        UFG::TrueCrowdResource *resource,
        bool isTexture,
        int *priority,
        UFG::ResourceUser *user)
{
  unsigned int mUID; // ebx
  int v9; // eax
  UFG::PriorityBucket::Type v10; // esi
  UFG::ResourceRequest *mNext; // rdi
  UFG::ResourceRequest *p_mRequestList; // r14
  UFG::allocator::free_link *v13; // rax
  UFG::ResourceRequest::Type v14; // r15d
  UFG::ResourceRequest *v15; // rax
  UFG::qNode<UFG::ResourceRequest,UFG::ResourceRequest> *mPrev; // rax
  UFG::qPropertySet *item; // [rsp+60h] [rbp+8h] BYREF

  mUID = resource->mPathSymbol.mUID;
  v9 = *priority;
  if ( *priority == qSymbol_Critical.mUID )
  {
    v10 = Critical;
  }
  else if ( v9 == qSymbol_High.mUID )
  {
    v10 = High;
  }
  else if ( v9 == qSymbol_Medium.mUID || v9 == qSymbol_Low.mUID )
  {
    v10 = Low;
  }
  else
  {
    v10 = Low;
    if ( v9 == qSymbol_Reserved.mUID )
      v10 = Reserved;
  }
  mNext = (UFG::ResourceRequest *)this->mRequestList.mNode.mNext;
  p_mRequestList = (UFG::ResourceRequest *)&this->mRequestList;
  if ( mNext != (UFG::ResourceRequest *)&this->mRequestList )
  {
    while ( mNext->mAssetSymbol.mUID != mUID )
    {
      mNext = (UFG::ResourceRequest *)mNext->mNext;
      if ( mNext == p_mRequestList )
        goto LABEL_16;
    }
    UFG::ResourceRequest::AddDependency(mNext, v10, user);
    goto LABEL_21;
  }
LABEL_16:
  v13 = UFG::qMalloc(0xE0ui64, "ResourceRequest", 0i64);
  item = (UFG::qPropertySet *)v13;
  v14 = Texture;
  if ( v13 )
  {
    UFG::ResourceRequest::ResourceRequest((UFG::ResourceRequest *)v13);
    mNext = v15;
  }
  else
  {
    mNext = 0i64;
  }
  UFG::TrueCrowdResource::GetPath(resource, mNext->mAssetName, 48);
  mNext->mAssetSymbol.mUID = mUID;
  mNext->mResource = resource;
  resource->mRequest = mNext;
  LOBYTE(v14) = !isTexture;
  mNext->mType = v14;
  UFG::ResourceRequest::AddDependency(mNext, v10, user);
  mPrev = p_mRequestList->mPrev;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  mNext->mNext = p_mRequestList;
  p_mRequestList->mPrev = mNext;
  item = (UFG::qPropertySet *)mNext;
  if ( mNext->mLoadStatus != Queued )
  {
    UFG::qArray<UFG::PedSpawningInfo *,0>::Add((UFG::qArray<UFG::qPropertySet *,0> *)this, &item, "qArray.Add");
    mNext->mLoadStatus = Queued;
LABEL_21:
    this->mDirty = 1;
  }
  return mNext;
}

// File Line: 629
// RVA: 0x442C10
void __fastcall UFG::ResourcePool::RequestUnLoadResource(
        UFG::ResourcePool *this,
        UFG::TrueCrowdResource *resource,
        int *priority,
        UFG::ResourceUser *user)
{
  UFG::ResourceRequest *v5; // rcx
  UFG::ResourcePool *mNext; // rax
  unsigned int mUID; // edx
  int v8; // eax
  UFG::PriorityBucket::Type v9; // edx

  v5 = 0i64;
  mNext = (UFG::ResourcePool *)this->mRequestList.mNode.mNext;
  if ( mNext != (UFG::ResourcePool *)&this->mRequestList )
  {
    mUID = resource->mPathSymbol.mUID;
    while ( mNext->mLoading.size != mUID )
    {
      mNext = (UFG::ResourcePool *)mNext->mQueued.p;
      if ( mNext == (UFG::ResourcePool *)&this->mRequestList )
        goto LABEL_7;
    }
    v5 = (UFG::ResourceRequest *)mNext;
  }
LABEL_7:
  v8 = *priority;
  if ( *priority == qSymbol_Critical.mUID )
  {
    v9 = Critical;
  }
  else if ( v8 == qSymbol_High.mUID )
  {
    v9 = High;
  }
  else if ( v8 == qSymbol_Medium.mUID || v8 == qSymbol_Low.mUID )
  {
    v9 = Low;
  }
  else
  {
    v9 = Low;
    if ( v8 == qSymbol_Reserved.mUID )
      v9 = Reserved;
  }
  UFG::ResourceRequest::RemoveDependency(v5, v9, user);
  this->mDirty = 1;
}

// File Line: 639
// RVA: 0x442250
void __fastcall UFG::ResourcePool::RemovePreloadReferences(UFG::ResourcePool *this, UFG::ResourceRequest *request)
{
  __int64 v4; // rsi
  UFG::qList<UFG::ResourceRequest,UFG::ResourceRequest,1,0> *p_mRequestList; // rdi
  UFG::PreloadRequest *v6; // rbx
  UFG::qSymbol *Priority; // rax
  UFG::ResourceRequest *v8; // r9
  UFG::qNode<UFG::ResourceRequest,UFG::ResourceRequest> *mNext; // rcx
  unsigned int mUID; // eax
  UFG::PriorityBucket::Type v11; // edx
  UFG::ResourceUser dependency; // [rsp+28h] [rbp-40h] BYREF
  UFG::qSymbol result; // [rsp+78h] [rbp+10h] BYREF
  UFG::qSymbol *p_result; // [rsp+80h] [rbp+18h]

  v4 = 0i64;
  if ( request->mPreloads.size )
  {
    p_result = &result;
    p_mRequestList = &this->mRequestList;
    do
    {
      v6 = request->mPreloads.p[v4];
      Priority = UFG::PreloadRequest::GetPriority(v6, &result);
      dependency.mMeshLoader = (UFG::MeshResourceLoader *)v6;
      dependency.mType = Preload;
      v8 = 0i64;
      mNext = this->mRequestList.mNode.mNext;
      if ( mNext != (UFG::qNode<UFG::ResourceRequest,UFG::ResourceRequest> *)p_mRequestList )
      {
        while ( LODWORD(mNext[1].mPrev) != request->mResource->mPathSymbol.mUID )
        {
          mNext = mNext->mNext;
          if ( mNext == (UFG::qNode<UFG::ResourceRequest,UFG::ResourceRequest> *)p_mRequestList )
            goto LABEL_8;
        }
        v8 = (UFG::ResourceRequest *)mNext;
      }
LABEL_8:
      mUID = Priority->mUID;
      if ( mUID == qSymbol_Critical.mUID )
      {
        v11 = Critical;
      }
      else if ( mUID == qSymbol_High.mUID )
      {
        v11 = High;
      }
      else if ( mUID == qSymbol_Medium.mUID || mUID == qSymbol_Low.mUID )
      {
        v11 = Low;
      }
      else
      {
        v11 = Low;
        if ( mUID == qSymbol_Reserved.mUID )
          v11 = Reserved;
      }
      UFG::ResourceRequest::RemoveDependency(v8, v11, &dependency);
      this->mDirty = 1;
      v4 = (unsigned int)(v4 + 1);
    }
    while ( (unsigned int)v4 < request->mPreloads.size );
  }
}

// File Line: 648
// RVA: 0x441A60
void __fastcall UFG::ResourcePool::ReleaseResourceSetFiles(UFG::ResourcePool *this, UFG::PreloadRequest *request)
{
  UFG::TrueCrowdSet *mSet; // r9
  bool v5; // r10
  __int64 v6; // rdx
  unsigned int v7; // ecx
  UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *v8; // rdi
  __int64 mNext_low; // rcx
  UFG::TrueCrowdModel *v10; // rbx
  UFG::ResourceRequest *v11; // r8
  unsigned int v12; // ecx
  unsigned int v13; // edx
  UFG::PreloadRequest **v14; // r8
  unsigned int v15; // eax
  __int64 v16; // rcx
  char *v17; // rdx
  __int64 v18; // r8
  char *v19; // rax
  __int64 v20; // rdx
  char *v21; // rax
  __int64 v22; // rax
  __int64 v23; // rcx
  __int64 v24; // rax
  __int64 v25; // rax
  __int64 v26; // rax
  unsigned int v27; // ecx
  unsigned int v28; // edx
  unsigned int v29; // r8d
  __int64 v30; // rcx
  char *v31; // rcx
  char *v32; // rdx
  UFG::TrueCrowdResource *v33; // rdx
  unsigned int v34; // r12d
  UFG::qArray<UFG::TrueCrowdModel *,0> *v35; // r13
  UFG::TrueCrowdModel ***p_p; // rax
  UFG::TrueCrowdModel *v37; // r14
  UFG::ResourceRequest *mRequest; // rax
  unsigned int v39; // ecx
  unsigned int size; // edx
  UFG::qSymbol *Priority; // rax
  UFG::ResourceRequest *v42; // r9
  UFG::ResourcePool *mNext; // rcx
  unsigned int mUID; // eax
  UFG::PriorityBucket::Type v45; // edx
  unsigned int v46; // edi
  __int64 mOffset; // rcx
  __int64 v48; // rdx
  __int64 v49; // rbx
  __int64 v50; // rax
  __int64 v51; // rdx
  __int64 v52; // rax
  __int64 v53; // rax
  __int64 v54; // rcx
  __int64 v55; // rax
  __int64 v56; // rdx
  __int64 v57; // rcx
  unsigned int v58; // eax
  unsigned int v59; // edx
  UFG::qSymbol *v60; // r10
  __int64 v61; // rcx
  __int64 v62; // rcx
  UFG::ResourceRequest *v63; // r9
  __int64 v64; // rax
  __int64 v65; // rcx
  __int64 v66; // rdx
  UFG::ResourcePool *p; // rax
  unsigned int v68; // eax
  UFG::PriorityBucket::Type v69; // edx
  __int64 v70; // [rsp+20h] [rbp-59h]
  UFG::TrueCrowdModel ***v71; // [rsp+28h] [rbp-51h]
  UFG::qSymbol v72; // [rsp+30h] [rbp-49h] BYREF
  UFG::qSymbol v73; // [rsp+34h] [rbp-45h] BYREF
  UFG::qSymbol v74; // [rsp+38h] [rbp-41h] BYREF
  UFG::qSymbol result; // [rsp+3Ch] [rbp-3Dh] BYREF
  UFG::TrueCrowdSet *v76; // [rsp+40h] [rbp-39h]
  UFG::qArray<UFG::TrueCrowdModel *,0> *v77; // [rsp+48h] [rbp-31h]
  UFG::qSymbol *v78; // [rsp+50h] [rbp-29h]
  UFG::ResourceUser user; // [rsp+58h] [rbp-21h] BYREF
  UFG::ResourceUser v80; // [rsp+68h] [rbp-11h] BYREF
  UFG::ResourceUser dependency; // [rsp+78h] [rbp-1h] BYREF
  UFG::ResourceUser v82; // [rsp+88h] [rbp+Fh] BYREF
  __int64 v83; // [rsp+98h] [rbp+1Fh]
  bool v84; // [rsp+E8h] [rbp+6Fh]
  unsigned int mComponentCount; // [rsp+F0h] [rbp+77h]
  unsigned int v86; // [rsp+F8h] [rbp+7Fh]

  v83 = -2i64;
  if ( request->mPreloadActive )
  {
    mSet = request->mInstance.mSet;
    v76 = mSet;
    v5 = !request->mIsSet;
    v84 = v5;
    mComponentCount = UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition.mEntities[mSet->mEntityIndex].mComponentCount;
    v86 = 0;
    v6 = 0i64;
    v70 = 0i64;
    if ( mComponentCount )
    {
      v7 = UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition.mEntities[mSet->mEntityIndex].mComponentCount;
      while ( !v5 )
      {
        v34 = 0;
        v35 = &mSet->mFiles[v6];
        v77 = v35;
        if ( v35->size )
        {
          p_p = &mSet->mFiles[v6].p;
          v71 = p_p;
          do
          {
            v37 = (*p_p)[v34];
            mRequest = v37->mRequest;
            if ( mRequest )
            {
              v39 = 0;
              size = mRequest->mPreloads.size;
              if ( size )
              {
                while ( request != mRequest->mPreloads.p[v39] )
                {
                  if ( ++v39 >= size )
                    goto LABEL_66;
                }
                if ( v39 != -1 )
                {
                  v78 = &v74;
                  Priority = UFG::PreloadRequest::GetPriority(request, &v74);
                  dependency.mMeshLoader = (UFG::MeshResourceLoader *)request;
                  dependency.mType = Preload;
                  v42 = 0i64;
                  mNext = (UFG::ResourcePool *)this->mRequestList.mNode.mNext;
                  if ( mNext != (UFG::ResourcePool *)&this->mRequestList )
                  {
                    while ( mNext->mLoading.size != v37->mPathSymbol.mUID )
                    {
                      mNext = (UFG::ResourcePool *)mNext->mQueued.p;
                      if ( mNext == (UFG::ResourcePool *)&this->mRequestList )
                        goto LABEL_55;
                    }
                    v42 = (UFG::ResourceRequest *)mNext;
                  }
LABEL_55:
                  mUID = Priority->mUID;
                  if ( mUID == qSymbol_Critical.mUID )
                  {
                    v45 = Critical;
                  }
                  else if ( mUID == qSymbol_High.mUID )
                  {
                    v45 = High;
                  }
                  else if ( mUID == qSymbol_Medium.mUID || mUID == qSymbol_Low.mUID )
                  {
                    v45 = Low;
                  }
                  else
                  {
                    v45 = Low;
                    if ( mUID == qSymbol_Reserved.mUID )
                      v45 = Reserved;
                  }
                  UFG::ResourceRequest::RemoveDependency(v42, v45, &dependency);
                  this->mDirty = 1;
                }
              }
            }
LABEL_66:
            v46 = 0;
            if ( v37->mNumTextureSets )
            {
              do
              {
                mOffset = v37->mTextureSets.mOffset;
                if ( mOffset )
                  v48 = (__int64)&v37->mTextureSets + mOffset;
                else
                  v48 = 0i64;
                v49 = 8i64 * v46;
                v50 = v49 + v48;
                v51 = *(_QWORD *)(v49 + v48);
                if ( v51 )
                  v52 = v51 + v50;
                else
                  v52 = 0i64;
                if ( *(_QWORD *)(v52 + 8) )
                {
                  if ( mOffset )
                    v53 = (__int64)&v37->mTextureSets + mOffset;
                  else
                    v53 = 0i64;
                  v54 = v49 + v53;
                  v55 = *(_QWORD *)(v49 + v53);
                  v56 = v54 + v55;
                  if ( !v55 )
                    v56 = 0i64;
                  v57 = *(_QWORD *)(v56 + 8);
                  v58 = 0;
                  v59 = *(_DWORD *)(v57 + 56);
                  if ( v59 )
                  {
                    while ( request != *(UFG::PreloadRequest **)(*(_QWORD *)(v57 + 64) + 8i64 * v58) )
                    {
                      if ( ++v58 >= v59 )
                        goto LABEL_105;
                    }
                    if ( v58 != -1 )
                    {
                      v78 = &v72;
                      v60 = UFG::PreloadRequest::GetPriority(request, &v72);
                      v82.mMeshLoader = (UFG::MeshResourceLoader *)request;
                      v82.mType = Preload;
                      v61 = v37->mTextureSets.mOffset;
                      if ( v61 )
                      {
                        v62 = (__int64)&v37->mTextureSets + v61;
                        v63 = 0i64;
                      }
                      else
                      {
                        v63 = 0i64;
                        v62 = 0i64;
                      }
                      v64 = v49 + v62;
                      v65 = *(_QWORD *)(v49 + v62);
                      v66 = v65 + v64;
                      if ( !v65 )
                        v66 = 0i64;
                      p = (UFG::ResourcePool *)this->mRequestList.mNode.mNext;
                      if ( p != (UFG::ResourcePool *)&this->mRequestList )
                      {
                        while ( p->mLoading.size != *(_DWORD *)(v66 + 28) )
                        {
                          p = (UFG::ResourcePool *)p->mQueued.p;
                          if ( p == (UFG::ResourcePool *)&this->mRequestList )
                            goto LABEL_94;
                        }
                        v63 = (UFG::ResourceRequest *)p;
                      }
LABEL_94:
                      v68 = v60->mUID;
                      if ( v60->mUID == qSymbol_Critical.mUID )
                      {
                        v69 = Critical;
                      }
                      else if ( v68 == qSymbol_High.mUID )
                      {
                        v69 = High;
                      }
                      else if ( v68 == qSymbol_Medium.mUID || v68 == qSymbol_Low.mUID )
                      {
                        v69 = Low;
                      }
                      else
                      {
                        v69 = Low;
                        if ( v68 == qSymbol_Reserved.mUID )
                          v69 = Reserved;
                      }
                      UFG::ResourceRequest::RemoveDependency(v63, v69, &v82);
                      this->mDirty = 1;
                    }
                  }
                }
LABEL_105:
                ++v46;
              }
              while ( v46 < v37->mNumTextureSets );
              v35 = v77;
            }
            ++v34;
            p_p = v71;
          }
          while ( v34 < v35->size );
LABEL_108:
          v6 = v70;
LABEL_109:
          v7 = mComponentCount;
        }
        ++v86;
        v70 = ++v6;
        mSet = v76;
        v5 = v84;
        if ( v86 >= v7 )
          goto LABEL_111;
      }
      v8 = (UFG::PreloadRequest *)((char *)request + 16 * v6);
      mNext_low = LODWORD(v8[3].mNext);
      if ( (_DWORD)mNext_low != -1 )
      {
        v10 = mSet->mFiles[v6].p[mNext_low];
        v11 = v10->mRequest;
        if ( v11 )
        {
          v12 = 0;
          v13 = v11->mPreloads.size;
          if ( v13 )
          {
            v14 = v11->mPreloads.p;
            while ( request != v14[v12] )
            {
              if ( ++v12 >= v13 )
                goto LABEL_14;
            }
            if ( v12 != -1 )
            {
              v15 = (unsigned int)UFG::PreloadRequest::GetPriority(request, &result);
              user.mMeshLoader = (UFG::MeshResourceLoader *)request;
              user.mType = Preload;
              UFG::ResourcePool::RequestUnLoadResource(this, v10, (UFG::qSymbol)v15, &user);
            }
          }
LABEL_14:
          v6 = v70;
        }
        if ( v10->mNumTextureSets )
        {
          v16 = v10->mTextureSets.mOffset;
          if ( v16 )
            v17 = (char *)&v10->mTextureSets + v16;
          else
            v17 = 0i64;
          v18 = 8i64 * HIDWORD(v8[3].mNext);
          v19 = &v17[v18];
          v20 = *(_QWORD *)&v17[v18];
          if ( v20 )
            v21 = &v19[v20];
          else
            v21 = 0i64;
          if ( *((_QWORD *)v21 + 1) )
          {
            v22 = v16 ? (__int64)&v10->mTextureSets + v16 : 0i64;
            v23 = v18 + v22;
            v24 = *(_QWORD *)(v18 + v22);
            v25 = v24 ? v23 + v24 : 0i64;
            v26 = *(_QWORD *)(v25 + 8);
            if ( v26 )
            {
              v27 = 0;
              v28 = *(_DWORD *)(v26 + 56);
              if ( v28 )
              {
                while ( request != *(UFG::PreloadRequest **)(*(_QWORD *)(v26 + 64) + 8i64 * v27) )
                {
                  if ( ++v27 >= v28 )
                    goto LABEL_108;
                }
                if ( v27 != -1 )
                {
                  v29 = (unsigned int)UFG::PreloadRequest::GetPriority(request, &v73);
                  v80.mMeshLoader = (UFG::MeshResourceLoader *)request;
                  v80.mType = Preload;
                  v30 = v10->mTextureSets.mOffset;
                  if ( v30 )
                    v31 = (char *)&v10->mTextureSets + v30;
                  else
                    v31 = 0i64;
                  v32 = &v31[8 * HIDWORD(v8[3].mNext)];
                  if ( *(_QWORD *)v32 )
                    v33 = (UFG::TrueCrowdResource *)&v32[*(_QWORD *)v32];
                  else
                    v33 = 0i64;
                  UFG::ResourcePool::RequestUnLoadResource(this, v33, (UFG::qSymbol)v29, &v80);
                }
              }
            }
          }
          goto LABEL_108;
        }
      }
      goto LABEL_109;
    }
LABEL_111:
    request->mPreloadActive = 0;
  }
}

// File Line: 727
// RVA: 0x4416A0
void __fastcall UFG::ResourcePool::ReleaseAllUnReferencedPreloads(
        UFG::ResourcePool *this,
        unsigned int preloadBucketIndex,
        bool forceUnload)
{
  __int64 v4; // rbx
  signed int v6; // ebp
  __int64 v7; // rsi
  unsigned int size; // ebp
  UFG::PreloadRequest **p; // rcx
  UFG::PreloadRequest *v10; // rdi
  unsigned int v11; // r9d
  UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *mPrev; // rax
  UFG::qArray<UFG::PreloadRequest *,0> *mPreloadBuckets; // r8
  __int64 v14; // rdx
  unsigned int v15; // eax

  v4 = preloadBucketIndex;
  v6 = this->mPreloadBuckets[preloadBucketIndex].size - 1;
  v7 = v6;
  if ( v6 >= 0 )
  {
    size = this->mPreloadBuckets[preloadBucketIndex].size;
    do
    {
      p = this->mPreloadBuckets[v4].p;
      v10 = p[v7];
      if ( !v10->mSpawnSetValid && !v10->mDirectRequestCount || forceUnload )
      {
        UFG::ResourcePool::ReleaseResourceSetFiles(this, p[v7]);
        *(_QWORD *)&v10->mDesiredInstanceCount = 0i64;
        v10->mVarietyRatio = 0.0;
        v11 = size;
        mPrev = this->mEmptyRequestList.mNode.mPrev;
        mPrev->mNext = v10;
        v10->mPrev = mPrev;
        v10->mNext = &this->mEmptyRequestList.mNode;
        this->mEmptyRequestList.mNode.mPrev = v10;
        mPreloadBuckets = this->mPreloadBuckets;
        if ( size != mPreloadBuckets[v4].size )
        {
          v14 = 8 * v7 + 8;
          do
          {
            ++v11;
            v14 += 8i64;
            *(UFG::PreloadRequest **)((char *)mPreloadBuckets[v4].p + v14 - 16) = *(UFG::PreloadRequest **)((char *)mPreloadBuckets[v4].p + v14 - 8);
          }
          while ( v11 != mPreloadBuckets[v4].size );
        }
        v15 = mPreloadBuckets[v4].size;
        if ( v15 > 1 )
          mPreloadBuckets[v4].size = v15 - 1;
        else
          mPreloadBuckets[v4].size = 0;
      }
      --size;
      --v7;
    }
    while ( v7 >= 0 );
  }
}

// File Line: 748
// RVA: 0x43FC60
void __fastcall UFG::ResourcePool::PreloadInstance(
        UFG::ResourcePool *this,
        UFG::PreloadRequest *request,
        UFG::TrueCrowdSet::Instance *instance)
{
  unsigned int i; // ebx
  char *v7; // rsi
  __int64 v8; // rdx
  UFG::TrueCrowdModel *v9; // r14
  UFG::qSymbol *Priority; // rax
  UFG::qSymbol *v11; // r9
  __int64 mOffset; // rcx
  _QWORD *v13; // rdx
  UFG::TrueCrowdResource *v14; // rdx
  UFG::ResourceUser user; // [rsp+40h] [rbp-48h] BYREF
  UFG::ResourceUser v16; // [rsp+50h] [rbp-38h] BYREF
  UFG::qSymbol result; // [rsp+98h] [rbp+10h] BYREF
  UFG::qSymbol v18; // [rsp+A8h] [rbp+20h] BYREF

  if ( !request->mPreloadActive )
  {
    for ( i = 0; i < instance->mNumParts; ++i )
    {
      v7 = (char *)instance + 16 * i;
      v8 = *((unsigned int *)v7 + 6);
      if ( (_DWORD)v8 != -1 )
      {
        v9 = instance->mSet->mFiles[i].p[v8];
        Priority = UFG::PreloadRequest::GetPriority(request, &result);
        user.mMeshLoader = (UFG::MeshResourceLoader *)request;
        user.mType = Preload;
        UFG::ResourcePool::RequestLoadResource(this, v9, 0, (__int64)Priority, &user);
        if ( v9->mNumTextureSets )
        {
          v11 = UFG::PreloadRequest::GetPriority(request, &v18);
          v16.mMeshLoader = (UFG::MeshResourceLoader *)request;
          v16.mType = Preload;
          mOffset = v9->mTextureSets.mOffset;
          if ( mOffset )
            mOffset += (__int64)&v9->mTextureSets;
          v13 = (_QWORD *)(mOffset + 8i64 * *((unsigned int *)v7 + 7));
          if ( *v13 )
            v14 = (UFG::TrueCrowdResource *)((char *)v13 + *v13);
          else
            v14 = 0i64;
          UFG::ResourcePool::RequestLoadResource(this, v14, 1, (__int64)v11, &v16);
        }
      }
    }
    request->mPreloadActive = 1;
  }
}

// File Line: 824
// RVA: 0x43D530
__int64 __fastcall UFG::ResourcePool::GetContractableAmbientOptions(
        UFG::ResourcePool *this,
        unsigned int pool,
        UFG::ResourcePool::ContractionSortData *candidates,
        unsigned int *candidateCount)
{
  UFG::qArray<UFG::PreloadRequest *,0> *mPreloadBuckets; // rax
  __int64 v5; // rcx
  __int64 v6; // r12
  UFG::qArray<UFG::PreloadRequest *,0> *v7; // rdx
  UFG::PreloadRequest *v8; // r13
  unsigned int size; // esi
  char v10; // di
  unsigned int v11; // ebx
  unsigned int v12; // r14d
  UFG::TrueCrowdSet *mSet; // r9
  __int64 mComponentCount; // r15
  char *v15; // r10
  UFG::qArray<UFG::TrueCrowdModel *,0> *mFiles; // r9
  __int64 v17; // r11
  __int64 j; // r8
  UFG::ResourceRequest *mRequest; // rdx
  unsigned int v20; // ecx
  unsigned int *mPriorityRefCounts; // rax
  char v22; // al
  char *v23; // rcx
  __int64 v24; // rdx
  __int64 v25; // rcx
  __int64 i; // [rsp+10h] [rbp-59h]
  __int64 v28; // [rsp+18h] [rbp-51h]
  __int64 v29; // [rsp+20h] [rbp-49h]
  unsigned int textureMemory[2]; // [rsp+30h] [rbp-39h] BYREF
  unsigned int modelMemory[2]; // [rsp+38h] [rbp-31h] BYREF
  char dest[88]; // [rsp+40h] [rbp-29h] BYREF
  __int64 vars0; // [rsp+D0h] [rbp+67h]
  void *retaddr; // [rsp+D8h] [rbp+6Fh]
  _DWORD *v36; // [rsp+E8h] [rbp+7Fh]

  mPreloadBuckets = this->mPreloadBuckets;
  LOBYTE(candidates) = 0;
  v5 = pool;
  v6 = 0i64;
  LODWORD(retaddr) = (_DWORD)candidates;
  v7 = &mPreloadBuckets[v5];
  for ( i = v5 * 16;
        (unsigned int)v6 < v7->size;
        v7 = (UFG::qArray<UFG::PreloadRequest *,0> *)(i + *(_QWORD *)(vars0 + 136)) )
  {
    v8 = v7->p[v6];
    if ( v8->mPreloadActive )
    {
      size = -1;
      v10 = 0;
      v11 = -1;
      v12 = -1;
      UFG::qMemSet(dest, 0, 0x40u);
      mSet = v8->mInstance.mSet;
      mComponentCount = UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition.mEntities[mSet->mEntityIndex].mComponentCount;
      if ( (_DWORD)mComponentCount )
      {
        v15 = dest;
        mFiles = mSet->mFiles;
        v17 = (unsigned int)mComponentCount;
        do
        {
          for ( j = 0i64; (unsigned int)j < mFiles->size; j = (unsigned int)(j + 1) )
          {
            mRequest = mFiles->p[j]->mRequest;
            if ( mRequest )
            {
              v20 = 0;
              mPriorityRefCounts = mRequest->mPriorityRefCounts;
              while ( !*mPriorityRefCounts )
              {
                ++v20;
                ++mPriorityRefCounts;
                if ( v20 >= 5 )
                  goto LABEL_22;
              }
              if ( v20 == 4 )
              {
                if ( size == -1 || size > mRequest->mInstances.size )
                  size = mRequest->mInstances.size;
                if ( v11 == -1 || v11 > mRequest->mProxies.size )
                  v11 = mRequest->mProxies.size;
                if ( v11 == -1 || v12 > mRequest->mPreloads.size )
                  v12 = mRequest->mPreloads.size;
                ++*(_DWORD *)v15;
                v10 = 1;
              }
            }
LABEL_22:
            ;
          }
          ++mFiles;
          v15 += 4;
          --v17;
        }
        while ( v17 );
        mSet = v8->mInstance.mSet;
      }
      v22 = 0;
      if ( (_DWORD)mComponentCount )
      {
        v23 = dest;
        v24 = mComponentCount;
        do
        {
          if ( v22 || *(_DWORD *)v23 > 1u )
            v22 = 1;
          v23 += 4;
          --v24;
        }
        while ( v24 );
      }
      BYTE1(v29) = v10;
      HIDWORD(v29) = LODWORD(v8->mVarietyRatio);
      LOBYTE(v29) = v22;
      textureMemory[0] = v12;
      UFG::TrueCrowdSet::GetCurrentMemoryUsage(mSet, modelMemory, &textureMemory[1]);
      LOBYTE(candidates) = (_BYTE)retaddr;
      if ( v10 )
      {
        LODWORD(candidates) = (unsigned __int8)retaddr;
        v25 = 5i64 * (unsigned int)*v36;
        *((_QWORD *)&this->mQueued.size + v25) = v28;
        *((_QWORD *)&this->mQueued.p + v25) = v29;
        *((_QWORD *)&this->mLoading.size + v25) = __PAIR64__(v11, size);
        *((_QWORD *)&this->mLoading.p + v25) = *(_QWORD *)textureMemory;
        *((_QWORD *)&this->mLoaded.size + v25) = *(_QWORD *)modelMemory;
        ++*v36;
        if ( !(size + v12 + v11) )
          LODWORD(candidates) = 1;
        LODWORD(retaddr) = (_DWORD)candidates;
      }
    }
    v6 = (unsigned int)(v6 + 1);
  }
  return (unsigned __int8)candidates;
}

// File Line: 853
// RVA: 0x43FDA0
bool __fastcall UFG::ResourcePool::PreloadSortPredicate(
        UFG::ResourcePool::ContractionSortData *a,
        UFG::ResourcePool::ContractionSortData *b)
{
  unsigned int mSpawnedReferences; // r8d
  unsigned int v4; // ecx
  bool v5; // cf
  unsigned int mProxyReferences; // ecx
  unsigned int v7; // r8d
  unsigned int mPreloadReferences; // ecx
  unsigned int v9; // r8d
  bool mExpanded; // cl
  float mVarietyRatio; // xmm0_4
  float v12; // xmm1_4

  mSpawnedReferences = b->mSpawnedReferences;
  v4 = a->mSpawnedReferences;
  v5 = v4 < mSpawnedReferences;
  if ( v4 != mSpawnedReferences )
    return v5;
  mProxyReferences = a->mProxyReferences;
  v7 = b->mProxyReferences;
  v5 = mProxyReferences < v7;
  if ( mProxyReferences != v7 )
    return v5;
  mPreloadReferences = a->mPreloadReferences;
  v9 = b->mPreloadReferences;
  v5 = mPreloadReferences < v9;
  if ( mPreloadReferences != v9 )
    return v5;
  mExpanded = a->mExpanded;
  if ( mExpanded != b->mExpanded )
    return mExpanded;
  mVarietyRatio = a->mVarietyRatio;
  v12 = b->mVarietyRatio;
  if ( mVarietyRatio == v12 )
    return a->mTextureMemory + a->mMeshMemory <= b->mTextureMemory + b->mMeshMemory;
  else
    return mVarietyRatio > v12;
}

// File Line: 878
// RVA: 0x442BD0
bool __fastcall UFG::ResourcePool::RequestSortPredicate(UFG::ResourceRequest *a, UFG::ResourceRequest *b)
{
  unsigned int size; // eax
  unsigned int v3; // r8d
  bool v4; // cf
  unsigned int v5; // eax
  unsigned int v6; // r8d
  unsigned int v7; // eax
  unsigned int v8; // r8d

  size = a->mInstances.size;
  v3 = b->mInstances.size;
  v4 = size < v3;
  if ( size == v3 )
  {
    v5 = a->mProxies.size;
    v6 = b->mProxies.size;
    v4 = v5 < v6;
    if ( v5 == v6 )
    {
      v7 = a->mPreloads.size;
      v8 = b->mPreloads.size;
      v4 = v7 < v8;
      if ( v7 == v8 )
        return a->mResource->mModelSize + a->mResource->mTextureSize < b->mResource->mModelSize
                                                                     + b->mResource->mTextureSize;
    }
  }
  return v4;
}

// File Line: 901
// RVA: 0x43A7C0
char __fastcall UFG::ResourcePool::ContractAmbientModel(UFG::ResourcePool *this, UFG::TrueCrowdModel *model)
{
  UFG::ResourceRequest *mRequest; // rax
  bool v5; // zf
  unsigned int mValue; // eax
  bool v7; // r15
  char v8; // si
  UFG::ResourceRequest *v9; // r13
  int v10; // eax
  __int64 i; // r14
  void *mUserContext; // rbx
  UFG::SimObjectGame *v13; // rbx
  __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::SimObject *m_pSimObject; // rcx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbp
  UFG::BaseCameraComponent *mCurrentCamera; // rax
  float *v19; // rax
  UFG::ResourceRequest *v20; // rdx
  unsigned int j; // ebx
  __int64 mOffset; // rax
  char *v23; // rcx
  char *v24; // rdx
  char *v25; // rcx
  char *v26; // rcx
  char *v27; // rax
  UFG::ResourceRequest **v28; // rdx
  UFG::ResourceRequest *v29; // rax

  if ( !model )
    return 0;
  mRequest = model->mRequest;
  if ( !mRequest || mRequest->mLoadStatus != Loaded )
    return 0;
  v5 = (unsigned int)UFG::FlowController::GetCurrentState(&UFG::gFlowController) == uidGameStateInGame_7;
  mValue = model->mType.mValue;
  v7 = !v5;
  v8 = 0;
  if ( mValue )
  {
    if ( mValue - 1 <= 1 )
    {
      v9 = model->mRequest;
      if ( v9 )
      {
        v10 = v9->mInstances.size - 1;
        for ( i = v10; i >= 0; --i )
        {
          mUserContext = v9->mInstances.p[i]->mUserContext;
          if ( mUserContext )
          {
            if ( (v13 = (UFG::SimObjectGame *)*((_QWORD *)mUserContext + 5)) != 0i64
              && ((m_Flags = v13->m_Flags, (m_Flags & 0x4000) == 0)
                ? (m_Flags >= 0
                 ? ((m_Flags & 0x2000) == 0
                  ? ((m_Flags & 0x1000) == 0
                   ? (ComponentOfType = UFG::SimObject::GetComponentOfType(
                                          v13,
                                          UFG::CompositeDrawableComponent::_TypeUID))
                   : (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(
                                          v13,
                                          UFG::CompositeDrawableComponent::_TypeUID)))
                  : (ComponentOfType = v13->m_Components.p[9].m_pComponent))
                 : (ComponentOfType = v13->m_Components.p[14].m_pComponent))
                : (ComponentOfType = v13->m_Components.p[14].m_pComponent),
                  ComponentOfType
               && (m_pSimObject = ComponentOfType[19].m_pSimObject) != 0i64
               && LOBYTE(m_pSimObject->vfptr) > 1u)
              || v7 )
            {
              if ( model->mType.mValue != 1 )
                goto LABEL_31;
              m_pTransformNodeComponent = 0i64;
              if ( v13 )
                m_pTransformNodeComponent = v13->m_pTransformNodeComponent;
              UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
              mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
              v19 = mCurrentCamera ? (float *)&mCurrentCamera->mCamera : 0i64;
              if ( (float)((float)((float)((float)(v19[45] - m_pTransformNodeComponent->mWorldTransform.v3.y)
                                         * (float)(v19[45] - m_pTransformNodeComponent->mWorldTransform.v3.y))
                                 + (float)((float)(v19[44] - m_pTransformNodeComponent->mWorldTransform.v3.x)
                                         * (float)(v19[44] - m_pTransformNodeComponent->mWorldTransform.v3.x)))
                         + (float)((float)(v19[46] - m_pTransformNodeComponent->mWorldTransform.v3.z)
                                 * (float)(v19[46] - m_pTransformNodeComponent->mWorldTransform.v3.z))) > 2500.0
                || v7 )
              {
LABEL_31:
                UFG::Simulation::DestroySimObject(&UFG::gSim, v13);
              }
            }
          }
        }
      }
    }
  }
  else
  {
    UFG::PedSpawnManager::ReducePedsWithSpecificModel(model, v7);
  }
  v20 = model->mRequest;
  if ( v20 )
    UFG::ResourcePool::RemovePreloadReferences(this, v20);
  for ( j = 0; j < model->mNumTextureSets; ++j )
  {
    mOffset = model->mTextureSets.mOffset;
    if ( mOffset )
      v23 = (char *)&model->mTextureSets + mOffset;
    else
      v23 = 0i64;
    v24 = &v23[8 * j];
    if ( *(_QWORD *)v24 )
      v25 = &v24[*(_QWORD *)v24];
    else
      v25 = 0i64;
    if ( *((_QWORD *)v25 + 1) )
    {
      if ( mOffset )
        v26 = (char *)&model->mTextureSets + mOffset;
      else
        v26 = 0i64;
      v27 = &v26[8 * j];
      v28 = (UFG::ResourceRequest **)&v27[*(_QWORD *)v27];
      if ( !*(_QWORD *)v27 )
        v28 = 0i64;
      UFG::ResourcePool::RemovePreloadReferences(this, v28[1]);
    }
  }
  v29 = model->mRequest;
  if ( !v29 || !v29->mInstances.size && !v29->mPreloads.size && !v29->mProxies.size )
    return 1;
  return v8;
}

// File Line: 975
// RVA: 0x43AAB0
void __fastcall UFG::ResourcePool::ContractAmbientModels(UFG::ResourcePool *this, unsigned int numModels)
{
  unsigned int v2; // r15d
  unsigned int v3; // r13d
  UFG::ResourcePool *v4; // r12
  unsigned int v5; // ebx
  unsigned int v6; // r14d
  unsigned int v7; // esi
  unsigned int v8; // r13d
  char v9; // di
  UFG::PreloadRequest *mResourceRequest; // rsi
  UFG::TrueCrowdModel *v11; // rax
  UFG::TrueCrowdSet *mSet; // rdx
  unsigned int mComponentCount; // r8d
  UFG::qArray<UFG::TrueCrowdModel *,0> *mFiles; // r14
  __int64 v15; // r12
  unsigned int i; // ebx
  UFG::TrueCrowdModel *v17; // r9
  UFG::ResourceRequest *mRequest; // r8
  unsigned int size; // edx
  unsigned int v20; // ecx
  UFG::PreloadRequest **p; // rax
  bool v22; // zf
  unsigned int v23; // eax
  unsigned int *mPriorityRefCounts; // rcx
  UFG::ResourcePriorityBucket *mLowBucket; // r9
  unsigned int v26; // r14d
  unsigned int j; // r8d
  UFG::ResourceRequest *v28; // rdx
  unsigned int v29; // eax
  unsigned int *v30; // rcx
  __int64 v31; // rax
  Render::IrradianceVolume **v32; // rdi
  __int64 v33; // rax
  int v34; // ecx
  Render::IrradianceVolume *v35; // r8
  float v36; // ecx
  Render::IrradianceVolume **v37; // r10
  Render::IrradianceVolume *v38; // r9
  float v39; // eax
  bool v40; // cf
  float v41; // eax
  float v42; // ecx
  float v43; // eax
  float v44; // ecx
  Render::IrradianceVolume *v45; // r9
  Render::IrradianceVolume *v46; // r11
  float v47; // eax
  float v48; // ecx
  bool v49; // cf
  float v50; // eax
  float v51; // ecx
  float v52; // eax
  float v53; // ecx
  Render::IrradianceVolume *v54; // r9
  float v55; // ecx
  float v56; // eax
  bool v57; // cf
  float v58; // eax
  float v59; // ecx
  float v60; // eax
  float v61; // ecx
  Render::IrradianceVolume *v62; // r8
  Render::IrradianceVolume **v63; // rbx
  Render::IrradianceVolume **v64; // r9
  float v65; // r10d
  Render::IrradianceVolume *v66; // rdx
  float v67; // eax
  bool v68; // cf
  float v69; // eax
  float v70; // ecx
  float v71; // eax
  float v72; // ecx
  Render::IrradianceVolume *v73; // rdx
  float v74; // eax
  bool v75; // cf
  float v76; // eax
  float v77; // ecx
  float v78; // eax
  float v79; // ecx
  Render::IrradianceVolume *v80; // rax
  Render::IrradianceVolume *v81; // rcx
  __int64 v82; // rbx
  __int64 v83; // rsi
  int v84; // edi
  Render::IrradianceVolume *v85; // r9
  int v86; // r11d
  __int64 k; // r10
  Render::IrradianceVolume *v88; // r8
  float z; // eax
  float v90; // ecx
  bool v91; // cf
  float v92; // eax
  float v93; // ecx
  float v94; // eax
  float v95; // ecx
  Render::IrradianceVolume **v96; // rbx
  unsigned int v97; // [rsp+20h] [rbp-E0h]
  Render::IrradianceVolume *left[256]; // [rsp+30h] [rbp-D0h] BYREF
  UFG::ResourcePool::ContractionSortData candidates[256]; // [rsp+830h] [rbp+730h] BYREF
  unsigned int v103; // [rsp+3090h] [rbp+2F90h]
  unsigned int candidateCount; // [rsp+3098h] [rbp+2F98h] BYREF

  v2 = 0;
  v3 = numModels;
  v4 = this;
  v5 = 0;
  v6 = 0;
  candidateCount = 0;
  if ( this->mEntityStates.size )
  {
    do
    {
      UFG::ResourcePool::GetContractableAmbientOptions(v4, v5 + 3, candidates, &candidateCount);
      ++v5;
    }
    while ( v5 < v4->mEntityStates.size );
    v6 = candidateCount;
  }
  v7 = 0;
  v103 = 0;
  if ( v6 )
  {
    UFG::qInsertionSort<UFG::ResourcePool::ContractionSortData,bool (*)(UFG::ResourcePool::ContractionSortData const &,UFG::ResourcePool::ContractionSortData const &)>(
      candidates,
      v6,
      UFG::ResourcePool::PreloadSortPredicate);
    v8 = 0;
    v97 = 0;
    do
    {
      v9 = 0;
      mResourceRequest = candidates[v8].mResourceRequest;
      if ( candidates[v8].mExpanded )
      {
        v11 = UFG::TrueCrowdSet::ChooseContractableAmbientPart(mResourceRequest->mInstance.mSet);
        v9 = UFG::ResourcePool::ContractAmbientModel(v4, v11);
      }
      else
      {
        mSet = mResourceRequest->mInstance.mSet;
        mComponentCount = UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition.mEntities[mSet->mEntityIndex].mComponentCount;
        if ( mComponentCount )
        {
          mFiles = mSet->mFiles;
          v15 = mComponentCount;
          do
          {
            for ( i = 0; i < mFiles->size; ++i )
            {
              v17 = mFiles->p[i];
              mRequest = v17->mRequest;
              if ( mRequest )
              {
                size = mRequest->mPreloads.size;
                v20 = 0;
                if ( size )
                {
                  p = mRequest->mPreloads.p;
                  while ( mResourceRequest != *p )
                  {
                    ++v20;
                    ++p;
                    if ( v20 >= size )
                      goto LABEL_16;
                  }
                }
                else
                {
LABEL_16:
                  v20 = -1;
                }
                v22 = v20 == -1;
                v23 = 0;
                mPriorityRefCounts = mRequest->mPriorityRefCounts;
                while ( !*mPriorityRefCounts )
                {
                  ++v23;
                  ++mPriorityRefCounts;
                  if ( v23 >= 5 )
                  {
                    v23 = 0;
                    break;
                  }
                }
                if ( !v22 && v23 == 4 && (v9 || UFG::ResourcePool::ContractAmbientModel(this, v17)) )
                  v9 = 1;
              }
            }
            ++mFiles;
            --v15;
          }
          while ( v15 );
          v8 = v97;
          v6 = candidateCount;
          v4 = this;
        }
        UFG::ResourcePool::ReleaseResourceSetFiles(v4, mResourceRequest);
      }
      v7 = v103;
      if ( v9 )
      {
        v7 = v103 + 1;
        v103 = v7;
        if ( v7 == numModels )
          break;
      }
      v97 = ++v8;
    }
    while ( v8 < v6 );
    v3 = numModels;
  }
  if ( v7 < v3 )
  {
    mLowBucket = v4->mLowBucket;
    v26 = 0;
    for ( j = 0; j < mLowBucket->mResourceRequests.size; ++j )
    {
      v28 = mLowBucket->mResourceRequests.p[j];
      if ( v28->mInstances.size || v28->mPreloads.size || v28->mProxies.size )
      {
        v29 = 0;
        v30 = v28->mPriorityRefCounts;
        while ( !*v30 )
        {
          ++v29;
          ++v30;
          if ( v29 >= 5 )
            goto LABEL_46;
        }
        if ( v29 == 4 && v28->mType == Model )
        {
          v31 = v26++;
          left[v31] = (Render::IrradianceVolume *)v28;
        }
      }
LABEL_46:
      ;
    }
    v32 = &left[(int)v26 - 1];
    v33 = v32 - left;
    v34 = v33 + 1;
    if ( (int)v33 + 1 < 32 )
    {
      if ( v34 > 1 )
      {
        v82 = 1i64;
        v83 = v34;
        if ( v34 > 1i64 )
        {
          v84 = 0;
          do
          {
            v85 = left[v82];
            v86 = v84;
            for ( k = v82 - 1; v86 >= 0; --v86 )
            {
              v88 = left[k];
              z = v85->mTransform.v2.z;
              v90 = v88->mTransform.v2.z;
              v91 = LODWORD(z) < LODWORD(v90);
              if ( LODWORD(z) == LODWORD(v90) )
              {
                v92 = v85->mTransformInv.v0.z;
                v93 = v88->mTransformInv.v0.z;
                v91 = LODWORD(v92) < LODWORD(v93);
                if ( LODWORD(v92) == LODWORD(v93) )
                {
                  v94 = v85->mTransform.v3.z;
                  v95 = v88->mTransform.v3.z;
                  v91 = LODWORD(v94) < LODWORD(v95);
                  if ( LODWORD(v94) == LODWORD(v95) )
                    v91 = *(_DWORD *)(*(_QWORD *)&v85->mTransform.v2.x + 16i64)
                        + *(_DWORD *)(*(_QWORD *)&v85->mTransform.v2.x + 20i64) < (unsigned int)(*(_DWORD *)(*(_QWORD *)&v88->mTransform.v2.x + 16i64)
                                                                                               + *(_DWORD *)(*(_QWORD *)&v88->mTransform.v2.x + 20i64));
                }
              }
              if ( !v91 )
                break;
              left[k-- + 1] = v88;
            }
            ++v82;
            ++v84;
            left[k + 1] = v85;
          }
          while ( v82 < v83 );
        }
        v7 = v103;
      }
    }
    else
    {
      v35 = left[0];
      v36 = left[0]->mTransform.v2.z;
      v37 = &left[v33 / 2];
      v38 = *v37;
      v39 = (*v37)->mTransform.v2.z;
      v40 = LODWORD(v39) < LODWORD(v36);
      if ( LODWORD(v39) == LODWORD(v36) )
      {
        v41 = v38->mTransformInv.v0.z;
        v42 = left[0]->mTransformInv.v0.z;
        v40 = LODWORD(v41) < LODWORD(v42);
        if ( LODWORD(v41) == LODWORD(v42) )
        {
          v43 = v38->mTransform.v3.z;
          v44 = left[0]->mTransform.v3.z;
          v40 = LODWORD(v43) < LODWORD(v44);
          if ( LODWORD(v43) == LODWORD(v44) )
            v40 = *(_DWORD *)(*(_QWORD *)&v38->mTransform.v2.x + 16i64)
                + *(_DWORD *)(*(_QWORD *)&v38->mTransform.v2.x + 20i64) < (unsigned int)(*(_DWORD *)(*(_QWORD *)&left[0]->mTransform.v2.x + 16i64)
                                                                                       + *(_DWORD *)(*(_QWORD *)&left[0]->mTransform.v2.x + 20i64));
        }
      }
      if ( v40 )
      {
        *v37 = left[0];
        v35 = v38;
        left[0] = v38;
      }
      v45 = *v37;
      v46 = *v32;
      v47 = (*v32)->mTransform.v2.z;
      v48 = (*v37)->mTransform.v2.z;
      v49 = LODWORD(v47) < LODWORD(v48);
      if ( LODWORD(v47) == LODWORD(v48) )
      {
        v50 = v46->mTransformInv.v0.z;
        v51 = v45->mTransformInv.v0.z;
        v49 = LODWORD(v50) < LODWORD(v51);
        if ( LODWORD(v50) == LODWORD(v51) )
        {
          v52 = v46->mTransform.v3.z;
          v53 = v45->mTransform.v3.z;
          v49 = LODWORD(v52) < LODWORD(v53);
          if ( LODWORD(v52) == LODWORD(v53) )
            v49 = *(_DWORD *)(*(_QWORD *)&v46->mTransform.v2.x + 16i64)
                + *(_DWORD *)(*(_QWORD *)&v46->mTransform.v2.x + 20i64) < (unsigned int)(*(_DWORD *)(*(_QWORD *)&v45->mTransform.v2.x + 16i64)
                                                                                       + *(_DWORD *)(*(_QWORD *)&v45->mTransform.v2.x + 20i64));
        }
      }
      if ( v49 )
      {
        *v32 = v45;
        *v37 = v46;
        v35 = left[0];
      }
      v54 = *v37;
      v55 = v35->mTransform.v2.z;
      v56 = (*v37)->mTransform.v2.z;
      v57 = LODWORD(v56) < LODWORD(v55);
      if ( LODWORD(v56) == LODWORD(v55) )
      {
        v58 = v54->mTransformInv.v0.z;
        v59 = v35->mTransformInv.v0.z;
        v57 = LODWORD(v58) < LODWORD(v59);
        if ( LODWORD(v58) == LODWORD(v59) )
        {
          v60 = v54->mTransform.v3.z;
          v61 = v35->mTransform.v3.z;
          v57 = LODWORD(v60) < LODWORD(v61);
          if ( LODWORD(v60) == LODWORD(v61) )
            v57 = *(_DWORD *)(*(_QWORD *)&v54->mTransform.v2.x + 16i64)
                + *(_DWORD *)(*(_QWORD *)&v54->mTransform.v2.x + 20i64) < (unsigned int)(*(_DWORD *)(*(_QWORD *)&v35->mTransform.v2.x + 16i64)
                                                                                       + *(_DWORD *)(*(_QWORD *)&v35->mTransform.v2.x + 20i64));
        }
      }
      if ( v57 )
      {
        *v37 = v35;
        left[0] = v54;
      }
      v62 = *v37;
      v63 = left;
      v64 = &left[(int)v26 - 1];
      if ( left <= v32 )
      {
        do
        {
          v65 = v62->mTransform.v2.z;
          while ( 1 )
          {
            v66 = *v63;
            v67 = (*v63)->mTransform.v2.z;
            v68 = LODWORD(v67) < LODWORD(v65);
            if ( LODWORD(v67) == LODWORD(v65) )
            {
              v69 = v66->mTransformInv.v0.z;
              v70 = v62->mTransformInv.v0.z;
              v68 = LODWORD(v69) < LODWORD(v70);
              if ( LODWORD(v69) == LODWORD(v70) )
              {
                v71 = v66->mTransform.v3.z;
                v72 = v62->mTransform.v3.z;
                v68 = LODWORD(v71) < LODWORD(v72);
                if ( LODWORD(v71) == LODWORD(v72) )
                  v68 = *(_DWORD *)(*(_QWORD *)&v66->mTransform.v2.x + 16i64)
                      + *(_DWORD *)(*(_QWORD *)&v66->mTransform.v2.x + 20i64) < (unsigned int)(*(_DWORD *)(*(_QWORD *)&v62->mTransform.v2.x + 16i64)
                                                                                             + *(_DWORD *)(*(_QWORD *)&v62->mTransform.v2.x + 20i64));
              }
            }
            if ( !v68 || v63 >= v32 )
              break;
            ++v63;
          }
          while ( 1 )
          {
            v73 = *v64;
            v74 = (*v64)->mTransform.v2.z;
            v75 = LODWORD(v65) < LODWORD(v74);
            if ( LODWORD(v65) == LODWORD(v74) )
            {
              v76 = v62->mTransformInv.v0.z;
              v77 = v73->mTransformInv.v0.z;
              v75 = LODWORD(v76) < LODWORD(v77);
              if ( LODWORD(v76) == LODWORD(v77) )
              {
                v78 = v62->mTransform.v3.z;
                v79 = v73->mTransform.v3.z;
                v75 = LODWORD(v78) < LODWORD(v79);
                if ( LODWORD(v78) == LODWORD(v79) )
                  v75 = *(_DWORD *)(*(_QWORD *)&v62->mTransform.v2.x + 16i64)
                      + *(_DWORD *)(*(_QWORD *)&v62->mTransform.v2.x + 20i64) < (unsigned int)(*(_DWORD *)(*(_QWORD *)&v73->mTransform.v2.x + 16i64)
                                                                                             + *(_DWORD *)(*(_QWORD *)&v73->mTransform.v2.x + 20i64));
              }
            }
            if ( !v75 || left >= v64 )
              break;
            --v64;
          }
          if ( v63 > v64 )
            break;
          v80 = *v64;
          v81 = *v63;
          --v64;
          *v63 = v80;
          v64[1] = v81;
          ++v63;
        }
        while ( v63 <= v64 );
      }
      if ( left < v64 )
        UFG::qQuickSortImpl<Render::Light *,bool (*)(Render::Light const *,Render::Light const *)>(
          left,
          v64,
          (bool (__fastcall *)(Render::IrradianceVolume *, Render::IrradianceVolume *))UFG::ResourcePool::RequestSortPredicate);
      if ( v63 < v32 )
        UFG::qQuickSortImpl<Render::Light *,bool (*)(Render::Light const *,Render::Light const *)>(
          v63,
          &left[(int)v26 - 1],
          (bool (__fastcall *)(Render::IrradianceVolume *, Render::IrradianceVolume *))UFG::ResourcePool::RequestSortPredicate);
    }
    if ( v26 )
    {
      v96 = left;
      do
      {
        if ( UFG::ResourcePool::ContractAmbientModel(v4, *(UFG::TrueCrowdModel **)&(*v96)->mTransform.v2.x) )
        {
          if ( ++v7 == v3 )
            break;
        }
        ++v2;
        ++v96;
      }
      while ( v2 < v26 );
    }
  }
}

// File Line: 1084
// RVA: 0x43C300
char __fastcall UFG::ResourcePool::ExpandAmbience(UFG::ResourcePool *this)
{
  __int64 v2; // rdi
  bool IsLoadingScreenUp; // r15
  UFG::ResourcePriorityBucket *mHighBucket; // r10
  UFG::ResourcePriorityBucket *mLowBucket; // r9
  signed int v6; // esi
  signed int v7; // r14d
  unsigned int size; // eax
  __int64 v9; // rbx
  UFG::EntityTypeState *v10; // r11
  __int64 mEntityType; // r9
  UFG::ResourcePriorityBucket *v12; // r8
  UFG::ResourcePriorityBucket *v13; // rdx
  int v14; // r10d
  int v15; // edx
  float mAmbientModelRatioTarget; // xmm4_4
  float v17; // xmm1_4
  int v18; // r8d
  float mAmbientTextureRatioTarget; // xmm2_4
  float v20; // xmm1_4
  unsigned int v21; // ecx
  unsigned int v22; // eax
  unsigned int v23; // ecx
  unsigned int v24; // eax
  unsigned int v25; // r14d
  int v26; // ecx
  UFG::qArray<UFG::PreloadRequest *,0> *mPreloadBuckets; // r8
  unsigned int v28; // edx
  UFG::PreloadRequest **p; // r8
  UFG::PreloadRequest *v30; // r15
  UFG::ResourcePriorityBucket *v31; // r8
  UFG::ResourcePriorityBucket *v32; // rdx
  unsigned int mAmbientModelMemoryLimit; // r13d
  int v34; // eax
  unsigned int v35; // r13d
  unsigned int mAmbientTextureMemoryLimit; // r12d
  int v37; // eax
  unsigned int v38; // r12d
  UFG::PartDatabase *v39; // rdx
  UFG::PartPool::Bucket *v40; // rcx
  UFG::TrueCrowdSet::Instance *p_mInstance; // r14
  UFG::TrueCrowdSet *v42; // rdi
  unsigned int v43; // edx
  __int64 i; // rbx
  unsigned int NumModelsLoaded; // eax
  UFG::ModelTextureCombination *v46; // r8
  unsigned int v47; // r10d
  unsigned int v48; // r9d
  unsigned int mNumParts; // eax
  UFG::ModelTextureCombination *v50; // r8
  __int64 v51; // r11
  __int64 mModelIndex; // rcx
  __int64 v53; // rdx
  __int64 v54; // rax
  __int64 v55; // rax
  __int64 v56; // rcx
  __int64 *v57; // rdx
  __int64 v58; // rax
  __int64 v59; // rcx
  unsigned int v61; // edx
  UFG::EntityTypeState *v62; // r13
  unsigned int v63; // edx
  int v64; // ecx
  UFG::qColour **p_mColourTint; // rax
  UFG::PreloadRequest *v66; // r15
  UFG::TrueCrowdSet *mSet; // rsi
  UFG::TrueCrowdDataBase *v68; // rdx
  unsigned int mComponentCount; // edi
  unsigned int v70; // ebx
  int v71; // r9d
  unsigned int v72; // ecx
  UFG::TrueCrowdModel ***p_p; // r10
  __int64 v74; // r11
  unsigned int v75; // eax
  UFG::TrueCrowdModel **v76; // rcx
  __int64 v77; // r8
  UFG::ResourceRequest *mRequest; // rdx
  UFG::PartDatabase *v79; // rax
  UFG::PartPool::Bucket *mMasterBucket; // rdx
  unsigned int mAvailableAmbientModelMemory; // r10d
  unsigned int mAvailableAmbientTextureMemory; // r11d
  unsigned int v83; // ebx
  UFG::ModelTextureCombination *mPart; // r8
  signed __int64 v85; // rsi
  __int64 v86; // r9
  __int64 v87; // rdx
  __int64 v88; // rax
  __int64 v89; // rax
  __int64 v90; // rcx
  __int64 *v91; // rdx
  __int64 v92; // rax
  __int64 v93; // rcx
  UFG::MeshResourceLoader *v94; // rsi
  UFG::TrueCrowdModel *Part; // rdi
  UFG::TrueCrowdTextureSet *TextureSet; // rax
  UFG::TrueCrowdResource *v97; // rbx
  unsigned int mModelSize; // ecx
  unsigned int v99; // r15d
  unsigned int mTextureSize; // ecx
  unsigned int v101; // r14d
  UFG::ResourceUser user; // [rsp+38h] [rbp-C8h] BYREF
  UFG::ResourceUser v103; // [rsp+48h] [rbp-B8h] BYREF
  __int64 v104; // [rsp+58h] [rbp-A8h]
  UFG::TrueCrowdSet::Instance instance; // [rsp+60h] [rbp-A0h] BYREF
  UFG::ResourcePool *reason; // [rsp+1D0h] [rbp+D0h] BYREF
  char v107; // [rsp+1D8h] [rbp+D8h]
  unsigned int v108; // [rsp+1E0h] [rbp+E0h]
  UFG::PreloadRequest *candidate; // [rsp+1E8h] [rbp+E8h] BYREF

  reason = this;
  v104 = -2i64;
  LOBYTE(v2) = 0;
  v107 = 0;
  IsLoadingScreenUp = UFG::LoadingLogic::IsLoadingScreenUp(&UFG::gLoadingLogic);
  mHighBucket = this->mHighBucket;
  mLowBucket = this->mLowBucket;
  v6 = this->mAmbientModelMemoryLimit
     - (mHighBucket->mMemoryUsage[0][1]
      + mHighBucket->mMemoryUsage[1][1]
      + mHighBucket->mMemoryUsage[2][1]
      + mLowBucket->mMemoryUsage[0][1]
      + mLowBucket->mMemoryUsage[1][1]
      + mLowBucket->mMemoryUsage[2][1]);
  v7 = this->mAmbientTextureMemoryLimit
     - (mLowBucket->mMemoryUsage[0][0]
      + mLowBucket->mMemoryUsage[1][0]
      + mLowBucket->mMemoryUsage[2][0]
      + mHighBucket->mMemoryUsage[0][0]
      + mHighBucket->mMemoryUsage[1][0]
      + mHighBucket->mMemoryUsage[2][0]);
  size = this->mEntityStates.size;
  if ( size )
  {
    v9 = 0i64;
    v2 = size;
    do
    {
      v10 = this->mEntityStates.p[v9];
      mEntityType = v10->mEntityType;
      v12 = this->mHighBucket;
      v13 = this->mLowBucket;
      v14 = v12->mMemoryUsage[mEntityType][1] + v13->mMemoryUsage[mEntityType][1];
      v15 = v12->mMemoryUsage[mEntityType][0] + v13->mMemoryUsage[mEntityType][0];
      v10->mAmbientModelRatio = (float)v14 / (float)(int)this->mAmbientModelMemoryLimit;
      v10->mAmbientTextureRatio = (float)v15 / (float)(int)this->mAmbientTextureMemoryLimit;
      mAmbientModelRatioTarget = v10->mAmbientModelRatioTarget;
      v17 = (float)((int)(float)((float)(int)this->mAmbientModelMemoryLimit * mAmbientModelRatioTarget) - v14);
      if ( v17 <= 0.0 )
        v17 = 0.0;
      v18 = (int)v17;
      v10->mAvailableAmbientModelMemory = (int)v17;
      mAmbientTextureRatioTarget = v10->mAmbientTextureRatioTarget;
      v20 = (float)((int)(float)((float)(int)this->mAmbientTextureMemoryLimit * mAmbientTextureRatioTarget) - v15);
      if ( v20 <= 0.0 )
        v20 = 0.0;
      v10->mAvailableAmbientTextureMemory = (int)v20;
      if ( IsLoadingScreenUp )
      {
        v21 = (int)(float)((float)v6 * mAmbientModelRatioTarget);
        v22 = 0;
        if ( v18 )
          v22 = v18;
        if ( v22 < v21 )
          v21 = v22;
        v10->mAvailableAmbientModelMemory = v21;
        v23 = (int)(float)((float)v7 * mAmbientTextureRatioTarget);
        v24 = 0;
        if ( (int)v20 )
          v24 = (int)v20;
        if ( v24 < v23 )
          v23 = v24;
        v10->mAvailableAmbientTextureMemory = v23;
      }
      ++v9;
      --v2;
    }
    while ( v2 );
  }
  v25 = 0;
  if ( !UFG::ResourcePool::BasicAmbienceLoaded(this)
    || (v26 = 0, mPreloadBuckets = this->mPreloadBuckets, (v28 = mPreloadBuckets[2].size) == 0) )
  {
LABEL_59:
    v61 = 0;
    v108 = 0;
    if ( !this->mEntityStates.size )
      return v2;
    while ( 1 )
    {
      v62 = this->mEntityStates.p[v61];
      v63 = v61 + 3;
      if ( this->mPreloadBuckets[v63].size )
      {
        LODWORD(reason) = 2;
        UFG::ResourcePool::GetExpansionCandidate(this, v63, &candidate, (UFG::ResourcePool::ExpansionReason *)&reason);
        if ( !(_DWORD)reason )
        {
          v64 = 15;
          p_mColourTint = &instance.mPart[0].mColourTint;
          do
          {
            *(p_mColourTint - 1) = 0i64;
            *p_mColourTint = 0i64;
            p_mColourTint += 2;
            --v64;
          }
          while ( v64 >= 0 );
          v66 = candidate;
          mSet = candidate->mInstance.mSet;
          instance.mSet = mSet;
          v68 = UFG::TrueCrowdDataBase::sTrueCrowdDataBase;
          mComponentCount = UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition.mEntities[mSet->mEntityIndex].mComponentCount;
          instance.mNumParts = mComponentCount;
          v70 = 0;
          if ( mComponentCount )
          {
            while ( 1 )
            {
              if ( mSet->mComponentDetails[v70].mbSpecificModel )
              {
                UFG::TrueCrowdSet::ChooseSpecificModel(mSet, v70, &instance.mPart[v70], 0i64);
              }
              else
              {
                v71 = 0;
                v72 = v68->mDefinition.mEntities[mSet->mEntityIndex].mComponentCount;
                if ( !v72 )
                  goto LABEL_78;
                p_p = &mSet->mFiles[0].p;
                v74 = v72;
                do
                {
                  v75 = *((_DWORD *)p_p - 2);
                  if ( v75 )
                  {
                    v76 = *p_p;
                    v77 = v75;
                    do
                    {
                      mRequest = (*v76)->mRequest;
                      if ( mRequest && mRequest->mLoadStatus == Loaded )
                        ++v71;
                      ++v76;
                      --v77;
                    }
                    while ( v77 );
                  }
                  p_p += 2;
                  --v74;
                }
                while ( v74 );
                if ( v71 )
                  UFG::TrueCrowdSet::ChooseLeastCommonModel(mSet, v70, &instance.mPart[v70], 0i64);
                else
LABEL_78:
                  UFG::TrueCrowdSet::ChooseRandomModel(mSet, v70, &instance.mPart[v70], 0i64);
              }
              ++v70;
              mComponentCount = instance.mNumParts;
              if ( v70 >= instance.mNumParts )
                break;
              v68 = UFG::TrueCrowdDataBase::sTrueCrowdDataBase;
            }
            mSet = instance.mSet;
          }
          v79 = UFG::PartDatabase::Instance();
          mMasterBucket = v79->mPool.mMasterBucket;
          mAvailableAmbientModelMemory = v79->mPool.mMaxModelMemory
                                       - v79->mPool.mExternalUsedModelMemory
                                       - mMasterBucket->mMemoryUsageModel;
          if ( v62->mAvailableAmbientModelMemory < mAvailableAmbientModelMemory )
            mAvailableAmbientModelMemory = v62->mAvailableAmbientModelMemory;
          mAvailableAmbientTextureMemory = v79->mPool.mMaxTextureMemory
                                         - v79->mPool.mExternalUsedTextureMemory
                                         - mMasterBucket->mMemoryUsageTexture;
          if ( v62->mAvailableAmbientTextureMemory < mAvailableAmbientTextureMemory )
            mAvailableAmbientTextureMemory = v62->mAvailableAmbientTextureMemory;
          v83 = 0;
          if ( !mComponentCount )
            goto LABEL_104;
          mPart = instance.mPart;
          v85 = (char *)mSet - (char *)instance.mPart;
          v86 = mComponentCount;
          do
          {
            if ( mPart->mModelIndex != -1 )
            {
              v87 = *((_QWORD *)&(*(UFG::qColour **)((char *)&mPart[3].mColourTint + v85))->r + mPart->mModelIndex);
              v88 = *(_QWORD *)(v87 + 8);
              if ( !v88 || *(_DWORD *)(v88 + 20) != 3 )
              {
                v25 += *(_DWORD *)(v87 + 16);
                v83 += *(_DWORD *)(v87 + 20);
              }
              if ( *(_WORD *)(v87 + 58) )
              {
                v89 = *(_QWORD *)(v87 + 72);
                if ( v89 )
                  v90 = v89 + v87 + 72;
                else
                  v90 = 0i64;
                v91 = (__int64 *)(v90 + 8i64 * mPart->mTextureSetIndex);
                v92 = *v91;
                if ( *v91 )
                  v92 += (__int64)v91;
                v93 = *(_QWORD *)(v92 + 8);
                if ( !v93 || *(_DWORD *)(v93 + 20) != 3 )
                  v83 += *(_DWORD *)(v92 + 20);
              }
            }
            ++mPart;
            --v86;
          }
          while ( v86 );
          if ( v25 <= mAvailableAmbientModelMemory && v83 <= mAvailableAmbientTextureMemory )
          {
LABEL_104:
            LOBYTE(v2) = 1;
            v107 = 1;
            UFG::ResourcePool::PreloadInstance(this, v66, &instance);
            v62->mAvailableAmbientModelMemory -= v25;
            v62->mAvailableAmbientTextureMemory -= v83;
            goto LABEL_119;
          }
          goto LABEL_116;
        }
        if ( (_DWORD)reason == 1 )
        {
          v94 = (UFG::MeshResourceLoader *)candidate;
          Part = UFG::TrueCrowdSet::ChooseNextPart(candidate->mInstance.mSet);
          TextureSet = UFG::TrueCrowdModel::ChooseNextTextureSet(Part);
          v97 = TextureSet;
          if ( TextureSet )
            mModelSize = TextureSet->mModelSize;
          else
            mModelSize = 0;
          v99 = mModelSize + Part->mModelSize;
          if ( TextureSet )
            mTextureSize = TextureSet->mTextureSize;
          else
            mTextureSize = 0;
          v101 = Part->mTextureSize + mTextureSize;
          if ( v99 <= v62->mAvailableAmbientModelMemory && v101 <= v62->mAvailableAmbientTextureMemory )
          {
            v107 = 1;
            LODWORD(reason) = qSymbol_Low;
            user.mMeshLoader = v94;
            user.mType = Preload;
            UFG::ResourcePool::RequestLoadResource(this, Part, 0, (__int64)&reason, &user);
            v62->mAvailableAmbientModelMemory -= v99;
            v62->mAvailableAmbientTextureMemory -= v101;
            if ( v97 )
            {
              LODWORD(reason) = qSymbol_Low;
              v103.mMeshLoader = v94;
              v103.mType = Preload;
              UFG::ResourcePool::RequestLoadResource(this, v97, 1, (__int64)&reason, &v103);
              goto LABEL_116;
            }
            LOBYTE(v2) = 1;
LABEL_119:
            v25 = 0;
            goto LABEL_120;
          }
LABEL_116:
          LOBYTE(v2) = v107;
          goto LABEL_119;
        }
      }
      LOBYTE(v2) = v107;
LABEL_120:
      v61 = v108 + 1;
      v108 = v61;
      if ( v61 >= this->mEntityStates.size )
        return v2;
    }
  }
  p = mPreloadBuckets[2].p;
  while ( 1 )
  {
    v30 = p[v26];
    if ( !v30->mPreloadActive )
      break;
    if ( ++v26 >= v28 )
      goto LABEL_59;
  }
  v31 = this->mHighBucket;
  v32 = this->mLowBucket;
  mAmbientModelMemoryLimit = this->mAmbientModelMemoryLimit;
  v34 = mAmbientModelMemoryLimit;
  if ( v32->mMemoryUsage[0][1]
     + v32->mMemoryUsage[1][1]
     + v32->mMemoryUsage[2][1]
     + v31->mMemoryUsage[0][1]
     + v31->mMemoryUsage[1][1]
     + v31->mMemoryUsage[2][1] < mAmbientModelMemoryLimit )
    v34 = v32->mMemoryUsage[0][1]
        + v32->mMemoryUsage[1][1]
        + v32->mMemoryUsage[2][1]
        + v31->mMemoryUsage[0][1]
        + v31->mMemoryUsage[1][1]
        + v31->mMemoryUsage[2][1];
  v35 = mAmbientModelMemoryLimit - v34;
  mAmbientTextureMemoryLimit = this->mAmbientTextureMemoryLimit;
  v37 = mAmbientTextureMemoryLimit;
  if ( v32->mMemoryUsage[0][0]
     + v32->mMemoryUsage[1][0]
     + v32->mMemoryUsage[2][0]
     + v31->mMemoryUsage[0][0]
     + v31->mMemoryUsage[1][0]
     + v31->mMemoryUsage[2][0] < mAmbientTextureMemoryLimit )
    v37 = v32->mMemoryUsage[0][0]
        + v32->mMemoryUsage[1][0]
        + v32->mMemoryUsage[2][0]
        + v31->mMemoryUsage[0][0]
        + v31->mMemoryUsage[1][0]
        + v31->mMemoryUsage[2][0];
  v38 = mAmbientTextureMemoryLimit - v37;
  v39 = UFG::PartDatabase::Instance();
  v40 = v39->mPool.mMasterBucket;
  if ( v35 >= v39->mPool.mMaxModelMemory - v40->mMemoryUsageModel - v39->mPool.mExternalUsedModelMemory )
    v35 = v39->mPool.mMaxModelMemory - v40->mMemoryUsageModel - v39->mPool.mExternalUsedModelMemory;
  if ( v38 >= v39->mPool.mMaxTextureMemory - v40->mMemoryUsageTexture - v39->mPool.mExternalUsedTextureMemory )
    v38 = v39->mPool.mMaxTextureMemory - v40->mMemoryUsageTexture - v39->mPool.mExternalUsedTextureMemory;
  p_mInstance = &v30->mInstance;
  v42 = v30->mInstance.mSet;
  v43 = UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition.mEntities[v42->mEntityIndex].mComponentCount;
  v30->mInstance.mNumParts = v43;
  for ( i = 0i64; (unsigned int)i < v30->mInstance.mNumParts; i = (unsigned int)(i + 1) )
  {
    if ( v42->mComponentDetails[i].mbSpecificModel )
    {
      UFG::TrueCrowdSet::ChooseSpecificModel(v42, i, &p_mInstance->mPart[(unsigned int)i], 0i64);
    }
    else
    {
      NumModelsLoaded = UFG::TrueCrowdSet::GetNumModelsLoaded(v42);
      v46 = &p_mInstance->mPart[(unsigned int)i];
      if ( NumModelsLoaded )
        UFG::TrueCrowdSet::ChooseLeastCommonModel(v42, i, v46, 0i64);
      else
        UFG::TrueCrowdSet::ChooseRandomModel(v42, i, v46, 0i64);
    }
  }
  v47 = 0;
  v48 = 0;
  mNumParts = v30->mInstance.mNumParts;
  if ( !mNumParts )
    goto LABEL_58;
  v50 = v30->mInstance.mPart;
  v51 = mNumParts;
  do
  {
    mModelIndex = v50->mModelIndex;
    if ( (_DWORD)mModelIndex != -1 )
    {
      v53 = *(_QWORD *)(*(_QWORD *)((char *)&p_mInstance->mSet->mResourceFilename.mUID
                                  + (unsigned __int64)v50
                                  - (_QWORD)p_mInstance)
                      + 8 * mModelIndex);
      v54 = *(_QWORD *)(v53 + 8);
      if ( !v54 || *(_DWORD *)(v54 + 20) != 3 )
      {
        v47 += *(_DWORD *)(v53 + 16);
        v48 += *(_DWORD *)(v53 + 20);
      }
      if ( *(_WORD *)(v53 + 58) )
      {
        v55 = *(_QWORD *)(v53 + 72);
        if ( v55 )
          v56 = v53 + v55 + 72;
        else
          v56 = 0i64;
        v57 = (__int64 *)(v56 + 8i64 * v50->mTextureSetIndex);
        v58 = *v57;
        if ( *v57 )
          v58 += (__int64)v57;
        v59 = *(_QWORD *)(v58 + 8);
        if ( !v59 || *(_DWORD *)(v59 + 20) != 3 )
          v48 += *(_DWORD *)(v58 + 20);
      }
    }
    ++v50;
    --v51;
  }
  while ( v51 );
  if ( v47 > v35 || v48 > v38 )
    return 0;
LABEL_58:
  UFG::ResourcePool::PreloadInstance(reason, v30, &v30->mInstance);
  return 1;
}

// File Line: 1207
// RVA: 0x43D990
void __fastcall UFG::ResourcePool::GetExpansionCandidate(
        UFG::ResourcePool *this,
        unsigned int preloadBucketIndex,
        UFG::PreloadRequest **candidate,
        UFG::ResourcePool::ExpansionReason *reason)
{
  UFG::qArray<UFG::PreloadRequest *,0> *mPreloadBuckets; // r13
  __int64 v5; // r15
  unsigned int v6; // r10d
  unsigned int size; // edi
  UFG::PreloadRequest **p; // rax
  float mVarietyRatio; // xmm1_4
  unsigned int v10; // ebx
  unsigned int v11; // r14d
  UFG::PreloadRequest **v12; // rsi
  unsigned int v13; // r10d
  UFG::TrueCrowdSet *mSet; // r9
  unsigned int mComponentCount; // r11d
  UFG::TrueCrowdModel ***p_p; // r9
  unsigned int v17; // r8d
  unsigned int v18; // edx
  UFG::TrueCrowdModel **v19; // rcx
  UFG::PreloadRequest **v20; // [rsp+50h] [rbp+18h]
  UFG::ResourcePool::ExpansionReason *v21; // [rsp+58h] [rbp+20h]

  v21 = reason;
  v20 = candidate;
  *candidate = 0i64;
  *reason = NoExpansion;
  mPreloadBuckets = this->mPreloadBuckets;
  v5 = preloadBucketIndex;
  v6 = 0;
  size = mPreloadBuckets[preloadBucketIndex].size;
  if ( size )
  {
    p = mPreloadBuckets[preloadBucketIndex].p;
    while ( (*p)->mPreloadActive )
    {
      ++v6;
      ++p;
      if ( v6 >= size )
        goto LABEL_5;
    }
    *candidate = *p;
    *reason = InitialInstance;
  }
  else
  {
LABEL_5:
    if ( preloadBucketIndex >= 3 )
    {
      mVarietyRatio = FLOAT_N3_4028235e38;
      v10 = 0;
      v11 = mPreloadBuckets[preloadBucketIndex].size;
      if ( size )
      {
        v12 = mPreloadBuckets[preloadBucketIndex].p;
        do
        {
          v13 = 0;
          mSet = (*v12)->mInstance.mSet;
          mComponentCount = UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition.mEntities[mSet->mEntityIndex].mComponentCount;
          if ( mComponentCount )
          {
            p_p = &mSet->mFiles[0].p;
            while ( 1 )
            {
              v17 = *((_DWORD *)p_p - 2);
              v18 = 0;
              if ( v17 )
                break;
LABEL_14:
              ++v13;
              p_p += 2;
              if ( v13 >= mComponentCount )
                goto LABEL_19;
            }
            v19 = *p_p;
            while ( (*v19)->mRequest )
            {
              ++v18;
              ++v19;
              if ( v18 >= v17 )
                goto LABEL_14;
            }
            if ( (*v12)->mVarietyRatio > mVarietyRatio )
            {
              mVarietyRatio = (*v12)->mVarietyRatio;
              v11 = v10;
            }
          }
LABEL_19:
          ++v10;
          ++v12;
        }
        while ( v10 < size );
        reason = v21;
        candidate = v20;
      }
      if ( v11 != size )
      {
        *candidate = mPreloadBuckets[v5].p[v11];
        *reason = MoreParts;
      }
    }
  }
}

// File Line: 1250
// RVA: 0x445670
char __fastcall UFG::ResourcePool::UpdateAmbientPreloads(UFG::ResourcePool *this)
{
  UFG::ResourcePriorityBucket *mReservedBucket; // r10
  UFG::ResourcePriorityBucket *mCriticalBucket; // r9
  float mFragmentationReservePercentage; // xmm2_4
  float v5; // xmm1_4
  unsigned int v6; // r11d
  unsigned int v7; // r8d
  unsigned int v8; // edx
  unsigned int v9; // ebx
  unsigned int v10; // ecx
  unsigned int v11; // ecx
  unsigned int v12; // ebx
  UFG::ResourcePriorityBucket *mHighBucket; // r8
  unsigned int v14; // edx
  unsigned int v15; // r10d
  unsigned int mMaxModelMemory; // eax
  unsigned int v17; // r10d
  UFG::ResourcePriorityBucket *mLowBucket; // rdx
  unsigned int v19; // r9d
  unsigned int v20; // r11d
  signed int v21; // ecx
  unsigned int v22; // edx
  unsigned int mMaxTextureMemory; // eax
  signed int v24; // r10d
  unsigned int v25; // r8d
  float v26; // xmm0_4
  unsigned int v27; // edx

  if ( this->mDirty )
    UFG::ResourcePool::UpdateVarietyRatios(this);
  mReservedBucket = this->mReservedBucket;
  mCriticalBucket = this->mCriticalBucket;
  mFragmentationReservePercentage = this->mFragmentationReservePercentage;
  v5 = 0.0;
  v6 = 0;
  v7 = mReservedBucket->mMemoryUsage[0][1] + mReservedBucket->mMemoryUsage[1][1] + mReservedBucket->mMemoryUsage[2][1];
  v8 = 0;
  if ( mReservedBucket->mReserveSize[1] > 0 )
    v8 = mReservedBucket->mReserveSize[1];
  v9 = mCriticalBucket->mMemoryUsage[0][1] + mCriticalBucket->mMemoryUsage[1][1] + mCriticalBucket->mMemoryUsage[2][1];
  v10 = 0;
  if ( mCriticalBucket->mReserveSize[1] > 0 )
    v10 = mCriticalBucket->mReserveSize[1];
  if ( v10 > v9 )
    v9 = v10;
  v11 = 0;
  if ( v8 > v7 )
    v7 = v8;
  v12 = v7 + v9;
  mHighBucket = this->mHighBucket;
  v14 = mReservedBucket->mMemoryUsage[0][0] + mReservedBucket->mMemoryUsage[1][0] + mReservedBucket->mMemoryUsage[2][0];
  if ( mReservedBucket->mReserveSize[0] > 0 )
    v11 = mReservedBucket->mReserveSize[0];
  v15 = mCriticalBucket->mMemoryUsage[0][0] + mCriticalBucket->mMemoryUsage[1][0] + mCriticalBucket->mMemoryUsage[2][0];
  if ( mCriticalBucket->mReserveSize[0] > 0 )
    v6 = mCriticalBucket->mReserveSize[0];
  mMaxModelMemory = this->mMaxModelMemory;
  if ( v6 > v15 )
    v15 = v6;
  if ( v11 > v14 )
    v14 = v11;
  v17 = v14 + v15;
  mLowBucket = this->mLowBucket;
  v19 = mHighBucket->mMemoryUsage[0][1]
      + mHighBucket->mMemoryUsage[1][1]
      + mHighBucket->mMemoryUsage[2][1]
      + mLowBucket->mMemoryUsage[0][1]
      + mLowBucket->mMemoryUsage[1][1]
      + mLowBucket->mMemoryUsage[2][1];
  v20 = mHighBucket->mMemoryUsage[0][0]
      + mHighBucket->mMemoryUsage[1][0]
      + mHighBucket->mMemoryUsage[2][0]
      + mLowBucket->mMemoryUsage[0][0]
      + mLowBucket->mMemoryUsage[1][0]
      + mLowBucket->mMemoryUsage[2][0];
  v21 = this->mMaxModelMemory;
  if ( v12 < mMaxModelMemory )
    mMaxModelMemory = v12;
  v22 = v21 - mMaxModelMemory;
  this->mAmbientModelMemoryLimit = v21 - mMaxModelMemory;
  mMaxTextureMemory = this->mMaxTextureMemory;
  if ( v17 < mMaxTextureMemory )
    mMaxTextureMemory = v17;
  v24 = this->mMaxTextureMemory;
  v25 = v24 - mMaxTextureMemory;
  this->mAmbientTextureMemoryLimit = v24 - mMaxTextureMemory;
  v26 = (float)(int)(v22 - (int)(float)((float)v21 * mFragmentationReservePercentage));
  if ( v26 < 0.0 )
    v26 = 0.0;
  v27 = (int)v26;
  this->mAmbientModelMemoryLimit = (int)v26;
  if ( (float)(int)(v25 - (int)(float)((float)v24 * mFragmentationReservePercentage)) >= 0.0 )
    v5 = (float)(int)(v25 - (int)(float)((float)v24 * mFragmentationReservePercentage));
  this->mAmbientTextureMemoryLimit = (int)v5;
  if ( v20 > (int)v5 || v19 > v27 || this->mStreamerStalled && !this->mUnReferencedBucket->mResourceRequests.size )
  {
    UFG::ResourcePool::ContractAmbientModels(this, 1u);
  }
  else if ( v27 && (int)v5 )
  {
    return UFG::ResourcePool::ExpandAmbience(this);
  }
  return 0;
}

// File Line: 1302
// RVA: 0x438D20
char __fastcall UFG::ResourcePool::BasicAmbienceLoaded(UFG::ResourcePool *this)
{
  unsigned int size; // r12d
  unsigned int v2; // ebp
  UFG::EntityTypeState **p; // r14
  unsigned int v5; // r15d
  UFG::qArray<UFG::PreloadRequest *,0> *mPreloadBuckets; // rax
  int v7; // ebx
  unsigned int v8; // esi
  UFG::PreloadRequest **i; // rdi

  size = this->mEntityStates.size;
  v2 = 0;
  if ( size )
  {
    p = this->mEntityStates.p;
    v5 = 3;
    do
    {
      if ( (*p)->mActive && (*p)->mHasMinimumAmbienceRequirement )
      {
        mPreloadBuckets = this->mPreloadBuckets;
        v7 = 0;
        v8 = mPreloadBuckets[v5].size;
        if ( !v8 )
          return 0;
        for ( i = mPreloadBuckets[v5].p; !UFG::TrueCrowdSet::IsLoaded((*i)->mInstance.mSet); ++i )
        {
          if ( ++v7 >= v8 )
            return 0;
        }
      }
      ++v2;
      ++v5;
      ++p;
    }
    while ( v2 < size );
  }
  return 1;
}

// File Line: 1341
// RVA: 0x4428A0
UFG::PreloadRequest *__fastcall UFG::ResourcePool::RequestPreload(
        UFG::ResourcePool *this,
        UFG::TrueCrowdSet::Instance *instance,
        unsigned int preloadBucketIndex,
        bool directRequest)
{
  unsigned int mUID; // ebx
  unsigned int v7; // r14d
  BOOL v8; // r11d
  int v9; // edx
  __int64 v10; // r15
  UFG::qArray<UFG::PreloadRequest *,0> *mPreloadBuckets; // r8
  unsigned int size; // r9d
  UFG::PreloadRequest **p; // r8
  UFG::PreloadRequest *v14; // rax
  UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *mNext; // rsi
  UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *mPrev; // rcx
  UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *v18; // rax
  UFG::allocator::free_link *v19; // rax
  UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *v20; // rax
  UFG::qArray<UFG::PreloadRequest *,0> *v21; // r12
  unsigned int v22; // ecx
  unsigned int v23; // r13d
  unsigned int capacity; // ebp
  __int64 v25; // r8
  unsigned int v26; // ebp
  unsigned __int64 v27; // rax
  UFG::allocator::free_link *v28; // rax
  UFG::TrueCrowdSet *mSet; // rax
  UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *v30; // rcx
  UFG::allocator::free_link *v31; // [rsp+20h] [rbp-48h]
  BOOL v33; // [rsp+88h] [rbp+20h]

  if ( preloadBucketIndex )
  {
    if ( preloadBucketIndex == 1 )
    {
      mUID = qSymbol_Critical.mUID;
    }
    else if ( preloadBucketIndex == 2 )
    {
      mUID = qSymbol_High.mUID;
    }
    else
    {
      mUID = qSymbol_Low.mUID;
    }
  }
  else
  {
    mUID = qSymbol_Reserved.mUID;
  }
  v7 = 0;
  v8 = directRequest;
  v33 = v8;
  v9 = 0;
  v10 = preloadBucketIndex;
  mPreloadBuckets = this->mPreloadBuckets;
  size = mPreloadBuckets[v10].size;
  if ( size )
  {
    p = mPreloadBuckets[v10].p;
    while ( p[v9]->mInstance.mSet != instance->mSet )
    {
      if ( ++v9 >= size )
        goto LABEL_17;
    }
    v14 = p[v9];
    if ( v8 )
      ++v14->mDirectRequestCount;
    else
      v14->mSpawnSetValid = 1;
    return this->mPreloadBuckets[v10].p[v9];
  }
  else
  {
LABEL_17:
    if ( (UFG::qList<UFG::PreloadRequest,UFG::PreloadRequest,1,0> *)this->mEmptyRequestList.mNode.mNext == &this->mEmptyRequestList )
    {
      v19 = UFG::qMalloc(0x148ui64, "PreloadRequest", 0i64);
      if ( v19 )
      {
        UFG::PreloadRequest::PreloadRequest((UFG::PreloadRequest *)v19);
        mNext = v20;
      }
      else
      {
        mNext = 0i64;
      }
    }
    else
    {
      mNext = this->mEmptyRequestList.mNode.mNext;
      mPrev = mNext->mPrev;
      v18 = mNext->mNext;
      mPrev->mNext = v18;
      v18->mPrev = mPrev;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      BYTE1(mNext[19].mNext) = 0;
      BYTE4(mNext[20].mPrev) = 0;
      HIDWORD(mNext[19].mNext) = 0;
      mNext[1].mPrev = 0i64;
      LODWORD(mNext[1].mNext) = 0;
      mNext[2].mPrev = 0i64;
      LODWORD(mNext[2].mNext) = 0;
    }
    v21 = this->mPreloadBuckets;
    v22 = v21[v10].size;
    v23 = v22 + 1;
    capacity = v21[v10].capacity;
    v25 = 2i64;
    if ( v22 + 1 > capacity )
    {
      if ( capacity )
        v26 = 2 * capacity;
      else
        v26 = 1;
      for ( ; v26 < v23; v26 *= 2 )
        ;
      if ( v26 <= 2 )
        v26 = 2;
      if ( v26 - v23 > 0x10000 )
        v26 = v22 + 65537;
      if ( v26 != v22 )
      {
        v27 = 8i64 * v26;
        if ( !is_mul_ok(v26, 8ui64) )
          v27 = -1i64;
        v28 = UFG::qMalloc(v27, "qArray.Add", 0i64);
        v31 = v28;
        if ( v21[v10].p )
        {
          if ( v21[v10].size )
          {
            do
            {
              v28[v7] = (UFG::allocator::free_link)v21[v10].p[v7];
              ++v7;
            }
            while ( v7 < v21[v10].size );
          }
          operator delete[](v21[v10].p);
          v28 = v31;
        }
        v21[v10].p = (UFG::PreloadRequest **)v28;
        v21[v10].capacity = v26;
        v25 = 2i64;
      }
    }
    v21[v10].size = v23;
    this->mPreloadBuckets[v10].p[this->mPreloadBuckets[v10].size - 1] = (UFG::PreloadRequest *)mNext;
    if ( mUID == qSymbol_Low.mUID )
    {
      mSet = instance->mSet;
      LOBYTE(mNext[19].mNext) = 1;
      mNext[2].mPrev = (UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *)mSet;
    }
    else
    {
      LOBYTE(mNext[19].mNext) = 0;
      v30 = mNext + 2;
      if ( (((unsigned __int8)((_BYTE)mNext + 32) | (unsigned __int8)instance) & 0xF) != 0 )
      {
        memmove(v30, instance, 0x118ui64);
      }
      else
      {
        do
        {
          *v30 = *(UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *)&instance->mSet;
          v30[1] = *(UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *)&instance->mMorphWeights[1];
          v30[2] = *(UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *)&instance->mPart[0].mColourTint;
          v30[3] = *(UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *)&instance->mPart[1].mColourTint;
          v30[4] = *(UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *)&instance->mPart[2].mColourTint;
          v30[5] = *(UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *)&instance->mPart[3].mColourTint;
          v30[6] = *(UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *)&instance->mPart[4].mColourTint;
          v30 += 8;
          v30[-1] = *(UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *)&instance->mPart[5].mColourTint;
          instance = (UFG::TrueCrowdSet::Instance *)((char *)instance + 128);
          --v25;
        }
        while ( v25 );
        *v30 = *(UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *)&instance->mSet;
        v30[1].mPrev = *(UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> **)&instance->mMorphWeights[1];
      }
    }
    if ( v33 )
      ++HIDWORD(mNext[19].mNext);
    else
      BYTE1(mNext[19].mNext) = 1;
    LODWORD(mNext[20].mPrev) = mUID;
    return (UFG::PreloadRequest *)mNext;
  }
}

// File Line: 1398
// RVA: 0x441950
void __fastcall UFG::ResourcePool::ReleasePreload(
        UFG::ResourcePool *this,
        UFG::TrueCrowdSet *resourceSet,
        unsigned int preloadBucketIndex,
        bool directRequest)
{
  UFG::qArray<UFG::PreloadRequest *,0> *mPreloadBuckets; // rax
  BOOL v6; // ecx
  unsigned __int64 v7; // rsi
  int v9; // r9d
  unsigned int size; // edx
  UFG::PreloadRequest **i; // rax
  UFG::PreloadRequest *v12; // rbx
  __int64 v13; // rcx
  UFG::qArray<UFG::PreloadRequest *,0> *v14; // r9
  unsigned int v15; // r8d
  UFG::PreloadRequest **p; // rdx
  UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *mPrev; // rax

  mPreloadBuckets = this->mPreloadBuckets;
  v6 = directRequest;
  v7 = preloadBucketIndex;
  v9 = 0;
  size = mPreloadBuckets[v7].size;
  if ( size )
  {
    for ( i = mPreloadBuckets[v7].p; ; ++i )
    {
      v12 = *i;
      if ( (*i)->mInstance.mSet == resourceSet )
        break;
      if ( ++v9 >= size )
        return;
    }
    if ( v6 )
      --v12->mDirectRequestCount;
    else
      v12->mSpawnSetValid = 0;
    if ( !v12->mSpawnSetValid && !v12->mDirectRequestCount )
    {
      UFG::ResourcePool::ReleaseResourceSetFiles(this, v12);
      v13 = 0i64;
      v14 = &this->mPreloadBuckets[v7];
      v15 = v14->size;
      if ( v14->size )
      {
        p = v14->p;
        while ( v12 != p[v13] )
        {
          v13 = (unsigned int)(v13 + 1);
          if ( (unsigned int)v13 >= v15 )
            goto LABEL_20;
        }
        if ( (int)v13 >= 0 )
        {
          p[v13] = p[v15 - 1];
          if ( v14->size > 1 )
            --v14->size;
          else
            v14->size = 0;
        }
      }
LABEL_20:
      mPrev = this->mEmptyRequestList.mNode.mPrev;
      mPrev->mNext = v12;
      v12->mPrev = mPrev;
      v12->mNext = &this->mEmptyRequestList.mNode;
      this->mEmptyRequestList.mNode.mPrev = v12;
    }
  }
}

// File Line: 1423
// RVA: 0x4417C0
void __fastcall UFG::ResourcePool::ReleaseAmbientPreloads(
        UFG::ResourcePool *this,
        UFG::TrueCrowdResource::EntityType type)
{
  unsigned int size; // ecx
  int v4; // r8d
  UFG::EntityTypeState **i; // r9
  unsigned int v6; // r8d
  __int64 v7; // rsi
  UFG::qArray<UFG::PreloadRequest *,0> *mPreloadBuckets; // rax
  unsigned int v9; // r8d
  UFG::PreloadRequest **p; // rdx
  UFG::TrueCrowdSet *mSet; // rcx
  unsigned int v12; // eax
  UFG::PreloadRequest *v13; // rbx
  __int64 v14; // rcx
  UFG::qArray<UFG::PreloadRequest *,0> *v15; // r9
  unsigned int v16; // edx
  UFG::PreloadRequest **v17; // r8
  UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *mPrev; // rax

  size = this->mEntityStates.size;
  v4 = 0;
  if ( size )
  {
    for ( i = this->mEntityStates.p; type != (*i)->mEntityType; ++i )
    {
      if ( ++v4 >= size )
        return;
    }
    v6 = v4 + 3;
    if ( v6 != -1 )
    {
      v7 = v6;
      while ( this->mPreloadBuckets[v7].size )
      {
        mPreloadBuckets = this->mPreloadBuckets;
        v9 = mPreloadBuckets[v7].size;
        p = mPreloadBuckets[v7].p;
        mSet = p[v9 - 1]->mInstance.mSet;
        v12 = 0;
        if ( v9 )
        {
          while ( 1 )
          {
            v13 = *p;
            if ( (*p)->mInstance.mSet == mSet )
              break;
            ++v12;
            ++p;
            if ( v12 >= v9 )
              goto LABEL_23;
          }
          v13->mSpawnSetValid = 0;
          if ( !v13->mDirectRequestCount )
          {
            UFG::ResourcePool::ReleaseResourceSetFiles(this, v13);
            v14 = 0i64;
            v15 = &this->mPreloadBuckets[v7];
            v16 = v15->size;
            if ( v15->size )
            {
              v17 = v15->p;
              while ( v13 != v17[v14] )
              {
                v14 = (unsigned int)(v14 + 1);
                if ( (unsigned int)v14 >= v16 )
                  goto LABEL_22;
              }
              if ( (int)v14 >= 0 )
              {
                v17[v14] = v17[v16 - 1];
                if ( v15->size > 1 )
                  --v15->size;
                else
                  v15->size = 0;
              }
            }
LABEL_22:
            mPrev = this->mEmptyRequestList.mNode.mPrev;
            mPrev->mNext = v13;
            v13->mPrev = mPrev;
            v13->mNext = &this->mEmptyRequestList.mNode;
            this->mEmptyRequestList.mNode.mPrev = v13;
          }
        }
LABEL_23:
        ;
      }
    }
  }
}

// File Line: 1437
// RVA: 0x4398A0
char __fastcall UFG::ResourcePool::CanSpawnAmbient(
        UFG::ResourcePool *this,
        UFG::TrueCrowdSet *trueCrowdSet,
        bool preloadedOnly)
{
  unsigned int mNumPreloadBuckets; // r11d
  unsigned int v5; // r10d
  UFG::qArray<UFG::PreloadRequest *,0> *v6; // r9
  char v7; // di
  unsigned int v8; // edx
  UFG::PreloadRequest **p; // rax

  if ( !preloadedOnly )
    return UFG::TrueCrowdSet::IsLoaded(trueCrowdSet);
  mNumPreloadBuckets = this->mNumPreloadBuckets;
  v5 = 2;
  if ( mNumPreloadBuckets <= 2 )
    return 0;
  v6 = this->mPreloadBuckets + 2;
  v7 = 0;
  while ( 1 )
  {
    v8 = 0;
    if ( v6->size )
      break;
LABEL_8:
    ++v5;
    ++v6;
    if ( v5 >= mNumPreloadBuckets )
      return 0;
  }
  p = v6->p;
  while ( (*p)->mInstance.mSet != trueCrowdSet )
  {
    ++v8;
    ++p;
    if ( v8 >= v6->size )
      goto LABEL_8;
  }
  if ( UFG::TrueCrowdSet::IsLoaded(trueCrowdSet) )
  {
    if ( UFG::TrueCrowdSet::IsPreloaded(trueCrowdSet) )
      return 1;
  }
  return v7;
}

// File Line: 1459
// RVA: 0x447320
void __fastcall UFG::ResourcePool::UpdateVarietyRatios(UFG::ResourcePool *this)
{
  unsigned int mNumPreloadBuckets; // r10d
  int v2; // r15d
  __int64 v4; // r9
  UFG::qArray<UFG::PreloadRequest *,0> *v5; // r8
  __int64 v6; // rcx
  __int64 v7; // rdx
  unsigned int v8; // eax
  __int64 v9; // r12
  signed int v10; // ecx
  __int64 i; // rbp
  UFG::PreloadRequest *v12; // rdi
  UFG::TrueCrowdSet *mSet; // r14
  int v14; // r11d
  unsigned int mComponentCount; // esi
  UFG::TrueCrowdModel ***p_p; // r10
  __int64 v17; // rbx
  unsigned int v18; // eax
  unsigned int v19; // r8d
  UFG::TrueCrowdModel **v20; // rdx
  __int64 v21; // r9
  UFG::ResourceRequest *mRequest; // rcx
  int v23; // ecx
  int *mFiles; // rdx
  __int64 v25; // r8
  int v26; // [rsp+30h] [rbp+8h]

  mNumPreloadBuckets = this->mNumPreloadBuckets;
  v2 = 0;
  if ( mNumPreloadBuckets > 2 )
  {
    v4 = mNumPreloadBuckets - 2;
    v5 = this->mPreloadBuckets + 2;
    do
    {
      v6 = v5->size - 1;
      if ( (signed int)(v5->size - 1) >= 0 )
      {
        v7 = (__int64)&v5->p[v6];
        do
        {
          if ( *(_BYTE *)(*(_QWORD *)v7 + 324i64) )
            v2 += *(_DWORD *)(*(_QWORD *)v7 + 16i64);
          v7 -= 8i64;
          --v6;
        }
        while ( v6 >= 0 );
      }
      ++v5;
      --v4;
    }
    while ( v4 );
  }
  v8 = 2;
  v26 = 2;
  if ( mNumPreloadBuckets > 2 )
  {
    do
    {
      v9 = v8;
      v10 = this->mPreloadBuckets[v8].size - 1;
      for ( i = v10; i >= 0; --i )
      {
        v12 = this->mPreloadBuckets[v9].p[i];
        if ( v12->mPreloadActive )
        {
          mSet = v12->mInstance.mSet;
          v14 = 0xFFFFFF;
          mComponentCount = UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition.mEntities[mSet->mEntityIndex].mComponentCount;
          if ( mComponentCount )
          {
            p_p = &mSet->mFiles[0].p;
            v17 = mComponentCount;
            do
            {
              v18 = *((_DWORD *)p_p - 2);
              v19 = 0;
              if ( v18 )
              {
                v20 = *p_p;
                v21 = v18;
                do
                {
                  mRequest = (*v20)->mRequest;
                  if ( mRequest && mRequest->mLoadStatus == Loaded )
                    ++v19;
                  ++v20;
                  --v21;
                }
                while ( v21 );
              }
              if ( v14 > v19 )
                v14 = v19;
              p_p += 2;
              --v17;
            }
            while ( v17 );
          }
          v23 = 0xFFFFFF;
          if ( mComponentCount )
          {
            mFiles = (int *)mSet->mFiles;
            v25 = UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition.mEntities[mSet->mEntityIndex].mComponentCount;
            do
            {
              if ( v23 > (unsigned int)*mFiles )
                v23 = *mFiles;
              mFiles += 4;
              --v25;
            }
            while ( v25 );
          }
          v12->mVarietyRatio = (float)(1.0 - (float)((float)v14 / (float)v23))
                             * (float)((float)(int)v12->mDesiredInstanceCount / (float)v2);
        }
        else
        {
          v12->mVarietyRatio = 0.0;
        }
      }
      v8 = v26 + 1;
      v26 = v8;
    }
    while ( v8 < this->mNumPreloadBuckets );
  }
}

// File Line: 1494
// RVA: 0x4415D0
void __fastcall UFG::ResourcePool::ReleaseAllAmbientPreloads(UFG::ResourcePool *this)
{
  unsigned int i; // ebp
  __int64 v3; // r15
  signed int v4; // ecx
  __int64 v5; // rsi
  UFG::qList<UFG::PreloadRequest,UFG::PreloadRequest,1,0> *p_mEmptyRequestList; // r14
  UFG::PreloadRequest *v7; // rdi
  UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *mPrev; // rax

  for ( i = 2; i < this->mNumPreloadBuckets; this->mPreloadBuckets[v3].size = 0 )
  {
    v3 = i;
    v4 = this->mPreloadBuckets[i].size - 1;
    v5 = v4;
    if ( v4 >= 0 )
    {
      p_mEmptyRequestList = &this->mEmptyRequestList;
      do
      {
        v7 = this->mPreloadBuckets[i].p[v5];
        UFG::ResourcePool::ReleaseResourceSetFiles(this, v7);
        --v5;
        mPrev = p_mEmptyRequestList->mNode.mPrev;
        mPrev->mNext = v7;
        v7->mPrev = mPrev;
        v7->mNext = &p_mEmptyRequestList->mNode;
        p_mEmptyRequestList->mNode.mPrev = v7;
      }
      while ( v5 >= 0 );
    }
    ++i;
  }
}

