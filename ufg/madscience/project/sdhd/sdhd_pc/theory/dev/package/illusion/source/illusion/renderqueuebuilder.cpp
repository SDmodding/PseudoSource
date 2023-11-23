// File Line: 91
// RVA: 0x92870
void __fastcall Illusion::RenderQueueBuilder::Init(
        Illusion::RenderQueueBuilder *this,
        unsigned int num_streams,
        unsigned __int64 *render_queue_uids,
        UFG::qMemoryStream<Illusion::RenderQueue,1120> *queue_streams,
        UFG::qMemoryStream<Illusion::QueueCommandBucket,2048> *bucket_streams,
        void (__fastcall *end_queue_callback)(UFG::qMemoryStream<Illusion::RenderQueue,1120> *, unsigned __int64, void *),
        void *end_queue_user_data)
{
  unsigned int i; // r8d
  __int64 v8; // rdx

  this->mActiveRenderQueueStreams = queue_streams;
  this->mEndQueueCallback = end_queue_callback;
  this->mActiveRenderQueueUIDs = render_queue_uids;
  this->mEndQueueUserData = end_queue_user_data;
  this->mMaxRenderQueuePrimitiveCount = 0x7FFFFFFF;
  this->mMaxRenderQueueCommandCount = 0x7FFFFFFF;
  this->mDebug = 0;
  this->mMaxActiveRenderQueues = num_streams;
  this->mQueueCommandBucketStreams = bucket_streams;
  for ( i = 0;
        i < this->mMaxActiveRenderQueues;
        *(void **)((char *)&this->mQueueCommandBucketStreams->mMainMemoryAddress + v8) = 0i64 )
  {
    v8 = i++;
    this->mActiveRenderQueueUIDs[v8] = 0i64;
    v8 *= 24i64;
    *(const char **)((char *)&this->mActiveRenderQueueStreams->mName + v8) = "RenderQueueBuilder.mActiveRenderQueueStreams";
    *(void **)((char *)&this->mActiveRenderQueueStreams->mMainMemoryAddress + v8) = 0i64;
    *(const char **)((char *)&this->mQueueCommandBucketStreams->mName + v8) = "RenderQueueBuilder.mQueueCommandBucketStreams";
  }
}

// File Line: 131
// RVA: 0x8E970
// attributes: thunk
void __fastcall Illusion::RenderQueueBuilder::Close(Illusion::RenderQueueBuilder *this)
{
  Illusion::RenderQueueBuilder::FlushActiveQueuesToPendingList(this);
}

// File Line: 138
// RVA: 0x8E730
Illusion::RenderQueue *__fastcall Illusion::RenderQueueBuilder::BeginQueue(
        Illusion::RenderQueueBuilder *this,
        UFG::qMemoryStream<Illusion::RenderQueue,1120> *queue_stream,
        void *user_data)
{
  Illusion::RenderQueue *result; // rax
  Illusion::RenderQueue *v7; // rdi
  UFG::qList<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket,1,0> *p_mBuckets; // rbx

  result = (Illusion::RenderQueue *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x460u, 0x10u);
  v7 = result;
  if ( result )
  {
    queue_stream->mMainMemoryAddress = result;
    p_mBuckets = &result->mBuckets;
    result->mPrev = result;
    result->mNext = result;
    result->mBuckets.mNode.mPrev = &result->mBuckets.mNode;
    result->mBuckets.mNode.mNext = &result->mBuckets.mNode;
    UFG::qMemSet(result->mStateValues.mParamValues, 0, 0x400u);
    v7->mStateValues.mSetValueMask.mFlags[1] = 0i64;
    v7->mStateValues.mSetValueMask.mFlags[0] = 0i64;
    v7->mState = 0;
    v7->mFreeBucket = 0i64;
    v7->mPlatData0 = this;
    v7->mPlatData1 = queue_stream;
    v7->mUserData = user_data;
    *(_QWORD *)&v7->mCommandCount = 0i64;
    p_mBuckets->mNode.mPrev = &p_mBuckets->mNode;
    v7->mBuckets.mNode.mNext = &p_mBuckets->mNode;
    return v7;
  }
  return result;
}

// File Line: 184
// RVA: 0x91FB0
void __fastcall Illusion::RenderQueueBuilder::FlushActiveQueuesToPendingList(Illusion::RenderQueueBuilder *this)
{
  unsigned int i; // edi
  __int64 v3; // rsi
  UFG::qMemoryStream<Illusion::RenderQueue,1120> *v4; // rbp
  _QWORD *mMainMemoryAddress; // rcx
  unsigned __int64 v6; // rdx
  __int64 v7; // rax
  int v8; // eax

  for ( i = 0; i < this->mMaxActiveRenderQueues; this->mActiveRenderQueueUIDs[v3] = 0i64 )
  {
    v3 = i;
    v4 = &this->mActiveRenderQueueStreams[i];
    if ( v4->mMainMemoryAddress )
    {
      mMainMemoryAddress = v4->mMainMemoryAddress;
      v6 = this->mActiveRenderQueueUIDs[i];
      v7 = mMainMemoryAddress[5];
      if ( v7 )
      {
        v8 = *(_DWORD *)(v7 + 24);
        mMainMemoryAddress[5] = 0i64;
        *((_DWORD *)mMainMemoryAddress + 18) += v8;
      }
      this->mEndQueueCallback(v4, v6, this->mEndQueueUserData);
      v4->mMainMemoryAddress = 0i64;
    }
    ++i;
  }
}

