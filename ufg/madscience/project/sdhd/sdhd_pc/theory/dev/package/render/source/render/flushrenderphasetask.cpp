// File Line: 15
// RVA: 0x14575E0
__int64 dynamic_initializer_for__gTaskFunctionDecl_EarlyFlushRenderPhaseTriggerTask__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(
    &gTaskFunctionDecl_EarlyFlushRenderPhaseTriggerTask,
    &gTaskFunctionDeclData_EarlyFlushRenderPhaseTriggerTask);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gTaskFunctionDecl_EarlyFlushRenderPhaseTriggerTask__);
}

// File Line: 35
// RVA: 0x14575B0
__int64 dynamic_initializer_for__gTaskFunctionDecl_EarlyFlushRenderPhaseTask__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(
    &gTaskFunctionDecl_EarlyFlushRenderPhaseTask,
    &gTaskFunctionDeclData_EarlyFlushRenderPhaseTask);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gTaskFunctionDecl_EarlyFlushRenderPhaseTask__);
}

// File Line: 37
// RVA: 0x7D5B0
void __fastcall EarlyFlushRenderPhaseTask(
        int workerId,
        UFG::qMemoryStreamer *memory_streamer,
        _QWORD *param_stream,
        void *pad0)
{
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v5; // rdx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v6; // r8
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *mPrev; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v8; // rcx
  RenderQueueLayer *v9; // rsi
  RenderQueueLayer **v10; // rbx
  __int64 v11; // rdi
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *mNext; // rdx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v13; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v14; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v15; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v16; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v17; // rdx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v18; // r8
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v19; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v20; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v21; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v22; // rax
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> v23; // [rsp+28h] [rbp-28h] BYREF
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> v24; // [rsp+38h] [rbp-18h] BYREF

  v23.mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v23;
  v23.mNode.mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v23;
  v5 = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)(param_stream + 2);
  v6 = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)param_stream[3];
  if ( v6 != v5 )
  {
    mPrev = v23.mNode.mPrev;
    v8 = v5->mPrev;
    v23.mNode.mPrev->mNext = v6;
    v6->mPrev = mPrev;
    v8->mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v23;
    v23.mNode.mPrev = v8;
    v5->mPrev = v5;
    v5->mNext = v5;
  }
  if ( *(_BYTE *)param_stream && *((_BYTE *)param_stream + 1) )
  {
    v9 = (RenderQueueLayer *)param_stream[9];
    v10 = (RenderQueueLayer **)(param_stream + 10);
    v11 = 4i64;
    do
    {
      RenderQueueLayer::Merge(v9, *v10++);
      --v11;
    }
    while ( v11 );
    v24.mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v24;
    v24.mNode.mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v24;
    v9->mSerializationList = &v24;
    RenderQueueLayer::SerializeRenderQueues(v9);
    v9->mSerializationList = 0i64;
    mNext = v24.mNode.mNext;
    if ( (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)v24.mNode.mNext != &v24 )
    {
      v13 = v23.mNode.mPrev;
      v14 = v24.mNode.mPrev;
      v23.mNode.mPrev->mNext = v24.mNode.mNext;
      mNext->mPrev = v13;
      v14->mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v23;
      v23.mNode.mPrev = v14;
      v24.mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v24;
      v24.mNode.mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v24;
    }
    UFG::qList<UFG::CachedLeaderboard,UFG::CachedLeaderboard,1,0>::DeleteNodes(&v24);
    v15 = v24.mNode.mPrev;
    v16 = v24.mNode.mNext;
    v24.mNode.mPrev->mNext = v24.mNode.mNext;
    v16->mPrev = v15;
    v24.mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v24;
    v24.mNode.mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v24;
  }
  v17 = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)(param_stream[1] + 16i64);
  v18 = v23.mNode.mNext;
  if ( (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)v23.mNode.mNext != &v23 )
  {
    v19 = v17->mPrev;
    v20 = v23.mNode.mPrev;
    v19->mNext = v23.mNode.mNext;
    v18->mPrev = v19;
    v20->mNext = v17;
    v17->mPrev = v20;
    v23.mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v23;
    v23.mNode.mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v23;
  }
  UFG::qList<UFG::CachedLeaderboard,UFG::CachedLeaderboard,1,0>::DeleteNodes(&v23);
  v21 = v23.mNode.mPrev;
  v22 = v23.mNode.mNext;
  v23.mNode.mPrev->mNext = v23.mNode.mNext;
  v22->mPrev = v21;
}

