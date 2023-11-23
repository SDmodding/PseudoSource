// File Line: 437
// RVA: 0x94AA0
void __fastcall Illusion::RenderQueue_PrintCommand(Illusion::QueueCommand *command)
{
  char *mData; // rdi
  __int16 mCommandType; // si
  unsigned __int16 mIndex; // r14
  const char *mName; // rbx
  char *v5; // rbp
  __int64 v6; // rax
  char dest[1024]; // [rsp+50h] [rbp-408h] BYREF

  mData = (char *)command->mData;
  mCommandType = command->mCommandType;
  mIndex = command->mIndex;
  mName = &customCaption;
  v5 = &customCaption;
  if ( !mData )
  {
    mName = "<null data>";
    goto LABEL_32;
  }
  switch ( mCommandType )
  {
    case 1:
      mName = mData + 52;
      v5 = dest;
      UFG::qSPrintf(dest, 1024, "SortUID=0x%08x", *((unsigned int *)mData + 28));
      goto LABEL_32;
    case 10:
      mName = (const char *)*((_QWORD *)mData + 30);
      goto LABEL_32;
    case 11:
      mName = (const char *)*((_QWORD *)mData + 33);
      UFG::qSPrintf(
        dest,
        1024,
        "[index_start=%d, num_prims=%d, prim_type=%d]",
        *((unsigned int *)mData + 63),
        *((_DWORD *)mData + 64),
        *((_DWORD *)mData + 62));
      v5 = dest;
      goto LABEL_32;
    case 12:
      mName = (const char *)*((_QWORD *)mData + 5);
      goto LABEL_32;
  }
  if ( (unsigned __int16)(mCommandType - 2) > 1u && (unsigned __int16)(mCommandType - 7) > 1u )
  {
    if ( mCommandType != 4 )
    {
      if ( mCommandType == 5 )
      {
        mIndex += 4;
      }
      else if ( mCommandType != 6 )
      {
        if ( mCommandType == 16 )
        {
          if ( *(_QWORD *)mData )
            mName = (const char *)(**(_QWORD **)mData + 81i64);
          else
            mName = "<null target>";
        }
        else if ( (unsigned __int16)(mCommandType - 14) <= 1u )
        {
          v5 = (char *)*((_QWORD *)mData + 3);
          mName = (const char *)(*(_QWORD *)mData + 81i64);
        }
        else if ( mCommandType == 9 )
        {
          UFG::qSPrintf(
            dest,
            1024,
            "[viewport=%v4, depth=%v2 scissor=%d %d %d %d]",
            mData,
            mData + 16,
            *((_DWORD *)mData + 6),
            *((_DWORD *)mData + 7),
            *((_DWORD *)mData + 8),
            *((_DWORD *)mData + 9));
          v5 = dest;
        }
        else if ( (unsigned __int16)(mCommandType - 22) > 1u && (unsigned __int16)(mCommandType - 20) <= 1u )
        {
          mName = (const char *)command->mData;
        }
        goto LABEL_32;
      }
    }
    mName = Illusion::gStateSystem.mStateParamDescs[mIndex].mName;
    UFG::qSPrintf(
      dest,
      1024,
      "%s [num_elem=%d, elem_size=%d, data_size=%d]",
      mData + 52,
      *((_DWORD *)mData + 27),
      *((_DWORD *)mData + 26),
      *((_DWORD *)mData + 23));
    v5 = dest;
    goto LABEL_32;
  }
  v6 = mIndex;
  mName = Illusion::gStateSystem.mStateParamDescs[v6].mName;
  if ( Illusion::gStateSystem.mStateParamDescs[v6].mIsResourceData )
    v5 = mData + 52;
LABEL_32:
  UFG::qPrintf(
    "%-25s : 0x%016x64 -> %3d  %-26s%s\n",
    Illusion::QueueCommandName[mCommandType],
    mData,
    (unsigned int)(__int16)mIndex,
    mName,
    v5);
}

// File Line: 534
// RVA: 0x94540
void __fastcall Illusion::RenderQueueSystem::Print(Illusion::RenderQueue *render_queue)
{
  UFG::qList<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket,1,0> *p_mBuckets; // rsi
  unsigned int v3; // edi
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *mNext; // rbx

  UFG::qPrintf(
    "-------------------------\n"
    "Queue: 0x%016x64  num_cmds=%4d  num_prims=%5d  platdata0=0x%016x64  platdata1=0x%016x64  userdata=0x%016x64\n",
    render_queue,
    render_queue->mCommandCount,
    render_queue->mPrimitiveCount,
    render_queue->mPlatData0,
    render_queue->mPlatData1,
    render_queue->mUserData);
  p_mBuckets = &render_queue->mBuckets;
  if ( (UFG::qList<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket,1,0> *)render_queue->mBuckets.mNode.mNext != &render_queue->mBuckets )
  {
    v3 = 0;
    mNext = render_queue->mBuckets.mNode.mNext;
    while ( mNext != (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)p_mBuckets )
    {
      Illusion::RenderQueue_PrintCommand((Illusion::QueueCommand *)&mNext[v3++ + 2]);
      if ( v3 >= LODWORD(mNext[1].mNext) )
      {
        mNext = mNext->mNext;
        v3 = 0;
      }
    }
  }
}