// File Line: 203
// RVA: 0x924D0
Illusion::RenderQueue *__fastcall Illusion::RenderQueueBuilder::GetRenderQueue(
        Illusion::RenderQueueBuilder *this,
        unsigned __int64 uid,
        void *user_data)
{
  unsigned int mMaxActiveRenderQueues; // esi
  int mMaxRenderQueuePrimitiveCount; // r14d
  int mMaxRenderQueueCommandCount; // r15d
  unsigned int v6; // r10d
  __int64 v7; // r9
  unsigned __int64 *mActiveRenderQueueUIDs; // rax
  Illusion::RenderQueue *result; // rax
  unsigned int v13; // edx
  float v14; // xmm2_4
  unsigned __int64 *v15; // r8
  __int64 v16; // rcx
  int v17; // edi
  int v18; // r11d
  __int64 v19; // rsi
  UFG::qMemoryStream<Illusion::RenderQueue,1120> *v20; // rdi
  _QWORD *mMainMemoryAddress; // rcx
  unsigned __int64 v22; // rdx
  __int64 v23; // rax
  int v24; // eax

  mMaxActiveRenderQueues = this->mMaxActiveRenderQueues;
  mMaxRenderQueuePrimitiveCount = this->mMaxRenderQueuePrimitiveCount;
  mMaxRenderQueueCommandCount = this->mMaxRenderQueueCommandCount;
  v6 = -1;
  v7 = 0i64;
  if ( !this->mMaxActiveRenderQueues )
    goto LABEL_8;
  mActiveRenderQueueUIDs = this->mActiveRenderQueueUIDs;
  while ( *mActiveRenderQueueUIDs != uid )
  {
    v7 = (unsigned int)(v7 + 1);
    ++mActiveRenderQueueUIDs;
    if ( (unsigned int)v7 >= mMaxActiveRenderQueues )
      goto LABEL_8;
  }
  result = (Illusion::RenderQueue *)this->mActiveRenderQueueStreams[v7].mMainMemoryAddress;
  if ( result->mCommandCount >= mMaxRenderQueueCommandCount || result->mPrimitiveCount >= mMaxRenderQueuePrimitiveCount )
  {
    v6 = v7;
LABEL_8:
    if ( v6 == -1 )
    {
      v13 = 0;
      v14 = 0.0;
      if ( mMaxActiveRenderQueues )
      {
        v15 = this->mActiveRenderQueueUIDs;
        v7 = 0i64;
        while ( *v15 )
        {
          v16 = *(__int64 *)((char *)&this->mActiveRenderQueueStreams->mMainMemoryAddress + v7);
          v17 = *(_DWORD *)(v16 + 72);
          v18 = *(_DWORD *)(v16 + 76);
          if ( v18 > mMaxRenderQueuePrimitiveCount || v17 > mMaxRenderQueueCommandCount )
            break;
          if ( (float)((float)((float)v17 * (float)(1.0 / (float)mMaxRenderQueueCommandCount))
                     + (float)((float)v18 * (float)(1.0 / (float)mMaxRenderQueuePrimitiveCount))) >= v14 )
          {
            v6 = v13;
            v14 = (float)((float)v17 * (float)(1.0 / (float)mMaxRenderQueueCommandCount))
                + (float)((float)v18 * (float)(1.0 / (float)mMaxRenderQueuePrimitiveCount));
          }
          ++v13;
          ++v15;
          v7 += 24i64;
          if ( v13 >= mMaxActiveRenderQueues )
            goto LABEL_18;
        }
        v6 = v13;
      }
    }
LABEL_18:
    v19 = v6;
    v20 = &this->mActiveRenderQueueStreams[v6];
    mMainMemoryAddress = v20->mMainMemoryAddress;
    if ( mMainMemoryAddress )
    {
      v22 = this->mActiveRenderQueueUIDs[v6];
      v23 = mMainMemoryAddress[5];
      if ( v23 )
      {
        v24 = *(_DWORD *)(v23 + 24);
        mMainMemoryAddress[5] = 0i64;
        *((_DWORD *)mMainMemoryAddress + 18) += v24;
      }
      ((void (__fastcall *)(UFG::qMemoryStream<Illusion::RenderQueue,1120> *, unsigned __int64, void *, __int64))this->mEndQueueCallback)(
        v20,
        v22,
        this->mEndQueueUserData,
        v7);
      v20->mMainMemoryAddress = 0i64;
    }
    Illusion::RenderQueueBuilder::BeginQueue(this, v20, user_data);
    this->mActiveRenderQueueUIDs[v19] = uid;
    return (Illusion::RenderQueue *)v20->mMainMemoryAddress;
  }
  return result;
}

// File Line: 324
// RVA: 0x95A50
void __fastcall Illusion::RenderQueueBuilderSimple::Simple_EndQueue(
        UFG::qMemoryStream<Illusion::RenderQueue,1120> *render_queue_stream,
        unsigned __int64 queue_uid,
        _QWORD *end_queue_user_data)
{
  __int64 *v3; // rdx
  _QWORD *mMainMemoryAddress; // rax
  __int64 v5; // r9
  __int64 v6; // rcx

  v3 = (__int64 *)end_queue_user_data[8];
  mMainMemoryAddress = render_queue_stream->mMainMemoryAddress;
  v5 = end_queue_user_data[9];
  v6 = *v3;
  if ( *v3 == v5 )
    v3[1] = (__int64)mMainMemoryAddress;
  else
    *(_QWORD *)(v6 + 8) = mMainMemoryAddress;
  *mMainMemoryAddress = v6;
  mMainMemoryAddress[1] = v5;
  *v3 = (__int64)mMainMemoryAddress;
}

