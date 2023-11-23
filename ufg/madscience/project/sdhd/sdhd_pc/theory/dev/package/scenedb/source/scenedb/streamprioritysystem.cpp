// File Line: 34
// RVA: 0x14702B0
__int64 UFG::_dynamic_initializer_for__gForceReleaseNamedStreams__()
{
  UFG::qString::qString(&gForceReleaseNamedStreams);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gForceReleaseNamedStreams__);
}

// File Line: 130
// RVA: 0x22F970
void __fastcall UFG::StreamPrioritySystem::StreamPrioritySystem(
        UFG::StreamPrioritySystem *this,
        unsigned int streamPoolIndex,
        UFG::StreamingMemory::DATA_TYPE streamerDataType,
        unsigned int streamerFlags,
        int streamPoolSize,
        int maxHandleCount,
        unsigned int minPriorityLevel,
        unsigned int highPriorityLevel)
{
  this->mStreamPoolIndex = streamPoolIndex;
  this->mStreamerDataType = streamerDataType;
  this->mStreamerFlags = streamerFlags;
  this->mStreamPoolSize = streamPoolSize;
  this->mMaxHandleCount = maxHandleCount;
  this->mMinPriorityLevel = minPriorityLevel;
  this->mHighPriorityLevel = highPriorityLevel;
  UFG::qFixedAllocator::qFixedAllocator(&this->mHandleAllocator);
  UFG::qArray<UFG::StreamPriorityHandle *,0>::qArray<UFG::StreamPriorityHandle *,0>(&this->mDesired, maxHandleCount, 0);
  UFG::qArray<UFG::StreamPriorityHandle *,0>::qArray<UFG::StreamPriorityHandle *,0>(
    &this->mQueuedRelease,
    maxHandleCount,
    0);
  UFG::qFixedAllocator::Init(
    &this->mHandleAllocator,
    this->mMaxHandleCount << 6,
    64,
    "StreamPrioritySystem::mHandleAllocator",
    0i64);
  gDebugMinPriorityLevel = HIWORD(this->mMinPriorityLevel);
  gDebugHighPriorityLevel = HIWORD(this->mHighPriorityLevel);
}

// File Line: 156
// RVA: 0x230E50
UFG::StreamPriorityHandle *__fastcall UFG::StreamPrioritySystem::CreateHandle(
        UFG::StreamPrioritySystem *this,
        UFG::qSharedString *filename)
{
  UFG::qFixedAllocator *p_mHandleAllocator; // rdx
  char *mFreeListHead; // rbx
  unsigned int mMostSlotsAllocated; // ecx

  if ( !this->mHandleAllocator.mFreeListHead )
    return 0i64;
  p_mHandleAllocator = &this->mHandleAllocator;
  mFreeListHead = this->mHandleAllocator.mFreeListHead;
  if ( mFreeListHead )
  {
    this->mHandleAllocator.mFreeListHead = *(char **)mFreeListHead;
    mMostSlotsAllocated = ++this->mHandleAllocator.mNumSlotsAllocated;
    if ( p_mHandleAllocator->mMostSlotsAllocated > mMostSlotsAllocated )
      mMostSlotsAllocated = p_mHandleAllocator->mMostSlotsAllocated;
    p_mHandleAllocator->mMostSlotsAllocated = mMostSlotsAllocated;
  }
  else
  {
    UFG::qFixedAllocator::ReportFull(&this->mHandleAllocator);
  }
  if ( mFreeListHead )
    UFG::StreamPriorityHandle::StreamPriorityHandle((UFG::StreamPriorityHandle *)mFreeListHead, filename);
  return (UFG::StreamPriorityHandle *)mFreeListHead;
}

// File Line: 172
// RVA: 0x231950
void __fastcall UFG::StreamPrioritySystem::FreeHandle(
        UFG::StreamPrioritySystem *this,
        UFG::StreamPriorityHandle *handle)
{
  UFG::StreamPriorityHandle *item; // [rsp+48h] [rbp+10h] BYREF

  item = handle;
  if ( (char *)handle < &this->mHandleAllocator.mBuffer[(unsigned __int64)this->mHandleAllocator.mBufferSize]
    && (char *)handle >= this->mHandleAllocator.mBuffer )
  {
    if ( handle->mHandle.mImpl )
      UFG::DataStreamer::ReleaseStream(&handle->mHandle);
    UFG::qArray<UFG::StreamPriorityHandle *,0>::Erase(&this->mDesired, &item);
    UFG::qArray<UFG::StreamPriorityHandle *,0>::Erase(&this->mQueuedRelease, &item);
    item = handle;
    UFG::qSharedString::~qSharedString(&handle->mFilename);
    UFG::DataStreamer::Handle::~Handle(&handle->mHandle);
    handle->mHandle.mPrev = (UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *)this->mHandleAllocator.mFreeListHead;
    this->mHandleAllocator.mFreeListHead = (char *)handle;
    --this->mHandleAllocator.mNumSlotsAllocated;
  }
}

