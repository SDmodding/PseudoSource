// File Line: 318
// RVA: 0xA1B640
void Illusion::RenderQueueSystem::Init(void)
{
  Illusion::RenderThreadManager::Init(&Illusion::gRenderThreadManager);
}

// File Line: 357
// RVA: 0xA1AA30
UFG::qTaskGroup *__fastcall Illusion::RenderQueueSystem::FlushRenderPhase(Illusion::RenderPhase *phase, unsigned int flush_task_count, unsigned int flush_task_dbg_id, UFG::qTask *flush_task_dep)
{
  UFG::qNode<Illusion::RenderPhase,Illusion::RenderPhase> *v4; // rax

  phase->mFlushTaskDependency = flush_task_dep;
  v4 = Illusion::RenderQueuePlat::mFlushedRenderPhases.mNode.mPrev;
  Illusion::RenderQueuePlat::mFlushedRenderPhases.mNode.mPrev->mNext = (UFG::qNode<Illusion::RenderPhase,Illusion::RenderPhase> *)&phase->mPrev;
  phase->mPrev = v4;
  phase->mNext = (UFG::qNode<Illusion::RenderPhase,Illusion::RenderPhase> *)&Illusion::RenderQueuePlat::mFlushedRenderPhases;
  Illusion::RenderQueuePlat::mFlushedRenderPhases.mNode.mPrev = (UFG::qNode<Illusion::RenderPhase,Illusion::RenderPhase> *)&phase->mPrev;
  return 0i64;
}

// File Line: 375
// RVA: 0x15AA5A0
__int64 dynamic_initializer_for__Illusion::RenderQueuePlat::mFlushedRenderPhases__()
{
  return atexit(dynamic_atexit_destructor_for__Illusion::RenderQueuePlat::mFlushedRenderPhases__);
}

// File Line: 380
// RVA: 0xA1B1F0
UFG::qList<Illusion::RenderPhase,Illusion::RenderPhase,1,0> *__fastcall Illusion::RenderQueuePlat::GetRenderPhasesForNextFrame()
{
  UFG::qList<Illusion::RenderPhase,Illusion::RenderPhase,1,0> *result; // rax
  UFG::qNode<Illusion::RenderPhase,Illusion::RenderPhase> *v1; // r8
  UFG::qNode<Illusion::RenderPhase,Illusion::RenderPhase> *v2; // rcx
  UFG::qNode<Illusion::RenderPhase,Illusion::RenderPhase> *v3; // rdx

  result = (UFG::qList<Illusion::RenderPhase,Illusion::RenderPhase,1,0> *)UFG::qLinearAllocator::Malloc(
                                                                            Illusion::gEngine.FrameMemory,
                                                                            0x10u,
                                                                            0x10u);
  if ( result )
  {
    result->mNode.mPrev = &result->mNode;
    result->mNode.mNext = &result->mNode;
  }
  v1 = Illusion::RenderQueuePlat::mFlushedRenderPhases.mNode.mNext;
  if ( (UFG::qList<Illusion::RenderPhase,Illusion::RenderPhase,1,0> *)Illusion::RenderQueuePlat::mFlushedRenderPhases.mNode.mNext != &Illusion::RenderQueuePlat::mFlushedRenderPhases )
  {
    v2 = result->mNode.mPrev;
    v3 = Illusion::RenderQueuePlat::mFlushedRenderPhases.mNode.mPrev;
    v2->mNext = Illusion::RenderQueuePlat::mFlushedRenderPhases.mNode.mNext;
    v1->mPrev = v2;
    v3->mNext = &result->mNode;
    result->mNode.mPrev = v3;
    Illusion::RenderQueuePlat::mFlushedRenderPhases.mNode.mPrev = (UFG::qNode<Illusion::RenderPhase,Illusion::RenderPhase> *)&Illusion::RenderQueuePlat::mFlushedRenderPhases;
    Illusion::RenderQueuePlat::mFlushedRenderPhases.mNode.mNext = (UFG::qNode<Illusion::RenderPhase,Illusion::RenderPhase> *)&Illusion::RenderQueuePlat::mFlushedRenderPhases;
  }
  return result;
}

