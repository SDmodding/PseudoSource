// File Line: 49
// RVA: 0x437140
void __fastcall UFG::ResourcePriorityBucket::ResourcePriorityBucket(UFG::ResourcePriorityBucket *this)
{
  UFG::ResourcePriorityBucket *v1; // rdi
  unsigned int v2; // ebx
  unsigned __int64 v3; // rax
  UFG::allocator::free_link *v4; // rax
  UFG::ResourceRequest **v5; // rsi

  v1 = this;
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
    if ( v1->mResourceRequests.p )
    {
      if ( v1->mResourceRequests.size > 0 )
      {
        do
        {
          v4[v2] = (UFG::allocator::free_link)v1->mResourceRequests.p[v2];
          ++v2;
        }
        while ( v2 < v1->mResourceRequests.size );
      }
      operator delete[](v1->mResourceRequests.p);
    }
    v1->mResourceRequests.p = v5;
    v1->mResourceRequests.capacity = 16;
  }
  UFG::qMemSet(v1->mMemoryUsage, 0, 0x18u);
}

// File Line: 88
// RVA: 0x4479C0
char __fastcall UFG::ResourcePriorityBucket::WillFitWithinSizeConstraints(UFG::ResourcePriorityBucket *this, UFG::TrueCrowdSet::Instance *instance)
{
  int v2; // edi
  UFG::TrueCrowdSet::Instance *v3; // rsi
  int v4; // ebx
  signed int v5; // edi
  signed int v6; // ebx
  UFG::PartDatabase *v7; // rax
  UFG::PartPool::Bucket *v8; // r8
  float v9; // xmm0_4
  int v10; // ecx
  signed int v11; // er14
  int v12; // eax
  float v13; // xmm0_4
  signed int v14; // ebp
  unsigned int v15; // eax
  char v16; // r10
  unsigned int v17; // er11
  unsigned int v18; // er9
  UFG::ModelTextureCombination *v19; // r8
  __int64 v20; // rbx
  __int64 v21; // rcx
  __int64 v22; // rdx
  __int64 v23; // rax
  __int64 v24; // rax
  signed __int64 v25; // rcx
  __int64 v26; // rax
  signed __int64 v27; // rdx
  __int64 v28; // rax
  signed __int64 v29; // rax
  __int64 v30; // rcx

  v2 = this->mMaxSize[1];
  v3 = instance;
  if ( v2 == -1 )
    return 1;
  v4 = this->mMaxSize[0];
  if ( v4 == -1 )
    return 1;
  v5 = v2 - (this->mMemoryUsage[0][1] + this->mMemoryUsage[1][1] + this->mMemoryUsage[2][1]);
  v6 = v4 - (this->mMemoryUsage[0][0] + this->mMemoryUsage[1][0] + this->mMemoryUsage[2][0]);
  v7 = UFG::PartDatabase::Instance();
  v8 = v7->mPool.mMasterBucket;
  v9 = (float)v5;
  v10 = v7->mPool.mMaxModelMemory - v8->mMemoryUsageModel - v7->mPool.mExternalUsedModelMemory;
  if ( (float)v5 >= (float)v10 )
    v9 = (float)v10;
  v11 = (signed int)v9;
  v12 = v7->mPool.mMaxTextureMemory - v8->mMemoryUsageTexture - v7->mPool.mExternalUsedTextureMemory;
  v13 = (float)v6;
  if ( (float)v6 >= (float)v12 )
    v13 = (float)v12;
  v14 = (signed int)v13;
  if ( v11 <= 0 || v14 <= 0 )
    return 0;
  v15 = v3->mNumParts;
  v16 = 0;
  v17 = 0;
  v18 = 0;
  if ( !v15 )
    return 1;
  v19 = v3->mPart;
  v20 = v15;
  do
  {
    v21 = v19->mModelIndex;
    if ( (_DWORD)v21 != -1 )
    {
      v22 = *(_QWORD *)(*(_QWORD *)((char *)&v19[2].mModelIndex + (unsigned __int64)v3->mSet - (_QWORD)v3) + 8 * v21);
      v23 = *(_QWORD *)(v22 + 8);
      if ( !v23 || *(_DWORD *)(v23 + 20) != 3 )
      {
        v17 += *(_DWORD *)(v22 + 16);
        v18 += *(_DWORD *)(v22 + 20);
      }
      if ( *(_WORD *)(v22 + 58) > 0u )
      {
        v24 = *(_QWORD *)(v22 + 72);
        if ( v24 )
          v25 = v24 + v22 + 72;
        else
          v25 = 0i64;
        v26 = v19->mTextureSetIndex;
        v27 = v25 + 8 * v26;
        v28 = *(_QWORD *)(v25 + 8 * v26);
        if ( v28 )
          v29 = v27 + v28;
        else
          v29 = 0i64;
        v30 = *(_QWORD *)(v29 + 8);
        if ( !v30 || *(_DWORD *)(v30 + 20) != 3 )
          v18 += *(_DWORD *)(v29 + 20);
      }
    }
    ++v19;
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
  UFG::ResourcePriorityBucket *v1; // rbx
  signed __int64 v2; // rsi
  unsigned int v3; // edi
  unsigned int i; // er8
  UFG::ResourceRequest *v5; // r9
  UFG::TrueCrowdResource *v6; // rdx
  signed __int64 v7; // rcx
  signed __int64 v8; // rdx
  signed __int64 v9; // r8
  signed __int64 v10; // rax
  signed __int64 v11; // r9

  v1 = this;
  UFG::qMemSet(this->mMemoryUsage, 0, 0x18u);
  v2 = 0i64;
  v3 = 0;
  if ( v1->mChildren.size )
  {
    do
      UFG::ResourcePriorityBucket::UpdateSize(v1->mChildren.p[v3++]);
    while ( v3 < v1->mChildren.size );
  }
  for ( i = 0; i < v1->mResourceRequests.size; *(_DWORD *)(v8 + 24) += v5->mResource->mTextureSize )
  {
    v5 = v1->mResourceRequests.p[i];
    v6 = v5->mResource;
    if ( v5->mType == 1 )
    {
      v7 = (signed __int64)v1 + 8 * (signed int)v6->mType.mValue;
      *(_DWORD *)(v7 + 28) += v6->mModelSize;
    }
    ++i;
    v8 = (signed __int64)v1 + 8 * (signed int)v6->mType.mValue;
  }
  if ( v1->mChildren.size > 0 )
  {
    do
    {
      v9 = v2;
      v10 = (signed __int64)v1->mMemoryUsage;
      v11 = 3i64;
      do
      {
        v10 += 8i64;
        *(_DWORD *)(v10 - 4) += *(int *)((char *)&v1->mChildren.p[v9]->mMaxSize[-5] + v10 - (_QWORD)v1);
        *(_DWORD *)(v10 - 8) += *(_DWORD *)((char *)v1->mChildren.p[v9] - (char *)v1 + v10 - 8);
        --v11;
      }
      while ( v11 );
      v2 = (unsigned int)(v2 + 1);
    }
    while ( (unsigned int)v2 < v1->mChildren.size );
  }
}

// File Line: 137
// RVA: 0x446670
void __fastcall UFG::ResourcePriorityBucket::UpdatePriority(UFG::ResourcePriorityBucket *this, unsigned int priority)
{
  __int64 v2; // rbx
  unsigned int v3; // edi
  UFG::ResourcePriorityBucket *v4; // rsi

  v2 = 0i64;
  v3 = priority;
  v4 = this;
  this->mPriority = priority;
  if ( this->mChildren.size )
  {
    do
    {
      v3 += v2 + 1;
      UFG::ResourcePriorityBucket::UpdatePriority(v4->mChildren.p[v2], v3);
      v2 = (unsigned int)(v2 + 1);
    }
    while ( (unsigned int)v2 < v4->mChildren.size );
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
  UFG::ResourcePool *v1; // rbx
  UFG::qList<UFG::PreloadRequest,UFG::PreloadRequest,1,0> *v2; // rdi
  unsigned __int64 v3; // rax
  UFG::allocator::free_link *v4; // rsi
  unsigned int i; // er8
  unsigned __int64 v6; // rax
  UFG::allocator::free_link *v7; // rsi
  unsigned int j; // er8
  unsigned __int64 v9; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::ResourceRequest **v11; // rsi
  unsigned int k; // er9
  signed __int64 v13; // rsi
  UFG::allocator::free_link *v14; // rax
  UFG::allocator::free_link *v15; // rcx
  signed int v16; // edx
  UFG::allocator::free_link *v17; // rax
  UFG::allocator::free_link *v18; // rax
  UFG::qList<UFG::ResourceRequest,UFG::ResourceRequest,1,0> *v19; // [rsp+68h] [rbp+10h]

  v1 = this;
  this->mQueued.p = 0i64;
  *(_QWORD *)&this->mQueued.size = 0i64;
  this->mLoading.p = 0i64;
  *(_QWORD *)&this->mLoading.size = 0i64;
  this->mLoaded.p = 0i64;
  *(_QWORD *)&this->mLoaded.size = 0i64;
  v19 = &this->mRequestList;
  v19->mNode.mPrev = &v19->mNode;
  v19->mNode.mNext = &v19->mNode;
  this->mEntityStates.p = 0i64;
  *(_QWORD *)&this->mEntityStates.size = 0i64;
  v2 = &this->mEmptyRequestList;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  *(_QWORD *)&this->mMaxModelMemory = 0i64;
  *(_QWORD *)&this->mAmbientModelMemoryLimit = 0i64;
  this->mFragmentationReservePercentage = 0.15000001;
  *(_WORD *)&this->mStreamerStalled = 256;
  if ( this->mQueued.capacity < 0x20 && this->mQueued.size != 32 )
  {
    v3 = 256i64;
    if ( !is_mul_ok(0x20ui64, 8ui64) )
      v3 = -1i64;
    v4 = UFG::qMalloc(v3, "ResourcePool", 0i64);
    if ( v1->mQueued.p )
    {
      for ( i = 0; i < v1->mQueued.size; ++i )
        v4[i] = (UFG::allocator::free_link)v1->mQueued.p[i];
      operator delete[](v1->mQueued.p);
    }
    v1->mQueued.p = (UFG::ResourceRequest **)v4;
    v1->mQueued.capacity = 32;
  }
  if ( v1->mLoading.capacity < 0x20 && v1->mLoading.size != 32 )
  {
    v6 = 256i64;
    if ( !is_mul_ok(0x20ui64, 8ui64) )
      v6 = -1i64;
    v7 = UFG::qMalloc(v6, "ResourcePool", 0i64);
    if ( v1->mLoading.p )
    {
      for ( j = 0; j < v1->mLoading.size; ++j )
        v7[j] = (UFG::allocator::free_link)v1->mLoading.p[j];
      operator delete[](v1->mLoading.p);
    }
    v1->mLoading.p = (UFG::ResourceRequest **)v7;
    v1->mLoading.capacity = 32;
  }
  if ( v1->mLoaded.capacity < 0x20 && v1->mLoaded.size != 32 )
  {
    v9 = 256i64;
    if ( !is_mul_ok(0x20ui64, 8ui64) )
      v9 = -1i64;
    v10 = UFG::qMalloc(v9, "ResourcePool", 0i64);
    v11 = (UFG::ResourceRequest **)v10;
    if ( v1->mLoaded.p )
    {
      for ( k = 0; k < v1->mLoaded.size; ++k )
        v10[k] = (UFG::allocator::free_link)v1->mLoaded.p[k];
      operator delete[](v1->mLoaded.p);
    }
    v1->mLoaded.p = v11;
    v1->mLoaded.capacity = 32;
  }
  UFG::ResourcePool::InitPriorityBuckets(v1);
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
    v18 = (UFG::allocator::free_link *)v2->mNode.mPrev;
    v18[1].mNext = v15;
    v15->mNext = v18;
    v15[1].mNext = (UFG::allocator::free_link *)v2;
    v2->mNode.mPrev = (UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *)v15;
    --v13;
  }
  while ( v13 );
}

// File Line: 247
// RVA: 0x437D00
void __fastcall UFG::ResourcePool::~ResourcePool(UFG::ResourcePool *this)
{
  UFG::ResourcePool *v1; // rdi
  UFG::ResourcePriorityBucket *v2; // rbx
  UFG::ResourceRequest **v3; // rcx
  UFG::ResourcePriorityBucket **v4; // rcx
  UFG::ResourcePriorityBucket *v5; // rbx
  UFG::ResourceRequest **v6; // rcx
  UFG::ResourcePriorityBucket **v7; // rcx
  UFG::ResourcePriorityBucket *v8; // rbx
  UFG::ResourceRequest **v9; // rcx
  UFG::ResourcePriorityBucket **v10; // rcx
  UFG::ResourcePriorityBucket *v11; // rbx
  UFG::ResourceRequest **v12; // rcx
  UFG::ResourcePriorityBucket **v13; // rcx
  UFG::ResourcePriorityBucket *v14; // rbx
  UFG::ResourceRequest **v15; // rcx
  UFG::ResourcePriorityBucket **v16; // rcx
  UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *v17; // rcx
  UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *v18; // rax
  UFG::EntityTypeState **v19; // rcx
  UFG::qNode<UFG::ResourceRequest,UFG::ResourceRequest> *v20; // rcx
  UFG::qNode<UFG::ResourceRequest,UFG::ResourceRequest> *v21; // rax
  UFG::ResourceRequest **v22; // rcx
  UFG::ResourceRequest **v23; // rcx
  UFG::ResourceRequest **v24; // rcx

  v1 = this;
  v2 = this->mMasterBucket;
  if ( v2 )
  {
    v3 = v2->mResourceRequests.p;
    if ( v3 )
      operator delete[](v3);
    v2->mResourceRequests.p = 0i64;
    *(_QWORD *)&v2->mResourceRequests.size = 0i64;
    v4 = v2->mChildren.p;
    if ( v4 )
      operator delete[](v4);
    v2->mChildren.p = 0i64;
    *(_QWORD *)&v2->mChildren.size = 0i64;
    operator delete[](v2);
  }
  v5 = v1->mReservedBucket;
  if ( v5 )
  {
    v6 = v5->mResourceRequests.p;
    if ( v6 )
      operator delete[](v6);
    v5->mResourceRequests.p = 0i64;
    *(_QWORD *)&v5->mResourceRequests.size = 0i64;
    v7 = v5->mChildren.p;
    if ( v7 )
      operator delete[](v7);
    v5->mChildren.p = 0i64;
    *(_QWORD *)&v5->mChildren.size = 0i64;
    operator delete[](v5);
  }
  v8 = v1->mCriticalBucket;
  if ( v8 )
  {
    v9 = v8->mResourceRequests.p;
    if ( v9 )
      operator delete[](v9);
    v8->mResourceRequests.p = 0i64;
    *(_QWORD *)&v8->mResourceRequests.size = 0i64;
    v10 = v8->mChildren.p;
    if ( v10 )
      operator delete[](v10);
    v8->mChildren.p = 0i64;
    *(_QWORD *)&v8->mChildren.size = 0i64;
    operator delete[](v8);
  }
  v11 = v1->mHighBucket;
  if ( v11 )
  {
    v12 = v11->mResourceRequests.p;
    if ( v12 )
      operator delete[](v12);
    v11->mResourceRequests.p = 0i64;
    *(_QWORD *)&v11->mResourceRequests.size = 0i64;
    v13 = v11->mChildren.p;
    if ( v13 )
      operator delete[](v13);
    v11->mChildren.p = 0i64;
    *(_QWORD *)&v11->mChildren.size = 0i64;
    operator delete[](v11);
  }
  v14 = v1->mLowBucket;
  if ( v14 )
  {
    v15 = v14->mResourceRequests.p;
    if ( v15 )
      operator delete[](v15);
    v14->mResourceRequests.p = 0i64;
    *(_QWORD *)&v14->mResourceRequests.size = 0i64;
    v16 = v14->mChildren.p;
    if ( v16 )
      operator delete[](v16);
    v14->mChildren.p = 0i64;
    *(_QWORD *)&v14->mChildren.size = 0i64;
    operator delete[](v14);
  }
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&v1->mEmptyRequestList);
  v17 = v1->mEmptyRequestList.mNode.mPrev;
  v18 = v1->mEmptyRequestList.mNode.mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  v1->mEmptyRequestList.mNode.mPrev = &v1->mEmptyRequestList.mNode;
  v1->mEmptyRequestList.mNode.mNext = &v1->mEmptyRequestList.mNode;
  v19 = v1->mEntityStates.p;
  if ( v19 )
    operator delete[](v19);
  v1->mEntityStates.p = 0i64;
  *(_QWORD *)&v1->mEntityStates.size = 0i64;
  UFG::qList<UFG::ResourceRequest,UFG::ResourceRequest,1,0>::DeleteNodes(&v1->mRequestList);
  v20 = v1->mRequestList.mNode.mPrev;
  v21 = v1->mRequestList.mNode.mNext;
  v20->mNext = v21;
  v21->mPrev = v20;
  v1->mRequestList.mNode.mPrev = &v1->mRequestList.mNode;
  v1->mRequestList.mNode.mNext = &v1->mRequestList.mNode;
  v22 = v1->mLoaded.p;
  if ( v22 )
    operator delete[](v22);
  v1->mLoaded.p = 0i64;
  *(_QWORD *)&v1->mLoaded.size = 0i64;
  v23 = v1->mLoading.p;
  if ( v23 )
    operator delete[](v23);
  v1->mLoading.p = 0i64;
  *(_QWORD *)&v1->mLoading.size = 0i64;
  v24 = v1->mQueued.p;
  if ( v24 )
    operator delete[](v24);
  v1->mQueued.p = 0i64;
  *(_QWORD *)&v1->mQueued.size = 0i64;
}

