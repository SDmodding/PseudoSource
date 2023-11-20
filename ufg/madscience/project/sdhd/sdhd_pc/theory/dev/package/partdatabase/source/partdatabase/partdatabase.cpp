// File Line: 29
// RVA: 0x154540
void __fastcall UFG::PartRequest::PartRequest(UFG::PartRequest *this)
{
  UFG::PartRequest *v1; // rdi
  UFG::qReflectHandle<UFG::PartDefinition> *v2; // rbx

  v1 = this;
  this->mPrev = (UFG::qNode<UFG::PartRequest,UFG::PartRequest> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::PartRequest,UFG::PartRequest> *)&this->mPrev;
  this->mModelDataStreamerHandle = 0i64;
  this->mTextureDataStreamerHandle = 0i64;
  this->mLoadCount = 0;
  v2 = &this->mPartDefHandle;
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&this->mPartDefHandle.mPrev);
  v2->mTypeUID = UFG::qStringHash64("UFG::PartDefinition", 0xFFFFFFFFFFFFFFFFui64);
  v1->mLoadStatus = 0;
  v1->mLastReferencedFrame = 0;
  v1->mInstances.p = 0i64;
  *(_QWORD *)&v1->mInstances.size = 0i64;
  UFG::qMemSet(v1->mPriorityRefCounts, 0, 0x14u);
}

// File Line: 65
// RVA: 0x158BA0
__int64 __fastcall UFG::PartRequest::GetHighestBucket(UFG::PartRequest *this)
{
  __int64 result; // rax
  unsigned int *v2; // rcx

  result = 0i64;
  v2 = this->mPriorityRefCounts;
  while ( !*v2 )
  {
    result = (unsigned int)(result + 1);
    ++v2;
    if ( (unsigned int)result >= 5 )
      return 0i64;
  }
  return result;
}

// File Line: 77
// RVA: 0x1599D0
void __fastcall UFG::PartRequest::OnLoaded(UFG::PartRequest *this)
{
  __int64 v1; // r10
  UFG::PartRequest *v2; // r9
  UFG::PartLoader *v3; // r8
  __int64 v4; // rax
  __int64 v5; // rdx
  signed __int64 v6; // rdx
  signed __int64 v7; // rcx

  v1 = 0i64;
  v2 = this;
  if ( this->mInstances.size )
  {
    do
    {
      v3 = v2->mInstances.p[v1];
      v4 = 0i64;
      v5 = v3->mPartRequestCount;
      if ( (_DWORD)v5 )
      {
        while ( v3->mPartRequests[v4] != v2 )
        {
          v4 = (unsigned int)(v4 + 1);
          if ( (unsigned int)v4 >= (unsigned int)v5 )
            goto LABEL_5;
        }
        v6 = 1i64 << (v4 & 0x3F);
        v7 = (signed __int64)(signed int)v4 >> 6;
        v3->mRequestsLoadedFlags.mBits[v7] |= v6;
        v3->mRequestsDispatchEventFlags.mBits[v7] |= v6;
      }
      else
      {
LABEL_5:
        v3->mPartRequests[v5] = v2;
        v3->mRequestsLoadedFlags.mBits[(signed __int64)(signed int)v3->mPartRequestCount >> 6] |= 1i64 << (v3->mPartRequestCount & 0x3F);
        v3->mRequestsDispatchEventFlags.mBits[(signed __int64)(signed int)v3->mPartRequestCount >> 6] |= 1i64 << (v3->mPartRequestCount & 0x3F);
        ++v3->mPartRequestCount;
      }
      v1 = (unsigned int)(v1 + 1);
      v3->mPartsDirty = 1;
    }
    while ( (unsigned int)v1 < v2->mInstances.size );
  }
}

// File Line: 87
// RVA: 0x1561F0
void __fastcall UFG::PartRequest::AddDependency(UFG::PartRequest *this, UFG::PartLoader *dependency)
{
  __int64 v2; // rbp
  UFG::PartLoader *v3; // r14
  unsigned int v4; // edx
  unsigned int v5; // ebx
  UFG::PartRequest *v6; // rsi
  unsigned int v7; // edx
  UFG::PartLoader **v8; // rax

  v2 = this->mInstances.size;
  v3 = dependency;
  v4 = this->mInstances.capacity;
  v5 = v2 + 1;
  v6 = this;
  if ( (signed int)v2 + 1 > v4 )
  {
    if ( v4 )
      v7 = 2 * v4;
    else
      v7 = 1;
    for ( ; v7 < v5; v7 *= 2 )
      ;
    if ( v7 <= 2 )
      v7 = 2;
    if ( v7 - v5 > 0x10000 )
      v7 = v2 + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
      (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mInstances,
      v7,
      "PartRequest::AddDependency");
  }
  v8 = v6->mInstances.p;
  v6->mInstances.size = v5;
  v8[v2] = v3;
  ++v6->mPriorityRefCounts[v3->mPriority];
  v6->mLastReferencedFrame = Illusion::gEngine.mFrameCount;
}

// File Line: 132
// RVA: 0x152FD0
void __fastcall UFG::PartPool::Bucket::Bucket(UFG::PartPool::Bucket *this)
{
  UFG::PartPool::Bucket *v1; // rbx
  unsigned __int64 v2; // rax
  char *v3; // rax
  char *v4; // rdi
  unsigned int i; // er9

  v1 = this;
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
    v4 = v3;
    if ( v1->mRequests.p )
    {
      for ( i = 0; i < v1->mRequests.size; ++i )
        *(_QWORD *)&v3[8 * i] = v1->mRequests.p[i];
      operator delete[](v1->mRequests.p);
    }
    v1->mRequests.p = (UFG::PartRequest **)v4;
    v1->mRequests.capacity = 16;
  }
  *(_QWORD *)&v1->mMemoryUsageModel = 0i64;
}