// File Line: 409
// RVA: 0xA1A1F0
void __fastcall Illusion::IRenderQueuePlat::Execute(Illusion::IRenderQueuePlat *this, void *context_param)
{
  int v2; // er13
  Illusion::TaskRenderEnv *v3; // rdi
  Illusion::IRenderQueuePlat *v4; // r14
  signed __int64 v5; // rcx
  unsigned int v6; // ebp
  __int64 v7; // rsi
  __int64 v8; // rdx
  Illusion::VertexDecl *v9; // rbx
  ID3D11Buffer *v10; // r15
  unsigned int v11; // er12
  __int64 v12; // rax
  signed int v13; // eax
  int v14; // ecx
  ID3D11Buffer *v15; // r15
  unsigned int v16; // er12
  __int64 v17; // rax
  __int64 v18; // rax
  unsigned int v19; // eax
  float v20; // xmm4_4
  float v21; // xmm3_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  int v25; // eax
  int v26; // ecx
  int v27; // er8
  int v28; // edx
  __int64 v29; // rax
  Illusion::Shader *v30; // rdx
  _QWORD *v31; // r8
  void (__fastcall *v32)(Illusion::TaskRenderEnv *, Illusion::Shader *, _QWORD *, Illusion::VertexDecl *); // rax
  UFG::qBaseNodeRB *v33; // rcx
  unsigned int v34; // edx
  unsigned int v35; // ecx
  int v36; // edx
  ID3D11Buffer *v37; // rax
  Illusion::BeginTargetCommandParams *v38; // rdx
  int v39; // [rsp+50h] [rbp+8h]

  v2 = 0;
  v3 = (Illusion::TaskRenderEnv *)context_param;
  v4 = this - 16;
  if ( !this )
    v4 = 0i64;
  UFG::qMemSet(&v4[96], 0, 0x400u);
  *(_QWORD *)&v4[88] = 0i64;
  *(_QWORD *)&v4[80] = 0i64;
  v5 = (signed __int64)&v4[16];
  v6 = 0;
  v7 = *(_QWORD *)&v4[24];
  if ( (Illusion::IRenderQueuePlat *)v7 != &v4[16] )
  {
    do
    {
      v8 = *(unsigned __int16 *)(v7 + 16 * (v6 + 2i64) + 2);
      v9 = *(Illusion::VertexDecl **)(v7 + 16 * (v6 + 2i64) + 8);
      switch ( *(signed __int16 *)(v7 + 16 * (v6 + 2i64)) )
      {
        case 1:
          *(_QWORD *)&v4[104] = v9;
          Illusion::TaskRenderEnv::SetShader(v3, (Illusion::Shader *)v9);
          goto LABEL_52;
        case 2:
          if ( (unsigned int)(signed __int16)v8 >= 0x40 )
            *(_QWORD *)&v4[88] |= 1i64 << ((unsigned __int8)v8 - 64);
          else
            *(_QWORD *)&v4[80] |= 1i64 << v8;
          v29 = (signed __int16)v8;
          *(_QWORD *)&v4[8 * v29 + 96] = v9;
          v30 = v3->mShader;
          v31 = v30->mShaderParam[v29];
          if ( v31 )
          {
            v32 = (void (__fastcall *)(Illusion::TaskRenderEnv *, Illusion::Shader *, _QWORD *, Illusion::VertexDecl *))v31[4];
            if ( v32 )
              v32(v3, v30, v31, v9);
          }
          goto LABEL_52;
        case 3:
          v5 = (signed __int64)&v4[16];
          if ( v9 != v3->mVertexDecl )
          {
            v3->mCurrState.mInputLayout = 0i64;
            v3->mVertexDecl = v9;
          }
          break;
        case 4:
          v10 = 0i64;
          v11 = 0;
          if ( v9 )
          {
            LODWORD(v9->mVertexDeclUser.mOffset) = Illusion::gEngine.mFrameCount;
            v12 = *(_QWORD *)&v9[1].mDebugName[4];
            if ( v12 )
            {
              v10 = *(ID3D11Buffer **)(v12 + 88);
              v11 = v9->mStreamStrides[1];
              v2 = v9->mStreamStrides[2];
            }
            else
            {
              UFG::qPrintf(
                "!!! ERROR !!! Trying to render with a buffer object (%s) that hasnt been fully created yet. This is an "
                "error in the PC D3D resource system.",
                v9->mDebugName,
                5368709120i64);
              v3->mAbortNextDraw = 1;
            }
          }
          v13 = 57;
          if ( v11 == 4 )
            v13 = 42;
          v3->mIndexCount = v2;
          v3->mCurrState.mIndexBuffer = v10;
          v3->mCurrState.mIndexBufferOffset = 0;
          v2 = 0;
          *(_DWORD *)v3->mCurrState.mIndexBufferFormat = v13;
          goto LABEL_52;
        case 5:
          goto $LN34_21;
        case 6:
          LOWORD(v8) = 4;
$LN34_21:
          v14 = (signed __int16)v8;
          v15 = 0i64;
          v16 = 0;
          v39 = (signed __int16)v8;
          if ( v9 )
          {
            LODWORD(v9->mVertexDeclUser.mOffset) = Illusion::gEngine.mFrameCount;
            v17 = *(_QWORD *)&v9[1].mDebugName[4];
            if ( v17 )
            {
              v15 = *(ID3D11Buffer **)(v17 + 88);
              v16 = v9->mStreamStrides[1];
              v2 = *(_DWORD *)(v17 + 96);
            }
            else
            {
              UFG::qPrintf(
                "!!! Error !!! Trying to render with a buffer object (%s) that hasnt been fully created yet. This is an "
                "error in the PC D3D resource system.",
                v9->mDebugName,
                5368709120i64);
              v14 = v39;
              v3->mAbortNextDraw = 1;
            }
          }
          v18 = v14;
          v3->mCurrState.mVertexBuffers[v18] = v15;
          v3->mCurrState.mVertexBufferOffsets[v18] = v2;
          v2 = 0;
          v3->mCurrState.mVertexBufferStrides[v18] = v16;
          goto LABEL_52;
        case 7:
          v5 = (signed __int64)&v4[16];
          if ( v9 )
          {
            v3->mAlphaState = (Illusion::AlphaState *)v9;
            v3->mCurrState.mBlendState = *(ID3D11BlendState **)&v9->mStreamStrides[3];
          }
          break;
        case 8:
          v5 = (signed __int64)&v4[16];
          if ( v9 )
          {
            v3->mRasterState = (Illusion::RasterState *)v9;
            v19 = BYTE1(v9->mStreamStrides[0]);
            v3->mCurrState.mBlendStateMask = -1;
            v3->mCurrState.mDepthStateStencilRef = v19;
            v3->mCurrState.mDepthState = (ID3D11DepthStencilState *)v9[1].mNode.mParent;
            v3->mCurrState.mRasterizerState = (ID3D11RasterizerState *)v9[1].mNode.mChild[0];
          }
          break;
        case 9:
          if ( v9 )
          {
            v20 = *((float *)&v9->mNode.mChild[1] + 1);
            v21 = *(float *)&v9->mNode.mChild[1];
            v22 = *((float *)v9->mNode.mChild + 1);
            v23 = *(float *)v9->mNode.mChild;
            v24 = *((float *)&v9->mNode.mParent + 1);
            v3->mCurrState.mViewport.TopLeftX = *(float *)&v9->mNode.mParent;
            v3->mCurrState.mViewport.TopLeftY = v24;
            v3->mCurrState.mViewport.Width = v23;
            v3->mCurrState.mViewport.Height = v22;
            v3->mCurrState.mViewport.MinDepth = v21;
            v3->mCurrState.mViewport.MaxDepth = v20;
            v25 = v9->mNode.mUID;
            v26 = (int)v9->mResourceHandles.mNode.mPrev;
            v27 = HIDWORD(v9->mResourceHandles.mNode.mPrev);
            v28 = *(&v9->mNode.mUID + 1);
            v3->mCurrState.mScissorRect.left = v25;
            v3->mCurrState.mScissorRect.right = v26 + v25;
            v3->mCurrState.mScissorRect.top = v28;
            v3->mCurrState.mScissorRect.bottom = v28 + v27;
          }
          goto LABEL_52;
        case 10:
          v3->mCurrState.mPrimType = Illusion::HardwareState::sPrimType[v9[1].mNumElements];
          Illusion::TaskRenderEnv::SubmitMesh(
            v3,
            v9[1].mStreamStrides[0],
            v9[1].mStreamStrides[1] * Illusion::HardwareState::sIndicesPerPrim[v9[1].mNumElements]);
          goto LABEL_52;
        case 11:
          v3->mCurrState.mPrimType = Illusion::HardwareState::sPrimType[LODWORD(v9[1].mVertexDeclUser.mOffset)];
          Illusion::TaskRenderEnv::SubmitMesh(
            v3,
            HIDWORD(v9[1].mVertexDeclUser.mOffset),
            LODWORD(v9[2].mNode.mParent)
          * Illusion::HardwareState::sIndicesPerPrim[LODWORD(v9[1].mVertexDeclUser.mOffset)]);
          goto LABEL_52;
        case 12:
          v34 = HIDWORD(v9->mNode.mChild[0][3].mParent);
          v3->mCurrState.mPrimType = Illusion::HardwareState::sPrimType[*((unsigned __int16 *)&v9->mNode.mUID + 2)];
          v35 = *(_DWORD *)&v9->mDebugName[4];
          v3->mCurrState.mVertexBuffers[0] = *(ID3D11Buffer **)&v9->mTypeUID;
          v3->mCurrState.mVertexBufferOffsets[0] = v35;
          v3->mCurrState.mVertexBufferStrides[0] = v34;
          v36 = *(_DWORD *)&v9->mDebugName[24];
          v37 = *(ID3D11Buffer **)&v9->mDebugName[12];
          v3->mCurrState.mIndexBufferOffset = *(_DWORD *)&v9->mDebugName[20];
          v3->mCurrState.mIndexBuffer = v37;
          v3->mIndexCount = v36;
          *(_DWORD *)v3->mCurrState.mIndexBufferFormat = 57;
          Illusion::TaskRenderEnv::SubmitMesh(v3, *(_DWORD *)&v9->mDebugName[20], *(_DWORD *)&v9->mDebugName[24]);
          goto LABEL_52;
        case 13:
          v33 = v9->mNode.mParent;
          v3->mCurrState.mPrimType = Illusion::HardwareState::sPrimType[LODWORD(v9->mNode.mParent[7].mParent)];
          Illusion::TaskRenderEnv::SubmitMeshInstanced(
            v3,
            (unsigned int)v9->mNode.mChild[0],
            HIDWORD(v33[7].mParent),
            LODWORD(v33[7].mChild[0]) * Illusion::HardwareState::sIndicesPerPrim[LODWORD(v33[7].mParent)]);
          goto LABEL_52;
        case 14:
          Illusion::TaskRenderEnv::SetTarget(v3, (Illusion::BeginTargetCommandParams *)v9);
          goto LABEL_52;
        case 15:
          if ( v9 && v9->mNode.mParent )
            Illusion::ITargetPlat::EndTarget(
              (Illusion::ITargetPlat *)v9->mNode.mParent,
              (Illusion::BeginTargetCommandParams *)v9);
          v5 = (signed __int64)&v4[16];
          if ( v3->mTarget )
            v3->mTarget = 0i64;
          break;
        case 16:
          v38 = (Illusion::BeginTargetCommandParams *)v9->mNode.mParent;
          if ( v9->mNode.mParent && v38->mTarget )
            Illusion::TaskRenderEnv::SetTarget(v3, v38);
          Illusion::TaskRenderEnv::ClearTarget(v3, (Illusion::ClearCommandParams *)v9);
          goto LABEL_52;
        case 17:
          ((void (__fastcall *)(UFG::qBaseNodeRB *, __int64, signed __int64))v9->mNode.mChild[0])(
            v9->mNode.mParent,
            v8,
            5368709120i64);
          goto LABEL_52;
        case 18:
          Illusion::OcclusionPlat::BeginQuery(&Illusion::gOcclusionPlat, (unsigned int)v9->mNode.mChild[0], 1u);
          goto LABEL_52;
        case 19:
          Illusion::ITargetPlat::EndQuery(
            (Illusion::OcclusionPlat *)v9->mNode.mParent->mParent,
            (unsigned int)v9->mNode.mChild[0],
            0x40000000u);
          goto LABEL_52;
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
          goto LABEL_52;
        case 26:
          Illusion::TaskRenderEnv::DispatchCompute(
            v3,
            (unsigned int)v9->mNode.mParent,
            HIDWORD(v9->mNode.mParent),
            (unsigned int)v9->mNode.mChild[0]);
          goto LABEL_52;
        case 27:
          ((void (__fastcall *)(ID3D11DeviceContext *, __int64, signed __int64))v3->mContext->vfptr[36].Release)(
            v3->mContext,
            v8,
            5368709120i64);
          memset(&v3->mDeviceState, 0, 0x910ui64);
          v3->mDeviceState.mInComputePipeline = 0;
          v3->mDeviceState.mBlendStateMask = -1;
LABEL_52:
          v5 = (signed __int64)&v4[16];
          break;
        default:
          break;
      }
      if ( ++v6 >= *(_DWORD *)(v7 + 24) )
      {
        v7 = *(_QWORD *)(v7 + 8);
        v6 = 0;
      }
    }
    while ( v7 != v5 );
  }
}