// File Line: 195
// RVA: 0x230C80
void __fastcall UFG::StreamPrioritySystem::ChangePriority(
        UFG::StreamPrioritySystem *this,
        UFG::qPropertySet *handle,
        unsigned int newPriority)
{
  unsigned int mOffset_high; // eax
  bool v6; // cl
  unsigned int size; // edx
  unsigned int v8; // eax
  UFG::StreamPriorityHandle **p; // rcx
  UFG::qPropertySet *item; // [rsp+38h] [rbp+10h] BYREF

  item = handle;
  mOffset_high = HIDWORD(handle->mProperties.mOffset);
  v6 = mOffset_high >= this->mMinPriorityLevel;
  if ( newPriority != mOffset_high )
  {
    HIDWORD(handle->mProperties.mOffset) = newPriority;
    if ( newPriority < this->mMinPriorityLevel )
    {
      if ( v6 )
      {
        UFG::qArray<UFG::StreamPriorityHandle *,0>::Erase(&this->mDesired, (UFG::StreamPriorityHandle *const *)&item);
        size = this->mQueuedRelease.size;
        v8 = 0;
        if ( !size )
          goto LABEL_14;
        p = this->mQueuedRelease.p;
        while ( handle != (UFG::qPropertySet *)*p )
        {
          ++v8;
          ++p;
          if ( v8 >= size )
            goto LABEL_14;
        }
        if ( v8 == -1 )
LABEL_14:
          UFG::qArray<UFG::PedSpawningInfo *,0>::Add(
            (UFG::qArray<UFG::qPropertySet *,0> *)&this->mQueuedRelease,
            &item,
            "qArray.Add");
      }
    }
    else if ( !v6 )
    {
      if ( SLODWORD(handle->mProperties.mOffset) > 0 )
        UFG::qArray<UFG::PedSpawningInfo *,0>::Add(
          (UFG::qArray<UFG::qPropertySet *,0> *)&this->mDesired,
          &item,
          "qArray.Add");
      UFG::qArray<UFG::StreamPriorityHandle *,0>::Erase(
        &this->mQueuedRelease,
        (UFG::StreamPriorityHandle *const *)&item);
    }
  }
}

// File Line: 273
// RVA: 0x231660
void __fastcall UFG::StreamPrioritySystem::EvictFromMemory(
        UFG::StreamPrioritySystem *this,
        UFG::StreamPriorityHandle *handle)
{
  UFG::StreamPriorityHandle *item; // [rsp+38h] [rbp+10h] BYREF

  item = handle;
  if ( handle->mHandle.mImpl )
    UFG::DataStreamer::ReleaseStream(&handle->mHandle);
  UFG::qArray<UFG::StreamPriorityHandle *,0>::Erase(&this->mDesired, &item);
  UFG::qArray<UFG::StreamPriorityHandle *,0>::Erase(&this->mQueuedRelease, &item);
  *(_QWORD *)&handle->mMemorySize = ((unsigned int)UFG::StreamFileWrapper::GetAllocationSize(handle->mFilename.mText)
                                   + 4095) & 0xFFFFF000;
}

// File Line: 343
// RVA: 0x235730
void __fastcall UFG::StreamPrioritySystem::Update(UFG::StreamPrioritySystem *this)
{
  UFG::StreamPrioritySystem::ReleaseQueuedHandles(this);
  UFG::StreamPrioritySystem::UpdateDesiredHandles(this);
}