// File Line: 138
// RVA: 0x15B530
void __fastcall UFG::PartPool::Bucket::UpdateSize(UFG::PartPool::Bucket *this)
{
  UFG::PartPool::Bucket *v1; // rbx
  __int64 v2; // rdi
  __int64 v3; // rsi
  UFG::PartRequest *v4; // rbp
  UFG::PartDefinition *v5; // rdi
  unsigned int v6; // eax
  UFG::qReflectObject *v7; // rdi
  int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // edx
  unsigned int v11; // er8
  UFG::PartPool::Bucket **v12; // rcx
  __int64 v13; // r9
  UFG::qString v14; // [rsp+28h] [rbp-80h]
  UFG::qString v15; // [rsp+50h] [rbp-58h]
  UFG::qString result; // [rsp+78h] [rbp-30h]

  v1 = this;
  *(_QWORD *)&this->mMemoryUsageModel = 0i64;
  v2 = 0i64;
  if ( this->mChildren.size )
  {
    do
    {
      UFG::PartPool::Bucket::UpdateSize(v1->mChildren.p[v2]);
      v2 = (unsigned int)(v2 + 1);
    }
    while ( (unsigned int)v2 < v1->mChildren.size );
  }
  v3 = 0i64;
  if ( v1->mRequests.size )
  {
    do
    {
      v4 = v1->mRequests.p[v3];
      v5 = (UFG::PartDefinition *)v4->mPartDefHandle.mData;
      if ( v5 )
      {
        if ( !v5->mModelSize )
        {
          UFG::PartDefinition::GetModelFileName((UFG::PartDefinition *)v4->mPartDefHandle.mData, &result);
          v5->mModelSize = PartDatabase_QueryFileSize(result.mData);
          UFG::PartDefinition::GetTextureFileName(v5, &v15);
          v5->mModelSize += PartDatabase_QueryFileSize(v15.mData);
          UFG::qString::~qString(&v15);
          UFG::qString::~qString(&result);
        }
        v6 = v5->mModelSize;
      }
      else
      {
        v6 = 0;
      }
      v1->mMemoryUsageModel += v6;
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
        v8 = HIDWORD(v7[2].mTypeUID);
      }
      else
      {
        v8 = 0;
      }
      v1->mMemoryUsageTexture += v8;
      v3 = (unsigned int)(v3 + 1);
    }
    while ( (unsigned int)v3 < v1->mRequests.size );
  }
  v9 = v1->mChildren.size;
  if ( v9 )
  {
    v10 = v1->mMemoryUsageModel;
    v11 = v1->mMemoryUsageTexture;
    v12 = v1->mChildren.p;
    v13 = v9;
    do
    {
      v10 += (*v12)->mMemoryUsageModel;
      v1->mMemoryUsageModel = v10;
      v11 += (*v12)->mMemoryUsageTexture;
      v1->mMemoryUsageTexture = v11;
      ++v12;
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
  UFG::PartPool::Bucket *v4; // rsi

  v2 = 0i64;
  v3 = priority;
  v4 = this;
  this->mPriority = priority;
  if ( this->mChildren.size )
  {
    do
    {
      v3 += v2 + 1;
      UFG::PartPool::Bucket::UpdatePriority(v4->mChildren.p[v2], v3);
      v2 = (unsigned int)(v2 + 1);
    }
    while ( (unsigned int)v2 < v4->mChildren.size );
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
  UFG::PartPool *v1; // rbx
  unsigned int v2; // edi
  unsigned __int64 v3; // rax
  char *v4; // rsi
  unsigned int i; // er8
  unsigned __int64 v6; // rax
  char *v7; // rsi
  unsigned int j; // er8
  unsigned __int64 v9; // rax
  char *v10; // rax
  char *v11; // rsi
  UFG::qList<UFG::PartRequest,UFG::PartRequest,1,0> *v12; // [rsp+58h] [rbp+10h]

  v1 = this;
  v2 = 0;
  this->mQueued.p = 0i64;
  *(_QWORD *)&this->mQueued.size = 0i64;
  this->mLoading.p = 0i64;
  *(_QWORD *)&this->mLoading.size = 0i64;
  this->mLoaded.p = 0i64;
  *(_QWORD *)&this->mLoaded.size = 0i64;
  v12 = &this->mRequestList;
  v12->mNode.mPrev = &v12->mNode;
  v12->mNode.mNext = &v12->mNode;
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
    if ( v1->mQueued.p )
    {
      for ( i = 0; i < v1->mQueued.size; ++i )
        *(_QWORD *)&v4[8 * i] = v1->mQueued.p[i];
      operator delete[](v1->mQueued.p);
    }
    v1->mQueued.p = (UFG::PartRequest **)v4;
    v1->mQueued.capacity = 32;
  }
  if ( v1->mLoading.capacity < 0x20 && v1->mLoading.size != 32 )
  {
    v6 = 256i64;
    if ( !is_mul_ok(0x20ui64, 8ui64) )
      v6 = -1i64;
    v7 = UFG::qMalloc(v6, "PartPool", 0i64);
    if ( v1->mLoading.p )
    {
      for ( j = 0; j < v1->mLoading.size; ++j )
        *(_QWORD *)&v7[8 * j] = v1->mLoading.p[j];
      operator delete[](v1->mLoading.p);
    }
    v1->mLoading.p = (UFG::PartRequest **)v7;
    v1->mLoading.capacity = 32;
  }
  if ( v1->mLoaded.capacity < 0x20 && v1->mLoaded.size != 32 )
  {
    v9 = 256i64;
    if ( !is_mul_ok(0x20ui64, 8ui64) )
      v9 = -1i64;
    v10 = UFG::qMalloc(v9, "PartPool", 0i64);
    v11 = v10;
    if ( v1->mLoaded.p )
    {
      if ( v1->mLoaded.size )
      {
        do
        {
          *(_QWORD *)&v10[8 * v2] = v1->mLoaded.p[v2];
          ++v2;
        }
        while ( v2 < v1->mLoaded.size );
      }
      operator delete[](v1->mLoaded.p);
    }
    v1->mLoaded.p = (UFG::PartRequest **)v11;
    v1->mLoaded.capacity = 32;
  }
  UFG::PartPool::InitBuckets(v1);
}

// File Line: 204
// RVA: 0x155370
void __fastcall UFG::PartPool::~PartPool(UFG::PartPool *this)
{
  UFG::qList<UFG::PartRequest,UFG::PartRequest,1,0> *v1; // rdi
  UFG::PartPool::Bucket *v2; // rbx
  UFG::PartPool::Bucket **v3; // rcx
  UFG::PartRequest **v4; // rcx
  UFG::qNode<UFG::PartRequest,UFG::PartRequest> *v5; // rbx
  UFG::qNode<UFG::PartRequest,UFG::PartRequest> *v6; // rcx
  UFG::qNode<UFG::PartRequest,UFG::PartRequest> *v7; // rcx
  UFG::qNode<UFG::PartRequest,UFG::PartRequest> *v8; // rbx
  UFG::qNode<UFG::PartRequest,UFG::PartRequest> *v9; // rcx
  UFG::qNode<UFG::PartRequest,UFG::PartRequest> *v10; // rcx
  UFG::qNode<UFG::PartRequest,UFG::PartRequest> *v11; // rbx
  UFG::qNode<UFG::PartRequest,UFG::PartRequest> *v12; // rcx
  UFG::qNode<UFG::PartRequest,UFG::PartRequest> *v13; // rcx
  UFG::qNode<UFG::PartRequest,UFG::PartRequest> *v14; // rbx
  UFG::qNode<UFG::PartRequest,UFG::PartRequest> *v15; // rcx
  UFG::qNode<UFG::PartRequest,UFG::PartRequest> *v16; // rcx
  UFG::qNode<UFG::PartRequest,UFG::PartRequest> *v17; // rcx
  UFG::qNode<UFG::PartRequest,UFG::PartRequest> *v18; // rax
  UFG::qNode<UFG::PartRequest,UFG::PartRequest> *v19; // rcx
  UFG::qNode<UFG::PartRequest,UFG::PartRequest> *v20; // rcx
  UFG::qNode<UFG::PartRequest,UFG::PartRequest> *v21; // rcx

  v1 = (UFG::qList<UFG::PartRequest,UFG::PartRequest,1,0> *)this;
  v2 = this->mMasterBucket;
  if ( v2 )
  {
    v3 = v2->mChildren.p;
    if ( v3 )
      operator delete[](v3);
    v2->mChildren.p = 0i64;
    *(_QWORD *)&v2->mChildren.size = 0i64;
    v4 = v2->mRequests.p;
    if ( v4 )
      operator delete[](v4);
    v2->mRequests.p = 0i64;
    *(_QWORD *)&v2->mRequests.size = 0i64;
    operator delete[](v2);
  }
  v5 = v1[4].mNode.mPrev;
  if ( v5 )
  {
    v6 = v5[3].mPrev;
    if ( v6 )
      operator delete[](v6);
    v5[3].mPrev = 0i64;
    v5[2].mNext = 0i64;
    v7 = v5[1].mNext;
    if ( v7 )
      operator delete[](v7);
    v5[1].mNext = 0i64;
    v5[1].mPrev = 0i64;
    operator delete[](v5);
  }
  v8 = v1[4].mNode.mNext;
  if ( v8 )
  {
    v9 = v8[3].mPrev;
    if ( v9 )
      operator delete[](v9);
    v8[3].mPrev = 0i64;
    v8[2].mNext = 0i64;
    v10 = v8[1].mNext;
    if ( v10 )
      operator delete[](v10);
    v8[1].mNext = 0i64;
    v8[1].mPrev = 0i64;
    operator delete[](v8);
  }
  v11 = v1[5].mNode.mPrev;
  if ( v11 )
  {
    v12 = v11[3].mPrev;
    if ( v12 )
      operator delete[](v12);
    v11[3].mPrev = 0i64;
    v11[2].mNext = 0i64;
    v13 = v11[1].mNext;
    if ( v13 )
      operator delete[](v13);
    v11[1].mNext = 0i64;
    v11[1].mPrev = 0i64;
    operator delete[](v11);
  }
  v14 = v1[5].mNode.mNext;
  if ( v14 )
  {
    v15 = v14[3].mPrev;
    if ( v15 )
      operator delete[](v15);
    v14[3].mPrev = 0i64;
    v14[2].mNext = 0i64;
    v16 = v14[1].mNext;
    if ( v16 )
      operator delete[](v16);
    v14[1].mNext = 0i64;
    v14[1].mPrev = 0i64;
    operator delete[](v14);
  }
  UFG::qList<UFG::PartRequest,UFG::PartRequest,1,0>::DeleteNodes(v1 + 6);
  v17 = v1[6].mNode.mPrev;
  v18 = v1[6].mNode.mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  v1[6].mNode.mPrev = &v1[6].mNode;
  v1[6].mNode.mNext = &v1[6].mNode;
  v19 = v1[2].mNode.mNext;
  if ( v19 )
    operator delete[](v19);
  v1[2].mNode.mNext = 0i64;
  v1[2].mNode.mPrev = 0i64;
  v20 = v1[1].mNode.mNext;
  if ( v20 )
    operator delete[](v20);
  v1[1].mNode.mNext = 0i64;
  v1[1].mNode.mPrev = 0i64;
  v21 = v1->mNode.mNext;
  if ( v21 )
    operator delete[](v21);
  v1->mNode.mNext = 0i64;
  v1->mNode.mPrev = 0i64;
}

// File Line: 223
// RVA: 0x158DB0
__int64 __fastcall UFG::PartPool::GetQueuedBytes(UFG::PartPool *this)
{
  UFG::PartPool *v1; // rdi
  unsigned int v2; // ebx
  __int64 v3; // rbp
  UFG::PartDefinition *v4; // rcx
  int v5; // eax
  int v6; // ebx
  UFG::PartRequest *v7; // rcx
  UFG::qReflectObject *v8; // rsi
  int v9; // eax
  __int64 v10; // rbp
  UFG::PartRequest *v11; // rcx
  UFG::PartDefinition *v12; // rsi
  unsigned int v13; // eax
  int v14; // ebx
  UFG::PartRequest *v15; // rcx
  UFG::qReflectObject *v16; // rsi
  int v17; // eax
  UFG::qString result; // [rsp+20h] [rbp-88h]
  __int64 v20; // [rsp+48h] [rbp-60h]
  UFG::qString v21; // [rsp+50h] [rbp-58h]
  UFG::qString v22; // [rsp+78h] [rbp-30h]

  v20 = -2i64;
  v1 = this;
  v2 = 0;
  v3 = 0i64;
  if ( this->mQueued.size )
  {
    do
    {
      v4 = (UFG::PartDefinition *)v1->mQueued.p[v3]->mPartDefHandle.mData;
      if ( v4 )
        v5 = UFG::PartDefinition::GetModelSize(v4);
      else
        v5 = 0;
      v6 = v5 + v2;
      v7 = v1->mQueued.p[v3];
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
        v9 = HIDWORD(v8[2].mTypeUID);
      }
      else
      {
        v9 = 0;
      }
      v2 = v9 + v6;
      v3 = (unsigned int)(v3 + 1);
    }
    while ( (unsigned int)v3 < v1->mQueued.size );
  }
  v10 = 0i64;
  if ( v1->mLoading.size )
  {
    do
    {
      v11 = v1->mLoading.p[v10];
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
        v13 = v12->mModelSize;
      }
      else
      {
        v13 = 0;
      }
      v14 = v13 + v2;
      v15 = v1->mLoading.p[v10];
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
      v10 = (unsigned int)(v10 + 1);
    }
    while ( (unsigned int)v10 < v1->mLoading.size );
  }
  return v2;
}

