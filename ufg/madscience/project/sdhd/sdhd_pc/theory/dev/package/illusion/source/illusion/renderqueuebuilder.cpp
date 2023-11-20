// File Line: 91
// RVA: 0x92870
void __fastcall Illusion::RenderQueueBuilder::Init(Illusion::RenderQueueBuilder *this, unsigned int num_streams, unsigned __int64 *render_queue_uids, UFG::qMemoryStream<Illusion::RenderQueue,1120> *queue_streams, UFG::qMemoryStream<Illusion::QueueCommandBucket,2048> *bucket_streams, void (__fastcall *end_queue_callback)(UFG::qMemoryStream<Illusion::RenderQueue,1120> *, unsigned __int64, void *), void *end_queue_user_data)
{
  unsigned int v7; // er8
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
  v7 = 0;
  if ( num_streams )
  {
    do
    {
      v8 = v7++;
      this->mActiveRenderQueueUIDs[v8] = 0i64;
      v8 *= 24i64;
      *(const char **)((char *)&this->mActiveRenderQueueStreams->mName + v8) = "RenderQueueBuilder.mActiveRenderQueueStreams";
      *(void **)((char *)&this->mActiveRenderQueueStreams->mMainMemoryAddress + v8) = 0i64;
      *(const char **)((char *)&this->mQueueCommandBucketStreams->mName + v8) = "RenderQueueBuilder.mQueueCommandBucketStreams";
      *(void **)((char *)&this->mQueueCommandBucketStreams->mMainMemoryAddress + v8) = 0i64;
    }
    while ( v7 < this->mMaxActiveRenderQueues );
  }
}

// File Line: 131
// RVA: 0x8E970
void __fastcall Illusion::RenderQueueBuilder::Close(Illusion::RenderQueueBuilder *this)
{
  Illusion::RenderQueueBuilder::FlushActiveQueuesToPendingList(this);
}

// File Line: 138
// RVA: 0x8E730
Illusion::RenderQueue *__fastcall Illusion::RenderQueueBuilder::BeginQueue(Illusion::RenderQueueBuilder *this, UFG::qMemoryStream<Illusion::RenderQueue,1120> *queue_stream, void *user_data)
{
  void *v3; // rbp
  UFG::qMemoryStream<Illusion::RenderQueue,1120> *v4; // rsi
  Illusion::RenderQueueBuilder *v5; // r14
  Illusion::RenderQueue *result; // rax
  Illusion::RenderQueue *v7; // rdi
  UFG::qList<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket,1,0> *v8; // rbx

  v3 = user_data;
  v4 = queue_stream;
  v5 = this;
  result = (Illusion::RenderQueue *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x460u, 0x10u);
  v7 = result;
  if ( result )
  {
    v4->mMainMemoryAddress = result;
    v8 = &result->mBuckets;
    result->mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&result->mPrev;
    result->mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&result->mPrev;
    v8->mNode.mPrev = &v8->mNode;
    result->mBuckets.mNode.mNext = &result->mBuckets.mNode;
    UFG::qMemSet(result->mStateValues.mParamValues, 0, 0x400u);
    v7->mStateValues.mSetValueMask.mFlags[1] = 0i64;
    v7->mStateValues.mSetValueMask.mFlags[0] = 0i64;
    v7->mState = 0;
    v7->mFreeBucket = 0i64;
    v7->mPlatData0 = v5;
    v7->mPlatData1 = v4;
    v7->mUserData = v3;
    *(_QWORD *)&v7->mCommandCount = 0i64;
    v8->mNode.mPrev = &v8->mNode;
    v7->mBuckets.mNode.mNext = &v8->mNode;
    result = v7;
  }
  return result;
}

// File Line: 184
// RVA: 0x91FB0
void __fastcall Illusion::RenderQueueBuilder::FlushActiveQueuesToPendingList(Illusion::RenderQueueBuilder *this)
{
  Illusion::RenderQueueBuilder *v1; // rbx
  unsigned int v2; // edi
  __int64 v3; // rsi
  signed __int64 v4; // rbp
  __int64 v5; // rcx
  unsigned __int64 v6; // rdx
  __int64 v7; // rax
  int v8; // eax

  v1 = this;
  v2 = 0;
  if ( this->mMaxActiveRenderQueues )
  {
    do
    {
      v3 = v2;
      v4 = (signed __int64)&v1->mActiveRenderQueueStreams[v2];
      if ( *(_QWORD *)(v4 + 8) )
      {
        v5 = *(_QWORD *)(v4 + 8);
        v6 = v1->mActiveRenderQueueUIDs[v2];
        v7 = *(_QWORD *)(v5 + 40);
        if ( v7 )
        {
          v8 = *(_DWORD *)(v7 + 24);
          *(_QWORD *)(v5 + 40) = 0i64;
          *(_DWORD *)(v5 + 72) += v8;
        }
        v1->mEndQueueCallback((UFG::qMemoryStream<Illusion::RenderQueue,1120> *)v4, v6, v1->mEndQueueUserData);
        *(_QWORD *)(v4 + 8) = 0i64;
      }
      ++v2;
      v1->mActiveRenderQueueUIDs[v3] = 0i64;
    }
    while ( v2 < v1->mMaxActiveRenderQueues );
  }
}

