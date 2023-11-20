// File Line: 437
// RVA: 0x94AA0
void __fastcall Illusion::RenderQueue_PrintCommand(Illusion::QueueCommand *command)
{
  char *v1; // rdi
  __int16 v2; // si
  unsigned __int16 v3; // r14
  char *v4; // rbx
  char *v5; // rbp
  __int64 v6; // rax
  __int64 v7; // [rsp+20h] [rbp-438h]
  __int64 v8; // [rsp+28h] [rbp-430h]
  __int64 v9; // [rsp+30h] [rbp-428h]
  __int64 v10; // [rsp+38h] [rbp-420h]
  __int64 v11[2]; // [rsp+40h] [rbp-418h]
  char dest; // [rsp+50h] [rbp-408h]

  v1 = (char *)command->mData;
  v2 = command->mCommandType;
  v3 = command->mIndex;
  v4 = &customWorldMapCaption;
  v5 = &customWorldMapCaption;
  if ( !v1 )
  {
    v4 = "<null data>";
    goto LABEL_32;
  }
  switch ( v2 )
  {
    case 1:
      v4 = v1 + 52;
      v5 = &dest;
      UFG::qSPrintf(&dest, 1024, "SortUID=0x%08x", *((unsigned int *)v1 + 28));
      goto LABEL_32;
    case 10:
      v4 = (char *)*((_QWORD *)v1 + 30);
      goto LABEL_32;
    case 11:
      v4 = (char *)*((_QWORD *)v1 + 33);
      LODWORD(v8) = *((_DWORD *)v1 + 62);
      LODWORD(v7) = *((_DWORD *)v1 + 64);
      UFG::qSPrintf(&dest, 1024, "[index_start=%d, num_prims=%d, prim_type=%d]", *((unsigned int *)v1 + 63), v7, v8);
      v5 = &dest;
      goto LABEL_32;
    case 12:
      v4 = (char *)*((_QWORD *)v1 + 5);
      goto LABEL_32;
  }
  if ( (unsigned __int16)(v2 - 2) > 1u && (unsigned __int16)(v2 - 7) > 1u )
  {
    if ( v2 != 4 )
    {
      if ( v2 == 5 )
        goto LABEL_27;
      if ( v2 != 6 )
      {
        if ( v2 == 16 )
        {
          if ( *(_QWORD *)v1 )
            v4 = (char *)(**(_QWORD **)v1 + 81i64);
          else
            v4 = "<null target>";
        }
        else if ( (unsigned __int16)(v2 - 14) <= 1u )
        {
          v5 = (char *)*((_QWORD *)v1 + 3);
          v4 = (char *)(*(_QWORD *)v1 + 81i64);
        }
        else if ( v2 == 9 )
        {
          LODWORD(v11[0]) = *((_DWORD *)v1 + 9);
          LODWORD(v10) = *((_DWORD *)v1 + 8);
          LODWORD(v9) = *((_DWORD *)v1 + 7);
          LODWORD(v8) = *((_DWORD *)v1 + 6);
          UFG::qSPrintf(&dest, 1024, "[viewport=%v4, depth=%v2 scissor=%d %d %d %d]", v1, v1 + 16, v8, v9, v10, v11[0]);
          v5 = &dest;
        }
        else if ( (unsigned __int16)(v2 - 22) > 1u && (unsigned __int16)(v2 - 20) <= 1u )
        {
          v4 = (char *)command->mData;
        }
        goto LABEL_32;
      }
    }
    if ( v2 != 5 )
    {
LABEL_28:
      v4 = Illusion::gStateSystem.mStateParamDescs[v3].mName;
      LODWORD(v9) = *((_DWORD *)v1 + 23);
      LODWORD(v8) = *((_DWORD *)v1 + 26);
      LODWORD(v7) = *((_DWORD *)v1 + 27);
      UFG::qSPrintf(&dest, 1024, "%s [num_elem=%d, elem_size=%d, data_size=%d]", v1 + 52, v7, v8, v9);
      v5 = &dest;
      goto LABEL_32;
    }
LABEL_27:
    v3 += 4;
    goto LABEL_28;
  }
  v6 = v3;
  v4 = Illusion::gStateSystem.mStateParamDescs[v6].mName;
  if ( Illusion::gStateSystem.mStateParamDescs[v6].mIsResourceData )
    v5 = v1 + 52;
LABEL_32:
  UFG::qPrintf(
    "%-25s : 0x%016x64 -> %3d  %-26s%s\n",
    Illusion::QueueCommandName[v2],
    v1,
    (unsigned int)(signed __int16)v3,
    v4,
    v5);
}