// File Line: 240
// RVA: 0x15A6B0
UFG::qNode<UFG::PartRequest,UFG::PartRequest> *__fastcall UFG::PartPool::RequestLoadPart(UFG::PartPool *this, UFG::PartDefinition *part, UFG::PartLoader *user)
{
  UFG::PartLoader *v3; // rbp
  UFG::PartDefinition *v4; // r14
  UFG::PartPool *v5; // rsi
  UFG::qNode<UFG::PartRequest,UFG::PartRequest> *v6; // rbx
  UFG::qList<UFG::PartRequest,UFG::PartRequest,1,0> *v7; // rdi
  char *v8; // rax
  UFG::qNode<UFG::PartRequest,UFG::PartRequest> *v9; // rax
  UFG::qNode<UFG::PartRequest,UFG::PartRequest> *v10; // rax
  UFG::qPropertySet *item; // [rsp+50h] [rbp+8h]

  v3 = user;
  v4 = part;
  v5 = this;
  v6 = this->mRequestList.mNode.mNext;
  v7 = &this->mRequestList;
  if ( v6 != (UFG::qNode<UFG::PartRequest,UFG::PartRequest> *)&this->mRequestList )
  {
    while ( v6[4].mPrev != (UFG::qNode<UFG::PartRequest,UFG::PartRequest> *)part->mBaseNode.mUID )
    {
      v6 = v6->mNext;
      if ( v6 == (UFG::qNode<UFG::PartRequest,UFG::PartRequest> *)v7 )
        goto LABEL_6;
    }
    UFG::PartRequest::AddDependency((UFG::PartRequest *)v6, user);
    goto LABEL_11;
  }
LABEL_6:
  v8 = UFG::qMalloc(0x80ui64, "PartRequest", 0i64);
  item = (UFG::qPropertySet *)v8;
  if ( v8 )
  {
    UFG::PartRequest::PartRequest((UFG::PartRequest *)v8);
    v6 = v9;
  }
  else
  {
    v6 = 0i64;
  }
  UFG::qReflectHandleBase::Init(
    (UFG::qReflectHandleBase *)&v6[2].mNext,
    (unsigned __int64)v6[3].mNext,
    v4->mBaseNode.mUID);
  UFG::PartRequest::AddDependency((UFG::PartRequest *)v6, v3);
  v10 = v7->mNode.mPrev;
  v10->mNext = v6;
  v6->mPrev = v10;
  v6->mNext = &v7->mNode;
  v7->mNode.mPrev = v6;
  item = (UFG::qPropertySet *)v6;
  if ( LODWORD(v6[5].mPrev) != 1 )
  {
    UFG::qArray<UFG::PedSpawningInfo *,0>::Add((UFG::qArray<UFG::qPropertySet *,0> *)v5, &item, "qArray.Add");
    LODWORD(v6[5].mPrev) = 1;
LABEL_11:
    v5->mDirty = 1;
  }
  return v6;
}

