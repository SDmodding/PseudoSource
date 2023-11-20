// File Line: 34
// RVA: 0x14702B0
__int64 UFG::_dynamic_initializer_for__gForceReleaseNamedStreams__()
{
  UFG::qString::qString(&gForceReleaseNamedStreams);
  return atexit(UFG::_dynamic_atexit_destructor_for__gForceReleaseNamedStreams__);
}

// File Line: 130
// RVA: 0x22F970
void __fastcall UFG::StreamPrioritySystem::StreamPrioritySystem(UFG::StreamPrioritySystem *this, unsigned int streamPoolIndex, UFG::StreamingMemory::DATA_TYPE streamerDataType, unsigned int streamerFlags, int streamPoolSize, int maxHandleCount, unsigned int minPriorityLevel, unsigned int highPriorityLevel)
{
  UFG::StreamPrioritySystem *v8; // rsi

  v8 = this;
  this->mStreamPoolIndex = streamPoolIndex;
  this->mStreamerDataType = streamerDataType;
  this->mStreamerFlags = streamerFlags;
  this->mStreamPoolSize = streamPoolSize;
  this->mMaxHandleCount = maxHandleCount;
  this->mMinPriorityLevel = minPriorityLevel;
  this->mHighPriorityLevel = highPriorityLevel;
  UFG::qFixedAllocator::qFixedAllocator(&this->mHandleAllocator);
  UFG::qArray<UFG::StreamPriorityHandle *,0>::qArray<UFG::StreamPriorityHandle *,0>(&v8->mDesired, maxHandleCount, 0);
  UFG::qArray<UFG::StreamPriorityHandle *,0>::qArray<UFG::StreamPriorityHandle *,0>(
    &v8->mQueuedRelease,
    maxHandleCount,
    0);
  UFG::qFixedAllocator::Init(
    &v8->mHandleAllocator,
    v8->mMaxHandleCount << 6,
    64,
    "StreamPrioritySystem::mHandleAllocator",
    0i64);
  gDebugMinPriorityLevel = HIWORD(v8->mMinPriorityLevel);
  gDebugHighPriorityLevel = HIWORD(v8->mHighPriorityLevel);
}

// File Line: 156
// RVA: 0x230E50
UFG::StreamPriorityHandle *__fastcall UFG::StreamPrioritySystem::CreateHandle(UFG::StreamPrioritySystem *this, UFG::qSharedString *filename)
{
  UFG::qSharedString *v2; // rdi
  UFG::qFixedAllocator *v4; // rdx
  char *v5; // rbx
  unsigned int v6; // ecx

  v2 = filename;
  if ( !this->mHandleAllocator.mFreeListHead )
    return 0i64;
  v4 = &this->mHandleAllocator;
  v5 = this->mHandleAllocator.mFreeListHead;
  if ( v5 )
  {
    this->mHandleAllocator.mFreeListHead = *(char **)v5;
    v6 = ++this->mHandleAllocator.mNumSlotsAllocated;
    if ( v4->mMostSlotsAllocated > v6 )
      v6 = v4->mMostSlotsAllocated;
    v4->mMostSlotsAllocated = v6;
  }
  else
  {
    UFG::qFixedAllocator::ReportFull(&this->mHandleAllocator);
  }
  if ( v5 )
    UFG::StreamPriorityHandle::StreamPriorityHandle((UFG::StreamPriorityHandle *)v5, v2);
  return (UFG::StreamPriorityHandle *)v5;
}

// File Line: 172
// RVA: 0x231950
void __fastcall UFG::StreamPrioritySystem::FreeHandle(UFG::StreamPrioritySystem *this, UFG::StreamPriorityHandle *handle)
{
  UFG::StreamPriorityHandle *v2; // rbx
  UFG::StreamPrioritySystem *v3; // rdi
  UFG::StreamPriorityHandle *item; // [rsp+48h] [rbp+10h]

  item = handle;
  v2 = handle;
  v3 = this;
  if ( (char *)handle < &this->mHandleAllocator.mBuffer[(unsigned __int64)this->mHandleAllocator.mBufferSize]
    && (char *)handle >= this->mHandleAllocator.mBuffer )
  {
    if ( handle->mHandle.mImpl )
      UFG::DataStreamer::ReleaseStream(&handle->mHandle);
    UFG::qArray<UFG::StreamPriorityHandle *,0>::Erase(&v3->mDesired, &item);
    UFG::qArray<UFG::StreamPriorityHandle *,0>::Erase(&v3->mQueuedRelease, &item);
    item = v2;
    UFG::qSharedString::~qSharedString(&v2->mFilename);
    UFG::DataStreamer::Handle::~Handle(&v2->mHandle);
    v2->mHandle.mPrev = (UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *)v3->mHandleAllocator.mFreeListHead;
    v3->mHandleAllocator.mFreeListHead = (char *)v2;
    --v3->mHandleAllocator.mNumSlotsAllocated;
  }
}