// File Line: 203
// RVA: 0x924D0
Illusion::RenderQueue *__fastcall Illusion::RenderQueueBuilder::GetRenderQueue(Illusion::RenderQueueBuilder *this, unsigned __int64 uid, void *user_data)
{
  unsigned int v3; // esi
  signed int v4; // er14
  signed int v5; // er15
  unsigned int v6; // er10
  __int64 v7; // r9
  void *v8; // r12
  unsigned __int64 v9; // rbp
  Illusion::RenderQueueBuilder *v10; // rbx
  unsigned __int64 *v11; // rax
  Illusion::RenderQueue *result; // rax
  unsigned int v13; // edx
  float v14; // xmm2_4
  unsigned __int64 *v15; // r8
  __int64 v16; // rcx
  signed int v17; // edi
  signed int v18; // er11
  __int64 v19; // rsi
  UFG::qMemoryStream<Illusion::RenderQueue,1120> *v20; // rdi
  _QWORD *v21; // rcx
  unsigned __int64 v22; // rdx
  __int64 v23; // rax
  int v24; // eax

  v3 = this->mMaxActiveRenderQueues;
  v4 = this->mMaxRenderQueuePrimitiveCount;
  v5 = this->mMaxRenderQueueCommandCount;
  v6 = -1;
  v7 = 0i64;
  v8 = user_data;
  v9 = uid;
  v10 = this;
  if ( !this->mMaxActiveRenderQueues )
    goto LABEL_8;
  v11 = this->mActiveRenderQueueUIDs;
  while ( *v11 != uid )
  {
    v7 = (unsigned int)(v7 + 1);
    ++v11;
    if ( (unsigned int)v7 >= v3 )
      goto LABEL_8;
  }
  result = (Illusion::RenderQueue *)this->mActiveRenderQueueStreams[v7].mMainMemoryAddress;
  if ( result->mCommandCount >= v5 || result->mPrimitiveCount >= v4 )
  {
    v6 = v7;
LABEL_8:
    if ( v6 == -1 )
    {
      v13 = 0;
      v14 = 0.0;
      if ( v3 )
      {
        v15 = this->mActiveRenderQueueUIDs;
        v7 = 0i64;
        while ( *v15 )
        {
          v16 = *(__int64 *)((char *)&v10->mActiveRenderQueueStreams->mMainMemoryAddress + v7);
          v17 = *(_DWORD *)(v16 + 72);
          v18 = *(_DWORD *)(v16 + 76);
          if ( v18 > v4 || v17 > v5 )
            break;
          if ( (float)((float)((float)v17 * (float)(1.0 / (float)v5)) + (float)((float)v18 * (float)(1.0 / (float)v4))) >= v14 )
          {
            v6 = v13;
            v14 = (float)((float)v17 * (float)(1.0 / (float)v5)) + (float)((float)v18 * (float)(1.0 / (float)v4));
          }
          ++v13;
          ++v15;
          v7 += 24i64;
          if ( v13 >= v3 )
            goto LABEL_18;
        }
        v6 = v13;
      }
    }
LABEL_18:
    v19 = v6;
    v20 = &v10->mActiveRenderQueueStreams[v6];
    v21 = v20->mMainMemoryAddress;
    if ( v21 )
    {
      v22 = v10->mActiveRenderQueueUIDs[v6];
      v23 = v21[5];
      if ( v23 )
      {
        v24 = *(_DWORD *)(v23 + 24);
        v21[5] = 0i64;
        *((_DWORD *)v21 + 18) += v24;
      }
      ((void (__fastcall *)(UFG::qMemoryStream<Illusion::RenderQueue,1120> *, unsigned __int64, void *, __int64))v10->mEndQueueCallback)(
        v20,
        v22,
        v10->mEndQueueUserData,
        v7);
      v20->mMainMemoryAddress = 0i64;
    }
    Illusion::RenderQueueBuilder::BeginQueue(v10, v20, v8);
    v10->mActiveRenderQueueUIDs[v19] = v9;
    result = (Illusion::RenderQueue *)v20->mMainMemoryAddress;
  }
  return result;
}

// File Line: 324
// RVA: 0x95A50
void __fastcall Illusion::RenderQueueBuilderSimple::Simple_EndQueue(UFG::qMemoryStream<Illusion::RenderQueue,1120> *render_queue_stream, unsigned __int64 queue_uid, void *end_queue_user_data)
{
  __int64 *v3; // rdx
  _QWORD *v4; // rax
  __int64 v5; // r9
  __int64 v6; // rcx

  v3 = (__int64 *)*((_QWORD *)end_queue_user_data + 8);
  v4 = render_queue_stream->mMainMemoryAddress;
  v5 = *((_QWORD *)end_queue_user_data + 9);
  v6 = *v3;
  if ( *v3 == v5 )
    v3[1] = (__int64)v4;
  else
    *(_QWORD *)(v6 + 8) = v4;
  *v4 = v6;
  v4[1] = v5;
  *v3 = (__int64)v4;
}