// File Line: 847
// RVA: 0xA1A7B0
void __fastcall Illusion::RenderQueuePlat::ExecuteFlushedRenderPhasesImmediate(UFG::qList<Illusion::RenderPhase,Illusion::RenderPhase,1,0> *flushed_render_phases)
{
  UFG::qList<Illusion::RenderPhase,Illusion::RenderPhase,1,0> *v1; // rsi
  UFG::qList<Illusion::RenderPhase,Illusion::RenderPhase,1,0> *i; // rbx
  UFG::qNode<Illusion::RenderPhase,Illusion::RenderPhase> *v3; // rcx
  UFG::qNode<Illusion::RenderPhase,Illusion::RenderPhase> *v4; // rax
  UFG::qTask *v5; // rdx
  UFG::qNode<Illusion::RenderPhase,Illusion::RenderPhase> *v6; // rdx
  UFG::qNode<Illusion::RenderPhase,Illusion::RenderPhase> *v7; // rcx
  UFG::qNode<Illusion::RenderPhase,Illusion::RenderPhase> *v8; // rax
  Render::SkinningCacheNode *v9; // rbx
  Illusion::TaskRenderEnv context_param; // [rsp+30h] [rbp-12D8h]
  UFG::qMap<void *> *v11; // [rsp+1310h] [rbp+8h]

  v1 = flushed_render_phases;
  Illusion::TaskRenderEnv::TaskRenderEnv(
    &context_param,
    *(ID3D11DeviceContext **)(*((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 104i64));
  Illusion::RenderQueuePlat::msPrintFlushedQueues = 0;
  for ( i = (UFG::qList<Illusion::RenderPhase,Illusion::RenderPhase,1,0> *)v1->mNode.mNext;
        i != v1;
        i = (UFG::qList<Illusion::RenderPhase,Illusion::RenderPhase,1,0> *)v1->mNode.mNext )
  {
    v3 = i->mNode.mPrev;
    v4 = i->mNode.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    i->mNode.mPrev = &i->mNode;
    i->mNode.mNext = &i->mNode;
    v5 = (UFG::qTask *)i[2].mNode.mPrev;
    if ( v5 )
      UFG::qTaskManager::Sync(&UFG::gTaskManager, v5);
    while ( (UFG::qList<Illusion::RenderPhase,Illusion::RenderPhase,1,0> *)i[1].mNode.mNext != &i[1] )
    {
      v6 = i[1].mNode.mNext;
      v7 = v6->mPrev;
      v8 = v6->mNext;
      v7->mNext = v8;
      v8->mPrev = v7;
      v6->mPrev = v6;
      v6->mNext = v6;
      Illusion::IRenderQueuePlat::Execute((Illusion::IRenderQueuePlat *)&v6[1], &context_param);
    }
  }
  Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::~CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>(&context_param.mInputLayoutCache.mLocalCache);
  v11 = &context_param.mConstantBufferValues;
  while ( context_param.mConstantBufferValues.mTree.mTree.mCount )
  {
    v9 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&context_param.mConstantBufferValues);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&context_param.mConstantBufferValues,
      &v9->mNode);
    operator delete[](v9);
  }
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&context_param.mConstantBufferValues);
}

// File Line: 904
// RVA: 0xA17BA0
void Illusion::RenderQueuePlat::ClearFlushedRenderPhases(void)
{
  UFG::qNode<Illusion::RenderPhase,Illusion::RenderPhase> *i; // rax
  UFG::qNode<Illusion::RenderPhase,Illusion::RenderPhase> *v1; // rdx
  UFG::qNode<Illusion::RenderPhase,Illusion::RenderPhase> *v2; // rcx

  for ( i = Illusion::RenderQueuePlat::mFlushedRenderPhases.mNode.mNext;
        (UFG::qList<Illusion::RenderPhase,Illusion::RenderPhase,1,0> *)Illusion::RenderQueuePlat::mFlushedRenderPhases.mNode.mNext != &Illusion::RenderQueuePlat::mFlushedRenderPhases;
        i = Illusion::RenderQueuePlat::mFlushedRenderPhases.mNode.mNext )
  {
    v1 = i->mPrev;
    v2 = i->mNext;
    v1->mNext = v2;
    v2->mPrev = v1;
    i->mPrev = i;
    i->mNext = i;
  }
}