// File Line: 262
// RVA: 0x15A7B0
void __fastcall UFG::PartPool::RequestUnLoadPart(UFG::PartPool *this, UFG::PartDefinition *part, UFG::PartLoader *user)
{
  UFG::PartPool *v3; // rax
  UFG::PartPool *v4; // r9
  UFG::PartLoader *v5; // r11
  UFG::PartPool *v6; // rbx
  unsigned __int64 v7; // rdx
  unsigned int v8; // edx
  __int64 v9; // rcx
  __int64 v10; // r8
  unsigned int v11; // eax

  v3 = (UFG::PartPool *)this->mRequestList.mNode.mNext;
  v4 = 0i64;
  v5 = user;
  v6 = this;
  if ( v3 != (UFG::PartPool *)&this->mRequestList )
  {
    v7 = part->mBaseNode.mUID;
    while ( v3->mReservedBucket != (UFG::PartPool::Bucket *)v7 )
    {
      v3 = (UFG::PartPool *)v3->mQueued.p;
      if ( v3 == (UFG::PartPool *)&this->mRequestList )
        goto LABEL_7;
    }
    v4 = v3;
  }
LABEL_7:
  v8 = v4->mMaxModelMemory;
  v9 = 0i64;
  if ( v8 )
  {
    v10 = *(_QWORD *)&v4->mExternalUsedModelMemory;
    while ( v5 != *(UFG::PartLoader **)(v10 + 8 * v9) )
    {
      v9 = (unsigned int)(v9 + 1);
      if ( (unsigned int)v9 >= v8 )
        goto LABEL_16;
    }
    if ( (signed int)v9 >= 0 )
    {
      *(_QWORD *)(v10 + 8 * v9) = *(_QWORD *)(v10 + 8i64 * (v8 - 1));
      v11 = v4->mMaxModelMemory;
      if ( v11 > 1 )
        v4->mMaxModelMemory = v11 - 1;
      else
        v4->mMaxModelMemory = 0;
    }
  }
LABEL_16:
  --*((_DWORD *)&v4->mHighBucket + v5->mPriority + 1);
  LODWORD(v4->mRequestList.mNode.mNext) = Illusion::gEngine.mFrameCount;
  v6->mDirty = 1;
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
  UFG::PartRequest *v2; // rsi
  UFG::PartRequest *v3; // rdi
  unsigned int v4; // er8
  unsigned int *v5; // rax
  unsigned int v6; // er9
  UFG::PartDefinition *v7; // rcx
  int v8; // er15
  UFG::PartDefinition *v9; // rdi
  unsigned int v10; // er14
  UFG::PartDefinition *v11; // rcx
  int v12; // ebp
  UFG::qReflectObject *v13; // rdi
  int v14; // eax
  UFG::qString result; // [rsp+28h] [rbp-70h]
  UFG::qString v17; // [rsp+50h] [rbp-48h]

  v2 = reqB;
  v3 = reqA;
  v4 = 0;
  v5 = reqB->mPriorityRefCounts;
  do
  {
    v6 = *(unsigned int *)((char *)v5 + (char *)reqA - (char *)reqB);
    if ( v6 != *v5 )
      return v6 > *v5;
    ++v4;
    ++v5;
  }
  while ( v4 < 5 );
  v7 = (UFG::PartDefinition *)reqA->mPartDefHandle.mData;
  if ( v7 )
    v8 = UFG::PartDefinition::GetModelSize(v7);
  else
    v8 = 0;
  v9 = (UFG::PartDefinition *)v3->mPartDefHandle.mData;
  if ( v9 )
  {
    if ( !v9->mTextureSize )
    {
      UFG::PartDefinition::GetTextureFileName(v9, &result);
      UFG::qString::ReplaceString(&result, ".perm.bin", ".temp.bin", 0);
      v9->mTextureSize = PartDatabase_QueryFileSize(result.mData);
      UFG::qString::~qString(&result);
    }
    v10 = v9->mTextureSize;
  }
  else
  {
    v10 = 0;
  }
  v11 = (UFG::PartDefinition *)v2->mPartDefHandle.mData;
  if ( v11 )
    v12 = UFG::PartDefinition::GetModelSize(v11);
  else
    v12 = 0;
  v13 = v2->mPartDefHandle.mData;
  if ( v13 )
  {
    if ( !HIDWORD(v13[2].mTypeUID) )
    {
      UFG::PartDefinition::GetTextureFileName((UFG::PartDefinition *)v2->mPartDefHandle.mData, &v17);
      UFG::qString::ReplaceString(&v17, ".perm.bin", ".temp.bin", 0);
      HIDWORD(v13[2].mTypeUID) = PartDatabase_QueryFileSize(v17.mData);
      UFG::qString::~qString(&v17);
    }
    v14 = HIDWORD(v13[2].mTypeUID);
  }
  else
  {
    v14 = 0;
  }
  return v10 + v8 < v14 + v12;
}