// File Line: 359
// RVA: 0x234CA0
void __fastcall UFG::StreamPrioritySystem::ReleaseQueuedHandles(UFG::StreamPrioritySystem *this)
{
  UFG::DataStreamer::Handle **p; // rbx

  p = (UFG::DataStreamer::Handle **)this->mQueuedRelease.p;
  if ( p == &p[this->mQueuedRelease.size] )
  {
    this->mQueuedRelease.size = 0;
  }
  else
  {
    do
    {
      if ( (*p)->mImpl )
        UFG::DataStreamer::ReleaseStream(*p);
      ++p;
    }
    while ( p != (UFG::DataStreamer::Handle **)&this->mQueuedRelease.p[this->mQueuedRelease.size] );
    this->mQueuedRelease.size = 0;
  }
}

// File Line: 396
// RVA: 0x235860
void __fastcall UFG::StreamPrioritySystem::UpdateDesiredHandles(UFG::StreamPrioritySystem *this)
{
  signed int size; // eax
  UFG::StreamPriorityHandle **p; // rbx
  __int64 v4; // rsi
  UFG::StreamPriorityHandle **v5; // r14
  __int64 v6; // rbp
  int v7; // r11d
  UFG::StreamPriorityHandle *v8; // r10
  int v9; // r8d
  __int64 i; // rdx
  UFG::StreamPriorityHandle *v11; // rcx
  unsigned int mPriority; // eax
  unsigned int v13; // r9d
  __int64 v14; // rsi
  int v15; // ebp
  int v16; // r14d
  __int64 v17; // rdi
  UFG::StreamPriorityHandle *v18; // rbx
  int mMemorySize; // eax
  const char *mText; // rdx
  __int64 j; // rbx
  UFG::StreamPriorityHandle *v22; // rcx

  size = this->mDesired.size;
  p = this->mDesired.p;
  if ( size > 1 )
  {
    v4 = 0i64;
    v5 = p + 1;
    v6 = (unsigned int)(size - 1);
    v7 = 0;
    do
    {
      v8 = *v5;
      v9 = v7;
      for ( i = v4; v9 >= 0; --v9 )
      {
        v11 = p[i];
        mPriority = v8->mPriority;
        v13 = v11->mPriority;
        if ( v13 >= mPriority && (v13 != mPriority || v11->mMemorySize <= v8->mMemorySize) )
          break;
        p[i-- + 1] = v11;
      }
      ++v7;
      ++v5;
      ++v4;
      p[i + 1] = v8;
      --v6;
    }
    while ( v6 );
  }
  v14 = this->mDesired.size;
  v15 = 0;
  v16 = 0;
  v17 = 0i64;
  if ( this->mDesired.size )
  {
    do
    {
      v18 = this->mDesired.p[v17];
      mMemorySize = v18->mMemorySize;
      v16 += mMemorySize;
      if ( v16 > this->mStreamPoolSize )
        break;
      if ( !v18->mHandle.mImpl )
      {
        mText = v18->mFilename.mText;
        if ( mMemorySize <= 0 )
          UFG::qPrintf(
            "WARNING: StreamPrioritySystem::QueueStream() --> File Does Not Exist (or is zero length) (%s)!\n",
            mText);
        else
          UFG::DataStreamer::QueueStream(
            &v18->mHandle,
            mText,
            this->mStreamerDataType,
            DEFAULT_PRIORITY,
            this->mStreamerFlags,
            0i64,
            0i64);
      }
      v18->mHandle.mPriority.mValue = v18->mPriority < this->mHighPriorityLevel ? 0x2000 : 10240;
      ++v17;
      ++v15;
    }
    while ( v17 < v14 );
  }
  for ( j = v15; j < v14; ++j )
  {
    v22 = this->mDesired.p[j];
    if ( v22->mHandle.mImpl )
    {
      v22->mHandle.mPriority.mValue = 0x2000;
      UFG::DataStreamer::ReleaseStream(&v22->mHandle);
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
void __fastcall UFG::StreamPriorityHandle::StreamPriorityHandle(
        UFG::StreamPriorityHandle *this,
        UFG::qSharedString *filename)
{
  this->mHandle.mPrev = &this->mHandle;
  this->mHandle.mNext = &this->mHandle;
  this->mHandle.mCallback = 0i64;
  this->mHandle.mCallbackParam = 0i64;
  this->mHandle.mImpl = 0i64;
  *(_DWORD *)&this->mHandle.mFlags = 536870915;
  this->mHandle._mTargetState.mValue = 1;
  UFG::qSharedString::qSharedString(&this->mFilename, filename);
  this->mPriority = 0;
  this->mMemorySize = (UFG::StreamFileWrapper::GetAllocationSize(filename->mText) + 4095) & 0xFFFFF000;
}