// File Line: 256
// RVA: 0x43EE10
void __fastcall UFG::ResourcePool::InitPriorityBuckets(UFG::ResourcePool *this)
{
  UFG::ResourcePool *v1; // rsi
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
  UFG::ResourcePriorityBucket *v15; // rsi
  unsigned int i; // ebx

  v1 = this;
  v2 = UFG::qMalloc(0x58ui64, "ResourcePriorityBucket", 0i64);
  v3 = 0;
  if ( v2 )
    UFG::ResourcePriorityBucket::ResourcePriorityBucket((UFG::ResourcePriorityBucket *)v2);
  else
    v4 = 0i64;
  v1->mMasterBucket = v4;
  v5 = UFG::qMalloc(0x58ui64, "ResourcePriorityBucket", 0i64);
  if ( v5 )
    UFG::ResourcePriorityBucket::ResourcePriorityBucket((UFG::ResourcePriorityBucket *)v5);
  else
    v6 = 0i64;
  v1->mReservedBucket = v6;
  UFG::ResourcePriorityBucket::AddChild(v1->mMasterBucket, v6);
  v7 = UFG::qMalloc(0x58ui64, "ResourcePriorityBucket", 0i64);
  if ( v7 )
    UFG::ResourcePriorityBucket::ResourcePriorityBucket((UFG::ResourcePriorityBucket *)v7);
  else
    v8 = 0i64;
  v1->mUnReferencedBucket = v8;
  UFG::ResourcePriorityBucket::AddChild(v1->mMasterBucket, v8);
  v9 = UFG::qMalloc(0x58ui64, "ResourcePriorityBucket", 0i64);
  if ( v9 )
    UFG::ResourcePriorityBucket::ResourcePriorityBucket((UFG::ResourcePriorityBucket *)v9);
  else
    v10 = 0i64;
  v1->mCriticalBucket = v10;
  UFG::ResourcePriorityBucket::AddChild(v1->mMasterBucket, v10);
  v11 = UFG::qMalloc(0x58ui64, "ResourcePriorityBucket", 0i64);
  if ( v11 )
    UFG::ResourcePriorityBucket::ResourcePriorityBucket((UFG::ResourcePriorityBucket *)v11);
  else
    v12 = 0i64;
  v1->mHighBucket = v12;
  UFG::ResourcePriorityBucket::AddChild(v1->mMasterBucket, v12);
  v13 = UFG::qMalloc(0x58ui64, "ResourcePriorityBucket", 0i64);
  if ( v13 )
    UFG::ResourcePriorityBucket::ResourcePriorityBucket((UFG::ResourcePriorityBucket *)v13);
  else
    v14 = 0i64;
  v1->mLowBucket = v14;
  UFG::ResourcePriorityBucket::AddChild(v1->mMasterBucket, v14);
  UFG::ResourcePriorityBucket::UpdateSize(v1->mMasterBucket);
  v15 = v1->mMasterBucket;
  v15->mPriority = 0;
  for ( i = 0; i < v15->mChildren.size; ++i )
  {
    v3 += i + 1;
    UFG::ResourcePriorityBucket::UpdatePriority(v15->mChildren.p[i], v3);
  }
}