// File Line: 195
// RVA: 0x230C80
void __fastcall UFG::StreamPrioritySystem::ChangePriority(UFG::StreamPrioritySystem *this, UFG::StreamPriorityHandle *handle, unsigned int newPriority)
{
  unsigned int v3; // eax
  UFG::StreamPrioritySystem *v4; // rdi
  UFG::StreamPriorityHandle *v5; // rbx
  bool v6; // cl
  unsigned int v7; // edx
  unsigned int v8; // eax
  UFG::StreamPriorityHandle **v9; // rcx
  UFG::qPropertySet *item; // [rsp+38h] [rbp+10h]

  item = (UFG::qPropertySet *)handle;
  v3 = handle->mPriority;
  v4 = this;
  v5 = handle;
  v6 = v3 >= this->mMinPriorityLevel;
  if ( newPriority != v3 )
  {
    handle->mPriority = newPriority;
    if ( newPriority < v4->mMinPriorityLevel )
    {
      if ( v6 )
      {
        UFG::qArray<UFG::StreamPriorityHandle *,0>::Erase(&v4->mDesired, (UFG::StreamPriorityHandle *const *)&item);
        v7 = v4->mQueuedRelease.size;
        v8 = 0;
        if ( !v7 )
          goto LABEL_14;
        v9 = v4->mQueuedRelease.p;
        while ( v5 != *v9 )
        {
          ++v8;
          ++v9;
          if ( v8 >= v7 )
            goto LABEL_14;
        }
        if ( v8 == -1 )
LABEL_14:
          UFG::qArray<UFG::PedSpawningInfo *,0>::Add(
            (UFG::qArray<UFG::qPropertySet *,0> *)&v4->mQueuedRelease,
            &item,
            "qArray.Add");
      }
    }
    else if ( !v6 )
    {
      if ( handle->mMemorySize > 0 )
        UFG::qArray<UFG::PedSpawningInfo *,0>::Add(
          (UFG::qArray<UFG::qPropertySet *,0> *)&v4->mDesired,
          &item,
          "qArray.Add");
      UFG::qArray<UFG::StreamPriorityHandle *,0>::Erase(&v4->mQueuedRelease, (UFG::StreamPriorityHandle *const *)&item);
    }
  }
}

// File Line: 273
// RVA: 0x231660
void __fastcall UFG::StreamPrioritySystem::EvictFromMemory(UFG::StreamPrioritySystem *this, UFG::StreamPriorityHandle *handle)
{
  UFG::StreamPriorityHandle *v2; // rbx
  UFG::StreamPrioritySystem *v3; // rdi
  UFG::StreamPriorityHandle *item; // [rsp+38h] [rbp+10h]

  item = handle;
  v2 = handle;
  v3 = this;
  if ( handle->mHandle.mImpl )
    UFG::DataStreamer::ReleaseStream(&handle->mHandle);
  UFG::qArray<UFG::StreamPriorityHandle *,0>::Erase(&v3->mDesired, &item);
  UFG::qArray<UFG::StreamPriorityHandle *,0>::Erase(&v3->mQueuedRelease, &item);
  *(_QWORD *)&v2->mMemorySize = ((unsigned int)UFG::StreamFileWrapper::GetAllocationSize(v2->mFilename.mText) + 4095) & 0xFFFFF000;
}

// File Line: 343
// RVA: 0x235730
void __fastcall UFG::StreamPrioritySystem::Update(UFG::StreamPrioritySystem *this)
{
  UFG::StreamPrioritySystem *v1; // rbx

  v1 = this;
  UFG::StreamPrioritySystem::ReleaseQueuedHandles(this);
  UFG::StreamPrioritySystem::UpdateDesiredHandles(v1);
}

// File Line: 359
// RVA: 0x234CA0
void __fastcall UFG::StreamPrioritySystem::ReleaseQueuedHandles(UFG::StreamPrioritySystem *this)
{
  UFG::DataStreamer::Handle **v1; // rbx
  UFG::StreamPrioritySystem *v2; // rdi

  v1 = (UFG::DataStreamer::Handle **)this->mQueuedRelease.p;
  v2 = this;
  if ( v1 == &v1[this->mQueuedRelease.size] )
  {
    this->mQueuedRelease.size = 0;
  }
  else
  {
    do
    {
      if ( (*v1)->mImpl )
        UFG::DataStreamer::ReleaseStream(*v1);
      ++v1;
    }
    while ( v1 != (UFG::DataStreamer::Handle **)&v2->mQueuedRelease.p[v2->mQueuedRelease.size] );
    v2->mQueuedRelease.size = 0;
  }
}