// File Line: 579
// RVA: 0x92050
void __fastcall Illusion::RenderQueueSystem::FlushRenderCommand(__int16 command_type, __int16 index, void *data)
{
  char *v6; // rax
  char *v7; // rbx
  __int64 v8; // rdx
  __int64 v9; // rax
  __int64 v10; // rcx
  char *v11; // rax
  char *v12; // rdx
  __int64 v13; // rax
  __int64 v14; // rax
  __int64 v15; // rax
  char *v16; // rax
  Illusion::RenderPhase *v17; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *mPrev; // rax

  v6 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x460u, 0x10u);
  v7 = v6;
  if ( v6 )
  {
    *(_QWORD *)v6 = v6;
    *((_QWORD *)v6 + 1) = v6;
    *((_QWORD *)v6 + 2) = v6 + 16;
    *((_QWORD *)v6 + 3) = v6 + 16;
    UFG::qMemSet(v6 + 96, 0, 0x400u);
    *((_QWORD *)v7 + 11) = 0i64;
    *((_QWORD *)v7 + 10) = 0i64;
    *((_DWORD *)v7 + 8) = 0;
    *((_QWORD *)v7 + 5) = 0i64;
    *((_QWORD *)v7 + 6) = 0i64;
    *((_QWORD *)v7 + 7) = 0i64;
    *((_QWORD *)v7 + 8) = 0i64;
    *((_QWORD *)v7 + 9) = 0i64;
  }
  else
  {
    v7 = 0i64;
  }
  v8 = *((_QWORD *)v7 + 5);
  if ( v8 )
  {
    v9 = *(unsigned int *)(v8 + 24);
    if ( (unsigned int)v9 < 0x7E )
    {
      v10 = v8 + 16 * (v9 + 2);
      *(_DWORD *)(v8 + 24) = v9 + 1;
      goto LABEL_12;
    }
    *((_DWORD *)v7 + 18) += *(_DWORD *)(v8 + 24);
    *((_QWORD *)v7 + 5) = 0i64;
  }
  v11 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v12 = v11;
  if ( v11 )
  {
    *(_QWORD *)v11 = v11;
    *((_QWORD *)v11 + 1) = v11;
    *((_QWORD *)v11 + 2) = 0i64;
    *((_DWORD *)v11 + 6) = 0;
    v13 = *((_QWORD *)v7 + 2);
    *(_QWORD *)(v13 + 8) = v12;
    *(_QWORD *)v12 = v13;
    *((_QWORD *)v12 + 1) = v7 + 16;
    *((_QWORD *)v7 + 2) = v12;
    *((_QWORD *)v7 + 5) = v12;
  }
  v14 = *((_QWORD *)v7 + 5);
  if ( v14 )
  {
    *(_DWORD *)(v14 + 24) = 1;
    v10 = *((_QWORD *)v7 + 5) + 32i64;
LABEL_12:
    if ( v10 )
    {
      *(_WORD *)v10 = command_type;
      *(_WORD *)(v10 + 2) = index;
      *(_QWORD *)(v10 + 8) = data;
    }
  }
  v15 = *((_QWORD *)v7 + 5);
  if ( v15 )
  {
    *((_DWORD *)v7 + 18) += *(_DWORD *)(v15 + 24);
    *((_QWORD *)v7 + 5) = 0i64;
  }
  v16 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x28u, 0x10u);
  v17 = (Illusion::RenderPhase *)v16;
  if ( v16 )
  {
    *(_QWORD *)v16 = v16;
    *((_QWORD *)v16 + 1) = v16;
    *((_QWORD *)v16 + 2) = v16 + 16;
    *((_QWORD *)v16 + 3) = v16 + 16;
    *((_QWORD *)v16 + 4) = 0i64;
  }
  else
  {
    v17 = 0i64;
  }
  mPrev = v17->mQueues.mNode.mPrev;
  mPrev->mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v7;
  *(_QWORD *)v7 = mPrev;
  *((_QWORD *)v7 + 1) = &v17->mQueues;
  v17->mQueues.mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v7;
  Illusion::RenderQueueSystem::FlushRenderPhase(v17, 1u, 0, 0i64, 0);
}