// File Line: 275
// RVA: 0x43E2D0
void __fastcall UFG::ResourcePool::Init(UFG::ResourcePool *this, UFG::StreamingMemory::DATA_TYPE streamingPool, UFG::StreamingMemory::DATA_TYPE streamingPoolVRam, UFG::qArray<UFG::EntityTypeState *,0> *resourceDescriptorList)
{
  UFG::qArray<UFG::EntityTypeState *,0> *v4; // r12
  UFG::StreamingMemory::DATA_TYPE v5; // edi
  UFG::StreamingMemory::DATA_TYPE v6; // ebx
  UFG::ResourcePool *v7; // r13
  UFG::qArray<UFG::EntityTypeState *,0> *v8; // rdi
  __int64 v9; // rbp
  __int64 v10; // r15
  unsigned int v11; // esi
  unsigned int v12; // ebx
  unsigned int v13; // ebx
  unsigned __int64 v14; // rax
  UFG::allocator::free_link *v15; // rax
  UFG::EntityTypeState **v16; // r14
  __int64 v17; // r9
  unsigned int v18; // eax
  int v19; // edi
  signed __int64 v20; // rax
  unsigned __int64 v21; // kr00_8
  unsigned __int8 v22; // cf
  unsigned __int64 v23; // rax
  UFG::allocator::free_link *v24; // rax
  signed __int64 v25; // rbx
  unsigned int v26; // esi
  signed __int64 v27; // rbx
  unsigned __int64 v28; // rax
  UFG::allocator::free_link *v29; // rax
  UFG::allocator::free_link *v30; // rdi
  __int64 v31; // r9
  UFG::ResourcePool *v32; // [rsp+80h] [rbp+8h]
  UFG::EntityTypeState **v33; // [rsp+98h] [rbp+20h]

  v32 = this;
  v4 = resourceDescriptorList;
  v5 = streamingPoolVRam;
  v6 = streamingPool;
  v7 = this;
  this->mMaxModelMemory = (signed int)(float)((float)(signed int)UFG::PartDatabase::Instance()->mPool.mMaxModelMemory
                                            * 0.94999999);
  v7->mMaxTextureMemory = (signed int)(float)((float)(signed int)UFG::PartDatabase::Instance()->mPool.mMaxTextureMemory
                                            * 0.94999999);
  v7->mStreamingPoolId = v6;
  v7->mStreamingPoolIdVRam = v5;
  *(_QWORD *)&v7->mAmbientModelMemoryLimit = 0i64;
  v8 = &v7->mEntityStates;
  if ( v4->size > v7->mEntityStates.capacity )
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
      (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&v7->mEntityStates,
      v4->size,
      "ResourcePool");
  v9 = 0i64;
  if ( v4->size )
  {
    do
    {
      v33 = v4->p;
      v10 = v8->size;
      v11 = v10 + 1;
      v12 = v7->mEntityStates.capacity;
      if ( (signed int)v10 + 1 > v12 )
      {
        if ( v12 )
          v13 = 2 * v12;
        else
          v13 = 1;
        for ( ; v13 < v11; v13 *= 2 )
          ;
        if ( v13 <= 2 )
          v13 = 2;
        if ( v13 - v11 > 0x10000 )
          v13 = v10 + 65537;
        if ( v13 != (_DWORD)v10 )
        {
          v14 = 8i64 * v13;
          if ( !is_mul_ok(v13, 8ui64) )
            v14 = -1i64;
          v15 = UFG::qMalloc(v14, "qArray.Add", 0i64);
          v16 = (UFG::EntityTypeState **)v15;
          if ( v7->mEntityStates.p )
          {
            v17 = 0i64;
            if ( v8->size )
            {
              do
              {
                v15[v17] = (UFG::allocator::free_link)v7->mEntityStates.p[v17];
                v17 = (unsigned int)(v17 + 1);
              }
              while ( (unsigned int)v17 < v8->size );
            }
            operator delete[](v7->mEntityStates.p);
          }
          v7->mEntityStates.p = v16;
          v7->mEntityStates.capacity = v13;
        }
      }
      v8->size = v11;
      v7->mEntityStates.p[v10] = v33[v9];
      v9 = (unsigned int)(v9 + 1);
    }
    while ( (unsigned int)v9 < v4->size );
    v7 = v32;
  }
  v18 = v4->size + 3;
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
    v25 = (signed __int64)&v24[1];
    `eh vector constructor iterator'(
      &v24[1],
      0x10ui64,
      v19,
      (void (__fastcall *)(void *))UFG::qArray<UFG::qSymbolUC,0>::qArray<UFG::qSymbolUC,0>);
  }
  else
  {
    v25 = 0i64;
  }
  v7->mPreloadBuckets = (UFG::qArray<UFG::PreloadRequest *,0> *)v25;
  v26 = 0;
  if ( v7->mNumPreloadBuckets )
  {
    do
    {
      v27 = (signed __int64)&v7->mPreloadBuckets[v26];
      if ( *(_DWORD *)(v27 + 4) < 0x20u && *(_DWORD *)v27 != 32 )
      {
        v28 = 256i64;
        if ( !is_mul_ok(0x20ui64, 8ui64) )
          v28 = -1i64;
        v29 = UFG::qMalloc(v28, "ResourcePool", 0i64);
        v30 = v29;
        if ( *(_QWORD *)(v27 + 8) )
        {
          v31 = 0i64;
          if ( *(_DWORD *)v27 )
          {
            do
            {
              v29[v31] = *(UFG::allocator::free_link *)(*(_QWORD *)(v27 + 8) + 8 * v31);
              v31 = (unsigned int)(v31 + 1);
            }
            while ( (unsigned int)v31 < *(_DWORD *)v27 );
          }
          operator delete[](*(void **)(v27 + 8));
        }
        *(_QWORD *)(v27 + 8) = v30;
        *(_DWORD *)(v27 + 4) = 32;
      }
      ++v26;
    }
    while ( v26 < v7->mNumPreloadBuckets );
  }
}

// File Line: 316
// RVA: 0x4459D0
void __fastcall UFG::ResourcePool::UpdateBuckets(UFG::ResourcePool *this)
{
  UFG::ResourcePool *v1; // r13
  UFG::ResourcePool *v2; // r15
  UFG::qList<UFG::ResourceRequest,UFG::ResourceRequest,1,0> *v3; // r13
  UFG::ResourceRequest **v4; // r12
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
  signed __int64 v16; // r9
  signed __int64 v17; // r8
  __int64 v18; // rax
  UFG::ResourcePriorityBucket *v19; // [rsp+20h] [rbp-68h]
  UFG::ResourcePriorityBucket *v20; // [rsp+28h] [rbp-60h]
  UFG::ResourcePriorityBucket *v21; // [rsp+30h] [rbp-58h]
  UFG::ResourcePriorityBucket *v22; // [rsp+38h] [rbp-50h]
  UFG::ResourcePriorityBucket *v23; // [rsp+40h] [rbp-48h]
  UFG::ResourcePool *v24; // [rsp+90h] [rbp+8h]

  v24 = this;
  v1 = this;
  this->mUnReferencedBucket->mResourceRequests.size = 0;
  this->mReservedBucket->mResourceRequests.size = 0;
  this->mCriticalBucket->mResourceRequests.size = 0;
  this->mHighBucket->mResourceRequests.size = 0;
  this->mLowBucket->mResourceRequests.size = 0;
  v2 = (UFG::ResourcePool *)this->mRequestList.mNode.mNext;
  v19 = this->mUnReferencedBucket;
  v20 = this->mReservedBucket;
  v21 = this->mCriticalBucket;
  v22 = this->mHighBucket;
  v23 = this->mLowBucket;
  if ( v2 != (UFG::ResourcePool *)&this->mRequestList )
  {
    v3 = &this->mRequestList;
    do
    {
      v4 = v2->mQueued.p;
      v5 = 0;
      v6 = (_DWORD *)((char *)&v2->mRequestList.mNode.mPrev + 4);
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
      v8 = (__int64)*(&v19 + v7);
      v9 = *(unsigned int *)(v8 + 72);
      v10 = *(_DWORD *)(v8 + 76);
      v11 = v9 + 1;
      if ( (signed int)v9 + 1 > v10 )
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
            v16 = 0i64;
            if ( *(_DWORD *)(v8 + 72) )
            {
              do
              {
                v17 = v16;
                v16 = (unsigned int)(v16 + 1);
                v14[v17] = *(UFG::allocator::free_link *)(v17 * 8 + *(_QWORD *)(v8 + 80));
              }
              while ( (unsigned int)v16 < *(_DWORD *)(v8 + 72) );
            }
            operator delete[](*(void **)(v8 + 80));
          }
          *(_QWORD *)(v8 + 80) = v15;
          *(_DWORD *)(v8 + 76) = v12;
        }
      }
      v18 = *(_QWORD *)(v8 + 80);
      *(_DWORD *)(v8 + 72) = v11;
      *(_QWORD *)(v18 + 8 * v9) = v2;
      v2 = (UFG::ResourcePool *)v4;
    }
    while ( v4 != (UFG::ResourceRequest **)v3 );
    v1 = v24;
  }
  UFG::ResourcePriorityBucket::UpdateSize(v1->mMasterBucket);
}

// File Line: 344
// RVA: 0x443420
bool __fastcall UFG::SortQueuedRequests(UFG::ResourceRequest *reqA, UFG::ResourceRequest *reqB)
{
  unsigned int *v2; // rax
  unsigned int v3; // er8
  unsigned int v4; // er9

  v2 = reqB->mPriorityRefCounts;
  v3 = 0;
  while ( 1 )
  {
    v4 = *(unsigned int *)((char *)v2 + (char *)reqA - (char *)reqB);
    if ( v4 != *v2 )
      break;
    ++v3;
    ++v2;
    if ( v3 >= 5 )
      return reqA->mResource->mModelSize + reqA->mResource->mTextureSize < reqB->mResource->mModelSize
                                                                         + reqB->mResource->mTextureSize;
  }
  return v4 > *v2;
}

// File Line: 356
// RVA: 0x447110
void __fastcall UFG::ResourcePool::UpdateRequests(UFG::ResourcePool *this)
{
  UFG::ResourcePool *v1; // rbx
  unsigned int v2; // eax
  char v3; // al
  __int64 v4; // rsi
  UFG::ResourceRequest **v5; // rdi
  Render::IrradianceVolume *right; // [rsp+18h] [rbp-1010h]
  char dest; // [rsp+20h] [rbp-1008h]
  UFG::StreamingMemory::DATA_TYPE dataTypes; // [rsp+1030h] [rbp+8h]
  UFG::StreamingMemory::DATA_TYPE v9; // [rsp+1034h] [rbp+Ch]

  v1 = this;
  if ( this->mDirty )
    UFG::ResourcePool::UpdateBuckets(this);
  v2 = v1->mLoading.size;
  v1->mStreamerStalled = 0;
  if ( v1->mQueued.size + v2 )
  {
    dataTypes = v1->mStreamingPoolId;
    v9 = v1->mStreamingPoolIdVRam;
    v3 = UFG::DataStreamer::IsStalled(&dataTypes, 2u);
    v1->mStreamerStalled = v3;
    if ( !v3 )
    {
      v4 = v1->mQueued.size;
      if ( (_DWORD)v4 )
      {
        UFG::qMemCopy(&dest, v1->mQueued.p, 8 * v4);
        UFG::qQuickSortImpl<Render::Light *,bool (*)(Render::Light const *,Render::Light const *)>(
          (Render::IrradianceVolume **)&dest,
          &right + (signed int)v4,
          (bool (__fastcall *)(Render::IrradianceVolume *, Render::IrradianceVolume *))UFG::SortQueuedRequests);
        if ( (_DWORD)v4 )
        {
          v5 = (UFG::ResourceRequest **)&dest;
          do
          {
            UFG::ResourcePool::QueueRequest(v1, *v5);
            ++v5;
            --v4;
          }
          while ( v4 );
          UFG::ResourcePriorityBucket::UpdateSize(v1->mMasterBucket);
        }
      }
    }
  }
}

// File Line: 400
// RVA: 0x43CE40
void __fastcall UFG::ResourcePool::FlushResources(UFG::ResourcePool *this, bool forceFlush)
{
  float v2; // xmm1_4
  bool v3; // r14
  UFG::ResourcePool *v4; // rsi
  unsigned int v5; // edi
  unsigned int v6; // ebx
  UFG::ResourcePriorityBucket *v7; // rax
  unsigned int v8; // er13
  unsigned int v9; // er12
  UFG::ResourcePriorityBucket *v10; // rcx
  __int64 v11; // rax
  unsigned int v12; // ebp
  __int64 v13; // r15
  unsigned int v14; // edx
  UFG::ResourceRequest *v15; // r14
  __int64 v16; // rcx
  UFG::TrueCrowdResource *v17; // rax
  UFG::ResourceRequest **v18; // r8
  unsigned int v19; // edx
  __int64 v20; // rcx
  UFG::ResourceRequest **v21; // r8
  unsigned int v22; // eax
  unsigned int v23; // edx
  __int64 v24; // rcx
  UFG::ResourceRequest **v25; // r8
  unsigned int v26; // eax
  UFG::TrueCrowdResource *v27; // rax
  unsigned int v28; // edi
  unsigned int v29; // ebx
  UFG::PartDatabase *v30; // rax
  UFG::qNode<UFG::ResourceRequest,UFG::ResourceRequest> *v31; // rdx
  UFG::qNode<UFG::ResourceRequest,UFG::ResourceRequest> *v32; // rax
  bool v33; // zf
  unsigned int v34; // [rsp+70h] [rbp+8h]
  bool v35; // [rsp+78h] [rbp+10h]
  __int64 v36; // [rsp+80h] [rbp+18h]
  __int64 v37; // [rsp+88h] [rbp+20h]

  v35 = forceFlush;
  v2 = this->mFragmentationReservePercentage;
  v3 = forceFlush;
  v4 = this;
  v5 = this->mMaxModelMemory - (signed int)(float)((float)(signed int)this->mMaxModelMemory * v2);
  v37 = v5;
  v6 = this->mMaxTextureMemory - (signed int)(float)((float)(signed int)this->mMaxTextureMemory * v2);
  v7 = this->mMasterBucket;
  v36 = v6;
  v8 = v7->mMemoryUsage[0][1] + v7->mMemoryUsage[1][1] + v7->mMemoryUsage[2][1];
  v9 = v7->mMemoryUsage[0][0] + v7->mMemoryUsage[1][0] + v7->mMemoryUsage[2][0];
  if ( forceFlush || this->mStreamerStalled || v8 > v5 || v9 > v6 )
  {
    if ( this->mDirty )
      UFG::ResourcePool::UpdateBuckets(this);
    v10 = v4->mUnReferencedBucket;
    v11 = (signed int)v10->mResourceRequests.size;
    if ( (_DWORD)v11 )
      UFG::qQuickSortImpl<Render::Light *,bool (*)(Render::Light const *,Render::Light const *)>(
        (Render::IrradianceVolume **)v10->mResourceRequests.p,
        (Render::IrradianceVolume **)&v10->mResourceRequests.p[v11 - 1],
        (bool (__fastcall *)(Render::IrradianceVolume *, Render::IrradianceVolume *))UFG::SortByReferenceFramePredicate);
    v12 = 0;
    v34 = v4->mUnReferencedBucket->mResourceRequests.size;
    if ( v34 )
    {
      v13 = 0i64;
      do
      {
        if ( !v3 && !v4->mStreamerStalled && v8 <= v5 && v9 <= v6 )
          break;
        v14 = v4->mQueued.size;
        v15 = v4->mUnReferencedBucket->mResourceRequests.p[v13];
        v16 = 0i64;
        v17 = v15->mResource;
        v8 -= v17->mModelSize;
        v9 -= v17->mTextureSize;
        if ( v4->mQueued.size )
        {
          v18 = v4->mQueued.p;
          while ( v15 != v18[v16] )
          {
            v16 = (unsigned int)(v16 + 1);
            if ( (unsigned int)v16 >= v14 )
              goto LABEL_24;
          }
          if ( (signed int)v16 >= 0 )
          {
            v18[v16] = v18[v14 - 1];
            if ( v4->mQueued.size > 1 )
              --v4->mQueued.size;
            else
              v4->mQueued.size = 0;
          }
        }
LABEL_24:
        v19 = v4->mLoading.size;
        v20 = 0i64;
        if ( v19 )
        {
          v21 = v4->mLoading.p;
          while ( v15 != v21[v20] )
          {
            v20 = (unsigned int)(v20 + 1);
            if ( (unsigned int)v20 >= v19 )
              goto LABEL_33;
          }
          if ( (signed int)v20 >= 0 )
          {
            v21[v20] = v21[v19 - 1];
            v22 = v4->mLoading.size;
            if ( v22 > 1 )
              v4->mLoading.size = v22 - 1;
            else
              v4->mLoading.size = 0;
          }
        }
LABEL_33:
        v23 = v4->mLoaded.size;
        v24 = 0i64;
        if ( v23 )
        {
          v25 = v4->mLoaded.p;
          while ( v15 != v25[v24] )
          {
            v24 = (unsigned int)(v24 + 1);
            if ( (unsigned int)v24 >= v23 )
              goto LABEL_42;
          }
          if ( (signed int)v24 >= 0 )
          {
            v25[v24] = v25[v23 - 1];
            v26 = v4->mLoaded.size;
            if ( v26 > 1 )
              v4->mLoaded.size = v26 - 1;
            else
              v4->mLoaded.size = 0;
          }
        }
LABEL_42:
        v27 = v15->mResource;
        v28 = v27->mTextureSize;
        v29 = v27->mModelSize;
        v30 = UFG::PartDatabase::Instance();
        v30->mPool.mExternalUsedModelMemory -= v29;
        v30->mPool.mExternalUsedTextureMemory -= v28;
        v15->mResource->mRequest = 0i64;
        v15->mResource = 0i64;
        UFG::DataStreamer::ReleaseStream(&v15->mDataStreamerHandle);
        v31 = v15->mPrev;
        v32 = v15->mNext;
        v31->mNext = v32;
        v32->mPrev = v31;
        v15->mPrev = (UFG::qNode<UFG::ResourceRequest,UFG::ResourceRequest> *)&v15->mPrev;
        v15->mNext = (UFG::qNode<UFG::ResourceRequest,UFG::ResourceRequest> *)&v15->mPrev;
        UFG::ResourceRequest::~ResourceRequest(v15);
        operator delete[](v15);
        v33 = v4->mStreamerStalled == 0;
        v4->mDirty = 1;
        if ( !v33 && v12 >= 1 )
          break;
        v6 = v36;
        v5 = v37;
        v3 = v35;
        ++v12;
        ++v13;
      }
      while ( v12 < v34 );
    }
  }
}

// File Line: 499
// RVA: 0x441020
void __fastcall UFG::ResourcePool::QueueRequest(UFG::ResourcePool *this, UFG::ResourceRequest *pRequest)
{
  UFG::ResourceRequest *callbackParam; // rbx
  UFG::ResourcePool *v3; // rdi
  unsigned int *v4; // r8
  unsigned int v5; // eax
  UFG::DataStreamer::PRIORITY v6; // esi
  int v7; // eax
  int v8; // eax
  bool v9; // zf
  unsigned int v10; // edx
  __int64 v11; // rcx
  UFG::ResourceRequest **v12; // r8
  UFG::StreamingMemory::DATA_TYPE v13; // er8
  unsigned int flags; // eax
  UFG::TrueCrowdResource *v15; // rax
  unsigned int v16; // edi
  unsigned int v17; // ebx
  UFG::PartDatabase *v18; // rax
  char dest; // [rsp+40h] [rbp-88h]
  UFG::qPropertySet *item; // [rsp+D8h] [rbp+10h]

  callbackParam = pRequest;
  v3 = this;
  UFG::qSPrintf(&dest, "%s.perm.bin", pRequest->mAssetName);
  v4 = callbackParam->mPriorityRefCounts;
  v5 = 0;
  while ( *v4 <= 0 )
  {
    ++v5;
    ++v4;
    if ( v5 >= 5 )
    {
      v5 = 0;
      break;
    }
  }
  v6 = 0x2000;
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
  v9 = callbackParam->mLoadStatus == 2;
  item = (UFG::qPropertySet *)callbackParam;
  if ( !v9 )
  {
    v10 = v3->mQueued.size;
    v11 = 0i64;
    if ( v3->mQueued.size )
    {
      v12 = v3->mQueued.p;
      while ( callbackParam != v12[v11] )
      {
        v11 = (unsigned int)(v11 + 1);
        if ( (unsigned int)v11 >= v10 )
          goto LABEL_20;
      }
      if ( (signed int)v11 >= 0 )
      {
        v12[v11] = v12[v10 - 1];
        if ( v3->mQueued.size > 1 )
          --v3->mQueued.size;
        else
          v3->mQueued.size = 0;
      }
    }
LABEL_20:
    UFG::qArray<UFG::PedSpawningInfo *,0>::Add((UFG::qArray<UFG::qPropertySet *,0> *)&v3->mLoading, &item, "qArray.Add");
    callbackParam->mLoadStatus = 2;
    v3->mDirty = 1;
  }
  if ( callbackParam->mType )
    v13 = v3->mStreamingPoolId;
  else
    v13 = v3->mStreamingPoolIdVRam;
  flags = 3;
  if ( callbackParam->mResource->mNonDefraggable == 0 )
    flags = 0;
  UFG::DataStreamer::QueueStream(
    &callbackParam->mDataStreamerHandle,
    &dest,
    v13,
    v6,
    flags,
    UFG::ResourcePool::ResourceHasBeenLoaded,
    callbackParam);
  v15 = callbackParam->mResource;
  v16 = v15->mTextureSize;
  v17 = v15->mModelSize;
  v18 = UFG::PartDatabase::Instance();
  v18->mPool.mExternalUsedModelMemory += v17;
  v18->mPool.mExternalUsedTextureMemory += v16;
}

// File Line: 543
// RVA: 0x442EA0
void __fastcall UFG::ResourcePool::ResourceHasBeenLoaded(UFG::DataStreamer::Handle *handle, void *callbackParam)
{
  UFG::ResourceRequest *v2; // rbx

  v2 = (UFG::ResourceRequest *)callbackParam;
  UFG::ResourceRequest::OnLoaded((UFG::ResourceRequest *)callbackParam);
  UFG::ResourcePool::ResourceLoadNotification(&UFG::ObjectResourceManager::sInstance->mPool, v2);
}

// File Line: 552
// RVA: 0x442ED0
void __fastcall UFG::ResourcePool::ResourceLoadNotification(UFG::ResourcePool *this, UFG::ResourceRequest *pRequest)
{
  bool v2; // zf
  UFG::ResourceRequest *v3; // rdi
  UFG::ResourcePool *v4; // rbx
  unsigned int v5; // edx
  __int64 v6; // rax
  UFG::ResourceRequest **v7; // r8
  unsigned int v8; // eax
  UFG::qPropertySet *item; // [rsp+38h] [rbp+10h]

  v2 = pRequest->mLoadStatus == 3;
  v3 = pRequest;
  v4 = this;
  item = (UFG::qPropertySet *)pRequest;
  if ( !v2 )
  {
    v5 = this->mLoading.size;
    v6 = 0i64;
    if ( v5 )
    {
      v7 = this->mLoading.p;
      while ( v3 != v7[v6] )
      {
        v6 = (unsigned int)(v6 + 1);
        if ( (unsigned int)v6 >= v5 )
          goto LABEL_11;
      }
      if ( (signed int)v6 >= 0 )
      {
        v7[(unsigned int)v6] = v7[v5 - 1];
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
    v3->mLoadStatus = 3;
    v4->mDirty = 1;
  }
}

// File Line: 600
// RVA: 0x442600
UFG::ResourceRequest *__fastcall UFG::ResourcePool::RequestLoadResource(UFG::ResourcePool *this, UFG::TrueCrowdResource *resource, bool isTexture, __int64 priority, UFG::ResourceUser *user)
{
  bool v5; // r12
  UFG::TrueCrowdResource *v6; // r13
  UFG::ResourcePool *v7; // rbp
  unsigned int v8; // ebx
  int v9; // eax
  UFG::PriorityBucket::Type v10; // esi
  UFG::ResourceRequest *v11; // rdi
  UFG::ResourceRequest *v12; // r14
  UFG::allocator::free_link *v13; // rax
  UFG::ResourceRequest::Type v14; // er15
  UFG::ResourceRequest *v15; // rax
  UFG::qNode<UFG::ResourceRequest,UFG::ResourceRequest> *v16; // rax
  UFG::qPropertySet *item; // [rsp+60h] [rbp+8h]

  v5 = isTexture;
  v6 = resource;
  v7 = this;
  v8 = resource->mPathSymbol.mUID;
  v9 = *(_DWORD *)priority;
  if ( *(_DWORD *)priority == qSymbol_Critical.mUID )
  {
    v10 = 2;
  }
  else if ( v9 == qSymbol_High.mUID )
  {
    v10 = 3;
  }
  else if ( v9 == qSymbol_Medium.mUID || v9 == qSymbol_Low.mUID )
  {
    v10 = 4;
  }
  else
  {
    v10 = 4;
    if ( v9 == qSymbol_Reserved.mUID )
      v10 = 1;
  }
  v11 = (UFG::ResourceRequest *)this->mRequestList.mNode.mNext;
  v12 = (UFG::ResourceRequest *)&this->mRequestList;
  if ( v11 != (UFG::ResourceRequest *)&this->mRequestList )
  {
    while ( v11->mAssetSymbol.mUID != v8 )
    {
      v11 = (UFG::ResourceRequest *)v11->mNext;
      if ( v11 == v12 )
        goto LABEL_16;
    }
    UFG::ResourceRequest::AddDependency(v11, v10, user);
    goto LABEL_21;
  }
LABEL_16:
  v13 = UFG::qMalloc(0xE0ui64, "ResourceRequest", 0i64);
  item = (UFG::qPropertySet *)v13;
  v14 = 0;
  if ( v13 )
  {
    UFG::ResourceRequest::ResourceRequest((UFG::ResourceRequest *)v13);
    v11 = v15;
  }
  else
  {
    v11 = 0i64;
  }
  UFG::TrueCrowdResource::GetPath(v6, v11->mAssetName, 48);
  v11->mAssetSymbol.mUID = v8;
  v11->mResource = v6;
  v6->mRequest = v11;
  LOBYTE(v14) = v5 == 0;
  v11->mType = v14;
  UFG::ResourceRequest::AddDependency(v11, v10, user);
  v16 = v12->mPrev;
  v16->mNext = (UFG::qNode<UFG::ResourceRequest,UFG::ResourceRequest> *)&v11->mPrev;
  v11->mPrev = v16;
  v11->mNext = (UFG::qNode<UFG::ResourceRequest,UFG::ResourceRequest> *)&v12->mPrev;
  v12->mPrev = (UFG::qNode<UFG::ResourceRequest,UFG::ResourceRequest> *)&v11->mPrev;
  item = (UFG::qPropertySet *)v11;
  if ( v11->mLoadStatus != 1 )
  {
    UFG::qArray<UFG::PedSpawningInfo *,0>::Add((UFG::qArray<UFG::qPropertySet *,0> *)v7, &item, "qArray.Add");
    v11->mLoadStatus = 1;
LABEL_21:
    v7->mDirty = 1;
  }
  return v11;
}

// File Line: 629
// RVA: 0x442C10
void __fastcall UFG::ResourcePool::RequestUnLoadResource(UFG::ResourcePool *this, UFG::TrueCrowdResource *resource, __int64 priority, UFG::ResourceUser *user)
{
  UFG::ResourcePool *v4; // rbx
  UFG::ResourceRequest *v5; // rcx
  UFG::ResourcePool *v6; // rax
  unsigned int v7; // edx
  int v8; // eax
  UFG::PriorityBucket::Type v9; // edx

  v4 = this;
  v5 = 0i64;
  v6 = (UFG::ResourcePool *)v4->mRequestList.mNode.mNext;
  if ( v6 != (UFG::ResourcePool *)&v4->mRequestList )
  {
    v7 = resource->mPathSymbol.mUID;
    while ( v6->mLoading.size != v7 )
    {
      v6 = (UFG::ResourcePool *)v6->mQueued.p;
      if ( v6 == (UFG::ResourcePool *)&v4->mRequestList )
        goto LABEL_7;
    }
    v5 = (UFG::ResourceRequest *)v6;
  }
LABEL_7:
  v8 = *(_DWORD *)priority;
  if ( *(_DWORD *)priority == qSymbol_Critical.mUID )
  {
    v9 = 2;
  }
  else if ( v8 == qSymbol_High.mUID )
  {
    v9 = 3;
  }
  else if ( v8 == qSymbol_Medium.mUID || v8 == qSymbol_Low.mUID )
  {
    v9 = 4;
  }
  else
  {
    v9 = 4;
    if ( v8 == qSymbol_Reserved.mUID )
      v9 = 1;
  }
  UFG::ResourceRequest::RemoveDependency(v5, v9, user);
  v4->mDirty = 1;
}

// File Line: 639
// RVA: 0x442250
void __fastcall UFG::ResourcePool::RemovePreloadReferences(UFG::ResourcePool *this, UFG::ResourceRequest *request)
{
  UFG::ResourceRequest *v2; // rbp
  UFG::ResourcePool *v3; // r14
  __int64 v4; // rsi
  UFG::qList<UFG::ResourceRequest,UFG::ResourceRequest,1,0> *v5; // rdi
  UFG::PreloadRequest *v6; // rbx
  UFG::qSymbol *v7; // rax
  UFG::ResourceRequest *v8; // r9
  UFG::qNode<UFG::ResourceRequest,UFG::ResourceRequest> *v9; // rcx
  unsigned int v10; // eax
  UFG::PriorityBucket::Type v11; // edx
  UFG::ResourceUser dependency; // [rsp+28h] [rbp-40h]
  UFG::qSymbol result; // [rsp+78h] [rbp+10h]
  UFG::qSymbol *v14; // [rsp+80h] [rbp+18h]

  v2 = request;
  v3 = this;
  v4 = 0i64;
  if ( request->mPreloads.size )
  {
    v14 = &result;
    v5 = &this->mRequestList;
    do
    {
      v6 = v2->mPreloads.p[v4];
      v7 = UFG::PreloadRequest::GetPriority(v6, &result);
      dependency.mMeshLoader = (UFG::MeshResourceLoader *)v6;
      dependency.mType = 1;
      v8 = 0i64;
      v9 = v3->mRequestList.mNode.mNext;
      if ( v9 != (UFG::qNode<UFG::ResourceRequest,UFG::ResourceRequest> *)v5 )
      {
        while ( LODWORD(v9[1].mPrev) != v2->mResource->mPathSymbol.mUID )
        {
          v9 = v9->mNext;
          if ( v9 == (UFG::qNode<UFG::ResourceRequest,UFG::ResourceRequest> *)v5 )
            goto LABEL_8;
        }
        v8 = (UFG::ResourceRequest *)v9;
      }
LABEL_8:
      v10 = v7->mUID;
      if ( v10 == qSymbol_Critical.mUID )
      {
        v11 = 2;
      }
      else if ( v10 == qSymbol_High.mUID )
      {
        v11 = 3;
      }
      else if ( v10 == qSymbol_Medium.mUID || v10 == qSymbol_Low.mUID )
      {
        v11 = 4;
      }
      else
      {
        v11 = 4;
        if ( v10 == qSymbol_Reserved.mUID )
          v11 = 1;
      }
      UFG::ResourceRequest::RemoveDependency(v8, v11, &dependency);
      v3->mDirty = 1;
      v4 = (unsigned int)(v4 + 1);
    }
    while ( (unsigned int)v4 < v2->mPreloads.size );
  }
}

// File Line: 648
// RVA: 0x441A60
void __fastcall UFG::ResourcePool::ReleaseResourceSetFiles(UFG::ResourcePool *this, UFG::PreloadRequest *request)
{
  UFG::PreloadRequest *v2; // rsi
  UFG::ResourcePool *v3; // r15
  UFG::TrueCrowdSet *v4; // r9
  bool v5; // r10
  __int64 v6; // rdx
  unsigned int v7; // ecx
  signed __int64 v8; // rdi
  __int64 v9; // rcx
  UFG::TrueCrowdModel *v10; // rbx
  UFG::ResourceRequest *v11; // r8
  unsigned int v12; // ecx
  unsigned int v13; // edx
  UFG::PreloadRequest **v14; // r8
  UFG::qSymbol v15; // eax
  __int64 v16; // rcx
  signed __int64 v17; // rdx
  signed __int64 v18; // r8
  signed __int64 v19; // rax
  __int64 v20; // rdx
  signed __int64 v21; // rax
  signed __int64 v22; // rax
  signed __int64 v23; // rcx
  __int64 v24; // rax
  signed __int64 v25; // rax
  __int64 v26; // rax
  unsigned int v27; // ecx
  unsigned int v28; // edx
  UFG::qSymbol v29; // er8
  __int64 v30; // rcx
  signed __int64 v31; // rcx
  _QWORD *v32; // rdx
  UFG::TrueCrowdResource *v33; // rdx
  unsigned int v34; // er12
  UFG::qNode<UFG::TrueCrowdSet,UFG::TrueCrowdSet> **v35; // r13
  _QWORD *v36; // rax
  __int64 v37; // r14
  __int64 v38; // rax
  unsigned int v39; // ecx
  unsigned int v40; // edx
  UFG::qSymbol *v41; // rax
  UFG::ResourceRequest *v42; // r9
  UFG::ResourcePool *v43; // rcx
  unsigned int v44; // eax
  UFG::PriorityBucket::Type v45; // edx
  unsigned int v46; // edi
  __int64 v47; // rcx
  signed __int64 v48; // rdx
  signed __int64 v49; // rbx
  signed __int64 v50; // rax
  __int64 v51; // rdx
  signed __int64 v52; // rax
  signed __int64 v53; // rax
  signed __int64 v54; // rcx
  __int64 v55; // rax
  signed __int64 v56; // rdx
  __int64 v57; // rcx
  unsigned int v58; // eax
  unsigned int v59; // edx
  UFG::qSymbol *v60; // r10
  __int64 v61; // rcx
  signed __int64 v62; // rcx
  UFG::ResourceRequest *v63; // r9
  signed __int64 v64; // rax
  __int64 v65; // rcx
  signed __int64 v66; // rdx
  UFG::ResourcePool *v67; // rax
  unsigned int v68; // eax
  UFG::PriorityBucket::Type v69; // edx
  __int64 v70; // [rsp+20h] [rbp-59h]
  signed __int64 v71; // [rsp+28h] [rbp-51h]
  UFG::qSymbol v72; // [rsp+30h] [rbp-49h]
  UFG::qSymbol v73; // [rsp+34h] [rbp-45h]
  UFG::qSymbol v74; // [rsp+38h] [rbp-41h]
  UFG::qSymbol result; // [rsp+3Ch] [rbp-3Dh]
  UFG::TrueCrowdSet *v76; // [rsp+40h] [rbp-39h]
  UFG::qNode<UFG::TrueCrowdSet,UFG::TrueCrowdSet> **v77; // [rsp+48h] [rbp-31h]
  UFG::qSymbol *v78; // [rsp+50h] [rbp-29h]
  UFG::ResourceUser user; // [rsp+58h] [rbp-21h]
  UFG::ResourceUser v80; // [rsp+68h] [rbp-11h]
  UFG::ResourceUser dependency; // [rsp+78h] [rbp-1h]
  UFG::ResourceUser v82; // [rsp+88h] [rbp+Fh]
  __int64 v83; // [rsp+98h] [rbp+1Fh]
  bool v84; // [rsp+E8h] [rbp+6Fh]
  unsigned int v85; // [rsp+F0h] [rbp+77h]
  unsigned int v86; // [rsp+F8h] [rbp+7Fh]

  v83 = -2i64;
  v2 = request;
  v3 = this;
  if ( request->mPreloadActive )
  {
    v4 = request->mInstance.mSet;
    v76 = v4;
    v5 = request->mIsSet == 0;
    v84 = request->mIsSet == 0;
    v85 = UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition.mEntities[v4->mEntityIndex].mComponentCount;
    v86 = 0;
    v6 = 0i64;
    v70 = 0i64;
    if ( v85 )
    {
      v7 = UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition.mEntities[v4->mEntityIndex].mComponentCount;
      while ( !v5 )
      {
        v34 = 0;
        v35 = &v4->mPrev + 2 * (v6 + 3);
        v77 = v35;
        if ( *(_DWORD *)v35 )
        {
          v36 = &v4->mFiles[v6].p;
          v71 = (signed __int64)&v4->mFiles[v6].p;
          do
          {
            v37 = *(_QWORD *)(*v36 + 8i64 * v34);
            v38 = *(_QWORD *)(v37 + 8);
            if ( v38 )
            {
              v39 = 0;
              v40 = *(_DWORD *)(v38 + 56);
              if ( v40 )
              {
                while ( v2 != *(UFG::PreloadRequest **)(*(_QWORD *)(v38 + 64) + 8i64 * v39) )
                {
                  if ( ++v39 >= v40 )
                    goto LABEL_66;
                }
                if ( v39 != -1 )
                {
                  v78 = &v74;
                  v41 = UFG::PreloadRequest::GetPriority(v2, &v74);
                  dependency.mMeshLoader = (UFG::MeshResourceLoader *)v2;
                  dependency.mType = 1;
                  v42 = 0i64;
                  v43 = (UFG::ResourcePool *)v3->mRequestList.mNode.mNext;
                  if ( v43 != (UFG::ResourcePool *)&v3->mRequestList )
                  {
                    while ( v43->mLoading.size != *(_DWORD *)(v37 + 28) )
                    {
                      v43 = (UFG::ResourcePool *)v43->mQueued.p;
                      if ( v43 == (UFG::ResourcePool *)&v3->mRequestList )
                        goto LABEL_55;
                    }
                    v42 = (UFG::ResourceRequest *)v43;
                  }
LABEL_55:
                  v44 = v41->mUID;
                  if ( v44 == qSymbol_Critical.mUID )
                  {
                    v45 = 2;
                  }
                  else if ( v44 == qSymbol_High.mUID )
                  {
                    v45 = 3;
                  }
                  else if ( v44 == qSymbol_Medium.mUID || v44 == qSymbol_Low.mUID )
                  {
                    v45 = 4;
                  }
                  else
                  {
                    v45 = 4;
                    if ( v44 == qSymbol_Reserved.mUID )
                      v45 = 1;
                  }
                  UFG::ResourceRequest::RemoveDependency(v42, v45, &dependency);
                  v3->mDirty = 1;
                }
              }
            }
LABEL_66:
            v46 = 0;
            if ( *(_WORD *)(v37 + 58) > 0u )
            {
              do
              {
                v47 = *(_QWORD *)(v37 + 72);
                if ( v47 )
                  v48 = v37 + v47 + 72;
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
                  if ( v47 )
                    v53 = v37 + v47 + 72;
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
                    while ( v2 != *(UFG::PreloadRequest **)(*(_QWORD *)(v57 + 64) + 8i64 * v58) )
                    {
                      if ( ++v58 >= v59 )
                        goto LABEL_105;
                    }
                    if ( v58 != -1 )
                    {
                      v78 = &v72;
                      v60 = UFG::PreloadRequest::GetPriority(v2, &v72);
                      v82.mMeshLoader = (UFG::MeshResourceLoader *)v2;
                      v82.mType = 1;
                      v61 = *(_QWORD *)(v37 + 72);
                      if ( v61 )
                      {
                        v62 = v37 + v61 + 72;
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
                      v67 = (UFG::ResourcePool *)v3->mRequestList.mNode.mNext;
                      if ( v67 != (UFG::ResourcePool *)&v3->mRequestList )
                      {
                        while ( v67->mLoading.size != *(_DWORD *)(v66 + 28) )
                        {
                          v67 = (UFG::ResourcePool *)v67->mQueued.p;
                          if ( v67 == (UFG::ResourcePool *)&v3->mRequestList )
                            goto LABEL_94;
                        }
                        v63 = (UFG::ResourceRequest *)v67;
                      }
LABEL_94:
                      v68 = v60->mUID;
                      if ( v60->mUID == qSymbol_Critical.mUID )
                      {
                        v69 = 2;
                      }
                      else if ( v68 == qSymbol_High.mUID )
                      {
                        v69 = 3;
                      }
                      else if ( v68 == qSymbol_Medium.mUID || v68 == qSymbol_Low.mUID )
                      {
                        v69 = 4;
                      }
                      else
                      {
                        v69 = 4;
                        if ( v68 == qSymbol_Reserved.mUID )
                          v69 = 1;
                      }
                      UFG::ResourceRequest::RemoveDependency(v63, v69, &v82);
                      v3->mDirty = 1;
                    }
                  }
                }
LABEL_105:
                ++v46;
              }
              while ( v46 < *(unsigned __int16 *)(v37 + 58) );
              v35 = v77;
            }
            ++v34;
            v36 = (_QWORD *)v71;
          }
          while ( v34 < *(_DWORD *)v35 );
LABEL_108:
          v6 = v70;
LABEL_109:
          v7 = v85;
        }
        ++v86;
        v70 = ++v6;
        v4 = v76;
        v5 = v84;
        if ( v86 >= v7 )
          goto LABEL_111;
      }
      v8 = (signed __int64)v2 + 16 * v6;
      v9 = *(unsigned int *)(v8 + 56);
      if ( (_DWORD)v9 != -1 )
      {
        v10 = v4->mFiles[v6].p[v9];
        v11 = v10->mRequest;
        if ( v11 )
        {
          v12 = 0;
          v13 = v11->mPreloads.size;
          if ( v13 )
          {
            v14 = v11->mPreloads.p;
            while ( v2 != v14[v12] )
            {
              if ( ++v12 >= v13 )
                goto LABEL_14;
            }
            if ( v12 != -1 )
            {
              v15.mUID = (unsigned int)UFG::PreloadRequest::GetPriority(v2, &result);
              user.mMeshLoader = (UFG::MeshResourceLoader *)v2;
              user.mType = 1;
              UFG::ResourcePool::RequestUnLoadResource(v3, (UFG::TrueCrowdResource *)&v10->mName, v15, &user);
            }
          }
LABEL_14:
          v6 = v70;
        }
        if ( v10->mNumTextureSets )
        {
          v16 = v10->mTextureSets.mOffset;
          if ( v16 )
            v17 = (signed __int64)&v10->mTextureSets + v16;
          else
            v17 = 0i64;
          v18 = 8i64 * *(unsigned int *)(v8 + 60);
          v19 = v18 + v17;
          v20 = *(_QWORD *)(v18 + v17);
          if ( v20 )
            v21 = v20 + v19;
          else
            v21 = 0i64;
          if ( *(_QWORD *)(v21 + 8) )
          {
            v22 = (signed __int64)(v16 ? (UFG::qOffset64<UFG::qOffset64<UFG::TrueCrowdTextureSet *> *> *)((char *)&v10->mTextureSets + v16) : 0i64);
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
                while ( v2 != *(UFG::PreloadRequest **)(*(_QWORD *)(v26 + 64) + 8i64 * v27) )
                {
                  if ( ++v27 >= v28 )
                    goto LABEL_108;
                }
                if ( v27 != -1 )
                {
                  v29.mUID = (unsigned int)UFG::PreloadRequest::GetPriority(v2, &v73);
                  v80.mMeshLoader = (UFG::MeshResourceLoader *)v2;
                  v80.mType = 1;
                  v30 = v10->mTextureSets.mOffset;
                  if ( v30 )
                    v31 = (signed __int64)&v10->mTextureSets + v30;
                  else
                    v31 = 0i64;
                  v32 = (_QWORD *)(v31 + 8i64 * *(unsigned int *)(v8 + 60));
                  if ( *v32 )
                    v33 = (UFG::TrueCrowdResource *)((char *)v32 + *v32);
                  else
                    v33 = 0i64;
                  UFG::ResourcePool::RequestUnLoadResource(v3, v33, v29, &v80);
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
    v2->mPreloadActive = 0;
  }
}

// File Line: 727
// RVA: 0x4416A0
void __fastcall UFG::ResourcePool::ReleaseAllUnReferencedPreloads(UFG::ResourcePool *this, unsigned int preloadBucketIndex, bool forceUnload)
{
  bool v3; // r15
  signed __int64 v4; // rbx
  UFG::ResourcePool *v5; // r14
  signed int v6; // ebp
  __int64 v7; // rsi
  unsigned int v8; // ebp
  UFG::PreloadRequest **v9; // rcx
  UFG::PreloadRequest *v10; // rdi
  unsigned int v11; // er9
  UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *v12; // rax
  UFG::qArray<UFG::PreloadRequest *,0> *v13; // r8
  signed __int64 v14; // rdx
  unsigned int v15; // eax

  v3 = forceUnload;
  v4 = preloadBucketIndex;
  v5 = this;
  v6 = this->mPreloadBuckets[preloadBucketIndex].size - 1;
  v7 = v6;
  if ( v6 >= 0 )
  {
    v8 = this->mPreloadBuckets[preloadBucketIndex].size;
    do
    {
      v9 = v5->mPreloadBuckets[v4].p;
      v10 = v9[v7];
      if ( !v10->mSpawnSetValid && v10->mDirectRequestCount <= 0 || v3 )
      {
        UFG::ResourcePool::ReleaseResourceSetFiles(v5, v9[v7]);
        *(_QWORD *)&v10->mDesiredInstanceCount = 0i64;
        v10->mVarietyRatio = 0.0;
        v11 = v8;
        v12 = v5->mEmptyRequestList.mNode.mPrev;
        v12->mNext = (UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *)&v10->mPrev;
        v10->mPrev = v12;
        v10->mNext = &v5->mEmptyRequestList.mNode;
        v5->mEmptyRequestList.mNode.mPrev = (UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *)&v10->mPrev;
        v13 = v5->mPreloadBuckets;
        if ( v8 != v13[v4].size )
        {
          v14 = 8 * v7 + 8;
          do
          {
            ++v11;
            v14 += 8i64;
            *(UFG::PreloadRequest **)((char *)v13[v4].p + v14 - 16) = *(UFG::PreloadRequest **)((char *)v13[v4].p
                                                                                              + v14
                                                                                              - 8);
          }
          while ( v11 != v13[v4].size );
        }
        v15 = v13[v4].size;
        if ( v15 > 1 )
          v13[v4].size = v15 - 1;
        else
          v13[v4].size = 0;
      }
      --v8;
      --v7;
    }
    while ( v7 >= 0 );
  }
}

// File Line: 748
// RVA: 0x43FC60
void __fastcall UFG::ResourcePool::PreloadInstance(UFG::ResourcePool *this, UFG::PreloadRequest *request, UFG::TrueCrowdSet::Instance *instance)
{
  UFG::TrueCrowdSet::Instance *v3; // rdi
  UFG::PreloadRequest *v4; // rbp
  UFG::ResourcePool *v5; // r15
  unsigned int v6; // ebx
  signed __int64 v7; // rsi
  __int64 v8; // rdx
  UFG::TrueCrowdModel *v9; // r14
  UFG::qSymbol *v10; // rax
  UFG::qSymbol *v11; // r9
  __int64 v12; // rcx
  _QWORD *v13; // rdx
  UFG::TrueCrowdResource *v14; // rdx
  UFG::ResourceUser user; // [rsp+40h] [rbp-48h]
  UFG::ResourceUser v16; // [rsp+50h] [rbp-38h]
  UFG::qSymbol result; // [rsp+98h] [rbp+10h]
  UFG::qSymbol v18; // [rsp+A8h] [rbp+20h]

  v3 = instance;
  v4 = request;
  v5 = this;
  if ( !request->mPreloadActive )
  {
    v6 = 0;
    if ( instance->mNumParts )
    {
      do
      {
        v7 = (signed __int64)v3 + 16 * v6;
        v8 = *(unsigned int *)(v7 + 24);
        if ( (_DWORD)v8 != -1 )
        {
          v9 = v3->mSet->mFiles[v6].p[v8];
          v10 = UFG::PreloadRequest::GetPriority(v4, &result);
          user.mMeshLoader = (UFG::MeshResourceLoader *)v4;
          user.mType = 1;
          UFG::ResourcePool::RequestLoadResource(v5, (UFG::TrueCrowdResource *)&v9->mName, 0, (__int64)v10, &user);
          if ( v9->mNumTextureSets )
          {
            v11 = UFG::PreloadRequest::GetPriority(v4, &v18);
            v16.mMeshLoader = (UFG::MeshResourceLoader *)v4;
            v16.mType = 1;
            v12 = v9->mTextureSets.mOffset;
            if ( v12 )
              v12 += (__int64)&v9->mTextureSets;
            v13 = (_QWORD *)(v12 + 8i64 * *(unsigned int *)(v7 + 28));
            if ( *v13 )
              v14 = (UFG::TrueCrowdResource *)((char *)v13 + *v13);
            else
              v14 = 0i64;
            UFG::ResourcePool::RequestLoadResource(v5, v14, 1, (__int64)v11, &v16);
          }
        }
        ++v6;
      }
      while ( v6 < v3->mNumParts );
    }
    v4->mPreloadActive = 1;
  }
}

// File Line: 824
// RVA: 0x43D530
__int64 __fastcall UFG::ResourcePool::GetContractableAmbientOptions(UFG::ResourcePool *this, unsigned int pool, UFG::ResourcePool::ContractionSortData *candidates, unsigned int *candidateCount)
{
  UFG::qArray<UFG::PreloadRequest *,0> *v4; // rax
  signed __int64 v5; // rcx
  __int64 v6; // r12
  UFG::qArray<UFG::PreloadRequest *,0> *v7; // rdx
  UFG::PreloadRequest *v8; // r13
  unsigned int v9; // esi
  char v10; // di
  unsigned int v11; // ebx
  unsigned int v12; // er14
  UFG::TrueCrowdSet *v13; // r9
  __int64 v14; // r15
  char *v15; // r10
  signed __int64 v16; // r9
  __int64 v17; // r11
  __int64 v18; // r8
  _DWORD *v19; // rdx
  unsigned int v20; // ecx
  _DWORD *v21; // rax
  char v22; // al
  char *v23; // rcx
  __int64 v24; // rdx
  signed __int64 v25; // rcx
  signed __int64 v27; // [rsp+10h] [rbp-59h]
  __int64 v28; // [rsp+18h] [rbp-51h]
  __int64 v29; // [rsp+20h] [rbp-49h]
  unsigned int textureMemory[2]; // [rsp+30h] [rbp-39h]
  unsigned int modelMemory[2]; // [rsp+38h] [rbp-31h]
  char dest; // [rsp+40h] [rbp-29h]
  __int64 vars0; // [rsp+D0h] [rbp+67h]
  int retaddr; // [rsp+D8h] [rbp+6Fh]
  UFG::ResourcePool *v35; // [rsp+E0h] [rbp+77h]
  _DWORD *v36; // [rsp+E8h] [rbp+7Fh]

  v35 = this;
  v4 = this->mPreloadBuckets;
  LOBYTE(candidates) = 0;
  v5 = pool;
  v6 = 0i64;
  retaddr = (signed int)candidates;
  v7 = &v4[v5];
  v27 = v5 * 16;
  if ( v4[v5].size )
  {
    do
    {
      v8 = v7->p[v6];
      if ( v8->mPreloadActive )
      {
        v9 = -1;
        v10 = 0;
        v11 = -1;
        v12 = -1;
        UFG::qMemSet(&dest, 0, 0x40u);
        v13 = v8->mInstance.mSet;
        v14 = UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition.mEntities[v13->mEntityIndex].mComponentCount;
        if ( (_DWORD)v14 )
        {
          v15 = &dest;
          v16 = (signed __int64)v13->mFiles;
          v17 = (unsigned int)v14;
          do
          {
            v18 = 0i64;
            if ( *(_DWORD *)v16 )
            {
              do
              {
                v19 = *(_DWORD **)(*(_QWORD *)(*(_QWORD *)(v16 + 8) + 8 * v18) + 8i64);
                if ( v19 )
                {
                  v20 = 0;
                  v21 = v19 + 25;
                  while ( !*v21 )
                  {
                    ++v20;
                    ++v21;
                    if ( v20 >= 5 )
                      goto LABEL_22;
                  }
                  if ( v20 == 4 )
                  {
                    if ( v9 == -1 || v9 > v19[10] )
                      v9 = v19[10];
                    if ( v11 == -1 || v11 > v19[18] )
                      v11 = v19[18];
                    if ( v11 == -1 || v12 > v19[14] )
                      v12 = v19[14];
                    ++*(_DWORD *)v15;
                    v10 = 1;
                  }
                }
LABEL_22:
                v18 = (unsigned int)(v18 + 1);
              }
              while ( (unsigned int)v18 < *(_DWORD *)v16 );
            }
            v16 += 16i64;
            v15 += 4;
            --v17;
          }
          while ( v17 );
          v13 = v8->mInstance.mSet;
        }
        v22 = 0;
        if ( (_DWORD)v14 )
        {
          v23 = &dest;
          v24 = v14;
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
        UFG::TrueCrowdSet::GetCurrentMemoryUsage(v13, modelMemory, &textureMemory[1]);
        LOBYTE(candidates) = retaddr;
        if ( v10 )
        {
          LODWORD(candidates) = (unsigned __int8)retaddr;
          v25 = 5i64 * (unsigned int)*v36;
          *((_QWORD *)&v35->mQueued.size + v25) = v28;
          *((_QWORD *)&v35->mQueued.p + v25) = v29;
          *((_QWORD *)&v35->mLoading.size + v25) = __PAIR__(v11, v9);
          *((_QWORD *)&v35->mLoading.p + v25) = *(_QWORD *)textureMemory;
          *((_QWORD *)&v35->mLoaded.size + v25) = *(_QWORD *)modelMemory;
          ++*v36;
          if ( !(v9 + v12 + v11) )
            LODWORD(candidates) = 1;
          retaddr = (signed int)candidates;
        }
      }
      v6 = (unsigned int)(v6 + 1);
      v7 = (UFG::qArray<UFG::PreloadRequest *,0> *)(v27 + *(_QWORD *)(vars0 + 136));
    }
    while ( (unsigned int)v6 < v7->size );
  }
  return (unsigned __int8)candidates;
}

// File Line: 853
// RVA: 0x43FDA0
bool __fastcall UFG::ResourcePool::PreloadSortPredicate(UFG::ResourcePool::ContractionSortData *a, UFG::ResourcePool::ContractionSortData *b)
{
  unsigned int v2; // er8
  UFG::ResourcePool::ContractionSortData *v3; // rax
  unsigned int v4; // ecx
  bool v5; // cf
  unsigned int v6; // ecx
  unsigned int v7; // er8
  unsigned int v8; // ecx
  unsigned int v9; // er8
  bool v10; // cl
  float v11; // xmm0_4
  float v12; // xmm1_4
  bool result; // al

  v2 = b->mSpawnedReferences;
  v3 = a;
  v4 = a->mSpawnedReferences;
  v5 = v4 < v2;
  if ( v4 != v2 )
    return v5;
  v6 = v3->mProxyReferences;
  v7 = b->mProxyReferences;
  v5 = v6 < v7;
  if ( v6 != v7 )
    return v5;
  v8 = v3->mPreloadReferences;
  v9 = b->mPreloadReferences;
  v5 = v8 < v9;
  if ( v8 != v9 )
    return v5;
  v10 = v3->mExpanded;
  if ( v10 != b->mExpanded )
    return v10 == 1;
  v11 = v3->mVarietyRatio;
  v12 = b->mVarietyRatio;
  if ( v11 == v12 )
    result = v3->mTextureMemory + v3->mMeshMemory <= b->mTextureMemory + b->mMeshMemory;
  else
    result = v11 > v12;
  return result;
}

// File Line: 878
// RVA: 0x442BD0
bool __fastcall UFG::ResourcePool::RequestSortPredicate(UFG::ResourceRequest *a, UFG::ResourceRequest *b)
{
  unsigned int v2; // eax
  unsigned int v3; // er8
  bool v4; // cf
  unsigned int v5; // eax
  unsigned int v6; // er8
  unsigned int v7; // eax
  unsigned int v8; // er8

  v2 = a->mInstances.size;
  v3 = b->mInstances.size;
  v4 = v2 < v3;
  if ( v2 == v3 )
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
        v4 = a->mResource->mModelSize + a->mResource->mTextureSize < b->mResource->mModelSize
                                                                   + b->mResource->mTextureSize;
    }
  }
  return v4;
}

// File Line: 901
// RVA: 0x43A7C0
char __fastcall UFG::ResourcePool::ContractAmbientModel(UFG::ResourcePool *this, UFG::TrueCrowdModel *model)
{
  UFG::TrueCrowdModel *v2; // rdi
  UFG::ResourcePool *v3; // r12
  UFG::ResourceRequest *v4; // rax
  bool v5; // zf
  unsigned int v6; // eax
  bool v7; // r15
  char v8; // si
  UFG::ResourceRequest *v9; // r13
  int v10; // eax
  __int64 i; // r14
  void *v12; // rbx
  UFG::SimObjectGame *v13; // rbx
  unsigned __int16 v14; // cx
  UFG::SimComponent *v15; // rax
  UFG::SimObject *v16; // rcx
  UFG::TransformNodeComponent *v17; // rbp
  UFG::BaseCameraComponent *v18; // rax
  float *v19; // rax
  UFG::ResourceRequest *v20; // rdx
  unsigned int v21; // ebx
  __int64 v22; // rax
  signed __int64 v23; // rcx
  signed __int64 v24; // rdx
  __int64 v25; // rcx
  signed __int64 v26; // rcx
  signed __int64 v27; // rcx
  signed __int64 v28; // rax
  __int64 v29; // rcx
  signed __int64 v30; // rdx
  UFG::ResourceRequest *v31; // rax

  v2 = model;
  v3 = this;
  if ( !model )
    return 0;
  v4 = model->mRequest;
  if ( !v4 || v4->mLoadStatus != 3 )
    return 0;
  v5 = (unsigned int)UFG::FlowController::GetCurrentState(&UFG::gFlowController) == uidGameStateInGame_7;
  v6 = v2->mType.mValue;
  v7 = !v5;
  v8 = 0;
  if ( v6 )
  {
    if ( v6 - 1 <= 1 )
    {
      v9 = v2->mRequest;
      if ( v9 )
      {
        v10 = v9->mInstances.size - 1;
        for ( i = v10; i >= 0; --i )
        {
          v12 = v9->mInstances.p[i]->mUserContext;
          if ( v12 )
          {
            if ( (v13 = (UFG::SimObjectGame *)*((_QWORD *)v12 + 5)) != 0i64
              && ((v14 = v13->m_Flags, !((v14 >> 14) & 1)) ? ((v14 & 0x8000u) == 0 ? (!((v14 >> 13) & 1) ? (!((v14 >> 12) & 1) ? (v15 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v13->vfptr, UFG::CompositeDrawableComponent::_TypeUID)) : (v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::CompositeDrawableComponent::_TypeUID))) : (v15 = v13->m_Components.p[9].m_pComponent)) : (v15 = v13->m_Components.p[14].m_pComponent)) : (v15 = v13->m_Components.p[14].m_pComponent),
                  v15 && (v16 = v15[19].m_pSimObject) != 0i64 && LOBYTE(v16->vfptr) > 1u)
              || v7 )
            {
              if ( v2->mType.mValue != 1 )
                goto LABEL_61;
              v17 = 0i64;
              if ( v13 )
                v17 = v13->m_pTransformNodeComponent;
              UFG::TransformNodeComponent::UpdateWorldTransform(v17);
              v18 = UFG::Director::Get()->mCurrentCamera;
              v19 = (float *)(v18 ? &v18->mCamera : 0i64);
              if ( (float)((float)((float)((float)(v19[45] - v17->mWorldTransform.v3.y)
                                         * (float)(v19[45] - v17->mWorldTransform.v3.y))
                                 + (float)((float)(v19[44] - v17->mWorldTransform.v3.x)
                                         * (float)(v19[44] - v17->mWorldTransform.v3.x)))
                         + (float)((float)(v19[46] - v17->mWorldTransform.v3.z)
                                 * (float)(v19[46] - v17->mWorldTransform.v3.z))) > 2500.0
                || v7 )
              {
LABEL_61:
                UFG::Simulation::DestroySimObject(&UFG::gSim, (UFG::SimObject *)&v13->vfptr);
              }
            }
          }
        }
      }
    }
  }
  else
  {
    UFG::PedSpawnManager::ReducePedsWithSpecificModel(v2, v7);
  }
  v20 = v2->mRequest;
  if ( v20 )
    UFG::ResourcePool::RemovePreloadReferences(v3, v20);
  v21 = 0;
  if ( v2->mNumTextureSets > 0u )
  {
    do
    {
      v22 = v2->mTextureSets.mOffset;
      if ( v22 )
        v23 = (signed __int64)&v2->mTextureSets + v22;
      else
        v23 = 0i64;
      v24 = v23 + 8i64 * v21;
      v25 = *(_QWORD *)(v23 + 8i64 * v21);
      if ( v25 )
        v26 = v24 + v25;
      else
        v26 = 0i64;
      if ( *(_QWORD *)(v26 + 8) )
      {
        if ( v22 )
          v27 = (signed __int64)&v2->mTextureSets + v22;
        else
          v27 = 0i64;
        v28 = v27 + 8i64 * v21;
        v29 = *(_QWORD *)(v27 + 8i64 * v21);
        v30 = v29 + v28;
        if ( !v29 )
          v30 = 0i64;
        UFG::ResourcePool::RemovePreloadReferences(v3, *(UFG::ResourceRequest **)(v30 + 8));
      }
      ++v21;
    }
    while ( v21 < v2->mNumTextureSets );
  }
  v31 = v2->mRequest;
  if ( !v31 || v31->mInstances.size <= 0 && v31->mPreloads.size <= 0 && v31->mProxies.size <= 0 )
    v8 = 1;
  return v8;
}

// File Line: 975
// RVA: 0x43AAB0
void __fastcall UFG::ResourcePool::ContractAmbientModels(UFG::ResourcePool *this, unsigned int numModels)
{
  unsigned int v2; // er15
  unsigned int v3; // er13
  UFG::ResourcePool *v4; // r12
  unsigned int v5; // ebx
  unsigned int v6; // er14
  unsigned int v7; // esi
  unsigned int v8; // er13
  char v9; // di
  UFG::PreloadRequest *v10; // rsi
  UFG::TrueCrowdModel *v11; // rax
  UFG::TrueCrowdSet *v12; // rdx
  unsigned int v13; // er8
  signed __int64 v14; // r14
  __int64 v15; // r12
  unsigned int i; // ebx
  UFG::TrueCrowdModel *v17; // r9
  UFG::ResourceRequest *v18; // r8
  unsigned int v19; // edx
  unsigned int v20; // ecx
  UFG::PreloadRequest **v21; // rax
  bool v22; // zf
  unsigned int v23; // eax
  unsigned int *v24; // rcx
  UFG::ResourcePriorityBucket *v25; // r9
  unsigned int v26; // er14
  unsigned int j; // er8
  UFG::ResourceRequest *v28; // rdx
  unsigned int v29; // eax
  unsigned int *v30; // rcx
  __int64 v31; // rax
  Render::IrradianceVolume **v32; // rdi
  signed __int64 v33; // rax
  signed int v34; // ecx
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
  float v65; // er10
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
  signed __int64 v82; // rbx
  signed __int64 v83; // rsi
  int v84; // edi
  __int64 v85; // r9
  int v86; // er11
  signed __int64 k; // r10
  __int64 v88; // r8
  unsigned int v89; // eax
  unsigned int v90; // ecx
  bool v91; // cf
  unsigned int v92; // eax
  unsigned int v93; // ecx
  unsigned int v94; // eax
  unsigned int v95; // ecx
  Render::IrradianceVolume **v96; // rbx
  unsigned int v97; // [rsp+20h] [rbp-E0h]
  Render::IrradianceVolume *right; // [rsp+28h] [rbp-D8h]
  Render::IrradianceVolume *left; // [rsp+30h] [rbp-D0h]
  __int64 v100[255]; // [rsp+38h] [rbp-C8h]
  UFG::ResourcePool::ContractionSortData candidates[256]; // [rsp+830h] [rbp+730h]
  UFG::ResourcePool *v102; // [rsp+3080h] [rbp+2F80h]
  unsigned int v103; // [rsp+3088h] [rbp+2F88h]
  unsigned int v104; // [rsp+3090h] [rbp+2F90h]
  unsigned int candidateCount; // [rsp+3098h] [rbp+2F98h]

  v103 = numModels;
  v102 = this;
  v2 = 0;
  v3 = numModels;
  v4 = this;
  v5 = 0;
  v6 = 0;
  candidateCount = 0;
  if ( this->mEntityStates.size )
  {
    do
      UFG::ResourcePool::GetContractableAmbientOptions(v4, v5++ + 3, candidates, &candidateCount);
    while ( v5 < v4->mEntityStates.size );
    v6 = candidateCount;
  }
  v7 = 0;
  v104 = 0;
  if ( v6 )
  {
    UFG::qInsertionSort<UFG::ResourcePool::ContractionSortData,bool (*)(UFG::ResourcePool::ContractionSortData const &,UFG::ResourcePool::ContractionSortData const &)>(
      candidates,
      v6,
      UFG::ResourcePool::PreloadSortPredicate);
    v8 = 0;
    v97 = 0;
    if ( v6 )
    {
      do
      {
        v9 = 0;
        v10 = candidates[v8].mResourceRequest;
        if ( candidates[v8].mExpanded )
        {
          v11 = UFG::TrueCrowdSet::ChooseContractableAmbientPart(v10->mInstance.mSet);
          v9 = UFG::ResourcePool::ContractAmbientModel(v4, v11);
        }
        else
        {
          v12 = v10->mInstance.mSet;
          v13 = UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition.mEntities[v12->mEntityIndex].mComponentCount;
          if ( v13 )
          {
            v14 = (signed __int64)v12->mFiles;
            v15 = v13;
            do
            {
              for ( i = 0; i < *(_DWORD *)v14; ++i )
              {
                v17 = *(UFG::TrueCrowdModel **)(*(_QWORD *)(v14 + 8) + 8i64 * i);
                v18 = v17->mRequest;
                if ( v18 )
                {
                  v19 = v18->mPreloads.size;
                  v20 = 0;
                  if ( v19 )
                  {
                    v21 = v18->mPreloads.p;
                    while ( v10 != *v21 )
                    {
                      ++v20;
                      ++v21;
                      if ( v20 >= v19 )
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
                  v24 = v18->mPriorityRefCounts;
                  while ( *v24 <= 0 )
                  {
                    ++v23;
                    ++v24;
                    if ( v23 >= 5 )
                    {
                      v23 = 0;
                      break;
                    }
                  }
                  if ( !v22 && v23 == 4 && (v9 || UFG::ResourcePool::ContractAmbientModel(v102, v17)) )
                    v9 = 1;
                }
              }
              v14 += 16i64;
              --v15;
            }
            while ( v15 );
            v8 = v97;
            v6 = candidateCount;
            v4 = v102;
          }
          UFG::ResourcePool::ReleaseResourceSetFiles(v4, v10);
        }
        v7 = v104;
        if ( v9 )
        {
          v7 = v104 + 1;
          v104 = v7;
          if ( v7 == v103 )
            break;
        }
        v97 = ++v8;
      }
      while ( v8 < v6 );
    }
    v3 = v103;
  }
  if ( v7 < v3 )
  {
    v25 = v4->mLowBucket;
    v26 = 0;
    for ( j = 0; j < v25->mResourceRequests.size; ++j )
    {
      v28 = v25->mResourceRequests.p[j];
      if ( v28->mInstances.size > 0 || v28->mPreloads.size > 0 || v28->mProxies.size > 0 )
      {
        v29 = 0;
        v30 = v28->mPriorityRefCounts;
        while ( *v30 <= 0 )
        {
          ++v29;
          ++v30;
          if ( v29 >= 5 )
            goto LABEL_46;
        }
        if ( v29 == 4 && v28->mType == 1 )
        {
          v31 = v26++;
          *(&left + v31) = (Render::IrradianceVolume *)v28;
        }
      }
LABEL_46:
      ;
    }
    v32 = &right + (signed int)v26;
    v33 = &right + (signed int)v26 - &left;
    v34 = v33 + 1;
    if ( (signed int)v33 + 1 < 32 )
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
            v85 = (__int64)*(&left + v82);
            v86 = v84;
            for ( k = v82 - 1; v86 >= 0; --v86 )
            {
              v88 = (__int64)*(&left + k);
              v89 = *(_DWORD *)(v85 + 40);
              v90 = *(_DWORD *)(v88 + 40);
              v91 = v89 < v90;
              if ( v89 == v90 )
              {
                v92 = *(_DWORD *)(v85 + 72);
                v93 = *(_DWORD *)(v88 + 72);
                v91 = v92 < v93;
                if ( v92 == v93 )
                {
                  v94 = *(_DWORD *)(v85 + 56);
                  v95 = *(_DWORD *)(v88 + 56);
                  v91 = v94 < v95;
                  if ( v94 == v95 )
                    v91 = *(_DWORD *)(*(_QWORD *)(v85 + 32) + 16i64) + *(_DWORD *)(*(_QWORD *)(v85 + 32) + 20i64) < (unsigned int)(*(_DWORD *)(*(_QWORD *)(v88 + 32) + 16i64) + *(_DWORD *)(*(_QWORD *)(v88 + 32) + 20i64));
                }
              }
              if ( !v91 )
                break;
              v100[k--] = v88;
            }
            ++v82;
            ++v84;
            v100[k] = v85;
          }
          while ( v82 < v83 );
        }
        v7 = v104;
      }
    }
    else
    {
      v35 = left;
      v36 = left->mTransform.v2.z;
      v37 = &left + v33 / 2;
      v38 = *v37;
      v39 = (*v37)->mTransform.v2.z;
      v40 = LODWORD(v39) < LODWORD(v36);
      if ( LODWORD(v39) == LODWORD(v36) )
      {
        v41 = v38->mTransformInv.v0.z;
        v42 = left->mTransformInv.v0.z;
        v40 = LODWORD(v41) < LODWORD(v42);
        if ( LODWORD(v41) == LODWORD(v42) )
        {
          v43 = v38->mTransform.v3.z;
          v44 = left->mTransform.v3.z;
          v40 = LODWORD(v43) < LODWORD(v44);
          if ( LODWORD(v43) == LODWORD(v44) )
            v40 = *(_DWORD *)(*(_QWORD *)&v38->mTransform.v2.x + 16i64)
                + *(_DWORD *)(*(_QWORD *)&v38->mTransform.v2.x + 20i64) < (unsigned int)(*(_DWORD *)(*(_QWORD *)&left->mTransform.v2.x + 16i64)
                                                                                       + *(_DWORD *)(*(_QWORD *)&left->mTransform.v2.x + 20i64));
        }
      }
      if ( v40 )
      {
        *v37 = left;
        v35 = v38;
        left = v38;
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
        v35 = left;
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
        left = v54;
      }
      v62 = *v37;
      v63 = &left;
      v64 = &right + (signed int)v26;
      if ( &left <= v32 )
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
            if ( !v75 || &left >= v64 )
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
      if ( &left < v64 )
        UFG::qQuickSortImpl<Render::Light *,bool (*)(Render::Light const *,Render::Light const *)>(
          &left,
          v64,
          (bool (__fastcall *)(Render::IrradianceVolume *, Render::IrradianceVolume *))UFG::ResourcePool::RequestSortPredicate);
      if ( v63 < v32 )
        UFG::qQuickSortImpl<Render::Light *,bool (*)(Render::Light const *,Render::Light const *)>(
          v63,
          &right + (signed int)v26,
          (bool (__fastcall *)(Render::IrradianceVolume *, Render::IrradianceVolume *))UFG::ResourcePool::RequestSortPredicate);
    }
    if ( v26 )
    {
      v96 = &left;
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
  UFG::ResourcePool *v1; // r12
  __int64 v2; // rdi
  bool v3; // r15
  UFG::ResourcePriorityBucket *v4; // r10
  UFG::ResourcePriorityBucket *v5; // r9
  int v6; // esi
  int v7; // er14
  unsigned int v8; // eax
  __int64 v9; // rbx
  float *v10; // r11
  __int64 v11; // r9
  UFG::ResourcePriorityBucket *v12; // r8
  UFG::ResourcePriorityBucket *v13; // rdx
  int v14; // er10
  int v15; // edx
  float v16; // xmm4_4
  float v17; // xmm1_4
  signed int v18; // er8
  float v19; // xmm2_4
  float v20; // xmm1_4
  unsigned int v21; // ecx
  unsigned int v22; // eax
  unsigned int v23; // ecx
  unsigned int v24; // eax
  unsigned int v25; // er14
  int v26; // ecx
  UFG::qArray<UFG::PreloadRequest *,0> *v27; // r8
  unsigned int v28; // edx
  UFG::PreloadRequest **v29; // r8
  UFG::PreloadRequest *v30; // r15
  UFG::ResourcePriorityBucket *v31; // r8
  UFG::ResourcePriorityBucket *v32; // rdx
  unsigned int v33; // er13
  int v34; // eax
  unsigned int v35; // er13
  unsigned int v36; // er12
  int v37; // eax
  unsigned int v38; // er12
  UFG::PartDatabase *v39; // rax
  UFG::PartDatabase *v40; // rdx
  UFG::PartPool::Bucket *v41; // rcx
  unsigned int v42; // eax
  UFG::TrueCrowdSet::Instance *v43; // r14
  UFG::TrueCrowdSet *v44; // rdi
  unsigned int v45; // edx
  __int64 v46; // rbx
  unsigned int v47; // eax
  UFG::ModelTextureCombination *v48; // r8
  unsigned int v49; // er10
  unsigned int v50; // er9
  unsigned int v51; // eax
  UFG::ModelTextureCombination *v52; // r8
  __int64 v53; // r11
  __int64 v54; // rcx
  __int64 v55; // rdx
  __int64 v56; // rax
  __int64 v57; // rax
  signed __int64 v58; // rcx
  signed __int64 v59; // rdx
  __int64 v60; // rax
  __int64 v61; // rcx
  unsigned int v63; // edx
  UFG::EntityTypeState *v64; // r13
  unsigned int v65; // edx
  signed int v66; // ecx
  UFG::qColour **v67; // rax
  UFG::PreloadRequest *v68; // r15
  UFG::TrueCrowdSet *v69; // rsi
  UFG::TrueCrowdDataBase *v70; // rdx
  unsigned int v71; // edi
  unsigned int v72; // ebx
  int v73; // er9
  unsigned int v74; // ecx
  UFG::TrueCrowdModel ***v75; // r10
  __int64 v76; // r11
  unsigned int v77; // eax
  UFG::TrueCrowdModel **v78; // rcx
  __int64 v79; // r8
  UFG::ResourceRequest *v80; // rdx
  UFG::PartDatabase *v81; // rax
  UFG::PartPool::Bucket *v82; // rdx
  unsigned int v83; // er10
  unsigned int v84; // er11
  unsigned int v85; // ebx
  UFG::ModelTextureCombination *v86; // r8
  signed __int64 v87; // rsi
  __int64 v88; // r9
  __int64 v89; // rdx
  __int64 v90; // rax
  __int64 v91; // rax
  signed __int64 v92; // rcx
  signed __int64 v93; // rdx
  __int64 v94; // rax
  __int64 v95; // rcx
  UFG::MeshResourceLoader *v96; // rsi
  UFG::TrueCrowdModel *v97; // rax
  UFG::TrueCrowdResource *v98; // rdi
  UFG::TrueCrowdTextureSet *v99; // rax
  UFG::TrueCrowdResource *v100; // rbx
  unsigned int v101; // ecx
  unsigned int v102; // er15
  unsigned int v103; // ecx
  unsigned int v104; // er14
  UFG::ResourceUser user; // [rsp+38h] [rbp-C8h]
  UFG::ResourceUser v106; // [rsp+48h] [rbp-B8h]
  __int64 v107; // [rsp+58h] [rbp-A8h]
  UFG::TrueCrowdSet::Instance instance; // [rsp+60h] [rbp-A0h]
  UFG::ResourcePool *reason; // [rsp+1D0h] [rbp+D0h]
  char v110; // [rsp+1D8h] [rbp+D8h]
  unsigned int v111; // [rsp+1E0h] [rbp+E0h]
  UFG::PreloadRequest *candidate; // [rsp+1E8h] [rbp+E8h]

  reason = this;
  v107 = -2i64;
  v1 = this;
  LOBYTE(v2) = 0;
  v110 = 0;
  v3 = UFG::LoadingLogic::IsLoadingScreenUp(&UFG::gLoadingLogic);
  v4 = v1->mHighBucket;
  v5 = v1->mLowBucket;
  v6 = v1->mAmbientModelMemoryLimit
     - (v4->mMemoryUsage[0][1]
      + v4->mMemoryUsage[1][1]
      + v4->mMemoryUsage[2][1]
      + v5->mMemoryUsage[0][1]
      + v5->mMemoryUsage[1][1]
      + v5->mMemoryUsage[2][1]);
  v7 = v1->mAmbientTextureMemoryLimit
     - (v5->mMemoryUsage[0][0]
      + v5->mMemoryUsage[1][0]
      + v5->mMemoryUsage[2][0]
      + v4->mMemoryUsage[0][0]
      + v4->mMemoryUsage[1][0]
      + v4->mMemoryUsage[2][0]);
  v8 = v1->mEntityStates.size;
  if ( v8 )
  {
    v9 = 0i64;
    v2 = v8;
    do
    {
      v10 = (float *)v1->mEntityStates.p[v9];
      v11 = *(signed int *)v10;
      v12 = v1->mHighBucket;
      v13 = v1->mLowBucket;
      v14 = v12->mMemoryUsage[v11][1] + v13->mMemoryUsage[v11][1];
      v15 = v12->mMemoryUsage[v11][0] + v13->mMemoryUsage[v11][0];
      v10[3] = (float)v14 / (float)(signed int)v1->mAmbientModelMemoryLimit;
      v10[5] = (float)v15 / (float)(signed int)v1->mAmbientTextureMemoryLimit;
      v16 = v10[2];
      v17 = (float)((signed int)(float)((float)(signed int)v1->mAmbientModelMemoryLimit * v10[2]) - v14);
      if ( v17 <= 0.0 )
        v17 = 0.0;
      v18 = (signed int)v17;
      *((_DWORD *)v10 + 6) = (signed int)v17;
      v19 = v10[4];
      v20 = (float)((signed int)(float)((float)(signed int)v1->mAmbientTextureMemoryLimit * v19) - v15);
      if ( v20 <= 0.0 )
        v20 = 0.0;
      *((_DWORD *)v10 + 7) = (signed int)v20;
      if ( v3 )
      {
        v21 = (signed int)(float)((float)v6 * v16);
        v22 = 0;
        if ( v18 )
          v22 = v18;
        if ( v22 < v21 )
          v21 = v22;
        *((_DWORD *)v10 + 6) = v21;
        v23 = (signed int)(float)((float)v7 * v19);
        v24 = 0;
        if ( (signed int)v20 )
          v24 = (signed int)v20;
        if ( v24 < v23 )
          v23 = v24;
        *((_DWORD *)v10 + 7) = v23;
      }
      ++v9;
      --v2;
    }
    while ( v2 );
  }
  v25 = 0;
  if ( !UFG::ResourcePool::BasicAmbienceLoaded(v1) || (v26 = 0, v27 = v1->mPreloadBuckets, (v28 = v27[2].size) == 0) )
  {
LABEL_59:
    v63 = 0;
    v111 = 0;
    if ( !v1->mEntityStates.size )
      return v2;
    while ( 1 )
    {
      v64 = v1->mEntityStates.p[v63];
      v65 = v63 + 3;
      if ( v1->mPreloadBuckets[v65].size )
      {
        LODWORD(reason) = 2;
        UFG::ResourcePool::GetExpansionCandidate(v1, v65, &candidate, (UFG::ResourcePool::ExpansionReason *)&reason);
        if ( !(_DWORD)reason )
        {
          v66 = 15;
          v67 = &instance.mPart[0].mColourTint;
          do
          {
            *(v67 - 1) = 0i64;
            *v67 = 0i64;
            v67 += 2;
            --v66;
          }
          while ( v66 >= 0 );
          v68 = candidate;
          v69 = candidate->mInstance.mSet;
          instance.mSet = v69;
          v70 = UFG::TrueCrowdDataBase::sTrueCrowdDataBase;
          v71 = UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition.mEntities[v69->mEntityIndex].mComponentCount;
          instance.mNumParts = v71;
          v72 = 0;
          if ( v71 )
          {
            while ( 1 )
            {
              if ( v69->mComponentDetails[v72++].mbSpecificModel )
              {
                UFG::TrueCrowdSet::ChooseSpecificModel(v69, v72, &instance.mPart[v72], 0i64);
              }
              else
              {
                v73 = 0;
                v74 = v70->mDefinition.mEntities[v69->mEntityIndex].mComponentCount;
                if ( !v74 )
                  goto LABEL_126;
                v75 = &v69->mFiles[0].p;
                v76 = v74;
                do
                {
                  v77 = *((_DWORD *)v75 - 2);
                  if ( v77 )
                  {
                    v78 = *v75;
                    v79 = v77;
                    do
                    {
                      v80 = (*v78)->mRequest;
                      if ( v80 && v80->mLoadStatus == 3 )
                        ++v73;
                      ++v78;
                      --v79;
                    }
                    while ( v79 );
                  }
                  v75 += 2;
                  --v76;
                }
                while ( v76 );
                if ( v73 )
                  UFG::TrueCrowdSet::ChooseLeastCommonModel(v69, v72, &instance.mPart[v72], 0i64);
                else
LABEL_126:
                  UFG::TrueCrowdSet::ChooseRandomModel(v69, v72, &instance.mPart[v72], 0i64);
              }
              v71 = instance.mNumParts;
              if ( v72 >= instance.mNumParts )
                break;
              v70 = UFG::TrueCrowdDataBase::sTrueCrowdDataBase;
            }
            v69 = instance.mSet;
          }
          v81 = UFG::PartDatabase::Instance();
          v82 = v81->mPool.mMasterBucket;
          v83 = v81->mPool.mMaxModelMemory - v81->mPool.mExternalUsedModelMemory - v82->mMemoryUsageModel;
          if ( v64->mAvailableAmbientModelMemory < v83 )
            v83 = v64->mAvailableAmbientModelMemory;
          v84 = v81->mPool.mMaxTextureMemory - v81->mPool.mExternalUsedTextureMemory - v82->mMemoryUsageTexture;
          if ( v64->mAvailableAmbientTextureMemory < v84 )
            v84 = v64->mAvailableAmbientTextureMemory;
          v85 = 0;
          if ( !v71 )
            goto LABEL_124;
          v86 = instance.mPart;
          v87 = (char *)v69 - (char *)instance.mPart;
          v88 = v71;
          do
          {
            if ( v86->mModelIndex != -1 )
            {
              v89 = *((_QWORD *)&(*(UFG::qColour **)((char *)&v86[3].mColourTint + v87))->r + v86->mModelIndex);
              v90 = *(_QWORD *)(v89 + 8);
              if ( !v90 || *(_DWORD *)(v90 + 20) != 3 )
              {
                v25 += *(_DWORD *)(v89 + 16);
                v85 += *(_DWORD *)(v89 + 20);
              }
              if ( *(_WORD *)(v89 + 58) )
              {
                v91 = *(_QWORD *)(v89 + 72);
                if ( v91 )
                  v92 = v91 + v89 + 72;
                else
                  v92 = 0i64;
                v93 = v92 + 8i64 * v86->mTextureSetIndex;
                v94 = *(_QWORD *)v93;
                if ( *(_QWORD *)v93 )
                  v94 += v93;
                v95 = *(_QWORD *)(v94 + 8);
                if ( !v95 || *(_DWORD *)(v95 + 20) != 3 )
                  v85 += *(_DWORD *)(v94 + 20);
              }
            }
            ++v86;
            --v88;
          }
          while ( v88 );
          if ( v25 <= v83 && v85 <= v84 )
          {
LABEL_124:
            LOBYTE(v2) = 1;
            v110 = 1;
            UFG::ResourcePool::PreloadInstance(v1, v68, &instance);
            v64->mAvailableAmbientModelMemory -= v25;
            v64->mAvailableAmbientTextureMemory -= v85;
            goto LABEL_119;
          }
          goto LABEL_116;
        }
        if ( (_DWORD)reason == 1 )
        {
          v96 = (UFG::MeshResourceLoader *)candidate;
          v97 = UFG::TrueCrowdSet::ChooseNextPart(candidate->mInstance.mSet);
          v98 = (UFG::TrueCrowdResource *)&v97->mName;
          v99 = UFG::TrueCrowdModel::ChooseNextTextureSet(v97);
          v100 = (UFG::TrueCrowdResource *)&v99->mName;
          if ( v99 )
            v101 = v99->mModelSize;
          else
            v101 = 0;
          v102 = v101 + v98->mModelSize;
          if ( v99 )
            v103 = v99->mTextureSize;
          else
            v103 = 0;
          v104 = v98->mTextureSize + v103;
          if ( v102 <= v64->mAvailableAmbientModelMemory && v104 <= v64->mAvailableAmbientTextureMemory )
          {
            v110 = 1;
            LODWORD(reason) = qSymbol_Low;
            user.mMeshLoader = v96;
            user.mType = 1;
            UFG::ResourcePool::RequestLoadResource(v1, v98, 0, (__int64)&reason, &user);
            v64->mAvailableAmbientModelMemory -= v102;
            v64->mAvailableAmbientTextureMemory -= v104;
            if ( v100 )
            {
              LODWORD(reason) = qSymbol_Low;
              v106.mMeshLoader = v96;
              v106.mType = 1;
              UFG::ResourcePool::RequestLoadResource(v1, v100, 1, (__int64)&reason, &v106);
              goto LABEL_116;
            }
            LOBYTE(v2) = 1;
LABEL_119:
            v25 = 0;
            goto LABEL_120;
          }
LABEL_116:
          LOBYTE(v2) = v110;
          goto LABEL_119;
        }
      }
      LOBYTE(v2) = v110;
LABEL_120:
      v63 = v111 + 1;
      v111 = v63;
      if ( v63 >= v1->mEntityStates.size )
        return v2;
    }
  }
  v29 = v27[2].p;
  while ( 1 )
  {
    v30 = v29[v26];
    if ( !v30->mPreloadActive )
      break;
    if ( ++v26 >= v28 )
      goto LABEL_59;
  }
  v31 = v1->mHighBucket;
  v32 = v1->mLowBucket;
  v33 = v1->mAmbientModelMemoryLimit;
  v34 = v33;
  if ( v32->mMemoryUsage[0][1]
     + v32->mMemoryUsage[1][1]
     + v32->mMemoryUsage[2][1]
     + v31->mMemoryUsage[0][1]
     + v31->mMemoryUsage[1][1]
     + v31->mMemoryUsage[2][1] < v33 )
    v34 = v32->mMemoryUsage[0][1]
        + v32->mMemoryUsage[1][1]
        + v32->mMemoryUsage[2][1]
        + v31->mMemoryUsage[0][1]
        + v31->mMemoryUsage[1][1]
        + v31->mMemoryUsage[2][1];
  v35 = v33 - v34;
  v36 = v1->mAmbientTextureMemoryLimit;
  v37 = v36;
  if ( v32->mMemoryUsage[0][0]
     + v32->mMemoryUsage[1][0]
     + v32->mMemoryUsage[2][0]
     + v31->mMemoryUsage[0][0]
     + v31->mMemoryUsage[1][0]
     + v31->mMemoryUsage[2][0] < v36 )
    v37 = v32->mMemoryUsage[0][0]
        + v32->mMemoryUsage[1][0]
        + v32->mMemoryUsage[2][0]
        + v31->mMemoryUsage[0][0]
        + v31->mMemoryUsage[1][0]
        + v31->mMemoryUsage[2][0];
  v38 = v36 - v37;
  v39 = UFG::PartDatabase::Instance();
  v40 = v39;
  v41 = v39->mPool.mMasterBucket;
  v42 = v39->mPool.mMaxModelMemory - v41->mMemoryUsageModel - v39->mPool.mExternalUsedModelMemory;
  if ( v35 >= v42 )
    v35 = v42;
  if ( v38 >= v40->mPool.mMaxTextureMemory - v41->mMemoryUsageTexture - v40->mPool.mExternalUsedTextureMemory )
    v38 = v40->mPool.mMaxTextureMemory - v41->mMemoryUsageTexture - v40->mPool.mExternalUsedTextureMemory;
  v43 = &v30->mInstance;
  v44 = v30->mInstance.mSet;
  v45 = UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition.mEntities[v44->mEntityIndex].mComponentCount;
  v30->mInstance.mNumParts = v45;
  v46 = 0i64;
  if ( v45 )
  {
    do
    {
      if ( v44->mComponentDetails[v46].mbSpecificModel )
      {
        UFG::TrueCrowdSet::ChooseSpecificModel(v44, v46, &v43->mPart[(unsigned int)v46], 0i64);
      }
      else
      {
        v47 = UFG::TrueCrowdSet::GetNumModelsLoaded(v44);
        v48 = &v43->mPart[(unsigned int)v46];
        if ( v47 )
          UFG::TrueCrowdSet::ChooseLeastCommonModel(v44, v46, v48, 0i64);
        else
          UFG::TrueCrowdSet::ChooseRandomModel(v44, v46, v48, 0i64);
      }
      v46 = (unsigned int)(v46 + 1);
    }
    while ( (unsigned int)v46 < v30->mInstance.mNumParts );
  }
  v49 = 0;
  v50 = 0;
  v51 = v30->mInstance.mNumParts;
  if ( !v51 )
    goto LABEL_125;
  v52 = v30->mInstance.mPart;
  v53 = v51;
  do
  {
    v54 = v52->mModelIndex;
    if ( (_DWORD)v54 != -1 )
    {
      v55 = *(_QWORD *)(*(_QWORD *)((char *)&v43->mSet->mResourceFilename.mUID + (unsigned __int64)v52 - (_QWORD)v43)
                      + 8 * v54);
      v56 = *(_QWORD *)(v55 + 8);
      if ( !v56 || *(_DWORD *)(v56 + 20) != 3 )
      {
        v49 += *(_DWORD *)(v55 + 16);
        v50 += *(_DWORD *)(v55 + 20);
      }
      if ( *(_WORD *)(v55 + 58) )
      {
        v57 = *(_QWORD *)(v55 + 72);
        if ( v57 )
          v58 = v55 + v57 + 72;
        else
          v58 = 0i64;
        v59 = v58 + 8i64 * v52->mTextureSetIndex;
        v60 = *(_QWORD *)v59;
        if ( *(_QWORD *)v59 )
          v60 += v59;
        v61 = *(_QWORD *)(v60 + 8);
        if ( !v61 || *(_DWORD *)(v61 + 20) != 3 )
          v50 += *(_DWORD *)(v60 + 20);
      }
    }
    ++v52;
    --v53;
  }
  while ( v53 );
  if ( v49 > v35 || v50 > v38 )
    return 0;
LABEL_125:
  UFG::ResourcePool::PreloadInstance(reason, v30, &v30->mInstance);
  return 1;
}> v35 || v50 > v38 )
    return 0;
LABEL_125:
  UFG::ResourcePool::PreloadInstance(reason, v30, &v30->mInstance);
  return 1;
}

// File Line: 1207
// RVA: 0x43D990
void __fastcall UFG::ResourcePool::GetExpansionCandidate(UFG::ResourcePool *this, unsigned int preloadBucketIndex, UFG::PreloadRequest **candidate, UFG::ResourcePool::ExpansionReason *reason)
{
  UFG::qArray<UFG::PreloadRequest *,0> *v4; // r13
  signed __int64 v5; // r15
  unsigned int v6; // er10
  unsigned int v7; // edi
  UFG::PreloadRequest **v8; // rax
  float v9; // xmm1_4
  unsigned int v10; // ebx
  unsigned int v11; // er14
  UFG::PreloadRequest **v12; // rsi
  unsigned int v13; // er10
  UFG::TrueCrowdSet *v14; // r9
  unsigned int v15; // er11
  UFG::TrueCrowdModel ***v16; // r9
  unsigned int v17; // er8
  unsigned int v18; // edx
  UFG::TrueCrowdModel **v19; // rcx
  UFG::PreloadRequest **v20; // [rsp+50h] [rbp+18h]
  UFG::ResourcePool::ExpansionReason *v21; // [rsp+58h] [rbp+20h]

  v21 = reason;
  v20 = candidate;
  *candidate = 0i64;
  *reason = 2;
  v4 = this->mPreloadBuckets;
  v5 = preloadBucketIndex;
  v6 = 0;
  v7 = v4[preloadBucketIndex].size;
  if ( v7 )
  {
    v8 = v4[preloadBucketIndex].p;
    while ( (*v8)->mPreloadActive )
    {
      ++v6;
      ++v8;
      if ( v6 >= v7 )
        goto LABEL_5;
    }
    *candidate = *v8;
    *reason = 0;
  }
  else
  {
LABEL_5:
    if ( preloadBucketIndex >= 3 )
    {
      v9 = FLOAT_N3_4028235e38;
      v10 = 0;
      v11 = v4[preloadBucketIndex].size;
      if ( v7 )
      {
        v12 = v4[preloadBucketIndex].p;
        do
        {
          v13 = 0;
          v14 = (*v12)->mInstance.mSet;
          v15 = UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition.mEntities[v14->mEntityIndex].mComponentCount;
          if ( v15 )
          {
            v16 = &v14->mFiles[0].p;
            while ( 1 )
            {
              v17 = *((_DWORD *)v16 - 2);
              v18 = 0;
              if ( v17 )
                break;
LABEL_14:
              ++v13;
              v16 += 2;
              if ( v13 >= v15 )
                goto LABEL_19;
            }
            v19 = *v16;
            while ( (*v19)->mRequest )
            {
              ++v18;
              ++v19;
              if ( v18 >= v17 )
                goto LABEL_14;
            }
            if ( (*v12)->mVarietyRatio > v9 )
            {
              v9 = (*v12)->mVarietyRatio;
              v11 = v10;
            }
          }
LABEL_19:
          ++v10;
          ++v12;
        }
        while ( v10 < v7 );
        reason = v21;
        candidate = v20;
      }
      if ( v11 != v7 )
      {
        *candidate = v4[v5].p[v11];
        *reason = 1;
      }
    }
  }
}

// File Line: 1250
// RVA: 0x445670
char __fastcall UFG::ResourcePool::UpdateAmbientPreloads(UFG::ResourcePool *this)
{
  UFG::ResourcePool *v1; // rdi
  UFG::ResourcePriorityBucket *v2; // r10
  UFG::ResourcePriorityBucket *v3; // r9
  float v4; // xmm2_4
  float v5; // xmm1_4
  unsigned int v6; // er11
  unsigned int v7; // er8
  unsigned int v8; // edx
  unsigned int v9; // ebx
  unsigned int v10; // ecx
  unsigned int v11; // ecx
  unsigned int v12; // ebx
  UFG::ResourcePriorityBucket *v13; // r8
  unsigned int v14; // edx
  unsigned int v15; // er10
  unsigned int v16; // eax
  unsigned int v17; // er10
  UFG::ResourcePriorityBucket *v18; // rdx
  unsigned int v19; // er9
  unsigned int v20; // er11
  signed int v21; // ecx
  int v22; // edx
  unsigned int v23; // eax
  signed int v24; // er10
  int v25; // er8
  float v26; // xmm0_4
  unsigned int v27; // edx

  v1 = this;
  if ( this->mDirty )
    UFG::ResourcePool::UpdateVarietyRatios(this);
  v2 = v1->mReservedBucket;
  v3 = v1->mCriticalBucket;
  v4 = v1->mFragmentationReservePercentage;
  v5 = 0.0;
  v6 = 0;
  v7 = v2->mMemoryUsage[0][1] + v2->mMemoryUsage[1][1] + v2->mMemoryUsage[2][1];
  v8 = 0;
  if ( v2->mReserveSize[1] > 0 )
    v8 = v2->mReserveSize[1];
  v9 = v3->mMemoryUsage[0][1] + v3->mMemoryUsage[1][1] + v3->mMemoryUsage[2][1];
  v10 = 0;
  if ( v3->mReserveSize[1] > 0 )
    v10 = v3->mReserveSize[1];
  if ( v10 > v9 )
    v9 = v10;
  v11 = 0;
  if ( v8 > v7 )
    v7 = v8;
  v12 = v7 + v9;
  v13 = v1->mHighBucket;
  v14 = v2->mMemoryUsage[0][0] + v2->mMemoryUsage[1][0] + v2->mMemoryUsage[2][0];
  if ( v2->mReserveSize[0] > 0 )
    v11 = v2->mReserveSize[0];
  v15 = v3->mMemoryUsage[0][0] + v3->mMemoryUsage[1][0] + v3->mMemoryUsage[2][0];
  if ( v3->mReserveSize[0] > 0 )
    v6 = v3->mReserveSize[0];
  v16 = v1->mMaxModelMemory;
  if ( v6 > v15 )
    v15 = v6;
  if ( v11 > v14 )
    v14 = v11;
  v17 = v14 + v15;
  v18 = v1->mLowBucket;
  v19 = v13->mMemoryUsage[0][1]
      + v13->mMemoryUsage[1][1]
      + v13->mMemoryUsage[2][1]
      + v18->mMemoryUsage[0][1]
      + v18->mMemoryUsage[1][1]
      + v18->mMemoryUsage[2][1];
  v20 = v13->mMemoryUsage[0][0]
      + v13->mMemoryUsage[1][0]
      + v13->mMemoryUsage[2][0]
      + v18->mMemoryUsage[0][0]
      + v18->mMemoryUsage[1][0]
      + v18->mMemoryUsage[2][0];
  v21 = v1->mMaxModelMemory;
  if ( v12 < v16 )
    v16 = v12;
  v22 = v21 - v16;
  v1->mAmbientModelMemoryLimit = v21 - v16;
  v23 = v1->mMaxTextureMemory;
  if ( v17 < v23 )
    v23 = v17;
  v24 = v1->mMaxTextureMemory;
  v25 = v1->mMaxTextureMemory - v23;
  v1->mAmbientTextureMemoryLimit = v25;
  v26 = (float)(v22 - (signed int)(float)((float)v21 * v4));
  if ( v26 < 0.0 )
    v26 = 0.0;
  v27 = (signed int)v26;
  v1->mAmbientModelMemoryLimit = (signed int)v26;
  if ( (float)(v25 - (signed int)(float)((float)v24 * v4)) >= 0.0 )
    v5 = (float)(v25 - (signed int)(float)((float)v24 * v4));
  v1->mAmbientTextureMemoryLimit = (signed int)v5;
  if ( v20 > (signed int)v5 || v19 > v27 || v1->mStreamerStalled && !v1->mUnReferencedBucket->mResourceRequests.size )
  {
    UFG::ResourcePool::ContractAmbientModels(v1, 1u);
  }
  else if ( v27 && (signed int)v5 )
  {
    return UFG::ResourcePool::ExpandAmbience(v1);
  }
  return 0;
}

// File Line: 1302
// RVA: 0x438D20
char __fastcall UFG::ResourcePool::BasicAmbienceLoaded(UFG::ResourcePool *this)
{
  unsigned int v1; // er12
  unsigned int v2; // ebp
  UFG::ResourcePool *v3; // r13
  UFG::EntityTypeState **v4; // r14
  unsigned int v5; // er15
  UFG::qArray<UFG::PreloadRequest *,0> *v6; // rax
  unsigned int v7; // ebx
  unsigned int v8; // esi
  UFG::PreloadRequest **v9; // rdi

  v1 = this->mEntityStates.size;
  v2 = 0;
  v3 = this;
  if ( v1 )
  {
    v4 = this->mEntityStates.p;
    v5 = 3;
    do
    {
      if ( (*v4)->mActive && (*v4)->mHasMinimumAmbienceRequirement )
      {
        v6 = v3->mPreloadBuckets;
        v7 = 0;
        v8 = v6[v5].size;
        if ( !v8 )
          return 0;
        v9 = v6[v5].p;
        while ( !UFG::TrueCrowdSet::IsLoaded((*v9)->mInstance.mSet) )
        {
          ++v7;
          ++v9;
          if ( v7 >= v8 )
            return 0;
        }
      }
      ++v2;
      ++v5;
      ++v4;
    }
    while ( v2 < v1 );
  }
  return 1;
}

// File Line: 1341
// RVA: 0x4428A0
UFG::PreloadRequest *__fastcall UFG::ResourcePool::RequestPreload(UFG::ResourcePool *this, UFG::TrueCrowdSet::Instance *instance, unsigned int preloadBucketIndex, bool directRequest)
{
  UFG::TrueCrowdSet::Instance *v4; // rdi
  UFG::ResourcePool *v5; // rbp
  unsigned int v6; // ebx
  unsigned int v7; // er14
  BOOL v8; // er11
  int v9; // edx
  __int64 v10; // r15
  UFG::qArray<UFG::PreloadRequest *,0> *v11; // r8
  unsigned int v12; // er9
  UFG::PreloadRequest **v13; // r8
  UFG::PreloadRequest *v14; // rax
  UFG::PreloadRequest *result; // rax
  UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *v16; // rsi
  UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *v17; // rcx
  UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *v18; // rax
  UFG::allocator::free_link *v19; // rax
  UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *v20; // rax
  UFG::qArray<UFG::PreloadRequest *,0> *v21; // r12
  unsigned int v22; // ecx
  unsigned int v23; // er13
  unsigned int v24; // ebp
  signed __int64 v25; // r8
  unsigned int v26; // ebp
  unsigned __int64 v27; // rax
  UFG::allocator::free_link *v28; // rax
  UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *v29; // rax
  UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *v30; // rcx
  UFG::allocator::free_link *v31; // [rsp+20h] [rbp-48h]
  UFG::ResourcePool *v32; // [rsp+70h] [rbp+8h]
  BOOL v33; // [rsp+88h] [rbp+20h]

  v32 = this;
  v4 = instance;
  v5 = this;
  if ( preloadBucketIndex )
  {
    if ( preloadBucketIndex == 1 )
    {
      v6 = qSymbol_Critical.mUID;
    }
    else if ( preloadBucketIndex == 2 )
    {
      v6 = qSymbol_High.mUID;
    }
    else
    {
      v6 = qSymbol_Low.mUID;
    }
  }
  else
  {
    v6 = qSymbol_Reserved.mUID;
  }
  v7 = 0;
  v8 = directRequest != 0;
  v33 = directRequest != 0;
  v9 = 0;
  v10 = preloadBucketIndex;
  v11 = this->mPreloadBuckets;
  v12 = v11[v10].size;
  if ( v12 )
  {
    v13 = v11[v10].p;
    while ( v13[v9]->mInstance.mSet != v4->mSet )
    {
      if ( ++v9 >= v12 )
        goto LABEL_17;
    }
    v14 = v13[v9];
    if ( v8 )
      ++v14->mDirectRequestCount;
    else
      v14->mSpawnSetValid = 1;
    result = this->mPreloadBuckets[v10].p[v9];
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
        v16 = v20;
      }
      else
      {
        v16 = 0i64;
      }
    }
    else
    {
      v16 = this->mEmptyRequestList.mNode.mNext;
      v17 = v16->mPrev;
      v18 = v16->mNext;
      v17->mNext = v18;
      v18->mPrev = v17;
      v16->mPrev = v16;
      v16->mNext = v16;
      BYTE1(v16[19].mNext) = 0;
      BYTE4(v16[20].mPrev) = 0;
      HIDWORD(v16[19].mNext) = 0;
      v16[1].mPrev = 0i64;
      LODWORD(v16[1].mNext) = 0;
      v16[2].mPrev = 0i64;
      LODWORD(v16[2].mNext) = 0;
    }
    v21 = v5->mPreloadBuckets;
    v22 = v21[v10].size;
    v23 = v22 + 1;
    v24 = v21[v10].capacity;
    v25 = 2i64;
    if ( v22 + 1 > v24 )
    {
      if ( v24 )
        v26 = 2 * v24;
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
    v32->mPreloadBuckets[v10].p[v32->mPreloadBuckets[v10].size - 1] = (UFG::PreloadRequest *)v16;
    if ( v6 == qSymbol_Low.mUID )
    {
      v29 = (UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *)v4->mSet;
      LOBYTE(v16[19].mNext) = 1;
      v16[2].mPrev = v29;
    }
    else
    {
      LOBYTE(v16[19].mNext) = 0;
      v30 = v16 + 2;
      if ( ((unsigned __int8)((_BYTE)v16 + 32) | (unsigned __int8)v4) & 0xF )
      {
        memmove(v30, v4, 0x118ui64);
      }
      else
      {
        do
        {
          *v30 = *(UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *)&v4->mSet;
          v30[1] = *(UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *)&v4->mMorphWeights[1];
          v30[2] = *(UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *)&v4->mPart[0].mColourTint;
          v30[3] = *(UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *)&v4->mPart[1].mColourTint;
          v30[4] = *(UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *)&v4->mPart[2].mColourTint;
          v30[5] = *(UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *)&v4->mPart[3].mColourTint;
          v30[6] = *(UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *)&v4->mPart[4].mColourTint;
          v30 += 8;
          v30[-1] = *(UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *)&v4->mPart[5].mColourTint;
          v4 = (UFG::TrueCrowdSet::Instance *)((char *)v4 + 128);
          --v25;
        }
        while ( v25 );
        *v30 = *(UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *)&v4->mSet;
        v30[1].mPrev = *(UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> **)&v4->mMorphWeights[1];
      }
    }
    if ( v33 )
      ++HIDWORD(v16[19].mNext);
    else
      BYTE1(v16[19].mNext) = 1;
    LODWORD(v16[20].mPrev) = v6;
    result = (UFG::PreloadRequest *)v16;
  }
  return result;
}

// File Line: 1398
// RVA: 0x441950
void __fastcall UFG::ResourcePool::ReleasePreload(UFG::ResourcePool *this, UFG::TrueCrowdSet *resourceSet, unsigned int preloadBucketIndex, bool directRequest)
{
  UFG::ResourcePool *v4; // rdi
  UFG::qArray<UFG::PreloadRequest *,0> *v5; // rax
  BOOL v6; // ecx
  signed __int64 v7; // rsi
  UFG::TrueCrowdSet *v8; // r10
  unsigned int v9; // er9
  unsigned int v10; // edx
  UFG::PreloadRequest **v11; // rax
  UFG::PreloadRequest *v12; // rbx
  __int64 v13; // rcx
  UFG::qArray<UFG::PreloadRequest *,0> *v14; // r9
  unsigned int v15; // er8
  UFG::PreloadRequest **v16; // rdx
  UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *v17; // rax

  v4 = this;
  v5 = this->mPreloadBuckets;
  v6 = directRequest != 0;
  v7 = preloadBucketIndex;
  v8 = resourceSet;
  v9 = 0;
  v10 = v5[v7].size;
  if ( v10 )
  {
    v11 = v5[v7].p;
    while ( 1 )
    {
      v12 = *v11;
      if ( (*v11)->mInstance.mSet == v8 )
        break;
      ++v9;
      ++v11;
      if ( v9 >= v10 )
        return;
    }
    if ( v6 )
      --v12->mDirectRequestCount;
    else
      v12->mSpawnSetValid = 0;
    if ( !v12->mSpawnSetValid && !v12->mDirectRequestCount )
    {
      UFG::ResourcePool::ReleaseResourceSetFiles(v4, v12);
      v13 = 0i64;
      v14 = &v4->mPreloadBuckets[v7];
      v15 = v14->size;
      if ( v14->size )
      {
        v16 = v14->p;
        while ( v12 != v16[v13] )
        {
          v13 = (unsigned int)(v13 + 1);
          if ( (unsigned int)v13 >= v15 )
            goto LABEL_20;
        }
        if ( (signed int)v13 >= 0 )
        {
          v16[v13] = v16[v15 - 1];
          if ( v14->size > 1 )
            --v14->size;
          else
            v14->size = 0;
        }
      }
LABEL_20:
      v17 = v4->mEmptyRequestList.mNode.mPrev;
      v17->mNext = (UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *)&v12->mPrev;
      v12->mPrev = v17;
      v12->mNext = &v4->mEmptyRequestList.mNode;
      v4->mEmptyRequestList.mNode.mPrev = (UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *)&v12->mPrev;
    }
  }
}

// File Line: 1423
// RVA: 0x4417C0
void __fastcall UFG::ResourcePool::ReleaseAmbientPreloads(UFG::ResourcePool *this, UFG::TrueCrowdResource::EntityType type)
{
  UFG::ResourcePool *v2; // rdi
  unsigned int v3; // ecx
  unsigned int v4; // er8
  UFG::EntityTypeState **v5; // r9
  unsigned int v6; // er8
  signed __int64 v7; // rsi
  UFG::qArray<UFG::PreloadRequest *,0> *v8; // rax
  unsigned int v9; // er8
  UFG::PreloadRequest **v10; // rdx
  UFG::TrueCrowdSet *v11; // rcx
  unsigned int v12; // eax
  UFG::PreloadRequest *v13; // rbx
  __int64 v14; // rcx
  UFG::qArray<UFG::PreloadRequest *,0> *v15; // r9
  unsigned int v16; // edx
  UFG::PreloadRequest **v17; // r8
  UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *v18; // rax

  v2 = this;
  v3 = this->mEntityStates.size;
  v4 = 0;
  if ( v3 )
  {
    v5 = v2->mEntityStates.p;
    while ( type != (*v5)->mEntityType )
    {
      ++v4;
      ++v5;
      if ( v4 >= v3 )
        return;
    }
    v6 = v4 + 3;
    if ( v6 != -1 )
    {
      v7 = v6;
      while ( v2->mPreloadBuckets[v7].size )
      {
        v8 = v2->mPreloadBuckets;
        v9 = v8[v7].size;
        v10 = v8[v7].p;
        v11 = v10[v9 - 1]->mInstance.mSet;
        v12 = 0;
        if ( v9 )
        {
          while ( 1 )
          {
            v13 = *v10;
            if ( (*v10)->mInstance.mSet == v11 )
              break;
            ++v12;
            ++v10;
            if ( v12 >= v9 )
              goto LABEL_23;
          }
          v13->mSpawnSetValid = 0;
          if ( v13->mDirectRequestCount <= 0 )
          {
            UFG::ResourcePool::ReleaseResourceSetFiles(v2, v13);
            v14 = 0i64;
            v15 = &v2->mPreloadBuckets[v7];
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
              if ( (signed int)v14 >= 0 )
              {
                v17[v14] = v17[v16 - 1];
                if ( v15->size > 1 )
                  --v15->size;
                else
                  v15->size = 0;
              }
            }
LABEL_22:
            v18 = v2->mEmptyRequestList.mNode.mPrev;
            v18->mNext = (UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *)&v13->mPrev;
            v13->mPrev = v18;
            v13->mNext = &v2->mEmptyRequestList.mNode;
            v2->mEmptyRequestList.mNode.mPrev = (UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *)&v13->mPrev;
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
char __fastcall UFG::ResourcePool::CanSpawnAmbient(UFG::ResourcePool *this, UFG::TrueCrowdSet *trueCrowdSet, bool preloadedOnly)
{
  UFG::TrueCrowdSet *v3; // rbx
  unsigned int v4; // er11
  unsigned int v5; // er10
  UFG::qArray<UFG::PreloadRequest *,0> *v6; // r9
  char v7; // di
  unsigned int v8; // edx
  UFG::PreloadRequest **v9; // rax

  v3 = trueCrowdSet;
  if ( !preloadedOnly )
    return UFG::TrueCrowdSet::IsLoaded(trueCrowdSet);
  v4 = this->mNumPreloadBuckets;
  v5 = 2;
  if ( v4 <= 2 )
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
    if ( v5 >= v4 )
      return 0;
  }
  v9 = v6->p;
  while ( (*v9)->mInstance.mSet != v3 )
  {
    ++v8;
    ++v9;
    if ( v8 >= v6->size )
      goto LABEL_8;
  }
  if ( UFG::TrueCrowdSet::IsLoaded(v3) )
  {
    if ( UFG::TrueCrowdSet::IsPreloaded(v3) )
      v7 = 1;
  }
  return v7;
}

// File Line: 1459
// RVA: 0x447320
void __fastcall UFG::ResourcePool::UpdateVarietyRatios(UFG::ResourcePool *this)
{
  unsigned int v1; // er10
  signed int v2; // er15
  UFG::ResourcePool *v3; // r13
  __int64 v4; // r9
  UFG::qArray<UFG::PreloadRequest *,0> *v5; // r8
  __int64 v6; // rcx
  signed __int64 v7; // rdx
  unsigned int v8; // eax
  signed __int64 v9; // r12
  int v10; // ecx
  __int64 i; // rbp
  UFG::PreloadRequest *v12; // rdi
  UFG::TrueCrowdSet *v13; // r14
  signed int v14; // er11
  unsigned int v15; // esi
  UFG::TrueCrowdModel ***v16; // r10
  __int64 v17; // rbx
  unsigned int v18; // eax
  unsigned int v19; // er8
  UFG::TrueCrowdModel **v20; // rdx
  __int64 v21; // r9
  UFG::ResourceRequest *v22; // rcx
  signed int v23; // ecx
  signed int *v24; // rdx
  __int64 v25; // r8
  signed int v26; // [rsp+30h] [rbp+8h]

  v1 = this->mNumPreloadBuckets;
  v2 = 0;
  v3 = this;
  if ( v1 > 2 )
  {
    v4 = v1 - 2;
    v5 = this->mPreloadBuckets + 2;
    do
    {
      v6 = v5->size - 1;
      if ( (signed int)(v5->size - 1) >= 0 )
      {
        v7 = (signed __int64)&v5->p[v6];
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
  if ( v1 > 2 )
  {
    do
    {
      v9 = v8;
      v10 = v3->mPreloadBuckets[v8].size - 1;
      for ( i = v10; i >= 0; --i )
      {
        v12 = v3->mPreloadBuckets[v9].p[i];
        if ( v12->mPreloadActive )
        {
          v13 = v12->mInstance.mSet;
          v14 = 0xFFFFFF;
          v15 = UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition.mEntities[v13->mEntityIndex].mComponentCount;
          if ( v15 )
          {
            v16 = &v13->mFiles[0].p;
            v17 = v15;
            do
            {
              v18 = *((_DWORD *)v16 - 2);
              v19 = 0;
              if ( v18 )
              {
                v20 = *v16;
                v21 = v18;
                do
                {
                  v22 = (*v20)->mRequest;
                  if ( v22 && v22->mLoadStatus == 3 )
                    ++v19;
                  ++v20;
                  --v21;
                }
                while ( v21 );
              }
              if ( v14 > v19 )
                v14 = v19;
              v16 += 2;
              --v17;
            }
            while ( v17 );
          }
          v23 = 0xFFFFFF;
          if ( v15 )
          {
            v24 = (signed int *)v13->mFiles;
            v25 = UFG::TrueCrowdDataBase::sTrueCrowdDataBase->mDefinition.mEntities[v13->mEntityIndex].mComponentCount;
            do
            {
              if ( v23 > (unsigned int)*v24 )
                v23 = *v24;
              v24 += 4;
              --v25;
            }
            while ( v25 );
          }
          v12->mVarietyRatio = (float)(1.0 - (float)((float)v14 / (float)v23))
                             * (float)((float)(signed int)v12->mDesiredInstanceCount / (float)v2);
        }
        else
        {
          v12->mVarietyRatio = 0.0;
        }
      }
      v8 = v26 + 1;
      v26 = v8;
    }
    while ( v8 < v3->mNumPreloadBuckets );
  }
}

// File Line: 1494
// RVA: 0x4415D0
void __fastcall UFG::ResourcePool::ReleaseAllAmbientPreloads(UFG::ResourcePool *this)
{
  unsigned int v1; // ebp
  UFG::ResourcePool *i; // rbx
  signed __int64 v3; // r15
  int v4; // ecx
  __int64 v5; // rsi
  UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *v6; // r14
  UFG::PreloadRequest *v7; // rdi
  UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *v8; // rax

  v1 = 2;
  for ( i = this; v1 < i->mNumPreloadBuckets; i->mPreloadBuckets[v3].size = 0 )
  {
    v3 = v1;
    v4 = i->mPreloadBuckets[v1].size - 1;
    v5 = v4;
    if ( v4 >= 0 )
    {
      v6 = &i->mEmptyRequestList.mNode;
      do
      {
        v7 = i->mPreloadBuckets[v1].p[v5];
        UFG::ResourcePool::ReleaseResourceSetFiles(i, v7);
        --v5;
        v8 = v6->mPrev;
        v8->mNext = (UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *)&v7->mPrev;
        v7->mPrev = v8;
        v7->mNext = v6;
        v6->mPrev = (UFG::qNode<UFG::PreloadRequest,UFG::PreloadRequest> *)&v7->mPrev;
      }
      while ( v5 >= 0 );
    }
    ++v1;
  }
}