// File Line: 396
// RVA: 0x235860
void __fastcall UFG::StreamPrioritySystem::UpdateDesiredHandles(UFG::StreamPrioritySystem *this)
{
  signed int v1; // eax
  UFG::StreamPriorityHandle **v2; // rbx
  UFG::StreamPrioritySystem *v3; // r15
  __int64 v4; // rsi
  UFG::StreamPriorityHandle **v5; // r14
  __int64 v6; // rbp
  int v7; // er11
  UFG::StreamPriorityHandle *v8; // r10
  int v9; // er8
  __int64 i; // rdx
  UFG::StreamPriorityHandle *v11; // rcx
  unsigned int v12; // eax
  unsigned int v13; // er9
  __int64 v14; // rsi
  int v15; // ebp
  int v16; // er14
  __int64 j; // rdi
  UFG::StreamPriorityHandle *v18; // rbx
  int v19; // eax
  const char *v20; // rdx
  __int64 k; // rbx
  UFG::DataStreamer::Handle *v22; // rcx

  v1 = this->mDesired.size;
  v2 = this->mDesired.p;
  v3 = this;
  if ( v1 > 1 )
  {
    v4 = 0i64;
    v5 = v2 + 1;
    v6 = (unsigned int)(v1 - 1);
    v7 = 0;
    do
    {
      v8 = *v5;
      v9 = v7;
      for ( i = v4; v9 >= 0; --v9 )
      {
        v11 = v2[i];
        v12 = v8->mPriority;
        v13 = v11->mPriority;
        if ( v13 >= v12 && (v13 != v12 || v11->mMemorySize <= v8->mMemorySize) )
          break;
        v2[i-- + 1] = v11;
      }
      ++v7;
      ++v5;
      ++v4;
      v2[i + 1] = v8;
      --v6;
    }
    while ( v6 );
  }
  v14 = v3->mDesired.size;
  v15 = 0;
  v16 = 0;
  for ( j = 0i64; j < v14; ++v15 )
  {
    v18 = v3->mDesired.p[j];
    v19 = v18->mMemorySize;
    v16 += v19;
    if ( v16 > v3->mStreamPoolSize )
      break;
    if ( !v18->mHandle.mImpl )
    {
      v20 = v18->mFilename.mText;
      if ( v19 <= 0 )
        UFG::qPrintf(
          "WARNING: StreamPrioritySystem::QueueStream() --> File Does Not Exist (or is zero length) (%s)!\n",
          v20);
      else
        UFG::DataStreamer::QueueStream(
          &v18->mHandle,
          v20,
          v3->mStreamerDataType,
          DEFAULT_PRIORITY,
          v3->mStreamerFlags,
          0i64,
          0i64);
    }
    v18->mHandle.mPriority.mValue = v18->mPriority < v3->mHighPriorityLevel ? 0x2000 : 10240;
    ++j;
  }
  for ( k = v15; k < v14; ++k )
  {
    v22 = &v3->mDesired.p[k]->mHandle;
    if ( v22->mImpl )
    {
      v22->mPriority.mValue = 0x2000;
      UFG::DataStreamer::ReleaseStream(v22);
    }
  }
}

// File Line: 490
// RVA: 0x232B20
__int64 __fastcall UFG::StreamPrioritySystem::GetMemorySize(const char *filename)
{
  return ((unsigned int)UFG::StreamFileWrapper::GetAllocationSize(filename) + 4095) & 0xFFFFF000;
}

// File Line: 662
// RVA: 0x22F8E0
void __fastcall UFG::StreamPriorityHandle::StreamPriorityHandle(UFG::StreamPriorityHandle *this, UFG::qSharedString *filename)
{
  UFG::qSharedString *v2; // rbx
  UFG::StreamPriorityHandle *v3; // rdi

  v2 = filename;
  v3 = this;
  this->mHandle.mPrev = (UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *)&this->mHandle.mPrev;
  this->mHandle.mNext = (UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *)&this->mHandle.mPrev;
  this->mHandle.mCallback = 0i64;
  this->mHandle.mCallbackParam = 0i64;
  this->mHandle.mImpl = 0i64;
  *(_DWORD *)&this->mHandle.mFlags = 536870915;
  this->mHandle._mTargetState.mValue = 1;
  UFG::qSharedString::qSharedString(&this->mFilename, filename);
  v3->mPriority = 0;
  v3->mMemorySize = ((unsigned __int64)UFG::StreamFileWrapper::GetAllocationSize(v2->mText) + 4095) & 0xFFFFF000;
}