// File Line: 289
// RVA: 0x15B460
void __fastcall UFG::PartPool::UpdateRequests(UFG::PartPool *this)
{
  UFG::PartPool *v1; // rbx
  unsigned int v2; // eax
  bool v3; // al
  __int64 v4; // rsi
  UFG::PartRequest **v5; // rdi
  Render::IrradianceVolume *right; // [rsp+18h] [rbp-1010h]
  char dest; // [rsp+20h] [rbp-1008h]

  v1 = this;
  if ( this->mDirty )
    UFG::PartPool::UpdateBuckets(this);
  v2 = v1->mLoading.size;
  v1->mStreamerStalled = 0;
  if ( v1->mQueued.size + v2 )
  {
    v3 = PartDatabase_IsStreamingStalled();
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
          v5 = (UFG::PartRequest **)&dest;
          do
          {
            UFG::PartPool::QueueRequest(v1, *v5);
            ++v5;
            --v4;
          }
          while ( v4 );
          UFG::PartPool::Bucket::UpdateSize(v1->mMasterBucket);
        }
      }
    }
  }
}

// File Line: 328
// RVA: 0x15A260
void __fastcall UFG::PartPool::ReloadRequests(UFG::PartPool *this)
{
  UFG::PartRequest *v1; // rbx
  UFG::PartRequest *v2; // rdi
  UFG::PartPool *v3; // rsi
  UFG::PartRequest *i; // rbx

  v1 = (UFG::PartRequest *)this->mRequestList.mNode.mNext;
  v2 = (UFG::PartRequest *)&this->mRequestList;
  v3 = this;
  if ( v1 != (UFG::PartRequest *)&this->mRequestList )
  {
    do
    {
      PartDatabase_ReleaseStream(v1);
      v1 = (UFG::PartRequest *)v1->mNext;
    }
    while ( v1 != v2 );
  }
  for ( i = (UFG::PartRequest *)v3->mRequestList.mNode.mNext; i != v2; i = (UFG::PartRequest *)i->mNext )
    PartDatabase_QueueStream(i);
}