// File Line: 534
// RVA: 0x94540
void __fastcall Illusion::RenderQueueSystem::Print(Illusion::RenderQueue *render_queue)
{
  Illusion::RenderQueue *v1; // rbx
  signed __int64 v2; // rsi
  unsigned int v3; // edi
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v4; // rbx

  v1 = render_queue;
  UFG::qPrintf(
    "-------------------------\n"
    "Queue: 0x%016x64  num_cmds=%4d  num_prims=%5d  platdata0=0x%016x64  platdata1=0x%016x64  userdata=0x%016x64\n",
    render_queue,
    render_queue->mCommandCount,
    render_queue->mPrimitiveCount,
    render_queue->mPlatData0,
    render_queue->mPlatData1,
    render_queue->mUserData);
  v2 = (signed __int64)&v1->mBuckets;
  if ( (UFG::qList<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket,1,0> *)v1->mBuckets.mNode.mNext != &v1->mBuckets )
  {
    v3 = 0;
    v4 = v1->mBuckets.mNode.mNext;
    while ( v4 != (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v2 )
    {
      Illusion::RenderQueue_PrintCommand((Illusion::QueueCommand *)&v4[v3++ + 2]);
      if ( v3 >= LODWORD(v4[1].mNext) )
      {
        v4 = v4->mNext;
        v3 = 0;
      }
    }
  }
}

// File Line: 579
// RVA: 0x92050
void __fastcall Illusion::RenderQueueSystem::FlushRenderCommand(__int16 command_type, __int16 index, void *data)
{
  void *v3; // rsi
  __int16 v4; // bp
  __int16 v5; // r14
  char *v6; // rax
  char *v7; // rbx
  _QWORD *v8; // ST40_8
  __int64 v9; // rdx
  __int64 v10; // rax
  signed __int64 v11; // rcx
  char *v12; // rax
  char *v13; // rdx
  __int64 v14; // rax
  __int64 v15; // rax
  __int64 v16; // rax
  char *v17; // rax
  Illusion::RenderPhase *v18; // rcx
  _QWORD *v19; // ST38_8
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v20; // rax

  v3 = data;
  v4 = index;
  v5 = command_type;
  v6 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x460u, 0x10u);
  v7 = v6;
  if ( v6 )
  {
    *(_QWORD *)v6 = v6;
    *((_QWORD *)v6 + 1) = v6;
    v8 = v6 + 16;
    *v8 = v8;
    v8[1] = v8;
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
  v9 = *((_QWORD *)v7 + 5);
  if ( v9 )
  {
    v10 = *(unsigned int *)(v9 + 24);
    if ( (unsigned int)v10 < 0x7E )
    {
      v11 = v9 + 16 * (v10 + 2);
      *(_DWORD *)(v9 + 24) = v10 + 1;
      goto LABEL_13;
    }
    if ( v9 )
    {
      *((_DWORD *)v7 + 18) += *(_DWORD *)(v9 + 24);
      *((_QWORD *)v7 + 5) = 0i64;
    }
  }
  v12 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v13 = v12;
  if ( v12 )
  {
    *(_QWORD *)v12 = v12;
    *((_QWORD *)v12 + 1) = v12;
    *((_QWORD *)v12 + 2) = 0i64;
    *((_DWORD *)v12 + 6) = 0;
    v14 = *((_QWORD *)v7 + 2);
    *(_QWORD *)(v14 + 8) = v13;
    *(_QWORD *)v13 = v14;
    *((_QWORD *)v13 + 1) = v7 + 16;
    *((_QWORD *)v7 + 2) = v13;
    *((_QWORD *)v7 + 5) = v13;
  }
  v15 = *((_QWORD *)v7 + 5);
  if ( v15 )
  {
    *(_DWORD *)(v15 + 24) = 1;
    v11 = *((_QWORD *)v7 + 5) + 32i64;
LABEL_13:
    if ( v11 )
    {
      *(_WORD *)v11 = v5;
      *(_WORD *)(v11 + 2) = v4;
      *(_QWORD *)(v11 + 8) = v3;
    }
  }
  v16 = *((_QWORD *)v7 + 5);
  if ( v16 )
  {
    *((_DWORD *)v7 + 18) += *(_DWORD *)(v16 + 24);
    *((_QWORD *)v7 + 5) = 0i64;
  }
  v17 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x28u, 0x10u);
  v18 = (Illusion::RenderPhase *)v17;
  if ( v17 )
  {
    *(_QWORD *)v17 = v17;
    *((_QWORD *)v17 + 1) = v17;
    v19 = v17 + 16;
    *v19 = v19;
    v19[1] = v19;
    *((_QWORD *)v17 + 4) = 0i64;
  }
  else
  {
    v18 = 0i64;
  }
  v20 = v18->mQueues.mNode.mPrev;
  v20->mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v7;
  *(_QWORD *)v7 = v20;
  *((_QWORD *)v7 + 1) = (char *)v18 + 16;
  v18->mQueues.mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v7;
  Illusion::RenderQueueSystem::FlushRenderPhase(v18, 1u, 0, 0i64, 0);
}