// File Line: 341
// RVA: 0x158800
void __fastcall UFG::PartPool::FlushParts(UFG::PartPool *this, bool forceFlush)
{
  UFG::PartPool *v2; // rdi
  float v3; // xmm1_4
  unsigned int v4; // ebx
  unsigned int v5; // esi
  UFG::PartPool::Bucket *v6; // rax
  unsigned int v7; // er14
  unsigned int v8; // er15
  UFG::PartPool::Bucket *v9; // rcx
  __int64 v10; // rax
  unsigned int v11; // er13
  unsigned int v12; // ebp
  __int64 v13; // r12
  UFG::PartRequest *v14; // rbx
  UFG::PartDefinition *v15; // rcx
  int v16; // eax
  UFG::qReflectObject *v17; // rsi
  int v18; // eax
  __int64 v19; // rcx
  unsigned int v20; // edx
  UFG::PartRequest **v21; // r8
  __int64 v22; // rcx
  unsigned int v23; // edx
  UFG::PartRequest **v24; // r8
  unsigned int v25; // eax
  __int64 v26; // rcx
  unsigned int v27; // edx
  UFG::PartRequest **v28; // r8
  unsigned int v29; // eax
  UFG::qNode<UFG::PartRequest,UFG::PartRequest> *v30; // rcx
  UFG::qNode<UFG::PartRequest,UFG::PartRequest> *v31; // rax
  UFG::PartLoader **v32; // rcx
  UFG::qNode<UFG::PartRequest,UFG::PartRequest> *v33; // rdx
  UFG::qNode<UFG::PartRequest,UFG::PartRequest> *v34; // rax
  UFG::qString result; // [rsp+30h] [rbp-78h]
  unsigned int v36; // [rsp+B0h] [rbp+8h]
  bool v37; // [rsp+B8h] [rbp+10h]
  unsigned int v38; // [rsp+C0h] [rbp+18h]

  v37 = forceFlush;
  v2 = this;
  v3 = this->mFragmentationReservePercentage;
  v4 = this->mMaxModelMemory - (signed int)(float)((float)(signed int)this->mMaxModelMemory * v3);
  v36 = this->mMaxModelMemory - (signed int)(float)((float)(signed int)this->mMaxModelMemory * v3);
  v5 = this->mMaxTextureMemory - (signed int)(float)((float)(signed int)this->mMaxTextureMemory * v3);
  v38 = this->mMaxTextureMemory - (signed int)(float)((float)(signed int)this->mMaxTextureMemory * v3);
  v6 = this->mMasterBucket;
  v7 = this->mExternalUsedModelMemory + v6->mMemoryUsageModel;
  v8 = this->mExternalUsedTextureMemory + v6->mMemoryUsageTexture;
  if ( forceFlush || this->mStreamerStalled || v7 > v4 || v8 > v5 )
  {
    if ( this->mDirty )
      UFG::PartPool::UpdateBuckets(this);
    v9 = v2->mUnReferencedBucket;
    v10 = (signed int)v9->mRequests.size;
    if ( (_DWORD)v10 )
      UFG::qQuickSortImpl<Render::Light *,bool (*)(Render::Light const *,Render::Light const *)>(
        (Render::IrradianceVolume **)v9->mRequests.p,
        (Render::IrradianceVolume **)&v9->mRequests.p[v10 - 1],
        (bool (__fastcall *)(Render::IrradianceVolume *, Render::IrradianceVolume *))UFG::SortByReferenceFramePredicate);
    v11 = v2->mUnReferencedBucket->mRequests.size;
    v12 = 0;
    if ( v11 )
    {
      v13 = 0i64;
      do
      {
        if ( !v37 && !v2->mStreamerStalled && v7 <= v4 && v8 <= v5 )
          break;
        v14 = v2->mUnReferencedBucket->mRequests.p[v13];
        v15 = (UFG::PartDefinition *)v14->mPartDefHandle.mData;
        if ( v15 )
          v16 = UFG::PartDefinition::GetModelSize(v15);
        else
          v16 = 0;
        v7 -= v16;
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
          v18 = HIDWORD(v17[2].mTypeUID);
          LODWORD(v17) = 0;
        }
        else
        {
          v18 = 0;
        }
        v8 -= v18;
        v19 = (unsigned int)v17;
        v20 = v2->mQueued.size;
        if ( v2->mQueued.size )
        {
          v21 = v2->mQueued.p;
          while ( v14 != v21[v19] )
          {
            v19 = (unsigned int)(v19 + 1);
            if ( (unsigned int)v19 >= v20 )
              goto LABEL_32;
          }
          if ( (signed int)v19 >= 0 )
          {
            v21[v19] = v21[v20 - 1];
            if ( v2->mQueued.size > 1 )
              --v2->mQueued.size;
            else
              v2->mQueued.size = (unsigned int)v17;
          }
        }
LABEL_32:
        v22 = (unsigned int)v17;
        v23 = v2->mLoading.size;
        if ( v23 )
        {
          v24 = v2->mLoading.p;
          while ( v14 != v24[v22] )
          {
            v22 = (unsigned int)(v22 + 1);
            if ( (unsigned int)v22 >= v23 )
              goto LABEL_41;
          }
          if ( (signed int)v22 >= 0 )
          {
            v24[v22] = v24[v23 - 1];
            v25 = v2->mLoading.size;
            if ( v25 > 1 )
              v2->mLoading.size = v25 - 1;
            else
              v2->mLoading.size = (unsigned int)v17;
          }
        }
LABEL_41:
        v26 = (unsigned int)v17;
        v27 = v2->mLoaded.size;
        if ( v27 )
        {
          v28 = v2->mLoaded.p;
          while ( v14 != v28[v26] )
          {
            v26 = (unsigned int)(v26 + 1);
            if ( (unsigned int)v26 >= v27 )
              goto LABEL_50;
          }
          if ( (signed int)v26 >= 0 )
          {
            v28[v26] = v28[v27 - 1];
            v29 = v2->mLoaded.size;
            if ( v29 > 1 )
              v2->mLoaded.size = v29 - 1;
            else
              v2->mLoaded.size = (unsigned int)v17;
          }
        }
LABEL_50:
        PartDatabase_ReleaseStream(v14);
        v30 = v14->mPrev;
        v31 = v14->mNext;
        v30->mNext = v31;
        v31->mPrev = v30;
        v14->mPrev = (UFG::qNode<UFG::PartRequest,UFG::PartRequest> *)&v14->mPrev;
        v14->mNext = (UFG::qNode<UFG::PartRequest,UFG::PartRequest> *)&v14->mPrev;
        v32 = v14->mInstances.p;
        if ( v32 )
          operator delete[](v32);
        v14->mInstances.p = 0i64;
        *(_QWORD *)&v14->mInstances.size = 0i64;
        UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&v14->mPartDefHandle.mPrev);
        v33 = v14->mPrev;
        v34 = v14->mNext;
        v33->mNext = v34;
        v34->mPrev = v33;
        v14->mPrev = (UFG::qNode<UFG::PartRequest,UFG::PartRequest> *)&v14->mPrev;
        v14->mNext = (UFG::qNode<UFG::PartRequest,UFG::PartRequest> *)&v14->mPrev;
        operator delete[](v14);
        v2->mDirty = 1;
        if ( v2->mStreamerStalled )
        {
          if ( v12 >= 1 )
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
  UFG::PartPool *v1; // rsi
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
  UFG::PartPool::Bucket *v15; // rsi
  unsigned int i; // ebx

  v1 = this;
  v2 = UFG::qMalloc(0x38ui64, "Bucket", 0i64);
  v3 = 0;
  if ( v2 )
    UFG::PartPool::Bucket::Bucket((UFG::PartPool::Bucket *)v2);
  else
    v4 = 0i64;
  v1->mMasterBucket = v4;
  v5 = UFG::qMalloc(0x38ui64, "Bucket", 0i64);
  if ( v5 )
    UFG::PartPool::Bucket::Bucket((UFG::PartPool::Bucket *)v5);
  else
    v6 = 0i64;
  v1->mReservedBucket = v6;
  UFG::PartPool::Bucket::AddChild(v1->mMasterBucket, v6);
  v7 = UFG::qMalloc(0x38ui64, "Bucket", 0i64);
  if ( v7 )
    UFG::PartPool::Bucket::Bucket((UFG::PartPool::Bucket *)v7);
  else
    v8 = 0i64;
  v1->mUnReferencedBucket = v8;
  UFG::PartPool::Bucket::AddChild(v1->mMasterBucket, v8);
  v9 = UFG::qMalloc(0x38ui64, "Bucket", 0i64);
  if ( v9 )
    UFG::PartPool::Bucket::Bucket((UFG::PartPool::Bucket *)v9);
  else
    v10 = 0i64;
  v1->mCriticalBucket = v10;
  UFG::PartPool::Bucket::AddChild(v1->mMasterBucket, v10);
  v11 = UFG::qMalloc(0x38ui64, "Bucket", 0i64);
  if ( v11 )
    UFG::PartPool::Bucket::Bucket((UFG::PartPool::Bucket *)v11);
  else
    v12 = 0i64;
  v1->mHighBucket = v12;
  UFG::PartPool::Bucket::AddChild(v1->mMasterBucket, v12);
  v13 = UFG::qMalloc(0x38ui64, "Bucket", 0i64);
  if ( v13 )
    UFG::PartPool::Bucket::Bucket((UFG::PartPool::Bucket *)v13);
  else
    v14 = 0i64;
  v1->mLowBucket = v14;
  UFG::PartPool::Bucket::AddChild(v1->mMasterBucket, v14);
  UFG::PartPool::Bucket::UpdateSize(v1->mMasterBucket);
  v15 = v1->mMasterBucket;
  v15->mPriority = 0;
  for ( i = 0; i < v15->mChildren.size; ++i )
  {
    v3 += i + 1;
    UFG::PartPool::Bucket::UpdatePriority(v15->mChildren.p[i], v3);
  }
}

// File Line: 487
// RVA: 0x159FD0
void __fastcall UFG::PartPool::QueueRequest(UFG::PartPool *this, UFG::PartRequest *pRequest)
{
  bool v2; // zf
  UFG::PartRequest *v3; // rbx
  UFG::PartPool *v4; // rdi
  unsigned int v5; // edx
  __int64 v6; // rax
  UFG::PartRequest **v7; // r8
  UFG::qPropertySet *item; // [rsp+38h] [rbp+10h]

  v2 = pRequest->mLoadStatus == 2;
  v3 = pRequest;
  v4 = this;
  item = (UFG::qPropertySet *)pRequest;
  if ( !v2 )
  {
    v5 = this->mQueued.size;
    v6 = 0i64;
    if ( this->mQueued.size )
    {
      v7 = this->mQueued.p;
      while ( v3 != v7[v6] )
      {
        v6 = (unsigned int)(v6 + 1);
        if ( (unsigned int)v6 >= v5 )
          goto LABEL_11;
      }
      if ( (signed int)v6 >= 0 )
      {
        v7[(unsigned int)v6] = v7[v5 - 1];
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
    v3->mLoadStatus = 2;
    v4->mDirty = 1;
  }
  PartDatabase_QueueStream(v3);
}

// File Line: 494
// RVA: 0x159AD0
void __fastcall UFG::PartPool::PartLoadNotification(UFG::PartPool *this, UFG::PartRequest *pRequest)
{
  bool v2; // zf
  UFG::PartRequest *v3; // rdi
  UFG::PartPool *v4; // rbx
  unsigned int v5; // edx
  __int64 v6; // rax
  UFG::PartRequest **v7; // r8
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

// File Line: 499
// RVA: 0x15B220
void __fastcall UFG::PartPool::UpdateBuckets(UFG::PartPool *this)
{
  UFG::PartPool *v1; // r13
  UFG::PartPool *v2; // r15
  UFG::qList<UFG::PartRequest,UFG::PartRequest,1,0> *v3; // r13
  UFG::PartRequest **v4; // r12
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
  __int64 v16; // r9
  signed __int64 v17; // r8
  __int64 v18; // rax
  UFG::PartPool::Bucket *v19; // [rsp+20h] [rbp-68h]
  UFG::PartPool::Bucket *v20; // [rsp+28h] [rbp-60h]
  UFG::PartPool::Bucket *v21; // [rsp+30h] [rbp-58h]
  UFG::PartPool::Bucket *v22; // [rsp+38h] [rbp-50h]
  UFG::PartPool::Bucket *v23; // [rsp+40h] [rbp-48h]
  UFG::PartPool *v24; // [rsp+90h] [rbp+8h]

  v24 = this;
  v1 = this;
  this->mUnReferencedBucket->mRequests.size = 0;
  this->mReservedBucket->mRequests.size = 0;
  this->mCriticalBucket->mRequests.size = 0;
  this->mHighBucket->mRequests.size = 0;
  this->mLowBucket->mRequests.size = 0;
  v2 = (UFG::PartPool *)this->mRequestList.mNode.mNext;
  v19 = this->mUnReferencedBucket;
  v20 = this->mReservedBucket;
  v21 = this->mCriticalBucket;
  v22 = this->mHighBucket;
  v23 = this->mLowBucket;
  if ( v2 != (UFG::PartPool *)&this->mRequestList )
  {
    v3 = &this->mRequestList;
    do
    {
      v4 = v2->mQueued.p;
      v5 = 0;
      v6 = (_DWORD *)((char *)&v2->mHighBucket + 4);
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
      v9 = *(unsigned int *)(v8 + 16);
      v10 = *(_DWORD *)(v8 + 20);
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
          if ( *(_QWORD *)(v8 + 24) )
          {
            v16 = 0i64;
            if ( *(_DWORD *)(v8 + 16) )
            {
              do
              {
                v17 = 8 * v16;
                v16 = (unsigned int)(v16 + 1);
                *(_QWORD *)&v14[v17] = *(_QWORD *)(v17 + *(_QWORD *)(v8 + 24));
              }
              while ( (unsigned int)v16 < *(_DWORD *)(v8 + 16) );
            }
            operator delete[](*(void **)(v8 + 24));
          }
          *(_QWORD *)(v8 + 24) = v15;
          *(_DWORD *)(v8 + 20) = v12;
        }
      }
      v18 = *(_QWORD *)(v8 + 24);
      *(_DWORD *)(v8 + 16) = v11;
      *(_QWORD *)(v18 + 8 * v9) = v2;
      v2 = (UFG::PartPool *)v4;
    }
    while ( v4 != (UFG::PartRequest **)v3 );
    v1 = v24;
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
unsigned int __fastcall UFG::PartDatabase::GetBytesRemainingToLoad(UFG::PartDatabase *this)
{
  return UFG::PartPool::GetQueuedBytes(&this->mPool);
}

// File Line: 587
// RVA: 0x15B1E0
void __fastcall UFG::PartDatabase::Update(UFG::PartDatabase *this, float deltaTime)
{
  UFG::PartDatabase *v2; // rbx

  v2 = this;
  if ( this->mReloadParts )
  {
    UFG::PartPool::ReloadRequests(&this->mPool);
    v2->mReloadParts = 0;
  }
  UFG::PartPool::UpdateRequests(&v2->mPool);
  v2->mPool.mDirty = 0;
}

// File Line: 601
// RVA: 0x1587F0
void __fastcall UFG::PartDatabase::FlushParts(UFG::PartDatabase *this, bool forceFlush)
{
  UFG::PartPool::FlushParts(&this->mPool, forceFlush);
}

// File Line: 606
// RVA: 0x158D50
UFG::qReflectObject *__fastcall UFG::PartDatabase::GetPartByName(UFG::PartDatabase *this, const char *name)
{
  const char *v2; // rdi
  unsigned __int64 v3; // rbx
  UFG::qReflectWarehouse *v4; // rax
  UFG::qReflectInventoryBase *v5; // rax

  v2 = name;
  v3 = UFG::qStringHash64("UFG::PartDefinition", 0xFFFFFFFFFFFFFFFFui64);
  v4 = UFG::qReflectWarehouse::Instance();
  v5 = UFG::qReflectWarehouse::GetInventory(v4, v3);
  return UFG::qReflectInventoryBase::FindObjectByName(v5, v2);
}

// File Line: 617
// RVA: 0x159AA0
void __fastcall UFG::PartDatabase::OnStreamingComplete(UFG::PartDatabase *this, UFG::PartRequest *pRequest)
{
  UFG::PartDatabase *v2; // rdi
  UFG::PartRequest *v3; // rbx

  v2 = this;
  v3 = pRequest;
  UFG::PartRequest::OnLoaded(pRequest);
  UFG::PartPool::PartLoadNotification(&v2->mPool, v3);
}

// File Line: 628
// RVA: 0x159570
void __fastcall UFG::PartDatabase::ModifyPriorityForPart(UFG::PartDatabase *this, UFG::PartDefinition *part, UFG::PartPriority::Type oldPriority, UFG::PartPriority::Type newPriority)
{
  UFG::qNode<UFG::PartRequest,UFG::PartRequest> *v4; // rax

  v4 = this->mPool.mRequestList.mNode.mNext;
  if ( v4 != (UFG::qNode<UFG::PartRequest,UFG::PartRequest> *)&this->mPool.mRequestList )
  {
    while ( v4[4].mPrev != (UFG::qNode<UFG::PartRequest,UFG::PartRequest> *)part->mBaseNode.mUID )
    {
      v4 = v4->mNext;
      if ( v4 == (UFG::qNode<UFG::PartRequest,UFG::PartRequest> *)&this->mPool.mRequestList )
        return;
    }
    ++*((_DWORD *)&v4[5].mPrev + newPriority + 1);
    LODWORD(v4[6].mNext) = Illusion::gEngine.mFrameCount;
    --*((_DWORD *)&v4[5].mPrev + oldPriority + 1);
    LODWORD(v4[6].mNext) = Illusion::gEngine.mFrameCount;
  }
}

// File Line: 638
// RVA: 0x159560
void __fastcall UFG::PartDatabase::LoadDatabase(UFG::PartDatabase *this)
{
  PartDatabase_LoadDatabase();
}

// File Line: 643
// RVA: 0x159480
void __fastcall UFG::PartDatabase::InitPool(UFG::PartDatabase *this)
{
  UFG::PartDatabase *v1; // rbx
  unsigned int mainMemory; // [rsp+30h] [rbp+8h]
  unsigned int textureMemory; // [rsp+38h] [rbp+10h]

  v1 = this;
  mainMemory = 0;
  textureMemory = 0;
  PartDatabase_QueryPoolSize(&mainMemory, &textureMemory);
  v1->mPool.mMaxModelMemory = mainMemory;
  v1->mPool.mMaxTextureMemory = textureMemory;
}

